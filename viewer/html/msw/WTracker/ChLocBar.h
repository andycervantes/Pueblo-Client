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

	This file consists of the the interface for the ChMainFrame class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChLocBar.h,v 1.2 1996/04/04 08:11:27 pritham Exp $

#if (!defined( CHLOCBAR_H ))
#define CHLOCBAR_H


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// ChFrmCombo window

class ChLocBarCombo : public CComboBox
{
// Construction
public:
	ChLocBarCombo();

// Attributes
public:

// Operations
public:

private :
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ChFrmCombo)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~ChLocBarCombo();

	// Generated message map functions
protected:
	//{{AFX_MSG(ChFrmCombo)
	//}}AFX_MSG
	LONG OnShowDropDown( UINT wParam, LONG lParam );

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// ChLocationBar dialog

class ChLocationBar : public CDialogBar
{
// Construction
public:
	ChLocationBar();   // standard constructor

// Dialog Data
	//{{AFX_DATA(ChLocationBar)
	enum { IDD = IDD_LOCBAR };
	CAnimateCtrl	m_animCntl;
	ChLocBarCombo	m_urlCombo;
	//}}AFX_DATA
	void EnableAnimationCtrl(bool bEnable);
	void UpdateLocationBar( const string& strURL );
	void GetLocBarText( string& strURL);
 	void InitLocationBar( );


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ChLocationBar)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void CommitLocationBar( );

	// Generated message map functions
	//{{AFX_MSG(ChLocationBar)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // CHLOCBAR_H
