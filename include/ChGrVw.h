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

	This file consists of the interface for the ChTxtView view class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/ChGrVw.h,v 2.16 1996/07/02 19:30:30 pritham Exp $

#if !defined( _CHGRVW_H )
#define _CHGRVW_H

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA    
#endif

#if defined( CH_MSW )
											/* Disable warnings about non-
												exported classes for MSW */
	#pragma warning( disable: 4275 )
	#pragma warning( disable: 4251 )

#endif	// defined( CH_MSW )


#if defined( CH_MSW )

	#include <mmsystem.h>

#endif	// defined( CH_MSW )

#include <ChTypes.h>

#if !defined( CH_VRML_VIEWER ) && !defined( CH_VRML_PLUGIN )

	#include <ChCore.h>
	#include <ChScrWnd.h>
	#include <ChPane.h>

#endif

//#include <ChDibImage.h>

#if !defined( CH_VRML_VIEWER ) && !defined( CH_VRML_PLUGIN )
	class ChGraphicMainInfo;
#endif

class ChDibPal;

/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define CH_DEF_COLOR	0x80000000

#if defined( CH_VRML_PLUGIN )

#define ChViewBaseClass		CWnd

#elif defined( CH_VRML_VIEWER )

#define ChViewBaseClass		CView

#else

#define ChViewBaseClass		ChScrollWnd

#endif


/*----------------------------------------------------------------------------
	ChGraphicView class
----------------------------------------------------------------------------*/

#if !defined( CH_VRML_VIEWER ) && !defined( CH_VRML_PLUGIN )

class ChGraphicView : public ChViewBaseClass, public ChPaneWndMethods

#else	// !defined( CH_VRML_VIEWER ) && !defined( CH_VRML_PLUGIN )

class ChGraphicView : public ChViewBaseClass

#endif	// !defined( CH_VRML_VIEWER ) && !defined( CH_VRML_PLUGIN )
{
	protected: 
		#if defined(CH_VRML_VIEWER)	 || defined(CH_VRML_PLUGIN )
		ChGraphicView( );
		#else
		ChGraphicView( ChGraphicMainInfo *pInfo );
		#endif
    	  
		#if defined( CH_VRML_VIEWER )
 		DECLARE_DYNCREATE( ChGraphicView )
		#endif

		#if !defined( CH_VRML_VIEWER ) && !defined( CH_VRML_PLUGIN )

		virtual void GetIdealSize( ChSize& size );
		virtual void OnFrameDisconnect( const ChModuleID& idNewModule );

		#endif

	public:
	    ChDibPal* m_pPal;					// Palette for drawing

	public:
    	CDocument* GetDocument();
		
		#if defined( CH_MSW )
											// Create a wnd

			bool Create( const CRect& rtView, CWnd* pParent,
							DWORD dwStyle = WS_VISIBLE | WS_BORDER, // | WS_VSCROLL,
							UINT uiID = 0 );

		#endif	// defined( CH_MSW )

		#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
		inline ChGraphicMainInfo* GetMainInfo() { return m_pGraphicInfo; }
		#endif

		ChDibPal *GetPalette() { return m_pPal; }

											// Draw off-screen buffer to screen

    	virtual void Draw( CDC* pDC = 0, RECT* pClipRect = 0 );

	    virtual void Render( CRect* pClipRect = 0 ) { return; }
		virtual void Animate( bool boolRun ) { return; }

		virtual bool IsCurrent();
	public:
    	virtual ~ChGraphicView();
    	virtual void OnDraw( CDC* pDC );	// Overridden to draw this view
    	virtual void OnInitialUpdate();		// First time after construction

    	virtual void OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint );

		#if defined( _DEBUG )

		    virtual void AssertValid() const;
		    virtual void Dump( CDumpContext& dc ) const;

		#endif	// defined( _DEBUG )

	private :
		#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
		ChGraphicMainInfo*	   	m_pGraphicInfo;
		#endif

	public:
		virtual bool NotifyPaletteChange( UINT uMsg, CWnd* pFocusWnd )
					{
						bool boolIsProcessed = false;

						if(IsCurrent())
						{
							switch (uMsg)
							{
								case WM_PALETTECHANGED:
								{
									OnPaletteChanged(pFocusWnd);
									break;
								}
								case WM_QUERYNEWPALETTE:
								{
									OnQueryNewPalette();
									boolIsProcessed = true;
									break;
								}
							}
						}
						return boolIsProcessed;
					}
	protected:
											// Generated message map functions
	    //{{AFX_MSG(ChGraphicView)
	    afx_msg void OnPaletteChanged(CWnd* pFocusWnd);
	    afx_msg BOOL OnQueryNewPalette();
	    //}}AFX_MSG

	    DECLARE_MESSAGE_MAP()

};

#ifndef _DEBUG  // Debug version in ChGrVw.cpp
inline CDocument* ChGraphicView::GetDocument()
   { return (CDocument*) 0; }
#endif

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR    
#endif

#endif	// !defined( _CHGRVW_H )
