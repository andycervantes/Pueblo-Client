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

	This file consists of Chaco utility functions.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/client/msw/ChUtils.cpp,v 2.1 1995/07/18 04:31:02 coyote Exp $

#include "headers.h"

#include "ChUtils.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

/*----------------------------------------------------------------------------

	FUNCTION		||	PointsToDevice

	pDC				||	Pointer to a device context.

	iPoints			||	Point size desired.  There are 72 points / inch.

	boolVertical	||	true if vertical screen resolution should be used,
						and false otherwise.  This parameter doesn't need
						to be explicitly passed.

	RETURNS			||	The pixel size corresponding to the desired point
						size.

------------------------------------------------------------------------------

	This utility function will return the correct pixel size for a desired
	point size.  The function's primary use is in obtaining font heights.
	NOTE that the size returned is based on vertical pixel resolution, and'
	may not be acurate for horizontal resolution.  To use horizontal
	resolution, pass the third parameter as false.

----------------------------------------------------------------------------*/

int PointsToDevice( CDC *pDC, int iPoints, bool boolVertical )
{
	int		iPixelsPerInch;
	int		iPixels;

	iPixelsPerInch = pDC->GetDeviceCaps( LOGPIXELSY );

	iPixels = (int)(((long)iPixelsPerInch * (long)iPoints) / 72L);

	return( iPixels );
}
