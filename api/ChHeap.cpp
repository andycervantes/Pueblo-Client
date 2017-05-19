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

	ChHeap (for Unix)

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/api/ChHeap.cpp,v 2.0 1995/05/11 00:09:10 coyote Exp $

#include <malloc.h>
#include <ChTypes.h>
#include <ChHeap.h>

HANDLE HeapCreate( int a, int b, int c )
{
    return 0;
}

void *HeapAlloc( HANDLE hHeap, chuint32 flags, chuint32 luLen )
{
    return ( malloc( luLen ) );
}

int HeapDestroy( HANDLE hHeap )
{
    return 0;
}

void *HeapReAlloc( HANDLE hHeap, chuint32 flags, void *oldbuf, chuint32 luNewSize )
{
    return realloc( oldbuf, luNewSize );
}

void HeapFree( HANDLE hHeap, chuint32 flags, void *buf )
{
    free( buf );
}

chuint32 HeapSize( HANDLE hHeap, chuint32 flags, void *buf )
{
    cerr << "XXX" << __FILE__ << ":" << __LINE__ << endl;    
    return 0;
}

// Local Variables: ***
// tab-width:4 ***
// End: ***
