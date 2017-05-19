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


#include "stdafx.h"
#include <ChReg.h>
#include "resource.h"
#include "ChMFrame.h"
#include "ChPrFont.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ChPrFont property page

IMPLEMENT_DYNCREATE(ChPrFont, CPropertyPage)

ChPrFont::ChPrFont() : CPropertyPage(ChPrFont::IDD),
					m_reg( CH_COMPANY_NAME, CH_HTML_PRODUCT_NAME, CH_FONT_GROUP ),
					m_boolInitialized( false )
{
	//{{AFX_DATA_INIT(ChPrFont)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

ChPrFont::~ChPrFont()
{
}

void ChPrFont::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ChPrFont)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


bool ChPrFont::OnSetActive()
{
	bool	boolResult;

	boolResult = CPropertyPage::OnSetActive();

	if (!m_boolInitialized)
	{
		CStatic		*pName;
		string		strSize;

		m_reg.Read( CH_FONT_PROPORTIONAL, m_strProportionalFont, 
							CH_FONT_PROPORTIONAL_DEF );
 		m_reg.Read( CH_FONT_PROPORTIONAL_SIZE, strSize, 
 						CH_FONT_PROPORTIONAL_SIZE_DEF );

		m_iProportionalPointSize = atoi( strSize );

		m_reg.Read( CH_FONT_FIXED, m_strFixedFont, CH_FONT_FIXED_DEF );
		m_reg.Read( CH_FONT_FIXED_SIZE, strSize, CH_FONT_FIXED_SIZE_DEF );

												// Set the proportional font name
		m_iFixedPointSize = atoi( strSize );
		pName = (CStatic *)GetDlgItem( IDC_STAT_PROPORTIONAL );
		pName->SetWindowText( m_strProportionalFont );
												// Set the fixed font name

		pName = (CStatic *)GetDlgItem( IDC_STAT_FIXED );
		pName->SetWindowText( m_strFixedFont );
											/* Set the initialized flag so
												that we don't do this again */
		m_boolInitialized = true;
	}

	return boolResult;
}


BOOL ChPrFont::OnKillActive()
{
	UpdateData( true );
	
	if (m_boolInitialized)
	{
		char	strNum[30];
		m_reg.Write( CH_FONT_PROPORTIONAL, m_strProportionalFont );

		_itoa( m_iProportionalPointSize, strNum, 10 );
 		m_reg.Write( CH_FONT_PROPORTIONAL_SIZE, strNum );

		m_reg.Write( CH_FONT_FIXED, m_strFixedFont );
		_ltoa( m_iFixedPointSize, strNum, 10 );
		m_reg.Write( CH_FONT_FIXED_SIZE, strNum );

		ChMainFrame* pFrame = (ChMainFrame*)GetParentFrame(); 
		if ( pFrame )
		{
			pFrame->GetHTMLWnd()->SendMessage( WM_HTML_FONT_CHANGE );
		}

	}
	return ( true );
}



BEGIN_MESSAGE_MAP(ChPrFont, CPropertyPage)
	//{{AFX_MSG_MAP(ChPrFont)
	ON_BN_CLICKED(IDC_CHOOSE_FIXED, OnChooseFixedFont)
	ON_BN_CLICKED(IDC_CHOOSE_PROPORTIONAL, OnChooseProportionalFont)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// ChPrFont message handlers

void ChPrFont::OnChooseFixedFont() 
{
	// TODO: Add your control notification handler code here
	LOGFONT	lf;
	ChMemClearStruct( &lf );

#ifdef CH_MSW
	HDC			hDC = ::GetDC( ::GetDesktopWindow() );
	int iPixelY = -1 * ::GetDeviceCaps(hDC, LOGPIXELSY);
	::ReleaseDC(::GetDesktopWindow(), hDC );
	
	lf.lfHeight = ( iPixelY * m_iFixedPointSize / 72);
	lf.lfWeight 		= FW_LIGHT;
	lf.lfCharSet 		= ANSI_CHARSET;
	lf.lfOutPrecision 	= OUT_STROKE_PRECIS;
	lf.lfClipPrecision 	= CLIP_STROKE_PRECIS;
	lf.lfQuality 		= DEFAULT_QUALITY;
	lf.lfPitchAndFamily = FIXED_PITCH | FF_MODERN;
	lstrcpy(lf.lfFaceName, m_strFixedFont );	 // should we get the name from the preference file ???
#else
	cerr << "XXX" << __FILE__ << ":" << __LINE__ << endl;	
#endif
	
	CFontDialog fixedFont( &lf, ( CF_FIXEDPITCHONLY | CF_SCREENFONTS |
							  CF_LIMITSIZE | CF_INITTOLOGFONTSTRUCT), NULL, this );

	fixedFont.m_cf.Flags &= ~CF_SHOWHELP; 
	fixedFont.m_cf.nSizeMin = 6;
	fixedFont.m_cf.nSizeMax = 16;
	fixedFont.m_cf.iPointSize = m_iFixedPointSize;
	if ( fixedFont.DoModal() == IDOK )
	{
		CStatic		*pName;
		m_strFixedFont = lf.lfFaceName;
		m_iFixedPointSize = fixedFont.m_cf.iPointSize/10;		
												// Set the fixed font name

		pName = (CStatic *)GetDlgItem( IDC_STAT_FIXED );
		pName->SetWindowText( m_strFixedFont );
	}
}

void ChPrFont::OnChooseProportionalFont() 
{
	// TODO: Add your control notification handler code here
	LOGFONT	lf;
	ChMemClearStruct( &lf );

#ifdef CH_MSW
	HDC			hDC = ::GetDC( ::GetDesktopWindow() );
	int iPixelY = -1 * ::GetDeviceCaps(hDC, LOGPIXELSY);
	::ReleaseDC(::GetDesktopWindow(), hDC );
	
	lf.lfHeight = ( iPixelY * m_iProportionalPointSize / 72);
	lf.lfWeight 		= FW_LIGHT;
	lf.lfCharSet 		= ANSI_CHARSET;
	lf.lfOutPrecision 	= OUT_STROKE_PRECIS;
	lf.lfClipPrecision 	= CLIP_STROKE_PRECIS;
	lf.lfQuality 		= DEFAULT_QUALITY;
	lf.lfPitchAndFamily = FIXED_PITCH | FF_MODERN;
	lstrcpy(lf.lfFaceName, m_strProportionalFont );	 // should we get the name from the preference file ???
#else
	cerr << "XXX" << __FILE__ << ":" << __LINE__ << endl;	
#endif
	
	CFontDialog propFont( &lf, ( CF_SCALABLEONLY | CF_SCREENFONTS |
							  CF_LIMITSIZE | CF_INITTOLOGFONTSTRUCT), NULL, this );

	propFont.m_cf.Flags &= ~CF_SHOWHELP; 
	propFont.m_cf.nSizeMin = 6;
	propFont.m_cf.nSizeMax = 16;
	propFont.m_cf.iPointSize = m_iProportionalPointSize;

	if ( propFont.DoModal() == IDOK )
	{
		m_strProportionalFont = lf.lfFaceName;
		m_iProportionalPointSize = propFont.m_cf.iPointSize/10;		
												// Set the proportional font name
		CStatic		*pName;
		pName = (CStatic *)GetDlgItem( IDC_STAT_PROPORTIONAL );
		pName->SetWindowText( m_strProportionalFont );
	}
	
}


/*----------------------------------------------------------------------------
	ChPrefsColorPage class
----------------------------------------------------------------------------*/

IMPLEMENT_DYNCREATE( ChPrefsColorPage, CPropertyPage )

ChPrefsColorPage::ChPrefsColorPage() :
					CPropertyPage( ChPrefsColorPage::IDD ),
					m_regColor( CH_COMPANY_NAME, CH_HTML_PRODUCT_NAME, CH_COLOR_GROUP ),
					m_boolInitialized( false )
{												   
	//{{AFX_DATA_INIT(ChPrefsColorPage)
	m_iBackColor = -1;
	m_iTextColor = -1;
	m_iLinkColor = -1;
	m_iFLinkColor = -1;
	m_iPLinkColor = -1;
	//}}AFX_DATA_INIT
}

ChPrefsColorPage::~ChPrefsColorPage()
{
}

void ChPrefsColorPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ChPrefsColorPage)
	DDX_Control(pDX, IDC_SAMPLE_BACK, m_btnSampleBack);
	DDX_Control(pDX, IDC_SAMPLE_TEXT, m_btnSampleText);
	DDX_Control(pDX, IDC_SAMPLE_LINK, m_btnSampleLink);
	DDX_Control(pDX, IDC_SAMPLE_FLINK, m_btnSampleFLink);
	DDX_Control(pDX, IDC_SAMPLE_PLINK, m_btnSamplePLink);
	DDX_Control(pDX, IDC_COMBO_BACK_COLOR, m_comboBackColor);
	DDX_Control(pDX, IDC_COMBO_TEXT_COLOR, m_comboTextColor);
	DDX_Control(pDX, IDC_COMBO_LINK_COLOR, m_comboLinkColor);
	DDX_Control(pDX, IDC_COMBO_FLINK_COLOR, m_comboFLinkColor);
	DDX_Control(pDX, IDC_COMBO_PLINK_COLOR, m_comboPLinkColor);
	DDX_CBIndex(pDX, IDC_COMBO_BACK_COLOR, m_iBackColor);
	DDX_CBIndex(pDX, IDC_COMBO_TEXT_COLOR, m_iTextColor);
	DDX_CBIndex(pDX, IDC_COMBO_LINK_COLOR, m_iLinkColor);
	DDX_CBIndex(pDX, IDC_COMBO_FLINK_COLOR, m_iFLinkColor);
	DDX_CBIndex(pDX, IDC_COMBO_PLINK_COLOR, m_iPLinkColor);
	//}}AFX_DATA_MAP
}


bool ChPrefsColorPage::OnSetActive()
{
	bool	boolResult;

	boolResult = CPropertyPage::OnSetActive();

	if (!m_boolInitialized)
	{
		chuint32		luColor;
		DWORD			dwStyle;
											// Initialize the color lists

		InitColorList( m_comboBackColor, IDS_TEXT_COLOR );
		InitColorList( m_comboTextColor, IDS_TEXT_COLOR );
		InitColorList( m_comboLinkColor, IDS_TEXT_COLOR );
		InitColorList( m_comboFLinkColor, IDS_TEXT_COLOR );
		InitColorList( m_comboPLinkColor, IDS_TEXT_COLOR );

											// Read the registry colors

		m_regColor.Read( CH_COLOR_BACK, luColor, CH_COLOR_DEFAULT );
		m_iBackColor = GetColorIndex( luColor );
		m_regColor.Read( CH_COLOR_TEXT, luColor, CH_COLOR_DEFAULT );
		m_iTextColor = GetColorIndex( luColor );
		m_regColor.Read( CH_COLOR_LINK, luColor, CH_COLOR_DEFAULT );
		m_iLinkColor = GetColorIndex( luColor );
		m_regColor.Read( CH_COLOR_FLINK, luColor, CH_COLOR_DEFAULT );
		m_iFLinkColor = GetColorIndex( luColor );
		m_regColor.Read( CH_COLOR_PLINK, luColor, CH_COLOR_DEFAULT );
		m_iPLinkColor = GetColorIndex( luColor );

		UpdateData( false );
											/* Set the background button to
												clip siblings */
		dwStyle = m_btnSampleBack.GetStyle();
		dwStyle |= WS_CLIPSIBLINGS;
		SetWindowLong( m_btnSampleBack.m_hWnd, GWL_STYLE, dwStyle );

											/* Set the initialized flag so
												that we don't do this again */
		m_boolInitialized = true;
	}

	return boolResult;
}


BOOL ChPrefsColorPage::OnKillActive()
{
	if (m_boolInitialized)
	{
		chint32		luColor;

		UpdateData();

		luColor = GetColorValue( m_iBackColor );
		m_regColor.Write( CH_COLOR_BACK, luColor );
		luColor = GetColorValue(  m_iTextColor );
		m_regColor.Write( CH_COLOR_TEXT, luColor );
		luColor = GetColorValue( m_iLinkColor );
		m_regColor.Write( CH_COLOR_LINK, luColor );
		luColor = GetColorValue( m_iFLinkColor );
		m_regColor.Write( CH_COLOR_FLINK, luColor );
		luColor = GetColorValue( m_iPLinkColor );
		m_regColor.Write( CH_COLOR_PLINK, luColor );

											/* Send message to all HTML windows
												to update font */
		ChMainFrame* pFrame = (ChMainFrame*)GetParentFrame(); 
		if ( pFrame )
		{
			pFrame->GetHTMLWnd()->SendMessage( WM_HTML_COLOR_CHANGE );
		}
	} 

	return true;
}


BEGIN_MESSAGE_MAP(ChPrefsColorPage, CPropertyPage)
	//{{AFX_MSG_MAP(ChPrefsColorPage)
	ON_WM_MEASUREITEM()
	ON_WM_DRAWITEM()
	ON_CBN_SELCHANGE(IDC_COMBO_BACK_COLOR, OnSelchangeComboBackColor)
	ON_CBN_SELCHANGE(IDC_COMBO_FLINK_COLOR, OnSelchangeComboFlinkColor)
	ON_CBN_SELCHANGE(IDC_COMBO_LINK_COLOR, OnSelchangeComboLinkColor)
	ON_CBN_SELCHANGE(IDC_COMBO_PLINK_COLOR, OnSelchangeComboPlinkColor)
	ON_CBN_SELCHANGE(IDC_COMBO_TEXT_COLOR, OnSelchangeComboTextColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChPrefsColorPage protected members
----------------------------------------------------------------------------*/
	
const chuint32	ChPrefsColorPage::m_luBackColors[] = {
									RGB( 255, 255, 255 ),	// white
									RGB( 192, 192, 192 ),	// lt grey
									RGB( 128, 128, 128 ),	// dk grey
									RGB( 0, 0, 0 ),			// black
									RGB( 255, 0, 0 ),		// red
									RGB( 255, 0, 255 ),		// magenta
									RGB( 0, 0, 255 ),		// blue
									RGB( 0, 255, 255 ),		// cyan
									RGB( 0, 255, 0 ),		// green
									RGB( 255, 255, 0 ),		// yellow
									RGB( 128, 0, 0 ),		// dk red
									RGB( 128, 0, 128 ),		// dk magenta
									RGB( 0, 0, 128 ),		// dk blue
									RGB( 0, 128, 128 ),		// dk cyan
									RGB( 0, 128, 0 ),		// dk green
									RGB( 128, 128, 0 ),		// dk yellow
									};


void ChPrefsColorPage::InitColorList( CComboBox& comboColor,
										chuint16 suExtraColorText )
{
	int					iLoop;
	const int			iCount = sizeof( m_luBackColors ) /
									sizeof( m_luBackColors[0] );

	if (suExtraColorText)
	{										// Add the extra color
		chuint32		luData;

		luData = CH_COLOR_DEFAULT | suExtraColorText;
		comboColor.AddString( (LPCSTR)luData );
	}

	for (iLoop = 0; iLoop < iCount; iLoop++)
	{
		comboColor.AddString( (LPCSTR)m_luBackColors[iLoop] );
	}
}


chint16 ChPrefsColorPage::GetColorIndex( chuint32 luColor,
											bool boolDefaultUsed )
{
											/* This function will return the
												color index corresponding to
												a given color.  If no colors
												match, the default color will
												be returned */

	int					iFound = -1;
	int					iLoop;
	const int			iCount = sizeof( m_luBackColors ) /
									sizeof( m_luBackColors[0] );

	for (iLoop = 0; (-1 == iFound) && (iLoop < iCount); iLoop++)
	{
		if (m_luBackColors[iLoop] == luColor)
		{
			iFound = iLoop;

			if (boolDefaultUsed)
			{
				iFound++;
			}
		}
	}

	if (-1 == iFound && boolDefaultUsed )
	{
		iFound = 0;
	}

	return iFound;
}


chuint32 ChPrefsColorPage::GetColorValue( chint16 sIndex,
											bool boolDefaultUsed )
{
	if (boolDefaultUsed)
	{
		sIndex--;
	}

	if (-1 == sIndex)
	{
		return CH_COLOR_DEFAULT;
	}
	else
	{
		ASSERT( sIndex >= 0 );
		ASSERT( sIndex < (sizeof( m_luBackColors ) /
							sizeof( m_luBackColors[0] )) );

		return m_luBackColors[sIndex];
	}
}


void ChPrefsColorPage::DrawColorItem( LPDRAWITEMSTRUCT lpDrawItemStruct,
										CDC* pDC, const CRect& rtItem )
{
	int			iIndex = lpDrawItemStruct->itemID - 1;
	chuint32	luItemData = lpDrawItemStruct->itemData;
	COLORREF	itemColor = (COLORREF)luItemData;
	DWORD		itemState = lpDrawItemStruct->itemState;

											// Fill the item rect with the color

	if ((-1 == iIndex) || IsDefColor( luItemData ))
	{
											/* Empty item or default window
												color */

		COLORREF	windowColor = GetSysColor( COLOR_WINDOW );
		CBrush		fillBrush( windowColor );
		COLORREF	textColor;
		string		strText;
		CFont		textFont;
		CFont*		pOldFont;
		CSize		sizeText;
		int			iLeft;
		int			iTop;

		pDC->FillRect( &rtItem, &fillBrush );
											// Default color

		if (ChWebTrackerManager::WTrackerLoadString( IDS_TEXT_COLOR, strText ))
		{
			textColor = GetSysColor( COLOR_BTNTEXT );

			pOldFont = pDC->SelectObject( m_comboBackColor.GetFont() );	  

			switch( lpDrawItemStruct->CtlID )
			{
				case IDC_COMBO_LINK_COLOR:
				{
					textColor = COLOR_DEF_LINK;
					break;
				}

				case IDC_COMBO_FLINK_COLOR :
				{
					textColor = COLOR_DEF_VIST_LINK;
					break;
				}

				case IDC_COMBO_PLINK_COLOR :
				{
					textColor = COLOR_DEF_PREFETCH_LINK;
					break;
				}
			}

			pDC->SetTextColor( textColor );
											// Center the text if possible

			sizeText = pDC->GetTextExtent( strText, strText.GetLength() );
			iTop = rtItem.top;
			if (rtItem.Height() > sizeText.cy)
			{
				iTop += (rtItem.Height() - sizeText.cy) / 2;
			}

			iLeft = rtItem.left;
			if (rtItem.Width() > sizeText.cx)
			{
				iLeft += (rtItem.Width() - sizeText.cx) / 2;
			}
			pDC->SetBkColor( windowColor );
											// Draw the text

			pDC->ExtTextOut( iLeft, iTop, ETO_OPAQUE, &rtItem, strText,
								strText.GetLength(), 0 );

			pDC->SelectObject( pOldFont );
		}
	}
	else
	{										// Specific color
		CBrush		fillBrush( itemColor );

		pDC->FillRect( &rtItem, &fillBrush );
	}

	if (itemState & ODS_FOCUS)
	{										/* Set the initial state of the
												focus */
		CRect	rtFocus( rtItem );

		rtFocus.InflateRect( -1, -1 );
		pDC->DrawFocusRect( &rtFocus );
	}
	else if (itemState & ODS_SELECTED)
	{										/* Set the initial state of the
												selection */

		DrawColorSelect( lpDrawItemStruct, pDC, rtItem, true );
	}
}


void ChPrefsColorPage::DrawColorSelect( LPDRAWITEMSTRUCT lpDrawItemStruct,
										CDC* pDC, const CRect& rtItem,
										bool boolSelected )
{
	if (boolSelected)
	{
		CPen	whitePen( PS_SOLID, 0, RGB( 255, 255, 255 ) );
		CPen	blackPen( PS_SOLID, 0, RGB( 0, 0, 0 ) );
		CBrush*	pNullBrush;
		CPen*	pOldPen;
		CBrush*	pOldBrush;
		CRect	rtOutline( rtItem );

		pNullBrush = CBrush::FromHandle( (HBRUSH)GetStockObject( NULL_BRUSH ) );
		pOldBrush = pDC->SelectObject( pNullBrush );
		pOldPen = pDC->SelectObject( &whitePen );

		pDC->Rectangle( rtOutline );
		rtOutline.InflateRect( -1, -1 );
		pOldPen = pDC->SelectObject( &blackPen );
		pDC->Rectangle( rtOutline );
		rtOutline.InflateRect( -1, -1 );
		pOldPen = pDC->SelectObject( &whitePen );
		pDC->Rectangle( rtOutline );

		pDC->SelectObject( pOldPen );
		pDC->SelectObject( pOldBrush );
	}
	else
	{
		DrawColorItem( lpDrawItemStruct, pDC, rtItem );
	}
}


void ChPrefsColorPage::DrawColorSample( LPDRAWITEMSTRUCT lpDrawItemStruct )
{
	CDC*		pDC;
	CRect		rtItem;
	COLORREF	colorBack;
	COLORREF	colorFore;
	chuint32	luBackColor;
	chuint32	luForeColor;
	COLORREF	defForeColor;
	string		strWindowText;
	CRect		rtWindow;
	int			iTop = 0;
	int			iLeft = 0;

	ASSERT( ODT_BUTTON == lpDrawItemStruct->CtlType );

	UpdateData();
											// Calculate the background color
	luBackColor = GetColorValue( m_iBackColor );
	if (IsDefColor( luBackColor ))
	{
		colorBack = GetSysColor( COLOR_WINDOW );
	}
	else
	{
		colorBack = (COLORREF)luBackColor;
	}
											/* Grab a copy of the things that
												are needed over and over
												again */

	pDC = CDC::FromHandle( lpDrawItemStruct->hDC );
	rtItem = lpDrawItemStruct->rcItem;

	switch( lpDrawItemStruct->CtlID )
	{
		case IDC_SAMPLE_BACK:
		{
			strWindowText = "";
			break;
		}

		case IDC_SAMPLE_TEXT:
		{
			luForeColor = GetColorValue( m_iTextColor );
			defForeColor = GetSysColor( COLOR_BTNTEXT );
			m_btnSampleText.GetWindowText( strWindowText );
			break;
		}

		case IDC_SAMPLE_LINK:
		{
			luForeColor = GetColorValue( m_iLinkColor );
			defForeColor = COLOR_DEF_LINK;
			m_btnSampleLink.GetWindowText( strWindowText );
			break;
		}

		case IDC_SAMPLE_FLINK:
		{
			luForeColor = GetColorValue( m_iFLinkColor );
			defForeColor = COLOR_DEF_VIST_LINK;
			m_btnSampleFLink.GetWindowText( strWindowText );
			break;
		}

		case IDC_SAMPLE_PLINK:
		{
			luForeColor = GetColorValue( m_iPLinkColor );
			defForeColor = COLOR_DEF_PREFETCH_LINK;
			m_btnSamplePLink.GetWindowText( strWindowText );
			break;
		}
	}

	if (!strWindowText.IsEmpty())
	{
		CSize	extents;

		if (IsDefColor( luForeColor ))
		{
			colorFore = defForeColor;
		}
		else
		{
			colorFore = (COLORREF)luForeColor;
		}
									// Measure the text

		extents = pDC->GetTextExtent( strWindowText,
										strWindowText.GetLength() );

		if (extents.cy < rtItem.Height())
		{
			iTop = rtItem.top + ((rtItem.Height() - extents.cy) / 2);
		}

		if (extents.cx < rtItem.Width())
		{
			iLeft = rtItem.left + ((rtItem.Width() - extents.cx) / 2);
		}
	}
									// Fill the rect with the color
	pDC->SetBkColor( colorBack );
	pDC->SetTextColor( colorFore );
	pDC->ExtTextOut( iLeft, iTop, ETO_OPAQUE, &rtItem, strWindowText,
						strWindowText.GetLength(), 0 );
}


/*----------------------------------------------------------------------------
	ChPrefsColorPage message handlers
----------------------------------------------------------------------------*/
	
void ChPrefsColorPage::OnMeasureItem( int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct )
{
	CPropertyPage ::OnMeasureItem( nIDCtl, lpMeasureItemStruct );
}


void ChPrefsColorPage::OnDrawItem( int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct )
{
	switch( nIDCtl )
	{
		case IDC_COMBO_BACK_COLOR:
		case IDC_COMBO_TEXT_COLOR:
		case IDC_COMBO_LINK_COLOR:
		case IDC_COMBO_FLINK_COLOR:
		case IDC_COMBO_PLINK_COLOR:
		{
			CDC*	pDC;
			CRect	rtItem;
			int		iSavedDC;

			ASSERT( ODT_COMBOBOX == lpDrawItemStruct->CtlType );

											/* Grab a copy of the things that
												are needed over and over
												again */

			pDC = CDC::FromHandle( lpDrawItemStruct->hDC );
			rtItem = lpDrawItemStruct->rcItem;
											/* Save the state of the passed-in
												DC */
			iSavedDC = pDC->SaveDC();
											// Draw the contents of the item

			if (lpDrawItemStruct->itemAction & ODA_DRAWENTIRE)
			{
				DrawColorItem( lpDrawItemStruct, pDC, rtItem );
			}
			else if (lpDrawItemStruct->itemAction & ODA_FOCUS)
			{
											// Toggle the focus rect
				CRect	rtFocus( rtItem );

				rtFocus.InflateRect( -1, -1 );
				pDC->DrawFocusRect( &rtFocus );
			}
			else if (lpDrawItemStruct->itemAction & ODA_SELECT)
			{
											// Toggle the selection rect
				bool	boolSelected;

				boolSelected = !!(lpDrawItemStruct->itemState & ODS_SELECTED);
				DrawColorSelect( lpDrawItemStruct, pDC, rtItem, boolSelected );
			}
											// Restore the original DC state
			pDC->RestoreDC( iSavedDC );
			break;
		}

		case IDC_SAMPLE_BACK:
		case IDC_SAMPLE_TEXT:
		case IDC_SAMPLE_LINK:
		case IDC_SAMPLE_FLINK:
		case IDC_SAMPLE_PLINK:
		{
			DrawColorSample( lpDrawItemStruct );
			break;
		}

		default:
		{
			CPropertyPage::OnDrawItem( nIDCtl, lpDrawItemStruct );
			break;
		}
	}
}


void ChPrefsColorPage::OnSelchangeComboBackColor() 
{
	m_btnSampleBack.Invalidate( false );
	m_btnSampleText.Invalidate( false );
	m_btnSampleLink.Invalidate( false );
	m_btnSampleFLink.Invalidate( false );
	m_btnSamplePLink.Invalidate( false );

	// Invalidate the color combo boxes 
	m_comboBackColor.Invalidate( );
	m_comboTextColor.Invalidate( );
	m_comboLinkColor.Invalidate( );
	m_comboFLinkColor.Invalidate( );
	m_comboPLinkColor.Invalidate( );

}

void ChPrefsColorPage::OnSelchangeComboTextColor() 
{
	m_btnSampleText.Invalidate( false );
}

void ChPrefsColorPage::OnSelchangeComboLinkColor() 
{
	m_btnSampleLink.Invalidate( false );
}

void ChPrefsColorPage::OnSelchangeComboFlinkColor() 
{
	m_btnSampleFLink.Invalidate( false );
}

void ChPrefsColorPage::OnSelchangeComboPlinkColor() 
{
	m_btnSamplePLink.Invalidate( false );
}

