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

	Implementation of stream handler for ChWorld.

----------------------------------------------------------------------------*/

// $Header: 

#include "headers.h"


#include <ChHTTP.h>
#include <ChUtil.h>	

#include <ChCore.h>
#include <ChMsgTyp.h>


#include "ChTextStream.h"


ChTextStreamManager::ChTextStreamManager( ChModuleID idModule )
{
	m_idModule = idModule;

}


int ChTextStreamManager::NewStream( chparam requestData, pChHTTPStream pStream, bool boolSeekable  )
{
	return streamAsFile;
}


void ChTextStreamManager::StreamAsFile(chparam requestData, pChHTTPStream pStream, const char* fname)
{

	ChLoadCompleteMsg*	pMsg = new ChLoadCompleteMsg( pStream->GetURL(), 
						pStream->GetCacheFilename(), 
						pStream->GetMimeType(),
						requestData );

	if ( requestData )
	{
		string *pstrHTML = (string*)requestData;
		pMsg->SetHTML( *pstrHTML );
		delete pstrHTML;
	}


	#if defined( CH_MSW ) && defined( CH_ARCH_32 )
	{
		ChCore::GetCore()->GetMsgQueue()->Add( m_idModule,	pMsg );
	}
	#else
	ChCore::GetCore()->DispatchMsg( m_idModule, *pMsg );
	delete pMsg;
	#endif	// defined( CH_MSW )
}

void ChTextStreamManager::DestroyStream( chparam requestData, pChHTTPStream pStream, int iReason )
{
	if ( iReason )
	{
		ChLoadErrorMsg*		pMsg;

		pMsg = new ChLoadErrorMsg( "", 0, pStream->GetURL(),
									iReason,  requestData );


		if ( requestData )
		{
			string *pstrHTML = (string*)requestData;
			delete pstrHTML;
		}

		#if defined( CH_MSW ) && defined( CH_ARCH_32 )
		{
			ChCore::GetCore()->GetMsgQueue()->Add( m_idModule,	pMsg );
		}
		#else
		{
			ChCore::GetCore()->DispatchMsg( m_idModule, *pMsg );
			delete pMsg;
		}
		#endif
	}
}
