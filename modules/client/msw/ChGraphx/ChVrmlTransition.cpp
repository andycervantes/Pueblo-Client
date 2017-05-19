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

	Implementation for the ChVrmlStateTransition classes for  navigation.

	Note: The "crabbish" functions means take a step to the side, either left/right, 
	up or down. (Remember the song about "Crabs walk sideways, and lobsters walk straight"?)

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChVrmlTransition.cpp,v 2.16 1996/07/08 21:30:37 jimd Exp $

#include "grheader.h"

#include "ChVrmlTransition.h"
#include "ChMaze.h"
#include "ChMazCam.h"
#include "ChRenderData.h"
#if 0
// An example of how to do a statically initialized STM
ChStateTransition::transition 	 mySTM[1][1] =
{
{1, ChStateTransition::ChTransitionActionHandler(ChVrmlStateTransition::MyDefaultHandler)} //elt 0, 0
};

ChStateTransition::transition 	*ChVrmlStateTransition::pSTM = &(mySTM[0][0]);

//then add these to the class defn
static transition *pSTM;
virtual transition * GetMatrix() {return pSTM;};

#endif

#include <ChKeyMap.h>

#define ACTION_MOD_KEY_UP	(1L << 4)

#define AddCell(i, j, k, cls, hdlr) \
	SetCell(i, j, k, ChStateTransition::ChTransitionActionHandler(cls::hdlr))

const chint32 maxClickTicks = 500;		  // milliseconds for a 'Click' as opposed to a press
const chint32 maxClickFrames = 1;		  // number of rendered frames for a 'Click' as opposed to a press
const chint32 animMoveTowardsTicks = 2000;		  // milliseconds for animation in a MoveTowards (reg speed)
const float secondsPerRotation = 3.;
const float turnSlewRate =  360. / secondsPerRotation;	
const float pitchSlewRate =  360. / secondsPerRotation;

const float spinThresholdSpeed = 2;
//-------------------------------------------------------------------------------------------
ChVrmlStateTransition::ChVrmlStateTransition(ChMazeWnd *pWnd) : 
	ChStateTransition(s_numStates, e_numEvents),
	m_pWnd(pWnd),
	m_lTime(0),
	m_keyFlags(0),
	m_look(0,0,-1)
{
	m_pKeyMap = new ChKeyMap;
}

ChVrmlStateTransition::~ChVrmlStateTransition()
{
	delete m_pKeyMap;
};

bool ChVrmlStateTransition::TranslateMouseEvent(int mouseMsg, int x, int y, chuint32 uFlags, int &event, chuint32 *&pData)
{
	bool boolProcessed = true;
	switch(mouseMsg)
	{
		case WM_LBUTTONDOWN:
		{
			event = ep_lbutton;
			//TRACE("LButtonUp\n");
			break;
		}
		case WM_RBUTTONDOWN:
		{
			event = ep_rbutton;
			break;
		}
		case WM_LBUTTONUP:
		{
			event = er_lbutton;
			//TRACE("LButtonUp\n");
			break;
		}
		case WM_RBUTTONUP:
		{
			event = er_rbutton;
			break;
		}
		case WM_MOUSEMOVE:
		{
			event = e_move;
			break;
		}
		default:
		{
			boolProcessed = false;
		}
	}
	if(boolProcessed)
	{
		chflag32		flMods = 0;
		if (GetKeyState( VK_MENU ) & 0x8000)
		{
			flMods |= ACTION_MOD_ALT;
		}

		if (uFlags & MK_SHIFT)
		{
			flMods |= ACTION_MOD_SHIFT;
		}

		if (uFlags & MK_CONTROL)
		{
			flMods |= ACTION_MOD_CONTROL;
		}

		m_flags = flMods;
		m_mouseFlags = uFlags;
		m_ix = x;
		m_iy = y;
	}
	return boolProcessed;
};

bool ChVrmlStateTransition::TranslateEvent(int iMsg, void *pMsgData,  int &event, chuint32 *&pData)
{
	if(iMsg == WM_TIMER)
	{
		event = e_tick;
		return true;
	}
	return false;
};


bool ChVrmlStateTransition::Examine()
{
	if ((m_iAnchorX != m_ix) || (m_iAnchorY != m_ix))
	{
		RECT r;

		m_pWnd->GetClientRect(&r);
		ChPoint ptLastMouse(m_iAnchorX, m_iAnchorY);
		ChPoint ptMouse(m_ix, m_iy);

		m_pWnd->GetCameraControl()->RotateBall(ptLastMouse, ptMouse, r.bottom - r.top);	

		m_iAnchorX = m_ix;
		m_iAnchorY = m_iy;

		m_mouseVelocity.set( ptMouse.x - ptLastMouse.x, ptMouse.y - ptLastMouse.y, 0.);

	}
	else
	{
		m_mouseVelocity.set(0.,0.,0.);
	}

	AccumMouseVelocity();

	RecordTime();

	return true;
}
	   
bool ChVrmlStateTransition::ExamineStart()
{
	RecordTime();
	RecordPressTime();
	m_iAnchorX = m_ix;
	m_iAnchorY = m_iy;

	m_mouseAvgVelocity.set(0.,0.,0.);
	m_mouseVelocity.set(0.,0.,0.);

	return true;
};

void ChVrmlStateTransition::AccumMouseVelocity()
{
	// just a simple one tap iir filter to damp jiggle as mouse button
	// is released.
	const float mouseVelocityWeight = .2;	// weight of 1st (only) filter tap
	GxVec3f velocity = m_mouseVelocity;
	velocity *= mouseVelocityWeight;

	m_mouseAvgVelocity *= (1. - mouseVelocityWeight - .001);	// ff guarantees stable decay
	m_mouseAvgVelocity += velocity;
}

bool ChVrmlStateTransition::Spin()
{
	RECT r;

	m_pWnd->GetClientRect(&r);
	ChPoint ptLastMouse(0, 0);
	ChPoint ptMouse(int(m_mouseAvgVelocity.x()), m_mouseAvgVelocity.y());

	m_pWnd->GetCameraControl()->RotateBall(ptLastMouse, ptMouse, r.bottom - r.top);	

	RecordTime();
	return true;
}
	   
bool ChVrmlStateTransition::SpinStart()
{
	RecordTime();
	return true;
};

void ChVrmlStateTransition::RecordTime()
{	
	// first record current velocity	 
	const chint32 minTickTime = 33;
	chint32 ticks = GetElapsedTicks();
	//ticks = min(ticks, minTickTime);
	GxVec3f loc = m_pWnd->GetCameraControl()->GetLoc();
	GxVec3f dir = m_pWnd->GetCameraControl()->GetLookDir();
	float secs = ticks / 1000.;

	if(secs > 0.0)
	{
		m_velocity = loc;
		m_velocity -= m_loc;
		m_velocity *= 1. / secs;
		m_loc = loc;

		dir.normalize();
		m_slewAxis = m_look.cross(dir);
		if(m_slewAxis.dot(m_slewAxis) <= 1e-8) m_slewAxis.set(0, 1, 0);
		m_slewAxis.normalize();
		float cosa = m_look.dot(dir);
		if(cosa > 1.0) cosa = 1.0;
		if(cosa < -1.0) cosa = -1.0;

		m_slewRate = acos(cosa) / secs;
		//TRACE3("Amount turned %f, rate %f, ticks %ld\n", double(acos(cosa)), double(m_slewRate), ticks);
		m_look = dir;
	}
	else
	{
		//TRACE("Record with no time elapsed\n");
	}

	// largest value is   2147483647, then it wraps to 0
	m_lTime = ::GetMessageTime();
}	   

void ChVrmlStateTransition::RecordPressTime()
{		 
	// largest value is   2147483647, then it wraps to 0
	m_lButtonTime = ::GetMessageTime();
	m_frameCount = m_pWnd->GetRenderContext()->GetFrameCount();
}	   

chint32	ChVrmlStateTransition::GetElapsedTicks()
{
	double dTime = ::GetMessageTime();
	while(dTime < m_lTime) dTime += 2147483648.;	// while instead of if is in case they hold 
													// down key for over 23 days	  :-)

	return chint32(dTime - m_lTime);
}

chint32	ChVrmlStateTransition::GetElapsedPressTicks()
{
	double dTime = ::GetMessageTime();
	while(dTime < m_lButtonTime) dTime += 2147483648.;	// while instead of if is in case they hold 
													// down key for over 23 days	  :-)

	return chint32(dTime - m_lButtonTime);
}


bool ChVrmlStateTransition::IsWithinFastClickTime()
{
	if(GetElapsedPressTicks() < maxClickTicks)
	{
		return true;
	}

	if(m_pWnd->GetRenderContext()->GetFrameCount() - m_frameCount <= maxClickFrames)
	{
		return true;
	}
	return false;
}


float ChVrmlStateTransition::Smooth(float val, float begin, float end, float idle )
{
	// Simple Harmonic motion smoother - just testing
	// doesn't use range #s yet
	return .5 * (cos((val - 1.) * 3.14159265359) + 1);
}

const float HACK_AGAIN = 30.;

float ChVrmlStateTransition::GetMoveAmountDistance()
{
	//return m_pWnd->GetMoveAmountDistance() / 3.;
	float unitsPerSecond = m_pWnd->GetMoveAmountDistance() * HACK_AGAIN;
	if(GetKeyState( VK_SHIFT ) & 0x8000)
	{
		unitsPerSecond *= 2;
	}
	chint32 ticks = GetElapsedTicks();
	ticks = max(ticks, 30);
	return unitsPerSecond * ticks / 1000.;
};

float ChVrmlStateTransition::GetMoveAmountAngle()
{
	//float speedFactor = m_pWnd->GetUserSpeedFactor();
	float speedFactor = 1;
	if(GetKeyState( VK_SHIFT ) & 0x8000)
	{
		speedFactor *= 2;
	}

	chint32 ticks = GetElapsedTicks();
	//ticks = max(ticks, 30);

	float amount = speedFactor *  turnSlewRate * ticks / 1000.;
	//TRACE2("Amount to turn %f, ticks %ld\n", double(3.141593 * amount / 180.), ticks);
	return  amount;
};

float ChVrmlStateTransition::GetMoveAmountAngle(int iPixels)
{
	RECT r;

	m_pWnd->GetClientRect(&r);
	float speedFactor = 2. * float(iPixels) / max((r.bottom - r.top), (r.right - r.left));	

 	chint32 ticks = GetElapsedTicks();
	ticks = max(ticks, 30);


	return speedFactor *  turnSlewRate * ticks / 1000.;
};

bool ChVrmlStateTransition::OnLeftClick(int x, int y, chuint32 uFlags)
{
	ReleaseCapture();
	return m_pWnd->OnLeftClick( x, y, uFlags);
}

bool ChVrmlStateTransition::OnRightClick(int x, int y, chuint32 uFlags)
{
	ReleaseCapture();
	return m_pWnd->OnRightClick( x, y, uFlags);
}

void ChVrmlStateTransition::GetMouseAnchorLoc(int &iX, int &iY)
{
	iX = m_iAnchorX;
	iY = m_iAnchorY;
}

void ChVrmlStateTransition::GetMouseLoc(int &iX, int &iY)
{
	iX = m_ix;
	iY = m_iy;
}

bool ChVrmlStateTransition::IsInAnchoredMove()
{		// return whether you need cross hairs
	bool boolInAnchoredMove = false;

	if(m_iState == s_lbuttondrag  ||
		 m_iState == s_lbuttondown  || 
		 m_iState == s_lbuttondownMove || 
		 m_iState == s_lbuttondragMove)
	{
		boolInAnchoredMove = true;
	}
	return boolInAnchoredMove;
}

bool ChVrmlStateTransition::GetVelocity(GxVec3f &velocity)
{
	// in world units/sec (usually m/s)
	if(m_iState == s_start || m_iState == s_alt)
	{
		velocity.set(0, 0, 0);
		return false;
	}
	velocity = m_velocity;
	return true;
}

bool ChVrmlStateTransition::GetAngularVelocity(GxVec3f &axis, float &slewRate)
{
	// in rads/sec
	if(m_iState == s_start || m_iState == s_alt)
	{
		axis.set(0, 1, 0);
		slewRate = 0.;
		return false;
	}
	axis = m_slewAxis;
	slewRate = m_slewRate;

	return true;
}

// --------------------------------------------------------------------------
// Walker
// --------------------------------------------------------------------------

ChVrmlWalkSTM::ChVrmlWalkSTM(ChMazeWnd *pWnd) : ChVrmlStateTransition(pWnd) 
{
	Init();
}

void ChVrmlWalkSTM::Init()
{

	// Now populate the STM
	// SetCell( int iState, int iEvent, int iNewState, ChTransitionActionHandler action)

	AddCell(s_start,	ep_alt,		s_alt, 		ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_alt,		er_alt,		s_start, 	ChVrmlWalkSTM,	DefaultHandler);
				
	// --			
	AddCell(s_start,	ep_up,		s_up, 		ChVrmlWalkSTM,	MoveForwardStart);
	AddCell(s_up, 		er_up,		s_start,	ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_up, 		e_tick,		s_up,		ChVrmlWalkSTM,	MoveForward);
	AddCell(s_up, 		ep_alt,		s_moveUp,	ChVrmlWalkSTM,	DefaultHandler);

	AddCell(s_alt,		ep_up,		s_moveUp,	ChVrmlWalkSTM,	MoveUpStart);
	AddCell(s_moveUp, 	er_up,		s_alt,		ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_moveUp, 	e_tick,		s_moveUp,	ChVrmlWalkSTM,	MoveUp);
	AddCell(s_moveUp, 	er_alt,		s_up,		ChVrmlWalkSTM,	DefaultHandler);
	// --			
	AddCell(s_start,	ep_down,	s_down, 	ChVrmlWalkSTM,	MoveReverseStart);
	AddCell(s_down, 	er_down,	s_start,	ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_down, 	e_tick,		s_down,		ChVrmlWalkSTM,	MoveReverse);
	AddCell(s_down, 	ep_alt,		s_moveDown,	ChVrmlWalkSTM,	DefaultHandler);

	AddCell(s_alt,			ep_down,	s_moveDown,	ChVrmlWalkSTM,	MoveDownStart);
	AddCell(s_moveDown, 	er_down,	s_alt,		ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_moveDown, 	e_tick,		s_moveDown,	ChVrmlWalkSTM,	MoveDown);
	AddCell(s_moveDown, 	er_alt,		s_down,		ChVrmlWalkSTM,	DefaultHandler);
	// --			
	AddCell(s_start,		ep_left,	s_left,		ChVrmlWalkSTM,	TurnLeftStart);
	AddCell(s_left, 		er_left,	s_start,	ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_left, 		e_tick,		s_left,		ChVrmlWalkSTM,	TurnLeft);
	AddCell(s_left, 		ep_alt,		s_moveLeft,	ChVrmlWalkSTM,	DefaultHandler);

	AddCell(s_alt,			ep_left,	s_moveLeft,	ChVrmlWalkSTM,	MoveLeftStart);
	AddCell(s_moveLeft, 	er_left	,	s_alt,		ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_moveLeft, 	e_tick,		s_moveLeft,	ChVrmlWalkSTM,	MoveLeft);
	AddCell(s_moveLeft, 	er_alt,		s_left,		ChVrmlWalkSTM,	DefaultHandler);
	// --			
	AddCell(s_start,		ep_right,	s_right, 		ChVrmlWalkSTM,	TurnRightStart);
	AddCell(s_right, 		er_right,	s_start,		ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_right, 		e_tick,		s_right,		ChVrmlWalkSTM,	TurnRight);
	AddCell(s_right, 		ep_alt,		s_moveRight,	ChVrmlWalkSTM,	DefaultHandler);

	AddCell(s_alt,			ep_right,	s_moveRight,	ChVrmlWalkSTM,	MoveRightStart);
	AddCell(s_moveRight, 	er_right,	s_alt,			ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_moveRight, 	e_tick,		s_moveRight,	ChVrmlWalkSTM,	MoveRight);
	AddCell(s_moveRight, 	er_alt,		s_right,		ChVrmlWalkSTM,	DefaultHandler);
	// --			
	AddCell(s_start,	ep_lookUp,		s_lookUp, 	ChVrmlWalkSTM,	LookUpStart);
	AddCell(s_lookUp, 	er_lookUp,		s_start,	ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_alt,		ep_lookUpAlt,	s_lookUp, 	ChVrmlWalkSTM,	LookUpStart);
	AddCell(s_lookUp, 	er_lookUpAlt,	s_alt,		ChVrmlWalkSTM,	DefaultHandler);
	//AddCell(s_lookUp, 	er_alt,			s_lookUp,	ChVrmlWalkSTM,	DefaultHandler); //nada
	AddCell(s_lookUp, 	e_tick,			s_lookUp,	ChVrmlWalkSTM,	LookUp);
	// --			
	AddCell(s_start,	ep_lookDown,	s_lookDown, ChVrmlWalkSTM,	LookDownStart);
	AddCell(s_lookDown, er_lookDown,	s_start,	ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_alt,		ep_lookDownAlt,	s_lookDown, ChVrmlWalkSTM,	LookDownStart);
	AddCell(s_lookDown, er_lookDownAlt,	s_alt,		ChVrmlWalkSTM,	DefaultHandler);
	//AddCell(s_lookDown, er_alt,			s_lookDown,	ChVrmlWalkSTM,	DefaultHandler); //nada
	AddCell(s_lookDown, e_tick,			s_lookDown,	ChVrmlWalkSTM,	LookDown);
	//
	// -- Mouse stuff
	//			
	AddCell(s_start,	ep_lbutton,		s_lbuttondown, 		ChVrmlWalkSTM,	WalkStart);
	AddCell(s_lbuttondown, 		er_lbutton,		s_start,	ChVrmlWalkSTM,	LeftClick);
	AddCell(s_lbuttondown, 		e_tick,		s_lbuttondrag,		ChVrmlWalkSTM,	TickWalk);
	AddCell(s_lbuttondown, 		e_move,		s_lbuttondrag,		ChVrmlWalkSTM,	DragWalk);
	AddCell(s_lbuttondown, 		ep_alt,		s_lbuttondownMove,	ChVrmlWalkSTM,	DefaultHandler);

	AddCell(s_alt,	ep_lbutton,		s_lbuttondownMove, 		ChVrmlWalkSTM,	CrabbishStart);
	AddCell(s_lbuttondownMove, 		er_lbutton,		s_alt,	ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_lbuttondownMove, 		e_tick,		s_lbuttondragMove,		ChVrmlWalkSTM,	TickCrabbishly);
	AddCell(s_lbuttondownMove, 		e_move,		s_lbuttondragMove,		ChVrmlWalkSTM,	DragCrabbishly);
	AddCell(s_lbuttondownMove, 		er_alt,		s_lbuttondown,	ChVrmlWalkSTM,	DefaultHandler);

	AddCell(s_lbuttondrag, 		er_lbutton,		s_start,	ChVrmlWalkSTM,	LeftClickSlow);
	AddCell(s_lbuttondrag, 		e_tick,		s_lbuttondrag,		ChVrmlWalkSTM,	TickWalk);
	AddCell(s_lbuttondrag, 		e_move,		s_lbuttondrag,		ChVrmlWalkSTM,	DragWalk);
	AddCell(s_lbuttondrag, 		ep_alt,		s_lbuttondragMove,	ChVrmlWalkSTM,	DefaultHandler);

	AddCell(s_lbuttondragMove, 		er_lbutton,		s_alt,	ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_lbuttondragMove, 		e_tick,		s_lbuttondragMove,		ChVrmlWalkSTM,	TickCrabbishly);
	AddCell(s_lbuttondragMove, 		e_move,		s_lbuttondragMove,		ChVrmlWalkSTM,	DragCrabbishly);
	AddCell(s_lbuttondragMove, 		er_alt,		s_lbuttondrag,	ChVrmlWalkSTM,	DefaultHandler);

//
	AddCell(s_start,	ep_rbutton,		s_rbuttondown, 		ChVrmlWalkSTM,	ExamineStart);
	AddCell(s_rbuttondown, 		er_rbutton,		s_start,	ChVrmlWalkSTM,	RightClick);
	AddCell(s_rbuttondown, 		e_tick,		s_rbuttondrag,		ChVrmlWalkSTM,	Examine);
	AddCell(s_rbuttondown, 		e_move,		s_rbuttondrag,		ChVrmlWalkSTM,	Examine);
	AddCell(s_rbuttondown, 		ep_alt,		s_rbuttondownMove,	ChVrmlWalkSTM,	DefaultHandler);

	AddCell(s_alt,	ep_rbutton,		s_rbuttondownMove, 		ChVrmlWalkSTM,	ExamineStart);
	AddCell(s_rbuttondownMove, 		er_rbutton,		s_alt,	ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_rbuttondownMove, 		e_tick,		s_rbuttondragMove,		ChVrmlWalkSTM,	Examine);
	AddCell(s_rbuttondownMove, 		e_move,		s_rbuttondragMove,		ChVrmlWalkSTM,	Examine);
	AddCell(s_rbuttondownMove, 		er_alt,		s_rbuttondown,	ChVrmlWalkSTM,	DefaultHandler);

	AddCell(s_rbuttondrag, 		er_rbutton,		s_start,	ChVrmlWalkSTM,	RightClickSlow);
	AddCell(s_rbuttondrag, 		e_tick,		s_rbuttondrag,		ChVrmlWalkSTM,	Examine);
	AddCell(s_rbuttondrag, 		e_move,		s_rbuttondrag,		ChVrmlWalkSTM,	Examine);
	AddCell(s_rbuttondrag, 		ep_alt,		s_rbuttondragMove,	ChVrmlWalkSTM,	DefaultHandler);

	AddCell(s_rbuttondragMove, 		er_rbutton,		s_alt,	ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_rbuttondragMove, 		e_tick,		s_rbuttondragMove,		ChVrmlWalkSTM,	Examine);
	AddCell(s_rbuttondragMove, 		e_move,		s_rbuttondragMove,		ChVrmlWalkSTM,	Examine);
	AddCell(s_rbuttondragMove, 		er_alt,		s_rbuttondrag,	ChVrmlWalkSTM,	DefaultHandler);

	// We only get in or out of these states via goto's in actions
	AddCell(s_goTowardsBegin, 	e_tick,		s_goTowards,	ChVrmlWalkSTM,	GoTowardsStart);
	AddCell(s_goTowards, 		e_tick,		s_goTowards,	ChVrmlWalkSTM,	GoTowards);
	// We only get into these states via goto's in actions; we get out by events
	AddCell(s_spinningBegin, 	e_tick,		s_spinning,	ChVrmlWalkSTM,	SpinStart);
	AddCell(s_spinning, 		e_tick,		s_spinning,	ChVrmlWalkSTM,	Spin);

	AddCell(s_spinningBegin,	ep_alt,		s_alt, 		ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_spinningBegin,	ep_up,		s_up, 		ChVrmlWalkSTM,	MoveForwardStart);
	AddCell(s_spinningBegin,	ep_down,	s_down, 	ChVrmlWalkSTM,	MoveReverseStart);
	AddCell(s_spinningBegin,	ep_left,	s_left,		ChVrmlWalkSTM,	TurnLeftStart);
	AddCell(s_spinningBegin,	ep_right,	s_right, 		ChVrmlWalkSTM,	TurnRightStart);
	AddCell(s_spinningBegin,	ep_lookUp,		s_lookUp, 	ChVrmlWalkSTM,	LookUpStart);
	AddCell(s_spinningBegin,	ep_lookDown,	s_lookDown, ChVrmlWalkSTM,	LookDownStart);
	AddCell(s_spinningBegin,	ep_lbutton,		s_lbuttondown, 		ChVrmlWalkSTM,	WalkStart);
	AddCell(s_spinningBegin,	ep_rbutton,		s_rbuttondown, 		ChVrmlWalkSTM,	ExamineStart);

	AddCell(s_spinning,	ep_alt,		s_alt, 		ChVrmlWalkSTM,	DefaultHandler);
	AddCell(s_spinning,	ep_up,		s_up, 		ChVrmlWalkSTM,	MoveForwardStart);
	AddCell(s_spinning,	ep_down,	s_down, 	ChVrmlWalkSTM,	MoveReverseStart);
	AddCell(s_spinning,	ep_left,	s_left,		ChVrmlWalkSTM,	TurnLeftStart);
	AddCell(s_spinning,	ep_right,	s_right, 		ChVrmlWalkSTM,	TurnRightStart);
	AddCell(s_spinning,	ep_lookUp,		s_lookUp, 	ChVrmlWalkSTM,	LookUpStart);
	AddCell(s_spinning,	ep_lookDown,	s_lookDown, ChVrmlWalkSTM,	LookDownStart);
	AddCell(s_spinning,	ep_lbutton,		s_lbuttondown, 		ChVrmlWalkSTM,	WalkStart);
	AddCell(s_spinning,	ep_rbutton,		s_rbuttondown, 		ChVrmlWalkSTM,	ExamineStart);
}

bool ChVrmlWalkSTM::TranslateKeyEvent(int keyMsg, int key, chuint32 modifiers, int &event, chuint32 *&pData)
{
	chflag32		flMods = 0;

	if (GetKeyState( VK_MENU ) & 0x8000)
	{
		flMods |= ACTION_MOD_ALT;
	}

	if (keyMsg == WM_KEYUP || keyMsg == WM_SYSKEYUP)
	{
		flMods |= ACTION_MOD_KEY_UP;
	}
	
	if (GetKeyState( VK_SHIFT ) & 0x8000)
	{
		flMods |= ACTION_MOD_SHIFT;
		m_keyFlags &= ~kd_shift;
	}

	if (GetKeyState( VK_CONTROL ) & 0x8000)
	{
		flMods |= ACTION_MOD_CONTROL;
		m_keyFlags &= ~kd_ctl;
	}

	bool boolFound = true;
	if(flMods & ACTION_MOD_KEY_UP)
	{
		switch(key)
		{
			case VK_UP:
			{
				event = er_up;
				m_keyFlags &= ~kd_up;
				break;
			}
			case VK_DOWN:
			{
				event = er_down;
				m_keyFlags &= ~kd_down;
				break;
			}
			case VK_LEFT:
			{
				event = er_left;
				m_keyFlags &= ~kd_left;
				break;
			}
			case VK_RIGHT:
			{
				event = er_right;
				m_keyFlags &= ~kd_right;
				break;
			}
			case 'A':
			{
				if(flMods & ACTION_MOD_ALT)
				{
					event = er_lookUpAlt;
				}
				else
				{
					event = er_lookUp;
				}
				m_keyFlags &= ~kd_lookUp;
				break;
			}
			case 'Z':
			{
				if(flMods & ACTION_MOD_ALT)
				{
					event = er_lookDownAlt;
				}
				else
				{
					event = er_lookDown;
				}
				m_keyFlags &= ~kd_lookDown;
				break;
			}
			case VK_MENU:
			{
				event = er_alt;
				m_keyFlags &= ~kd_alt;
				break;
			}
			default:
			{
				boolFound = false;
			}
		}
	}
	else
	{
		switch(key)
		{
			case VK_UP:
			{
				event = ep_up;
				m_keyFlags |= kd_up;
				break;
			}
			case VK_DOWN:
			{
				event = ep_down;
				m_keyFlags |= kd_down;
				break;
			}
			case VK_LEFT:
			{
				event = ep_left;
				m_keyFlags |= kd_left;
				break;
			}
			case VK_RIGHT:
			{
				event = ep_right;
				m_keyFlags |= kd_right;
				break;
			}
			case 'A':
			{
				if(flMods & ACTION_MOD_ALT)
				{
					event = ep_lookUpAlt;
				}
				else
				{
					event = ep_lookUp;
				}
				m_keyFlags |= kd_lookUp;
				break;
			}
			case 'Z':
			{
				if(flMods & ACTION_MOD_ALT)
				{
					event = ep_lookDownAlt;
				}
				else
				{
					event = ep_lookDown;
				}
				m_keyFlags |= kd_lookDown;
				break;
			}
			case VK_MENU:
			{
				event = ep_alt;
				m_keyFlags |= kd_alt;
				break;
			}
			default:
			{
				boolFound = false;
			}
		}
	}

	if (boolFound)
	{

		m_flags = flMods;
		return true;
	}

	return false;
};

// Handlers
bool ChVrmlWalkSTM::MoveForwardStart()
{
	RecordTime();
	m_pWnd->GetCameraControl()->HeadsUp();	
	MoveForward( );
	return true;
};	   

bool ChVrmlWalkSTM::MoveReverseStart()
{
	RecordTime();
	m_pWnd->GetCameraControl()->HeadsUp();
	MoveReverse( );
	return true;
};	   

bool ChVrmlWalkSTM::MoveUpStart()
{
	RecordTime();
	m_pWnd->GetCameraControl()->HeadsUp();
	MoveUp( );
	return true;
};	   

bool ChVrmlWalkSTM::MoveDownStart()
{
	RecordTime();
	m_pWnd->GetCameraControl()->HeadsUp();
	MoveDown( );
	return true;
};	   

bool ChVrmlWalkSTM::TurnLeftStart()
{
	RecordTime();
	m_pWnd->GetCameraControl()->HeadsUp();
	TurnLeft( );
	return true;
};	   

bool ChVrmlWalkSTM::MoveLeftStart()
{
	RecordTime();
	m_pWnd->GetCameraControl()->HeadsUp();
	MoveLeft( );
	return true;
};	   

bool ChVrmlWalkSTM::TurnRightStart()
{
	RecordTime();
	m_pWnd->GetCameraControl()->HeadsUp();
	TurnRight( );
	return true;
};	   

bool ChVrmlWalkSTM::MoveRightStart()
{
	RecordTime();
	m_pWnd->GetCameraControl()->HeadsUp();
	MoveRight( );
	return true;
};	   

bool ChVrmlWalkSTM::LookUpStart()
{
	RecordTime();
	m_pWnd->GetCameraControl()->HeadsUp();
	LookUp( );
	return true;
};	   

bool ChVrmlWalkSTM::LookDownStart()
{
	RecordTime();
	m_pWnd->GetCameraControl()->HeadsUp();
	LookDown( );
	return true;
};	   

bool ChVrmlWalkSTM::MoveForward()
{
	m_pWnd->GetCameraControl()->HeadsUp();	// Ought to break all these out into "start" methods
											// for efficiency's sake.
	m_pWnd->GetCameraControl()->WalkForward( GetMoveAmountDistance() );
	RecordTime();
	return true;
};	   

bool ChVrmlWalkSTM::MoveReverse()
{
	m_pWnd->GetCameraControl()->HeadsUp();
	m_pWnd->GetCameraControl()->WalkBackward( GetMoveAmountDistance() );
	RecordTime();
	return true;
};	   

bool ChVrmlWalkSTM::MoveUp()
{
	m_pWnd->GetCameraControl()->HeadsUp();
	m_pWnd->GetCameraControl()->Shift( 0., GetMoveAmountDistance(), 0. );
	RecordTime();
	return true;
};	   

bool ChVrmlWalkSTM::MoveDown()
{
	m_pWnd->GetCameraControl()->HeadsUp();
	m_pWnd->GetCameraControl()->Shift( 0., -GetMoveAmountDistance(), 0. );
	RecordTime();
	return true;
};	   

bool ChVrmlWalkSTM::TurnLeft()
{
	m_pWnd->GetCameraControl()->HeadsUp();
	m_pWnd->GetCameraControl()->Turn( GetMoveAmountAngle() );
	RecordTime();
	return true;
};	   

bool ChVrmlWalkSTM::MoveLeft()
{
	m_pWnd->GetCameraControl()->HeadsUp();
	m_pWnd->GetCameraControl()->MoveLeft( GetMoveAmountDistance() );
	return true;
};	   

bool ChVrmlWalkSTM::TurnRight()
{
	m_pWnd->GetCameraControl()->HeadsUp();
	m_pWnd->GetCameraControl()->Turn( -(GetMoveAmountAngle()) );
	RecordTime();
	return true;
};	   

bool ChVrmlWalkSTM::MoveRight()
{
	m_pWnd->GetCameraControl()->HeadsUp();
	m_pWnd->GetCameraControl()->MoveRight( GetMoveAmountDistance() );
	return true;
};	   

bool ChVrmlWalkSTM::LookUp()
{
	m_pWnd->GetCameraControl()->HeadsUp();
	m_pWnd->GetCameraControl()->Pitch( (GetMoveAmountAngle()) );
	RecordTime();
	return true;
};	   

bool ChVrmlWalkSTM::LookDown()
{
	m_pWnd->GetCameraControl()->HeadsUp();
	m_pWnd->GetCameraControl()->Pitch( -(GetMoveAmountAngle()) );
	RecordTime();
	return true;
};	   


bool ChVrmlWalkSTM::WalkStart()
{
	RecordTime();
	RecordPressTime();
	m_iAnchorX = m_ix;
	m_iAnchorY = m_iy;

	m_pWnd->GetCameraControl()->HeadsUp();
	return true;
};	   

bool ChVrmlWalkSTM::CrabbishStart()
{
	RecordTime();
	RecordPressTime();
	m_iAnchorX = m_ix;
	m_iAnchorY = m_iy;

	m_pWnd->GetCameraControl()->HeadsUp();
	return true;
};	   

const float HACK_HACK = 10.;
const float HACK_HACK_ANGLE = 40.;

bool ChVrmlWalkSTM::DragWalk()
{
		
	return true;
};	   

bool ChVrmlWalkSTM::DragCrabbishly()
{
	return true;
};	   


bool ChVrmlWalkSTM::TickWalk()
{
	float		fMoveX, fMoveY;

	fMoveX = GetMoveAmountAngle(m_iAnchorX - m_ix);
	//fMoveX /= HACK_HACK_ANGLE;

	fMoveY = m_iAnchorY - m_iy;
	fMoveY /= HACK_HACK;

	m_pWnd->GetCameraControl()->WalkForward( m_pWnd->CalcAccel( fMoveY ), false );
	m_pWnd->GetCameraControl()->Turn( fMoveX );
	RecordTime();

	return true;
};	   

bool ChVrmlWalkSTM::TickCrabbishly()
{
	float		fMoveX, fMoveY;

	fMoveX = m_iAnchorX - m_ix;
	fMoveX /= HACK_HACK;

	fMoveY = m_iAnchorY - m_iy;
	fMoveY /= HACK_HACK;

	m_pWnd->GetCameraControl()->Shift( 0., m_pWnd->CalcAccel( fMoveY ), 0., false );  // absolutely up
	m_pWnd->GetCameraControl()->MoveLeft(  m_pWnd->CalcAccel( fMoveX ) );
	RecordTime();

	return true;
};	   


bool ChVrmlWalkSTM::LeftClick()
{
	if(GetKeyState( VK_CONTROL ) & 0x8000)
	{
#if !defined(CH_USE_3DR)
		SetState(s_goTowardsBegin);
#endif
		return false;
	}
	else 
	{
		//TRACE3("Left Clicked. x = %d, y = %d, flags = %lx\n", m_ix, m_iy, m_mouseFlags);
		OnLeftClick(m_ix, m_iy, m_mouseFlags);
		return true;
	}
};	   

bool ChVrmlWalkSTM::LeftClickSlow()
{
	//TRACE1("Click time : %d\n", GetElapsedPressTicks() < maxClickTicks);
	if(IsWithinFastClickTime())
	{
		return LeftClick();
	}
	return true;
};	   


bool ChVrmlWalkSTM::RightClick()
{
	OnRightClick(m_ix, m_iy, m_mouseFlags);
	return true;
};	   

bool ChVrmlWalkSTM::RightClickSlow()
{
	if(m_mouseAvgVelocity.magnitude() > spinThresholdSpeed)
	{
		SetState(s_spinningBegin);
		return false;
	}                               
	else if(IsWithinFastClickTime())
	{
		return RightClick();
	}
	return true;
};	   

bool ChVrmlWalkSTM::GoTowardsStart()
{
#if !defined(CH_USE_3DR)
	GxVec3f	target;
	bool boolHit = m_pWnd->GetRenderContext()->GetHitPoint(m_ix, m_iy, target);

	if(boolHit)
	{
		RecordTime();
		//m_pWnd->GetCameraControl()->LookAt( target, false );	  // Turn towards it
		m_pWnd->GetCameraControl()->HeadsUp( );	  
		m_target = target;

		GxVec3f	camLoc = m_pWnd->GetRenderContext()->GetCameraLoc();
		target += camLoc;
		target *= .5;					// Go halfway there, not keeping y constant
		//target.y() = camLoc.y();		   

		m_startLook = ((ChQvPCameraRenderData *)(m_pWnd->GetRenderContext()->GetCurrentCamera()->GetRenderData()))->GetDir();
		m_destination = target;
		m_start = camLoc;
	}
	else
	{
		if(GetKeyState( VK_MENU ) & 0x8000) SetState(s_alt);
		else SetState(s_start);
		return false;
	}
#endif
	return true;
}

bool ChVrmlWalkSTM::GoTowards()
{
#if !defined(CH_USE_3DR)
	GxVec3f	camLoc = m_pWnd->GetRenderContext()->GetCameraLoc();
	GxVec3f	target = m_target;
	GxVec3f	start = m_start;
	GxVec3f	destination = m_destination;

	float perCent = GetElapsedTicks() / float(animMoveTowardsTicks);	// how far we 'oughta' be
	if(GetKeyState( VK_SHIFT ) & 0x8000) perCent *= 2;

	perCent = min(perCent, 1.0);
	perCent = Smooth(perCent);

	//camLoc.y() = destination.y() = start.y() = 0;	// ignore y

	GxVec3f v = destination;
	v -= start;			// vector to move total
	v *= perCent;		// vector we should have moved
	v += start;			// where we oughta be
	v -= camLoc;		// how far we have to go, vectorish

	// Now compute the new lookDirection; linearly interpolate from original
	// look direction to final, which is staring right at target
	GxVec3f startLook = m_startLook;

	GxVec3f endLook = m_target;
	endLook -= m_destination;
	endLook.normalize();

	startLook *= (1.0 - perCent);
	endLook *= perCent;

	GxVec3f lookDir = endLook;
	lookDir += startLook;

	lookDir.normalize;

	m_pWnd->GetCameraControl()->Shift( v.x(), v.y(), v.z(), false );
	m_pWnd->GetCameraControl()->SetLookDir( lookDir, false );	  // Turn towards it
	m_pWnd->GetCameraControl()->HeadsUp( );	  

	if(perCent >= 1.0)
	{
		if(GetKeyState( VK_MENU ) & 0x8000) SetState(s_alt);
		else SetState(s_start);
		return false;
	}
#endif
	return true;

}




// --------------------------------------------------------------------------
// Flier
// --------------------------------------------------------------------------

ChVrmlFlySTM::ChVrmlFlySTM(ChMazeWnd *pWnd) : ChVrmlStateTransition(pWnd) 
{
	Init();
}

void ChVrmlFlySTM::Init()
{

	// Now populate the STM
	// SetCell( int iState, int iEvent, int iNewState, ChTransitionActionHandler action)

	AddCell(s_start,	ep_alt,		s_alt, 		ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_alt,		er_alt,		s_start, 	ChVrmlFlySTM,	DefaultHandler);
				
	// --			
	AddCell(s_start,	ep_up,		s_up, 		ChVrmlFlySTM,	TurnUpStart);
	AddCell(s_up, 		er_up,		s_start,	ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_up, 		e_tick,		s_up,		ChVrmlFlySTM,	TurnUp);
	AddCell(s_up, 		ep_alt,		s_moveUp,	ChVrmlFlySTM,	DefaultHandler);

	AddCell(s_alt,		ep_up,		s_moveUp,	ChVrmlFlySTM,	MoveUpStart);
	AddCell(s_moveUp, 	er_up,		s_alt,		ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_moveUp, 	e_tick,		s_moveUp,	ChVrmlFlySTM,	MoveUp);
	AddCell(s_moveUp, 	er_alt,		s_up,		ChVrmlFlySTM,	DefaultHandler);
	// --			
	AddCell(s_start,	ep_down,	s_down, 	ChVrmlFlySTM,	TurnDownStart);
	AddCell(s_down, 	er_down,	s_start,	ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_down, 	e_tick,		s_down,		ChVrmlFlySTM,	TurnDown);
	AddCell(s_down, 	ep_alt,		s_moveDown,	ChVrmlFlySTM,	DefaultHandler);

	AddCell(s_alt,			ep_down,	s_moveDown,	ChVrmlFlySTM,	MoveDownStart);
	AddCell(s_moveDown, 	er_down,	s_alt,		ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_moveDown, 	e_tick,		s_moveDown,	ChVrmlFlySTM,	MoveDown);
	AddCell(s_moveDown, 	er_alt,		s_down,		ChVrmlFlySTM,	DefaultHandler);
	// --			
	AddCell(s_start,		ep_left,	s_left,		ChVrmlFlySTM,	TurnLeftStart);
	AddCell(s_left, 		er_left,	s_start,	ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_left, 		e_tick,		s_left,		ChVrmlFlySTM,	TurnLeft);
	AddCell(s_left, 		ep_alt,		s_moveLeft,	ChVrmlFlySTM,	DefaultHandler);

	AddCell(s_alt,			ep_left,	s_moveLeft,	ChVrmlFlySTM,	MoveLeftStart);
	AddCell(s_moveLeft, 	er_left	,	s_alt,		ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_moveLeft, 	e_tick,		s_moveLeft,	ChVrmlFlySTM,	MoveLeft);
	AddCell(s_moveLeft, 	er_alt,		s_left,		ChVrmlFlySTM,	DefaultHandler);
	// --			
	AddCell(s_start,		ep_right,	s_right, 		ChVrmlFlySTM,	TurnRightStart);
	AddCell(s_right, 		er_right,	s_start,		ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_right, 		e_tick,		s_right,		ChVrmlFlySTM,	TurnRight);
	AddCell(s_right, 		ep_alt,		s_moveRight,	ChVrmlFlySTM,	DefaultHandler);

	AddCell(s_alt,			ep_right,	s_moveRight,	ChVrmlFlySTM,	MoveRightStart);
	AddCell(s_moveRight, 	er_right,	s_alt,			ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_moveRight, 	e_tick,		s_moveRight,	ChVrmlFlySTM,	MoveRight);
	AddCell(s_moveRight, 	er_alt,		s_right,		ChVrmlFlySTM,	DefaultHandler);
	// --			
	AddCell(s_start,			ep_thrustForward,		s_thrustForward, 	ChVrmlFlySTM,	MoveForwardStart);
	AddCell(s_thrustForward, 	er_thrustForward,		s_start,			ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_alt,				ep_thrustForwardAlt,	s_thrustForward, 	ChVrmlFlySTM,	MoveForwardStart);
	AddCell(s_thrustForward, 	er_thrustForwardAlt,	s_alt,				ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_thrustForward, 	e_tick,					s_thrustForward,	ChVrmlFlySTM,	MoveForward);
	// --			
	AddCell(s_start,		ep_thrustBack,		s_thrustBack, 	ChVrmlFlySTM,	MoveReverseStart);
	AddCell(s_thrustBack, 	er_thrustBack,		s_start,		ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_alt,			ep_thrustBackAlt,	s_thrustBack, 	ChVrmlFlySTM,	MoveReverseStart);
	AddCell(s_thrustBack, 	er_thrustBackAlt,	s_alt,			ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_thrustBack, 	e_tick,				s_thrustBack,	ChVrmlFlySTM,	MoveReverse);
	// --			
	AddCell(s_start,			ep_rollRight,		s_rollRight, 	ChVrmlFlySTM,	RollRightStart);
	AddCell(s_rollRight, 	er_rollRight,		s_start,			ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_alt,				ep_rollRightAlt,	s_rollRight, 	ChVrmlFlySTM,	RollRightStart);
	AddCell(s_rollRight, 	er_rollRightAlt,	s_alt,				ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_rollRight, 	e_tick,					s_rollRight,	ChVrmlFlySTM,	RollRight);
	// --			
	AddCell(s_start,		ep_rollLeft,		s_rollLeft, 	ChVrmlFlySTM,	RollLeftStart);
	AddCell(s_rollLeft, 	er_rollLeft,		s_start,		ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_alt,			ep_rollLeftAlt,	s_rollLeft, 	ChVrmlFlySTM,	RollLeftStart);
	AddCell(s_rollLeft, 	er_rollLeftAlt,	s_alt,			ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_rollLeft, 	e_tick,				s_rollLeft,	ChVrmlFlySTM,	RollLeft);
	//
	// -- Mouse stuff
	//			
	AddCell(s_start,	ep_lbutton,		s_lbuttondown, 		ChVrmlFlySTM,	FlyStart);
	AddCell(s_lbuttondown, 		er_lbutton,		s_start,	ChVrmlFlySTM,	LeftClick);
	AddCell(s_lbuttondown, 		e_tick,		s_lbuttondrag,		ChVrmlFlySTM,	TickFly);
	AddCell(s_lbuttondown, 		e_move,		s_lbuttondrag,		ChVrmlFlySTM,	DragFly);
	AddCell(s_lbuttondown, 		ep_alt,		s_lbuttondownMove,	ChVrmlFlySTM,	DefaultHandler);

	AddCell(s_thrustBack,	ep_lbutton,		s_lbuttondown, 		ChVrmlFlySTM,	FlyStart);

	AddCell(s_alt,	ep_lbutton,		s_lbuttondownMove, 		ChVrmlFlySTM,	CrabbishStart);
	AddCell(s_lbuttondownMove, 		er_lbutton,		s_alt,	ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_lbuttondownMove, 		e_tick,		s_lbuttondragMove,		ChVrmlFlySTM,	TickCrabbishly);
	AddCell(s_lbuttondownMove, 		e_move,		s_lbuttondragMove,		ChVrmlFlySTM,	DragCrabbishly);
	AddCell(s_lbuttondownMove, 		er_alt,		s_lbuttondown,	ChVrmlFlySTM,	DefaultHandler);

	AddCell(s_lbuttondrag, 		er_lbutton,		s_start,	ChVrmlFlySTM,	LeftClickSlow);
	AddCell(s_lbuttondrag, 		e_tick,		s_lbuttondrag,		ChVrmlFlySTM,	TickFly);
	AddCell(s_lbuttondrag, 		e_move,		s_lbuttondrag,		ChVrmlFlySTM,	DragFly);
	AddCell(s_lbuttondrag, 		ep_alt,		s_lbuttondragMove,	ChVrmlFlySTM,	DefaultHandler);

	AddCell(s_lbuttondragMove, 		er_lbutton,		s_alt,	ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_lbuttondragMove, 		e_tick,		s_lbuttondragMove,		ChVrmlFlySTM,	TickCrabbishly);
	AddCell(s_lbuttondragMove, 		e_move,		s_lbuttondragMove,		ChVrmlFlySTM,	DragCrabbishly);
	AddCell(s_lbuttondragMove, 		er_alt,		s_lbuttondrag,	ChVrmlFlySTM,	DefaultHandler);

//
	AddCell(s_start,	ep_rbutton,		s_rbuttondown, 		ChVrmlFlySTM,	ExamineStart);
	AddCell(s_rbuttondown, 		er_rbutton,		s_start,	ChVrmlFlySTM,	RightClick);
	AddCell(s_rbuttondown, 		e_tick,		s_rbuttondrag,		ChVrmlFlySTM,	Examine);
	AddCell(s_rbuttondown, 		e_move,		s_rbuttondrag,		ChVrmlFlySTM,	Examine);
	AddCell(s_rbuttondown, 		ep_alt,		s_rbuttondownMove,	ChVrmlFlySTM,	DefaultHandler);

	AddCell(s_alt,	ep_rbutton,		s_rbuttondownMove, 		ChVrmlFlySTM,	ExamineStart);
	AddCell(s_rbuttondownMove, 		er_rbutton,		s_alt,	ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_rbuttondownMove, 		e_tick,		s_rbuttondragMove,		ChVrmlFlySTM,	Examine);
	AddCell(s_rbuttondownMove, 		e_move,		s_rbuttondragMove,		ChVrmlFlySTM,	Examine);
	AddCell(s_rbuttondownMove, 		er_alt,		s_rbuttondown,	ChVrmlFlySTM,	DefaultHandler);

	AddCell(s_rbuttondrag, 		er_rbutton,		s_start,	ChVrmlFlySTM,	RightClickSlow);
	AddCell(s_rbuttondrag, 		e_tick,		s_rbuttondrag,		ChVrmlFlySTM,	Examine);
	AddCell(s_rbuttondrag, 		e_move,		s_rbuttondrag,		ChVrmlFlySTM,	Examine);
	AddCell(s_rbuttondrag, 		ep_alt,		s_rbuttondragMove,	ChVrmlFlySTM,	DefaultHandler);

	AddCell(s_rbuttondragMove, 		er_rbutton,		s_alt,	ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_rbuttondragMove, 		e_tick,		s_rbuttondragMove,		ChVrmlFlySTM,	Examine);
	AddCell(s_rbuttondragMove, 		e_move,		s_rbuttondragMove,		ChVrmlFlySTM,	Examine);
	AddCell(s_rbuttondragMove, 		er_alt,		s_rbuttondrag,	ChVrmlFlySTM,	DefaultHandler);

	// We only get in or out of these states via goto's in actions
	AddCell(s_goTowardsBegin, 	e_tick,		s_goTowards,	ChVrmlFlySTM,	GoTowardsStart);
	AddCell(s_goTowards, 		e_tick,		s_goTowards,	ChVrmlFlySTM,	GoTowards);

	// We only get into these states via goto's in actions; we get out by events
	AddCell(s_spinningBegin, 	e_tick,		s_spinning,	ChVrmlFlySTM,	SpinStart);
	AddCell(s_spinning, 		e_tick,		s_spinning,	ChVrmlFlySTM,	Spin);

	AddCell(s_spinningBegin,	ep_alt,		s_alt, 		ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_spinningBegin,	ep_up,		s_up, 		ChVrmlFlySTM,	TurnUpStart);
	AddCell(s_spinningBegin,	ep_down,	s_down, 	ChVrmlFlySTM,	TurnDownStart);
	AddCell(s_spinningBegin,	ep_left,	s_left,		ChVrmlFlySTM,	TurnLeftStart);
	AddCell(s_spinningBegin,	ep_right,	s_right, 		ChVrmlFlySTM,	TurnRightStart);
	AddCell(s_spinningBegin,	ep_thrustForward,		s_thrustForward, 	ChVrmlFlySTM,	MoveForwardStart);
	AddCell(s_spinningBegin,	ep_thrustBack,		s_thrustBack, 	ChVrmlFlySTM,	MoveReverseStart);
	AddCell(s_spinningBegin,	ep_lbutton,		s_lbuttondown, 		ChVrmlFlySTM,	FlyStart);
	AddCell(s_spinningBegin,	ep_rbutton,		s_rbuttondown, 		ChVrmlFlySTM,	ExamineStart);

	AddCell(s_spinning,	ep_alt,		s_alt, 		ChVrmlFlySTM,	DefaultHandler);
	AddCell(s_spinning,	ep_up,		s_up, 		ChVrmlFlySTM,	TurnUpStart);
	AddCell(s_spinning,	ep_down,	s_down, 	ChVrmlFlySTM,	TurnDownStart);
	AddCell(s_spinning,	ep_left,	s_left,		ChVrmlFlySTM,	TurnLeftStart);
	AddCell(s_spinning,	ep_right,	s_right, 		ChVrmlFlySTM,	TurnRightStart);
	AddCell(s_spinning,	ep_thrustForward,		s_thrustForward, 	ChVrmlFlySTM,	MoveForwardStart);
	AddCell(s_spinning,	ep_thrustBack,		s_thrustBack, 	ChVrmlFlySTM,	MoveReverseStart);
	AddCell(s_spinning,	ep_lbutton,		s_lbuttondown, 		ChVrmlFlySTM,	FlyStart);
	AddCell(s_spinning,	ep_rbutton,		s_rbuttondown, 		ChVrmlFlySTM,	ExamineStart);
}

bool ChVrmlFlySTM::TranslateKeyEvent(int keyMsg, int key, chuint32 modifiers, int &event, chuint32 *&pData)
{
	chflag32		flMods = 0;

	if (GetKeyState( VK_MENU ) & 0x8000)
	{
		flMods |= ACTION_MOD_ALT;
	}

	if (keyMsg == WM_KEYUP || keyMsg == WM_SYSKEYUP)
	{
		flMods |= ACTION_MOD_KEY_UP;
	}
	
	if (GetKeyState( VK_SHIFT ) & 0x8000)
	{
		flMods |= ACTION_MOD_SHIFT;
		m_keyFlags &= ~kd_shift;
	}

	if (GetKeyState( VK_CONTROL ) & 0x8000)
	{
		flMods |= ACTION_MOD_CONTROL;
		m_keyFlags &= ~kd_ctl;
	}

	bool boolFound = true;
	if(flMods & ACTION_MOD_KEY_UP)
	{
		switch(key)
		{
			case VK_UP:
			{
				event = er_up;
				m_keyFlags &= ~kd_up;
				break;
			}
			case VK_DOWN:
			{
				event = er_down;
				m_keyFlags &= ~kd_down;
				break;
			}
			case VK_LEFT:
			{
				event = er_left;
				m_keyFlags &= ~kd_left;
				break;
			}
			case VK_RIGHT:
			{
				event = er_right;
				m_keyFlags &= ~kd_right;
				break;
			}
			case 'A':
			{
				if(flMods & ACTION_MOD_ALT)
				{
					event = er_thrustForwardAlt;
				}
				else
				{
					event = er_thrustForward;
				}
				m_keyFlags &= ~kd_thrustForward;
				break;
			}
			case 'Z':
			{
				if(flMods & ACTION_MOD_ALT)
				{
					event = er_thrustBackAlt;
				}
				else
				{
					event = er_thrustBack;
				}
				m_keyFlags &= ~kd_thrustBack;
				break;
			}
			case 'Q':
			{
				if(flMods & ACTION_MOD_ALT)
				{
					event = er_rollLeftAlt;
				}
				else
				{
					event = er_rollLeft;
				}
				m_keyFlags &= ~kd_rollLeft;
				break;
			}
			case 'E':
			{
				if(flMods & ACTION_MOD_ALT)
				{
					event = er_rollRightAlt;
				}
				else
				{
					event = er_rollRight;
				}
				m_keyFlags &= ~kd_rollRight;
				break;
			}
			case VK_MENU:
			{
				event = er_alt;
				m_keyFlags &= ~kd_alt;
				break;
			}
			default:
			{
				boolFound = false;
			}
		}
	}
	else
	{
		switch(key)
		{
			case VK_UP:
			{
				event = ep_up;
				m_keyFlags |= kd_up;
				break;
			}
			case VK_DOWN:
			{
				event = ep_down;
				m_keyFlags |= kd_down;
				break;
			}
			case VK_LEFT:
			{
				event = ep_left;
				m_keyFlags |= kd_left;
				break;
			}
			case VK_RIGHT:
			{
				event = ep_right;
				m_keyFlags |= kd_right;
				break;
			}
			case 'A':
			{
				if(flMods & ACTION_MOD_ALT)
				{
					event = ep_thrustForwardAlt;
				}
				else
				{
					event = ep_thrustForward;
				}
				break;
				m_keyFlags |= kd_thrustForward;
			}
			case 'Z':
			{
				if(flMods & ACTION_MOD_ALT)
				{
					event = ep_thrustBackAlt;
				}
				else
				{
					event = ep_thrustBack;
				}
				m_keyFlags |= kd_thrustBack;
				break;
			}
			case 'Q':
			{
				if(flMods & ACTION_MOD_ALT)
				{
					event = ep_rollLeftAlt;
				}
				else
				{
					event = ep_rollLeft;
				}
				m_keyFlags |= kd_rollLeft;
				break;
			}
			case 'E':
			{
				if(flMods & ACTION_MOD_ALT)
				{
					event = ep_rollRightAlt;
				}
				else
				{
					event = ep_rollRight;
				}
				m_keyFlags |= kd_rollRight;
				break;
			}
			case VK_MENU:
			{
				event = ep_alt;
				m_keyFlags |= kd_alt;
				break;
			}
			default:
			{
				boolFound = false;
			}
		}
	}

	if (boolFound)
	{

		m_flags = flMods;
		return true;
	}

	return false;
};

// Handlers
bool ChVrmlFlySTM::MoveForwardStart()
{
	RecordTime();
	MoveForward( );
	return true;
};	   

bool ChVrmlFlySTM::MoveReverseStart()
{
	RecordTime();
	MoveReverse( );
	return true;
};	   

bool ChVrmlFlySTM::MoveUpStart()
{
	RecordTime();
	MoveUp( );
	return true;
};	   

bool ChVrmlFlySTM::MoveDownStart()
{
	RecordTime();
	MoveDown( );
	return true;
};	   

bool ChVrmlFlySTM::TurnLeftStart()
{
	RecordTime();
	TurnLeft( );
	return true;
};	   

bool ChVrmlFlySTM::RollLeftStart()
{
	RecordTime();
	RollLeft( );
	return true;
};	   

bool ChVrmlFlySTM::MoveLeftStart()
{
	RecordTime();
	MoveLeft( );
	return true;
};	   

bool ChVrmlFlySTM::TurnRightStart()
{
	RecordTime();
	TurnRight( );
	return true;
};	   

bool ChVrmlFlySTM::RollRightStart()
{
	RecordTime();
	RollRight( );
	return true;
};	   

bool ChVrmlFlySTM::MoveRightStart()
{
	RecordTime();
	MoveRight( );
	return true;
};	   

bool ChVrmlFlySTM::TurnUpStart()
{
	RecordTime();
	TurnUp( );
	return true;
};	   

bool ChVrmlFlySTM::TurnDownStart()
{
	RecordTime();
	TurnDown( );
	return true;
};	   

bool ChVrmlFlySTM::MoveForward()
{
	m_pWnd->GetCameraControl()->MoveForward( GetMoveAmountDistance() );
	RecordTime();
	return true;
};	   

bool ChVrmlFlySTM::MoveReverse()
{
	m_pWnd->GetCameraControl()->MoveBackward( GetMoveAmountDistance() );
	RecordTime();
	return true;
};	   

bool ChVrmlFlySTM::MoveUp()
{
	m_pWnd->GetCameraControl()->MoveUp( GetMoveAmountDistance() );
	RecordTime();
	return true;
};	   

bool ChVrmlFlySTM::MoveDown()
{
	m_pWnd->GetCameraControl()->MoveDown(  GetMoveAmountDistance() );
	RecordTime();
	return true;
};	   

bool ChVrmlFlySTM::TurnLeft()
{
	m_pWnd->GetCameraControl()->Yaw( GetMoveAmountAngle() );
	RecordTime();
	return true;
};	   

bool ChVrmlFlySTM::RollLeft()	// CCW camera roll
{
	m_pWnd->GetCameraControl()->Roll( - 2 * GetMoveAmountAngle() );
	RecordTime();
	return true;
};	   

bool ChVrmlFlySTM::MoveLeft()
{
	m_pWnd->GetCameraControl()->MoveLeft( GetMoveAmountDistance() );
	return true;
};	   

bool ChVrmlFlySTM::TurnRight()
{
	m_pWnd->GetCameraControl()->Yaw( -(GetMoveAmountAngle()) );
	RecordTime();
	return true;
};	   

bool ChVrmlFlySTM::RollRight()	 // CW for the camera - image goes ccw
{
	m_pWnd->GetCameraControl()->Roll( 2 * (GetMoveAmountAngle()) );
	RecordTime();
	return true;
};	   

bool ChVrmlFlySTM::MoveRight()
{
	m_pWnd->GetCameraControl()->MoveRight( GetMoveAmountDistance() );
	return true;
};	   

bool ChVrmlFlySTM::TurnUp()
{
	m_pWnd->GetCameraControl()->Pitch( (GetMoveAmountAngle()) );
	RecordTime();
	return true;
};	   

bool ChVrmlFlySTM::TurnDown()
{
	m_pWnd->GetCameraControl()->Pitch( -(GetMoveAmountAngle()) );
	RecordTime();
	return true;
};	   


bool ChVrmlFlySTM::FlyStart()
{
	RecordTime();
	RecordPressTime();
	m_iAnchorX = m_ix;
	m_iAnchorY = m_iy;

	return true;
};	   

bool ChVrmlFlySTM::CrabbishStart()
{
	RecordTime();
	RecordPressTime();
	m_iAnchorX = m_ix;
	m_iAnchorY = m_iy;

	return true;
};	   


bool ChVrmlFlySTM::DragFly()
{
		
	return true;
};	   

bool ChVrmlFlySTM::DragCrabbishly()
{
	return true;
};	   


bool ChVrmlFlySTM::TickFly()
{
	float		fMoveX, fMoveY;

	if(!(GetKeyState( VK_CONTROL ) & 0x8000))
	{
		fMoveX = GetMoveAmountAngle(m_iAnchorX - m_ix);
		//fMoveX /= HACK_HACK_ANGLE;

		fMoveY = GetMoveAmountAngle(m_iAnchorY - m_iy);
		//fMoveY /= HACK_HACK_ANGLE;

		float fDistance = GetMoveAmountDistance();
		if(GetKeyState( 'Z' ) & 0x8000)
		{
			fDistance = -fDistance;
		}

		if(fMoveX != 0.0)
		{
			m_pWnd->GetCameraControl()->Yaw( fMoveX, true );   // set dirty for no
															   // to cause use of smarter collision tester
		}
		if(fMoveX != 0.0)
		{
			m_pWnd->GetCameraControl()->Pitch( fMoveY, true );
		}
		m_pWnd->GetCameraControl()->MoveForward( fDistance );
		RecordTime();
	}
	return true;
};	   

bool ChVrmlFlySTM::TickCrabbishly()
{
	float		fMoveX, fMoveY;

	fMoveX = m_iAnchorX - m_ix;
	fMoveX /= HACK_HACK;

	fMoveY = m_iAnchorY - m_iy;
	fMoveY /= HACK_HACK;

	m_pWnd->GetCameraControl()->MoveUp(  m_pWnd->CalcAccel( fMoveY ), false );  // relatively up
	m_pWnd->GetCameraControl()->MoveLeft(  m_pWnd->CalcAccel( fMoveX ) );
	RecordTime();

	return true;
};	   


bool ChVrmlFlySTM::LeftClick()
{
	if(GetKeyState( VK_CONTROL ) & 0x8000)
	{
#if !defined(CH_USE_3DR)

		SetState(s_goTowardsBegin);
		return false;
#endif
	}
	else 
	{
		OnLeftClick(m_ix, m_iy, m_mouseFlags);
	}

	return true;
};	   

bool ChVrmlFlySTM::LeftClickSlow()
{
	if(IsWithinFastClickTime())
	{
		return LeftClick();
	}
	else if(GetKeyState( 'Z' ) & 0x8000)
	{
		SetState(s_thrustBack);
		return false;
	}
	return true;
};	   


bool ChVrmlFlySTM::RightClick()
{
	OnRightClick(m_ix, m_iy, m_mouseFlags);
	return true;
};	   

bool ChVrmlFlySTM::RightClickSlow()
{   
	if(m_mouseAvgVelocity.magnitude() > spinThresholdSpeed)
	{
		SetState(s_spinningBegin);
		return false;
	}                               
	else if(IsWithinFastClickTime())
	{
		return RightClick();
	}
	
	return true;
};	   

bool ChVrmlFlySTM::GoTowardsStart()
{
#if !defined(CH_USE_3DR)
	GxVec3f	target;
	bool boolHit = m_pWnd->GetRenderContext()->GetHitPoint(m_ix, m_iy, target);

	if(boolHit)
	{
		RecordTime();
		//m_pWnd->GetCameraControl()->LookAt( target, false );	  // Turn towards it
		m_target = target;

		GxVec3f	camLoc = m_pWnd->GetRenderContext()->GetCameraLoc();
		target += camLoc;
		target *= .5;					// Go halfway there, not keeping y constant
		//target.y() = camLoc.y();		   

		m_startLook = ((ChQvPCameraRenderData *)(m_pWnd->GetRenderContext()->GetCurrentCamera()->GetRenderData()))->GetDir();
		m_destination = target;
		m_start = camLoc;
	}
	else
	{
		if(GetKeyState( VK_MENU ) & 0x8000) SetState(s_alt);
		else SetState(s_start);
		return false;
	}
#endif
	return true;
}

bool ChVrmlFlySTM::GoTowards()
{
#if !defined(CH_USE_3DR)
	GxVec3f	camLoc = m_pWnd->GetRenderContext()->GetCameraLoc();
	GxVec3f	target = m_target;
	GxVec3f	start = m_start;
	GxVec3f	destination = m_destination;

	float perCent = GetElapsedTicks() / float(animMoveTowardsTicks);	// how far we 'oughta' be
	if(GetKeyState( VK_SHIFT ) & 0x8000) perCent *= 2;

	perCent = min(perCent, 1.0);
	perCent = Smooth(perCent);

	//camLoc.y() = destination.y() = start.y() = 0;	// ignore y

	GxVec3f v = destination;
	v -= start;			// vector to move total
	v *= perCent;		// vector we should have moved
	v += start;			// where we oughta be
	v -= camLoc;		// how far we have to go, vectorish

	// Now compute the new lookDirection; linearly interpolate from original
	// look direction to final, which is staring right at target
	GxVec3f startLook = m_startLook;

	GxVec3f endLook = m_target;
	endLook -= m_destination;
	endLook.normalize();

	startLook *= (1.0 - perCent);
	endLook *= perCent;

	GxVec3f lookDir = endLook;
	lookDir += startLook;

	lookDir.normalize;

	m_pWnd->GetCameraControl()->SetLookDir( lookDir, false );	  // Turn towards it
	m_pWnd->GetCameraControl()->Shift( v.x(), v.y(), v.z(), true );

	if(perCent >= 1.0)
	{
		if(GetKeyState( VK_MENU ) & 0x8000) SetState(s_alt);
		else SetState(s_start);
		return false;
	}
#endif
	return true;

}

// --------------------------------------------------------------------------
// Examiner
// --------------------------------------------------------------------------

ChVrmlExaminerSTM::ChVrmlExaminerSTM(ChMazeWnd *pWnd) : ChVrmlFlySTM(pWnd) 
{
	Init();
}

void ChVrmlExaminerSTM::Init()
{

	// Now populate the STM
	// SetCell( int iState, int iEvent, int iNewState, ChTransitionActionHandler action)
	ChVrmlFlySTM::Init();

				
	// --			
	AddCell(s_start,	ep_up,		s_up, 		ChVrmlExaminerSTM,	TurnUpStart);
	AddCell(s_up, 		e_tick,		s_up,		ChVrmlExaminerSTM,	TurnUp);

	// --			
	AddCell(s_start,	ep_down,	s_down, 	ChVrmlExaminerSTM,	TurnDownStart);
	AddCell(s_down, 	e_tick,		s_down,		ChVrmlExaminerSTM,	TurnDown);

	// --			
	AddCell(s_start,		ep_left,	s_left,		ChVrmlExaminerSTM,	TurnLeftStart);
	AddCell(s_left, 		e_tick,		s_left,		ChVrmlExaminerSTM,	TurnLeft);

	AddCell(s_start,		ep_right,	s_right, 		ChVrmlExaminerSTM,	TurnRightStart);
	AddCell(s_right, 		e_tick,		s_right,		ChVrmlExaminerSTM,	TurnRight);

	//
	AddCell(s_spinningBegin,	ep_up,		s_up, 		ChVrmlExaminerSTM,	TurnUpStart);
	AddCell(s_spinningBegin,	ep_down,	s_down, 	ChVrmlExaminerSTM,	TurnDownStart);
	AddCell(s_spinningBegin,	ep_left,	s_left,		ChVrmlExaminerSTM,	TurnLeftStart);
	AddCell(s_spinningBegin,	ep_right,	s_right, 		ChVrmlExaminerSTM,	TurnRightStart);
	AddCell(s_spinning,	ep_up,		s_up, 		ChVrmlExaminerSTM,	TurnUpStart);
	AddCell(s_spinning,	ep_down,	s_down, 	ChVrmlExaminerSTM,	TurnDownStart);
	AddCell(s_spinning,	ep_left,	s_left,		ChVrmlExaminerSTM,	TurnLeftStart);
	AddCell(s_spinning,	ep_right,	s_right, 		ChVrmlExaminerSTM,	TurnRightStart);
}

// Handlers
bool ChVrmlExaminerSTM::TurnLeftStart()
{
	RecordTime();
	TurnLeft( );
	return true;
};	   

bool ChVrmlExaminerSTM::TurnRightStart()
{
	RecordTime();
	TurnRight( );
	return true;
};	   
bool ChVrmlExaminerSTM::TurnDownStart()
{
	RecordTime();
	TurnDown( );
	return true;
};	   

bool ChVrmlExaminerSTM::TurnUpStart()
{
	RecordTime();
	TurnUp( );
	return true;
};	   
bool ChVrmlExaminerSTM::TurnLeft()
{
	m_pWnd->GetCameraControl()->RotateBallHorz( GetMoveAmountAngle() );
	RecordTime();
	return true;
};	   
bool ChVrmlExaminerSTM::TurnRight()
{
	m_pWnd->GetCameraControl()->RotateBallHorz( -(GetMoveAmountAngle()) );
	RecordTime();
	return true;
};	   

bool ChVrmlExaminerSTM::TurnUp()
{
	m_pWnd->GetCameraControl()->RotateBallVert( (GetMoveAmountAngle()) );
	RecordTime();
	return true;
};	   

bool ChVrmlExaminerSTM::TurnDown()
{
	m_pWnd->GetCameraControl()->RotateBallVert( -(GetMoveAmountAngle()) );
	RecordTime();
	return true;
};	   




