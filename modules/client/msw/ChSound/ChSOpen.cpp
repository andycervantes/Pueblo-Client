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

	Implementation of the ChSoundOpenFileDlg, based on the Windows common
	dialog.  This dialog manages opening sound files.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChSound/ChSOpen.cpp,v 1.8 1996/10/09 20:31:55 coyote Exp $

#include "headers.h"

#include <dlgs.h>

#include "ChSound.h"
#include "ChSOpen.h"
#include "ChSoundInfo.h"

#include <cderr.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	Utility functions
----------------------------------------------------------------------------*/

UINT APIENTRY ChSoundOpenFileHook( HWND hdlg, UINT message, WPARAM wParam,
									LPARAM lParam );
CH_INTERN_FUNC( bool )
ChSoundOpenFileHookNotify( HWND hDlg, OFNOTIFY* pOFN );


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define OPEN_DLG_FLAGS		(OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST |\
								OFN_HIDEREADONLY | OFN_ENABLETEMPLATE)
#define OPEN_DLG_FILTER		"Wave Files (*.wav)|*.wav|"\
								"All Files (*.*)|*.*||"


/*----------------------------------------------------------------------------
	ChSoundOpenFileDlg class
----------------------------------------------------------------------------*/

ChSoundOpenFileDlg::ChSoundOpenFileDlg( ChSoundMainInfo* pMainInfo,
										chuint16 suVolume,
										const string& strAlertSoundPath,
										const string& strAlertSoundTitle,
										CWnd* pParent ) :
		CFileDialog( true, "wav", strAlertSoundTitle, OPEN_DLG_FLAGS,
						OPEN_DLG_FILTER ),
		m_pMainInfo( pMainInfo ),
		m_suVolume( suVolume ),
		m_strInitialTitle( strAlertSoundTitle ),
		m_strInitialPath( strAlertSoundPath ),
		m_boolNoSound( false )
{
	m_flSysProps = ChUtil::GetSystemProperties();

	if (m_suVolume < 0x7FFF)
	{										/* Make sure they can hear tested
												sounds */
		m_suVolume = 0x7FFF;
	}

	m_ofn.lpstrInitialDir = m_strInitialPath;

	if (m_flSysProps & CH_PROP_WIN95)
	{
		m_ofn.Flags |= OFN_EXPLORER;
	}

	if (m_flSysProps & CH_PROP_LONG_FILENAMES)
	{
		m_ofn.Flags |= OFN_LONGNAMES;
	}

	#if !defined( CH_PUEBLO_PLUGIN )
	{
		m_ofn.hInstance = ChSoundDLL.hModule;
	}
	#else
	{
		m_ofn.hInstance = AfxGetInstanceHandle();
	}
	#endif

	if (m_flSysProps & CH_PROP_WIN95)
	{
		m_ofn.lpTemplateName = MAKEINTRESOURCE( IDD_SOUND_FILE_OPEN_95 );

											/* On Windows95, we need a hook
												to get button presses */
		m_ofn.Flags |= OFN_ENABLEHOOK;
		m_ofn.lCustData = (DWORD)this;
		m_ofn.lpfnHook = ChSoundOpenFileHook;
	}
	else
	{
		m_ofn.lpTemplateName = MAKEINTRESOURCE( IDD_SOUND_FILE_OPEN );
	}

	//{{AFX_DATA_INIT(ChSoundOpenFileDlg)
	//}}AFX_DATA_INIT
}


int ChSoundOpenFileDlg::DoModal() 
{
	int			iResult;

	iResult = CFileDialog::DoModal();

	#if defined( CH_DEBUG )
	{
		if (IDCANCEL == iResult)
		{
			DWORD	dwExtendedError;

			dwExtendedError = CommDlgExtendedError();

			if (dwExtendedError)
			{
				switch (dwExtendedError)
				{
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
	}
	#endif	// defined( CH_DEBUG )

	if (m_boolNoSound)
	{
		m_szFileTitle[0] = 0;
		m_szFileName[0] = 0;
	}

	return iResult;
}


void ChSoundOpenFileDlg::DoDataExchange( CDataExchange* pDX )
{
	CFileDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ChSoundOpenFileDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP( ChSoundOpenFileDlg, CFileDialog )
	//{{AFX_MSG_MAP(ChSoundOpenFileDlg)
	ON_BN_CLICKED(IDC_NO_SOUND, OnNoSound)
	ON_BN_CLICKED(IDC_TEST, OnTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChSoundOpenFileDlg message handlers
----------------------------------------------------------------------------*/

void ChSoundOpenFileDlg::OnNoSound() 
{
	m_boolNoSound = true;
	EndDialog( IDOK );
}


void ChSoundOpenFileDlg::OnTest() 
{
	string	strCurrent;

	if (m_flSysProps & CH_PROP_WIN95)
	{
		char	strBuffer[_MAX_PATH];

		SendMessage( CDM_GETFILEPATH, sizeof( strBuffer ),
						(LPARAM)(char*)strBuffer );
		strCurrent = strBuffer;
	}
	else
	{
		CEdit*	pFilenameEdit;

		if (pFilenameEdit = (CEdit*)GetDlgItem( 1152 ))
		{
			pFilenameEdit->GetWindowText( strCurrent );
		}
	}

	if (!strCurrent.IsEmpty() && GetMainInfo())
	{
		ChSoundInfo		info( false, true, m_suVolume );

		info.SetFilename( strCurrent );
		info.SetDeviceType( devWave );

		if (!GetMainInfo()->DoPlay( &info ))
		{
			AfxMessageBox( IDS_INVALID_SOUND );
		}
	}
}


/*----------------------------------------------------------------------------
	ChSoundOpenFileDlg class hook function
----------------------------------------------------------------------------*/

UINT APIENTRY ChSoundOpenFileHook( HWND hDlg, UINT message, WPARAM wParam,
									LPARAM lParam )
{
	bool		boolProcessed;

	switch( message )
	{
		case WM_NOTIFY:
		{
			boolProcessed = ChSoundOpenFileHookNotify( hDlg,
														(OFNOTIFY*)lParam );
			break;
		}

		case WM_COMMAND:
		{
			if (HIWORD( lParam ) == BN_CLICKED)
			{
				switch( LOWORD( wParam ) )
				{
					case IDC_TEST:
					{
						HWND					hwndButton = (HWND)lParam;
						ChSoundOpenFileDlg*		pDlg;

						pDlg = (ChSoundOpenFileDlg*)
									GetWindowLong( hwndButton, GWL_USERDATA );
						ASSERT( pDlg );

						pDlg->Test();
						boolProcessed = true;
						break;
					}

					case IDC_NO_SOUND:
					{
						HWND					hwndButton = (HWND)lParam;
						ChSoundOpenFileDlg*		pDlg;

						pDlg = (ChSoundOpenFileDlg*)
									GetWindowLong( hwndButton, GWL_USERDATA );
						ASSERT( pDlg );

						pDlg->NoSound();
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
ChSoundOpenFileHookNotify( HWND hDlg, OFNOTIFY* pOFN )
{
	bool		boolProcessed;

	switch( pOFN->hdr.code )
	{
		case CDN_INITDONE:
		{
			HWND	hBtn;

			hBtn = GetDlgItem( hDlg, IDC_TEST );
			if (hBtn)
			{
				SetWindowLong( hBtn, GWL_USERDATA,
								(DWORD)pOFN->lpOFN->lCustData );
			}

			hBtn = GetDlgItem( hDlg, IDC_NO_SOUND );
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
