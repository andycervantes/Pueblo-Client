/*----------------------------------------------------------------------------

            .###.  ###     ###       ,#,          .###.    ,#######,
         ,####""   ###    .###     ,##'##,     ,####""   .##'    `##.
        ###        ###########    ,##' `##,   ###       ####      ####
        ###..      ###'    ###  ,###########, ####..    `###,    ,##'
          `######  ###     ###  `##'     `##'   `######   `########'


	Copyright 1995, Chaco Communications, Inc. All rights reserved.
	Unpublished -- Rights reserved under the copyright laws of the United
	States.  Use of a copyright notice is precautionary only and does no
	imply publication or disclosure.

	This software contains confidential information and trade secrets of
	Chaco Communications, Inc.  Use, disclosure, or reproduction is
	prohibited without the prior express written permission of Chaco
	Communications, Inc.

	RESTRICTED RIGHTS LEGEND

	Use, duplication, or disclosure by the Government is subject to
	restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
	Technical Data and Computer Software clause at DFARS 252.227-7013.

	Chaco Communications, Inc.
	10164 Parkwood Drive, Suite 8, Cupertino, CA, 95014-1533

------------------------------------------------------------------------------

	This file contains the implementation of the base Pueblo view class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChBaseVw.cpp,v 1.2 1996/03/30 00:38:59 pritham Exp $

#include "stdafx.h"

#include "resource.h"
#include "ChMFrame.h"
#include "ChBaseVw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	ChBaseView class
----------------------------------------------------------------------------*/

IMPLEMENT_DYNCREATE(ChBaseView, CView)

ChBaseView::ChBaseView() : m_pbrowseWnd( 0 )
{
}

ChBaseView::~ChBaseView()
{
	delete m_pbrowseWnd;
}


BEGIN_MESSAGE_MAP(ChBaseView, CView)
	//{{AFX_MSG_MAP(ChBaseView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	ON_WM_CREATE()       
	ON_MESSAGE( WM_CTLCOLORDLG, OnCtlColorStatic )
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChBaseView drawing
----------------------------------------------------------------------------*/

void ChBaseView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

int ChBaseView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{   
	lpCreateStruct->style &= ~WS_BORDER;
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;  

	CRect rtFrame( 0, 0, 100, 100 );

	ChMainFrame* pFrame = (ChMainFrame*)GetParentFrame( );

	m_pbrowseWnd = new ChBrowserWnd( pFrame->GetHTTPConn() );

	m_pbrowseWnd->Create( rtFrame, this,  WS_VISIBLE | WS_VSCROLL );

	return 0;
	
} 


LONG ChBaseView::OnCtlColorStatic( WPARAM wParam, LPARAM lParam )
{
	return 0;
}

void ChBaseView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	
	if ( m_pbrowseWnd && m_pbrowseWnd->GetSafeHwnd() )
	{
		m_pbrowseWnd->SetWindowPos( NULL, 0, 0, cx, cy, 
			SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER ); 
	}                                      	
	
} 

/*----------------------------------------------------------------------------
	ChBaseView diagnostics
----------------------------------------------------------------------------*/

#if defined( _DEBUG )

void ChBaseView::AssertValid() const
{
	CView::AssertValid();
}

void ChBaseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif	// defined( _DEBUG )


/*----------------------------------------------------------------------------
	ChBaseView message handlers
----------------------------------------------------------------------------*/
