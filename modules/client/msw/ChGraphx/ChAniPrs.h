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

	Interface for the Animation parsing classes.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChAniPrs.h,v 2.3 1996/03/15 08:12:15 pritham Exp $


#if !defined( _CHGRPARS_H )
#define _CHGRPARS_H

#include "ChAnim.h"
#include "ChAnimy.h"
#include <ChHTTP.h>


#define YYSTYPE chint32


class ChAnimHTTPReq;
//class ChHTTPConn;

class ChAnimBindVal
{
	public:
		enum type {Integer, String, Pointer};

	protected:
		int	m_key;
		void *m_val;
		int m_ival;
		type m_type;

	public:
		ChAnimBindVal( int key, void *val) : 
			m_type(Pointer), m_key(key), m_val(val)
			{ };
		ChAnimBindVal( int key, int val) : 
			m_type(Integer), m_key(key), m_ival(val)
			{ };

		inline int GetKey() { return m_key; }
		inline int GetIVal() { ASSERT(m_type == Integer); return m_ival; }
		inline void * GetVal() { ASSERT(m_type != Integer); return m_val; }
		inline type GetType() { return m_type; }
};

class ChBindList: public  ChPtrList<ChAnimBindVal>
{
	public:
		ChBindList() : ChPtrList<ChAnimBindVal>() {};
};

class ChBoundCells
{

	protected:
		chint32 m_lCount;
		ChCell *m_pCells;

	public:

		ChBoundCells( chint32 lCount, ChCell *pCells ) :
			m_lCount(lCount), m_pCells(pCells) { };

		chint32 GetCount () {return m_lCount;};
		ChCell * GetCells () {return m_pCells;};
		
};

class ChBoundSprite
{

	protected:
		string m_strURL;
		CPhasedSprite *m_pSprite;

	public:

		ChBoundSprite(CPhasedSprite* pSprite = 0, const string &strURL = string("")  ) :
			m_strURL(strURL), m_pSprite(pSprite) { };

		string GetURL () {return m_strURL;};
		CPhasedSprite* GetSprite () {return m_pSprite;};
		
};

typedef ChBindList * pChBindList;
typedef ChAnimBindVal * pChAnimBindVal;
	

// The main parsing class
class ChAnimParser
{

	public:
					
	public:
		ChAnimParser( ChAnimView * pView, iostream * pStrm, 
					  ChGraphicMainInfo*	pInfo, 
					  const string& strURL, 
					  ChGraphicHTTPReq *pParentReq = 0 ) : 
			m_pStrm(pStrm), m_pView(pView), m_pParentReq(pParentReq), m_pInfo(pInfo),
			m_strURL(strURL),
			m_pCast(0), m_lResult(0)
			{ m_theParser = this; };

		virtual ~ChAnimParser() { m_theParser = 0; }

		static ChAnimParser * GetParser() { return m_theParser; }
		YYSTYPE bind( int tok, void *val );
		YYSTYPE bind( int tok, int val );
		int interpret();
		chint32 AddAnchor( ChBindList *pList );
		chint32 AddCast( ChBindList *pList );
		chint32 Sprite( ChBindList *pList );
		chint32 Script( ChBindList *pList );
		chint32 Frames( ChBindList *pList );
		chint32 Background( ChBindList *pList );
		YYSTYPE NewBindingList(ChAnimBindVal *);
		YYSTYPE AppendBindingList(ChBindList *, ChAnimBindVal *);
//		inline ChHTTPConn* GetHTTPConn() { return m_pInfo->GetHTTPConn(); };
		inline ChAnimParser * SetCast( ChAnimCastMember *pCast )
			{
				m_pCast = pCast;
				return this;
			};
		chint32 GetKey();	 // get the final result
		chint32 GetVal();
		inline string& GetURL() {return m_strURL;};

	protected:
		static ChAnimParser * m_theParser;
		iostream * m_pStrm;
		ChGraphicMainInfo*	m_pInfo;
		ChAnimView * m_pView;
		int yylex(void);
		void yyerror(const char *) { };
		void ReadString( string& strStr );
		void SkipIfComment( );
		int LookupKeyword(string& strTok);
		int yyparse(void);
		YYSTYPE yylval;
		YYSTYPE yyval;
		ChGraphicHTTPReq *	m_pParentReq;
		ChAnimCastMember *m_pCast;
		YYSTYPE m_lResult;
		string m_strURL;	  // URL for this file being parsed

};
#endif
