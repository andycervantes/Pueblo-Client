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

	Implementation for the computation of bounding boxes of a VRML QV tree
	(currently assumes Intel 3DR.)

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvHitTst.cpp,v 2.20 1996/06/27 03:44:00 jimd Exp $

#include "grheader.h"
//
#if defined( CH_ARCH_16 )
#include <QvElemnt.h>   
#else
#include <QvElement.h>   
#endif
//#include <QvNodes.h>
#include <QvState.h>
#if defined( CH_ARCH_16 )
#include <UnknNode.h>   
#else
#include <QvUnknownNode.h>
#endif
#ifdef CH_MSW
#include <windows.h>
#endif
#ifdef HUGE
#undef HUGE
#endif
#include <math.h>
#include "ChMaze.h"
#include "CvBound.h"
#include "CvHitTst.h"
#include "CvTrnsfm.h"

// Even if we render purely retained, we need this if we use RL
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#include "imode.h"
#endif

#define DEFAULT_HITTEST(cls)	\
	 int cls::HitTest(QvState *state, ChQvBounds * pBounds)	\
	  {traverse(state); return 0;}; 


// for dubugging only
static int indent = 0;
// ---------------


// maybe make this a method of GxVec3f??
// PointDistToLine : 
// Returns the minimum distance between the line (p0, v) and the point q
// Optionally, return the t for the min point, where 
// p = p0 + v * t
float PointDistToLine(const GxVec3f &p0, const GxVec3f &v, const GxVec3f &q, float *pT)
{
	// We do it by minimizing squared distance from line p = p0 + t * v to
	// the point q.
	// 
	GxVec3f alpha(p0);
	alpha -= q;
	
	float t = -(alpha.x() * v.x() + alpha.y() * v.y() + alpha.z() * v.z()) / v.dot(v);  
	if(pT) *pT = t;

	GxVec3f p(v);
	p *= t;
	p += p0;	// p is now nearest point

	p -= q;		// now diff with q
	return p.magnitude();
};

// Intersect a sphere of radius r1 moving along the ray (p0, v) with the sphere
// of radius r2 centered at q
// Return true if they intersect, and place the t intersection value in fT
// fT is unchanged unless intersection happens
bool MovingSphereToSphere(const GxVec3f &p0, const GxVec3f &v, float r1, const GxVec3f &q, float r2, float &fT)
{
	// We do it by minimizing squared distance from line p = p0 + t * v to
	// the point q.
	// 
	GxVec3f alpha(p0);
	alpha -= q;
	
	float a = v.dot(v);
	float b = 2 * (alpha.x() * v.x() + alpha.y() * v.y() + alpha.z() * v.z());
	float r = r1 + r2;
	float c = alpha.dot(alpha) - r * r;

	float desc = b * b - 4. * a * c;
	if(desc < 0) return false;

	float rt = sqrt(desc);

	float t1 = -(b - rt)/ (2. * a);
	float t2 = -(b + rt)/ (2. * a);

	// Select the minimum positive value of t1 and t2
	bool boolHit = false;
	if(t1 >= 0 && t2 >= 0)
	{
		fT = min(t1, t2);
		boolHit = true;
	}
	else if(t1 >= 0)
	{
		fT = t1;
		boolHit = true;
	}
	else if(t2 >= 0)
	{
		fT = t2;
		boolHit = true;
	}
	// else all intersections are behind us in negative t


	return boolHit;
};

void QvWWWAnchor::UpdateSensor(QvState * state)
{
#if defined(CH_USE_3DR)

	G3dHandle_t hGC = ((ChQvState*)state)->GetView()->GetGC();
	
	G3dSetActiveStack(hGC, G3DT_CAM_CLIP);
	G3dPushTransform(hGC);
	G3dSetActiveStack(hGC, G3DT_MODEL);
	G3dPushTransform(hGC);
	
	G3dSetActiveStack(hGC, G3DT_CAM_CLIP);
	G3dPopTransform(hGC);
	G3dSetActiveStack(hGC, G3DT_MODEL);
	G3dPopTransform(hGC);
#endif
}

#if defined(CH_USE_3DR)
void ChQvAnchorSensor::Init(ChRenderContext *pRC)
{
	G3dHandle_t hGC = pRC->GetGC();
	PointF_t dir, up;
	G3dGetCameraPosition(hGC, &m_cameraLoc, &dir, &up);
	G3dSetActiveStack(hGC, G3DT_CAM_CLIP);
	G3dGetTransform(hGC, m_CamClipTransform);
	G3dSetActiveStack(hGC, G3DT_MODEL);
	float right, left, top, bottom;
	G3dGetCameraPort(hGC, &right, &left, &top, &bottom);
	SetPort(left, top, right, bottom);

	// hack: TODO - FIX THIS
	// put the instance's transform on the stack - oughta be ignored later, we hope
	pRC->SetModelTransform(m_pAnchor->GetTransform());
	memcpy(m_ModelTransform, G3dGetModelCamMatrix(hGC), sizeof(m_ModelTransform));
}
#endif

#if defined(CH_USE_3DR)
inline void GetCubeVertex( PointF_t &lower, PointF_t &upper, int num, PointF_t &vert)
{
	vert.x = (num & 4) ? upper.x : lower.x;
	vert.y = (num & 2) ? upper.y : lower.y;				 
	vert.z = (num & 1) ? upper.z : lower.z;				 
}												 

inline PointF_t GetCubeVertex( PointF_t &lower, PointF_t &upper, int num)
{	PointF_t vert;
	vert.x = (num & 4) ? upper.x : lower.x;
	vert.y = (num & 2) ? upper.y : lower.y;
	vert.z = (num & 1) ? upper.z : lower.z;
	return vert;
}

IntersectLineCube(LineF_t &line, PointF_t &lower, PointF_t &upper, PointF_t &ptInt, TransformF_t mat, bool boolRay = true);

#if !defined(EPSILON)
#define EPSILON (1.e-6)
#endif

IntersectLineCube(LineF_t &line, PointF_t &lower, PointF_t &upper, PointF_t &ptInt, TransformF_t mat, bool boolRay)
{
	float	fZNear;
	bool boolHit = false;
	// these are ccw, tho it doesn't matter here
	static int	verts[6][4] = 
	{
		{0, 2, 6, 4},	 // back
		{1, 5, 7, 3},	 // front
		{0, 1, 3, 2},	 // lhs
		{4, 6, 7, 5},	 // rhs
		{0, 4, 1, 5},	 // bottom
		{2, 3, 7, 6}	 // top
	};

	for(int j = 0; j < 6; j++)
	{
		PlaneF_t plane;
		PointF_t pt;
		PointF_t vert0, vert1, vert2;

		GetCubeVertex(lower, upper, verts[j][0], vert0); 
		GetCubeVertex(lower, upper, verts[j][1], vert1);
		GetCubeVertex(lower, upper, verts[j][2], vert2);
		G3d3PointPlane(&vert0, &vert1, &vert2, &plane);
		if(G3dLinePlaneIntersect(&line, &plane, &pt))
		{ 
										// Make the cube bigger to account for FP roundoff
			bool	boolIntersect = 
				pt.x >= lower.x - EPSILON && pt.x <= upper.x + EPSILON &&
				pt.y >= lower.y - EPSILON && pt.y <= upper.y + EPSILON &&
				pt.z >= lower.z - EPSILON && pt.z <= upper.z + EPSILON;

			// Check for 'behind' the line origin, if treating this as a ray
			if(boolRay)
			{
				PointF_t v1;

				v1.x = pt.x - line.point.x;
				v1.y = pt.y - line.point.y;
				v1.z = pt.z - line.point.z;

				if(G3dDot(&v1, &line.vector) < 0) boolIntersect = false; 
			}

			if(boolIntersect)
			{
										// transform to camera space to check z
										// looking for -nearest- intersection
				PointFW_t pt2;
				G3dTransformPointF(&pt, &pt2, mat);
				if(boolHit)
				{						  // neg z is farther ==> greater is nearer
					if(pt2.z > fZNear)
					{
							// new min; replace old intersection
						ptInt = pt;
						fZNear = pt2.z;
					}
				}
				else
				{
							// first face to intersect with this ray
					ptInt = pt;
					fZNear = pt2.z;
					boolHit = true;
				}
			}
		}
	}
	return boolHit;
}

// Computes the line in object space that goes thru wx, wy in window space
void ChQvAnchorSensor::PointWindowToObject(Float_t wx, Float_t wy, LineF_t & line)
{
	PointF_t	pt = {wx, wy, 0};							
	PointF_t	pt2;
	PointFW_t	ptW;

	if(m_boolDirty)
	{
		G3dInvertMatrix(m_CamClipTransform, m_invCamClipTransform);
		G3dInvertMatrix(m_ModelTransform, m_invModelTransform);
		m_boolDirty = false;
	} 
	pt.x = ((pt.x * 2.) / (m_right - m_left)) - 1.;
	pt.y = ((pt.y * 2.) / (m_top - m_bottom)) - 1.;
	pt.y = -pt.y;

	G3dTransformPointF(&pt, &ptW, m_invCamClipTransform); 
	CopyPoint(ptW, pt2);
	G3dTransformPointF(&pt2, &ptW, m_invModelTransform); 
	CopyPoint(ptW, line.vector);
	/////////////
	// Camera is in world coords; convert to model

	GxTransform3Wf mat;
	TransformF_t invMat;
	GxVec3f lower;
	GxVec3f upper;

	m_bounds.GetBounds( upper, lower, mat);
	CopyPoint(m_cameraLoc, pt2);
	G3dInvertMatrix(*(mat.GetMatrix()), invMat);
	G3dTransformPointF(&pt2, &ptW, invMat); 
	CopyPoint(ptW, line.point);

	///////////////
	line.vector.x -= line.point.x;
	line.vector.y -= line.point.y;
	line.vector.z -= line.point.z;
}

bool ChQvAnchorSensor::HitTest(G3dHandle_t hGC, chint32 lX, chint32 lY, float &fZ)
{
	GxVec3f lower;
	GxVec3f upper;
	PointF_t pt;
	PointFW_t pt2;
	GxTransform3Wf mat;
	bool boolHit = false;



	m_bounds.GetBounds( lower, upper, mat);
	LineF_t line;

	PointWindowToObject(lX, lY, line);

	// This function doesn't work - reported to Intel : case #46594
	//G3dPointWindowToObject(hGC, xx, yy, &line); 
	//G3dPointWindowToObject(hGC, lX, lY, &line);

												// this gets nearest pt in WS; i think it should be camera
												// space instead ??!! which means the mat should be the MCT
	//if(IntersectLineCube(line, lower, upper, pt, mat))
												// Like this	   
	
		   
	TransformF_t toClipMat;
	G3dMultMatrix( m_ModelTransform, m_CamClipTransform, toClipMat);
	//if(IntersectLineCube(line, lower, upper, pt, toClipMat))
	PointF_t lowerp, upperp;

	lowerp.x = lower.x();	lowerp.y = lower.y(); lowerp.z = lower.z();
	upperp.x = upper.x();	upperp.y = upper.y(); upperp.z = upper.z();

	if(IntersectLineCube(line, lowerp, upperp, pt, m_ModelTransform))
	{
	   boolHit = true;
	   // transform pt, then
	   G3dTransformPointF(&pt, &pt2, m_ModelTransform);
	   fZ = pt2.z;
	}
	
	return boolHit;
}

#endif


string ChQvAnchorSensor::GetCommand()
{
	#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
	QvInfo * pChild;
	string command, phrase, name, href;

    for (int i = 0; i < GetAnchorNode()->getNumChildren(); i++)
	{
		pChild = (QvInfo*)(GetAnchorNode()->getChild(i));
		// Test if this is really a info node
		string type;
		pChild->GetType(type);
		if(type == "QvInfo")
		{
			name = pChild->getName().getString();
			string prefix = name.Left(3);
			prefix.MakeLower();
			if(prefix == "xch")
			{
				phrase = name;
				string value = 	pChild->string.value.getString();
				if(value != QV_UNDEFINED_INFO)
				{
					phrase += "=\"" + value + "\"";
				}
				
				command += phrase + " ";
			}
		}
	}

	name = GetAnchorNode()->name.value.getString();
	if(!name.IsEmpty() && name != QV_UNDEFINED_INFO)
	{ 
		href.Format("href=\"%s\"", name);
		command += href;
	}
	name = command;

	#else
		// Scout
	string name;
	name = GetAnchorNode()->name.value.getString();
	
	#endif
		 // Append the point field, if we have it
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	if(!name.IsEmpty() && m_pAnchor->IsPointMap())
	{
		string buf;
		buf.Format("?%1.2f,%1.2f,%1.2f", double(m_hitPoint.x()),double(m_hitPoint.y()),double(m_hitPoint.z()));
		name += buf; 
	}
	#else
		// hit point isn't being converted yet!
	#endif
	return name;
}

bool ChQvAnchorSensor::GetHint(string &hint)
{
	QvInfo * pChild;
	string name;
	bool boolFound = false;
	string cmd;
	
	// if there's a description, use that, else look at the info kids

	name = GetAnchorNode()->description.value.getString();

	if(!name.IsEmpty())
	{
		hint = name;
		boolFound = true;
		// we could cache this if it's too slow
	    for (int i = 0; i < GetAnchorNode()->getNumChildren(); i++)
		{
			pChild = (QvInfo*)(GetAnchorNode()->getChild(i));
			// Test if this is really a info node	
			string type;
			pChild->GetType(type);
			if(type == "QvInfo")
			{
				name = pChild->getName().getString();
				name.MakeLower();
				if(name == "xch_cmd")
				{
					cmd = pChild->string.value.getString();
				}
			}
		}
	}
	else
	{
		// we could cache this if it's too slow
	    for (int i = 0; i < GetAnchorNode()->getNumChildren(); i++)
		{
			pChild = (QvInfo*)(GetAnchorNode()->getChild(i));
			// Test if this is really a info node	
			string type;
			pChild->GetType(type);
			if(type == "QvInfo")
			{
				name = pChild->getName().getString();
				name.MakeLower();
				if(!boolFound && name == "xch_hint")
				{
					hint = pChild->string.value.getString();
					boolFound = true;
				}
				if(name == "xch_cmd")
				{
					cmd = pChild->string.value.getString();
				}
			}
		}

	}
	if(!boolFound)		// use the href as the hint
	{
		name = GetAnchorNode()->name.value.getString();
		if(!name.IsEmpty() && name != "<Undefined info>")
		{ 
			hint = name;
			boolFound = true;
		}
	}
	if(!cmd.IsEmpty())
	{
		string tmp = hint;
		hint = cmd;
		if(boolFound)
		{
			hint += " (" + tmp + ")";
		}
		boolFound = true;
	}

	return boolFound;
}

#if defined(CH_USE_3DR)
#endif	   // CH_USE_3DR


bool ChHittestIterator::DoNode(ChQvInstance& inst)
{
	bool boolKeepGoing = true;
	switch(GetVisitType())
	{
		case beforeChildren:
		{
			bool ImHit = false;
						   // GetBounds && check em
			ChQvBounds bounds;
			inst.GetBounds(bounds);

			//check instance's bounds
			GxVec3f hPt;
			ImHit = bounds.HitTest(GetRenderContext(), m_iX, m_iY, hPt); // hit me
			SetDoKids(ImHit); 

			break;
		}
		case afterChildren:
		{
			break;			 
		}
		case isLeaf:
		{
			boolKeepGoing = true; 	// need logic for first find, etc here
			inst.Hittest(GetRenderContext(), this);
			break;
		}
	}
	return boolKeepGoing;

};

void ChHittestIterator::Add(ChQvInstance *pInstance, const GxVec3f &pt)
{
	m_instances.AddTail(ChInstanceHit(pInstance, pt));
};

bool ChHittestIterator::GetHit( ChQvInstance *& closest, GxVec3f &pt)
{
	if(m_instances.IsEmpty()) return false;
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	float distance = 1e17;		// way far away
	ChPosition pos = m_instances.GetHeadPosition();
    while (pos)
    {
        ChInstanceHit &bucket = m_instances.GetNext(pos);
		
		// Transform to screen space
		#if (defined(CH_USE_RLAB))
		RLIMViewVertex ptInScreen;
		
		RLIMTransformVertices
        (   GetRenderContext()->GetViewport(), 
        	bucket.m_pInstance->GetFrame(),
            (RLIMPositionVector*)&(bucket.m_pt),
            &ptInScreen,
            sizeof(RLIMPositionVector), 
            sizeof(RLIMViewVertex),
            1,
            1
        );
		bool boolUseIt = ptInScreen.sz >= 0 && ptInScreen.sz < distance; 

		if(boolUseIt)
		{
			distance = ptInScreen.sz;
			closest =  bucket.m_pInstance;
			pt = bucket.m_pt;
		}
		#elif (defined(CH_USE_D3D) && defined(CH_IMMED_MODE))

		#pragma message("D3D Immediate mode hittesting not done")
		bool boolUseIt = false; 

		#endif

			
    }

	#endif
	return true;
};

bool ChCollisionIterator::DoNode(ChQvInstance& inst)
{
	bool boolKeepGoing = true;
	switch(GetVisitType())
	{
		case beforeChildren:
		{
			bool ImHit = true;
						   // GetBounds && check em
			ChQvBounds bounds;
			inst.GetBounds(bounds);

			//check group instance's bounds
			GxVec3f hPt;
			//ImHit = bounds.Test(GetRenderContext(), m_iX, m_iY, hPt); // hit me  TODO ???????!!!!!!!!!!!!!!!
			SetDoKids(ImHit); 

			break;
		}
		case afterChildren:
		{
			break;			 
		}
		case isLeaf:
		{
			boolKeepGoing = true; 	// need logic for first find, etc here
			inst.CollisionTest(GetRenderContext(), this);
			break;
		}
	}
	return boolKeepGoing;

};

void ChCollisionIterator::Add(ChQvInstance *pInstance, float t)
{
	m_instances.AddTail(ChInstanceHit(pInstance, t));
};

bool ChCollisionIterator::GetHit( ChQvInstance *& closest,float &t)
{
	if(m_instances.IsEmpty()) return false;
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	ChPosition pos = m_instances.GetHeadPosition();
	bool boolHit = false;
    while (pos)
    {
        ChInstanceHit &bucket = m_instances.GetNext(pos);
		
		if(!boolHit || (bucket.m_t < t && bucket.m_t >= 0))
		{
			boolHit = true;
			closest =  bucket.m_pInstance;
			t = bucket.m_t;
		}
    }

	return boolHit;
	#endif
};


/* derived from Graphics Gems II intsph.c
/* ----	intsph - Intersect a ray with a sphere. -----------------------	*/
/*									*/
/*									*/
/*	Description:							*/
/*	    Intsph determines the intersection of a ray with a sphere.	*/
/*									*/
/*	On entry:							*/
/*	    raybase = The coordinate defining the base of the		*/
/*		      intersecting ray.					*/
/*	    raycos  = The direction cosines of the above ray.		*/
/*	    center  = The center location of the sphere.		*/
/*	    radius  = The radius of the sphere.				*/
/*									*/
/*	On return:							*/
/*	    rin     = The entering distance of the intersection.	*/
/*	    rout    = The leaving  distance of the intersection.	*/
/*									*/
/*	Returns:  True if the ray intersects the sphere.		*/
/*									*/
/* --------------------------------------------------------------------	*/


int	intsph(const GxVec3f &raybase, const GxVec3f &raycos, const GxVec3f &center, float radius, float &rin, float &rout)
{
	int	hit;			/* True if ray intersects sphere*/
	double	dx, dy, dz;		/* Ray base to sphere center	*/
	double	bsq, u, disc;
	double	root;


	dx   = raybase.x() - center.x();
	dy   = raybase.y() - center.y();
	dz   = raybase.z() - center.z();
	bsq  = dx*raycos.x() + dy*raycos.y() + dz*raycos.z(); 
	u    = dx*dx + dy*dy + dz*dz - radius*radius;
	disc = bsq*bsq - u;
  
	hit  = (disc >= 0.0);

	if  (hit) { 				/* If ray hits sphere	*/
	    root  =  sqrt(disc);
	    rin  = -bsq - root;		/*    entering distance	*/
	    rout = -bsq + root;		/*    leaving distance	*/
	}
  
	return (hit);
}

bool ChQvSphereInstance::Hittest(ChRenderContext *pRC, ChHittestIterator *pIterator)
{
	GxVec3f p, vec;	// the line
	int iX, iY;
	pIterator->GetScreenPoint(iX, iY);
	m_pBounds->SetTransform(GetTransform());;	// refresh bounds
	m_pBounds->PointWindowToObject(pRC, iX, iY, p, vec);
	vec.normalize();
	GxVec3f center(0, 0, 0);	  // always centered at 0 in object space
	float rin, rout;
	int hit = intsph(p, vec, center, ((QvSphere*)GetNode())->radius.value, rin, rout);
	if(hit && (rin >= 0 || rout >= 0))
	{
		float t = (rin >= 0) ? rin : rout;
		vec *= t;
		vec += p;
		pIterator->Add(this, vec); 
	}
	return true;
}

bool ChQvSphereInstance::CollisionTest(ChRenderContext *pRC, ChCollisionIterator *pIterator)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	// using rlab transforms here - otherwise portable
	GxVec3f p0(pIterator->GetLoc()), vec(pIterator->GetDir());	// the line
	float radius = pIterator->GetRadius();
	
	GxVec3f center(0, 0, 0);	  // always centered at 0 in object space
	float r = ((QvSphere*)GetNode())->radius.value;
	// now transform camera loc and dir to object - they are in world now
	GxVec3f vecObj, p0Obj;
	vec += p0;
	vec.z() = -vec.z();
	p0.z() = -p0.z();
	ChNrFrameInverseTransform(m_frame, (ChNrVector*)&vecObj, (ChNrVector*)&vec);
	ChNrFrameInverseTransform(m_frame, (ChNrVector*)&p0Obj, (ChNrVector*)&p0);
	vecObj -= p0Obj;

	// R is a problem TODO	 !!!!!!!!!!!!

	float t;
	int hit = MovingSphereToSphere(p0Obj, vecObj, radius, center, r, t);

	if(hit && (t >= 0.0))
	{
		pIterator->Add(this, t); 
	}
#endif
	return true;
}

#if (defined(CH_USE_RLAB))
bool ChRenderContext::GetHitPoint(int iX, int iY, GxVec3f &pt)
{
	// ix and iY are in screen coords; pt is in -world- coords

	bool boolHit = false; 

	if(m_viewport)
	{
		ChNrFrame frame;

		// Lock the scene and don't be nice
		LockScene();
	
		RLVisual visual;
		const float aTinyBit = 1e-6;
		 
		if(ChNrViewportFindVisual( m_viewport, &visual, &frame, iX, iY) != RLNotFound)
		{
			// Hit -something-. How far away is it?
			GxVec3f clickPoint, framePoint;
			ChNrFaceInfo faceInfo;
			ChNrVector4d screenCoord, frameScreenCoord;

			ChNrFrameGetPosition(frame, m_sceneFrame, (ChNrVector*)&framePoint);
			ChNrViewportTransform(m_viewport, &frameScreenCoord, (ChNrVector*)&framePoint);
			float fVisualFrameZ = ((frameScreenCoord.w != 0.0) ? (frameScreenCoord.z / frameScreenCoord.w) : 0.0);
			RLError foundIt = ChNrViewportFindFace( m_viewport, &faceInfo, iX, iY);
			if( foundIt != RLNotFound )
			{
				ChNrFrameGetPosition(faceInfo.frame, m_sceneFrame, (ChNrVector*)&clickPoint);
				ChNrViewportTransform(m_viewport, &frameScreenCoord, (ChNrVector*)&clickPoint);
				float fFaceFrameZ = ((frameScreenCoord.w != 0.0) ? (frameScreenCoord.z / frameScreenCoord.w) : 0.0);
				if(faceInfo.frame == frame  || fFaceFrameZ <= fVisualFrameZ + aTinyBit )
				{
					clickPoint = *(GxVec3f*)&faceInfo.position;
					screenCoord.x = clickPoint.x();
					screenCoord.y = clickPoint.y();
					screenCoord.z = clickPoint.z();
					screenCoord.w = 1;
					ChNrViewportInverseTransform(m_viewport, (ChNrVector*)&clickPoint, &screenCoord);
				}
				else
				{
					// It's not a face visual, must be a decal
					clickPoint = framePoint;
				}
			}
			else
			{
				// It's not a face visual, must be a decal
				clickPoint = framePoint;
			}

			// Convert to world coords
			ChNrFrameInverseTransform(m_sceneFrame, (ChNrVector*)&pt, (ChNrVector*)&clickPoint);
			boolHit = true;
	

		}
		// Now see if it's in the immediate render world
		#if defined(CH_IMMED_MODE)
		{
			ChHittestIterator	iterator(this, iX, iY);
			iterator.Attach(GetRoot());
			iterator.Iterate();

			ChQvInstance *pInst;
			GxVec3f immpt;

			if(iterator.GetHit(pInst, immpt))
			{
				ChNrFrame	hitFrame = pInst->GetFrame();
				bool boolIsClosest = true;
				if(boolHit)
				{
					RLIMViewVertex ptInScreen;
		
					#if 1
					RLIMTransformVertices
				    (   GetViewport(), 
				    	m_sceneFrame,
				        (RLIMPositionVector*)&(pt),
				        &ptInScreen,
				        sizeof(RLIMPositionVector), 
				        sizeof(RLIMViewVertex),
				        1,
				        1
				    );
					#endif
					float retainedZ = ptInScreen.sz;

					RLIMTransformVertices
				    (   GetViewport(), 
				    	hitFrame,
				        (RLIMPositionVector*)&(immpt),
				        &ptInScreen,
				        sizeof(RLIMPositionVector), 
				        sizeof(RLIMViewVertex),
				        1,
				        1
				    );
					float immedZ = ptInScreen.sz;

					boolIsClosest = immedZ < retainedZ;
				}
				if(boolIsClosest)
				{
					GxVec3f tmp;
					ChNrFrameTransform(hitFrame, (ChNrVector*)&tmp, (ChNrVector*)&immpt);
					ChNrFrameInverseTransform(m_sceneFrame, (ChNrVector*)&pt, (ChNrVector*)&tmp);
					boolHit = true;
				}
			}
		}
		#endif

		UnlockScene();
	}
	
	return boolHit;

} 

//#if 0
#elif (defined(CH_USE_D3D))

bool ChRenderContext::GetHitPoint(int iX, int iY, GxVec3f &pt)
{
	// ix and iY are in screen coords; pt is in -world- coords


	bool boolHit = false; 

	if(m_viewport)
	{

		// Lock the scene and don't be nice
		LockScene();
	
		GxVec3f	retainedPoint;
	    LPDIRECT3DRMVISUAL visual;
	    LPDIRECT3DRMFRAME pickFrame;
	    LPDIRECT3DRMPICKEDARRAY picked = 0;
	    LPDIRECT3DRMFRAMEARRAY frames;
	    LPDIRECT3DRMMESHBUILDER mesh;
	    LPDIRECT3DRMTEXTURE decal;
		D3DRMPICKDESC 	pickInfo;

		HRESULT rval = m_viewport->Pick(iX, iY, &picked);
		int count = picked ? picked->GetSize() : 0;
		float z = 0;
		if(count > 0)
		{
            picked->GetPick(0, &visual, &frames, &pickInfo);
            frames->GetElement(frames->GetSize() - 1, &pickFrame);

            if (SUCCEEDED(visual->QueryInterface(IID_IDirect3DRMMeshBuilder, (void **) &mesh)))
            {   
                mesh->Release();
				boolHit = true;
            }
            else if (SUCCEEDED(visual->QueryInterface(IID_IDirect3DRMTexture, (void **) &decal)))
            {   
                decal->Release();
 				boolHit = true;
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
			ChNrViewportInverseTransform(m_viewport, (ChNrVector*)&clickPoint, &screenCoord);

			ChNrFrameInverseTransform(m_sceneFrame, (ChNrVector*)&pt, (ChNrVector*)&clickPoint);

		}
		UnlockScene();
	
	}
	return boolHit;
};
#endif

//#endif
// end of file
