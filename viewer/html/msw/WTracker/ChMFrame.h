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

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChMFrame.h,v 1.5 1996/03/30 00:39:02 pritham Exp $

#if (!defined( _CHMFRAME_H ))
#define _CHMFRAME_H

#include <ChSplay.h>
#include <ChHtpCon.h>
#include "ChLocBar.h"
#include "ChBaseVw.h"

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA    
#endif


class ChMainFrame;

typedef ChSplay< string, ChMainFrame*> 		ChFrameList;


/*============================================================================
class ChWebTrackerStatic
============================================================================*/

class ChWebTrackerManager
{
	public :
		ChWebTrackerManager() : m_pDocTemplate( 0 ),
								m_boolInDeleteAll( false )
			{
			}
		~ChWebTrackerManager() 
			{
				delete m_pDocTemplate;
			}


		void AddToFrameList( const string& strName, ChMainFrame* pFrame ); 
		void RemoveFromFrameList( const string& strName, ChMainFrame* pFrame ); 
		void DeleteAllFrames();
		ChMainFrame* FindFrame( const string& strName );
		static int	 WTrackerLoadString( UINT iID, string& strBuffer );
	public  :
		CSingleDocTemplate*  m_pDocTemplate;
		ChFrameList			m_frameList;
		bool				m_boolInDeleteAll;
};

CH_EXTERN_VAR ChWebTrackerManager webTrackerMgr;



/*============================================================================
								CONSTANTS
============================================================================*/


#define ID_PROGRESS_UPDATE_TIMER		100
#define HALF_SECOND_TIMER_DURATION		500

/*============================================================================
				ChMainFrame class interface
============================================================================*/

class ChMainFrame : public CFrameWnd
{
	DECLARE_DYNCREATE( ChMainFrame )

	protected:								// create from serialization only
		ChMainFrame();

	public:
		virtual ~ChMainFrame();

		#ifdef _DEBUG
			virtual void AssertValid() const;
			virtual void Dump( CDumpContext& dc ) const;
		#endif


		ChBrowserWnd* GetHTMLWnd()		{ return ((ChBaseView*)GetActiveView())->GetHTMLWnd(); }
		ChHTTPConn*   GetHTTPConn()		{ return &m_httpConn; }
		void UpdateLocationBar( const string& strURL );
		void LoadURL( const string& strURL );


		void SetFrameName( const string& strName );
											// Operations
#ifdef CH_MSW
		ChFont*		GetAppFont()				{ return m_pAppFont; }
#endif

	public:
											/* ClassWizard generated virtual
												function overrides */
	//{{AFX_VIRTUAL(ChMainFrame)
	public:
		virtual bool PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	protected:
		void InitStatusBar();
		void DrawProgressBar();
		inline chint16 GetProgressWidth() { return m_sProgressWidth; }
		inline void SetProgressWidth( chint16 sWidth )
						{ m_sProgressWidth = sWidth; }
		void ClearStatus( );


	private:
		static string		m_strClass;

		string				m_strFrameName;
											// control bar embedded members
		CStatusBar		m_wndStatusBar;
		CToolBar	    m_wndToolBar;
		ChLocationBar  	m_wndDlgBar;


		chint16			m_sProgressWidth;	// Width of progress bar in pixels
		#if defined( CH_MSW )
		ChFont*			m_pAppFont;
		#endif
		int				m_idTimer;			// Timer ID
		bool			m_boolInProgress;
		bool			m_boolUpdate;
		HINSTANCE		m_hResourceOld;
		static CBrush	m_brClearProgress;
		static CBrush	m_brShowProgress; 

		ChHTTPSocketConn	m_httpConn;


											// Generated message map functions
	protected:
		//{{AFX_MSG(ChMainFrame)
		afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		afx_msg void OnClose();
		afx_msg void OnPaletteChanged(CWnd* pFocusWnd);
		afx_msg BOOL OnQueryNewPalette();
		afx_msg void OnTimer(UINT nIDEvent);
		afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
		afx_msg void OnEditCopy();
		afx_msg void OnFileOpenLoc();
		afx_msg void OnGoBack();
		afx_msg void OnUpdateGoBack(CCmdUI* pCmdUI);
		afx_msg void OnGoForward();
		afx_msg void OnUpdateGoForward(CCmdUI* pCmdUI);
		afx_msg void OnGoHome();
		afx_msg void OnGoStopLoading();
		afx_msg void OnViewRefresh();
		afx_msg void OnViewReload();
		afx_msg void OnUpdateViewReload(CCmdUI* pCmdUI);
		afx_msg void OnUpdateViewRefresh(CCmdUI* pCmdUI);
		afx_msg void OnUpdateGoStopLoading(CCmdUI* pCmdUI);
		afx_msg void OnAppAbout();
		afx_msg void OnEditPreferences();
		afx_msg void OnUpdateGoHome(CCmdUI* pCmdUI);
		afx_msg void OnFileOpen();
		afx_msg void OnFrameClose();
		afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	//}}AFX_MSG

		DECLARE_MESSAGE_MAP()
};

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR 
#endif

#endif	// !defined( _CHMFRAME_H )
