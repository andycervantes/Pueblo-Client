/*----------------------------------------------------------------------------

            .###.  ###     ###       ,#,          .###.    ,#######,
         ,####""   ###    .###     ,##'##,     ,####""   .##'    `##.
        ###        ###########    ,##' `##,   ###       ####      ####
        ###..      ###'    ###  ,###########, ####..    `###,    ,##'
          `######  ###     ###  `##'     `##'   `######   `########'


	Copyright 1995, Chaco Communications, Inc. All rights reserved.
	Unpublished -- Rights reserved under the copyright laws of the United
	States.  Use of a copyright notice is precautionary only and does no
	imply publication or disclosure.

	This software contains confidential information and trade secrets of
	Chaco Communications, Inc.  Use, disclosure, or reproduction is
	prohibited without the prior express written permission of Chaco
	Communications, Inc.

	RESTRICTED RIGHTS LEGEND

	Use, duplication, or disclosure by the Government is subject to
	restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
	Technical Data and Computer Software clause at DFARS 252.227-7013.

	Chaco Communications, Inc.
	10164 Parkwood Drive, Suite 8, Cupertino, CA, 95014-1533

------------------------------------------------------------------------------

This file includes the code for the main Pueblo client app.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WebBrwsr/Pueblo.cpp,v 1.2 1996/07/02 19:57:32 pritham Exp $

#include "stdafx.h"

#include <ChReg.h>
#include <ChHtpCon.h>
#include <ChWebTracker.h>

#include "Pueblo.h"



#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	Static variables:
----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------
	ChApp object -- There is only one of these per application.
----------------------------------------------------------------------------*/

ChApp	NEAR	theApp;       


/*----------------------------------------------------------------------------
	ChApp class
----------------------------------------------------------------------------*/

BEGIN_MESSAGE_MAP( ChApp, CWinApp )
	//{{AFX_MSG_MAP(ChApp)
	//}}AFX_MSG_MAP
	
END_MESSAGE_MAP()

/*----------------------------------------------------------------------------

	FUNCTION	||	ChApp::ChApp

------------------------------------------------------------------------------

	Constructor for the ChApp class.

----------------------------------------------------------------------------*/

ChApp::ChApp()
{										
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChApp::ChApp

------------------------------------------------------------------------------

	Constructor for the ChApp class.

----------------------------------------------------------------------------*/

ChApp::~ChApp()
{											// Unregister the core module
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChApp::InitInstance

------------------------------------------------------------------------------

	Initialize the Application instance.

----------------------------------------------------------------------------*/

bool ChApp::InitInstance()
{


	CSingleDocTemplate	*pDocTemplate;
											/* Set a registry key to be used
												for MFC internals */
	{
		SetRegistryKey( CH_COMPANY_NAME );
											/* Enable 3 dimensional control
												appearance */
		Enable3dControls();
	}
	
	#if defined( CH_MSW )
	{										// Initialize socket extension
		AfxSocketInit();
	}
	#endif
	
											/* Load standard INI file
												options */
	LoadStdProfileSettings( 0 );
	
	
											/* Register the application's
												document templates.  Document
												templates serve as the
												connection between documents,
												frame windows and views. */
	pDocTemplate =	ChWebTracker::GetDocumentTemplate();

	AddDocTemplate( pDocTemplate );
											// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes();

											// Simple command line parsing
	if (m_lpCmdLine[0] == '\0')
	{
											// Create a new (empty) document
		OnFileNew();
	}
	else
	{
											// Open an existing document
		OpenDocumentFile( m_lpCmdLine );
	}

											// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();

	return( true );
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChApp::ExitInstance

------------------------------------------------------------------------------

	Cleanup the Application instance.

----------------------------------------------------------------------------*/

int ChApp::ExitInstance()
{   
	ChHTTPSocketConn::EnforceCacheLimit();       
	#if defined( CH_ARCH_16 )
  	Ctl3dUnregister( m_hInstance );
	#endif
  	return ( 0 ); // return code
}



/*============================================================================
				ChApp misc. command handlers
============================================================================*/


/*----------------------------------------------------------------------------

	FUNCTION	||	ChApp::OnIdle

------------------------------------------------------------------------------

	This function will be called every time the application is idle.  We
	use this to dismiss the splash screen whenever there is time available.

----------------------------------------------------------------------------*/

bool ChApp::OnIdle( LONG lCount )
{
	bool	boolMoreIdleDesired;
											// call base class idle first

	boolMoreIdleDesired = CWinApp::OnIdle( lCount );


#if 0											// then do our work
	if (m_splash.m_hWnd != 0)
	{										/* There is currently an existing
												splash screen */

		if (::GetCurrentTime() - m_luSplashTime > 10000)
		{
											/* timeout expired, destroy the
												splash window */
			m_splash.DestroyWindow();
			m_pMainWnd->UpdateWindow();
											/* NOTE: don't set bResult to
												false, CWinApp::OnIdle may
												have returned true */
		}
		else
		{									// Check again later...
			boolMoreIdleDesired = true;
		}
	}
	#endif

	return( boolMoreIdleDesired );
}


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

bool ChApp::PreTranslateMessage( MSG* pMsg )
{
	bool boolFinished = CWinApp::PreTranslateMessage( pMsg );
	if( !boolFinished )
	{
		CWnd* pMainWnd = AfxGetMainWnd();
	}

	#if 0
	if (m_splash.m_hWnd != 0 &&
		(pMsg->message == WM_KEYDOWN ||
		 pMsg->message == WM_SYSKEYDOWN ||
		 pMsg->message == WM_LBUTTONDOWN ||
		 pMsg->message == WM_RBUTTONDOWN ||
		 pMsg->message == WM_MBUTTONDOWN ||
		 pMsg->message == WM_NCLBUTTONDOWN ||
		 pMsg->message == WM_NCRBUTTONDOWN ||
		 pMsg->message == WM_NCMBUTTONDOWN))
	{
		m_splash.DestroyWindow();
		m_pMainWnd->UpdateWindow();
	}
	#endif
	
	return boolFinished;
}


