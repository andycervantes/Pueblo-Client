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

	Definition for the ChWorldMainInfo class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChWorld/World.h,v 2.62 1996/09/12 19:10:24 pritham Exp $

#if !defined( _WORLD_H )
#define _WORLD_H

#include <ChConn.h>
#include <ChDispat.h>

#include "ChWInfo.h"
#include "ChWorldCmdLine.h"

/*----------------------------------------------------------------------------
	Switches
----------------------------------------------------------------------------*/

#if defined( CH_MSW )

	#define USE_SOUND
											/* Define this to load the
												graphics VRML module on world
												load */
	#define USE_GRAPHICS	1

#endif	// defined( CH_MSW )


/*----------------------------------------------------------------------------
	Includes
----------------------------------------------------------------------------*/


#include "TinTin.h"


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

											// HTML
#define MUD_TEXT_ON			"<xch_mudtext>"
#define MUD_TEXT_OFF		"</xch_mudtext>"

/*----------------------------------------------------------------------------
	Types
----------------------------------------------------------------------------*/

#if !defined( CH_PUEBLO_PLUGIN )
typedef enum { editMenuCut, editMenuCopy, editMenuPaste } EditMenuItem;
#endif

typedef enum { focusNone, focusTextInput, focusTextOutput } FocusTarget;
typedef enum { echoOn, echoTelnetOff, echoAutoOff } EchoState;


/*----------------------------------------------------------------------------
	Forward class declarations
----------------------------------------------------------------------------*/

class ChCore;
class ChWorldMainInfo;
class ChWorldConn;
class ChTextInput;
class ChTextOutput;

#if !defined( CH_PUEBLO_PLUGIN )
class ChMenu;
class ChFileMenu;
class ChEditMenu;
class ChViewMenu;
class ChWindowMenu;
#endif

class ChWorldStreamManager;
class ChConnectingDlg;

/*----------------------------------------------------------------------------
	ChWorldTinTin class
----------------------------------------------------------------------------*/

class ChWorldTinTin : public TinTin
{
	public:
		ChWorldTinTin( ChWorldMainInfo* pMainInfo );
		~ChWorldTinTin() {}

		virtual void SendToWorld( const string& strOutput );
		virtual void Display( const string& strOutput,
								bool boolPreformatted = false ) const;
};


/*----------------------------------------------------------------------------
	WorldLoadInfo class

		A pointer to an object of this class is passed as user data when
		loading URLs.
----------------------------------------------------------------------------*/

class WorldLoadInfo
{
	public:
		typedef enum { typeModule } LoadType;

	public:
		WorldLoadInfo( const string& strModule ) :
				m_strModule( strModule )
					{
					}

		inline LoadType GetType() { return typeModule; }
		inline const string& GetModuleName() { return m_strModule; }
	protected:
		string		m_strModule;
};


/*----------------------------------------------------------------------------
	ChWorldMainInfo class
----------------------------------------------------------------------------*/

class ChWorldMainInfo : public ChMainInfo
{
	friend class ChWorldConn;
	friend class ChConnectingDlg;

	CH_FRIEND_SOCKET_HANDLER( worldSocketHandler )
	CH_FRIEND_SOCKET_ASYNCHANDLER( worldSocketAsyncHandler )

	CH_FRIEND_MESSAGE_HANDLER( worldGetPageDataHandler )
	CH_FRIEND_MESSAGE_HANDLER( worldLoadCompleteHandler )
	CH_FRIEND_MESSAGE_HANDLER( worldInvalidWorldHandler )

	CH_FRIEND_MESSAGE_HANDLER( OnStdEditCut )
	CH_FRIEND_MESSAGE_HANDLER( OnStdEditCopy )
	CH_FRIEND_MESSAGE_HANDLER( OnStdEditPaste )

	public:
		enum tagTrackUsage { worldConnect = 1, worldDisconnect, worldEnhanced };

		ChWorldMainInfo( const ChModuleID& idModule, ChCore* pCore,
							ChArgumentList* pList );
		virtual ~ChWorldMainInfo();
		
		inline int 	GetConnectID() { return m_iConnectID; }
		inline ChTextInput* GetTextInput() { return m_pTextInput; }
		inline ChTextOutput* GetTextOutput() { return m_pTextOutput; }
		inline ChWorldTinTin* GetTinTin() { return m_pTinTin; }

		inline ChWorldStreamManager* GetStream() { return m_pWorldStreamMgr; }

		inline const string& GetCurrentURL() const { return m_strCurrentURL; }
		inline const ChModuleID& GetSoundID() const { return m_idSoundModule; }
		inline const ChModuleID& GetGraphicsID() const { return m_idGraphicsModule; }
		inline ChWorldConn* GetWorldConnection() const { return m_pWorldConn; }
		inline ChWorldInfo* GetWorldInfo() { return m_pWorldInfo; }
		inline ChWorldCmdLine& GetCmdLine()	{ return m_worldCmdLine; }
		inline bool IsFirstPuebloEnhanced() const
						{
							return !m_boolPuebloEnhancedFound;
						}
		inline bool IsLoadPending() const { return m_boolLoadPending; }
		inline void SetLoadPending( bool boolPending )
						{
							m_boolLoadPending = boolPending;
						}
		inline bool IsPersonalList() const { return m_boolPersonalList; }
		inline bool IsShown() const { return m_boolShown; }
		inline bool IsTopLevelWorldList() const
						{
							return (m_urlList.GetCount() <= 1);
						}

		void NotifyCore( ChMsg& msg ) const;
		void NotifySound( ChMsg& msg ) const;
		void NotifyGraphics( ChMsg& msg )  const;

		inline EchoState GetEchoState() const { return m_echoState; }

		inline bool GetNotify() const { return m_boolNotify; }
		inline bool GetNotifyAlert() const { return m_boolNotifyAlert; }
		inline const string& GetNotifyMatch() const { return m_strNotifyMatch; }

#if !defined( CH_PUEBLO_PLUGIN )
		inline ChFileMenu* GetFileMenu()
						{
							return m_boolMenus ? m_pStdFileMenu : 0;
						}
		inline ChEditMenu* GetEditMenu()
						{
							return m_boolMenus ? m_pStdEditMenu : 0;
						}
		inline ChViewMenu* GetViewMenu()
						{
							return m_boolMenus ? m_pStdViewMenu : 0;
						}
		inline ChMenu* GetWorldMenu()
						{
							return m_boolMenus ? m_pWorldMenu : 0;
						}
		inline ChWindowMenu* GetWindowMenu()
						{
							return m_boolMenus ? m_pStdWindowMenu : 0;
						}

#endif //  !defined( CH_PUEBLO_PLUGIN )

		inline bool IsConnected() { return 0 != m_pWorldConn; }

		inline void SetCurrentURL( const string& strURL )
						{
							m_strCurrentURL = strURL;
						}
		inline void SetPauseOnDisconnect( bool boolPauseOnDisconnect )
						{
							m_boolPauseOnDisconnect = boolPauseOnDisconnect;
						}

		virtual void OnSecondTick( time_t timeCurr );

											/* The first two methods here will
												send text to the world, while
												the third will display text
												into the output window */

		void Send( const string& strText, bool boolEcho = true );
		void Send( const string& strDefaultCmd,
					const string& strMD5, const string& strOverrideCmd,
					const string& strParams, bool boolEcho = true );
		void Display( const string& strText, bool boolPreformatted );

		void Initialize();
		void ShowModule( bool boolShow );
		void DisplayWorldList();

		bool DoCommand( const string& strCommand, chint32 lX = -1,
							chint32 lY = -1 );
		bool DoInline( const string& strArgs );
		bool DoHint( const string& strArgs );

		void DoAlert();
#if !defined( CH_PUEBLO_PLUGIN )
		void DoQuickConnect();
#endif

		bool Connect( const ChWorldInfo& info );
		void CreateShortcut( const ChWorldInfo& info );

		void OnInitialStartup();
		void OnPuebloEnhanced( const ChVersion& versEnhanced );
		void DoAutoLogin();
		void ShutdownWorld( bool boolShutdownMessage = true,
							bool boolEntirely = false );

		void AddCurrentWorld();
		void CreateShortcut();
		void CreateCurrentWorldShortcut();
		bool GetPersonalWorldList();
		void EditPersonalWorldList();

		void DoPreviousURL();

		void SetEchoPrefs( bool boolEcho, bool boolBold, bool boolItalic );

		bool LookForPuebloEnhanced( const string& strLine,
									ChVersion& versEnhanced );

		void UpdatePreferences();

		void SetFocusTarget( FocusTarget target, bool boolGainingFocus );

		bool WantTextLines();
		void OnTextLine( const string& strLine );
		void LookForNotify( const string& strLine ) const;

		void SetEchoState( EchoState newState, bool boolPreserve = false );

		inline const string& GetMD5() const { return m_strMD5; }
		inline void SetMD5( const string& strMD5 ) { m_strMD5 = strMD5; }
		inline bool VerifyMD5( const string& strMD5 ) const
				{
					return strMD5 == m_strMD5;
				}

		void CreateMD5Checksum();

	protected:
		inline FocusTarget GetFocusTarget() { return m_focusTarget; }
		inline const string& GetHomePage() { return m_worldCmdLine.GetHomePage(); }

		inline bool DisplayChanged() { return m_boolDisplayChanged; }
		inline void SetDisplayChanged( bool boolChanged = true )
				{
					m_boolDisplayChanged = boolChanged;
				}

		inline void SetNotify( bool boolNotify )
						{
							m_boolNotify = boolNotify;
						}
		inline void SetNotifyAlert( bool boolNotifyAlert )
						{
							m_boolNotifyAlert = boolNotifyAlert;
						}
		inline void SetNotifyMatch( const string& strMatch )
						{
							m_strNotifyMatch = strMatch;
							m_strNotifyMatch.MakeLower();
						}
		inline void SetPersonalList( bool boolPersonal = true )
						{
							m_boolPersonalList = boolPersonal;
						}
		inline void SetShown( bool boolShown = true )
						{
							m_boolShown = boolShown;
						}

		void OnWorldConnect();
		void OnInvalidWorld( const string& strReason );

		void OnAsyncSocketAddress( int iError, unsigned long address );
		void OnConnectComplete( int iErrorCode );

		bool DoJump( const string& strURL, const string& strHTML,
						bool boolForceLoad, bool boolAddToHistory = true,
						bool boolCritical = false );
		void DoXCmd( const string& strCommand );
		bool DoXMode( string& strArgs );

		void SetSoundID( const ChModuleID& idModule );
		void SetGraphicsID( const ChModuleID& idModule );

#if !defined( CH_PUEBLO_PLUGIN )
		bool CheckEditMenuItem( EditMenuItem item );
		void DoEditMenuItem( EditMenuItem item );
#endif

		void AddChacoListJump();

		void DisplayConnectDlg( const ChWorldInfo& info );
		void CloseConnectDlg();

	private:
		void RegisterDispatchers();

#if !defined( CH_PUEBLO_PLUGIN )
		void CreateMenus();
		void InstallMenus();
		void UninstallMenus();
		void DestroyMenus();
#endif

		void Disconnect();					/* Should only be called from the
												ShutdownWorld method */
		void AddURLToList( const string& strURL );
		void EmptyURLList();

		void LoadSoundModule( bool boolOptional = false );
		void UnloadSoundModule();
		void LoadGraphicsModule( bool boolOptional = false );
		void UnloadGraphicsModule();

		void SendConnectedMsg();
		void TrackUsage( int iType );

	private:

		ChTextInput*			m_pTextInput;
		ChTextOutput*			m_pTextOutput;
		ChWorldConn*			m_pWorldConn;
		ChWorldTinTin*			m_pTinTin;

		ChWorldStreamManager*	m_pWorldStreamMgr;

		ChDispatcher			m_worldDispatcher;

		bool					m_boolLoadPending;
		bool					m_boolPuebloEnhancedFound;

		FocusTarget				m_focusTarget;

		ChModuleID				m_idSoundModule;
		ChModuleID		 		m_idGraphicsModule;

		ChWorldInfo*			m_pWorldInfo;

		bool					m_boolShown;
		EchoState				m_echoState;

#if !defined( CH_PUEBLO_PLUGIN )
		bool					m_boolMenus;
		bool					m_boolMenusInstalled;

		ChFileMenu*				m_pStdFileMenu;
		ChEditMenu*				m_pStdEditMenu;
		ChViewMenu*				m_pStdViewMenu;
		ChMenu*					m_pWorldMenu;
		ChWindowMenu*			m_pStdWindowMenu;
#endif

		bool					m_boolPersonalList;
		bool					m_boolDisplayChanged;
		bool					m_boolPauseOnDisconnect;

		ChParamList				m_urlList;

		string					m_strCurrentURL;

		bool					m_boolNotify;
		bool					m_boolNotifyAlert;
		string					m_strNotifyMatch;
		ChWorldCmdLine			m_worldCmdLine;
		int						m_iConnectID;

		ChConnectingDlg*		m_pConnectingDlg;
		bool					m_boolWaitingForHostName;

		CRITICAL_SECTION		m_critsecDisconnect;

		string					m_strMD5;
		string					m_strPuebloClientParams;
};


#endif	// !defined( _WORLD_H )
