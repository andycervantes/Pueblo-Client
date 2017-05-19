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

// $Header: /home/cvs/chaco/modules/client/portable/ChGraphx/GxTrnsfm.cpp,v 1.6 1996/09/14 22:28:45 pritham Exp $
#ifndef _GX_TRNSFM_C_
#define _GX_TRNSFM_C_

#if ( _MSC_VER > 900	 )
#pragma warning( disable: 4237 )
#endif

#include <ChTypes.h>

#include "GxTypes.h"
#include "GxTrnsfm.h"
#if defined(CH_USE_3DR)
#include "3dr.h"
#include "3dg.h"
#elif defined(CH_USE_RLAB)
// need some help??
#endif
#include "../../msw/ChGraphx/CvTrnsfm.h"

#if defined(CH_USE_3DR)
#define ComposeMatrix(a,b,c)	 G3dMultMatrix((a), (b), (c))
#define DoMultMatrix G3dMultMatrix
#define DoInverse G3dInvertMatrix
#else
#if ( _MSC_VER == 900	 )
#define ComposeMatrix(a,b,c)	 MultMatrix((b), (a), (c))
#else
#define ComposeMatrix(a,b,c)	 MultMatrix(((const float(*)[4])b), ((const float(*)[4])a), (c))
#endif

#define DoMultMatrix MultMatrix
#define DoInverse affine_matrix4_inverse
#endif

#if defined(CH_RIGHTHAND_NOTATION)
#define GX_ROW_COL(mat, a,b)	(mat)[a][b]
#else
#define GX_ROW_COL(mat, a,b)	(mat)[b][a]
#endif

GxTransform3Wf::GxTransform3Wf( /* Identity */ ) : m_boolDirty(false)
{
	IdentityMatrix(m_mat);
	IdentityMatrix(m_invMat);
}

GxTransform3Wf::GxTransform3Wf( GxVec3f& axis, float angle /* Rotation */ ) : m_boolDirty(true)
{
	RotationMatrix( axis.x(), 
					axis.y(),
					axis.z(),
					angle,
					m_mat);
}

GxTransform3Wf::GxTransform3Wf( const GxTransform3Wf& v ) : m_boolDirty(true)
{
	memcpy(m_mat, v.m_mat, sizeof(m_mat));
	if(!v.m_boolDirty)
	{
		memcpy(m_invMat, v.m_invMat, sizeof(m_invMat));
		m_boolDirty = false;
	}
}

GxTransform3Wf::GxTransform3Wf( /*const*/ GxTransformF_t& m ) : m_boolDirty(true)
{
	memcpy(m_mat, m, sizeof(m_mat));
}

GxTransform3Wf& GxTransform3Wf::operator=( const GxTransform3Wf& v )
{
	if(this != &v)
	{
		memcpy(m_mat, v.m_mat, sizeof(m_mat));
		if(!v.m_boolDirty)
		{
			memcpy(m_invMat, v.m_invMat, sizeof(m_invMat));
			m_boolDirty = false;
		}
		else
		{
			m_boolDirty = true;
		}
	}
	return *this ;
}

GxTransform3Wf& GxTransform3Wf::operator=( const GxTransformF_t& m )
{
	memcpy(m_mat, m, sizeof(m_mat));
	m_boolDirty = true;

	return *this ;
}

GxTransform3Wf * GxTransform3Wf::Scale(  GxVec3f& v )
{
   	GxTransformF_t	mat, matTmp;
	ScalingMatrix(v.x(), v.y(), v.z(), matTmp);
	memcpy(mat, m_mat, sizeof(m_mat));
	ComposeMatrix( mat, matTmp, m_mat);
	m_boolDirty = true;
	return this;
}

GxTransform3Wf * GxTransform3Wf::Translate(  GxVec3f& v )
{
   	GxTransformF_t	mat, matTmp;
	TranslationMatrix(v.x(), v.y(), v.z(), matTmp);
	memcpy(mat, m_mat, sizeof(m_mat));
	ComposeMatrix(mat, matTmp, m_mat);
	m_boolDirty = true;
	return this;
}

GxTransform3Wf * GxTransform3Wf::Rotate(  GxVec3f& axis, float angle )
{
   	GxTransformF_t	mat, matTmp;
	RotationMatrix( axis.x(), 
					axis.y(),
					axis.z(),
					angle,
					matTmp);
	memcpy(mat, m_mat, sizeof(m_mat));
	ComposeMatrix(mat, matTmp, m_mat);
	m_boolDirty = true;
	return this;
}

GxTransform3Wf * GxTransform3Wf::Invert()
{
	if(m_boolDirty)
	{
		memcpy(m_invMat, m_mat, sizeof(m_mat));	 // save original as inverse
		DoInverse(m_invMat, m_mat);		 // invert copy to m_mat
		m_boolDirty = false;
	}
	else
	{
	   	GxTransformF_t	mat;
		memcpy(mat, m_invMat, sizeof(m_mat));
		memcpy(m_invMat, m_mat, sizeof(m_mat));	
		memcpy(m_mat, mat, sizeof(m_mat));
	}
	return this;
}

GxTransform3Wf * GxTransform3Wf::Identity()
{
	IdentityMatrix(m_mat);
	IdentityMatrix(m_invMat);
	m_boolDirty = false;
	return this;
}

GxTransform3Wf& GxTransform3Wf::operator*=( const GxTransform3Wf& m )
{
   	GxTransformF_t	mat;
	memcpy(mat, m_mat, sizeof(m_mat));
	
	#if ( _MSC_VER == 900	 )
	DoMultMatrix( mat, (float(*)[4])m.m_mat, m_mat);
	#else
	DoMultMatrix((const float(*)[4])mat, (const float(*)[4])m.m_mat, m_mat);
	#endif

	m_boolDirty = true;
	return *this ;
}


GxVec3f GxTransform3Wf::operator*( const GxVec3f& v ) const
{
	#if defined(CH_USE_3DR)
	PointF_t	v3;
	PointFW_t	resultW;
	CopyPoint(v, v3);
	G3dTransformPointF(&v3, &resultW, (float(*)[4])m_mat);
	GxVec3f result(resultW.x, resultW.y, resultW.z);
	return result;
	#else
	// v is a -row- vector ; this actually does v * this
	float w;
	GxVec3f	result;
	TransformW(v, result, w);
	if (w != 0.0)
	{
		result.x() /= w;  result.y() /= w;  result.z() /= w;
	}
	return result;
	#endif
}


GxVec3f GxTransform3Wf::TransformW( const GxVec3f& v, float& w ) const
{
	#if defined(CH_USE_3DR)
	PointF_t	v3;
	PointFW_t	resultW;
	CopyPoint(v, v3);
	G3dTransformPointF(&v3, &resultW, (float(*)[4])m_mat);
	GxVec3f result(resultW.x, resultW.y, resultW.z);
	w = resultW.w;
	return result;
	#else
	// v is a -row- vector ; this actually does v * this
	GxVec3f	result;
	result.x() = (v[0] * m_mat[0][0]) + (v[1] * m_mat[1][0]) + (v[2] * m_mat[2][0]) + m_mat[3][0];
	result.y() = (v[0] * m_mat[0][1]) + (v[1] * m_mat[1][1]) + (v[2] * m_mat[2][1]) + m_mat[3][1];
	result.z() = (v[0] * m_mat[0][2]) + (v[1] * m_mat[1][2]) + (v[2] * m_mat[2][2]) + m_mat[3][2];
	w =    (v[0] * m_mat[0][3]) + (v[1] * m_mat[1][3]) + (v[2] * m_mat[2][3]) + m_mat[3][3];
	return result;
	#endif
}

GxVec3f &GxTransform3Wf::TransformW( const GxVec3f& v,  GxVec3f& result, float& w ) const
{					   // This version can save a copy operation
	#if defined(CH_USE_3DR)
	PointF_t	v3;
	PointFW_t	resultW;
	CopyPoint(v, v3);
	G3dTransformPointF(&v3, &resultW, (float(*)[4])m_mat);
	result.set(resultW.x, resultW.y, resultW.z);
	w = resultW.w;
	return result;
	#else
	// v is a -row- vector ; this actually does v * this
	result.x() = (v[0] * m_mat[0][0]) + (v[1] * m_mat[1][0]) + (v[2] * m_mat[2][0]) + m_mat[3][0];
	result.y() = (v[0] * m_mat[0][1]) + (v[1] * m_mat[1][1]) + (v[2] * m_mat[2][1]) + m_mat[3][1];
	result.z() = (v[0] * m_mat[0][2]) + (v[1] * m_mat[1][2]) + (v[2] * m_mat[2][2]) + m_mat[3][2];
	w =    (v[0] * m_mat[0][3]) + (v[1] * m_mat[1][3]) + (v[2] * m_mat[2][3]) + m_mat[3][3];
	return result;
	#endif
}

GxTransform3Wf GxTransform3Wf::operator*(  const GxTransform3Wf& v  ) const
{
   	GxTransform3Wf	result(*this);
	result *=	v;
	return result;
}

GxTransform3Wf GxTransform3Wf::Compose(  const GxTransform3Wf& v  ) const
{
	// Compose v with this, i.e, functionally:  v(*this(x))
	#if defined(CH_RIGHTHAND_NOTATION)
   	GxTransform3Wf	result(*this);	// for RL:	res = this * v
	result *=	v;
	#else
   	GxTransform3Wf	result(v);		// for 3DR: res = v * this
	result *=	*this;
	#endif
	return result;
}

//GxVec3f operator[]( int i ) const

GxTransform3Wf GxTransform3Wf::Inverse() const
{
   	GxTransform3Wf	result(*this);	// far from optimal
	result.Invert();
	return result;
}

void GxTransform3Wf::IdentityMatrix(GxTransformF_t &mat)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++) mat[i][j] = 0.;
		mat[i][i] = 1.;
	}
		
	return;
}

void GxTransform3Wf::MultMatrix(const GxTransformF_t a, const GxTransformF_t b, GxTransformF_t result)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			result[i][j] = 0.;
			for(int k = 0; k < 4; k++)
			{
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}
		
	return;
}

void GxTransform3Wf::CopyMatrix(const GxTransformF_t src, GxTransformF_t dst)
{
	memcpy(dst, src, sizeof(dst));
		
	return;
}

GxTransform3Wf * GxTransform3Wf::LookAt( GxVec3f& dir, bool boolUseZ /*= false */)
{	
	GxVec3f loc(0,0,0), up;
	GxVec3f x(1,0,0), z(0,0,1);

	up = dir.cross(x);
	if(up.dot(up) < 1.e-12) up = dir.cross(z);

	return LookAt(loc, dir, up, boolUseZ);
}
GxTransform3Wf * GxTransform3Wf::LookAt( GxVec3f& dir, GxVec3f& up, bool boolUseZ /*= false*/)
{
	GxVec3f loc(0,0,0);

	return LookAt(loc, dir, up, boolUseZ);
}
GxTransform3Wf * GxTransform3Wf::LookAt( GxVec3f& loc, GxVec3f& target, GxVec3f up, bool boolUseZ /*= false */)
{
	GxVec3f dir = target;
	dir -= loc;
	dir.normalize();
	up.normalize();

	GxVec3f perp = dir.cross(up);
	up = perp.cross(dir);			// force orthogonality;

	#if 0 && defined(CH_USE_RLAB)
	GxVec3f n = dir.cross(up);
	#else
	GxVec3f n = up.cross(dir);
	#endif
	
    GX_ROW_COL(m_mat,0,0) = 	n.x();
	GX_ROW_COL(m_mat,1,0) = 	n.y();
	GX_ROW_COL(m_mat,2,0) = 	n.z() * (boolUseZ ? -1 : 1);
	GX_ROW_COL(m_mat,3,0) = 	-(n.dot(loc));

	GX_ROW_COL(m_mat,0,1) = 	up.x();
	GX_ROW_COL(m_mat,1,1) = 	up.y();
	GX_ROW_COL(m_mat,2,1) = 	up.z() * (boolUseZ ? -1 : 1);
	GX_ROW_COL(m_mat,3,1) = 	-(up.dot(loc));

	GX_ROW_COL(m_mat,0,2) = 	dir.x();
	GX_ROW_COL(m_mat,1,2) = 	dir.y();
	GX_ROW_COL(m_mat,2,2) = 	dir.z() * (boolUseZ ? -1 : 1);
	GX_ROW_COL(m_mat,3,2) = 	-(dir.dot(loc));

	GX_ROW_COL(m_mat,0,3) = 	0.0; 
	GX_ROW_COL(m_mat,1,3) = 	0.0; 
	GX_ROW_COL(m_mat,2,3) = 	0.0; 
	GX_ROW_COL(m_mat,3,3) = 	1.0;

	return this;
}

#endif // _GX_TRNSFM_C_
