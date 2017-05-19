// chbasdoc.cpp : implementation file
//

#include "stdafx.h"
#include  <ChReg.h>
#include <ChHTTP.h>
#include <ChUrlMap.h>

#include "resource.h"
#include "ChBasDoc.h" 
#include "ChBaseVw.h"
#include "ChHtmDsp.h"
#include "ChMFrame.h"

#include <iostream.h>
#include <fstream.h>


#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ChBaseDoc

IMPLEMENT_DYNCREATE(ChBaseDoc, CDocument)

ChBaseDoc::ChBaseDoc() : m_pFrame ( 0 ),
						 m_pHTMLView( 0 )
{
}

BOOL ChBaseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// cache the pointer to our view
	POSITION pos = GetFirstViewPosition( );
	ASSERT( pos );		
	m_pHTMLView = ((ChBaseView*)GetNextView( pos ))->GetHTMLWnd(); 
	pos = GetFirstViewPosition( );
	m_pFrame = (ChMainFrame*)GetNextView( pos )->GetParentFrame( );
	ASSERT( m_pFrame );

	return TRUE;
}

BOOL ChBaseDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
 	string strURL;
 	string strMimeType;


	{  // convert the local file to URL of file scheme
		ChURLParts::MapHostFileToURL( lpszPathName,  strURL );
	}

	 GetHTMLWnd()->LoadURL( strURL );

	return true;
}


ChBaseDoc::~ChBaseDoc()
{
}


BEGIN_MESSAGE_MAP(ChBaseDoc, CDocument)
	//{{AFX_MSG_MAP(ChBaseDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// ChBaseDoc diagnostics

#ifdef _DEBUG
void ChBaseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void ChBaseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// ChBaseDoc serialization

void ChBaseDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		string strFile = GetHTMLWnd()->GetFilename();
		ifstream in(strFile);
		while(!in.eof())
		{
			char buf[1024];

			in.read(buf, sizeof(buf));
			ar.Write(buf, in.gcount());
		}
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// ChBaseDoc commands

#if 0

void ChBaseDoc::OnEditCopy() 
{
}



void ChBaseDoc::OnFileOpenLoc() 
{
	// TODO: Add your command handler code here
	COpenLoc openLoc( GetHTMLWnd(), m_pFrame );

	if ( IDOK ==  openLoc.DoModal() )
	{
		GetHTMLWnd()->LoadURL( openLoc.GetLocation() );
	}
}	
				   
void ChBaseDoc::OnGoBack() 
{
	// TODO: Add your command handler code here
	GetHTMLWnd()->GoBackward( );
}

void ChBaseDoc::OnUpdateGoBack(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( GetHTMLWnd()->CanGoBackward( ) );
}

void ChBaseDoc::OnGoForward() 
{
	GetHTMLWnd()->GoForward( );
}

void ChBaseDoc::OnUpdateGoForward(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( GetHTMLWnd()->CanGoForward( ) );
}

void ChBaseDoc::OnGoHome() 
{
	// TODO: Add your command handler code here
	GetHTMLWnd()->LoadURL( GetHTMLWnd()->GetHomePage() );
}


void ChBaseDoc::OnUpdateGoHome(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( !GetHTMLWnd()->GetHomePage( ).IsEmpty() );
}


void ChBaseDoc::OnGoStopLoading() 
{
	// TODO: Add your command handler code here
	m_pFrame->GetHTTPConn()->AbortRequests();
}

void ChBaseDoc::OnViewRefresh() 
{
	GetHTMLWnd()->Invalidate();
}

void ChBaseDoc::OnUpdateViewRefresh(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( !GetHTMLWnd()->GetDocURL().IsEmpty() );	
}

void ChBaseDoc::OnViewReload() 
{
	// TODO: Add your command handler code here
	GetHTMLWnd()->LoadURL( GetHTMLWnd()->GetDocURL(), ChHTTPConn::ReloadURL );

}

void ChBaseDoc::OnUpdateViewReload(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( !GetHTMLWnd()->GetDocURL().IsEmpty() );	
}




/*----------------------------------------------------------------------------

	FUNCTION	||	ChApp::OnAppAbout

------------------------------------------------------------------------------

	This function will execute the 'About Pueblo' dialog.

----------------------------------------------------------------------------*/

void ChBaseDoc::OnAppAbout()
{
	ChAbout		aboutDlg( IDS_ABOUT_TITLE, m_pFrame );

	aboutDlg.DoModal();
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChApp::OnEditPreferences

------------------------------------------------------------------------------

	This function will execute the preferences property sheet.

----------------------------------------------------------------------------*/

void ChBaseDoc::OnEditPreferences() 
{
	ChPrefs				prefsDlg( IDS_TITLE_PREFS_DLG, m_pFrame );
	ChPrFont			prefsFonts;
	ChCachePrefsPage	prefsCache;
	ChNetworkPage		prefsNetwork;

											/* Add the property pages for this
												property sheet */
	prefsDlg.AddPage( &prefsFonts );
	prefsDlg.AddPage( &prefsCache );
	prefsDlg.AddPage( &prefsNetwork );

											/* Execute the property sheet
												modally */
	prefsDlg.DoModal();
}



void ChBaseDoc::OnFileOpen() 
{
	// TODO: Add your command handler code here
	string strFilter;
	ChWebTrackerManager::WTrackerLoadString( IDS_OPEN_WEB_TRACKER_FILTER, strFilter );

	CFileDialog	fileOpen( true, NULL, NULL,
					OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
					strFilter, m_pFrame );

	if ( fileOpen.DoModal() == IDOK )
	{
		string strURL;
		ChURLParts::MapHostFileToURL( fileOpen.GetPathName( ),  strURL );
		GetHTMLWnd()->LoadURL( strURL );
	}
}
#endif // 0
