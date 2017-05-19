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

	This file contains the definitions for Chaco size class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/ChSize.h,v 2.1 1995/06/02 07:50:00 glenn Exp $

#if !defined( _CHSIZE_H )
#define _CHSIZE_H

#ifdef CH_UNIX

class ChSize
{
  public:
	ChSize( int new_cx, int new_cy )
	{
	    cx = new_cx;
		cy = new_cy;
	};
	ChSize() { cx = cy = 0; };
	operator==( ChSize& sz ) { return ((cx == sz.cx) && (cy == sz.cy)); };
	operator!=( ChSize& sz ) { return (! (*this == sz) ); };

	chuint32 cx, cy;
};

#endif // CH_UNIX

#endif // _CHSIZE_H

// Local Variables: ***
// tab-width:4 ***
// End: ***
