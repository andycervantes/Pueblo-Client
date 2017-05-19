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

	This is the precompiled header for files in this module, and is
	included by all files.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WebBrwsr/StdAFX.h,v 1.2 1996/09/17 21:51:44 pritham Exp $

#if (!defined( _STDAFX_H ))
#define _STDAFX_H


#if defined( CH_MSW )

	#include <afxwin.h>						// MFC core and std components
	#include <afxext.h>						// MFC extensions
	#include <afxdisp.h>					// MFC dispatchers
	#include <afxsock.h>						// MFC extensions
	#if !defined( NO_TEMPLATES )
	#include <afxtempl.h>					// MFC template classes
	#endif
	#if defined( WIN32 )
		#include <afxcmn.h>					// MFC new control classes

	#endif	// defined( WIN32 )

	#if ( _MSC_VER > 900	 )
	#pragma warning( disable: 4237 )
	#else

	#pragma warning( disable: 4041 )
	#endif

#endif	// CH_MSW


#include <ChTypes.h>
#include <ChExcept.h>

#include "resource.h"
#include <ChConst.h>

#define CH_HTML_PRODUCT_NAME	"WebTracker"

#endif	// !defined( _STDAFX_H )
