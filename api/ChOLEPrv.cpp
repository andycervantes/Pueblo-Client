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

	This file contains the implementation of.

----------------------------------------------------------------------------*/

#include "headers.h"

#include <stdlib.h>
#include <string.h>
#include <iostream.h>
#include <fstream.h>


#include <ChConst.h>
#include <ChUtil.h>
#include <ChReg.h>

#if defined( CH_NOTIFY_MODULE )
#include <ChCore.h>
#include <ChMsgTyp.h>
#endif


#include <ChOLENet.h>	
#include "ChOLEPrv.h"

#if defined( CH_VRML_VIEWER )
#include "ChGrType.h"
#endif


#define CH_USE_SOCKET




//	Static initialization.
ChVisitedList				ChOLEConnInfo::m_visitedList;
ChOLEConnActiveList			ChOLEConnInfo::m_connActiveList;
ChOLEConnWaitList			ChOLEConnInfo::m_connWaitList;
ChOLETempFileList			ChOLEConnInfo::m_tempFileList;
CNetscapeNetwork* 			ChOLEConnInfo::m_pOLEConn;
string						ChOLEConnInfo::m_strCacheDir;
ChHTTPSocketConn*			ChOLEConnInfo::m_phttpSocketConn = 0;
/////////////////////////////////////////////////////////////////////////////
// ChOLEConnInfo implementation 


void ChOLEConnInfo::InitOLEConnInfo()
{


	// first, initialize OLE
	SCODE sc = ::OleInitialize(NULL);
	if (FAILED(sc))
	{
		// warn about non-NULL success codes
		TRACE1("Warning: OleInitialize returned scode = %d.\n",	sc);
	}

	#if defined( CH_VRML_VIEWER )
	ChRegistry reg( CH_COMPANY_NAME, CH_VRML_PRODUCT_NAME, CH_CACHE_GROUP );
	#else
	ChRegistry	reg( CH_CACHE_GROUP );
	#endif

	string		strDir;
											/* Get the local cache directory.
												Start with the app path. */
	ChUtil::GetAppDirectory( strDir );

	#if defined( CH_MSW )
	{
		strDir += CACHE_DIR;

		reg.Read( CH_CACHE_DIR, m_strCacheDir, strDir );
	}
	#elif defined( CH_UNIX )
	{
		strDir = ChUtil::GetPuebloDir() + "/" + CACHE_DIR;
		m_strCacheDir = strDir;
	}
	#else	// defined( CH_MSW )
	{
		#error "ChHTTPOLE::InitOLEConn : OS not defined"
	}
	#endif	// defined( CH_MSW )

}

class ZapVisitedConn : public ChVisitor2<string, pChVisitedInfo>  
{
	public:
	 	bool Visit( const string& key,  const pChVisitedInfo& pVisited )
		{
			delete pVisited;
			return true;
		}
};


void ChOLEConnInfo::TermOLEConnInfo()
{
	if ( m_pOLEConn )
	{
		delete m_pOLEConn;
	}

	::OleUninitialize();

	if ( m_phttpSocketConn )
	{
		m_phttpSocketConn->AbortRequests();
		// to cache management
		ChHTTPSocketConn::EnforceCacheLimit();       
		delete m_phttpSocketConn;
	}

	ChPosition posConn = GetConnectionList().GetHeadPosition();

	while (0 != posConn)
	{
		ChOLEConnInfo *pConn = GetConnectionList().GetNext( posConn );
		GetConnectionList().RemoveHead();
		delete pConn;

		posConn = ChOLEConnInfo::GetConnectionList().GetHeadPosition();
	}


	// zap all visited entries
	//ZapVisitedConn		zapVisited;
	//GetVisitedList().Infix( zapVisited );

	posConn = GetWaitList().GetHeadPosition();

	while (0 != posConn)
	{
		ChOLEConnInfo *pConn = GetWaitList().GetHead();
		GetWaitList().RemoveHead();
		delete pConn;

		posConn = GetWaitList().GetHeadPosition();
	}

	// remove all the temp files created
	posConn = GetTempFileList().GetHeadPosition();

	while (0 != posConn)
	{
		string *pstrFile = GetTempFileList().GetHead();
		GetTempFileList().RemoveHead();
		::DeleteFile( *pstrFile );
		delete pstrFile;

		posConn = GetTempFileList().GetHeadPosition();
	}

}


bool ChOLEConnInfo::ProcessConnectionRequest( ) 
{	   
	bool boolSuccess = true;


	if ( !ChOLEConnInfo::GetHTTPOLE() )
	{

		// We use our own HTTP client 
		::EnterCriticalSection( &ChHTTPOLE::m_oleSync );

		ChOLEConnInfo *pConn = GetWaitList().GetHead();
		GetWaitList().RemoveHead();

		::LeaveCriticalSection( &ChHTTPOLE::m_oleSync );

		if ( ChOLEConnInfo::m_phttpSocketConn )
		{
			// we will do our on notification
			m_phttpSocketConn->GetURL( pConn->GetURL(), 
						pConn->GetUserData(), 0, pConn->GetOptions());
		}

		delete pConn;
		return true;
	}

	::EnterCriticalSection( &ChHTTPOLE::m_oleSync );

	TRACE2( "ProcessConnectionRequest : Num pending %d, Num in wait %d\n", GetConnectionList().GetCount(), 
					GetWaitList().GetCount( ) );

	while( GetConnectionList().GetCount() == 0 && GetWaitList().GetCount( ) )
	{  // start the next request
	
		ChOLEConnInfo *pConn = GetWaitList().GetHead();
		GetWaitList().RemoveHead();

		GetConnectionList().AddTail( pConn );

		::LeaveCriticalSection( &ChHTTPOLE::m_oleSync );


		if ( m_pOLEConn->Open( pConn->GetURL(), 0, NULL, 0, NULL ) )
		{	// sucessfully initiated a request, start a thread and read the data in the thread

		}
		else
		{  // connection failed

			long lError =  m_pOLEConn->GetStatus();

			m_pOLEConn->Close();

			::EnterCriticalSection( &ChHTTPOLE::m_oleSync );

			if ( lError == 0x200 )
			{
			
			
				GetWaitList().AddTail( pConn );
				GetConnectionList().RemoveTail();

			}  
			else
			{
				pConn->DoErrorNotification( lError );
				delete pConn;
				GetConnectionList().RemoveTail();
				boolSuccess = false;
			}

			::LeaveCriticalSection( &ChHTTPOLE::m_oleSync );
		}

		::EnterCriticalSection( &ChHTTPOLE::m_oleSync );
	
	}
	::LeaveCriticalSection( &ChHTTPOLE::m_oleSync );
	
	return boolSuccess;
}

/////////////////////////////////////////////////////////////////////////////
// ChOLEConnInfo 	Implementation



void ChOLEConnInfo::DoLoadCompeteNotification( string& strFile, string& strURL, 
									string& strMimeType )
{
	// OLE notifications come from a separate thread, got to protect my data

	::EnterCriticalSection( &ChHTTPOLE::m_oleSync );

	ChPosition posConn = GetWaitList().GetHeadPosition();

	while (0 != posConn)
	{										/* Make sure that the new request
												is not currently being
												processed */
		ChPosition	prevPos = posConn;
		ChOLEConnInfo *pConn = GetWaitList().GetNext( posConn );

		if (pConn->GetURL() == strURL )
		{
			TRACE1( "Coming out of HTTP_WAIT %s\n",
						(const char *)GetURL() );

			if ( pConn->GetOptions() &	CH_OPT_NOTIFY_ON_COMPLETE )
			{
				#if defined( CH_NOTIFY_MODULE )
				if ( GetHTTPConn()->GetNotificationWnd() == 0 )
				{
					ChLoadCompleteMsg*	pMsg = new ChLoadCompleteMsg( strURL, strFile, strMimeType, pConn->GetUserData() );
					#if defined( CH_MSW ) && defined( CH_ARCH_32 )
					{
						ChCore::GetCore()->GetMsgQueue()->Add( GetHTTPConn()->GetModuleID(),
																pMsg );
					}
					#else
					ChCore::GetCore()->DispatchMsg( GetHTTPConn()->GetModuleID(), *pMsg );
					delete pMsg;
					#endif	// defined( CH_MSW )
				}
				else
				#else
				if ( GetHTTPConn()->GetNotificationWnd() )
				#endif
				{
					#if defined( CH_MSW )
					ChHTTPNotification* pInfo = new ChHTTPNotification( strURL, strFile, strMimeType, pConn->GetUserData(), 0); 
					ASSERT( pInfo );

					if ( !::PostMessage( pConn->GetHTTPConn()->GetNotificationWnd(), WM_CHACO_HTTP_MSG, 0, (LPARAM)pInfo ) )
					{
					}
					#endif
				}
			}
			// remove the connection we are done with this
			GetWaitList().Remove( prevPos );
			delete pConn;

			posConn = GetWaitList().GetHeadPosition();
		}
	}
	

	TRACE( "LoadComplete : Num pending %d\n", GetWaitList().GetCount() );
	  
	if ( GetOptions() &	CH_OPT_NOTIFY_ON_COMPLETE )
	{
		#if defined( CH_NOTIFY_MODULE )
		if ( GetHTTPConn()->GetNotificationWnd() == 0 )
		{
			// Do load complete message
			ChLoadCompleteMsg*	pMsg = new ChLoadCompleteMsg( strURL, strFile, strMimeType, GetUserData() );

			#if defined( CH_MSW ) && defined( CH_ARCH_32 )
			{
				ChCore::GetCore()->GetMsgQueue()->Add( GetHTTPConn()->GetModuleID(),
														pMsg );
			}
			#else
			ChCore::GetCore()->DispatchMsg( GetModuleID(), *pMsg );
			delete pMsg;
			#endif	// defined( CH_MSW )
		}
		else
		#else
		if ( GetHTTPConn()->GetNotificationWnd() )
		#endif
		{
			#if defined( CH_MSW )
			ChHTTPNotification* pInfo = new ChHTTPNotification( strURL, strFile, strMimeType, GetUserData(), 0 ); 
			ASSERT( pInfo );


			//::SendNotifyMessage( GetHTTPConn()->GetNotificationWnd(), WM_CHACO_HTTP_MSG, 0, (LPARAM)pInfo );	
			::PostMessage( GetHTTPConn()->GetNotificationWnd(), WM_CHACO_HTTP_MSG, 0, (LPARAM)pInfo );	
			#endif
		}
	}

	::LeaveCriticalSection( &ChHTTPOLE::m_oleSync );


}

void ChOLEConnInfo::DoErrorNotification(  int iError )
{

	// OLE notifications come from a separate thread, got to protect my data
	::EnterCriticalSection( &ChHTTPOLE::m_oleSync );

	ChPosition posConn = GetWaitList().GetHeadPosition();

	while (0 != posConn)
	{										/* Make sure that the new request
												is not currently being
												processed */
		ChPosition	prevPos = posConn;
		ChOLEConnInfo *pConn = GetWaitList().GetNext( posConn );

		if ( pConn->IsAborted() || pConn->GetURL() == GetURL() )
		{
			TRACE1( "Coming out of HTTP_WAIT %s\n",
						(const char *)GetURL() );

			if ( pConn->GetOptions() &	CH_OPT_NOTIFY_ON_COMPLETE )
			{
				#if defined( CH_NOTIFY_MODULE )
				if ( pConn->GetHTTPConn()->GetNotificationWnd() == 0 )
				{
					ChLoadErrorMsg*	pMsg = new ChLoadErrorMsg( "", 0, pConn->GetURL(), iError,
											pConn->GetUserData() );
					#if defined( CH_MSW ) && defined( CH_ARCH_32 )
					{
						ChCore::GetCore()->GetMsgQueue()->Add( GetHTTPConn()->GetModuleID(),
																pMsg );
					}
					#else
					ChCore::GetCore()->DispatchMsg( GetModuleID(), *pMsg );
					delete pMsg;
					#endif	// defined( CH_MSW )
				}
				else
				#else
				if ( pConn->GetHTTPConn()->GetNotificationWnd() )
				#endif
				{
					#if defined( CH_MSW )
					ChHTTPNotification* pInfo = new ChHTTPNotification( iError, pConn->GetURL(), 
																pConn->GetUserData()); 
					ASSERT( pInfo );

					::PostMessage( GetHTTPConn()->GetNotificationWnd(), WM_CHACO_HTTP_MSG, 0, (LPARAM)pInfo );	
					#endif
				}

			}
			// remove the connection we are done with this
			GetWaitList().Remove( prevPos );
			delete pConn;

			posConn = GetWaitList().GetHeadPosition();
		}
	}


	if ( GetOptions() &	CH_OPT_NOTIFY_ON_COMPLETE )
	{
		#if defined( CH_NOTIFY_MODULE )
		if ( GetHTTPConn()->GetNotificationWnd() == 0 )
		{

			ChLoadErrorMsg*	pMsg = new ChLoadErrorMsg( "", 0, GetURL(), iError,
										GetUserData() );
			#if defined( CH_MSW ) && defined( CH_ARCH_32 )
			{
				ChCore::GetCore()->GetMsgQueue()->Add( GetHTTPConn()->GetModuleID(),
														pMsg );
			}
			#else
			ChCore::GetCore()->DispatchMsg( GetHTTPConn()->GetModuleID(), *pMsg );
			delete pMsg;
			#endif	// defined( CH_MSW )
		}
		else  
		#else
		if ( GetHTTPConn()->GetNotificationWnd() )
		#endif
		{
			#if defined( CH_MSW )
			ChHTTPNotification* pInfo = new ChHTTPNotification( iError, GetURL(), 
														GetUserData()); 
			ASSERT( pInfo );

			::PostMessage( GetHTTPConn()->GetNotificationWnd(), WM_CHACO_HTTP_MSG, 0, (LPARAM)pInfo );	
			#endif
		}
	}

	::LeaveCriticalSection( &ChHTTPOLE::m_oleSync );
}



/*----------------------------------------------------------------------------

	FUNCTION	||	HTTPReadThread

------------------------------------------------------------------------------

	Thread for processing data from the socket

----------------------------------------------------------------------------*/

UINT OLEReadThread( LPVOID pData )
{
	ChHTTPOLE*		pHTTPOLE = (ChHTTPOLE*)pData;
	bool			boolTryOLE = true;

	TRACE( "Start OLE thread\n" );

  	// initialize the OLE Conn object
	ChOLEConnInfo::InitOLEConnInfo();

	// wait till we get an event to process
	DWORD dwStatus;

	while (WAIT_FAILED !=
			(dwStatus =
				::WaitForMultipleObjects( ChHTTPOLE::GetTotalEvents(),
											ChHTTPOLE::GetEvents(), false,
							   				INFINITE )))
	{
		chint32				lEvent = dwStatus - WAIT_OBJECT_0;

 		if (ChHTTPOLE::GetEvents()[lEvent] == ChHTTPOLE::GetEndThread())
		{	// Mommy wants me to quit
											// Delete the current thread
			TRACE( "End request thread : Terminate on event\n" );
			// Cleanup all	

			ChOLEConnInfo::TermOLEConnInfo();
			AfxEndThread( 0 );
			return ( 0 );
		}

		if ( boolTryOLE )
		{
			// Create the ole object
			//	Create a new OLE Network object to handle netowrk loads.
			ChOLEConnInfo::m_pOLEConn = new CNetscapeNetwork;

			COleException oleException;
			if ( !ChOLEConnInfo::GetHTTPOLE()->CreateDispatch("Netscape.Network.1", &oleException ) )
			{  // failed, we cannot use this object
				delete ChOLEConnInfo::m_pOLEConn;
				ChOLEConnInfo::m_pOLEConn = 0;
				boolTryOLE = false;
			}
		}

		if ( !ChOLEConnInfo::GetHTTPOLE() && !ChOLEConnInfo::m_phttpSocketConn )
		{  // unable to create a OLE object lets create a HTTP object

			ChOLEConnInfo::m_phttpSocketConn = new ChHTTPSocketConn( 
									pHTTPOLE->GetModuleID(), 0, pHTTPOLE->GetMsgMask() );
		
			ChOLEConnInfo::m_phttpSocketConn->SetNotificationWnd( 
								pHTTPOLE->GetNotificationWnd(), pHTTPOLE->GetMsgMask() );	
			// Copy the stream handlers of DDEConn
			pHTTPOLE->SetStreamHandler( ChOLEConnInfo::m_phttpSocketConn );	

		}


		::EnterCriticalSection( &ChHTTPOLE::m_oleSync );
	
		while (	ChOLEConnInfo::GetWaitList().GetCount() )
		{ 	// Loop till we have requests to be processed

			::LeaveCriticalSection( &ChHTTPOLE::m_oleSync );

			if ( ChOLEConnInfo::ProcessConnectionRequest() 
								&& ChOLEConnInfo::GetHTTPOLE() )
			{  	// sucessful request, get the data


				ChOLEConnInfo * pConn = ChOLEConnInfo::GetConnectionList().GetHead();

				ASSERT( pConn );

				char   strPath[MAX_PATH];

				GetTempFileName( ChOLEConnInfo::GetCacheDir(), "Ch", 0, strPath );

				fstream *pFile = ::new fstream( strPath, ios::out | ios::binary, filebuf::sh_none );

				long lLength = ChOLEConnInfo::GetHTTPOLE()->GetContentLength();

				if ( lLength == 0 || lLength > 4094 )
				{
					lLength = 4094;
				}
				BSTR pBuffer = SysAllocStringLen(NULL, lLength );

				// Read data from the server
				short iStat;
				while( !pConn->IsAborted() && 
						(iStat = ChOLEConnInfo::GetHTTPOLE()->Read( &pBuffer, (short)lLength )) != -1 )
				{
					if ( iStat > 0 )
					{  // write to a local file
						// do progress here
						pFile->write( pBuffer, iStat );
					}
					else
					{
						Sleep( 500 );
					}
				}

				pFile->close();

				::delete pFile;

				SysFreeString(pBuffer);

				// add the file to our temp file list 

				// Notify complete
				long lError =  ChOLEConnInfo::GetHTTPOLE()->GetStatus();

				string strMimeType( ChOLEConnInfo::GetHTTPOLE()->GetContentType() );

				ChOLEConnInfo::GetHTTPOLE()->Close();

				if ( pConn->IsAborted() )
				{  // user aborted
					lError = CH_HTTP_ERROR_USER_ABORT;
				}

				if ( lError )
				{
					pConn->DoErrorNotification( lError );

					::DeleteFile( strPath );
				}
				else
				{
					string* pstrFile =  new string( strPath );

					pConn->DoLoadCompeteNotification( *pstrFile, pConn->GetURL(), strMimeType );

					// Add this to our visted list

					::EnterCriticalSection( &ChHTTPOLE::m_oleSync );

					ChVisitedInfo *pVisted = new ChVisitedInfo( *pstrFile, strMimeType );
					ASSERT( pVisted );
					ChOLEConnInfo::GetVisitedList().Insert( pConn->GetURL(), pVisted );

					::LeaveCriticalSection( &ChHTTPOLE::m_oleSync );

					ChOLEConnInfo::GetTempFileList().AddTail( pstrFile );
				}
			}
			// about to check the wait list 
			::EnterCriticalSection( &ChHTTPOLE::m_oleSync );
		}

		// Come out of critical section and go back to wait state
		::LeaveCriticalSection( &ChHTTPOLE::m_oleSync );

		// Free the OLE object
		if ( ChOLEConnInfo::GetHTTPOLE() )
		{  // done, free the object
			delete ChOLEConnInfo::m_pOLEConn;
			ChOLEConnInfo::m_pOLEConn = 0;
		}


	}
	// Unexpected, cleanup anyway
	ChOLEConnInfo::TermOLEConnInfo();
	AfxEndThread( 1 );
	return 1;
}
