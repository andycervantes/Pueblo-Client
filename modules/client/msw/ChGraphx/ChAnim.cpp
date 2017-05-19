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

	Implementation for the ChGraphic class, which is used to display
	graphics, & accept selection of hot spots and sprites.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChAnim.cpp,v 2.18 1996/09/12 19:09:41 pritham Exp $

#include "grheader.h"

#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN ) && !defined( CH_PUEBLO_PLUGIN )
#include "resource.h"
#else
#include "vwrres.h"
#endif

#include <ChCore.h>

#include "ChGrMod.h"
#include "ChAniPrs.h"
#include <fstream.h>
#include <ChDibImage.h>
#include <ChGIFDecoder.h>
#include <ChJPEGDecoder.h>
#include <ChUtil.h>
#include <ChImgUtil.h>
#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

#define NOT_IMPLEMENTED	TRACE2("Function not implemented, file %s: line %s.", __FILE__, __LINE__)


// Either of the following dummy declarations cause the compiler
// to fully define the 	ChPtrList<ChAnimAnchor> class, preventing
// a warning when deleting m_pCastAnchors;
//ChPtrList<ChAnimAnchor>	m_dummy;
class dummyAnchorPtrList:ChPtrList<ChAnimAnchor>
{
	public:

};

typedef struct tagChAnimStringTable
{
	char * strStr;
	chint32	key;
} ChAnimStringTable;

static ChAnimStringTable aChAnimPointerNames[] =
{
	"Pointer", CH_CURSOR_STD_PTR,	
	"Crosshairs", CH_CURSOR_HAIRS,		
	"Wait", CH_CURSOR_WAIT,		
	"Picker", CH_CURSOR_PICK,		
	"Finger", CH_CURSOR_PICK,		
	"IBeam", CH_CURSOR_IBEAM,		
	"Edit", CH_CURSOR_IBEAM,		
	"No", CH_CURSOR_NO,		
	"Forbidden", CH_CURSOR_NO,		
	"", 0
};

/*	
	Class ChAnimView
*/
//IMPLEMENT_DYNCREATE( ChAnimView, ChGraphicView )

BEGIN_MESSAGE_MAP(ChAnimView, ChGraphicView)
    //{{AFX_MSG_MAP(ChAnimView)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


ChAnimView::ChAnimView( ChGraphicMainInfo *pInfo ) : 
		ChGraphicView( pInfo ),
		m_uiTimer(0), 
		m_cursorId(CH_CURSOR_STD_PTR),
		m_anchorId(0), 
		m_pCastAnchors(0), 
		m_pDibBkgnd(0), 
		m_boolBackgroundDirty(false),
		m_boolCenterIt(true)
{ 
    m_pDIB = NULL;
    m_pPal = NULL;
    m_pOneToOneClrTab = NULL;
    m_bUseCreateDIBSection = false;
    m_hbmSection = NULL;

    // See if we are on Win32s which exports CreateDIBSection but
    // does not support it
    DWORD dwVer = GetVersion();
    if ((dwVer & 0x800000FF) != 0x080000003) {
        // Not on Win32s so try to get the CreateDIBSection procedure address.
        HANDLE hMod = ::GetModuleHandle("gdi32");
        if (hMod) {
            m_pCDSProc = (CDSPROC*) GetProcAddress((HMODULE) hMod, "CreateDIBSection");
            if (m_pCDSProc) {
                m_bUseCreateDIBSection = true;
            }
        }
    }
											// Cursors need to get moved to grview ??????????????
	for (int j=0; j<MAX_CURSOR_COUNT; j++)
	{
		m_cursors[j] = LoadCursor( 0, IDC_ARROW ); 
	}
	m_cursors[CH_CURSOR_STD_PTR] = ::LoadCursor( 0, IDC_ARROW );
	m_cursors[CH_CURSOR_HAIRS] = ::LoadCursor( 0, IDC_CROSS );
	m_cursors[CH_CURSOR_WAIT] = ::LoadCursor( 0, IDC_WAIT );
	m_cursors[CH_CURSOR_NO] = ::LoadCursor( 0, IDC_NO );
	m_cursors[CH_CURSOR_IBEAM] = ::LoadCursor( 0, IDC_IBEAM );

	if ( ChUtil::GetSystemType() == CH_SYS_WIN32S || 	
				ChUtil::GetSystemType() == CH_SYS_WIN3X ) 
	{
		m_cursors[CH_CURSOR_PICK] = ::LoadCursor( ChGraphicsDLL.hModule,
												MAKEINTRESOURCE( IDC_HANDMONO ));
	}
	else
	{
		m_cursors[CH_CURSOR_PICK] = ::LoadCursor( ChGraphicsDLL.hModule,
												MAKEINTRESOURCE( IDC_PICKER ));
	}

	m_pDibBkgnd = new ChDibBmp;

}


ChAnimView::~ChAnimView() 
{ 
	// Delete characters
	while (!m_characters.IsEmpty())
	{
		ChAnimCastMember *pCast = m_characters.RemoveHead();
		delete pCast;
	}
	//  Note: Installed anchors are deleted when splay tree is zapped

	// We need to explicitly zap list of pending anchors, if any
	if (m_pCastAnchors && !m_pCastAnchors->IsEmpty())
	{
		ChAnimAnchor *pAnchor = m_pCastAnchors->RemoveHead();
		delete pAnchor;
	}
	delete m_pCastAnchors;
    if (m_pDIB) { delete m_pDIB; m_pDIB = 0;}
    if (m_pPal) { delete m_pPal; m_pPal = 0;}
    if (m_pOneToOneClrTab) {free(m_pOneToOneClrTab); m_pOneToOneClrTab = 0;}
    if (m_hbmSection) {::DeleteObject(m_hbmSection);	m_hbmSection = 0;}
    EmptyDirtyList();
	delete m_pDibBkgnd;	   
	m_pDibBkgnd = 0;
}


// Create a Window
bool ChAnimView::Create( const CRect& rtView, CWnd* pParent, DWORD dwStyle,
						UINT uiID )
{
	bool boolSuccess = ChGraphicView::Create( rtView, pParent, dwStyle, uiID );
	return boolSuccess;
}

BOOL ChAnimView::PreCreateWindow( CREATESTRUCT& cs )
{
		HCURSOR		hCursor;

	if (!ChGraphicView::PreCreateWindow( cs ))
	{
		return false;
	}

	hCursor = AfxGetApp()->LoadStandardCursor( IDC_ARROW );
	cs.lpszClass = AfxRegisterWndClass( CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW, hCursor,
										(HBRUSH)(COLOR_WINDOW + 1) );
	return true;

	//return ChGraphicView::PreCreateWindow(cs);
}


// Create a new buffer, tables and palette to match a supplied DIB.
BOOL ChAnimView::Create(ChDibBmp *pDIB)
{
    // Create the 1-to-1 palette index table.
    if (m_pOneToOneClrTab) free(m_pOneToOneClrTab);
    m_pOneToOneClrTab = 
        (LPBITMAPINFO) malloc(sizeof(BITMAPINFOHEADER)
                              + 256 * sizeof(WORD));
    if (!m_pOneToOneClrTab) {
        TRACE("Failed to create color table");
        return false;
    }

    // Set up the table header to match the DIB
    // by copying the header and then constructing the 1-to-1
    // index translation table.
    memcpy(m_pOneToOneClrTab,
           pDIB->GetBitmapInfoAddress(),
           sizeof(BITMAPINFOHEADER));
    // make sure the length of the table is set to 256 not to
    // the number of colors in the DIB which is irrelevant
    m_pOneToOneClrTab->bmiHeader.biClrUsed = 0; // default (256) 
    WORD* pIndex;
    pIndex = (LPWORD)((LPBYTE)m_pOneToOneClrTab + sizeof(BITMAPINFOHEADER));
    for (int i = 0; i < 256; i++) {
        *pIndex++ = (WORD) i;
    }

    // Create a palette from the DIB so that we can use it to do
    // screen drawing.
    if (m_pPal) delete m_pPal;
    m_pPal = new ChDibPal;
    ASSERT(m_pPal);
    if (!m_pPal->Create(pDIB)) {
        TRACE("Failed to create palette");
        delete m_pPal;
        m_pPal = NULL;
        return false;
    } else {
        // Map the colors so that we get an identity palette.
        m_pPal->SetSysPalColors();
    }

    // Delete any existing DIB and create a new one.
    if (m_pDIB) delete m_pDIB;
    m_pDIB = new ChDibBmp;
    BOOL bResult = false;
    if (m_bUseCreateDIBSection) {
        if (m_hbmSection) ::DeleteObject(m_hbmSection);
        ASSERT(m_pCDSProc);
        CDC* pDC = GetDC();
        CPalette* pPalOld = pDC->SelectPalette(m_pPal, false);
        pDC->RealizePalette();
        BYTE* pBits = NULL;
        m_hbmSection = (*m_pCDSProc)(pDC->GetSafeHdc(),
                                     m_pOneToOneClrTab,
                                     DIB_PAL_COLORS,
                                     (VOID **) &pBits,
                                     NULL,
                                     0);
        pDC->SelectPalette(pPalOld, false);
        ASSERT(m_hbmSection);
        ASSERT(pBits);
        ReleaseDC(pDC);
        bResult = m_pDIB->Create(pDIB->GetBitmapInfoAddress(), pBits);
    } else {
        bResult = m_pDIB->Create(pDIB->GetWidth(), pDIB->GetHeight());
    } 
    if (!bResult) {
        TRACE("Failed to create off-screen DIB");
        delete m_pDIB;
        m_pDIB = NULL;
        return false;
    }

    CSize sizeTotal;
    sizeTotal.cx = m_pDIB->GetWidth();
    sizeTotal.cy = m_pDIB->GetHeight();
    //SetScrollSizes(MM_TEXT, sizeTotal);
    SetScrollSizes(sizeTotal);


    return true;
}


void ChAnimView::OnInitialUpdate()
{
    CSize sizeTotal;
    if (m_pDIB) {
        sizeTotal.cx = m_pDIB->GetWidth();
        sizeTotal.cy = m_pDIB->GetHeight();
    } else {
        sizeTotal.cx = 640;
        sizeTotal.cy = 480;
    }
    SetScrollSizes(sizeTotal);
}

bool ChAnimView::LoadBackground( const string & strURL )
{
	delete m_pDibBkgnd;
	m_pDibBkgnd = new ChDibBmp;
								   
    if (!m_pDibBkgnd->Load( (char *)(LPCTSTR( strURL )) ))
    {
        return false;
    }

    // Create a new buffer
    // and palette
    
    m_spriteList.m_NotifyObj.SetView(this);
    NewBackground(m_pDibBkgnd);
	return true;
}


bool ChAnimView::LoadBackgroundJPEG( const string & strURL )
{
	delete m_pDibBkgnd;
	m_pDibBkgnd = new ChDibBmp;
	
	ChDib  dibImage;
	ChJPEG jpegDecoder( &dibImage );							   

    if (!jpegDecoder.Load( strURL ) )//, ChDib::load8Bit ))
    {
        return false;
    }

	// convert dib to dibbmp
	m_pDibBkgnd->Create( dibImage.GetBitmapInfoAddress(), 
				(BYTE*)dibImage.GetBitsAddress(), true );

    // Create a new buffer
    // and palette
    
    m_spriteList.m_NotifyObj.SetView(this);
    NewBackground(m_pDibBkgnd);
	return true;
}


bool ChAnimView::LoadBackgroundGIF( const string & strURL )
{
	delete m_pDibBkgnd;
	m_pDibBkgnd = new ChDibBmp;
								   
	ChDib  dibImage;
	ChGifDecoder gifDecoder( &dibImage );							   

    if (!gifDecoder.Load( strURL )) //, ChDib::load8Bit ) )
    {
        return false;
    }

	// convert dib to dibbmp
	m_pDibBkgnd->Create( dibImage.GetBitmapInfoAddress(), 
				(BYTE*)dibImage.GetBitsAddress(), true );


    // Create a new buffer
    // and palette
    
    m_spriteList.m_NotifyObj.SetView(this);
    NewBackground(m_pDibBkgnd);
	return true;
}

bool ChAnimView::LoadBackground( chuint16 suResId )
{
	delete m_pDibBkgnd;
	m_pDibBkgnd = new ChDibBmp;

    if (!m_pDibBkgnd->Load( suResId, ChGraphicsDLL.hModule ))
    {
        return false;
    }
											// Create a new buffer and palette
    m_spriteList.m_NotifyObj.SetView( this );
    NewBackground( m_pDibBkgnd );

	return true;
}

// Create a new buffer and palette to match a new 
// background DIB
bool ChAnimView::NewBackground(ChDibBmp* pDIB)
{
	int iColors = ChImgUtil::MaxDeviceColors();
	if ( (iColors > 256 || iColors < 0) && 
		pDIB->GetBitmapInfoAddress()->bmiHeader.biBitCount <= 8 )
	{
		ChDibBmp* pDibNew = new ChDibBmp();
		ASSERT( pDibNew );
		pDibNew->Create( pDIB->GetBitmapInfoAddress()->bmiHeader.biWidth,
						pDIB->GetBitmapInfoAddress()->bmiHeader.biHeight,
						24 );
		pDIB->CopyBits( pDibNew, 
                    0, 0,
                    pDIB->GetBitmapInfoAddress()->bmiHeader.biWidth,  
                    pDIB->GetBitmapInfoAddress()->bmiHeader.biHeight,
                    0, 0 );
		delete pDIB;

		pDIB = pDibNew;

	} 
	m_pDibBkgnd = pDIB; 
	m_boolBackgroundDirty = true;
	Invalidate(true);
	UpdateWindow();
	return true;
	//DeferredNewBackground();
}

bool ChAnimView::DeferredNewBackground()
{
	ChDibBmp* pDIB = m_pDibBkgnd;

	m_boolBackgroundDirty = false;
    // Create a new buffer and palette
     if ( pDIB->GetBitmapInfoAddress()->bmiHeader.biBitCount <= 8 )
	 {
	   if (!Create(pDIB)) {
	        return false;
	    }

	    // Map the colors of the background DIB to
	    // the identity palette we just created for the background
	    pDIB->MapColorsToPalette(GetPalette());
	}
	else
	{
		m_bUseCreateDIBSection = false;

	    if (m_pOneToOneClrTab) free(m_pOneToOneClrTab);
		m_pOneToOneClrTab = 0;
	    if (m_pPal) delete m_pPal;
		m_pPal = 0;

	    if (m_pDIB) delete m_pDIB;
	    m_pDIB = new ChDibBmp;
        
        if( !m_pDIB->Create(pDIB->GetWidth(), pDIB->GetHeight(),
        			pDIB->GetBitmapInfoAddress()->bmiHeader.biBitCount ) )
		{
			return false;
		}
	    CSize sizeTotal;
	    sizeTotal.cx = m_pDIB->GetWidth();
	    sizeTotal.cy = m_pDIB->GetHeight();
	    SetScrollSizes(sizeTotal);

	}

    // Render the entire scene to the off-screen buffer
    Render();

    // Paint the off-screen buffer to the window
    //Draw();
	//Invalidate(true);

    return true;
}

// Render the scene to the off-screen buffer
// pClipRect defaults to NULL
void ChAnimView::Render(CRect* pClipRect)
{
    // make sure we have something to render to
    if (!m_pDIB) return;
    CRect rcDraw;
        
    // get the background DIB and render it
    m_pDibBkgnd->GetRect(&rcDraw);
    // If a clip rect was supplied use it
    if (pClipRect) {
        rcDraw.IntersectRect(pClipRect, &rcDraw);
    }

    // draw the image of the DIB to the os buffer
    ASSERT(m_pDIB);
    m_pDibBkgnd->CopyBits(m_pDIB,       
                   rcDraw.left,
                   rcDraw.top,     
                   rcDraw.right - rcDraw.left,
                   rcDraw.bottom - rcDraw.top,
                   rcDraw.left, 
                   rcDraw.top);

#if 1
    // Render the sprite list from the bottom of the list to the top
    // Note that we always clip to the background DIB
    POSITION pos = m_spriteList.GetTailPosition();
    CSprite *pSprite;
    while (pos) {
        pSprite = m_spriteList.GetPrev(pos);
        pSprite->Render(m_pDIB, &rcDraw);
    }
#endif    
}

// Draw a section of the off-screen image buffer to the screen.
void ChAnimView::Draw(CDC* pDC, LPRECT pRect)
{
    CDC* pdc;
    CRect rcDraw;

	if(m_boolBackgroundDirty)
	{
		DeferredNewBackground();
	}

    // Make sure we have what we need to do a paint.

    if ( m_pDIB && !m_pOneToOneClrTab) 
    {
		if ( m_pDIB->GetBitmapInfoAddress()->bmiHeader.biBitCount <= 8  )
		{
			return;
		}
	}
	else if (!m_pDIB || !m_pOneToOneClrTab) 
	{

		return;
    }

    // See if a DC was supplied, and get one if not.
    if (pDC) {
        pdc = pDC;
    } else {
        pdc = GetDC();
		ChScrollWnd::OnPrepareDC(pdc);	// jwd
    }

    // See if a clip rect was supplied, and use the client area if not.
    if (pRect) {
        rcDraw = *pRect;			  // this is in logicals; jwd
    } else {
        GetClientRect(rcDraw);
		pdc->DPtoLP(LPRECT(rcDraw));  // fixed scrolling bug; jwd
    }

    // Get the clip box.
    CRect rcClip;
    pdc->GetClipBox(rcClip);

    // Create a rect for the DIB.
    CRect rcDIB;
    rcDIB.left = rcDIB.top = 0;
    rcDIB.right = m_pDIB->GetWidth() - 1;
    rcDIB.bottom = m_pDIB->GetHeight() - 1;

    // Find a rectangle that describes the intersection of the draw
    // rect, clip rect, and DIB rect.
    CRect rcBlt;
    rcBlt.IntersectRect(&rcDraw, &rcClip);
    rcBlt.IntersectRect(&rcBlt, &rcDIB);

    // Copy the update rectangle from the off-screen DC to the
    // window DC. Note that the DIB origin is the bottom-left corner.
    int w, h, xs, xd, yd, ys;
    w = rcBlt.right - rcBlt.left;
    h = rcBlt.bottom - rcBlt.top;
    xs = xd = rcBlt.left;
    yd = rcBlt.top;
    if (m_bUseCreateDIBSection) {
        ys = rcBlt.top;
    } else {
        ys = m_pDIB->GetHeight() - rcBlt.bottom;
    }

	// Center the image, if requested, and it's smaller than window
	if( m_boolCenterIt )
	{
		if(m_pDIB->GetWidth() - 1 < rcDraw.right - rcDraw.left)
		{
			xd +=  ((rcDraw.right - rcDraw.left) - (m_pDIB->GetWidth() - 1)) / 2;
		}
		if(m_pDIB->GetHeight() - 1 < rcDraw.bottom - rcDraw.top)
		{
			yd +=  ((rcDraw.bottom - rcDraw.top) - (m_pDIB->GetHeight() - 1)) / 2;
		}
	}

    // If we have a palette, select and realize it.
    CPalette* ppalOld = NULL;
    if(m_pPal) {
        ppalOld = pdc->SelectPalette(m_pPal, 0);
        pdc->RealizePalette();
    }

    BYTE* pBits;
    if (m_bUseCreateDIBSection) {
        HDC dcMem = ::CreateCompatibleDC(pdc->GetSafeHdc());
        HBITMAP hbmOld = (HBITMAP) ::SelectObject(dcMem, m_hbmSection);
        // Note: you do not need to select the palette into
        // the memory DC because the DIB section is using palette
        // index values not colors.
        ::BitBlt(pdc->GetSafeHdc(),
                 xd, yd,
                 w, h,
                 dcMem,
                 xs, ys,
                 SRCCOPY);
        ::SelectObject(dcMem, hbmOld);
        ::DeleteDC(dcMem);
    } else {
        pBits = (BYTE*)m_pDIB->GetBitsAddress();
        ::StretchDIBits(pdc->GetSafeHdc(),
                    xd,                 // Destination x
                    yd,                 // Destination y
                    w,                  // Destination width
                    h,                  // Destination height
                    xs,                 // Source x
                    ys,                 // Source y
                    w,                  // Source width
                    h,                  // Source height
                    pBits,              // Pointer to bits
                    m_pOneToOneClrTab ? m_pOneToOneClrTab :
               		m_pDIB->GetBitmapInfoAddress(),  // BITMAPINFO
                    m_pOneToOneClrTab ? DIB_PAL_COLORS : DIB_RGB_COLORS,     // Options
                    SRCCOPY);           // Rop
    }

    // Select old palette if we altered it.
    if (ppalOld) pdc->SelectPalette(ppalOld, 0);

    // Release the DC if it was one we created.
    if (!pDC) ReleaseDC(pdc);
}

// Add a region to the dirty list.
void ChAnimView::AddDirtyRegion(CRect* prcNew)
{
    // Get the rectangle currently at the top of the list.
    POSITION pos = m_DirtyList.GetHeadPosition();
    if (pos) {
        CRect* prcTop = (CRect*)m_DirtyList.GetNext(pos);
        CRect rcTest;
        // If the new one intersects the top one merge them.
        if (rcTest.IntersectRect(prcTop, prcNew)) {
            prcTop->UnionRect(prcTop, prcNew);
            return;
        }
    }
    // List is empty, or there was no intersection.
    CRect* prc = new CRect;
    *prc = *prcNew; // Copy the data.
    // Add a new rectangle to the list.
    m_DirtyList.AddHead((CObject*)prc);
}

// Render and draw all the dirty regions.
void ChAnimView::RenderAndDrawDirtyList()
{
    POSITION pos = m_DirtyList.GetHeadPosition();
    // Render all the dirty regions.
    while (pos) {
        // Get the next region.
        CRect* pRect = (CRect*)m_DirtyList.GetNext(pos);
        // Render it.
        Render(pRect);
    }
    // Draw all the dirty regions to the screen.
    while (!m_DirtyList.IsEmpty()) {
        // Get the next region.
        CRect* pRect = (CRect*)m_DirtyList.RemoveHead();
        Draw(NULL, pRect);
        // Done with it.
        delete pRect;
    }
}

// Empty the dirty list.
void ChAnimView::EmptyDirtyList()
{
    while (!m_DirtyList.IsEmpty()) {
        CRect* prc = (CRect*)m_DirtyList.RemoveHead();
        delete prc;
    }
}


void ChAnimView::Animate( bool boolRun)
{
	if( boolRun )
	{
	    if (m_uiTimer) return;
	    m_uiTimer = SetTimer(1, 55, NULL);    
	    //m_uiTimer = SetTimer(1, 100, NULL);    
	}
	else
	{
	    if (m_uiTimer)
	    {
	    	KillTimer(1);
			m_uiTimer = 0;
		}
	}
}

						// called by system timer mgr (to be defined)
void ChAnimView::OnTick()
{
    if (!m_characters.IsEmpty())
    {// Walk the character list and update any which are moving
		ChPosition pos = m_characters.GetHeadPosition();
	// !!!!!!!!! ?????????? need to change for varying framerates
		chuint32 luCurrMsec = 1000; 
	    while (pos) {
	        ChAnimCastMember* pch = m_characters.GetNext(pos);
			pch->Tick(luCurrMsec);
	    }
	    // redraw the changes
	    RenderAndDrawDirtyList();
	}

	// Now set the cursor; Animating may bring an anchor under the cursor
	POINT	point;
	::GetCursorPos( &point );
								// Need to make sure it's in our area first
	LRESULT hitCode = ::SendMessage( GetSafeHwnd(), 
									 WM_NCHITTEST, 
									 0, 
									 MAKELONG((short)point.x, (short)point.y));
	if( HTCLIENT == hitCode)
	{
		ScreenToClient( &point );

		SetCursor( point );
	}
}

ChAnimView* ChAnimView::AnimateCharacter( chuint32 luId, bool boolRun )
{
    ChAnimCastMember* pch = FindChar(luId);
    
    if (pch) pch->Animate(boolRun);

	return this;
}

ChAnimView* ChAnimView::ShowCharacter( chuint32 luId, bool boolShow )
{
    ChAnimCastMember* pch = FindChar(luId);
    
    if (pch) pch->Show(boolShow);

	return this;
}

ChAnimCastMember * ChAnimView::FindChar(chuint32 luId)
{
	if (m_characters.IsEmpty()) return 0;

	ChPosition pos = m_characters.GetHeadPosition();

    while (pos) {
        ChAnimCastMember* pch = m_characters.GetNext(pos);
		if( pch->GetId() == luId) return pch;
    }

	return 0;
}
// A new sprite has been added to the document
void ChAnimView::NewSprite(CSprite* pSprite)
{   
    // map the colors in the sprite DIB to the
    // palette in the off-screen buffered view
    if (m_pPal) {
        pSprite->MapColorsToPalette(m_pPal);
    }

    // Render the scene
    Render();

    // Draw the new scene to the screen
    Draw();
}


// add a cast member to the view; checks for uniqueness by id and replaces if
// a dupe. consumes pChar and deletes it when char is deleted or replaced
void ChAnimView::AddCharacter( ChAnimCastMember * pChar )
{
	ChAnimCastMember * pOldChar = FindChar( pChar->GetId() );

	if (pOldChar)
	{
		DeleteCharacter(pChar->GetId());
	}

	m_characters.AddTail( pChar );
	pChar->OnAddition( this );

	// Add it to the character list
	return;
}

ChAnimView* ChAnimView::DeleteCharacter( chuint32 luId )
{
	if (m_characters.IsEmpty()) return this;

	ChPosition pos = m_characters.GetHeadPosition();
    while (pos)
    {
 		ChPosition oldpos = pos;
    	ChAnimCastMember* pch = m_characters.GetNext(pos);
		if( pch->GetId() == luId) 
		{
			m_characters.Remove(oldpos);
			delete pch;
		}
    }
	return this;
}

bool ChAnimView::AddAnchor( ChAnimAnchor* pAnchor, bool boolPutInPending )
{															  
	  // set back ptr; need for notification decency
	pAnchor->SetView(this);

	// Add to the rect anchor list, or try to add to a cast member
	if( pAnchor->GetType() == ChAnimAnchor::rect )
	{
		ChAnimAnchor** ppExisting;								  
		if	(ppExisting = m_Anchors.Find(pAnchor->GetId()))
		{
			//delete *ppExisting;
			m_Anchors.Delete(pAnchor->GetId());
		}
		m_Anchors.Insert(pAnchor->GetId(), pAnchor);
	}
	else
	{
		// find the cast member
		ChAnimCastMember * pCast = FindChar( pAnchor->GetHotCastId() );

		if (pCast)
		{
			pCast->SetAnchor( pAnchor );
		}
		else if (boolPutInPending)
		{
			if(!m_pCastAnchors)
			{
				m_pCastAnchors = new ChPtrList<ChAnimAnchor>;
			}
			if(m_pCastAnchors->IsEmpty() || !(m_pCastAnchors->Find( pAnchor )))
			{
				m_pCastAnchors->AddHead( pAnchor );
			}
			return false;	// not added; put on pending list
		}
		else  return false; // don't put on pending, nothing done
		
	}
	return true;
}
bool ChAnimView::DeleteAnchor( const chuint32 luId )
{
	 ChAnimAnchor** ppExisting;
	 if	(ppExisting = m_Anchors.Find(luId))
	 {
	 	delete *ppExisting;
		m_Anchors.Delete(luId);
	 }
	return true;
}

bool ChAnimView::DeleteAnchors(  )
{
	 
	m_Anchors.Erase(); // destruct method should delete anchors
	 
	return true;
}


void ChAnimView::LoadAnchors(const string& strFilename)		 // Go away???
{	
	ifstream	anchorFile( strFilename );

	//ChAnimParser parser( this, (iostream *)(&anchorFile), pInfo->GetHTTPConn() );
	ChAnimParser parser( this, (iostream *)(&anchorFile), 0, "");

	bool boolSuccess = !parser.interpret();		 // try new parser 1=> failed
	ASSERT(boolSuccess);		// rude, but only for debugging CAML

	#if 0	// old format  - not supported anymore
	{
		chuint32 id;
		chuint32 hotCastid;
		CRect rcHot;
		chuint32 castId;
		string strHint;
		chuint32 lCursor;
		ChAnimAnchor::type theType;   
		chint32 lStartCell;
		chint32 tmp;

		anchorFile.seekg(0, ios::beg);	

		anchorFile >> tmp;															  
		theType = (ChAnimAnchor::type)tmp;

		while (theType)
		{
			switch (theType)
			{
				case ChAnimAnchor::rect:
				{
				 	anchorFile >> id;
					anchorFile >> rcHot.left >> rcHot.top;
					anchorFile >> rcHot.right >> rcHot.bottom;
					anchorFile.eatwhite();
					anchorFile.get();	   // first quote
					anchorFile.get((strHint.GetBuffer(200)), 200, '"');
					strHint.ReleaseBuffer();
					anchorFile.get();	   // last quote
					ChAnimAnchor *pAnchor = new ChAnimAnchor(id, rcHot);
					anchorFile >> lCursor >> castId >> lStartCell;
					pAnchor->SetHint(strHint);
					pAnchor->SetCast(castId);
					pAnchor->SetStartFrame(lStartCell);
					pAnchor->SetCursorId(lCursor);

					AddAnchor(pAnchor);
					break;
				}
				case  ChAnimAnchor::cast:
				{
					anchorFile >> id;
					anchorFile >> hotCastid;
					anchorFile.eatwhite();
					anchorFile.get();	   // first quote
					anchorFile.get((strHint.GetBuffer(200)), 200, '"');
					strHint.ReleaseBuffer();
					anchorFile.get();	   // last quote
					ChAnimAnchor *pAnchor = new ChAnimAnchor(id, hotCastid);
					anchorFile >> lCursor >> castId >> lStartCell;
					pAnchor->SetHint(strHint);
					pAnchor->SetCast(castId);
					pAnchor->SetStartFrame(lStartCell);
					pAnchor->SetCursorId(lCursor);

					AddAnchor(pAnchor);
				
					break;
				}
			}
			anchorFile >> tmp;
			theType = (ChAnimAnchor::type)tmp;

		}
	}
	#endif	// 0 for old format
	
}


void ChAnimView::OnTimer(UINT nIDEvent) 
{
	OnTick();
}

void ChAnimView::OnDestroy() 
{
	ChGraphicView::OnDestroy();
	
    if (m_uiTimer) KillTimer(1);
	
}

void ChAnimView::OnLButtonDown(UINT nFlags, CPoint pt) 
{
	ChAnimAnchor *pHit;

	if (pHit = FindAnchor(pt))
	{
		pHit->Notify(pt);
	}	

}

void ChAnimView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	ChGraphicView::OnLButtonUp(nFlags, point);
}

void ChAnimView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	//ChGraphicView::OnMouseMove(nFlags, point);
}

BOOL ChAnimView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if(HTCLIENT == nHitTest)
	{
		POINT	point;
		::GetCursorPos( &point );
		ScreenToClient( &point );

		return SetCursor( point );
	}
	else return ChGraphicView::OnSetCursor(pWnd, nHitTest, message);
}

BOOL ChAnimView::SetCursor( POINT& pointInClient )
{
	HCURSOR hCursor = GetCursor(m_cursorId);

	ChAnimAnchor *pHit = 0;
	chuint32	anchorId = 0;		// compare this to last anchor with hint displayed


	pHit = FindAnchor( pointInClient );

	if (pHit)
	{
		hCursor = GetCursor(pHit->GetCursorId());
		anchorId = pHit->GetId();
	}
	else
	{
		anchorId = 0;
	}
	::SetCursor(hCursor);

	if (anchorId != m_anchorId)
	{
		string strHint = "";
		if(anchorId)
		{
			strHint = pHit->GetHint();
		}
		((CFrameWnd*)(AfxGetMainWnd()))->SetMessageText(LPCTSTR(strHint));
		m_anchorId = anchorId;
	}

	return true;
	//return ChGraphicView::OnSetCursor(pWnd, nHitTest, message);
}

void ChAnimView::UpdateAnchorList()
{			   // !!!!!!!!!!!!!!!!!
	if ( m_pCastAnchors	)
	{
		ChPosition pos = m_pCastAnchors->GetHeadPosition();
	    while (pos)
	    {
			ChPosition oldPos = pos;
	        ChAnimAnchor* pAnchor = m_pCastAnchors->GetNext(pos);
			if (AddAnchor( pAnchor, false))
			{
				m_pCastAnchors->Remove( oldPos );
			}
	    }
		
		if(m_pCastAnchors->IsEmpty())
		{
			delete m_pCastAnchors;
			m_pCastAnchors = 0;
		}
	}
}

// Important! pt is in window coords (not scrolled)
ChAnimAnchor *ChAnimView::FindAnchor( const CPoint & pt )
{
	CPoint pointInView = GetDeviceScrollPosition( ) + CSize(pt);	 // now it's in view coords
	ChAnimAnchor *pHit = 0, *pTry;

	if (m_pCastAnchors) UpdateAnchorList();		// make sure all anchors are
												// associated with chars, if possible
	// first try the sprite/char type of anchors
	// by walking the sprite list.
	// If the sprite has an anchor, hittest it
    POSITION pos = m_spriteList.GetHeadPosition();
    CPhasedSprite *pSprite;
	

    while (pos)
    {
        pSprite = (CPhasedSprite *)(m_spriteList.GetNext(pos));
        pTry = pSprite->GetCast()->GetAnchor();	// any sprite on list -MUST- have a
												// cast member, but not necessarily an 
												// anchor.
		if (pTry)
		{
			if(pSprite->HitTest(pointInView))
			{
				pHit = pTry;
				break;
			}
		} 
    }

	if (!pHit)		// no hit in sprites
	{
		m_HitFinder.Initialize(pointInView);

		m_Anchors.Infix( m_HitFinder );
		pHit = m_HitFinder.GetHit();
		// Optimization trick; force this node to front, so we find faster
		if (pHit)
		{
			m_Anchors.Find(pHit->GetId());
		}
	}
	return pHit;
}


/*----------------------------------------------------------------------------
	ChAnimAnchor class
----------------------------------------------------------------------------*/

ChAnimAnchor::ChAnimAnchor() :
					m_id( 0 ),
					m_rcHot( 0, 0, 0, 0 ),
					m_cursor( CH_CURSOR_PICK ),
					m_type( rect ),
					m_pView( 0 ),
					m_pHotCast( 0 ),
					m_hotCastId( 0 ),
					m_pCast( 0 ),
					m_castId( 0 ),
					m_lStartCell( 0 )
{
}


ChAnimAnchor::ChAnimAnchor( chuint32 id, CRect& rcHot ) :
					m_id( id ),
					m_rcHot( rcHot ),
					m_cursor( CH_CURSOR_PICK ),
					m_type( rect ),
					m_pView( 0 ),
					m_pHotCast( 0 ),
					m_hotCastId( 0 ),
					m_pCast( 0 ),
					m_castId( 0 ),
					m_lStartCell( 0 )
{
}


ChAnimAnchor::ChAnimAnchor( chuint32 id, chuint32 hotCastId ) :
					m_id( id ),
					m_rcHot( 0, 0, 0, 0 ),
					m_cursor( CH_CURSOR_PICK ),
					m_type( cast ),
					m_pView( 0 ),
					m_pHotCast( 0 ),
					m_hotCastId( hotCastId ),
					m_pCast( 0 ),
					m_castId( 0 ),
					m_lStartCell( 0 )
{
}


ChAnimAnchor::~ChAnimAnchor()
{
	m_pCast = 0;
	m_castId = 0;
}


bool ChAnimAnchor::Notify( CPoint& pt )
{
	ChAnimCastMember *pCast = GetCast();
	if (pCast)
	{
		// default is to toggle animation
		pCast->Animate(!(pCast->IsAnimating()));
		pCast->SetCell(m_lStartCell);
	}
	Post(pt);		   // needs to be here in case they delete us during post

	return true; // did something
}

bool ChAnimAnchor::Post(CPoint &point)	
{
	//ChAnchorEventMsg msg( m_id, point );
	//m_pModule->Post(event);
	//m_pModule->Post(CH_MSG_ANCHOR_EVENT, 1, m_id);
	//ChCore::GetCore()->DispatchMsg( m_moduleId, msg ); // client only right now
	if( !m_strCmdArg.IsEmpty())
	{
		bool boolProcessed;
		ChCmdMsg msg( m_strCmdArg );
		m_pView->GetCmdHookMgr()->Dispatch( msg, boolProcessed );
	}
	return true;
}

ChAnimCastMember * ChAnimAnchor::GetCast()
{
	if ( m_pCast ) return m_pCast;
	else if (m_castId)
	{
		// ask the view to find it based on id, and cache it for future
		return( m_pCast = m_pView->FindChar(m_castId) );
	}
	return 0; 
}


void ChAnimAnchor::SetCursor( string& cursorName )
{
	chuint32 id = CH_CURSOR_STD_PTR;
	
	for (int	j = 0;aChAnimPointerNames[j].key; j++)
	{
		if (!cursorName.CompareNoCase(aChAnimPointerNames[j].strStr))
		{
			id = aChAnimPointerNames[j].key;
			break;
		}
	}
	SetCursorId(id);
}
