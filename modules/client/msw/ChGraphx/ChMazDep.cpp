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

	Implementation for the dependency and Http request tracking for VRML..

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChMazDep.cpp,v 2.39 1996/07/02 19:41:22 pritham Exp $

#include "grheader.h"
//
#include <QvDB.h>
#include <QvInput.h>
#include <QvNode.h>
#include <QvState.h>
#include <QvChildList.h>
#if defined( CH_ARCH_16 )
#include <Texture2.h>
#else
#include <QvTexture2.h>
#endif

//#include <ChGIF.h>
//#include <ChJPEG.h>


#include <ChCore.h>
#include <ChUtil.h>
#include <ChHTTP.h>

#include "ChMaze.h"
#include "ChRenderData.h"
#include "ChMazDep.h"
#include "CvBound.h"
#include "CvQuery.h"
#include "ChRLImg.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

// Read in a VRML scene; traversal and storage is our responsibility.


ChMazeSceneHTTPReq::ChMazeSceneHTTPReq( ChGraphicView * pView,
										const string& strURL ) :
		ChGraphicSceneHTTPReq( pView, strURL ),
		m_pInfo( 0 )
{
}


ChMazeSceneHTTPReq::~ChMazeSceneHTTPReq()
{
}




#if 0
// Texture Request class
bool ChMazeTextureHTTPReq::Load(const string& strFilename, void *pTexture )
{
	// load the new texture, unless already there
	GetView()->SetupContexts();	// just in case we haven't drawn yet
	ChQvTextureRenderData* pRenderData = 
		(ChQvTextureRenderData*)(m_pTextureNode->GetRenderData());

	#if defined(CH_USE_3DR)	
	ChTextureHandle	hTexture = (ChTextureHandle)pTexture;
	#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	ChRLImage *hTexture = (ChRLImage *)pTexture;
	#endif

	if(!pRenderData->GetTextureHandle())
	{	
		if ( hTexture )
		{   // make sure we are setting the texture to the right scene
			GetView()->GetRenderContext()->LockScene();
			ChGraphicPageID pagID = GetView()->GetCurrentPage(); 

			if ( pagID == GetPage() )
			{
				pRenderData->
						LoadTexture( GetView()->GetRenderContext(), hTexture );
			}
			else
			{
				#if defined(CH_USE_3DR)	
					#pragma message("3DR textures leak")
				#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
					delete hTexture;
				#endif
			}

			GetView()->GetRenderContext()->UnlockScene();
		}
		else
		{
			TRACE( " We should not be coming here any more!!!\n" );
			ASSERT( 0 );
			#if 0
			switch ( GetTextureType() )
			{
				case ChHTTPConn::typeGIF:
				{
					// create the gif object
					ChGIF *pGIF = new ChGIF;
					// Load the GIF file
					pGIF->Load( strFilename, ChDib::load8Bit );

					chuint uOption = ChMazeTextureHTTPReq::textureAutoSize;

					if ( pGIF->IsTransperent() )
					{
					 	uOption |= ChMazeTextureHTTPReq::textureChromaKey;
					}

					pRenderData->
						LoadTexture( GetView()->GetRenderContext(), pGIF, 
										 				  pGIF->GetTransperentColor(), 
										 				  uOption );
					#if 0
					pRenderData->
						SetTextureHandle( GetView()->GetRenderContext()->LoadDIBTexture( pGIF, 
										 				  pGIF->GetTransperentColor(), 
										 				  uOption ));
					#endif

					delete pGIF;
					break;
				}
				case ChHTTPConn::typeJPEG:
				{
					// create the gif object
					ChJPEG *pJPEG = new ChJPEG;
					// Load the GIF file
					pJPEG->Load( strFilename, ChDib::load24Bit );

					chuint uOption = ChMazeTextureHTTPReq::textureAutoSize;

					pRenderData->
						LoadTexture( GetView()->GetRenderContext(), pJPEG, 
										 0, 
										 uOption );
					#if 0
					pRenderData->
						SetTextureHandle( GetView()->GetRenderContext()->LoadDIBTexture( pJPEG, 
										 0, 
										 uOption ));
					#endif

					delete pJPEG;
					break;
				}
				default :
				{				// this should be a BMP
							 // Load a texture node
#if defined(CH_USE_3DR)
					G3dHandle_t hGC = GetView()->GetGC(); 
				
					pRenderData->
						SetTextureHandle(G3dLoadTexture(hGC, LPCTSTR(strFilename)));
#else
					chuint uOption = ChMazeTextureHTTPReq::textureAutoSize;
					ChDib *pDib = new ChDib;
					// Load the GIF file
					pDib->Load( strFilename );
					pRenderData->
						LoadTexture( GetView()->GetRenderContext(), pDib, 
										 0, 
										 uOption );
					delete pDib;
#endif
					break;
				}
			}
			#endif // 0
		}

		if(pRenderData->GetTextureHandle())
		{
#if defined(CH_USE_3DR)
			pRenderData->SetRC( GetView()->GetRC());	   // save for destruct time
#endif
			GetView()->GetRenderContext()->SetDirty();
			GetView()->InvalidateRect(0, false);
			return true; 
		}
	}
	else
	{
		if ( hTexture )
		{
			#if defined(CH_USE_3DR)	
				#pragma message("3DR textures leak")
			#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
				delete hTexture;
			#endif
		}
	}
	return false; 

}

#endif //0

#if 0

// Inline Request class
bool ChMazeInlineHTTPReq::Load(string& strFilename, string& strURL, ChMazeMainInfo* pInfo)
{  
	bool boolSuccess = false;
	// save tree, and do traversal
	GetView()->SetupContexts();	// just in case we haven't drawn yet

	switch ( GetFileType() )
	{
		case ChHTTPConn::typeVRML:
		{
			

			HANDLE hFile = ::CreateFile(
							    strFilename,		// address of name of the file 
							    GENERIC_READ,	// access (read-write) mode 
							    FILE_SHARE_READ,// share mode 
							    NULL,			// address of security descriptor 
							    OPEN_EXISTING,	// how to create 
							    0,				// file attributes 
							    NULL			// handle of file with attributes to copy  
						   );
				   
			if ( hFile != INVALID_HANDLE_VALUE )
			{	// Do the init for this file
				QvDB::init();

				// Set the stream handle
			    ChQvFileMapInput	in;
				in.setFilePointer( hFile );

			    QvNode	*root = 0;

			    if (QvDB::read(&in, root) && root != 0)
				{
					boolSuccess = true;
					ChQvWWWInlineRenderData *pRenderData =  ((ChQvWWWInlineRenderData*)(m_pInlineNode->GetRenderData()));
					if(pRenderData->GetCurrentURL().IsEmpty())
					{
						// Attach to tree, and instantiate the new subtree
						m_pInlineNode->children->append(root);
						pRenderData->Instantiate(GetView(), root);
						pRenderData->SetURL(strURL);

						// Spawn for new requests
						ChQvSpawnState state(GetView(), strURL);
				    	root->traverse(&state);

						// Set it dirty, for redraw, etc.
						GetView()->GetRenderContext()->SetDirty();
						GetView()->InvalidateRect(0, false);
					}
					boolSuccess = true;
				}
			    else
			    {
					TRACE("Read was bad.\n");
					// Clean up on bad read
					if(root)
					{
						#if 0
						ChQvDeleteState	state(GetView());
						root->traverse(&state);
						delete root;
						#endif
						root->Release();
					}
			    }
				::CloseHandle( hFile );
			}
			break;
		}
		default: break;			// just fail
	}

	return boolSuccess; 
}

#endif // 0



