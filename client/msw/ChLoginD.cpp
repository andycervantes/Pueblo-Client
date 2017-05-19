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

	This file contains the implementation of the ChLoginDlg class, used to
	log into the Chaco server.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/client/msw/ChLoginD.cpp,v 2.18 1996/04/19 00:33:22 coyote Exp $

#include "headers.h"
#include "resource.h"

#include "ChLoginD.h"
#include "ChMFrame.h"
#include "ChClCore.h"

#include <ChReg.h>
#include <ChUtil.h>

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define FORBIDDEN_NAME_CHAR		'_'
#define MSG_NEW_USERNAME		(WM_USER + 1)


/*----------------------------------------------------------------------------
	ChLoginDlg class
----------------------------------------------------------------------------*/

ChLoginDlg::ChLoginDlg( const string& strUsername, CWnd *pParent ) :
				CDialog( ChLoginDlg::IDD, pParent ),
				m_nameList( CH_LOGIN_GROUP, CH_LOGIN_NAMES ),
				m_strUsername( strUsername )
{
	//{{AFX_DATA_INIT(ChLoginDlg)
	//}}AFX_DATA_INIT
}


/*----------------------------------------------------------------------------
	ChLoginDlg dialog member functions
----------------------------------------------------------------------------*/

void ChLoginDlg::DoDataExchange( CDataExchange* pDX )
{
	CDialog::DoDataExchange( pDX );

	//{{AFX_DATA_MAP(ChLoginDlg)
	DDX_Control(pDX, IDC_LOGIN_SIGN_ON, m_btnSignon);
	DDX_Control(pDX, IDC_LOGIN_PASSWORD, m_editPassword);
	DDX_Control(pDX, IDC_LOGIN_REMEMBER, m_btnRemember);
	DDX_Control(pDX, IDC_LOGIN_USERNAME, m_comboUsername);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP( ChLoginDlg, CDialog )
	//{{AFX_MSG_MAP( ChLoginDlg )
	ON_EN_CHANGE(IDC_LOGIN_PASSWORD, OnChangeLoginPassword)
	ON_CBN_SELCHANGE(IDC_LOGIN_USERNAME, OnSelchangeLoginUsernameList)
	ON_BN_CLICKED(IDC_LOGIN_NEW_ACCOUNT, OnLoginNewAccount)
	ON_BN_CLICKED(IDC_LOGIN_SIGN_ON, OnLoginSignOn)
	ON_CBN_EDITCHANGE(IDC_LOGIN_USERNAME, OnEditchangeLoginUsername)
	ON_BN_CLICKED(ID_HELP, OnHelp)
	//}}AFX_MSG_MAP

	ON_MESSAGE( MSG_NEW_USERNAME, OnNewUsernameSelected )
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChLoginDlg message handlers
----------------------------------------------------------------------------*/

bool ChLoginDlg::OnInitDialog()
{
	string		strNames;
	bool		boolFocusNotSet = true;
	string		strUsername;
	string		strPassword;

	CDialog::OnInitDialog();

	CenterWindow();


	if (m_nameList.GetCount() > 0)
	{
		chint16		sIndex = 0;
		string		strOneName;
		ChRegistry	reg( CH_LOGIN_GROUP );
											/* Add the names to the popup
												list */

		while (m_nameList.GetName( sIndex, strOneName ))
		{
			m_comboUsername.AddString( strOneName );
		}

		if (m_strUsername.IsEmpty())
		{
			reg.Read( CH_LOGIN_LAST_NAME, strOneName );
		}
		else
		{
			strOneName = m_strUsername;
		}

		if (!strOneName.IsEmpty())
		{									// Select the requested user name

			if (CB_ERR == m_comboUsername.SelectString( -1, strOneName ))
			{
											// Set focus to the username field

				m_comboUsername.SetWindowText( strOneName );
				m_comboUsername.SetEditSel( 0, -1 );
				m_comboUsername.SetFocus();
			}
			else
			{								// Set focus to the password field
				m_editPassword.SetFocus();
			}

			boolFocusNotSet = false;
		}
	}

	#if defined( CH_MSW ) && defined( CH_ARCH_32 )

	else
	{
		ChClientCore*	pCore = ChClientCore::GetCore();

		if (m_strUsername.IsEmpty())
		{
			if (pCore->GetClientInfo()->GetPlatform() == osWinNT)
			{
				char	buffer[80];
				DWORD	dwSize = sizeof( buffer );

											/* On NT, initialize with the user
												name */
				::GetUserName( buffer, &dwSize );

				m_comboUsername.SetWindowText( buffer );
				m_comboUsername.SetEditSel( 0, -1 );
			}
		}
		else
		{
			m_comboUsername.SetWindowText( m_strUsername );
			m_comboUsername.SetEditSel( 0, -1 );
		}

											// Set focus to the username field
		m_comboUsername.SetFocus();

		boolFocusNotSet = false;
	}

	#else
	{
		#pragma message( "GetUserName missing under win16" )
	}
	#endif

	if (InitSavedPassword())
	{
		m_btnSignon.SetFocus();
		boolFocusNotSet = false;
	}
											// Update the buttons
	ValidateFields();
											/* Limit the text in the edit
												fields */
	m_comboUsername.LimitText( maxUsernameLen );
	m_editPassword.LimitText( maxPasswordLen );

	return boolFocusNotSet;					/* Return true unless you set the
												focus to a control */
}

void ChLoginDlg::OnChangeLoginPassword()
{
	ValidateFields();
}


void ChLoginDlg::OnEditchangeLoginUsername()
{
	int		iIndex;
	string	strText;
	bool	boolChanged = false;

	m_comboUsername.GetWindowText( strText );

	while (-1 != (iIndex = strText.Find( FORBIDDEN_NAME_CHAR )))
	{
		strText = strText.Left( iIndex ) + strText.Mid( iIndex + 1 );
		boolChanged = true;
	}

	if (boolChanged)
	{
		DWORD		dwSel;
		chuint16	suSel;
											// Save the selection
		dwSel = m_comboUsername.GetEditSel();
		suSel = LOWORD( dwSel );
		if (suSel > 0)
		{
			suSel--;
		}
											// Change the text

		m_comboUsername.SetWindowText( strText );

											// Restore the selection

		m_comboUsername.SetEditSel( suSel, suSel );
	}

	ValidateFields();
}


void ChLoginDlg::OnSelchangeLoginUsernameList()
{
	PostMessage( MSG_NEW_USERNAME );
}


void ChLoginDlg::OnLoginSignOn()
{
											// Fill in the data fields
	SyncDataValues();

	if (m_boolRemember)
	{
		SavePassword();
	}
	else
	{
		EraseSavedPassword();
	}

	EndDialog( IDC_LOGIN_SIGN_ON );
}


void ChLoginDlg::OnLoginNewAccount()
{
	bool	boolValid;

	if (ChLoginDlg::ValidatePassword())
	{
		chuint16	sResult;

		do
		{
			ChPasswordVerifyDlg		verifyDlg( m_strPassword );

			sResult = verifyDlg.DoModal();

			if (IDOK == sResult)
			{									/* Get the password from the
													verify dialog to the login
													dialog */

				m_strPassword = verifyDlg.GetPassword();
				SyncDataValues( false );

				boolValid = ChLoginDlg::ValidatePassword();
			}
			else if (sResult == IDCANCEL)
			{
				boolValid = true;
			}

		} while (!boolValid);

		if (IDOK == sResult)
		{
											// Fill in the data fields
			SyncDataValues();
											// New password entered and valid
			if (m_boolRemember)
			{
				SavePassword();
			}
			else
			{
				EraseSavedPassword();
			}

			EndDialog( IDC_LOGIN_NEW_ACCOUNT );
		}
	}
}


void ChLoginDlg::OnHelp()
{
	WinHelp( 0x20000 + ChLoginDlg::IDD );
}


LONG ChLoginDlg::OnNewUsernameSelected( WPARAM wParam, LPARAM lParam )
{
	InitSavedPassword();

	ValidateFields();

	return 0;	
}


/*----------------------------------------------------------------------------
	ChLoginDlg protected methods
----------------------------------------------------------------------------*/

void ChLoginDlg::EndDialog( chint16 sResult )
{
											// Fill in the data fields
	SyncDataValues();
											// Call the parent class' method
	CDialog::EndDialog( sResult );
}


bool ChLoginDlg::InitSavedPassword()
{
	string		strUsername;
	string		strPassword;
	bool		boolFound;

	m_comboUsername.GetWindowText( strUsername );

	if (boolFound = GetSavedPassword( strUsername, strPassword ))
	{
		m_editPassword.SetWindowText( strPassword );
		m_editPassword.SetSel( 32767, 32767 );
		m_btnRemember.SetCheck( 1 );
	}
	else
	{
		m_editPassword.SetWindowText( "" );
		m_btnRemember.SetCheck( 0 );
	}

	return boolFound;
}


void ChLoginDlg::SavePassword()
{
	ChRegistry	reg( CH_LOGIN_GROUP );
	string		strEncryptedPassword = m_strPassword;

	if (!m_strUsername.IsEmpty() && !m_strPassword.IsEmpty())
	{
											// Encrypt the string

		ChUtil::EncryptString( strEncryptedPassword, true );
		reg.Write( m_strUsername, strEncryptedPassword );
	}
}


void ChLoginDlg::EraseSavedPassword()
{
	ChRegistry	reg( CH_LOGIN_GROUP );

	if (!m_strUsername.IsEmpty())
	{
		reg.Erase( m_strUsername );
	}
}


bool ChLoginDlg::GetSavedPassword( const string& strUsername,
									string& strPassword )
{
	ChRegistry	reg( CH_LOGIN_GROUP );
	string		strEncryptedPassword;
	bool		boolSaved = false;

	if (!strUsername.IsEmpty())
	{
		reg.Read( strUsername, strPassword, "" );
		if (!strPassword.IsEmpty())
		{									// Decrypt the string

			ChUtil::EncryptString( strPassword, false );
			boolSaved = true;
		}
	}

	return boolSaved;
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChLoginDlg::SyncDataValues

------------------------------------------------------------------------------

	This method will syncronize the member variables to the values of the
	controls.

----------------------------------------------------------------------------*/

void ChLoginDlg::SyncDataValues( bool boolToVariables )
{
	if (boolToVariables)
	{										// Get m_strPassword

		m_editPassword.GetWindowText( m_strPassword );

											// Get m_strUsername

		m_comboUsername.GetWindowText( m_strUsername );

		m_boolRemember = m_btnRemember.GetCheck() ? true : false;
	}
	else
	{
											// Set m_strPassword

		m_editPassword.SetWindowText( m_strPassword );

											// Set m_strUsername

		m_comboUsername.SetWindowText( m_strUsername );

		m_btnRemember.SetCheck( m_boolRemember ? 1 : 0 );
	}
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChLoginDlg::ValidateFields

------------------------------------------------------------------------------

	This method is called whenever the value of one of the entry fields
	changes.  The method ensures that valid values have been entered, and
	adjusts the buttons in the dialog accordingly.

----------------------------------------------------------------------------*/

void ChLoginDlg::ValidateFields()
{
	SyncDataValues();

	bool	boolLegal;
											// Check the username & password

	boolLegal = m_strUsername.GetLength() >= minUsernameLen;
	boolLegal = boolLegal && (m_strPassword.GetLength() > 0);

											/* Adjust buttons depending on
												legality */

	GetDlgItem( IDC_LOGIN_SIGN_ON )->EnableWindow( boolLegal );
	GetDlgItem( IDC_LOGIN_NEW_ACCOUNT )->EnableWindow( boolLegal );
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChLoginDlg::ValidatePassword

------------------------------------------------------------------------------

	This method is called after the user has selected 'login' or 'create
	account'.  The method ensures that the password meets basic legality
	requirements, and if it does, it returns true.

----------------------------------------------------------------------------*/

bool ChLoginDlg::ValidatePassword()
{
	bool	boolLegal = true;

	SyncDataValues();

	if (m_strPassword.GetLength() < minPasswordLen)
	{
		string	strFormat;
		string	strMessage;

		LOADSTRING( IDS_PWD_TOO_SHORT, strFormat );
		#if defined ( CH_ARCH_16 )         
		char *pstrMsg = strMessage.GetBufferSetLength( 
									strFormat.GetLength() + 10 );
		::wsprintf( pstrMsg, strFormat,  minPasswordLen );
		strMessage.ReleaseBuffer();
		#else
		strMessage.Format( (const char*)strFormat, minPasswordLen );
		#endif

		AfxMessageBox( strMessage, MB_OK | MB_ICONSTOP, 0 );

		boolLegal = false;
	}

	if (boolLegal)
	{
		string	strUsername( m_strUsername );
		string	strPassword( m_strPassword );

		strUsername.MakeLower();
		strPassword.MakeLower();
											/* Check to see if the user name
												and password are equal, or if
												the password contains the user
												name, or if the password is
												a part of the user name */

		if ((0 == strPassword.Compare( strUsername )) ||
			(-1 != strPassword.Find( strUsername )) ||
			(-1 != strUsername.Find( strPassword )))
		{
			AfxMessageBox( IDS_PWD_UN_EQUAL, MB_OK | MB_ICONSTOP, 0 );
			boolLegal = false;
		}
	}

	return boolLegal;
}


/*----------------------------------------------------------------------------
	ChPasswordVerifyDlg class
----------------------------------------------------------------------------*/

ChPasswordVerifyDlg::ChPasswordVerifyDlg( string strPassword, CWnd* pParent ) :
						CDialog( ChPasswordVerifyDlg::IDD, pParent ),
						m_strPassword( strPassword )
{
	//{{AFX_DATA_INIT(ChPasswordVerifyDlg)
	m_strPasswordVerify = _T("");
	//}}AFX_DATA_INIT
}


void ChPasswordVerifyDlg::DoDataExchange( CDataExchange* pDX )
{
	CDialog::DoDataExchange( pDX );

	//{{AFX_DATA_MAP(ChPasswordVerifyDlg)
	DDX_Text(pDX, IDC_LOGIN_PASSWORD, m_strPassword );
	DDX_Text(pDX, IDC_LOGIN_PASSWORD_VERIFY, m_strPasswordVerify );
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP( ChPasswordVerifyDlg, CDialog )
	//{{AFX_MSG_MAP(ChPasswordVerifyDlg)
	ON_BN_CLICKED(ID_HELP, OnHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChPasswordVerifyDlg message handlers
----------------------------------------------------------------------------*/

void ChPasswordVerifyDlg::OnHelp()
{
	WinHelp( 0x20000 + ChPasswordVerifyDlg::IDD );
}

void ChPasswordVerifyDlg::OnOK()
{
	UpdateData();

	if (m_strPassword == m_strPasswordVerify)
	{
		CDialog::OnOK();
	}
	else
	{
		CEdit*	pPWVerify = (CEdit*)GetDlgItem( IDC_LOGIN_PASSWORD_VERIFY );

		AfxMessageBox( IDS_PASSWORD_MISMATCH, MB_OK | MB_ICONSTOP, 0 );

											// Set focus back to the edit field
		pPWVerify->SetSel( 0, -1 );
		pPWVerify->SetFocus();
	}
}
