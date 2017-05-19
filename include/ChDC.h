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

	This file contains the definitions for Chaco DC class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/ChDC.h,v 2.2 1995/07/27 03:14:01 glenn Exp $

#if !defined( _CHDC_H )
#define _CHDC_H

#ifdef CH_UNIX

#include <assert.h>
#include <ChScrlVw.h>
#include <ChFont.h>


#define TA_BASELINE 1

// Solaris' sys/stream.h has a TRANSPARENT also, so we include the file, 
// get rid of the TRANSPARENT, and define our own.
#ifdef SOLARIS
#include <sys/stream.h>
#endif // SOLARIS

#ifdef TRANSPARENT
#undef TRANSPARENT
#endif
#define TRANSPARENT 1
#define CH_DEF_COLOR	0x80000000

#define SYSTEM_FONT 1

// For ExtTextOut()
#define ETO_OPAQUE 1

typedef struct tagTEXTMETRIC 
{
	chuint32 tmHeight, tmExternalLeading, tmAscent;
} TEXTMETRIC;

class ChClientDC
{
  public:
	ChClientDC( ChScrollView* pView )
	{
		XGCValues gcv;
		Widget w;

		m_pView = pView;

		w = m_pView->GetDrawingArea();
		m_dsp = XtDisplay( w );
		m_textColor = gcv.foreground = WhitePixelOfScreen( XtScreen( w ) );
		m_gc = XCreateGC( m_dsp, RootWindowOfScreen( XtScreen( w ) ), GCForeground, &gcv );
		XtVaGetValues( w,
					   XmNcolormap, &m_colormap,
					   NULL );
//		m_colormap = DefaultColormap( m_dsp, DefaultScreen( m_dsp ) );
		m_pFont = &m_DefaultFont;
	};
	~ChClientDC() { XFreeGC( m_dsp, m_gc ); }
	ChFont* SelectObject( ChFont* pFont ) { 
		ChFont* pOldFont;
		XGCValues gcv;

		pOldFont = m_pFont;
		gcv.font = pFont->GetFontStruct()->fid;
		XChangeGC( m_dsp, m_gc, GCFont, &gcv );	// Make it the current font for the GC
		m_pFont = pFont;
		return pOldFont;
	};
	void GetTextMetrics( TEXTMETRIC* pTM );
	void SetTextAlign( chuint32 flags ) {
		assert( flags == TA_BASELINE );
	};
	void SetTextJustification( chuint x, chuint y ) {
		assert(x == 0);
		assert(y == 0);
	};
	chuint16 SetTextCharacterExtra(chuint16 width) {
		if (width)
			cerr << "XXX" << " ChClientDC::SetTextCharacterExtra(width) " << __FILE__ << ":" << __LINE__ << endl;
		return width;
	};
	// XXX What is this supposed to do?
	chuint16 GetTextCharacterExtra(void) { 
		return 0; 
	};
	COLORREF SetTextColor(COLORREF color) {
		COLORREF	oldTextColor = m_textColor;
		XColor		textXColor;
		unsigned long	newPixelColor;

		if (color & CH_DEF_COLOR) {
			newPixelColor = WhitePixelOfScreen( XDefaultScreenOfDisplay( m_dsp ) );
		} else {
			m_textColor = color;
			textXColor.blue		= (color & 0x00ff0000) >> 16;
			textXColor.blue		= textXColor.blue << 8 + textXColor.blue;
			textXColor.green	= (color & 0x0000ff00) >> 8;
			textXColor.green	= textXColor.green << 8 + textXColor.green;
			textXColor.red		= color & 0x000000ff;
			textXColor.red		= textXColor.red << 8 + textXColor.red;
			textXColor.flags	= DoRed | DoGreen | DoBlue;

			if (!XAllocColor( m_dsp, m_colormap, &textXColor )) {
				cerr << "Unable to allocate color." << endl;
			}
			newPixelColor = textXColor.pixel;
		}
		XSetForeground( m_dsp, m_gc, newPixelColor );
		return oldTextColor;
	};
	COLORREF SetBkColor(COLORREF color);
	void SetBkMode(chuint32 flags) {
		if (flags != TRANSPARENT)
			cerr << "XXX" << " ChClientDC::SetBkMode(flags != TRANSPARENT) " << __FILE__ << ":" << __LINE__ << endl;
	};
	ChFont* SelectStockObject( chuint32 stock ) {
		assert( stock == SYSTEM_FONT );
		return &m_DefaultFont;
	};
	ChSize GetTextExtent( char *pstrText, int iLength );
	ChSize TabbedTextOut( chuint32 x, chuint32 y, pstr pText, int iCount,
						 chuint32 u1, chuint32 u2, chuint32 u3);
	void ExtTextOut( int unused1, int unused2, chuint32 flags, ChRect& rtRect,
					 char *unused3, int unused4, int *unused5);


  private:
	ChScrollView* 	m_pView;
	GC 				m_gc;
	Display 		*m_dsp;
	ChFont* 		m_pFont;
	COLORREF 		m_textColor;
	Colormap		m_colormap;
	static ChFont	m_DefaultFont;
};

typedef ChClientDC CDC;

#endif // CH_UNIX

#endif // _CHDC_H

// Local Variables: ***
// tab-width:4 ***
// End: ***
