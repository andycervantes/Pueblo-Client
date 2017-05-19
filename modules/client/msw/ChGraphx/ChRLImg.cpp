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

	Implementation of the ChRLImage class for  Render Morphics

----------------------------------------------------------------------------*/

// $Header: 

#include "grheader.h"


#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

#include "ChMazDep.h"
#include "ChRLImg.h"

//#define CH_ALWAYS_USE_24_BIT_TEXTURES	1

/*----------------------------------------------------------------------------
	ChRLImage class	-- a wrapper for RenderMorphics version of RLImage
----------------------------------------------------------------------------*/
ChRLImage::ChRLImage( bool boolScale, chuint uOption ) 
			: 	m_boolChroma(false),
				m_boolScale( boolScale ),
				m_uOption( uOption ),
			  	m_pDestroyCallback( 0 ),
			  	m_pDestroyData( 0 ),
				m_iUseCount( 1 ),
				m_pDibImage( 0 ),
				m_iChromaIndex( -1 )
{
	ChMemClearStruct( &m_rlImg );
}

ChRLImage::ChRLImage( ChDib* pDib, bool boolScale, 
			chuint uOption, chuint32 luChromaKey /*= 0 */ ) 
			: 	m_boolChroma(false),
				m_boolScale( boolScale ),
				m_uOption( uOption ),
			  	m_pDestroyCallback( 0 ),
			  	m_pDestroyData( 0 ),
				m_iUseCount( 1 ),
				m_pDibImage( 0 ),
				m_iChromaIndex( -1 )
{
	ConvertDib2RL( pDib, boolScale, 
					uOption, luChromaKey);
}
												// tile img onto new one
ChRLImage::ChRLImage( const ChRLImage &img, int width, int height ) 
					: m_boolChroma(false),
					m_boolScale( false ),
					m_uOption( 0 ),
				  	m_pDestroyCallback( 0 ),
				  	m_pDestroyData( 0 ),
					m_pDibImage( 0 ),
					m_iChromaIndex( -1 )

{
	// To start we have a use count of 1
	m_iUseCount = 1;
	
	m_rlImg =  img.m_rlImg;

	// Adjust the size
	m_rlImg.height = height;
	m_rlImg.width = width;
	int iDepth = img.m_rlImg.depth / 8;
	m_rlImg.bytes_per_line = m_rlImg.width * iDepth;

	// Copy the palette if any
	if ( img.m_rlImg.palette )
	{
	    m_rlImg.palette = new ChNrPaletteEntry[m_rlImg.palette_size];
		memcpy(m_rlImg.palette, img.m_rlImg.palette, sizeof(ChNrPaletteEntry) * m_rlImg.palette_size);
	}
	 
	// Tile the bits, starting at top left
	int srcRow = 0;
	m_rlImg.buffer1 = new BYTE[m_rlImg.bytes_per_line * height];

	LPBYTE pBuffer = (LPBYTE)m_rlImg.buffer1;
	int bytesPerCopy = img.m_rlImg.width * iDepth;		// NOT bytes per line, there may be trailing junk

	for(int dstRow = 0; dstRow < height; dstRow++)				  //m_rlImg.bytes_per_line
	{
		if(srcRow >= img.m_rlImg.height) srcRow = 0;
		LPBYTE pSrcBuffer = (LPBYTE)img.m_rlImg.buffer1 + img.m_rlImg.bytes_per_line * srcRow;
		int bytesCopied = 0;
		LPBYTE pDst = pBuffer + dstRow * m_rlImg.bytes_per_line;
		while(bytesCopied < m_rlImg.bytes_per_line)
		{
			int bytesToCopy = bytesPerCopy;
			if(bytesPerCopy + bytesCopied > m_rlImg.bytes_per_line) 
			{
				bytesToCopy = m_rlImg.bytes_per_line - bytesCopied;
			} 
			memcpy(pDst, pSrcBuffer, bytesToCopy);
			bytesCopied += bytesToCopy;
			pDst += bytesToCopy;
		}
		srcRow++;
	}
}

ChRLImage::~ChRLImage()
{
	ASSERT( m_iUseCount == 0 );
	// do the cleanup
	if ( m_rlImg.palette ) delete [] m_rlImg.palette;
	m_rlImg.palette = 0;
	if ( m_rlImg.buffer1 ) delete [] m_rlImg.buffer1;
	m_rlImg.buffer1 = 0;

	delete m_pDibImage;
}


void ChRLImage::Release()
{
	ASSERT( m_iUseCount > 0 );

	m_iUseCount--;

	if ( 0 == m_iUseCount )
	{
		if ( m_pDestroyCallback )
		{
			m_pDestroyCallback( m_pDestroyData, this );
		}
		delete this;
	}
}

bool ChRLImage::NewImage( pChImageInfo pImage )
{
	m_imgInfo = *pImage;
	return true;
}

bool ChRLImage::Create( int iFrame, BITMAPINFO* pBMI, BYTE* pBits) // Create from existing mem
{
	ASSERT( false );
	return false;
}


bool ChRLImage::Create( pChImageFrameInfo pFrameInfo, int iBitCount /*= 8 */)
{	 
	if ( pFrameInfo->iFrame != 0 )
	{ // we handle only one frame now
		return false;
	}

	int 	iWidth = pFrameInfo->iWidth, 
			iHeight = pFrameInfo->iHeight;

	ComputeSize( pFrameInfo->iWidth, pFrameInfo->iHeight, 
				m_boolScale, m_uOption, iWidth, iHeight );



	if ( //pFrameInfo->luAttrs & ChImageConsumer::imgTransparent || 
			iWidth != pFrameInfo->iWidth || iHeight != pFrameInfo->iHeight )
	{	// we need to scale, it is easier to convert image to dib and then back to RL 
		// in this case
		TRACE( "ChRLImage::Severe performance loss : Using non-power of 2 textures\n" );
		if ( 0 == m_pDibImage )
		{
			m_pDibImage = new ChDib;
			ASSERT( m_pDibImage );
		}
		m_pDibImage->NewImage( &m_imgInfo );
		m_rlImg.width = pFrameInfo->iWidth; 
		m_rlImg.height = pFrameInfo->iHeight;

	}

	
	if ( m_pDibImage )
	{
	 	if ( m_pDibImage->Create( pFrameInfo->iFrame, pFrameInfo->iWidth, 
	 							pFrameInfo->iHeight, iBitCount ) )
		{

			if ( pFrameInfo->luAttrs & ChImageConsumer::imgTransparent )
			{
				// Transparency makes us use 24bits + alpha
				m_chromaKey = pFrameInfo->colorTransparent & 0xffffff;
				m_boolChroma = true;
				m_uOption |= ChMazeTextureHTTPReq::textureChromaKey;
			}

		 	return true;
		}
	}
	else
	{
		int		iDepth = 3;		// in bytes
		#if !defined(CH_ALWAYS_USE_24_BIT_TEXTURES)
		if( iBitCount == 8) iDepth = 1;
		#endif
		bool	boolAlpha = false;

		if ( pFrameInfo->luAttrs & ChImageConsumer::imgTransparent )
		{
			// Transparency makes us use 24bits + alpha
			iDepth = 4;		// 24 bits and add an alpha
			boolAlpha = true;
			m_chromaKey = pFrameInfo->colorTransparent & 0xffffff;
			m_iChromaIndex = pFrameInfo->iTransparentIndex;
			m_boolChroma = true;
		}

		// Create the RLImage now
		m_rlImg.width = iWidth; 
		m_rlImg.height = iHeight;
		m_rlImg.aspectx = 2;
		m_rlImg.aspecty = 1;
		// bits/pixel
		m_rlImg.depth	= 8 * iDepth; // we keep it as either 8 or 24 bit + maybe an alpha
		// storage width
		m_rlImg.bytes_per_line = m_rlImg.width * iDepth;
		if(m_rlImg.bytes_per_line & 3)
		{
			m_rlImg.bytes_per_line += 4;
			m_rlImg.bytes_per_line &= ~3;
		}

		if(boolAlpha)
		{
			m_rlImg.alpha_mask 	= 0xFF000000;
		}
		else
		{
			m_rlImg.alpha_mask 	= 0;
		}

		// Make an 8 bit paletted RLImage
		if ( 8 == m_rlImg.depth )
		{
			m_rlImg.rgb 			= 0;

		    m_rlImg.red_mask		= 0xFF; 
		    m_rlImg.green_mask		= 0xFF;   
		    m_rlImg.blue_mask		= 0xFF;
			
			m_rlImg.alpha_mask 		= 0xFF;
		}
		else
		{
			m_rlImg.rgb = true;	

			m_rlImg.red_mask 	= 0xFF0000;
			m_rlImg.green_mask 	= 0xFF00;
			m_rlImg.blue_mask 	= 0xFF;
		}

		m_rlImg.palette_size 	= 0;
		m_rlImg.palette 		= 0;


		m_rlImg.buffer1 = new BYTE[ m_rlImg.bytes_per_line * m_rlImg.height]; 
		ASSERT( m_rlImg.buffer1 );
		m_rlImg.buffer2 = 0;
		
		return true;
	}

	return false;
}

bool ChRLImage::SetColorTable( int iFrame, RGBQUAD* pColorTbl, int iColors ) 
{
	ASSERT( iFrame == 0  );

	if ( m_pDibImage )
	{
		m_pDibImage->SetColorTable( iFrame, pColorTbl, iColors );
	}
	else
	{

	    m_rlImg.palette_size 	= 256;
	    m_rlImg.palette 		= new ChNrPaletteEntry[m_rlImg.palette_size];

		// Copy the palette
		for(int j = 0; j < iColors && j < m_rlImg.palette_size; j++)
		{
			m_rlImg.palette[j].blue 	= pColorTbl[ j ].rgbBlue;  		
			m_rlImg.palette[j].green 	= pColorTbl[ j ].rgbGreen; 	
			m_rlImg.palette[j].red 		= pColorTbl[ j ].rgbRed;   
			m_rlImg.palette[j].flags = ChNrPaletteReadOnly;
		}
			
		for( j = iColors; j < 256; j++)
		{
			m_rlImg.palette[j].flags = ChNrPaletteFree;   // unuse the  entry
		}
	}

	return true;
} 

bool ChRLImage::SetScanLine( int iFrame, int iScanLine, 
					BYTE* pPixels, int iBufferLength, int iFormat )
{
	ASSERT( iFrame == 0  );

	if ( m_pDibImage )
	{
		m_pDibImage->SetScanLine( iFrame, iScanLine, 
						pPixels, iBufferLength, iFormat );

		// if this is the last scan line then convert the dib to rl and free the 
		// dib
		if ( m_pDibImage && iScanLine == m_rlImg.height - 1 )
		{ // convert the image to RL now

			ConvertDib2RL( m_pDibImage, m_boolScale, m_uOption, m_chromaKey );
			delete m_pDibImage;
			m_pDibImage = 0; 
		}
	}
	else
	{
		LPBYTE pBuffer = (LPBYTE)m_rlImg.buffer1;
		// Move the pointer to the current scan line
		pBuffer += ( m_rlImg.bytes_per_line * iScanLine );

		if ( format8Bit == iFormat )
		{

			if ( m_rlImg.depth == 8  )
			{
				int bytesToCopy = min(iBufferLength, m_rlImg.bytes_per_line); 
				ChMemCopy( pBuffer, pPixels,  bytesToCopy );
			}
			else if ( m_rlImg.depth == 32 || m_rlImg.depth == 24 )
			{
			
				LPBYTE 		pSrc;
				pSrc = pPixels; 
	            int iCount = min(iBufferLength, m_rlImg.width);    // Number of pixels to scan.

	            while (iCount--) 
	            {
					*pBuffer++ = m_rlImg.palette[ *pSrc ].blue;
					*pBuffer++ = m_rlImg.palette[ *pSrc ].green;
					*pBuffer++ = m_rlImg.palette[ *pSrc ].red;
					if(m_rlImg.depth == 32)
					{
						BYTE	alpha = 0xff;
							// Depending on matching byte orders here
						if( (BYTE)m_iChromaIndex == (*pSrc) )
						{
							alpha = 0x0;
						}
						*pBuffer++ = alpha;
					}
					++pSrc;
	            }

				if ( iScanLine == m_rlImg.height - 1 )
				{
					delete [] m_rlImg.palette;
					m_rlImg.palette = 0;
					m_rlImg.palette_size = 0;
				}

			}
			else
			{
				TRACE( "ChRLImage : Invalid format\n" );
				ASSERT( false );
			}
		}
		else if( format24RGB == iFormat )
		{
			int bytesToCopy = min(iBufferLength, m_rlImg.bytes_per_line); 
			ChMemCopy( pBuffer, pPixels,  bytesToCopy );
		}
		else if( format24BGR == iFormat )
		{
			int bytesToCopy = min(iBufferLength, m_rlImg.bytes_per_line); 
			for (int col = bytesToCopy; col > 0; col--) 
			{
				*pBuffer++ = pPixels[2];	
				*pBuffer++ = pPixels[1];
				*pBuffer++ = pPixels[0];
				pPixels += 3;
			}
		}


	}


	return true;
}



ChRLImage::ConvertDib2RL( ChDib* pDib, bool boolScale, 
			chuint uOption, chuint32 luChromaKey /*= 0 */)
{
	// To start we have a use count of 1
	m_iUseCount = 1;

	// Create a RLImage from a ChDib

	// See if it's chromakey transparent, and how deep it is
	int		iDepth = 3;		// in bytes
	#if !defined(CH_ALWAYS_USE_24_BIT_TEXTURES)
	if(pDib->GetBitmapInfoAddress()->bmiHeader.biBitCount == 8) iDepth = 1;
	#endif
	bool	boolAlpha = false;
	if(uOption & ChMazeTextureHTTPReq::textureChromaKey)
	{
		// Transparency makes us use 24bits + alpha
		iDepth = 4;		// 24 bits and add an alpha
		boolAlpha = true;
		luChromaKey &= 0xffffff;	// ignore high byte - alpha or flags
		m_chromaKey = luChromaKey;
		m_boolChroma = true;
	}

	ComputeSize( pDib->GetWidth(), pDib->GetHeight(), 
			boolScale, uOption, m_rlImg.width, m_rlImg.height );


	// shrink or expand if required
	if ( m_rlImg.width != pDib->GetWidth() || m_rlImg.height != pDib->GetHeight())
	{
		// size the DIB
		pDib->SetSize( m_rlImg.width, m_rlImg.height );
	}

	// Create the RLImage now
	m_rlImg.aspectx = 2;
	m_rlImg.aspecty = 1;
	// bits/pixel
	m_rlImg.depth	= 8 * iDepth; // we keep it as either 8 or 24 bit + maybe an alpha
	// storage width
	//	m_rlImg.bytes_per_line = (((m_rlImg.width * 3) + 3) & ~3);
	m_rlImg.bytes_per_line = m_rlImg.width * iDepth;
	if(m_rlImg.bytes_per_line & 3)
	{
		m_rlImg.bytes_per_line += 4;
		m_rlImg.bytes_per_line &= ~3;
	}

	if(boolAlpha)
	{
		m_rlImg.alpha_mask 	= 0xFF000000;
	}
	else
	{
		m_rlImg.alpha_mask 	= 0;
	}

	m_rlImg.rgb = true;	

	m_rlImg.red_mask 	= 0xFF0000;
	m_rlImg.green_mask 	= 0xFF00;
	m_rlImg.blue_mask 	= 0xFF;

	m_rlImg.palette_size 	= 0;
	m_rlImg.palette 		= 0;


	m_rlImg.buffer1 = new BYTE[ m_rlImg.bytes_per_line * m_rlImg.height]; 
	ASSERT( m_rlImg.buffer1 );
	m_rlImg.buffer2 = 0;

	// copy the bits
	LPBYTE pBuffer = (LPBYTE)m_rlImg.buffer1;
	LPBYTE pBits   = (LPBYTE)pDib->GetBitsAddress();

	if ( pDib->GetBitmapInfoAddress()->bmiHeader.biBitCount == 8 )
	{
		int  		iDibStorageWidth =  ( (m_rlImg.width + 3) & ~3 );
        int 		iDinc = m_rlImg.bytes_per_line - ( m_rlImg.width * iDepth); // Destination increment value
        int 		iCount;
		LPBYTE 		pSrc;
		RGBQUAD*	pRgbQuad = pDib->GetClrTabAddress( 0 );

		// Dib is stored bottom up
		pBits += ( m_rlImg.height - 1 ) * iDibStorageWidth;

		if(iDepth > 1)
		{
			// Use an RGBA RLImage
			for( int i = 0; i < m_rlImg.height; i++ )
	        {
				pSrc = pBits; 
	            iCount = m_rlImg.width;    // Number of pixels to scan.
	            while (iCount--) 
	            {
					*pBuffer++ = pRgbQuad[ *pSrc ].rgbBlue;
					*pBuffer++ = pRgbQuad[ *pSrc ].rgbGreen;
					*pBuffer++ = pRgbQuad[ *pSrc ].rgbRed;
					if(boolAlpha)
					{
						BYTE	alpha = 0xff;
							// Depending on matching byte orders here
						if(((*((chuint*)(pRgbQuad + *pSrc))) & 0xffffff) == luChromaKey)
						{
							alpha = 0x0;
						}
						*pBuffer++ = alpha;
					}
					++pSrc;
	            }
	            // Move on to the next line.
				pBits   -=   iDibStorageWidth;   // Dib is stored bottom up
	            pBuffer += iDinc;
	        }
		}
		else
		{
			// Make an 8 bit paletted RLImage
		    m_rlImg.red_mask		= 0xFF; 
		    m_rlImg.green_mask		= 0xFF;   
		    m_rlImg.blue_mask		= 0xFF;
			m_rlImg.alpha_mask 		= 0xFF;
		    m_rlImg.palette_size 	= 256;
		    m_rlImg.palette 		= new ChNrPaletteEntry[m_rlImg.palette_size];
			m_rlImg.rgb 			= 0;
			int iEntries = pDib->GetNumClrEntries();
			// Copy the palette
			for(int j = 0; j < iEntries; j ++)
			{
				m_rlImg.palette[j].blue 	= pRgbQuad[ j ].rgbBlue;  		
				m_rlImg.palette[j].green 	= pRgbQuad[ j ].rgbGreen; 	
				m_rlImg.palette[j].red 		= pRgbQuad[ j ].rgbRed;   
				m_rlImg.palette[j].flags = ChNrPaletteReadOnly;
				
			}
			for( j = iEntries; j < 256; j ++)
			{
				m_rlImg.palette[j].flags = ChNrPaletteFree;   // unuse the  entry
			}
			// Now copy the bytes, literally
			int bytesToCopy = min(iDibStorageWidth, m_rlImg.bytes_per_line); 
			for( int i = 0; i < m_rlImg.height; i++ )
			{
				ChMemCopy( pBuffer, pBits,  bytesToCopy );
				// Next scan line, move down
				pBuffer +=  m_rlImg.bytes_per_line;
				// Next scan line, move up
				pBits   -=   iDibStorageWidth;   // Dib is stored bottom up
			}
		}
	}
	else  if ( pDib->GetBitmapInfoAddress()->bmiHeader.biBitCount == 24 )
	{
		// PRITHAM: alpha channel for chromakey not done for bottom up
		// But right now we don't support any like that do we?
		// I think this only applies to PNG (jwd) right?
		#pragma message("Not handling bottom up chromakey 24 bit dibs")
		// Dib is stored bottom up
		pBits += ( m_rlImg.height - 1 ) * m_rlImg.bytes_per_line;

		for( int i = 0; i < m_rlImg.height; i++ )
		{
			ChMemCopy( pBuffer, pBits,  m_rlImg.bytes_per_line );
			// Next scan line, move down
			pBuffer +=  m_rlImg.bytes_per_line;
			// Next scan line, move up
			pBits   -=   m_rlImg.bytes_per_line;   // Dib is stored bottom up
		}
	}
	else  if ( pDib->GetBitmapInfoAddress()->bmiHeader.biBitCount == 4 )
	{
		int  		iDibStorageWidth =  ( ( ( m_rlImg.width >> 1 ) + 3) & ~3 );
        int 		iDinc = m_rlImg.bytes_per_line - ( m_rlImg.width * iDepth); // Destination increment value
        int 		iCount;
		LPBYTE 		pSrc;
		RGBQUAD*	pRgbQuad = pDib->GetClrTabAddress( 0 );

		// Dib is stored bottom up
		pBits += ( m_rlImg.height - 1 ) * iDibStorageWidth;


		for( int i = 0; i < m_rlImg.height; i++ )
        {
			pSrc = pBits; 
            iCount = m_rlImg.width;    // Number of pixels to scan.
            while ( iCount-- ) 
            {
				BYTE bIndex1 = (((*pSrc) >> 4) & 0x0F);
				BYTE bIndex2 = ( (*pSrc) & 0x0F );
	
				*pBuffer++ = pRgbQuad[ bIndex1 ].rgbBlue;
				*pBuffer++ = pRgbQuad[ bIndex1 ].rgbGreen;
				*pBuffer++ = pRgbQuad[ bIndex1 ].rgbRed;
	
				if ( iCount--)
				{
					*pBuffer++ = pRgbQuad[ bIndex2 ].rgbBlue;
					*pBuffer++ = pRgbQuad[ bIndex2 ].rgbGreen;
					*pBuffer++ = pRgbQuad[ bIndex2 ].rgbRed;
				}

				++pSrc;
            }
            // Move on to the next line.
			pBits   -=   iDibStorageWidth;   // Dib is stored bottom up
            pBuffer += iDinc;
        }
	}

	return true;
}


void ChRLImage::ComputeSize( int iOldWidth, int iOldHeight,
			 bool& boolScale, chuint uOption, int &iWidth, int& iHeight )
{
	if(uOption & ChMazeTextureHTTPReq::textureKeepSize)
	{
		boolScale = false;	// incompatible!
		iWidth = iOldWidth;
		iHeight = iOldHeight;
	}
	else
	{
		iWidth = 1;
		iHeight = 1;

		// power of 2
		while( (iWidth * 2) <= iOldWidth )
		{
			iWidth *= 2;
		}
		while( (iHeight * 2) <= iOldHeight )
		{
			iHeight *= 2;
		}

		if ( boolScale )
		{ // Limit to 128
			if ( iWidth > 128 )
			{
				iWidth = 128;
			}
			if ( iHeight > 128 )
			{
				iHeight = 128;
			}

		}
		else
		{	
			if ( uOption & ChMazeTextureHTTPReq::textureAutoSize )
			{  // auto will always increase the size if it is less than 256
				if ( iWidth != iOldWidth 
									&& (iWidth * 2) <= 256 )
				{
					iWidth *= 2;
				}

				if ( iHeight != iOldHeight 
									&& (iHeight * 2) <= 256  )
				{
					iHeight *= 2;
				}
			}
			else if ( uOption & ChMazeTextureHTTPReq::textureExpand )
			{
				if ( iWidth != iOldWidth )
				{
					iWidth *= 2;
				}

				if ( iHeight != iOldHeight )
				{
					iHeight *= 2;
				}
			}
		}
	}
	iWidth = max(iWidth, 4);				   	// RL barfs on 2x2 
	iHeight = max(iHeight, 4);				// do this even for keepSize??

}

#endif // defined(CH_USE_RLAB)
