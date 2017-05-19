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

	This file consists of the implementation of the ChGraphicView view class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChGrVw.cpp,v 2.15 1996/07/02 19:41:15 pritham Exp $

#include "grheader.h"
#include "ChGrMod.h"
#include "ChGrVw.h"

#include <ChDibBmp.h>

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA    
#endif

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define CH_TXTVW_NEWLINE			0x0D	/* LF - line feed  */
#define CH_TXTVW_TAB				0x09	/* HT - tabs  */


/*----------------------------------------------------------------------------
	ChGraphicView class
----------------------------------------------------------------------------*/

#if defined( CH_VRML_VIEWER )
IMPLEMENT_DYNCREATE(ChGraphicView, ChViewBaseClass)
#endif


BEGIN_MESSAGE_MAP(ChGraphicView, ChViewBaseClass)
    //{{AFX_MSG_MAP(ChGraphicView)
    ON_WM_PALETTECHANGED()
    ON_WM_QUERYNEWPALETTE()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// ChGraphicView construction/destruction

#if defined( CH_VRML_VIEWER ) || defined( CH_VRML_PLUGIN )
ChGraphicView::ChGraphicView() : m_pPal( 0 )
#else
ChGraphicView::ChGraphicView( ChGraphicMainInfo *pInfo ) : 
					m_pPal( 0 ),
					m_pGraphicInfo( pInfo )
#endif
{
}


ChGraphicView::~ChGraphicView()
{
    if (m_pPal)
    {
    	delete m_pPal;
    	m_pPal = 0;
    }
}


#if !defined( CH_VRML_VIEWER ) && !defined( CH_VRML_PLUGIN )

void ChGraphicView::GetIdealSize( ChSize& size )
{
}


void ChGraphicView::OnFrameDisconnect( const ChModuleID& idNewModule )
{
											// We're losing the pane
	GetMainInfo()->SetHidden();
}


#endif	// !defined( CH_VRML_VIEWER ) && !defined( CH_VRML_PLUGIN )


#if defined( CH_MSW )

bool ChGraphicView::Create( const CRect& rtView, CWnd* pParent, DWORD dwStyle,
						UINT uiID )
{
	#if defined( CH_VRML_VIEWER )  || defined(CH_VRML_PLUGIN )
	return ChViewBaseClass::Create( "", "", dwStyle, rtView, pParent, uiID );
	#else
	return ChViewBaseClass::Create( "", dwStyle, rtView, pParent, uiID );
	#endif
}
#endif

/////////////////////////////////////////////////////////////////////////////
// ChGraphicView drawing

void ChGraphicView::OnInitialUpdate()
{
#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
    CSize sizeTotal;
    sizeTotal.cx = 640;
    sizeTotal.cy = 480;
    SetScrollSizes(sizeTotal);
	#endif
}

void ChGraphicView::OnDraw(CDC* pDC)
{
    Draw(pDC);
}

bool ChGraphicView::IsCurrent()
{
	#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
		ChPane*		pPane;

		pPane = m_pGraphicInfo->GetCore()->GetPaneMgr()->
					FindPane( ChPaneMgr::strGraphicName );

		return pPane->GetWindow() == this;
	#else
		return ( true );
	#endif
}


/////////////////////////////////////////////////////////////////////////////
// ChGraphicView diagnostics

#ifdef _DEBUG
void ChGraphicView::AssertValid() const
{
    CWnd::AssertValid();
}

void ChGraphicView::Dump(CDumpContext& dc) const
{
    CWnd::Dump(dc);
}

CDocument* ChGraphicView::GetDocument() // Non-debug version is inline
{
    return 0;
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// ChGraphicView message handlers

// Draw a section of the off-screen image buffer to the screen.	- moved to ChAnimView
void ChGraphicView::Draw(CDC* pDC, LPRECT pRect)
{

}

void ChGraphicView::OnPaletteChanged(CWnd* pFocusWnd)
{
    // See if the change was caused by us and ignore it if not.
    if (pFocusWnd != this) 
    {
        //OnQueryNewPalette();	// This works if there is only one
		// palette fort thr appliation
	    if (m_pPal) 
	    {
	        CDC*	pDC = GetDC();

	        UINT	u = pDC->RealizePalette();


			if ( u )
			{  	// colors changed
	        	InvalidateRect( 0, true );		// Repaint the lot
			}
		
	        ReleaseDC( pDC );
		}
    }
}

// Note: Windows actually ignores the return value.
BOOL ChGraphicView::OnQueryNewPalette()
{
    // We are going active so realize our palette.
    if (m_pPal) {
        CDC* pdc = GetDC();
        CPalette* poldpal = pdc->SelectPalette(m_pPal, false);
        UINT u = pdc->RealizePalette();
        ReleaseDC(pdc);
        if (u != 0) {
            // Some colors changed so we need to do a repaint.
            InvalidateRect(NULL, true); // Repaint the lot.
            return true; // Say we did something.
        }
    }
    return false; // Say we did nothing.
}

// Update the view to reflect some change in the doc.
void ChGraphicView::OnUpdate(CView* pSender,
                        LPARAM lHint,
                        CObject* pHint)
{
    // Render and draw everything.
    Render();
    Draw();
}

