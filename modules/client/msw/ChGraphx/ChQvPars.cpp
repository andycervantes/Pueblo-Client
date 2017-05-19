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

	Implementation for the ChGraphicMaze class, which is used to display VRML.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChQvPars.cpp,v 1.6 1996/04/21 07:05:05 pritham Exp $
#include "grheader.h"
				  

#include "ChMaze.h"
#include "ChQvPars.h"


bool ChMazeWnd::AddParseInfo( ChParseInfo* pParseInfo )
{
	if ( GetRenderContext()->IsThreaded() )
	{
		::EnterCriticalSection( &m_syncParser );
	}

	m_parseThreadList.AddTail( pParseInfo );  

	if ( GetRenderContext()->IsThreaded() )
	{
		::LeaveCriticalSection( &m_syncParser ); 
	}
	return true;
}

bool ChMazeWnd::RemoveParseInfo( ChParseInfo* pParseInfo )
{
	if ( GetRenderContext()->IsThreaded() )
	{
		::EnterCriticalSection( &m_syncParser );
	}

	ChPosition pos = m_parseThreadList.GetHeadPosition();
	bool	boolDone = false;

	while ( 0 != pos  && !boolDone )
	{
		ChPosition posPrev = pos;
		ChParseInfo* pInfo = m_parseThreadList.GetNext( pos );

		if ( pInfo == pParseInfo )
		{	// cleanup the node
			m_parseThreadList.Remove( posPrev );
			boolDone = true;
		}
	}

	if ( GetRenderContext()->IsThreaded() )
	{
		::LeaveCriticalSection( &m_syncParser ); 
	}

	return boolDone;
}

bool ChMazeWnd::AbortParsing(  )
{
	if (  GetRenderContext()->IsThreaded() && 
			m_parseThreadList.GetCount() )
	{
		::EnterCriticalSection( &m_syncParser );

		// Abort all parse threads
		ChPosition pos = m_parseThreadList.GetHeadPosition();

		while (0 != pos )
		{
			ChParseInfo* pInfo = m_parseThreadList.GetNext( pos );

			pInfo->Abort();
		}

		::LeaveCriticalSection( &m_syncParser ); 

		// Wait till all the threads terminate
		while( m_parseThreadList.GetCount()  )
		{
			DWORD dwStatus = ::WaitForSingleObject( m_hParseThreadEvent, INFINITE );

			ASSERT( dwStatus == WAIT_OBJECT_0 ); 

			ChPosition pos = m_parseThreadList.GetHeadPosition();

			while (0 != pos )
			{
				ChPosition posPrev = pos;
				ChParseInfo* pInfo = m_parseThreadList.GetNext( pos );

				if ( pInfo->GetState() == ChParseInfo::stateAbort )
				{	// cleanup the node
				  	delete pInfo;
					m_parseThreadList.Remove( posPrev );
					pos = m_parseThreadList.GetHeadPosition();
				}
				else if ( pInfo->GetState() == ChParseInfo::stateDone )
				{	// This will be deleted by the message handler
					m_parseThreadList.Remove( posPrev );
					pos = m_parseThreadList.GetHeadPosition();
				}
			}

		}
	}

	return true;
}





////////////////////////////////////////////////////////////////////////////////////////////
/////////////
////////////
//////////////////////////////////////////////////////////////////////////////////

UINT ParseThread( LPVOID pData );


ChParseInfo::ChParseInfo( ChMazeWnd* pWnd, const string strURL, const string& strFileName ) :
				m_boolCancel( false ), 
				m_boolParseResult( false ),
				m_pRoot( 0 ), m_pWnd( pWnd ), m_strFile( strFileName ),
				m_strURL( strURL ), m_iType( typeUnknown ), m_iState( stateInit ),
				m_pUserData2(0)
{

}

ChParseInfo::~ChParseInfo( )
{
}

bool ChParseInfo::ParseVrmlFile( int iType )
{
	
	m_iType = iType;

	// Open the file
	HANDLE				hFile;
	hFile = ::CreateFile(
					    m_strFile,		// address of name of the file 
					    GENERIC_READ,	// access (read-write) mode 
					    FILE_SHARE_READ,// share mode 
					    NULL,			// address of security descriptor 
					    OPEN_EXISTING,	// how to create 
					    0,				// file attributes 
					    NULL			// handle of file with attributes to copy  
				   );
				   
	if ( hFile != INVALID_HANDLE_VALUE )
	{	// Do the init for this file
		QvDB::init();

		// Set the stream handle
		m_in.setFilePointer( hFile );


		// Starting to parse
		SetState( stateInQVParse );

		// If we can start a thread do so only if the file is > minFileSize, otherwise
		// parse the file in the current thread context
		// Inline is already in its own thread.
		if ( m_pWnd->GetRenderContext()->IsThreaded()  && GetType() == ChParseInfo::typeScene
						&& ::GetFileSize( hFile, 0 ) > minFileSize )
		{	 
			// Set NotificationInfo for posting error messages
			m_in.SetAsyncNotificationInfo( m_pWnd->GetSafeHwnd() );

			TRACE( "Starting a thread to parse file %s\n", LPCSTR(m_strFile) );
			CWinThread *pParseThread = ::AfxBeginThread( ParseThread, (void*)this ); 
			ASSERT( pParseThread );
		}
		else
		{
			SetParseResult( (QvDB::read( GetStream(), 
									GetQVNode()) 
									&& GetQVNode() != 0) );

			m_pWnd->PostMessage( WM_VRML_PARSE_DONE, 0, (LPARAM)this );
		}

		return true;
	}	
	
	return false;			   

}



UINT ParseThread( LPVOID pData )
{
	ChParseInfo	*pParse = (ChParseInfo*)pData;
	HWND 		 hWnd = pParse->GetWnd()->GetSafeHwnd();
	HANDLE		 hEndEvent =  pParse->GetWnd()->GetEndParseEvent();

	TRACE( "Start parse thread.. \n" );
 
 // parse and set the result
	pParse->SetParseResult( (QvDB::read( pParse->GetStream(), pParse->GetQVNode()) 
					&& pParse->GetQVNode() != 0) );

	if ( pParse->IsCanceled() )
	{
		pParse->SetState( ChParseInfo::stateAbort );
	}
	else
	{
		pParse->SetState( ChParseInfo::stateDone );	

		if ( ::IsWindow( hWnd )	)
		{
			pParse->GetWnd()->PostMessage( WM_VRML_PARSE_DONE, 
						0, (LPARAM)pParse );
		}
		else
		{
			pParse->SetState( ChParseInfo::stateAbort );
		}
	}

	// if any thread is blocking for this thread to terminate, this should wake up the
	// thread
	TRACE( "End parse thread\n" );

	::SetEvent( hEndEvent );


	AfxEndThread( 0 );

	return 0;
}
