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

	This file contains the interface for the ChPrefs class, which
	manages preferences.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChPrefs.h,v 1.1 1996/02/26 23:04:32 pritham Exp $

#if !defined( _CHPREFS_H )
#define _CHPREFS_H


/*----------------------------------------------------------------------------
	ChPrefs class
----------------------------------------------------------------------------*/

class ChPrefs : public CPropertySheet
{
	DECLARE_DYNAMIC( ChPrefs )

	public:
		ChPrefs( UINT nIDCaption, CWnd* pParentWnd = 0, UINT iSelectPage = 0 );
		ChPrefs( LPCTSTR pszCaption, CWnd* pParentWnd = 0, UINT iSelectPage = 0 );


											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(ChPrefs)
		//}}AFX_VIRTUAL

	public:
		virtual ~ChPrefs();

											// Generated message map functions
	protected:
		//{{AFX_MSG(ChPrefs)
		// NOTE - the ClassWizard will add and remove member functions here.
			afx_msg void OnOK(  );
		//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#endif	// !defined( _CHPREFS_H )
