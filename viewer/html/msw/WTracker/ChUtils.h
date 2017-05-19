/*----------------------------------------------------------------------------

            .###.  ###     ###       ,#,          .###.    ,#######,
         ,####""   ###    .###     ,##’##,     ,####""   .##’    ‘##.
        ###        ###########    ,##’ ‘##,   ###       ####      ####
        ###..      ###’    ###  ,###########, ####..    ‘###,    ,##’
          ‘######  ###     ###  ‘##’     ‘##’   ‘######   ‘########’


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

	This header file consists of Chaco utility functionality.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChUtils.h,v 1.1 1996/02/26 23:04:33 pritham Exp $

#include "stdafx.h"

int PointsToDevice( CDC *pDC, int iPoints, bool boolVertical = true );
