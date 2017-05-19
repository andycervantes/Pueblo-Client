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

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChBasDoc.h,v 1.2 1996/03/14 03:08:41 pritham Exp $

#if !defined( _CHBASDOC_H )
#define _CHBASDOC_H

class ChBrowserWnd;
class ChMainFrame;

/*----------------------------------------------------------------------------
	ChBaseDoc class
----------------------------------------------------------------------------*/

class ChBaseDoc : public CDocument
{
	protected:
		ChBaseDoc();						/* Protected constructor used by
												dynamic creation */
		DECLARE_DYNCREATE( ChBaseDoc )
											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(ChBaseDoc)
		protected:
		virtual BOOL OnNewDocument();
		//}}AFX_VIRTUAL

											// Implementation
	public:
		virtual ~ChBaseDoc();
		virtual void Serialize(CArchive& ar);   // overridden for document i/o

		#ifdef _DEBUG
			virtual void AssertValid() const;
			virtual void Dump(CDumpContext& dc) const;
		#endif

		virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);


		ChBrowserWnd* GetHTMLWnd()				{ return m_pHTMLView; }

	private :
		ChBrowserWnd *		 m_pHTMLView;
		ChMainFrame*		 m_pFrame;
											// Generated message map functions
	protected:
		//{{AFX_MSG(ChBaseDoc)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#endif	// !defined( _CHBASDOC_H )
