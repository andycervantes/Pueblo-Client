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

	This file contains the interface for the ChPaneManager class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/ChMime.h,v 2.3 1995/11/20 04:43:15 pritham Exp $

#if !defined( _CHMIME_H )
#define _CHMIME_H

#include <ChList.h>


#if defined( CH_MSW )
											/* Disable warnings about non-
												exported classes for MSW */
	#pragma warning( disable: 4275 )
	#pragma warning( disable: 4251 )

#endif	// defined( CH_MSW )

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
#endif

class ChPaneMgr;
class ChHTTPConn;


/*----------------------------------------------------------------------------
	ChPane class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS ChMimeItem
{
	friend class ChMimeMgr;
	friend static void ChDestructHelper( ChMimeItem* pItem );

	public:

	protected:
		ChMimeItem( const ChModuleID& idModule, const string& strMimeType );
		~ChMimeItem();

		inline const ChModuleID& GetModuleID() { return m_idModule; }
		inline const string& GetMimeType() { return m_strMimeType; }
		inline void SetModuleID( const ChModuleID& idModule )
					{
						m_idModule = idModule;
					}

	protected:
		ChModuleID		m_idModule;
		string			m_strMimeType;
};


/*----------------------------------------------------------------------------
	ChMimeMgr list destruct helper
----------------------------------------------------------------------------*/

static void ChDestructHelper( ChMimeItem* pItem )
{
	delete pItem;
}


/*----------------------------------------------------------------------------
	ChMimeMgr class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS ChMimeMgr
{
	CH_FRIEND_MESSAGE_HANDLER( mimeLoadCompleteHandler )

	public:
		ChMimeMgr();
		~ChMimeMgr();

		ChMimeItem* AddHandler( const ChModuleID& idModule,
								const string& strMimeType );
		void RemoveHandler( const ChModuleID& idModule,
							const string& strMimeType );

		void LoadURL( const string& strURL, const string& strHTML );

	protected:
		inline ChModuleID GetModuleID() const { return m_idMimeModule; }

		ChMimeItem* FindItem( const string& strMimeType );
		ChHTTPConn* GetHTTPConn();
		void RegisterModule();
		void UnregisterModule();
		void DispatchLoad( ChLoadCompleteMsg* pLoadCompleteMsg );

	protected:
		ChPtrList<ChMimeItem>	m_list;
		ChModuleID				m_idMimeModule;
		ChHTTPConn*				m_pHTTPConn;
};


#if defined( CH_MSW ) && defined( CH_ARCH_16 )
	#undef AFXAPP_DATA
	#define AFXAPP_DATA NEAR
#endif

#endif	// !defined( _CHMIME_H )
