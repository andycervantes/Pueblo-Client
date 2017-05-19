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

	This file contains the interface for the ChLoginDlg classes, used to log
	into the Chaco server.  The classes defined in this file are as follows:

		ChLoginDlg		-- Used for logins when the Chaco client believes
							that the user already has an account on the
							server.
		ChLoginDlgFirst	-- Used for logins when the Chaco client believes
							that the user has never logged in before.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/client/msw/ChLoginD.h,v 2.8 1995/10/10 02:02:36 coyote Exp $

#if !defined( _CHLOGIND_H )
#define _CHLOGIND_H

#include "ChNList.h"

/*----------------------------------------------------------------------------
				ChLoginDlg dialog interface
----------------------------------------------------------------------------*/

class ChLoginDlg : public CDialog
{
	public:
		enum tagConstants{ minPasswordLen = 6,
							minUsernameLen = 1,
							maxUsernameLen = 20,
							maxPasswordLen = 20 };

	public:
		ChLoginDlg( const string& strUsername, CWnd *pParent = 0 );

		inline string GetUsername() { return m_strUsername; };
		inline string GetPassword() { return m_strPassword; };

		static bool GetSavedPassword( const string& strUsername,
										string& strPassword );

											// Dialog data
		//{{AFX_DATA(ChLoginDlg)
		enum { IDD = IDD_LOGIN };
		CButton	m_btnSignon;
		CEdit	m_editPassword;
		CButton	m_btnRemember;
		CComboBox	m_comboUsername;
		//}}AFX_DATA

											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(ChLoginDlg)
	protected:
			virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
		//}}AFX_VIRTUAL

	protected:
											// Generated message map functions
		//{{AFX_MSG(ChLoginDlg)
		virtual bool OnInitDialog();
		afx_msg void OnChangeLoginPassword();
		afx_msg void OnChangeLoginUsername();
		afx_msg void OnSelchangeLoginUsernameList();
		afx_msg void OnLoginNewAccount();
		afx_msg void OnLoginSignOn();
		afx_msg void OnEditchangeLoginUsername();
		afx_msg void OnHelp();
		//}}AFX_MSG

		afx_msg LONG OnNewUsernameSelected( WPARAM wParam, LPARAM lParam );
		
		DECLARE_MESSAGE_MAP()

	protected:
		void EndDialog( chint16 sResult );

		bool InitSavedPassword();
		void SavePassword();
		void EraseSavedPassword();

		void EncryptString( string& strSource, bool boolEncrypt );

		void SyncDataValues( bool boolToVariables = true );
		void ValidateFields();
		bool ValidatePassword();
		bool ValidatePasswordLen();

	protected:
		string		m_strUsername;
		string		m_strPassword;
		bool		m_boolRemember;

		ChNameList	m_nameList;
};


/*----------------------------------------------------------------------------
	ChPasswordVerifyDlg class
----------------------------------------------------------------------------*/

class ChPasswordVerifyDlg : public CDialog
{
	public:
		ChPasswordVerifyDlg( string strPassword, CWnd* pParent = 0 );

		inline const string& GetPassword() { return m_strPassword; }

											// Dialog Data
		//{{AFX_DATA(ChPasswordVerifyDlg)
		enum { IDD = IDD_VERIFY_PASSWORD };
		string	m_strPassword;
		string	m_strPasswordVerify;
		//}}AFX_DATA

											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(ChPasswordVerifyDlg)
		protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		//}}AFX_VIRTUAL

	protected:
											// Generated message map functions
		//{{AFX_MSG(ChPasswordVerifyDlg)
		afx_msg void OnHelp();
		virtual void OnOK();
		//}}AFX_MSG

		DECLARE_MESSAGE_MAP()
};

#endif	// !defined( _CHLOGIND_H )
