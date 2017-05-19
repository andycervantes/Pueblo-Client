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

	Implementation for the ChGraphicMaze class, which is used to display VRML.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChMaze.cpp,v 2.148 1996/09/20 20:46:20 jimd Exp $

#include "grheader.h"

#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN ) && !defined( CH_PUEBLO_PLUGIN )
#include "resource.h"
#else
#include "vwrres.h"
#endif

#include <ChReg.h>

#include <ChURLMap.h>

#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
#include <ChCore.h>
#include "ChGrMod.h"
#endif
#include <ChHTTP.h>
#include <ChUtil.h>



#include <QvNode.h>
#include <QvState.h>
#include <QvReadError.h>
#include <QvChildList.h>

#include <fstream.h>
#include <strstrea.h>

#include "ChMaze.h"
#include "ChMazCam.h"
#include "CvHitTst.h"
#include "ChQvPars.h"
#include "ChGrStrm.h"
#include "ChRenderData.h"
#include "ChMazDep.h"

// Change to real one when ready for scout version
#if defined(CH_VRML_EVENTS)	 && !defined( CH_VRML_PLUGIN )
#include "ChStubBrowser.h"
#endif

#include "ChVrmlTransition.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

#define NOT_IMPLEMENTED	TRACE2("Function not implemented, file %s: line %s.", __FILE__, __LINE__)


/*----------------------------------------------------------------------------
	Key map constants
----------------------------------------------------------------------------*/

#define ACTION_FORWARD		"Forward"
#define ACTION_BACKWARD		"Backward"
#define ACTION_LEFT			"Left"
#define ACTION_RIGHT		"Right"
#define ACTION_UP			"Up"
#define ACTION_DOWN			"Down"
#define ACTION_TURN_LEFT	"Turn left"
#define ACTION_TURN_RIGHT	"Turn right"
#define ACTION_TURN_UP		"Turn up"
#define ACTION_TURN_DOWN	"Turn down"
#define ACTION_ROLL_LEFT	"Roll left"
#define ACTION_ROLL_RIGHT	"Roll right"
#define ACTION_GO_FASTER	"Faster"
#define ACTION_GO_SLOWER	"Slower"


#define  ACTION_WALK			"Walk Mode"
#define  ACTION_FLY				"Fly Mode"
#define  ACTION_EXAMINE			"Examine Mode"
#define  ACTION_BRIGHTER		"Brighter"
#define  ACTION_DIMMER			"Dimmer"
#define  ACTION_NEXT_CAMERA		"Next Camera"
#define  ACTION_PREV_CAMERA		"Prev Camera"
#define  ACTION_RESET_CAMERA	"Reset Camera"

#define  KEY_WALK		'W'
#define  KEY_FLY		'F'
#define  KEY_EXAMINE	'E'
#define  KEY_BRIGHTER	'B'
#define  KEY_DIMMER		'D'
#define  KEY_RESET_CAMERA		VK_HOME


#define ACTION_MOD_SHIFT	(1L << 0)
#define ACTION_MOD_CONTROL	(1L << 1)

const int defStepsPerWorld = 100;
const int defMoveAmount = 10;	// obsolete
const float defUserSpeed = 1;
const float minUserSpeed = .1;
const float maxUserSpeed = 10.;

int		ChMazeWnd::m_iObjectCount = 0;


/*----------------------------------------------------------------------------
	Action enum
----------------------------------------------------------------------------*/

typedef enum {	walkMode = 1, flyMode, examineMode, beBrighter, beDimmer, 
				goNextCamera, goPrevCamera, goFaster, goSlower, resetCamera } KeyAction;




/*----------------------------------------------------------------------------
	ChMazeWnd class
----------------------------------------------------------------------------*/


#if defined(CH_VRML_VIEWER)	

#undef new

IMPLEMENT_DYNCREATE( ChMazeWnd, ChGraphicView )

#endif

#if defined(CH_VRML_VIEWER)	|| defined(CH_VRML_PLUGIN )

ChMazeWnd::ChMazeWnd() :
				m_pHttpConn( 0 ),
				m_pSettings( 0 ),
				ChGraphicView(),
				m_pGraphicStream(0),
#else
ChMazeWnd::ChMazeWnd( ChMazeMainInfo *pInfo, ChVrmlSettings *pSettings ) :
				ChGraphicView( pInfo ),
				m_pSettings(pSettings),
#endif
				m_pRoot( 0 ),
				m_pCameraControl( 0 ),
				m_pBounds(0),
				m_fUserSpeedFactor(defUserSpeed),
				m_boolInMouseAnchor( false ),
				m_boolInMouseMove( false ),
				m_boolMoving(false),
				m_sCrosshairHalfWidth( 20 ),
				m_sCrosshairHalfHeight( 20 ),
				m_pageCount (0),
				m_uiMoveTimer( 0 ),
				m_uiTickTimer( 0 ),
				m_pAnchor( 0 ),
				m_hParseThreadEvent( 0 ),
				m_boolMouseMove(false),
				#if defined(CH_VRML_EVENTS)	 && !defined( CH_VRML_PLUGIN )
				m_pVrmlBrowser(0),
				#endif
				m_pScoutMenu( 0 ),
				m_hCameraMenu(0)
{

	m_iObjectCount++;  // Total number of maze objects

	m_pCameraControl = new ChMazeCameraControl( this );

	m_keyMap.AddItem( KEY_WALK, ACTION_MOD_CONTROL, ACTION_WALK, walkMode );
	m_keyMap.AddItem( KEY_FLY, ACTION_MOD_CONTROL, ACTION_FLY, flyMode );
	m_keyMap.AddItem( KEY_EXAMINE, ACTION_MOD_CONTROL, ACTION_EXAMINE, examineMode );
	m_keyMap.AddItem( KEY_BRIGHTER, ACTION_MOD_CONTROL, ACTION_BRIGHTER, beBrighter );
	m_keyMap.AddItem( KEY_DIMMER, ACTION_MOD_CONTROL, ACTION_DIMMER, beDimmer );

	m_keyMap.AddItem( VK_ADD, 0, ACTION_GO_FASTER, goFaster );
	m_keyMap.AddItem( VK_SUBTRACT, 0, ACTION_GO_SLOWER, goSlower );

	m_keyMap.AddItem( VK_NEXT, 0, ACTION_NEXT_CAMERA, goNextCamera );
	m_keyMap.AddItem( VK_PRIOR, 0, ACTION_PREV_CAMERA, goPrevCamera );
	m_keyMap.AddItem( KEY_RESET_CAMERA, 0, ACTION_RESET_CAMERA, resetCamera );

	#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN ) && !defined(CH_PUEBLO_PLUGIN )
	if ( ChUtil::GetSystemType() == CH_SYS_WIN32S || 	
				ChUtil::GetSystemType() == CH_SYS_WIN3X ) 
	{
		m_hAnchorCursor = ::LoadCursor( ChGraphicsDLL.hModule,
												MAKEINTRESOURCE( IDC_HANDMONO ));
	}
	else
	{
		m_hAnchorCursor = ::LoadCursor( ChGraphicsDLL.hModule,
												MAKEINTRESOURCE( IDC_PICKER ));
	}
	#else
		#if defined(CH_VRML_VIEWER) 
		if ( ChUtil::GetSystemType() == CH_SYS_WIN32S || 	
					ChUtil::GetSystemType() == CH_SYS_WIN3X ) 
		{

			m_hAnchorCursor = ::LoadCursor( AfxGetResourceHandle(),
													MAKEINTRESOURCE( IDC_HANDMONO ));
		}
		else
		{
			m_hAnchorCursor = ::LoadCursor( AfxGetResourceHandle(),
													MAKEINTRESOURCE( IDC_PICKER ));
		}
		#else
		if ( ChUtil::GetSystemType() == CH_SYS_WIN32S || 	
					ChUtil::GetSystemType() == CH_SYS_WIN3X ) 
		{

			m_hAnchorCursor = ::LoadCursor( AfxGetInstanceHandle(),
													MAKEINTRESOURCE( IDC_HANDMONO ));
		}
		else
		{
			m_hAnchorCursor = ::LoadCursor( AfxGetInstanceHandle(),
													MAKEINTRESOURCE( IDC_PICKER ));
		}
		#endif
	#endif
	m_hCursor = ::LoadCursor( NULL, IDC_ARROW );


	m_pNavigators[walk] = new  ChVrmlWalkSTM(this);
	m_pNavigators[fly] = new  ChVrmlFlySTM(this);
	m_pNavigators[examine] = new  ChVrmlExaminerSTM(this);

}


ChMazeWnd::~ChMazeWnd()
{
	
	m_iObjectCount--; // Total number of Maze objects

	delete m_pNavigators[walk];
	delete m_pNavigators[fly];
	delete m_pNavigators[examine];

	if ( m_pScoutMenu )
	{
		delete m_pScoutMenu;
	}

	if (0 != m_pCameraControl)
	{
		delete m_pCameraControl;
	}
	ClearAnchors();
	delete m_pBounds;
	m_pBounds = 0;

	if( m_hParseThreadEvent )
	{
		::CloseHandle( m_hParseThreadEvent );
		m_hParseThreadEvent = 0;
		::DeleteCriticalSection( &m_syncParser );

	}

	#if defined(CH_VRML_EVENTS)	 && !defined( CH_VRML_PLUGIN )
	delete m_pVrmlBrowser;
	#endif

	// Cleanup HTTP Stream
	#if defined(CH_VRML_VIEWER)	|| defined(CH_VRML_PLUGIN )
	GetHTTPConn()->SetStreamMgr(m_pGraphicStream->GetNextStreamMgr());
	delete m_pGraphicStream;
	#endif

}


#if defined(CH_VRML_VIEWER)	 || defined(CH_VRML_PLUGIN )
void ChMazeWnd::InitMazeView( ChHTTPConn *httpConn, ChVrmlSettings *pSettings  )
{
	m_pHttpConn = httpConn;
	m_pSettings = pSettings;

 	m_pGraphicStream = new ChGraphicStreamManager( GetHTTPConn()->GetStreamMgr() ); 
	ASSERT( m_pGraphicStream );
	GetHTTPConn()->SetStreamMgr( m_pGraphicStream );
}
#endif

// Added by VSP : Cleanup QV on exit
void ChMazeWnd::TermMazeWnd()
{ 	 
	if ( 0 == m_iObjectCount )
	{
		QvDB::term(); 
	}
}


BEGIN_MESSAGE_MAP(ChMazeWnd, ChGraphicView)
	//{{AFX_MSG_MAP(ChMazeWnd)
	ON_WM_SIZE()
	ON_WM_CHAR()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_SETCURSOR()
	ON_WM_PAINT()
	ON_COMMAND(IDM_CAMERA_NEXT, OnCameraNext)
	ON_COMMAND(IDM_CAMERA_PREV, OnCameraPrev)
	ON_COMMAND(ID_OPT_RESET_SPEED, OnOptResetSpeed)
	ON_COMMAND(IDM_OPTIMIZE_BETTER, OnOptimizeBetter)
	ON_COMMAND(IDM_OPTIMIZE_FASTER, OnOptimizeFaster)
    ON_WM_PALETTECHANGED()
    ON_WM_QUERYNEWPALETTE()
	ON_COMMAND(IDM_COLLISION_CHECKING, OnCollisionChecking)
	//}}AFX_MSG_MAP
	ON_WM_SYSKEYDOWN()
	ON_WM_SYSKEYUP()
	ON_MESSAGE( WM_VRML_PREF_CHANGE, OnPrefChange )
	ON_MESSAGE( WM_VRML_PROGRESS, OnProgressMsg )
	ON_MESSAGE( WM_VRML_PARSE_ERROR, OnParseError)
	ON_MESSAGE( WM_VRML_PARSE_DONE, OnParseComplete )
	ON_MESSAGE( WM_VRML_LOAD_TEXTURE, OnLoadTexture )
	ON_MESSAGE( WM_VRML_EVENT, OnVrmlEvent )
	ON_MESSAGE( WM_VRML_ACTIVATE, OnActivateWnd )
	ON_MESSAGE( WM_VRML_MAZE_ERROR, OnMazeError)

	ON_COMMAND(ID_OPT_HEADLIGHT_SWITCH, OnHeadlightSwitch)
	ON_COMMAND(ID_VIEW_RESET_CAMERA, OnResetCamera)
	ON_COMMAND(IDM_BRIGHTEN, OnBrighten)
	ON_COMMAND(IDM_DIMMER, OnDimmer)
	ON_COMMAND(IDM_EXAMINE, OnExamine)
	ON_COMMAND(IDM_FLY, OnFly)
	ON_COMMAND(IDM_WALK, OnWalk)
	ON_WM_INITMENUPOPUP()
	ON_COMMAND_RANGE(IDM_CAMERA_FIRST, IDM_CAMERA_LAST, OnCameraMenuCommand)
	ON_UPDATE_COMMAND_UI_RANGE(IDM_CAMERA_FIRST, IDM_CAMERA_LAST, OnCameraMenuUpdateCommand)

END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChMazeWnd drawing
----------------------------------------------------------------------------*/

void ChMazeWnd::OnInitialUpdate()
{
	ChGraphicView::OnInitialUpdate();

	#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
	CSize sizeTotal;
	// TODO: calculate the total size of this view	MAKE THE BARS GO AWAY _ HACK
	sizeTotal.cx = sizeTotal.cy = 1;
	SetScrollSizes(sizeTotal);
	#endif
}
#if 0
bool ChMazeWnd::LoadBackground( const string & strURL )
{

    if (!m_dibBkgnd.Load((char *)(LPCTSTR(strURL)))) {
        return false;
    }

    // Create a new buffer
    // and palette

   // m_spriteList.m_NotifyObj.SetView(this);
    NewBackground(&m_dibBkgnd);
	return true;
}
#endif
void ChMazeWnd::OnPaletteChanged(CWnd* pFocusWnd)
{
											/* See if the change was caused by
												us and ignore it if so */
    if (pFocusWnd != this)
    {
		#if 0
	        //OnQueryNewPalette();	// ????????????????????????
		#else
		{									/* Prevent background technicolor.
												3dr takes care of foreground
												querynewpalette */
	        CDC*	pDC = GetDC();
	        UINT	u = pDC->RealizePalette();

	        ReleaseDC( pDC );

			GetRenderContext()->SetDirty();
	        InvalidateRect( 0, false );		// Repaint the lot
		}
		#endif
    }
}


// Note: Windows actually ignores the return value.
BOOL ChMazeWnd::OnQueryNewPalette()
{
//R3dApplyNewPalette(	m_RC.GetRC());

    return false; // Say we did nothing.
    // We are going active so realize our palette.
    //if (m_pPal)
    {
        CDC* pdc = GetDC();
        //CPalette* poldpal = pdc->SelectPalette(m_pPal, false);
        UINT u = pdc->RealizePalette(); // ??????????????????????
        ReleaseDC(pdc);
        if (u != 0) {
            // Some colors changed so we need to do a repaint.
            return true; // Say we did something.
        }
    }
	
	GetRenderContext()->SetDirty();
	InvalidateRect(0, false); // Repaint the lot.	 not fast, but better than technicolor

    return false; // Say we did nothing.
}


bool ChMazeWnd::Create( const CRect& rtView, CWnd* pParent, DWORD dwStyle,
						UINT uiID )
{
	bool	boolSuccess;

	boolSuccess = ChGraphicView::Create( rtView, pParent, dwStyle, uiID );
	if (boolSuccess)
	{
		/* set up our 3dr rc and gc; assumes we have CS_OWNDC*/

		SetupContexts();
	}

	return boolSuccess;
}

void ChMazeWnd::SetupContexts()
{
	if(!m_RC.GetRC())
	{
		m_RC.Init( this, GetDC() );
	}
}


void ChMazeWnd::SetGlobalHints()
{
	ChQvGlobalSearchState	state( this );

	SetupContexts();
	m_pRoot->traverse( &state );

	m_fAspect = state.GetAspect();
	m_backGroundColor = state.GetBackground();
	m_boolLightOn = state.GetLightOn();
	
	#if 0
	m_sceneViewerMode = state.GetViewerMode();
	m_sceneCollisionMode = state.GetCollisionMode();	
	#endif

	if(state.GetViewerMode() != none)	   // will be invalid if not spec'd in file
	{
		GetSettings()->SetViewerMode(state.GetViewerMode());
	}

	if(state.GetCollisionMode() != invalidCollisionMode)
	{
		GetSettings()->SetCollisionMode(state.GetCollisionMode());
	}

	if(!m_boolLightOn && !IsHeadlightOn()) SetHeadlight(true);	// Force headlight on if no scene light
}


void ChMazeWnd::SetupTreeDefaults()
{
	SetupContexts();
	GetRenderContext()->NewDefaultCamera()->SetCurrentCamera();
}



void ChMazeWnd::Draw( CDC* pDC, RECT* pRect )
{
    CDC*	pUseDC;

	#if defined( CH_USE_3DR )
	if(!m_RC.IsDirty()) return;

    CRect	rcDraw;

	SetupContexts();
	ClearAnchors();
    										/* Make sure we have what we need
    											to do a paint */
    if (!m_pRoot)
    {
        return;
    }
    #endif
    										/* See if a DC was supplied, and
    											get one if not */
    if (pDC)
    {
		pUseDC = pDC;
    }
    else
    {
		pUseDC = GetDC();

		#if !defined( CH_VRML_PLUGIN )
		ChViewBaseClass::OnPrepareDC( pUseDC );	// jwd
		#endif
    }
	#if defined( CH_USE_3DR )
    										/* See if a clip rect was supplied,
    											and use the client area if not */
    if (pRect)
    {
		rcDraw = *pRect;					// this is in logicals; jwd
    }
    else
    {
		GetClientRect( rcDraw );
		pUseDC->DPtoLP( LPRECT( rcDraw ) );	// fixed scrolling bug; jwd
    }

	pUseDC->RealizePalette();				// ???

	{
		CRect		rcClient;

        GetClientRect( rcClient );

		if ((rcClient.bottom > 1) && (rcClient.right > 1))
		{
			// make 3dr contexts for our dc
			// this is all moved to create
			//m_hRC = R3dCreateRC((DWORD)(pDC->GetSafeHdc()), R3D_RI_DOUBLE_BUFFER /*R3D_RI_DEFAULT*/);

	        //R3dSetState( m_hRC, R3D_STA_ENABLES, R3D_SE_Z_BUFFERING);
	        //R3dSetState( m_hRC, R3D_STA_DISABLES, R3D_SE_CLIPPING);

			//m_hGC = G3dCreateGC( m_hRC);

			Fixed32_t		on = 1;
			Fixed32_t		off = 0;
			ChShadingLevel	userShadingPref;

	        G3dSetState( m_RC.GetGC(), G3DL_FRONT_CCW, &off);

			// Init the rendering context or whatever

			G3dSetWindowSize(m_RC.GetGC(), Float_t(rcClient.right), Float_t(rcClient.bottom));

			R3dSetState( m_RC.GetRC(), R3D_STA_BG_COLOR, GetBackgroundColorL());  // use the hint

											// Set the shading appropriately
			if (IsMoving())
			{

				userShadingPref = GetSettings()->GetMoveRenderQuality();
			}
			else
			{
				userShadingPref = GetSettings()->GetRenderQuality();
			}
			m_RC.SetShadingPref(userShadingPref);
			

			R3dClearBuffers( m_RC.GetRC(),
								R3D_CI_DRAW_BUFFER | R3D_CI_ZBUFFER );
			G3dClearStack( m_RC.GetGC() );
											/* Turn off texturing except when
												we encounter one; then do it at
												draw prim time */

			R3dSetState( m_RC.GetRC(), R3D_STA_DISABLES, R3D_SE_TEXTURING );
			R3dSetState( m_RC.GetRC(), R3D_STA_TEX_ID, (Dword_t)(0) );
			R3dSetState( m_RC.GetRC(), R3D_STA_DISABLES, R3D_SE_MODULATION );
			G3dSetState( m_RC.GetGC(), G3DL_TEXTURE_MOD, &off );



			//ChQvState	state( this );

			TRACE( "Drawing the tree\r\n" );

			#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
			// TODO
			m_pMainInfo->StartFrameTime();
			#else
			StartFrameTime();
			#endif

	    	if (m_pRoot)
	    	{
				if(m_RC.Draw())
				{
					POINT	ptCursor;

					GetCursorPos( &ptCursor );
					ScreenToClient( &ptCursor );
					IsAnchor(ptCursor.x, ptCursor.y);		// update the status line
				}
			}

			#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
			m_pMainInfo->EndFrameTime();
			#else
			EndFrameTime();
			#endif
			R3dSwapBuffers( m_RC.GetRC(), 0 );
		}
	}
	#else
	#endif	// defined( CH_USE_3DR )

	if (IsInMouseMove())
	{
		DrawMouseMoveCrosshair( pDC );
		DrawMouseMoveVector( pDC );
	}
    										/* Release the DC if it was one
    											we created */
    if (0 == pDC)
    {
    	ReleaseDC( pUseDC );
	}
}


// Render the scene to the off-screen buffer
// pClipRect defaults to 0
void ChMazeWnd::Render(CRect* pClipRect)
{
}


bool ChMazeWnd::NotifyPaletteChange( UINT uMsg, CWnd* pFocusWnd )
{
	bool boolIsProcessed = false;

	if (IsCurrent())
	{
		switch( uMsg )
		{
			case WM_PALETTECHANGED:
			{
				OnPaletteChanged( pFocusWnd );

				//SendMessage(WM_PALETTECHANGED, WORD(pFocusWnd->GetSafeHwnd( )));
				break;
			}
			case WM_QUERYNEWPALETTE:
			{
											/* 3DR is apparently hooking the
												window with the DC passed to
												CreateRC to get this message */

				boolIsProcessed = true;
				SendMessage( WM_QUERYNEWPALETTE );
				GetRenderContext()->SetDirty();
				InvalidateRect( 0, false );
				break;
			}
		}
	}

	return boolIsProcessed;
}

void ChMazeWnd::AdjustLight(string strCmd, int iLight, float fLevel)
{
	ChQvState state(this, strCmd, iLight, fLevel);
    if(m_pRoot) m_pRoot->traverse(&state);
	GetRenderContext()->SetDirty();
	InvalidateRect(0, false);
}


void ChMazeWnd::DoNodeCommand(string& strCmd, string &strNodeVRML )
{
	// Build a new tree

	string strVRML = EncapsulateVRML(strNodeVRML);

	// make the vrml thing

	char *buf = strVRML.GetBuffer(1);
	istrstream is(buf);
	bool boolSuccess = false;
	QvDB::init();

    ChQvInput	in;
	in.setFilePointer(&is);
    QvNode	*root;

    if (QvDB::read(&in, root) && root != 0)
	{
		boolSuccess = true;
	}
    else
    {
		return ;
    }

	string strSubCmd;
	string strKey;

	ChQvState state(this, strCmd, strSubCmd, strKey, strNodeVRML, root);
    if(m_pRoot) m_pRoot->traverse(&state);
 	ChQvState defstate(this, strCmd, strSubCmd, strKey, strNodeVRML, root);
	// used to walk the default root here, but now camera is handled elsewhere
	delete root;
	GetRenderContext()->SetDirty();
	InvalidateRect(0, false);
}

bool ChMazeWnd::CheckForTrailingJunk(QvInput &in ) //, FILE *f)
{
	char ch;

	in.get( ch );

	#if 0
	while( ch  != EOF)
	{
		if(!isspace(ch))
		{
			//Trailing junk
			if(ch == '#')
			{
				while( ch  != EOF && ch != '\n' && ch != '\r') in.get(ch);	// ignore comments				
			}
			else
			{
				QvReadError::post(&in, "Trailing characters after toplevel node. (Only one toplevel node allowed.)");
				return true;
			}

		}
		else
		{
			in.get( ch );
		}
	}
	#endif	// Allow just about anything
	return false;
}

bool ChMazeWnd::LoadScene( const string &strURL, const string &strFilename, chparam data )
{

	if ( m_hParseThreadEvent == 0 && GetRenderContext()->IsThreaded() )
	{	// Create the thread event
		m_hParseThreadEvent = ::CreateEvent( 0, false, false, 0 );
		ASSERT( m_hParseThreadEvent );
		::InitializeCriticalSection( &m_syncParser );
	}

	// cancel all parse threads before we start a new thread
	AbortParsing();
	// Reset the event
	::ResetEvent( GetEndParseEvent() );

	
	ChParseInfo * pParseInfo = new ChParseInfo( this, strURL, strFilename );
	ASSERT( pParseInfo );

	pParseInfo->SetUserData2((void*)data);

	// Add it to my list of parse threads running
	AddParseInfo( pParseInfo );

	if ( !pParseInfo->ParseVrmlFile( ChParseInfo::typeScene ))
	{   // failed to initialize
		m_parseThreadList.RemoveTail( );

		delete pParseInfo;
	}

	return true;

}

bool ChMazeWnd::LoadWWWInline( const string &strURL, const string &strFilename, 
											QvWWWInline *pInlineNode )
{
	
	ChParseInfo * pParseInfo = new ChParseInfo( this, strURL, strFilename );
	ASSERT( pParseInfo );

	pParseInfo->SetUserData( pInlineNode );

	((ChQvWWWInlineRenderData*)(pInlineNode->GetRenderData()))->SetParseInfo(pParseInfo); // starting to parse
	// Serialize this
	// Add it to my list of parse threads running
	AddParseInfo( pParseInfo );

	if ( !pParseInfo->ParseVrmlFile( ChParseInfo::typeWWWInline ))
	{   // failed to initialize
		RemoveParseInfo( pParseInfo );

		delete pParseInfo;
	}

	return true;

}



#define CAMERA_CLASS	"QvPerspectiveCamera"
#define CAMERA_CLASS_ORTHO	"QvOrthographicCamera"

ChMazeWnd* ChMazeWnd::SetScene( QvNode *root )
{
	m_pRoot = root;
						/* Get the global hints from the
							tree */
	SetGlobalHints();
	SetupTreeDefaults();

	// Reset the navigators
	for(int j = 0; j < viewerModeCount; j++)
	{
		if(m_pNavigators[j])
		{
			m_pNavigators[j]->SetState(ChVrmlStateTransition::s_start);
		}
	}

	#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
	GetMainInfo()->GetCore()->AbortRequests( false, 
								GetMainInfo()->GetStream() );
	#else
	GetHTTPConn()->AbortRequests( false, GetHTTPConn()->GetStreamMgr() );
	#endif

	// Set the node count to zero
	GetRenderContext()->ResetScene();
						// Delete the old instance tree, and
						// make a new one

	ChQvBuildState bldIt(this);
	m_pRoot->traverse(&bldIt);

	// TODO !!	   fix this for trivial trees
	GetRenderContext()->SetRoot((ChQvInstance*)(bldIt.GetCurrentParent()));

		 // Compute bounds on instance tree
	
	if (!m_pBounds) m_pBounds = new ChQvBounds;
	//m_pBounds->Apply(m_pRoot, this);
	m_pBounds->Apply(GetRenderContext()->GetRoot(), GetRenderContext());

	// Set the initial camera
	ChQvQuery cameraQuery( this, CAMERA_CLASS, ChQvQuery::byClassName );
	cameraQuery.Apply( m_pRoot );
								// Try to get the camera node
	QvPerspectiveCamera* pCameraNode = (QvPerspectiveCamera*)cameraQuery.GetNode();

	if(!pCameraNode)
	{
		// No perspective camera, maybe an ortho one?
		ChQvQuery cameraQuery( this, CAMERA_CLASS_ORTHO, ChQvQuery::byClassName );
		cameraQuery.Apply( m_pRoot );
								// Try to get the camera node
		pCameraNode = (QvPerspectiveCamera*)cameraQuery.GetNode();
	}
	if(pCameraNode)
	{
		GetRenderContext()->SetCurrentCamera(pCameraNode);
		//GetRenderContext()->SetCurrentCamera(pCameraNode);	  // ????????
	}
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	else
	{
		GetRenderContext()->SetCurrentCamera();
	}
	#endif


	GetCameraControl()->Init();
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

	GetRenderContext()->StartConstruction();	// Start the actual scene building
												// in reality lab - done in 
												// another thread
	#endif
	if (!m_uiTickTimer)
	{
											// Start the timer
		m_uiTickTimer = SetTimer( moveTimerID+1, moveTimerDuration, 0 );
	}

	GetRenderContext()->SetDirty();
	Invalidate(false);

	OnLoadComplete();	// Call the UI or whoever to tell it we're loaded

	return this;
}

void ChMazeWnd::Spawn(const string & strURL)
{
	ChQvSpawnState state(this, strURL);
    if(m_pRoot) m_pRoot->traverse(&state);
	return;
}




#if defined(CH_USE_3DR)
void ChMazeWnd::AddAnchor(ChQvAnchorSensor *pAnchor)
{
	pAnchor->SetID(m_anchors.GetCount());
	m_anchors.AddTail(pAnchor);
}
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
// no need to
#else
#pragma message("Not adding/clearing anchors")
#endif

void ChMazeWnd::ClearAnchors()
{
#if defined(CH_USE_3DR)
	ChQvAnchorSensor *pAnchor;
	while(!m_anchors.IsEmpty())
	{
		pAnchor = m_anchors.RemoveHead();
		delete pAnchor;
	}
#endif
}

/*----------------------------------------------------------------------------
	ChMazeWnd Pueblo helper functions
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	ChMazeWnd static functions
----------------------------------------------------------------------------*/

string ChMazeWnd::EncapsulateVRML( string strNodeVRML )
{
	string	strBuf( "#VRML V1.0 ascii\n " );

	//strBuf += " Separator {");
	strBuf += strNodeVRML;
	//strBuf += " }";

	return strBuf;
}


/*----------------------------------------------------------------------------
	ChMazeWnd diagnostics
----------------------------------------------------------------------------*/

#if defined( _DEBUG )

void ChMazeWnd::AssertValid() const
{
	ChGraphicView::AssertValid();
}

void ChMazeWnd::Dump( CDumpContext& dc ) const
{
	ChGraphicView::Dump( dc );
}

#endif	// defined( _DEBUG )


/*----------------------------------------------------------------------------
	ChMazeWnd protected methods
----------------------------------------------------------------------------*/

bool ChMazeWnd::NewBackground( ChDib* pDIB )
{											/* Create a new buffer and
												palette to match a new
												background DIB */
    return true;
}


bool ChMazeWnd::IsAnchor( int iX, int iY, pChQvAnchorSensor &pHitAnchor )
{
	bool boolIsAnchor = false;
#if defined(CH_USE_3DR)
	if(!GetScene()) return false;
											/* X and Y are in window
												coordinates */
	G3dSetActiveStack(GetGC(), G3DT_CAM_CLIP);
	G3dPushTransform(GetGC());
	G3dSetActiveStack(GetGC(), G3DT_MODEL);
	G3dPushTransform(GetGC());
	
	// Now do the hittest on each anchor in the list. If -any- get a hit, we choose the closest.
    if (!m_anchors.IsEmpty())
    {
		float	fNearZ;
		ChQvAnchorSensor *pAnchor, *pNearAnchor = 0;

		ChPosition pos = m_anchors.GetHeadPosition();
	    while (pos) {
	        pAnchor = m_anchors.GetNext(pos);
			float fZ;
			if( pAnchor->HitTest(GetGC(), iX, iY, fZ))
			{
				if(!pNearAnchor || fZ > fNearZ)
				{
					fNearZ = fZ;
					pNearAnchor = pAnchor;
				}
			}
	    }
		if (pNearAnchor)
		{
			boolIsAnchor = true;
			QvWWWAnchor	*pAnchorNode = pNearAnchor->GetAnchorNode();
			string hint;
			pNearAnchor->GetHint(hint);

			OnHotSpot(0, hint);

			m_boolIsHintDisplayed = true;
			pHitAnchor = pNearAnchor;  
			m_hCursor = m_hAnchorCursor;
			::SetCursor(m_hAnchorCursor);
		}
		else
		{
			if(m_boolIsHintDisplayed)
			{
				string hint;

				OnHotSpot(0, hint);

				m_boolIsHintDisplayed = false;
				HCURSOR hCurs = m_hCursor = HCURSOR(GetClassLong(GetSafeHwnd(), GCL_HCURSOR));
				::SetCursor(hCurs);
			}
		}
	}


	G3dSetActiveStack(GetGC(), G3DT_CAM_CLIP);
	G3dPopTransform(GetGC());
	G3dSetActiveStack(GetGC(), G3DT_MODEL);
	G3dPopTransform(GetGC());
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	{
		// Hand it to RC; it has scene data
		GetRenderContext()->LockScene();
		boolIsAnchor = GetRenderContext()->IsAnchor(iX, iY, pHitAnchor);
		if(boolIsAnchor)
		{	
			string hint;
			pHitAnchor->GetHint(hint);

			OnHotSpot(0, hint);

			m_boolIsHintDisplayed = true;
			m_hCursor = m_hAnchorCursor;
			::SetCursor(m_hAnchorCursor);
		}
		else if(m_boolIsHintDisplayed)
		{
			string hint;

			OnHotSpot(0, hint);

			m_boolIsHintDisplayed = false;
			HCURSOR hCurs = m_hCursor = HCURSOR(GetClassLong(GetSafeHwnd(), GCL_HCURSOR));
			::SetCursor(hCurs);
		}
		GetRenderContext()->UnlockScene();
	}				

#else
#pragma message("Not testing anchors")
#endif

	
	return boolIsAnchor;
}

void ChMazeWnd::WriteStatus( UINT uMsgID )
{
	// iMessage should be > 0 for all valid messages and 0 to remove
	// any progress message. If you want to define any new message,
	// add it to the list in ChMaze.h


	// The status messages could be generated by worker threads, so
	// we post the message to the thread that created this window and
	// retrive the message and let the virtual functions to the work
	PostMessage( WM_VRML_PROGRESS, 	uMsgID );
}

void ChMazeWnd::OnHotSpot( chparam userData,
								const string& strDocURL  )
{
	#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
	GetMainInfo()->WriteStatus(strDocURL);
	#else
	#endif
}

void ChMazeWnd::StartAnchor( int iX, int iY )
{
#if defined(CH_USE_3DR)
											/* We can't be in both mouse move
												and anchor states */
	ChQvAnchorSensor		*pAnchor;

	ASSERT( !IsInMouseMove() );
	IsAnchor(iX, iY, pAnchor);			
											// Save the current anchor by   
											// making a copy of the sensor  
	m_pAnchor = new ChQvAnchorSensor(0);
	*m_pAnchor = *pAnchor;												 
	m_boolInMouseAnchor = true;
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))											 
											/* We can't be in both mouse move
												and anchor states */
	ChQvAnchorSensor		*pAnchor;

	ASSERT( !IsInMouseMove() );
	IsAnchor(iX, iY, pAnchor);			
											// Don't make a copy for rlab  
	m_pAnchor = pAnchor;												 
	m_boolInMouseAnchor = true;											 
#else
#pragma message("Not starting anchors")
#endif
}


void ChMazeWnd::UpdateAnchor( int iX, int iY )
{
	IsAnchor(iX, iY);		// update the status line
}


void ChMazeWnd::EndAnchor( int iX, int iY )
{
#if defined(CH_USE_3DR) || defined(CH_USE_RLAB) || defined(CH_USE_D3D)
	ChQvAnchorSensor		*pAnchor;

								// get the anchor currently under mouse, if any
								// and test to see if it's the one that started us
	if(IsAnchor(iX, iY, pAnchor) && pAnchor /*&& *pAnchor == *m_pAnchor*/)	   // jwd - changed to use click
	{
		//WriteStatus("Request Initiated");		// just for debugging
															// Tell my info who will tell the pane mgr
															// It's their job to notify

		string command;

		command = pAnchor->GetCommand();
		if(!command.IsEmpty())
		{
			#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
			GetMainInfo()->NotifyAnchor(command);
			#else
			GetURL(command, 0, GetCurrentURL());
			#endif
		}
	}
	else
	{
		WriteStatus( PROGRESS_MSG_0 );
		//WriteStatus("Anchor cancelled");			// just for debugging
		//TRACE("Anchor cancelled\n");			// just for debugging
	}

	#if defined(CH_USE_3DR)
	delete m_pAnchor;
	#endif
#else
#pragma message("Not ending anchors")
#endif
	m_boolInMouseAnchor = false;
	m_pAnchor = 0;
}

/* Reset camera to starting location */
ChMazeWnd* ChMazeWnd::ResetCamera()
{
	GetSceneNavigator()->SetState(ChVrmlStateTransition::s_start);
	GetCameraControl()->Reset();
	return this;
}

void ChMazeWnd::StartMouseMove( int iX, int iY )
{
	CDC*	pDC;
											/* We can't be in both mouse move
												and anchor states */
	// -- ASSERT( !IsInMouseAnchor() );
											// Set flag for state
	m_boolInMouseMove = true;
											// Set flag for rendering
	SetMoving( true );
											// Save initial mouse pos
	m_ptMouseStart.x = iX;
	m_ptMouseStart.y = iY;
	m_ptLastMouse = m_ptMouse = m_ptMouseStart;

											// Draw crosshair
	pDC = GetDC();

	DrawMouseMoveCrosshair( pDC );
	DrawMouseMoveVector( pDC );

	ReleaseDC( pDC );
											// Start the timer

	m_uiMoveTimer = SetTimer( moveTimerID, moveTimerDuration, 0 );
}


void ChMazeWnd::UpdateMouseMove( int iX, int iY )
{
	float	fVertMove;
	float	fHorzMove;
	bool	boolShift;
	bool	boolControl;
	bool	boolMoved;

	if (GetSettings()->GetViewerMode() != examine)
	{
		if ((m_ptMouseStart.x != iX) || (m_ptMouseStart.y != iY))
		{
			m_ptLastMouse = m_ptMouse;
			m_ptMouse.x = iX;
			m_ptMouse.y = iY;

			boolShift = !!(GetKeyState( VK_SHIFT ) & 0x8000);
			boolControl = !!(GetKeyState( VK_CONTROL ) & 0x8000);

			fHorzMove = CalcMouseHorzMove();
			fVertMove = CalcMouseVertMove();

			if (!boolShift && !boolControl)		// No modifiers
			{
				GetCameraControl()->MoveForward( CalcAccel( fVertMove ), false );
				GetCameraControl()->Yaw( fHorzMove );

				boolMoved = true;
			}
			else if (boolShift && !boolControl)	// Shift key only
			{
				GetCameraControl()->MoveUp( CalcAccel( fVertMove ), false );
				GetCameraControl()->MoveLeft( CalcAccel( fHorzMove ) );

				boolMoved = true;
			}
			else if (!boolShift && boolControl)	// Control key only
			{
				GetCameraControl()->Roll( -CalcAccel( fHorzMove ), false );	// It will disable if walking
				GetCameraControl()->Pitch( fVertMove );

				boolMoved = true;
			}
			else								// Shift and Control
			{
				boolMoved = false;
			}
		}
	}
	else
	{
		if ((m_ptLastMouse.x != iX) || (m_ptLastMouse.y != iY))
		{
			m_ptMouse.x = iX;
			m_ptMouse.y = iY;
			RECT r;

			GetClientRect(&r);
			GetCameraControl()->RotateBall(m_ptLastMouse, m_ptMouse, r.bottom - r.top);	

			boolMoved = true;
			m_ptLastMouse = m_ptMouse;
		}
	}
}


void ChMazeWnd::EndMouseMove( int iX, int iY )
{
											// Clear flag for state
	m_boolInMouseMove = false;
											// Clear flag for rendering
	SetMoving( false );

	GetRenderContext()->SetDirty();
	Invalidate( false );
											// Stop the timer
	if (m_uiMoveTimer)
	{
		KillTimer( m_uiMoveTimer );
		m_uiMoveTimer = 0;
	}
}


void ChMazeWnd::DrawMouseMoveCrosshair( CDC* pDC )
{
	CPen	pen( PS_SOLID, 0, RGB( 0xff, 0, 0 ) );
	CPen*	pOldPen;
											 // We only draw if the navigator 
											 // wants us to
	if (m_pNavigators[GetSettings()->GetViewerMode()]->IsInAnchoredMove() && GetSettings()->GetMoveVector())
	{
		ASSERT( 0 != pDC );

		pOldPen = pDC->SelectObject( &pen );

		int iX, iY;
		m_pNavigators[GetSettings()->GetViewerMode()]->GetMouseAnchorLoc(iX, iY);

		pDC->MoveTo( iX - m_sCrosshairHalfWidth, iY );
		pDC->LineTo( iX + m_sCrosshairHalfWidth, iY );
		pDC->MoveTo( iX, iY - m_sCrosshairHalfHeight );
		pDC->LineTo( iX, iY + m_sCrosshairHalfHeight );

		pDC->SelectObject( pOldPen );
	}
}


void ChMazeWnd::DrawMouseMoveVector( CDC* pDC )
{
	if (m_pNavigators[GetSettings()->GetViewerMode()]->IsInAnchoredMove() && GetSettings()->GetMoveVector())
	{
		ASSERT( 0 != pDC );

		CPoint ptMouseStart, ptMouse;
		int iX, iY;
		m_pNavigators[GetSettings()->GetViewerMode()]->GetMouseAnchorLoc(iX, iY);
		ptMouseStart.x = iX; ptMouseStart.y	= iY;		
		m_pNavigators[GetSettings()->GetViewerMode()]->GetMouseLoc(iX, iY);
		ptMouse.x	=	iX;  ptMouse.y = iY;

		if (ptMouseStart != ptMouse)
		{
			CPen	pen( PS_SOLID, 0, RGB( 0xff, 0, 0 ) );
			CPen*	pOldPen = pDC->SelectObject( &pen );

			pDC->MoveTo( ptMouseStart.x, ptMouseStart.y );
			pDC->LineTo( ptMouse.x, ptMouse.y );

			pDC->SelectObject( pOldPen );
		}

		m_ptLastMouse = m_ptMouse;
	}
}


float ChMazeWnd::CalcMouseHorzMove()
{
	float		fMove;

	fMove = m_ptMouseStart.x - m_ptMouse.x;
	fMove /= (float)m_sCrosshairHalfWidth;

	return fMove;
}


float ChMazeWnd::CalcMouseVertMove()
{											// Positive is up
	float		fMove;

	fMove = m_ptMouseStart.y - m_ptMouse.y;
	fMove /= (float)m_sCrosshairHalfHeight;

	return fMove;
}


float ChMazeWnd::CalcAccel( float fVal )
{
	float worldSize = 1.;
	if(!GetBounds()->IsEmpty())
	{
		GxVec3f				lower, upper;
		GetBounds()->GetWorldBounds(lower, upper);
		upper -= lower;
		worldSize = upper.magnitude();
	}

	float fMove = (worldSize * fVal * GetUserSpeedFactor()) / (defStepsPerWorld * defMoveAmount);
	return fMove;
}

bool ChMazeWnd::GetURL( const string& strURL, chparam userData,
				const char* pstrDefURL )
{

	#if (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
	bool boolCached = false;

	if ( userData )
	{

		ChGraphicHTTPReq *pHTTPReq	 = (ChGraphicHTTPReq *)userData;
		if ( pHTTPReq->GetType() == ChGraphicHTTPReq::texture )
		{

			#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
			ChGraphicStreamManager* pStream = (ChGraphicStreamManager*)GetMainInfo()->GetStream();
			#else
			ChGraphicStreamManager* pStream = m_pGraphicStream;
			#endif
			ChMazeTextureHTTPReq* pReq = ( ChMazeTextureHTTPReq*)pHTTPReq;
			// use cache only if it is not keep size
			if ( pStream && !(pReq->GetOption() & ChMazeTextureHTTPReq::textureKeepSize) )
			{
				ChURLParts urlParts;
				urlParts.GetURLParts( strURL, pstrDefURL );

				ChRLImage* pImage = pStream->GetCachedImage( urlParts.GetURL() );

				if ( pImage )
				{  // we have the image use it
					ChQvTextureRenderData* pRenderData = 
						(ChQvTextureRenderData*)(pReq->GetTextureNode()->GetRenderData());

					pRenderData->LoadTexture( GetRenderContext(), pImage );

					boolCached = true;

					delete pReq;
		
				}
			}
		}
	}

	if ( !boolCached )
	#endif
	{

		#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
		ChURLParts urlParts;
		urlParts.GetURLParts( strURL, pstrDefURL );

		return GetMainInfo()->GetCore()->GetURL( urlParts.GetURL(),  0, 
									GetMainInfo()->GetStream(), userData );
		#else

		GetHTTPConn()->GetURL( strURL, (chparam)userData, LPCTSTR(pstrDefURL) );
		return false;
		#endif
	}

	return true;
}

float  ChMazeWnd::GetMoveAmountDistance()
{									 // maybe can use calcAccel???
	float fVal = 2.;
	float worldSize = 1.;
	if(GetScene())
	{
		if(!GetBounds()->IsEmpty())
		{
			GxVec3f				lower, upper;
			GetBounds()->GetWorldBounds(lower, upper);
			upper -= lower;
			worldSize = upper.magnitude();
		}
	}
	float fMove = (worldSize * fVal * GetUserSpeedFactor()) / (defStepsPerWorld);
	return fMove;
}

float  ChMazeWnd::GetMoveAmountAngle()
{										
	return float(GetUserSpeedFactor());
}

float  ChMazeWnd::GetUserSpeedFactor()
{
	return m_fUserSpeedFactor;
}

void  ChMazeWnd::SetUserSpeedFactor(float fSpeed)
{
	m_fUserSpeedFactor = peg(fSpeed, minUserSpeed, maxUserSpeed);
}

void  ChMazeWnd::ResetUserSpeedFactor()
{
	m_fUserSpeedFactor = defUserSpeed;
}

ChMazeWnd * ChMazeWnd::GoFaster(bool boolFaster /* = true */)
{
	const float accel = 1. + 1. / 16.;

	float		fSpeed = GetUserSpeedFactor();
	if (boolFaster)
	{

		fSpeed *= accel;

		SetUserSpeedFactor( fSpeed );
	}
	else	
	{
		fSpeed /= accel;

		SetUserSpeedFactor( fSpeed );
	}
	return this;
}

Ch3DCollisionMode ChMazeWnd::GetCollisionMode( )
{
#if 0
	if(GetSettings()->GetOverrideCollisionMode() || m_sceneCollisionMode == invalidCollisionMode)
	{
		return GetSettings()->GetCollisionMode();
	}
	else
	{
		return m_sceneCollisionMode;
	}
#endif
		return GetSettings()->GetCollisionMode();
}

void ChMazeWnd::EndFrameTime()
{
	#if defined(CH_VRML_VIEWER)	|| defined(CH_VRML_PLUGIN )
	DWORD	luNow = GetTickCount();
	DWORD	luElapsed = luNow - m_luTime;
	string	strStatus;
	double	frameRate = luElapsed ? 1.0 / (float)luElapsed : 1.0;

	frameRate *= 1000.0;	  // ticks are in milliseconds

	strStatus.Format( "Frames per second: %.2f", frameRate );
		#if  defined(CH_VRML_PLUGIN )
			#pragma message("Not setting frame rate ")
		#else
		((CFrameWnd*)(AfxGetMainWnd()))->SetMessageText( strStatus );
		#endif
	#else
	GetMainInfo()->EndFrameTime();
	#endif
}

void ChMazeWnd::StartFrameTime()
{ 
	#if defined(CH_VRML_VIEWER)	|| defined( CH_VRML_PLUGIN )
	m_luTime = GetTickCount();
	#else
	m_luTime = GetTickCount();
	GetMainInfo()->StartFrameTime();
	#endif
}

ChMazeWnd* ChMazeWnd::SetHeadlight( bool boolOn )
{
	GetSettings()->SetHeadlightSwitch(boolOn);
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	m_RC.AdjustHeadlight();
	#endif
	return this;
}

#if defined(CH_VRML_EVENTS)	 && !defined( CH_VRML_PLUGIN )
ChVrmlBrowser * ChMazeWnd::GetBrowser()
{
	if(!m_pVrmlBrowser) m_pVrmlBrowser = new ChStubBrowser(&m_RC);
	
	return m_pVrmlBrowser;
}
#endif

bool ChMazeWnd::GetVelocity(GxVec3f &velocity)
{
	if(!GetScene())
	{
		velocity.set(0,0,0);
		return false;	
	}
	return GetSceneNavigator()->GetVelocity(velocity);
}
bool ChMazeWnd::GetAngularVelocity(GxVec3f &axis, float &slewRate)
{
	if(!GetScene())
	{
		axis.set(0,0,0);
		slewRate = 0.;
		return false;	
	}
	return GetSceneNavigator()->GetAngularVelocity(axis, slewRate);
}

/*----------------------------------------------------------------------------
	ChMazeWnd message handlers
----------------------------------------------------------------------------*/

void ChMazeWnd::OnSize( UINT nType, int cx, int cy )
{
	ChGraphicView::OnSize(nType, cx, cy);
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	m_RC.Resize(cx, cy);
	#endif

	GetRenderContext()->SetDirty();
	InvalidateRect(0, false);
}


void ChMazeWnd::OnChar( UINT nChar, UINT nRepCnt, UINT nFlags )
{
	// TODO: Add your message handler code here and/or call default

	ChGraphicView::OnChar( nChar, nRepCnt, nFlags );
}


void ChMazeWnd::OnLButtonDblClk( UINT nFlags, CPoint point )
{
	// TODO: Add your message handler code here and/or call default

	ChGraphicView::OnLButtonDblClk( nFlags, point );
}


void ChMazeWnd::OnLButtonDown( UINT nFlags, CPoint point )
{
											/* In pueblo, we always have a scene if
											visible. Not so in viewers, which might be loaded 
											empty. In this case, ignore mouse downs; you
											can't move around if you're nowhere, one
											must have space and existence in order to move. */
	if(!GetScene()) return;	
											/* Set capture so we absolutely
												get the mouse up event */
	SetCapture();

	bool boolProcessed = m_pNavigators[GetSettings()->GetViewerMode()]->
		ProcessMouseEvent(WM_LBUTTONDOWN, point.x, point.y, nFlags);


	#if 0

	if (IsAnchor( point.x, point.y ))
	{
		StartAnchor( point.x, point.y );
	}
	//else
	{
		StartMouseMove( point.x, point.y );
	}
	#endif
}


void ChMazeWnd::OnLButtonUp( UINT nFlags, CPoint point )
{
											/* We can't be in both mouse move
												and anchor states */

	// -- ASSERT( !(IsInMouseAnchor() && IsInMouseMove()) );
	if(!GetScene()) return;	
	bool boolEither = m_pNavigators[GetSettings()->GetViewerMode()]->
		ProcessMouseEvent(WM_LBUTTONUP, point.x, point.y, nFlags);

	#if 0
	bool boolEither = IsInMouseAnchor() || IsInMouseMove();
	if (IsInMouseMove())
	{
		EndMouseMove( point.x, point.y );
	}
	if (IsInMouseAnchor())
	{
		EndAnchor( point.x, point.y );
	}
	#endif
	// -- else
	if(!boolEither)
	{
		ChGraphicView::OnLButtonUp( nFlags, point );
	}
	if(!(nFlags & (MK_MBUTTON | MK_RBUTTON | MK_LBUTTON)))ReleaseCapture();
}


void ChMazeWnd::OnMouseMove( UINT nFlags, CPoint point )
{
	if(!GetScene()) return;
	
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	m_boolMouseMove = true;

	#else
	IsAnchor(point.x, point.y);		// update the status line
	#endif

	bool boolProcessed = m_pNavigators[GetSettings()->GetViewerMode()]->
		ProcessMouseEvent(WM_MOUSEMOVE, point.x, point.y, nFlags);

	if(!boolProcessed)	ChGraphicView::OnMouseMove( nFlags, point );

											/* We can't be in both mouse move
												and anchor states */

	// -- ASSERT( !(IsInMouseAnchor() && IsInMouseMove()) );
	#if 0
	if (IsInMouseAnchor())
	{
		UpdateAnchor( point.x, point.y );
	}
	// -- else 
	if (IsInMouseMove())
	{
//		UpdateMouseMove( point.x, point.y );
	}
	else
	{
		bool boolAnchor = IsAnchor( point.x, point.y );

		ChGraphicView::OnMouseMove( nFlags, point );
	}
	#endif
}


void ChMazeWnd::OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags )
{
	bool			boolProcessed = true;
	ChPosition		pos;
	ChKeyMapItem*	pItem;
	chflag32		flMods = 0;

	if (GetKeyState( VK_SHIFT ) & 0x8000)
	{
		flMods |= ACTION_MOD_SHIFT;
	}

	if (GetKeyState( VK_CONTROL ) & 0x8000)
	{
		flMods |= ACTION_MOD_CONTROL;
	}

	pos = m_keyMap.FindItem( nChar, flMods );
	if (pos)
	{
		pItem = m_keyMap.GetItem( pos );

		ASSERT( pItem );

		switch( (KeyAction)pItem->GetUserData() )
		{

			case goFaster:
			{
				GoFaster(true);
				break;
			}

			case goSlower:
			{
				GoFaster(false);
				break;
			}

			case walkMode:
			{
				OnWalk();
				break;
			}
			case flyMode:
			{
				OnFly();
				break;
			}
			case examineMode:
			{
				OnExamine();
				break;
			}
			case beBrighter:
			{
				OnBrighten();
				break;
			}
			case beDimmer:
			{
				OnDimmer();
				break;
			}
			case goPrevCamera:
			{
				OnCameraPrev();
				break;
			}

			case goNextCamera:
			{
				OnCameraNext();
				break;
			}


			case resetCamera:
			{
				ResetCamera()->InvalidateRect( NULL, false );
				break;
			}
			
			default:
			{
				boolProcessed = false;
				break;
			}
		}
	}
	else
	{
		boolProcessed = false;
	}

	if(!boolProcessed)
	{
		boolProcessed = m_pNavigators[GetSettings()->GetViewerMode()]->ProcessKeyEvent(WM_KEYDOWN, nChar, 0);
	}

	if (!boolProcessed)
	{
		ChGraphicView::OnKeyDown( nChar, nRepCnt, nFlags );
	}
}


void ChMazeWnd::OnKeyUp( UINT nChar, UINT nRepCnt, UINT nFlags )
{
	// TODO: Add your message handler code here and/or call default

	bool			boolProcessed = false;

	boolProcessed = m_pNavigators[GetSettings()->GetViewerMode()]->ProcessKeyEvent(WM_KEYUP, nChar, 0);

	if (!boolProcessed)
	{
		ChGraphicView::OnKeyUp( nChar, nRepCnt, nFlags );
	}
}


void ChMazeWnd::OnRButtonDblClk( UINT nFlags, CPoint point )
{
	// TODO: Add your message handler code here and/or call default

	ChGraphicView::OnRButtonDblClk( nFlags, point );
}


void ChMazeWnd::OnRButtonUp( UINT nFlags, CPoint point )
{
	// TODO: Add your message handler code here and/or call default

	if(!GetScene()) return;	
	if(! m_pNavigators[GetSettings()->GetViewerMode()]->
		ProcessMouseEvent(WM_RBUTTONUP, point.x, point.y, nFlags))
	{
		ChGraphicView::OnRButtonUp( nFlags, point );
	}
	if(!(nFlags & (MK_MBUTTON | MK_RBUTTON | MK_LBUTTON)))ReleaseCapture();
}


void ChMazeWnd::OnRButtonDown( UINT nFlags, CPoint point )
{
	// TODO: Add your message handler code here and/or call default

	if(!GetScene()) return;	
	SetCapture();
	if(! m_pNavigators[GetSettings()->GetViewerMode()]->
		ProcessMouseEvent(WM_RBUTTONDOWN, point.x, point.y, nFlags))
	{
		ChGraphicView::OnRButtonDown( nFlags, point );
	}
}


BOOL ChMazeWnd::PreCreateWindow( CREATESTRUCT& cs )
{
		HCURSOR		hCursor;

	if (!ChGraphicView::PreCreateWindow( cs ))
	{
		return false;
	}

	hCursor = AfxGetApp()->LoadStandardCursor( IDC_ARROW );
	cs.lpszClass = AfxRegisterWndClass( CS_DBLCLKS | CS_OWNDC, hCursor,
									//	(HBRUSH)(COLOR_WINDOW + 1) );
										(HBRUSH)(COLOR_BTNFACE + 1) );
	return true;

	//return ChGraphicView::PreCreateWindow(cs);
}

void ChMazeWnd::OnDestroy()
{
	m_currentPage = GetNewPage(); // bump the page number so that any pending request 
								  // will fail gracefully

	#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
	GetMainInfo()->GetCore()->AbortRequests( false, 
								GetMainInfo()->GetStream() );
	#else
	GetHTTPConn()->AbortRequests( false, GetHTTPConn()->GetStreamMgr() );
	#endif


	// cancel all parse threads if any
	AbortParsing();

	m_RC.AbortConstruction();

	if(m_uiTickTimer)
	{
		KillTimer( m_uiTickTimer );
		m_uiTickTimer = 0;
	}
	ChGraphicView::OnDestroy();

	if(m_pRoot)
	{
	#if 0
		ChQvDeleteState	state(this);
		m_pRoot->traverse(&state);
		delete m_pRoot;
	#endif
		m_pRoot->Release();	
	}

	m_RC.Term();
}


void ChMazeWnd::OnTimer( UINT nIDEvent )
{
	if (m_uiMoveTimer == nIDEvent)
	{
		POINT	ptCursor;

		GetCursorPos( &ptCursor );
		ScreenToClient( &ptCursor );
		IsAnchor(ptCursor.x, ptCursor.y);		// update the status line
		m_pNavigators[GetSettings()->GetViewerMode()]->ProcessEvent(WM_TIMER, 0);
		//UpdateMouseMove( ptCursor.x, ptCursor.y );
	}
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	else if(m_uiTickTimer == nIDEvent)
	{
		POINT	ptCursor;
		KillTimer( moveTimerID+1);
		chuint32 luLastFrame = m_luTime;
		GetCursorPos( &ptCursor );
		ScreenToClient( &ptCursor );

		m_pNavigators[GetSettings()->GetViewerMode()]->ProcessEvent(WM_TIMER, 0);

		m_RC.LowerConstructionThreads(m_pNavigators[GetSettings()->GetViewerMode()]->IsMoving());

		//TRACE("Calling draw...");
		if( ContinueDraw() && m_RC.Draw())
		{
			//TRACE("rendered");	TRACE("\n");
			IsAnchor(ptCursor.x, ptCursor.y);		// update the status line
			m_boolMouseMove = false;
		}
		//TRACE("\n");
		
		CDC* pDC = GetDC();
		DrawMouseMoveCrosshair( pDC );
		DrawMouseMoveVector( pDC );
		ReleaseDC(pDC);

		if(m_boolMouseMove)
		{
			IsAnchor(ptCursor.x, ptCursor.y);		// update the status line
			m_boolMouseMove = false;
		}

		chuint32 luTimeElapsed, luTime = GetTickCount();
		
		luTimeElapsed = (luTime > luLastFrame) ? luTime - luLastFrame : 0; // one jitter every 23 days
 
 		int iTicks = moveTimerDuration - UINT(luTimeElapsed);
		//iTicks = max(iTicks, 1);
		int iSlackTime = 8;
		if(m_pNavigators[GetSettings()->GetViewerMode()]->IsMoving())
		{
			iSlackTime = 4;
		}
		iTicks = max(iTicks, iSlackTime);	 // Give other threads time to work, too
		m_uiTickTimer = SetTimer( moveTimerID+1, UINT(iTicks), 0 );

	}
	#else
	else if(m_uiTickTimer == nIDEvent)
	{
		POINT	ptCursor;

		GetCursorPos( &ptCursor );
		ScreenToClient( &ptCursor );
		IsAnchor(ptCursor.x, ptCursor.y);		// update the status line
		m_pNavigators[GetSettings()->GetViewerMode()]->ProcessEvent(WM_TIMER, 0);
		//UpdateMouseMove( ptCursor.x, ptCursor.y );
		m_boolMouseMove = false;
	}
	#endif
	else
	{
		ChGraphicView::OnTimer( nIDEvent );
	}
}


BOOL ChMazeWnd::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if(nHitTest == HTCLIENT)
	{
		SetCursor(m_hCursor);
		return true;
	}
	else
		return ChGraphicView::OnSetCursor(pWnd, nHitTest, message);
}

void ChMazeWnd::OnVRMLActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	//if(GetRC())	RLWinHandleActivate(GetRC(), MAKEWORD( nState, bMinimized) );
	if(GetRenderContext())	GetRenderContext()->OnWindowActivate( nState, bMinimized );

	#endif
}

void ChMazeWnd::OnPaint() 
{
	#if defined(CH_USE_3DR)
	// class wizard says: Do not call ChGraphicView::OnPaint() for painting messages  ????????
	GetRenderContext()->SetDirty();
	ChGraphicView::OnPaint();
	#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

	//CPaintDC dc(this); // device context for painting
	GetRenderContext()->SetDirty();

	// TODO: Add your message handler code here
  	RECT r;
    PAINTSTRUCT ps;

    if (GetUpdateRect(&r, FALSE))
    {
    	BeginPaint(&ps);
		if(GetRC())
		{
			//RLWinHandlePaint(GetRC(), ps.hdc);
			GetRenderContext()->OnWindowPaint(ps.hdc);
		}
		EndPaint(&ps);
    }
	#endif
}

LONG ChMazeWnd::OnPrefChange( UINT wParam, LONG lParam )
{
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

	m_RC.AdjustHeadlight();
	#endif
	if(wParam & ChVrmlSettings::viewerMode)
	{
		m_pNavigators[GetSettings()->GetViewerMode()]->SetState(ChVrmlStateTransition::s_start);
	}
	else if(wParam & ChVrmlSettings::renderOptimization)
	{
		GetRenderContext()->OptimizationChanged();
		GetRenderContext()->SetDirty();
	}
	else
	{
		GetRenderContext()->SetDirty();
	}
	return 1;	
}

LONG ChMazeWnd::OnVrmlEvent( UINT wParam, LONG lParam )
{
	LONG lValue = 1;
#if defined(CH_VRML_EVENTS)
	ChEventMsg *pEventMsg = (ChEventMsg *)lParam;
	lValue = m_RC.ProcessEvent(pEventMsg);
#endif
	return lValue;	
}


LONG ChMazeWnd::OnProgressMsg( UINT wParam, LONG lParam )
{
	// Override this member function to get notification of progress
	OnUpdateProgress( wParam );
	return 1;	
}

LONG ChMazeWnd::OnMazeError( UINT wParam, LONG lParam )
{
	// Override this member function to get notification of progress
	string* pstrBuf = (string*)lParam;

	OnError( wParam, *pstrBuf, traceError);

	delete pstrBuf;
	return 1;	
}


LONG ChMazeWnd::OnParseError( UINT wParam, LONG lParam )
{
	// Override this member function to get notification of progress
	char* pBuf = (char*)lParam;

	OnError( CH_MAZE_PARSE_ERROR_SYNTAX, string(pBuf) + "\n", traceError);

	#if !defined(CH_VRML_PLUGIN )
	if ( pBuf )
	{
		AfxMessageBox( pBuf,  MB_OK | MB_ICONEXCLAMATION );
	}
	#endif

	delete [] pBuf;

	// Resume animation - this one blew up so no need to wait
	GetRenderContext()->Animate();
	return 1;	
}



LONG ChMazeWnd::OnParseComplete( UINT wParam, LONG lParam )
{

	ChParseInfo* pParseInfo = (ChParseInfo*)lParam;
	ASSERT( pParseInfo );

	bool		boolSuccess = false;
	bool		boolFound   = RemoveParseInfo( pParseInfo );


	if ( boolFound && pParseInfo->GetType() == ChParseInfo::typeScene )
	{
		QvNode *rootToDelete = 0;

	    if ( pParseInfo->GetParseResult() )
		{
			#if 0 && I_HOPE
			if(m_pRoot)
			{
				ChQvDeleteState	state(this);
				m_pRoot->traverse(&state);
				delete m_pRoot;
			}
			#endif

			rootToDelete = m_pRoot;

			#if defined(CH_USE_3DR)
			ClearAnchors();
			delete m_pAnchor;
			m_pAnchor = 0;
			#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
			// no need to
			#else
			#pragma message("Not clearing anchor")
			#endif

			m_pRoot = pParseInfo->GetQVNode();
			boolSuccess = true;
			CheckForTrailingJunk( *pParseInfo->GetStream() );

		}
	    else
	    {
			TRACE("Read was bad.\n");
			// Clean up on bad read
			if(pParseInfo->GetQVNode())
			{
				#if 0
				SetupContexts();
				ChQvDeleteState	state(this);
				pParseInfo->GetQVNode()->traverse(&state);
				delete pParseInfo->GetQVNode();
				#endif
				pParseInfo->GetQVNode()->Release();	
			}
	    }

		// save tree, and do traversal
		if(boolSuccess)
		{
			// We are going to mess with the scene, we better lock befor any body
			// uses

			GetRenderContext()->LockScene();
			m_strURL = pParseInfo->GetURL();
			m_currentPage = GetNewPage();
			GetRenderContext()->UnlockScene(); // done, can be used now

			#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
			// Always visible if we're a standalone viewer
			GetMainInfo()->ShowModule();
			#endif			
						// pop up if not visible
			SetScene(m_pRoot)->InvalidateRect(0, false);


			
								  // Zap the old scene; we are guaranteed
							  // all its construction threads are now
							  // ended
			if(rootToDelete)
			{
				rootToDelete->Release();

				#if 0
				ChQvDeleteState	state(this);
				rootToDelete->traverse(&state);
				delete rootToDelete;
				#endif
			}

			Spawn( pParseInfo->GetURL() );	 // Spawn new requests based on embedded URLs

			#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
			ChGraphicDocumentHTTPReq * pReq = (ChGraphicDocumentHTTPReq *)(pParseInfo->GetUserData2());
			if(pReq)
			{
				GetMainInfo()->OnParseComplete(pParseInfo->GetURL(), chparam(pReq));  
				delete pReq;
				
			}
			#endif
		}

	}
	else if ( boolFound && pParseInfo->GetType() == ChParseInfo::typeWWWInline )
	{
		QvWWWInline *pInlineNode = (QvWWWInline*)pParseInfo->GetUserData();

	    if ( pParseInfo->GetParseResult() )
		{
			if(pInlineNode)
			{
				ChQvWWWInlineRenderData *pRenderData =  ((ChQvWWWInlineRenderData*)(pInlineNode->GetRenderData()));
				pRenderData->SetParseInfo(0);
				if(pRenderData->GetCurrentURL().IsEmpty())
				{
					// Attach to tree, and instantiate the new subtree
					pInlineNode->children->append(pParseInfo->GetQVNode());
					pRenderData->Instantiate( this, pParseInfo->GetQVNode());
					pRenderData->SetURL(pParseInfo->GetURL());

					// Spawn for new requests
					ChQvSpawnState state( this, pParseInfo->GetURL() );
			    	pParseInfo->GetQVNode()->traverse(&state);

					// Set it dirty, for redraw, etc.
					GetRenderContext()->SetDirty();
					InvalidateRect(0, false);
				}
			}
			else
			{
				TRACE("WWWInline parse complete, but node is gone, so deleting result.\n");
				pParseInfo->GetQVNode()->Release();	// oughta be non-null cuz parse result was good
			}
		}
	    else
	    {
			TRACE("WWWInline Read was bad.\n");
			// Clean up on bad read
			if(pParseInfo->GetQVNode())
			{
				pParseInfo->GetQVNode()->Release();
			}
	    }


	}
	else
	{
		if(pParseInfo->GetQVNode())
		{
			pParseInfo->GetQVNode()->Release();

		}
	}
	// done with this file, cleanup 
	delete pParseInfo;
	return 1;	
}

LONG ChMazeWnd::OnLoadTexture( UINT wParam, LONG lParam )
{
	GetRenderContext()->AddToTextureQueue( (ChMazeTextureHTTPReq*)lParam );
	return 0;
}

LONG ChMazeWnd::OnActivateWnd( UINT wParam, LONG lParam ) 
{

	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		#if 0
		if (WA_INACTIVE != nState)
		{
			SetFocus();
		}
		#endif
		OnVRMLActivate( LOWORD(wParam), CWnd::FromHandle( (HWND)lParam ), HIWORD(wParam));
	#endif

	return 0;
}


void ChMazeWnd::OnSysKeyDown(  UINT nChar, UINT nRepCnt, UINT nFlags )
{
	bool boolProcessed = m_pNavigators[GetSettings()->GetViewerMode()]->ProcessKeyEvent(WM_KEYDOWN, nChar, 0);
	if(!boolProcessed /*|| nChar == VK_MENU*/)
	{
		ChGraphicView::OnSysKeyDown( nChar, nRepCnt, nFlags );
	}
}

void ChMazeWnd::OnSysKeyUp(  UINT nChar, UINT nRepCnt, UINT nFlags )
{
	bool boolProcessed = m_pNavigators[GetSettings()->GetViewerMode()]->ProcessKeyEvent(WM_KEYUP, nChar, 0);
	if(!boolProcessed /*|| nChar == VK_MENU*/)
	{
		ChGraphicView::OnSysKeyUp( nChar, nRepCnt, nFlags );
	}
}

bool ChMazeWnd::OnLeftClick(int x, int y, chuint32 uFlags)
{
	EndAnchor(x, y);
	return true;
}

bool ChMazeWnd::OnRightClick(int x, int y, chuint32 uFlags)
{
	DisplayMenu(  x, y, uFlags );
	return true;
}



/*----------------------------------------------------------------------------
	Override this virtual member function to display trace messages generated
	by VRML parser, HTTP load errors, plugin errors etc.
----------------------------------------------------------------------------*/
void ChMazeWnd::OnError( chuint32 luErrorCode, const string& strMsg, int iType  )
{

}

