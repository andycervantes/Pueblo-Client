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

	This file contains the implementation of the ChPrefsApps class,
	which manages helper application preferences.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/client/msw/ChPrApps.cpp,v 2.10 1996/04/19 00:33:24 coyote Exp $

#include "headers.h"

#include <cderr.h>

#include <ChReg.h>
#include <ChUtil.h>
#include "pueblo.h"
#include "ChPrApps.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define OPEN_DLG_FLAGS		(OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST |\
								OFN_HIDEREADONLY | OFN_ENABLETEMPLATE)


/*----------------------------------------------------------------------------
	ChPrefsApps class
----------------------------------------------------------------------------*/

IMPLEMENT_DYNCREATE( ChPrefsApps, ChPropertyPage )


ChPrefsApps::ChPrefsApps() :
				ChPropertyPage( ChPrefsApps::IDD, 0, hInstApp ),
				m_reg( CH_APPS_GROUP ),
				m_boolInitialized( false )
{
	//{{AFX_DATA_INIT(ChPrefsApps)
	m_strBrowser = _T("");
	m_boolInternal = FALSE;
	//}}AFX_DATA_INIT
}


ChPrefsApps::~ChPrefsApps()
{
}


void ChPrefsApps::DoDataExchange( CDataExchange* pDX )
{
	ChPropertyPage::DoDataExchange( pDX );

	//{{AFX_DATA_MAP(ChPrefsApps)
	//}}AFX_DATA_MAP
}


bool ChPrefsApps::OnSetActive()
{
	bool	boolResult;

	boolResult = ChPropertyPage::OnSetActive();

	if (!m_boolInitialized)
	{
		ReadRegistry();
											/* Set the initialized flag so
												that we don't do this again */
		m_boolInitialized = true;
	}

	return boolResult;
}


void ChPrefsApps::OnCommit()
{
	if (m_boolInitialized)
	{
		m_reg.WriteBool( CH_APP_WEBTRACKER, m_boolInternal );
		m_reg.Write( CH_APP_WEBBROWSER, m_strBrowser );
	}     
}


BEGIN_MESSAGE_MAP( ChPrefsApps, ChPropertyPage )
	//{{AFX_MSG_MAP(ChPrefsApps)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChPrefsApps protected methods
----------------------------------------------------------------------------*/

void ChPrefsApps::ReadRegistry()
{
	m_reg.Read( CH_APP_WEBBROWSER, m_strBrowser, CH_APP_WEBBROWSER_DEF );
	m_reg.ReadBool( CH_APP_WEBTRACKER, m_boolInternal, CH_APP_WEBTRACKER_DEF );

	DisplayBrowserName( m_strBrowser );
	
	if (m_strBrowser.IsEmpty() || m_boolInternal)
	{
		m_boolInternal = true;	
	}
}

void ChPrefsApps::DisplayBrowserName( const string& strName )
{
	CStatic*	pStatic = (CStatic*)GetDlgItem( IDC_STATIC_BROWSER );

	if (strName.GetLength())
	{
		string		strBrowserName( strName );
		int			iIndex = strBrowserName.ReverseFind( '\\' );

		if (-1 != iIndex)
		{
			strBrowserName = strBrowserName.Mid( iIndex + 1 );
		}

		pStatic->SetWindowText( strBrowserName );
	}
	else
	{	
		string		strTag;

		LOADSTRING( IDS_WEB_BROWSER_INTERNAL, strTag );
		pStatic->SetWindowText( strTag );
	}
}


/*----------------------------------------------------------------------------
	ChPrefsApps message handlers
----------------------------------------------------------------------------*/

void ChPrefsApps::OnBrowse() 
{
	string			strFilter;
	string			strTitle;
	int				iResult;

	LOADSTRING( IDS_OPEN_WEB_BROWSER_FILTER, strFilter );
	LOADSTRING( IDS_OPEN_WEB_BROWSER_TITLE, strTitle );

	ChWebBrowserSelectFileDlg	browseDlg( strTitle, m_strBrowser, strFilter,
											AfxGetMainWnd() );

	iResult = browseDlg.DoModal();
	if (IDOK == iResult)
	{										// Read the registry again
		ReadRegistry();
	}
	else if (IDC_INTERNAL == iResult)
	{
		m_boolInternal = true;
		m_strBrowser = "";

		DisplayBrowserName( m_strBrowser );
	}
}


/*----------------------------------------------------------------------------
	Utility functions
----------------------------------------------------------------------------*/

UINT APIENTRY ChOpenFileHook( HWND hdlg, UINT message, WPARAM wParam,
									LPARAM lParam );
CH_INTERN_FUNC( bool )
ChOpenFileHookNotify( HWND hDlg, OFNOTIFY* pOFN );


/*----------------------------------------------------------------------------
	ChWebBrowserSelectFileDlg class
----------------------------------------------------------------------------*/

ChWebBrowserSelectFileDlg::ChWebBrowserSelectFileDlg( const string& strTitle,
														const string& strBrowser,
														const string& strFilter,
														CWnd* pParent ) :
		CFileDialog( true, "exe", 0, OPEN_DLG_FLAGS, strFilter ),
		m_reg( CH_APPS_GROUP ),
		m_boolInternal( false )
{
	chuint32	flSysProps = ChUtil::GetSystemProperties();
	string		strBrowserName( strBrowser );
	int			iIndex = strBrowser.ReverseFind( '\\' );

	if (-1 != iIndex)
	{
		m_strInitialDir = strBrowser.Left( iIndex + 1 );
		strBrowserName = strBrowserName.Mid( iIndex + 1 );
	}
											/* Setup initial file name
												(Copied into buffer in
													CFileDialog) */
	lstrcpyn( m_szFileName, strBrowserName,
				(sizeof( m_szFileName ) / sizeof( m_szFileName[0] )) );

	m_ofn.lpstrTitle = strTitle;
	m_ofn.lpstrInitialDir = m_strInitialDir;

	if (flSysProps & CH_PROP_WIN95)
	{
		m_ofn.Flags |= OFN_EXPLORER;
	}

	if (flSysProps & CH_PROP_LONG_FILENAMES)
	{
		m_ofn.Flags |= OFN_LONGNAMES;
	}

	if (flSysProps & CH_PROP_WIN95)
	{
		m_ofn.lpTemplateName = MAKEINTRESOURCE( IDD_SELECT_WEB_BROWSER_95 );
		m_ofn.hInstance = AfxGetInstanceHandle();

											/* On Windows95, we need a hook
												to get button presses */
		m_ofn.Flags |= OFN_ENABLEHOOK;
		m_ofn.lCustData = (DWORD)this;
		m_ofn.lpfnHook = ChOpenFileHook;
	}
	else
	{
		m_ofn.lpTemplateName = MAKEINTRESOURCE( IDD_SELECT_WEB_BROWSER );
		m_ofn.hInstance = AfxGetInstanceHandle();
	}

	//{{AFX_DATA_INIT(ChWebBrowserSelectFileDlg)
	//}}AFX_DATA_INIT
}


int ChWebBrowserSelectFileDlg::DoModal() 
{
	int		iResult;

	m_iModalResult = 0;

	if (IDOK == (iResult = CFileDialog::DoModal()))
	{
		m_reg.Write( CH_APP_WEBBROWSER, GetPathName( ) );
		m_boolInternal = false;
	}
	else
	{
		if (IDC_INTERNAL == m_iModalResult)
		{									/* They really pressed
												'use internal' */
			m_boolInternal = true;
			iResult = IDC_INTERNAL;
		}

		#if defined( CH_DEBUG )

		else if (IDCANCEL == iResult)
		{
			DWORD	dwExtendedError;

			dwExtendedError = CommDlgExtendedError();

			if (dwExtendedError)
			{
				switch (dwExtendedError)
				{
					case CDERR_NOHINSTANCE:
					{
						TRACE( "The ENABLETEMPLATE flag was specified in the "
								"Flags member of a structure for the "
								"corresponding common dialog box, but "
								"the application failed to provide a "
								"corresponding instance handle." );
						break;
					}

					case CDERR_DIALOGFAILURE:
					{
						TRACE( "The common dialog box procedure's call to "
								"the DialogBox function failed. For "
								"example, this error occurs if the common "
								"dialog box call specifies an invalid window "
								"handle.\n" );
						break;
					}

					case CDERR_FINDRESFAILURE:
					{
						TRACE( "The common dialog box procedure failed to "
								"find a specified resource.\n" );
						break;
					}

					case CDERR_INITIALIZATION:
					{
						TRACE( "The common dialog box procedure failed "
								"during initialization. This error often "
								"occurs when insufficient memory is "
								"available.\n" );
						break;
					}

					case CDERR_LOADRESFAILURE:
					{
						TRACE( "The common dialog box procedure failed "
								"to load a specified resource.\n" );
						break;
					}

					case CDERR_LOCKRESFAILURE:
					{
						TRACE( "The common dialog box procedure failed "
								"to lock a specified resource.\n" );
						break;
					}

					default:
					{
						TRACE1( "Error %lu in ChSoundOpenFileDlg::DoModal()\n",
									dwExtendedError );
						break;
					}
				}
			}
		}

		#endif	// defined( CH_DEBUG )
	}

	m_reg.WriteBool( CH_APP_WEBTRACKER, m_boolInternal );

	return iResult;
}


void ChWebBrowserSelectFileDlg::DoDataExchange( CDataExchange* pDX )
{
	CFileDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(ChWebBrowserSelectFileDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP( ChWebBrowserSelectFileDlg, CFileDialog )
	//{{AFX_MSG_MAP(ChWebBrowserSelectFileDlg)
    ON_BN_CLICKED(IDC_INTERNAL, OnInternal)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChWebBrowserSelectFileDlg message handlers
----------------------------------------------------------------------------*/

void ChWebBrowserSelectFileDlg::OnInternal()
{
	m_iModalResult = IDC_INTERNAL;

    m_boolInternal = true;
    EndDialog( IDC_INTERNAL );
}


/*----------------------------------------------------------------------------
	ChWebBrowserSelectFileDlg class hook function
----------------------------------------------------------------------------*/

UINT APIENTRY ChOpenFileHook( HWND hDlg, UINT message, WPARAM wParam,
									LPARAM lParam )
{
	bool		boolProcessed;

	switch( message )
	{
		case WM_NOTIFY:
		{
			boolProcessed = ChOpenFileHookNotify( hDlg, (OFNOTIFY*)lParam );
			break;
		}

		case WM_COMMAND:
		{
			if (HIWORD( wParam ) == BN_CLICKED)
			{
				switch( LOWORD( wParam ) )
				{
					case IDC_INTERNAL:
					{
						HWND						hwndButton = (HWND)lParam;
						ChWebBrowserSelectFileDlg*	pDlg;

						pDlg = (ChWebBrowserSelectFileDlg*)
									GetWindowLong( hwndButton, GWL_USERDATA );
						ASSERT( pDlg );

						pDlg->UseInternal();
						boolProcessed = true;
						break;
					}

					default:
					{
						boolProcessed = false;
						break;
					}
				}
			}
			break;
		}

		default:
		{
			boolProcessed = false;
			break;
		}
	}

	return boolProcessed;
}


CH_INTERN_FUNC( bool )
ChOpenFileHookNotify( HWND hDlg, OFNOTIFY* pOFN )
{
	bool		boolProcessed;

	switch( pOFN->hdr.code )
	{
		case CDN_INITDONE:
		{
			HWND hBtn = GetDlgItem( hDlg, IDC_INTERNAL );
			if (hBtn)
			{
				SetWindowLong( hBtn, GWL_USERDATA,
								(DWORD)pOFN->lpOFN->lCustData );
			}
			boolProcessed = true;
			break;
		}

		default:
		{
			boolProcessed = false;
			break;
		}
	}

	return boolProcessed;
}
