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

	Implementation for the ChQvAsciiText class for  Intel 3DR.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChAscTxt.cpp,v 2.19 1996/06/27 03:42:57 jimd Exp $

#include "grheader.h"

#include "CvInstnc.h"
#include <QvInfo.h>
#include <QvState.h>
#include "ChMaze.h"
#include "ChMazDep.h"
#include "CvTrnsfm.h"
#include "CvNormal.h"
#include "CvBound.h"
#include "CvMaterl.h"
#include "CvTextur.h"
#include "ChGrFont.h"

#define USE_TEXTURE_TEXT	1

/*
From the VRML 1.0 Spec
Also see: 
http://vrml.wired.com/vrml.tech/vrml10-3.html

AsciiText

This node represents strings of text characters from the ASCII coded character set. The first
string is rendered with its baseline at (0,0,0). All subsequent strings advance y by -(size *
spacing). See FontStyle for a description of the size field. The justification field determines
the placement of the strings in the x dimension. LEFT (the default) places the left edge of each
string at x=0. CENTER places the center of each string at x=0. RIGHT places the right edge of
each string at x=0. Text is rendered from left to right, top to bottom in the font set by FontStyle.
The width field defines a suggested width constraint for each string. The default is to use the
natural width of each string. Setting any value to 0 indicates the natural width should be used for
that string. 

The text is transformed by the current cumulative transformation and is drawn with the current
material and texture. 

Textures are applied to 3D text as follows. The texture origin is at the origin of the first string, as
determined by the justification. The texture is scaled equally in both S and T dimensions, with
the font height representing 1 unit. S increases to the right. The T origin can occur anywhere
along each character, depending on how that character's outline is defined. 



JUSTIFICATION

     LEFT     Align left edge of text to origin

     CENTER   Align center of text to origin

     RIGHT    Align right edge of text to origin


FILE FORMAT/DEFAULTS

     AsciiText {

          string         ""    # MFString

          spacing        1     # SFFloat

          justification  LEFT  # SFEnum

          width          0     # MFFloat

     }


*/

/* Helper class for cache */

class ChAsciiCharCache
{
	friend class ChQvAsciiTextInstance;

	protected:
		ChPolyPolygonGx3 *m_pPoly;
		unsigned int m_letter;
		float m_xAdvance, m_yAdvance;
 

	public:
		ChAsciiCharCache(ChPolyPolygonGx3 *pPoly, unsigned int letter, float	xAdvance, float yAdvance)
		{
			m_pPoly = pPoly;
			m_letter = letter;
			m_xAdvance = xAdvance;
			m_yAdvance = yAdvance;
		};
		~ChAsciiCharCache()
		{
			delete m_pPoly;
		};
};

ChQvAsciiTextInstance::ChQvAsciiTextInstance() : ChQvShapeInstance(), m_pCache(0)
{
}

ChQvAsciiTextInstance::~ChQvAsciiTextInstance()
{
	if(m_pCache)
	{
		while(!m_pCache->IsEmpty())
		{
			ChAsciiCharCache *pCharCache = m_pCache->RemoveHead();
			delete pCharCache;
		}
		delete m_pCache;
		m_pCache = 0;
	}
}



float ChQvAsciiTextInstance::GetTextWidth(HFONT hFont, int index)
{
	// return specified length if ! 0, else  string length in units
	QvAsciiText *pNode = (QvAsciiText *)m_pNode;
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	// fixed width not implemented yet for 3dr
	if(pNode->width.num > index && pNode->width.values[index] > 0.0) 
	{						     // treat negative like zero
		return pNode->width.values[index];
	}
	else
	#endif
	{
		char *str = (char*)(pNode->string.values[index].getString());
		return GetTextWidth( hFont, str );
	}
}

float ChQvAsciiTextInstance::GetTextWidth(HFONT hFont,  char * text)
{
	HDC hdc = ::GetDC(NULL);
	HFONT oldFont = HFONT(::SelectObject(hdc, hFont));

	SIZE size;
	if ( !GetTextExtentPoint32(hdc, text, strlen(text), &size) )
	{  // function will fail under Win32s, use	 GetTextExtentPoint
	  	GetTextExtentPoint(hdc, text, strlen(text), &size);
	}

	::SelectObject(hdc, oldFont);
	ReleaseDC(NULL, hdc);

	if(0 == size.cy) size.cy = 1;
	return size.cx * GetFontStyle()->size.value / size.cy; // 
}

float ChQvAsciiTextInstance::GetBaselineOffset()
{
	//return the baseline offset from TL corner for the current font
	// Remember that 1.0 * spacing is -total- font height, including all spacing
	QvAsciiText *pNode = (QvAsciiText *)m_pNode;
	return (-.75 * pNode->spacing.value * GetFontStyle()->size.value);	// bogus computation :: TODO - make accurate
}

float ChQvAsciiTextInstance::GetTextHeight()
{
	QvAsciiText *pNode = (QvAsciiText *)m_pNode;
	return pNode->spacing.value * pNode->string.num * GetFontStyle()->size.value;
}

float ChQvAsciiTextInstance::GetFontLODHeight(ChRenderContext *pRC)
{
	float height;

	ChQvBounds charBounds;
	GxVec3f lower, upper, center(0.,0.,0);
	const float MAX_FONT_HEIGHT = 50;
										// arbitrary value - determines best possible appearance
	const float aMatterOfTaste = 2;		// smaller is higher quality

	lower.set(0., 0., 0.);
	upper.set(GetFontStyle()->size.value * .5, GetFontStyle()->size.value, 0.);
	charBounds.SetBounds(lower, upper);
 	charBounds.SetCenter(center);
	charBounds.SetTransform(GetTransform());

	ChRect extent = GetBoundsExtent(pRC, &charBounds);

	int maxExtent = max(extent.bottom - extent.top, extent.right - extent.left);

	height = maxExtent / aMatterOfTaste;	
	float quality = pRC->GetQuality();
	height *= quality;

	height = max(height, 2.0);
	height = min(height, MAX_FONT_HEIGHT);
	return height;
}

bool ChQvAsciiTextInstance::Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	{
		ASSERT(m_frame );
		pRC->LockQv();		   // Lock tree so other threads don't kill our data
		if(!pIterator->IsOKToProceed(this))	 // This locks scene if available
		{
			pRC->UnlockQv();		   // Unlock tree 
			return 0;
		}
		if(IsConstructed())
		{
			pRC->UnlockScene();
			pRC->UnlockQv();		   // Unlock tree 
			return 1;
		}
		m_boolConstructed = true;
		
		
 		QvAsciiText *pNode = (QvAsciiText *)GetNode();

		ChNrMesh mesh = m_mesh = pRC->CreateMesh();
		ChNrFrameAddVisual(GetFrame(), mesh);
		D3DRelease(mesh);

		ChNrObjectSetAppData(mesh, (unsigned long)this);
		ChNrMeshSetPerspective(mesh,true);  
		ChNrMeshSetColorSource(mesh,ColorFromFace); 

				// flag to say something got put in here
		bool boolFilled = false;
		HFONT hFont;

		#if defined(USE_TEXTURE_TEXT)
		{
			// Use Textured text
			const int minimumAscent = 20;  // Before applying quality

			ChQvAsciiTextMaterials materialMap( this);
			pRC->AdjustTransparency(materialMap);
			ChMaterial mat = materialMap.GetMat(0);
			ChColor color = mat.GetBase();

			// Create the text dib - monochrome
			int quality = ((ChMazeWnd*)(pRC->GetWnd()))->GetSettings()->GetAsciiTextQuality();
			quality = peg(quality, 0, 2);

			float xEnlargement = 1 << quality, yEnlargement = 1 << quality;		// Blow up to get rid of jaggies
			int minAscent = minimumAscent * 1 << quality;
			float fontSize = GetFontStyle()->size.value;
			int iAscent = yEnlargement * fontSize;
			while(iAscent < minAscent)
			{
				xEnlargement++;	 yEnlargement++;
				iAscent = yEnlargement * fontSize;
			}

			hFont = CreateFont(iAscent);

		  	float xChar = 0, yChar = 0; 	  // current character position

			int fLeft = 0, fRight = 0, fTotalWidth = 0;
			for(int line = 0; line < pNode->string.num; line++)
			{
				float width = GetTextWidth(hFont, line) * xEnlargement;

				float x;
				switch(pNode->justification.value)
				{
					case QvAsciiText::LEFT:
						x = 0.;	
						break;
					case QvAsciiText::RIGHT:
						x = -width;
						break;
					case QvAsciiText::CENTER:
						x = -((width + 1) / 2);
						break;
				}
				fLeft = min(fLeft, x);
				fRight = max(fRight, x + width);
			}
			fTotalWidth = fRight - fLeft;

			int	iBmpWidth = int(fTotalWidth); 
			int	iBmpHeight = GetTextHeight() * yEnlargement;

			int w = 1, h = 1;

			while(w < iBmpWidth) w = w << 1;
			float xFactor =	float(w) / iBmpWidth;
			xEnlargement *= xFactor;
			iBmpWidth = w;

			while(h < iBmpHeight) h = h << 1;
			float yFactor =	float(h) / iBmpHeight;
			yEnlargement *= yFactor;
			iBmpHeight = h;

			fLeft *= xFactor;
			fRight *= xFactor;
			fTotalWidth *= xFactor;		  // Roughly

			float aspect = yFactor > .01 ? xFactor / yFactor : 1;

			DeleteObject(hFont);
			iAscent = yEnlargement * fontSize;
			hFont = CreateFont(iAscent, aspect);

			CDC dc;
			CBitmap bmp;
			bmp.CreateBitmap(iBmpWidth, iBmpHeight, 1, 1, 0);
			dc.CreateCompatibleDC(0);
			CBitmap *pOldBmp = dc.SelectObject(&bmp);
			CFont *pFont = CFont::FromHandle(hFont); 
			CFont *pOldFont = dc.SelectObject(pFont);

			RECT r = {0, 0, iBmpWidth, iBmpHeight};
			CBrush brush;
			brush.CreateStockObject(BLACK_BRUSH);
			dc.FillRect(&r, &brush); 
			dc.SetTextColor( RGB(0xff, 0xff, 0xff));
			dc.SetBkColor( RGB(0x0, 0x0, 0x0));
			dc.SetTextAlign( TA_TOP | TA_LEFT );

			int charWidths[256];
			dc.GetOutputCharWidth( 0, 255, charWidths );

			for(line = 0; line < pNode->string.num; line++)
			{
													// 'string' field is really QvMFString
				string text = pNode->string.values[line].getString();

				int numChars = text.GetLength();

				float width = GetTextWidth(hFont, line) * xEnlargement;
				if(!(pNode->width.num > line && pNode->width.values[line] > 0.0) )
				{
					width  /= aspect;	// very roughly
				}

				GxVec3f p;
				switch(pNode->justification.value)
				{
					case QvAsciiText::LEFT:
						 p.x() = 0.;	
						break;
					case QvAsciiText::RIGHT:
						p.x() = -width;
						break;
					case QvAsciiText::CENTER:
						p.x() = -width / 2;
						break;
				}
				p.y() = /*-GetBaselineOffset()*/ + line * pNode->spacing.value * fontSize;	// chars ought be on baseline 
				p.z() = 0;

				p.x() -= fLeft;
				p.y() *= yEnlargement;
				CSize cs = dc.GetOutputTextExtent( text, text.GetLength() );
				
				int * pWidths = 0;
				int widthWanted;
				if(pNode->width.num > line && pNode->width.values[line] > 0.0)
				{	
					 widthWanted =  int(pNode->width.values[line] * xEnlargement + .5);
				}
				else
				{
					 widthWanted =  iBmpWidth;
				} 
				pWidths = new int[numChars];
				int sum = 0;
				for(int ich = 0; ich < numChars; ich++)
				{
				 	pWidths[ich] = charWidths[text[ich]];
					sum += pWidths[ich];
				}

				float factor = float(widthWanted) / sum;	// how much to expand or contract the string

				if(pNode->width.num > line && pNode->width.values[line] > 0.0 || factor < 1.0)
				{
					int actual = 0;
					sum = 0;
					for(ich = 0; ich < numChars; ich++)
					{
						sum += pWidths[ich];
						int desired = int(factor * sum);
						pWidths[ich] = desired - actual;
						actual += pWidths[ich];
					}
				}
					//int nCharExtra = (float(widthWanted - cs.cx)) / (text.GetLength() - 1) + .5;
					//dc.SetTextCharacterExtra( nCharExtra );
				dc.ExtTextOut(int(p.x()), int(p.y()), 0, 0, text, text.GetLength(), pWidths);
				delete [] pWidths;
			}

			dc.SelectObject(pOldBmp);
			dc.SelectObject(pOldFont);

			//ChColor color(1., 0., 0.);
			#if (defined(CH_USE_RLAB))
			ChTexture *pTxt = new ChTexture(pRC, color, bmp);
			#else
			ChColor chromaKey((~(*(color.GetNative()))) && 0xffffff);
			ChTexture *pTxt = new ChTexture(pRC, color, bmp, &chromaKey);
			#endif
		
			GxVec3f verts[4], normals[2];
			verts[0].set(fLeft / xEnlargement, pNode->spacing.value * fontSize, 0);
			verts[1].set(fRight / xEnlargement, pNode->spacing.value * fontSize, 0);
			verts[2].set(fRight / xEnlargement, pNode->spacing.value * fontSize - GetTextHeight(), 0);
			verts[3].set(fLeft / xEnlargement, pNode->spacing.value * fontSize - GetTextHeight(), 0);

			// we need both front and back
			normals[0].set(0, 0, 1);
			normals[1].set(0, 0, -1);

			ChNrFaceData face_data[4 * 2 * 2 + 2 + 1];
			int ifd = 0;
			ChNrFaceArray facesAdded;
			int numFacesAdded;

			face_data[ifd++]	=	4;
			face_data[ifd++]	=	0;
			face_data[ifd++]	=	0;
			face_data[ifd++]	=	1;
			face_data[ifd++]	=	0;
			face_data[ifd++]	=	2;
			face_data[ifd++]	=	0;
			face_data[ifd++]	=	3;
			face_data[ifd++]	=	0;

			face_data[ifd++]	=	4;
			face_data[ifd++]	=	0;
			face_data[ifd++]	=	1;
			face_data[ifd++]	=	3;
			face_data[ifd++]	=	1;
			face_data[ifd++]	=	2;
			face_data[ifd++]	=	1;
			face_data[ifd++]	=	1;
			face_data[ifd++]	=	1;

			face_data[ifd++]	=	0;

			ChNrMeshAddFaces(	m_mesh, 
							4, 
							(ChNrVector*)verts, 
							2, 
							(ChNrVector*)normals, 
							face_data, 
							&numFacesAdded,
							&facesAdded);
		
			#if defined(CH_USE_D3D)
			numFacesAdded = facesAdded->GetSize();
			#endif

			#if defined(CH_USE_D3D)
			//ChColor chromaKey = pTxt->GetChromaKey();
			pTxt->GetHandle()->SetDecalTransparency(true);
			pTxt->GetHandle()->SetDecalTransparentColor(*(chromaKey.GetNative()));
			#endif
			ChNrMeshSetTexture( mesh, pTxt->GetHandle());
			D3DRelease(pTxt->GetHandle());

			if(numFacesAdded) boolFilled = true;

			unsigned int iface = 0;
			ChNrFace elt;
			int count = ChNrFaceGetVertexCount(GetElement(facesAdded,iface,elt));

			for(int k = 0; k < count; k++)
			{				
				int index = ChNrFaceGetVertexIndex(elt, k);
				float y = k < 2 ? 0 : 1;
				float x = (k == 0 || k == 3) ? 0 : 1; 
				ChNrMeshSetTextureCoordinates(mesh, index, x, y);
			}

			D3DRelease(elt);
			ChNrFree(facesAdded);							  
		}
		// end textured text
		 
		#else	// don't USE_TEXTURE_TEXT


				  // Do it with facets or wireframes
		ChNrMeshSetQuality(mesh,RenderWireframe);  

		// Decide how many normals to store; we need both front and back if not backculled
		int numNorms = 0;

		// Need to reserve space for vertices, normals, and faces - ?? but how much?


		int iAscent = 30;
		bool boolWireframe = true;

		hFont = CreateFont(iAscent);

		int xAdvance, yAdvance;

		ChQvAsciiTextMaterials materialMap( this);
		pRC->AdjustTransparency(materialMap);

		float fontSize = GetFontStyle()->size.value;

		for(int line = 0; line < pNode->string.num; line++)
		{
												// 'string' field is really QvMFString
			string text = pNode->string.values[line].getString();

			int numChars = text.GetLength();

			float width = GetTextWidth(hFont, line);

			GxVec3f p;
			switch(pNode->justification.value)
			{
				case QvAsciiText::LEFT:
					 p.x() = 0.;	
					break;
				case QvAsciiText::RIGHT:
					p.x() = -width;
					break;
				case QvAsciiText::CENTER:
					p.x() = -width / 2;
					break;
			}
			p.y() = /*-GetBaselineOffset()*/ - line * pNode->spacing.value * fontSize;	// chars ought be on baseline 
			p.z() = 0;
	  		float xChar = 0, yChar = 0; 	  // current character position
			for( int j = 0; j < numChars; j++ )
			{
				// Do a glyph
	  			unsigned int letter = text[j];
	  			ChPolyPolygonGx3 *pPoly;
				pPoly = CreateGlyphPolyPoly (hFont, letter, iAscent, xAdvance, yAdvance);
				if(pPoly && pPoly->GetPointCount())
				{
					boolFilled = true;
					// Convexify pPoly if not wireframe
					if (!boolWireframe) {
						// Replace pPoly with a convexified version of itself
						ChPolyPolygonGx3 *pPoly2 = pPoly->Convexify();
						delete pPoly;
						pPoly = pPoly2;
					}
					
					int numVertsTotal = pPoly->GetPointCount();
					int numFaces = pPoly->GetPolyCount();
					int face_data_size = numVertsTotal * 2 		// point indices; no normals - 2 is for backs
										+ numFaces * 2 				// face counts
										+ 1;					// terminator

					int * face_data = new int[face_data_size];

					GxVec3f *points 	= new GxVec3f[numVertsTotal];
					
					int vertIndex = 0;
					int ifd = 0;	// Index to Face Data
					
					for(int poly = 0; poly < pPoly->GetPolyCount(); poly++)
					{
						int nVerts = pPoly->GetPointCount(poly);
						if(nVerts)
						{	
							face_data[ifd]  = face_data[ifd + nVerts + 1] = nVerts; 
							ifd ++;

							for(int k = 0; k < nVerts; k++)
							{
								GxVec3f ip = pPoly->GetPoint(poly, k);
								points[vertIndex].x() = p.x() + xChar + float(ip.x()) / iAscent * fontSize;
								points[vertIndex].y() = p.y() + yChar + float(ip.y()) / iAscent * fontSize;
								points[vertIndex].z() = 0;
								face_data[ifd+k] = vertIndex;
								int reverseIndex = ifd + nVerts + nVerts - k;
								face_data[reverseIndex] = vertIndex;
								vertIndex++;
							}

							ifd += nVerts + nVerts + 1;
						}
					}
					face_data[ifd] = 0;

					ChNrFace *facesAdded;
					int numFacesAdded;
					ChNrMeshAddFaces(m_mesh,
							       numVertsTotal,
							       (ChNrVector*) points,
							       0,
							       (ChNrVector*) 0,
							       face_data,
							       &numFacesAdded,
							       &facesAdded);

					for(int j = 0; j < numFacesAdded; j ++)
					{
						materialMap.Set(m_mesh, facesAdded[j]);
					}

			 		ChNrFree(facesAdded);							  
					delete [] face_data; 
					delete [] points; 
				}

				delete pPoly;
			
				xChar += float(xAdvance) / iAscent * fontSize;
				yChar += float(yAdvance) / iAscent * fontSize;
	
			}
		}
		#endif
		if(!boolFilled)
		{
			ChNrFrame parent;
			ChNrFrameGetParent(m_frame, parent);
			ChNrFrameRemoveChild(parent, m_frame);
			m_frame = 0;
			m_mesh = 0;
		}
		DeleteObject(hFont);

		pIterator->DidAShape();
		pRC->UnlockScene();		
		pRC->UnlockQv();		   // Unlock tree 
	}
#endif
	return true;
}

bool ChQvAsciiTextInstance::Draw(ChRenderContext *pRC, ChDrawIterator *pIterator)
{
#if defined( CH_USE_3DR )
	{
		Fixed32_t On = 1;
		Fixed32_t Off = 0;
		static  PointF_t norm =		{ 0, 0, 1};
		G3dHandle_t hGC = pRC->GetGC();
		Dword_t  hRC = pRC->GetRC();
		QvAsciiText *pNode = (QvAsciiText *)GetNode();
		pRC->SetModelTransform(GetTransform());
		bool boolWireframe = 1;

		Fixed32_t oldShading;
	    G3dGetState( hGC, G3DL_FLAT_SHADING, &oldShading);
	    G3dSetState( hGC, G3DL_FLAT_SHADING, &On);
		Dword_t disabled = ( hRC, R3D_STA_DISABLES );
		Dword_t enabled = ( hRC, R3D_STA_ENABLES );
		R3dSetState( hRC, R3D_STA_ENABLES, R3D_SE_CLIPPING);  // I need them to clip for me too
															  // because I'm not pixel accurate

		pRC->SetShading(this);
	    R3dSetState( hRC, R3D_STA_DISABLES, R3D_SE_SHADING);

		Float_t		cull = 0;	   // never backcull text
		Fixed32_t wMattNum = 0;	  // always use material 0
		G3dSetMatt( hGC,  wMattNum, G3DM_BACK_CULL,	(Float_t *)&cull );
	
		// Check for cache
		bool boolFirst = false;
		if(!m_pCache)
		{
			boolFirst = true;
			m_pCache = new ChPtrList<ChAsciiCharCache>;
		}
		ChPosition pos = 0;
		if (!boolFirst)
		{
			pos = m_pCache->GetHeadPosition();	 // Initial position if reading cache
		}
	 
		bool boolUseTexture = SetupTexture(pRC);

		int iAscent = 20;	// LOD later

		// LOD computation
		// Base it on a 1 char square at the origin
		//iAscent = int(GetFontLODHeight(pRC));	 - we're caching instead now

		HFONT hFont = CreateFont(iAscent);
		// cache more intelligently later

		int xAdvance, yAdvance;

		Fixed32_t lCCW;
		G3dGetState( hGC, G3DL_FRONT_CCW, &lCCW);
		G3dSetState( hGC, G3DL_FRONT_CCW, &On);

		bool boolPureEmissive;
		ChQvAsciiTextMaterials materialMap( this);
		materialMap.Set(hRC, hGC, &boolPureEmissive);

		ColorFA_t color, diff, emissive;
		G3dGetMatt(hGC, 0, G3DM_DIFFUSE, (float*)&diff);
		G3dGetMatt(hGC, 0, G3DM_EMIT, (float*)&emissive);
		ColorFA_t black = {0.,0., 0., 0.};

		// We're using prelit colors
		// Bogus em up by assuming a light value of  white .5
		// ignoring specular and Lambertian effects
		// Conversely, you could assume light = 1 and cos(theta) = .5 for diffuse
		// These are so dinky nobody's gonna notice
		//color.r = diff.r / 2 + emissive.r;
		//color.g = diff.g / 2 + emissive.g;
		//color.b = diff.b / 2 + emissive.b;
		color.r = max(diff.r, emissive.r);
		color.g = max(diff.g, emissive.g);
		color.b = max(diff.b, emissive.b);
		color.a = 1.0;
		unsigned long r, g, b, val;
		G3dSetMatt(hGC, 0, G3DM_EMIT, (float*)&color);
		G3dSetMatt(hGC, 0, G3DM_DIFFUSE, (float*)&black);
		G3dSetMatt(hGC, 0, G3DM_BACK_EMIT, (float*)&color);
		G3dSetMatt(hGC, 0, G3DM_BACK_DIFFUSE, (float*)&black);

		r = long( color.r * 255.0 );
		g = long( color.g * 255.0 );
		b = long( color.b * 255.0 );
		val = r | (g << 8) | (b << 16) | 0xff000000;

		R3dSetState( hRC, R3D_STA_FG_COLOR, val); 


		pRC->SetModulation( boolUseTexture, boolPureEmissive);  // 
		float fontSize = GetFontStyle()->size.value;

		for(int line = 0; line < pNode->string.num; line++)
		{
												// 'string' field is really QvMFString
			string text = pNode->string.values[line].getString();

			int numChars = text.GetLength();


			float width = GetTextWidth(hFont, line);
			ColorFA_t purple = {.8, 0., .8, 1.};

			PointF_t p;
			switch(pNode->justification.value)
			{
				case QvAsciiText::LEFT:
					 p.x = 0.;	
					break;
				case QvAsciiText::RIGHT:
					p.x = -width;
					break;
				case QvAsciiText::CENTER:
					p.x = -width / 2;
					break;
			}
			p.y = /*-GetBaselineOffset()*/ - line * pNode->spacing.value * fontSize;	// chars ought be on baseline 
			p.z = 0;
	  		float xChar = 0, yChar = 0; 	  // current character position
			for( int j = 0; j < numChars; j++ )
			{
	  			unsigned int letter = text[j];
	  			ChPolyPolygonGx3 *pPoly;
				if(boolFirst)
				{
					pPoly = CreateGlyphPolyPoly (hFont, letter, iAscent, xAdvance, yAdvance);
					ChAsciiCharCache *pCache = new ChAsciiCharCache(pPoly, letter, xAdvance, yAdvance);
					m_pCache->AddTail(pCache);
				}
				else
				{
					// Get from cache
					ChAsciiCharCache *pCharCache = m_pCache->GetNext(pos);
					pPoly = pCharCache->m_pPoly;
					xAdvance = pCharCache->m_xAdvance;
					yAdvance = pCharCache->m_yAdvance;
				}
				if(pPoly)
				{
					// Convexify pPoly if not wireframe
					if (!boolWireframe) {
						// Replace pPoly with a convexified version of itself
						ChPolyPolygonGx3 *pPoly2 = pPoly->Convexify();
						delete pPoly;
						pPoly = pPoly2;
					}
					for(int poly = 0; poly < pPoly->GetPolyCount(); poly++)
					{
						int nVerts = pPoly->GetPointCount(poly);
						if(nVerts)
						{	
							PointF_t *points 	= new PointF_t[nVerts];
							PointF_t *normals 	= new PointF_t[nVerts];
							#if 0	
							PointF_t *textures 	= new PointF_t[nVerts];
							ColorFA_t *colors 	= new ColorFA_t[nVerts];;
							#endif

							for(int k = 0; k < nVerts; k++)
							{
								GxVec3f ip = pPoly->GetPoint(poly, k);
								points[k].x = p.x + xChar + float(ip.x()) / iAscent * fontSize;
								points[k].y = p.y + yChar + float(ip.y()) / iAscent * fontSize;
								points[k].z = 0;
								normals[k] = norm;
							#if 0	
								colors[k] = color;
								textures[k].x = float(ip.x) / iAscent;
								textures[k].y = float(ip.y) / iAscent;
								textures[k].z = 0.;
							#endif
							}

							if(boolWireframe)
							{
								        G3dSetState( hGC, G3DL_FLAT_SHADING, &On);

								try
								{

								#if 0
									for(int k = 0; k < nVerts - 1; k++)
									{
										G3dPrimitiveF(hGC, G3D_PRM_POLYLINE, 2,
													points + k, sizeof(PointF_t), 
													&norm, sizeof(PointF_t), 
													//0, sizeof(PointF_t), 
													0, sizeof(PointF_t), 
													0, sizeof(ColorFA_t) );

									}
								#else
									G3dPrimitiveF(hGC, G3D_PRM_POLYLINE, nVerts,
												points, sizeof(PointF_t), 
												normals, sizeof(PointF_t), 
												//0, sizeof(PointF_t), 
												0, sizeof(PointF_t), 
												0, sizeof(ColorFA_t) );
								#endif
								}
								catch (...)
								{
									//TRACE("Exception in drawing text polyline caught\r\n");
								}
								        G3dSetState( hGC, G3DL_FLAT_SHADING, &Off);
							}
							else
							{
								#if 0
								// Triangulate here
								try
								{
									G3dPrimitiveF(hGC, G3D_PRM_POLYGON, nVerts,
												points, sizeof(PointF_t), 
												normals, sizeof(PointF_t), 
												textures, sizeof(PointF_t), 
												colors, sizeof(ColorFA_t) );
								}
								catch (...)
								{
									//TRACE("Exception in drawing text polygon caught\r\n");
								}
								#endif
							}
							delete [] points; 
							delete [] normals; 
							#if 0
							delete [] textures;
							delete [] colors;
							#endif
						}
					}
				}
				#if 0
				#endif
				//delete pPoly;	  // cached now
			
				xChar += float(xAdvance) / iAscent * fontSize;
				yChar += float(yAdvance) / iAscent * fontSize;
	
			}
		}
		
		DeleteObject(hFont);
		G3dSetState( hGC, G3DL_FRONT_CCW, &lCCW);
		{
			pRC->SetTexture(0);							// turn off texture
		}
		R3dSetState( hRC, R3D_STA_DISABLES, disabled ); 
		R3dSetState( hRC, R3D_STA_ENABLES, enabled);
	    G3dSetState( hGC, G3DL_FLAT_SHADING, &oldShading);
	}
#else
#endif
	return true;
}

HFONT ChQvAsciiTextInstance::CreateFont(int iAscent, float aspect)		// very Windows-y
{	
	HFONT	hMyFont;
	LOGFONT lf;

	GetObject(GetStockObject(SYSTEM_FONT), sizeof(lf), &lf);
	lf.lfHeight = iAscent;
	lf.lfWidth = 0;
	switch(GetFontStyle()->family.value)
	{
		case QvFontStyle::SERIF:
		{
			strcpy(lf.lfFaceName, "Times New Roman");
			break;
		}
		case QvFontStyle::TYPEWRITER:
		{
			strcpy(lf.lfFaceName, "Courier New");
			break;
		}
		default:	// QvFontStyle::SANS or whatever
		{
			strcpy(lf.lfFaceName, "Arial");
			break;
		}
	}
	if(GetFontStyle()->style.value	& QvFontStyle::BOLD)
	{
		lf.lfWeight = 700; 
	}
	if(GetFontStyle()->style.value	& QvFontStyle::ITALIC)
	{
		lf.lfItalic = true;
	}
	hMyFont = CreateFontIndirect(&lf);

	if(aspect != 0.0)
	{
		// Tweak the aspect ratio to fit our mutated shape
		TEXTMETRIC tm;
		CDC dc;
		dc.CreateCompatibleDC(0);
		CFont *pOldFont = dc.SelectObject(CFont::FromHandle(hMyFont));
		dc.GetTextMetrics(&tm);
		dc.SelectObject(pOldFont);

		lf.lfWidth = int(tm.tmAveCharWidth * aspect);

		DeleteObject(hMyFont);
		hMyFont = CreateFontIndirect(&lf);

	}

	return hMyFont;
}
