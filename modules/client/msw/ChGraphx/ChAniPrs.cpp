/*----------------------------------------------------------------------------
                        _                              _ _       
        /\             | |                            | (_)      
       /  \   _ __   __| |_ __ ___  _ __ ___   ___  __| |_  __ _ 
      / /\ \ | '_ \ / _` | '__/ _ \| '_ ` _ \ / _ \/ _` | |/ _` |
     / ____ \| | | | (_| | | | (_) | | | | | |  __/ (_| | | (_| |
    /_/    \_\_| |_|\__,_|_|  \___/|_| |_| |_|\___|\__,_|_|\__,_|

    The contents of this file are subject to the Andromedia Public
	License Version 1.0 (the "License"); you may not use this file
	except in compliance with the License. You may obtain a copy of
	the License at http://www.andromedia.com/APL/

    Software distributed under the License is distributed on an
	"AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
	implied. See the License for the specific language governing
	rights and limitations under the License.

    The Original Code is Pueblo client code, released November 4, 1998.

    The Initial Developer of the Original Code is Andromedia Incorporated.
	Portions created by Andromedia are Copyright (C) 1998 Andromedia
	Incorporated.  All Rights Reserved.

	Andromedia Incorporated                         415.365.6700
	818 Mission Street - 2nd Floor                  415.365.6701 fax
	San Francisco, CA 94103

    Contributor(s):
	--------------------------------------------------------------------------
	   Chaco team:  Dan Greening, Glenn Crocker, Jim Doubek,
	                Coyote Lussier, Pritham Shetty.

					Wrote and designed original codebase.

------------------------------------------------------------------------------

	This file consists of the implementation of the ChAnim parsing classes.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChAniPrs.cpp,v 2.3 1996/03/15 08:12:14 pritham Exp $

#include "grheader.h"
#include <ChUrlMap.h>
#include "ChGrMod.h"
#include "ChAniPrs.h"
#include "ChAniDep.h"
#include "ChGrStrm.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

ChAnimParser * ChAnimParser::m_theParser = 0;

typedef struct tagChAnimToken {
	char * m_pstrToken;
	int	m_token;
} ChAnimToken;

const ChAnimToken  aAnimTokens[] =
{
	{"anchor",		ANCHOR },
	{"anchorlist",	ANCHORLIST },
	{"background",	BACKGROUND },
	{"cast",		CAST  },
	{"castid",		CASTID  },
	{"cmdarg", 		CMDARG  },
	{"columns",		COLUMNS  },
	{"cursor",		CURSOR  },
	{"false",		FALSEVAL  },
	{"file",		FILE  },
	{"format",		FORMAT  },
	{"framerate",	FRAMERATE  },
	{"frames",		FRAMES  },
	{"goto",		GOTO  },
	{"hint",		HINT },
	{"hotcastid",	HOTCAST  },
	{"hotrect",		HOTRECT },        
	{"id",			NODEID },        
	{"isanimating",	ISANIMATING  },
	{"isdraggable",	ISDRAGGABLE  },
	{"isvisible",	ISVISIBLE  },
	{"name",		NAME  },
	{"rows",		ROWS  },
	{"scene",		SCENE },           
	{"script",		SCRIPT  },
	{"sprite",		SPRITE  },
	{"startframe",	STARTFRAME  },
	{"stop",		STOP  },
	{"true",		TRUEVAL  },
	{"", 0}
};

YYSTYPE ChAnimParser::bind( int tok, void *val )
{
	return YYSTYPE(new ChAnimBindVal( tok, val ));
}

YYSTYPE ChAnimParser::bind( int tok, int val )
{
	return YYSTYPE(new ChAnimBindVal( tok, val ));
}


int ChAnimParser::yylex(void)
{
	yylval = 0;
	int tok = 0; // eof until we know better
	string strTok;
	int ch;
	static char * strTokens = "{}";

	m_pStrm->eatwhite();
	SkipIfComment();
	m_pStrm->eatwhite();
	ch = m_pStrm->peek();
	if (strchr(strTokens, ch))
	{
		m_pStrm->get();
		switch( ch )
		{
			case '{':
			case '}':
			{
				//yytext[0] = ch;
				//yytext[1] = 0;
				tok = ch;
				break;
			}
		}
	}
	else
	{
		ReadString(strTok);
		if (!strTok.IsEmpty())
		{	
			//strcpy( yytext, LPCTSTR(strTok) );
			if(isdigit(strTok[0]))
			{
				double num = atof((LPCTSTR)strTok);
				if (int(num) == num)
				{
					yylval = YYSTYPE(num);
					tok = INT;
				}
				else
				{
					yylval = YYSTYPE(new double(num));
					tok = FLOAT;
				}
			}
			else
			{
				// look up keyword, if not found it's just a string
				tok = LookupKeyword(strTok);
				if (!tok)
				{	
 					yylval = YYSTYPE(new string(strTok));
					tok = STRING;
				}
			}
		}
	}

	return tok;
}

int ChAnimParser::LookupKeyword(string& strTok)
{
	int tok = 0;
	int j = 0;
	while(aAnimTokens[j].m_token)
	{
		if (!strTok.CompareNoCase(aAnimTokens[j].m_pstrToken))
		{
			return aAnimTokens[j].m_token;
		}
		j++;
	}

	return tok;
}

#define TOKEN_DELIMS "{}#"

void ChAnimParser::ReadString( string& strStr )
{
	strStr = "";
	m_pStrm->eatwhite();
	SkipIfComment();
	m_pStrm->eatwhite();
	int ch = m_pStrm->peek();
	if (ch == '"' || ch == '\'')
	{
		m_pStrm->get();	   // first quote
		m_pStrm->get((strStr.GetBuffer(1000)), 1000, '"');
		strStr.ReleaseBuffer();
		m_pStrm->get();	   // last quote
	}
	else
	{
		char * pBuf = strStr.GetBuffer(1000);
		char * pStart = pBuf;
		ch = m_pStrm->get();
		while( !m_pStrm->eof() && !isspace(ch) && !strchr(TOKEN_DELIMS, ch) )
		{
			*pBuf++ = ch;
			ch = m_pStrm->get();
		}
		strStr.ReleaseBuffer(pBuf - pStart);
		if (!m_pStrm->eof()) m_pStrm->putback(ch);
	}
}

void ChAnimParser::SkipIfComment( void )
{
	m_pStrm->eatwhite();
	int ch = m_pStrm->peek();
	while (ch == '#')
	{
		m_pStrm->ignore( 1000, '\n');
		m_pStrm->eatwhite();
		ch = m_pStrm->peek();
	}
}

chint32 ChAnimParser::AddAnchor( ChBindList *pList )
{
	ChAnimAnchor* pAnchor = new ChAnimAnchor;

	while(!pList->IsEmpty())
	{
		ChAnimBindVal *pBindVal = pList->RemoveHead();
		switch (pBindVal->GetKey())
		{
			case CAST:
			{
				pAnchor->SetCast( pBindVal->GetIVal() );
				break;
			}
			case CMDARG:
			{
				string *s = (string *)(pBindVal->GetVal());
				pAnchor->SetCmd( *s );
				delete s;
				break;
			}
			case CURSOR:
			{
				string *s = (string *)(pBindVal->GetVal());
				pAnchor->SetCursor( *s );
				delete s;
				break;
			}
			case HINT:
			{
				string *s = (string *)(pBindVal->GetVal());
				pAnchor->SetHint( *s );
				delete s;
				break;
			}
			case HOTCAST:
			{
				pAnchor->SetHotCastId( pBindVal->GetIVal() );
				break;
			}
			case HOTRECT:
			{
				CRect *r = (CRect *)(pBindVal->GetVal());
				pAnchor->SetRect( *r );
				delete r;
				break;
			}
			case NODEID:
			{
				pAnchor->SetId( pBindVal->GetIVal() );
				break;
			}
			case STARTFRAME:
			{
				pAnchor->SetStartFrame( pBindVal->GetIVal() );
				break;
			}
		}
		delete pBindVal;	
	}

	delete pList;
	if (pAnchor->GetId())
	{
		m_pView->AddAnchor(pAnchor);
	}
	return true;
}

chint32 ChAnimParser::AddCast( ChBindList *pList )
{
	ChAnimCastMember *pCast = new ChAnimCastMember(0);   // if id is 0, didn't read 
	CPhasedSprite* pSprite = 0;

 	ChPosition pos = 0;
 	if(!pList->IsEmpty()) pos = pList->GetHeadPosition();
    while (pos)
    {
		ChAnimBindVal *pBindVal = pList->GetNext(pos);
		switch (pBindVal->GetKey())
		{
			case NODEID:
			{
				pCast->SetId(pBindVal->GetIVal() );
				break;
			}
			case NAME:
			{
				string *s = (string *)(pBindVal->GetVal());
				pCast->SetName(*s);
				delete s;
				break;
			}
			case SPRITE:
			{
				ChBoundSprite * pBound = (ChBoundSprite *)(pBindVal->GetVal());
				pSprite = pBound->GetSprite();
				// setsprite overwrites these; oughta clean it up, but . . .
				pCast->m_iNumSpriteRows = pBound->GetSprite()->GetNumCellRows();
				pCast->m_iNumSpriteCols	 = pBound->GetSprite()->GetNumCellColumns();
				//pCast->SetSprite( pBound->GetSprite( ));
				pCast->SetSpriteURL( pBound->GetURL( ));
				delete pBound;
				break;
			}
			case ISVISIBLE:
			{
				pCast->Show( pBindVal->GetIVal() );
				break;
			}
			case ISANIMATING:
			{
				pCast->Animate( pBindVal->GetIVal() );
				break;
			}
			case ISDRAGGABLE:
			{
				pCast->SetDraggable( pBindVal->GetIVal() );
				break;
			}
			case SCRIPT:
			{
				ChAnimScript *pScript  = (ChAnimScript *)(pBindVal->GetVal());

				pCast->SetScript( pScript, false );  // don't copy cells; too slow
				pScript->SaveCells();		  // don't delete them either; that would crash
				delete pScript;				  // destructor noramlly deletes cells
				break;
			}
			case SCRIPTREF:
			{
				pCast->SetScriptURL( *(string *)(pBindVal->GetVal()));

				delete (string *)(pBindVal->GetVal());
				break;
			}
		}
		delete pBindVal;	
	}
	delete pList;

	pCast->SetSprite( pSprite);

	ChAnimCastHTTPReq *pNewCastReq = new ChAnimCastHTTPReq ( m_pView, pCast, GetURL() );
	if(m_pParentReq) m_pParentReq->Add(pNewCastReq);
	pNewCastReq->RequestParts( m_pInfo );

	return true;
}

chint32 ChAnimParser::Background( ChBindList *pList )
{
	string strURL;

 	ChPosition pos = 0;
 	if(!pList->IsEmpty()) pos = pList->GetHeadPosition();
    while (pos)
    {
		ChAnimBindVal *pBindVal = pList->GetNext(pos);
		switch (pBindVal->GetKey())
		{
			case FILE:
			{
				string *s = (string *)(pBindVal->GetVal());
				strURL = *s;
				delete s;
				break;
			}
		}
		delete pBindVal;	
	}
	delete pList;

	if( !strURL.IsEmpty())
	{
		ChAnimBackgroundHTTPReq *pHTTPReq = new ChAnimBackgroundHTTPReq ( m_pView, GetURL() );
		ChURLParts urlParts;
		urlParts.GetURLParts( strURL, GetURL() );

		m_pInfo->GetCore()->GetURL( strURL, 0, m_pInfo->GetStream(), (chparam)pHTTPReq );
		m_pInfo->SetLeafDependent(pHTTPReq);		
	}


	return true;
}

chint32 ChAnimParser::Sprite( ChBindList *pList )
{
	CPhasedSprite* pSprite = new CPhasedSprite;
	string strURL;

 	ChPosition pos = 0;
 	if(!pList->IsEmpty()) pos = pList->GetHeadPosition();
    while (pos)
    {
		ChAnimBindVal *pBindVal = pList->GetNext(pos);
		switch (pBindVal->GetKey())
		{
			case NODEID:
			{
				//pSprite->SetId(pBindVal->GetIVal() );
				break;
			}
			case NAME:
			{
				string *s = (string *)(pBindVal->GetVal());
				//pSprite->SetName(*s);
				delete s;
				break;
			}
			case FILE:
			{
				string *s = (string *)(pBindVal->GetVal());
				strURL = *s;
				delete s;
				break;
			}
			case ROWS:
			{
				chint32 rows = pBindVal->GetIVal() ;
				if(pSprite->GetHeight() < rows)
				{
					pSprite->Create(pSprite->GetWidth(), rows);
				}
				pSprite->SetNumCellRows( rows );
				break;
			}
			case COLUMNS:
			{
				chint32 columns = pBindVal->GetIVal() ;
				if(pSprite->GetWidth() < columns)
				{
					pSprite->Create(columns, pSprite->GetHeight());
				}
				pSprite->SetNumCellColumns( columns );
				break;
			}
		}
		delete pBindVal;	
	}
	delete pList;
	ChBoundSprite * pBound = new ChBoundSprite(pSprite, strURL);
	return chint32(pBound);
}

chint32 ChAnimParser::Script( ChBindList *pList )
{
	ChAnimScript *pScript = new ChAnimScript;

 	ChPosition pos = 0;
 	if(!pList->IsEmpty()) pos = pList->GetHeadPosition();
    while (pos)
    {
		ChAnimBindVal *pBindVal = pList->GetNext(pos);
		switch (pBindVal->GetKey())
		{
			case NODEID:
			{
				break;
			}
			case NAME:
			{
				string *s = (string *)(pBindVal->GetVal());
				//pScript->SetName(*s);
				delete s;
				break;
			}
			case FRAMERATE:
			{
				pScript->SetFrameRate(pBindVal->GetIVal() );
				break;
			}
			case FRAMES:
			{
				ChBoundCells * pBound = (ChBoundCells *)(pBindVal->GetIVal());
				pScript->SetCells(pBound->GetCells());
				pScript->SetCount(pBound->GetCount());
				delete pBound;
				break;
			}
			case STARTFRAME:
			{
				pScript->SetCurCell( pBindVal->GetIVal() );
				break;
			}
		}
		delete pBindVal;	
	}

	delete pList;
	return chint32(pScript);
}

chint32 ChAnimParser::Frames( ChBindList *pList )
{
	chint32 numFrames = pList->GetCount() + 1; // one extra in case of no stop or cycle at end
	ChCell * pFrames = new ChCell[numFrames];
 	ChPosition pos = 0;
 	if(!pList->IsEmpty()) pos = pList->GetHeadPosition();
	ChBoundCells * pBound = new ChBoundCells( numFrames, pFrames );

	int j = 0;
    while (pos)
    {
		ChAnimBindVal *pBindVal = pList->GetNext(pos);
		switch (pBindVal->GetKey())
		{
			case FRAMEVAL:
			{
				ChCell * pCell = ((ChCell *)(pBindVal->GetVal()));
				pFrames[j++] = *pCell;
				delete pCell;
				break;
			}
			case STOP:
			{
				pFrames[j++] = ChCell(0,0,0,0,CH_ANIM_SCRIPT_STOP, 0); 
				break;
			}
			case GOTO:
			{
				pFrames[j++] = ChCell(0,0,0,0,CH_ANIM_SCRIPT_GO_TO,pBindVal->GetIVal()); 
				break;
			}
		}
		delete pBindVal;	
	}

	pFrames[j++] = ChCell(0,0,0,0,CH_ANIM_SCRIPT_STOP, 0);   // guaranteed stop cell
    delete pList;
	return chint32(pBound);
}

YYSTYPE ChAnimParser::NewBindingList(ChAnimBindVal *pBindVal)
{
	ChBindList *pList = new ChBindList;

	pList->AddTail(pBindVal);

	return YYSTYPE(pList);
}

YYSTYPE ChAnimParser::AppendBindingList(ChBindList *pList, ChAnimBindVal *pBindVal)
{	
	pList->AddTail(pBindVal);

	return YYSTYPE(pList);
}

int ChAnimParser::interpret()
{
	// make sure this is correct file type
	string strFirstline;
	string strIntro("#ChacoGraph 1.0");

	m_pStrm->get((strFirstline.GetBuffer(1000)), 1000);
	strFirstline.ReleaseBuffer();
	if (strIntro.CompareNoCase(strFirstline.Left(strIntro.GetLength())))
		return 1;
	//return ChAnimYyparse();
	return yyparse();
};	

chint32 ChAnimParser::GetKey()	 // get the final result
{
	chint32 lVal = 0;

	if(	m_lResult )
	{
		lVal = ((ChAnimBindVal *)m_lResult)->GetKey();
	}
	return lVal;
}

chint32 ChAnimParser::GetVal()
{
	chint32 lVal = 0;

	if(	m_lResult )
	{
		if (((ChAnimBindVal *)m_lResult)->GetType() == ChAnimBindVal::Integer)
		{
			lVal = ((ChAnimBindVal *)m_lResult)->GetIVal();
		}
		else
		{
			lVal = chint32(((ChAnimBindVal *)m_lResult)->GetVal());
		}
	}
	return lVal;
}
