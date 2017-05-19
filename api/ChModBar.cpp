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

	Implementation for the ChModuleBar class.  This class is the parent for
	all tear-off bar type classes used by modules.  This class is MSW-only.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/api/ChModBar.cpp,v 2.4 1995/10/24 00:04:55 coyote Exp $

#error "This file is defunct.  Please don't use it.  -- Ron Lussier"

#include "headers.h"

#include <ChCore.h>
#include <ChPerFrm.h>
#include <ChModBar.h>
#include <ChTlBar.h>

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA    
#endif

/*----------------------------------------------------------------------------
	ChModuleBar statics
----------------------------------------------------------------------------*/

static UINT BASED_CODE buttons[] =
{
	ID_SEPARATOR
};


/*----------------------------------------------------------------------------
	ChModuleBar class
----------------------------------------------------------------------------*/

ChModuleBar::ChModuleBar( chflag32 flStyle ) :
				ChToolBar(), m_sCount( 0 ), m_flStyle( flStyle ),
				m_hWndFocus( 0 )
{
	CRect	rtOriginal( 0, 0, 100, 100 );
	CRect	rtTest( rtOriginal );
	DWORD	dwVersion = ::GetVersion();
	bool	boolWin4 = (BYTE)dwVersion >= 4;
	
	#if defined( WIN32 )
	CalcInsideRect( rtTest, true );
	#else
	CalcInsideRect( rtTest );
	#endif

	m_sBorderVert = (chint16)(rtTest.top - rtOriginal.top);
	m_sBorderHorz = (chint16)(rtTest.left - rtOriginal.left);

	m_sBorderHorz2 = GetSystemMetrics( SM_CXBORDER );
	if (boolWin4)
	{
		m_sBorderHorz2 *= 2;
	}

	m_sBorderVert2 = GetSystemMetrics( SM_CYBORDER );
	if (boolWin4)
	{
		m_sBorderVert2 *= 2;
	}
}


ChModuleBar::~ChModuleBar()
{
}


BEGIN_MESSAGE_MAP( ChModuleBar, ChToolBar )
	//{{AFX_MSG_MAP(ChModuleBar)
	ON_WM_ACTIVATE()
	ON_WM_SETFOCUS()
	ON_WM_MOUSEACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


bool ChModuleBar::Create( string strTitle, CWnd* pParent, chint32 lWidth,
							chint32 lHeight, chflag32 flDockSides )
{
	bool		boolSuccess;
	ChCore*		pCore = ChCore::GetCore();
	CFrameWnd*	pFrameWnd = pCore->GetFrameWnd();
	DWORD		dwStyle;

	m_lWidth = lWidth;
	m_lHeight = lHeight;

	if (0 == pParent)
	{
		pParent = pFrameWnd;
	}

	if (dockTop == flDockSides)
	{
		dwStyle = CBRS_TOP;
	}
	else if (dockLeft == flDockSides)
	{
		dwStyle = CBRS_LEFT;
	}
	else if (dockRight == flDockSides)
	{
		dwStyle = CBRS_RIGHT;
	}
	else
	{
		dwStyle = CBRS_BOTTOM;
	}

	if (ChToolBar::Create( pParent, dwStyle, 0 ))
	{
		SetWindowText( strTitle );
											// Support docking with this bar
        #if defined( WIN32 )
		{
			DWORD		dwDockStyle = 0;

			if (flDockSides & dockTop)
			{
				dwDockStyle |= CBRS_ALIGN_TOP;
			}

			if (flDockSides & dockBottom)
			{
				dwDockStyle |= CBRS_ALIGN_BOTTOM;
			}

			if (flDockSides & dockLeft)
			{
				dwDockStyle |= CBRS_ALIGN_LEFT;
			}

			if (flDockSides & dockRight)
			{
				dwDockStyle |= CBRS_ALIGN_RIGHT;
			}

			EnableDocking( dwDockStyle );
		}
		#endif	// defined( WIN32 )

		if (lHeight)
		{									// Set the height of the toolbar
			SetHeight( lHeight );
		}

		SetBarStyle( GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY );

		#if defined( WIN32 )
		{
											/* Dock the control bar onto the
												parent */
			pFrameWnd->DockControlBar( this );
		}
		#endif	// defined( WIN32 )

		boolSuccess = true;
	}
	else
	{
		boolSuccess = false;
	}

	return boolSuccess;
}


CSize ChModuleBar::CalcFixedLayout( bool boolStretch, bool boolHorz )
{
	CSize	sizeToolbar;
	chint32	lWidth = m_lWidth;
	chint32	lHeight = m_lHeight;
    
	if ((0 == lHeight) || (0 == lWidth))
	{
		sizeToolbar = ChToolBar::CalcFixedLayout( boolStretch, boolHorz );
	}     

	if (0 == lHeight)
	{
		lHeight = sizeToolbar.cy;
	}

	if (0 == lWidth)
	{
		lWidth = sizeToolbar.cx;
	}

	return CSize( (int)lWidth, (int)lHeight );
}


void ChModuleBar::DoPaint( CDC* pDC )
{
	if (m_sCount)
	{
		ChToolBar::DoPaint( pDC );
	}
	else
	{
		CControlBar::DoPaint( pDC );		// Draw border
	}
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChModuleBar::HitTest

	point		||	Point, in window coordinates, to be tested.

------------------------------------------------------------------------------

	This virtual method tests the point for position over a bar element.

----------------------------------------------------------------------------*/

int ChModuleBar::HitTest( CPoint point )
{
	int		iHit;

	if (m_sCount)
	{
		iHit = ChToolBar::HitTest( point );
	}
	else
	{
		iHit = -1;							// Nothing hit
	}

	return iHit;
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChModuleBar::SetButtons

------------------------------------------------------------------------------

	This non-virtual method overrides the parent class' method to store
	the count of the number of buttons in the toolbar.

----------------------------------------------------------------------------*/

bool ChModuleBar::SetButtons( const UINT* pIDArray, int iCount )
{
	bool		boolSuccess = true;

	m_sCount = iCount;

	if (iCount)
	{
		boolSuccess = ChToolBar::SetButtons( pIDArray, iCount );
	}

	return boolSuccess;
}


void ChModuleBar::SaveState()
{
}

void ChModuleBar::RestoreState()
{
	ChCore	*pCore = ChCore::GetCore();

	ShowWindow( SW_SHOW );
	(pCore->GetFrameWnd())->RecalcLayout();
}
 
void ChModuleBar::CalcOutsideRect( CRect& rtFrame, bool boolHorz ) const
{
	DWORD dwStyle = m_dwStyle;
            
            
	ASSERT_VALID( this );
            
	if (dwStyle & CBRS_BORDER_LEFT)
	{
		rtFrame.left += m_sBorderHorz2;
	}

	if (dwStyle & CBRS_BORDER_TOP)
	{
		rtFrame.top += m_sBorderVert2;
	}

	if (dwStyle & CBRS_BORDER_RIGHT)
	{
		rtFrame.right -= m_sBorderHorz2;
	}

	if (dwStyle & CBRS_BORDER_BOTTOM)
	{
		rtFrame.bottom -= m_sBorderVert2;
	}                   
											// outset the top and bottom.
	if (boolHorz)
	{
		rtFrame.left -= m_cxLeftBorder;
		rtFrame.top -= m_cyTopBorder;
		rtFrame.right += (int)GetRightBorder();
		rtFrame.bottom += m_cyBottomBorder;
	}
	else
	{
		rtFrame.left -= m_cyTopBorder;
		rtFrame.top -= m_cxLeftBorder;
		rtFrame.right += m_cyBottomBorder;
		rtFrame.bottom += (int)GetRightBorder();
	}     
	
}


bool ChModuleBar::SaveFocusControl()
{											/* Save focus window if focus is
												on this window's controls */
	HWND	hWndFocus = ::GetFocus();

	if (hWndFocus != 0 && ::IsChild( m_hWnd, hWndFocus ))
	{
		m_hWndFocus = hWndFocus;

		return true;
	}
	else
	{
		return false;
	}
}


/*----------------------------------------------------------------------------
	ChModuleBar message handlers
----------------------------------------------------------------------------*/

void ChModuleBar::OnActivate( UINT nState, CWnd* pWndOther, BOOL bMinimized )
{
	ChToolBar::OnActivate( nState, pWndOther, bMinimized );

	if (WA_INACTIVE == nState)
	{
		SaveFocusControl();					/* Save focus when frame loses
												activation */
	}
}


void ChModuleBar::OnSetFocus( CWnd* pOldWnd )
{
	if (m_hWndFocus && ::IsWindow( m_hWndFocus ))
	{
		::SetFocus( m_hWndFocus );
	}
	else
	{									/* Invalid or unknown focus window...
											let windows handle it */
		m_hWndFocus = 0;
		ChToolBar::OnSetFocus( pOldWnd );
	}
}


int ChModuleBar::OnMouseActivate( CWnd* pDesktopWnd, UINT nHitTest,
									UINT message )
{
	ChPersistentFrame*	pFrame = ChCore::GetCore()->GetFrameWnd();

	if (pFrame)
	{
		pFrame->SetActiveWnd( this );
	}

	return ChToolBar::OnMouseActivate( pDesktopWnd, nHitTest, message );
}


#if defined( CH_MSW ) && defined( CH_ARCH_16 )
	#undef AFXAPP_DATA
	#define AFXAPP_DATA NEAR    
#endif
