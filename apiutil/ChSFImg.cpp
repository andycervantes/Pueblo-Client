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

	Chaco SFImage decoder

----------------------------------------------------------------------------*/


#include "headers.h"

#include <ChTypes.h>

#include <ChSFImg.h>

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA    
#endif

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif							    

  
/////////////////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL( ChSFImage, ChDib, 0 /* Schema number */ )

ChSFImage::ChSFImage() : ChDib()
{
}

ChSFImage::~ChSFImage() 
{
	
}

BOOL ChSFImage::Load( const char * pszFileName, chuint32 flOptions /* = ChDIB::loadAuto */ )
{
	TRACE( "SFImage should be created from a memory image\n" );
	ASSERT( false );
	return false;
}

BOOL ChSFImage::Create(int width, int height, int iNumComponents, 
	    							unsigned char* pBytes )
{	 
	ASSERT( width && height && iNumComponents );
	// create a DIB of the requested size

	if ( !ChDib::Create( width, height, ( iNumComponents < 3 ? 8 : 24 ) ) )
	{
		return false;
	}


	// The trasperency bit is currently ignored, we will have to
	// create a mask when we have a renderer which supports trasperency

	#if defined( _DEBUG )
	if ( iNumComponents == 2 || iNumComponents == 4  )
		TRACE( "Ignoring trasperency bit \n" );
	#endif
	
	if ( iNumComponents <= 4  )
	{	// copy the image
		int iDibComp = 1;

		if ( iNumComponents >= 3 )
		{	// 3 bytes/pixel
			iDibComp = 3;	
		}


		// Fill the data into our DIB
		unsigned char * pBits = ( unsigned char * )ChDib::GetBitsAddress();

		for ( int i = 0; i < height; i++ )
		{
			if ( iNumComponents == 1 || iNumComponents == 2  )
			{
				for ( int j = 0; j < width;  j++ )
				{
					pBits[j] = *pBytes;

					pBytes += iNumComponents;
				}
			}
			else
			{
				for ( int j = 0; j < (width * iDibComp);  j += iDibComp )
				{
					pBits[j + 2] = pBytes[0];
					pBits[j + 1] = pBytes[1];
					pBits[j]     = pBytes[2];

					pBytes += iNumComponents;
				}
			}
			// Go to the next row
		    pBits += (((width * iDibComp ) + 3) & ~3);
		}
	}
	else
	{
		return false;
	}
	return true;
}
