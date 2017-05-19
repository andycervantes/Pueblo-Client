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

	Implementation of the ChTextOutPrefsPage class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/ChPrefs.cpp,v 2.6 1996/02/17 01:46:40 coyote Exp $

#include "headers.h"
#include "resource.h"

#include "ChText.h"
#include "ChPrefs.h"
#include "ChKeyMapType.h"

#include <cderr.h>

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
	ChTextOutPrefsPage class
----------------------------------------------------------------------------*/
	
IMPLEMENT_DYNCREATE( ChTextOutPrefsPage, ChPropertyPage )

ChTextOutPrefsPage::ChTextOutPrefsPage() :
			ChPropertyPage( ChTextOutPrefsPage::IDD, 0, hTextDLL ),
			m_reg( TEXT_OUT_PREFS_GROUP ),
			m_boolDirty( false ),
			m_boolInitialized( false ),
			m_lLines( 0 )
{
	//{{AFX_DATA_INIT(ChTextOutPrefsPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

ChTextOutPrefsPage::~ChTextOutPrefsPage()
{
}


bool ChTextOutPrefsPage::OnSetActive()
{
	bool	boolResult;

	boolResult = ChPropertyPage::OnSetActive();

	if (!m_boolInitialized)
	{
		char		buffer[32];
		chint32		lLines;

		m_reg.Read( TEXT_OUT_PREFS_LINES, lLines, TEXT_OUT_PREFS_LINES_DEF );
		SetLines( lLines );
											/* Limit text to 4 digits and set
												the initial value */
		m_editLines.LimitText( 4 );

		sprintf( buffer, "%ld", GetLines() );
		m_editLines.SetWindowText( buffer );
											/* Set the initialized flag so
												that we don't do this again */
		m_boolInitialized = true;
	}

	return boolResult;
}


void ChTextOutPrefsPage::OnCommit()
{
	if (m_boolInitialized)
	{										// Write data to registry

		m_reg.Write( TEXT_OUT_PREFS_LINES, GetLines() );
	}     
}


void ChTextOutPrefsPage::DoDataExchange(CDataExchange* pDX)
{
	ChPropertyPage::DoDataExchange( pDX );

	//{{AFX_DATA_MAP(ChTextOutPrefsPage)
	DDX_Control(pDX, IDC_EDIT_LINES, m_editLines);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP( ChTextOutPrefsPage, ChPropertyPage )
	//{{AFX_MSG_MAP(ChTextOutPrefsPage)
	ON_EN_CHANGE(IDC_EDIT_LINES, OnChangeEditLines)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChTextOutPrefsPage message handlers
----------------------------------------------------------------------------*/
	
void ChTextOutPrefsPage::OnChangeEditLines() 
{
	string		strText;
	chint32		lLines;
	char		buffer[32];

	m_editLines.GetWindowText( strText );

	lLines = atol( strText );
	sprintf( buffer, "%ld", lLines );

	if (strText != buffer)
	{
		m_editLines.SetWindowText( buffer );
		m_editLines.SetSel( 32767, 32767 );
	}

	if (GetLines() != lLines)
	{
		SetLines( lLines );
		SetDirty();
	}
}



/*----------------------------------------------------------------------------
	ChTextInPrefsPage class
----------------------------------------------------------------------------*/
	
IMPLEMENT_DYNCREATE( ChTextInPrefsPage, ChPropertyPage )

ChTextInPrefsPage::ChTextInPrefsPage() :
			ChPropertyPage( ChTextInPrefsPage::IDD, 0, hTextDLL ),
			m_reg( TEXT_IN_PREFS_GROUP ),
			m_boolDirty( false ),
			m_boolInitialized( false ),
			m_sEditLines( 0 )
{
	//{{AFX_DATA_INIT(ChTextInPrefsPage)
	m_iKeyMap = -1;
	m_boolClear = FALSE;
	m_strLineCount = _T("");
	//}}AFX_DATA_INIT
}

ChTextInPrefsPage::~ChTextInPrefsPage()
{
}


bool ChTextInPrefsPage::OnSetActive()
{
	bool	boolResult;

	boolResult = ChPropertyPage::OnSetActive();

	if (!m_boolInitialized)
	{
		string		strKeyMap;

		m_reg.Read( TEXT_IN_PREFS_KEYMAP, strKeyMap,
					TEXT_IN_PREFS_KEYMAP_DEF );
		m_keyMap.Set( strKeyMap );

		m_reg.Read( TEXT_IN_EDIT_LINES, m_sEditLines,
					TEXT_IN_EDIT_LINES_DEF );

		m_reg.Read( TEXT_IN_TINTIN_FILE, m_strTinTinFile,
					TEXT_IN_TINTIN_FILE_DEF );
		DisplayTinTinName( m_strTinTinFile );
											// Initialize the dialog data
		UpdateData( false );
											// Limit the edit field to 2 digits
		m_editLineCount.LimitText( 2 );
											/* Set the initialized flag so
												that we don't do this again */
		m_boolInitialized = true;
	}

	return boolResult;
}


bool ChTextInPrefsPage::OnKillActive()
{
	bool	boolSuccess;

	if (boolSuccess = ChPropertyPage::OnKillActive())
	{
		if ((GetEditLines() <= 0) || (GetEditLines() > TEXT_IN_EDIT_LINES_MAX))
		{
			string		strFormat;
			string		strOut;

			LOADSTRING( IDS_LINES_OUT_OF_RANGE, strFormat );
			strOut.Format( strFormat, (int)TEXT_IN_EDIT_LINES_MAX );
			MessageBox( strOut );
			m_editLineCount.SetFocus();

			boolSuccess = false;
		}
	}

	return boolSuccess;
}


void ChTextInPrefsPage::OnCommit()
{
	if (m_boolInitialized)
	{										// Write data to registry

		m_reg.Write( TEXT_IN_PREFS_KEYMAP, m_keyMap.GetName() );
		m_reg.Write( TEXT_IN_EDIT_LINES, m_sEditLines );
		m_reg.Write( TEXT_IN_TINTIN_FILE, m_strTinTinFile );
	}     
}


void ChTextInPrefsPage::SetEditLines( chint16 sLines )
{
	m_sEditLines = sLines;

	if (GetEditLines() <= 0)
	{
		m_sEditLines = 1;
	}
	else if (GetEditLines() > TEXT_IN_EDIT_LINES_MAX)
	{
		m_sEditLines = TEXT_IN_EDIT_LINES_MAX;
	}
}


void ChTextInPrefsPage::DoDataExchange( CDataExchange* pDX )
{
	ChPropertyPage::DoDataExchange( pDX );

	if (!pDX->m_bSaveAndValidate)
	{
		m_strLineCount.Format( "%hd", m_sEditLines );

		switch( m_keyMap )
		{
			case keymapEmacs:
			{
				m_iKeyMap = 1;
				break;
			}

			default:
			{
				m_iKeyMap = 0;
				break;
			}
		}
	}

	//{{AFX_DATA_MAP(ChTextInPrefsPage)
	DDX_Control(pDX, IDC_EDIT_LINE_COUNT, m_editLineCount);
	DDX_Radio(pDX, IDC_RADIO_WINDOWS, m_iKeyMap);
	DDX_Check(pDX, IDC_CHECK_CLEAR, m_boolClear);
	DDX_Text(pDX, IDC_EDIT_LINE_COUNT, m_strLineCount);
	//}}AFX_DATA_MAP

	if (pDX->m_bSaveAndValidate)
	{
		m_sEditLines = atoi( m_strLineCount );

		switch( m_iKeyMap )
		{
			case 1:
			{
				m_keyMap = keymapEmacs;
				break;
			}

			default:
			{
				m_keyMap = keymapWindows;
				break;
			}
		}
	}
}


BEGIN_MESSAGE_MAP( ChTextInPrefsPage, ChPropertyPage )
	//{{AFX_MSG_MAP(ChTextInPrefsPage)
	ON_EN_UPDATE(IDC_EDIT_LINE_COUNT, OnUpdateEditLineCount)
	ON_BN_CLICKED(IDC_TINTIN_FILE, OnTintinFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChTextInPrefsPage protected methods
----------------------------------------------------------------------------*/

void ChTextInPrefsPage::DisplayTinTinName( const string& strName )
{
	CStatic*	pStatic = (CStatic*)GetDlgItem( IDC_STATIC_TINTIN_FILE );

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

		LOADSTRING( IDS_TINTIN_NO_FILE, strTag );
		pStatic->SetWindowText( strTag );
	}
}


/*----------------------------------------------------------------------------
	ChTextInPrefsPage message handlers
----------------------------------------------------------------------------*/

void ChTextInPrefsPage::OnUpdateEditLineCount() 
{
	string		strNewText;
	const char*	pstrOld;

	m_editLineCount.GetWindowText( m_strLineCount );
	pstrOld = m_strLineCount;

	while (*pstrOld)
	{
		if (isdigit( *pstrOld ))
		{
			strNewText += *pstrOld;
		}

		pstrOld++;
	}

	if (strNewText != m_strLineCount)
	{
		int		iStart;
		int		iEnd;

		m_editLineCount.GetSel( iStart, iEnd );

		m_editLineCount.SetWindowText( strNewText );

											/* Subtract one since we're
												removing a character from
												the edit field */
		if (iStart > 0)	iStart--;
		if (iEnd > 0)	iEnd--;

		m_editLineCount.SetSel( iStart, iEnd );
		MessageBeep( MB_OK );
	}
}


void ChTextInPrefsPage::OnTintinFile() 
{
	string		strFilter;
	string		strTitle;
	int			iResult;

	LOADSTRING( IDS_OPEN_TINTIN_FILTER, strFilter );
	LOADSTRING( IDS_OPEN_TINTIN_TITLE, strTitle );

	ChTinTinSelectFileDlg	browseDlg( strTitle, m_strTinTinFile, strFilter,
											AfxGetMainWnd() );

	iResult = browseDlg.DoModal();

	if (IDOK == iResult)
	{										// Read the registry again

		m_reg.Read( TEXT_IN_TINTIN_FILE, m_strTinTinFile,
					TEXT_IN_TINTIN_FILE_DEF );
		DisplayTinTinName( m_strTinTinFile );
	}
	else if (IDC_NO_TINTIN_FILE == iResult)
	{
		m_strTinTinFile = "";

		DisplayTinTinName( m_strTinTinFile );
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
	ChTinTinSelectFileDlg class
----------------------------------------------------------------------------*/

ChTinTinSelectFileDlg::ChTinTinSelectFileDlg( const string& strTitle,
														const string& strBrowser,
														const string& strFilter,
														CWnd* pParent ) :
		CFileDialog( true, "txt", 0, OPEN_DLG_FLAGS, strFilter ),
		m_reg( TEXT_IN_PREFS_GROUP )
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
		m_ofn.lpTemplateName = MAKEINTRESOURCE( IDD_SELECT_TINTIN_95 );
		m_ofn.hInstance = ChTextDLL.hModule;

											/* On Windows95, we need a hook
												to get button presses */
		m_ofn.Flags |= OFN_ENABLEHOOK;
		m_ofn.lCustData = (DWORD)this;
		m_ofn.lpfnHook = ChOpenFileHook;
	}
	else
	{
		m_ofn.lpTemplateName = MAKEINTRESOURCE( IDD_SELECT_TINTIN );
		m_ofn.hInstance = ChTextDLL.hModule;
	}

	//{{AFX_DATA_INIT(ChTinTinSelectFileDlg)
	//}}AFX_DATA_INIT
}


int ChTinTinSelectFileDlg::DoModal() 
{
	int		iResult;

	m_iModalResult = 0;

	if (IDOK == (iResult = CFileDialog::DoModal()))
	{
		m_reg.Write( TEXT_IN_TINTIN_FILE, GetPathName() );
	}
	else
	{
		if (IDC_NO_TINTIN_FILE == m_iModalResult)
		{									/* They really pressed
												'use internal' */
			iResult = IDC_NO_TINTIN_FILE;
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

	return iResult;
}


void ChTinTinSelectFileDlg::DoDataExchange( CDataExchange* pDX )
{
	CFileDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ChTinTinSelectFileDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP( ChTinTinSelectFileDlg, CFileDialog )
	//{{AFX_MSG_MAP(ChTinTinSelectFileDlg)
    ON_BN_CLICKED(IDC_NO_TINTIN_FILE, OnNoTinTinFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChTinTinSelectFileDlg message handlers
----------------------------------------------------------------------------*/

void ChTinTinSelectFileDlg::OnNoTinTinFile()
{
	m_iModalResult = IDC_NO_TINTIN_FILE;

    EndDialog( IDC_NO_TINTIN_FILE );
}


/*----------------------------------------------------------------------------
	ChTinTinSelectFileDlg class hook function
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
			if (HIWORD( lParam ) == BN_CLICKED)
			{
				switch( LOWORD( wParam ) )
				{
					case IDC_NO_TINTIN_FILE:
					{
						HWND					hwndButton = (HWND)lParam;
						ChTinTinSelectFileDlg*	pDlg;

						pDlg = (ChTinTinSelectFileDlg*)
									GetWindowLong( hwndButton, GWL_USERDATA );
						ASSERT( pDlg );

						pDlg->UseNoFile();
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
			HWND hBtn = GetDlgItem( hDlg, IDC_NO_TINTIN_FILE );
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
