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

	Implementation for the ChTextOutput class, which is used to display
	output text.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChHtmDsp.cpp,v 1.8 1996/06/07 03:06:40 pritham Exp $

#include "stdafx.h"
#include <ChUtil.h>
#include <ChReg.h>
#include <ChHtpCon.h>
#include <ChHtmlSettings.h>
#include <iostream.h>
#include <fstream.h>


#include "resource.h"
#include "ChMFrame.h"
#include "ChHtmDsp.h"

#ifdef CH_UNIX
#include <ChTypes.h>
#include "../../unix/ChText/TextPriv.h"
#endif

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
	Chaco menu handlers
----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------
	ChTextOutMainInfo class
----------------------------------------------------------------------------*/





/*----------------------------------------------------------------------------
	ChBrowserWnd class
----------------------------------------------------------------------------*/

ChBrowserWnd::ChBrowserWnd( ChHTTPConn *pConn ) : ChHtmlWnd( pConn )
{
	m_listPos = 0;
	GetSettings()->SetProductName( CH_HTML_PRODUCT_NAME );
}

ChBrowserWnd::~ChBrowserWnd()
{
	ChRegistry reg( CH_COMPANY_NAME, CH_HTML_PRODUCT_NAME, VISIT_HISTORY );
	string   strKey;

	int iCount = 0;

	ChPosition pos = m_urlList.GetTailPosition();

	string visitedList[10];

	while( pos )
	{
		ChHTMLHistory *pvrmlHist = (ChHTMLHistory*)m_urlList.GetPrev( pos );
		// Write the last 10 visits into registry	
		if ( iCount < 10 )
		{
			bool boolAdd = true;

			for ( int i  = 0; i < iCount; i++ )
			{
				if ( visitedList[i] == pvrmlHist->GetURL() )
				{
					boolAdd = false;
					break;
				}

			}

			if ( boolAdd )
			{
				strKey.Format( VISIT_KEY, iCount );
				reg.Write( strKey, pvrmlHist->GetURL() );
				visitedList[iCount++]	= pvrmlHist->GetURL();
			}
		}

		delete pvrmlHist;
	}
}


void ChBrowserWnd::OnLoadComplete( const string& strFile, const string& strURL, 
											const string& strMimeType,
											chparam userData )
{
	// Load the file to display
	ChHtmlWnd::OnLoadComplete( strFile, strURL, strMimeType, userData );

	// Zap the pending request
	m_strPendingRequest.Empty();
	
	if ( strURL == GetDocURL() )
	{
		{
			ChHTMLHistory *pNew = new ChHTMLHistory( strURL, strFile, strMimeType );
			m_urlList.AddTail( (chparam)pNew);
			m_listPos = m_urlList.GetTailPosition();
		}

		UpdateFrameOnLoad( strURL, strFile );
	}

}

void ChBrowserWnd::OnLoadError( chint32 lError, const string& strErrMsg, 
								const string& strURL,	chparam userData  )
{
	// Zap the pending request
	m_strPendingRequest.Empty();
	// Display the error message
	if ( lError >= CH_HTTP_CLIENT_ERROR_BASE )
	{
		string strCaption;
		ChWebTrackerManager::WTrackerLoadString( AFX_IDS_APP_TITLE, strCaption );
		string strData( "Error : " );
		strData += strErrMsg;
		strData += TEXT( "\r\nURL : " );
		strData += strURL;

		ChMainFrame* pFrame = (ChMainFrame*)GetParentFrame(); 

		pFrame->MessageBox( strData, strCaption, MB_OK | MB_ICONEXCLAMATION );
	}
	else
	{
		string strFile;
		ChUtil::GetTempFileName( strFile, 0, 0, ".htm" );
		
		fstream errFile( strFile, ios::out, filebuf::sh_none );
		if ( errFile.is_open() )
		{

			ChUtil::AddFileToTempList( strFile );

			string strData( "<html><h1>" );
			errFile.write( strData, strData.GetLength() );
			errFile.write( strErrMsg, strErrMsg.GetLength() );
			strData = "</h1>";
			errFile.write( strData, strData.GetLength() );	 
			errFile.close();

			string strMimeType( MIME_HTML );
			if ( DisplayFile(  strFile, strMimeType, ChHtmlWnd::fileReplace, strURL ) )
			{
				ChHTMLHistory *pNew = new ChHTMLHistory( strURL, strFile, strMimeType );
				m_urlList.AddTail( (chparam)pNew);
				m_listPos = m_urlList.GetTailPosition();
	
				UpdateFrameOnLoad( strURL, strFile );
			}

		}
		else
		{
			string strCaption;
			ChWebTrackerManager::WTrackerLoadString( AFX_IDS_APP_TITLE, strCaption );
			ChMainFrame* pFrame = (ChMainFrame*)GetParentFrame(); 
			pFrame->MessageBox( strErrMsg, strCaption, MB_OK | MB_ICONEXCLAMATION );
		}
		 
	}


}


// Notification when cursor is on hotspot
void ChBrowserWnd::OnHotSpot( chparam userData,
								const string& strDocURL  )
{ // add code here for status bar update
	if (  userData )
	{
		string strHint;

		GetHTMLAttribute( (const char*)userData, TEXT("href" ), strHint );
		GetParentFrame()->SetMessageText( strHint );
	}
	else
	{
		GetParentFrame()->SetMessageText( TEXT( "" ) );
	}

}



void ChBrowserWnd::AbortRequests( )
{
	m_strPendingRequest.Empty();
	GetHTTPConn()->AbortRequests(); 
}

void ChBrowserWnd::LoadURL( const string& strURL,  chuint32 flOptions /* = 0 */ )
{

	GetHTTPConn()->AbortRequests(); 
	m_strPendingRequest = strURL;
	ChHtmlWnd::LoadURL( strURL );
	
}


void ChBrowserWnd::GoForward( )
{
	if ( m_listPos && m_listPos != m_urlList.GetTailPosition())
	{
		ChPosition	m_currPos = m_listPos;
		m_urlList.GetNext( m_currPos );
		m_listPos = m_currPos;
		
		if ( m_currPos )
		{	
			ChHTMLHistory *pHistory = (ChHTMLHistory*)m_urlList.GetNext( m_currPos );
			string strDocURL, strFile, strMimeType;
			pHistory->GetHistory( strDocURL, strFile, strMimeType );	
			AbortRequests();
			DisplayFile(  strFile, strMimeType, ChHtmlWnd::fileReplace, strDocURL );

			UpdateFrameOnLoad( strDocURL, strFile );
		}
	}
	if ( m_listPos == 0 )
	{
		m_listPos = m_urlList.GetTailPosition();
	}
}
void ChBrowserWnd::GoBackward( )
{
	if ( m_listPos && m_listPos != m_urlList.GetHeadPosition() )
	{
		ChPosition	m_currPos = m_listPos;
		m_urlList.GetPrev( m_currPos );
		m_listPos = m_currPos;

		if ( m_currPos )
		{	
			ChHTMLHistory *pHistory = (ChHTMLHistory*)m_urlList.GetPrev( m_currPos );
			string strDocURL, strFile, strMimeType;
			pHistory->GetHistory( strDocURL, strFile, strMimeType );	
			AbortRequests();
			DisplayFile(  strFile, strMimeType, ChHtmlWnd::fileReplace, strDocURL );

			UpdateFrameOnLoad( strDocURL, strFile );
		}
	}
	if ( m_listPos == 0 )
	{
		m_listPos = m_urlList.GetHeadPosition();
	}
}


void ChBrowserWnd::UpdateFrameOnLoad( const string& strURL, const string& strFile )
{
	string strMessage;

	if ( GetDocTitle().IsEmpty() )
	{
		if(!strURL.IsEmpty() && strURL.Left(5).CompareNoCase("file:"))
		{
			strMessage = string(CH_HTML_PRODUCT_NAME) + " - " + strURL;
		}
		else
		{
			char name[_MAX_FNAME], ext[_MAX_EXT ];

			_splitpath( LPCTSTR(strFile), 0, 0, name, ext);
			strMessage = string(CH_HTML_PRODUCT_NAME) + " - " + name + ext;
		}
	}
	else
	{
		strMessage = string(CH_HTML_PRODUCT_NAME) + " - " + GetDocTitle();
	}

	ChMainFrame* pFrame = (ChMainFrame*)GetParentFrame(); 
	pFrame->SetWindowText( strMessage ); 
	pFrame->UpdateLocationBar( strURL );
}


#ifndef CH_UNIX
BEGIN_MESSAGE_MAP( ChBrowserWnd, ChHtmlWnd )
	//{{AFX_MSG_MAP(ChBrowserWnd)
	ON_WM_MOUSEACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/*----------------------------------------------------------------------------
	ChBrowserWnd message handlers
----------------------------------------------------------------------------*/


int ChBrowserWnd::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	// This is here to prevent a crash in ChScrollWnd which calls the
	// frame window through ChCore. We don't have a core now.
	return CWnd ::OnMouseActivate(pDesktopWnd, nHitTest, message);
}



#endif // !defined( CH_UNIX )




