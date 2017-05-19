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

	This file contains the definitions for ChScrollView class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/ChScrlVw.h,v 2.3 1995/06/27 16:50:07 glenn Exp $

#if !defined( _CHSCRLVW_H )
#define _CHSCRLVW_H

#ifdef CH_UNIX

#define String XtString
#include <Xm/Text.h>
#undef String

#include <ChRect.h>
#include <ChSize.h>

class ChClientDC;

#define MM_TEXT 0x00000001

#define SB_VERT 1
#define SB_HORZ 2
#define SB_BOTH 3

#define ESB_ENABLE_BOTH		0x00000001
#define ESB_DISABLE_BOTH	0x00000002

class ChScrollView
{
  public:
	static const ChSize	sizeDefault;

	ChScrollView();
	virtual ~ChScrollView();
	ChClientDC* GetContext() { return m_pDC; };
	ChPoint& GetDeviceScrollPosition();
	void ScrollToPosition( ChPoint ptNew );
	void InvalidateRect( const ChRect& rtInvalid, bool boolDunno = true ) {
		XClearArea( XtDisplay( m_drawingArea ), XtWindow( m_drawingArea ), rtInvalid.left, rtInvalid.top, 
				   rtInvalid.right - rtInvalid.left,
				   rtInvalid.bottom - rtInvalid.top, True );
		cerr << "XXX" << __FILE__ << ":" << __LINE__ << endl;
	};
	void InvalidateRect( const void * luInvalid, bool boolDunno ) {
		XClearArea( XtDisplay( m_drawingArea ), XtWindow( m_drawingArea ), 0, 0, 0, 0, True );
	};
	void InvalidateRect( ChRect* prtInvalid ) {
		InvalidateRect( *prtInvalid );
	};
	void Invalidate(void) { InvalidateRect( 0, true ); };
	void SetScrollSizes( ChSize& sizeTotal, const ChSize& sizePage = sizeDefault,
									 const ChSize& sizeLine = sizeDefault);
	void EnableScrollBar( chuint32 which, chuint32 flags );
	void ShowScrollBar( chuint32 which, bool boolShow = true );
	void SetScrollPos( chuint32 luFlags, chint32 lPos );
	Widget GetDrawingArea(void) { return m_drawingArea; };
	void UpdateWindow() {
//		cerr << "XXX" << " ChScrollView::UpdateWindow() " << __FILE__ << ":" << __LINE__ << endl;
	};
	void GetClientRect( ChRect* prtClient );

	// callbacks:
	virtual void OnDraw( Widget widget, XtPointer client_data, XtPointer call_data );
	virtual void OnInput( Widget widget, XtPointer client_data, XtPointer call_data );
	static void FakeOnDraw( Widget widget, XtPointer client_data,
											 XtPointer call_data );
	static void FakeOnScroll( Widget widget, XtPointer client_data,
											 XtPointer call_data );
	static void FakeOnInput( Widget widget, XtPointer client_data,
											  XtPointer call_data );
	virtual void OnLButtonUp( chuint32 nFlags, ChPoint& point ) { };
	virtual void OnSize(UINT nType, int cx, int cy) { };
  private:
	ChPoint m_point;
	Widget	m_drawingArea, m_scrolledWindow;
	Widget  m_vsb;	// vertical scroll bar
	ChClientDC* m_pDC;
};

#endif // CH_UNIX

#endif // _CHSCRLVW_H

// Local Variables: ***
// tab-width:4 ***
// End: ***
