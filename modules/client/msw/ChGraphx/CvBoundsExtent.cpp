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

	Implementation of ChQvInstance::GetBoundsExtent.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvBoundsExtent.cpp,v 2.1 1996/06/27 03:43:56 jimd Exp $

#include "grheader.h"

#include "CvInstnc.h"
#include <QvInfo.h>
#include <QvState.h>
#include "ChMaze.h"
#include "ChRenderData.h"
#include "ChScriptData.h"
#include "ChMazDep.h"
#include "CvTrnsfm.h"
#include "CvNormal.h"
#include "CvBound.h"
#include "CvConvrt.h"
#include "CvHitTst.h"
#include "imode.h"


/* Get extent of bounds passed in if != 0, or default to bounds of instance */
ChRect ChQvInstance::GetBoundsExtent(ChRenderContext *pRC, ChQvBounds *pBounds, bool *pboolClipped, bool boolBeGenerous)
{
	// boolClipped means -completely- clipped
	// we'll set it to true if anything lies within the viewport
	// If boolBeGenerous is set, put a buffer area around the viewport
	// for clipping purposes. This means nearby things will be flagged as
	// not clipped.
	bool boolClipped = true;

	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	ASSERT(m_frame);
	ASSERT(pRC);
	ASSERT(pRC->GetViewport());

	ChQvBounds bounds;
	if(pBounds)
	{
		bounds = *pBounds;
	}
	else
	{
		GetBounds(bounds);
	}
	
	// Take bounding cube
	float fpts[8*3];
	GxVec3f *pts = (GxVec3f *)fpts;	 // don't construct! (faster)
	GxVec3f lower, upper;

	bounds.GetBounds(lower, upper);

	for(int j=0; j<8; j++)
	{
		pts[j].set( ((j & 1) ? lower.x() : upper.x()),
					((j & 2) ? lower.y() : upper.y()),
					((j & 4) ? lower.z() : upper.z()));
		
	}
	ChNrViewport view = pRC->GetViewport();

	#if (defined(CH_USE_RLAB))
	 // use immed mode api
	RLIMViewVertex		viewVerts[8];

	RLIMClippingFlag clip = RLIMTransformVertices
    (   view, 
    	m_frame,
        (RLIMPositionVector*)(pts),
        viewVerts,
        sizeof(GxVec3f), 
        sizeof(RLIMViewVertex),
        8,
        1
    );

	boolClipped = true;
								// RLIMTransformVertices doesn't fill
								// in screen coords sometimes
								// if the point is clipped, so use the 
								// homogeneous ones. We'll wait to convert
								// until it's the rect to minimize computations
	for(j=0; j<8; j++)
	{
		float rhw = viewVerts[j].hw;
		if(rhw != 0.0) rhw = 1 / rhw;
		pts[j].set(viewVerts[j].hx * rhw , viewVerts[j].hy * rhw, viewVerts[j].hz * rhw);

		if(boolClipped && pboolClipped)
		{
			if( 0 <= viewVerts[j].hz )	// just check for behind 
			{
				boolClipped = false;
			}
		}
	}
	#elif (defined(CH_USE_D3D))
  	// Transform to screen space
	GxVec3f tmp;
	for(j=0; j<8; j++)
	{
		// first to world
		ChNrFrameTransform(m_frame, (ChNrVector*)(&tmp), (ChNrVector*)(pts + j));
		pts[j] = tmp;
	}

	for(j=0; j<8; j++)
	{
		// then to screen
		ChNrVector4d tmp;
		ChNrViewportTransform(pRC->GetViewport(), (&tmp), (ChNrVector*)(pts + j));

		#if 0
		// assume it works unless we find otherwise
		// RL's viewport transforms are sometimes completely bogus,
		// so do the inverse and see if it makes sense. If not, we'll
		// ignore this one and return a null rect
		GxVec3f invTmp;
		ChNrViewportInverseTransform(pRC->GetViewport(), (ChNrVector*)(&invTmp), (&tmp));
		
		invTmp -= pts[j];
		float mag = invTmp.magnitude();
		if(mag / pts[j].magnitude() > 1e-2)
		{
			// Bogus transform!
			if(pboolClipped) *pboolClipped = false;
			ChRect rtExtent(0,0,0,0);
			return rtExtent;
		}
		#endif // test for bogosity

		pts[j].x() = tmp.x / tmp.w;
		pts[j].y() = tmp.y / tmp.w;
		pts[j].z() = tmp.z / tmp.w;
		if(boolClipped && pboolClipped)
		{
			if( 0 <= tmp.z )	// just check for behind 
			{
				boolClipped = false;
			}
		}
	}

	#else
	// old code - use retained mode api
	// Transform to screen space
	for(j=0; j<8; j++)
	{
		// first to world
		ChNrFrameTransform(m_frame, (ChNrVector*)(&tmp), (ChNrVector*)(pts + j));
		pts[j] = tmp;
	}

	for(j=0; j<8; j++)
	{
		// then to screen
		ChNrVector4d tmp;
		ChNrViewportTransform(pRC->GetViewport(), (&tmp), (ChNrVector*)(pts + j));

		// RL's viewport transforms are sometimes completely bogus,
		// so do the inverse and see if it makes sense. If not, we'll
		// ignore this one and return a null rect
		GxVec3f invTmp;
		ChNrViewportInverseTransform(pRC->GetViewport(), (ChNrVector*)(&invTmp), (&tmp));
		
		invTmp -= pts[j];
		float mag = invTmp.magnitude();
		if(mag / pts[j].magnitude() > 1e-2)
		{
			// Bogus transform!
			if(pboolClipped) *pboolClipped = false;
			ChRect rtExtent(0,0,0,0);
			return rtExtent;
		}

		pts[j].x() = tmp.x / tmp.w;
		pts[j].y() = tmp.y / tmp.w;
		pts[j].z() = tmp.z / tmp.w;
		if(boolClipped && pboolClipped)
		{
			#if 0
			if( tmp.w * xmin <= tmp.x && tmp.x < tmp.w * xmax &&
				tmp.w * ymin <= tmp.y && tmp.y < tmp.w * ymax &&
				0 <= tmp.z && tmp.z < tmp.w)
			#endif
			if( 0 <= tmp.z )	// just check for behind 
			{
				boolClipped = false;
			}
		}
	}

	#endif

	// Take the bounds of result
	bounds.GetBounds( pts, 8, lower, upper );


	int xmin, xmax, ymin, ymax;
	xmin = 0;
	xmax = ChNrViewportGetWidth(view);
	ymin = 0;
	ymax = ChNrViewportGetHeight(view);
	int halfExtent = max(xmax, ymax) / 2;
	#if (defined(CH_USE_D3D))
	ChRect rtExtent(int(lower.x()), 
					int(lower.y()), 
					int(upper.x()), 
					int(upper.y()));
	#else
											   // extent is in homo coords,
											   // convert to screen
	ChRect rtExtent(int(lower.x() * halfExtent) + xmax / 2, 
					int(lower.y() * halfExtent) + ymax / 2, 
					int(upper.x() * halfExtent) + xmax / 2, 
					int(upper.y() * halfExtent) + ymax / 2);
	#endif

	rtExtent.bottom = max(rtExtent.top+1, rtExtent.bottom);		   // guarantee some extent - at least a pixel
	rtExtent.right = max(rtExtent.left+1, rtExtent.right);

	// Intersect the extent rect with the viewport to figure out x/y clipping
	if(!boolClipped)
	{

		ChRect viewRect(xmin, ymin, xmax, ymax), r;
											  // Put a buffer area around the viewport
											  // so objects nearby are indicated as not clipped
		if(boolBeGenerous)
		{
			viewRect.InflateRect((xmax - xmin) / 3, (ymax - ymin) / 3);	
		}

		boolClipped = !r.IntersectRect(&rtExtent, &viewRect);
	}



	if(pboolClipped)
	{
		if(boolClipped)
		{							 // weird code here to set breakpoints
		 	*pboolClipped = true;	 // set the return if desired
		}
		else
		{
		 	*pboolClipped = false;	 // set the return if desired
		}
	}
	return rtExtent;
	
	#else

	// Even older attempt - using our own transforms

	GxVec3f lower, upper;
	#if DEBUG
	GxTransform3Wf modelWorld = GetTransform();
	#endif

	GxTransform3Wf modelCamera = pRC->GetWorldToCameraTransform();	// world to camera
	modelCamera *= GetTransform();						// now it's model to camera
	ChQvBounds bounds;
	if(pBounds)
	{
		bounds = *pBounds;
	}
	else
	{
		GetBounds(bounds);
	}
	bounds.GetTransformedBounds(lower, upper, modelCamera);

	GxTransform3Wf cameraToClip = pRC->GetCameraToClipTransform();
	GxTransform3Wf clipToScreen = pRC->GetClipToScreenTransform();
	float wu, wl;
	lower = cameraToClip.TransformW(lower, wl);
	lower *= 1. / wl;
	upper = cameraToClip.TransformW(upper, wu);
	upper *= 1. / wu;
	lower = clipToScreen * lower;
	upper = clipToScreen * upper;
	ChRect rtExtent(int(lower.x()), int(lower.y()), int(upper.x()), int(upper.y()));
	return rtExtent;
	#endif
}

// end of file
