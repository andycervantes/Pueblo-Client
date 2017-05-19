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

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChMazMod.cpp,v 2.82 1996/09/12 19:09:43 pritham Exp $

#include "grheader.h"

#include <ctype.h>

#include <ChCore.h>
#include <ChHtmWnd.h>
#include <ChPane.h>

#if defined( CH_MSW ) && defined( CH_ARCH_16 )

	#include <ChUtil.h>

#endif	// defined( CH_MSW ) && defined( CH_ARCH_16 )

#include "ChGrMod.h"
#include "ChVrmlWnd.h"
#include "ChMazDep.h"

#if !defined( CH_PUEBLO_PLUGIN )
#include "ChMazePr.h"
#endif

#include "ChRlabPr.h"
#include "ChRenderData.h"

#if defined( CH_VRML_EVENTS )

#include "ChStubBrowser.h"
#include "ChVrmlEvent.h"

#endif	// defined( CH_VRML_EVENTS )

#include "ChMazCam.h"


#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

#include "ChRLImg.h"

#endif	// defined( CH_USE_RLAB )

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define GRAPHICS_PANE		1

									// Graphics img command modifiers for VRML

#define CH_GRAPH_VRML				"xch_graph_vrml"
#define CH_GRAPH_CMD_MINTIME   		"xch_minTime"
#define CH_GRAPH_CMD_MAXTIME   		"xch_maxTime"
#define CH_GRAPH_CMD_MAXMOVE   		"xch_maxMove"
#define CH_GRAPH_CMD_MAXROTATION   	"xch_maxRotation"
#define CH_GRAPH_CMD_STARTTIME   	"xch_startTime"
#define CH_GRAPH_CMD_PARAMS   		"params"
#define CH_CMD_NAME			   		"xch_cmd"

// IHTML magic name for the the current viewpoint node
#define theCurrentViewpoint			"current_viewpoint"

/*----------------------------------------------------------------------------
	Handler declarations
----------------------------------------------------------------------------*/

CH_DECLARE_MESSAGE_HANDLER( mazeInitHandler )
CH_DECLARE_MESSAGE_HANDLER( mazeLoadCompleteHandler )
CH_DECLARE_MESSAGE_HANDLER( mazeLoadErrorHandler )
#if !defined( CH_PUEBLO_PLUGIN )
CH_DECLARE_MESSAGE_HANDLER( mazeGetPageCountHandler )
CH_DECLARE_MESSAGE_HANDLER( mazeGetPagesHandler )
CH_DECLARE_MESSAGE_HANDLER( mazeGetPageDataHandler )
CH_DECLARE_MESSAGE_HANDLER( mazeReleasePagesHandler )
#endif

CH_DECLARE_MESSAGE_HANDLER( mazeLoadSceneHandler )
CH_DECLARE_MESSAGE_HANDLER( mazeImageHookHandler )
#if !defined( CH_PUEBLO_PLUGIN )
CH_DECLARE_MESSAGE_HANDLER( mazePlayGraphicHandler )
#endif


static ChMsgHandlerDesc	mazeHandlers[] =
						{	{CH_MSG_INIT, 			mazeInitHandler},
							{CH_MSG_LOAD_COMPLETE,	mazeLoadCompleteHandler},
							{CH_MSG_LOAD_ERROR,		mazeLoadErrorHandler},
#if !defined( CH_PUEBLO_PLUGIN )
						{CH_MSG_GET_PAGE_COUNT,	mazeGetPageCountHandler},
							{CH_MSG_GET_PAGES,		mazeGetPagesHandler},
							{CH_MSG_GET_PAGE_DATA,	mazeGetPageDataHandler},
							{CH_MSG_RELEASE_PAGES,	mazeReleasePagesHandler},
#endif
							{CH_MSG_INLINE,			mazeImageHookHandler},
#if !defined( CH_PUEBLO_PLUGIN )
							{CH_MSG_PLAY_GRAPHIC,	mazePlayGraphicHandler},
#endif
							{CH_MSG_LOAD_SCENE,		mazeLoadSceneHandler}
						};
/*----------------------------------------------------------------------------
	Chaco menu handlers
----------------------------------------------------------------------------*/

CH_DECLARE_MESSAGE_HANDLER( graphicsViewMenuHandler )


/*----------------------------------------------------------------------------
	ChMazeMainInfo class
----------------------------------------------------------------------------*/

ChMazeMainInfo::ChMazeMainInfo( ChModuleID idModule,
								ChCore* pCore ) :
					ChGraphicMainInfo( idModule, pCore ),
					m_reg( GR_PREFS_GROUP ),
					m_pInProgressReqs(0),
					m_minNotifyTime(-1),
					m_maxNotifyTime(-1),
					m_lastTick(0),
					m_boolNotificationEnabled(false)
{
	ChPane*		pPane = GetPaneMgr()->FindPane( ChPaneMgr::strGraphicName );
	CRect		rtChild( -100, -100, -1, -1 );
	bool		boolCreated;


	m_pSettings	 = new ChVrmlSettings;
	ReadPreferences();
	m_pWnd = new ChPuebloVrmlWnd( this, m_pSettings );
	boolCreated = GetView()->Create( rtChild, pPane->GetFrameWnd() );

	ASSERT( boolCreated );

	GetView()->SetCmdHookMgr( &m_hookMgr );
	m_pStartReq = new ChMazeStartHTTPReq( GetView(), "" );
}

void ChMazeMainInfo::Initialize()
{	
	ChGraphicMainInfo::Initialize();

	// GetView()->SetHeadlight(false);	Why on earth did we do this????
}

ChMazeMainInfo::~ChMazeMainInfo()
{											/* ChGraphicMainInfo class does
												most all the work */

	ChPane*		pPane = GetPaneMgr()->FindPane( ChPaneMgr::strGraphicName );

	ASSERT( 0 != pPane );

	if ((GetView() == pPane->GetWindow()) &&
		(pPane->GetModuleID() == GetModuleID()))
	{
											// Remove the window from the pane
		pPane->SetOwner( 0, 0, 0 );
	}
											// Destroy the window
	if (GetView())
	{
		GetView()->DestroyWindow();
		delete m_pWnd;
		m_pWnd = 0;
	}

	ChMazeWnd::TermMazeWnd();

	delete m_pSettings;
}


void ChMazeMainInfo::RegisterDispatchers()
{
	chint16		sHandlerCount = sizeof( mazeHandlers ) /
								sizeof( ChMsgHandlerDesc );

	ChGraphicMainInfo::RegisterDispatchers();	  // inherit handlers
	m_graphicDispatcher.AddHandler( mazeHandlers, sHandlerCount );
}


void ChMazeMainInfo::ShowModule( bool boolShow )
{
	ChGraphicMainInfo::ShowModule( boolShow );
	GetView()->SendMessage( WM_QUERYNEWPALETTE );	// ???? fake out 3dr
	if(!boolShow) m_boolNotificationEnabled = false;

	#if 0
	if(!boolShow) 
	{
		// to track down leaks just temporary!!!!!!!!!!!
		ChPane*		pPane = GetPaneMgr()->FindPane( ChPaneMgr::strGraphicName );

		ASSERT( 0 != pPane );

		if ((GetView() == pPane->GetWindow()) &&
			(pPane->GetModuleID() == GetModuleID()))
		{
												// Remove the window from the pane
			pPane->SetOwner( 0, 0, 0 );
		}
												// Destroy the window
		if (GetView())
		{
			GetView()->DestroyWindow();
			delete m_pWnd;
			m_pWnd = 0;
		}

		ChMazeWnd::TermMazeWnd();
	
		CRect		rtChild( -100, -100, -1, -1 );
		m_pWnd = new ChPuebloVrmlWnd( this, m_pSettings );
		bool boolCreated = GetView()->Create( rtChild, pPane->GetFrameWnd() );

		ASSERT( boolCreated );

		GetView()->SetCmdHookMgr( &m_hookMgr );
		delete m_pStartReq;
		m_pStartReq = new ChMazeStartHTTPReq( GetView(), "" );
	}
	#endif
}


void ChMazeMainInfo::EndFrameTime()
{
	DWORD	luNow = GetTickCount();
	DWORD	luElapsed = luNow - m_luTime;
	string	strStatus;
	double	frameRate = luElapsed ? 1.0 / (float)luElapsed : 1.0;

	frameRate *= 1000.0;

	strStatus.Format( "Frames per second: %.2f", frameRate );
	WriteStatus( strStatus );
}

void ChMazeMainInfo::WriteStatus(const string &strMessage)
{
	ChStatusMsg		StatusMsg( (string&)strMessage );
	GetCore()->DispatchMsg( CH_CORE_MODULE_ID, StatusMsg );
}

void ChMazeMainInfo::DoCommand(string& strArgs)
{
	string strValue;
	//TRACE1("DoCommand: %s\n", strArgs);
	//  respond to hooked img messages
	if (ChHtmlWnd::GetHTMLAttribute( strArgs, CH_GRAPH_CMD, strValue ))
	{      
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
		
		if(!strCmd.CompareNoCase("light"))
		{
			int	iLight;
			float fLevel; 
			#if defined( CH_ARCH_16 ) 
			const char* pstrStart = strValue;
			pstrStart += i;
			char * pstrEnd;
			iLight =  (int)strtol( pstrStart, &pstrEnd, 10 );
			pstrStart = pstrEnd;
			fLevel =  (int)strtod( pstrStart, &pstrEnd );
			#else
			::sscanf(LPCTSTR(strValue), "%s %d %f", cmd, &iLight, &fLevel);
			#endif
			//GetView()->AdjustLight(string(cmd), iLight, fLevel);
			GetView()->AdjustLight( strCmd, iLight, fLevel);
			return;
		}
		else if(!strCmd.CompareNoCase("draw"))
		{
									// <img xch_graph="draw">
			GetView()->UpdateWindow();
			#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
			GetView()->GetRenderContext()->Draw();
			#endif
			return;
		}
		else if(!strCmd.CompareNoCase("event"))
		{
									// <img xch_graph="event {type} {name} [count] {arg[s]}">
			ProcessEvent(strArgs);
			return;
		}
		else if (!strCmd.CompareNoCase( "load" ))
		{
			// Forwarded by pane as notification of what will happen
			OnLoadInitiated(string(""));
			return;
		}

		else
		{
			// handle all others tbd
		}
	}
	//else
	{
		string strVRML;
		if(ChHtmlWnd::GetHTMLAttribute( strArgs, CH_GRAPH_CMD_NODE, strVRML ))
		{
			string strCmd("node");
			GetView()->DoNodeCommand(strCmd, strVRML);
			return;
		}
	}
	
	{
		string strCmd;
		if(ChHtmlWnd::GetHTMLAttribute( strArgs, CH_EVENT_NOTIFY, strCmd ))
		{
			strCmd.TrimLeft();
			strCmd.TrimRight();
			if(!strCmd.CompareNoCase("move"))
			{
				SetupPositionNotification(strArgs);
			}
		 	return;
		}
	}
}

#if 0
// oughta do it this way someday
template <class eType> 
bool readMFEvent(string &in, const string &fmt, eType *&pEvent)
{
}
#endif

void ChMazeMainInfo::ProcessEvent(string& strArgs)
{
	#if defined(CH_VRML_EVENTS)
	string strValue;

//	TRACE1("ProcessEvent: %s\n", strArgs);
	//  respond to hooked img messages
									// <img xch_graph="event {node} {type} {eventName} [count] {arg[s]}">
									// example:
									// <img xch_graph="event MyCubeRotation SFRotation setRotation 0. 1. 0. .2">

	if (ChHtmlWnd::GetHTMLAttribute( strArgs, CH_GRAPH_CMD, strValue ))
	{      

		strValue.TrimLeft();
		char cmd[100];
		char name[200];
		char nodeName[200];
		char eventTypeName[200];
		int numBytes = 0;	

		ChVRMLEvent::type	eventType;
	   
		int numRead = ::sscanf(LPCTSTR(strValue), "%s %s %s %s%n", cmd, nodeName, eventTypeName, name, &numBytes);

		if(numRead >= 4)
		{
			ChVrmlBrowser * pBrowser = GetView()->GetBrowser();

			// Find the subject node
			
			string strNode(nodeName);

			ChNode * pNode = (pBrowser->Resolve(0, strNode));
			if(pNode == 0 && !strNode.CompareNoCase(theCurrentViewpoint))
			{
				pNode = pBrowser->GetViewpoint();
			}
			ChNode *pSFNode = 0;

			if(pNode)
			{
				// Got a node to work on
				string strEvent(eventTypeName);
				eventType = pBrowser->GetType(strEvent);
				ChIVrmlEvent *pEvent = 0;
			
				switch(eventType)
				{
					case ChVRMLEvent::SFRotation :
					{
						float x, y, z, angle;
						int numRead = ::sscanf(LPCTSTR(strValue) + numBytes, "%f %f %f %f", &x, &y, &z, &angle);
						pEvent = new ChRotationEvent(name, x, y, z, angle);
						break;
					}
					case ChVRMLEvent::SFVec3f :
					{
						float x, y, z;
						int numRead = ::sscanf(LPCTSTR(strValue) + numBytes, "%f %f %f", &x, &y, &z);
						pEvent = new ChVec3fEvent(name, x, y, z);
						break;
					}
					case ChVRMLEvent::MFVec3f :
					{
						int count;
						int nBytes = numBytes;
						int n;
						int numRead = ::sscanf(LPCTSTR(strValue) + nBytes, "%d%n", &count, &n);
						if(numRead)
						{
							float *val = new float [count*3];
							for(int i = 0; i < count * 3; i++)
							{
								nBytes += n;
								numRead = ::sscanf(LPCTSTR(strValue) + nBytes, "%f%n", val+i, &n);
								if(!numRead) break;
							}
							if(numRead) pEvent = new ChVec3fEvent(name, count, val);
							delete []val;
						}
						break;
					}
					case ChVRMLEvent::SFLong :
					{
						long value;
						int numRead = ::sscanf(LPCTSTR(strValue) + numBytes, "%d", &value);
						pEvent = new ChLongEvent(name, value);
						break;
					}
					case ChVRMLEvent::SFFloat :
					{
						float value;
						int numRead = ::sscanf(LPCTSTR(strValue) + numBytes, "%g", &value);
						pEvent = new ChFloatEvent(name, value);
						break;
					}
					case ChVRMLEvent::MFFloat :
					{
						int count;
						int nBytes = numBytes;
						int n;
						int numRead = ::sscanf(LPCTSTR(strValue) + nBytes, "%d%n", &count, &n);
						if(numRead)
						{
							float *val = new float [count];
							for(int i = 0; i < count; i++)
							{
								nBytes += n;
								numRead = ::sscanf(LPCTSTR(strValue) + nBytes, "%f%n", val+i, &n);
								if(!numRead) break;
							}
							if(numRead) pEvent = new ChFloatEvent(name, count, val);
							delete []val;
						}
						break;
					}
					case ChVRMLEvent::MFRotation :
					{
						float x, y, z, angle;

						int count;
						int nBytes = numBytes;
						int n;
						int numRead = ::sscanf(LPCTSTR(strValue) + nBytes, "%d%n", &count, &n);
						if(numRead)
						{
							float *val = new float [count * 4];
							for(int i = 0; i < count; i++)
							{
								nBytes += n;
								numRead = ::sscanf(LPCTSTR(strValue) + nBytes, "%f %f %f %f%n", &x, &y, &z, &angle, &n);
								if(numRead < 4) break;
								int index = i * 4;
								val[index] = x;
								val[index+1] = y;
								val[index+2] = z;
								val[index+3] = angle;
							}
							if(numRead) pEvent = new ChRotationEvent(name, count, val);
							delete []val;
						}
						break;
					}
					case ChVRMLEvent::SFBool :
					{
						bool value = false;
						string buf;
						char *pbuf = buf.GetBuffer(1000);

						int numRead = ::sscanf(LPCTSTR(strValue) + numBytes, "%s", buf);
						buf.ReleaseBuffer();
						if(numRead)
						{
							if(	!buf.CompareNoCase("true") || 
								!buf.CompareNoCase("1") || 
								!buf.CompareNoCase("t") || 
								!buf.CompareNoCase("yes")  || 
								!buf.CompareNoCase("y")) value = true;
							// assuming illegals are false
							pEvent = new ChBoolEvent(name, value);
						}
						break;
					}
					case ChVRMLEvent::SFTime :
					{
						double value;
						int numRead = ::sscanf(LPCTSTR(strValue) + numBytes, "%lg", &value);
						pEvent = new ChTimeEvent(name, value);
						break;
					}
					case ChVRMLEvent::SFNode :
					case ChVRMLEvent::MFNode :
					{
						// Our syntax only allows one node right now
						// and only via code
						string strVrml;
						if (ChHtmlWnd::GetHTMLAttribute( strArgs, CH_GRAPH_VRML, strVrml ))
						{
							if(strVrml.Left(6) != "#VRML ")
							{
								string strBuf = strVrml;
								strVrml = string("#VRML V1.0 ascii\n ") + strBuf;
							}

							// TODO Check for optional header field	xch_vrml_hdr

							pSFNode = (ChNode*)(pBrowser->CompileVRML(strVrml));
						}
						else
						{
							// remainder of fields if any are node names; just do first for now
							int numRead, n;
							char argNodeName[1000];
							if(numRead = ::sscanf(LPCTSTR(strValue) + numBytes, "%s%n", argNodeName, &n))
							{
								string strArgNodeName (argNodeName);
								pSFNode = (pBrowser->Resolve(pNode, strArgNodeName));
								numBytes += n;
							}
							if(!pSFNode)
							{
								string strMsg;
								strMsg.Format("VRML: Event %s, node %s was not found in scene graph under node %s.\n", 
									name, argNodeName, strNode );
								((ChMazeWnd*)GetView())->OnError( CH_MAZE_ROUTE_ERROR_NODE_NOTFOUND, strMsg, ChMazeWnd::traceError);
							}

						}

						if(pSFNode) pEvent = new ChNodeEvent(name, pSFNode);
						break;
					}
					default:
					{
						// Ignore it
						break;
					}
				}
			
				if(pEvent)
				{
					if(ChIVrmlEvent::IsMultiple(eventType))
					{
						pEvent->SetMultiple(true);
					} 
					pBrowser->SendEvent(pNode, 0, pEvent);	// I'm doing this direct, so
															// don't delete the event. In the real case,
															// It needs to be deleted after sending
					pBrowser->FreeNode(pNode);				// Preservation of node is now browser's
															// responsibility. This undoes the Use()
															// implicit in Resolve()
					
				}
				if(pSFNode) pBrowser->FreeNode(pSFNode); 
			}
			else
			{
				// No node found for subject; complain
				string strMsg;
				strMsg.Format("VRML: Event %s, node %s was not found.\n", LPCTSTR(name), strNode );
				((ChMazeWnd*)GetView())->OnError( CH_MAZE_ROUTE_ERROR_NODE_NOTFOUND, strMsg, ChMazeWnd::traceError);
				//TRACE(strMsg);	// ahhh, should we print this too?
			}

		}
	}
	#endif
}


void ChMazeMainInfo::SetupPositionNotification(const string &strArgs)
{
	// Call this with a blank string to reset

	/* <img xch_event="move" 
			xch_minTime=nnn 
			xch_maxTime=nnn 
			xch_maxMove=nnn.nn 
			xch_startTime=nnn 
			params="position look up time orientation velocity slewrate">

			defaults:
				xch_minTime=1000 
				xch_maxTime=10000 
				xch_maxMove=0.5 
				xch_startTime=0 
				params="position" - specifying empty gives no args

			where notification param formats are:
				position f f f
				look	f f f
				up f f f
				time : long milliseconds since startTime 
				orientation f f f f (axis, then angle)
				velocity f f f
				slewRate f f f f (axis, then angular velocity)

				all units are in meters or radians, or meter/sec or rads/sec
				all time is in milliseconds
	*/
	// Defaults
	long 	lMinTime=1000; 
	long 	lMaxTime=10000; 
	float 	fMaxMove=0.5;
	float 	fMaxRotation=3.1415927 / 12;	   // 15 degrees
	char 	params[CH_MAX_NOTIFICATION_PARAMS];
	chint32 ticks = ::GetMessageTime();
	bool	boolEnabled = false;
	double 	dOffset=-ticks;

	memset(params, 0, sizeof(params));
	params[0] = 'p';
	

	if(!strArgs.IsEmpty())
	{
		lMinTime=m_minNotifyTime;     // we'll just modify current
		lMaxTime=m_maxNotifyTime;   
		fMaxMove=m_maxMove;     
		fMaxRotation=m_maxRotation;     
		dOffset=m_dTimeOffset;
		boolEnabled = true;     
		memmove(params, m_params, sizeof(params));
		double t;
		int numRead;
		string strValue;
		if(ChHtmlWnd::GetHTMLAttribute( strArgs, CH_GRAPH_CMD_MINTIME, strValue ))
		{
			if((numRead = sscanf(LPCTSTR(strValue), "%lg", &t)) >= 1 )
			{
				lMinTime = long(t);
			} 
		}
			
		if(ChHtmlWnd::GetHTMLAttribute( strArgs, CH_GRAPH_CMD_MAXTIME, strValue ))
		{
			if((numRead = sscanf(LPCTSTR(strValue), "%lg", &t)) >= 1 )
			{
				lMaxTime = long(t);
			} 
		}

		if(ChHtmlWnd::GetHTMLAttribute( strArgs, CH_GRAPH_CMD_MAXMOVE, strValue ))	
		{
			if((numRead = sscanf(LPCTSTR(strValue), "%lg", &t)) >= 1 )
			{
				fMaxMove = t;
			} 
		}
			
		if(ChHtmlWnd::GetHTMLAttribute( strArgs, CH_GRAPH_CMD_MAXROTATION, strValue ))	
		{
			if((numRead = sscanf(LPCTSTR(strValue), "%lg", &t)) >= 1 )
			{
				fMaxRotation = t;
			} 
		}
			
		if(ChHtmlWnd::GetHTMLAttribute( strArgs, CH_GRAPH_CMD_STARTTIME, strValue ))	
		{
			if((numRead = sscanf(LPCTSTR(strValue), "%lg", &t)) >= 1 )
			{
				dOffset = (t - ticks);
			} 
		}
			
		if(ChHtmlWnd::GetHTMLAttribute( strArgs, CH_CMD_NAME, strValue ))	
		{
			if( strValue.IsEmpty()) boolEnabled = false;
			else boolEnabled = true;
			// No processing of name yet
		}
			
		if(ChHtmlWnd::GetHTMLAttribute( strArgs, CH_GRAPH_CMD_PARAMS, strValue ))
		{
			char *pTxt = strValue.GetBuffer(100);
			char key[200];
			int n, i = 0;
			memset(params, 0, sizeof(params));

			while(i < CH_MAX_NOTIFICATION_PARAMS && pTxt && *pTxt && sscanf( pTxt, "%s%n", key, &n))
			{
				string sKey(key);					      

				if(!sKey.CompareNoCase("position") ||
					!sKey.CompareNoCase("look") ||
					!sKey.CompareNoCase("up") ||
					!sKey.CompareNoCase("time") ||
					!sKey.CompareNoCase("orientation") ||
					!sKey.CompareNoCase("velocity") ||
					!sKey.CompareNoCase("slewrate"))
				{
					params[i++] = tolower(key[0]);		// first letter is key
				}
				pTxt += n;		
			}
		}	
	}
	

	// Copy the stuff into 'this'
	m_minNotifyTime 	=	lMinTime;	
	m_maxNotifyTime 	=	lMaxTime;	  
	m_maxMove       	=	fMaxMove;	
	m_maxRotation       =	fMaxRotation;	
	m_dTimeOffset   	=	dOffset;
	m_boolNotificationEnabled	= boolEnabled;		  
	memmove(m_params, params, sizeof(params));
 

}

ChMazeMainInfo * ChMazeMainInfo::Add(ChGraphicHTTPReq *pInProgressReq)
{
	if(!m_pInProgressReqs)
	{
		//m_pInProgressReqs = new ChPtrList<ChGraphicHTTPReq>;
		m_pInProgressReqs = new ChGraphicHTTPReqList;
	}
	m_pInProgressReqs->AddTail(pInProgressReq);
	return this;
}

ChMazeMainInfo * ChMazeMainInfo::Delete(ChGraphicHTTPReq *pInProgressReq)
{
	if(m_pInProgressReqs)
	{
		ChPosition	pos;
		if(!m_pInProgressReqs->IsEmpty())
		{
			pos = m_pInProgressReqs->Find(pInProgressReq, 0 );
			if(pos) m_pInProgressReqs->Remove(pos);
		}
		if(m_pInProgressReqs->IsEmpty())
		{
			delete m_pInProgressReqs;
			m_pInProgressReqs = 0;
		}
	}
	return this;
}

ChMazeMainInfo * ChMazeMainInfo::CancelInProgressReqs()
{
	if(m_pInProgressReqs)
	{
		while(!m_pInProgressReqs->IsEmpty())
		{
			ChGraphicHTTPReq *pReq = m_pInProgressReqs->RemoveHead();
			pReq->Cancel();
		}
		delete m_pInProgressReqs;
		m_pInProgressReqs = 0;
	}
	return this;
}

void ChMazeMainInfo::OnTick()
{
	// Bootleg the animation tick for our own purposes

	chint32 ticks = ::GetMessageTime();
	if(IsShown() && m_boolNotificationEnabled && ticks - m_lastTick >= m_minNotifyTime)
	{
		// notify mud
		// if moved or if over max time for notify, do it
		ChPuebloVrmlWnd* pWnd =	(ChPuebloVrmlWnd*)m_pWnd;
		GxVec3f loc =  pWnd->GetCameraControl()->GetLoc();
		GxVec3f look =  pWnd->GetCameraControl()->GetLookDir();
		GxVec3f up =  pWnd->GetCameraControl()->GetUp();
		GxVec3f delta = loc;
		delta -= m_lastLoc;
		float distance = delta.magnitude();
		float cosm = cos(m_maxRotation);
		if(!m_lastTick 
			|| distance > m_maxMove 
			|| ticks - m_lastTick > m_maxNotifyTime
			|| (m_maxRotation > 0 && m_lastLook.dot(look) < cosm)
			|| (m_maxRotation > 0 && m_lastUp.dot(up) < cosm) )
		{
			string command;

			FormatMoveCommand(command);
			NotifyAnchor(command);

			m_lastTick = ticks;
			m_lastLoc = loc;
			m_lastUp = up;
			m_lastLook = look;
		}

	}
}
void ChMazeMainInfo::FormatMoveCommand(string &command)
{

	command = "xch_cmd=\"PUEBLOMOVE";
	for(int i = 0; i < CH_MAX_NOTIFICATION_PARAMS; i++)
	{
		char buf[100];						      
		GxVec3f vec;
		buf[0] = 0;
		ChPuebloVrmlWnd* pWnd =	(ChPuebloVrmlWnd*)m_pWnd;
						       
		// possibilities:
		// position look up time orientation velocity slewrate
		switch(m_params[i])
		{
			case 'p':
			{
				vec = pWnd->GetCameraControl()->GetLoc();
				sprintf(buf, " %6.3f %6.3f %6.3f", double(vec.x()), double(vec.y()), double(vec.z()));
				break;
			}
			case 'l':
			{
				vec = pWnd->GetCameraControl()->GetLookDir();
				sprintf(buf, " %6.3f %6.3f %6.3f", double(vec.x()), double(vec.y()), double(vec.z()));
				break;
			}
			case 'u':
			{
				vec = pWnd->GetCameraControl()->GetUp();
				sprintf(buf, " %6.3f %6.3f %6.3f", double(vec.x()), double(vec.y()), double(vec.z()));
				break;
			}
			case 't':
			{
				chint32 lTime = chint32(::GetMessageTime() + m_dTimeOffset);
				sprintf(buf, " %ld", lTime);
				break;
			}
			case 'o':
			{
				float angle;
				pWnd->GetCameraControl()->GetOrientation(vec, angle);
				sprintf(buf, " %6.3f %6.3f %6.3f %6.3f", double(vec.x()), double(vec.y()), double(vec.z()), double(angle));
				break;
			}
			#if 1
			case 'v':
			{
				pWnd->GetVelocity(vec);
				sprintf(buf, " %6.3f %6.3f %6.3f", double(vec.x()), double(vec.y()), double(vec.z()));
				break;
			}
			case 's':
			{
				float angle;
				pWnd->GetAngularVelocity(vec, angle);
				sprintf(buf, " %6.3f %6.3f %6.3f %6.3f", double(vec.x()), double(vec.y()), double(vec.z()), double(angle));
				break;
			}
			#endif
		}
		command += buf;
	}
	command += "\"";
}

bool ChMazeMainInfo::OnCameraChange(int efChanged)
{
	return true;
}

/*----------------------------------------------------------------------------
	ChMazeMainInfo protected methods
----------------------------------------------------------------------------*/

void ChMazeMainInfo::ReadPreferences()
{
	GetSettings()->ReadPreferences( "", "", GR_PREFS_GROUP );
}

void ChMazeMainInfo::UpdatePreferences( bool boolMoveVector,
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
										 )
{
	GetSettings()->UpdatePreferences( boolMoveVector,
										boolScaleTextures,
										renderQuality,
										moveRenderQuality,
										fHeadlight,
										#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
										iAsciiTextQuality,
										boolCollisionAlarm        
										#else
										1 
										#endif
										);	// 
	GetView()->GetRenderContext()->SetDirty();
	GetView()->Invalidate(false);
}

void ChMazeMainInfo::OnParseComplete(string &strURL, chparam data)
{
	ChGraphicDocumentHTTPReq*pReq = (ChGraphicDocumentHTTPReq*)data;
	DoQueuedCommands(pReq);

	// Now notify the mud, if requested
	int iOptions = pReq->GetNotificationOption();
	if(iOptions & ChGraphicDocumentHTTPReq::parsed)
	{
		string command;

		command.Format("xch_cmd=\"PUEBLOMOVE %s %s \"", "parsed", strURL);
		NotifyAnchor(command);

	}
}

void ChMazeMainInfo::OnLoadInitiated(string &strURL)
{
	#if defined(CH_VRML_EVENTS)
	SetupPositionNotification("");
	#endif
};

#if defined( CH_MSW ) && defined( CH_ARCH_16 )

CH_INTERN_FUNC( void )
TrimLeft( string& strWork )
{                               
	int nDataLength = strWork.GetLength();
	// find first non-space character
	char* pstrBuf = strWork.GetBuffer( nDataLength );
	char* pstrStart = pstrBuf;
	while ( isspace(*pstrBuf) )
		pstrBuf = pstrBuf++;

	// fix up data and length
	nDataLength = nDataLength - (pstrBuf - pstrStart);
	ChMemMove( pstrStart, pstrBuf, nDataLength + 1); 
	
	strWork.ReleaseBuffer();
	
}

CH_INTERN_FUNC( void )
TrimRight( string& strWork )
{
	int nDataLength = strWork.GetLength();
	char* pstrBuf = strWork.GetBuffer( nDataLength );
	char* pstrLast = NULL;

	while (*pstrBuf != '\0')
	{
		if ( isspace(*pstrBuf))
		{
			if (pstrLast == NULL)
				pstrLast = pstrBuf;
		}
		else
			pstrLast = NULL;
		pstrBuf = pstrBuf++;
	}

	if (pstrLast != NULL)
	{
		// truncate at trailing space start
		*pstrLast = '\0';
	}
	strWork.ReleaseBuffer();
}

#endif // defined( CH_MSW ) && defined( CH_ARCH_16 )


/*----------------------------------------------------------------------------
	ChMazeMainInfo handlers
----------------------------------------------------------------------------*/

CH_IMPLEMENT_MESSAGE_HANDLER( mazeInitHandler )
{
	ChMazeMainInfo*	pInfo = (ChMazeMainInfo*)pMainInfo;

	pInfo->Initialize();
	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( mazeLoadCompleteHandler )
{
	ChLoadCompleteMsg*	pMsg = (ChLoadCompleteMsg*)&msg;
	string				strURL;
	string				strFilename;
	chparam				userData;
	ChMazeMainInfo*	pInfo = (ChMazeMainInfo*)pMainInfo;
	string				strModuleName;
	ChModuleID			idModule;
										// Get message params

	pMsg->GetParams( strModuleName, idModule, strFilename, userData );

	if ("" == strModuleName)
	{										// Not a module, must be data
		pMsg->GetParams( strURL, strFilename, userData );

		ChGraphicHTTPReq *pHTTPReq	 = (ChGraphicHTTPReq *)userData;

		TRACE( "MESSAGE:  CH_MSG_LOAD_COMPLETE (core)\n" );
		TRACE1( "         %s ->\n", (const char*)strURL );
		TRACE1( "         %s\n", (const char*)strFilename );

		switch(pHTTPReq->GetType())
		{
			case ChGraphicHTTPReq::scene:
			{
				// shouldn't be here anymore
				break;
			}
			case ChGraphicHTTPReq::texture:
			{
				TRACE( "We should not be coming here !!!\n" );
				ASSERT( 0 );

				#if 0
												// Load a texture
	 			ChMazeTextureHTTPReq *pReq = (ChMazeTextureHTTPReq *)pHTTPReq;

				void* pData = pMsg->GetNotifyData();

				if(pReq->GetPage() == pInfo->GetView()->GetCurrentPage())
				{
											/* Get the type of graphics file
												(BMP, GIF, JPEG etc.) */

					string	strType = pMsg->GetType();

					pReq->SetTextureType( ChHTTPConn::GetMimeType( strType ) );

					pReq->Load(strFilename, pData, pInfo);

				}
				else
				{	// delete the textures created by our stream handler
					#if defined(CH_USE_3DR)
	#pragma message("3DR textures leak")
					#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
					delete (ChRLImage*)pData;
					#endif
						
				}
				delete pReq;  // it's done
				#endif // 0

				break;
			}
			case ChGraphicHTTPReq::wwwInline:
			{
				TRACE( "We should not be coming here !!!\n" );
				ASSERT( 0 );

				#if 0
												// Load the background
	 			ChMazeInlineHTTPReq *pReq = (ChMazeInlineHTTPReq *)pHTTPReq;

				if(pReq->GetPage() == pInfo->GetView()->GetCurrentPage())
				{
											/* Get the type of graphics file
												(better be VRML!) */

					string	strType = pMsg->GetType();

					pReq->SetFileType( ChHTTPConn::GetMimeType( strType ) );
					// load the file
 					pReq->Load(strFilename, strURL, pInfo);

				}
				delete pReq;  // it's done
				#endif // 0

				break;
			}
			default:
				break;
		}
	}

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( mazeLoadErrorHandler )
{
	ChLoadErrorMsg*		pMsg = (ChLoadErrorMsg*)&msg;
	string				strModuleName;
	ChModuleID			idModule;
	string				strURL;
	string				strError;
	chint32				lError;
	chparam				userData;
	ChMazeMainInfo*		pInfo = (ChMazeMainInfo*)pMainInfo;

	pMsg->GetParams( strModuleName, idModule, strURL, lError, userData, strError );
	ChGraphicHTTPReq *pHTTPReq	 = (ChGraphicHTTPReq *)userData;

	// Send to trace window

	ChGraphicHTTPReq::type eType = pHTTPReq->GetType();

	string strType;
	if(eType == ChGraphicHTTPReq::texture)
	{
		strType = "texture file ";

	}
	else if(eType == ChGraphicHTTPReq::wwwInline)
	{
		strType = "WWWInline ";
		((ChQvWWWInlineRenderData*)(((ChMazeInlineHTTPReq*)pHTTPReq)->GetInlineNode()->GetRenderData()))->SetReq(0);
	}

	string strMsg;
	if(strError.IsEmpty())
	{
		strMsg.Format("URL load for %s%s failed: Error number %ld\n", LPCTSTR(strType), LPCTSTR(strURL), lError);
	}
	else
	{
		strMsg.Format("URL load for %s%s failed: %s\n", LPCTSTR(strType), LPCTSTR(strURL), LPCTSTR(strError));
	}																	 
	pInfo->GetCore()->Trace( strMsg, ChCore::traceErrors, true );
											// Clean up
	if (pInfo->GetLeafDependent() == pHTTPReq)
	{
		pInfo->SetLeafDependent( 0 );
	}
	delete pHTTPReq;
	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( mazeLoadSceneHandler )
{
	ChMazeMainInfo*	pInfo = (ChMazeMainInfo*)pMainInfo;
	ChSceneMsg *pMsg = (ChSceneMsg *)&msg;

	string strURL, strFilename, strType;
	bool	boolNew;
	chparam data;
	pInfo->SetupPositionNotification("");		// New scene, reset notification
	pMsg->GetParams(strURL, strFilename, strType, boolNew, data);

	//if(!strFilename.IsEmpty())
	{
								 		// Load a file of vrml
		pInfo->GetView()->LoadScene( strURL, strFilename, data );
	}
	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( mazeImageHookHandler )
{
	ChMazeMainInfo*	pInfo = (ChMazeMainInfo*)pMainInfo;

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
	{								// Do it
		pInfo->DoCommand( strArgs );
	}

	return 0;
}


#if !defined( CH_PUEBLO_PLUGIN )

CH_IMPLEMENT_MESSAGE_HANDLER( mazeGetPageCountHandler )
{
	ChMazeMainInfo*		pInfo = (ChMazeMainInfo*)pMainInfo;
	ChGetPageCountMsg*	pMsg = (ChGetPageCountMsg*)&msg;
	ChPageType			type;
	int					iPageCount;

	pMsg->GetParams( type );

	switch( type )
	{
		case pagePreferences:
		{
			iPageCount = 1;
			break;
		}

		default:
		{
			iPageCount = 0;
			break;
		}
	}

	return iPageCount;
}


CH_IMPLEMENT_MESSAGE_HANDLER( mazeGetPagesHandler )
{
	ChMazeMainInfo*		pInfo = (ChMazeMainInfo*)pMainInfo;
	ChGetPagesMsg*		pMsg = (ChGetPagesMsg*)&msg;
	ChPageType			type;
	chint16				sCount;
	chparam*			pPages;

	pMsg->GetParams( type, sCount, pPages );

	switch( type )
	{
		case pagePreferences:
		{
			ASSERT( 1 == sCount );

			#if defined( CH_MSW )
			{
				ChVrmlSettings *pSettings = pInfo->GetSettings();

				#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
				ChMazeRlabPrefPage*		pPage;
				pPage = new ChMazeRlabPrefPage;
				ASSERT( pPage );

				pPage->SetInitialPreferences( 	pSettings->GetAsciiTextQuality(),
												pSettings->GetCollisionAlarm(),
												pSettings->GetMoveVector(),
												pSettings->GetHeadlightBrightness() );

				#else

				ChMazePrefPage*		pPage;
				pPage = new ChMazePrefPage;
				ASSERT( pPage );

				pPage->SetInitialPreferences( pSettings->GetRenderQuality(),
												pSettings->GetMoveRenderQuality(),
												pSettings->GetMoveVector(),
												pSettings->GetScaleTextures(),
												pSettings->GetHeadlightBrightness() );
				#endif

				pPages[0] = (chparam)pPage;
			}
			#endif
			break;
		}

		default:
		{
			break;
		}
	}

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( mazeGetPageDataHandler )
{
	ChMazeMainInfo*		pInfo = (ChMazeMainInfo*)pMainInfo;
	ChGetPageDataMsg*	pMsg = (ChGetPageDataMsg*)&msg;
	ChPageType			type;
	chint16				sCount;
	chparam*			pPages;

	pMsg->GetParams( type, sCount, pPages );

	switch( type )
	{
		case pagePreferences:
		{
			ASSERT( 1 == sCount );

			#if defined( CH_MSW )
			{
				if (pPages[0])
				{
					#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
					ChMazeRlabPrefPage*	pPage = (ChMazeRlabPrefPage*)pPages[0];
					#else
					ChMazePrefPage*	pPage = (ChMazePrefPage*)pPages[0];
					#endif

					pPage->OnCommit();
											/*  Update your render level */

					pInfo->UpdatePreferences( pPage->GetMovingVector(),
												pPage->GetScaleTextures(),
												pPage->GetRenderLevel(),
												pPage->GetMoveRenderLevel(),
												pPage->GetHeadlightBrightness(),
												#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
												pPage->GetAsciiTextQuality(),
												pPage->GetCollisionAlarm()
												#else
												1
												#endif
												 );
				}
			}
			#endif	// defined( CH_MSW )
			break;
		}

		default:
		{
			break;
		}
	}

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( mazeReleasePagesHandler )
{
	ChReleasePagesMsg*	pMsg = (ChReleasePagesMsg*)&msg;
	ChPageType			type;
	chint16				sCount;
	chparam*			pPages;

	pMsg->GetParams( type, sCount, pPages );

	switch( type )
	{
		case pagePreferences:
		{
			ASSERT( 1 == sCount );

			#if defined( CH_MSW )
			{
				if (pPages[0])
				{
					ChMazePrefPage*	pPage = (ChMazePrefPage*)pPages[0];

					delete pPage;
				}
			}
			#endif	// defined( CH_MSW )
			break;
		}

		default:
		{
			break;
		}
	}

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( mazePlayGraphicHandler )
{
	ChMazeMainInfo*		pInfo = (ChMazeMainInfo*)pMainInfo;
	ChPlayGraphicMsg*		pMsg = (ChPlayGraphicMsg*)&msg;
	chuint32				luId = 0;
	bool					boolPlay = true;
	ChPlayGraphicMsg::type	when;

	pMsg->GetParams( luId, boolPlay, when );
	// Ignores everything but boolPlay
	if (!luId)
	{
		pInfo->GetView()->GetRenderContext()->Animate( boolPlay );
		if(boolPlay) pInfo->GetView()->GetRenderContext()->SetDirty();	// won't start unless dirty
	}

	return 0;
}
#endif // #if !defined( CH_PUEBLO_PLUGIN )



/*----------------------------------------------------------------------------
	Chaco menu handlers
----------------------------------------------------------------------------*/

CH_IMPLEMENT_MESSAGE_HANDLER( graphicsViewMenuHandler )
{
	chparam		retVal = 0;

	return retVal;
}
