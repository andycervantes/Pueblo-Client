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

	Implementation for the ChColor class for  Intel 3DR and RealityLab.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChColor.cpp,v 2.2 1996/06/27 03:43:03 jimd Exp $

#include "grheader.h"

#include "ChColor.h"

#if defined(CH_USE_3DR)

ChColorA::ChColorA()
{
	m_color.r = m_color.g = m_color.b = m_color.a = 0.f;
};
ChColorA::ChColorA(float r, float g, float b, float alpha)
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
	m_color.a = alpha;
};

ChColorA::ChColorA(ChNativeColorA color) : m_color(color) { };

ChColorA * ChColorA::set(float r, float g, float b, float alpha ) 
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
	m_color.a = alpha;
	return this;
};

ChColorValue ChColorA::r()
{
	return m_color.r;
};

ChColorValue ChColorA::g()
{
	return m_color.g;
};

ChColorValue ChColorA::b()
{
	return m_color.b;
};

ChColorValue ChColorA::alpha()
{
	return m_color.a;
};

ChColorA * ChColorA::SetR(ChColorValue r)
{
	m_color.r = r;
	return this;
};

ChColorA * ChColorA::SetG(ChColorValue g)
{
	m_color.g = g;
	return this;
};

ChColorA * ChColorA::SetB(ChColorValue b)
{
	m_color.b = b;
	return this;
};

ChColorA * ChColorA::SetAlpha(ChColorValue a)
{
	m_color.a = a;
	return this;
};

ChColor::ChColor()
{
	m_color.r = m_color.g = m_color.b = 0.f;
};
ChColor::ChColor(float r, float g, float b)
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
};

ChColor::ChColor(ChNativeColor color) : m_color(color) { };

ChColor * ChColor::set(float r, float g, float b) 
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
	return this;
};

ChColorValue ChColor::r()
{
	return m_color.r;
};

ChColorValue ChColor::g()
{
	return m_color.g;
};

ChColorValue ChColor::b()
{
	return m_color.b;
};


ChColor * ChColor::SetR(ChColorValue r)
{
	m_color.r = r;
	return this;
};

ChColor * ChColor::SetG(ChColorValue g)
{
	m_color.g = g;
	return this;
};

ChColor * ChColor::SetB(ChColorValue b)
{
	m_color.b = b;
	return this;
};



#elif (defined(CH_USE_RLAB))

#if 0
// moved to .h
ChColorA::ChColorA()
{
	m_color =  0;
};
ChColorA::ChColorA(float r, float g, float b, float alpha)
{
	m_color = RLCreateColourRGBA(r, g, b, alpha);
};

ChColorA::ChColorA(ChNativeColorA color) : m_color(color) { };

ChColorA * ChColorA::set(float r, float g, float b, float a) 
{
	m_color = RLCreateColourRGBA(r, g, b, a);
	return this;
};

ChColorValue ChColorA::r()
{
	return RLColourGetRed(m_color);
};

ChColorValue ChColorA::g()
{
	return RLColourGetGreen(m_color);
};

ChColorValue ChColorA::b()
{
	return RLColourGetBlue(m_color);
};

ChColorValue ChColorA::alpha()
{
	return RLColourGetAlpha(m_color);
};

ChColorA * ChColorA::SetR(ChColorValue red)
{
	m_color = RLCreateColourRGBA(red, g(), b(), alpha());
	return this;
};

ChColorA * ChColorA::SetG(ChColorValue green)
{
	m_color = RLCreateColourRGBA(r(), green, b(), alpha());
	return this;
};

ChColorA * ChColorA::SetB(ChColorValue blue)
{
	m_color = RLCreateColourRGBA(r(), g(), blue, alpha());
	return this;
};

ChColorA * ChColorA::SetAlpha(ChColorValue a)
{
	m_color = RLCreateColourRGBA(r(), g(), b(), a);
	return this;
};
#endif
#endif
