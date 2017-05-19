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

----------------------------------------------------------------------------*/
#include "stdafx.h"

#include "resource.h"
#include "ChMFrame.h"
#include "ChBasDoc.h"
#include "ChBaseVw.h"
#include <ChWebTracker.h>



CH_EXTERN_VAR AFX_EXTENSION_MODULE WTrackerDLL;

CH_GLOBAL_VAR ChWebTrackerManager webTrackerMgr;



CSingleDocTemplate* ChWebTracker::GetDocumentTemplate()
{	
	return ( new CSingleDocTemplate( IDR_MAINFRAME, RUNTIME_CLASS( ChBaseDoc ),
								RUNTIME_CLASS( ChMainFrame ),
								RUNTIME_CLASS( ChBaseView ) ) );
}

bool ChWebTracker::LoadWebTracker( const string& strURL, const char* pstrFrameName /* = 0 */,
													CWnd* pOwner /* = 0 */ )
{

	HINSTANCE hInstOld = AfxGetResourceHandle(  );
	AfxSetResourceHandle( WTrackerDLL.hResource );

	if ( !webTrackerMgr.m_pDocTemplate )
	{
	  	webTrackerMgr.m_pDocTemplate = GetDocumentTemplate();
	}

	ASSERT( webTrackerMgr.m_pDocTemplate );

	string strName( pstrFrameName ? pstrFrameName : WEBTRACKER );

	strName.MakeLower();

	ChMainFrame* pWnd = webTrackerMgr.FindFrame( strName );
	if ( !pWnd )
	{
		pWnd = ( ChMainFrame* )webTrackerMgr.m_pDocTemplate->CreateNewFrame( 0, 0 );
		ASSERT( pWnd );

		if ( pOwner )
		{
			pWnd->SetOwner( pOwner );
		}
		pWnd->SetFrameName( strName );
		webTrackerMgr.m_pDocTemplate->InitialUpdateFrame( pWnd, 0, true );
	}

	AfxSetResourceHandle( hInstOld );


	if ( pWnd && !strURL.IsEmpty() )
	{
		pWnd->LoadURL( strURL );
	}

	return pWnd != 0;
}

void ChWebTracker::CloseAllFrames()
{
 	webTrackerMgr.DeleteAllFrames();
}

//////////////////////////////////////////////////////////////////
////////////	ChWebTrackerManager
/////////////////////////////////////////////////////////////////

ChMainFrame* ChWebTrackerManager::FindFrame( const string& strName )
{
	ChMainFrame** ppFrame= m_frameList.Find( strName ); 
	if ( ppFrame && *ppFrame )
	{
		return *ppFrame;		
	}

	return 0;
}



void ChWebTrackerManager::AddToFrameList( const string& strName, ChMainFrame* pFrame )
{
	if ( !m_frameList.Find( strName ) )
	{
		m_frameList.Insert( strName, pFrame );		
	}

}

void ChWebTrackerManager::RemoveFromFrameList( const string& strName, ChMainFrame* pFrame )
{
	if ( !m_boolInDeleteAll )
	{
		m_frameList.Delete( strName );
	}
}

/*----------------------------------------------------------------------------
	ChVisitDeleteAll class
----------------------------------------------------------------------------*/

class ChVisitDeleteAll : public ChVisitor2<string, ChMainFrame*>
{
	public:
		ChVisitDeleteAll() {}

		bool Visit( const string& strName,
					 ChMainFrame* const&  pFrame );
};


bool ChVisitDeleteAll::Visit( const string& strName,
					 ChMainFrame* const&  pFrame )
{
	pFrame->SendMessage( WM_COMMAND, ID_APP_EXIT );
	return true;
}



void ChWebTrackerManager::DeleteAllFrames(  )
{
	ChVisitDeleteAll deleteAll;

	m_boolInDeleteAll = true;

	m_frameList.Infix( deleteAll );
	m_frameList.Erase();

	m_boolInDeleteAll = false;
}


int	 ChWebTrackerManager::WTrackerLoadString( UINT nID, string& strBuffer )
{
	LPTSTR 	lpszBuf = strBuffer.GetBuffer( 255 );
	ASSERT( lpszBuf );
	int nLen;
	if ((nLen = ::LoadString(WTrackerDLL.hResource, nID, lpszBuf, 255)) != 0)
	{  
		strBuffer.ReleaseBuffer();
		return nLen;
	}

	strBuffer.ReleaseBuffer();
	return 0;

}
