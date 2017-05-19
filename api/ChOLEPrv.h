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

	This file consists of the Chaco OLE private interface .

----------------------------------------------------------------------------*/

#if (!defined( _CHOLEPRV_H ))
#define _CHOLEPRV_H

#include <afxole.h>         // MFC OLE classes

#include <ChSplay.h> 
#include <ChList.h>
#include <ChHtpCon.h>

#include "netscape.h"

class ChOLEConnInfo;
class ChVisitedInfo;

typedef ChVisitedInfo *pChVisitedInfo;
typedef ChOLEConnInfo *pChOLEConnInfo;

typedef ChSplay< string, pChVisitedInfo > ChVisitedList;            
typedef ChPtrList<ChOLEConnInfo > 	ChOLEConnActiveList;            
typedef ChPtrList<ChOLEConnInfo>	ChOLEConnWaitList;     
typedef ChPtrList<string>			ChOLETempFileList;     


UINT  OLEReadThread( LPVOID pData );


/////////////////////////////////////////////////////////////////////////////
// ChVisitedInfo 
// This class maintains the URL's visted during this session
class ChVisitedInfo
{
	public :
		ChVisitedInfo( string& strLocalFile, string strMimeType ) : 
								m_strLocalFile( strLocalFile ), 
								m_strMimeType( strMimeType )
		{}

		~ChVisitedInfo()  {}

		string& GetLocalFileName()
				{
					return m_strLocalFile;
				}
		string& GetMimeType()
				{
					return m_strMimeType;
				}
	private :
		string m_strLocalFile;
		string m_strMimeType;
};




/////////////////////////////////////////////////////////////////////////////
// ChOLEConnInfo 
// This class maintains information about the requested URL. There will be one
// instance of this object per GetURL request. If the request is new then
// this goes into the active list and is removed when ViewDocFile is received.
// If this is a duplicate then it goes into the wait list.
class ChOLEConnInfo	
{
	public :
		ChOLEConnInfo(ChHTTPOLE* pOLE, string& strURL, chuint32 flOptions, 
										chparam userData ) : m_phttpOLE(pOLE), 
													   m_strURL( strURL ),
													   m_userData( userData ),
													   m_flOptions( flOptions ),
													   m_boolAbort( false ) {}
		~ChOLEConnInfo() {}

		ChHTTPOLE* GetHTTPConn()					{ return m_phttpOLE; }
		chparam    GetUserData()					{ return m_userData; }
		string&    GetURL()							{ return m_strURL; }
		chuint32   GetOptions()						{ return m_flOptions; }

		void		Abort()							{ m_boolAbort = true; }
		bool		IsAborted()						{ return m_boolAbort; }

		void DoLoadCompeteNotification( string& strFile, string& strURL, 
									string& strMimeType );
		void ChOLEConnInfo::DoErrorNotification(  int iError  );


	private :
		ChHTTPOLE 	*m_phttpOLE;
		chparam 	m_userData;
		string 		m_strURL;
		chuint32	m_flOptions;
		bool		m_boolAbort;

	private :

	public :
		static void InitOLEConnInfo();
		static void TermOLEConnInfo();
		static ChVisitedList& GetVisitedList()			{ return m_visitedList; }
		static ChOLEConnActiveList& GetConnectionList()	{ return m_connActiveList; }
		static ChOLEConnWaitList& GetWaitList()			{ return m_connWaitList; }
		static ChOLETempFileList& GetTempFileList()		{ return m_tempFileList; }
		static CNetscapeNetwork* GetHTTPOLE()			{ return m_pOLEConn; }
		static bool   ProcessConnectionRequest( ) ;
		static string&  GetCacheDir()					{ return m_strCacheDir;	}
		static ChHTTPSocketConn* GetSocketConn()		{ return m_phttpSocketConn; }


		static ChVisitedList		m_visitedList;
		static ChOLEConnActiveList	m_connActiveList;
		static ChOLEConnWaitList	m_connWaitList;
		static ChOLETempFileList	m_tempFileList;
		static CNetscapeNetwork* 	m_pOLEConn;
		static ChHTTPSocketConn*	m_phttpSocketConn;
		static string				m_strCacheDir;

};

#endif //(!defined( _CHOLEPRV_H ))
