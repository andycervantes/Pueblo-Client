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

	Header file for the Chaco Sockets++ library.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/SocketXX.h,v 2.2 1996/04/26 17:04:24 coyote Exp $

#if !defined( _SOCKETXX_H )
#define _SOCKETXX_H

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA    
#endif

#if defined( CH_SERVER ) || defined( CH_UNIX )
	#include <sockstrm.h>
	#include <sockinet.h>
#else
	#include <ChSock.h>
#endif


/*----------------------------------------------------------------------------
	Socket handler definition macros:
----------------------------------------------------------------------------*/

#define CH_DECLARE_SOCKET_HANDLER( name ) \
				CH_EXTERN_CALLBACK( void ) \
				name( sockinetbuf& socket, chparam luEvent, int iErrorCode );

#define CH_IMPLEMENT_SOCKET_HANDLER( name ) \
				CH_GLOBAL_CALLBACK( void ) \
				name( sockinetbuf& socket, chparam luEvent, int iErrorCode )

#define CH_FRIEND_SOCKET_HANDLER( name ) \
				friend CH_GLOBAL_CALLBACK( void ) \
				name( sockinetbuf& socket, chparam luEvent, int iErrorCode );

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
	#undef AFXAPP_DATA
	#define AFXAPP_DATA NEAR    
#endif

#endif	// !defined( _SOCKETXX_H )