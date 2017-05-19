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

#if !defined( _CHPANMOD_H )
#define _CHPANMOD_H

#include <ChHTTP.h>
#include "ChGrMod.h"   

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA    
#endif


/*----------------------------------------------------------------------------
	Chaco message handlers
----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
	Forward classes
----------------------------------------------------------------------------*/

class ChGraphicViewer;
class ChGraphicStreamManager;

/*----------------------------------------------------------------------------
	ChViewerMsgDispatch class - used dispatching message to the mime viewer
----------------------------------------------------------------------------*/
class ChViewerMsgDispatch
{
	public :
		ChViewerMsgDispatch( ChMainInfo* pInfo, ChModuleID& idModule ) :
					m_pMainInfo( pInfo ), m_idModule( idModule )
					{
					}

		~ChViewerMsgDispatch( ) 	{}

		void Send( ChMsg& msg )
				{
					m_pMainInfo->GetCore()->DispatchMsg( m_idModule, msg );
				}
		void Post( ChMsg& msg )
				{
					m_pMainInfo->GetCore()->DispatchMsg( m_idModule, msg );
				}

	private :
		ChMainInfo*	m_pMainInfo;
		ChModuleID  m_idModule;
};


/*----------------------------------------------------------------------------
	ChGraphicViewer class - used for keeping track of both installed and
	pending viewers.
----------------------------------------------------------------------------*/
class ChGraphicViewer
{
	public:
		ChGraphicViewer( ChMainInfo* pInfo, const string &strModule, ChModuleID idModule = 0)
			:  m_pMainInfo( pInfo ), m_pMsgDispatcher(0),  m_idModule(idModule), m_strModule(strModule)
			{
				if(idModule)
				{
					m_pMsgDispatcher = new ChViewerMsgDispatch( m_pMainInfo, idModule);
				}
			};

		virtual ~ChGraphicViewer()
		{
			delete m_pMsgDispatcher;
		};
		inline 	string &GetModuleName() {return m_strModule;};
		inline 	ChViewerMsgDispatch *GetModule() {return m_pMsgDispatcher;};
		inline  ChModuleID GetModuleID() {return m_idModule;};
		 
		 
	protected:
		ChMainInfo*			m_pMainInfo;
		ChViewerMsgDispatch		*m_pMsgDispatcher;
		ChModuleID			m_idModule;
		string 				m_strModule;
};

typedef ChGraphicViewer *pChGraphicViewer;
/*----------------------------------------------------------------------------
	ChGraphicPaneInfo class
----------------------------------------------------------------------------*/
#if !defined( NO_TEMPLATES )
typedef ChSplay<ChHTTPConn::tagMimeTypes, pChGraphicViewer> ChViewerSplay;
#else      
#include "templcls\ChHtpVw.h"
typedef ChSplayHTTPViewer		ChViewerSplay;            
#endif

class ChGraphicPaneInfo : public ChMainInfo
{
	CH_FRIEND_MESSAGE_HANDLER( paneInstallHookHandler )
	CH_FRIEND_MESSAGE_HANDLER( panePromoteHookHandler )
	CH_FRIEND_MESSAGE_HANDLER( paneUninstallHookHandler )
	CH_FRIEND_MESSAGE_HANDLER( paneLoadCompleteHandler )
	CH_FRIEND_MESSAGE_HANDLER( paneImageHookHandler )
	CH_FRIEND_MESSAGE_HANDLER( paneCmdHookHandler )

	public:

	public:
		ChGraphicPaneInfo( ChModuleID idModule, ChCore* pCore );
		virtual ~ChGraphicPaneInfo();

		void RegisterDispatchers();

		virtual void ShowModule( bool boolShow  = true );

//		inline ChHTTPConn* GetHTTPConn() { return &m_httpConn; }
		inline ChGraphicStreamManager* GetStream() { return m_pGraphicStream; }
		inline ChHookManager* GetCmdHookMgr() { return &m_cmdHookMgr; }
		inline ChHookManager* GetImageHookMgr() { return &m_imageHookMgr; }
		inline ChViewerMsgDispatch * GetCurrentViewer() { return m_pCurrentViewer; }
		inline ChModuleID  GetCurrentViewerID() { return m_currentViewerID; }
		inline ChGraphicPaneInfo * SetCurrentViewer(ChViewerMsgDispatch *pViewer, ChModuleID id)
			{ m_pCurrentViewer = pViewer; m_currentViewerID = id; return this;}
		inline ChGraphicDocumentHTTPReq *GetPendingLoad() {return m_pPendingLoad; }
		inline ChGraphicPaneInfo * SetPendingLoad(ChGraphicDocumentHTTPReq * pPending)
			{m_pPendingLoad = pPending; return this;}

		inline bool IsShown() { return m_boolShown; }

  		void Initialize();
		bool IsGraphicViewer(ChModuleID idModule);
		void HookViewerMessages(ChModuleID idModule);
		//virtual void OnParseComplete(string &strURL);

	protected:
		ChDispatcher					m_graphicDispatcher;
		ChHookManager					m_imageHookMgr;
		ChHookManager					m_cmdHookMgr;
//		ChHTTPSocketConn				m_httpConn;
		ChGraphicStreamManager			*m_pGraphicStream;
		ChModuleID						m_idMazeModule;
		ChModuleID						m_idAnimModule;
		ChViewerSplay				 	*m_pViewers;
		ChViewerSplay				 	*m_pPendingViewers;
		ChViewerMsgDispatch 			*m_pCurrentViewer;		// current viewer
		ChModuleID						m_currentViewerID;
		ChGraphicDocumentHTTPReq 		*m_pPendingLoad;		// Load in progress
		ChGraphicDocumentHTTPReq 		*m_pSuspendedLoad;		// Load awaiting viewer
		bool							m_boolShown;

		bool DoCommand(string& strArgs);
		void DoLoadCommand(string& strArgs);
		void DoShowCommand(string& strArgs);
		void DoViewerCommand(string& strArgs);
		void DoQueuedCommands(ChGraphicDocumentHTTPReq *pReq);
		void SendViewerCommand(string& strArgs, ChViewerMsgDispatch* pMod = 0);
		void RegisterViewer(const string &strModuleName, ChModuleID idModule);
		void RegisterViewer(const string &strModuleName, ChModuleID idModule, ChHTTPConn::tagMimeTypes type);
		void RegisterPendingViewer(const string &strModuleName, ChHTTPConn::tagMimeTypes type);
		bool IsMimeViewerPending( string strType, string *pstrViewer = 0 );
		inline ChGraphicPaneInfo * SetSuspendedLoad(ChGraphicDocumentHTTPReq *pReq)
		{
			if(m_pSuspendedLoad != pReq) delete m_pSuspendedLoad;
			m_pSuspendedLoad = pReq;
			return this;
		}

		ChViewerMsgDispatch * GetMimeViewer( string strType );
		ChViewerMsgDispatch * GetMimeViewer( string strType, ChModuleID &id );
		bool Load( ChGraphicDocumentHTTPReq *pReq, ChViewerMsgDispatch* pViewer  = 0, ChModuleID id = 0);
		bool Load( ChGraphicDocumentHTTPReq *pReq, const string &strURL, 
			const string &strFilename, const string &strType, ChViewerMsgDispatch* pViewer  = 0, 
			ChModuleID id = 0 );
};  


#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR    
#endif



#endif	// !defined( _CHPANMOD_H )
