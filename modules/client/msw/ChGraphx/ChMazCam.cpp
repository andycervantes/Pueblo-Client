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

	Implementation for the ChGraphicMaze class, which is used to display
	graphics, & accept selection of hot spots and sprites.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChMazCam.cpp,v 2.38 1996/06/27 03:43:16 jimd Exp $

#include "grheader.h"
//
#include <ChCore.h>

#include <QvDB.h>
#include <QvInput.h>
#include <QvNode.h>
#include <QvState.h>

#include <fstream.h>
#include <strstrea.h>

#include "ChMaze.h"
#include "ChRenderData.h"
#include "ChMazCam.h"
#include "CvTrnsfm.h"
#include "CvBound.h"


#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#define CH_DO_COLLISIONS	1
#endif

#define MOVE_AS_MUCH_AS_POSSIBLE	1

/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define CAMERA_NAME		"DEF Start PerspectiveCamera { }"
#define CAMERA_CLASS	"QvPerspectiveCamera"

#define IDX_X			0
#define IDX_Y			1
#define IDX_Z			2

#define PI				3.141592654
#define HALF_PI			(PI / 2.0)



/*----------------------------------------------------------------------------
	ChMazeCameraControl class
----------------------------------------------------------------------------*/

ChMazeCameraControl::ChMazeCameraControl( ChMazeWnd* pMazeWnd ) :
						m_pMazeWnd( pMazeWnd ),
						m_cameraQuery( pMazeWnd, CAMERA_CLASS, ChQvQuery::byClassName )
{
}



ChMazeCameraControl::~ChMazeCameraControl()
{
}


void ChMazeCameraControl::Init()
{
	QvNode*					pScene = GetScene();
	QvPerspectiveCamera*	pCameraNode;
	if(pScene)
	{
		GxVec3f	loc;
												// Default Up and Dir are always thus:	
		GxVec3f	dir(0, 0, -1);	
		GxVec3f	up(0, 1, 0);
												// Get the camera node

		pCameraNode = (QvPerspectiveCamera*)(m_pMazeWnd->GetRenderContext()->GetCurrentCamera());

		if (pCameraNode == (m_pMazeWnd->GetRenderContext()->GetDefaultCamera()))
		{
												
												  // Compute the location based on the 
												  // bounding box of the scene
			loc = ComputeDefaultLocation();
												  // Now set the camera
			ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(pCameraNode->GetRenderData());
			pRenderData->SetLoc(loc);
			pRenderData->SetDir(dir);
			pRenderData->SetUp(up);
			
			pRenderData->SetStartLoc(loc)->SetStartUp(up)->SetStartDir(dir);

			pRenderData->SynchCamera();
		}
	}

}

GxVec3f ChMazeCameraControl::ComputeDefaultLocation()
{
	QvNode*					pScene = GetScene();
	GxVec3f 				loc(0., 0., 1.);
	GxVec3f					lower, upper;


	// If there are bounds use them, otherwise use standard
	if( !GetMazeWnd()->GetBounds()->IsEmpty() )
	{
		GetMazeWnd()->GetBounds()->GetWorldBounds(lower, upper);
												// Do we need to use weighted center?
		GxVec3f				center = upper;
		center += lower;   center *= .5;	 // avg
		
		loc = center;		// really only need x & y now

		float maxDim = max(max(upper.x() - lower.x(), upper.y() - lower.y()), upper.z() - lower.z());
		loc.z() = max(upper.z() + maxDim / 2., center.z() + maxDim);

		// Now make sure we are back enough to see the whole height at the center z
		float tana = tan(.785398 / 2.);			// use vrml default camera angle
		float d = (upper.y() - lower.y()) / (2. * tana);
		d *= 1.05;	// add a fudge factor 

		if (m_pMazeWnd->GetSettings()->GetViewerMode() == examine)
		{
			loc.z() = max(loc.z(), upper.z() + d);
		}
		else
		{
			loc.z() = max(loc.z(), center.z() + d);
		}
		// fix when we get a non-broken renderer
		#if defined(CH_USE_3DR)
		loc.z() = max(loc.z(), 1. + upper.z());	// for 3dr hither/yon bugs
		#endif	// hope the others work better

	}
	return loc;
}

void ChMazeCameraControl::Reset()
{
	QvPerspectiveCamera*	pNode;
	if (pNode = GetCameraNode())
	{
		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(pNode->GetRenderData());
		pRenderData->Reset();
		pRenderData->SynchCamera();
	}
}

void ChMazeCameraControl::GetPosition( float& fPosX, float& fPosY,
										float& fPosZ )
{
											/* Fetches the x, y, and z values
												for the current position */
	QvPerspectiveCamera*	pNode;

	if (pNode = GetCameraNode())
	{
		fPosX = pNode->position.value[IDX_X];
		fPosY = pNode->position.value[IDX_Y];
		fPosZ = pNode->position.value[IDX_Z];
	}
}

GxVec3f ChMazeCameraControl::GetLoc()
{
	ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());
	return pRenderData->GetLoc();
}
GxVec3f ChMazeCameraControl::GetLookDir()
{
	ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());
	return pRenderData->GetDir();
}
GxVec3f ChMazeCameraControl::GetUp()
{
	ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());
	return pRenderData->GetUp();
}

bool ChMazeCameraControl::GetOrientation(GxVec3f &vec, float &angle)
{
	ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());
	if (!pRenderData) return false;

	// This assumes the camera node is synched with the renderdata
	QvNode *pNode = GetCameraNode();
	QvSFRotation*	pOrientation;
	if(pRenderData->IsPerspective())
	{
		pOrientation = &(((QvOrthographicCamera*)pNode)->orientation);
	}
	else
	{
		pOrientation = &(((QvPerspectiveCamera*)pNode)->orientation);
	}
	vec.x() = pOrientation->axis[0];
	vec.y() = pOrientation->axis[1];
	vec.z() = pOrientation->axis[2];
	angle = pOrientation->angle;
	return true;
}

bool ChMazeCameraControl::Shift( float fUnitsX, float fUnitsY,
										float fUnitsZ, bool boolDraw, 
										bool boolTestCollision /* = true */,
										bool boolPartialMoveOK /* = true */ )
{
											/* Adds the x, y, and z values
												to the current position.
												Negative values are okay. */
	ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());
	GxVec3f	loc  = pRenderData->GetLoc();

	#if defined(CH_DO_COLLISIONS)
	if(boolTestCollision && m_pMazeWnd->GetCollisionMode() != collisionOff)
	{
		GxVec3f dir(fUnitsX, fUnitsY, fUnitsZ);
		float range =  m_pMazeWnd->GetRenderContext()->GetCollisionRange(dir);
		if( (range * range) <= (fUnitsX * fUnitsX + fUnitsY * fUnitsY + fUnitsZ * fUnitsZ) * 1.21)
		{
			if(m_pMazeWnd->GetSettings()->GetCollisionAlarm())
			{
				::MessageBeep(MB_ICONHAND);
			}
			#if defined(MOVE_AS_MUCH_AS_POSSIBLE)
			if(boolPartialMoveOK)
			{
				AdjustMove(fUnitsX, fUnitsY, fUnitsZ, range);
			}
			else
			#endif
			{
				return false; // failed to shift
			}
		}
	}
	#endif



	loc.x() += fUnitsX;
	loc.y() += fUnitsY;
	loc.z() += fUnitsZ;
	pRenderData->SetLoc(loc);
	pRenderData->SynchCamera();

	if (boolDraw)
	{
		InvalidateCamera( GetCameraNode() );
	}
	return true;		// say we did the shift
}

void ChMazeCameraControl::AdjustMove(float &fX, float &fY, float &fZ, float range)
{
	GxVec3f move(fX, fY, fZ);
	float mag = move.magnitude();

	if( range <=  mag * 1.1)
	{
		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());
		float hither = pRenderData->GetHither();
		range -= 3 * hither;
		if(range > 0)
		{
			move.normalize();
			move *= range / 1.5;
		}
		else
		{
			move.set(0, 0, 0);		 // Too Close!!
		}
		fX = move.x();	fY = move.y();	fZ = move.z();
	}
}

void ChMazeCameraControl::MoveForward( float fUnits, bool boolDraw )
{
	QvPerspectiveCamera*	pNode;

	if (pNode = GetCameraNode())
	{
		float	fX = 0;
		float	fY = 0;
		float	fZ = fUnits;	 // Positive is in direction of look

		#if defined(CH_DO_COLLISIONS)
		if(m_pMazeWnd->GetCollisionMode() != collisionOff)
		{
			float range;
			#if YOU_WANNA_USE_THE_VIEWPORT
			if(fZ >= 0.0 && !(m_pMazeWnd->GetRenderContext()->IsDirty()))
			{
				range =  m_pMazeWnd->GetRenderContext()->GetCollisionRange();
			}
			else
			#endif
			{
				GxVec3f dir(0., 0., fZ);
				range =  m_pMazeWnd->GetRenderContext()->GetCollisionRange(dir, true);
			}
			if( range <=  (fabs(fZ) * 1.1))
			{
				if(fabs(fZ) > 0 && m_pMazeWnd->GetSettings()->GetCollisionAlarm())
				{
					::MessageBeep(MB_ICONHAND);
				}
				#if defined(MOVE_AS_MUCH_AS_POSSIBLE)
				AdjustMove(fX, fY, fZ, range);
				#else
				return;
				#endif
			}
		}
		#endif

		ComputeRelativeCameraShift( fX, fY, fZ );

		#if defined(CH_USE_3DR)
		{
			// Because of 3dr bug, our axis is -never- exactly vertical
			// If it's -almost- vertical, then zero the y delta
			// Additionally, we have round-off error.
			if( (fY*fY) / (fX * fX + fZ * fZ) <= 1e-3)
			{
				fY = 0.;
			}
		}
		#endif

		Shift(fX, fY, fZ, boolDraw, false);

	}
}

void ChMazeCameraControl::WalkForward( float fUnits, bool boolDraw )
{
	QvPerspectiveCamera*	pNode;

	if (pNode = GetCameraNode())
	{
		float	fX = 0;
		float	fY = 0;
		float	fZ = fUnits;	 // Positive is in direction of look

		#if defined(CH_DO_COLLISIONS)
		if(m_pMazeWnd->GetCollisionMode() != collisionOff)
		{
			float range;
			#if YOU_WANNA_USE_THE_VIEWPORT
			if(fZ >= 0.0 && !(m_pMazeWnd->GetRenderContext()->IsDirty()))
			{
				range =  m_pMazeWnd->GetRenderContext()->GetCollisionRange();
			}
			else
			#endif
			{
				GxVec3f dir(0., 0., fZ);
				range =  m_pMazeWnd->GetRenderContext()->GetCollisionRange(dir, true);
			}
			if( range <=  (fabs(fZ) * 1.1))
			{
				if(m_pMazeWnd->GetSettings()->GetCollisionAlarm())
				{
					::MessageBeep(MB_ICONHAND);
				}
				#if defined(MOVE_AS_MUCH_AS_POSSIBLE)
				AdjustMove(fX, fY, fZ, range);
				#else
				return;
				#endif
			}
		}
		#endif

		ComputeRelativeCameraShift( fX, fY, fZ );

		fY = 0;

		Shift(fX, fY, fZ, boolDraw, false);

	}
}


void ChMazeCameraControl::MoveBackward( float fUnits, bool boolDraw )
{
	QvPerspectiveCamera*	pNode;

	if (pNode = GetCameraNode())
	{
		float	fX = 0;
		float	fY = 0;
		float	fZ = -fUnits;  	 // Positive is in direction of look

		ComputeRelativeCameraShift( fX, fY, fZ );

		#if defined(CH_USE_3DR)
			// Because of 3dr bug, our axis is -never- exactly vertical
			// If it's -almost- vertical, then zero the y delta
			// Additionally, we have round-off error.
			if( (fY*fY) / (fX * fX + fZ * fZ) <= 1e-3)
			{
				fY = 0.;
			}
		#endif
		Shift(fX, fY, fZ, boolDraw);
	}
}


void ChMazeCameraControl::WalkBackward( float fUnits, bool boolDraw )
{
	QvPerspectiveCamera*	pNode;

	if (pNode = GetCameraNode())
	{
		float	fX = 0;
		float	fY = 0;
		float	fZ = -fUnits;  	 // Positive is in direction of look

		ComputeRelativeCameraShift( fX, fY, fZ );

		fY = 0;

		Shift(fX, fY, fZ, boolDraw);
	}
}


void ChMazeCameraControl::MoveLeft( float fUnits, bool boolDraw )
{
	QvPerspectiveCamera*	pNode;

	if (pNode = GetCameraNode())
	{
		float	fX = -fUnits;
		float	fY = 0;
		float	fZ = 0;

		ComputeRelativeCameraShift( fX, fY, fZ );
		
		if(m_pMazeWnd->GetRenderContext()->GetViewerMode() == walk)
		{
			fY = 0;
		}
		else
		{
			// Because of 3dr bug, our axis is -never- exactly vertical
			// If it's -almost- vertical, then zero the y delta
			// Additionally, we have round-off error.
			if( (fY*fY) / (fX * fX + fZ * fZ) <= 1e-3)
			{
				fY = 0.;
			}
		}

		Shift(fX, fY, fZ, boolDraw);
	}
}


void ChMazeCameraControl::MoveRight( float fUnits, bool boolDraw )
{
	QvPerspectiveCamera*	pNode;

	if (pNode = GetCameraNode())
	{
		float	fX = fUnits;
		float	fY = 0;
		float	fZ = 0;

		ComputeRelativeCameraShift( fX, fY, fZ );

		if(m_pMazeWnd->GetRenderContext()->GetViewerMode() == walk)
		{
			fY = 0;
		}
		else
		{
			// Because of 3dr bug, our axis is -never- exactly vertical
			// If it's -almost- vertical, then zero the y delta
			// Additionally, we have round-off error.
			if( (fY*fY) / (fX * fX + fZ * fZ) <= 1e-3)
			{
				fY = 0.;
			}
		}

		Shift(fX, fY, fZ, boolDraw);
	}
}



void ChMazeCameraControl::MoveUp( float fUnits, bool boolDraw )
{
	QvPerspectiveCamera*	pNode;
	// This is -relative-
	if (pNode = GetCameraNode())
	{
		float	fX = 0;
		float	fY = fUnits;
		float	fZ = 0;

		ComputeRelativeCameraShift( fX, fY, fZ );

		Shift(fX, fY, fZ, boolDraw);
	}
}


void ChMazeCameraControl::MoveDown( float fUnits, bool boolDraw )
{
	QvPerspectiveCamera*	pNode;

	// This is always relative
	if (pNode = GetCameraNode())
	{
		float	fX = 0;
		float	fY = -fUnits;
		float	fZ = 0;

		ComputeRelativeCameraShift( fX, fY, fZ );

		Shift(fX, fY, fZ, boolDraw);

	}
}


void ChMazeCameraControl::Yaw( float fDegrees, bool boolDraw )
{
											// Positive degrees is left
	QvPerspectiveCamera*	pNode;

	if (pNode = GetCameraNode())
	{
		float	fDeltaRadians;

		fDeltaRadians = (fDegrees / 180.0) * PI;

		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());

		GxVec3f		dir  = pRenderData->GetDir();
		GxVec3f		up  = pRenderData->GetUp();
		GxVec3f	axis = up;
		GxTransform3Wf mat(axis, fDeltaRadians);

		dir = mat * dir;
		up = mat * up;

		pRenderData->SetDir(dir);
		pRenderData->SetUp(up);
		pRenderData->SynchCamera();

		if (boolDraw)
		{
			InvalidateCamera( pNode );
		}
	}
}

void ChMazeCameraControl::Turn( float fDegrees, bool boolDraw )
{
											// Positive degrees is left
	QvPerspectiveCamera*	pNode;

	if (pNode = GetCameraNode())
	{
		float	fDeltaRadians;

		fDeltaRadians = (fDegrees / 180.0) * PI;

		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());

		GxVec3f		dir  = pRenderData->GetDir();
		GxVec3f		up  = pRenderData->GetUp();
		GxVec3f	axis(0., 1., 0);
		GxTransform3Wf mat(axis, fDeltaRadians);

		dir = mat * dir;
		up = mat * up;

		#if 0
		// Now straighten your head if walking
		if(m_pMazeWnd->GetRenderContext()->GetViewerMode() == walk)
		{
			HeadsUp(dir, up);
		}
		#endif

		pRenderData->SetDir(dir);
		pRenderData->SetUp(up);
		pRenderData->SynchCamera();

		if (boolDraw)
		{
			InvalidateCamera( pNode );
		}
	}
}


void ChMazeCameraControl::Pitch( float fDegrees, bool boolDraw )
{
											// Positive degrees is up
	QvPerspectiveCamera*	pNode;

	if (pNode = GetCameraNode())
	{
		float	fDeltaRadians;

		fDeltaRadians = (fDegrees / 180.0) * PI;

		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());

		GxVec3f		dir  = pRenderData->GetDir();
		GxVec3f		up  = pRenderData->GetUp();
		GxVec3f		axis = dir.cross(up);

		GxTransform3Wf mat(axis, fDeltaRadians);

		dir = mat * dir;
		up = mat * up;


		pRenderData->SetDir(dir);
		pRenderData->SetUp(up);
		pRenderData->SynchCamera();

		if (boolDraw)
		{
			InvalidateCamera( pNode );
		}
	}
}


void ChMazeCameraControl::Roll( float fDegrees, bool boolDraw )
{
											/* Positive degrees is counter-
												clockwise */
	// Does nothing if walking
	if(m_pMazeWnd->GetRenderContext()->GetViewerMode() == walk)
	{
		return;
	}

	QvPerspectiveCamera*	pNode;

	if (pNode = GetCameraNode())
	{
		float	fDeltaRadians;

		fDeltaRadians = (fDegrees / 180.0) * PI;

		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());

		GxVec3f		dir  = pRenderData->GetDir();
		GxVec3f		up  = pRenderData->GetUp();
		GxVec3f		axis = dir;

		GxTransform3Wf mat(axis, fDeltaRadians);

		dir = mat * dir;
		up = mat * up;


		pRenderData->SetDir(dir);
		pRenderData->SetUp(up);
		pRenderData->SynchCamera();

		if (boolDraw)
		{
			InvalidateCamera( pNode );
		}
	}
}

void ChMazeCameraControl::LookAt( GxVec3f &target, bool boolDraw )
{
	QvPerspectiveCamera*	pNode;

	if (pNode = GetCameraNode())
	{

		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());

		GxVec3f	dir  = target;
		GxVec3f	loc  = pRenderData->GetLoc();

		dir -= loc;

		dir .normalize;

		pRenderData->SetDir(dir);
		pRenderData->SynchCamera();

		if (boolDraw)
		{
			InvalidateCamera( pNode );
		}
	}
}

void ChMazeCameraControl::SetLookDir( GxVec3f &lookDir, bool boolDraw )
{
	QvPerspectiveCamera*	pNode;

	if (pNode = GetCameraNode())
	{

		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());

		GxVec3f	dir  = lookDir;

		dir .normalize;

		pRenderData->SetDir(dir);
		pRenderData->SynchCamera();

		if (boolDraw)
		{
			InvalidateCamera( pNode );
		}
	}
}

void ChMazeCameraControl::RotateBallHorz(float fDegrees, bool boolDraw /*= true */)
{  
	GxVec3f axis (0., 1., 0);

	RotateBall( axis, PI * fDegrees / 180., boolDraw);
}

void ChMazeCameraControl::RotateBallVert(float fDegrees, bool boolDraw /*= true */)
{  
	GxVec3f axis (1., 0., 0);

	RotateBall( axis, PI * fDegrees / 180., boolDraw);
}

void ChMazeCameraControl::RotateBall(const ChPoint &ptLastMouse, const ChPoint &ptMouse, int iDiameter, bool boolDraw)
{
	// Rotate the camera location as if on the surface of a trackball
	// the 'finger' on the ball has moved from ptLastMouse to ptMouse.
	// the 'diameter' of the ball determines how sensitive it is
	// for now, we'll just use the relative offset from one pt to the other
	if(ptMouse.x == ptLastMouse.x && ptMouse.y == ptLastMouse.y) return; // No move!
	
	GxVec3f	delta(ptMouse.x - ptLastMouse.x, ptMouse.y - ptLastMouse.y, 0.);
	delta.x() /= iDiameter; 
	delta.y() /= -iDiameter; 				// flip coords in y
	float angle = -PI * delta.magnitude();

	GxVec3f	axis, zaxis(0., 0., 1.);
	axis = zaxis.cross(delta);
	RotateBall(axis, angle, boolDraw);
}


/*----------------------------------------------------------------------------
	ChMazeCameraControl protected methods
----------------------------------------------------------------------------*/

void ChMazeCameraControl::RotateBall(GxVec3f axis, float fRadians, bool boolDraw /*= true */)
{
	QvPerspectiveCamera* pNode = GetCameraNode();
	if(!pNode) return;	// nothing to rotate!

	ComputeRelativeCameraShift(axis.x(), axis.y(), axis.z());
	axis.normalize();

	// Get the bounding cube center, and use this as the center of rotation
	GxVec3f				lower, upper;
	GetMazeWnd()->GetBounds()->GetWorldBounds(lower, upper);
	GxVec3f				center = upper;
	center += lower;   center *= .5;	 // avg

	ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());
	GxVec3f		dir  = pRenderData->GetDir();
	GxVec3f		up  = pRenderData->GetUp();
	GxVec3f	loc  = pRenderData->GetLoc();

	GxTransform3Wf mat;
	#if defined(CH_USE_3DR)
	mat.Translate(center);
 	GxTransform3Wf rotMat(axis, fRadians);

	mat = rotMat.Compose(mat);
	mat.Translate(GxVec3f(-center.x(), -center.y(), -center.z()));
	loc = mat * loc;
	#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
 	GxTransform3Wf rotMat(axis, fRadians);	 // ??????????????????
	
	loc -= center;
	loc = rotMat * loc;
	loc += center;

	#else
	#pragma message("camera motion not defined")
	#endif

	GxVec3f toMove = loc;
	toMove -= pRenderData->GetLoc();	// This is so we can use Shift,
										// which does collision testing for us


	dir = rotMat * dir;
	up = rotMat * up;

	//pRenderData->SetLoc(loc);
	if(Shift(toMove.x(), toMove.y(), toMove.z(), false, true, false))
	{
					// Don't do rotates if the shift collided 
		pRenderData->SetDir(dir);
		pRenderData->SetUp(up);
		pRenderData->SynchCamera();
	}

	if (boolDraw)
	{
		InvalidateCamera( GetCameraNode() );
	}

}

QvPerspectiveCamera* ChMazeCameraControl::GetCameraNode()
{
	return  (QvPerspectiveCamera*)(m_pMazeWnd->GetRenderContext()->GetCurrentCamera());
}


void ChMazeCameraControl::InvalidateCamera( QvPerspectiveCamera* pCameraNode )
{
	GetMazeWnd()->GetRenderContext()->SetDirty();
	pCameraNode->Invalidate( GetMazeWnd()->GetRenderContext() );
}


void ChMazeCameraControl::
ComputeRelativeCameraShift( float &fX, float &fY, float &fZ )
{
	/* This method transforms from camera to world-like space for use in
		camera motion relative to camera orientation.  No translations, just
		adjusts x,y,z from the camera node's orientation to world. */

	GxVec3f		tmp;
	#if 0 && OLD_NAVIGATION
	if(m_pMazeWnd->GetRenderContext()->GetViewerMode() == walk)
	{
		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());
		GxVec3f		dir  = pRenderData->GetDir();
		GxVec3f		up  = pRenderData->GetUp();

		GxVec3f 	n = dir.cross(up);
		 
		tmp.x() = fZ * dir.x() + fX * n.x();
		tmp.y() = fY;
		tmp.z() = fZ * dir.z() + fX * n.z();
	}
	else
	#endif

	{
		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());
		GxVec3f		dir  = pRenderData->GetDir();
		GxVec3f		up  = pRenderData->GetUp();

		GxVec3f 	n = dir.cross(up);
		 
		tmp.x() = fZ * dir.x() + fY * up.x() + fX * n.x();
		tmp.y() = fZ * dir.y() + fY * up.y() + fX * n.y();
		tmp.z() = fZ * dir.z() + fY * up.z() + fX * n.z();
	}

	fX = tmp.x();
	fY = tmp.y();
	fZ = tmp.z();
}

void ChMazeCameraControl::
ComputeRelativeCameraShift( GxVec3f &vec, const GxVec3f &dir, const GxVec3f &up )
{
	/* This method transforms from camera to world-like space for use in
		camera motion relative to camera orientation.  No translations, just
		adjusts x,y,z from the camera node's orientation to world. */

	GxVec3f		tmp;
	GxVec3f 	n = dir.cross(up);
	 
	tmp.x() = vec.z() * dir.x() + vec.y() * up.x() + vec.x() * n.x();
	tmp.y() = vec.z() * dir.y() + vec.y() * up.y() + vec.x() * n.y();
	tmp.z() = vec.z() * dir.z() + vec.y() * up.z() + vec.x() * n.z();

	vec = tmp;
}

const float EPS = 1.e-12;	// nigh unto zero

void ChMazeCameraControl::HeadsUp(GxVec3f &dir, GxVec3f &up, bool boolAllowInverted)
{
	GxVec3f yAxis(0., 1., 0.);
	float prod = up.dot(yAxis);

	if(fabs(prod) < EPS) return;	// horizontal, let it be

	GxVec3f n = yAxis.cross(dir);				// normal to plane defined by (dir, yaxis)

	if (n.dot(n) > EPS)
	{
		up = dir.cross(n);
	}
	else
	{
		// special case; looking straight up or down
		// we should have trapped this if dir and up were really perps, buy
		// maybe they weren't
		return;
	} 

	if (up.dot(up) < EPS)
	{
		up.set( 0, 1, 0);
	}
	up.normalize();
	if(boolAllowInverted && prod < 0)
	{
			  // use up-down sense of original
		up.x() = -up.x();
		up.y() = -up.y();
		up.z() = -up.z();
	}
}

void ChMazeCameraControl::HeadsUp(bool boolDraw)
{
	QvPerspectiveCamera*	pNode;

	if (pNode = GetCameraNode())
	{
		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(GetCameraNode()->GetRenderData());

		GxVec3f		dir  = pRenderData->GetDir();
		GxVec3f		up  = pRenderData->GetUp();
		
		// Now straighten your head 
		HeadsUp(dir, up);

		pRenderData->SetDir(dir);
		pRenderData->SetUp(up);
		pRenderData->SynchCamera();

		if (boolDraw)
		{
			InvalidateCamera( pNode );
		}
	}
}

// end of file
