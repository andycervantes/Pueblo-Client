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

	This file contains the definitions for ChFont.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/ChFont.h,v 2.1 1995/07/03 19:55:39 glenn Exp $

#if !defined( _CHFONT_H )
#define _CHFONT_H

#ifdef CH_UNIX
#include <ChTypes.h>

extern XFontStruct* ChFontCacheLoadQueryFont( Display* display, char *pstrFontName );

extern Widget formWidget;

class ChFont
{
  public:
	ChFont() : m_pXFont(0)
	{
		Update();
	};
	~ChFont() { };
	void GetObject( int iUnused, LOGFONT* pXFont );
	XFontStruct* GetFontStruct() { Update(); return m_pXFont; };
	void CreateFontIndirect( LOGFONT *pXFont );
	void CreateFontIndirect( char *font_specifier );
  private:
    // Update is called to try to set m_pXFont, in case it didn't get set.
    // The particular case where this happens is with global ChFonts.
	void Update(void);
	XFontStruct* m_pXFont;
};

#endif // CH_UNIX

#endif // _CHFONT_H

// Local Variables: ***
// tab-width:4 ***
// End: ***
