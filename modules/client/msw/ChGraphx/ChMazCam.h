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

	Interface for the ChMazeCameraController class, which manipulates the
	camera for a ChMazeWnd object.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChMazCam.h,v 2.21 1996/06/27 03:43:17 jimd Exp $
//
#if !defined( _CHMAZCAM_H )
#define _CHMAZCAM_H

#include "ChMaze.h"
#include "CvQuery.h"


/*----------------------------------------------------------------------------
	ChMazeCameraControl class
----------------------------------------------------------------------------*/

	enum Constraint { constraintNone = 0, constrainX = 1, constrainY = 2, constrainZ = 4};

class ChMazeCameraControl
{
	public:
	public:
		ChMazeCameraControl( ChMazeWnd* pMazeWnd );
		virtual ~ChMazeCameraControl();

		void GetPosition( float& fPosX, float& fPosY, float& fPosZ );

		bool Shift( float fUnitsX, float fUnitsY, float fUnitsZ,
						bool boolDraw = true, bool boolTestCollision  = true, bool boolPartialMoveOK = true );

		void MoveForward( float fUnits = 1.0, bool boolDraw = true );
		void MoveBackward( float fUnits = 1.0, bool boolDraw = true );

		void MoveLeft( float fUnits = 1.0, bool boolDraw = true );
		void MoveRight( float fUnits = 1.0, bool boolDraw = true );
		void MoveUp( float fUnits = 1.0, bool boolDraw = true );
		void MoveDown( float fUnits = 1.0, bool boolDraw = true );

		void WalkForward( float fUnits = 1.0, bool boolDraw = true );
		void WalkBackward( float fUnits = 1.0, bool boolDraw = true );


		void Yaw( float fDegrees = 1.0, bool boolDraw = true );	 // relative
		void Turn( float fDegrees = 1.0, bool boolDraw = true );	 // assume y axis

		void Pitch( float fDegrees = 1.0, bool boolDraw = true );
		void Roll( float fDegrees = 1.0, bool boolDraw = true );
		void Init();			
		void Reset();
		void RotateBall(const ChPoint &ptLastMouse, const ChPoint &ptMouse, int iDiameter, bool boolDraw = true);
		void RotateBallHorz(float fDegrees, bool boolDraw = true);
		void RotateBallVert(float fDegrees, bool boolDraw = true);
		void HeadsUp(bool boolDraw = true);
		void LookAt( GxVec3f &target, bool boolDraw = true );
		void SetLookDir( GxVec3f &lookDir, bool boolDraw = true);

		GxVec3f GetLoc();
		GxVec3f GetLookDir();
		GxVec3f GetUp();

		bool GetOrientation(GxVec3f &vec, float &angle);

		void AdjustMove(float &fX, float &fY, float &fZ, float range);
		static void ComputeRelativeCameraShift( GxVec3f &vec, const GxVec3f &dir, const GxVec3f &up );

	protected:
		inline ChMazeWnd* GetMazeWnd()
				{
					ASSERT( 0 != m_pMazeWnd );
					return m_pMazeWnd;
				}
		inline QvNode* GetScene()
				{
					ASSERT( 0 != GetMazeWnd() );
					return GetMazeWnd()->GetScene();
				}

		QvPerspectiveCamera* GetCameraNode();
		void InvalidateCamera( QvPerspectiveCamera* pCameraNode );

 		void ComputeRelativeCameraShift( float &fX, float &fY, float &fZ );
		void HeadsUp(GxVec3f &dir, GxVec3f &up, bool boolAllowInverted = false);
		GxVec3f ComputeDefaultLocation();
		void RotateBall(GxVec3f axis, float fRadians, bool boolDraw = true);


	protected:
		ChMazeWnd*		m_pMazeWnd;
		ChQvQuery		m_cameraQuery;

		//PointFW_t	m_loc;
		//PointF_t	m_dir;	
		//PointF_t	m_up;
};


#endif	// !defined( _CHMAZCAM_H )
