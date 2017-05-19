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

// $Header: /home/cvs/chaco/modules/client/portable/ChGraphx/GxTrnsfm.h,v 1.6 1996/09/14 22:28:45 pritham Exp $

#ifndef _GX_TRNSFM_H_
#define _GX_TRNSFM_H_

#if ( _MSC_VER > 900	 )
#pragma warning( disable: 4237 )
#endif

#include <ChTypes.h>

#ifdef HUGE
#undef HUGE
#endif

#include <math.h>
#include <iostream.h>
#include "GxTypes.h"
								  // reality labs -Kate Seekings- marketer in London    
								  //				 Servan Keondjin @ microsoft - programmer on RLab          

#if !defined(M_PI)				  
#define M_PI 3.1415926536		
#define M_PI_4 (M_PI/4.0)
#endif

#ifdef CH_MSW // WIN32
#endif

typedef float GxTransformF_t[4][4];

#if ( _MSC_VER != 900	 )
typedef const float constGxTransformF_t[4][4];
#endif

class GxTransform3Wf
{
	public:
		GxTransform3Wf( /* Identity */ );

		GxTransform3Wf( GxVec3f& v, float angle /* Rotation */ );

		GxTransform3Wf( const GxTransform3Wf& t );

		GxTransform3Wf( /*const*/ GxTransformF_t& m );

		GxTransform3Wf& operator=( const GxTransform3Wf& t );
		GxTransform3Wf& operator=( const GxTransformF_t& m );

		GxTransform3Wf * Scale(  GxVec3f& v );
		GxTransform3Wf * Translate(  GxVec3f& v );
		GxTransform3Wf * Rotate(  GxVec3f& v, float angle );
		GxTransform3Wf * Invert();
		GxTransform3Wf * Identity();
		GxTransform3Wf * LookAt( GxVec3f& dir, bool boolUseZ = false );
		GxTransform3Wf * LookAt( GxVec3f& dir, GxVec3f& up, bool boolUseZ = false);
		GxTransform3Wf * LookAt( GxVec3f& loc, GxVec3f& dir, GxVec3f up, bool boolUseZ = false);

		GxTransform3Wf& operator*=( const GxTransform3Wf& v );
		GxVec3f operator*( const GxVec3f& v ) const;
		GxVec3f TransformW( const GxVec3f& v, float& w ) const;
		GxVec3f &TransformW( const GxVec3f& v,  GxVec3f& result, float& w ) const;
		GxTransform3Wf operator*(  const GxTransform3Wf& m  ) const;
		GxTransform3Wf Compose(  const GxTransform3Wf& m  ) const;

		GxTransform3Wf Inverse() const;

		inline GxTransformF_t* GetMatrix() { return (&m_mat) ; };

		static void IdentityMatrix(GxTransformF_t &mat);
		static void MultMatrix(const GxTransformF_t a, const GxTransformF_t b, GxTransformF_t result);
		#if ( _MSC_VER == 900	 )
		static void CopyMatrix(const GxTransformF_t src, GxTransformF_t dst);
		#else
		static void CopyMatrix(constGxTransformF_t src, GxTransformF_t dst);
		#endif

   protected:
   		GxTransformF_t	m_mat;
   		GxTransformF_t	m_invMat;
		bool			m_boolDirty;

} ;

#if 0
inline ostream& operator<<( ostream& os, const GxTransform3Wf& v )
{
   os << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")" ;
   return os ;
}
#endif

// Helpers

bool
affine_matrix4_inverse (GxTransformF_t &in, GxTransformF_t &out);

#endif // _GX_TRNSFM_H_
