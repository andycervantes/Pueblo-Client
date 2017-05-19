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

	Implementation for the Native create methods ChRenderContext class for  Intel 3DR.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChNrCreate.cpp,v 1.1 1996/06/27 17:23:29 jimd Exp $

#define INITGUID
#include "grheader.h"

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#include "ChRender.h"

ChNrFrame ChRenderContext::CreateFrame(ChNrFrame parent)
{
#if (defined(CH_USE_RLAB))
	return RLCreateFrame(parent);
#elif (defined(CH_USE_D3D))
	ASSERT(m_D3DRM);
	ChNrFrame frame = 0;
	m_D3DRM->CreateFrame(parent, &frame);
	return frame;
#endif
}

ChNrMesh ChRenderContext::CreateMesh()
{
#if (defined(CH_USE_RLAB))
	return RLCreateMesh();

#elif (defined(CH_USE_D3D))
	ASSERT(m_D3DRM);
	ChNrMesh mesh = 0;
	m_D3DRM->CreateMeshBuilder(&mesh);
	return mesh;

#endif
}
ChNrFace ChRenderContext::CreateFace()
{
#if (defined(CH_USE_RLAB))
	return RLCreateFace();

#elif (defined(CH_USE_D3D))
	ASSERT(m_D3DRM);
	ChNrFace face = 0;
	m_D3DRM->CreateFace(&face);
	return face;

#endif
}
ChNrLight ChRenderContext::CreateLight(ChNrLightType type, const ChColor & color)
{
	ChColor clr = color;
#if (defined(CH_USE_RLAB))
	return RLCreateLight(type, *(clr.GetNative()));

#elif (defined(CH_USE_D3D))
	ASSERT(m_D3DRM);
	ChNrLight light = 0;
	m_D3DRM->CreateLight(type, *(clr.GetNative()), &light);
	return light;
#endif
}
ChNrLight ChRenderContext::CreateLightRGB(ChNrLightType type, ChNrValue r, ChNrValue g, ChNrValue b)
{
#if (defined(CH_USE_RLAB))
	return RLCreateLightRGB(type, r, g, b);

#elif (defined(CH_USE_D3D))
	ASSERT(m_D3DRM);
	ChNrLight light = 0;
	m_D3DRM->CreateLightRGB(type, r, g, b, &light);
	return light;

#endif
};

ChNrViewport ChRenderContext::CreateViewport(ChNativeContext dev, ChNrFrame camera, DWORD dwXPos, DWORD dwYPos, DWORD dwWidth, DWORD dwHeight)
{
#if (defined(CH_USE_RLAB))
	return RLCreateViewport(dev, camera, dwXPos, dwYPos, dwWidth, dwHeight);

#elif (defined(CH_USE_D3D))
	ASSERT(m_D3DRM);
	ChNrViewport view = 0;
	m_D3DRM->CreateViewport(dev, camera, dwXPos, dwYPos, dwWidth, dwHeight, &view);
	return view;
#endif
};

ChNrMaterial ChRenderContext::CreateMaterial(ChNrValue ks, ChNrValue pow)
{
#if (defined(CH_USE_RLAB))
	return RLCreateMaterial(ks, pow);

#elif (defined(CH_USE_D3D))
	ASSERT(m_D3DRM);
	ChNrMaterial material = 0;
	m_D3DRM->CreateMaterial(pow, &material);
	return material;
#endif
};

ChTextureHandle ChRenderContext::CreateTexture(ChNrImage *pImage )
{
#if (defined(CH_USE_RLAB))
	return RLCreateTexture(pImage );

#elif (defined(CH_USE_D3D))
	ASSERT(m_D3DRM);
	ChTextureHandle texture;
	m_D3DRM->CreateTexture(pImage, &texture);
	return texture;

#endif
}

#endif
// end of file
