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

	This file consists of interfaces of the ChAbout class, ChSplashWnd class,
	and ChBigIcon class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChAbout.h,v 1.3 1996/07/02 19:57:29 pritham Exp $

#if (!defined( _CHABOUT_H ))
#define _CHABOUT_H
#include <ChDibImage.h>


/*----------------------------------------------------------------------------
				ChLogoBmp class
----------------------------------------------------------------------------*/

class ChLogoBitmap : public CButton
{
	public:
		enum tagLogoAlign{ top = 0x1, bottom = 0x2, vcenter = 0x4,
							left = 0x8, right = 0x10, hcenter = 0x20 };
	public:
		void SizeToContent( chflag16 fAlignment );

	protected:
		ChDib		m_logoBmp;
		chint32		m_lBmpHeight;
		chint32		m_lBmpWidth;

		virtual void DrawItem( LPDRAWITEMSTRUCT lpDrawItemStruct );

		//{{AFX_MSG(ChLogoBitmap)
		afx_msg bool OnEraseBkgnd(CDC* pDC);
		//}}AFX_MSG
	
	DECLARE_MESSAGE_MAP()
};


/*----------------------------------------------------------------------------
	ChSplashWnd class
----------------------------------------------------------------------------*/

class ChSplashWnd : public CDialog
{
											// Construction
	public:
		bool Create( CWnd* pParent );

											// Dialog Data
		//{{AFX_DATA(ChSplashWnd)
		enum { IDD = IDD_SPLASH };
			// NOTE: the ClassWizard will add data members here
		//}}AFX_DATA

											// Implementation
	protected:
	    									// DDX/DDV support

		virtual void DoDataExchange( CDataExchange* pDX );

	protected:
		ChLogoBitmap	logoBmp;

		// Generated message map functions
		//{{AFX_MSG(ChSplashWnd)
		virtual bool OnInitDialog();
	afx_msg void OnDestroy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};


/*----------------------------------------------------------------------------
	ChPuebloAbout property page class
----------------------------------------------------------------------------*/

class ChPuebloAbout : public CPropertyPage
{
	DECLARE_DYNCREATE( ChPuebloAbout )

	public:
		ChPuebloAbout();
		~ChPuebloAbout();

		void CreateTextWindow();
											// Overrides
		virtual bool OnSetActive();

	protected:
											// Dialog data
		//{{AFX_DATA(ChPuebloAbout)
		enum { IDD = IDD_ABOUT_BOX };
		CStatic	m_staticVersion;
		CStatic	m_staticProductName;
		CStatic	m_staticLegend;
		CStatic	m_staticCopyright;
		CStatic	m_staticClause;
			// NOTE - ClassWizard will add data members here.
			//    DO NOT EDIT what you see in these blocks of generated code !
		//}}AFX_DATA


											/* ClassWizard generate virtual
												function overrides */
		//{{AFX_VIRTUAL(ChPuebloAbout)
		protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		//}}AFX_VIRTUAL

	protected:
		ChLogoBitmap	m_logoBmp;

	protected:
		// Generated message map functions
		//{{AFX_MSG(ChPuebloAbout)
		virtual BOOL OnInitDialog();
		//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};



/*----------------------------------------------------------------------------
	ChTeamAbout property page class
----------------------------------------------------------------------------*/

class ChTeamAbout : public CPropertyPage
{
	DECLARE_DYNCREATE( ChTeamAbout )

	public:
		ChTeamAbout();
		~ChTeamAbout();

											// Overrides
		virtual bool OnSetActive();

	protected:
		void RandomizeNames();
		int GetRandomInt( int iMax );
		void SetNames();

	protected:
		enum tagConst { namesCount = 5 };

		static int		iTeamNames[namesCount];

	protected:
											// Dialog Data
		//{{AFX_DATA(ChTeamAbout)
		enum { IDD = IDD_ABOUT_TEAM };
			// NOTE - ClassWizard will add data members here.
			//    DO NOT EDIT what you see in these blocks of generated code !
		//}}AFX_DATA


											/* ClassWizard generate virtual
												function overrides */
		//{{AFX_VIRTUAL(ChTeamAbout)
		protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		//}}AFX_VIRTUAL

	protected:
		// Generated message map functions
		//{{AFX_MSG(ChTeamAbout)
		virtual BOOL OnInitDialog();
		//}}AFX_MSG

	protected:
		ChLogoBitmap	m_logoBmp;

	DECLARE_MESSAGE_MAP()
};


/*----------------------------------------------------------------------------
	ChAbout property sheet class
----------------------------------------------------------------------------*/

class ChAbout : public CPropertySheet
{
	DECLARE_DYNAMIC( ChAbout )

	public:
		ChAbout( chuint16 suIDCaption, CWnd *pParentWnd = 0,
					chuint16 suSelectPage = 0 );
		ChAbout( char *pstrCaption, CWnd *pParentWnd = 0,
					chuint16 suSelectPage = 0 );

	public:
		ChPuebloAbout		puebloPage;
		ChTeamAbout			teamPage;
											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(ChAbout)
		//}}AFX_VIRTUAL

	public:
		virtual ~ChAbout();

	protected:
		void Construct();

	protected:
		//{{AFX_MSG(ChAbout)
		afx_msg void OnHelp();
		afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#endif	// !defined( _CHABOUT_H )
