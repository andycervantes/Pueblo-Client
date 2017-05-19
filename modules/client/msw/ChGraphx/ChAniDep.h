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

	Interface for the Animation HTTP and load request classes.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChAniDep.h,v 2.4 1996/03/15 08:12:12 pritham Exp $

#include "grheader.h"
#if !defined( _CHANIDEP_H )
#define _CHANIDEP_H

#include "ChAnim.h"
#include "ChGrDep.h"
//#include "ChGrMod.h"

/* Animation HTTP and load request classes, along with dependency tracking */

//class ChAnimHTTPReq	: public CObject
#if 0
class ChAnimHTTPReq : public ChGraphicHTTPReq
{
	public:
	//enum type {anchor = 1, background, cast, script, sprite, start};

	protected:
		//ChAnimView * m_pView;
		//type m_type;
 		//ChPtrList<ChAnimHTTPReq> m_dependencies;

		//ChAnimHTTPReq *m_parent;	  // parent depends on me
		virtual void AddParent( ChGraphicHTTPReq *pDependency );

	public:

		ChAnimHTTPReq( type aType, ChAnimView * pView) :
			ChGraphicHTTPReq( aType, pView )
				{ 
					//TRACE0("ChAnimHTTPReq()"); 
				}

		virtual ~ChAnimHTTPReq();

		inline type GetType() {return m_type;}
		inline void *  GetView() {return m_pView;}
		virtual void Add( ChGraphicHTTPReq *pDependency );
		virtual void Delete( ChGraphicHTTPReq *pDependency );
		virtual void OnEmpty();
};
#endif

/* request for an anchor url */
class ChAnimAnchorHTTPReq : public 	ChGraphicHTTPReq
{
	protected:

	public:
		ChAnimAnchorHTTPReq(  ChAnimView * pView, const string& strURL) :
			ChGraphicHTTPReq( anchor, pView, strURL)
			{ };

};

/* request to load background */
class ChAnimBackgroundHTTPReq : public 	ChGraphicBackgroundHTTPReq
{
	protected:
 		ChPtrList<ChGraphicHTTPReq> m_parents;		 // yup, plural; we have many
		
		virtual void AddParent( ChGraphicHTTPReq *pDependency );

	public:
		ChAnimBackgroundHTTPReq(  ChAnimView * pView, const string& strURL) :
			ChGraphicBackgroundHTTPReq(pView, strURL)
			{ };
		virtual ~ChAnimBackgroundHTTPReq();

};


/* request to load a scene (.cst, .wrl) from url */
class ChAnimSceneHTTPReq : public 	ChGraphicHTTPReq
{
	protected:
		
	public:
		ChAnimSceneHTTPReq(  ChAnimView * pView, const string& strURL) :
			ChGraphicHTTPReq( cast, pView, strURL)
			{ };

		virtual ~ChAnimSceneHTTPReq() {};

		virtual void OnEmpty();
		virtual bool Load(string& strFilename, ChGraphicMainInfo* pInfo);

};

/* request to load one cast member, or a family from url */
class ChAnimCastHTTPReq : public 	ChGraphicHTTPReq
{
	protected:
		ChAnimCastMember *m_pCast;
	public:
		ChAnimCastHTTPReq(  ChAnimView * pView, const string& strURL) :
			ChGraphicHTTPReq( cast, pView, strURL), m_pCast(0)
			{ };

		ChAnimCastHTTPReq( ChAnimView * pView, ChAnimCastMember *pCast, const string& strURL) :
			ChGraphicHTTPReq( cast, pView, strURL), m_pCast(pCast)
			{ };

		virtual ~ChAnimCastHTTPReq() {};

		virtual void OnEmpty();
		bool Load(string& strFilename, ChGraphicMainInfo* pInfo);
		bool RequestParts(ChGraphicMainInfo* pConn);

};

/* loading a script from url */
class ChAnimScriptHTTPReq : public 	ChGraphicHTTPReq
{
	protected:
		chuint32 m_castId;		 // needed for isolated load
		ChAnimCastMember *m_pCast;

	public:
		ChAnimScriptHTTPReq(  ChAnimView * pView, chuint32 castId, const string& strURL) :
			ChGraphicHTTPReq( script, pView, strURL), 
			m_castId(castId), m_pCast(0)
			{ };
		ChAnimScriptHTTPReq(  ChAnimView * pView,ChAnimCastMember *pCast, const string& strURL) :
			ChGraphicHTTPReq( script, pView, strURL), 
			m_castId(pCast->GetId()), m_pCast(pCast)
			{ };

		bool Load(string& strFilename, ChGraphicMainInfo* pInfo);

};

/* loading a sprite from url */
class ChAnimSpriteHTTPReq : public 	ChGraphicHTTPReq
{
	protected:
		CPhasedSprite* m_pSprite;

	public:
		ChAnimSpriteHTTPReq(  ChAnimView * pView, const string& strURL) :
			ChGraphicHTTPReq( sprite, pView, strURL), m_pSprite(0)
			{ };
		ChAnimSpriteHTTPReq(  ChAnimView * pView, CPhasedSprite* pSprite, const string& strURL) :
			ChGraphicHTTPReq( sprite, pView, strURL), m_pSprite(pSprite)
			{ };

		inline CPhasedSprite* GetSprite() { return m_pSprite; };
		bool Load(string& strFilename, ChGraphicMainInfo* pInfo);

};

class ChAnimStartHTTPReq : public 	ChGraphicStartHTTPReq
{
	protected:
		//bool m_boolStartAnimating;
		//bool m_boolOutstanding;
		 
	public:
		ChAnimStartHTTPReq(  ChAnimView * pView, const string& strURL) :
			ChGraphicStartHTTPReq( pView, strURL)
			{ };

		virtual void OnEmpty()
		{
			if(IsOutstanding())
			{
				((ChAnimView *)m_pView)->Animate(m_boolStartAnimating);
				ClearAnimating();
			}
		}

		virtual void SetStartAnimating(bool boolPlay)
		{ 
			m_boolStartAnimating = boolPlay;
			m_boolOutstanding = true;
		};
		virtual void ClearAnimating()
		{ 
			m_boolOutstanding = false;
		};
		virtual bool GetStartAnimating() const { return m_boolStartAnimating; };
		virtual bool IsOutstanding() const { return m_boolOutstanding; };
};




#endif // _CHANIDEP_H

