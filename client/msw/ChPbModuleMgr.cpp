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

	This file contains the implementation of Pueblo module manager core.  This
	file is only used on the client.

----------------------------------------------------------------------------*/

#include "headers.h"

#include <ChReg.h>
#include <ChUtil.h>

#include "ChPbModuleMgr.h"
#include "ChClCore.h"


CH_DECLARE_MAIN_HANDLER( coreMainHandler )

// There is only one module list and a ID map table for one APP
ChPuebloModuleList			ChPuebloModuleManager::m_moduleList;
ChPuebloModuleIDMap			ChPuebloModuleManager::m_moduleIDMap;
string						ChPuebloModuleManager::m_strAppDir;

///////////////////////////////////////////////////////////////////////////////
////////////   ChPuebloModuleManager
////////////
//////////////////////////////////////////////////////////////////////////////

ChPuebloModuleManager::ChPuebloModuleManager( ChClientCore* pCore  ) :
						m_pCore( pCore ),
						m_coreStreamManager( pCore ),
						m_httpConnection( &m_coreStreamManager, 0 /*ChHTTPConn::connLocalState */ ),
						m_idGenerator( 1000 ),
						m_boolInUnloadAll( false )

{
	ASSERT( pCore );
	InitModuleManager();

}
ChPuebloModuleManager::~ChPuebloModuleManager()
{
	
}


ChModuleID ChPuebloModuleManager::GetModuleID( const string& strModule )
{
	ChModuleInfo* pInfo = m_moduleList.Find( strModule ); 

	if ( pInfo )
	{
		return pInfo->GetModuleID();
	}

	return( 0 );
	
}
string ChPuebloModuleManager::GetModuleName( const ChModuleID idModule )
{
	string* pstrModule = m_moduleIDMap.Find( idModule ); 

	if ( pstrModule )
	{
		return *pstrModule;
	}

	return( string("") );
}

ChModuleRunInfo* ChPuebloModuleManager::GetRunInfo( const ChModuleID idModule )
{
	ChModuleRunInfo** pRunInfo = m_moduleRunTable.Find( idModule );

	if ( pRunInfo && *pRunInfo )
	{
		return *pRunInfo;
	}
	return  0; 
}

ChDispatcher* ChPuebloModuleManager::GetDispatcher( const ChModuleID idModule )
{
	ChModuleRunInfo** pRunInfo = m_moduleRunTable.Find( idModule );

	if ( pRunInfo && *pRunInfo )
	{
		return (*pRunInfo)->GetDispatcher();
	}

	return 0;
}

void ChPuebloModuleManager::InitModuleManager()
{

	if ( m_strAppDir.IsEmpty() )
	{
		if ( !GetModuleFileName( NULL, m_strAppDir.GetBuffer( 512 ), 512 ) )
		{
			m_strAppDir.ReleaseBuffer();	
			TRACE( "GetModuleFileName function failed !!!!" );
			ASSERT( 0 );
		}

		m_strAppDir.ReleaseBuffer();	
		// path of application, scrpit modules are stored relative to app path
		m_strAppDir = m_strAppDir.Left( m_strAppDir.ReverseFind( TEXT( '\\' ) ) + 1 );

		// Empty the current list and rebuild 
		m_moduleList.Erase();
		// Generate module IDs from 1000
		m_idGenerator = 1000;

		// Add the core module to the list
		ChModuleInfo modInfo( CH_CORE_MODULE_ID, string("") );
		m_moduleList.Insert( CH_CLIENT_CORE_NAME, modInfo ); 	
		m_moduleIDMap.Insert( CH_CORE_MODULE_ID, CH_CLIENT_CORE_NAME); 	

		// Build the list of all loadable modules
		BuildModuleList();
	}

}

bool ChPuebloModuleManager::InitCore()
{
	bool			boolSuccess = true;
	ChMainInfo		*pMainInfo;
	ChInitMsg		msg( CH_CORE_MODULE_ID, "" );
	string			strModuleName( CH_CLIENT_CORE_NAME );


	#if defined( CH_MSW )
	ChModuleRunInfo*	pModuleInfo = new ChModuleRunInfo( strModuleName,  0 );
	#else
	ChModuleRunInfo*	pModuleInfo = new ChModuleRunInfo( strModuleName );
	#endif

	ASSERT( pModuleInfo ); 
	m_moduleRunTable.Insert( CH_CORE_MODULE_ID, pModuleInfo );


	pMainInfo = (ChMainInfo *)(coreMainHandler( msg, m_pCore, 0, 
						CH_CORE_MODULE_ID, &strModuleName, 0 ));

	pModuleInfo->Set( coreMainHandler, pMainInfo );

	if ( 0 == pMainInfo )
	{

		m_moduleRunTable.Delete( CH_CORE_MODULE_ID );
	  	delete pModuleInfo;
		boolSuccess = false;
	}
	else
	{
		pModuleInfo->GetDispatcher()->Dispatch( msg );
	}

	return boolSuccess;
}


bool ChPuebloModuleManager::OnStartup()
{
	// Initialize core for this instance
	InitCore();

	ChArgumentList* pArgList = m_pCore->GetArgList();

	string			strLoadParam( "http://www.chaco.com/pueblo-media/lists/" );
	pArgList->AddArg( "PuebloList",  strLoadParam );

	// This will be lanuched by the script handler
	OnLoadModule( string( "Chaco World Manager module"),	pArgList );

	pArgList->Empty();

	#if 0
	ChRegistry		reg( CH_LOGIN_GROUP );

	if (reg.Read( CH_STARTUP_SCRIPT_URL, strURL ))
	{
					
	}
	else
	{ // No script specified load the default script
	  // Get the local default script file name
	  	string strScriptFile( GetAppDirectory() + DEFAULT_SCRIPT );
		ParseScript( strScriptFile );
	}
	#endif

	return true;
}


bool ChPuebloModuleManager::OnShutDown()
{

	m_httpConnection.AbortRequests( true );
	return true;
}


bool  ChPuebloModuleManager::OnLoadModule( const string& strModuleName, ChArgumentList *pArgList)
{

	string 	strLibrary;
	bool	boolSuccess = true;

	if ( FindModule( strModuleName, strLibrary ) )
	{	// We have the module, load it

		ChModuleRunInfo** pRunInfo =  m_moduleRunTable.Find( GetModuleID( strModuleName ) );

		if ( pRunInfo && *pRunInfo )
		{ // Module is already loaded, up the use count
			(*pRunInfo)->Use();
		}
		else 
		{  // Load the module, if sucessful add it to the run table
			boolSuccess = LoadPuebloModule( strModuleName, strLibrary, pArgList );

		}
	}
	else
	{	 // not in our list, request server to download
			boolSuccess = false;
	}

	return boolSuccess;

}

bool ChPuebloModuleManager::FindModule( const string& strModuleName, string& strLibrary )
{
	ChModuleInfo* pInfo = m_moduleList.Find( strModuleName ); 

	strLibrary.Empty();

	if ( pInfo && !pInfo->GetLibraryName().IsEmpty() )
	{
		strLibrary = pInfo->GetLibraryName(); 	
	}

	return 	!strLibrary.IsEmpty();
}

bool ChPuebloModuleManager::LoadPuebloModule( const string& strModule, const string& strLibrary,
									ChArgumentList *pArgList )
{

	bool			boolSuccess = true;
	ChMainHandler	handler;

	#if defined( CH_MSW )

	HINSTANCE		hLibrary;

	#endif	// defined( CH_MSW )

	#if    defined( CH_MSW )
	{       
		TRACE2( "LOAD: Library %s (%s)\n", (const char *)strLibrary,
											(const char *)strModule );

		#pragma message( "Reality Lab workaround : Remove this when we get a fix\n" __FILE__ )
		// add a work around for the reality lab bug.
		// Reality lab cannot be used from more than one dll, if they are
		// then the dll should never be unloaded till the app terminates
		{
			string 	strMod( strLibrary );
			strMod.MakeLower();

			if ( strMod.Find( TEXT( "chgraphx.dll" ) ) != -1 )
			{
				ChUtil::AddModuleToLoadList( strLibrary );
			}
		}
											/* Load the library and get the ChMain
												entrypoint address */
		hLibrary = LoadLibrary( strLibrary );

        #if defined( WIN32 )
		if (0 == hLibrary)
		{
			boolSuccess = false;
		}
		#else
		if ( hLibrary <= HINSTANCE_ERROR )  
		{
			boolSuccess = false;
		}
		#endif
		else
		{
			handler = (ChMainHandler)GetProcAddress( hLibrary, CH_MAIN_NAME );
            
 			if (0 == handler)
			{
           		#if defined( WIN32 )
				DWORD		dwError;

				dwError = GetLastError(); 
				#endif

				boolSuccess = false;
			} 
		}
	}
	#else	// defined( CH_MSW )
	{
		#if defined( linux )
			CH_DECLARE_MAIN_HANDLER( ChMainEntry );
#ifdef CH_CLIENT
			CH_DECLARE_MAIN_HANDLER( ChMainEntryWorld );

			if (strLibrary == CH_MODULE_WORLD) {
				handler = ChMainEntryWorld;
			} else
#endif // CH_CLIENT
			{
				handler = ChMainEntry;
			}
		#else
			void *lib = dlopen( strLibrary, RTLD_NOW );
			if (lib) {
				handler = (ChMainHandler)dlsym( lib, CH_MAIN_NAME );
				if (handler == 0) {
					cerr << dlerror() << endl;
					boolSuccess = false;
				}
			} else {
				cerr << dlerror() << endl;
				boolSuccess = false;
			}
		#endif // !linux
	}
	#endif	// defined( CH_MSW )

	if (boolSuccess)
	{	 
		ChModuleID		idModule = GetModuleID( strModule );
		ChModuleID		idServerModule = 3;
		string			strLoadParam;

		ChInitMsg		initMsg( idModule, strLoadParam, idServerModule );
		ChMainInfo*		pMainInfo;

		#if defined( CH_MSW )
		ChModuleRunInfo*	pModuleInfo = new ChModuleRunInfo( strModule,  hLibrary );
		#else
		ChModuleRunInfo*	pModuleInfo = new ChModuleRunInfo( strModule );
		#endif

		ASSERT( pModuleInfo ); 
		m_moduleRunTable.Insert( idModule, pModuleInfo );



		pMainInfo = (ChMainInfo *)(handler( initMsg, m_pCore, 0, idModule,
											&strModule, pArgList ));

		if (pMainInfo)
		{


			pModuleInfo->Set( handler, pMainInfo );

			pModuleInfo->GetDispatcher()->Dispatch( initMsg );
		}
		else
		{
			::FreeLibrary( hLibrary );
			boolSuccess = false;

			m_moduleRunTable.Delete( CH_CORE_MODULE_ID );
		  	delete pModuleInfo;
			boolSuccess = false;
		}
	}

	return boolSuccess;
}


void ChPuebloModuleManager::BuildModuleList()
{
	string strDir;

	strDir = GetAppDirectory() + TEXT( "modules" );

	void * pDir = ChUtil::OpenDirectory( strDir, TEXT( "*.*" ), 0xFFFFFFFF );

	if ( !pDir )
	{
		TRACE( "No modules installed !!!" );
		return;
	}

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

					if ( VerQueryValue(pstrBuffer,
				              TEXT("\\StringFileInfo\\040904b0\\PuebloModule"),
				              (LPVOID  *)&pstrValue,
				              &dwBytes) )
					{  // add it to the list if not present
						string strModule( pstrValue );

						if ( !strModule.IsEmpty() )
						{
							while( true )
							{
								int iIndex = strModule.Find( TEXT( ';' ));

								if ( iIndex == -1 )
								{
									ChModuleInfo* pInfo = m_moduleList.Find( strModule ); 

									if ( pInfo == 0 )
									{
										ChModuleInfo modInfo( m_idGenerator, string(attrs.astrName) );
										m_moduleList.Insert( strModule, modInfo ); 	
										m_moduleIDMap.Insert( m_idGenerator++, strModule); 	
									}
									break;
								}
								else
								{
									string strTemp;
									strTemp = strModule.Left( iIndex );

									ChModuleInfo* pInfo = m_moduleList.Find( strTemp ); 

									if ( pInfo == 0 )
									{
										ChModuleInfo modInfo( m_idGenerator, string(attrs.astrName) );
										m_moduleList.Insert( strTemp, modInfo ); 	
										m_moduleIDMap.Insert( m_idGenerator++, strTemp); 	
									}

									strModule = strModule.Right( 
													strModule.GetLength() - ( iIndex + 1 ) );
								}
							}
						}

					}

				}
				delete [] pstrBuffer;	
			}

		}
	}
	ChUtil::CloseDirectory( pDir );
}


