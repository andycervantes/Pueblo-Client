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

	Declaration for the ChMazeWnd class, which is used to display
	3d graphics.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/portable/ChGraphx/GxQuaternion.h,v 1.3 1996/07/03 19:51:02 jimd Exp $

#if !defined( _GXQUATERNION_H )
#define _GXQUATERNION_H

#if defined( CH_MSW )
	#pragma warning( disable:4091 )
#endif	// defined( CH_MSW )

#include "GxTypes.h"

class GxQuaternion
{
	public:
		GxQuaternion( float x = 0, float y = 1, float z = 0, float angle = 0. )
		{
			set(x, y, z, angle);
		};

		GxQuaternion( GxVec3f& v, float angle )
		{
			set(v, angle);
		};

		GxQuaternion( GxVec3f& dir, GxVec3f& up )
		{
			set(dir, up);
		}

		GxQuaternion( const GxQuaternion& q )
		{
			m_v = q.m_v;
			m_real = q.m_real; 
		}

		inline GxQuaternion& operator=( const GxQuaternion& q )
		{
			m_v = q.m_v;
			m_real = q.m_real; 
			return *this ;
		}

		void set( float x, float y, float z, float angle );
		void set( const GxVec3f& v, float angle );
		void set( GxVec3f dir, GxVec3f up );

		GxQuaternion& operator*=( const GxQuaternion& q );

		// Negation is inversion 
		inline GxQuaternion operator-( )
		{
			GxQuaternion res(*this);
			res.m_v = -m_v;
			return res;
		}

		inline GxQuaternion& operator*=( const float& s )
		{
			m_real *= s;
			m_v *= s;
			return *this ;
		}

		GxVec3f axis() const;
		float angle() const;

		void AxisAngle(GxVec3f &axis, float &angle) const;

		GxQuaternion operator*(GxQuaternion q) const;

		GxQuaternion slerp(const GxQuaternion &q, float u);
		float GxQuaternion::dot(const GxQuaternion &q);
		void normalize();

   private:
      GxVec3f m_v;
	  float m_real;
} ;





#endif // _GXQUATERNION_H
