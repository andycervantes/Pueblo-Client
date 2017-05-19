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

// $Header: /home/cvs/chaco/include/ChModMgr.h,v 2.5 1995/09/15 16:50:02 coyote Exp $

#if !defined( _CHMODMGR_H )
#define _CHMODMGR_H

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA    
#endif

#include <ChTypes.h>
#include <ChModule.h>
#include <ChSplay.h>

#define CH_LOCAL_MODULE_ID_START 	0xFFFFF000
#define CH_LOCAL_MODULE_ID_END		0xFFFFFFFF


/*----------------------------------------------------------------------------
	ChModuleInfo class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS ChModuleInfo
{
	public:
		ChModuleInfo() : m_boolStatic( true ), m_pMainInfo( 0 ),
							m_mainHandler( 0 ), 
							m_pDispatcher( 0 ),
							m_sUsageCount( 0 )
				{
					#if defined( CH_MSW )
					{						/* Must be set later with
												SetLibraryHandle() */
						m_hLibrary = 0;
					}
					#endif	// defined( CH_MSW )
				}

		ChModuleInfo( const string& strName, const string& strFilename,
						bool boolStatic, ChMainHandler mainHandler,
						ChMainInfo *pMainInfo );
		ChModuleInfo( ChDispatcher* pDispatcher );

		inline bool IsValid() const { return (0 != m_pMainInfo); }
		inline bool IsStatic() const { return m_boolStatic; }

		inline ChDispatcher* GetDispatcher() const { return m_pDispatcher; }
		inline const string& GetName() const { return m_strName; }
		inline const string& GetFilename() const { return m_strFilename; }
		inline ChMainHandler GetMainHandler() const { return m_mainHandler; }
		inline ChMainInfo* GetMainInfo() const { return m_pMainInfo; }

		#if defined( CH_MSW )

		inline void SetLibraryHandle( HINSTANCE hLibrary )
						{ m_hLibrary = hLibrary; }
		inline HINSTANCE GetLibraryHandle() { return m_hLibrary; }

		#endif	// defined( CH_MSW )

		inline void SetDispatcher( ChDispatcher* pDispatcher )
						{ m_pDispatcher = pDispatcher; }
		inline void Set( const string& strName, bool boolStatic,
							ChMainHandler mainHandler, ChMainInfo* pMainInfo )
						{
							m_strName = strName;
							m_boolStatic = boolStatic;
							m_mainHandler = mainHandler;
							m_pMainInfo = pMainInfo;
						}

		inline chint16 GetModuleUsage() const { return m_sUsageCount; }
		inline chint16 IncrementModuleUsage() { return ++m_sUsageCount; }
		inline chint16 DecrementModuleUsage() { return --m_sUsageCount; }

		bool Unload( const ChModuleID idModule );

	private:
		string			m_strName;
		string			m_strFilename;
		bool			m_boolStatic;
		ChMainInfo*		m_pMainInfo;
		ChMainHandler	m_mainHandler;
		ChDispatcher*	m_pDispatcher;
		chint16			m_sUsageCount;

		#if defined( CH_MSW )

		HINSTANCE		m_hLibrary;

		#endif	// defined( CH_MSW )
};


/*----------------------------------------------------------------------------
	Destructor helper
----------------------------------------------------------------------------*/

static void ChPtrSplayDestruct( ChModuleInfo* pItem )
{
	delete pItem;
}  

#if defined( NO_TEMPLATES )
#include <TemplCls\ChModTre.h>  
#endif


CH_TYPEDEF_CALLBACK( bool, ChModEnumFunc )( const ChModuleInfo& moduleInfo );


/*----------------------------------------------------------------------------
	ChModuleMgr class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS ChModuleMgr
{
	public:
		ChModuleMgr();							// Standard constructor
		~ChModuleMgr();

		static  ChModuleID CreateLocalModule();

		bool Add( const ChModuleID& idModule, const string& strModule,
					ChMainHandler mainHandler );
		bool Load( const ChModuleID& idModule, const string& strModule,
						const string& strLibrary, const string& strLoadParam,
						const ChModuleID idServerModule );

		void IncrementModuleUsage( const ChModuleID& idModule );
		void Unload( const ChModuleID& idModule );

		void EnumerateModules( ChModEnumFunc enumFunc );
		int GetCount();
		int GetModuleIDs( int iMax, ChModuleID* pModules );

		void HideAll();
		void UnloadAll();
		void CheckpointAll();

		bool FindModule( const string& strModule, ChModuleID& idModule,
							string& strFilename );

		ChDispatcher* GetDispatcher( const ChModuleID& idModule );
		ChMainInfo* GetMainInfo( const ChModuleID& idModule );
		string GetModuleName( const ChModuleID& idModule );

		void SetDispatcher( const ChModuleID& idModule, ChDispatcher* pDispatcher );

	protected:
		inline bool InUnloadAll() { return m_boolInUnloadAll; }
		inline bool SetUnloadAll( bool boolInUnload = true )
						{
							bool	boolPrevUnload = m_boolInUnloadAll;

							m_boolInUnloadAll = boolInUnload;

							return boolPrevUnload;
						}

	private:
		#if !defined( NO_TEMPLATES )
		ChPtrSplay<ChModuleInfo>	m_moduleTree;
		#else
		ChModuleSplayTree			m_moduleTree;
		#endif
		bool						m_boolInUnloadAll;

		static ChModuleID			m_idLocalModule;
};

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR    
#endif

#endif	// !defined( _CHMODMGR_H )
