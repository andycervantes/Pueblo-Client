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

	ChClientDC class

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/api/ChDC.cpp,v 2.1 1995/06/21 17:55:08 glenn Exp $

#define String XtString
#include <Xm/ScrolledW.h>
#include <Xm/DrawingA.h>
#undef String

#include <ChTypes.h>
#include <ChRect.h>
#include <ChSize.h>
#include <ChScrlVw.h>
#include <ChDC.h>

ChFont	ChClientDC::m_DefaultFont;
   
ChSize ChClientDC::GetTextExtent( char *pstrText, int iLength )
{
	// XXX We're getting in to there an awful lot.  Why?  -glenn 4/6/95
#ifdef CH_VERBOSE
//	cerr << "ChClientDC::GetTextExtent(" << pstrText << "," << iLength << ") " << __FILE__ << ":" << __LINE__ << endl;
#endif
	
	int direction, ascent, descent;
	XCharStruct overall;
	
	XTextExtents( m_pFont->GetFontStruct(), pstrText, iLength, &direction,
				  &ascent, &descent, &overall );
	return ChSize(overall.width, overall.ascent + overall.descent);
};

ChSize ChClientDC::TabbedTextOut( chuint32 x, chuint32 y, pstr pText, int iCount,
								  chuint32 u1, chuint32 u2, chuint32 u3)
{
	XDrawString( m_dsp, XtWindow( m_pView->GetDrawingArea() ), m_gc, x, y, pText, iCount );
	return GetTextExtent( pText, iCount );
};			

void ChClientDC::GetTextMetrics( TEXTMETRIC* pTM )
{
	int direction, ascent, descent;
	XCharStruct overall;
	
	XTextExtents( m_pFont->GetFontStruct(), "X", 1, &direction, &ascent,
				  &descent, &overall );
	
	pTM->tmHeight = ascent + descent;
	pTM->tmExternalLeading = 0;
	pTM->tmAscent = ascent;
};

// This is basically a line-drawing function.  Pueblo doesn't use it
// any other way currently.  (Hence all the unused params.)
void ChClientDC::ExtTextOut( int unused1, int unused2, chuint32 flags,
					 ChRect& rtRect, char *unused3, int
					 unused4, int *unused5)
{
	XDrawRectangle( m_dsp, XtWindow( m_pView->GetDrawingArea() ), m_gc,
					rtRect.left,
					rtRect.top,
					rtRect.right - rtRect.left,
					rtRect.bottom - rtRect.top );
}

COLORREF ChClientDC::SetBkColor(COLORREF color)
{
	COLORREF old_color;
	XGCValues gcv;	
	
	XGetGCValues( m_dsp, m_gc, GCBackground, &gcv );
	old_color = gcv.background;

//	XSetBackground( m_dsp, m_gc, color );
	XSetForeground( m_dsp, m_gc, color );
	if (color & CH_DEF_COLOR) {
		cerr << "ChClientDC::SetBkColor(): Setting CH_DEF_COLOR" << endl;
	}

	return old_color;
};

// Local Variables: ***
// tab-width:4 ***
// End: ***
