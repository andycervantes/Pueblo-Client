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

	Implementation for the ChGraphic class, which is used to display
	graphics, & accept selection of hot spots and sprites.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChGrMod.cpp,v 2.25 1996/04/19 00:56:33 jimd Exp $

#include "grheader.h"

#include <ChCore.h>
#include <ChPane.h>

#include "ChGrMod.h"

#if defined(CH_USE_2D)
#include "ChAniDep.h"
#endif

//#include "ChClMod.h"
#include "ChGrStrm.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	Handler declarations
----------------------------------------------------------------------------*/

#if 1
CH_DECLARE_MESSAGE_HANDLER( graphicShowModuleHandler )
CH_DECLARE_MESSAGE_HANDLER( graphicResetHandler )
CH_DECLARE_MESSAGE_HANDLER( graphicInstallHookHandler )
CH_DECLARE_MESSAGE_HANDLER( graphicPromoteHookHandler )
CH_DECLARE_MESSAGE_HANDLER( graphicUninstallHookHandler )

#else
CH_DECLARE_MESSAGE_HANDLER( graphicInitHandler )
CH_DECLARE_MESSAGE_HANDLER( graphicLoadCompleteHandler )
CH_DECLARE_MESSAGE_HANDLER( graphicLoadErrorHandler )
CH_DECLARE_MESSAGE_HANDLER( graphicLoadImageHandler )
CH_DECLARE_MESSAGE_HANDLER( graphicLoadCastHandler )
CH_DECLARE_MESSAGE_HANDLER( graphicLoadAnchorHandler )
CH_DECLARE_MESSAGE_HANDLER( graphicLoadScriptHandler )
CH_DECLARE_MESSAGE_HANDLER( graphicPlayGraphicHandler )
CH_DECLARE_MESSAGE_HANDLER( graphicShowCastHandler )
CH_DECLARE_MESSAGE_HANDLER( graphicEnableDragHandler )
#endif



static ChMsgHandlerDesc	graphicHandlers[] =
							{	{CH_MSG_SHOW_MODULE,	graphicShowModuleHandler},
								{CH_MSG_RESET,			graphicResetHandler},
								//{CH_MSG_INIT, 			graphicInitHandler},
								{CH_MSG_INSTALL_HOOK, 	graphicInstallHookHandler},
								{CH_MSG_PROMOTE_HOOK, 	graphicPromoteHookHandler},
								{CH_MSG_UNINSTALL_HOOK, graphicUninstallHookHandler}
							};

/*----------------------------------------------------------------------------
	ChGraphicMainInfo class
----------------------------------------------------------------------------*/

ChGraphicMainInfo::ChGraphicMainInfo( ChModuleID idModule,
										ChCore* pCore ) :
					ChMainInfo( idModule, pCore ),
					m_graphicDispatcher( pCore, idModule, defGraphicHandler ),
					m_hookMgr( pCore, idModule ),
					m_pBackReq(0),
					m_pStartReq(0),
					m_pWnd(0), 
					m_pageCount(0),
					m_boolShown( false )
{
	// Setup the HTTP stream
 	m_pGraphicStream = new ChGraphicStreamManager( pCore, 0 ); 
	ASSERT( m_pGraphicStream );
											// Compute pane limits
	ComputeDesiredSize();

}


ChGraphicMainInfo::~ChGraphicMainInfo()
{
	delete m_pGraphicStream;
	m_pGraphicStream = 0;
	delete m_pStartReq;
	m_pStartReq = 0;

}

void ChGraphicMainInfo::Initialize()
{	
}

void ChGraphicMainInfo::ComputeDesiredSize()
{
	ChPane*		pPane = GetPaneMgr()->FindPane( ChPaneMgr::strGraphicName );
	CClientDC	dc( pPane->GetFrameWnd() );
	TEXTMETRIC	tm;

	dc.GetTextMetrics( &tm );

	m_sMinWidth = tm.tmAveCharWidth * minCharWidth;
	m_sIdealWidth = tm.tmAveCharWidth * idealCharWidth;
	m_sMinHeight = (tm.tmHeight + tm.tmExternalLeading) * minCharHeight;
	m_sIdealHeight = (tm.tmHeight + tm.tmExternalLeading) * idealCharHeight;
}


void ChGraphicMainInfo::RegisterDispatchers()
{
	chint16		sHandlerCount = sizeof( graphicHandlers ) /
								sizeof( ChMsgHandlerDesc );

	m_graphicDispatcher.AddHandler( graphicHandlers, sHandlerCount );
}


void ChGraphicMainInfo::ShowModule( bool boolShow )
{
	ChPane*		pPane = GetPaneMgr()->FindPane( ChPaneMgr::strGraphicName );

	ASSERT( 0 != pPane );

	if (boolShow && (pPane->GetWindow() != GetView()))
	{
		pPane->SetOwner( GetModuleID(), GetView(), GetView() );
		pPane->SetSizePrefs( m_sIdealWidth, m_sIdealHeight, m_sMinWidth,
								m_sMinHeight );
	}

	if (boolShow && !IsShown())
	{
		GetView()->ShowWindow( SW_SHOW );
		pPane->Show();
		SetShown( true );
	}
	else if (!boolShow && IsShown())
	{
		pPane->Show( false );
		GetView()->ShowWindow( SW_HIDE );
		SetShown( false );
	}
}


void ChGraphicMainInfo::NotifyAnchor(string &strAnchor)
{
	bool		boolProcessed = false;
	ChCmdMsg	msg( strAnchor );

	msg.SetOriginModule( GetModuleID() );
	GetCmdHookMgr()->Dispatch( msg, boolProcessed );
}


void ChGraphicMainInfo::SetHidden()
{
	if (IsShown())
	{
		SetShown( false );
		
		if (GetView())
		{
			GetView()->ShowWindow( SW_HIDE );
		}
	}
}
void ChGraphicMainInfo::DoQueuedCommands(ChGraphicDocumentHTTPReq *pReq)
{
	// Sends queued commands on to current viewer
	ChStrList *pCommandQ = pReq->GetCommandQueue();

	if(pCommandQ)
	{
		string strCmd;

		while (!pCommandQ->IsEmpty())
		{
			strCmd = pCommandQ->RemoveHead();
			DoCommand(strCmd);
		}

		delete pCommandQ;
		pReq->SetCommandQueue(0);
	}

	return;
}



/*----------------------------------------------------------------------------
	Chaco message handlers
----------------------------------------------------------------------------*/

CH_IMPLEMENT_MESSAGE_HANDLER( defGraphicHandler )
{
	ChGraphicMainInfo*	pInfo = (ChGraphicMainInfo*)pMainInfo;


	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( graphicShowModuleHandler )
{
	ChShowModuleMsg*	pMsg = (ChShowModuleMsg*)&msg;
	ChGraphicMainInfo*	pInfo = (ChGraphicMainInfo*)pMainInfo;

	pInfo->ShowModule( pMsg->IsShowing() );

	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( graphicResetHandler )
{
	ChResetMsg*	pMsg = (ChResetMsg*)&msg;
	ChGraphicMainInfo*	pInfo = (ChGraphicMainInfo*)pMainInfo;

	pInfo->ShowModule( false );

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( graphicInstallHookHandler )
{
	
	ChGraphicMainInfo*	pInfo = (ChGraphicMainInfo*)pMainInfo;
	ChInstallHookMsg*	pMsg = (ChInstallHookMsg*)&msg;
	ChHookManager*		pHookMgr = pInfo->GetCmdHookMgr();
	ChModuleID			idHookModule;
	chint32				lMessage;

	pMsg->GetParams( idHookModule, lMessage );
	ASSERT( 0 == lMessage || CH_MSG_CMD == lMessage );

	pHookMgr->Install( idHookModule );

	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( graphicPromoteHookHandler )
{
	ChGraphicMainInfo*	pInfo = (ChGraphicMainInfo*)pMainInfo;
	ChPromoteHookMsg*	pMsg = (ChPromoteHookMsg*)&msg;
	ChHookManager*		pHookMgr = pInfo->GetCmdHookMgr();
	ChModuleID			idHookModule;
	bool				boolPromote;
	chint32				lMessage;

	pMsg->GetParams( idHookModule, boolPromote, lMessage );
	ASSERT( 0 == lMessage || CH_MSG_CMD == lMessage );

	pHookMgr->Promote( idHookModule, boolPromote );

	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( graphicUninstallHookHandler )
{
	ChGraphicMainInfo*	pInfo = (ChGraphicMainInfo*)pMainInfo;
	ChUninstallHookMsg*	pMsg = (ChUninstallHookMsg*)&msg;
	ChHookManager*		pHookMgr = pInfo->GetCmdHookMgr();
	ChModuleID			idHookModule;
	chint32				lMessage;

	pMsg->GetParams( idHookModule, lMessage );
	ASSERT( 0 == lMessage || CH_MSG_CMD == lMessage );

	pHookMgr->Uninstall( idHookModule );

	return 0;
}

