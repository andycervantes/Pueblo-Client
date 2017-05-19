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

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChBaseVw.h,v 1.2 1996/03/30 00:39:00 pritham Exp $

#if !defined( _CHBASEVW_H )
#define _CHBASEVW_H

#include "ChHtmDsp.h"


/*----------------------------------------------------------------------------
	ChBaseView class
----------------------------------------------------------------------------*/

class ChBaseView : public CView
{
	protected:
		ChBaseView();						/* Protected constructor used by
												dynamic creation */
		DECLARE_DYNCREATE( ChBaseView )

											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(ChBaseView)
		protected:
		virtual void OnDraw(CDC* pDC);      // Overridden to draw this view
		//}}AFX_VIRTUAL

	public :
		ChBrowserWnd* GetHTMLWnd()		{ return m_pbrowseWnd; }

	private :
		ChBrowserWnd*	m_pbrowseWnd;
											// Implementation
	protected:
		virtual ~ChBaseView();

		#if defined( _DEBUG )
			virtual void AssertValid() const;
			virtual void Dump(CDumpContext& dc) const;
		#endif

											// Generated message map functions
	protected:
		//{{AFX_MSG(ChBaseView)
			// NOTE - the ClassWizard will add and remove member functions here.
		afx_msg void OnSize(UINT nType, int cx, int cy);
		//}}AFX_MSG  
		afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		afx_msg LONG OnCtlColorStatic( WPARAM wParam, LPARAM lParam );

	DECLARE_MESSAGE_MAP()
};

#endif	// !defined( _CHBASEVW_H )
