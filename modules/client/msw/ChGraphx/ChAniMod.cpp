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

	Implementation for the ChGraphic class, which is used to display
	graphics, & accept selection of hot spots and sprites.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChAniMod.cpp,v 2.20 1996/04/16 05:11:10 coyote Exp $

#include "grheader.h"

#include <ChCore.h>
#include <ChHTTP.h>

#include "ChGrMod.h"
#include "ChAniDep.h"
#include "ChGrStrm.h"

#include <ChPane.h>

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

#define GRAPHICS_PANE 1

/*----------------------------------------------------------------------------
	Handler declarations
----------------------------------------------------------------------------*/

#if 1
CH_DECLARE_MESSAGE_HANDLER( animatorInitHandler )
CH_DECLARE_MESSAGE_HANDLER( animatorLoadCompleteHandler )
CH_DECLARE_MESSAGE_HANDLER( animatorLoadErrorHandler )
CH_DECLARE_MESSAGE_HANDLER( animatorLoadImageHandler )
CH_DECLARE_MESSAGE_HANDLER( animatorLoadCastHandler )
CH_DECLARE_MESSAGE_HANDLER( animatorLoadAnchorHandler )
CH_DECLARE_MESSAGE_HANDLER( animatorLoadSceneHandler )
CH_DECLARE_MESSAGE_HANDLER( animatorPlayGraphicHandler )
CH_DECLARE_MESSAGE_HANDLER( animatorShowCastHandler )
CH_DECLARE_MESSAGE_HANDLER( animatorEnableDragHandler )
#else
CH_DECLARE_MESSAGE_HANDLER( animatorShowModuleHandler )
CH_DECLARE_MESSAGE_HANDLER( animatorInstallHookHandler )
CH_DECLARE_MESSAGE_HANDLER( animatorPromoteHookHandler )
CH_DECLARE_MESSAGE_HANDLER( animatorUninstallHookHandler )
CH_DECLARE_MESSAGE_HANDLER( animatorPaletteChangeHandler )
#endif



static ChMsgHandlerDesc	animatorHandlers[] =
							{	{CH_MSG_INIT, 			animatorInitHandler},
								{CH_MSG_LOAD_COMPLETE,	animatorLoadCompleteHandler},
								{CH_MSG_LOAD_ERROR,		animatorLoadErrorHandler},
								{CH_MSG_LOAD_IMAGE,		animatorLoadImageHandler},
								{CH_MSG_LOAD_CAST,		animatorLoadCastHandler},
								{CH_MSG_LOAD_ANCHOR,	animatorLoadAnchorHandler},
								{CH_MSG_LOAD_SCENE,		animatorLoadSceneHandler},
								{CH_MSG_PLAY_GRAPHIC,	animatorPlayGraphicHandler},
								{CH_MSG_SHOW_CAST,		animatorShowCastHandler},
								{CH_MSG_ENABLE_DRAG,	animatorEnableDragHandler}
							};


/*----------------------------------------------------------------------------
	ChAnimMainInfo class
----------------------------------------------------------------------------*/

ChAnimMainInfo::ChAnimMainInfo( ChModuleID idModule,
										ChCore* pCore ) :
					ChGraphicMainInfo( idModule, pCore )
{
	ChPane*		pPane = GetPaneMgr()->FindPane( ChPaneMgr::strGraphicName );
	CRect		rtChild( -100, -100, -1, -1 );

	ComputeDesiredSize();

	m_pWnd = new ChAnimView( this );
	bool boolCreated = GetView()->Create( rtChild, pPane->GetFrameWnd() );
	ASSERT( boolCreated );

	GetView()->SetCmdHookMgr( &m_hookMgr );
	m_pStartReq = new ChAnimStartHTTPReq( GetView(), "" );
}


ChAnimMainInfo::~ChAnimMainInfo()
{
	ChPane*		pPane = GetPaneMgr()->FindPane( ChPaneMgr::strGraphicName );

	ASSERT( 0 != pPane );

	if ((GetView() == pPane->GetWindow()) &&
		(pPane->GetModuleID() == GetModuleID()))
	{
											// Remove the window from the pane
		pPane->SetOwner( 0, 0, 0 );
	}
											// Destroy the window
	if (GetView())
	{
		GetView()->DestroyWindow();
		delete m_pWnd;
		m_pWnd = 0;
	}

}


void ChAnimMainInfo::RegisterDispatchers()
{
	chint16		sHandlerCount = sizeof( animatorHandlers ) /
								sizeof( ChMsgHandlerDesc );

	ChGraphicMainInfo::RegisterDispatchers();	  // inherit handlers
	m_graphicDispatcher.AddHandler( animatorHandlers, sHandlerCount );
}


/*----------------------------------------------------------------------------
	Animator module message handlers
----------------------------------------------------------------------------*/

CH_IMPLEMENT_MESSAGE_HANDLER( animatorInitHandler )
{
	ChMazeMainInfo*	pInfo = (ChMazeMainInfo*)pMainInfo;

	pInfo->Initialize();
	return 0;
}



CH_IMPLEMENT_MESSAGE_HANDLER( animatorEnableDragHandler )	 // not implemented
{
	ChAnimMainInfo*		pInfo = (ChAnimMainInfo*)pMainInfo;
	ChEnableDragMsg*	pMsg = (ChEnableDragMsg*)&msg;

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( animatorLoadCompleteHandler )
{
	ChLoadCompleteMsg*	pMsg = (ChLoadCompleteMsg*)&msg;
	string				strURL;
	string				strFilename;
	chparam				userData;
	ChAnimMainInfo*		pInfo = (ChAnimMainInfo*)pMainInfo;
	ChGraphicHTTPReq*	pHTTPReq;
										// Get message params

	pMsg->GetParams( strURL, strFilename, userData );
	pHTTPReq = (ChGraphicHTTPReq*)userData;

	TRACE( "MESSAGE:  CH_MSG_LOAD_COMPLETE (core)\n" );
	TRACE1( "         %s ->\n", (const char*)strURL );
	TRACE1( "         %s\n", (const char*)strFilename );

	switch( pHTTPReq->GetType() )
	{
		case ChGraphicHTTPReq::script:
		{									// Load the Script to the character

			ChAnimScriptHTTPReq*	pReq = (ChAnimScriptHTTPReq*)pHTTPReq;

											// Load a script from a file
 			pReq->Load( strFilename, pInfo );
											// It will delete itself if done
			break;
		}

		case ChGraphicHTTPReq::anchor:
		{
			ChAnimAnchorHTTPReq*	pReq = (ChAnimAnchorHTTPReq*)pHTTPReq;

											// Load a file of anchors

 			pInfo->GetView()->LoadAnchors( strFilename ); // !!!oughta move this method to AnchorReq
			delete pHTTPReq;
			break;
		}

		case ChGraphicHTTPReq::cast:
		{
			ChAnimCastHTTPReq*	pReq = (ChAnimCastHTTPReq*)pHTTPReq;

											// Load a file of cast members
 			pReq->Load( strFilename, pInfo );
			delete pReq;					/* It's done, although it may have
												spawned more */
			break;
		}

		case ChGraphicHTTPReq::sprite:
		{									// Load the sprite to the character

			ChAnimSpriteHTTPReq*	pReq = (ChAnimSpriteHTTPReq*)pHTTPReq;

											// Load a file of cast members
 			pReq->Load( strFilename, pInfo );
											// It will delete itself if done
			break;
		}

		case ChGraphicHTTPReq::background:
		{									// Load the background

 			ChAnimBackgroundHTTPReq*	pReq = (ChAnimBackgroundHTTPReq*)pHTTPReq;

			pInfo->GetView()->Invalidate( true );
			pInfo->GetView()->LoadBackground( strFilename );

											// oughta be this dependency

			ASSERT( pReq == pInfo->GetLeafDependent() );

			pInfo->SetLeafDependent( 0 );
			delete pReq;
			break;
		}

		default:
		{
			break;
		}
	}

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( animatorLoadErrorHandler )
{
	ChLoadErrorMsg*		pMsg = (ChLoadErrorMsg*)&msg;
	string				strModuleName;
	ChModuleID			idModule;
	string				strURL;
	chint32				lError;
	chparam				userData;
	ChGraphicHTTPReq*	pHTTPReq;

	pMsg->GetParams( strModuleName, idModule, strURL, lError, userData );
	pHTTPReq = (ChGraphicHTTPReq *)userData;

	delete pHTTPReq;						// Clean up
	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( animatorLoadImageHandler )
{
	ChAnimMainInfo*	pInfo = (ChAnimMainInfo*)pMainInfo;

											/* for now, assumes URL is just
												a file */
											// !!!!!!!!!!!!
	#if 0
	{
		ChImageMsg*					pMsg = (ChImageMsg*)&msg;
		string						strURL;
		ChAnimBackgroundHTTPReq*	pHTTPReq

		pMsg->GetParams( strURL );
		pHTTPReq = new ChAnimBackgroundHTTPReq ( pInfo->GetView(), strURL );

		//boolSuccess =
		// "http://www.chaco.com/pueblo/ChAnim/msw32/snow.bmp"

		pInfo->GetHTTPConn()->GetURL( strURL, (chparam)pHTTPReq );
		pInfo->SetLeafDependent( pHTTPReq );
	}
	#endif

	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( animatorLoadCastHandler )
{
	ChAnimMainInfo*	pInfo = (ChAnimMainInfo*)pMainInfo;
	// for now, assumes sprite URL is just a file
	// !!!!!!!!!!!!
	//ChArchive	archive( pMsg, modeRead );

	ChCastMsg *pMsg = (ChCastMsg *)&msg;

#if 0 // oblsoete forms
	if(pMsg->GetType() == ChCastMsg::direct)
	{
		ChAnimCastMember *pChar = new ChAnimCastMember;
  		CPhasedSprite* pSprite;

		pChar->InitFromMsg( pMsg );

		if(!pChar->GetScriptCells())
		{
			//boolSuccess = GetHTTPConn()->GetURL( pChar->GetScriptURL(), (chparam)pHTTPCharReq );
		}

		//ChGraphicHTTPReq *pHTTPReq = new ChGraphicHTTPReq ( ChGraphicHTTPReq::script, pChar );
		//boolSuccess =
		// "http://www.chaco.com/pueblo/ChText/msw32/ChText.dll"
		//pInfo->GetHTTPConn()->GetURL( pChar->GetSpriteURL(), (chparam)pHTTPReq );
												// following needs to get changed when we go asynch
		string strSpriteURL = pChar->GetSpriteURL();
		pSprite = pChar->GetSprite();
		int iNumSpriteRows = pSprite->GetNumCellRows();	   // retain the grid, it gets
		int iNumSpriteCols = pSprite->GetNumCellColumns();// wiped out by pSprite->Initialize
		pSprite->Load( (char *)(LPCTSTR(strSpriteURL)));
		pSprite->Initialize();
		pSprite->SetNumCellRows(iNumSpriteRows);		   // restore grid
		pSprite->SetNumCellColumns(iNumSpriteCols);
		pChar->SetSprite(pSprite);

		pInfo->GetView()->AddCharacter(pChar); // AddCharacter consumes pChar
	}
	else if(pMsg->GetType() == ChCastMsg::url)
	{
		string strURL;
		pMsg->GetParams( strURL );

		ChAnimCastHTTPReq *pHTTPReq = new ChAnimCastHTTPReq ( pInfo->GetView(), strURL );
		if (pInfo->GetRootDependent())
		{
			pInfo->GetRootDependent()->Add(pHTTPReq);
		}


		pInfo->GetHTTPConn()->GetURL( strURL, (chparam)pHTTPReq );
	}
	else
	#endif // obsolete forms

	if(pMsg->GetType() == ChCastMsg::remove)
	{
		chuint32 luId;
		pMsg->GetParams( luId );
		pInfo->GetView()->DeleteCharacter(luId);
	}

	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( animatorLoadAnchorHandler )
{
	ChAnimMainInfo*	pInfo = (ChAnimMainInfo*)pMainInfo;
	ChAnchorMsg*	pMsg = (ChAnchorMsg*)&msg;

	switch ( pMsg->GetType() )
	{
		case ChAnchorMsg::direct_rect:
		{
			ChAnimAnchor*	pAnchor = new ChAnimAnchor;

			pMsg->GetParams( pAnchor->m_id, pAnchor->m_rcHot,
								pAnchor->m_strCmdArg, pAnchor->m_strHint,
								pAnchor->m_cursor );
			pInfo->GetView()->AddAnchor( pAnchor );
			break;
		}

		case ChAnchorMsg::url:
		{
			string					strURL;
			ChAnimAnchorHTTPReq*	pHTTPReq;

			pMsg->GetParams( strURL );
			pHTTPReq = new ChAnimAnchorHTTPReq ( pInfo->GetView(), strURL );
			pInfo->GetCore()->GetURL( strURL, 0, pInfo->GetStream(), (chparam)pHTTPReq );
			break;
		}

		case ChAnchorMsg::direct_cast:
		{
			ChAnimAnchor*	pAnchor = new ChAnimAnchor;
			pMsg->GetParams( pAnchor->m_id, pAnchor->m_hotCastId,
								pAnchor->m_strCmdArg, pAnchor->m_strHint,
								pAnchor->m_cursor );
			pInfo->GetView()->AddAnchor( pAnchor );
			break;
		}

		case ChAnchorMsg::remove:
		{
			chuint32	id;

			pMsg->GetParams(id );
			if (id)
			{
				pInfo->GetView()->DeleteAnchor( id );
			}
			else
			{
				pInfo->GetView()->DeleteAnchors();
			}
			break;
		}

		default:
		{
			break;
		}
	}

	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( animatorLoadSceneHandler )
{
	ChAnimMainInfo*	pInfo = (ChAnimMainInfo*)pMainInfo;
	ChSceneMsg *pMsg = (ChSceneMsg *)&msg;

	string strURL;
	string strFilename;					// TODO ???????? !!!!!!!!! Replace this with pane version
	string strType;
	bool	boolNew;
	pMsg->GetParams(strURL, strFilename, strType, boolNew);
	//if(!strURL.IsEmpty() || !strFilename.IsEmpty())
	{

		#pragma message ("Animation scene loading not done")
		//ChAnimSceneHTTPReq *pHTTPReq = new ChAnimSceneHTTPReq ( pInfo->GetView(), strURL );


		// Need to switch on mime type, create appropriate httpreq, then load the file
		//typeText, typeHTML, typeGIF, typeMidi, typeWave, typeJPEG,
							//	typeVRML,	typeBMP
	 	ChHTTPConn::tagMimeTypes type = (ChHTTPConn::tagMimeTypes)ChHTTPConn::GetMimeType(strType);
		switch(type)
		{
			case ChHTTPConn::typeGIF :
			{
												// Load the background
	 			ChAnimBackgroundHTTPReq req(pInfo->GetView(), strURL);
				pInfo->SetLeafDependent(&req);
				pInfo->ShowModule(true);
				pInfo->GetView()->Invalidate(true);
				pInfo->GetView()->LoadBackgroundGIF(strFilename);
				pInfo->GetView()->UpdateWindow();
				pInfo->SetLeafDependent(0);
				break;
			}
			case ChHTTPConn::typeJPEG :
			{
												// Load the background
	 			ChAnimBackgroundHTTPReq req(pInfo->GetView(), strURL);
				pInfo->SetLeafDependent(&req);
				pInfo->ShowModule(true);
				pInfo->GetView()->Invalidate(true);
				pInfo->GetView()->LoadBackgroundJPEG(strFilename);
				pInfo->GetView()->UpdateWindow();
				pInfo->SetLeafDependent(0);
				break;
			}
			case ChHTTPConn::typeBMP :
			{
												// Load the background
	 			ChAnimBackgroundHTTPReq req(pInfo->GetView(), strURL);
				pInfo->SetLeafDependent(&req);
				pInfo->ShowModule(true);
				pInfo->GetView()->Invalidate(true);
				pInfo->GetView()->LoadBackground(strFilename);
				pInfo->GetView()->UpdateWindow();
				pInfo->SetLeafDependent(0);
				break;
			}
			case ChHTTPConn::typeText :
			{
				// assume it's an animation file??
				ChAnimSceneHTTPReq *pHTTPReq = new ChAnimSceneHTTPReq ( pInfo->GetView(), strURL );
				break;
			}
			default:
			{
				break;
			}
		}
		#if 0
		ChAnimSceneHTTPReq *pHTTPReq = new ChAnimSceneHTTPReq ( pInfo->GetView(), strURL );

		pInfo->GetHTTPConn()->GetURL( strURL, (chparam)pHTTPReq );
		//////////////
		if(boolNew)
		{
			pInfo->SetLeafDependent(pHTTPReq);
		}
		else
		{
			if (pInfo->GetRootDependent())
			{
				pInfo->GetRootDependent()->Add(pHTTPReq);
			}
		}
		#endif
	}
	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( animatorPlayGraphicHandler )
{
	ChAnimMainInfo*			pInfo = (ChAnimMainInfo*)pMainInfo;
	ChPlayGraphicMsg*		pMsg = (ChPlayGraphicMsg*)&msg;
	chuint32				luId = 0;
	bool					boolPlay = true;
	ChPlayGraphicMsg::type	when;

	pMsg->GetParams( luId, boolPlay, when );
	if (!luId)
	{
		switch( when )
		{
			case ChPlayGraphicMsg::immediate:
			{
				pInfo->GetView()->Animate( boolPlay );
				break;
			}
			case ChPlayGraphicMsg::on_load_complete:
			{
				pInfo->GetRootDependent()->SetStartAnimating( boolPlay );
				break;
			}
		}
	}
	else
	{
		pInfo->GetView()->AnimateCharacter( luId, boolPlay );
	}

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( animatorShowCastHandler )
{
	ChAnimMainInfo*	pInfo = (ChAnimMainInfo*)pMainInfo;
	ChShowCastMsg*	pMsg = (ChShowCastMsg*)&msg;
	bool			boolShow = true;
	chuint32		luId;

	pMsg->GetParams( luId, boolShow );
	pInfo->GetView()->ShowCharacter( luId, boolShow );

	return 0;
}
