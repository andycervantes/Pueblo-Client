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

	This file consists of the implementation of the PlugIn manager class.

----------------------------------------------------------------------------*/

#include "headers.h"
#include <ChUtil.h>

#include "ChHtmlView.h"
#include <ChHTTP.h>
#include "ChPlgInMgr.h"


LONG CALLBACK EXPORT PluginProc( HWND hwnd, UINT  uMsg,
												WPARAM wParam, LPARAM lParam );


string 				ChPlugInMgr::m_strPuebloPluginDir;
string 				ChPlugInMgr::m_strNetscapePluginDir;
string 				ChPlugInMgr::m_strPluginWndClass;
ChPlugInDllLst		ChPlugInMgr::m_plgInDllList;


ChPlugInMgr::ChPlugInMgr()
{
	if ( m_strPuebloPluginDir.IsEmpty() || m_strNetscapePluginDir.IsEmpty() )
	{ // First time initialize all the directory info
		Initialize();
	}
}

ChPlugInMgr::~ChPlugInMgr()
{

}

void ChPlugInMgr::Initialize()
{
	if ( m_strPuebloPluginDir.IsEmpty() )
	{
		if ( !::GetModuleFileName( NULL, m_strPuebloPluginDir.GetBuffer( 512 ), 512 ) )
		{
			m_strPuebloPluginDir.ReleaseBuffer();	
			TRACE( "GetModuleFileName function failed !!!!" );
		}

		m_strPuebloPluginDir.ReleaseBuffer();	
		if ( !m_strPuebloPluginDir.IsEmpty() )
		{
			m_strPuebloPluginDir = m_strPuebloPluginDir.Left( 
							m_strPuebloPluginDir.ReverseFind( TEXT( '\\' ) ) + 1 );

			m_strPuebloPluginDir += TEXT( "plugins" );

			// if there is no plugin directory create one
			if ( !ChUtil::FileExists( m_strPuebloPluginDir ) )
			{
			 	::CreateDirectory( m_strPuebloPluginDir, NULL );	
			}
			// Make a list of Pueblo plugins
			LocatePlugIn( m_strPuebloPluginDir, true );
		}
	}

	if ( m_strNetscapePluginDir.IsEmpty() )
	{
		DWORD  dwSize = MAX_PATH;
		HKEY   hKey;

		if ( ERROR_SUCCESS == ::RegOpenKeyEx(
								HKEY_CLASSES_ROOT,	
						    	"NetscapeMarkup\\shell\\open\\command",
						    	NULL,				// reserved 
						    	KEY_QUERY_VALUE	, &hKey)
							   )	
		{

			::RegQueryValueEx(   	hKey,		// handle of key to query 
							    	"",// address of name of value to query 
							    	NULL,				// reserved 
							    	NULL,				// address of buffer for value type 
							    	(LPBYTE )
							    	m_strNetscapePluginDir.
							    	GetBuffer( dwSize ),// address of data buffer 
							    	&dwSize );	// address of data buffer size 

			m_strNetscapePluginDir.ReleaseBuffer( );

			RegCloseKey( hKey );
		}

		if ( !m_strNetscapePluginDir.IsEmpty() )
		{
			m_strNetscapePluginDir = m_strNetscapePluginDir.Left( 
						m_strNetscapePluginDir.ReverseFind( TEXT( '\\' ) ) + 1 );

			m_strNetscapePluginDir += TEXT( "plugins" );
			// Make a list of all Netscape plugins
  			LocatePlugIn( m_strNetscapePluginDir, false );
		}
	}

}

bool ChPlugInMgr::FindPlugIn( const string& strMimeType, string& strPlgInModule )
{

	strPlgInModule.Empty();

	ChPluginDllInfo* pInfo = m_plgInDllList.Find( strMimeType ); 

	if ( pInfo  )
	{
		strPlgInModule = pInfo->GetDllName();; 	
	}
	else
	{ // search for plugins in Pueblo directory first
	  	string strAltMime;
	  	int iIndex = strMimeType.Find( TEXT( '/' ) );

		if ( iIndex != -1 )
		{	// change the sub-type
			strAltMime =  strMimeType.Left( iIndex + 1 );
			strAltMime += TEXT( '*' );
			pInfo = m_plgInDllList.Find( strAltMime ); 
			if ( pInfo  )
			{
				strPlgInModule = pInfo->GetDllName();; 	
			}
		}
		if ( strPlgInModule.IsEmpty() )
		{ // Find the global mime handler
			strAltMime = TEXT( "*" );
			pInfo = m_plgInDllList.Find( strAltMime ); 

			if ( pInfo  )
			{
				strPlgInModule = pInfo->GetDllName();; 	
			}
		}
	}
	// Did we find it ?
	return !strPlgInModule.IsEmpty();
}

void ChPlugInMgr::LocatePlugIn( const string& strDir, bool boolPuebloPlugin )
{


	void * pDir = ChUtil::OpenDirectory( strDir, TEXT( "NP*.dll" ), 0xFFFFFFFF );

	if ( pDir )
	{
		ChFileAttrs attrs;

		while( ChUtil::ReadDirectory( pDir,  &attrs, ChUtil::reqPath ) )
		{
			if ( attrs.astrName[0] )
			{
				DWORD  dwHandle;
				DWORD dwLen = GetFileVersionInfoSize( 
								attrs.astrName,	// pointer to filename string
					    		&dwHandle 		// pointer to variable to receive zero
				   				);

				if ( dwLen )
				{
					char * pstrBuffer = new char[dwLen];
					ASSERT( pstrBuffer );
					char *pstrValue;
					if ( GetFileVersionInfo(
								attrs.astrName,	// pointer to filename string
							    dwHandle,	// ignored 
							    dwLen,		// size of buffer
							    pstrBuffer 	// pointer to buffer to receive file-version info.
										   ) )
					{
						UINT dwBytes = 0;

						string strPlgInMime, strFileExtents, strFileOpenName;

						if ( VerQueryValue(pstrBuffer,
					              TEXT("\\StringFileInfo\\040904E4\\MIMEType"),
					              (LPVOID  *)&pstrValue,
					              &dwBytes) )
						{  // add it to the list if not present
							strPlgInMime = pstrValue;
						}

						if ( VerQueryValue(pstrBuffer,
					              TEXT("\\StringFileInfo\\040904E4\\FileExtents"),
					              (LPVOID  *)&pstrValue,
					              &dwBytes) )
						{  // add it to the list if not present
							strFileExtents = pstrValue;
						}
						if ( VerQueryValue(pstrBuffer,
					              TEXT("\\StringFileInfo\\040904E4\\FileOpenName"),
					              (LPVOID  *)&pstrValue,
					              &dwBytes) )
						{  // add it to the list if not present
							strFileOpenName = pstrValue;
						}

						while( !strPlgInMime.IsEmpty()  )
						{
							int iMimeIndex = strPlgInMime.Find( TEXT( '|' ));
							int iFileIndex = strFileExtents.Find( TEXT( '|' ));
							int iDescIndex = strFileOpenName.Find( TEXT( '|' ));

							if ( iMimeIndex == -1 )
							{
								iMimeIndex = strPlgInMime.Find( TEXT( ';' ));
							}

							if ( iMimeIndex == -1 )
							{
								ChPluginDllInfo dllInfo( string(attrs.astrName), strFileExtents, 
															strFileOpenName, attrs.mtime,
															boolPuebloPlugin );

								AddToList( strPlgInMime, dllInfo, boolPuebloPlugin );
								break;
							}
							else
							{
								string strTemp;
								strTemp = strPlgInMime.Left( iMimeIndex );

								ChPluginDllInfo dllInfo( string(attrs.astrName), strFileExtents.Left( iFileIndex ), 
															strFileOpenName.Left( iDescIndex ), attrs.mtime,
															boolPuebloPlugin );

								AddToList( strTemp, dllInfo, boolPuebloPlugin );

								strPlgInMime = strPlgInMime.Right( 
												strPlgInMime.GetLength() - ( iMimeIndex + 1) );
								strFileExtents = strFileExtents.Right( 
												strFileExtents.GetLength() - ( iFileIndex + 1) );
								strFileOpenName = strFileOpenName.Right( 
												strFileOpenName.GetLength() - ( iDescIndex + 1) );
							}
						}
					}
					delete [] pstrBuffer;	
				}

			}
		}
		ChUtil::CloseDirectory( pDir );
	}
}

bool ChPlugInMgr::AddToList( const string strPlgInMime, ChPluginDllInfo& info, bool boolPuebloPlugin )
{
	ChPluginDllInfo *pInfo = m_plgInDllList.Find( strPlgInMime ); 

	if ( pInfo == 0 )
	{
		m_plgInDllList.Insert( strPlgInMime, info ); 	
		ChHTTPConn::AddMimeType( strPlgInMime, info.GetFileExtent(), 
												info.GetFileOpenName() );

	}
	else
	{
		if ( ::CompareFileTime( &info.GetFileTime(), &pInfo->GetFileTime() ) > 0 )
		{  // This is newer use it

			if ( boolPuebloPlugin || !pInfo->IsPuebloPlugin() )
			{ // Do not replace a Netscape plugin with Pueblo plugin
				m_plgInDllList.Delete( strPlgInMime ); 
				m_plgInDllList.Insert( strPlgInMime, info ); 
				ChHTTPConn::AddMimeType( strPlgInMime, info.GetFileExtent(), 
												info.GetFileOpenName() );
			}	
		}
	}
	return true;
}

bool ChPlugInMgr::HandleMimeType( const string& strMimeType )
{
	string strModule;

	if ( !strMimeType.IsEmpty() && FindPlugIn( strMimeType, strModule ) )
	{
		return true;
	}
	return false;
}


bool ChPlugInMgr::LoadPlugInModule( ChHtmlView*	pHtmlView,
									const string& strLocalFile, const string& strURL,
									const string& strMimeType, ChObjInline* pInline)
{
	string 	strModule;

	if (FindPlugIn( strMimeType, strModule ) )
	{  // we found a plugin, load it and initialize

		ChPlugInInstance* pInst = new ChPlugInInstance( strURL, strMimeType, 
										(uint16)pInline->GetMode()  );
		ASSERT( pInst );

		if ( 0 == pInline->GetPluginData() )
		{
			ChInlinePluginData* pData = new ChInlinePluginData( 0 );
			ASSERT( pData );
			// remove any image data
			pInline->SetImageData( 0 );
			// Set the plugin data
			pInline->SetPluginData( pData );
		}


		pInline->GetPluginData()->SetPluginInstance( pInst );

		#pragma message( "Reality Lab workaround : Remove this when we get a fix\n" __FILE__ )
		// add a work around for the reality lab bug.
		// Reality lab cannot be used from more than one dll, if they are
		// then the dll should never be unloaded till the app terminates
		{
			string 	strMod( strModule );
			strMod.MakeLower();

			if ( strModule.Find( TEXT( "NPScout.dll" ) ) != -1 )
			{
				ChUtil::AddModuleToLoadList( strModule );
			}
		}


		if ( pInst->Initialize( strModule ) )
		{ // create the plugin window
			ChSize sizeObj;
			pInline->GetImageSize( sizeObj );

			if ( pInst->New( pHtmlView,
							strLocalFile, sizeObj, 
							pInline->GetPluginData()->GetArgs() ) )
			{
				return true;
			}
		}
		
	}

	return false;
}

const char* ChPlugInMgr::GetClassName()
{
	if ( m_strPluginWndClass.IsEmpty() )
	{
		//m_strPluginWndClass = AfxRegisterWndClass( 0 );
		WNDCLASS	wc;

		wc.hInstance = AfxGetInstanceHandle();
		wc.lpszClassName = TEXT( "_ChacoPluginWnd" );
		wc.lpfnWndProc	= PluginProc;
		wc.hCursor = ::LoadCursor( NULL, IDC_ARROW );
		wc.hIcon = 0;
		wc.hbrBackground = 0;
		wc.lpszMenuName = 0;
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;

		if (RegisterClass( &wc ))
		{  
			m_strPluginWndClass = TEXT( "_ChacoPluginWnd" );
		}
	}

	return m_strPluginWndClass;
}


LONG CALLBACK EXPORT
PluginProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch( uMsg )
	{
		case WM_PLUGIN_INIT_STREAM :
		{// this is called only for the src url in the embed tag
			ChPlugInStream* pStream = (ChPlugInStream*)lParam;
		
			pStream->New();
			pStream->SetState( ChPlugInStream::streamFile );
			//::MessageBox( NULL, "WM_PLUGIN_INIT_STREAM ", "Plugin test", MB_APPLMODAL );
			//::Sleep( 1000 );
			::PostMessage( hWnd, WM_PLUGIN_SET_WINDOW, 0, lParam );
			break;
		}
		case WM_PLUGIN_SET_WINDOW :
		{
			ChPlugInStream* pStream = (ChPlugInStream*)lParam;
			ChPlugInInstance* pInst = ((ChPlugInInstance*)pStream->GetNetscapeInstance()->ndata);

			ChRect rtClient;
			::GetClientRect( hWnd, rtClient );
			::SetWindowPos( hWnd, HWND_TOP, 0, 0, 0, 0, SWP_NOACTIVATE 
								|  SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOMOVE );

			pInst->SetWindow( rtClient, true );

			//::MessageBox( NULL, "WM_PLUGIN_SET_WINDOW ", "Plugin test", MB_APPLMODAL );
			//::Sleep( 1000 );
		
			::PostMessage( hWnd, WM_PLUGIN_STREAM_FILE, 0, lParam );
			break;
		}
		case WM_PLUGIN_NEW_STREAM :
		{
			ChPlugInStream* pStream = (ChPlugInStream*)lParam;
			

			//::MessageBox( NULL, "WM_PLUGIN_NEW_STREAM ", "Plugin test", MB_APPLMODAL );
			//::Sleep( 1000 );

			pStream->New();
			pStream->SetState( ChPlugInStream::streamFile );
			::PostMessage( hWnd, WM_PLUGIN_STREAM_FILE, 0, lParam );
			break;
		}
		case WM_PLUGIN_STREAM_FILE :
		{
			ChPlugInStream* pStream = (ChPlugInStream*)lParam;
			
			//::MessageBox( NULL, "WM_PLUGIN_STREAM_FILE ", "Plugin test", MB_APPLMODAL );
			//::Sleep( 1000 );

			pStream->StreamFile( pStream->GetLocalFile() );
			pStream->SetState( ChPlugInStream::destroyStream );

			::PostMessage( hWnd, WM_PLUGIN_DESTROY_STREAM, 0, lParam );
			break;
		}
		case WM_PLUGIN_DESTROY_STREAM :
		{
			ChPlugInStream* pStream = (ChPlugInStream*)lParam;
			
			//::MessageBox( NULL, "WM_PLUGIN_DESTROY_STREAM ", "Plugin test", MB_APPLMODAL );
			//::Sleep( 1000 );

			pStream->DestroyStream( );
			pStream->SetState( ChPlugInStream::destroyStream + 1 );

			delete pStream;
			break;
		}
		default :
		{
			return DefWindowProc( hWnd, uMsg, wParam, lParam );
		}
	}
	return 0L;
}




