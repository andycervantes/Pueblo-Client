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

This file includes the code for the main cache and network preference page.

----------------------------------------------------------------------------*/

// chprnet.cpp : implementation file
//

#include "stdafx.h"
#include <ChHtpCon.h>
#include <ChReg.h>
#include "resource.h"
#include "ChMFrame.h"
#include "ChPrNet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif



/*----------------------------------------------------------------------------
	ChCachePrefsPage class
----------------------------------------------------------------------------*/

IMPLEMENT_DYNCREATE(ChCachePrefsPage, CPropertyPage)

ChCachePrefsPage::ChCachePrefsPage() : CPropertyPage(ChCachePrefsPage::IDD),
					m_reg( CH_COMPANY_NAME, CH_HTML_PRODUCT_NAME, CH_CACHE_GROUP ),
					m_boolInitialized( false )
{
	//{{AFX_DATA_INIT(ChCachePrefsPage)
	m_cacheDir = _T("");
	m_uCacheSize = 1000;
	//}}AFX_DATA_INIT
}

ChCachePrefsPage::~ChCachePrefsPage()
{
}

void ChCachePrefsPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ChCachePrefsPage)
	DDX_Text(pDX, IDC_CACHE_DIR, m_cacheDir);
	DDV_MaxChars(pDX, m_cacheDir, 256);
	DDX_Text(pDX, IDC_CACHE_SIZE, m_uCacheSize);
	DDV_MinMaxUInt(pDX, m_uCacheSize, 10, 10000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ChCachePrefsPage, CPropertyPage)
	//{{AFX_MSG_MAP(ChCachePrefsPage)
	ON_BN_CLICKED(IDC_CLR_CACHE, OnClrCache)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

#define CACHE_DIR				"URLCACHE"

bool ChCachePrefsPage::OnSetActive()
{
	bool	boolResult;

	boolResult = CPropertyPage::OnSetActive();

	if (!m_boolInitialized)
	{
		string		strSize;
		string		strDir;
		chuint32	luOption;

		#if defined( CH_MSW )
		{
			CWinApp*	pApp = AfxGetApp();
			char		strPath[MAX_PATH];
			int			iLastSeparator;

			::GetModuleFileName( pApp->m_hInstance, strPath, MAX_PATH );
			strDir = strPath;
													// Strip out the app name

			iLastSeparator = strDir.ReverseFind( TEXT( '\\' ) );

			if (iLastSeparator >= 0)
			{
				strDir = strDir.Left( iLastSeparator + 1 );
			}
		}
		#else	// defined( CH_MSW )
		{
			extern string strPuebloDirectory;
			strDir = strPuebloDirectory;
		}
		#endif	// defined( CH_MSW )

		m_reg.Read( CH_CACHE_DIR, m_cacheDir, strDir );

		int iIndex =  m_cacheDir.Find( CACHE_DIR );
		if ( iIndex && iIndex != -1 )
		{  // remove what we added to the path
			m_cacheDir = m_cacheDir.Left( iIndex - 1  );
		}


		long luSize;
 		m_reg.Read( CH_CACHE_SIZE, luSize, CH_CACHE_SIZE_DEF );
		m_uCacheSize = (UINT)luSize;

	//	if ( pClientCore->GetState() != ChClientCore::disconnected )
		{
			CButton * pBtn = (CButton*)GetDlgItem( IDC_CLR_CACHE );
			pBtn->EnableWindow( false );
		}

 		m_reg.Read( CH_CACHE_OPTION, luOption, CH_CACHE_OPTION_DEF );

		if ( luOption & CH_CACHE_VERIFY_PER_SESSION )
		{
			CheckDlgButton( IDC_VRFY_SESSION, true );
		}
		else if ( luOption & CH_CACHE_VERIFY_EVERYTIME )
		{
			CheckDlgButton( IDC_VRFY_EVERYTIME, true );
		}
		else
		{
			CheckDlgButton( IDC_VRFY_NEVER, true );
		}
											/* Set the initialized flag so
												that we don't do this again */
		UpdateData( false ); 			// initialize the controls
		m_boolInitialized = true;
	}

	return boolResult;
}


void ChCachePrefsPage::OnCommit()
{
	if (m_boolInitialized)
	{

		chuint32 luOption;

		if ( IsDlgButtonChecked( IDC_VRFY_SESSION ) )
		{
			luOption = CH_CACHE_VERIFY_PER_SESSION;
		}
		else if ( IsDlgButtonChecked( IDC_VRFY_EVERYTIME ) )
		{
			luOption = CH_CACHE_VERIFY_EVERYTIME;
		}
		else
		{
			luOption = CH_CACHE_VERIFY_NEVER;
		}

 		m_reg.Write( CH_CACHE_OPTION, luOption );

		char	strNum[30];
											// validate the directory

		if ( m_cacheDir[m_cacheDir.GetLength() - 1] != TEXT( '\\' ) )
		{
			m_cacheDir += TEXT( "\\" );
		}
		m_cacheDir += CACHE_DIR;

		if ( ChHTTPSocketConn::CreateAndValidateCacheDir( m_cacheDir ) )
		{
			m_reg.Write( CH_CACHE_DIR, m_cacheDir );
		}
		else
		{
			string strCaption;
			ChWebTrackerManager::WTrackerLoadString( AFX_IDS_APP_TITLE, strCaption );
			string strMessage;


			ChWebTrackerManager::WTrackerLoadString( IDS_INVALID_CACHE_DIR, strMessage );
			char * pMsg = new char[ m_cacheDir.GetLength() + strMessage.GetLength() + 2 ];
			wsprintf( pMsg, strMessage, m_cacheDir );
			ChMainFrame* pFrame = (ChMainFrame*)GetParentFrame(); 
			if ( pFrame )
			{
				pFrame->MessageBox( strMessage, strCaption, MB_ICONSTOP);
			}
			else
			{
				AfxMessageBox( pMsg );
			}
			delete []pMsg;
			return;
		}

		#if defined( CH_MSW )
		{
			_ltoa( m_uCacheSize, strNum, 10 );
		}
		#else	// defined( CH_MSW )
		{
			ltoa( m_uCacheSize, strNum, 10 );
		}
		#endif	// defined( CH_MSW )

 		m_reg.Write( CH_CACHE_SIZE, (chuint32)m_uCacheSize );
	}
}


/////////////////////////////////////////////////////////////////////////////
// ChCachePrefsPage message handlers

void ChCachePrefsPage::OnClrCache()
{
	ChHTTPSocketConn::ClearCache();
}


/////////////////////////////////////////////////////////////////////////////
// ChNetworkPage property page

IMPLEMENT_DYNCREATE(ChNetworkPage, CPropertyPage)

ChNetworkPage::ChNetworkPage() : CPropertyPage(ChNetworkPage::IDD),
					m_reg( CH_COMPANY_NAME, CH_HTML_PRODUCT_NAME, CH_NETWORK_GROUP ),
					m_boolInitialized( false )
{
	//{{AFX_DATA_INIT(ChNetworkPage)
	m_uMaxConn = 0;
	//}}AFX_DATA_INIT
}

ChNetworkPage::~ChNetworkPage()
{
}

void ChNetworkPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ChNetworkPage)
	DDX_Text(pDX, IDC_MAX_CONN, m_uMaxConn);
	DDV_MinMaxUInt(pDX, m_uMaxConn, 1, 10);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ChNetworkPage, CPropertyPage)
	//{{AFX_MSG_MAP(ChNetworkPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


bool ChNetworkPage::OnSetActive()
{
	bool	boolResult;

	boolResult = CPropertyPage::OnSetActive();

	if (!m_boolInitialized)
	{
		string		strSize;

 		m_reg.Read( CH_MAX_CONNECTIONS, strSize, 
 						CH_MAX_CONNECTIONS_DEF );

		m_uMaxConn = atoi( strSize );
											/* Set the initialized flag so
												that we don't do this again */
		UpdateData( false ); 			// initialize the controls
		m_boolInitialized = true;
	}


	return boolResult;
}


BOOL ChNetworkPage::OnKillActive()
{                      
	UpdateData( true );
	if (m_boolInitialized)
	{
	 	char strNum[30];
		_itoa( m_uMaxConn, strNum, 10 );
		if ( m_uMaxConn )
		{    
			string strTemp;
			
			strTemp = strNum;
 			m_reg.Write( CH_MAX_CONNECTIONS, strTemp );
		}
	}   
	return ( true );
}


/////////////////////////////////////////////////////////////////////////////
// ChNetworkPage message handlers     

