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

#if !defined( _CHPRFONT_H )
#define _CHPRFONT_H

#include <ChReg.h>

// chprfont.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ChPrFont dialog

class ChPrFont : public CPropertyPage
{
	DECLARE_DYNCREATE(ChPrFont)

// Construction
public:
	ChPrFont();
	~ChPrFont();

		// Overrides
		virtual bool OnSetActive();
		virtual BOOL  OnKillActive();
// Dialog Data
	//{{AFX_DATA(ChPrFont)
	enum { IDD = IDD_PREF_FONT };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(ChPrFont)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(ChPrFont)
	afx_msg void OnChooseFixedFont();
	afx_msg void OnChooseProportionalFont();
	//}}AFX_MSG
	protected:
		bool		m_boolInitialized;
		string		m_strProportionalFont;
		int			m_iProportionalPointSize;
		string		m_strFixedFont;
		int			m_iFixedPointSize;
		ChRegistry	m_reg;

	DECLARE_MESSAGE_MAP()

};


/*----------------------------------------------------------------------------
	ChPrefsColorPage class
----------------------------------------------------------------------------*/

class ChPrefsColorPage : public CPropertyPage
{
	DECLARE_DYNCREATE( ChPrefsColorPage )

	public:
		ChPrefsColorPage();
		~ChPrefsColorPage();
											// Overrides
		virtual bool OnSetActive();
		virtual BOOL  OnKillActive();
											// Dialog Data
		//{{AFX_DATA(ChPrefsColorPage)
		enum { IDD = IDD_PREF_COLORS };
		CButton	m_btnSampleBack;
		CButton	m_btnSampleText;
		CButton	m_btnSampleLink;
		CButton	m_btnSamplePLink;
		CButton	m_btnSampleFLink;
		CComboBox	m_comboBackColor;
		CComboBox	m_comboTextColor;
		CComboBox	m_comboLinkColor;
		CComboBox	m_comboFLinkColor;
		CComboBox	m_comboPLinkColor;
		int			m_iBackColor;
		int			m_iTextColor;
		int			m_iLinkColor;
		int			m_iFLinkColor;
		int			m_iPLinkColor;
		//}}AFX_DATA
											/* ClassWizard generate virtual
												function overrides */
		//{{AFX_VIRTUAL(ChPrefsColorPage)
		protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		//}}AFX_VIRTUAL

	protected:
		inline bool IsDefColor( chuint32 luColor )
						{
							return ( CH_COLOR_DEFAULT & luColor );
						}
		void InitColorList( CComboBox& comboColor,
								chuint16 suExtraColorText = 0 );
		chint16 GetColorIndex( chuint32 luColor, bool boolDefaultUsed = true );
		chuint32 GetColorValue( chint16 sIndex, bool boolDefaultUsed = true );
		void DrawColorItem( LPDRAWITEMSTRUCT lpDrawItemStruct, CDC* pDC,
								const CRect& rtItem );
		void DrawColorSelect( LPDRAWITEMSTRUCT lpDrawItemStruct,
								CDC* pDC, const CRect& rtItem,
								bool boolSelected );
		void UpdateColorSample();
		void DrawColorSample( LPDRAWITEMSTRUCT lpDrawItemStruct );

											// Generated message map functions
		//{{AFX_MSG(ChPrefsColorPage)
		afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
		afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
		afx_msg void OnSelchangeComboBackColor();
		afx_msg void OnSelchangeComboTextColor();
		afx_msg void OnSelchangeComboLinkColor();
		afx_msg void OnSelchangeComboFlinkColor();
		afx_msg void OnSelchangeComboPlinkColor();
		//}}AFX_MSG

	protected:
		static const chuint32	m_luBackColors[];

		bool					m_boolInitialized;
		ChRegistry				m_regColor;

	DECLARE_MESSAGE_MAP()
};

#endif	// !defined( _CHPRFONT_H )
