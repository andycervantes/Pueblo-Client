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

	Chaco/Qv bounding box classes and routines.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvTrnsfm.h,v 2.9 1995/10/23 17:59:24 jimd Exp $

#if !defined( _CVTRNSFM_H )
#define _CVTRNSFM_H

#include <math.h>
#include "GxTypes.h"

#if defined(_QV_NODE_)
void GetTransform(QvMatrixTransform *pNode, GxTransformF_t& mat);
void GetTransform(QvRotation *pNode, GxTransformF_t& mat);
void GetTransform(QvScale *pNode, GxTransformF_t& mat);
void GetTransform(QvTransform *pNode, GxTransformF_t& mat);
void GetTransform(QvTranslation *pNode, GxTransformF_t& mat);
bool GetTransform(QvElement *elt, GxTransformF_t& eltMat);
void AccumQVTransform( QvState * qvState, GxTransformF_t& mat);
#endif // _QV_NODE_



// 3dr 2.08 has bugs in these (or at least in transform one - didn't test matrix version
void RotateMatrix( float angle, float x, float y, float z, GxTransformF_t mat);


void TranslationMatrix(float fX, float fY, float fZ, GxTransformF_t& mat);
void ScalingMatrix(float fX, float fY, float fZ, GxTransformF_t& mat);
void RotationMatrix(float fAxisX, float fAxisY, float fAxisZ, float fAngle, GxTransformF_t& mat);

#if defined(CH_USE_3DR)
void TransformPoint( const PointFW_t &src, PointF_t &dst, GxTransformF_t& mat );
void TransformPoint( const PointFW_t &src, PointFW_t &dst, GxTransformF_t& mat );
void TransformPoint( const PointF_t &src, PointF_t &dst, GxTransformF_t& mat );
void TransformPoint( const PointF_t &src, PointFW_t &dst, GxTransformF_t& mat );

inline void CopyPoint(const PointFW_t &src, PointF_t &dst)
{
	dst.x = src.x;
	dst.y = src.y;
	dst.z = src.z;
}

inline void CopyPoint(const PointF_t &src, PointFW_t &dst)
{
	dst.x = src.x;
	dst.y = src.y;
	dst.z = src.z;
	dst.w = 0.;
}

inline void CopyPoint(const PointFW_t &src, GxVec3f &dst)
{
	dst.set(src.x, src.y, src.z);
}

inline void CopyPoint(const GxVec3f &src, PointF_t &dst)
{
	dst.x = src.x();
	dst.y = src.y();
	dst.z = src.z();
}

inline void CopyPoint(const GxVec3f &src, PointFW_t &dst )
{
	dst.x = src.x();
	dst.y = src.y();
	dst.z = src.z();
	dst.w = 0.;
}


#endif

#endif // _CVBOUND_H

