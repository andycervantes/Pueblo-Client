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

	Implementation for the ChQvInstance class for  Intel 3DR.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvTextur.cpp,v 2.11 1996/06/27 03:44:16 jimd Exp $

#include "grheader.h"

#include "CvInstnc.h"
#include <QvInfo.h>
#include <QvState.h>
#include "ChMaze.h"
#include "CvBound.h"
#include "CvTextur.h"
#include "ChRenderData.h"

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
//RLDestroyCallback TextureDestroyCallback;
void TextureDestroyCallback(ChNrObject obj, void * arg)
{
	ChTexture *pTex = (ChTexture *)arg;
	delete pTex;
}

ChTexture::ChTexture() : m_pImage(0), m_texture(0), m_pBytes(0), m_boolChroma(false)
{
	#if 0
	Create(16, 16, ChColor(0, 0, 0));
	// Create Texture
	m_texture = RLCreateTexture(m_pImage);
	ChNrObjectAddDestroyCallback(m_texture, TextureDestroyCallback, this);
	#endif
}

ChTexture::ChTexture( ChRenderContext *pRC, int width, int height, const ChColor& color, bool boolPalette ) : 
	m_pImage(0), m_texture(0), m_pBytes(0), m_boolChroma(false)
{
	Create(width, height, color);
	// Create Texture
	m_texture = pRC->CreateTexture(m_pImage);
	ChNrObjectAddDestroyCallback(m_texture, TextureDestroyCallback, this);
}

ChTexture::ChTexture( ChRenderContext *pRC, const ChColor& color, const CBitmap &alphaBmp, const ChColor *pChroma ) : 
	m_pImage(0), m_texture(0), m_pBytes(0)
{	
	BITMAP bmpData;

	m_boolChroma = pChroma != 0;
	if(m_boolChroma) m_chromaKey = *pChroma;

	alphaBmp.GetObject(sizeof(bmpData), &bmpData);
	int width = bmpData.bmWidth, height = bmpData.bmHeight;
	Create(width, height, color);
	SetAlpha(alphaBmp);
	// Create Texture
	m_texture = pRC->CreateTexture(m_pImage);
	ChNrObjectAddDestroyCallback(m_texture, TextureDestroyCallback, this);
}

ChTexture::~ChTexture()
{
	delete m_pImage;
	m_pImage = 0;
	delete [] m_pBytes;
	m_pBytes = 0;
}

bool ChTexture::Create( int width, int height, const ChColor& color, bool boolPalette ) 
{
	// Assume for now that width and height are [powers of 2
	int bytesPerPixel = boolPalette ? 1 : 4;
	m_pBytes = new char[width * height * bytesPerPixel];
	m_pImage = new ChNrImage;

	// Fill in structure 
    m_pImage->width		=	width;
    m_pImage->height	=	height;
    m_pImage->aspectx 	=	1;
    m_pImage->aspecty	=	1;
    m_pImage->depth = boolPalette ? 8 : 32;			/* bits per pixel */
    m_pImage->rgb = !boolPalette;
    m_pImage->bytes_per_line = bytesPerPixel * width;
    m_pImage->buffer1 = m_pBytes;	
    m_pImage->buffer2 = 0;
    if(boolPalette)
    {
		int paletteSize = 1<<m_pImage->depth;

	    m_pImage->red_mask		= 0xFF; 
	    m_pImage->green_mask	= 0xFF;   
	    m_pImage->blue_mask		= 0xFF;
		m_pImage->alpha_mask 	= 0xFF;
	    m_pImage->palette_size = paletteSize;
	    m_pImage->palette = new ChNrPaletteEntry[paletteSize];
		// Fill in color
		ChColor acolor = color;
		unsigned char red = (unsigned char)(acolor.r() * 255);
		unsigned char green = (unsigned char)(acolor.g() * 255);
		unsigned char blue = (unsigned char)(acolor.b() * 255);
		for(int j = 0; j < m_pImage->palette_size; j ++)
		{
			m_pImage->palette[j].red = red;	
			m_pImage->palette[j].green = green;	
			m_pImage->palette[j].blue = blue;
			m_pImage->palette[j].flags = ChNrPaletteFree;
				
		}
		m_pImage->palette[0].flags = ChNrPaletteReadOnly;   // just use the 0th entry
		memcpy(m_pBytes, 0, width * height * bytesPerPixel);
    }
    else
    {			
	    m_pImage->red_mask		= 0xFF0000; 
	    m_pImage->green_mask	= 0xFF00;   
	    m_pImage->blue_mask		= 0xFF;
		m_pImage->alpha_mask 	= 0xFF000000;
	    m_pImage->palette_size = 0;
	    m_pImage->palette = 0;

		// Fill in color
		ChColor acolor = color;
		acolor.SetAlpha(1.);
		for(int j = 0; j < width * height; j ++)
		{
			memcpy(m_pBytes + j * 4, acolor.GetNative(), 4);
		}
	}

	return true;
};

bool ChTexture::SetAlpha( const CBitmap &alphaBmp )
{	
	BITMAP bmpData;

	alphaBmp.GetObject(sizeof(bmpData), &bmpData);
	int width = bmpData.bmWidth, height = bmpData.bmHeight;
	if(height < 0) height = -height;
	HBITMAP hBmp = HBITMAP(alphaBmp.GetSafeHandle());		// MFC doesn't do dib stuff

	LPBITMAPINFO pInfo = (LPBITMAPINFO)(new char[sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD)]);
	pInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	pInfo->bmiHeader.biCompression = BI_RGB;
	pInfo->bmiHeader.biBitCount = 1;
	pInfo->bmiHeader.biPlanes = 1;
	pInfo->bmiHeader.biHeight = bmpData.bmHeight;
	pInfo->bmiHeader.biWidth = width;
	//pInfo->bmiHeader.biBitCount = 1;
	CDC dc;
	dc.CreateCompatibleDC(0);
	int val = ::GetDIBits(	dc.GetSafeHdc(), 			// HDC  hdc,	// handle of device context 
    			hBmp,		// HBITMAP  hbmp,	// handle of bitmap 
    			0,			// UINT  uStartScan,	// first scan line to set in destination bitmap  
    			height,		// UINT  cScanLines,	// number of scan lines to copy 
    			0,		// LPVOID  lpvBits,	// address of array for bitmap bits 
    			pInfo,		// LPBITMAPINFO  lpbi,	// address of structure with bitmap data 
    			DIB_RGB_COLORS);// UINT  uUsage 	// RGB or palette index 

	BYTE *pBits = new BYTE[pInfo->bmiHeader.biSizeImage];
	pInfo->bmiHeader.biCompression = BI_RGB;

	//ppInfo->bmiHeader.biBitCount = 1;

	::GetDIBits(	dc.GetSafeHdc(), 			// HDC  hdc,	// handle of device context 
    			hBmp,		// HBITMAP  hbmp,	// handle of bitmap 
    			0,			// UINT  uStartScan,	// first scan line to set in destination bitmap  
    			height,		// UINT  cScanLines,	// number of scan lines to copy 
    			pBits,		// LPVOID  lpvBits,	// address of array for bitmap bits 
    			pInfo,		// LPBITMAPINFO  lpbi,	// address of structure with bitmap data 
    			DIB_RGB_COLORS);// UINT  uUsage 	// RGB or palette index 
	
	ASSERT(pInfo->bmiHeader.biBitCount == 1);		// only handling this for now

	int bytesPerRow = ((width - 1) / 32 + 1) * 4;
	BYTE	*pSrc = pBits;

	// We'll write the chroma key into the color bytes
	// if requested.
	unsigned long *pChroma;
	if(m_boolChroma) pChroma = (unsigned long *)(m_chromaKey.GetNative());

	for(int i = 0; i < height; i++)
	{
		int row = (bmpData.bmHeight > 0) ? height - i - 1: i;
		char * pBytes = m_pBytes + row * width * 4;
		for(int j=0; j<width; j++)
		{
			//unsigned char mask = 1 << (j % 8);
			unsigned char mask = 128 >> (j % 8);
			#if 0

			unsigned int t1 = pSrc[j / 8];
			unsigned int t2 = t1 & mask;
			unsigned int t3 = !!t2;
			char alpha = pInfo->bmiColors[t3].rgbRed;
			#else
			char alpha = pInfo->bmiColors[!!(pSrc[j / 8] & mask)].rgbRed;
			#endif

			// Set the chroma key if requested, 
			// Then set the alpha
			if(m_boolChroma && !alpha)
			{
				memcpy(pBytes + j * 4, pChroma, sizeof(*pChroma));
			}
			pBytes[j * 4 + 3] = alpha;
		}
		pSrc += bytesPerRow;
	}
	delete [] pInfo;
	delete [] pBits; 
	//ChNrTextureChanged( m_texture, true, true );
	return true;
}


#endif


#if defined(CH_USE_3DR)
#endif // 3dr

ChQvTextureMap::ChQvTextureMap( ChQvShapeInstance *pInst ) : m_pInst(pInst), m_pTx2(0), m_pIndices(0)
{
	m_pTx2 =(float*)((QvMFVec2f*)(pInst->GetTextureCoordinate2()->point.values));
};

/////////////////////////////////////////////////////////////

#if defined(CH_USE_3DR)
PointF_t ChQvIndexedTextures::GetCoord3(int index, float *pVert)
{
	PointF_t	texCoord;
													 
	if(m_boolIsDefault)
	{
		if(m_iMajor == 1)
		{
		 	texCoord.x =  (m_fMajorOff - pVert[m_iMajor]) / m_fMajorLen;
		}
		else
		{
			texCoord.x =  (pVert[m_iMajor] - m_fMajorOff) / m_fMajorLen;
		}
		if(m_iMinor == 1)
		{
			texCoord.y =  (m_fMinorOff - pVert[m_iMinor]) / m_fMajorLen;

			// Trim from top - no special case for y - assumes fMinorOff is min bound
			//texCoord.y =  (pVert[m_iMinor] - m_fMinorOff) / m_fMajorLen;
		}
		else
		{
			texCoord.y =  (pVert[m_iMinor] - m_fMinorOff) / m_fMajorLen;
		}
	}
	else
	{
		int i;
		if(m_pIndices)
		{
			i =  (m_pIndices[index % m_numIndices] * 2);
		}
		else
		{
			i =  (index * 2);
		}
		texCoord.x = m_pTx2[i];
		texCoord.y = 1. - m_pTx2[i+1];	   // we use 3dr coords; vrml are bot-left origin
	}
										  // Transform the coords
	texCoord.y = 1. - texCoord.y;		  // to vrml
	((ChQvTexture2TransformRenderData*)(m_pInst->GetTexture2Transform()->GetRenderData()))
		->Transform(texCoord.x, texCoord.y);
	texCoord.y = 1. - texCoord.y;	// back to 3dr

	texCoord.z = 1;
	return texCoord;
};
#else
GxVec3f ChQvIndexedTextures::GetCoord3(int index, float *pVert)
{
	GxVec3f	texCoord;
													 
	if(m_boolIsDefault)
	{
		#if 0
		if(m_iMajor == 1)
		{
		 	texCoord.x() =  (m_fMajorOff - pVert[m_iMajor]) / m_fMajorLen;
		}
		else
		{
			texCoord.x() =  (pVert[m_iMajor] - m_fMajorOff) / m_fMajorLen;
		}
		if(m_iMinor == 1)
		{
			texCoord.y() =  (m_fMinorOff - pVert[m_iMinor]) / m_fMajorLen;
		}
		else
		{
			texCoord.y() =  (pVert[m_iMinor] - m_fMinorOff) / m_fMajorLen;
		}
		#endif
			texCoord.x() =  (pVert[m_iMajor] - m_fMajorOff) / m_fMajorLen;
 			texCoord.y() =  (pVert[m_iMinor] - m_fMinorOff) / m_fMajorLen;

	}
	else
	{	
		int i;
		if(m_pIndices)
		{
			i =  (m_pIndices[index % m_numIndices] * 2);
		}
		else
		{
			i =  (index * 2);
		}
		texCoord.x() = m_pTx2[i];
		texCoord.y() = m_pTx2[i+1];
		//texCoord.y() = 1. - m_pTx2[i+1];	   // we use 3dr coords; vrml are bot-left origin  -removed jwd 3/14/96
	}
										  // Transform the coords
	//texCoord.y() = 1. - texCoord.y();		  // to vrml	 -removed jwd 3/14/96
	((ChQvTexture2TransformRenderData*)(m_pInst->GetTexture2Transform()->GetRenderData()))
		->Transform(texCoord.x(), texCoord.y());
	texCoord.y() = 1. - texCoord.y();	// back to rlab

	texCoord.z() = 1;
	return texCoord;
};


#endif


/////////////////////////////////////////////////////////////


ChQvConeTextures::ChQvConeTextures( ChQvConeInstance *pInst, int iNumFacets )
 : ChQvTextureMap(pInst), m_iNumFacets(iNumFacets)
{
	float pi = atan(1.) * 4.;
	float twoPi = pi * 2;
	m_fStep = twoPi / m_iNumFacets;
	//m_fStep = 1. / m_iNumFacets;
	m_boolIsDefault = true;
};

#if defined(CH_USE_3DR)
PointF_t ChQvConeTextures::GetCoord3(int part, int facet, int vert)
{
	PointF_t	texCoord;
	// assumes we start at top back, then go down & ccw
	// we assume a quadstrip facet model
	// each facet has two vertices; one at top and one bottom
	switch( part )
	{
		case 0:
		{
			texCoord.x = facet / float(m_iNumFacets);	// facets: 0 to numFacets, inclusive
			texCoord.y = (vert & 1) ? 1. : 0.;
			texCoord.z = 1;
			break;
		}
		case 1:
		{		// note bottom starts at 180 (front), and goes cw
			float theta = m_fStep * vert + PI;  // verts:  0 to numFacets, inclusive
			texCoord.x = .5 + sin(theta) * .5;	 // opp direction from top
			texCoord.y = .5 - cos(theta) * .5;
			texCoord.z = 1;
			break;
		}
		default:
		{	// error
			break;
		}
	}
										  // Transform the coords
	texCoord.y = 1. - texCoord.y;		  // to vrml
	((ChQvTexture2TransformRenderData*)(m_pInst->GetTexture2Transform()->GetRenderData()))
		->Transform(texCoord.x, texCoord.y);
	texCoord.y = 1. - texCoord.y;	// back to 3dr


	return texCoord;
};
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
GxVec3f ChQvConeTextures::GetCoord3(ChQvConeInstance::Parts part, int facet, int vert)
{
	GxVec3f	texCoord;
	// assumes we start at top back, then go down & ccw
	// we assume a quadstrip facet model
	// each facet has two vertices; one at top and one bottom
	switch( part )
	{
		case ChQvConeInstance::Sides:
		{
			texCoord.x() = (facet + (.5 * vert)) / float(m_iNumFacets);	// 
			texCoord.y() = (vert & 1) ? 0. : 1.;   // middle is top
			texCoord.z() = 1;
			break;
		}
		case ChQvConeInstance::Bottom:
		{		// note bottom starts at 180 (front), and goes cw
			float theta = m_fStep * vert + PI;  // verts:  0 to numFacets, inclusive
			texCoord.x() = .5 + sin(theta) * .5;	 // opp direction from top
			texCoord.y() = .5 - cos(theta) * .5;
			texCoord.z() = 1;
			break;
		}
		default:
		{	// error
			break;
		}
	}
										  // Transform the coords
	texCoord.y() = 1. - texCoord.y();		  // to vrml
	((ChQvTexture2TransformRenderData*)(m_pInst->GetTexture2Transform()->GetRenderData()))
		->Transform(texCoord.x(), texCoord.y());
	texCoord.y() = 1. - texCoord.y();	// back to 3dr


	return texCoord;
};
#endif


/////////////////////////////////////////////////////////////
ChQvCubeTextures::ChQvCubeTextures( ChQvCubeInstance *pInst ) : ChQvTextureMap(pInst)
{
	m_boolIsDefault = true;
}


#if defined(CH_USE_3DR)
PointF_t ChQvCubeTextures::GetCoord3(int face, int vert)
{
	PointF_t	texCoord;
	
	texCoord.x = (vert == 0 || vert == 3) ? 0. : 1.;
	texCoord.y = (vert == 0 || vert == 1) ? 0. : 1.;
										  // Transform the coords
	texCoord.y = 1. - texCoord.y;		  // to vrml
	((ChQvTexture2TransformRenderData*)(m_pInst->GetTexture2Transform()->GetRenderData()))
		->Transform(texCoord.x, texCoord.y);
	texCoord.y = 1. - texCoord.y;	// back to 3dr

	texCoord.z = 1;

	return texCoord;
};
#else
GxVec3f ChQvCubeTextures::GetCoord3(int face, int vert)
{
	GxVec3f	texCoord;
	
	texCoord.x() = (vert == 0 || vert == 3) ? 0. : 1.;
	texCoord.y() = (vert == 0 || vert == 1) ? 0. : 1.;
										  // Transform the coords
	texCoord.y() = 1. - texCoord.y();		  // to vrml
	((ChQvTexture2TransformRenderData*)(m_pInst->GetTexture2Transform()->GetRenderData()))
		->Transform(texCoord.x(), texCoord.y());
	texCoord.y() = 1. - texCoord.y();	// back to 3dr

	texCoord.z() = 1;

	return texCoord;
};
#endif


//////////////////////////////////////////////////////////////////
ChQvCylinderTextures::ChQvCylinderTextures( ChQvCylinderInstance *pInst, int iNumFacets )
 : ChQvTextureMap(pInst), m_iNumFacets(iNumFacets)
{
	float pi = atan(1.) * 4.;
	float twoPi = pi * 2;
	m_fStep = twoPi / m_iNumFacets;
	m_boolIsDefault = true;
};
#if defined(CH_USE_3DR)
PointF_t ChQvCylinderTextures::GetCoord3(int part, int facet, int vert)
{								// TODO get rid of this and use gxvec3f
	PointF_t	texCoord;
	// assumes we start at top back, then go down & ccw
	// we assume a quadstrip facet model
	// each facet has two vertices; one at top and one bottom
	switch( part )
	{
		case 0:
		{
			texCoord.x = facet / float(m_iNumFacets);	// facets: 0 to numFacets, inclusive
			texCoord.y = (vert & 1) ? 1. : 0.;
			texCoord.z = 1;
			break;
		}
		case 1:
		{		// start at 0, and go ccw
			float theta = m_fStep * vert;	  // verts:  0 to numFacets, inclusive
			texCoord.x = .5 - sin(theta) * .5;
			texCoord.y = .5 - cos(theta) * .5;
			texCoord.z = 1;
			break;
		}
		case 2:
		{		// note bottom starts at 180 (front), and goes cw
			float theta = m_fStep * vert + PI;  // verts:  0 to numFacets, inclusive
			texCoord.x = .5 + sin(theta) * .5;	 // opp direction from top
			texCoord.y = .5 - cos(theta) * .5;
			texCoord.z = 1;
			break;
		}
		default:
		{	// error
			break;
		}
	}
										  // Transform the coords
	texCoord.y = 1. - texCoord.y;		  // to vrml
	((ChQvTexture2TransformRenderData*)(m_pInst->GetTexture2Transform()->GetRenderData()))
		->Transform(texCoord.x, texCoord.y);
	texCoord.y = 1. - texCoord.y;	// back to 3dr


	return texCoord;
};
#else
GxVec3f ChQvCylinderTextures::GetCoord3(ChQvCylinderInstance::Parts part, int facet, int vert)
{
	GxVec3f	texCoord;	// 0 is sides, 1 is top, 2 is bottom
	// assumes we start at top back, then go down & ccw
	// we assume a quadstrip facet model
	// each facet has two vertices; one at top and one bottom
	switch( part )
	{
		case ChQvCylinderInstance::Sides:
		{
			if(vert > 1) facet++;
			texCoord.x() = facet / float(m_iNumFacets);	// facets: 0 to numFacets, inclusive
			texCoord.y() = (vert & 1) ? 1. : 0.;
			texCoord.z() = 1;
			break;
		}
		case ChQvCylinderInstance::Top:
		{		// start at 0, and go ccw
			float theta = m_fStep * vert;	  // verts:  0 to numFacets, inclusive
			texCoord.x() = .5 - sin(theta) * .5;
			texCoord.y() = .5 - cos(theta) * .5;
			texCoord.z() = 1;
			break;
		}
		case ChQvCylinderInstance::Bottom:
		{		// note bottom starts at 180 (front), and goes cw
			float theta = m_fStep * vert + PI;  // verts:  0 to numFacets, inclusive
			texCoord.x() = .5 + sin(theta) * .5;	 // opp direction from top
			texCoord.y() = .5 - cos(theta) * .5;
			texCoord.z() = 1;
			break;
		}
		default:
		{	// error
			break;
		}
	}
										  // Transform the coords
	texCoord.y() = 1. - texCoord.y();		  // to vrml
	((ChQvTexture2TransformRenderData*)(m_pInst->GetTexture2Transform()->GetRenderData()))
		->Transform(texCoord.x(), texCoord.y());
	texCoord.y() = 1. - texCoord.y();	// back to rlab


	return texCoord;
};
#endif

ChQvIFSTextures::ChQvIFSTextures( ChQvIFSInstance *pInst)
{
	m_pInst = pInst;
	QvIndexedFaceSet* pNode = (QvIndexedFaceSet*)(pInst->GetNode());
	m_boolIsDefault = true;
												// Ignore completely degenerate maps,
												// it's probably our default node anyways.
												// But we accept even a two point map
	if(pInst->GetTextureCoordinate2()->point.num > 1)
	{
		m_pTx2 =(float*)((QvMFVec2f*)(pInst->GetTextureCoordinate2()->point.values));
		m_boolIsDefault = false;
		// Do we have a coord index array with our node?
		if(pNode->textureCoordIndex.num > 1)
		{
			m_pIndices =  pNode->textureCoordIndex.values;
			m_numIndices =  pNode->textureCoordIndex.num;
											// Validate map indices, use defaults if bad
			for(int j=0; j < pNode->textureCoordIndex.num && pNode->textureCoordIndex.values[j] != -1; j++)
			{
				if(pNode->textureCoordIndex.values[j] < -1 || 
					pNode->textureCoordIndex.values[j] >= pInst->GetTextureCoordinate2()->point.num)
				{
					m_boolIsDefault = true;
					break;
				}
			}
		}

	}
	if(m_boolIsDefault)
	{
		// Compute default parameters 
		GxVec3f	bounds[2], center;

		QvCoordinate3 *pC3 = pInst->GetCoordinate3();
		GetBoundingCube( &pNode->coordIndex, pC3, bounds[0], bounds[1], center);
		float	extent[3];
		
		extent[0] = bounds[1].x() - bounds[0].x();	 
		extent[1] = bounds[1].y() - bounds[0].y();	 
		extent[2] = bounds[1].z() - bounds[0].z();	 
		m_iMajor = 0;
		if(extent[1] > extent[m_iMajor]) m_iMajor = 1;
		if(extent[2] > extent[m_iMajor]) m_iMajor = 2;
		m_iMinor = (m_iMajor+1)%3;
		if(extent[(m_iMinor+1)%3] > extent[m_iMinor]) m_iMinor = (m_iMinor+1)%3;
		m_fMajorLen = extent[m_iMajor];

		if(m_iMinor==0)  m_fMinorOff = bounds[0].x();
		if(m_iMinor==1)  m_fMinorOff = bounds[1].y();
		if(m_iMinor==2)  m_fMinorOff = bounds[0].z();
		
		if(m_iMajor==0)  m_fMajorOff = bounds[0].x();
		if(m_iMajor==1)  m_fMajorOff = bounds[1].y();
		if(m_iMajor==2)  m_fMajorOff = bounds[0].z();
		
		#if !defined(CH_USE_3DR)
		if(m_iMinor==1)  m_fMinorOff = bounds[0].y();
		if(m_iMajor==1)  m_fMajorOff = bounds[0].y();
		#endif
	}
};

ChQvILSTextures::ChQvILSTextures( ChQvILSInstance *pInst) : ChQvIndexedTextures(pInst)
 {
	QvIndexedLineSet* pNode = (QvIndexedLineSet*)(pInst->GetNode());
	m_boolIsDefault = true;

	if(pInst->GetTextureCoordinate2()->point.num > 1)
	{
		m_pTx2 =(float*)((QvMFVec2f*)(pInst->GetTextureCoordinate2()->point.values));
		m_boolIsDefault = false;
		// Do we have a coord index array with our node?
		if(pNode->textureCoordIndex.num > 1)
		{
			m_pIndices =  pNode->textureCoordIndex.values;
			m_numIndices =  pNode->textureCoordIndex.num;

											// Validate map indices, use defaults if bad
			for(int j=0; j < pNode->textureCoordIndex.num && pNode->textureCoordIndex.values[j] != -1; j++)
			{
				if(pNode->textureCoordIndex.values[j] < -1 || 
					pNode->textureCoordIndex.values[j] >= pInst->GetTextureCoordinate2()->point.num)
				{
					m_boolIsDefault = true;
					break;
				}
			}
		}
	}
	if(m_boolIsDefault)
	{
		m_boolIsDefault = true;
		// Compute default parameters 
		GxVec3f	bounds[2], center;

		QvCoordinate3 *pC3 = pInst->GetCoordinate3();
		GetBoundingCube( &pNode->coordIndex, pC3, bounds[0], bounds[1], center);
		float	extent[3];
		
		extent[0] = bounds[1].x - bounds[0].x;	 
		extent[1] = bounds[1].y - bounds[0].y;	 
		extent[2] = bounds[1].z - bounds[0].z;	 
		m_iMajor = 0;
		if(extent[1] > extent[m_iMajor]) m_iMajor = 1;
		if(extent[2] > extent[m_iMajor]) m_iMajor = 2;
		m_iMinor = (m_iMajor+1)%3;
		if(extent[(m_iMinor+1)%3] > extent[m_iMinor]) m_iMinor = (m_iMinor+1)%3;
		m_fMajorLen = extent[m_iMajor];

		if(m_iMinor==0)  m_fMinorOff = bounds[0].x;
		if(m_iMinor==1)  m_fMinorOff = bounds[1].y;
		if(m_iMinor==2)  m_fMinorOff = bounds[0].z;
		
		if(m_iMajor==0)  m_fMajorOff = bounds[0].x;
		if(m_iMajor==1)  m_fMajorOff = bounds[1].y;
		if(m_iMajor==2)  m_fMajorOff = bounds[0].z;
		
	}
};

#if defined(CH_USE_3DR)
#endif // 3DR 

// end of file
