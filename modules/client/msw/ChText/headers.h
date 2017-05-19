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

	Source file that includes just the standard includes.  This file may
	be used for precompiled headers.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/headers.h,v 2.6 1996/02/17 01:46:44 coyote Exp $

#if defined( CH_MSW )

	#include <afxwin.h>						// MFC core and std components
	#include <afxext.h>						// MFC extensions
	#include <afxdisp.h>					// MFC dispatchers

#endif	// CH_MSW

#include <ChTypes.h>
#include <ChModule.h>
#include <ChDispat.h>
#include <ChMsg.h>
#include <ChMsgTyp.h>
#include <ChUtil.h>

#if defined( CH_MSW )

	#if !defined( NO_TEMPLATES )
	#include <afxtempl.h>					// MFC template classes
	#endif

#endif	// CH_MSW

#include <ChText.h>

#include "Text.h"
#include "resource.h"


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define MAX_MENU_STRING_LEN			30


/*----------------------------------------------------------------------------
	Text Out preferences registry group
----------------------------------------------------------------------------*/

#define TEXT_OUT_PREFS_GROUP		"Text Output module"
#define TEXT_OUT_PREFS_LINES			"Buffer lines"
#define TEXT_OUT_PREFS_LINES_DEF			400

#define TEXT_IN_PREFS_GROUP			"Text Input module"
#define TEXT_IN_PREFS_KEYMAP			"Key map"
#define TEXT_IN_PREFS_KEYMAP_DEF			"windows"
#define TEXT_IN_PREFS_CLEAR				"Clear input after send"
#define TEXT_IN_PREFS_CLEAR_DEF				true
#define TEXT_IN_EDIT_LINES				"Number of edit lines"
#define TEXT_IN_EDIT_LINES_DEF				2
#define TEXT_IN_EDIT_LINES_MAX				10
#define TEXT_IN_TINTIN_FILE				"TinTin command file"
#define TEXT_IN_TINTIN_FILE_DEF				""


/*----------------------------------------------------------------------------
	Global variables
----------------------------------------------------------------------------*/

#if defined( CH_MSW ) 

CH_EXTERN_VAR AFX_EXTENSION_MODULE	ChTextDLL;

#endif	// defined( CH_MSW ) && !defined( CH_ARCH_16 )


/*----------------------------------------------------------------------------
	Macros
----------------------------------------------------------------------------*/

#if defined( CH_MSW )

	#define LOADSTRING( lKey, strValue ) \
				(ChUtil::Load( (chparam)ChTextDLL.hModule, lKey, strValue ))

#elif defined( CH_UNIX )

	#define LOADSTRING( lKey, strValue ) \
				(ChUtil::Load( (chparam)text_resources, lKey, strValue ))

#else

	#error "OS not defined"

#endif


/*----------------------------------------------------------------------------
	Utility functions
----------------------------------------------------------------------------*/

CH_EXTERN_FUNC( void )
TruncateMenuString( string& strText );

