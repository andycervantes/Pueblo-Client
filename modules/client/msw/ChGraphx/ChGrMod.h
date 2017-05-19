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

	Interface for the ChGraphicOutputBar class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChGrMod.h,v 2.40 1996/06/27 03:43:05 jimd Exp $

#if !defined( _CHGRMOD_H )
#define _CHGRMOD_H

#include "ChGrVw.h"
#if defined(CH_USE_2D)
//#include "ChAnim.h"
#endif

#include "ChGraphx.h"
#include "ChGrDep.h"
#include <ChHook.h>
#include <ChReg.h>
#include <ChDispat.h>
#include <GxTypes.h>


#define CH_MAX_NOTIFICATION_PARAMS 10

// Graphics img commands
#define CH_GRAPH_CMD   		"xch_graph"
#define CH_EVENT_NOTIFY		"event"
// this one is obsolete
#define CH_GRAPH_CMD_NODE	"xch_graph_node"


/*----------------------------------------------------------------------------
	Chaco message handlers
----------------------------------------------------------------------------*/

CH_DECLARE_MESSAGE_HANDLER( defGraphicHandler )


/*----------------------------------------------------------------------------
	Forward classes
----------------------------------------------------------------------------*/

class ChAnimView;
class ChAnimCharacter;

class ChAnimHTTPReq;
class ChAnimStartHTTPReq;
class ChAnimBackgroundHTTPReq;
class ChGraphicDocumentHTTPReq;

class ChMazeWnd;
class ChMenu;
class ChGraphicStreamManager;

/*----------------------------------------------------------------------------
	ChGraphicMainInfo class
----------------------------------------------------------------------------*/

class ChGraphicMainInfo : public ChMainInfo
{
	CH_FRIEND_MESSAGE_HANDLER( graphicInstallHookHandler )
	CH_FRIEND_MESSAGE_HANDLER( graphicPromoteHookHandler )
	CH_FRIEND_MESSAGE_HANDLER( graphicUninstallHookHandler )

	public:
		enum tagConstants { idealCharWidth = 80, minCharWidth = 20,
							idealCharHeight = 15, minCharHeight = 2 };

	public:
		ChGraphicMainInfo( ChModuleID idModule, ChCore* pCore );
		virtual ~ChGraphicMainInfo();

		void RegisterDispatchers();
		virtual void Initialize();

		inline bool IsShown() { return m_boolShown; }
		inline ChGraphicView* GetView() { return m_pWnd; }
		virtual void ShowModule( bool boolShow  = true);
		inline ChGraphicStreamManager* GetStream() { return m_pGraphicStream; }
		ChGraphicStartHTTPReq *GetRootDependent() { return m_pStartReq; };
		ChGraphicBackgroundHTTPReq *GetLeafDependent() { return (ChGraphicBackgroundHTTPReq *)m_pBackReq; };
		inline void SetRootDependent(ChGraphicStartHTTPReq *pReq) { m_pStartReq = pReq; };
		inline void SetLeafDependent(ChGraphicBackgroundHTTPReq *pReq) { m_pBackReq = pReq; };
		inline ChHookManager* GetCmdHookMgr() { return &m_hookMgr; }

		inline ChGraphicPageID GetNewPage() { return ++m_pageCount; }
		void NotifyAnchor(string &strAnchor);

		virtual void OnParseComplete(string &strURL,  chparam data) {};
		virtual void OnLoadInitiated(string &strURL) {};

											/* The following method is called
												when the pane is lost to
												another module */
		void SetHidden();

	protected:
		ChDispatcher			m_graphicDispatcher;
		ChGraphicView*			m_pWnd;	// really a wnd, not a view
		ChHookManager			m_hookMgr;
		ChGraphicStreamManager	*m_pGraphicStream;
		ChGraphicPageID			m_pageCount;	 // page id factory for this viewer; each view object has their current one

	protected:
		inline void SetShown( bool boolShown )
						{
							m_boolShown = boolShown;
						}

		ChGraphicHTTPReq *m_pBackReq;
		ChGraphicStartHTTPReq *m_pStartReq;

		void HookPaletteMessages( const ChModuleID& idModule );

		virtual void ComputeDesiredSize();
		void DoQueuedCommands(ChGraphicDocumentHTTPReq *pReq);
		virtual void DoCommand( string& strArgs ) {};

	protected:
		bool		m_boolShown;

		chint16		m_sMinWidth;
		chint16		m_sIdealWidth;
		chint16		m_sMinHeight;
		chint16		m_sIdealHeight;
};

class ChAnimMainInfo : public ChGraphicMainInfo
{
	public:

	public:
		ChAnimMainInfo( ChModuleID idModule, ChCore* pCore );
		virtual ~ChAnimMainInfo();

 		ChAnimStartHTTPReq *GetRootDependent()
 			{ return (ChAnimStartHTTPReq *)m_pStartReq; };

		void RegisterDispatchers();
		inline ChAnimView* GetView() { return (ChAnimView*)m_pWnd; }
};

class ChMazeSceneHTTPReq;


/*----------------------------------------------------------------------------
	ChMazeMainInfo class
----------------------------------------------------------------------------*/
class ChVrmlSettings;

class ChMazeMainInfo : public ChGraphicMainInfo
{
	CH_FRIEND_MESSAGE_HANDLER( mazeLoadCompleteHandler )
	CH_FRIEND_MESSAGE_HANDLER( mazeGetPageDataHandler )

	public:
		ChMazeMainInfo( ChModuleID idModule, ChCore* pCore );
		virtual ~ChMazeMainInfo();

		inline ChMazeSceneHTTPReq* GetLeafDependent()
						{
							return (ChMazeSceneHTTPReq *)m_pBackReq;
						}
		#if 0
		inline ChShadingLevel GetRenderQuality() { return m_renderQuality; }
		inline ChShadingLevel GetMoveRenderQuality()
						{
							return m_moveRenderQuality;
						}
		inline bool GetMoveVector() { return m_boolMoveVector; }
		inline bool GetScaleTextures() { return m_boolScaleTextures; }
		inline float GetHeadlightBrightness()	{ return GetSettings()->GetHeadlightBrightness();};
 		inline bool GetOverrideSceneMode() { return m_boolOverrideSceneViewerMode; }
 		inline Ch3DViewerMode GetViewerMode()
						{
							return (Ch3DViewerMode)m_viewerMode;
						}

		#endif
		inline ChMazeWnd* GetView() { return (ChMazeWnd*)m_pWnd; }
		inline ChVrmlSettings *GetSettings( ) {return m_pSettings; };

		inline void SetLeafDependent( ChMazeSceneHTTPReq *pReq )
						{
							m_pBackReq = (ChGraphicHTTPReq*)pReq;
						}

		virtual void Initialize();
		void RegisterDispatchers();
		virtual void DoCommand( string& strArgs );
		bool DoLoadCommand( string& strArgs );
		void ProcessEvent( string& strArgs );

		ChMazeMainInfo* Delete( ChGraphicHTTPReq* pInProgressReq );
		ChMazeMainInfo* CancelInProgressReqs();
		ChMazeMainInfo* Add( ChGraphicHTTPReq* pInProgressReq );
		void EndFrameTime();
		void StartFrameTime() { m_luTime = GetTickCount(); }
 		virtual void ShowModule( bool boolShow  = true);

		void WriteStatus(const string &strMessage);
		void OnTick();
		bool OnCameraChange(int efChanged);
		void SetupPositionNotification(const string &strArgs);
		virtual void OnParseComplete(string &strURL, chparam data);
		virtual void OnLoadInitiated(string &strURL);


	protected:
		void ReadPreferences();
		void UpdatePreferences( bool boolMoveVector,
								bool boolScaleTextures,
								ChShadingLevel renderQuality,
								ChShadingLevel moveRenderQuality,
								float fHeadlight,
								#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
								int iAsciiTextQuality,
								bool boolCollisionAlarm
								#else
								int iAsciiTextQuality
								#endif
								
								  );
		 void FormatMoveCommand(string &command);


	private:
		ChRegistry				m_reg;

		DWORD					m_luTime;
		ChGraphicHTTPReqList*	m_pInProgressReqs;

		ChVrmlSettings*			m_pSettings;

		chint32 				m_minNotifyTime;
		chint32 				m_maxNotifyTime;
		chint32 				m_lastTick;
		float 					m_maxMove;
		float 					m_maxRotation;
		double					m_dTimeOffset;
		char 					m_params[CH_MAX_NOTIFICATION_PARAMS];
		GxVec3f					m_lastLoc;
		GxVec3f					m_lastUp;
		GxVec3f					m_lastLook;
		bool					m_boolNotificationEnabled;
};

#endif	// !defined( _CHGRMOD_H )
