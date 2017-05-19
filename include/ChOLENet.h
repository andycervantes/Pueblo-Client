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

	This file consists of the Chaco OLE interface to WEB clients.

----------------------------------------------------------------------------*/


#if (!defined( _CHOLENET_H ))
#define _CHOLENET_H

#include <ChHTTP.h>


class  ChHTTPOLE : public ChHTTPConn
{

	public :
		ChHTTPOLE( ChHTTPStreamManager* pStreamMgr, chuint32 flOptions = 0 );
		virtual ~ChHTTPOLE();

		// Methods
		int			GetConnectionType()				
						{ 
							return  usingOLE; 
						}

		virtual bool GetURL( const string& strURL, chparam userData,
						const char* pstrDefURL = 0,
						chuint32 flOptions = 0, ChHTTPStreamManager* pStreamMgr = 0 );

		virtual bool PostURL( const string& strURL, const char* pstrBody,
							chint32 lLen = -1, chparam userData = 0,
							const char* pstrDefURL = 0, 
							chuint32 flOptions = 0, ChHTTPStreamManager* pStreamMgr = 0 )
							{	 
								return FALSE;
							}
		virtual void QueryURL( const string& strFile, string& strURL, string& strMimeType )
							{
							}
		virtual bool IsURLCached( const string& strURL, const char* pstrDefURL = 0 )
						{
							return false;
						}
		virtual bool IsVisitedURL( const string& strURL, const char* pstrDefURL = 0 )
						{
							return false;
						}
		virtual bool GetCachedURL( const string& strURL, string& strName, 
								string& strMimeType, const char* pstrDefURL  = 0 , 
								chuint32 flOption  = 0 )
						{
							return false;
						}
		virtual bool DeleteCachedURL( const string& pstrURL, const char* pstrDefURL = 0 )
						{
							return false;
						}
		virtual void AbortRequests( bool boolAbortPrefetch = false, ChHTTPStreamManager* pStreamMgr = 0 );	 

		virtual int NumActive();		

	
		virtual void ShutDownHTTP();

		virtual void GetConnState( string& strMsg, DWORD& dwProgress, DWORD& dwRange )
						{
							strMsg.Empty();
							dwProgress = 0;
							dwRange = 0;
						}

		virtual bool ViewFile( const string strURL, const string& strFile ); 



	public :
		// OLE related methods
		enum tagEventType { eventRequest = 0, eventEndThread = 1, numEvents = 2 };

		void ViewDocFile( CString& strFile, CString&strURL, CString& strMimeType );
		bool IsThreaded()			{ return m_boolThreaded; }

		// static methods
		static int GetTotalEvents()		{ return numEvents; }
		static HANDLE* GetEvents()		{ return m_hOLENetEvent; }
		static HANDLE  GetRequestEvent(){ return m_hOLENetEvent[eventRequest]; }
		static HANDLE  GetEndThread()	{ return m_hOLENetEvent[eventEndThread]; }

	private :
		void InitOLEConn();

	private :
		bool					m_boolThreaded;
		static unsigned	long	m_numObjects;
		static HANDLE			m_hOLENetEvent[2];
	public :
		static CRITICAL_SECTION	m_oleSync;


};
#endif // defined( _CHOLENET_H )


