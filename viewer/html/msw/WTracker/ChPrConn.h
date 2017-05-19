/*----------------------------------------------------------------------------

            .###.  ###     ###       ,#,          .###.    ,#######,
         ,####""   ###    .###     ,##’##,     ,####""   .##’    ‘##.
        ###        ###########    ,##’ ‘##,   ###       ####      ####
        ###..      ###’    ###  ,###########, ####..    ‘###,    ,##’
          ‘######  ###     ###  ‘##’     ‘##’   ‘######   ‘########’


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

	This file contains the implementation of the ChPrConn preferences page,
	which manages connection preferences.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChPrConn.h,v 1.1 1996/02/26 23:04:29 pritham Exp $

#include <ChReg.h>


/*----------------------------------------------------------------------------
	ChConnPrefsPage class
----------------------------------------------------------------------------*/

class ChConnPrefsPage : public CPropertyPage
{
	DECLARE_DYNCREATE( ChConnPrefsPage )

	public:
		ChConnPrefsPage();
		~ChConnPrefsPage();

		// Overrides
		virtual bool OnSetActive();
		virtual BOOL  OnKillActive();
											// Dialog Data
		//{{AFX_DATA(ChConnPrefsPage)
		enum { IDD = IDD_PREF_CONNECTION };
		//}}AFX_DATA


											/* ClassWizard generate virtual
												function overrides */
		//{{AFX_VIRTUAL(ChConnPrefsPage)
		//}}AFX_VIRTUAL

	protected:
											// Generated message map functions
		//{{AFX_MSG(ChConnPrefsPage)
		// NOTE: the ClassWizard will add member functions here
		//}}AFX_MSG

	protected:
		bool		m_boolInitialized;
		string		m_strHost;
		chint16		m_sPort;
		ChRegistry	m_reg;
	
	DECLARE_MESSAGE_MAP()
};
