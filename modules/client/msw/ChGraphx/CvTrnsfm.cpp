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

	Implementation for the computation of transforms of a VRML QV tree
	(currently assumes Intel 3DR.)

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvTrnsfm.cpp,v 2.17 1996/06/27 03:44:18 jimd Exp $

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
#include "CvTrnsfm.h"
#include "CvConvrt.h"

void GetTransform(QvMatrixTransform *pNode, GxTransformF_t& mat)
{
	Qv2Native(pNode->matrix, mat);
}

void GetTransform(QvRotation *pNode, GxTransformF_t& mat)
{
	RotationMatrix(pNode->rotation.axis[0], 
					pNode->rotation.axis[1],
					pNode->rotation.axis[2],
					pNode->rotation.angle,
					mat);
}

void GetTransform(QvScale *pNode, GxTransformF_t& mat)
{
	ScalingMatrix(pNode->scaleFactor.value[0],
				  pNode->scaleFactor.value[1],
				  pNode->scaleFactor.value[2],
				  mat);
}
    
void GetTransform(QvTransform *pNode, GxTransformF_t& mat)
{
										/* The VRML 1.0 spec (5/26/95) states:
										
										"The transform node 

										Transform {
										    translation T1
										    rotation R1
										    scaleFactor S
										    scaleOrientation R2
										    center T2
										  }

										is equivalent to the sequence 

										Translation { translation T1 }
										Translation { translation T2 }
										Rotation { rotation R1 }
										Rotation { rotation R2 }
										Scale { scaleFactor S }
										Rotation { rotation -R2 }
										Translation { translation -T2 }"
										
										*/
	// We accumulate the matrix in mat by multiplying by each step. Note the
	// use of mat and tmpMat alternates in each step.
	GxTransformF_t stepMat, tmpMat;

		// T1	=> mat
	TranslationMatrix (pNode->translation.value[0], pNode->translation.value[1], pNode->translation.value[2], mat );

		// T2	=> tmpMat
	TranslationMatrix (pNode->center.value[0], pNode->center.value[1], pNode->center.value[2], stepMat );
	ComposeMatrix(mat, stepMat, tmpMat);
	
		// R1	=> mat	
	RotationMatrix(pNode->rotation.axis[0], 
			pNode->rotation.axis[1],
			pNode->rotation.axis[2],
			pNode->rotation.angle,
			stepMat);
	ComposeMatrix(tmpMat, stepMat, mat);

		// R2	=> tmpMat
	RotationMatrix(pNode->scaleOrientation.axis[0], 
			pNode->scaleOrientation.axis[1],
			pNode->scaleOrientation.axis[2],
			pNode->scaleOrientation.angle,
			stepMat);
	ComposeMatrix(mat, stepMat, tmpMat);

		// S	=> mat
	ScalingMatrix (pNode->scaleFactor.value[0], pNode->scaleFactor.value[1], pNode->scaleFactor.value[2], stepMat );
	ComposeMatrix(tmpMat, stepMat, mat);

		// -R2	=> tmpMat
	RotationMatrix(pNode->scaleOrientation.axis[0], 
			pNode->scaleOrientation.axis[1],
			pNode->scaleOrientation.axis[2],
			-pNode->scaleOrientation.angle,
			stepMat);
	ComposeMatrix(mat, stepMat, tmpMat);

		// -T2	=> mat
	TranslationMatrix (-pNode->center.value[0], -pNode->center.value[1], -pNode->center.value[2], stepMat );
	ComposeMatrix(tmpMat, stepMat, mat);
}

void GetTransform(QvTranslation *pNode, GxTransformF_t& mat)
{
	TranslationMatrix(pNode->translation.value[0],
					  pNode->translation.value[1],
					  pNode->translation.value[2],	
					  mat);
}

bool GetTransform(QvElement *elt, GxTransformF_t& eltMat)
{
	bool	boolHasMatrix;
	switch(elt->type)
	{
		case QvElement::MatrixTransform:
		{	
			GetTransform((QvMatrixTransform *)(elt->data), eltMat);
			boolHasMatrix = true;
			break;
		}
		case QvElement::Rotation:
		{
			GetTransform((QvRotation *)(elt->data), eltMat);
			boolHasMatrix = true;
			break;
		}
		case QvElement::Scale:
		{
			GetTransform((QvScale *)(elt->data), eltMat);
			boolHasMatrix = true;
			break;
		}
		case QvElement::Transform:
		{
			GetTransform((QvTransform *)(elt->data), eltMat);
			boolHasMatrix = true;
			break;
		}
		case QvElement::Translation:
		{
			GetTransform((QvTranslation *)(elt->data), eltMat);
			boolHasMatrix = true;
			break;
		}
		default:
		{
			boolHasMatrix = false;
			break;
		}
	}
	return boolHasMatrix;
}

void normalize(float &x, float &y, float &z)
{
	float sum = x * x + y * y + z * z;
	sum = sqrt(sum);
	x /= sum;	y /= sum;	z /= sum;
}

void RotateMatrix( float angle, float x, float y, float z, GxTransformF_t mat)
{
#if defined(CH_USE_3DR)
	float aBit = .001;
	float eps = aBit;

	if (fabs(x) < eps && fabs(z) < eps  )
	{
		float sum, sum2;
		x += aBit;
		sum2 = x * x + y * y + z * z;
		sum = sqrt(sum2);
		x /= sum;	y /= sum;	z /= sum;
	}
		
	G3dRotateMatrix( angle, x, y, z, mat);
#else
	float c = cos(angle);
	float s = sin(angle);
	float t = 1.0 - c;

	//normalize(x, y, z);	assume normalized
    
    mat[0][0] = 	t * x * x + c;
	mat[1][0] = 	t * x * y - s * z;
	mat[2][0] = 	t * x * z + s * y;
	mat[3][0] = 	0.0;

	mat[0][1] = 	t * x * y + s * z;
	mat[1][1] = 	t * y * y + c;
	mat[2][1] = 	t * y * z - s * x;
	mat[3][1] = 	0.0;

	mat[0][2] = 	t * x * z - s * y;
	mat[1][2] = 	t * y * z + s * x;
	mat[2][2] = 	t * z * z + c;
	mat[3][2] = 	0.0;

	mat[0][3] = 	0.0; 
	mat[1][3] = 	0.0; 
	mat[2][3] = 	0.0; 
	mat[3][3] = 	1.0;

#endif
}



void TranslationMatrix(float fX, float fY, float fZ, GxTransformF_t& mat)
{
	GxTransform3Wf::IdentityMatrix(mat);
#if defined(CH_USE_3DR)
	mat[0][3] = fX;
	mat[1][3] =	fY;
	mat[2][3] = fZ;
#else
	mat[3][0] = fX;		   
	mat[3][1] =	fY;		   
	mat[3][2] = fZ;		   
#endif
}

void ScalingMatrix(float fX, float fY, float fZ, GxTransformF_t& mat)
{
	GxTransform3Wf::IdentityMatrix(mat);
	mat[0][0] = fX;
	mat[1][1] = fY;
	mat[2][2] = fZ;
}

void RotationMatrix(float fAxisX, float fAxisY, float fAxisZ, float fAngle, GxTransformF_t& mat)
{
	// This takes into account the difference between vrml and 3dr's sense of rotation
	GxVec3f axis;

	axis.set( fAxisX, fAxisY, fAxisZ);
	if (axis.dot(axis) < 1e-12)
	{
		axis.set( 0, 0, 1);
	}
	axis.normalize();
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	fAngle = -fAngle;
	#endif
						   // for other renderers??? TODO
	RotateMatrix(-fAngle, 	
					axis.x(),
					axis.y(),
					axis.z(),
					mat);
}

#if defined(CH_USE_3DR)
void TransformPoint( const PointFW_t &src, PointF_t &dst, GxTransformF_t& mat )
{
	PointFW_t tmp;
	PointF_t tmps;
	CopyPoint(src, tmps);
	G3dTransformPointF( &tmps, &tmp, mat );
	CopyPoint(tmp, dst);
}
void TransformPoint( const PointFW_t &src, PointFW_t &dst, GxTransformF_t& mat )
{
	PointF_t tmps;
	CopyPoint(src, tmps);
	G3dTransformPointF( &tmps, &dst, mat );
}
void TransformPoint( const PointF_t &src, PointF_t &dst, GxTransformF_t& mat )
{
	PointFW_t tmp;
	G3dTransformPointF( (PointF_t*)&src, &tmp, mat );
	CopyPoint(tmp, dst);
}
void TransformPoint( const PointF_t &src, PointFW_t &dst, GxTransformF_t& mat )
{
	G3dTransformPointF( (PointF_t*)&src, &dst, mat );
}
#endif // defined(CH_USE_3DR)


void AccumQVTransform( QvState * qvState, GxTransformF_t& mat)
{

	QvElement *	top = qvState->getTopElement(QvState::TransformationIndex); 
	QvElement *	elt;
	GxTransformF_t eltMat, tmpMat;
	bool	boolHasMatrix;

	GxTransform3Wf::IdentityMatrix(mat);

	for( elt = top; elt; elt = elt->next )
	{
		boolHasMatrix = GetTransform(elt, eltMat);
		if(boolHasMatrix)
		{
			ComposeMatrix(eltMat, mat, tmpMat);		 // premult because of inside out order
			#if ( _MSC_VER == 900	 )	 
			GxTransform3Wf::CopyMatrix( tmpMat, mat);				 // walking down stack
			#else
			GxTransform3Wf::CopyMatrix((const float(*)[4])tmpMat, mat);				 // walking down stack
			#endif
		}
	}

}



#if 0
// Obsolete ??
void ComputeCameraOrientation( float pan, float tilt, float &axisX, float &axisY, float &axisZ, float &angle );
void ComputePanAndTilt( float &pan, float &tilt, float axisX, float axisY, float axisZ, float angle );

// Based on pan and tilt, compute the transform for vrml
void ComputeCameraOrientation( float pan, float tilt, float &axisX, float &axisY, float &axisZ, float &angle )
{
	PointF_t	dir, axis;
	PointF_t 	dirZ = {0.0f, 0.0f, -1.0f};
	PointFW_t 	tmp;
 	GxTransformF_t mat;

	RotationMatrix(1, 0, 0, tilt, mat);
	G3dTransformPointF( &dirZ, &tmp, mat );
	CopyPoint(tmp, dir);
	RotationMatrix(0, 1, 0, pan, mat);
	G3dTransformPointF( &dir, &tmp, mat );
	CopyPoint(tmp, dir);

 	G3dCross(&dirZ, &dir, &axis);

	if (G3dDot(&axis, &axis) < 1e-12)
	{
		axis.x = 0; axis.y = 1; axis.z = 0;
	}
	G3dUnitVector(&axis);

	float cosa = G3dDot(&dirZ, &dir);	// both were unit vectors before
	angle = acos(cosa);
	axisX = axis.x;
	axisY = axis.y;
	axisZ = axis.z;
}
#if !defined(PI)
#define PI 3.1415927
#endif
// Based on transform for vrml, compute the pan and tilt
void ComputePanAndTilt( float &pan, float &tilt, float axisX, float axisY, float axisZ, float angle )
{
	PointF_t	dir;
	PointF_t 	dirZ = {0.0f, 0.0f, -1.0f};
	PointF_t 	dirY = {0.0f, 1.0f, 0.0f};
	PointFW_t 	tmp;
 	GxTransformF_t mat;

	RotationMatrix(axisX, 
				axisY,
				axisZ,
				angle,
				mat);
	G3dTransformPointF( &dirZ, &tmp, mat );
	CopyPoint(tmp, dir);

	tilt = asin(dir.y);

	if (fabs(tilt) < 1e-2) tilt = 0;	// make up for round off creep
	if( fabs(1. - fabs(dir.y)) > 1e-4)
	{
		pan = atan2( dir.x, dir.z ) + PI;
		if(pan > PI) pan -= PI + PI;
	}
	else
	{
		pan = atan2( -axisZ, axisX ) + PI;
		if(pan > PI) pan -= PI + PI;
	}
}
#endif
// end of file
