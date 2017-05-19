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

	Defines the initialization routines for the DLL.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/Dll.cpp,v 2.1 1995/12/01 09:28:29 coyote Exp $

#include "headers.h"

#include <afxdllx.h>

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	Global variables
----------------------------------------------------------------------------*/

#if defined( CH_MSW ) 

CH_GLOBAL_VAR HINSTANCE				hTextDLL;
CH_GLOBAL_VAR AFX_EXTENSION_MODULE	ChTextDLL = { NULL, NULL };

#endif	// defined( CH_MSW ) && !defined( CH_ARCH_16 )


/*----------------------------------------------------------------------------
	Library entry point (for Win32 and Win16)
----------------------------------------------------------------------------*/

#if defined( CH_MSW ) && !defined( CH_ARCH_16 )

extern "C" int APIENTRY
DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved )
{
	if (DLL_PROCESS_ATTACH == dwReason)
	{
		TRACE0( "CHTEXT.DLL Initializing!\n" );

											/* Extension DLL one-time
												initialization */

		AfxInitExtensionModule( ChTextDLL, hInstance );
		hTextDLL = ChTextDLL.hModule;
											/* Insert this DLL into the
												resource chain */
		new CDynLinkLibrary( ChTextDLL );
	}
	else if (DLL_PROCESS_DETACH == dwReason)
	{
		TRACE0( "CHTEXT.DLL Terminating!\n" );
	}

	return true;
}

#else	// defined( CH_MSW ) && !defined( CH_ARCH_16 )

extern "C" int CALLBACK LibMain(HINSTANCE hInstance, WORD, WORD, LPSTR)
{
	// Extension DLL one-time initialization - do not allocate memory here,
	//   use the TRACE or ASSERT macros or call MessageBox
	AfxInitExtensionModule(ChTextDLL, hInstance); 
	return 1;   // ok
}

// Exported DLL initialization is run in context of running application 
//extern "C" extern void WINAPI InitPueblo()
CH_GLOBAL_LIBRARY( void )
InitChTextDLL()
{
	// create a new CDynLinkLibrary for this app
	new CDynLinkLibrary(ChTextDLL);
	
}

#endif	// defined( CH_MSW ) && !defined( CH_ARCH_16 )

