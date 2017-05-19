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

	Implementation for the ChQvPCameraRenderData class for  Intel 3DR and 
	Microsoft's RealityLab.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvCamera.cpp,v 2.27 1996/10/03 21:46:12 jimd Exp $

#include "grheader.h"

#include <QvInfo.h>
#include <QvState.h>
#include "ChMaze.h"
#include "CvConvrt.h"
#include "CvTrnsfm.h"
#include "CvNormal.h"
#include "CvInstnc.h"
#include "CvType.h"
#include "CvBound.h"
#include "ChRenderData.h"
#include "GxQuaternion.h"

#include "ChVrmlTransition.h"


ChQvPCameraRenderData::ChQvPCameraRenderData(QvPerspectiveCamera *pCamera, ChQvBuildState* state ) : 
	ChQvRenderBaseData(),
	m_boolPerspective(true), 
	m_pCamera(pCamera),
	m_boolNew(true),
	m_boolSynchEnabled(true)
{
#if defined(CH_VRML_EVENTS)
	if(!m_pDispatcher)
	{
		m_pDispatcher = new	ChVrmlDispatcher;
		Init();
	}
#endif
	Attach(pCamera);
	m_strName = MakeName(state);
	ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
	m_pRC = pRC;
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	m_transform = m_pRC->GetModelTransform();
	#endif

	#if 1
	if(!m_strName.IsEmpty()) pRC->AddCamera(pCamera, m_strName);
	#endif
}

ChQvPCameraRenderData::ChQvPCameraRenderData(QvOrthographicCamera *pCamera, ChQvBuildState* state ) : 
	ChQvRenderBaseData(),
	m_boolPerspective(false), 
	m_pCamera((QvPerspectiveCamera *)((QvNode*)pCamera)),
	m_boolNew(true),
	m_boolSynchEnabled(true)
{
#if defined(CH_VRML_EVENTS)
	if(!m_pDispatcher)
	{
		m_pDispatcher = new	ChVrmlDispatcher;
		Init();
	}
#endif
	Attach(pCamera);
	m_strName = MakeName(state);
	ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
	m_pRC = pRC;
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	m_transform = m_pRC->GetModelTransform();
	#endif
	pRC->AddCamera(pCamera, m_strName);
}

ChQvPCameraRenderData::~ChQvPCameraRenderData()
{
#if 1
	//if(!m_strName.IsEmpty()) m_pRC->RemoveCamera(m_strName);
#endif
}

void ChQvPCameraRenderData::Init()
{
	ChQvRenderBaseData::Init();
#if defined(CH_VRML_EVENTS)

	AddVrmlDispatcher("set_orientation", SFRotation, OnSetOrientation);
	AddVrmlDispatcher("set_position", SFVec3f, OnSetPosition);

#endif

};


void ChQvPCameraRenderData::Term()
{
#if defined(CH_VRML_EVENTS)
	delete m_pDispatcher;
	m_pDispatcher = 0;
#endif
}

void ChQvPCameraRenderData::SetDirty(bool boolDirty)
{
	ChQvRenderBaseData::SetDirty(boolDirty);
#if 1
	if(boolDirty && IsSynchEnabled())
	{
		Synch();
		if(m_pRC && m_pNode == m_pRC->GetCurrentCamera())
		{
			SetRenderer();

				// And set the context dirty
			m_pRC->SetDirty();
		}
	}
	//ChQvRenderBaseData::SetDirty(false);
#endif
} 


ChQvPCameraRenderData *ChQvPCameraRenderData::SetLoc(GxVec3f &loc)
{
	m_loc = loc;
	// Notify window that we moved
	if(m_pRC->GetCurrentCamera() == GetNode())
	{
		((ChMazeWnd*)(m_pRC->GetWnd()))->OnCameraChange(ChMazeWnd::cameraMoved);
	}
	return this;
};
ChQvPCameraRenderData *ChQvPCameraRenderData::SetDir(GxVec3f &dir)
{
	m_dir = dir; 
	// Notify window that we turned
	if(m_pRC->GetCurrentCamera() == GetNode())
	{
		((ChMazeWnd*)(m_pRC->GetWnd()))->OnCameraChange(ChMazeWnd::cameraTurned);
	}
	return this;
};

ChQvPCameraRenderData *ChQvPCameraRenderData::SetUp(GxVec3f &up)
{
	m_up = up; 
	// Notify window that we turned
	if(m_pRC->GetCurrentCamera() == GetNode())
	{
		((ChMazeWnd*)(m_pRC->GetWnd()))->OnCameraChange(ChMazeWnd::cameraTurned);
	}
	return this;
};

GxTransform3Wf ChQvPCameraRenderData::GetTransform()
{
	return GxTransform3Wf(m_cameraTransform);
}
GxTransform3Wf ChQvPCameraRenderData::GetInverseTransform()
{
	#if defined(CH_USE_3DR)
	return GxTransform3Wf(m_invCameraTransform);
	#else
	return m_cameraTransform.Inverse();
	#endif
}

GxTransform3Wf ChQvPCameraRenderData::GetClipTransform()
{
	return GxTransform3Wf(m_camClipTransform);
}




string ChQvPCameraRenderData::MakeName(ChQvBuildState* state)
{
	string name;
	QvNode * pParentNode = 0;
	ChQvGroupInstance *pParentInst = state->GetCurrentParent();
	if(pParentInst)
	{
		pParentNode = pParentInst->GetNode();
	}
	#if 1
	if(pParentNode)
	{
		string strType;
		if(pParentNode->GetType(strType) == typeQvSwitch && pParentNode->getName() == "Cameras")
		{
			name = (char *)(m_pNode->getName().getString());
			if(name.IsEmpty())
			{
				ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
				name.Format("Camera %d", pRC->GetCameraCount());
			}
		}
	}
	#else
	string prefix;

	if(pParentNode)
	{
		string strType;
		if(pParentNode->GetType(strType) == typeQvSwitch)
		{
			if(pParentNode->getName() == "Cameras") prefix = "Cameras:";
		}
	}
	name = prefix + (char *)(m_pNode->getName().getString());
	if(name.IsEmpty())
	{
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		name.Format("Camera %d", pRC->GetCameraCount());
	}
	#endif

	return name;
}

ChQvPCameraRenderData * ChQvPCameraRenderData::Reset()
{
	SetLoc(m_startLoc);
	SetDir(m_startDir);
	SetUp (m_startUp);
	return this;
}

void ChQvPCameraRenderData::SynchCamera()		  // Set camera node fields to agree with this
{
	if(m_boolPerspective)
	{
		EnableSynch(false);	// turn off to prevent redundant computation
		QvPerspectiveCamera *pCamera = (QvPerspectiveCamera*)((QvNode*)m_pCamera);

		pCamera->position.setValue(&m_loc);

		GxVec3f 	dirZ (0.0f, 0.0f, -1.0f);
		GxVec3f	axis;
		float angle;

		#if (!defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )) || defined(CH_VRML_EVENTS)

		GxQuaternion quat(m_dir, m_up);
		quat.AxisAngle(axis, angle);

		axis.normalize();
		#else
		// We don't really need this except for Pueblo or VRML 2.0, so do it lazy
		// The quaternion code takes longer. This way doesn't pay attention to up
		// but if we don't use it who cares? Do the same thing for ortho camera
		// later too.
		axis = dirZ.cross(m_dir);
		if (axis.dot(axis) < 1e-12)
		{
			axis.set( 0, 1, 0);
		}
		axis.normalize();
		float cosa = dirZ.dot(m_dir);	// both were unit vectors before
		angle = acos(cosa);
		#endif

		float orient[4];
		orient[0] = axis.x();
		orient[1] = axis.y();
		orient[2] = axis.z();
		orient[3] = angle;
		pCamera->orientation.setValue(orient);

		EnableSynch();

}
	else
	{
		QvOrthographicCamera *pCamera = (QvOrthographicCamera*)((QvNode*)m_pCamera);
		pCamera->position.value[0] = m_loc.x();
		pCamera->position.value[1] = m_loc.y();
		pCamera->position.value[2] = m_loc.z();
		GxVec3f 	dirZ(0.0f, 0.0f, -1.0f);
		GxVec3f	axis;
		float angle;

		#if (!defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )) || defined(CH_VRML_EVENTS)

		GxQuaternion quat(m_dir, m_up);
		quat.AxisAngle(axis, angle);

		axis.normalize();
		#else
		axis = dirZ.cross(m_dir);
		if (axis.dot(axis) < 1e-12)
		{
			axis.set( 0, 1, 0);
		}
		axis.normalize();
		float cosa = dirZ.dot(m_dir);	// both were unit vectors before
		angle = acos(cosa);
		#endif

		pCamera->orientation.axis[0] = axis.x();
		pCamera->orientation.axis[1] = axis.y();
		pCamera->orientation.axis[2] = axis.z();

		pCamera->orientation.angle = angle;
	}
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	SetRenderer();
#endif
}	

void ChQvPCameraRenderData::Synch()		  // Set this' fields to agree with camera node
{
	GxVec3f	up, yAxis(0.0f, 1.0f, 0.0f);		// starting loc for look dirs
	GxVec3f	dir, dira(0.0f, 0.0f, -1.0f);		// will rotate later
	GxVec3f 	loc, axis;
	float angle;

	// Get the node's data; be safe about it
	if(m_boolPerspective)
	{
		QvPerspectiveCamera *pCamera = (QvPerspectiveCamera*)((QvNode*)m_pCamera);
		Qv2Gx(pCamera->position, loc);
		Qv2Gx(pCamera->orientation.axis, axis);
		angle = pCamera->orientation.angle;
	}
	else
	{
		QvOrthographicCamera *pCamera = (QvOrthographicCamera*)((QvNode*)m_pCamera);
		Qv2Gx(pCamera->position, loc);
		Qv2Gx(pCamera->orientation.axis, axis);
		angle = pCamera->orientation.angle;
	}

	angle = -angle;


	// Inventor puts the camera in transformed world (model) coordinates,
	// RLAB's camera is in the base frame. Apply our stack transform to the 
	// frame, then apply the camera loc and direction. 
	// Remember VRML is RHS, but RLab is LHS

	GxTransform3Wf	stackMat = m_transform;
	GxTransform3Wf	rotMat(axis, -angle);

										  
	GxTransform3Wf cameraMat = rotMat;		  // up/down has nothing to do with the transform jwd 12/7/95

	dir = cameraMat * dira;
	dir.normalize();

	if(m_pRC->GetViewerMode() != walk )
	{
		up  = cameraMat * yAxis;
	}
	else						// We're walking; keep camera level
	{							// This computation is not pure VRML,
								// but it keeps camera manipulations much cleaner for
								// walking situations. The camera acts more camera-like 
								// and less airplane-like.

		GxVec3f n = yAxis.cross(dir);				// normal to plane defined by (dir, yaxis)

		if (n.dot(n) > SMIDGEON)
		{
			up = dir.cross(n);
		}
		else
		{
			// special case; looking straight up or down
			up  = cameraMat * yAxis;
		} 

		if (up.dot(up) < SMIDGEON)
		{
			up = yAxis;
		}
	}
	up.normalize();

	SetLoc(*(GxVec3f*)&loc)->SetUp(*(GxVec3f*)&up)->SetDir(*(GxVec3f*)&dir);
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

ChQvPCameraRenderData * ChQvPCameraRenderData::Select()
{
	m_pRC->LockScene();
	// Make this camera the current one for the RC
	if(m_boolNew)
	{
		 // We only need to compute all this stuff if we are using this camera for the first time
		 // Otherwise, we remember from the last time selected
		GxVec3f	up, yAxis(0.0f, 1.0f, 0.0f);		// starting loc for look dirs
		GxVec3f	dir, dira(0.0f, 0.0f, -1.0f);		// will rotate later
		GxVec3f 	loc, axis;
		float angle, heightAngle, height;
		float nearDistance, farDistance;

		// Get the node's data; be safe about it
		if(m_boolPerspective)
		{
			QvPerspectiveCamera *pCamera = (QvPerspectiveCamera*)((QvNode*)m_pCamera);
			Qv2Gx(pCamera->position, loc);
			Qv2Gx(pCamera->orientation.axis, axis);
			angle = pCamera->orientation.angle;
			heightAngle = pCamera->heightAngle.value;
			nearDistance = pCamera->nearDistance.value;
			farDistance = pCamera->farDistance.value;
		}
		else
		{
			QvOrthographicCamera *pCamera = (QvOrthographicCamera*)((QvNode*)m_pCamera);
			Qv2Gx(pCamera->position, loc);
			Qv2Gx(pCamera->orientation.axis, axis);
			angle = pCamera->orientation.angle;
			height = pCamera->height.value;
			nearDistance = pCamera->nearDistance.value;
			farDistance = pCamera->farDistance.value;
		}

		angle = -angle;

		ChNrViewport view = m_pRC->GetViewport();
		ChNrFrame cameraFrame; 
		ChNrViewportGetCamera(view, cameraFrame);


		// Inventor puts the camera in transformed world (model) coordinates,
		// RLAB's camera is in the base frame. Apply our stack transform to the 
		// frame, then apply the camera loc and direction. 
		// Remember VRML is RHS, but RLab is LHS

		GxTransform3Wf	stackMat = m_transform;
		ChNrFrameAddTransform(cameraFrame, CombineReplace, *(stackMat.GetMatrix())); // TODO make an intermediate frame for this
		GxTransform3Wf	rotMat(axis, -angle);

											  
		GxTransform3Wf cameraMat = rotMat;		  // up/down has nothing to do with the transform jwd 12/7/95

		dir = cameraMat * dira;
		dir.normalize();

		if(m_pRC->GetViewerMode() != walk )
		{
			up  = cameraMat * yAxis;
		}
		else						// We're walking; keep camera level
		{							// This computation is not pure VRML,
									// but it keeps camera manipulations much cleaner for
									// walking situations. The camera acts more camera-like 
									// and less airplane-like.

			GxVec3f n = yAxis.cross(dir);				// normal to plane defined by (dir, yaxis)

			if (n.dot(n) > SMIDGEON)
			{
				up = dir.cross(n);
			}
			else
			{
				// special case; looking straight up or down
				up  = cameraMat * yAxis;
			} 

			if (up.dot(up) < SMIDGEON)
			{
				up = yAxis;
			}
		}
		up.normalize();
	
		SetLoc(*(GxVec3f*)&loc)->SetUp(*(GxVec3f*)&up)->SetDir(*(GxVec3f*)&dir);
		SetStartLoc(*(GxVec3f*)&loc)->SetStartUp(*(GxVec3f*)&up)->SetStartDir(*(GxVec3f*)&dir);
		m_boolNew = false;
		D3DRelease(cameraFrame);
	}

	SetDirty(false);


	SetRenderer();
	m_pRC->CreateHeadlight();
    // ChNrFrameAddLight(m_pRC->GetFrame(), RLCreateLightRGB(ChNrLightAmbient, RLVal(0.2), RLVal(0.2), RLVal(0.2)));


	// Now let's save the matrices into the render data for later use
	
	#if 0		
	memcpy(pRenderData->m_cameraTransform, G3dGetModelCamMatrix(hGC), sizeof(pRenderData->m_cameraTransform));
	memcpy(pRenderData->m_invCameraTransform, G3dGetInverseModelCamMatrix(hGC), sizeof(pRenderData->m_invCameraTransform));
	G3dSetActiveStack(hGC, G3DT_CAM_CLIP);
	GxTransformF_t mat;
	G3dGetTransform(hGC, mat);	   
	pRenderData->m_camClipTransform	= GxTransform3Wf(mat);
	G3dSetActiveStack(hGC, G3DT_MODEL);
	#else
	//#pragma message("Saving of camera transforms not done.")
	#endif

	m_pRC->UnlockScene();

	return this;
}

ChQvPCameraRenderData * ChQvPCameraRenderData::SetRenderer(bool boolNow)
{
	if(!boolNow)
	{
		m_boolRendererDirty = true;
	}
	else if(m_boolRendererDirty)
	{
		m_boolRendererDirty = false;
		m_pRC->LockScene();
		// Set this camera's settings into the RC, viewport, etc.

		float heightAngle, height;
		float nearDistance, farDistance;

		// Get the node's data; be safe about it
		if(m_boolPerspective)
		{
			QvPerspectiveCamera *pCamera = (QvPerspectiveCamera*)((QvNode*)m_pCamera);
			heightAngle = pCamera->heightAngle.value;
			nearDistance = pCamera->nearDistance.value;
			farDistance = pCamera->farDistance.value;
		}
		else
		{
			QvOrthographicCamera *pCamera = (QvOrthographicCamera*)((QvNode*)m_pCamera);
			height = pCamera->height.value;
			nearDistance = pCamera->nearDistance.value;
			farDistance = pCamera->farDistance.value;
		}


		ChNrViewport view = m_pRC->GetViewport();
		ChNrFrame cameraFrame;		
		ChNrViewportGetCamera(view, cameraFrame);	// Release is well below here

		ChNrViewportSetProjection(view, m_boolPerspective ? ProjectPerspective : ProjectOrthographic );


		// Inventor puts the camera in transformed world (model) coordinates,
		// RLAB's camera is in the base frame. Apply our stack transform to the 
		// frame, then apply the camera loc and direction. 
		// Remember VRML is RHS, but RLab is LHS

		GxTransform3Wf	stackMat = m_transform;

		ChNrFrameAddTransform(cameraFrame, CombineReplace, *(stackMat.GetMatrix())); // TODO make an intermediate frame for this
		ChNrFrameAddScale(cameraFrame, CombineBefore, 1., 1., -1.);	  // ???   --
		GxTransform3Wf theTransform;
		GxVec3f dir = m_dir, up = m_up;
		dir.z() = -dir.z();
		up.z() = -up.z();
		theTransform.LookAt( dir, up, false);	   // --
		ChNrFrameAddTranslation(cameraFrame, CombineBefore, m_loc.x(), m_loc.y(), -m_loc.z());	// z alrady scaled	- ???
		ChNrFrameAddTransform(cameraFrame, CombineBefore, *(theTransform.GetMatrix()));

		#if 0

		ChNrFrameAddTransform(cameraFrame, CombineReplace, *(stackMat.GetMatrix())); // TODO make an intermediate frame for this
	

		GxTransform3Wf theTransform;
		GxVec3f dir = -m_dir, up = -m_up;
		theTransform.LookAt( dir, up, false);	   // --
		ChNrFrameAddTranslation(cameraFrame, CombineBefore, m_loc.x(), m_loc.y(), m_loc.z());	// z alrady scaled	- ???
		ChNrFrameAddTransform(cameraFrame, CombineBefore, *(theTransform.GetMatrix()));
		ChNrFrameAddScale(cameraFrame, CombineBefore, 1., 1.,1.);	  // ???   --
		#endif

		// Massage the front and back planes to enclose the whole scene if possible.
		// If the version is 1.0 and nearDistance is 1.0, ignore it
		float fNear = nearDistance;
		if(true && fNear == 1.0)	// for >= vrml 1.1
		{
			fNear = .01;
		} 
		float fFar = 8000.;
		//const float maxZResolution = 32000.;	// Assuming ?? bits signed
		const float maxZResolution = 8000.;	// Assuming ?? bits signed
		ChMazeWnd * pWnd = (ChMazeWnd *)(m_pRC->GetWnd());
		if(pWnd->GetBounds())
		{				   
							// Compute based on scene bounds, and
							// multiply in a little fudge factor for luck
			fFar = 1.5 * pWnd->GetBounds()->GetFarDistance(m_loc.x(), m_loc.y(), m_loc.z());
			//fFar *= 40.;	// Work in the front of the buffer; we get less problems that way
			fFar *= 15.;	// Work in the front of the buffer; we get less problems that way

		}
		float minNear = fFar / maxZResolution;	   // lessen zbuffer roundoff error
		fNear = max(fNear, minNear);
		ChNrViewportSetFront(view, fNear);
		ChNrViewportSetBack(view, fFar);

		m_right 	=  ChNrViewportGetWidth(view);		/* right */        
		m_left  	=  0.0f;					/* left*/          
		m_top   	=  ChNrViewportGetHeight(view);		/* top */          
		m_bottom	=  0.0f;					/* bottom */ 
	      
		// RL uses largest dimension to match to "field", so if this is
		// width, adjust accordingly, since VRML is height-based.
		float fieldHeight;
	
		if (m_boolPerspective)
		{
			fieldHeight = fNear * tan(heightAngle / 2.);
		}
		else
		{
			fieldHeight = height / 2;
		}											

		float aspect = float(ChNrViewportGetHeight(view)) / ChNrViewportGetWidth(view);
		if (aspect < 1.0) fieldHeight /= aspect; 
		ChNrViewportSetField(view, fieldHeight);

		D3DRelease(cameraFrame);   // matches 'GetCamera'
		m_pRC->UnlockScene();
	}

	return this;
}

void ChQvPCameraRenderData::GetOrientationTransform(GxTransform3Wf &theTransform)
{
	GxVec3f dir = m_dir, up = m_up;
	dir.z() = -dir.z();
	up.z() = -up.z();
	theTransform.LookAt( dir, up, false);	   // --
}
float ChQvPCameraRenderData::GetHither()
{
	if(!m_pRC) return .01;
	ChNrViewport view = m_pRC->GetViewport();
	return ChNrViewportGetFront(view);
}
float ChQvPCameraRenderData::GetYon()
{
	if(!m_pRC) return 1.;
	ChNrViewport view = m_pRC->GetViewport();
	return ChNrViewportGetBack(view);
}
#endif


#if defined(CH_USE_3DR)
void ChQvPCameraRenderData::TransformPoint( const GxVec3f &src, GxVec3f &dst )
{
	::TransformPoint( *((PointF_t*)(&src)), *((PointF_t*)(&dst)), m_cameraTransform);
}

void ChQvPCameraRenderData::InverseTransformPoint( const GxVec3f &src, GxVec3f &dst )
{
	::TransformPoint( *((PointF_t*)(&src)), *((PointF_t*)(&dst)), m_invCameraTransform);
}

void ChQvPCameraRenderData::TransformNormal( const GxVec3f &src, GxVec3f &dst )
{
	PointF_t tmp;
	G3dTransformNormalF( ((PointF_t*)(&src)), ((PointF_t*)(&tmp)), m_cameraTransform );
	dst.set(tmp.x, tmp.y, tmp.z);
}

void ChQvPCameraRenderData::InverseTransformNormal( const GxVec3f &src, GxVec3f &dst )
{
	PointF_t tmp;
	G3dTransformNormalF( ((PointF_t*)(&src)), ((PointF_t*)(&tmp)), m_invCameraTransform );
	dst.set(tmp.x, tmp.y, tmp.z);
}

#else
//#pragma message("Bunch of camera transform methods Not done!")
#endif


bool ChQvPCameraRenderData::OnSetOrientation(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEventList)
{
	bool boolSuccess = true;
#if defined(CH_VRML_EVENTS)
	// Change the orientation value, and dirty the context so it takes effect
	float axis[3];
	float angle;
	ChRotationEvent *pEvent = (ChRotationEvent *)pEventList;
	pEvent->GetValue(axis, angle);

	string strType;
	nodeType typ = nodeType(m_pNode->GetType(strType));
	QvSFRotation *pRotation = 0;

	if(typ == typeQvOrthographicCamera)
	{
		pRotation = &(((QvOrthographicCamera *)m_pNode)->orientation);
	}
	else if(typ == typeQvPerspectiveCamera)
	{
		pRotation = &(((QvPerspectiveCamera *)m_pNode)->orientation);
	}

	pRotation->axis[0] = axis[0];
	pRotation->axis[1] = axis[1];
	pRotation->axis[2] = axis[2];
	pRotation->angle = angle;

	// Now update the camera settings from the Qv values
	if(m_pNode == pRC->GetCurrentCamera())
	{
		// Stop navigating - If we are spinning, everything screws up
		((ChMazeWnd*)(pRC->GetWnd()))->GetSceneNavigator()->SetState(ChVrmlStateTransition::s_start);
	}
	Synch();
	if(m_pNode == pRC->GetCurrentCamera())
	{
		SetRenderer();

			// And set the context dirty
		pRC->SetDirty();
	}
#endif

	return boolSuccess;
}

bool ChQvPCameraRenderData::OnSetPosition(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEventList)
{
	bool boolSuccess = false;
#if defined(CH_VRML_EVENTS)

	// Change the position value, and dirty the context so it takes effect
	float position[3];
	ChVec3fEvent *pEvent = (ChVec3fEvent *)pEventList;
	pEvent->GetValue(position);

	string strType;
	nodeType typ = nodeType(m_pNode->GetType(strType));
	QvSFVec3f *pPosition = 0;

	if(typ == typeQvOrthographicCamera)
	{
		pPosition = &(((QvOrthographicCamera *)m_pNode)->position);
	}
	else if(typ == typeQvPerspectiveCamera)
	{
		pPosition = &(((QvPerspectiveCamera *)m_pNode)->position);
	}
	else
	{
		boolSuccess = false;
	}

	pPosition->value[0] = position[0];
	pPosition->value[1] = position[1];
	pPosition->value[2] = position[2];

	// Now update the camera settings from the Qv values
	if(m_pNode == pRC->GetCurrentCamera())
	{
		// Stop navigating - If we are spinning, everything screws up
		((ChMazeWnd*)(pRC->GetWnd()))->GetSceneNavigator()->SetState(ChVrmlStateTransition::s_start);
	}
	Synch();
	if(m_pNode == pRC->GetCurrentCamera())
	{
		SetRenderer();

			// And set the context dirty
		pRC->SetDirty();
	}


#endif

	return boolSuccess;
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) || defined(CH_USE_D3D)
bool ChQvPCameraRenderData::OnTick()
{
	  // 'move' tick
	SetRenderer(true);
	return true;
}
#endif
