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

	This file consists of the implementation of the ChGraphicView view class.

----------------------------------------------------------------------------*/

#include "grheader.h"

#include <ChUrlMap.h>

#include "ChGrMod.h"
#include "ChAniDep.h"
#include "ChAniPrs.h"
#include "ChGrStrm.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

#if 0
ChAnimHTTPReq::~ChAnimHTTPReq()
{
//TRACE0("~ChAnimHTTPReq()");
	if (m_parent) m_parent->Delete(this);
	m_parent=0;
}

void ChAnimHTTPReq::Add( ChGraphicHTTPReq *pDependency )
{
	m_dependencies.AddTail(pDependency);
	pDependency->AddParent(this);
}

void ChAnimHTTPReq::Delete( ChGraphicHTTPReq *pDependency )
{
	ChPosition pos = m_dependencies.Find(pDependency);
	m_dependencies.Remove(pos);

	if (pos && m_dependencies.IsEmpty())
	{
		OnEmpty();
	}
}

void ChAnimHTTPReq::OnEmpty()
{
	if(m_parent)
	{
		m_parent->Delete(this);
		m_parent = 0;
	}

	delete this;
};

void ChAnimHTTPReq::AddParent( ChAnimHTTPReq *pDependency )
{
	m_parent = pDependency;
}

#endif // 0
// subclasses in alpha order

// ChAnimBackgroundHTTPReq

ChAnimBackgroundHTTPReq::~ChAnimBackgroundHTTPReq()
{
	m_parent = 0;
	while(!m_parents.IsEmpty())
	{
		ChGraphicHTTPReq *pParent = m_parents.RemoveHead();
		pParent->Delete(this);
	}
}

void ChAnimBackgroundHTTPReq::AddParent( ChGraphicHTTPReq *pDependency )
{
	m_parent = pDependency;	// last one added - not really used
	m_parents.AddTail(pDependency);
}

// ChAnimCastHTTPReq

void ChAnimCastHTTPReq::OnEmpty()
{
	// Do all the stuff we are dependent on sprites and scripts
	
	CPhasedSprite* pSprite;

	pSprite = m_pCast->GetSprite();
	m_pCast->SetSprite(pSprite);		// sets up sprite ready to be realized

	m_pCast->InitializeScript();

	((ChAnimView*)m_pView)->AddCharacter(m_pCast);	// includes sprite palette setting
	if(m_parent)
	{
		m_parent->Delete(this);
	}
	m_parent = 0;
	delete this;
}

bool  ChAnimCastHTTPReq::RequestParts(ChGraphicMainInfo* pGraphicInfo )
{
	if (m_pCast->GetId())
	{
		ChAnimSpriteHTTPReq *pSpriteReq = new ChAnimSpriteHTTPReq ( (ChAnimView*)m_pView, m_pCast->GetSprite(), GetURL() );
		Add(pSpriteReq);
		ChURLParts urlParts;
		urlParts.GetURLParts( m_pCast->GetSpriteURL(), GetURL() );

		pGraphicInfo->GetCore()->GetURL( urlParts.GetURL(), 0, pGraphicInfo->GetStream(), 
									(chparam)pSpriteReq );

		if ( (m_pCast->GetScriptURL()).GetLength())
		{
			urlParts.GetURLParts( m_pCast->GetScriptURL(), GetURL() );

			ChAnimScriptHTTPReq *pScriptReq = new ChAnimScriptHTTPReq ( (ChAnimView*)m_pView, m_pCast, GetURL() );
			Add(pScriptReq);
			pGraphicInfo->GetCore()->GetURL( m_pCast->GetScriptURL(), 0, 
											pGraphicInfo->GetStream(), (chparam)pScriptReq );
		}
	}
	return true;
}

bool  ChAnimCastHTTPReq::Load(string& strFilename, ChGraphicMainInfo* pInfo)
{
	//ChAnimCastMember *pCast = new ChAnimCastMember(0);   // if id is 0, didn't read
	ifstream castStrm(strFilename);
	// parse it, adding what's parsed and spawning new requests for sprites and scripts
	ChAnimParser parser( (ChAnimView*)m_pView, 
						 (iostream *)(&castStrm), 
						 pInfo, 
						 GetURL(), 
						 (ChGraphicHTTPReq*)m_parent );

	bool boolSuccess = !parser.interpret();		 // try new parser 1=> failed
	ASSERT(boolSuccess);		// rude, but only for debugging CAML


	#if 0
	/*while(pCast)
	{
		pCast->Read( castStrm );
		if (pCast->GetId())
		{
			// kick off other stages: sprite and optional script
			ChAnimCastHTTPReq *pNewCastReq = new ChAnimCastHTTPReq ( pInfo->GetView(), pCast );
			if (m_parent) m_parent->Add(pNewCastReq);
			ChAnimSpriteHTTPReq *pSpriteReq = new ChAnimSpriteHTTPReq ( pInfo->GetView(), pCast->GetSprite() );
			pNewCastReq->Add(pSpriteReq);
			pInfo->GetHTTPConn()->GetURL( pCast->GetSpriteURL(), (chparam)pSpriteReq );
			if ( (pCast->GetScriptURL()).GetLength())
			{
				ChAnimScriptHTTPReq *pScriptReq = new ChAnimScriptHTTPReq ( pInfo->GetView(), pCast );
				pNewCastReq->Add(pScriptReq);
				pInfo->GetHTTPConn()->GetURL( pCast->GetScriptURL(), (chparam)pScriptReq );
			}
			pCast = new ChAnimCastMember(0);
		}
		else
		{
			delete pCast; // done
			pCast = 0;
		}
	}
	*/
	#endif
	
	return true; 
}

// ChAnimSceneHTTPReq
void ChAnimSceneHTTPReq::OnEmpty()
{

	if(m_parent)
	{
		m_parent->Delete(this);
	}
	m_parent = 0;
	delete this;
}


bool  ChAnimSceneHTTPReq::Load(string& strFilename, ChGraphicMainInfo* pInfo)
{
	ifstream castStrm(strFilename);
	// parse it, adding what's parsed and spawning new requests for sprites and scripts
	ChAnimParser parser( (ChAnimView*)m_pView, 
						 (iostream *)(&castStrm), 
						 pInfo, 
						 GetURL(), 
						 (ChGraphicHTTPReq*)m_parent );

	bool boolSuccess = !parser.interpret();		 // try new parser 1=> failed
	ASSERT(boolSuccess);		// rude, but only for debugging CAML


	return true; 
}


// ChAnimScriptHTTPReq

bool  ChAnimScriptHTTPReq::Load(string& strFilename, ChGraphicMainInfo* pInfo)
{
	// only implemented for load from a cast member
	// to an existing cast member, and for not-yet-requested cast member later
	ifstream	scriptFile( strFilename );
	ASSERT(m_pCast);
	ChAnimParser parser( (ChAnimView*)m_pView, 
						 (iostream *)(&scriptFile), 
						 pInfo, 
						 GetURL(), 
						 (ChGraphicHTTPReq*)m_parent );

	parser.SetCast( m_pCast );	// who to add it to
	//parser.SetMode( ChAnimParser::script );	// what to accept ??

	bool boolSuccess = !parser.interpret();		 // try new parser 1=> failed
	ASSERT(boolSuccess);		// rude, but only for debugging CAML

	if(parser.GetKey() == SCRIPT)
	{
				ChAnimScript *pScript  = (ChAnimScript *)(parser.GetVal());

				m_pCast->SetScript( pScript, false );  // don't copy cells; too slow
				pScript->SaveCells();		  // don't delete them either; that would crash
				delete pScript;				  // destructor noramlly deletes cells
	}
	#if 0
	ifstream	scriptFile( strFilename );
	int numCells, iCurCell;
	int iNumSpriteRows, iNumSpriteCols;
	chint32 lFrameRate;
	 
	scriptFile >> numCells;
	scriptFile >> iCurCell;
	scriptFile >> lFrameRate;
	scriptFile >> iNumSpriteRows;
	scriptFile >> iNumSpriteCols;
	ChCell *pScript = new ChCell [numCells];

	for (int j=0; j<numCells; j++)
	{
		scriptFile >> pScript[j].x;     
		scriptFile >> pScript[j].y;     
		scriptFile >> pScript[j].z;     
		scriptFile >> pScript[j].sprite;	 // currently ignored 3/19/95
		scriptFile >> pScript[j].row;   
		scriptFile >> pScript[j].col;   
	}

	m_pCast->SetScript(numCells,  iCurCell,  lFrameRate, pScript);
	#endif

	delete this;

	return false;
}

// ChAnimSpriteHTTPReq

bool  ChAnimSpriteHTTPReq::Load(string& strFilename, ChGraphicMainInfo* pInfo)
{
	
	m_pSprite->Load( (char *)(LPCTSTR(strFilename)));
	m_pSprite->Initialize();
	if (pInfo->GetLeafDependent())
	{
		Add(pInfo->GetLeafDependent());
	}
	else delete this;

	return false;
}

