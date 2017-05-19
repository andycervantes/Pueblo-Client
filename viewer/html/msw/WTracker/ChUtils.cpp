/*----------------------------------------------------------------------------

            .###.  ###     ###       ,#,          .###.    ,#######,
         ,####""   ###    .###     ,##'##,     ,####""   .##'    `##.
        ###        ###########    ,##' `##,   ###       ####      ####
        ###..      ###'    ###  ,###########, ####..    `###,    ,##'
          `######  ###     ###  `##'     `##'   `######   `########'


	Copyright 1995, Chaco Communications, Inc. All rights reserved.
	Unpublished -- Rights reserved under the copyright laws of the United
	States.  Use of a copyright notice is precautionary only and does no
	imply publication or disclosure.

	This software contains confidential information and trade secrets of
	Chaco Communications, Inc.  Use, disclosure, or reproduction is
	prohibited without the prior express written permission of Chaco
	Communications, Inc.

	RESTRICTED RIGHTS LEGEND

	Use, duplication, or disclosure by the Government is subject to
	restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
	Technical Data and Computer Software clause at DFARS 252.227-7013.

	Chaco Communications, Inc.
	10164 Parkwood Drive, Suite 8, Cupertino, CA, 95014-1533

------------------------------------------------------------------------------

	This file consists of Chaco utility functions.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChUtils.cpp,v 1.1 1996/02/26 23:04:32 pritham Exp $

#include "stdafx.h"

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
