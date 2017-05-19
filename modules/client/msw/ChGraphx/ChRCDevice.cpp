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

	Implementation of native device creation for the ChRenderContext class.
	Used by RL and D3D implementations

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChRCDevice.cpp,v 2.4 1996/07/19 20:44:45 jimd Exp $

#include "grheader.h"

#include "ChMaze.h"
#include "ChRCDevice.h"

#if defined(CH_USE_D3D)

#if !defined(CH_EXCEPTIONS)
#error "This file requires enabling of C++ Exceptions!"
#endif

HRESULT
GetSurfDesc(LPDDSURFACEDESC lpDDSurfDesc,LPDIRECTDRAWSURFACE lpDDSurf)
{
    HRESULT result;
    memset(lpDDSurfDesc, 0, sizeof(DDSURFACEDESC));
    lpDDSurfDesc->dwSize = sizeof(DDSURFACEDESC);
    result = lpDDSurf->GetSurfaceDesc(lpDDSurfDesc);
    return result;
}

#endif 	 // D3D

ChNativeContext ChRenderContext::CreateDevice(int width, int height)
{
	#if (defined(CH_USE_RLAB))
	#ifdef DDRAW
	m_hRC = createWinDevice(win, hdc, NULL, width, height);
	#else
	m_hRC = RLWinCreateDevice(GetWnd()->GetSafeHwnd(), NULL, width, height);
	#endif
	#elif (defined(CH_USE_D3D))

	ChRenderOptimization setting = ((ChMazeWnd*)GetWnd())->GetSettings()->GetRenderOptimization();

	for(int j = 0; j < renderOptimizationCount; j++)
	{
		m_drivers[j] = ChD3dDriver();
	}
	if(m_drivers[renderBetter].GetName().IsEmpty())
	{
		if(!EnumDrivers()) return 0;	// FAILURE!
	}

	/*
     * Create the D3DRM device from this window and using the specified D3D
     * driver.
     */
	GUID guid = m_drivers[setting].GetGUID();	// our driver to use
	m_hRC = 0;									// in case of failure
	#if FANCY_CREATE
	// NOT DONE YET!!
	// Create the front and back buffers, along with the clipper

	// Create the Z buffer

	// Create the device on top of the buffers

	#else
    HRESULT rval = m_D3DRM->CreateDeviceFromClipper(m_DDClipper, &guid, width, height, &m_hRC);
	#endif

	#if 0
	DDSURFACEDESC desc;
	LPDIRECTDRAWSURFACE lpDDSurf = 0;
	LPDIRECT3DDEVICE d3dDevice = 0;
	rval = m_hRC->GetDirect3DDevice(&d3dDevice);
	if(rval == DD_OK)
	{

		rval = d3dDevice->QueryInterface(IID_IDirectDrawSurface, (void**)&lpDDSurf);
		if(rval == DD_OK)
		{
			GetSurfDesc(&desc,lpDDSurf);
			if((desc.ddsCaps.dwCaps & DDSCAPS_BACKBUFFER) == 0)
			{
				LPDIRECTDRAWSURFACE backSurf = 0;
				DDSCAPS ddsCaps;
				ddsCaps.dwCaps = DDSCAPS_BACKBUFFER;
				rval = lpDDSurf->GetAttachedSurface(&ddsCaps, &backSurf); 
				if(rval == DD_OK)
				{
					GetSurfDesc(&desc,backSurf);
				}
				RELEASE_INTERFACE(backSurf);
			}
		}
	}
	RELEASE_INTERFACE(lpDDSurf);
	RELEASE_INTERFACE(d3dDevice);
	#endif	// 0

	#endif // elif (defined(CH_USE_D3D))
	return m_hRC;
}

#if (defined(CH_USE_D3D))

int ChRenderContext::GetBPP()
{
    return GetDeviceCaps(m_hDC, BITSPIXEL);
}

static HRESULT
WINAPI enumDeviceFunc(LPGUID lpGuid, LPSTR lpDeviceDescription, LPSTR lpDeviceName,
        LPD3DDEVICEDESC lpHWDesc, LPD3DDEVICEDESC lpHELDesc, LPVOID lpContext)
{

	ChRenderContext *pRC = (ChRenderContext *)lpContext;

	return pRC->EnumDriver(lpGuid, lpDeviceDescription, lpDeviceName,
        lpHWDesc, lpHELDesc);

}

/****************************************************************************/
/*                         D3D Device Enumeration                           */
/****************************************************************************/
/*
 * BPPToDDBD
 * Converts bits per pixel to a DirectDraw bit depth flag
 */
static DWORD
BPPToDDBD(int bpp)
{
    switch(bpp) {
        case 1:
            return DDBD_1;
        case 2:
            return DDBD_2;
        case 4:
            return DDBD_4;
        case 8:
            return DDBD_8;
        case 16:
            return DDBD_16;
        case 24:
            return DDBD_24;
        case 32:
            return DDBD_32;
        default:
            return 0;
    }
}

HRESULT ChRenderContext::EnumDriver(LPGUID lpGuid, LPSTR lpDeviceDescription, LPSTR lpDeviceName,
        LPD3DDEVICEDESC lpHWDesc, LPD3DDEVICEDESC lpHELDesc)
{
    BOOL hardware = FALSE; /* current start driver is hardware */
    BOOL mono = FALSE;     /* current start driver is mono light */
    LPD3DDEVICEDESC lpDesc;
    /*
     * Decide which device description we should consult
     */
    lpDesc = lpHWDesc->dcmColorModel ? lpHWDesc : lpHELDesc;
    /*
     * If this driver cannot render in the current display bit depth skip
     * it and continue with the enumeration.
     */
    if (!(lpDesc->dwDeviceRenderBitDepth & BPPToDDBD(GetBPP())))
        return D3DENUMRET_OK;
    /*
     * Record this driver's info
     */
    //memcpy(&myglobs.DriverGUID[myglobs.NumDrivers], lpGuid, sizeof(GUID));
    //lstrcpy(&myglobs.DriverName[myglobs.NumDrivers][0], lpDeviceName);
    /*
     * Choose hardware over software for everything, RGB lights over mono lights for "better"
	 * mono over rgb for "faster"
     */
    hardware = lpDesc == lpHWDesc ? TRUE : FALSE;
    mono = lpDesc->dcmColorModel & D3DCOLOR_MONO ? TRUE : FALSE;
    if (m_drivers[renderBetter].GetName().IsEmpty()) {
        /*
         * this is the first valid driver
         */
		m_drivers[renderBetter].Set(lpDeviceName, *lpGuid, hardware, mono);
		m_drivers[renderFaster].Set(lpDeviceName, *lpGuid, hardware, mono);
    } 
    else
    {
    	if (hardware)
	    {
	        /*
	         * this driver is hardware and start driver is not
	         */
			 if(!m_drivers[renderBetter].IsHardware() || (!mono && m_drivers[renderBetter].IsMono()))
			 {
			 	// If both mono, choose the hardware one
				m_drivers[renderBetter].Set(lpDeviceName, *lpGuid, hardware, mono);
			 }
			 if(!m_drivers[renderFaster].IsHardware() || (mono && !m_drivers[renderFaster].IsMono()))
			 {
				m_drivers[renderFaster].Set(lpDeviceName, *lpGuid, hardware, mono);
			 }
    	}
		if(mono)
		{
			 if(!m_drivers[renderFaster].IsHardware() && !m_drivers[renderFaster].IsMono())
			 {
				m_drivers[renderFaster].Set(lpDeviceName, *lpGuid, hardware, mono);
			 }
		}
		else
		{
			 if(!m_drivers[renderBetter].IsHardware() && m_drivers[renderBetter].IsMono())
			 {
				m_drivers[renderBetter].Set(lpDeviceName, *lpGuid, hardware, mono);
			 }
		}
	}

	//#pragma message("D3D no-devices failure handling Not done!")
    return (D3DENUMRET_OK);
}

/*
 * EnumDrivers
 * Enumerate the available D3D drivers, add them to the file menu, and choose
 * one to use.
 */
BOOL ChRenderContext::EnumDrivers()
{
    LPDIRECTDRAW lpDD;
    LPDIRECT3D lpD3D;
    HRESULT rval;

    /*
     * Create a DirectDraw object and query for the Direct3D interface to use
     * to enumerate the drivers.
     */
    rval = DirectDrawCreate(NULL, &lpDD, NULL);
    if (rval != DD_OK) {
        //TRACE1("Creation of DirectDraw HEL failed.\n%s", D3DRMErrorToString(rval));
        return FALSE;
    }
    rval = lpDD->QueryInterface(IID_IDirect3D, (void**) &lpD3D);
    if (rval != DD_OK) {
        //TRACE1("Creation of Direct3D interface failed.\n%s", D3DRMErrorToString(rval));
        lpDD->Release();
        return FALSE;
    }
    /*
     * Enumerate the drivers, setting CurrDriver to -1 to initialize the
     * driver selection code in enumDeviceFunc
     */

    rval = lpD3D->EnumDevices(enumDeviceFunc, this);
    if (rval != DD_OK) {
        //TRACE1("Enumeration of drivers failed.\n%s", D3DAppErrorToString(rval));
        return FALSE;
    }
    lpD3D->Release();
    lpDD->Release();

    /*
     * Make sure we found at least one valid driver for each one
     */

	if(m_drivers[renderBetter].GetName().IsEmpty() || 
		m_drivers[renderFaster].GetName().IsEmpty())
	{
		return FALSE;
	}

    return TRUE;
}

#endif	// D3D


#if (defined(CH_USE_D3D))
ChDevice3D::ChDevice3D() :
		#if (defined(CH_USE_D3D))
		m_frontSurface(0),
		m_backSurface(0),
		m_zSurface(0),
		m_clipper(0),
		#endif
		m_pRC(0),
		m_device(0)
{
}
ChDevice3D::ChDevice3D(ChRenderContext *pRC, int width, int height, bool boolOffscreen ) :
		#if (defined(CH_USE_D3D))
		m_frontSurface(0),
		m_backSurface(0),
		m_zSurface(0),
		m_clipper(0),
		#endif
		m_pRC(0),
		m_device(0)
{
	Init(pRC, width, height, boolOffscreen);	
}


ChDevice3D::~ChDevice3D()
{
	Kill();
}

void ChDevice3D::Kill()
{
	RELEASE_INTERFACE(m_device);
	RELEASE_INTERFACE(m_backSurface);
	RELEASE_INTERFACE(m_frontSurface);
	RELEASE_INTERFACE(m_zSurface);
	RELEASE_INTERFACE(m_clipper);
}



bool ChDevice3D::Init(ChRenderContext *pRC, int width, int height, bool boolOffscreen)
{
	Kill();					// If we decide we want to reuse these,
							// just release eveything first
	m_pRC = pRC;
	if(boolOffscreen)
	{
		return pRC->InitOffscreenDevice(*this, width, height);
	}
	else
	{
		return pRC->InitWindowDevice(*this, width, height);
	}
}

bool ChRenderContext::InitWindowDevice(ChDevice3D &device, int width, int height)
{
	return false;
}

bool ChRenderContext::InitOffscreenDevice(ChDevice3D &device, int width, int height)
{
	bool boolSuccess = true;
	#if (defined(CH_USE_D3D))
    DDSURFACEDESC       ddsd;
    //HRESULT result;

	device.m_frontSurface = 0;
	device.m_backSurface = 0;
	device.m_device = 0;

	try
	{
	    memset( &ddsd, 0, sizeof( ddsd ) );
	    ddsd.dwSize = sizeof( ddsd );
	    ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT |DDSD_WIDTH | DDSD_BACKBUFFERCOUNT;
	    ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY | DDSCAPS_FLIP |
            DDSCAPS_3DDEVICE | DDSCAPS_COMPLEX;
	    ddsd.dwBackBufferCount = 1;
		ddsd.dwHeight = height;
	    ddsd.dwWidth = width;

	    if(m_DD->CreateSurface(&ddsd, &device.m_frontSurface, NULL) != DD_OK) 
	    	throw ChExInterface(CH_EX_CREATE_FAILED);

		ddsd.ddsCaps.dwCaps = DDSCAPS_BACKBUFFER;

		if(device.m_frontSurface->GetAttachedSurface(&ddsd.ddsCaps, &device.m_backSurface) != DD_OK) 
	    	throw ChExInterface(CH_EX_QUERY_FAILED);


		ChRenderOptimization setting = ((ChMazeWnd*)GetWnd())->GetSettings()->GetRenderOptimization();
		GUID guid = m_drivers[setting].GetGUID();	// our driver to use
		if(m_D3DRM->CreateDeviceFromSurface(&guid, m_DD, device.m_backSurface, &device.m_device) != DD_OK) 
	    	throw ChExInterface(CH_EX_QUERY_FAILED);

	}
	catch( ChExInterface qExcept )
	{
		int val =  qExcept.val;
		TRACE1("Offscreen device creation failure - reason %d", val);  
		RELEASE_INTERFACE(device.m_frontSurface);
		RELEASE_INTERFACE(device.m_backSurface);
		boolSuccess = false;
	}
	catch(...)
	{
		RELEASE_INTERFACE(device.m_frontSurface);
		RELEASE_INTERFACE(device.m_backSurface);
		boolSuccess = false;
	}
	#endif

	return (boolSuccess);
	
}

#endif // D3D


//#endif // (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)




#if 0
	// maybe useful debris
		#if 0
		if(device.m_backSurface->QueryInterface( , &device.m_device) != DD_OK) 
	    	throw ChExInterface(CH_EX_QUERY_FAILED);


           d3dappi.lpBackBuffer->lpVtbl->QueryInterface(d3dappi.lpBackBuffer,
                                                &d3dappi.Driver[driver].Guid,
                                              (LPVOID*)&d3dappi.lpD3DDevice);
		#endif
HRESULT
D3DAppICreateSurface(LPDDSURFACEDESC lpDDSurfDesc,
                LPDIRECTDRAWSURFACE FAR *lpDDSurface) {
    HRESULT result;
    if (d3dappi.bOnlySystemMemory)
        lpDDSurfDesc->ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;
    result = d3dappi.lpDD->lpVtbl->CreateSurface(d3dappi.lpDD, lpDDSurfDesc,
                                                 lpDDSurface, NULL);
    return result;
}


    ddrval = D3DAppCreateSurface(&ddsd, &myglobs.lpFrameRateBuffer);
    if (ddrval != DD_OK) {
        Msg("Could not create frame rate buffer.\n%s", D3DAppErrorToString(ddrval));    
        goto exit_with_error;
    }
#endif	// debris
