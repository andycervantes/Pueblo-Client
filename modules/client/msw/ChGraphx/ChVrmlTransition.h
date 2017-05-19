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

----------------------------------------------------------------------------*/

#if !defined( _CHVRMLTRANSITION_H_ )
#define _CHVRMLTRANSITION_H_

#include "ChTransition.h"
#include <GxTypes.h>

#define ACTION_MOD_SHIFT	(1L << 0)
#define ACTION_MOD_CONTROL	(1L << 1)
#define ACTION_MOD_ALT		(1L << 2)

class ChKeyMap;
class ChMazeWnd;

class ChVrmlStateTransition : public ChStateTransition
{
	public:


		// Events
		enum EventType {
			// key downs
			ep_up = 0,	   // UP arrow key
			ep_down,
			ep_left,
			ep_right,
			ep_lookUp,
			ep_lookDown,
			ep_lookUpAlt,
			ep_lookDownAlt,
			ep_thrustForward,
			ep_thrustBack,
			ep_thrustForwardAlt,
			ep_thrustBackAlt,
			ep_space,
			ep_enter,
			ep_rollRight,
			ep_rollLeft,
			ep_rollRightAlt,
			ep_rollLeftAlt,
			ep_alt,	// - change flags too

			// key ups
			er_up,
			er_down,
			er_left,
			er_right,
			er_lookUp,
			er_lookDown,
			er_lookUpAlt,
			er_lookDownAlt,
			er_thrustForward,
			er_thrustBack,   
			er_thrustForwardAlt,
			er_thrustBackAlt,   
			er_space,        
			er_enter,        
			er_rollRight,    
			er_rollLeft,     
			er_rollRightAlt,    
			er_rollLeftAlt,     
			er_alt,	// - change flags too

			// mouse
			ep_lbutton,
			ep_rbutton,
			er_lbutton,
			er_rbutton,
			e_move,

			// others
			e_tick,

			e_numEvents
		};

// non events
//shiftdown - change flags
//ctldown - change flags
//shiftup - change flags
//ctlup - change flags

		enum State { 
			s_start = 0,
			s_alt,
			s_up,
			s_down,
			s_left,
			s_right,
			s_moveUp,
			s_moveDown,
			s_moveLeft,
			s_moveRight,
			s_lookUp,
			s_lookDown,
			s_thrustForward,
			s_thrustBack,
			s_space,
			s_enter,
			s_rollRight,
			s_rollLeft,
			s_lbuttondown,
			s_rbuttondown,
			s_lbuttondrag,
			s_rbuttondrag,
			s_lbuttondownMove,
			s_rbuttondownMove,
			s_lbuttondragMove,
			s_rbuttondragMove,
			s_goTowardsBegin,
			s_goTowards,
			s_spinningBegin,
			s_spinning,

			s_keyDown,	 // use this to replace all the silly separate key states

			// trailer to count
			s_numStates
		};

		enum KeyState {
			kd_up				= 0x01,
			kd_down				= 0x02,
			kd_left				= 0x04,
			kd_right			= 0x08,
			kd_rollRight		= 0x10,
			kd_rollLeft			= 0x20,
			kd_alt				= 0x40,
			kd_shift			= 0x80,
			kd_ctl				= 0x100,
			kd_thrustForward	= 0x200,
			kd_thrustBack		= 0x400,
			kd_lookUp			= 0x800,
			kd_lookDown			= 0x1000
		};					

	public:
		ChVrmlStateTransition(ChMazeWnd *pWnd);
		virtual ~ChVrmlStateTransition();
		
		bool Examine();
		bool ExamineStart();

		bool Spin();
		bool SpinStart();

		virtual bool OnLeftClick(int x, int y, chuint32 uFlags);
		virtual bool OnRightClick(int x, int y, chuint32 uFlags);
		virtual bool IsInAnchoredMove();		// return whether you need cross hairs
		void GetMouseAnchorLoc(int &iX, int &iY);
		void GetMouseLoc(int &iX, int &iY);
		bool GetVelocity(GxVec3f &velocity);	// in world units/sec (usually m/s)
		bool GetAngularVelocity(GxVec3f &axis, float &slewRate); // in rads/sec
		inline bool IsMoving() { return m_iState != s_spinning && m_velocity.magnitude() > 0.0;}; 
	
	protected:
		//virtual bool TranslateKeyEvent(int keyMsg, int key, chuint32 modifiers, int &event, chuint32 *&pData);
 		virtual bool TranslateMouseEvent(int mouseMsg, int x, int y, chuint32 uFlags, int &event, chuint32 *&pData);
		virtual bool TranslateEvent(int iMsg, void *pMsgData,  int &event, chuint32 *&pData);

		void RecordTime();
		void RecordPressTime();
		chint32	GetElapsedTicks();
		chint32	GetElapsedPressTicks();
		float Smooth(float val, float begin = 0., float end = 1., float idle = 0.);
		float GetMoveAmountDistance();
		float GetMoveAmountAngle();
		float GetMoveAmountAngle(int iPixels);

		void  AccumMouseVelocity();
		bool IsWithinFastClickTime();



	protected:
		UINT	m_flags;
		ChMazeWnd *m_pWnd;
		ChKeyMap	*m_pKeyMap;
		int	m_ix;			// at last mouse event
		int	m_iy;
		int	m_iAnchorX;		// Anchor for move
		int	m_iAnchorY;
		chuint32 m_mouseFlags;
		chuint32 m_keyFlags;

		chint32	m_lTime;	// last noted event time
		chint32	m_lButtonTime;  	// last buttondown time
		chint32 m_frameCount;		// frame count for buttondown
		// Camera animation locations
		GxVec3f	m_target;
		GxVec3f	m_destination;
		GxVec3f	m_start;
		GxVec3f	m_startLook;

		GxVec3f	m_mouseVelocity;
		GxVec3f	m_mouseAvgVelocity;

		// Current velocities 
		GxVec3f	m_velocity;
		GxVec3f	m_slewAxis;
		float	m_slewRate;
		// and positions for differentiating
		GxVec3f	m_loc;
		GxVec3f	m_look;


};		

class ChVrmlWalkSTM : public ChVrmlStateTransition
{
	public:
	protected:

	public:
		ChVrmlWalkSTM(ChMazeWnd *pWnd);
		virtual ~ChVrmlWalkSTM() {};

		bool MoveForward();
		bool MoveReverse();
		bool MoveUp();
		bool MoveDown();
		bool TurnLeft();
		bool MoveLeft();
		bool TurnRight();
		bool MoveRight();
		bool LookUp();
		bool LookDown();
		
		bool MoveForwardStart();
		bool MoveReverseStart();
		bool MoveUpStart();
		bool MoveDownStart();
		bool TurnLeftStart();
		bool MoveLeftStart();
		bool TurnRightStart();
		bool MoveRightStart();
		bool LookUpStart();
		bool LookDownStart();
		
		bool WalkStart();
		bool CrabbishStart();

		bool DragWalk();
		bool DragCrabbishly();

		bool TickWalk();
		bool TickCrabbishly();

		bool LeftClick();
		bool LeftClickSlow();

		bool RightClick();
		bool RightClickSlow();

		bool GoTowardsStart();
		bool GoTowards();

		//bool ThrustForward();
		//bool ThrustReverse();

	protected:
		virtual bool TranslateKeyEvent(int keyMsg, int key, chuint32 modifiers, int &event, chuint32 *&pData);
		void Init();

};

class ChVrmlFlySTM : public ChVrmlStateTransition
{

	public:
		ChVrmlFlySTM(ChMazeWnd *pWnd);
		virtual ~ChVrmlFlySTM() {};

		bool MoveForward();
		bool MoveReverse();
		bool MoveForwardStart();
		bool MoveReverseStart();
		
		bool TurnUp();
		bool TurnDown();
		bool MoveUp();
		bool MoveDown();
		bool TurnLeft();
		bool MoveLeft();
		bool RollLeft();
		bool TurnRight();
		bool MoveRight();
		bool RollRight();
		//bool ThrustForward();
		//bool ThrustBack();
		
		bool TurnUpStart();
		bool TurnDownStart();
		bool MoveUpStart();
		bool MoveDownStart();
		bool TurnLeftStart();
		bool MoveLeftStart();
		bool RollLeftStart();
		bool TurnRightStart();
		bool MoveRightStart();
		bool RollRightStart();
		
		bool FlyStart();
		bool CrabbishStart();

		bool DragFly();
		bool DragCrabbishly();

		bool TickFly();
		bool TickCrabbishly();

		bool LeftClick();
		bool LeftClickSlow();

		bool RightClick();
		bool RightClickSlow();

		bool GoTowardsStart();
		bool GoTowards();


	protected:
		virtual bool TranslateKeyEvent(int keyMsg, int key, chuint32 modifiers, int &event, chuint32 *&pData);
		void Init();

};
class ChVrmlExaminerSTM : public ChVrmlFlySTM
{

	public:
		ChVrmlExaminerSTM(ChMazeWnd *pWnd);
		virtual ~ChVrmlExaminerSTM() {};

		bool TurnUp();
		bool TurnDown();
		bool TurnLeft();
		bool TurnRight();

		bool TurnUpStart();
		bool TurnDownStart();
		bool TurnLeftStart();
		bool TurnRightStart();

	protected:
		void Init();

};

#endif	// _CHVRMLTRANSITION_H_
