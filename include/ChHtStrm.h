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

	This file contains the definition of the ChHTTPInfo class, used to
	manage a connection for downloading modules and data from the server.

----------------------------------------------------------------------------*/

// $Header: 

#if (!defined( _CHHTSTRM_H ))
#define _CHHTSTRM_H

class  ChStreamHandler;
class  ChMimeStream ;

typedef ChStreamHandler *pChStreamHandler;
typedef ChMimeStream 	*pChMimeStream;



class CH_EXPORT_CLASS ChMimeStream 
{
	public :
    	enum tagStreamType { streamNormal = 0x1, streamAsFile = 0x02 };

		ChMimeStream() :
				m_lContentLength( 0 ), m_pData(0)
					{
					}
		virtual ~ChMimeStream()
					{
					}

	    virtual UINT Initialize( ) = 0;

	    virtual int WriteReady( int iBytes )
					{
						return iBytes;
					}
	    virtual int Write( const char* pBuffer, int iBytes )
					{
						return iBytes;
					}

	    virtual void Close( int iStatus ) = 0;

	    virtual bool Notify()
					{
						return true;
					}

	    // methods provided my the base class
	    string& GetURL()
				{
					return m_strURL;	
				}
	    string& GetCacheFilename()
				{
					return m_strFilename;	
				}
	    string& GetMimeType()
				{
					return m_strMimeType;	
					
				}
	    string& GetContentEncoding()
				{
					return m_strEncoding;	
				}
	    long GetContentLength()
				{
					return m_lContentLength;	
				}
	    long GetUserData()
				{
					return m_userData;	
				}

	    void* GetNotifyData()
				{
					return m_pData;					
				}
		UINT  GetStreamOption()
				{
					return 	m_uStreamOption;
				}
	     // Attributes
		 void SetStreamOption( UINT uOption )
		 		{
		 			m_uStreamOption = uOption;
				}
		 void SetNotifyData( void *pData )
		 		{
					m_pData = pData;
				}
	public :
		string 		m_strURL;
		string 		m_strFilename;
		string 		m_strMimeType;
		string 		m_strEncoding;
		long		m_lContentLength;
		chparam		m_userData;
	private :
		UINT		m_uStreamOption;
		void*		m_pData;
  
};



class CH_EXPORT_CLASS ChStreamHandler
{
	public :
		virtual ~ChStreamHandler() 		{}
	    virtual ChMimeStream *NewStream() = 0;
	    virtual void DestroyStream( ChMimeStream *pStream ) = 0;

	private :

};




#endif // (!defined( _CHHTSTRM_H ))

