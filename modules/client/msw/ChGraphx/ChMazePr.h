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

	Interface for the ChMazePrefPage class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChMazePr.h,v 2.18 1996/09/12 19:09:46 pritham Exp $


#if (!defined( _CHMAZEPR_H_ ))
#define _CHMAZEPR_H_

#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN ) && !defined( CH_PUEBLO_PLUGIN )
#include "resource.h"
#else
#include "vwrres.h"
#endif

#if !defined(USE_CNM_CTL)
#define 		USE_CNM_CTL		
#endif

#include <ChReg.h>
#include <ChPage.h>
#include "ChGrType.h"
#if defined( WIN32 )

#if defined( USE_CNM_CTL )

	#include <afxcmn.h>					// MFC new control classes
#endif

#endif	// defined( WIN32 )

#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN ) && !defined( CH_PUEBLO_PLUGIN )
#define ChPropertyBaseClass ChPropertyPage
#else
#define ChPropertyBaseClass CPropertyPage
#endif

/*----------------------------------------------------------------------------
	ChMazePrefPage class
----------------------------------------------------------------------------*/

class ChMazePrefPage : public ChPropertyBaseClass
{
	DECLARE_DYNCREATE( ChMazePrefPage )

	public:
		ChMazePrefPage();
		ChMazePrefPage(int idd);
		~ChMazePrefPage();

		void Init();

		inline ChShadingLevel GetRenderLevel()
						{
							return (ChShadingLevel)m_iRenderLevel;
						}
		inline ChShadingLevel GetMoveRenderLevel()
						{
							return (ChShadingLevel)m_iMoveRenderLevel;
						}
		inline bool GetMovingVector() { return m_boolMoveVector; }
		inline bool GetScaleTextures() { return m_boolScaleTextures; }
		inline float GetHeadlightBrightness() { return float(float(m_iHeadlightBrightness) / 100.); }

		void SetInitialPreferences( ChShadingLevel renderLevel,
									ChShadingLevel moveRenderLevel,
									bool boolMoveVector,
									bool boolScaleTextures,
									float fHeadlight );
		void SetInitialPreferences( bool boolMoveVector,
									float fHeadlight);
		virtual void WritePreferences();
											// Overrides
		virtual bool OnSetActive();
		#if defined(CH_VRML_VIEWER)	|| defined( CH_VRML_PLUGIN ) || defined( CH_PUEBLO_PLUGIN )
		virtual BOOL OnKillActive( );
		#else
		virtual void OnCommit();
		#endif
#if 0
// Enable this block and comment out the enum in the afx_data block
// below except when using class wizard to modify this dialog	
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

	enum { IDD = IDD_PREF_PAGE_RLAB };
#else
#endif
#pragma message("Pref page selection disabled - please enable")
#else
#endif

#if defined( USE_CNM_CTL )
		CSliderCtrl	m_headlightBrightness;
#else
		CScrollBar	m_headlightBrightness;
#endif

		//{{AFX_DATA(ChMazePrefPage)
		enum { IDD = IDD_PREF_PAGE_VRML };
		BOOL	m_boolMoveVector;
		BOOL	m_boolScaleTextures;
		int		m_iMoveRenderLevel;
		int		m_iRenderLevel;
	//}}AFX_DATA

											/* ClassWizard generate virtual
												function overrides */
		//{{AFX_VIRTUAL(ChMazePrefPage)
		protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		//}}AFX_VIRTUAL

	protected:
		// Generated message map functions
		//{{AFX_MSG(ChMazePrefPage)
			// NOTE: the ClassWizard will add member functions here
			afx_msg void OnVScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar );
		//}}AFX_MSG

		DECLARE_MESSAGE_MAP()

	protected:
#if defined( USE_CNM_CTL )
		void ReadSliderPos( CSliderCtrl& slider, const char* strRegKey );
		void WriteSliderPos( CSliderCtrl& slider, const char* strRegKey );
 		void InitSlider( CSliderCtrl& slider );
  		int InvertSliderPos(CSliderCtrl& slider, int iPos);
#else
		void ReadSliderPos( CScrollBar& slider, const char* strRegKey );
		void WriteSliderPos( CScrollBar& slider, const char* strRegKey );
 		void InitSlider( CScrollBar& slider );
  		int InvertSliderPos(CScrollBar& slider, int iPos);
#endif

	protected:
		ChRegistry		m_reg;
		bool			m_boolInitialized;

		chint16			m_sOriginalRenderLevel;
		chint16			m_sOriginalRenderLevelMoving;
		chint16			m_iHeadlightBrightness;
		chuint16		m_suBrightnessRange;
};

#endif	// !defined( _CHMAZEPR_H_ )
