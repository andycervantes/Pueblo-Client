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

----------------------------------------------------------------------------*/

#ifndef _GX_TYPES_H_
#define _GX_TYPES_H_

#ifdef HUGE
#undef HUGE
#endif

#include <math.h>
#include <iostream.h>

#if !defined(M_PI)
#define M_PI 3.1415926536
#define M_PI_4 (M_PI/4.0)
#endif

#ifdef CH_MSW // WIN32
#pragma warning(disable: 4244) // just until srinivas fixes the messages
#endif

class GxVec3f
{
	public:
		GxVec3f( float x = 0, float y = 0, float z = 0 )
		{
			m_pV[0] = x, m_pV[1] = y, m_pV[2] = z ;
		}

		GxVec3f( float v[3] )
		{
			m_pV[0] = v[0], m_pV[1] = v[1], m_pV[2] = v[2] ;
		}

		GxVec3f( const GxVec3f& v )
		{
			m_pV[0] = v.m_pV[0], m_pV[1] = v.m_pV[1], m_pV[2] = v.m_pV[2] ;
		}

		inline GxVec3f& operator=( const GxVec3f& v )
		{
			m_pV[0] = v.m_pV[0], m_pV[1] = v.m_pV[1], m_pV[2] = v.m_pV[2] ;
			return *this ;
		}

		void set( float x, float y, float z )
		{
			m_pV[0] = x, m_pV[1] = y, m_pV[2] = z ;
		}

		inline GxVec3f& operator+=( const GxVec3f& v )
		{
			m_pV[0] += v.m_pV[0], m_pV[1] += v.m_pV[1], m_pV[2] += v.m_pV[2] ;
			return *this ;
		}

		inline GxVec3f& operator-=( const GxVec3f& v )
		{
			m_pV[0] -= v.m_pV[0], m_pV[1] -= v.m_pV[1], m_pV[2] -= v.m_pV[2] ;
			return *this ;
		}

		inline GxVec3f operator-( )
		{
			return( GxVec3f(-m_pV[0], -m_pV[1], -m_pV[2])) ;
		}

		inline GxVec3f& operator*=( const float& s )
		{
			m_pV[0] *= s, m_pV[1] *= s, m_pV[2]*= s;
			return *this ;
		}

		inline float x() const { return m_pV[0] ; }
		inline float y() const { return m_pV[1] ; }
		inline float z() const { return m_pV[2] ; }
		inline float operator[]( int i ) const { return m_pV[i%3] ; }

		inline float& x() { return m_pV[0] ; }
		inline float& y() { return m_pV[1] ; }
		inline float& z() { return m_pV[2] ; }
		inline float& operator[]( int i ) { return m_pV[i%3] ; }

		float magnitude() const
		{
		 return sqrt ( m_pV[0]*m_pV[0] + m_pV[1]*m_pV[1] + m_pV[2]*m_pV[2] ) ;
		}

		inline float dot( const GxVec3f& v ) const
		{
		 return m_pV[0]*v.m_pV[0] + m_pV[1]*v.m_pV[1] + m_pV[2]*v.m_pV[2] ;
		}

		GxVec3f cross( const GxVec3f& v ) const
		{
			GxVec3f vv ;
			vv.m_pV[0] = m_pV[1]*v.m_pV[2] - v.m_pV[1]*m_pV[2] ;
			vv.m_pV[1] = v.m_pV[0]*m_pV[2] - m_pV[0]*v.m_pV[2] ;
			vv.m_pV[2] = m_pV[0]*v.m_pV[1] - v.m_pV[0]*m_pV[1] ;
			return vv ;
		}

		void normalize()
		{
			float mag = magnitude() ;
			if ( mag > 0 ) m_pV[0] /= mag ; m_pV[1] /= mag ; m_pV[2] /= mag ;
		}

		inline void minimum( const GxVec3f& v )
		{
			// Set this to be minimum of this and v
			if(m_pV[0] > v.m_pV[0]) m_pV[0] = v.m_pV[0];
			if(m_pV[1] > v.m_pV[1]) m_pV[1] = v.m_pV[1];
			if(m_pV[2] > v.m_pV[2]) m_pV[2] = v.m_pV[2];
		}

		inline void maximum( const GxVec3f& v )
		{
			// Set this to be maximum of this and v
			if(m_pV[0] < v.m_pV[0]) m_pV[0] = v.m_pV[0];
			if(m_pV[1] < v.m_pV[1]) m_pV[1] = v.m_pV[1];
			if(m_pV[2] < v.m_pV[2]) m_pV[2] = v.m_pV[2];
		}


   private:
      float m_pV[3] ;
} ;

inline ostream& operator<<( ostream& os, const GxVec3f& v )
{
   os << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")" ;
   return os ;
}

class GxVec2f
{
   public:
      GxVec2f( float x = 0, float y = 0 )
      {
		 m_pV[0] = x, m_pV[1] = y ;
      }

      GxVec2f( float v[2] )
      {
		 m_pV[0] = v[0], m_pV[1] = v[1] ;
      }

      GxVec2f( const GxVec2f& v )
      {
		 m_pV[0] = v.m_pV[0], m_pV[1] = v.m_pV[1] ;
      }

      GxVec2f& operator=( const GxVec2f& v )
      {
		 m_pV[0] = v.m_pV[0], m_pV[1] = v.m_pV[1] ;
		 return *this ;
      }

      void set( float x, float y )
      {
		 m_pV[0] = x, m_pV[1] = y ;
      }

      float x() const { return m_pV[0] ; }
      float y() const { return m_pV[1] ; }
      float u() const { return m_pV[0] ; }
      float v() const { return m_pV[1] ; }
      float operator[]( int i ) const { return m_pV[i%2] ; }

      float& x() { return m_pV[0] ; }
      float& y() { return m_pV[1] ; }
      float& u() { return m_pV[0] ; }
      float& v() { return m_pV[1] ; }
      float& operator[]( int i ) { return m_pV[i%2] ; }

      float magnitude() const
      {
		 return sqrt ( m_pV[0]*m_pV[0] + m_pV[1]*m_pV[1] ) ;
      }

      void normalize()
      {
		 float mag = magnitude() ;
		 if ( mag > 0 ) m_pV[0] /= mag ; m_pV[1] /= mag ;
      }

   private:
      float m_pV[2] ;
} ;

inline ostream& operator<<( ostream& os, const GxVec2f& v )
{
   os << "(" << v[0] << ", " << v[1] << ")" ;
   return os ;
}

#endif // _GX_TYPES_H_
