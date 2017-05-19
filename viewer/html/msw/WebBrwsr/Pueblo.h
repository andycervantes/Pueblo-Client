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

	This file consists of the Chaco application class definition.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WebBrwsr/Pueblo.h,v 1.1 1996/02/26 23:13:58 pritham Exp $

#if (!defined( _CHACO_H ))
#define _CHACO_H


#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif


/*----------------------------------------------------------------------------
	ChApp class
----------------------------------------------------------------------------*/

class ChApp : public CWinApp
{
	public:
		ChApp();
		virtual ~ChApp();

	private:

	//	ChSplashWnd		m_splash;			// Splash window
		chuint32		m_luSplashTime;

											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(ChApp)
	public:
		virtual bool InitInstance();
		virtual int  ExitInstance();
		virtual bool OnIdle(LONG lCount);
		virtual bool PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL
											// Implementation
	public:
	//	inline ChSplashWnd* GetSplashWnd() { return( &m_splash ); }
		inline void SetSplashTime()	{ m_luSplashTime = ::GetCurrentTime(); }

	//{{AFX_MSG(ChApp)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#endif	// !defined( _CHACO_H )
