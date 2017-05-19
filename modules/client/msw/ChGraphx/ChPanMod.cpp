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

	Implementation for the ChGraphicPaneInfo class, which is used to manage the 
	graphics pane.

----------------------------------------------------------------------------*/

#include "grheader.h"
#include <ctype.h>
#include <ChCore.h>

#include "ChPanMod.h"
#include <ChHtmWnd.h>

#include "ChGrStrm.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

#define GRAPHICS_PANE 1


/*----------------------------------------------------------------------------
	Handler declarations
----------------------------------------------------------------------------*/

CH_DECLARE_MESSAGE_HANDLER( paneLoadCompleteHandler )
CH_DECLARE_MESSAGE_HANDLER( paneLoadErrorHandler )
CH_DECLARE_MESSAGE_HANDLER( paneLoadImageHandler )
CH_DECLARE_MESSAGE_HANDLER( paneInitHandler )
CH_DECLARE_MESSAGE_HANDLER( paneLoadSceneHandler )
CH_DECLARE_MESSAGE_HANDLER( paneImageHookHandler )
CH_DECLARE_MESSAGE_HANDLER( paneCmdHookHandler )
CH_DECLARE_MESSAGE_HANDLER( paneShowModuleHandler )
CH_DECLARE_MESSAGE_HANDLER( paneResetHandler )
CH_DECLARE_MESSAGE_HANDLER( paneInstallHookHandler )
CH_DECLARE_MESSAGE_HANDLER( panePromoteHookHandler )
CH_DECLARE_MESSAGE_HANDLER( paneUninstallHookHandler )
CH_DECLARE_MESSAGE_HANDLER( panePaletteChangeHandler )


static ChMsgHandlerDesc	paneHandlers[] =
							{	{CH_MSG_LOAD_COMPLETE,	paneLoadCompleteHandler},
								{CH_MSG_LOAD_ERROR,		paneLoadErrorHandler},
								{CH_MSG_LOAD_SCENE,		paneLoadSceneHandler},
								{CH_MSG_SHOW_MODULE,	paneShowModuleHandler},
								{CH_MSG_RESET,			paneResetHandler},
								{CH_MSG_INIT, 			paneInitHandler},
								{CH_MSG_INLINE,			paneImageHookHandler},
								{CH_MSG_CMD,			paneCmdHookHandler},
								{CH_MSG_INSTALL_HOOK, 	paneInstallHookHandler},
								{CH_MSG_PROMOTE_HOOK, 	panePromoteHookHandler},
								{CH_MSG_UNINSTALL_HOOK, paneUninstallHookHandler},
								{CH_MSG_LOAD_IMAGE,		paneLoadImageHandler}
							};

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#include <ChUtil.h>
#endif

/*----------------------------------------------------------------------------
	ChGraphicPaneInfo class
----------------------------------------------------------------------------*/

ChGraphicPaneInfo::ChGraphicPaneInfo( ChModuleID idModule,
										ChCore* pCore ) :
					ChMainInfo( idModule, pCore ),
					m_graphicDispatcher( pCore, idModule, defGraphicHandler ),
					m_imageHookMgr( pCore, idModule ),
					m_cmdHookMgr( pCore, idModule ),
					m_pViewers(0),
					m_pPendingViewers(0),
					m_pCurrentViewer(0),
					m_currentViewerID(0),
					m_pPendingLoad(0),
					m_pSuspendedLoad(0),
					m_boolShown( false )
{
 	m_pGraphicStream = new ChGraphicStreamManager( pCore, 0 ); 
	ASSERT( m_pGraphicStream );
}

class DeleteViewerOp : public 
						#if !defined( NO_TEMPLATES )
						ChVisitor2<ChHTTPConn::tagMimeTypes, pChGraphicViewer>  
						#else 
						ChSplayHTTPViewerVisitor2
						#endif
{
	public:
		 bool Visit( const ChHTTPConn::tagMimeTypes& key,  const pChGraphicViewer& pVwr )
				{
					delete pVwr;
					return true;
				}
};

ChGraphicPaneInfo::~ChGraphicPaneInfo()
{
	ShowModule( false );
											// Clean out viewer lookup tables
	DeleteViewerOp		zapViewers;
	if (m_pViewers)
	{
		m_pViewers->Infix( zapViewers );
		delete m_pViewers;
		m_pViewers = 0;
	}

	if (m_pPendingViewers)
	{
		m_pPendingViewers->Infix( zapViewers );
		delete m_pPendingViewers;
		m_pPendingViewers = 0;
	}
											// Get rid of preloaded viewers
	if (m_idMazeModule)
	{
		UnloadClientModule( m_idMazeModule );
	}

	if (m_idAnimModule)
	{
		UnloadClientModule( m_idAnimModule );
	}

	// Cleanup HTTP Stream
	delete m_pGraphicStream;

}


void ChGraphicPaneInfo::Initialize()
{	
											// Load graphics viewers

	RegisterPendingViewer( CH_MODULE_GRAPHICS_ANIMATION, ChHTTPConn::typeGIF );
	RegisterPendingViewer( CH_MODULE_GRAPHICS_ANIMATION, ChHTTPConn::typeJPEG );
	RegisterPendingViewer( CH_MODULE_GRAPHICS_ANIMATION, ChHTTPConn::typeBMP );
	RegisterPendingViewer( CH_MODULE_GRAPHICS_MAZE, ChHTTPConn::typeVRML );

	LoadClientModule( CH_MODULE_GRAPHICS_MAZE, CH_MODULE_GRAPHICS_BASE,
						GetModuleID() );
	LoadClientModule( CH_MODULE_GRAPHICS_ANIMATION, CH_MODULE_GRAPHICS_BASE,
						GetModuleID() );

}


void ChGraphicPaneInfo::RegisterDispatchers()
{
	chint16		sHandlerCount = sizeof( paneHandlers ) /
								sizeof( ChMsgHandlerDesc );

	m_graphicDispatcher.AddHandler( paneHandlers, sHandlerCount );
}


void ChGraphicPaneInfo::HookViewerMessages(ChModuleID idModule)
{
	ChInstallHookMsg	msg( GetModuleID(), CH_MSG_CMD );

	GetCore()->DispatchMsg( idModule, msg );
}


void ChGraphicPaneInfo::ShowModule( bool boolShow )
{
	if (boolShow && !IsShown())
	{
		InstallHook( CH_MSG_INLINE, GetModuleID() );
		m_boolShown = true;
	}
	else if (!boolShow && IsShown())
	{
		UninstallHook( CH_MSG_INLINE, GetModuleID() );
		m_boolShown = false;
	}

	if (GetCurrentViewer())
	{
		ChShowModuleMsg		msg( boolShow );

		GetCurrentViewer()->Send( msg );
	}
}


// ===========================
// Command methods and helpers
// ===========================


string TrimArg(string & strVal )
{
	string strValue = strVal;

	#if defined( CH_ARCH_16 )    
	TrimLeft( strValue );
	#else
	strValue.TrimLeft();
	#endif
	char cmd[100];
		#if defined( CH_ARCH_16 ) 
	    
	for ( int i = 0; i < 99 && !isspace( strValue[i] );  i++ )
	{
		cmd[i] = strValue[i];
	}  
	cmd[i] = 0;
	#else
	::sscanf(LPCTSTR(strValue), "%s", cmd);
	#endif
	string strCmd(cmd);
	#if defined( CH_ARCH_16 )   
	TrimLeft( strCmd );
	TrimRight( strCmd ); 
	#else
	strCmd.TrimLeft();
	strCmd.TrimRight();
	#endif
	return strCmd;
}


bool ChGraphicPaneInfo::DoCommand( string& strArgs )
{
	string strValue;
//	TRACE1("DoCommand: %s\n", strArgs);
	bool boolProcessed = false;
	//  respond to hooked img messages

	// We already screened in the hook handler for img's of interest
	
	if (ChHtmlWnd::GetHTMLAttribute( strArgs, CH_GRAPH_CMD, strValue ))
	{
		string strCmd = TrimArg(strValue);
		if (!strCmd.CompareNoCase( "load" ))
		{
			DoLoadCommand( strArgs );
			boolProcessed = true;
		}
		else if(!strCmd.CompareNoCase( "show" ) || !strCmd.CompareNoCase( "hide" ))
		{
			DoShowCommand( strArgs );
			boolProcessed = true;
		}
	}

	if(!boolProcessed)
	{
		DoViewerCommand( strArgs );
		boolProcessed = false;		// allow others to hook
	}

	return boolProcessed;
}


void ChGraphicPaneInfo::DoViewerCommand(string& strArgs)
{
	ChGraphicDocumentHTTPReq*		pDependent;
	if (pDependent = GetPendingLoad())
	{
									// Queue up message
		pDependent->AddCommand( strArgs );
	}
	else
	{	
		SendViewerCommand( strArgs );
	}
}


void ChGraphicPaneInfo::SendViewerCommand(string& strArgs, ChViewerMsgDispatch* pMod)
{
	ChInlineMsg msg( strArgs );

	if (!pMod)
	{
		pMod = GetCurrentViewer();
	}

	if (pMod)
	{
		pMod->Post( msg );
	}

	//if(pMod) pMod->Send(msg);
}

void ChGraphicPaneInfo::DoLoadCommand( string& strArgs )
{
	//  respond to hooked img load message; preempt outstanding loads if any
	string		strURL;
									// Needs to prempt in-progress load

	if(ChHtmlWnd::GetHTMLHref( strArgs, true, strURL ))
	{
		ChGraphicDocumentHTTPReq *pHTTPReq = new ChGraphicDocumentHTTPReq ( GetModuleID(), strURL );

		if (GetPendingLoad())
		{
			GetPendingLoad()->Cancel();
			SetPendingLoad( 0 );
		}

		SetPendingLoad( pHTTPReq );
		
		string strOption;

		ChHtmlWnd::GetHTMLAttribute( strArgs, "xch_notify", strOption );
		pHTTPReq->SetNotificationOption(strOption);

		ChViewerMsgDispatch* pViewer	= GetCurrentViewer();
		if(pViewer)
		{
			ChInlineMsg msg(strArgs);
			pViewer->Send(msg);

			// Turn off animation, so we get a little time to think
			ChPlayGraphicMsg stopPlayingRightNow(0, false, ChPlayGraphicMsg::immediate);
			pViewer->Send(stopPlayingRightNow);
		}
		GetCore()->GetURL( strURL, 0, GetStream(), (chparam)pHTTPReq );
	}

	return;
}

void ChGraphicPaneInfo::DoShowCommand(string& strArgs)
{
	string strValue;
									//  Show or hide the current viewer
	if (ChHtmlWnd::GetHTMLAttribute( strArgs, CH_GRAPH_CMD, strValue ))
	{
		string strCmd = TrimArg(strValue);
		bool boolShow = !strCmd.CompareNoCase( "show" );
		ChShowModuleMsg msg(boolShow);

		if(GetCurrentViewer()) GetCurrentViewer()->Send(msg);
	}
	return;
}

void ChGraphicPaneInfo::DoQueuedCommands(ChGraphicDocumentHTTPReq *pReq)
{
	// Sends queued commands on to current viewer
	ChStrList *pCommandQ = pReq->GetCommandQueue();

	if(pCommandQ)
	{
		string strCmd;

		while (!pCommandQ->IsEmpty())
		{
			strCmd = pCommandQ->RemoveHead();
			SendViewerCommand(strCmd);
		}

		delete pCommandQ;
		pReq->SetCommandQueue(0);
	}

	return;
}

// ===========================
// Viewer registration methods
// ===========================

void ChGraphicPaneInfo::RegisterViewer( const string &strModuleName,
										ChModuleID idModule )
{
	if(CH_MODULE_GRAPHICS_ANIMATION == strModuleName) 
	{
		RegisterViewer( strModuleName,idModule, ChHTTPConn::typeGIF );
		RegisterViewer( strModuleName, idModule, ChHTTPConn::typeJPEG );
		RegisterViewer( strModuleName, idModule, ChHTTPConn::typeBMP );
		//HookViewerMessages(idModule);						   // it doesn't understand yet
	}
	else if (CH_MODULE_GRAPHICS_MAZE == strModuleName)
	{
		RegisterViewer( strModuleName,idModule, ChHTTPConn::typeVRML );
		HookViewerMessages(idModule);
	}
}


void ChGraphicPaneInfo::RegisterViewer( const string &strModuleName,
										ChModuleID idModule,
										ChHTTPConn::tagMimeTypes type )
{
											/* This should do a use on the
												module in the future, then
												release when we destroy the
												table */

	ChGraphicViewer*	pViewer = new ChGraphicViewer( this, strModuleName, idModule );

	if (!m_pViewers)
	{
		m_pViewers = new ChViewerSplay;
	}

	m_pViewers->Insert( type, pViewer );

											// Now delete from pending, if found
	ChGraphicViewer**	ppPendingViewer;

	if (m_pPendingViewers)
	{										/* Note we assume we never have
												more than one outstanding
												viewer load for any one mime
												type - having more than one
												registered is bogus anyways */

		ppPendingViewer = m_pPendingViewers->Find( type );
		if (ppPendingViewer)
		{
			ChGraphicViewer*	pDeletedViewer = *ppPendingViewer;

			m_pPendingViewers->Delete( type );
											// Delete the viewer object
			delete pDeletedViewer;
		}

		#if 0

		if(m_pPendingViewers->IsEmpty())
		{
			delete m_pPendingViewers;
			m_pPendingViewers = 0;
		}

		#endif
	}

	// Now, if a load was waiting for this viewer, do it
	if(m_pSuspendedLoad)
	{
		string strType = m_pSuspendedLoad->GetMimeType();
		if(type == (ChHTTPConn::tagMimeTypes)ChHTTPConn::GetMimeType(strType))
		{
			Load(m_pSuspendedLoad);
		}
	}

}


void ChGraphicPaneInfo::RegisterPendingViewer( const string &strModuleName,
												ChHTTPConn::tagMimeTypes type )
{
	ChGraphicViewer*	pViewer = new ChGraphicViewer( this, strModuleName );

	if (!m_pPendingViewers)
	{
		m_pPendingViewers = new ChViewerSplay;
	}

	m_pPendingViewers->Insert( type, pViewer );
}


ChViewerMsgDispatch * ChGraphicPaneInfo::GetMimeViewer( string strType )
{
	ChModuleID id;
	return GetMimeViewer(strType, id);
}

ChViewerMsgDispatch * ChGraphicPaneInfo::GetMimeViewer( string strType, ChModuleID &id)
{
	ChViewerMsgDispatch*		pViewer = 0;
	ChHTTPConn::tagMimeTypes	type;
	ChGraphicViewer**			ppViewerDef;

	type = (ChHTTPConn::tagMimeTypes)ChHTTPConn::GetMimeType( strType );

	if (m_pViewers)
	{
		ppViewerDef = m_pViewers->Find( type );
		if (ppViewerDef)
		{
			pViewer = (*ppViewerDef)->GetModule();
			id = (*ppViewerDef)->GetModuleID();
		}
	}

	return pViewer;
}

// Answer whether a mime type has an outstanding load of a viewer module, and also
// return the name of the module if pstrViewer is not null

bool ChGraphicPaneInfo::IsMimeViewerPending( string strType, string *pstrViewer /*= 0*/ )
{
	ChHTTPConn::tagMimeTypes type = (ChHTTPConn::tagMimeTypes)ChHTTPConn::GetMimeType(strType);
	ChGraphicViewer ** ppViewerDef;
	if (m_pPendingViewers)
	{
		ppViewerDef = m_pPendingViewers->Find(type);
		if (ppViewerDef && pstrViewer)
		{
			// they wanna know the name
			*pstrViewer = (*ppViewerDef)->GetModuleName();
		}
	}
	return (ppViewerDef != 0);
}

// Load commands to be sent to viewer

bool ChGraphicPaneInfo::Load( ChGraphicDocumentHTTPReq *pReq, ChViewerMsgDispatch* pViewer /* = 0*/, 
	ChModuleID id /* = 0 */ )
{
	string strURL		= pReq->GetURL();
	string strFilename	= pReq->GetFilename();
	string strType		= pReq->GetMimeType();

	return Load( pReq, strURL, strFilename, strType, pViewer, id );
}

// This function assumes we definitely have a viewer for the mime type
bool ChGraphicPaneInfo::Load( ChGraphicDocumentHTTPReq *pReq, const string &strURL, 
	const string &strFilename, const string &strType, ChViewerMsgDispatch* pViewer /* = 0*/,
	ChModuleID id /* = 0 */ )
{ 

	if(!pViewer || !id)
	{
		pViewer = GetMimeViewer( strType, id );
	}

	bool boolSuccess = false;
	if(pViewer)
	{
		ChViewerMsgDispatch *pOldViewer = 0;
		if(id != GetCurrentViewerID())
		{
			SetCurrentViewer(pViewer, id);
		}
		int iOptions = pReq->GetNotificationOption();

		ChSceneMsg sceneMsg(strURL, strFilename, strType, true, chparam(pReq));
		pViewer->Send(sceneMsg);

		//DoQueuedCommands(pReq);	 // take care of any queued commands
		boolSuccess = true;			  
	}
	SetSuspendedLoad(0);
	return boolSuccess;
}

bool ChGraphicPaneInfo::IsGraphicViewer(ChModuleID idModule)
{
	return (idModule == m_idMazeModule || idModule == m_idMazeModule); 
}

#if 0
void ChGraphicPaneInfo::OnParseComplete(string &strURL, chparam data)
{
	ChGraphicDocumentHTTPReq* pReq = (ChGraphicDocumentHTTPReq* )data;
	DoQueuedCommands(pReq);	 // take care of any queued commands
}
#endif

///////////////////////////////////////////////////////////////////////////////
////////////////////////////// Handlers	 //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

CH_IMPLEMENT_MESSAGE_HANDLER( paneInitHandler )
{
	ChGraphicPaneInfo*	pInfo = (ChGraphicPaneInfo*)pMainInfo;

	pInfo->Initialize();
	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( paneLoadCompleteHandler )
{
	ChLoadCompleteMsg*	pMsg = (ChLoadCompleteMsg*)&msg;
	string				strURL;
	string				strFilename;
	chparam				userData;
	ChGraphicPaneInfo*	pInfo = (ChGraphicPaneInfo*)pMainInfo;
	string				strModuleName;
	ChModuleID			idModule;
										// Get message params

	pMsg->GetParams( strModuleName, idModule, strFilename, userData );

	if ("" == strModuleName)
	{										// Not a module, must be data
		pMsg->GetParams( strURL, strFilename, userData );

		// TODO handle loading real stuff
		ChGraphicHTTPReq *pHTTPReq	 = (ChGraphicHTTPReq *)userData;

		TRACE( "MESSAGE:  CH_MSG_LOAD_COMPLETE (Graphics Pane Mgr)\n" );
		TRACE1( "         %s ->\n", (const char*)strURL );
		TRACE1( "         %s\n", (const char*)strFilename );

		switch (pHTTPReq->GetType())
		{
			case ChGraphicHTTPReq::document:
			{								/* Find out the mime type, and send
												the load msg on to the proper
												viewer */

	 			ChGraphicDocumentHTTPReq *pReq = (ChGraphicDocumentHTTPReq *)pHTTPReq;

				if (!pReq->IsCancelled())
				{
					string					strType = pMsg->GetType();
					string					strViewerName;
					ChModuleID				idViewer;
					ChViewerMsgDispatch*	pViewer;

					pViewer = pInfo->GetMimeViewer( strType, idViewer );
					pInfo->SetPendingLoad( 0 );

					if (pViewer)
					{
						pInfo->Load( pReq, strURL, strFilename, strType, pViewer, idViewer );
						//delete pReq;  // it's done, altho it may have spawned more	 ?????????????????
					}
					else if (pInfo->IsMimeViewerPending( strType, &strViewerName ))
					{
						TRACE2("Awaiting arrival of viewer '%s' for mime type '%s'\n", strViewerName, strType);
						pReq->SetFile( strURL, strFilename, strType );
						pInfo->SetSuspendedLoad(pReq);		   // awaiting the arrival of a viewer
					}
					else
					{
						// no viewer configured; do nothing
						TRACE1("No viewer configured for mime type '%s'!\n", strType);
						delete pReq;  // it's done, altho it may have spawned more
					}
				}
				else
				{
					// Trash it
					TRACE1("Graphics file load pre-empted: %s\r", LPCTSTR(strFilename));
					delete pReq;  // it's done, altho it may have spawned more
				}
				break;
			}

			default:
			{
				break;
			}
		}
	}
	else
	{
		if(CH_MODULE_GRAPHICS_ANIMATION == strModuleName)
		{
			pInfo->m_idAnimModule = idModule;	   // i confess
			pInfo->RegisterViewer(strModuleName, idModule);
		}
		else if(CH_MODULE_GRAPHICS_MAZE == strModuleName)
		{
			pInfo->m_idMazeModule = idModule;
			pInfo->RegisterViewer(strModuleName, idModule);
		}
	}

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( paneLoadErrorHandler )
{
	ChLoadErrorMsg*		pMsg = (ChLoadErrorMsg*)&msg;
	string				strURL;
	string				strModuleName;
	string				strError;
	ChModuleID			idModule;
	chint32				lError;
	chparam				userData;
	ChGraphicPaneInfo*	pInfo = (ChGraphicPaneInfo*)pMainInfo;
											// Get message params

	pMsg->GetParams( strModuleName, idModule, strURL, lError, userData, strError );
	ChGraphicHTTPReq *pHTTPReq	 = (ChGraphicHTTPReq *)userData;
											// Clean up
	if(pInfo->GetPendingLoad() == pHTTPReq) pInfo->SetPendingLoad(0);

	delete pHTTPReq;
	// Send to trace window
	string strMsg;
	if(strError.IsEmpty())
	{
		strMsg.Format("URL Load Failed: Error number %ld\n", lError);
	}
	else
	{
		strMsg.Format("URL Load Failed: %s\n", strError);
	}
	pInfo->GetCore()->Trace( strMsg, ChCore::traceErrors, true );

	// Tell the viewer it's ok to animate now
	ChViewerMsgDispatch* pViewer	= pInfo->GetCurrentViewer();
	if(pViewer)
	{
		// probably a bug for 2 d - We really need a resume and suspend message
		ChPlayGraphicMsg restartPlayingRightNow(0, true, ChPlayGraphicMsg::immediate);
		pViewer->Send(restartPlayingRightNow);
	}

	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( paneLoadImageHandler )
{
	ChGraphicPaneInfo*	pInfo = (ChGraphicPaneInfo*)pMainInfo;
	// for now, assumes URL is just a file
	// !!!!!!!!!!!!
	#if 0
	ChImageMsg *pMsg = (ChImageMsg *)&msg;
	string strURL;
	pMsg->GetParams(strURL);

	//  load a VRML URL
	ChGraphicBackgroundHTTPReq *pHTTPReq = new ChGraphicBackgroundHTTPReq ( pInfo->GetView(), strURL );
	pInfo->GetHTTPConn()->GetURL( strURL, (chparam)pHTTPReq );
	pInfo->SetLeafDependent(pHTTPReq);
	#endif
	return 0;
}



CH_IMPLEMENT_MESSAGE_HANDLER( paneCmdHookHandler )
{
	ChGraphicPaneInfo*	pInfo = (ChGraphicPaneInfo*)pMainInfo;

	ChCmdMsg *pMsg = (ChCmdMsg *)&msg;
	string strArgs;
	pMsg->GetParams(strArgs);

	ChModuleID idOrigin = msg.GetOriginModule();

	if(pInfo->IsGraphicViewer(idOrigin))
	{
														/* If this is a graphic viewer
														controlled by us, pass its cmd 
														message on to our hook chain */
		ChCmdMsg newMsg(strArgs);
		bool boolProcessed = false;

	 	pInfo->GetCmdHookMgr()->Dispatch( newMsg, boolProcessed );
	}
	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( paneImageHookHandler )
{
	ChGraphicPaneInfo*	pInfo = (ChGraphicPaneInfo*)pMainInfo;

	ChInlineMsg *pMsg = (ChInlineMsg *)&msg;
	string strArgs;
	pMsg->GetParams(strArgs);
				  //xch_graph="load" href="http://www.chaco.com/pueblo/0.6/ChAnim/msw32/pueblo.wrl>"
				  // xch_module="load" xch_module_name="Chaco VRML Module" xch_module_name_base="ChGraphx">
				//	  xch_graph="load" href="http://www.chaco.com/pueblo/0.6/ChAnim/msw32/pueblo.wrl>
				//	  xch_graph="light 1 .5">
	string strValue;
											// Respond to hooked img messages

	if (ChHtmlWnd::GetHTMLAttribute( strArgs, CH_GRAPH_CMD, strValue ) ||
		ChHtmlWnd::GetHTMLAttribute( strArgs, CH_GRAPH_CMD_NODE, strValue ) ||
		ChHtmlWnd::GetHTMLAttribute( strArgs, CH_EVENT_NOTIFY, strValue ))
	{

								// Do it
		if(pInfo->DoCommand( strArgs ))
		{
			msg.SetProcessed(true);
		}

	}

	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( paneLoadSceneHandler )
{
	ChGraphicPaneInfo*	pInfo = (ChGraphicPaneInfo*)pMainInfo;
	ChSceneMsg *pMsg = (ChSceneMsg *)&msg;

	string strURL, strFilename, strType;
	bool	boolNew;
	pMsg->GetParams(strURL, strFilename, strType, boolNew);

								 		// Load a file of something
									// Needs to prempt in-progress load


	ChGraphicDocumentHTTPReq *pHTTPReq = new ChGraphicDocumentHTTPReq ( pMainInfo->GetModuleID(), strURL );

	if (pInfo->GetPendingLoad())
	{
		pInfo->GetPendingLoad()->Cancel();
		pInfo->SetPendingLoad( 0 );
	}

	pInfo->SetPendingLoad( pHTTPReq );
	pInfo->GetCore()->GetURL( strURL, 0, pInfo->GetStream(), (chparam)pHTTPReq );


	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( paneShowModuleHandler )
{
	ChShowModuleMsg*	pMsg = (ChShowModuleMsg*)&msg;
	ChGraphicPaneInfo*	pInfo = (ChGraphicPaneInfo*)pMainInfo;

	pInfo->ShowModule( pMsg->IsShowing() );

	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( paneResetHandler )
{
	ChResetMsg*	pMsg = (ChResetMsg*)&msg;
	ChGraphicPaneInfo*	pInfo = (ChGraphicPaneInfo*)pMainInfo;

	if (pInfo->GetCurrentViewer())
	{
		ChResetMsg		msg;

		pInfo->GetCurrentViewer()->Send( msg );
	}
	pInfo->SetCurrentViewer(0,0);
	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( paneInstallHookHandler )
{
	
	ChGraphicPaneInfo*	pInfo = (ChGraphicPaneInfo*)pMainInfo;
	ChInstallHookMsg*	pMsg = (ChInstallHookMsg*)&msg;
	ChHookManager*		pHookMgr;
	ChModuleID			idHookModule;
	chint32				lMessage;

	pMsg->GetParams( idHookModule, lMessage );
	//ASSERT( 0 == lMessage || CH_MSG_CMD == lMessage || CH_MSG_INLINE == lMessage);

	switch(lMessage)
	{
		case CH_MSG_CMD:
		{
			pHookMgr = pInfo->GetCmdHookMgr();
			pHookMgr->Install( idHookModule );
			break;
		}
		case CH_MSG_INLINE:
		{
 			pHookMgr = pInfo->GetImageHookMgr();
			pHookMgr->Install( idHookModule );
			break;
		}
	}
	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( panePromoteHookHandler )
{
	ChGraphicPaneInfo*	pInfo = (ChGraphicPaneInfo*)pMainInfo;
	ChPromoteHookMsg*	pMsg = (ChPromoteHookMsg*)&msg;
	ChHookManager*		pHookMgr;
	ChModuleID			idHookModule;
	bool				boolPromote;
	chint32				lMessage;

	pMsg->GetParams( idHookModule, boolPromote, lMessage );
	//ASSERT( 0 == lMessage || CH_MSG_CMD == lMessage || CH_MSG_INLINE == lMessage);

	switch(lMessage)
	{
		case CH_MSG_CMD:
		{
			pHookMgr = pInfo->GetCmdHookMgr();
			pHookMgr->Promote( idHookModule, boolPromote );
			break;
		}
		case CH_MSG_INLINE:
		{
 			pHookMgr = pInfo->GetImageHookMgr();
			pHookMgr->Promote( idHookModule, boolPromote );
			break;
		}
		case 0:
		{
			pHookMgr = pInfo->GetCmdHookMgr();
			pHookMgr->Promote( idHookModule, boolPromote );
 			pHookMgr = pInfo->GetImageHookMgr();
			pHookMgr->Promote( idHookModule, boolPromote );
			break;
		}
		default:
			break;
	}


	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( paneUninstallHookHandler )
{
	ChGraphicPaneInfo*	pInfo = (ChGraphicPaneInfo*)pMainInfo;
	ChUninstallHookMsg*	pMsg = (ChUninstallHookMsg*)&msg;
	ChHookManager*		pHookMgr;
	ChModuleID			idHookModule;
	chint32				lMessage;

	pMsg->GetParams( idHookModule, lMessage );
	//ASSERT( 0 == lMessage || CH_MSG_CMD == lMessage || CH_MSG_INLINE == lMessage);

	switch(lMessage)
	{
		case CH_MSG_CMD:
		{
			pHookMgr = pInfo->GetCmdHookMgr();
			pHookMgr->Uninstall( idHookModule );
			break;
		}
		case CH_MSG_INLINE:
		{
 			pHookMgr = pInfo->GetImageHookMgr();
			pHookMgr->Uninstall( idHookModule );
			break;
		}
		case 0:
		{
			pHookMgr = pInfo->GetCmdHookMgr();
			pHookMgr->Uninstall( idHookModule );
 			pHookMgr = pInfo->GetImageHookMgr();
			pHookMgr->Uninstall( idHookModule );
			break;
		}
		default:
			break;
	}


	return 0;
}



