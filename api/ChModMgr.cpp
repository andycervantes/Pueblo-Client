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

	This file contains the implementation of the ChModuleMgr class, which
	manages module information as well as loading and unloading modules.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/api/ChModMgr.cpp,v 2.11 1995/11/07 18:19:12 coyote Exp $

#include "headers.h"

#include <ChModMgr.h>
#include <ChMsgTyp.h>
#include <ChSplay.h>
#include <ChDispat.h>
#include <ChList.h>
#include <ChWorld.h>

#ifdef CH_UNIX
#include <dlfcn.h>
#include <sys/param.h>
#include <unistd.h>
#endif

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	Static Unload list
----------------------------------------------------------------------------*/

#if !defined( NO_TEMPLATES )
static ChList<chparam>	unloadedList;
#else 
static ChParamList		unloadedList;
#endif


ChModuleID ChModuleMgr::m_idLocalModule = CH_LOCAL_MODULE_ID_START;

/*----------------------------------------------------------------------------
	ChModuleInfo class
----------------------------------------------------------------------------*/

ChModuleInfo::ChModuleInfo( const string& strName, const string& strFilename,
							bool boolStatic, ChMainHandler mainHandler,
							ChMainInfo *pMainInfo ) :
					m_strName( strName ),
					m_strFilename( strFilename ),
					m_boolStatic( boolStatic ),
					m_pMainInfo( pMainInfo ),
					m_mainHandler( mainHandler ),
					m_sUsageCount( 1 )
{
	#if defined( CH_MSW )
	{										/* Must be set later with
												SetLibraryHandle() */
		m_hLibrary = 0;
	}
	#endif	// defined( CH_MSW )
}

ChModuleInfo::ChModuleInfo( ChDispatcher* pDispatcher ) :
					m_boolStatic( true ), m_pMainInfo( 0 ), m_mainHandler( 0 ),
					m_pDispatcher( pDispatcher ), m_sUsageCount( 1 )
{
	#if defined( CH_MSW )
	{										/* Must be set later with
												SetLibraryHandle() */
		m_hLibrary = 0;
	}
	#endif	// defined( CH_MSW )
}


bool ChModuleInfo::Unload( const ChModuleID idModule )
{
	bool	boolUnloaded;

	if ( 0 >= DecrementModuleUsage())
	{
		ChMainInfo		*pMainInfo = GetMainInfo();
		ChMainHandler	handler = GetMainHandler();
		ChTermMsg		msg;
											// Send the TERM message

		handler( msg, pMainInfo, idModule, &GetName() );

											// Unload the library
		#if defined( CH_MSW )
		{
			HINSTANCE	hLibrary;

			if (hLibrary = GetLibraryHandle())
			{
				FreeLibrary( hLibrary );
			}
		}
		#endif	// defined( CH_MSW )

		boolUnloaded = true;
	}
	else
	{
		boolUnloaded = false;
	}

	return boolUnloaded;
}


/*----------------------------------------------------------------------------
	ChVisitEnumAll class
----------------------------------------------------------------------------*/

class ChVisitEnumAll : public 
							#if !defined( NO_TEMPLATES )
								ChPtrSplayVisitor2<ChModuleInfo>
							#else 
								ChModuleSplayTreePtrVisitor2
							#endif	
{
	public:
		ChVisitEnumAll( ChModEnumFunc enumFunc )
			{
				m_enumFunc = enumFunc;
			}

		bool Visit( ChModuleID idModule, const ChModuleInfo* pModuleInfo );

	protected:
		ChModEnumFunc	m_enumFunc;
};

bool ChVisitEnumAll::Visit( ChModuleID idModule,
							const ChModuleInfo* pModuleInfo )
{
	bool	boolContinue;

	boolContinue = m_enumFunc( *pModuleInfo );

	return boolContinue;
}


/*----------------------------------------------------------------------------
	ChVisitCountAll class
----------------------------------------------------------------------------*/

class ChVisitCountAll : public 
							#if !defined( NO_TEMPLATES )
								ChPtrSplayVisitor2<ChModuleInfo>
							#else 
								ChModuleSplayTreePtrVisitor2
							#endif	
{
	public:
		ChVisitCountAll() : m_iCount( 0 ) {}

		virtual void Start() { m_iCount = 0; }
		virtual bool Visit( ChModuleID idModule,
							const ChModuleInfo* pModuleInfo );

		inline int GetCount() { return m_iCount; }

	protected:
		int		m_iCount;
};

bool ChVisitCountAll::Visit( ChModuleID idModule,
								const ChModuleInfo* pModuleInfo )
{
	m_iCount++;
	return true;
}


/*----------------------------------------------------------------------------
	ChVisitGetModuleIDs class
----------------------------------------------------------------------------*/

class ChVisitGetModuleIDs : public 
							#if !defined( NO_TEMPLATES )
								ChPtrSplayVisitor2<ChModuleInfo>
							#else 
								ChModuleSplayTreePtrVisitor2
							#endif	
{
	public:
		ChVisitGetModuleIDs( int iMax, ChModuleID* pModules ) :
					m_iMax( iMax ),
					m_pModules( pModules ),
					m_iIndex( 0 )
				{
				}

		virtual void Start()
				{
					ASSERT( m_pModules );
					m_iIndex = 0;
				}
		virtual bool Visit( ChModuleID idModule,
							const ChModuleInfo* pModuleInfo );

		inline int GetCount() { return m_iIndex; }

	protected:
		int			m_iMax;
		ChModuleID*	m_pModules;
		int			m_iIndex;
};

bool ChVisitGetModuleIDs::Visit( ChModuleID idModule,
								const ChModuleInfo* pModuleInfo )
{
	if (m_iIndex >= m_iMax)
	{
		return false;
	}

	m_pModules[m_iIndex] = idModule;
	m_iIndex++;

	return true;
}


/*----------------------------------------------------------------------------
	ChVisitHideAll class
----------------------------------------------------------------------------*/

class ChVisitHideAll : public 
							#if !defined( NO_TEMPLATES )
								ChPtrSplayVisitor2<ChModuleInfo>
							#else 
								ChModuleSplayTreePtrVisitor2
							#endif	
{
	public:
		ChVisitHideAll() {}

		bool Visit( ChModuleID idModule, const ChModuleInfo* pModuleInfo );
};

bool ChVisitHideAll::Visit( ChModuleID idModule, const ChModuleInfo* pModuleInfo )
{
	if (idModule != CH_CORE_MODULE_ID)
	{										/* Hide all modules except
												the core */
		ChShowModuleMsg		msg( false );

		pModuleInfo->GetDispatcher()->Dispatch( msg );
	}
	return true;
}


/*----------------------------------------------------------------------------
	ChVisitUnloadAll class
----------------------------------------------------------------------------*/

class ChVisitUnloadAll : public 
							#if !defined( NO_TEMPLATES )
								ChPtrSplayVisitor2<ChModuleInfo>
							#else 
								ChModuleSplayTreePtrVisitor2
							#endif	
{
	public:
		ChVisitUnloadAll() {}

		bool Visit( ChModuleID idModule, const ChModuleInfo* pModuleInfo );
};

bool ChVisitUnloadAll::Visit( ChModuleID idModule,
								const ChModuleInfo* pModuleInfo )
{
	if (idModule != CH_CORE_MODULE_ID && idModule < CH_LOCAL_MODULE_ID_START )
	{										/* Unload all modules except
												the core */

		if (((ChModuleInfo*&)pModuleInfo)->Unload( idModule ))
		{
			unloadedList.AddTail( idModule );
		}
	}

	return true;
}


/*----------------------------------------------------------------------------
	ChVisitCheckpointAll class
----------------------------------------------------------------------------*/

class ChVisitCheckpointAll : public 
							#if !defined( NO_TEMPLATES )
								ChPtrSplayVisitor2<ChModuleInfo>
							#else 
								ChModuleSplayTreePtrVisitor2
							#endif	
{
	public:
		ChVisitCheckpointAll() {}

		bool Visit( ChModuleID idModule,
					const ChModuleInfo* pModuleInfo );
};

bool ChVisitCheckpointAll::Visit( ChModuleID idModule,
									const ChModuleInfo* pModuleInfo )
{
	if (idModule != CH_CORE_MODULE_ID && idModule < CH_LOCAL_MODULE_ID_START )
	{										/* Checkpoint all modules except
												the core */
		ChCheckpointModuleMsg	msg;

		pModuleInfo->GetDispatcher()->Dispatch( msg );
	}

	return true;
}


/*----------------------------------------------------------------------------
	ChFindModuleOp class
----------------------------------------------------------------------------*/

class ChFindModuleOp : public 
							#if !defined( NO_TEMPLATES )
								ChPtrSplayVisitor2<ChModuleInfo>
							#else 
								ChModuleSplayTreePtrVisitor2
							#endif	
{
	public:
		ChFindModuleOp( const string& strName ) :
				m_strName( strName ), m_idModule( 0 ) {}

		inline bool GetInfo( ChModuleID& idModule, string& strFilename )
						{
							idModule = m_idModule;
							strFilename = m_strFilename;

							return 0 != m_idModule;
						}

		bool Visit( ChModuleID idModule,
					const ChModuleInfo* pModuleInfo );

	private:
		string		m_strName;				// Module name passed in
		ChModuleID	m_idModule;				// Two values to return
		string		m_strFilename;
};

bool ChFindModuleOp::Visit( ChModuleID idModule,
							const ChModuleInfo* pModuleInfo )
{
	bool	boolContinue;

	if (pModuleInfo->GetName() == m_strName)
	{										// We found the module
		m_idModule = idModule;
		m_strFilename = pModuleInfo->GetFilename();
		boolContinue = false;
	}
	else
	{
		boolContinue = true;
	}

	return boolContinue;
}


/*----------------------------------------------------------------------------
	ChModuleMgr class
----------------------------------------------------------------------------*/

ChModuleMgr::ChModuleMgr() : m_boolInUnloadAll( false )
{
}


ChModuleMgr::~ChModuleMgr()
{
}


ChModuleID ChModuleMgr::CreateLocalModule()
{
	// Module IDs are valid only on the client
	// 0xFFFFF000 - 0xFFFFFFFF	are reserved fo local modules
	return ( m_idLocalModule++ );
}


bool ChModuleMgr::Add( const ChModuleID& idModule, const string& strModule,
						ChMainHandler mainHandler )
{
	bool			boolSuccess;
	ChInitMsg		msg( idModule, CH_CORE_MODULE_ID );
	ChMainInfo		*pMainInfo;

	pMainInfo = (ChMainInfo *)(mainHandler( msg, 0, idModule, &strModule ));
	if (pMainInfo)
	{
		ChModuleInfo*	pModuleInfo = m_moduleTree.FindValue( idModule );
		ChInitMsg		initMsg( idModule, "" );

		if (pModuleInfo)
		{									/* Change existing information in
												the tree */

			pModuleInfo->Set( strModule, true, mainHandler, pMainInfo );
		}
		else
		{									// Add the information to the tree
			ChModuleInfo*	pInfo;

			pInfo = new ChModuleInfo( strModule, "", true, mainHandler,
										pMainInfo );
			m_moduleTree.Insert( idModule, pInfo );
		}
											/* Send a ChInitMsg to the module's
												handler */

		pModuleInfo->GetDispatcher()->Dispatch( initMsg );
		boolSuccess = true;
	}
	else
	{
		boolSuccess = false;
	}

	return boolSuccess;
}



bool ChModuleMgr::Load( const ChModuleID& idModule, const string& strModule,
						const string& strLibrary, const string& strLoadParam,
						const ChModuleID idServerModule )
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
		ChInitMsg		initMsg( idModule, strLoadParam, idServerModule );
		ChMainInfo*		pMainInfo;

		pMainInfo = (ChMainInfo *)(handler( initMsg, 0, idModule,
											&strModule ));

		if (pMainInfo)
		{
			ChModuleInfo*	pModuleInfo = m_moduleTree.FindValue( idModule );

			if (pModuleInfo)
			{								/* Change existing information in
												the tree */

				pModuleInfo->Set( strModule, false, handler, pMainInfo );

				#if defined( CH_MSW )
				{
					pModuleInfo->SetLibraryHandle( hLibrary );
				}
				#endif	// defined( CH_MSW )
			}
			else
			{								// Add the information to the tree
				ChModuleInfo	*pInfo;

				pInfo = new ChModuleInfo( strModule, strLibrary, false,
											handler, pMainInfo );
				#if defined( CH_MSW )
				{
					pInfo->SetLibraryHandle( hLibrary );
				}
				#endif	// defined( CH_MSW )

				m_moduleTree.Insert( idModule, pInfo );
				pModuleInfo = m_moduleTree.FindValue( idModule );
			}
											/* Send a ChInitMsg to the module's
												handler */

			pModuleInfo->GetDispatcher()->Dispatch( initMsg );
			boolSuccess = true;
		}
		else
		{
			boolSuccess = false;
		}
	}

	return boolSuccess;
}


void ChModuleMgr::IncrementModuleUsage( const ChModuleID& idModule )
{
	ChModuleInfo*	pModuleInfo = m_moduleTree.FindValue( idModule );

	ASSERT( pModuleInfo );

	pModuleInfo->IncrementModuleUsage();
}


void ChModuleMgr::Unload( const ChModuleID& idModule )
{
	ChModuleInfo*	pModuleInfo = m_moduleTree.FindValue( idModule );

	if (pModuleInfo && pModuleInfo->Unload( idModule ))
	{
		if (InUnloadAll())
		{									/* We can't delete right now, so
												add to a list to unload later */
			unloadedList.AddTail( idModule );
		}
		else
		{										// Delete from the tree
			m_moduleTree.Delete( idModule );
		}
	}
}


ChDispatcher* ChModuleMgr::GetDispatcher( const ChModuleID& idModule )
{
	ChDispatcher*	pDispatcher = 0;
	ChModuleInfo*	pModuleInfo;

	if (pModuleInfo = m_moduleTree.FindValue( idModule ))
	{
		pDispatcher = pModuleInfo->GetDispatcher();
	}
	
	return pDispatcher;
}


void ChModuleMgr::SetDispatcher( const ChModuleID& idModule, ChDispatcher* pDispatcher )
{
	ChModuleInfo*	pModuleInfo;

	if (pModuleInfo = m_moduleTree.FindValue( idModule ))
	{
											// The module is already loaded

		pModuleInfo->SetDispatcher( pDispatcher );
	}
	else
	{										// The module is not yet loaded
		ChModuleInfo*	pInfo;

		pInfo = new ChModuleInfo( pDispatcher );
		m_moduleTree.Insert( idModule, pInfo );
	}
}


void ChModuleMgr::EnumerateModules( ChModEnumFunc enumFunc )
{
	ChVisitEnumAll	enumAll( enumFunc );

	m_moduleTree.Infix( enumAll );
}


int ChModuleMgr::GetCount()
{
	ChVisitCountAll	countAll;

	m_moduleTree.Infix( countAll );

	return countAll.GetCount();
}


int ChModuleMgr::GetModuleIDs( int iMax, ChModuleID* pModules )
{
	ChVisitGetModuleIDs	getAll( iMax, pModules );

	m_moduleTree.Infix( getAll );

	return getAll.GetCount();
}


void ChModuleMgr::HideAll()
{
	ChVisitHideAll	hideAll;

	m_moduleTree.Infix( hideAll );
}


void ChModuleMgr::UnloadAll()
{
	ChVisitUnloadAll	unloadAll;
	bool				boolPrevUnload;

	boolPrevUnload = SetUnloadAll();
	m_moduleTree.Infix( unloadAll );
	SetUnloadAll( boolPrevUnload );
											// Erase all entries unloadList
	while (!unloadedList.IsEmpty())
	{
		ChModuleID			idUnloaded;
	
		idUnloaded = unloadedList.RemoveHead();
		m_moduleTree.Delete( idUnloaded );
	}
}

void ChModuleMgr::CheckpointAll()
{
	ChVisitCheckpointAll	checkpointAll;

	m_moduleTree.Infix( checkpointAll );
}


bool ChModuleMgr::FindModule( const string& strModule,
								ChModuleID& idModule, string& strFilename )
{
	ChFindModuleOp		moduleSearch( strModule );
	bool				boolLoaded;
											// Scan the tree for the module
	m_moduleTree.Infix( moduleSearch );
											// Return what we found

	if (moduleSearch.GetInfo( idModule, strFilename ))
	{
		boolLoaded = true;
	}
	else
	{
		boolLoaded = false;
	}

	return boolLoaded;
}


ChMainInfo* ChModuleMgr::GetMainInfo( const ChModuleID& idModule )
{
	ChMainInfo*		pInfo;
	ChModuleInfo*	pModuleInfo;

	if (pModuleInfo = m_moduleTree.FindValue( idModule ))
	{
		pInfo = pModuleInfo->GetMainInfo();
	}
	else
	{
		pInfo = 0;
	}

	return pInfo;
}

string ChModuleMgr::GetModuleName( const ChModuleID& idModule )
{
	ChModuleInfo*	pModuleInfo;
	string			strName;

	if (pModuleInfo = m_moduleTree.FindValue( idModule ))
	{
		strName = pModuleInfo->GetName();
	}
	else
	{
		strName = "";
	}

	return strName;
}

// Local Variables: ***
// tab-width:4 ***
// End: ***
