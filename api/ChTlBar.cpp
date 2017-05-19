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

	This file consists of the implementation of the ChAccountInfo class.

----------------------------------------------------------------------------*/


#include "headers.h"

#include <afxpriv.h>	
#include <ChTlBar.h>            

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA    
#endif


// Implementation of the ToolTip window

CToolTip::CToolTip(CWnd* pParentWnd)
{
	// Initialize member variables
	m_uShowToolTip =	0; 
	// Initial text
	m_strTipText = 	""; 
	// use default font
	m_pFont = 		NULL;  
	// clearence around the text
	m_uClearance = 	2;
	
	// Get the height and width of the cursor
	m_uCursorHt = ::GetSystemMetrics( SM_CYCURSOR ) >> 1;
	m_uCursorWd = ::GetSystemMetrics( SM_CXCURSOR ) >> 2;      
	
			
	// It has a yellow solid fill color which displays black text  
	// This is the color used by tool tips under MFC 3.0, lets be consistant
	m_hBrush = CreateSolidBrush(RGB(255, 255, 128));

	// Register a new class for the tool tip window.
	CString strWndClass = AfxRegisterWndClass( CS_SAVEBITS, 0, m_hBrush, 0);
	
	// Create the tool tip window
	CreateEx(0, strWndClass, NULL, WS_POPUP | WS_CLIPSIBLINGS | WS_BORDER, 
										0, 0, 0, 0, pParentWnd->m_hWnd, 0);
}

CToolTip::~CToolTip()
{
	// Clean up
	if ( m_pFont )
	{
		m_pFont->DeleteObject();
		delete m_pFont;
	} 
}

int CToolTip::OnCreate(LPCREATESTRUCT lpCreateStruct)
{       
	// call the base class
	if ( CWnd::OnCreate(lpCreateStruct) == -1 )
		return -1;
		
	// Create the font to use in tooltip windows. 
	// Initially a 8 point MS Sans Serif font
	LOGFONT		lf;
	CClientDC 	dc(this);
	int 		nFontSize = -1 * (::GetDeviceCaps(dc.m_hDC, LOGPIXELSY) * 8 / 72);
			
	m_pFont = new CFont();
	
	// Clear the font structure
	ChMemClearStruct( &lf );
	
	lf.lfHeight = nFontSize;
	lf.lfWeight = FW_REGULAR;
	lf.lfCharSet = ANSI_CHARSET;
	lf.lfOutPrecision = OUT_STROKE_PRECIS;
	lf.lfClipPrecision = CLIP_STROKE_PRECIS;
	lf.lfQuality = DEFAULT_QUALITY;
	lf.lfPitchAndFamily = FF_DONTCARE;
	lstrcpy(lf.lfFaceName, "MS Sans Serif");
	
	// Create the font font the tool tip window
	m_pFont->CreateFontIndirect( &lf );
						
	return 0;	
}
						
void CToolTip::OnPaint()
{
	CPaintDC dc(this);
	
	// Select the font 
	CFont* pOldFont = dc.SelectObject(m_pFont);
	
	// Get rect
	RECT rect;
	GetClientRect(&rect);
	
	// Draw the text in black
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(0, 0, 0));
	dc.DrawText(m_strTipText, m_strTipText.GetLength(),
		 &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	
	// Restore the dc
	dc.SelectObject(pOldFont);
}


void CToolTip::ShowToolTip(UINT nID )
{
	// Show the tool tip window, displaying the 
	// text for the current ID
	
	// Is this a new button ?
	if ( nID == m_uShowToolTip )
	{
		return;
	}
		
	m_uShowToolTip = nID;  
	
	 
	//Load the text to display  from the string table and get the sub-string to display					
	CString strToolTip;
	int iPos;  // Position of the tool tip text 
	// Get the string to display
	if ( strToolTip.LoadString( nID ) 
			&& (iPos = strToolTip.ReverseFind( TEXT( '\n' )) + 1) > 0)
	{ 
		// Get the sub-string
		m_strTipText = strToolTip.Right( strToolTip.GetLength() - iPos );	
		
		// Determine size of  window based on size of text
		CClientDC dc(this);
		CFont* pOldFont = dc.SelectObject(m_pFont);
		CSize size = dc.GetTextExtent(m_strTipText, m_strTipText.GetLength() );
			
		// Set the window to be at the tail of the cursor
		POINT point;
		GetCursorPos(&point);

		SetWindowPos(&wndNoTopMost, point.x +  m_uCursorWd, point.y + m_uCursorHt, 
				 size.cx + (2 * m_uClearance), size.cy + (2 * m_uClearance),
				  SWP_DRAWFRAME | SWP_NOACTIVATE | SWP_SHOWWINDOW);
						
		// Clean-Up
		dc.SelectObject(pOldFont);
				
		// Invalidate this window and re-paint
		InvalidateRect(NULL);
		UpdateWindow();
	}
}

void CToolTip::HideToolTip()
{
	if ( IsWindowVisible() )
	{
		ShowWindow(SW_HIDE);
		m_uShowToolTip = 0;
	}
}

BEGIN_MESSAGE_MAP(CToolTip, CWnd)
	//{{AFX_MSG_MAP(CToolTip)
	ON_WM_PAINT()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


IMPLEMENT_DYNCREATE(ChToolBar, CToolBar)

ChToolBar::ChToolBar()
	 : CToolBar()
{
	// Initialize member variables
	m_pToolTipWnd = 	NULL;	// window not yet created
	m_bEnableToolTips =	FALSE;	// ToolTips are not enabled (until  window is created)
    m_bEnableFlyBy =	FALSE;	// FlyBy's help
    m_ptCurPos =		0, 0;	// No last cursor position
    m_uShowTip =		0;		// No current tip to be shown
    m_uWait =			500;	// 500 milliseconds before time is shown
    m_bMouseDown =		FALSE;	// Left mouse button is not down to start with
    m_dwStyle	 = 		0;		// style of the tool bar
	m_uBorderWidth = ::GetSystemMetrics( SM_CXBORDER );
}

ChToolBar::~ChToolBar()
{
	// Clean up
	if ( m_pToolTipWnd )
	{
		m_pToolTipWnd->DestroyWindow();
		delete m_pToolTipWnd; 
	}
}

ChToolBar::Create(CWnd* pParentWnd, DWORD dwStyle, UINT nID)
{
	// Call base class first 
	if ( dwStyle & CBRS_TOOLTIPS )
	{
		m_bEnableToolTips =	TRUE;	// Enable tool tips
		dwStyle &= ~CBRS_TOOLTIPS;
	}
	
	if ( dwStyle & CBRS_FLYBY )
	{
		m_bEnableFlyBy =	TRUE;	// Enable fly by
		dwStyle &= ~CBRS_FLYBY;
	}
	
	// save the toolbar style
	m_dwStyle = dwStyle;

	bool bRetVal = CToolBar::Create(pParentWnd, dwStyle, nID);
	
	// Create the  tool tip window. It is not initially visible
	m_pToolTipWnd = new CToolTip(this);
	
	// Did we create the window
	if ( !m_pToolTipWnd )
	{
		m_bEnableToolTips = FALSE;
	}
		
	// Return the result of CToolBar::Create()
	return bRetVal;
}  

ChSize ChToolBar::CalcFixedLayout(bool bStretch, bool bHorz)
{
	ASSERT_VALID(this);

	ChSize size;
	
 	size.cx = (bStretch && bHorz ? 32767 : 0);
	size.cy = (bStretch && !bHorz ? 32767 : 0);

	CRect rect;
	rect.SetRectEmpty();        // only need top and left
	CalcInsideRect(rect);


	if (bHorz)
		size.cy = m_sizeButton.cy - rect.Height(); // rect.Height() < 0
	else
		size.cx = m_sizeButton.cx - rect.Width(); // rect.Width() < 0

	return size;
} 

// input Rect should be client rectangle size
void ChToolBar::CalcInsideRect(RECT& rect) const
{                  
	// inset the top and bottom.
	rect.left += m_cxLeftBorder;
	rect.top += m_cyTopBorder;
	rect.bottom -= m_cyBottomBorder;
}

         


void ChToolBar::OnLButtonDown(UINT nFlags, CPoint point)
{
	// Call base class first
	CToolBar::OnLButtonDown(nFlags, point);
	
	// Hide the tool tip when the mouse button is pressed
	m_bMouseDown = TRUE;
	if ( m_pToolTipWnd ) 
	{
		m_pToolTipWnd->HideToolTip();
	}
}

void ChToolBar::OnLButtonUp(UINT nFlags, CPoint point)
{
	// Call base class first
	CToolBar::OnLButtonUp(nFlags, point);
	
	// Hide the tool tip when the mouse button is pressed
	m_bMouseDown = FALSE;
	if ( m_pToolTipWnd )  
	{
		m_pToolTipWnd->HideToolTip();
	}
}

void ChToolBar::OnMouseMove(UINT nFlags, CPoint point)
{
	// Call base class first
	CToolBar::OnMouseMove(nFlags, point); 
	
	if( GetParent()->m_hWnd != ::GetActiveWindow() )
	{
		return;
	}
	
	// Get current toolbar button mouse is over. 0 if none
	UINT nID = GetToolBarBtnUnderMouse();
		
	if ( nID )
	{
		// Post WM_MENUSELECT to parent window. This allows updating of status bar
		if ( m_bEnableFlyBy )
		{     
			GetParent()->SendMessage( WM_SETMESSAGESTRING, nID ); 
			#if 0
			CWnd * pMain = GetParent();
			CMenu* pMenu = pMain->GetMenu();
			if ( pMenu )                
			{
				pMain->SendMessage( WM_MENUSELECT, nID, 
					MAKELONG(pMenu->GetMenuState(nID, MF_BYCOMMAND), 
					pMenu->m_hMenu));
			} 
			#endif
		}
		
		// if this is a new id hide the tool tip
		if ( nID != m_uShowTip && m_pToolTipWnd )
		{
			m_pToolTipWnd->HideToolTip();
		}
			
		// Set m_uShowTip, x Pixel to display and timer
		if ( m_bEnableToolTips )
		{
			m_ptCurPos = point;
			ClientToScreen(&point);
			m_uShowTip = nID;
			SetTimer(1, m_uWait, NULL);
			return;
		}
	}    
	else
	{
		if ( m_bEnableFlyBy )
		{     
			GetParent()->SendMessage( WM_SETMESSAGESTRING, AFX_IDS_IDLEMESSAGE ); 
		}
	}
	
	// If we made it this far, we need to hide the current tip (if any)
	if ( m_pToolTipWnd )
		m_pToolTipWnd->HideToolTip();
}

void ChToolBar::OnTimer(UINT nIDEvent)
{
//	CWnd* pMain = AfxGetMainWnd();
	CWnd* pMain = GetParent();
	if ( m_pToolTipWnd && pMain->IsWindowEnabled() && 
			pMain->m_hWnd == ::GetActiveWindow() && 
			!pMain->IsIconic() && !m_bMouseDown)
	{
		// Show tip if cursor has not moved since timer was set
		POINT ptCur;
		::GetCursorPos(&ptCur);
		ScreenToClient(&ptCur);
		if ( m_ptCurPos == ptCur ) 
		{ // Show the tool tip
			m_pToolTipWnd->ShowToolTip(m_uShowTip );
		}
	}
		
	// Always kill the timer
	KillTimer(nIDEvent);
}

LRESULT ChToolBar::OnIdleUpdateCmdUI(WPARAM wParam, LPARAM lParam)
{
	
	if ( m_pToolTipWnd )
	{
		POINT 	ptCur;
		RECT	rToolBar;
		::GetCursorPos(&ptCur);
		GetWindowRect(&rToolBar);
		if ( !(::PtInRect(&rToolBar, ptCur)) || GetParent()->m_hWnd != ::GetActiveWindow() )  
		{
			m_pToolTipWnd->HideToolTip();
			if ( m_bEnableFlyBy )
			{     
				//GetParent()->SendMessage( WM_SETMESSAGESTRING, AFX_IDS_IDLEMESSAGE ); 
			}
		}
	}

	return CToolBar::OnIdleUpdateCmdUI(wParam, lParam);
}   



BEGIN_MESSAGE_MAP(ChToolBar, CToolBar)
	//{{AFX_MSG_MAP(CToolTipBar)
	ON_MESSAGE(WM_IDLEUPDATECMDUI, OnIdleUpdateCmdUI)
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// private function

UINT ChToolBar::GetToolBarBtnUnderMouse()
{
	// Return the menu ID the mouse is over (0 if none)
	RECT rItem;
	UINT nID = 0, nStyle = 0;
	int  nImage = 0;
	
	// Get the current mouse position
	POINT point;
	GetCursorPos(&point);
	
	// Get the toolbar rect
	RECT rToolBar;
	GetWindowRect(&rToolBar);
				
	for ( int i = 0; i < GetCount(); i++ )
	{
		GetItemRect(i, &rItem);
		ClientToScreen(&rItem);
		if ( ::PtInRect(&rItem, point) != 0 )
		{
			// We have found a item in the CToolBar that we are over
			// Is it a separator? (Values passed by reference)
			GetButtonInfo(i, nID, nStyle, nImage);
			if ( !(nStyle & TBBS_SEPARATOR) )
				return nID;
		}
	}
	
	// If we made it this far, we are not over a button
	return 0;
}
