/*----------------------------------------------------------------------------
                        _                              _ _       
        /\             | |                            | (_)      
       /  \   _ __   __| |_ __ ___  _ __ ___   ___  __| |_  __ _ 
      / /\ \ | '_ \ / _` | '__/ _ \| '_ ` _ \ / _ \/ _` | |/ _` |
     / ____ \| | | | (_| | | | (_) | | | | | |  __/ (_| | | (_| |
    /_/    \_\_| |_|\__,_|_|  \___/|_| |_| |_|\___|\__,_|_|\__,_|

    The contents of this file are subject to the Andromedia Public
	License Version 1.0 (the "License"); you may not use this file
	except in compliance with the License. You may obtain a copy of
	the License at http://www.andromedia.com/APL/

    Software distributed under the License is distributed on an
	"AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
	implied. See the License for the specific language governing
	rights and limitations under the License.

    The Original Code is Pueblo client code, released November 4, 1998.

    The Initial Developer of the Original Code is Andromedia Incorporated.
	Portions created by Andromedia are Copyright (C) 1998 Andromedia
	Incorporated.  All Rights Reserved.

	Andromedia Incorporated                         415.365.6700
	818 Mission Street - 2nd Floor                  415.365.6701 fax
	San Francisco, CA 94103

    Contributor(s):
	--------------------------------------------------------------------------
	   Chaco team:  Dan Greening, Glenn Crocker, Jim Doubek,
	                Coyote Lussier, Pritham Shetty.

					Wrote and designed original codebase.

------------------------------------------------------------------------------

	Implementation of the ChMazePrefPage class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChMazePr.cpp,v 2.21 1996/09/12 19:09:46 pritham Exp $

#include "grheader.h"
//
#include "ChGraphx.h"
#include "ChMazePr.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define SLIDER_TICKS				10
#define SLIDER_PAGES				5
#define SLIDER_LINES				50
#define BRIGHTNESS_MAX_RANGE		100


/*----------------------------------------------------------------------------
	ChMazePrefPage class
----------------------------------------------------------------------------*/

IMPLEMENT_DYNCREATE( ChMazePrefPage, ChPropertyBaseClass )

ChMazePrefPage::ChMazePrefPage() :
	#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN ) && !defined(CH_PUEBLO_PLUGIN )
					ChPropertyBaseClass( ChMazePrefPage::IDD, 0,
										ChGraphicsDLL.hModule ),
					m_reg( GR_PREFS_GROUP ),
	#else
					ChPropertyBaseClass( ChMazePrefPage::IDD, 0 ),
					m_reg( CH_COMPANY_NAME, CH_VRML_PRODUCT_NAME, GR_PREFS_GROUP ),
	#endif
					m_suBrightnessRange( 100 ),
					m_boolInitialized( false )
{
	Init();
}


ChMazePrefPage::ChMazePrefPage(int idd) :
	#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN ) && !defined(CH_PUEBLO_PLUGIN )
					ChPropertyBaseClass( idd, 0,
										ChGraphicsDLL.hModule ),
					m_reg( GR_PREFS_GROUP ),
	#else
					ChPropertyBaseClass( idd, 0 ),
					m_reg( CH_COMPANY_NAME, CH_VRML_PRODUCT_NAME, GR_PREFS_GROUP ),
	#endif
					m_suBrightnessRange( 100 ),
					m_boolInitialized( false )
{
	Init();
}


ChMazePrefPage::~ChMazePrefPage()
{
}


void ChMazePrefPage::Init()
{
	//{{AFX_DATA_INIT(ChMazePrefPage)
	m_boolMoveVector = -1;
	m_boolScaleTextures = -1;
	m_iMoveRenderLevel = -1;
	m_iRenderLevel = -1;
	//}}AFX_DATA_INIT

	//m_iViewerMode = -1;
}

void ChMazePrefPage::DoDataExchange( CDataExchange* pDX )
{
	ChPropertyBaseClass::DoDataExchange( pDX );
	// eventually, the #if'd vars will move to another class

	//{{AFX_DATA_MAP(ChMazePrefPage)
	DDX_Check(pDX, IDC_CHECK_VECTOR, m_boolMoveVector);
	#if !(defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	DDX_Check(pDX, IDC_CHECK_SCALE, m_boolScaleTextures);
	DDX_CBIndex(pDX, IDC_COMBO_MOVING, m_iMoveRenderLevel);
	DDX_CBIndex(pDX, IDC_COMBO_STILL, m_iRenderLevel);
	#endif
	DDX_Control(pDX, IDC_HEADLIGHT_BRIGHTNESS, m_headlightBrightness);
	//}}AFX_DATA_MAP
	
	//DDX_CBIndex(pDX, IDC_COMBO_VIEWER_MODE, m_iViewerMode);
}


void ChMazePrefPage::SetInitialPreferences( ChShadingLevel renderLevel,
											ChShadingLevel moveRenderLevel,
											bool boolMoveVector,
											bool boolScaleTextures,
											float fHeadlight )
{
	m_iRenderLevel = m_sOriginalRenderLevel = (chint16)renderLevel;
	m_iMoveRenderLevel = m_sOriginalRenderLevelMoving =
			(chint16)moveRenderLevel;
	m_boolScaleTextures = boolScaleTextures;


	ChMazePrefPage::SetInitialPreferences(  boolMoveVector,
											 fHeadlight );

}

void ChMazePrefPage::SetInitialPreferences( bool boolMoveVector,
											float fHeadlight )
{
	m_boolMoveVector = boolMoveVector;
	m_iHeadlightBrightness = chint16( 100 * fHeadlight + .5 );

	//m_iViewerMode = m_sOriginalViewerMode = chint16(viewerMode);
}


void ChMazePrefPage::WritePreferences()
{
	if (m_boolInitialized)
	{
		#if !(defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		// just disable until we spilt this into a separate 3dr class
		if (m_sOriginalRenderLevel != m_iRenderLevel)
		{
			chint16			sSetting;

			sSetting = (chint16)m_iRenderLevel;
			m_reg.Write( GR_PREFS_RENDER_QUALITY, sSetting );
		}

		if (m_sOriginalRenderLevelMoving != m_iMoveRenderLevel)
		{
			chint16			sSetting;

			sSetting = (chint16)m_iMoveRenderLevel;
			m_reg.Write( GR_PREFS_RENDER_QUALITY_MOVING, sSetting );
		}
		m_reg.WriteBool( GR_PREFS_DRAW_SCALE_PAT, m_boolScaleTextures );
		#endif // RLAB


		#if defined( USE_CNM_CTL )
		m_iHeadlightBrightness = m_headlightBrightness.GetPos();
		#else
		m_iHeadlightBrightness = m_headlightBrightness.GetScrollPos();
		#endif	   
 		m_iHeadlightBrightness = InvertSliderPos( m_headlightBrightness, m_iHeadlightBrightness );

		WriteSliderPos( m_headlightBrightness, GR_PREFS_HEADLIGHT_BRIGHTNESS);

		m_reg.WriteBool( GR_PREFS_DRAW_MOVE_VECTOR, m_boolMoveVector );

	}
}

#if defined( USE_CNM_CTL )
void ChMazePrefPage::ReadSliderPos( CSliderCtrl& slider, const char* strRegKey )
#else
void ChMazePrefPage::ReadSliderPos( CScrollBar& slider, const char* strRegKey )
#endif
{
	chuint16	iPos;

	m_reg.Read( strRegKey, iPos, BRIGHTNESS_MAX_RANGE );
	if (iPos > BRIGHTNESS_MAX_RANGE)
	{
		iPos = BRIGHTNESS_MAX_RANGE;
	}

	iPos = InvertSliderPos( slider, iPos );
	#if defined( USE_CNM_CTL )
	slider.SetPos( iPos );
	#else
	slider.SetScrollPos( iPos );
	#endif
}


#if defined( USE_CNM_CTL )
void ChMazePrefPage::WriteSliderPos( CSliderCtrl& slider, const char* strRegKey )
#else
void ChMazePrefPage::WriteSliderPos( CScrollBar& slider, const char* strRegKey )
#endif
{
	int			iPos;

	#if defined( USE_CNM_CTL )
	iPos = slider.GetPos();
	#else
	iPos = slider.GetScrollPos();
	#endif

	iPos = InvertSliderPos( slider, iPos );

	m_reg.Write( strRegKey, iPos );
}

#if defined( USE_CNM_CTL )
int ChMazePrefPage::InvertSliderPos(CSliderCtrl& slider, int iPos)
#else
int ChMazePrefPage::InvertSliderPos(CScrollBar& slider, int iPos)
#endif
{
	int iMin, iMax;

	#if defined( USE_CNM_CTL )
	slider.GetRange(iMin, iMax);
	#else
	slider.GetScrollRange( &iMin, &iMax);
	#endif

	return (iMax - iPos);
}

#if defined( USE_CNM_CTL )
void ChMazePrefPage::InitSlider( CSliderCtrl& slider )
#else
void ChMazePrefPage::InitSlider( CScrollBar& slider )
#endif
{
	#if defined( USE_CNM_CTL )
	slider.SetRange( 0, m_suBrightnessRange );
	slider.SetLineSize( m_suBrightnessRange / SLIDER_LINES );
	slider.SetPageSize( m_suBrightnessRange / SLIDER_PAGES );
	slider.SetTicFreq( m_suBrightnessRange / SLIDER_TICKS );
	#else
	slider.SetScrollRange( 0, m_suBrightnessRange );
	#endif
}


BEGIN_MESSAGE_MAP( ChMazePrefPage, ChPropertyBaseClass )
	//{{AFX_MSG_MAP(ChMazePrefPage)
		// NOTE: the ClassWizard will add message map macros here
		ON_WM_VSCROLL( )	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void ChMazePrefPage::OnVScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar )
{
	#if !defined( USE_CNM_CTL )
	switch( nSBCode )
	{
		case SB_LINEDOWN  :
		{
			m_headlightBrightness.SetScrollPos( m_headlightBrightness.GetScrollPos() + 1 );
			break;
		}
		case SB_LINEUP  :
		{
			m_headlightBrightness.SetScrollPos( m_headlightBrightness.GetScrollPos() - 1 );
			break;
		}
		case SB_PAGEDOWN  :
		{
			m_headlightBrightness.SetScrollPos( m_headlightBrightness.GetScrollPos() + 10 );
			break;
		}
		case SB_PAGEUP  :
		{
			m_headlightBrightness.SetScrollPos( m_headlightBrightness.GetScrollPos() - 10 );
			break;
		}
		case SB_THUMBTRACK  :
		{
			m_headlightBrightness.SetScrollPos( nPos );
			break;
		}
	} 
	#endif
}



bool ChMazePrefPage::OnSetActive()
{
	bool	boolResult;

	ASSERT( m_boolMoveVector != -1 );

	boolResult = ChPropertyBaseClass::OnSetActive();
	
	InitSlider(m_headlightBrightness);
	 
	int iPos = InvertSliderPos( m_headlightBrightness, m_iHeadlightBrightness );
	#if defined( USE_CNM_CTL )
	m_headlightBrightness.SetPos( iPos );
	#else
	m_headlightBrightness.SetScrollPos( iPos );
	#endif

	if (!m_boolInitialized)
	{

		m_boolInitialized = true;
	}

	return boolResult;
}



#if defined(CH_VRML_VIEWER) || defined( CH_VRML_PLUGIN )  || defined( CH_PUEBLO_PLUGIN )
BOOL ChMazePrefPage::OnKillActive( )
{
	ASSERT( m_boolMoveVector != -1 );
 	UpdateData( true );

	WritePreferences();
	return true;
}
#else
void ChMazePrefPage::OnCommit()
{
	ASSERT( m_boolMoveVector != -1 );

	WritePreferences();
}
#endif


/*----------------------------------------------------------------------------
	ChMazePrefPage message handlers
----------------------------------------------------------------------------*/

