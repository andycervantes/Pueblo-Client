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

	Interface for the ChRLImage class for  Render Morphics

----------------------------------------------------------------------------*/

// $Header: 

#if !defined( ChRLImage_h )
#define ChRLImage_h

#if defined( CH_USE_RLAB ) || defined(CH_USE_D3D)
#include "ChGrRend.h"

#include <ChImgConsumer.h>

typedef ChNrImage FAR*	pRLImage;

class ChDib;

class ChRLImage;
typedef ChRLImage* pChRLImage;

CH_TYPEDEF_CALLBACK( void, pChRLImageDestroy ) 
	( void* pData, ChRLImage* pImage);



/*----------------------------------------------------------------------------
	ChRLImage class	-- a wrapper for Render morphics version of RLImage
----------------------------------------------------------------------------*/

class ChRLImage : public ChImageConsumer
{
	public :
									// pDib      = Dib to convert
									// boolLimit = true then texture is limited to max of 128x128
									// uOption = ChMazeTextureHTTPReq::textureExpand or
									// 			 ChMazeTextureHTTPReq::textureShrink or
									// 			 ChMazeTextureHTTPReq::textureKeepSize or
									// 			can be ORed with
									// 			 ChMazeTextureHTTPReq::textureChromaKey
									// luChromaKey - use if textureChromaKey is set - used
									//				to set the alpha channel
		ChRLImage( bool boolLimit, chuint uOption );
		ChRLImage( ChDib* pDib, bool boolLimit, chuint uOption, chuint32 luChromaKey = 0 );
												// tile img onto new one
		ChRLImage( const ChRLImage &img, int width, int height );	   
					
		// Overidable methods of ChImageConsumer
		virtual bool NewImage( pChImageInfo pImage );
	    virtual bool Create( int iFrame, BITMAPINFO* pBMI, BYTE* pBits); // Create from existing mem
		virtual bool Create( pChImageFrameInfo pFrameInfo, int iBitCount = 8 );
		virtual bool SetColorTable( int iFrame, RGBQUAD* pColorTbl, int iSize );
		virtual bool SetScanLine( int iFrame, int iScanLine, 
						BYTE* pBits, int iBufferLength, int iFormat );

		inline void Use()					{  m_iUseCount++; }
		void Release();

		operator pRLImage() const
			{ 
				return (pRLImage)&m_rlImg; 
			}
		  
		bool IsChromaKey() { return m_boolChroma; };
		ChColor GetChromaKey() { return m_chromaKey; };
		void SetDestroyCallback( pChRLImageDestroy pCallback, void* pData)
					{
						m_pDestroyCallback = pCallback;
						m_pDestroyData = pData;
					}

	private :
		ChNrImage			m_rlImg;

		bool				m_boolScale;
		bool				m_boolChroma;
		COLORREF			m_chromaKey;
		int					m_iChromaIndex;
		pChRLImageDestroy	m_pDestroyCallback;
		void*				m_pDestroyData;
		chuint				m_uOption;
		ChDib*				m_pDibImage;
		ChImageInfo			m_imgInfo;
	protected: 
		virtual ~ChRLImage();

		ConvertDib2RL( ChDib* pDib, bool boolLimit, chuint uOption, chuint32 luChromaKey = 0 );


	private :
		int			m_iUseCount;

	protected:
		static void ComputeSize( int iOldWidth, int iOldHeight, 
						bool& boolScale, chuint uOption, int &iWidth, int& iHeight );

};

#endif // defined(CH_USE_RLAB)

#endif // !defined ( ChRLImage_h )

