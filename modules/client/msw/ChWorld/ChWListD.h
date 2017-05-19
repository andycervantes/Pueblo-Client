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

	Implementation for the ChWorldListDlg class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChWorld/ChWListD.h,v 2.17 1996/03/18 21:06:12 coyote Exp $

#if !defined( _CHWLISTD_H )
#define _CHWLISTD_H

#include <ChReg.h>
#include <ChDlg.h>

#include "ChWList.h"


class ChCore;

/*----------------------------------------------------------------------------
	ChWorldListDlg class
----------------------------------------------------------------------------*/

class ChWorldListDlg : public ChDialog
{
	public:
		ChWorldListDlg( ChCore* pCore, bool boolConnected, CWnd* pParent = 0 );

		inline const string& GetName() { return m_strName; }
		inline const string& GetDesc() { return m_strDesc; }
		inline const string& GetHost() { return m_strHost; }
		inline const string& GetAddr() { return m_strAddr; }
		inline chint16 GetPort() { return m_sPort; }
		inline const ChWorldType& GetType() { return m_type; }
		inline ChLoginType GetLoginType() { return m_loginType; }
		inline const string& GetUsername() { return m_strUsername; }
		inline const string& GetPassword() { return m_strPassword; }
		inline const string& GetHomePage() { return m_strHomePage; }

											// Dialog Data
		//{{AFX_DATA(ChWorldListDlg)
		enum { IDD = IDD_WORLD_LIST };
		CButton	m_btnAdd;
		CButton	m_btnEdit;
		CButton	m_btnDelete;
		CButton	m_btnConnect;
		CListBox	m_listWorlds;
		//}}AFX_DATA
											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(ChWorldListDlg)
		protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		//}}AFX_VIRTUAL

	protected:
		void Add( bool boolChange, const string& strName,
					const string& strDesc, const string& strHost,
					chint16 sPort, const ChWorldType& type,
					ChLoginType login, const string& strUsername,
					const string& strPassword, const string& strHomePage );

		void UpdateButtons();

		void InstallWorldList();
		int AddNameToList( const string& strName, const string& strUsername );
		void ExtractName( const string& strListEntry, string& strName,
							string& strUsername );
		void CreateShortcut();
		bool SyncDataFields();
		ChWorldInfo* GetCurrInfo();
		void Delete( int iIndex );

	protected:
											// Generated message map functions
		//{{AFX_MSG(ChWorldListDlg)
		afx_msg void OnListAdd();
		virtual BOOL OnInitDialog();
		afx_msg void OnSelchangeWorldList();
		afx_msg void OnListDelete();
		afx_msg void OnListConnect();
		virtual void OnOK();
		afx_msg void OnListEdit();
		afx_msg void OnListCreateShortcut();
		//}}AFX_MSG

		DECLARE_MESSAGE_MAP()

	protected:
		ChCore*		m_pCore;
		bool		m_boolConnected;
		ChWorldList	m_worldList;

		string		m_strName;
		string		m_strDesc;
		string		m_strHost;
		string		m_strAddr;
		chint16		m_sPort;
		ChWorldType	m_type;
		ChLoginType	m_loginType;
		string		m_strUsername;
		string		m_strPassword;
		string		m_strHomePage;
};


/*----------------------------------------------------------------------------
	ChWorldListDlg class
----------------------------------------------------------------------------*/

class ChWorldListEdit : public CDialog
{
	public:
		ChWorldListEdit( CWnd* pParent = 0 );
		ChWorldListEdit( const string& strName, const string& strDesc,
							const string& strHost, chint16 sPort,
							ChWorldType type, ChLoginType loginType,
							const string& strUsername,
							const string& strPassword,
							const string& strHomePage, CWnd* pParent = 0 );

		inline bool IsNew() { return m_boolNew; }
		inline const string& GetName() { return m_strName; }
		inline const string& GetDesc() { return m_strDesc; }
		inline const string& GetHost() { return m_strHost; }
		inline chint16 GetPort() { return m_sPort; }
		inline const ChWorldType& GetType() { return m_type; }
		inline const string& GetUsername() { return m_strUsername; }
		inline const string& GetPassword() { return m_strPassword; }
		inline const string& GetHomePage() { return m_strHomePage; }
		inline ChLoginType GetLoginType() { return m_loginType; }

		void UpdateButtons();
		void UpdateWarningMessage();

		void RemoveIllegalChars( CEdit& edit );
											// Dialog Data
		//{{AFX_DATA(ChWorldListEdit)
		enum { IDD = IDD_WORLD_LIST_EDIT };
		CEdit	m_editHomePage;
		CButton	m_radioMudLogin;
		CButton	m_radioConnectLogin;
		CComboBox	m_comboTypes;
		CStatic	m_staticMessage;
		CEdit	m_editUsername;
		CEdit	m_editPassword;
		CButton	m_btnOkay;
		CEdit	m_editPort;
		CEdit	m_editName;
		CEdit	m_editHost;
		CEdit	m_editDesc;
		CString	m_strName;
		CString	m_strType;
		CString	m_strDesc;
		CString	m_strHost;
		int		m_sPort;
		CString	m_strUsername;
		CString	m_strPassword;
		int		m_iLoginStyle;
		CString	m_strHomePage;
		//}}AFX_DATA
											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(ChWorldListEdit)
		protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		//}}AFX_VIRTUAL

	protected:
											// Generated message map functions
		//{{AFX_MSG(ChWorldListEdit)
		afx_msg void OnChangeListName();
		afx_msg void OnChangeListHost();
		afx_msg void OnChangeListPort();
		afx_msg void OnSelchangeListType();
		virtual BOOL OnInitDialog();
		afx_msg void OnChangeListPassword();
		afx_msg void OnChangeListUsername();
		afx_msg void OnRadioLoginConnect();
		afx_msg void OnRadioLoginMud();
	afx_msg void OnUpdateListName();
	afx_msg void OnUpdateListUsername();
	//}}AFX_MSG

		DECLARE_MESSAGE_MAP()

	protected:
		bool		m_boolNew;
		ChWorldType	m_type;
		ChLoginType	m_loginType;
};


#endif	// !defined( _CHWLISTD_H )
