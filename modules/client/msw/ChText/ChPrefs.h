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

	Interface for the ChTextOutPrefsPage class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/ChPrefs.h,v 2.6 1996/02/17 01:46:41 coyote Exp $

#if (!defined( _CHPREFS_H_ ))
#define _CHPREFS_H_


#include <ChPage.h>
#include <ChReg.h>

#include "ChTxtIn.h"


#ifdef CH_MSW

/*----------------------------------------------------------------------------
	ChTextOutPrefsPage class
----------------------------------------------------------------------------*/
	
class ChTextOutPrefsPage : public ChPropertyPage
{
	DECLARE_DYNCREATE( ChTextOutPrefsPage )

	public:
		ChTextOutPrefsPage();
		virtual ~ChTextOutPrefsPage();

		virtual bool OnSetActive();			/* Called when this page gets the
												focus */
		virtual void OnCommit();			/* Called to commit data (this is
												a good time to save data to the
												registry */

		inline chint32 GetLines() { return m_lLines; }

											// Dialog Data
		//{{AFX_DATA(ChTextOutPrefsPage)
		enum { IDD = IDD_PREF_PAGE_TEXT_OUT };
		CEdit	m_editLines;
		//}}AFX_DATA
											/* ClassWizard generate virtual
												function overrides */
		//{{AFX_VIRTUAL(ChTextOutPrefsPage)
		protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		//}}AFX_VIRTUAL

	protected:
		inline bool IsDirty() { return m_boolDirty; }
		inline void SetDirty( bool boolDirty = true )
						{
							m_boolDirty = boolDirty;
						}

		inline void SetLines( chint32 lLines ) { m_lLines = lLines; }

	protected:
											// Generated message map functions
		//{{AFX_MSG(ChTextOutPrefsPage)
		afx_msg void OnChangeEditLines();
		//}}AFX_MSG

		DECLARE_MESSAGE_MAP()

	protected:
		ChRegistry	m_reg;
		bool		m_boolInitialized;
		bool		m_boolDirty;

		chint32		m_lLines;
};


/*----------------------------------------------------------------------------
	ChTextInPrefsPage class
----------------------------------------------------------------------------*/
	
class ChTextInPrefsPage : public ChPropertyPage
{
	DECLARE_DYNCREATE( ChTextInPrefsPage )

	public:
		ChTextInPrefsPage();
		virtual ~ChTextInPrefsPage();

		inline ChKeyMapType GetKeymap() { return m_keyMap; }
		inline chint16 GetEditLines() { return m_sEditLines; }

		virtual bool OnSetActive();			/* Called when this page gets the
												focus */
		virtual bool OnKillActive();	    // Perform validation here
		virtual void OnCommit();			/* Called to commit data (this is
												a good time to save data to the
												registry */

		void SetEditLines( chint16 sLines );

											// Dialog Data
		//{{AFX_DATA(ChTextInPrefsPage)
		enum { IDD = IDD_PREF_PAGE_TEXT_IN };
		CEdit	m_editLineCount;
		int		m_iKeyMap;
		BOOL	m_boolClear;
		CString	m_strLineCount;
		//}}AFX_DATA
											/* ClassWizard generate virtual
												function overrides */
		//{{AFX_VIRTUAL(ChTextInPrefsPage)
		protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		//}}AFX_VIRTUAL

	protected:
		inline bool IsDirty() { return m_boolDirty; }
		inline void SetDirty( bool boolDirty = true )
						{
							m_boolDirty = boolDirty;
						}

		void DisplayTinTinName( const string& strName );

	protected:
											// Generated message map functions
		//{{AFX_MSG(ChTextInPrefsPage)
		afx_msg void OnUpdateEditLineCount();
	afx_msg void OnTintinFile();
	//}}AFX_MSG

		DECLARE_MESSAGE_MAP()

	protected:
		ChRegistry		m_reg;
		bool			m_boolInitialized;
		bool			m_boolDirty;

		chint16			m_sEditLines;
		ChKeyMapType	m_keyMap;

		string			m_strTinTinFile;
};



/*----------------------------------------------------------------------------
	ChTinTinSelectFileDlg class
----------------------------------------------------------------------------*/

class ChTinTinSelectFileDlg : public CFileDialog
{
	public:
		ChTinTinSelectFileDlg( const string& strTitle,
								const string& strPath,
								const string& strFilter,
								CWnd* pParent = 0 );

		inline void UseNoFile() { OnNoTinTinFile(); }
											// Dialog Data
		//{{AFX_DATA(ChWebBrowserSelectFileDlg)
		enum { IDD = IDD_SELECT_TINTIN };
		//}}AFX_DATA
											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(ChWebBrowserSelectFileDlg)
		public:
			virtual int DoModal();
		protected:
			virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		//}}AFX_VIRTUAL

	protected:
											// Generated message map functions
		//{{AFX_MSG(ChWebBrowserSelectFileDlg)
        afx_msg void OnNoTinTinFile();
		//}}AFX_MSG

		DECLARE_MESSAGE_MAP()

	protected:
		int				m_iModalResult;
		ChRegistry		m_reg;
		string			m_strInitialDir;
};


#endif // CH_MSW
#endif	// !defined( _CHPREFS_H_ )
