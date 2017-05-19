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

	This file contains the implementation of the ChPrefs class, which
	manages preferences.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChPrefs.cpp,v 1.2 1996/09/17 21:44:42 pritham Exp $

#include "stdafx.h"
#include "ChPrefs.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	ChPrefs class
----------------------------------------------------------------------------*/

IMPLEMENT_DYNAMIC( ChPrefs, CPropertySheet )


ChPrefs::ChPrefs( UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage ) :
			CPropertySheet( nIDCaption, pParentWnd, iSelectPage )
{
}

ChPrefs::ChPrefs( LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage ) :
			CPropertySheet( pszCaption, pParentWnd, iSelectPage )
{
}

ChPrefs::~ChPrefs()
{
}


BEGIN_MESSAGE_MAP( ChPrefs, CPropertySheet )
	//{{AFX_MSG_MAP(ChPrefs)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		ON_BN_CLICKED(IDOK, OnOK)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChPrefs message handlers
----------------------------------------------------------------------------*/
void ChPrefs::OnOK() 
{
    // grab the data for the current sheet                            
	GetActivePage()->OnKillActive();
	#if ( _MFC_VER > 0x0400	 )
	EndDialog( IDOK );
	#else
	CPropertySheet::OnOK(  );
	#endif
}

