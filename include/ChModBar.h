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

	Implementation for the ChModuleBar class.  This class is the parent for
	all tear-off bar type classes used by modules.  This class is MSW-only.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/ChModBar.h,v 2.3 1995/10/24 00:05:14 coyote Exp $

#error "This file is defunct.  Please don't use it.  -- Ron Lussier"

#if !defined( _CHMODBAR_H )
#define _CHMODBAR_H      
#include <ChTlBar.h>

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA    
#endif

/*----------------------------------------------------------------------------
	ChModuleBar class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS ChModuleBar : public ChToolBar
{
	public:
		enum tagBarStyles { showTitle = 1 };
		enum tagDockAlign { dockTop = 1, dockBottom = 2, dockLeft = 4,
							dockRight = 8,
							dockTopBottom = dockTop | dockBottom,
							dockLeftRight = dockLeft | dockRight,
							dockAll = dockTopBottom | dockLeftRight };

	public:
		ChModuleBar( chflag32 flStyle = 0 );
		virtual ~ChModuleBar();

		bool Create( string strTitle = "", CWnd* pParent = 0,
						chint32 lWidth = 0, chint32 lHeight = 0,
						chflag32 flDockSides = dockAll );

		void SaveState();
		void RestoreState();

		inline chint32 GetLeftBorder() const 
							{  
								#if defined( CH_ARCH_16 )   
								return ChToolBar::GetLeftBorder();
								#else
								return m_cxLeftBorder; 
								#endif
							} 
		inline chint32 GetRightBorder() const 
					{ 
						#if defined( CH_ARCH_16 )   
						return ChToolBar::GetRightBorder();
						#else
						return m_cxRightBorder;    
						#endif
					}
		inline chint32 GetTopBorder() const 
					{ 
						#if defined( CH_ARCH_16 )   
						return ChToolBar::GetTopBorder();
						#else
						return m_cyTopBorder;    
						#endif
					}
		inline chint32 GetBottomBorder() const 
					{ 
						#if defined( CH_ARCH_16 )   
						return ChToolBar::GetBottomBorder();
						#else
						return m_cyBottomBorder;    
						#endif
					}

		inline void SetHeight( chint32 lHeight ) 
							{ 
								m_lHeight = lHeight; 
								#if defined( CH_ARCH_16 )
								ChToolBar::SetHeight( (int)m_lHeight );  
								#endif
							}
		inline void SetWidth( chint32 lWidth ) { m_lWidth = lWidth; }

		virtual CSize CalcFixedLayout( bool boolStretch, bool boolHorz );
		virtual void DoPaint( CDC* pDC );
		virtual int HitTest( CPoint point );

		bool SetButtons( const UINT* pIDArray, int iCount );

		#if defined( CH_ARCH_16 )
		CFrameWnd* GetDockingFrame() const
		{
			return GetParentFrame();
		}
		#endif

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ChModuleBar)
	//}}AFX_VIRTUAL

	protected:
		void CalcOutsideRect( CRect& rtFrame, bool boolHorz = true ) const;
		bool SaveFocusControl();
	
	protected:
		chint32			m_lHeight;
		chint32			m_lWidth;

		chint16			m_sBorderVert;
		chint16			m_sBorderHorz;

		chint16			m_sBorderHorz2;
		chint16			m_sBorderVert2;

		chint16			m_sCount;			// Number of buttons
		chflag32		m_flStyle;

		HWND			m_hWndFocus;		// Last known focus window

	protected:
		//{{AFX_MSG(ChModuleBar)
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR    
#endif

#endif	// !defined( _CHMODBAR_H )
