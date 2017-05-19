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

	This file contains the interface for the ChModuleMgr class, which
	manages module information as well as loading and unloading modules.

----------------------------------------------------------------------------*/


#include "headers.h"

#include <ChDispat.h>
#include <ChMsgTyp.h>

#include "ChPbModuleMgr.h"
#include "ChRunTimeInfo.h"

#define CH_LOCAL_MODULE_ID_START 	0xFFFFF000
#define CH_LOCAL_MODULE_ID_END		0xFFFFFFFF

#pragma optimize( "", off )

/*----------------------------------------------------------------------------
	ChModuleInfo class
----------------------------------------------------------------------------*/

#if defined( CH_MSW )
ChModuleRunInfo::ChModuleRunInfo( const string& strModule,
									HINSTANCE hLibrary ) :
						m_hLibrary(  hLibrary ),
#else
ChModuleRunInfo::ChModuleRunInfo( const string& strModule )	:
#endif
						m_strName( strModule ),
						m_mainHandler( 0 ),
						m_pMainInfo( 0 ),
						m_iUseCount( 1 ),
						m_pDispatcher( 0 )
{
}


ChModuleRunInfo::~ChModuleRunInfo()
{
	#if defined( CH_MSW )
	{
		if (m_hLibrary)
		{
			::FreeLibrary( m_hLibrary );
		}
	}
	#endif	// defined( CH_MSW )
} 

bool ChModuleRunInfo::Unload( const ChModuleID idModule )
{
	Release();

	if ( GetUseCount() == 0 )
	{
		ChMainInfo		*pMainInfo = GetMainInfo();
		ChMainHandler	handler = GetMainHandler();
		ChTermMsg		msg;
											// Send the TERM message

		handler( msg, pMainInfo->GetCore(), pMainInfo, idModule, &GetName(), 0 );

		if ( m_hLibrary )
		{
			::FreeLibrary( m_hLibrary );
			m_hLibrary = 0; 
		}
	}

	return true;
}


/*----------------------------------------------------------------------------
	ChVisitHideAll class
----------------------------------------------------------------------------*/

class ChVisitHideAll : public ChVisitor2<ChModuleID, ChModuleRunInfo*>
{
	public:
		ChVisitHideAll() {}

		bool Visit( const ChModuleID& idModule, const pChModuleRunInfo& pModuleInfo );
};


bool ChVisitHideAll::Visit( const ChModuleID& idModule, const pChModuleRunInfo& pModuleInfo )
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
	ChVisitCountAll class
----------------------------------------------------------------------------*/

class ChVisitCountAll : public	ChVisitor2<ChModuleID, ChModuleRunInfo*>
{
	public:
		ChVisitCountAll() : m_iCount( 0 ) {}

		virtual void Start() { m_iCount = 0; }
		virtual bool Visit( const ChModuleID& idModule,  ChModuleRunInfo* const& pModuleInfo );

		inline int GetCount() { return m_iCount; }

	protected:
		int		m_iCount;
};

bool ChVisitCountAll::Visit( const ChModuleID& idModule, ChModuleRunInfo* const& pModuleInfo )
{
	m_iCount++;
	return true;
}


/*----------------------------------------------------------------------------
	ChVisitGetModuleIDs class
----------------------------------------------------------------------------*/

class ChVisitGetModuleIDs : public ChVisitor2<ChModuleID, ChModuleRunInfo*>
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

		virtual bool Visit( const ChModuleID& idModule,
							ChModuleRunInfo* const& pModuleInfo );

		inline int GetCount() { return m_iIndex; }

	protected:
		int			m_iMax;
		ChModuleID*	m_pModules;
		int			m_iIndex;
};


bool ChVisitGetModuleIDs::Visit( const ChModuleID& idModule,
									ChModuleRunInfo* const& pModuleInfo )
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
	ChVisitOnTick class
----------------------------------------------------------------------------*/

class ChVisitOnTick : public ChVisitor2<ChModuleID, ChModuleRunInfo*>
{
	public:
		ChVisitOnTick( time_t timeCurr ) : m_timeCurr( timeCurr ) {}

		virtual bool Visit( const ChModuleID& idModule,
							ChModuleRunInfo* const& pModuleInfo );

	protected:
		time_t		m_timeCurr;
};


bool ChVisitOnTick::Visit( const ChModuleID& idModule,
							ChModuleRunInfo* const& pModuleInfo )
{
	if (pModuleInfo->GetMainInfo())
	{
		pModuleInfo->GetMainInfo()->OnSecondTick( m_timeCurr );
	}
	return true;
}


/*----------------------------------------------------------------------------
	ChVisitUnloadAll class
----------------------------------------------------------------------------*/

class ChVisitUnloadAll : public ChVisitor2<ChModuleID, ChModuleRunInfo*>
{
	public:
		ChVisitUnloadAll() {}

		bool Visit( const ChModuleID& idModule,
					ChModuleRunInfo* const& pModuleInfo );
};


bool ChVisitUnloadAll::Visit( const ChModuleID& idModule,
								ChModuleRunInfo* const& pModuleInfo )
{
	if (idModule != CH_CORE_MODULE_ID && idModule < CH_LOCAL_MODULE_ID_START )
	{										/* Unload all modules except
												the core */

		((ChModuleRunInfo*&)pModuleInfo)->Unload( idModule );
	}

	return true;
}


/*----------------------------------------------------------------------------
	ChVisitDeleteRunInfo class
----------------------------------------------------------------------------*/

class ChVisitDeleteRunInfo : public ChVisitor2<ChModuleID, string>
{
	public:
		ChVisitDeleteRunInfo( ChModuleRunTable*	pRunTable) :
						m_pRunTable( pRunTable )	
						{}

		bool Visit( const ChModuleID& idModule, const string& strModule );
	private :
		ChModuleRunTable*	m_pRunTable;
};


bool ChVisitDeleteRunInfo::Visit( const ChModuleID& idModule,
									const string& strModule )
{
	ChModuleRunInfo** ppRunInfo =  m_pRunTable->Find( idModule );
	
	if ( ppRunInfo && *ppRunInfo )
	{
		ChModuleRunInfo* pRunInfo = *ppRunInfo;
		if ( pRunInfo->GetUseCount() <= 0 )
		{
			m_pRunTable->Delete( idModule );
			delete pRunInfo;
		}
	}
	return true;
}


/*----------------------------------------------------------------------------
	ChPuebloModuleManager class
----------------------------------------------------------------------------*/

int	 ChPuebloModuleManager::GetModuleCount()
{
	ChVisitCountAll	countAll;

	m_moduleRunTable.Infix( countAll );

	return countAll.GetCount();
}


int ChPuebloModuleManager::GetModuleIDs( int iModuleCount, ChModuleID* pModules )
{
	ChVisitGetModuleIDs	getAll( iModuleCount, pModules );

	m_moduleRunTable.Infix( getAll );

	return getAll.GetCount();
}  


void ChPuebloModuleManager::OnSecondTick( time_t timeCurr )
{
	ChVisitOnTick		tickVisitor( timeCurr );

	m_moduleRunTable.Infix( tickVisitor );
}  


void ChPuebloModuleManager::HideAll()
{
	ChVisitHideAll	hideAll;

	m_moduleRunTable.Infix( hideAll );
}


void ChPuebloModuleManager::UnloadAll()
{
	m_boolInUnloadAll = true;

	ChVisitUnloadAll	unloadAll;

	m_moduleRunTable.Infix( unloadAll );

											// Erase all entries unloadList
	ChVisitDeleteRunInfo deleteUnloaded( &m_moduleRunTable );

	m_moduleIDMap.Infix( deleteUnloaded );

	m_boolInUnloadAll = false;
}


void ChPuebloModuleManager::UnloadModule( const ChModuleID idModule )
{

	ChModuleRunInfo** ppRunInfo =  m_moduleRunTable.Find( idModule );
	
	if ( ppRunInfo && *ppRunInfo )
	{
		ChModuleRunInfo* pRunInfo = *ppRunInfo;

		pRunInfo->Unload( idModule );

		if ( !m_boolInUnloadAll )
		{
			if ( !pRunInfo->GetUseCount() )
			{
				m_moduleRunTable.Delete( idModule );

				delete pRunInfo;
			}
		}
	}
}
