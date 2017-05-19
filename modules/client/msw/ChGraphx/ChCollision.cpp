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

	Implementation for collision detection in VRML/RenderLab

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChCollision.cpp,v 2.10 1996/07/08 21:30:22 jimd Exp $

#include "grheader.h"
//
#ifdef CH_MSW
#include <windows.h>
#endif
#ifdef HUGE
#undef HUGE
#endif
#include <math.h>
//#include <strstrea.h>
#include "ChMaze.h"
#include "CvBound.h"
#include "CvHitTst.h"
#include "CvTrnsfm.h"
#include "ChCollision.h"
#include "ChMazCam.h"
#include "ChRCDevice.h"

#define CH_TRANSPARENCY_COLLISION_THRESHOLD		0.90
#define CH_INFINITE_RANGE	 1000000
//#define NEAR_PLANE_SCALE	100.0
#define NEAR_PLANE_SCALE	1.0



#if (defined(CH_USE_D3D)) || (defined(CH_USE_RLAB))

#if 0 && (defined(CH_USE_D3D))

// Just stubs to get us going on d3d
#pragma message("D3D Collision Testing Not enabled!")

#if 1
float ChRenderContext::GetCollisionRange(GxVec3f &look, bool boolRelative /* = false*/)
{
	// Return the range the current camera can be moved without colliding with something
	// value is in -camera- coords

	float range = CH_INFINITE_RANGE; // free to move if no scene
	return range;
};
#endif

#else	 // must be (defined(CH_USE_RLAB))



float ChRenderContext::GetCollisionRange(GxVec3f &look, bool boolRelative /* = false*/)
{
	// Return the range the current camera can be moved without colliding with something
	// value is in -camera- coords

	float range = CH_INFINITE_RANGE; // free to move if no scene

	if(m_viewport)
	{

		// Lock the scene and don't be nice
		LockScene();

		if(!m_pCollisionSensor) 
		{
		   m_pCollisionSensor = new ChCollisionView(this, m_viewport, m_sceneFrame, m_cameraFrame);
		}

		if(boolRelative)
		{
			m_pCollisionSensor->SetRelativeDir(look);
		}
		else
		{
			m_pCollisionSensor->SetDir(look);
		}
		m_pCollisionSensor->Render();
		bool boolUseFaces = true;
		#if (defined(CH_USE_RLAB))
		boolUseFaces = m_maxTransparency > CH_TRANSPARENCY_COLLISION_THRESHOLD;
		#endif
		range = m_pCollisionSensor->GetCollisionRange(boolUseFaces);

		// Now check the immediate mode stuff
		#if (defined(CH_IMMED_MODE))
		GxVec3f dir(look);
		if(boolRelative)
		{
			ChMazeCameraControl::ComputeRelativeCameraShift( dir, GetCameraDir(), GetCameraUp() );
		}
		ChCollisionIterator	iterator(this, GetCameraLoc(), dir, GetAvatarRadius());

		iterator.Attach(GetRoot());
		iterator.Iterate();
		float t;
		ChQvInstance *pInst;
		if(iterator.GetHit(pInst, t))
		{
			float immedRange = dir.magnitude() * t;
			if(immedRange < range) range = immedRange;
		}
		#endif	// CH_IMMED_MODE

		UnlockScene();

		#if BE_VERY_NOISY_ON_COLLISION_TESTING
		::AfxTrace("Range %6.3f dir (%6.3f, %6.3f, %6.3f) (%s). \n", 
				double(range), double(look.x()), double(look.y()), double(look.z()),
				(boolRelative ? "relative" : "absolute"));
		#endif
	}
	
	return range;
						
} 
#endif
#endif

float ChCollisionView::GetCollisionRange(bool boolUseFaces)
{
	// Return the range the current camera can be moved without colliding with something
	// value is in -camera- coords

	float range = CH_INFINITE_RANGE; // free to move if no scene

#if (defined(CH_USE_RLAB))
	//LockScene();
	int iX = ChNrViewportGetWidth(m_view) / 2;
	int iY = ChNrViewportGetHeight(m_view) / 2;
	RLVisual 	visual;
	ChNrFrame 	frame;
	
	float z = GetZ();

	if(/*false && */ !boolUseFaces)
	{
		
		// take range - I'm not sure if this works if we have a scaling transform before the camera
		//range = ptInCameraSpace.magnitude() - 	ChNrViewportGetFront(m_view) * NEAR_PLANE_SCALE;
		range = z - ChNrViewportGetFront(m_view) * 2 * NEAR_PLANE_SCALE;
		range = max(range, 0.); 
	}
	else if(ChNrViewportFindVisual( m_view, &visual, &frame, iX, iY) != RLNotFound)
	{
		// Hit -something-. How far away is it?
		GxVec3f clickPoint;
		ChNrFaceInfo faceInfo;
		if((ChNrViewportFindFace( m_view, &faceInfo, iX, iY) != RLNotFound)
					&& faceInfo.frame == frame)
		{
			clickPoint = *(GxVec3f*)&faceInfo.position;
			ChNrVector4d screenCoord;
			screenCoord.x = clickPoint.x();
			screenCoord.y = clickPoint.y();
			screenCoord.z = clickPoint.z();
			screenCoord.w = 1;
			ChNrViewportInverseTransform(m_view, (ChNrVector*)&clickPoint, &screenCoord);
		}
		else
		{
			// It's not a face visual, must be a decal
			ChNrFrameGetPosition(frame, m_scene, (ChNrVector*)&clickPoint);
		}

		// Convert to camera coords
		GxVec3f ptInCameraSpace;
		ChNrFrameInverseTransform(m_camera, (ChNrVector*)&ptInCameraSpace, (ChNrVector*)&clickPoint);
		
		//TRACE1("bufffer's z / pt.z() = %f\n", double(z / clickPoint.z()));
		// take range - I'm not sure if this works if we have a scaling transform before the camera
		range = ptInCameraSpace.magnitude() - ChNrViewportGetFront(m_view) * 2 * NEAR_PLANE_SCALE;
		range = max(range, 0.); 

	}

	//UnlockScene();
		#if BE_VERY_NOISY_ON_COLLISION_TESTING
			GxVec3f origin, loc;
		ChNrFrameTransform(m_camera, (ChNrVector*)&loc, (ChNrVector*)&origin);
		origin = loc;
		ChNrFrameInverseTransform(m_scene, (ChNrVector*)&loc, (ChNrVector*)&origin);
		::AfxTrace(" Camera is at (%6.3f, %6.3f, %6.3f) in scene. ", 
				double(loc.x()), double(loc.y()), double(loc.z()));
		#endif
#elif (defined(CH_USE_D3D))
	int iX = ChNrViewportGetWidth(m_view) / 2;
	int iY = ChNrViewportGetHeight(m_view) / 2;


		GxVec3f	retainedPoint;
	    LPDIRECT3DRMVISUAL visual;
	    LPDIRECT3DRMFRAME pickFrame;
	    LPDIRECT3DRMPICKEDARRAY picked = 0;
	    LPDIRECT3DRMFRAMEARRAY frames;
	    LPDIRECT3DRMMESHBUILDER mesh;
	    LPDIRECT3DRMTEXTURE decal;
		D3DRMPICKDESC 	pickInfo;

		HRESULT rval = m_view->Pick(iX, iY, &picked);
		int count = picked ? picked->GetSize() : 0;
		float z = 0;
		if(count > 0)
		{
            picked->GetPick(0, &visual, &frames, &pickInfo);
            frames->GetElement(frames->GetSize() - 1, &pickFrame);

            if (SUCCEEDED(visual->QueryInterface(IID_IDirect3DRMMeshBuilder, (void **) &mesh)))
            {   
                mesh->Release();
            }
            else if (SUCCEEDED(visual->QueryInterface(IID_IDirect3DRMTexture, (void **) &decal)))
            {   
                decal->Release();
           	}

			pickFrame->Release();
			frames->Release();
			visual->Release();
			GxVec3f clickPoint;
			ChNrVector4d screenCoord;

			screenCoord.x = pickInfo.vPosition.x;
			screenCoord.y = pickInfo.vPosition.y;
			screenCoord.z = pickInfo.vPosition.z;
			screenCoord.w = 1;
			ChNrViewportInverseTransform(m_view, (ChNrVector*)&clickPoint, &screenCoord);

			// Convert to camera coords
			GxVec3f ptInCameraSpace;
			ChNrFrameInverseTransform(m_camera, (ChNrVector*)&ptInCameraSpace, (ChNrVector*)&clickPoint);
			range = ptInCameraSpace.magnitude() - ChNrViewportGetFront(m_view) * 2 * NEAR_PLANE_SCALE;
			range = max(range, 0.); 

		}
	// ------------------------------------------------------
	#if 0
	RLVisual 	visual;
	ChNrFrame 	frame;
	
	if(ChNrViewportFindVisual( m_view, &visual, &frame, iX, iY) != RLNotFound)
	{
		// Hit -something-. How far away is it?
		GxVec3f clickPoint;
		ChNrFaceInfo faceInfo;
		if((ChNrViewportFindFace( m_view, &faceInfo, iX, iY) != RLNotFound)
					&& faceInfo.frame == frame)
		{
			clickPoint = *(GxVec3f*)&faceInfo.position;
			ChNrVector4d screenCoord;
			screenCoord.x = clickPoint.x();
			screenCoord.y = clickPoint.y();
			screenCoord.z = clickPoint.z();
			screenCoord.w = 1;
			ChNrViewportInverseTransform(m_view, (ChNrVector*)&clickPoint, &screenCoord);
		}
		else
		{
			// It's not a face visual, must be a decal
			ChNrFrameGetPosition(frame, m_scene, (ChNrVector*)&clickPoint);
		}

		// Convert to camera coords
		GxVec3f ptInCameraSpace;
		ChNrFrameInverseTransform(m_camera, (ChNrVector*)&ptInCameraSpace, (ChNrVector*)&clickPoint);
		
		//TRACE1("bufffer's z / pt.z() = %f\n", double(z / clickPoint.z()));
		// take range - I'm not sure if this works if we have a scaling transform before the camera
		range = ptInCameraSpace.magnitude() - ChNrViewportGetFront(m_view) * 2 * NEAR_PLANE_SCALE;
		range = max(range, 0.); 

	}
	#endif
#endif

	return range;

} 

#if 1
#define WIDTH 4
#define HEIGHT 4

//unsigned char buffer1[WIDTH * HEIGHT * 4];

#if (defined(CH_USE_RLAB))
static RLImage stockImage = {
	WIDTH, HEIGHT,	/* width, height	*/
	2, 1,			/* aspectx, aspecty */
	24,			/* depth 	*/
	TRUE,			/* rgb 	*/
	WIDTH*4,		/* bytes_per_line */
	0,		/* buffer1 	*/
	NULL,			/* buffer2 	*/
	0xff0000,		/* red mask 	*/
     0xff00,		/* green mask 	*/
	0xff,			/* blue mask 	*/
	0,			/* alpha mask 	*/
	0,			/* palette size 	*/
	NULL,			/* palette 	*/
};

#define ZBUFFERDEPTH	16
#endif

ChCollisionView::ChCollisionView(ChRenderContext *pRC, ChNrViewport sceneView, ChNrFrame scene, ChNrFrame sceneCamera ) :
	m_buffer(0), m_zBuffer(0)
	#if (defined(CH_USE_D3D))
	, m_pDevice(0)
	#endif
{
    m_camera = pRC->CreateFrame(sceneCamera);
    ChNrFrameSetPosition(m_camera, sceneCamera, 0, 0, 0);
    ChNrFrameSetOrientation(m_camera, sceneCamera,
				   0, 0, -1,
				   0, 1, 0);  // point backwards to start

#if (defined(CH_USE_RLAB))
						  // Set up the image buffer
	m_image = stockImage;
	
	m_buffer = new unsigned char [WIDTH * HEIGHT * 4];
	::memset(m_buffer, 0,  WIDTH * HEIGHT * 4);

	m_image.buffer1 = m_buffer;
						 // Now set up the z buffer
	m_zBufferImage = stockImage;
	m_zBufferImage.depth = ZBUFFERDEPTH;
	m_zBufferImage.bytes_per_line = ZBUFFERDEPTH / 8 * m_zBufferImage.width;

	m_zBuffer = new unsigned char [WIDTH * HEIGHT * ZBUFFERDEPTH / 8];
	::memset(m_zBuffer, 0,  WIDTH * HEIGHT * ZBUFFERDEPTH / 8);
	m_zBufferImage.buffer1 = m_zBuffer;



    m_dev = RLCreateMemoryDevice(&m_image, /*0*/ &m_zBufferImage  , NULL, NULL, NULL, NULL);
#elif (defined(CH_USE_D3D))
	m_pDevice = new ChDevice3D(pRC, WIDTH, HEIGHT);
	m_dev = m_pDevice->GetDevice();
#endif

    ChNrDeviceSetQuality(m_dev, RenderFlat);
    m_view = pRC->CreateViewport(m_dev, m_camera, 0, 0,
				     ChNrDeviceGetWidth(m_dev),
				     ChNrDeviceGetHeight(m_dev));
	m_scene = scene;
	m_sceneCamera = sceneCamera;

	ChNrViewportSetProjection(m_view, ChNrViewportGetProjection(sceneView) );
	ChNrViewportSetFront(m_view, ChNrViewportGetFront(sceneView) /  NEAR_PLANE_SCALE);	// as close as possible
	ChNrViewportSetBack(m_view, ChNrViewportGetBack(sceneView));

#ifdef _DEBUG
	float front = ChNrViewportGetFront(sceneView);
	float back =  ChNrViewportGetBack(sceneView);
	//int field = int(ChNrViewportGetField(sceneView) * 4. / ChNrViewportGetHeight(sceneView));
#endif

	float field = (ChNrViewportGetField(sceneView) * 4. / ChNrViewportGetHeight(sceneView));
	ChNrViewportSetField(m_view, field / NEAR_PLANE_SCALE);

    //RLTick(); /* render a scene */


}
ChCollisionView::~ChCollisionView()
{
    if(m_view) ChNrObjectDestroy(m_view);
	m_view = 0;

#if (defined(CH_USE_RLAB))
    if(m_dev) ChNrObjectDestroy(m_dev);
	m_dev = 0;
#elif (defined(CH_USE_D3D))
// delete the rcdevice
	delete m_pDevice;
#endif
	delete [] m_buffer;
	m_buffer = 0;
	delete [] m_zBuffer;
	m_zBuffer = 0;
	
}

void ChCollisionView::SetDir(GxVec3f dir)
{
	dir.normalize();
	//dir .z() = -dir.z();
	dir .x() = -dir.x();
	dir .y() = -dir.y();

	GxVec3f xAxis(1, 0, 0), yAxis(0, 1, 0), sideways, up;

	if(dir.dot(yAxis) > .9)
	{
		sideways = dir.cross(xAxis);
	}
	else
	{
		sideways = dir.cross(yAxis);
	}
	up = sideways.cross(dir);


    ChNrFrameSetOrientation(m_camera, m_scene,
				   dir.x(), dir.y(), dir.z(),
				   up.x(), up.y(), up.z());
	SetBack();  

};
void ChCollisionView::SetRelativeDir(GxVec3f dir)
{
	dir.normalize();

	GxVec3f xAxis(1, 0, 0), yAxis(0, 1, 0), sideways, up;

	if(dir.dot(yAxis) > .9)
	{
		sideways = dir.cross(xAxis);
	}
	else
	{
		sideways = dir.cross(yAxis);
	}
	up = sideways.cross(dir);

    ChNrFrameSetOrientation(m_camera, m_sceneCamera,
				   dir.x(), dir.y(), dir.z(),
				   up.x(), up.y(), up.z());  
	SetBack();  

}
void ChCollisionView::SetBack()
{
			  // Step back a bit for the collision view from the current camera loc
			  // to account for the near clipping plane
	GxVec3f dir, up;


    ChNrFrameGetOrientation(m_camera, m_sceneCamera,
				   (ChNrVector*)&dir,
				   (ChNrVector*)&up);  
	dir.normalize();

	dir *= -ChNrViewportGetFront(m_view);
    ChNrFrameSetPosition(m_camera, m_sceneCamera,
				   dir.x(), dir.y(), dir.z());  
}

void ChCollisionView::Render()
{
#if (defined(CH_USE_RLAB))
	::memset(m_zBuffer, 0xff,  WIDTH * HEIGHT * ZBUFFERDEPTH / 8);
#endif
	ChNrViewportClear(m_view);
	ChNrViewportRender(m_view, m_scene);
	ChNrDeviceUpdate(m_dev);

}

float ChCollisionView::GetZ()
{
#if (defined(CH_USE_RLAB))
	GxVec3f pt;
	ChNrVector4d screenCoord;
	unsigned short	zMin = 0xffff;
	int width = ChNrViewportGetWidth(m_view);
	int height = ChNrViewportGetHeight(m_view);
	for(int x = 0; x < width; x++)
	{
		for(int y = 0; y < height; y++)
		{
			int index = y * m_zBufferImage.bytes_per_line / 2 + x ;
			unsigned short	z = ((unsigned short*)m_zBufferImage.buffer1)[index];
			zMin = min(z, zMin);
		}
	}

	if(zMin == 0xffff) return CH_INFINITE_RANGE; // free to move if nothing drawn

	screenCoord.x = 0;
	screenCoord.y = 0;
	#if 1
	screenCoord.x = width / 2;
	screenCoord.y = height / 2;
	#endif
	screenCoord.z =  float(zMin) / 65535.;
	screenCoord.w = 1;
	ChNrViewportInverseTransform(m_view, (ChNrVector*)&pt, &screenCoord);

	// Convert to camera coords
	GxVec3f ptInCameraSpace;
	ChNrFrameInverseTransform(m_camera, (ChNrVector*)&ptInCameraSpace, (ChNrVector*)&pt);

	return ptInCameraSpace.z();
#else
	return 0;
#endif
}


#endif	// 0 or 1

#if (defined(CH_USE_D3D))

// Just stubs to get us going on d3d
#pragma message("D3D Collision Testing Not done!")

#if 0
float ChRenderContext::GetCollisionRange(GxVec3f &look, bool boolRelative /* = false*/)
{
	// Return the range the current camera can be moved without colliding with something
	// value is in -camera- coords

	float range = CH_INFINITE_RANGE; // free to move if no scene
	return range;
};
#endif


#elif (defined(CH_USE_RLAB))


//#define BE_VERY_NOISY_ON_COLLISION_TESTING 1
float ChRenderContext::GetAvatarRadius()
{
	return .1;	// bout the size of your head
};

float ChRenderContext::GetCollisionRange()
{
	// Return the range the current camera can be moved without colliding with something
	// value is in -camera- coords

	float range = CH_INFINITE_RANGE; // free to move if no scene

	if(m_viewport)
	{
		ChNrFrame frame;

		// Lock the scene and don't be nice
		LockScene();
	
		int iX = ChNrViewportGetWidth(m_viewport) / 2;
		int iY = ChNrViewportGetHeight(m_viewport) / 2;
		RLVisual visual;

		if(ChNrViewportFindVisual( m_viewport, &visual, &frame, iX, iY) != RLNotFound)
		{
			// Hit -something-. How far away is it?
			GxVec3f clickPoint;
			ChNrFaceInfo faceInfo;
			if((ChNrViewportFindFace( m_viewport, &faceInfo, iX, iY) != RLNotFound)
						&& faceInfo.frame == frame)
			{
				clickPoint = *(GxVec3f*)&faceInfo.position;
				ChNrVector4d screenCoord;
				screenCoord.x = clickPoint.x();
				screenCoord.y = clickPoint.y();
				screenCoord.z = clickPoint.z();
				screenCoord.w = 1;
				ChNrViewportInverseTransform(m_viewport, (ChNrVector*)&clickPoint, &screenCoord);
			}
			else
			{
				// It's not a face visual, must be a decal
				ChNrFrameGetPosition(frame, m_sceneFrame, (ChNrVector*)&clickPoint);
			}

			// Convert to camera coords
			GxVec3f ptInCameraSpace;
			ChNrFrameInverseTransform(m_cameraFrame, (ChNrVector*)&ptInCameraSpace, (ChNrVector*)&clickPoint);
			
			// take range - I'm not sure if this works if we have a scaling transform before the camera
			range = ptInCameraSpace.magnitude() - 	ChNrViewportGetFront(m_viewport);
			range = max(range, 0.); 

		}

		UnlockScene();

	}
	
	return range;

} 

#endif

// end of file
