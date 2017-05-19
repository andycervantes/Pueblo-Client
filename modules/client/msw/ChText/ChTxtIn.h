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

	Interface for the ChTextInputBar class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/ChTxtIn.h,v 2.20 1996/02/17 01:46:43 coyote Exp $

#if !defined( _CHTXTIN_H )
#define _CHTXTIN_H

#include <ChClMod.h>
#include <ChSerMod.h>

#include <ChMenu.h>
#include <ChHook.h>
#include <ChKeyMap.h>

#include "ChHist.h"
#include "ChKeyMapType.h"
#include "TinTin.h"


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define INPUT_BANNER_TITLE		"_TEXT_INPUT_BANNER_"

#if defined( CH_MSW )

#define EDIT_MENU_TITLE			"&Edit"

#else

#define EDIT_MENU_TITLE			"Edit"

#endif

#define TINTIN_INIT_FILE		"tintin.txt"

/*----------------------------------------------------------------------------
	Types
----------------------------------------------------------------------------*/

CH_TYPEDEF_LIBRARY( bool, SubclassCtl3dProc )( HWND hwndCtl );

typedef enum { tabModeReset, tabModeStart, tabModeHistory,
				tabModeKeywords, tabModeEnd } TabCompletionMode;


/*----------------------------------------------------------------------------
	Chaco message handlers
----------------------------------------------------------------------------*/

CH_DECLARE_MESSAGE_HANDLER( defTextInHandler )


/*----------------------------------------------------------------------------
	ChTextInTinTin class
----------------------------------------------------------------------------*/

class ChTextInMainInfo;

class ChTextInTinTin : public TinTin
{
	public:
		ChTextInTinTin( ChTextInMainInfo* pMainInfo );
		~ChTextInTinTin() {}

		virtual void SendToWorld( const string& strOutput );
		virtual void Display( const string& strOutput );

	protected:
		inline ChTextInMainInfo* GetMainInfo() { return m_pMainInfo; }

	protected:
		ChTextInMainInfo*	m_pMainInfo;
};


/*----------------------------------------------------------------------------
	ChTextInputEdit class
----------------------------------------------------------------------------*/

class ChSplitterBanner;

class ChTextInputEdit : public CEdit
{
	public:
		enum tagConstants { maxHistory = 100,
							maxMenuHistory = 5,
							popupMenuHistoryBase = 10000 };

	public:
		ChTextInputEdit( const ChModuleID& idServerModule );

		inline ChTextInMainInfo* GetMainInfo()
					{ return m_pMainInfo; }

		inline bool IsValid() { return (0 != m_hWnd); }
		inline bool IsControlKeyDown()
					{
						return !!(0x8000 & GetKeyState( VK_CONTROL ));
					}
		inline bool IsBrowsingHistory() { return m_boolBrowsingHistory; }

		inline void SetSelectedText( string& strText )
					{
						SetWindowText( strText );
						SetSel( 0, -1 );
					}
		inline void SetHistoryText( string& strText )
					{
						int		iLen = strText.GetLength();

						SetWindowText( strText );
						SetSel( iLen, iLen );
					}

		inline bool IsPassword() { return m_boolPassword; }
		inline void SetPassword( bool boolPassword )
					{
						m_boolPassword = boolPassword;
					}

		bool Create( ChWnd* pParent, ChTextInMainInfo* pMainInfo );

		static void GetSize( int iLines, CSize& size );

		void Send( const string& strText );
		void Send();
		void Display( const string& strText );
		void EraseText();

		void UpdatePreferences();

	public:
		virtual bool PreTranslateMessage( MSG* pMsg );

											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(ChTextInputEdit)
		//}}AFX_VIRTUAL

											// Implementation
	public:
		virtual ~ChTextInputEdit();

	protected:
		void OnSendKey();
		void MoveInHistory( bool boolUp );
		void SetBrowsingHistory( bool boolBrowsing );
		void DoTabCompletion();
		void DoRightButtonMenu( CPoint ptMouse );
		void ConstructRightButtonMenu( CMenu& menu );

		int GetEndOfLineIndex( int iLine ) const;
		void SendKeyDown( UINT uiKey, LPARAM lParam, bool boolStripCtrl );
		bool ProcessKey( UINT& uiChar, LPARAM lParam );

	protected:
		ChTextInMainInfo*	m_pMainInfo;
		ChServerModule		m_serverCore;
		bool				m_boolPassword;

		bool				m_boolWindows95;
		HINSTANCE			m_h3dLib;
		SubclassCtl3dProc	m_pprocSubclassCtl3d;

		bool				m_boolClearOnSend;
		bool				m_boolBrowsingHistory;
		ChHistory			m_history;
		string				m_strEndText;

		ChKeyMapType		m_keyMapType;
		ChKeyMap			m_keyMap;

		TabCompletionMode	m_tabCompletionMode;
		ChPosition			m_posTabCompletion;
		string				m_strTabCompletion;

	protected:
		//{{AFX_MSG(ChTextInputEdit)
		afx_msg void OnKillFocus(CWnd* pNewWnd);
		afx_msg void OnSetFocus(CWnd* pOldWnd);
		afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
		afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
		virtual bool OnCommand( WPARAM wParam, LPARAM lParam );

	DECLARE_MESSAGE_MAP()
};


/*----------------------------------------------------------------------------
	ChTextInMainInfo class
----------------------------------------------------------------------------*/

class ChTextInMainInfo : public ChMainInfo
{
	CH_FRIEND_MESSAGE_HANDLER( textInInitHandler )

	public:
		ChTextInMainInfo( const ChModuleID& idModule,
							const ChModuleID& idServerModule );
		virtual ~ChTextInMainInfo();

		inline bool IsShown() const { return m_boolShown; }
		inline ChTextInputEdit* GetEdit()
						{
							return m_pEdit;
						}
		inline chint16 GetEditLines() const { return m_sEditLines; }
		inline ChTextInTinTin* GetTinTin() { return m_pTinTinProcessor; }
		inline ChHookManager* GetHookMgr() { return &m_hooks; }
		inline const ChModuleID& GetServerModule() const
						{
							return m_idServerModule;
						}
		inline ChEditMenu* GetStdEditMenu()
						{
							return m_boolMenus ? &m_stdEditMenu : 0;
						}
		inline ChMenu* GetStdWindowMenu()
						{
							return m_boolMenus ? &m_stdWindowMenu : 0;
						}
		inline bool IsMenuInstalled() { return m_boolMenusInstalled; }

		inline bool IsPassword() { return GetEdit()->IsPassword(); }
		inline void SetPassword( bool boolPassword )
					{
						GetEdit()->SetPassword( boolPassword );
					}

		void RegisterDispatchers();
		void ShowModule( bool boolShow );

		void Send( const string& strText );
		void Display( const string& strText );

		void UpdatePreferences();

	protected:
		void Initialize();

	private:
		void CreateMenus();
		void InstallMenus();
		void UninstallMenus();
		void DestroyMenus();

	private:
		ChModuleID			m_idServerModule;
		ChDispatcher		m_textInDispatcher;
		ChSplitterBanner*	m_pBanner;
		ChTextInputEdit*	m_pEdit;
		bool				m_boolShown;
		bool				m_boolMenus;
		bool				m_boolMenusInstalled;
		ChEditMenu			m_stdEditMenu;
		ChWindowMenu		m_stdWindowMenu;
		ChHookManager		m_hooks;

		chint16				m_sEditLines;
		string				m_strTinTinFile;

		ChTextInTinTin*		m_pTinTinProcessor;
};

#endif	// !defined( _CHTXTIN_H )
