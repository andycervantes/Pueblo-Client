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

	ChFont class

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/api/ChFont.cpp,v 2.0 1995/05/11 00:09:07 coyote Exp $

#define String XtString
#include <X11/Intrinsic.h>
#undef String

#include <ChTypes.h>
#include <ChSplay.h>
#include <ChFont.h>

void ChFont::CreateFontIndirect( LOGFONT *hXFont )
{
	XFontStruct *pXFont = *hXFont;
	m_pXFont = pXFont;
}

void ChFont::CreateFontIndirect( char *font_specifier )
{
    XFontStruct *pXFont;

	pXFont = ChFontCacheLoadQueryFont( XtDisplay( formWidget ), font_specifier );
	if (pXFont) {
		m_pXFont = pXFont;
	} else {
		cerr << "Error looking up font:  " << font_specifier << endl;
	}
}

void ChFont::GetObject( int iUnused, LOGFONT* pXFont )
{
	Update();
	*pXFont = m_pXFont;
}

void ChFont::Update(void)
{
	if (m_pXFont == 0 && formWidget)
		m_pXFont = ChFontCacheLoadQueryFont( XtDisplay( formWidget ), "-*-times-medium-r-*-*-*-140-*-*-*-*-iso8859-*" ); // XXX Don't use global.
}

// Like XLoadQueryFont, only it does caching and never frees the pointers it returns.
// Note that this function doesn't know anything about wildcards in font
// specifiers.
XFontStruct* ChFontCacheLoadQueryFont( Display* display, char *pstrFontName )
{
	static ChSplay< string, XFontStruct*> font_cache;
	XFontStruct **hFontStruct;
	XFontStruct *pFontStruct;
	string strFontName( pstrFontName );

#if 0
	strFontName = "fixed";
	pstrFontName = "fixed";
#endif
	
	hFontStruct = font_cache.Find( strFontName );
	if (hFontStruct) {
		pFontStruct = *hFontStruct;
	} else {
		cerr << "Getting font: " << pstrFontName << endl;
		pFontStruct = XLoadQueryFont( display, pstrFontName );
		if (pFontStruct == NULL) {
			cerr << "Unable to find font: " << pstrFontName << endl;
			pFontStruct = XLoadQueryFont( display, "fixed" );
		}
		font_cache.Insert( strFontName, pFontStruct );
	}

	return pFontStruct;
}

// Local Variables: ***
// tab-width:4 ***
// End: ***
