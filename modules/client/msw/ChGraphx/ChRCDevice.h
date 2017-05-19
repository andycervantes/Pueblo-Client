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

	Implementation of native device creation to support ChRenderContext class.
	Used by D3D implementation; eventually want to use for RL too

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChRCDevice.h,v 2.3 1996/07/19 20:44:46 jimd Exp $

#if !defined( _CHRCDEVICE_H )
#define _CHRCDEVICE_H
#if (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
#include "ChRender.h"

// Com Interface exception class
class ChExInterface
{
	public:
		ChExInterface(const int i) : val(i) {};
 		virtual ~ChExInterface()  {};

		int val;
	protected:
		ChExInterface()  {};
};

const int CH_EX_QUERY_FAILED = 1;
const int CH_EX_CREATE_FAILED = 2;
 

#if (defined(CH_USE_D3D))

class ChDevice3D 
{
	friend class ChRenderContext;
	
	protected:

	ChNativeContext m_device;
	ChRenderContext *m_pRC;

	#if (defined(CH_USE_D3D))
	LPDIRECTDRAWSURFACE	m_frontSurface;
	LPDIRECTDRAWSURFACE	m_backSurface;
	LPDIRECTDRAWSURFACE	m_zSurface;
	LPDIRECTDRAWCLIPPER m_clipper;	/* DirectDrawClipper object  */
	
	#elif (defined(CH_USE_RLAB))
	#endif

	public:

		ChDevice3D();
		ChDevice3D(ChRenderContext *pRC, int width, int height, bool boolOffscreen = true);
		virtual ~ChDevice3D();

		ChNativeContext GetDevice() {return m_device;};

	protected:
		bool Init(ChRenderContext *pRC, int width, int height, bool boolOffscreen = true);
		void Kill();


   private:
											/* Disable copy constructor and
												assignment operator - can implement AddRef/Release
												COM usage counts later if we want*/

      inline ChDevice3D( const ChDevice3D& )  {}
      inline ChDevice3D& operator=( const ChDevice3D& )
      			{
      				return *this;
      			}


};


#endif // D3D
#endif // (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
#endif	  // _CHRCDEVICE_H
