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

	Defines the ChAd module for the Pueblo system.  This module is
	used to play MIDI music.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChAd/ChAd.cpp,v 1.24 1996/04/16 05:11:06 coyote Exp $

#include "headers.h"
#include "resource.h"

#if defined( CH_UNIX )

	#include <ChDispat.h>
	#include <ChMsgTyp.h>
	#include <ChReg.h>
	#include "../../unix/ChTxtMud/UnixRes.h"

#endif	// defined( CH_UNIX )

#include <fstream.h>

#include <ChMsgTyp.h>
#include <ChExcept.h>
#include <ChMenu.h>
#include <ChCore.h>
#include <ChHttp.h>
#include <ChHtmWnd.h>
#include <ChPane.h>

#include "ChAdHtml.h"

#include <ChAd.h>


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define DEFAULT_AD_WIDTH		460			// In pixels
#define DEFAULT_AD_HEIGHT		60			// In pixels

#define AD_BANNER_NAME			"_Ad_Module_Banner_Pane_"


/*----------------------------------------------------------------------------
	Handler declarations
----------------------------------------------------------------------------*/

CH_DECLARE_MESSAGE_HANDLER( defAdHandler )
CH_DECLARE_MESSAGE_HANDLER( adInitHandler )
CH_DECLARE_MESSAGE_HANDLER( adShowModuleHandler )
CH_DECLARE_MESSAGE_HANDLER( adLoadCompleteHandler )
CH_DECLARE_MESSAGE_HANDLER( adLoadErrorHandler )
CH_DECLARE_MESSAGE_HANDLER( adGetPageCountHandler )
CH_DECLARE_MESSAGE_HANDLER( adHandler )

static ChMsgHandlerDesc	adHandlers[] =
					{	{CH_MSG_INIT, adInitHandler},
						{CH_MSG_SHOW_MODULE, adShowModuleHandler},
						{CH_MSG_LOAD_COMPLETE, adLoadCompleteHandler},
						{CH_MSG_LOAD_ERROR, adLoadErrorHandler},
						{CH_MSG_GET_PAGE_COUNT, adGetPageCountHandler},
						{CH_MSG_AD, adHandler} };


/*----------------------------------------------------------------------------
	ChAdMainInfo class
----------------------------------------------------------------------------*/

ChAdMainInfo::ChAdMainInfo( const ChModuleID& idModule,
										 ChCore* pCore,
										ChArgumentList* pList  ) :
					ChMainInfo( idModule, pCore ),
//					m_clientCore( ChClientModule::GetCoreID() ),
//					m_serverModule( idServerModule ),
					m_adDispatcher( pCore, idModule, defAdHandler ),
					m_boolShown( false ),
					m_boolMenus( false ),
					m_sAdWidth( DEFAULT_AD_WIDTH ),
					m_sAdHeight( DEFAULT_AD_HEIGHT )
{
	RegisterDispatchers();
}


ChAdMainInfo::~ChAdMainInfo()
{
											// Clear all panes

	GetPaneMgr()->ShowAllPanes( GetModuleID(), false );
	GetPaneMgr()->DestroyAllPanes( GetModuleID() );

	DestroyMenus();
}


void ChAdMainInfo::Initialize()
{
	ChRect		rtChild( -100, -100, -1, -1 );
	bool		boolCreated;
	ChPane*		pPane = GetPaneMgr()->FindPane( AD_BANNER_NAME );

											/* Register ourselves with the Ad
												banner window */
	GetAdBannerWnd()->SetMainInfo( this );

	if (0 == pPane)
	{										/* Create the Ad pane if it doesn't
												already exist */

		pPane = GetPaneMgr()->CreatePane( AD_BANNER_NAME, 0, GetAdWidth(),
											GetAdHeight(),
											paneInternal | paneNoScroll );
	}
	ASSERT( pPane );
											// Create the Ad output window

	boolCreated = GetAdBannerWnd()->Create( rtChild, pPane->GetFrameWnd() );
	ASSERT( boolCreated );
											/* Turn off scrolling for the
												ad banner */
	GetAdBannerWnd()->AllowScroll( false, false );

											// Set the child into the view

	pPane->SetOwner( GetModuleID(), GetAdBannerWnd(), GetAdBannerWnd() );

	CreateMenus();							// Create & Install menus
}


void ChAdMainInfo::ShowModule( bool boolShow )
{
	ChPane*		pPane = GetPaneMgr()->FindPane( AD_BANNER_NAME );

	ASSERT( pPane );

	if (boolShow && !IsShown())
	{
		InstallMenus();

		pPane->Show();

		SetShown( boolShow );
	}
	else if (!boolShow && IsShown())
	{
		UninstallMenus();

		pPane->Show( false );

		SetShown( boolShow );
	}
}


void ChAdMainInfo::DisplayAdBanner( const string& strAdURL,
									const string& strParam,
									const string& strUserParam )
{
	ChPane*			pPane = GetPaneMgr()->FindPane( AD_BANNER_NAME );

	string			strFormat;
	string			strPaneHTML;

	m_strCurrAdURL = strAdURL;
	m_strCurrAdParam = strParam;
	m_strCurrAdUserParam = strUserParam;

	GetAdBannerWnd()->LoadURL( strAdURL );
}


bool ChAdMainInfo::DoAdClick( const string& strArgs, chint32 lX, chint32 lY )
{
	bool		boolProcessed = false;
	string		strURL;
//	ChTime		time;

	if (ChHtmlWnd::GetHTMLHref( strArgs, false, strURL ))
	{
		if (!strURL.IsEmpty())
		{
			//string		strParam( m_strCurrAdUserParam );

			if ((lX >= 0) && (lY >= 0))
			{								/* Append the coordinates to the
												URL */
				char	buffer[80];

				sprintf( buffer, "?%ld,%ld", lX, lY );
				strURL += buffer;
			}

			#if 0
			if (strParam.IsEmpty())
			{
											/* If there isn't a user param
												associated with this ad, then
												send the URL to the server */
				strParam = strURL;
			}
											/* Create and send the statistic
												message to the server
												indicating that the ad was
												selected */

			ChUsageStatisticMsg	statisticMsg( ChUsageStatisticMsg::adSelected,
												ChTime::GetCurrentTime(),
												strParam );

			m_serverModule.Post( statisticMsg );
			#else
			TRACE( "Need to send Ad info to server\n" );
			#pragma message( "Sending Ad info to server not done\n" __FILE__ )
			#endif

											// Load the page
			GetCore()->DisplayWebPage( strURL, ChCore::browserUserPref );

			boolProcessed = true;
		}
	}

	return boolProcessed;
}


/*----------------------------------------------------------------------------
	ChAdMainInfo protected methods
----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
	ChAdMainInfo private methods
----------------------------------------------------------------------------*/

void ChAdMainInfo::RegisterDispatchers()
{
	chint16		sHandlerCount = sizeof( adHandlers ) /
								sizeof( ChMsgHandlerDesc );

	m_adDispatcher.AddHandler( adHandlers, sHandlerCount );
}


void ChAdMainInfo::CreateMenus()
{
	m_boolMenus = true;
}


void ChAdMainInfo::InstallMenus()
{
}


void ChAdMainInfo::UninstallMenus()
{
}


void ChAdMainInfo::DestroyMenus()
{
	m_boolMenus = false;
}


/*----------------------------------------------------------------------------
	Chaco module library entry point
----------------------------------------------------------------------------*/

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
CH_EXTERN_LIBRARY( void )
InitChAdDLL();
#endif

#ifdef __linux__
CH_IMPLEMENT_MAIN_HANDLER( ChMainEntryMidi )
#else
ChMain
#endif
{
	chparam		retVal = 0;

	switch( msg.GetMessage() )
	{
		case CH_MSG_INIT:
		{
			ChInitMsg*	pMsg = (ChInitMsg*)&msg;
			string		strLoadParam;
			ChModuleID	idServerModule;             

			#if defined( CH_MSW ) && defined( CH_ARCH_16 )
			{
											// Initialize MFC
				InitChAdDLL();
			}
			#endif	// defined( CH_MSW ) && defined( CH_ARCH_16 )

			pMsg->GetParams( idModule, strLoadParam, idServerModule );

			if (*pstrModule == CH_MODULE_AD)
			{
				ChAdMainInfo	*pMainInfo;

				pMainInfo = new ChAdMainInfo( idModule, pCore,
												pArgList );

				retVal = (chparam)pMainInfo;
			}
			break;
		}

		case CH_MSG_TERM:
		{
			delete pMainInfo;
			break;
		}
	}

	return retVal;
}


/*----------------------------------------------------------------------------
	Chaco message handlers
----------------------------------------------------------------------------*/

CH_IMPLEMENT_MESSAGE_HANDLER( defAdHandler )
{
	chparam		retVal = 0;

	return retVal;
}

CH_IMPLEMENT_MESSAGE_HANDLER( adInitHandler )
{
	ChAdMainInfo*	pInfo = (ChAdMainInfo*)pMainInfo;

	pInfo->Initialize();
	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( adShowModuleHandler )
{
	ChShowModuleMsg*	pMsg = (ChShowModuleMsg*)&msg;
	ChAdMainInfo*		pInfo = (ChAdMainInfo*)pMainInfo;

	pInfo->ShowModule( pMsg->IsShowing() );
	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( adLoadCompleteHandler )
{
	ChAdMainInfo*		pInfo = (ChAdMainInfo*)pMainInfo;
	ChLoadCompleteMsg*	pMsg = (ChLoadCompleteMsg*)&msg;
	string				strModuleName;
	ChModuleID			idModule;
	string				strFilename;
	chparam				userData;

	pMsg->GetParams( strModuleName, idModule, strFilename, userData );

	if (strModuleName.IsEmpty())
	{										/* Not a module, must be data,
												but we aren't expecting data? */
	}

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( adLoadErrorHandler )
{
	ChAdMainInfo*		pInfo = (ChAdMainInfo*)pMainInfo;
	ChLoadErrorMsg*		pMsg = (ChLoadErrorMsg*)&msg;
	string				strModuleName;
	ChModuleID			idModule;
	string				strURL;
	chint32				lError;
	chparam				userData;

	pMsg->GetParams( strModuleName, idModule, strURL, lError, userData );

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( adGetPageCountHandler )
{
	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( adHandler )
{
	ChAdMainInfo*	pInfo = (ChAdMainInfo*)pMainInfo;
	ChAdMsg*		pMsg = (ChAdMsg*)&msg;
	string			strAdURL;
	string			strParam;
	string			strUserParam;

	pMsg->GetParams( strAdURL, strParam, strUserParam );
	pInfo->DisplayAdBanner( strAdURL, strParam, strUserParam );
	return 0;
}
