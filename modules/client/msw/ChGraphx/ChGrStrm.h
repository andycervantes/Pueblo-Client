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

	Interface of mime handlers for ChMaze.

----------------------------------------------------------------------------*/

// $Header: 

#if !defined( _CHGRSTRM_H )
#define _CHGRSTRM_H

#include <ChHttpStream.h>
#include <ChSplay.h>
class ChMazeTextureHTTPReq;	

#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )  
class ChCore;
#endif

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
class 	ChRLImage;
typedef ChSplay<string, ChRLImage*>	ChRLImageCache;     
#endif       



/*----------------------------------------------------------------------------
	ChGraphicStreamManager class
----------------------------------------------------------------------------*/


class ChGraphicStreamManager  :  public  ChHTTPStreamManager
{
	public :
		#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )  
		ChGraphicStreamManager( ChCore* pCore, ChHTTPStreamManager* pNext); 
		#else
		ChGraphicStreamManager( ChHTTPStreamManager* pNext );
		#endif

		virtual ~ChGraphicStreamManager(); 		

	    virtual int NewStream( chparam requestData, pChHTTPStream pStream, bool boolSeekable  );
	    virtual void DestroyStream( chparam requestData, pChHTTPStream pStream, int iReason );
	 	virtual void StreamAsFile(chparam requestData, pChHTTPStream pStream, const char* fname);

		ChHTTPStreamManager* GetNextStreamMgr()  { return m_pNextStream; }
		void LockDecode();
		void UnlockDecode();
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		ChRLImageCache& GetImageCache() 		{ return m_imagCache; }
 		ChRLImage* GetCachedImage( const string& strURL );

		#endif
	private :
		void LoadTexture( int iMimeType, pChHTTPStream pStream, 
														ChMazeTextureHTTPReq *pReq );

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		void ClearImageCache()				{ m_imagCache.Erase(); };
		#endif


	public :
		CRITICAL_SECTION		m_syncDecode;
		int 					m_iSysType;
		ChHTTPStreamManager* 	m_pNextStream;
		
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		ChRLImageCache			m_imagCache;
		#endif

		#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )  
		ChCore* 				m_pCore; 
		#endif
};



#endif //!defined( _CHGRSTRM_H )
