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

	This file contains the implementation of the ChMimeManager class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/api/ChMime.cpp,v 2.5 1995/11/20 04:49:23 pritham Exp $

#include "headers.h"

#include <ChTypes.h>
#include <ChMsgTyp.h>
#include <ChCore.h>
#include <ChHTTP.h>
#include <ChDispat.h>
#include <ChModMgr.h>
#include <ChMime.h>
#include <ChHtmWnd.h>


#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


CH_DECLARE_MAIN_HANDLER( mimeMainHandler )

CH_DECLARE_MESSAGE_HANDLER( mimeDefHandler )
CH_DECLARE_MESSAGE_HANDLER( mimeInitHandler )
CH_DECLARE_MESSAGE_HANDLER( mimeTermHandler )
CH_DECLARE_MESSAGE_HANDLER( mimeLoadCompleteHandler )
CH_DECLARE_MESSAGE_HANDLER( mimeLoadErrorHandler )

static ChMsgHandlerDesc	mimeHandlers[] =
						{
							{CH_MSG_INIT, mimeInitHandler},
							{CH_MSG_TERM, mimeTermHandler},
							{CH_MSG_LOAD_COMPLETE, mimeLoadCompleteHandler},
							{CH_MSG_LOAD_ERROR, mimeLoadErrorHandler},
						};


/*----------------------------------------------------------------------------
	ChHTMLLoadInfo class
----------------------------------------------------------------------------*/

class ChMimeLoadInfo
{
	public:
		ChMimeLoadInfo( ChMimeMgr* pMimeMgr, const string& strHTML ) :
							m_pMimeMgr( pMimeMgr ),
							m_strHTML( strHTML )
				{
				}

		inline const string& GetHTML() { return m_strHTML; }
		inline ChMimeMgr* GetMimeMgr() { return m_pMimeMgr; }

		inline void SetHTML( const string& strHTML ) { m_strHTML = strHTML; }

	protected:
		ChMimeMgr*	m_pMimeMgr;
		string		m_strHTML;
};


/*----------------------------------------------------------------------------
	ChMimeMainInfo class
----------------------------------------------------------------------------*/

class ChMimeMainInfo : public ChMainInfo
{
	public:
		ChMimeMainInfo( ChModuleID idModule ) :
			ChMainInfo( idModule ),
			mimeDispatcher( idModule, mimeDefHandler ) {}

	public:
		ChDispatcher	mimeDispatcher;
};


/*----------------------------------------------------------------------------
	Mime module handler implementations
----------------------------------------------------------------------------*/

CH_IMPLEMENT_MAIN_HANDLER( mimeMainHandler )
{
	chparam		retVal = 0;

	switch( msg.GetMessage() )
	{
		case CH_MSG_INIT:
		{
			ChMimeMainInfo*		pMainInfo;
			chint16				sHandlerCount = sizeof( mimeHandlers ) /
												sizeof( ChMsgHandlerDesc );

											// Construct the main info object

			pMainInfo = new ChMimeMainInfo( idModule );

											// Add specific message handlers

			pMainInfo->mimeDispatcher.AddHandler( mimeHandlers,
													sHandlerCount );

											/* Return a pointer to the
												ChMainInfo-derived class */
			retVal = (chparam)pMainInfo;
			break;
		}

		case CH_MSG_TERM:
		{
			delete pMainInfo;
			break;
		}
	}

	return retVal;
}


CH_IMPLEMENT_MESSAGE_HANDLER( mimeDefHandler )
{
	chparam				retVal = 0;

	TRACE1( "MESSAGE:  UNKNOWN (%ld) (mime)\n", msg.GetMessage() );

	return retVal;
}


CH_IMPLEMENT_MESSAGE_HANDLER( mimeInitHandler )
{
	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( mimeTermHandler )
{
	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( mimeLoadCompleteHandler )
{
	ChLoadCompleteMsg*	pMsg = (ChLoadCompleteMsg*)&msg;
	string				strURL;
	string				strFilename;
	string				strType;
	chparam				userData;
	ChMimeLoadInfo*		pLoadInfo;
	ChMimeMgr*			pMimeMgr;
											// Get message params

	pMsg->GetParams( strURL, strFilename, userData );
	strType = pMsg->GetType();
	pLoadInfo = (ChMimeLoadInfo*)userData;

	TRACE1( "Mime Load Complete:        %s\n", (const char*)strURL );

	pMimeMgr = pLoadInfo->GetMimeMgr();
	ASSERT( pMimeMgr );
											/* Stick the HTML into the load
												complete message */
	pMsg->SetHTML( pLoadInfo->GetHTML() );
											// Dispatch the load complete
	pMimeMgr->DispatchLoad( pMsg );
											// Clean up
	delete pLoadInfo;

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( mimeLoadErrorHandler )
{
	ChLoadErrorMsg*		pMsg = (ChLoadErrorMsg*)&msg;
	string				strModuleName;
	ChModuleID			idModule;
	string				strURL;
	chint32				lError;
	chparam				userData;
	ChMimeLoadInfo*		pLoadInfo;
											// Get message params

	pMsg->GetParams( strModuleName, idModule, strURL, lError, userData );
	pLoadInfo = (ChMimeLoadInfo*)userData;

	TRACE1( "MESSAGE:  CH_MSG_LOAD_ERROR (%ld) (mime)\n", lError );
	TRACE1( "         %s\n", (const char*)strURL );

											// Clean up
	delete pLoadInfo;

	return 0;
}


/*----------------------------------------------------------------------------
	ChMimeMgr class
----------------------------------------------------------------------------*/

#define CH_MIME_LOCAL_NAME		"Pueblo Mime Manager local module"


/*----------------------------------------------------------------------------
	ChMimeMgr class
----------------------------------------------------------------------------*/

ChMimeMgr::ChMimeMgr() :
				m_idMimeModule( 0 ),
				m_pHTTPConn( 0 )
{
	RegisterModule();
}


ChMimeMgr::~ChMimeMgr()
{
	UnregisterModule();

	m_list.Empty();

	if (m_pHTTPConn)
	{
		delete m_pHTTPConn;
		m_pHTTPConn = 0;
	}
}


ChMimeItem* ChMimeMgr::AddHandler( const ChModuleID& idModule,
									const string& strMimeType )
{
	ChMimeItem*		pItem = FindItem( strMimeType );

	if (0 == pItem)
	{										// We need to add a new entry

		pItem = new ChMimeItem( idModule, strMimeType );
		ASSERT( 0 != pItem );

		m_list.AddTail( pItem );
	}
	else
	{										/* An entry for this mime type
												already exists */
		pItem->SetModuleID( idModule );
	}

	return pItem;
}


void ChMimeMgr::RemoveHandler( const ChModuleID& idModule,
								const string& strMimeType )
{
	ChPosition	pos = m_list.GetHeadPosition();
	bool		boolFoundAndDestroyed = false;

	while (pos && !boolFoundAndDestroyed)
	{
		ChMimeItem*		pItem = m_list.Get( pos );

		if ((strMimeType == pItem->GetMimeType()) &&
			(idModule == pItem->GetModuleID()))
		{
			m_list.Remove( pos );
			boolFoundAndDestroyed = true;
		}
	}
}


void ChMimeMgr::LoadURL( const string& strURL, const string& strHTML )
{
	ChMimeLoadInfo*		pInfo = new ChMimeLoadInfo( this, strHTML );
	string				strActiveURL( strURL );

	if (strActiveURL.IsEmpty())
	{
		ChHtmlWnd::GetHTMLHref( strHTML, true, strActiveURL );
	}

	if (!strActiveURL.IsEmpty())
	{
		GetHTTPConn()->GetURL( strActiveURL, (chparam)pInfo );
	}
	else
	{
		TRACE1( "Empty URL passed into ChMimeMgr::LoadURL : %s ", strHTML );
	}
}


/*----------------------------------------------------------------------------
	ChMimeMgr protected methods
----------------------------------------------------------------------------*/

ChMimeItem* ChMimeMgr::FindItem( const string& strMimeType )
{
	ChMimeItem*		pItem = 0;
	ChPosition		pos = m_list.GetHeadPosition();
	string			strMime = strMimeType;

	strMime.MakeLower();
	strMime.TrimLeft();
	strMime.TrimRight();

	while ((0 != pos) && (0 == pItem))
	{
		ChMimeItem*		pCurrItem = m_list.Get( pos );

		if (strMime == pCurrItem->GetMimeType())
		{
			pItem = pCurrItem;
		}
		else
		{
			m_list.GetNext( pos );
		}
	}

	return pItem;
}


ChHTTPConn* ChMimeMgr::GetHTTPConn()
{ 
	if (0 == m_pHTTPConn)
	{
		m_pHTTPConn = new ChHTTPSocketConn( GetModuleID() );

		ASSERT( m_pHTTPConn );	
	}

	return m_pHTTPConn; 
}


void ChMimeMgr::RegisterModule()
{
	ChModuleMgr*	pMgr = ChCore::GetCore()->GetModuleMgr();

	ASSERT( pMgr );

	m_idMimeModule = pMgr->CreateLocalModule();

											// Register the module

	pMgr->Add( m_idMimeModule, CH_MIME_LOCAL_NAME, mimeMainHandler );
}


void ChMimeMgr::UnregisterModule()
{
	ChModuleMgr*	pMgr = ChCore::GetCore()->GetModuleMgr();

	ASSERT( pMgr );

	pMgr->Unload( GetModuleID() );
}


void ChMimeMgr::DispatchLoad( ChLoadCompleteMsg* pLoadCompleteMsg )
{
	string			strMimeType = pLoadCompleteMsg->GetType();
	ChMimeItem*		pItem = FindItem( strMimeType );

	if (pItem)
	{
		ChCore*		pCore = ChCore::GetCore();
		ChModuleID	idModule = pItem->GetModuleID();

		pCore->DispatchMsg( idModule, *pLoadCompleteMsg );
	}
}


/*----------------------------------------------------------------------------
	ChMimeItem class
----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
	ChMimeItem protected methods
----------------------------------------------------------------------------*/

ChMimeItem::ChMimeItem( const ChModuleID& idModule,
						const string& strMimeType ) :
				m_idModule( idModule ),
				m_strMimeType( strMimeType )
{
}


ChMimeItem::~ChMimeItem()
{
}
