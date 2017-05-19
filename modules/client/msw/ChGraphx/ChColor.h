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

	Declaration for the ChColor and ChColorA classes, 
	which are used to store renderer specific colors for 3d graphics renderers for contexts
	and in QvNodes. 

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChColor.h,v 2.2 1996/06/27 03:43:03 jimd Exp $
//
#if !defined( _CHCOLOR_H_ )
#define _CHCOLOR_H_

#include "ChGrRend.h"

#include <ChGraphx.h>
#include "ChGrType.h"

#ifdef HUGE
#undef HUGE
#endif



#if defined(CH_USE_OPENGL)
// Open GL

#elif defined(CH_USE_3DR)
// Intel 3DR
typedef ColorF_t ChNativeColor;
typedef ColorFA_t ChNativeColorA;

#elif (defined(CH_USE_RLAB))
// Microsoft Reality Lab
typedef RLColour ChNativeColor;
typedef RLColour ChNativeColorA;

#elif (defined(CH_USE_D3D))
// Microsoft d3d
typedef D3DCOLOR ChNativeColor;
typedef D3DCOLOR ChNativeColorA;

#endif // 3DR

typedef float ChColorValue;

class ChColorA
{
	protected:
		ChNativeColorA	m_color;

	public:
		#if (defined(CH_USE_RLAB))
		ChColorA()
		{
			m_color =  0;
		};
		ChColorA(float r, float g, float b, float alpha = 1.)
		{
			m_color = RLCreateColourRGBA(r, g, b, alpha);
		};

		ChColorA(ChNativeColorA color) : m_color(color) { };

		inline ChColorA * set(float r, float g, float b, float a = 1.) 
		{
			m_color = RLCreateColourRGBA(r, g, b, a);
			return this;
		};

		inline ChColorValue r()
		{
			return RLColourGetRed(m_color);
		};

		inline ChColorValue g()
		{
			return RLColourGetGreen(m_color);
		};

		inline ChColorValue b()
		{
			return RLColourGetBlue(m_color);
		};

		inline ChColorValue alpha()
		{
			return RLColourGetAlpha(m_color);
		};

		inline ChColorA * SetR(ChColorValue red)
		{
			m_color = RLCreateColourRGBA(red, g(), b(), alpha());
			return this;
		};

		inline ChColorA * SetG(ChColorValue green)
		{
			m_color = RLCreateColourRGBA(r(), green, b(), alpha());
			return this;
		};

		inline ChColorA * SetB(ChColorValue blue)
		{
			m_color = RLCreateColourRGBA(r(), g(), blue, alpha());
			return this;
		};

		inline ChColorA * SetAlpha(ChColorValue a)
		{
			m_color = RLCreateColourRGBA(r(), g(), b(), a);
			return this;
		};
		inline bool IsBlack() { return ((m_color & 0xffffff) == 0);};

		#elif defined(CH_USE_D3D)


		ChColorA()
		{
			m_color =  0;
		};
		ChColorA(float r, float g, float b, float alpha = 1.)
		{
			m_color = RGBA_MAKE(IntColor(r), IntColor(g), IntColor(b), IntColor(alpha));
		};

		ChColorA(ChNativeColorA color) : m_color(color) { };
		#if 1
		inline ChColorA * set(float r, float g, float b, float a = 1.) 
		{
			m_color = RGBA_MAKE(IntColor(r), IntColor(g), IntColor(b), IntColor(a));
			return this;
		};
			 #endif
		inline ChColorValue r()
		{
			return FloatColor(RGB_GETRED(m_color));
		};

		inline ChColorValue g()
		{
			return FloatColor(RGB_GETGREEN(m_color));
		};

		inline ChColorValue b()
		{
			return FloatColor(RGB_GETBLUE(m_color));
		};

		inline ChColorValue alpha()
		{
			return FloatColor(RGBA_GETALPHA(m_color));
		};

		inline ChColorA * SetR(ChColorValue red)
		{
			m_color &=  0xff00ffff;
			m_color |= IntColor(red) << 16;
			return this;
		};

		inline ChColorA * SetG(ChColorValue green)
		{
			m_color &=  0xffff00ff;
			m_color |= IntColor(green) << 8;
			return this;
		};

		inline ChColorA * SetB(ChColorValue blue)
		{
			m_color &=  0xffffff00;
			m_color |= IntColor(blue);
			return this;
		};

		inline ChColorA * SetAlpha(ChColorValue a)
		{
			m_color &= 0x00ffffff;
			m_color |= IntColor(a) << 24;
			return this;
		};
		inline bool IsBlack() { return ((m_color & 0xffffff) == 0);};
		#else
		ChColorA();
		ChColorA(float r, float g, float b, float alpha = 1.);
		ChColorA(ChNativeColorA color);

		ChColorA * set(float r, float g, float b, float alpha = 1.);
		ChColorValue r();
		ChColorValue g();
		ChColorValue b();
		ChColorValue alpha();
		ChColorA * SetR(ChColorValue r);
		ChColorA * SetG(ChColorValue g);
		ChColorA * SetB(ChColorValue b);
		ChColorA * SetAlpha(ChColorValue a);

		inline bool IsBlack() { return (r() == 0. && g() == 0. && b() == 0.);};
		#endif

		inline ChNativeColorA *GetNative() {return &m_color;};
		inline const ChNativeColorA *GetNative() const {return &m_color;};
		inline ChColorA& operator*=( const float& s )
		{
			set(r()*s, g()*s, b()*s, alpha());		// need to clip either here or in set
			return *this ;
		}

	protected:

		static inline int IntColor(float val)
		{
			return int(val * 255);
		}

		static inline float FloatColor(int val)
		{
			return float(val) / float(255.);
		}

};


#if defined(CH_USE_3DR)
class ChColor
{
	protected:
		ChNativeColor	m_color;

	public:
		ChColor();
		ChColor(float r, float g, float b);
		ChColor(ChNativeColor color);

		ChColor * set(float r, float g, float b);
		ChColorValue r();
		ChColorValue g();
		ChColorValue b();
		ChColor * SetR(ChColorValue r);
		ChColor * SetG(ChColorValue g);
		ChColor * SetB(ChColorValue b);

		ChNativeColor *GetNative() {return &m_color;};
};
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
typedef ChColorA ChColor;
#elif defined(CH_USE_D3D)
typedef ChColorA ChColor;
#endif


#endif // _CHCOLOR_H_
