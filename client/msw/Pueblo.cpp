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

This file includes the code for the main Pueblo client app.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/client/msw/Pueblo.cpp,v 2.38 1996/07/04 22:49:57 coyote Exp $

#include "headers.h"

#include "Pueblo.h"
#include <ChDDE.h>
#include <ChHtpCon.h>
#include <ChTime.h>
#include "ChBaseVw.h"
#include "ChMFrame.h"
#include "ChClCore.h"
#include <ChPblDoc.h>
#include <ChRMenu.h>

#if defined( CH_MSW )
#include <ChSock.h>
#endif

#if !defined( WIN32 )
#include <ctl3d.h>
#endif

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	Global variables
----------------------------------------------------------------------------*/

#if defined( CH_MSW )

CH_GLOBAL_VAR HINSTANCE		hInstApp;

#endif	// defined( CH_MSW )


/*----------------------------------------------------------------------------
	ChApp object -- There is only one of these per application.
----------------------------------------------------------------------------*/

ChApp NEAR		theApp;

ChHTTPDDE*		ChApp::m_pddeConn;



/*----------------------------------------------------------------------------
	Utility functions
----------------------------------------------------------------------------*/

void CALLBACK AppTickProc( HWND hWnd, UINT uiMsg, UINT idEvent, DWORD dwTime )
{
	theApp.OnSecondTick( time(0) );
}



/*----------------------------------------------------------------------------
	ChApp class
----------------------------------------------------------------------------*/

BEGIN_MESSAGE_MAP( ChApp, CWinApp )
	//{{AFX_MSG_MAP(ChApp)
	ON_COMMAND(ID_FILE_NEW, OnNewPuebloFrame)
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW, OnUpdateNewPuebloFrame)
	//}}AFX_MSG_MAP
											/* Standard file based document
												commands */
	ON_COMMAND( ID_FILE_NEW, CWinApp::OnFileNew )
	ON_COMMAND( ID_FILE_OPEN, CWinApp::OnFileOpen )

											// Standard print setup command

	ON_COMMAND( ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup )

END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChApp::ChApp

		Constructor for the ChApp class.
----------------------------------------------------------------------------*/

ChApp::ChApp() :
		//	m_boolCommandLineUsed( false )
		m_pCurrMenuMgr( 0 ),
		m_pCurrFrame( 0 ),
		m_boolInDelete( 0 ),
		m_uiTimerID( 0 )
{
	hInstApp = 0;
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChApp::~ChApp

------------------------------------------------------------------------------

	Destructor for the ChApp class.

----------------------------------------------------------------------------*/

ChApp::~ChApp()
{
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChApp::InitInstance

------------------------------------------------------------------------------

	Initialize the Application instance.

----------------------------------------------------------------------------*/

BOOL ChApp::InitInstance()
{
	CSingleDocTemplate	*pDocTemplate;
											// Store the instance identifier
	hInstApp = m_hInstance;
											/* Set a registry key to be used
												for MFC internals */
	#if defined( WIN32 )
	{
		SetRegistryKey( CH_COMPANY_NAME );
											/* Enable 3 dimensional control
												appearance */
		Enable3dControls();
	}
	#else
	{
	  	Ctl3dRegister( m_hInstance );
	   	Ctl3dAutoSubclass( m_hInstance );
	}
	#endif

	#if defined( CH_MSW )
	{										// Initialize socket extension
		AfxSocketInit();
		ChChacoSocket::InitWinsockNotification( m_hInstance );
	}
	#endif

	// Create the timer for all our UI and module tick notification
	m_uiTimerID = ::SetTimer( 0, 0, 1000, AppTickProc );

											/* Create and display the splash
												screen */
	if (m_splash.Create( 0 ))
	{
		m_splash.SetWindowPos( &CWnd::wndTopMost, 0, 0, 0, 0,
								SWP_SHOWWINDOW| SWP_NOSIZE | SWP_NOMOVE );
		m_splash.UpdateWindow();
	}
											/* Load standard INI file
												options */
	LoadStdProfileSettings( 0 );
											/* Register the application's
												document templates.  Document
												templates serve as the
												connection between documents,
												frame windows and views. */
	pDocTemplate =
		new CSingleDocTemplate( IDR_MAINFRAME, RUNTIME_CLASS( ChPuebloDoc ),
								RUNTIME_CLASS( ChMainFrame ),
								RUNTIME_CLASS( ChBaseView ) );
	AddDocTemplate( pDocTemplate );
											// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes();
											// Simple command line parsing
	OnFileNew();

	ASSERT( m_pMainWnd );
											// Create the DDE conn object
	m_pddeConn = new ChHTTPDDE( 0 );
	ASSERT( m_pddeConn );

	ChMainFrame* pFrame = (ChMainFrame*)m_pMainWnd;

											// Enable drag/drop open
	pFrame->DragAcceptFiles();

	chuint			startOptions = 0;
	string			strCmdLine( m_lpCmdLine );
	ChRegistry		appReg( CH_MISC_GROUP );
	string			strAcceptedVersion;
	ChClientInfo	clientInfo( ChClientInfo::thisMachine );
	string			strClientVersion;

	strClientVersion = clientInfo.GetClientVersion().Format();

	appReg.Read( CH_MISC_LICENSE_ACCEPTED, strAcceptedVersion, "" );

											/* Do we need to display the
												license dialog ? */

	if (strAcceptedVersion != strClientVersion)
	{
		startOptions |= ChClientCore::doLicense;
	}

	if (TimeToRegister())
	{
		startOptions |=  ChClientCore::doRegistration;
	}

	#if defined( _DEBUG )
	{										/* For debugging purpose, keep
												the shift key down to start
												the registration wizard */
		if (GetKeyState( VK_SHIFT ) & 0x8000)
		{
			startOptions |= ChClientCore::doRegistration;
		}
	}
	#endif	// defined( _DEBUG )
											// Start Pueblo

	if (startOptions || !strCmdLine.IsEmpty())
	{										/* Initialization of Pueblo is
												done, remove the splash
												screen */
		m_splash.DestroyWindow();
	}

	pFrame->GetPuebloCore()->StartPueblo( strCmdLine,
											startOptions |
												ChClientCore::doLoginNotify );

	if (!startOptions && strCmdLine.IsEmpty())
	{										/* Initialization of Pueblo is
												done, remove the splash
												screen */
		m_splash.DestroyWindow();
	}

	return( true );
}


/*----------------------------------------------------------------------------
	ChApp::ExitInstance

		Cleanup the Application instance.
----------------------------------------------------------------------------*/

int ChApp::ExitInstance()
{

	if (m_uiTimerID)
	{										// Turn off the timer
		::KillTimer( 0, m_uiTimerID );
	}

	if (m_pddeConn)
	{
		delete m_pddeConn;
		m_pddeConn = 0;
	}

	ChHTTPSocketConn::EnforceCacheLimit();

  	return ( 0 ); // return code
}


/*----------------------------------------------------------------------------
	ChApp misc. command handlers
----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------

	FUNCTION	||	ChApp::PreTranslateMessage

	RETURNS		||	true to abort processing, and false to continue
					processing.

------------------------------------------------------------------------------

	This function will be called before translating messages in the message
	loop.  We hook here to destroy the splash screen when we enter the
	message loop.  We also use this opportunity to catch messages from
	threads.

----------------------------------------------------------------------------*/

BOOL ChApp::PreTranslateMessage( MSG* pMsg )
{
	BOOL boolFinished = CWinApp::PreTranslateMessage( pMsg );

	if (!boolFinished)
	{
		if (CWinThread::m_pMainWnd  != (CWnd*)m_pCurrFrame)
		{
			if (m_pFrameList.FindValue( (chparam)CWinThread::m_pMainWnd ))
			{
				m_pCurrFrame = (CFrameWnd*)CWinThread::m_pMainWnd;
				m_pCurrMenuMgr = ((ChMainFrame*)m_pCurrFrame)->GetPuebloCore()->GetMenuMgr();
			}
			else
			{
				m_pCurrMenuMgr = 0;
				m_pCurrFrame = 0;
			}
		}

		if (m_pCurrMenuMgr)
		{
			boolFinished = m_pCurrMenuMgr->TranslateAccelerators(
								CWinThread::m_pMainWnd->GetSafeHwnd(), pMsg);
		}
	}

	return boolFinished;
}


CDocument* ChApp::OpenDocumentFile( LPCTSTR lpszFileName )
{
	return 0;
}


ChHTTPDDE* ChApp::GetDDEConn()
{
	return ChApp::m_pddeConn;
}


bool ChApp::OnDDECommand( LPTSTR lpszCommand )
{
	return CWinApp::OnDDECommand( lpszCommand );
}


/*----------------------------------------------------------------------------
	ChApp::TimeToRegister
	
	Check if it is time to send registration info.
----------------------------------------------------------------------------*/
	
bool ChApp::TimeToRegister()
{
	ChRegistry	timeToRegister( CH_GENERAL_GROUP );
	chuint32	luTime;
	time_t		currTime = time( 0 );

	if (timeToRegister.Read( CH_PRODUCT_ID, luTime ) && luTime)
	{
		chint32		lRegistered;
											/* Check if we have already
												registered */

		if (timeToRegister.Read( CH_REGISTERED, lRegistered ))
		{
			if (CH_UNREGISTERED_USER == lRegistered)
			{
				if ((chuint32)currTime > luTime)
				{
					return true;
				}
			}
			else if (CH_REGISTERED_USER == lRegistered)
			{
											/* User has registered but not
												notified yet, send info to
												user */
				return true;
			}
		}
	}
	else
	{										/* New installation, mark the time
												and say not registred */

		currTime += REG_PROMPT_DAYS * SECONDS_IN_A_DAY;

		timeToRegister.Write( CH_PRODUCT_ID, (chuint32)currTime );
		timeToRegister.Write( CH_REGISTERED, CH_UNREGISTERED_USER );
	}

	return false;
}

