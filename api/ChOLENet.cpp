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

	This file consists of the Chaco OLE interface to WEB clients.

----------------------------------------------------------------------------*/

#include "headers.h"

#include <stdlib.h>
#include <string.h>

#include <ChUtil.h>

#include <ChUrlMap.h>
#include <ChOLENet.h>	
#include "ChOLEPrv.h"



#if defined( CH_VRML_VIEWER )
#include "ChGrType.h"
#endif





//#define OLE_ERR_MSG		"Unable to establish converstion with a web browser. Please start the browser application and retry the operation."


// Static initialization : ChHTTPOLE
unsigned	long			ChHTTPOLE::m_numObjects = 0;
HANDLE						ChHTTPOLE::m_hOLENetEvent[2];
CRITICAL_SECTION			ChHTTPOLE::m_oleSync;

/////////////////////////////////////////////////////////////////////////////
// ChHTTPOLE implementation 


ChHTTPOLE::ChHTTPOLE( ChModuleID idModule, 
						int iMaxConn /* = 5 */,
						chuint32 flMsgMask /* = msgAll */ )	
							:  ChHTTPConn( idModule, iMaxConn, flMsgMask  ),
							   m_boolThreaded( false )

{
	InitOLEConn();
}

ChHTTPOLE::ChHTTPOLE( HWND hWnd, 
						int iMaxConn /* = 5 */,
						chuint32  flMsgMask /* = msgAll */ )	
							:  ChHTTPConn( hWnd, iMaxConn, flMsgMask  ),
							   m_boolThreaded( false )
{
	InitOLEConn();
}


void ChHTTPOLE::InitOLEConn()
{

	m_boolThreaded = !!(ChUtil::GetSystemProperties() & CH_PROP_MULTITHREADED );

	if ( 0 == m_numObjects )
	{
		 
		if ( m_boolThreaded )
		{
			::InitializeCriticalSection( &m_oleSync );
			m_hOLENetEvent[eventRequest] = CreateEvent( 0, false, false, 0 );
			ASSERT( m_hOLENetEvent[eventRequest] );
			m_hOLENetEvent[eventEndThread] = CreateEvent( 0, false, false, 0 );
			ASSERT( m_hOLENetEvent[eventEndThread] );

			AfxBeginThread( OLEReadThread, (ptr)this );

		}

	}
	
	// Incerement the usage count
	m_numObjects++;
}



ChHTTPOLE::~ChHTTPOLE( )
{

	m_numObjects--;
	if ( m_numObjects == 0)
	{
	 	ShutDownHTTP();
	} 
}

void ChHTTPOLE::ShutDownHTTP()
{
	// Decerement the usage count

	if ( m_numObjects > 0 )
	{ 
		m_numObjects = 0;
	}

	if ( 0 == m_numObjects )
	{
	
		// Kill the OLE Network thread
		::SetEvent( GetEndThread() );


		::DeleteCriticalSection( &m_oleSync );

		for ( int i = 0; i < GetTotalEvents(); i++ )
		{
			CloseHandle( GetEvents()[i] );
		}

	}
}


int ChHTTPOLE::NumActive()		
{
	::EnterCriticalSection( &m_oleSync );

	int iConnections = ChOLEConnInfo::GetConnectionList().GetCount() +
	 		ChOLEConnInfo::GetWaitList().GetCount();

	::LeaveCriticalSection( &m_oleSync );

	if ( ChOLEConnInfo::GetSocketConn()  )
	{	// our connections
		iConnections += ChOLEConnInfo::GetSocketConn()->GetTotalConnections();	
	}

	 return iConnections;
}

	

void ChHTTPOLE::AbortRequests( bool boolAbortPrefetch /*= false */,
						ChHTTPStreamManager* pStreamMgr /*= 0 */)
{

	::EnterCriticalSection( &m_oleSync );

	if ( ChOLEConnInfo::GetConnectionList().GetCount() )
	{

		ChPosition posConn = ChOLEConnInfo::GetConnectionList().GetHeadPosition();
		
		while (0 != posConn)
		{
			ChOLEConnInfo *pConn = ChOLEConnInfo::GetConnectionList().GetNext( posConn );
			pConn->Abort();
		}
	}


	ChPosition posConn = ChOLEConnInfo::GetWaitList().GetHeadPosition();

	while (0 != posConn)
	{
		ChOLEConnInfo *pConn = ChOLEConnInfo::GetWaitList().GetNext( posConn );
		pConn->Abort();
	}

	posConn = ChOLEConnInfo::GetWaitList().GetHeadPosition();

	
	if ( posConn )
	{ // remove all the requests
		ChPosition prevPos = posConn;

		ChOLEConnInfo *pConn = ChOLEConnInfo::GetWaitList().GetNext( posConn );	 

		ChOLEConnInfo::GetWaitList().Remove( prevPos );

		pConn->DoErrorNotification( CH_HTTP_ERROR_USER_ABORT );

		delete pConn;
	}


	::LeaveCriticalSection( &m_oleSync );

	// check if we have our own http requests
	if ( ChOLEConnInfo::GetSocketConn()  )
	{
		ChOLEConnInfo::GetSocketConn()->AbortRequests();	
	}

}	 

bool ChHTTPOLE::ViewFile( const string strURL, const string& strFile ) 
{	
	string strEmpty;

	if (  1 )
	{  // connection failed, try shell execute
		char strBuffer[MAX_PATH];
		::GetCurrentDirectory( MAX_PATH, strBuffer );
		ShellExecute( AfxGetMainWnd()->GetSafeHwnd(), 
					"open", strFile, NULL, strBuffer, 0);
	}

	return true;
}


bool ChHTTPOLE::GetURL( const string& strURL, chparam userData,
						const char* pstrDefURL /* = 0 */, 
						chuint32 flOptions /*= CH_OPT_NOTIFY_ON_COMPLETE */,
						ChHTTPStreamManager* pStreamMgr /*= 0 */)
{
	// resolve the URL
	string strRequest;

	ChURLParts	urlParts;

	if ( urlParts.GetURLParts( strURL, pstrDefURL ) )
	{
		if(  urlParts.GetScheme() == ChURLParts::typeFile )
		{
			// Map URL to localfile
			strRequest = urlParts.GetURL();		 
			string	strFile, strMimeType;
			ChURLParts::MapURLToHostFile( strRequest, strFile );
			ChHTTPConn::GetMimeTypeByFileExtn( strFile, strMimeType  );


		 	ChOLEConnInfo	*pNewConn = new ChOLEConnInfo( this, strRequest, flOptions, userData );
			ASSERT( pNewConn );
		
			pNewConn->DoLoadCompeteNotification( strFile, strRequest, strMimeType ); 

			delete pNewConn;

			return true;

		}
		
	}
	
	strRequest = urlParts.GetURL();		 
	// check if we have a file scheme for GetURL, if we do
	// then resolve path and do a load complete


	if ( strRequest.IsEmpty() )
	{
		TRACE( "Error : URL is empty \n" );
	 	ChOLEConnInfo	*pNewConn = new ChOLEConnInfo( this, strRequest, flOptions, userData );
		ASSERT( pNewConn );
		pNewConn->DoErrorNotification( CH_HTTP_ERROR_BAD_URL );
		delete pNewConn;
		return FALSE;
	}


	TRACE1( "Getting URL %s\n", LPCSTR( strRequest ) );
	// Check if we have already visted the location
	ChVisitedInfo ** ppVisted = ChOLEConnInfo::GetVisitedList().Find( strRequest );

	if ( ppVisted && *ppVisted )
	{  // return what we have

	 	ChOLEConnInfo	*pNewConn = new ChOLEConnInfo( this, strRequest, flOptions, userData );
		ASSERT( pNewConn );
		
		pNewConn->DoLoadCompeteNotification( (*ppVisted)->GetLocalFileName(), 
								strRequest, (*ppVisted)->GetMimeType() ); 

		delete pNewConn;

		return true;
	}

	// Find if this is a duplicate request, if it is put
	// it in our wait list, else add it to our conn list
 	ChOLEConnInfo	*pNewConn = new ChOLEConnInfo( this, strRequest, flOptions, userData );
	ASSERT( pNewConn );

	if ( IsThreaded() )
	{
		::EnterCriticalSection( &m_oleSync );

		ChOLEConnInfo::GetWaitList().AddTail( pNewConn );

		::LeaveCriticalSection( &m_oleSync );

		::SetEvent( ChHTTPOLE::GetRequestEvent() );
	}
	else
	{
		ASSERT( false );
		//ProcessNonThreadedRequest();
	}
	
	return true;
}		 




void ChHTTPOLE::ViewDocFile( CString& strFile, CString& strURL, CString& strMimeType )
{

	
	ChOLEConnInfo	*pConn = new ChOLEConnInfo( this, strURL, 
									CH_OPT_NOTIFY_ON_COMPLETE, 0 );
	ASSERT( pConn );

	pConn->DoLoadCompeteNotification( strFile, strURL, strMimeType ); 

	delete pConn;
	// Add this to our visted list

	::EnterCriticalSection( &m_oleSync );

	ChVisitedInfo *pVisted = new ChVisitedInfo( strFile, strMimeType );
	ASSERT( pVisted );
	ChOLEConnInfo::GetVisitedList().Insert( strURL, pVisted );

	::LeaveCriticalSection( &m_oleSync );

	return;
}

