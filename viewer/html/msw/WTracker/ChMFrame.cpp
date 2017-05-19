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

	This file consists of the ChMainFrame class implementation.  This is
	the top-level frame.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChMFrame.cpp,v 1.8 1996/07/02 19:57:29 pritham Exp $

#include "stdafx.h"
#include <ChConst.h>
#include <ChReg.h>
#include <ChHtpCon.h>
#include <ChUtil.h>
#include <ChImgUtil.h>

#include "resource.h"
#include "ChAbout.h"
#include "ChPrefs.h"
#include "ChPrNet.h"
#include "ChPrFont.h"
#include "OpenLoc.h"
#include "ChMFrame.h"

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA    
#endif

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif



/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define  TOOL_BAR_VISIBLE		0x0001
#define  STATUS_BAR_VISIBLE		0x0002


#define APP_STATE 									TEXT( "Window size" )
#define APP_POS										TEXT( "Rect" )
#define APP_SHOWSTATEMAX							TEXT( "max" )
#define APP_SHOWSTATEICON							TEXT( "icon" )
#define APP_TOOLBAR									TEXT( "tool" )					
#define APP_STATUSBAR								TEXT( "status" )

#define CH_STATUS_PROGRESS_PANE		1

CBrush	ChMainFrame::m_brClearProgress;
CBrush	ChMainFrame::m_brShowProgress;

/*----------------------------------------------------------------------------
	Forward declarations
----------------------------------------------------------------------------*/
CH_EXTERN_VAR AFX_EXTENSION_MODULE WTrackerDLL;

/*----------------------------------------------------------------------------
	ChMainFrame class
----------------------------------------------------------------------------*/

IMPLEMENT_DYNCREATE( ChMainFrame, CFrameWnd )

BEGIN_MESSAGE_MAP( ChMainFrame, CFrameWnd )
	//{{AFX_MSG_MAP(ChMainFrame)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_PALETTECHANGED()
	ON_WM_QUERYNEWPALETTE()
	ON_WM_TIMER()
	ON_WM_ACTIVATE()
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_FILE_OPEN_LOC, OnFileOpenLoc)
	ON_COMMAND(ID_GO_BACK, OnGoBack)
	ON_UPDATE_COMMAND_UI(ID_GO_BACK, OnUpdateGoBack)
	ON_COMMAND(ID_GO_FORWARD, OnGoForward)
	ON_UPDATE_COMMAND_UI(ID_GO_FORWARD, OnUpdateGoForward)
	ON_COMMAND(ID_GO_HOME, OnGoHome)
	ON_COMMAND(ID_GO_STOP_LOADING, OnGoStopLoading)
	ON_COMMAND(ID_VIEW_REFRESH, OnViewRefresh)
	ON_COMMAND(ID_VIEW_RELOAD, OnViewReload)
	ON_UPDATE_COMMAND_UI(ID_VIEW_RELOAD, OnUpdateViewReload)
	ON_UPDATE_COMMAND_UI(ID_VIEW_REFRESH, OnUpdateViewRefresh)
	ON_UPDATE_COMMAND_UI(ID_GO_STOP_LOADING, OnUpdateGoStopLoading)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_EDIT_PREFERENCES, OnEditPreferences)
	ON_UPDATE_COMMAND_UI(ID_GO_HOME, OnUpdateGoHome)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_APP_EXIT, OnFrameClose)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	//}}AFX_MSG_MAP
											// Global help commands

	ON_COMMAND( ID_HELP_INDEX, CFrameWnd::OnHelpIndex )
	ON_COMMAND( ID_HELP_USING, CFrameWnd::OnHelpUsing )
	ON_COMMAND( ID_HELP, CFrameWnd::OnHelp )
	ON_COMMAND( ID_CONTEXT_HELP, CFrameWnd::OnContextHelp )
	ON_COMMAND( ID_DEFAULT_HELP, CFrameWnd::OnHelpIndex )   
END_MESSAGE_MAP()

											/* arrays of IDs used to
												initialize control bars --
												first initialize the
												toolbar buttons (IDs are
												command buttons) */
static UINT BASED_CODE buttons[] =
{											/* Same order as in the bitmap
												'toolbar.bmp' */
	ID_GO_BACK,
	ID_GO_FORWARD,
	ID_GO_HOME,
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_FILE_OPEN_LOC,
	ID_EDIT_FIND,
	ID_FILE_PRINT,
	ID_EDIT_COPY,
	ID_SEPARATOR,
	ID_GO_STOP_LOADING,
	ID_SEPARATOR,
	ID_APP_ABOUT,
//	ID_CONTEXT_HELP,
};

static UINT BASED_CODE indicators[] =
{											// Status line indicators
	ID_SEPARATOR,							
	IDS_PROGRESS_BAR							// Progress bar
};



/*----------------------------------------------------------------------------
	ChMainFrame class implementation
----------------------------------------------------------------------------*/

string		ChMainFrame::m_strClass;


ChMainFrame::ChMainFrame() : m_sProgressWidth( 0 ),
							 m_idTimer( 0 ), m_boolInProgress( false ),
							 m_boolUpdate( false ),
							 m_httpConn( 0, ChHTTPConn::connLocalState ),
							 m_hResourceOld( 0 ),
							#ifdef CH_MSW
								 m_pAppFont( 0 )
							#endif

{

	#ifdef CH_MSW
	if (0 == m_strClass.GetLength())
	{
		HICON		hIcon = AfxGetApp()->LoadIcon( IDR_MAINFRAME );

		m_strClass = AfxRegisterWndClass( 0, LoadCursor( 0, IDC_ARROW ),
											(HBRUSH)(COLOR_WINDOW + 1),
											hIcon );
	}

	// Create font for the application
	{     
		LOGFONT		lf;
		HDC			hDC = ::GetDC( ::GetDesktopWindow() );
		int 		nFontSize = -1 * (::GetDeviceCaps(hDC, LOGPIXELSY) * 9 / 72);
		::ReleaseDC(::GetDesktopWindow(), hDC );

		// Clear the font structure
		ChMemClearStruct( &lf );

		m_pAppFont = new CFont();
		ASSERT( m_pAppFont );
			
		lf.lfHeight = nFontSize;
		lf.lfWeight = FW_LIGHT;
		lf.lfCharSet = ANSI_CHARSET;
		lf.lfOutPrecision = OUT_STROKE_PRECIS;
		lf.lfClipPrecision = CLIP_STROKE_PRECIS;
		lf.lfQuality = DEFAULT_QUALITY;
		lf.lfPitchAndFamily = FF_DONTCARE;
		lstrcpy(lf.lfFaceName, "MS Sans Serif");
			
		m_pAppFont->CreateFontIndirect( &lf ); 
	}                              
	#endif

	// Create the brush for status messages
	if ( !m_brClearProgress.GetSafeHandle() )
	{
		int iIndex = ChUtil::GetSystemType() ==  CH_SYS_WIN95 ? COLOR_3DFACE : COLOR_BTNFACE;
		m_brClearProgress.CreateSolidBrush( GetSysColor( iIndex ) );
		m_brShowProgress.CreateSolidBrush( RGB( 0xff, 0, 0 ) );
	}
}

ChMainFrame::~ChMainFrame()
{
	#ifdef CH_MSW
		if ( m_pAppFont )
		{
			delete m_pAppFont;
		}
	#endif
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChMainFrame::PreCreateWindow

	cs			||	Creation structure.  Fields in this structure may be
					changed to modify how the frame will be created.

------------------------------------------------------------------------------

	This function is called before the frame window is created.

----------------------------------------------------------------------------*/

bool ChMainFrame::PreCreateWindow( CREATESTRUCT& cs )
{
	cs.lpszClass = m_strClass;
	cs.dwExStyle |= WS_EX_CONTEXTHELP;

	ChRegistry reg( CH_COMPANY_NAME, CH_HTML_PRODUCT_NAME, APP_STATE );

	string strPos;
	reg.Read( APP_POS, strPos, TEXT("0,0,0,0") );
	 
	pstr pstrNext, pstrStop;
	cs.x = (int)strtol( strPos, &pstrStop, 10 ); 
	pstrNext = pstrStop;

	if ( pstrStop )
		cs.y = (int)strtol( pstrNext+1, &pstrStop, 10 );
	pstrNext = pstrStop;
	if ( pstrStop )
		cs.cx = (int)strtol( pstrNext+1, &pstrStop, 10 );
	pstrNext = pstrStop;
	if ( pstrStop )
		cs.cy = (int)strtol( pstrNext+1, &pstrStop, 10 ); 
		
	if ( cs.cx == 0 && cs.cy == 0 )
	{ 
		cs.x = cs.y = cs.cx = cs.cy = CW_USEDEFAULT;
	}

	#if defined( CH_ARCH_32 )

	// Make sure that when the window comes up we are not clipped by the 
	// tray
	OSVERSIONINFO osInfo;
	osInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx( &osInfo );
	if ( osInfo.dwPlatformId != VER_PLATFORM_WIN32_NT &&
		osInfo.dwPlatformId !=	VER_PLATFORM_WIN32s	)
	{

		RECT rtWork;
		::SystemParametersInfo( SPI_GETWORKAREA, sizeof(RECT),
					  &rtWork, 0);
		{
			if ( rtWork.left > cs.x && cs.x != CW_USEDEFAULT)
			{
				cs.x = rtWork.left;
			}

			if ( rtWork.top > cs.y && cs.y != CW_USEDEFAULT )
			{
				cs.y = rtWork.top;
			}

			if ( (cs.x  + cs.cx ) > rtWork.right && cs.cx != CW_USEDEFAULT )
			{
				int iLeft =  (cs.x  + cs.cx) -  rtWork.right;

				if ( iLeft < cs.x  ) 
				{
					cs.x -= iLeft;
				}
				else
				{
					cs.x = rtWork.left;
				}
			} 
		
			if ( (cs.y  + cs.cy) > rtWork.bottom && cs.cy != CW_USEDEFAULT )
			{
				int iBottom =  (cs.y  + cs.cy) -  rtWork.bottom;

				if ( iBottom < cs.y  ) 
				{
					cs.y -= iBottom;
				}
				else
				{
					cs.y = rtWork.top;
				}
			} 
		}
	}
	#endif
	

											// set the initial state		
	bool boolIconized, boolMaximized;
	reg.ReadBool( APP_SHOWSTATEICON, boolIconized, true );
	reg.ReadBool( APP_SHOWSTATEICON, boolMaximized, false );

	if ( AfxGetMainWnd() != this )
	{
		if(boolMaximized) 		AfxGetApp()->m_nCmdShow = SW_SHOWMAXIMIZED;
		else if(boolIconized) 	AfxGetApp()->m_nCmdShow = SW_SHOWMINIMIZED;
		else 					AfxGetApp()->m_nCmdShow = SW_SHOWNORMAL;
	}

	return CFrameWnd::PreCreateWindow( cs );
}


/*----------------------------------------------------------------------------
	ChMainFrame diagnostics
----------------------------------------------------------------------------*/

#if (defined( _DEBUG ))

void ChMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}


void ChMainFrame::Dump( CDumpContext& dc ) const
{
	CFrameWnd::Dump( dc );
}

#endif	// defined( _DEBUG )




/*----------------------------------------------------------------------------

	FUNCTION		||	ChMainFrame::InitStatusBar

------------------------------------------------------------------------------

	This function will perform initialization on the status bar.

----------------------------------------------------------------------------*/

void ChMainFrame::InitStatusBar()
{
	UINT idProgress, nStyle;
	int	 iWidth;
	m_wndStatusBar.GetPaneInfo( CH_STATUS_PROGRESS_PANE, idProgress, nStyle,
								iWidth );
	
	SetProgressWidth( (chint16)iWidth );

	m_wndStatusBar.SetFont( GetAppFont() );
}


/*----------------------------------------------------------------------------

	FUNCTION		||	ChMainFrame::DrawProgressBar

------------------------------------------------------------------------------

	This function is called to update the progress bar.  It should be called
	continuously.

----------------------------------------------------------------------------*/

void ChMainFrame::DrawProgressBar()
{


	if ( m_httpConn.IsActive() )
	{
		int			iPercent;
		string 		strMessage;
		m_httpConn.GetProgressMsg( strMessage, iPercent );

		if ( !m_boolInProgress )
		{
			m_wndDlgBar.EnableAnimationCtrl( true );
			m_boolInProgress = true;
		}

		SetMessageText( strMessage );

		CRect		rtProgress;
		chint16		sProgressPixels;
		CDC*		pBarDC;

		m_wndStatusBar.GetItemRect( CH_STATUS_PROGRESS_PANE, &rtProgress );

		rtProgress.InflateRect( -1, -1 );		// Leave room for the 3d borders

		sProgressPixels = (chint16)((GetProgressWidth() * iPercent) / 100);

		pBarDC = m_wndStatusBar.GetDC();

		if (sProgressPixels < (rtProgress.right - rtProgress.left))
		{
			CRect	rtEmpty;

			rtEmpty = rtProgress;
			rtEmpty.left = rtProgress.left + sProgressPixels;

			pBarDC->FillRect( &rtEmpty, &m_brClearProgress );
		}

		if (sProgressPixels)
		{
			rtProgress.right = rtProgress.left + sProgressPixels;

			pBarDC->FillRect( &rtProgress, &m_brShowProgress );
		}

		m_wndStatusBar.ReleaseDC( pBarDC );


	} 
	else
	{
		if ( m_boolInProgress )
		{
			ClearStatus();
		}
	}
}

void ChMainFrame::ClearStatus( )
{
	if ( m_boolInProgress )
	{
		//Update once just to get rid of any old progress state
		m_wndDlgBar.EnableAnimationCtrl( false );
		m_boolInProgress = false;
	}
	SetMessageText( TEXT( "" ) );

	CRect		rtProgress;
	m_wndStatusBar.GetItemRect( CH_STATUS_PROGRESS_PANE, &rtProgress );

	rtProgress.InflateRect( -1, -1 );		// Leave room for the 3d borders


	CDC*		pBarDC;
	pBarDC = m_wndStatusBar.GetDC();
	pBarDC->FillRect( &rtProgress, &m_brClearProgress );
	m_wndStatusBar.ReleaseDC( pBarDC );

}

void ChMainFrame::LoadURL( const string& strURL )
{
	GetHTMLWnd()->LoadURL( strURL, 0 );
}

void ChMainFrame::UpdateLocationBar( const string& strURL )
{
	m_wndDlgBar.UpdateLocationBar( strURL );
}

void ChMainFrame::SetFrameName( const string& strName )
{
	webTrackerMgr.AddToFrameList( strName, this );
	m_strFrameName = strName;
}

/*----------------------------------------------------------------------------
	ChMainFrame message handlers
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------

	FUNCTION		||	ChMainFrame::OnCreate

	lpCreateStruct	||	Pointer to the structure containing information
						about the object being created.

------------------------------------------------------------------------------

	This function is called during processing of the WM_CREATE message,
	after the window is created but before it is shown.

----------------------------------------------------------------------------*/

int ChMainFrame::OnCreate( LPCREATESTRUCT lpCreateStruct )
{

	if (CFrameWnd::OnCreate( lpCreateStruct ) == -1)
	{
		return -1;
	}

	if (!m_wndToolBar.Create( this ) ||
		!m_wndToolBar.LoadBitmap( IDR_MAINFRAME ) ||
		!m_wndToolBar.SetButtons( buttons, sizeof( buttons )/sizeof( UINT ) ))
	{
		TRACE0( "Failed to create toolbar\n" );

		return( -1 );						// Failed to create the toolbar
	}

	if (!m_wndStatusBar.Create( this ) ||
		!m_wndStatusBar.SetIndicators( indicators,
									sizeof( indicators ) / sizeof( UINT ) ))
	{
		TRACE0( "Failed to create status bar\n" );

		return( -1 );						// Failed to create the status
	}
	else
	{
		InitStatusBar();
	}
	
	m_wndToolBar.EnableDocking( CBRS_ALIGN_TOP );
	//EnableDocking( CBRS_ALIGN_TOP );
	//DockControlBar( &m_wndToolBar, AFX_IDW_DOCKBAR_TOP  );

	if (!m_wndDlgBar.Create(this, IDD_LOCBAR,
		CBRS_TOP  |CBRS_TOOLTIPS |CBRS_FLYBY, IDD_LOCBAR))
	{
		TRACE0("Failed to create DlgBar\n");
		return -1;      // fail to create
	}
	m_wndDlgBar.UpdateData( false );
	m_wndDlgBar.InitLocationBar();

	m_wndToolBar.SetBarStyle( m_wndToolBar.GetBarStyle() |
								CBRS_TOOLTIPS | CBRS_FLYBY );
   
	ChRegistry reg( CH_COMPANY_NAME, CH_HTML_PRODUCT_NAME, APP_STATE );

	bool boolTool, boolStatus;
	reg.ReadBool( APP_TOOLBAR, boolTool, true );
	reg.ReadBool( APP_STATUSBAR, boolStatus, true );


	// Are toolbar and status bar visible
	if( !(boolTool))
	{ // Hide the button bar
		m_wndToolBar.ShowWindow( SW_HIDE );
	}
	if( !(boolStatus) )
	{ // Hide the status bar
		m_wndStatusBar.ShowWindow( SW_HIDE );
	}   

	RecalcLayout();


	return( 0 );
}




/*----------------------------------------------------------------------------

	FUNCTION	||	ChMainFrame::OnClose

------------------------------------------------------------------------------

	This function will prompt to discover whether or not it is safe to
	terminate the application.

	When the Pueblo client is logged in, it terminates by sending a request
	to the server.  The server then controls the termination sequence.

	If the Pueblo client is offline, termination proceeds normally.

----------------------------------------------------------------------------*/

void ChMainFrame::OnClose()
{

	webTrackerMgr.RemoveFromFrameList( m_strFrameName, this );

	if ( m_hResourceOld )
	{
		AfxSetResourceHandle( m_hResourceOld );	  
		m_hResourceOld = 0;
	}


	CRect 			rtFrame;
	UINT			uVisible = 0;
	WINDOWPLACEMENT wndPl;
	// size and location of the frame
	wndPl.length = sizeof( wndPl );  
	GetWindowPlacement( &wndPl );
	rtFrame = wndPl.rcNormalPosition;  

	ChRegistry reg( CH_COMPANY_NAME, CH_HTML_PRODUCT_NAME, APP_STATE );

	reg.WriteBool( APP_SHOWSTATEICON, wndPl.showCmd == SW_SHOWMINIMIZED );
	reg.WriteBool( APP_SHOWSTATEMAX, wndPl.showCmd == SW_SHOWMAXIMIZED );

	// is toolbar and status bar visible
	reg.WriteBool( APP_TOOLBAR, (m_wndToolBar.GetStyle() & WS_VISIBLE) != 0L );
	reg.WriteBool( APP_STATUSBAR, (m_wndStatusBar.GetStyle() & WS_VISIBLE) != 0L );
                    
	// Write the information to the ini file

	// Position and size
	char strBuffer[100];
	wsprintf( strBuffer, "%d,%d,%d,%d",rtFrame.left, rtFrame.top, 
						rtFrame.Width(), rtFrame.Height() );
	reg.Write( APP_POS, string( strBuffer ) );


	CFrameWnd::OnClose();
}






void ChMainFrame::OnPaletteChanged(CWnd* pFocusWnd) 
{
	SendMessageToDescendants( WM_PALETTECHANGED, 
							(WPARAM)(pFocusWnd->GetSafeHwnd() ) );
	
}

BOOL ChMainFrame::OnQueryNewPalette() 
{
	// TODO: Add your message handler code here and/or call default
	CPalette * pPal = ChImgUtil::GetStdPalette();
	bool	boolChanged = false;

	if ( pPal )
	{

        CDC*	pDC = GetDC();
		CPalette * pOldPal = pDC->SelectPalette( pPal, false );

        boolChanged	 = (BOOL)pDC->RealizePalette();
	
		pDC->SelectPalette( pOldPal, true );

        pDC->RealizePalette();

        ReleaseDC( pDC );
	}
	return boolChanged;
}

void ChMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	DrawProgressBar();			// Update the progress bar

	CFrameWnd ::OnTimer(nIDEvent);
}

BOOL ChMainFrame::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	if ( wParam == IDOK )
	{ 
		string strURL;
		m_wndDlgBar.GetLocBarText( strURL );	
		if ( !strURL.IsEmpty() 
				&& strURL != GetHTMLWnd()->GetPendingRequest() )
		{
			GetHTMLWnd()->LoadURL( strURL, ChHTTPConn::ReloadURL );
		}
	}
	else
	{
		return CFrameWnd ::OnCommand(wParam, lParam);
	}

	return 1;
}

void ChMainFrame::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CFrameWnd ::OnActivate(nState, pWndOther, bMinimized);

	if ( WA_INACTIVE  == nState ) 
	{
		if ( m_idTimer )
		{
			KillTimer( m_idTimer );
			m_idTimer = 0;
			// Cleanup the status bar on deactivation
			ClearStatus();
		} 

		if ( m_hResourceOld )
		{
			AfxSetResourceHandle( m_hResourceOld );	  
			m_hResourceOld = 0;
		}
	}
	else
	{

		if ( WTrackerDLL.hModule != AfxGetResourceHandle() )
		{
			m_hResourceOld = AfxGetResourceHandle(  );
			AfxSetResourceHandle( WTrackerDLL.hModule );
		}

	   	if ( 0 == m_idTimer )
	   	{
			// TODO: Add your message handler code here
			m_idTimer = SetTimer( ID_PROGRESS_UPDATE_TIMER, 
							HALF_SECOND_TIMER_DURATION, NULL );
		}
	}
	
}


void ChMainFrame::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	chint32 lStart, lEnd;

	GetHTMLWnd()->GetSel( lStart, lEnd );
	pCmdUI->Enable( lStart != lEnd );
}

void ChMainFrame::OnEditCopy() 
{
	GetHTMLWnd()->CopyToClipboard();
}



void ChMainFrame::OnFileOpenLoc() 
{
	// TODO: Add your command handler code here
	COpenLoc openLoc( GetHTMLWnd(), this );

	if ( IDOK ==  openLoc.DoModal() )
	{
		GetHTMLWnd()->LoadURL( openLoc.GetLocation() );
	}
}

void ChMainFrame::OnGoBack() 
{
	// TODO: Add your command handler code here
	GetHTMLWnd()->GoBackward( );
}

void ChMainFrame::OnUpdateGoBack(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( GetHTMLWnd()->CanGoBackward( ) );
}

void ChMainFrame::OnGoForward() 
{
	GetHTMLWnd()->GoForward( );
}

void ChMainFrame::OnUpdateGoForward(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( GetHTMLWnd()->CanGoForward( ) );
}

void ChMainFrame::OnGoHome() 
{
	// TODO: Add your command handler code here
	GetHTMLWnd()->LoadURL( GetHTMLWnd()->GetHomePage() );
}


void ChMainFrame::OnUpdateGoHome(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( !GetHTMLWnd()->GetHomePage( ).IsEmpty() );
}


void ChMainFrame::OnGoStopLoading() 
{
	// TODO: Add your command handler code here
	GetHTTPConn()->AbortRequests();
}

void ChMainFrame::OnViewRefresh() 
{
	GetHTMLWnd()->Invalidate();
}

void ChMainFrame::OnUpdateViewRefresh(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( !GetHTMLWnd()->GetDocURL().IsEmpty() );	
}

void ChMainFrame::OnViewReload() 
{
	// TODO: Add your command handler code here
	GetHTMLWnd()->LoadURL( GetHTMLWnd()->GetDocURL(), ChHTTPConn::ReloadURL );

}

void ChMainFrame::OnUpdateViewReload(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( !GetHTMLWnd()->GetDocURL().IsEmpty() );	
}

void ChMainFrame::OnUpdateGoStopLoading(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( GetHTTPConn()->IsActive() );
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChApp::OnAppAbout

------------------------------------------------------------------------------

	This function will execute the 'About Pueblo' dialog.

----------------------------------------------------------------------------*/

void ChMainFrame::OnAppAbout()
{
	ChAbout		aboutDlg( IDS_ABOUT_TITLE, this );

	aboutDlg.DoModal();
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChApp::OnEditPreferences

------------------------------------------------------------------------------

	This function will execute the preferences property sheet.

----------------------------------------------------------------------------*/

void ChMainFrame::OnEditPreferences() 
{
	ChPrefs				prefsDlg( IDS_TITLE_PREFS_DLG, this );
	ChPrFont			prefsFonts;
	ChCachePrefsPage	prefsCache;
	ChNetworkPage		prefsNetwork;
	ChPrefsColorPage    prefColor;
											/* Add the property pages for this
												property sheet */
	prefsDlg.AddPage( &prefsFonts );
	prefsDlg.AddPage( &prefColor );
	prefsDlg.AddPage( &prefsCache );
	prefsDlg.AddPage( &prefsNetwork );

											/* Execute the property sheet
												modally */
	prefsDlg.DoModal();
}



void ChMainFrame::OnFileOpen() 
{
	// TODO: Add your command handler code here
	string strFilter;
	ChWebTrackerManager::WTrackerLoadString( IDS_OPEN_WEB_TRACKER_FILTER, strFilter );

	CFileDialog	fileOpen( true, NULL, NULL,
					OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
					strFilter, this );

	if ( fileOpen.DoModal() == IDOK )
	{
		string strURL;
		ChURLParts::MapHostFileToURL( fileOpen.GetPathName( ),  strURL );
		GetHTMLWnd()->LoadURL( strURL );
	}
}
		 

void ChMainFrame::OnFrameClose() 
{
	// TODO: Add your command handler code here

	if ( AfxGetMainWnd() != this )
	{
		OnClose();
	}
	else
	{
		::PostQuitMessage( 0 );
		OnClose();
	}
}

