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

	ChScrollView, for Unix.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/api/ChScrlVw.cpp,v 2.3 1995/06/30 05:34:26 glenn Exp $

#define String XtString
#include <Xm/ScrolledW.h>
#include <Xm/DrawingA.h>
#include <Xm/ScrollBar.h>
#undef String

#include <ChTypes.h>
#include <ChRect.h>
#include <ChSize.h>
#include <ChScrlVw.h>
#include <ChDC.h>

extern Widget formWidget;	// Top-level form widget in the main window.

const ChSize ChScrollView::sizeDefault( 0, 0 );

void ChScrollView::FakeOnInput( Widget widget, XtPointer client_data,
							XtPointer call_data )
{
	ChScrollView*	pScrollView = (ChScrollView *)client_data;
	XmDrawingAreaCallbackStruct* cbs = (XmDrawingAreaCallbackStruct *) call_data;
	XEvent* 		event = cbs->event;
	
	pScrollView->OnInput( widget, client_data, call_data );
	// Send OnLButtonUp, if that's what this is.
	if ( (cbs->reason == XmCR_INPUT) &&
		 (event->xany.type == ButtonRelease) &&
		 (event->xbutton.button == Button1) ) {
		ChPoint buttonPoint( event->xbutton.x, event->xbutton.y );
		ChPoint scrollPoint = pScrollView->GetDeviceScrollPosition();
		// OnLButtonUp() expects this to be in parent-window (unscrolled)
		// coordinates, so subtract out the scroll size.
		buttonPoint.x -= scrollPoint.x;
		buttonPoint.y -= scrollPoint.y;
		pScrollView->OnLButtonUp( 0, buttonPoint );
	}
}

void ChScrollView::FakeOnDraw( Widget widget, XtPointer client_data,
						   XtPointer call_data )
{
	ChScrollView *pScrollView = (ChScrollView *)client_data;
	
	pScrollView->OnDraw( widget, client_data, call_data );
}

#if 0
void ChScrollView::FakeOnScroll( Widget widget, XtPointer client_data,
								 XtPointer call_data )
{
	ChScrollView *pScrollView = (ChScrollView *)client_data;
	
	cerr << "XXX ChScrollView::FakeOnScroll" << endl;
//	pScrollView->OnDraw( widget, client_data, call_data );
}
#endif // 0

void ChScrollView::OnInput( Widget widget, XtPointer client_data,
							XtPointer call_data )
{
}

void ChScrollView::OnDraw( Widget widget, XtPointer client_data,
						   XtPointer call_data )
{
}

ChScrollView::ChScrollView()
{
	Arg args[20];
	int n;
	WidgetList formChildren;	// The first child is our bottom attachment
	int childCount;

	// Get the children & childCount
	XtVaGetValues( formWidget,
				   XmNchildren, &formChildren,
				   XmNnumChildren, &childCount,
				   NULL );

	n = 0;
	XtSetArg(args[n], XmNscrollingPolicy, XmAUTOMATIC); n++;

	XtSetArg(args[n], XmNtopAttachment, XmATTACH_FORM); n++;
	XtSetArg(args[n], XmNleftAttachment, XmATTACH_FORM); n++;
	XtSetArg(args[n], XmNrightAttachment, XmATTACH_FORM); n++;
	if ((childCount >= 1) && (XtIsManaged( formChildren[0] ))) {
		XtSetArg(args[n], XmNbottomAttachment, XmATTACH_WIDGET); n++;
		XtSetArg(args[n], XmNbottomWidget, formChildren[0]); n++;
	} else {
		XtSetArg(args[n], XmNbottomAttachment, XmATTACH_FORM); n++;
	}
	
	m_scrolledWindow = XtCreateManagedWidget( "scrolled_w",
											  xmScrolledWindowWidgetClass, formWidget,
											  args, n );

	m_drawingArea = XtVaCreateManagedWidget( "drawing_a",
											 xmDrawingAreaWidgetClass, m_scrolledWindow,
											 XmNwidth, 490,
											 XmNheight, 1000,
											 NULL );
	XtAddCallback( m_drawingArea, XmNinputCallback, FakeOnInput, this );
	XtAddCallback( m_drawingArea, XmNexposeCallback, FakeOnDraw, this );

#if 0
	m_vsb = XtVaCreateManagedWidget( "vsb", xmScrollBarWidgetClass,
									 m_scrolledWindow,
									 XmNorientation, XmVERTICAL,
									 NULL );

	XmScrolledWindowSetAreas( m_scrolledWindow, 0, m_vsb, m_drawingArea );

	XtAddCallback( m_vsb, XmNvalueChangedCallback, FakeOnScroll, this );
	XtAddCallback( m_vsb, XmNdragCallback, FakeOnScroll, this );
#endif // 0
	
	m_pDC = new ChClientDC( this );
}

ChScrollView::~ChScrollView()
{
	XtDestroyWidget( m_drawingArea );
	delete m_pDC;
}

void ChScrollView::SetScrollSizes( ChSize& sizeTotal, const ChSize& sizePage,
									const ChSize& sizeLine )
{
	static int lock = 0;	// If we're called recursively, just return.

	if (!lock) {
		lock++;
		XtVaSetValues( GetDrawingArea(),
//					   XmNwidth, sizeTotal.cx,
					   XmNheight, sizeTotal.cy,
					   NULL );
		XtVaGetValues( GetDrawingArea(),
					   XmNwidth, &sizeTotal.cx,
					   NULL );
//		OnSize( 0, sizeTotal.cx, sizeTotal.cy );
		lock--;
	}
}

void ChScrollView::EnableScrollBar( chuint32 which, chuint32 flags )
{
	return;
}

void ChScrollView::ShowScrollBar( chuint32 which, bool boolShow )
{
	return;
}

void ChScrollView::SetScrollPos( chuint32 luFlags, chint32 lPos )
{
	Widget scrollbar;
	int value, slider_size, increment, page_increment;

	// get the scroll bar, either vertical or horizontal:
	// Move the drawing area
	if (luFlags == SB_VERT) {
		XtVaGetValues( m_scrolledWindow, XmNverticalScrollBar, &scrollbar, NULL );
	} else {
		XtVaGetValues( m_scrolledWindow, XmNhorizontalScrollBar, &scrollbar, NULL );
	}
	XmScrollBarGetValues( scrollbar, &value, &slider_size, &increment,
						  &page_increment );
	// Change the value to be 'lPos'.  Leave the others alone.
	XmScrollBarSetValues( scrollbar, lPos, slider_size, increment,
						  page_increment, True );
}

void ChScrollView::GetClientRect( ChRect* prtClient )
{
	Dimension x, y, width, height;
#if 0
	XtVaGetValues( m_drawingArea, XmNx, &x, XmNy, &y,
				   XmNwidth, &width, XmNheight, &height, NULL );
#else
	XtVaGetValues( m_scrolledWindow, XmNx, &x, XmNy, &y,
				   XmNwidth, &width, XmNheight, &height, NULL );
#endif
	prtClient->left = x;
	prtClient->right = x + width;
	prtClient->top = y;
	prtClient->bottom = y + height;
}

ChPoint&  ChScrollView::GetDeviceScrollPosition()
{
	Widget sb_vert;
//	Widget sb_horz;
	int value, slider_size, increment, page_increment;

	XtVaGetValues( m_scrolledWindow, XmNverticalScrollBar, &sb_vert, NULL );
//	XtVaGetValues( m_scrolledWindow, XmNhorizontalScrollBar, &sb_horz, NULL );
	XmScrollBarGetValues( sb_vert, &value, &slider_size, &increment,
						  &page_increment );
	m_point.y = value;
#if 0
	XmScrollBarGetValues( sb_horz, &value, &slider_size, &increment,
						  &page_increment );
	m_point.x = value;
#else
	m_point.x = 0;
#endif
	return m_point;
};

void ChScrollView::ScrollToPosition( ChPoint ptNew )
{ 
	cerr << "XXX" << " ChScrollView::ScrollToPosition( ChPoint ptNew ) " << __FILE__ << ":" << __LINE__ << endl;
	SetScrollPos( SB_VERT, ptNew.y );
	SetScrollPos( SB_HORZ, ptNew.x );
};

// Local Variables: ***
// tab-width:4 ***
// End: ***
