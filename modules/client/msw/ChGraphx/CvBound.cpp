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

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvBound.cpp,v 2.28 1996/06/27 03:43:55 jimd Exp $

#include "grheader.h"
//
#if defined( CH_ARCH_16 )
#include <QvElemnt.h>   
#else
#include <QvElement.h>   
#endif
#include <QvNodes.h>
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
#include <strstrea.h>
#include "ChMaze.h"
#include "CvBound.h"
#include "CvInstnc.h"

#define DEFAULT_GETBOUNDS(cls)	\
	 int cls::GetBounds(QvState *state, ChQvBounds * pBounds)	\
	  {traverse(state); return 0;}; 

// If they make it bigger, tough
#define BIGGIE 1.e17

// for dubugging only
static int indent = 0;
// ---------------


/* ChQvBounds methods */



#if 0
bool GetBoundingCube(QvMFLong *pCoordIndex, QvCoordinate3 *pC3, PointF_t &lower, PointF_t &upper, PointF_t &center ) 
{
	lower.x = lower.y = lower.z = BIGGIE;
	upper.x = upper.y = upper.z = -BIGGIE;
	center.x = center.y = center.z = 0.;
	int count = 0;

	for( int j = 0; j< pCoordIndex->num; j++)
	{
		if (pCoordIndex->values[j] != QV_END_FACE_INDEX)
		{ 
			int index = pCoordIndex->values[j] * 3;
			lower.x = min(lower.x, pC3->point.values[index]);
			lower.y = min(lower.y, pC3->point.values[index+1]); 
			lower.z = min(lower.z, pC3->point.values[index+2]); 

			upper.x = max(upper.x, pC3->point.values[index]);
			upper.y = max(upper.y, pC3->point.values[index+1]); 
			upper.z = max(upper.z, pC3->point.values[index+2]);
			
			center.x += pC3->point.values[index]; 
			center.y += pC3->point.values[index+1];
			center.z += pC3->point.values[index+2];
			
			count++;
		}
 
	}

	if(count>0)
	{
		center.x /= count;
		center.y /= count;
		center.z /= count;
	}
	return true;
}



bool GetBoundingCube(QvIndexedFaceSet *pFace, QvCoordinate3 *pC3, PointF_t &lower, PointF_t &upper, PointF_t &center ) 
{
	return (GetBoundingCube(&pFace->coordIndex, pC3, lower, upper, center));
}

bool GetBoundingCube(QvIndexedLineSet *pSet, QvCoordinate3 *pC3, PointF_t &lower, PointF_t &upper, PointF_t &center ) 
{
	return (GetBoundingCube(&pSet->coordIndex, pC3, lower, upper, center));
}


bool GetBoundingCube(QvCone *cone, PointF_t *pBnds) 
{
	pBnds[0].x = -cone->bottomRadius.value;  
	pBnds[0].y = -cone->height.value / 2.;  
	pBnds[0].z = -cone->bottomRadius.value;  
	pBnds[1].x = cone->bottomRadius.value;  
	pBnds[1].y = cone->height.value / 2.;   
	pBnds[1].z = cone->bottomRadius.value;  
	return true;
}

bool GetBoundingCube(QvCylinder *cylinder, PointF_t *pBnds) 
{
	pBnds[0].x = -cylinder->radius.value;  
	pBnds[0].y = -cylinder->height.value / 2.;  
	pBnds[0].z = -cylinder->radius.value;  
	pBnds[1].x = cylinder->radius.value;  
	pBnds[1].y = cylinder->height.value / 2.;   
	pBnds[1].z = cylinder->radius.value;  
	return true;
}
#endif

// ChQvBounds
void ChQvBounds::Apply(ChQvInstance *pInst, ChRenderContext *pRC)
{
	ChBoundsIterator iterator(pRC, this);
	iterator.Attach( pInst );
	iterator.Iterate( );
}



void ChQvBounds::GetTransformedBounds(GxVec3f &lower, GxVec3f &upper, GxTransform3Wf &mat)
{
	// Transform vertices of object cube, then take cube in transformed coords
	GxVec3f tmp, pts[8];
	for(int j=0; j<8; j++)
	{
		tmp.x() = (j & 1) ? m_lower.x() : m_upper.x();;
		tmp.y() = (j & 2) ? m_lower.y() : m_upper.y();;
		tmp.z() = (j & 4) ? m_lower.z() : m_upper.z();
		pts[j] = mat * tmp;
	}
	GetBounds( pts, 8, lower, upper );
}


void ChQvBounds::GetBounds(GxVec3f &lower, GxVec3f &upper, GxTransform3Wf &mat)
{
	lower.x() 	 = 	 m_lower.x(); 
	lower.y() 	 = 	 m_lower.y(); 
	lower.z() 	 = 	 m_lower.z(); 
	upper.x() 	 = 	 m_upper.x(); 
	upper.y() 	 = 	 m_upper.y(); 
	upper.z() 	 = 	 m_upper.z(); 
	mat = GxTransform3Wf(m_mat);
}

void ChQvBounds::GetCenter(GxVec3f &center)
{
	center.x() 	  =   m_center.x();
	center.y() 	  =   m_center.y();
	center.z() 	  =   m_center.z();
}								
								

void ChQvBounds::GetBounds(GxVec3f *pts, int numPts, GxVec3f &lower, GxVec3f &upper ) 
{
	lower.set(BIGGIE, BIGGIE, BIGGIE);
	upper.set(-BIGGIE, -BIGGIE, -BIGGIE);
	for( int index = 0; index< numPts; index++)
	{
		lower.minimum(pts[index]);
		upper.maximum(pts[index]);
	}
	return;
}

void ChQvBounds::GetBounds(GxVec3f *pts, int numPts, GxVec3f &lower, GxVec3f &upper, GxVec3f &center ) 
{
	lower.set(BIGGIE, BIGGIE, BIGGIE);
	upper.set(-BIGGIE, -BIGGIE, -BIGGIE);
	center.set(0,0,0);
	for( int index = 0; index < numPts; index++)
	{
		lower.minimum(pts[index]);
		upper.maximum(pts[index]);
 		center += pts[index];
	}

	if(numPts > 0) center *= 1./float(numPts);
	return;
}

bool ChQvBounds::IntersectLine(const GxVec3f &p0, const GxVec3f &vec, GxVec3f &result, bool boolRay)
{
	float	fMinT;
	bool boolHit = false;
	const float epsilon = 1.e-6;

	{
		// Line is of form p = p0 + t * vec
		float t;
		for(int face = 0; face < 6; face++)
		{
			GxVec3f &p = (face & 1) ? m_lower : m_upper;
			int i = face / 2;
			if(fabs(vec[i]) > epsilon)
			{
				t = (p[i]  - (p0[i]))/ vec[i];
		
				for(int j = 0; j < 2; j++)
				{
					int index = (i+j) % 3;
					float val = p0[index] + t * vec[index];
					if((!boolRay || t > 0) && val >= m_lower[index] - epsilon && val <= m_upper[index] + epsilon)
					{
						if(boolHit)
						{
							fMinT = min(t, fMinT);
						}
						else
						{
							boolHit = true;
							fMinT = t;
							result = vec;
							result *= t;
							result += p0;
						}
					}
				}  
			}
		}
	}
	if(boolHit)
	{
		result = vec;
		result *= fMinT;
		result += p0;
	}
	return boolHit;
}

// Hittest the screen point lX, lY against this bounds cube
// Return true if a hit, and the collision point in fZ
bool ChQvBounds::HitTest(ChRenderContext *pRC, chint32 lX, chint32 lY, GxVec3f &hPt)
{
	GxVec3f p, vec;	// the ray
	GxVec3f hitPt;
	bool boolHit = false;


	PointWindowToObject(pRC, lX, lY, p, vec);


	if(IntersectLine(p, vec, hitPt))
	{
		hPt = hitPt;
		boolHit = true;
	}
	
	return boolHit;
}

// Computes the line (p, vec) in object space that goes thru wx, wy in window space
void ChQvBounds::PointWindowToObject(ChRenderContext *pRC, float wx, float wy, GxVec3f &p, GxVec3f &vec)
{
	ChNrVector4d screenCoord = {wx, wy, 0, 1};
	#if 0
	screenCoord.x = wx;
	screenCoord.y = wy;
	screenCoord.z = 0;
	screenCoord.w = 1;
	#endif
	GxVec3f q;	// p in world space
	ChNrViewportInverseTransform(pRC->GetViewport(), (ChNrVector*)&q, &screenCoord);

	GxVec3f camLoc = pRC->GetCameraLoc();

	GxTransform3Wf m = m_mat.Inverse();
	q.z() = -q.z();	   // root frame transform
	p = m * camLoc;
	vec = m * q;
	vec -= p;
#if 0
	// 3dr version
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
#endif
}



// Node Bounds methods  - soon to be obsolete

#if 0
DEFAULT_GETBOUNDS(QvSpin)
DEFAULT_GETBOUNDS(QvCone)
DEFAULT_GETBOUNDS(QvCube)
DEFAULT_GETBOUNDS(QvCylinder)
DEFAULT_GETBOUNDS(QvGroup)
DEFAULT_GETBOUNDS(QvIndexedFaceSet)
DEFAULT_GETBOUNDS(QvIndexedLineSet)
DEFAULT_GETBOUNDS(QvLOD)	// ??
DEFAULT_GETBOUNDS(QvSeparator)
DEFAULT_GETBOUNDS(QvSpinGroup)
DEFAULT_GETBOUNDS(QvSwitch)			// ??
DEFAULT_GETBOUNDS(QvTransformSeparator)
DEFAULT_GETBOUNDS(QvBackground)
									  // ??'s below are yet to be done

DEFAULT_GETBOUNDS(QvAsciiText)
DEFAULT_GETBOUNDS(QvBaseColor)
DEFAULT_GETBOUNDS(QvFontStyle)

DEFAULT_GETBOUNDS(QvCoordinate3)
DEFAULT_GETBOUNDS(QvDirectionalLight)
#if defined(_QV_ENVIRONMENT_)
DEFAULT_GETBOUNDS(QvEnvironment)
#endif
DEFAULT_GETBOUNDS(QvInfo)
DEFAULT_GETBOUNDS(QvMaterial)
DEFAULT_GETBOUNDS(QvMaterialBinding)
DEFAULT_GETBOUNDS(QvMatrixTransform)
DEFAULT_GETBOUNDS(QvNormal)
DEFAULT_GETBOUNDS(QvNormalBinding)
DEFAULT_GETBOUNDS(QvOrthographicCamera)
DEFAULT_GETBOUNDS(QvPerspectiveCamera)
DEFAULT_GETBOUNDS(QvPointLight)
DEFAULT_GETBOUNDS(QvPointSet)	  // ??
DEFAULT_GETBOUNDS(QvRotation)
DEFAULT_GETBOUNDS(QvScale)
DEFAULT_GETBOUNDS(QvShapeHints)
DEFAULT_GETBOUNDS(QvSphere)		   // ??
DEFAULT_GETBOUNDS(QvSpotLight)
DEFAULT_GETBOUNDS(QvTexture2)
DEFAULT_GETBOUNDS(QvTexture2Transform)
DEFAULT_GETBOUNDS(QvTextureCoordinate2)
DEFAULT_GETBOUNDS(QvTransform)
DEFAULT_GETBOUNDS(QvTranslation)
DEFAULT_GETBOUNDS(QvWWWAnchor)			 // ??
DEFAULT_GETBOUNDS(QvWWWInline)			 // ??
DEFAULT_GETBOUNDS(QvUnknownNode)		 // ??

DEFAULT_GETBOUNDS(QvOrientationInterpolator)
DEFAULT_GETBOUNDS(QvInterpolator)
DEFAULT_GETBOUNDS(QvSensor)
DEFAULT_GETBOUNDS(QvTimeSensor)
#endif

// Instance Bounds computers - the wave of the future

// First the helpers - these are pretty local
bool GetBoundingCube(QvMFLong *pCoordIndex, QvCoordinate3 *pC3, GxVec3f &lower, GxVec3f &upper, GxVec3f &center ) 
{
	lower.set(BIGGIE, BIGGIE, BIGGIE);
	upper.set(-BIGGIE, -BIGGIE, -BIGGIE);
	center.set(0., 0., 0.);
	int count = 0;

	for( int j = 0; j< pCoordIndex->num; j++)
	{
		if (pCoordIndex->values[j] != QV_END_FACE_INDEX)
		{ 
			int index = pCoordIndex->values[j] * 3;
			#if 1
			// Should be faster this way!
			GxVec3f *p = (GxVec3f*)(pC3->point.values+index);	// ASSUMES ALIGNMENT!!
			lower.minimum(*p);
			upper.maximum(*p);
	 		center += *p;

			#else

			lower.x() = min(lower.x(), pC3->point.values[index]);
			lower.y() = min(lower.y(), pC3->point.values[index+1]); 
			lower.z() = min(lower.z(), pC3->point.values[index+2]); 

			upper.x() = max(upper.x(), pC3->point.values[index]);
			upper.y() = max(upper.y(), pC3->point.values[index+1]); 
			upper.z() = max(upper.z(), pC3->point.values[index+2]);
			
			center.x() += pC3->point.values[index]; 
			center.y() += pC3->point.values[index+1];
			center.z() += pC3->point.values[index+2];
			#endif
			count++;
		}
 
	}

	if(count>0)
	{
		center.x() /= count;
		center.y() /= count;
		center.z() /= count;
	}
	return true;
}



// Then the Node Instances

bool ChQvIFSInstance::ComputeBounds()
{	
	if(!m_pBounds) m_pBounds = new ChQvBounds;
	GxVec3f upper, lower, center;
	QvCoordinate3 *pC3 = GetCoordinate3();
	GetBoundingCube( &(((QvIndexedFaceSet*)GetNode())->coordIndex), pC3, lower, upper, center);

	m_pBounds->SetBounds(lower, upper);
	m_pBounds->SetCenter(center);
	m_pBounds->SetTransform(GetTransform());
	m_boolBoundsDirty = false;   
	return true;
};
 
bool ChQvILSInstance::ComputeBounds()
{
	if(!m_pBounds) m_pBounds = new ChQvBounds;
	GxVec3f upper, lower, center;
	QvCoordinate3 *pC3 = GetCoordinate3();
	GetBoundingCube( &(((QvIndexedLineSet*)GetNode())->coordIndex), pC3, lower, upper, center);

	m_pBounds->SetBounds(lower, upper);
	m_pBounds->SetCenter(center);
	m_pBounds->SetTransform(GetTransform());
	m_boolBoundsDirty = false;   
	   
	return true;
}; 

bool ChQvCubeInstance::ComputeBounds()
{
	if(!m_pBounds) m_pBounds = new ChQvBounds;
	GxVec3f lower, upper, center(0.,0.,0);
	QvCube * pCube = (QvCube *)GetNode();

	lower.x() = -pCube->width.value / 2.;   
	lower.y() = -pCube->height.value / 2.;  
	lower.z() = -pCube->depth.value / 2.;   
	upper.x() =  pCube->width.value / 2.;   
	upper.y() =  pCube->height.value / 2.;  
	upper.z() =  pCube->depth.value / 2.;
	
	m_pBounds->SetBounds(lower, upper);
	m_pBounds->SetCenter(center);
	m_pBounds->SetTransform(GetTransform());
	m_boolBoundsDirty = false;   
	   
	return 1;
}; 

int ChQvConeInstance::ComputeBounds()
{
	if(!m_pBounds) m_pBounds = new ChQvBounds;
	GxVec3f lower, upper, center(0.,0.,0);
 	QvCone * pCone = (QvCone *)GetNode();

	lower.x() = -pCone->bottomRadius.value;   
	lower.y() = -pCone->height.value / 2.;  
	lower.z() = -pCone->bottomRadius.value;   
	upper.x() =  pCone->bottomRadius.value;   
	upper.y() =  pCone->height.value / 2.;  
	upper.z() =  pCone->bottomRadius.value;
	
	m_pBounds->SetBounds(lower, upper);
	m_pBounds->SetCenter(center);
	m_pBounds->SetTransform(GetTransform());
	m_boolBoundsDirty = false;   
	   
	return 1;
}; 

int ChQvSphereInstance::ComputeBounds()
{
	if(m_boolBoundsDirty)
	{
		if(!m_pBounds) m_pBounds = new ChQvBounds;
		GxVec3f lower, upper, center(0.,0.,0);
	  	QvSphere * pSphere = (QvSphere *)GetNode();

		lower.x() = -pSphere->radius.value;   
		lower.y() = -pSphere->radius.value;  
		lower.z() = -pSphere->radius.value;   
		upper.x() =  pSphere->radius.value;   
		upper.y() =  pSphere->radius.value;  
		upper.z() =  pSphere->radius.value;
	
		m_pBounds->SetBounds(lower, upper);
		m_pBounds->SetCenter(center);
		m_pBounds->SetTransform(GetTransform());
		m_boolBoundsDirty = false;   
		m_boolBoundsDirty = false;   
	}   
	return 1;
}; 

const float fMinInlineBox = 1.0e-6;

int ChQvWWWInlineInstance::ComputeBounds()
{
	if(!m_pBounds) m_pBounds = new ChQvBounds;
	QvWWWInline * pWWWInline = (QvWWWInline *)GetNode();
	GxVec3f lower, upper, center;

	float fHalfWidth = pWWWInline->bboxSize.value[0] / 2.0;
	float fHalfHeight = pWWWInline->bboxSize.value[1] / 2.0;
	float fHalfDepth = pWWWInline->bboxSize.value[2] / 2.0;
	if(fHalfWidth <= 0.0) fHalfWidth = fMinInlineBox;
	if(fHalfHeight <= 0.0) fHalfHeight = fMinInlineBox;
	if(fHalfDepth <= 0.0) fHalfDepth = fMinInlineBox;
	upper.x() = fHalfWidth;
	upper.y() = fHalfHeight;
	upper.z() = fHalfDepth;
	lower.x() = -fHalfWidth;
	lower.y() = -fHalfHeight;
	lower.z() = -fHalfDepth;
	center.x() = pWWWInline->bboxCenter.value[0];
	center.y() = pWWWInline->bboxCenter.value[1];
	center.z() = pWWWInline->bboxCenter.value[2];

	m_pBounds->SetBounds(lower, upper);
	m_pBounds->SetCenter(center);
	m_pBounds->SetTransform(GetTransform());
	m_boolBoundsDirty = false;   

	return 1;
};

int ChQvCylinderInstance::ComputeBounds()
{
	if(!m_pBounds) m_pBounds = new ChQvBounds;
	GxVec3f lower, upper, center(0.,0.,0);
  	QvCylinder * pCylinder = (QvCylinder *)GetNode();

	lower.x() = -pCylinder->radius.value;   
	lower.y() = -pCylinder->height.value / 2.;  
	lower.z() = -pCylinder->radius.value;   
	upper.x() =  pCylinder->radius.value;   
	upper.y() =  pCylinder->height.value / 2.;  
	upper.z() =  pCylinder->radius.value;
	
	m_pBounds->SetBounds(lower, upper);
 	m_pBounds->SetCenter(center);
	m_pBounds->SetTransform(GetTransform());
	m_boolBoundsDirty = false;   
	   
	return 1;
};

int ChQvAsciiTextInstance::ComputeBounds()
{
	if(!m_pBounds) m_pBounds = new ChQvBounds;
	QvAsciiText *pNode = (QvAsciiText *)m_pNode;
	if(!m_pBounds) m_pBounds = new ChQvBounds;

	GxVec3f lower, upper, center(0.,0.,0);

	HFONT hFont = CreateFont(100);
	float maxWidth = 0.0;
	for(int line = 0; line < pNode->string.num; line++)
	{
		float width = GetTextWidth(hFont, line);
		maxWidth = max(width, maxWidth);
	}
	switch(pNode->justification.value)
	{
		case QvAsciiText::LEFT:
			 lower.x() = 0.;	
			break;
		case QvAsciiText::RIGHT:
			lower.x() = -maxWidth;
			break;
		case QvAsciiText::CENTER:
			lower.x() = -maxWidth / 2;
			break;
	}
	upper.x() = lower.x() + maxWidth;
	upper.y() = -GetBaselineOffset() - line * pNode->spacing.value * GetFontStyle()->size.value;
	lower.y() = upper.y() - GetTextHeight();
	upper.z() = 0.0;
	lower.z() = -.01;	// give it a bit of depth, for safety

	center = lower;
	center += upper;
	center *= .5;

	DeleteObject(hFont);
	
	m_pBounds->SetBounds(lower, upper);
	m_pBounds->SetCenter(center);
	m_pBounds->SetTransform(GetTransform());
	m_boolBoundsDirty = false;   

	return 1;
};

int ChQvPointSetInstance::ComputeBounds()
{
	if(!m_pBounds) m_pBounds = new ChQvBounds;
	QvPointSet *pNode = (QvPointSet *)GetNode();
	QvCoordinate3 *pC3 = GetCoordinate3();
	GxVec3f lower, upper, center(0.,0.,0);

	lower.set(BIGGIE, BIGGIE, BIGGIE);
	upper.set(-BIGGIE, -BIGGIE, -BIGGIE);
	center.set(0., 0., 0.);
	int count = 0;

	int numPoints = pNode->numPoints.value;
	if(numPoints < 0)
	{
		numPoints = pC3->point.num - pNode->startIndex.value;
	}
	for(int j = pNode->startIndex.value; j < numPoints + pNode->startIndex.value; j++)	  
	{

		int index = j * 3;
		lower.x() = min(lower.x(), pC3->point.values[index]);
		lower.y() = min(lower.y(), pC3->point.values[index+1]); 
		lower.z() = min(lower.z(), pC3->point.values[index+2]); 

		upper.x() = max(upper.x(), pC3->point.values[index]);
		upper.y() = max(upper.y(), pC3->point.values[index+1]); 
		upper.z() = max(upper.z(), pC3->point.values[index+2]);
		
		center.x() += pC3->point.values[index]; 
		center.y() += pC3->point.values[index+1];
		center.z() += pC3->point.values[index+2];
		
		count++;
	}
 

	if(count>0)
	{
		center.x() /= count;
		center.y() /= count;
		center.z() /= count;
	}

	m_pBounds->SetBounds(lower, upper);
 	m_pBounds->SetCenter(center);
	m_pBounds->SetTransform(GetTransform());
	   
	m_boolBoundsDirty = false;   
	return 1;
};

void ChBoundsIterator::Push()
{	
	ChBoundsStack *pStack = new ChBoundsStack(m_upper, m_lower, m_center, m_childBoundsCount, m_inverseTransform);
	m_stack.AddHead(pStack);
}

bool ChBoundsIterator::Pop()
{
	if(m_stack.IsEmpty()) return false;
	ChBoundsStack *pStack = m_stack.RemoveHead();
	
	m_upper = pStack->m_upper;
	m_lower = pStack->m_lower;
	m_center = pStack->m_center;
	m_inverseTransform = pStack->m_inverseTransform;
	m_childBoundsCount = pStack->m_childBoundsCount;
	delete pStack;
	return true; 
}
 
ChBoundsIterator* ChBoundsIterator::LocalReset()
{
	m_upper.set(0.,0.,0.);
	m_lower.set(0.,0.,0.);
	m_center.set(0.,0.,0.);
	m_childBoundsCount = 0;
	m_inverseTransform.Identity();
	return this; 
}

bool ChBoundsIterator::DoNode(ChQvInstance& inst)
{
	switch(GetVisitType())
	{
		case beforeChildren:
		{
			Push();
			LocalReset();
			// set the inverse transform
			m_inverseTransform = inst.GetTransform().Inverse();
			#if 0
			if(!inst.IsBoundsDirty()) 	SetDoKids(false); 
			#endif

			break;
		}
		case afterChildren:
		{
		 	if(m_childBoundsCount)
			{
				m_center.x() /= m_childBoundsCount;
				m_center.y() /= m_childBoundsCount;
				m_center.z() /= m_childBoundsCount;
			}
			m_pBounds->SetBounds(m_lower, m_upper);
		 	m_pBounds->SetCenter(m_center);
			m_pBounds->SetTransform(inst.GetTransform());
			Pop();					
			Accumulate();
			// Get the bounds of group nodes, which are never
			// called with VisitType "isLeaf".
			if(inst.GetBounds(*GetBounds()))
			{
				Accumulate();
			}
			break;
		}
		case isLeaf:
		{
			if(inst.GetBounds(*GetBounds()))
			{
				Accumulate();
			}

			break;
		}
	}
	return true;

}

void ChBoundsIterator::Accumulate()
{
	if(!m_pBounds->IsEmpty())
	{
		m_childBoundsCount++;
		GxTransform3Wf	childMat;
		GxVec3f childLower, childUpper;
		m_pBounds->GetBounds(childLower, childUpper, childMat);
		
		#if defined(CH_USE_3DR)			 
		childMat = m_inverseTransform * childMat;	// Get the child into the current object coord system
		#else
		childMat = childMat * m_inverseTransform;	// Get the child into the current object coord system
		#endif
		//childMat = childMat.Compose(m_inverseTransform);	// Get the child into the current object coord system
		m_pBounds->GetTransformedBounds(childLower, childUpper, childMat);
		if(m_childBoundsCount > 1)
		{
			m_lower.x() = min(m_lower.x(), childLower.x());
			m_lower.y() = min(m_lower.y(), childLower.y()); 
			m_lower.z() = min(m_lower.z(), childLower.z()); 
			m_upper.x() = max(m_upper.x(), childUpper.x());
			m_upper.y() = max(m_upper.y(), childUpper.y()); 
			m_upper.z() = max(m_upper.z(), childUpper.z());
		}
		else
		{
			m_lower = childLower;
			m_upper = childUpper;
		}
		GxVec3f childCenter;
		m_pBounds->GetCenter(childCenter);
		childCenter = childMat * childCenter;
		m_center += childCenter;	
	}
}

// end of file
