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

	This file consists of implementations of the ChAbout class, ChSplashWnd
	class, and ChBigIcon class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChAbout.cpp,v 1.5 1996/07/02 19:57:28 pritham Exp $

#include "stdafx.h"

#include <time.h>
//#include <ChClInfo.h>

#include "resource.h"
#include "ChAbout.h"
#include "ChMFrame.h"
#include <ChDibDecoder.h>

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif



CH_EXTERN_VAR AFX_EXTENSION_MODULE WTrackerDLL;

#define COLOR_LT_GRAY		RGB( 0x80, 0x80, 0x80 )
#define COLOR_WHITE			RGB( 0xff, 0xff, 0xff )

/*----------------------------------------------------------------------------
				ChLogoBitmap class
----------------------------------------------------------------------------*/

BEGIN_MESSAGE_MAP( ChLogoBitmap, CButton )
	//{{AFX_MSG_MAP(ChLogoBitmap)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------

	FUNCTION	||	ChLogoBitmap::SizeToContent

------------------------------------------------------------------------------

	This function will size a bitmap button to the size of the bitmap.
	This method MUST be called.

----------------------------------------------------------------------------*/

void ChLogoBitmap::SizeToContent( chflag16 fAlignment )
{
	ChDibDecoder dibDecoder( &m_logoBmp );
	if (dibDecoder.Load( IDR_CHACO_DIB,  WTrackerDLL.hResource ))
	{
		m_lBmpHeight = m_logoBmp.GetHeight();
		m_lBmpWidth = m_logoBmp.GetWidth();
	}
	else
	{
		m_lBmpHeight = 0;
		m_lBmpWidth = 0;
	}

	if (m_lBmpHeight && m_lBmpWidth)
	{
		CRect	rtParent;
		chint32	lTop = 5;
		chint32	lLeft = 5;
		chint32	lWidth = m_lBmpWidth;
		chint32	lHeight = m_lBmpHeight;

		GetParent()->GetClientRect( &rtParent );

		if (rtParent.Height() < lHeight)
		{
			lHeight = rtParent.Height() - 10;
		}
											// Calculate alignment
		if (fAlignment & right)
		{
			lLeft = rtParent.Width() - (m_lBmpWidth + 5);
		}
		else if (fAlignment & hcenter)
		{
			lLeft = (rtParent.Width() - m_lBmpWidth) / 2;
		}

		if (fAlignment & bottom)
		{
			lTop = rtParent.Height() - (m_lBmpHeight + 5);
		}
		else if (fAlignment & vcenter)
		{
			lTop = (rtParent.Height() - m_lBmpHeight) / 2;
		}
											// Reposition the window

		SetWindowPos( 0, (int)lLeft, (int)lTop, (int)lWidth, (int)lHeight,
						SWP_NOACTIVATE | SWP_NOZORDER );
	}
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChLogoBitmap::DrawItem

------------------------------------------------------------------------------

	This function will draw the contents of the bitmap button.

----------------------------------------------------------------------------*/

void ChLogoBitmap::DrawItem( LPDRAWITEMSTRUCT lpDrawItemStruct )
{
	if (0 == m_logoBmp.GetWidth())
	{
		return;								// Bitmap load unsuccessful
	}

	//if ( IsWindowVisible() )
	{
		CDC*		pDC = CDC::FromHandle( lpDrawItemStruct->hDC );
		CRect		rect;

		ASSERT( pDC != 0 );

		GetClientRect( rect );

	  	m_logoBmp.SetSize( rect.Width(), rect.Height() );
	  	m_logoBmp.Draw( pDC, 0, 0, COLOR_WHITE );
	}
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChLogoBitmap::OnEraseBkgnd

------------------------------------------------------------------------------

	This function will handle erase processing for the class.

----------------------------------------------------------------------------*/

bool ChLogoBitmap::OnEraseBkgnd( CDC* )
{
	return true;    // we don't do any erasing...
}

#if 0
/*----------------------------------------------------------------------------
				ChSplashWnd class
----------------------------------------------------------------------------*/

BEGIN_MESSAGE_MAP( ChSplashWnd, CDialog )
	//{{AFX_MSG_MAP(ChSplashWnd)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------

	FUNCTION	||	ChSplashWnd::DoDataExchange

------------------------------------------------------------------------------

	This function is called by the framework to exchange and validate
	dialog data.

----------------------------------------------------------------------------*/

void ChSplashWnd::DoDataExchange( CDataExchange* pDX )
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ChSplashWnd)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


/*----------------------------------------------------------------------------
	ChSplashWnd message handlers
----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------

	FUNCTION	||	ChSplashWnd::Create

------------------------------------------------------------------------------

	This function is called to create the splash window dialog.

----------------------------------------------------------------------------*/

bool ChSplashWnd::Create( CWnd* pParent )
{
	//{{AFX_DATA_INIT(ChSplashWnd)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	if (!CDialog::Create( ChSplashWnd::IDD, pParent ))
	{
		TRACE0( "Warning: creation of ChSplashWnd dialog failed\n" );
		return( false );
	}

	return( true );
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChSplashWnd::OnInitDialog

------------------------------------------------------------------------------

	This function is called when the dialog is initialized.  We use this
	handler to subclass the owner-draw button.

----------------------------------------------------------------------------*/

bool ChSplashWnd::OnInitDialog()
{
	ChClientInfo	clientInfo( ChClientInfo::thisMachine );
	ChVersion		clientVer = clientInfo.GetClientVersion();
	CWnd*			pVersionWnd = GetDlgItem( IDC_VERSION_STRING );
	string			strFormat;
	string			strVersion;

	CDialog::OnInitDialog();

	if (GetParent()->IsIconic())
	{										/* If the parent is iconic, center
												on the desktop */
		CenterWindow( GetDesktopWindow() );
	}
	else
	{										/* If the parent is not iconic,
												center on the parent */
		CenterWindow();
	}
											// initialize the Chaco logo

	logoBmp.SubclassDlgItem( IDC_CHACO_LOGO, this );
	logoBmp.SizeToContent( ChLogoBitmap::hcenter | ChLogoBitmap::top );

											// Set the version string correctly
	pVersionWnd->GetWindowText( strFormat );
	#if defined( CH_ARCH_16 )  
	char * pstrVersion = new char[ strFormat.GetLength() + lstrlen(clientVer.Format() ) + 2];
	::wsprintf( pstrVersion,  strFormat, (const char*)clientVer.Format() );  
	strVersion = pstrVersion;
	delete []pstrVersion;      
	#else
	strVersion.Format( strFormat, (const char*)clientVer.Format() );
	#endif
	pVersionWnd->SetWindowText( strVersion );
  											/* return true unless you set the
  												focus to a control */
	return( true );
}


void ChSplashWnd::OnDestroy() 
{
	CDialog ::OnDestroy();
	
}

#endif // 0


/*----------------------------------------------------------------------------
	ChAbout property sheet class
----------------------------------------------------------------------------*/

IMPLEMENT_DYNAMIC( ChAbout, CPropertySheet )

ChAbout::ChAbout( chuint16 suIDCaption, CWnd *pParentWnd,
					chuint16 suSelectPage ) :
			CPropertySheet( suIDCaption, pParentWnd, suSelectPage )
{
	Construct();
}

ChAbout::ChAbout( char *pstrCaption, CWnd *pParentWnd,
					chuint16 suSelectPage ) :
			CPropertySheet( pstrCaption, pParentWnd, suSelectPage )
{
	Construct();
}

ChAbout::~ChAbout()
{
}


BEGIN_MESSAGE_MAP( ChAbout, CPropertySheet )
	//{{AFX_MSG_MAP(ChAbout)
	ON_COMMAND(ID_HELP, OnHelp)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


int ChAbout::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CPropertySheet::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here           
	// Remove the Apply button fro the sheet
	GetDlgItem( ID_APPLY_NOW  )->ShowWindow( SW_HIDE ); 
	GetDlgItem( IDCANCEL  )->ShowWindow( SW_HIDE ); 
	GetDlgItem( ID_HELP  )->ShowWindow( SW_HIDE ); 
	
	
	// Reposition the OK, Cancel and Help buttons
	CRect rtFrame, rtBtn;
	GetWindowRect( &rtFrame );

	GetDlgItem( IDOK  )->GetWindowRect( &rtBtn );

	int xPos = (rtFrame.Width() - (rtBtn.Width() ))/2;

	CPoint ptPos( xPos, rtBtn.top );
	ScreenToClient( &ptPos );
	ptPos.x = xPos;

	GetDlgItem( IDOK  )->SetWindowPos( 0, ptPos.x, ptPos.y, 0, 0, 
						SWP_NOSIZE | SWP_NOZORDER | SWP_NOREDRAW | SWP_NOACTIVATE );

	return 0;
}



/*----------------------------------------------------------------------------
	ChAbout property sheet methods
----------------------------------------------------------------------------*/

void ChAbout::Construct()
{
	AddPage( &puebloPage );
	AddPage( &teamPage );
}


/*----------------------------------------------------------------------------
	ChAbout message maps
----------------------------------------------------------------------------*/

void ChAbout::OnHelp() 
{											/* This method gets the help
												button press and passes it on
												to the currently active
												page to process */
	WinHelp( 0x20000 + IDD_ABOUT_BOX );
}


/*----------------------------------------------------------------------------
	ChPuebloAbout property page class
----------------------------------------------------------------------------*/

IMPLEMENT_DYNCREATE( ChPuebloAbout, CPropertyPage )

ChPuebloAbout::ChPuebloAbout() :
					CPropertyPage( ChPuebloAbout::IDD )
{
	//{{AFX_DATA_INIT(ChPuebloAbout)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

ChPuebloAbout::~ChPuebloAbout()
{
}



void ChPuebloAbout::DoDataExchange( CDataExchange* pDX )
{
	CPropertyPage::DoDataExchange( pDX );

	//{{AFX_DATA_MAP(ChPuebloAbout)
	DDX_Control(pDX, IDC_STATIC_VERSION, m_staticVersion);
	DDX_Control(pDX, IDC_PROD_NAME, m_staticProductName);
	DDX_Control(pDX, IDC_LEGEND, m_staticLegend);
	DDX_Control(pDX, IDC_COPYRIGHT, m_staticCopyright);
	DDX_Control(pDX, IDC_CLAUSE, m_staticClause);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP( ChPuebloAbout, CPropertyPage )
	//{{AFX_MSG_MAP(ChPuebloAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChPuebloAbout message handlers
----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
	ChPuebloAbout message handlers
----------------------------------------------------------------------------*/

bool ChPuebloAbout::OnInitDialog()
{

	CPropertyPage::OnInitDialog();

											// initialize the Chaco logo

	m_logoBmp.SubclassDlgItem( IDC_CHACO_LOGO, this );
	m_logoBmp.SizeToContent( ChLogoBitmap::left | ChLogoBitmap::vcenter );

	{										/* Set fonts for static fields in
												the page to make it more
												attractive */
		HDC			hDC = ::GetDC( m_hWnd );
		LOGFONT		lf;
		int 		iPixelSize = ::GetDeviceCaps( hDC, LOGPIXELSY );
		CFont		font;

		::ReleaseDC( m_hWnd, hDC );
											// Clear the font structure
		ChMemClearStruct( &lf );

		lf.lfHeight = -1 * (iPixelSize * 14 / 72);
		lf.lfWeight = FW_BOLD;
		lf.lfCharSet = ANSI_CHARSET;
		lf.lfOutPrecision = OUT_STROKE_PRECIS;
		lf.lfClipPrecision = CLIP_STROKE_PRECIS;
		lf.lfQuality = DEFAULT_QUALITY;
		lf.lfPitchAndFamily = FF_DONTCARE;
		lstrcpy( lf.lfFaceName, "Arial" );

		font.CreateFontIndirect( &lf );
		m_staticProductName.SendMessage( WM_SETFONT,
											(WPARAM)font.GetSafeHandle() );
		font.Detach();

		lf.lfHeight = -1 * (iPixelSize * 8 / 72);
		lf.lfWeight = FW_NORMAL;
		font.CreateFontIndirect( &lf );
		m_staticVersion.SendMessage( WM_SETFONT,
										(WPARAM)font.GetSafeHandle() );
		font.Detach();

		lf.lfHeight = -1 * (iPixelSize * 9 / 72);
		lf.lfWeight = FW_BOLD;
		font.CreateFontIndirect( &lf );
		m_staticCopyright.SendMessage( WM_SETFONT,
										(WPARAM)font.GetSafeHandle() );
		font.Detach();

		lf.lfHeight = -1 * (iPixelSize * 8 / 72);
		lf.lfWeight = FW_BOLD;
		font.CreateFontIndirect( &lf );
		m_staticLegend.SendMessage( WM_SETFONT,
										(WPARAM)font.GetSafeHandle() );
		m_staticClause.SendMessage( WM_SETFONT,
										(WPARAM)font.GetSafeHandle() );
		font.Detach();

		lf.lfHeight = -1 * (iPixelSize * 6 / 72);
		lf.lfWeight = FW_MEDIUM;
		font.CreateFontIndirect( &lf );
		m_staticClause.SendMessage( WM_SETFONT,
										(WPARAM)font.GetSafeHandle() );
		font.Detach();
	}

	//m_staticVersion.SetWindowText( strVerNum );

	return true;  // return true unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


bool ChPuebloAbout::OnSetActive()
{
	bool		boolSuccess;

	boolSuccess = CPropertyPage::OnSetActive();

	return boolSuccess;
}




/*----------------------------------------------------------------------------
	ChTeamAbout property sheet class
----------------------------------------------------------------------------*/

int	ChTeamAbout::iTeamNames[namesCount] = {	    IDS_TEAM_GLENN,
												IDS_TEAM_PRITHAM,
												IDS_TEAM_RON,
												IDS_TEAM_JIM,
												IDS_TEAM_DAN };

IMPLEMENT_DYNCREATE( ChTeamAbout, CPropertyPage )

ChTeamAbout::ChTeamAbout() : CPropertyPage( ChTeamAbout::IDD )
{
	//{{AFX_DATA_INIT(ChTeamAbout)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

ChTeamAbout::~ChTeamAbout()
{
}

void ChTeamAbout::DoDataExchange( CDataExchange* pDX )
{
	CPropertyPage::DoDataExchange( pDX );

	//{{AFX_DATA_MAP(ChTeamAbout)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP( ChTeamAbout, CPropertyPage )
	//{{AFX_MSG_MAP(ChTeamAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChTeamAbout protected methods
----------------------------------------------------------------------------*/

void ChTeamAbout::RandomizeNames()
{
	int		iLoop;
											/* Initialize the random number
												generator with the current
												time */
	srand( (unsigned int)time( 0 ) );

	for (iLoop = 0; iLoop < 30; iLoop++)
	{
		int		iFirst = GetRandomInt( namesCount - 1 );
		int		iSecond = GetRandomInt( namesCount - 1 );

		if (iFirst != iSecond)
		{
			int		iTemp;
											// Swap the two
			iTemp = iTeamNames[iFirst];
			iTeamNames[iFirst] = iTeamNames[iSecond];
			iTeamNames[iSecond] = iTemp;
		}
	}
}


int ChTeamAbout::GetRandomInt( int iMax )
{											/* Generates a random int between
												zero and iMax, inclusive */
	int		iResult;
	double	dRan = (double)rand();
	double	fVal = dRan / (double)RAND_MAX;

	iResult = (int)((fVal * (double)iMax) + 0.5);
	ASSERT( iResult >= 0 && iResult <= iMax );

	return iResult;
}


void ChTeamAbout::SetNames()
{
	static int	iFields[namesCount] = { IDC_NAME_1, IDC_NAME_2, IDC_NAME_3,
										IDC_NAME_4, IDC_NAME_5 };
	int			iLoop;

	for (iLoop = 0; iLoop < namesCount; iLoop++)
	{
		CStatic*	pStatic;

		if (pStatic = (CStatic*)GetDlgItem( iFields[iLoop] ))
		{
			string	strName;

			ChWebTrackerManager::WTrackerLoadString( iTeamNames[iLoop], strName );
			pStatic->SetWindowText( strName );
		}
	}
}


/*----------------------------------------------------------------------------
	ChTeamAbout message handlers
----------------------------------------------------------------------------*/

BOOL ChTeamAbout::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
											// initialize the Chaco logo

	m_logoBmp.SubclassDlgItem( IDC_CHACO_LOGO, this );
	m_logoBmp.SizeToContent( ChLogoBitmap::left | ChLogoBitmap::vcenter );

	RandomizeNames();
	SetNames();

	return true;							/* Return TRUE unless you set the
												focus to a control */
}

bool ChTeamAbout::OnSetActive()
{
	bool		boolSuccess;

	boolSuccess = CPropertyPage::OnSetActive();


	return boolSuccess;
}
