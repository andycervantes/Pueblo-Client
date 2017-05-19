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

	Chaco/Qv conversion inlines.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvConvrt.h,v 2.11 1996/06/27 03:43:59 jimd Exp $

#if !defined( _CVCONVRT_H )
#define _CVCONVRT_H

#include <QvNodes.h>
#include <GxTrnsfm.h>
#include "ChColor.h"

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#define	 CH_RIGHTHAND_NOTATION	1
#endif

/// Uncomment the following, or define as a flag to build with 
// the assumption that the 3dr gamma is set too high (which it used to do in NT)
//#define ASSUME_GAMMA_2	1
#if defined(CH_RIGHTHAND_NOTATION)

#if ( _MSC_VER == 900	 )	 
#define ComposeMatrix(a, b, c)	GxTransform3Wf::MultMatrix( (b), (a), (c))
#else
#define ComposeMatrix(a, b, c)	GxTransform3Wf::MultMatrix( ((const float(*)[4])b), ((const float(*)[4])a), (c))
#endif

#else

#if ( _MSC_VER == 900	 )	 
#define ComposeMatrix(a, b, c)	GxTransform3Wf::MultMatrix((a), (b), (c))
#else
#define ComposeMatrix(a, b, c)	GxTransform3Wf::MultMatrix(((const float(*)[4])(a)), ((const float(*)[4])(b)), (c))
#endif

#endif
inline float
Qv2NativeColor( float& qvColor )
{
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	//return (sqrt(qvColor));
	return ((qvColor));
	#else
	#if defined(ASSUME_GAMMA_2)
	return(qvColor * qvColor);		// very approximately this undoes an assumed gamma of .5 ~ 2.0
	#else
	return (qvColor);
	#endif
	#endif
}

// First of all some handy conversion routines.
#if !defined(CH_USE_3DR)

void Qv2Native( QvSFMatrix& matrix, GxTransformF_t& mat);

inline void Qv2Native(QvSFColor& src, ChColor& dst)
{
	dst.SetR( Qv2NativeColor(src.value[0]));
	dst.SetG( Qv2NativeColor(src.value[1]));
	dst.SetB( Qv2NativeColor(src.value[2]));
	dst.SetAlpha( 1 );		 // opaque
}

inline void Qv2Native(QvMFColor& src, int index, ChColorA& dst)
{
	if(src.num)
	{
		/// Colors cycle
		index = index % src.num;
		dst.set( Qv2NativeColor(src.values[index*3+0]), 
				Qv2NativeColor(src.values[index*3+1]), 
				Qv2NativeColor(src.values[index*3+2]),
				1.0);
		#if 0
		dst.SetR( Qv2NativeColor(src.values[index*3+0]));
		dst.SetG( Qv2NativeColor(src.values[index*3+1]));
		dst.SetB( Qv2NativeColor(src.values[index*3+2]));
		#endif
	}
	else
	{
		// Careful of empty colors; assume empty one is black
		dst.SetR(0);
		dst.SetG(0);
		dst.SetB(0);
		dst.SetAlpha( 1 );	 // opaque
	}
}


#else
inline void Qv2Native(QvSFVec3f& src, PointF_t& dst)
{
	dst.x = src.value[0];
	dst.y = src.value[1];
	dst.z = src.value[2];
}

inline void Qv2Native(QvMFVec3f& src, int index, PointF_t& dst)
{
	dst.x = src.values[index*3];
	dst.y = src.values[index*3+1];
	dst.z = src.values[index*3+2];
}

inline void Qv2Native(QvSFVec3f& src, PointFW_t& dst)
{
	dst.x = src.value[0];
	dst.y = src.value[1];
	dst.z = src.value[2];
	dst.w = 0;
}

inline void Qv2Native(QvSFColor& src, ColorF_t& dst)
{
	dst.r = Qv2NativeColor(src.value[0]);
	dst.g = Qv2NativeColor(src.value[1]);
	dst.b = Qv2NativeColor(src.value[2]);
}

inline void Qv2Native(QvSFColor& src, ColorFA_t& dst)
{
	dst.r = Qv2NativeColor(src.value[0]);
	dst.g = Qv2NativeColor(src.value[1]);
	dst.b = Qv2NativeColor(src.value[2]);
	dst.a = 1;
}

inline void Qv2Native(QvMFColor& src, ColorF_t& dst)
{
	dst.r = Qv2NativeColor(src.values[0]);
	dst.g = Qv2NativeColor(src.values[1]);
	dst.b = Qv2NativeColor(src.values[2]);
}

inline void Qv2Native(QvMFColor& src, ColorFA_t& dst)
{
	dst.r = Qv2NativeColor(src.values[0]);
	dst.g = Qv2NativeColor(src.values[1]);
	dst.b = Qv2NativeColor(src.values[2]);
	dst.a = 1;
}

inline void Qv2Native(QvMFColor& src, int index, ColorF_t& dst)
{
	dst.r = Qv2NativeColor(src.values[index*3+0]);
	dst.g = Qv2NativeColor(src.values[index*3+1]);
	dst.b = Qv2NativeColor(src.values[index*3+2]);
}

inline void Qv2Native(QvMFColor& src, int index, ColorFA_t& dst)
{
	dst.r = Qv2NativeColor(src.values[index*3+0]);
	dst.g = Qv2NativeColor(src.values[index*3+1]);
	dst.b = Qv2NativeColor(src.values[index*3+2]);
	dst.a = 1;
}

void Qv2Native( QvSFMatrix& matrix, GxTransformF_t& mat);

#endif	// 3dr specific

inline void Qv2Gx(QvSFVec3f& src, GxVec3f& dst)
{
	dst.set(src.value[0], src.value[1], src.value[2]);
}

inline void Qv2Gx(QvMFVec3f& src, int index, GxVec3f& dst)
{
	dst.set( src.values[index*3], src.values[index*3+1], src.values[index*3+2]);
}

#if 1
inline void Qv2Gx(float *src, GxVec3f& dst)
{
	dst.set( src[0], src[1], src[2]);
}
#endif

#endif // _CVCONVRT_H
