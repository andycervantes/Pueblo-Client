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

	Implementation for the mime handlers for ChMaze.

----------------------------------------------------------------------------*/

// $Header: 

#include "grheader.h"


#include <ChReg.h>
#include <ChHTTP.h>
#include <ChUtil.h>	
#include <ChUnzip.h>	

#include <ChDibDecoder.h>
#include <ChGIFDecoder.h>
#include <ChJPEGDecoder.h>

#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
#include "ChCore.h"
#include <ChMsgTyp.h>
#include <ChModule.h>
#include "ChGrMod.h"
#endif


#include "ChMaze.h"
#include "ChMazDep.h"
#include "ChRLImg.h"


#include "ChGrStrm.h"
#include "ChRenderData.h"


#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )  
ChGraphicStreamManager::ChGraphicStreamManager( ChCore* pCore, ChHTTPStreamManager* pNext) 
						: m_pNextStream( pNext ),
						  m_pCore( pCore )
#else
ChGraphicStreamManager::ChGraphicStreamManager( ChHTTPStreamManager* pNext) : m_pNextStream( pNext )
#endif
{


	m_iSysType = ChUtil::GetSystemType();

	if (  m_iSysType == CH_SYS_WINNT	||  m_iSysType == CH_SYS_WIN95 )
	{									// Initialize the critcal section

		::InitializeCriticalSection( &m_syncDecode );
	}
}

ChGraphicStreamManager::~ChGraphicStreamManager( )
{
	if (  m_iSysType == CH_SYS_WINNT ||  m_iSysType == CH_SYS_WIN95 )
	{									// Initialize the critcal section

		::DeleteCriticalSection( &m_syncDecode );
	}
}


int ChGraphicStreamManager::NewStream( chparam requestData, pChHTTPStream pStream, bool boolSeekable  )
{
	return streamAsFile;
}


void ChGraphicStreamManager::StreamAsFile(chparam requestData, pChHTTPStream pStream, const char* fname)
{

	int iMimeType = ChHTTPConn::GetMimeType( pStream->GetMimeType() );

	ChGraphicHTTPReq::type loadType = ChGraphicHTTPReq::scene;
	ChGraphicHTTPReq *pHTTPReq	 = (ChGraphicHTTPReq *)requestData;

	if(requestData)
	{
		loadType = pHTTPReq->GetType();
	}

	switch(loadType)
	{
		#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )  
		case ChGraphicHTTPReq::anchor:
		case ChGraphicHTTPReq::script:
		case ChGraphicHTTPReq::sprite:
		case ChGraphicHTTPReq::background:
		case ChGraphicHTTPReq::document:
		{
			ChModuleID idModule = 0;

			if ( loadType == ChGraphicHTTPReq::document )
			{
				ChGraphicDocumentHTTPReq* pReq = (ChGraphicDocumentHTTPReq*)pHTTPReq;
				idModule = pReq->GetModuleID();
			}
			else
			{
				if ( pHTTPReq->GetView() )
				{
					idModule = ((ChGraphicView*)pHTTPReq->GetView())->GetMainInfo()->GetModuleID();
				}
			}

			if ( idModule )
			{
				ChLoadCompleteMsg*	pMsg = new ChLoadCompleteMsg( pStream->GetURL(), 
								pStream->GetCacheFilename(), 
								pStream->GetMimeType(),
								requestData );
				#if defined( CH_MSW ) && defined( CH_ARCH_32 )
				if ( ChUtil::GetSystemProperties() & CH_PROP_MULTITHREADED )
				{  // Send it to the core frame which will to the dispatch
			
					m_pCore->AsyncDispatchMsg( idModule, pMsg );
				}
				else
				{
					m_pCore->DispatchMsg( idModule, *pMsg );
					delete pMsg;
				}
				#else
				m_pCore->DispatchMsg( idModule, *pMsg );
				delete pMsg;
				#endif	// defined( CH_MSW )
			}
			break;
		}
		#endif
		case ChGraphicHTTPReq::scene:
		{
			#if defined(CH_VRML_VIEWER) || defined(CH_VRML_PLUGIN )
	 		// Load a file of vrml
			if ( GetNextStreamMgr() )
			{
				GetNextStreamMgr()->StreamAsFile( requestData,  pStream, fname);
			}
			#else
			TRACE( "We should never have come here\n" );
			ASSERT( false );
			#endif

			delete pHTTPReq;  // it's done
			break;
		}
		case ChGraphicHTTPReq::texture:
		{
											// Load a texture
 			ChMazeTextureHTTPReq *pReq = (ChMazeTextureHTTPReq *)pHTTPReq;

			if( pReq->GetPage() == pReq->GetView()->GetCurrentPage() )
			{
				pReq->SetTextureType( iMimeType );
				// load the texture
				LoadTexture( iMimeType, pStream, pReq );
			}
			else
			{	// no longer required
				delete pReq;  // it's done
			}

			break;
		}
		case ChGraphicHTTPReq::wwwInline:
		{
			// Load the inline file
 			ChMazeInlineHTTPReq *pReq = (ChMazeInlineHTTPReq *)pHTTPReq;
			pReq->GetView()->GetRenderContext()->LockQv();	
			if(pReq->GetPage() == pReq->GetView()->GetCurrentPage() && !pReq->IsCancelled())
			{
				ASSERT(pReq->GetInlineNode());

			   	if ( ChHTTPConn::typeVRML == iMimeType )
				{
					pReq->SetFileType( iMimeType );

					int iType =  ChUnzip::GetZipType( pStream->GetCacheFilename() );

					if ( iType != ChUnzip::typeUnknown )
					{
					  	string strNewFile;

						ChUtil::GetTempFileName( strNewFile, 0, 0, ".wrl" );

						ChUnzip unzip;

						if ( unzip.UnzipFileTo( pStream->GetCacheFilename(), 
										iType == ChUnzip::typeGZIP ? UNZIP_OPT_GZIP_FILE : UNZIP_DEF_OPTION,
										0, strNewFile ) )
						{
					  	
							// load the file
							pReq->GetView()->LoadWWWInline( pStream->GetURL(), strNewFile, pReq->GetInlineNode() );

							// add file to temp list
							ChUtil::AddFileToTempList( strNewFile );
						}
					}
					else
					{

						// load the file
						pReq->GetView()->LoadWWWInline( pStream->GetURL(), 
										pStream->GetCacheFilename(), pReq->GetInlineNode());
					}
				}
														 // request phase is complete
				((ChQvWWWInlineRenderData*)(pReq->GetInlineNode()->GetRenderData()))->SetReq(0);

			}
			else
			{
				if(pReq->IsCancelled()) TRACE("Inline HTTP request cancelled\n");
			}
			pReq->GetView()->GetRenderContext()->UnlockQv();	
			delete pReq;  // it's done
			break;
		}
		default:
		{
			break;
		}
	}

}

void ChGraphicStreamManager::DestroyStream( chparam requestData, pChHTTPStream pStream, int iReason )
{
	if(iReason)
	{
		TRACE1("Stream request failed; reason %d\n", iReason);
		#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )  
		ChGraphicHTTPReq::type loadType = ChGraphicHTTPReq::scene;
		ChGraphicHTTPReq *pHTTPReq	 = (ChGraphicHTTPReq *)requestData;

		if(requestData)
		{
			loadType = pHTTPReq->GetType();
		}
		ChModuleID idModule = 0;

		if ( loadType == ChGraphicHTTPReq::document )
		{
			ChGraphicDocumentHTTPReq* pReq = (ChGraphicDocumentHTTPReq*)pHTTPReq;
			idModule = pReq->GetModuleID();
		}
		else
		{
			if ( pHTTPReq->GetView() )
			{
				if((ChGraphicView*)pHTTPReq->GetView())
				{
					idModule = ((ChGraphicView*)pHTTPReq->GetView())->GetMainInfo()->GetModuleID();
				}
			}
		}

		if ( idModule )
		{
			string strError = pStream->GetErrorMsg();
			ChLoadErrorMsg*	pMsg = new ChLoadErrorMsg( "", idModule, pStream->GetURL(), 
							iReason,
							requestData,
							strError );
			#if defined( CH_MSW ) && defined( CH_ARCH_32 )
			if ( ChUtil::GetSystemProperties() & CH_PROP_MULTITHREADED )
			{  // Send it to the core frame which will to the dispatch
		
				m_pCore->AsyncDispatchMsg( idModule, pMsg );
			}
			else
			{
				m_pCore->DispatchMsg( idModule, *pMsg );
				delete pMsg;
			}
			#else
			m_pCore->DispatchMsg( idModule, *pMsg );
			delete pMsg;
			#endif	// defined( CH_MSW )
		}
		#else // Plugin and viewer only
		ChGraphicHTTPReq *pHTTPReq	 = (ChGraphicHTTPReq *)requestData;
		if ( pHTTPReq && pHTTPReq->GetView() )
		{
			string * pMsg = new string( pStream->GetErrorMsg() );
			// The merssage string is deleted by the message handler
			((ChGraphicView*)pHTTPReq->GetView())->PostMessage(  WM_VRML_MAZE_ERROR, 
												CH_MAZE_HTTP_ERROR_BASE + iReason, 
												(LPARAM)pMsg );
		}
		#endif	   
	}

	if ( GetNextStreamMgr() )
	{
		GetNextStreamMgr()->DestroyStream( requestData,  pStream, iReason );
	}
}


/////////////////////////////////////////////////////////////////////////////////////
/////////// Implementation of ChGrTextureHandler

void ChGraphicStreamManager::LockDecode()
{
	if (  m_iSysType == CH_SYS_WINNT	||  m_iSysType == CH_SYS_WIN95 )
	{
		::EnterCriticalSection( &m_syncDecode );
	}
}

void ChGraphicStreamManager::UnlockDecode()
{
	if (  m_iSysType == CH_SYS_WINNT	||  m_iSysType == CH_SYS_WIN95 )
	{
		::LeaveCriticalSection( &m_syncDecode );
	}
}



#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
/*----------------------------------------------------------------------------
	ChVisitFindRLImage class
----------------------------------------------------------------------------*/

class ChVisitFindRLImage : public ChVisitor2<string, ChRLImage*>
{
	public:
		ChVisitFindRLImage(  ChRLImage* pImage ) :	m_pRLImage( pImage )
						{}

		bool Visit( const string& strKey, const pChRLImage& pRLImage );
	public :
		string		m_strKey;
		 ChRLImage* m_pRLImage;
};


bool ChVisitFindRLImage::Visit( const string& strKey, const pChRLImage& pRLImage )
{
	if ( pRLImage == m_pRLImage )
	{
		m_strKey = strKey;
		return false;
	}
	return true;
}

CH_GLOBAL_CALLBACK( void )
ChRLImageDestroyCallback( void* pData, ChRLImage* pImage )
{

	ChGraphicStreamManager* pGrMgr = (ChGraphicStreamManager*)pData;

	ChVisitFindRLImage	findImage( pImage );

	pGrMgr->LockDecode();

	// Find if this image is in our cache
	pGrMgr->GetImageCache().Infix( findImage );

	if ( !findImage.m_strKey.IsEmpty() )
	{
	 	pGrMgr->GetImageCache().Delete( findImage.m_strKey );
		//TRACE1( "ChRLImageDestroyCallback : Deleting image %s\n", LPCSTR( findImage.m_strKey ) ); 
	}
	else
	{
		TRACE( "ChRLImageDestroyCallback : Image not in cache !!!\n" ); 
	}

	pGrMgr->UnlockDecode();
}

ChRLImage* ChGraphicStreamManager::GetCachedImage( const string& strURL )
{

	LockDecode();

	ChRLImage** ppCache = m_imagCache.Find( strURL );
	ChRLImage*  pRLImage = 0;


	if ( ppCache && *ppCache )
	{
		pRLImage = *ppCache;
		pRLImage->Use();
	}

	UnlockDecode();

	return pRLImage;
}

#endif	// (defined(CH_USE_RLAB) || defined(CH_USE_D3D))


void ChGraphicStreamManager::LoadTexture( int iMimeType, pChHTTPStream pStream, 
												ChMazeTextureHTTPReq *pReq )
{
	chuint uOption = pReq->GetOption() ? pReq->GetOption() : ChMazeTextureHTTPReq::textureAutoSize;
	chuint32 luChromaClr = 0;
	
	#if defined(CH_USE_3DR)	
	ChDib* pDib = 0;
	ChTextureHandle	pData = 0;
	#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	ChRLImage *pData = 0;
	#endif

	if( pReq->GetPage() != pReq->GetView()->GetCurrentPage() )
	{ // We have already moved to a different page, discard the request
		
		delete pReq;
		return;
	}

	if ( pReq->GetTextureNode()->GetUsage() <= 1 )
	{  // The node is no longer used, discard the request
		delete pReq;
		return;
	}


	// Enter critical section : This is done for 2 reasons
	// 	1) Serialze decode so that threads don't take up all the CPU
	//  2) ChDib::SetSize  needs to serialzed
	LockDecode();

	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	ChRLImage** ppCache = 0;
	// cache only autosized images
	if ( !(uOption & ChMazeTextureHTTPReq::textureKeepSize) ) 
	{
	 	ppCache = m_imagCache.Find( pStream->GetURL() );
	}

	if ( ppCache && *ppCache )
	{
		TRACE( "Using cached image\n" );
		pData = *ppCache;
		pData->Use();
	}
	else
	#endif
	{

		TRACE2( "Start decoding texture : %s\nFile : %s\n", LPCSTR(pStream->GetURL() ),
							LPCSTR(pStream->GetCacheFilename() )  );
		// Update progress
		//pReq->GetView()->WriteStatus( PROGRESS_MSG_3 );

		switch( iMimeType )
		{
			case ChHTTPConn::typeGIF:
			{
				// create the gif object
				#if defined(CH_USE_3DR)
				pDib = new ChDib;
				ChGIFDecoder gifDecoder( pDib );

				// Load the GIF file
				if ( gifDecoder.Load( pStream->GetCacheFilename(), ChDib::load8Bit ) )
				{
					if ( pGIF->IsTransparent() )
					{
					 	uOption |= ChMazeTextureHTTPReq::textureChromaKey;
						luChromaClr = pDib->GetTransparentColor(); 
					}
				}
				else
				{
					delete pDib;
					pDib = 0;
				}

				#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

				pData = new ChRLImage( false, uOption );
				ASSERT( pData );

				ChGifDecoder gifDecoder( pData );
				// Load the GIF file
				if ( !gifDecoder.Load( pStream->GetCacheFilename(), ChImageDecoder::load8Bit ) )
				{
					pData->Release();
					pData = 0;
				}

				#endif



				break;
			}
			case ChHTTPConn::typeJPEG:
			{
				#if defined(CH_USE_3DR)
				pDib = new ChDib;
				ChJPEG jpegDecoder( pDib );

				// Load the GIF file
				if ( !jpegDecoder.Load( pStream->GetCacheFilename(), ChImageDecoder::load24Bit ) )
				{
					delete pDib;
					pDib = 0;
				}
				#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

				pData = new ChRLImage( false, uOption );
				ASSERT( pData );

				ChJPEG  jpegDecoder( pData );
				// Load the GIF file
				if ( !jpegDecoder.Load( pStream->GetCacheFilename(), ChImageDecoder::load24Bit ) )
				{
					pData->Release();
					pData = 0;
				}

				#endif
				break;
			}
			case ChHTTPConn::typeBMP :
			{
				#if defined(CH_USE_3DR)

				pData = G3dLoadTexture(pReq->GetView()->GetGC(), LPCTSTR(pStream->GetCacheFilename()) );

				#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
				ChDib* pDib = 0;
	
				pDib = new ChDib;
				ChDibDecoder dibDecoder( pDib );
				// Load the GIF file
				if ( !dibDecoder.Load( pStream->GetCacheFilename() ) )
				{
					delete pDib;
					pDib = 0;
				}
				else
				{
					pData = new ChRLImage( pDib, false, uOption );
					delete pDib;
					pDib = 0;
				}
				#endif

				break;
			}
			default :
			{				// this unknown type
				break;
			}
		}

		#if defined(CH_USE_3DR)
		// Decoding is expensive, check if the page is still valid
		if ( pDib )
		{
			if( pReq->GetPage() == pReq->GetView()->GetCurrentPage() )
			{
				if ( pData == 0 && pDib )
				{
					pData = pReq->GetView()->GetRenderContext()->LoadDIBTexture( pDib, luChromaClr, uOption );
				}
			}

			delete pDib;
		}
		#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		if ( pData )
		{
			if( pReq->GetPage() == pReq->GetView()->GetCurrentPage() )
			{
				pData->SetDestroyCallback( ChRLImageDestroyCallback, this );
				// Add it to our cache list
				ChRLImage** ppCache = m_imagCache.Find( pStream->GetURL() );

				if ( ppCache && *ppCache )
				{
					ASSERT( 0 );
				}

				m_imagCache.Insert( pStream->GetURL(), pData );
			}
			else
			{  	// We no longer need this
				pData->Release();
			}
			
		}
		#endif

		TRACE( "End decoding texture\n" );
	}

	// Leave the critical section
	UnlockDecode();

	if ( pData )
	{
		// load the texture
		pReq->SetTextureHandle( pData );
		if( !pReq->GetView()->PostMessage( WM_VRML_LOAD_TEXTURE, 0, (LPARAM)pReq ) )
		{
			delete pReq;
		}
		//pReq->Load(pStream->GetCacheFilename(), (void*)pData );
	}
	else
	{
		delete pReq;
	}

	// Update progress
	//pReq->GetView()->WriteStatus( PROGRESS_MSG_0 );


}
