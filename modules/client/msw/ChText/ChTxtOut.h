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

	Interface for the ChTextOutputBar class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/ChTxtOut.h,v 2.29 1996/02/22 01:45:01 coyote Exp $

#if !defined( _CHTXTOUT_H )
#define _CHTXTOUT_H

#include <ChHtpCon.h>
#include <ChHtmWnd.h>
#include <ChMenu.h>
#include <ChPane.h>
#include <ChHook.h>


/*----------------------------------------------------------------------------
	Chaco message handlers
----------------------------------------------------------------------------*/

CH_DECLARE_MESSAGE_HANDLER( defTextOutHandler )


/*----------------------------------------------------------------------------
	ChTextOutputWnd class
----------------------------------------------------------------------------*/

class ChTextOutMainInfo;
class ChTextStreamManager;

class ChTextOutputWnd : public ChHtmlWnd
{

	public:
		ChTextOutputWnd();
		virtual ~ChTextOutputWnd();

		#if defined( CH_MSW )

		inline bool IsValid() { return (0 != m_hWnd); }

		#endif	// defined( CH_MSW )

		inline ChTextOutMainInfo* GetMainInfo()
							  { return m_pTxtOutInfo; }
		inline void SetMainInfo( ChTextOutMainInfo* pInfo )
							  {  m_pTxtOutInfo = pInfo; }

	protected:
											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(ChTextOutputWnd)
		//}}AFX_VIRTUAL
		#if defined( CH_MSW )
		void OnPaletteChanged(CWnd* pFocusWnd);
		BOOL OnQueryNewPalette();
		#endif

		virtual void OnHotSpot(  chparam userData, const string& strDocURL );
		virtual void OnSelectHotSpot( int x, int y, ChPoint& ptRel,
										chparam userData,
										const string& strDocURL );

											// Image tag callback method

		virtual bool OnInline( const char* pstrArgs, const string& strDocURL );

											/* The following method is called
												when there is a inline image
												to be loaded */

		virtual void OnLoadImage( const char* pstrURL, ChObjInline *pImage,
											const string& strDocURL  );

										/* Handle form submit */
		virtual void OnSubmitForm( const string& strFormData );


	public:
											// Hook management methods

		inline void InstallHook( chint32 lMessage, const ChModuleID& idModule )
					{
						GetHookMgr( lMessage )->Install( idModule );
					}

		inline void UninstallHook( chint32 lMessage,
									const ChModuleID& idModule )
					{
						GetHookMgr( lMessage )->Uninstall( idModule );
					}

		inline void PromoteHook( chint32 lMessage, const ChModuleID& idModule,
									bool boolPromote )
					{
						GetHookMgr( lMessage )->Promote( idModule,
															boolPromote );
					}

		inline void DoHook( ChMsg& msg )
					{
						bool	boolProcessed;

						GetHookMgr( msg.GetMessage() )->
											Dispatch( msg, boolProcessed );
					}

	protected:
		inline ChHookManager* GetHookMgr( chint32 lMessage )
					{
						ChHookManager*		pMgr;

						switch( lMessage )
						{
							case CH_MSG_CMD:
							{
								pMgr = &m_hookCommand;
								break;
							}

							case CH_MSG_INLINE:
							{
								pMgr = &m_hookInline;
								break;
							}

							case CH_MSG_HINT:
							{
								pMgr = &m_hookHint;
								break;
							}
							default:
							{
								ASSERT( false );
								pMgr = 0;
								break;
							}
						}

						return pMgr;
					}

	private :
		ChHookManager				m_hookCommand;
		ChHookManager				m_hookHint;
		ChHookManager				m_hookInline;
		ChTextOutMainInfo* 			m_pTxtOutInfo;

	#if !defined( CH_UNIX )

	protected:
		//{{AFX_MSG(ChTextOutputWnd)
		afx_msg void OnKillFocus(CWnd* pNewWnd);
		afx_msg void OnSetFocus(CWnd* pOldWnd);
		//}}AFX_MSG

		DECLARE_MESSAGE_MAP()

	#endif	// !defined( CH_UNIX )
};


#if !defined( CH_UNIX )

/*----------------------------------------------------------------------------
	ChTextOutMainInfo class
----------------------------------------------------------------------------*/

class ChTextOutMainInfo : public ChMainInfo
{
	public:
		enum tagConstants { idealCharWidth = 80, minCharWidth = 20,
							idealCharHeight = 25, minCharHeight = 1,
							charsPerLine = 80 };

	public:
		ChTextOutMainInfo( ChModuleID idModule, ChModuleID idServerModule );
		virtual ~ChTextOutMainInfo();

		inline bool IsShown() { return m_boolShown; }
		inline ChTextOutputWnd* GetOutputWnd() { return &m_outWnd; }
//		inline ChClientModule* GetTextInModule() { return m_pTextIn; }
		inline const ChModuleID& GetWorldModuleID() { return m_idWorldModule; }

		inline ChEditMenu* GetStdEditMenu()
					{
						return m_boolMenus ? &m_stdEditMenu : 0;
					}
		inline bool IsMenuInstalled() { return  m_boolMenusInstalled; }

		inline chint32 GetBufferLimit()
					{
						return m_outWnd.GetBufferLimit() * charsPerLine;
					}
		inline void SetBufferLimit( chint32 lLines )
					{
						m_outWnd.SetBufferLimit( lLines * charsPerLine );
					}

		void Initialize();
		void RegisterDispatchers();
//		void SetTextInID( const ChModuleID& idModule );
		void ShowModule( bool boolShow );

		void LoadFile( const string& strFilename, const string& strURL,
						const string& strHTML, const string& strMimeType );

		bool DoPaneCommand( ChPane::ChPaneCmd paneCmd, const char* pstrArgs );
		void DoPaneOpen( const string& strFilename, const string& strMimeType, 
						 const string& strURL,	const string& strHTML );
		void DoPaneClose( const string& strHTML );

											// Hook management methods

		inline void InstallHook( chint32 lMessage, const ChModuleID& idModule )
					{
						GetHookMgr( lMessage )->Install( idModule );
					}

		inline void UninstallHook( chint32 lMessage,
									const ChModuleID& idModule )
					{
						GetHookMgr( lMessage )->Uninstall( idModule );
					}

		inline void PromoteHook( chint32 lMessage, const ChModuleID& idModule,
									bool boolPromote )
					{
						GetHookMgr( lMessage )->Promote( idModule,
															boolPromote );
					}

		inline void DoHook( ChMsg& msg )
					{
						bool	boolProcessed;

						GetHookMgr( msg.GetMessage() )->
											Dispatch( msg, boolProcessed );
					}

	protected:
		inline ChHookManager* GetHookMgr( chint32 lMessage )
					{
						ChHookManager*		pMgr;

						switch( lMessage )
						{
							case CH_MSG_CMD:
							{
								pMgr = &m_hookCommand;
								break;
							}

							case CH_MSG_INLINE:
							{
								pMgr = &m_hookInline;
								break;
							}

							case CH_MSG_HINT:
							{
								pMgr = &m_hookHint;
								break;
							}

							default:
							{
								ASSERT( false );
								pMgr = 0;
								break;
							}
						}

						return pMgr;
					}

		void InstallOutputHooks( ChTextOutputWnd* pOutWnd,
									bool boolInstall = true );

	private:
		void CreateMenus();
		void InstallMenus();
		void UninstallMenus();
		void DestroyMenus();

	private:
		ChHookManager	m_hookCommand;
		ChHookManager	m_hookHint;
		ChHookManager	m_hookInline;

		static chint16	m_sMinWidth;
		static chint16	m_sIdealWidth;
		static chint16	m_sMinHeight;
		static chint16	m_sIdealHeight;

	private:
		ChHTTPSocketConn		m_httpConn;
		ChTextStreamManager 	*m_pTextStreamMgr;
		ChDispatcher			m_textOutDispatcher;
		ChTextOutputWnd			m_outWnd;
		ChEditMenu				m_stdEditMenu;

//		ChModuleID				m_idTextInModule;
//		ChClientModule*			m_pTextIn;

		ChModuleID				m_idWorldModule;

		bool					m_boolShown;
		bool					m_boolMenus;
		bool					m_boolMenusInstalled;
};

#endif	// !defined( CH_UNIX )
#endif	// !defined( _CHTXTOUT_H )
