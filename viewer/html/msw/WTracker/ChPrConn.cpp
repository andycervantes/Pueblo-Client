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

	This file contains the implementation of the ChConnPrefsPage class,
	which manages connection preferences.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChPrConn.cpp,v 1.2 1996/03/30 00:39:03 pritham Exp $

#include "stdafx.h"
#include <ChReg.h>

#include "ChPrConn.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	ChConnPrefsPage class
----------------------------------------------------------------------------*/

IMPLEMENT_DYNCREATE( ChConnPrefsPage, CPropertyPage )


ChConnPrefsPage::ChConnPrefsPage() :
					CPropertyPage( ChConnPrefsPage::IDD ),
					m_reg( CH_COMPANY_NAME, CH_HTML_PRODUCT_NAME, CH_CONNECTION_GROUP ),
					m_boolInitialized( false )
{
	//{{AFX_DATA_INIT(ChConnPrefsPage)
	//}}AFX_DATA_INIT
}


ChConnPrefsPage::~ChConnPrefsPage()
{
}


bool ChConnPrefsPage::OnSetActive()
{
	bool	boolResult;

	boolResult = CPropertyPage::OnSetActive();

	if (!m_boolInitialized)
	{
									/* Set the initialized flag so
												that we don't do this again */
		m_boolInitialized = true;
	}

	return boolResult;
}


BOOL ChConnPrefsPage::OnKillActive()
{
	if (m_boolInitialized)
	{
	}     
	return( true );
}


BEGIN_MESSAGE_MAP( ChConnPrefsPage, CPropertyPage )
	//{{AFX_MSG_MAP(ChConnPrefsPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChConnPrefsPage message handlers
----------------------------------------------------------------------------*/

