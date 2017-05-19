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

	Implementation for the ChRenderContext class for  Intel 3DR.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/Ch3Rendr.cpp,v 2.109 1996/09/26 02:06:59 pritham Exp $

#include "grheader.h"

#include <QvInfo.h>
#include <QvState.h>
#include "ChMaze.h"
#include "ChRenderData.h"
#include "ChMazDep.h"
#include "CvConvrt.h"
#include "CvTrnsfm.h"
#include "CvNormal.h"
#include "CvInstnc.h"
#include "CvTextur.h"
#include "CvType.h"
#include "CvHitTst.h"
#include "CvMaterl.h"
#include "ChSphere.h"
#include "ChRLImg.h"
#include <ChSFImage.h>
#include "ChCollision.h"

#if defined(CH_USE_D3D)
#include <d3d.h>
#endif

#include <malloc.h>
#if defined(WIN32)
#include <sys/timeb.h>
#endif

#include <ChCore.h>
#include <ChUtil.h>

// Even if we render purely retained, we need this if we use RL
#if (defined(CH_USE_RLAB))
#include "imode.h"
#endif

// Use our debugging allocator - caution do not use for production
// it's too slow and probably won't work for 2 dlls
//#define USE_OUR_RL_ALLOC	1
#define new DEBUG_NEW


#if (defined(CH_USE_RLAB))

const ChNrRenderQuality stdQuality = RenderGouraud ; // 	 // 	RLRenderPhong  
//const ChNrColorModel stdColorModel = RLColourRGB; //   RLColourRamp		
const ChNrColorModel stdColorModel = RLColourRamp; //   RLColourRGB	
	
#if defined(_DEBUG) && defined(USE_OUR_RL_ALLOC)
void* ChRLAlloc(size_t);           
void* ChRLRealloc(void*, size_t);   
void ChRLFree(void*);               

#endif // defined(_DEBUG) && defined(USE_OUR_RL_ALLOC)

#elif defined(CH_USE_D3D)

const ChNrRenderQuality stdQuality = RenderGouraud | D3DRMLIGHT_ON |  D3DRMFILL_SOLID; // 	 // 	RLRenderPhong  
//const ChNrColorModel stdColorModel = RLColourRGB; //   RLColourRamp		
//const ChNrColorModel stdColorModel = RLColourRamp; //   RLColourRGB		
#endif



class ChCameraEntry
{
	protected:
		string m_name;
		QvNode *m_pCamera;
		ChGraphicPageID m_page;

	public:
		ChCameraEntry(string name, QvNode *pCamera, ChGraphicPageID page) :
			m_name(name), m_pCamera(pCamera), m_page(page) {};

		string &GetName() {return m_name;};
		QvNode *GetCamera(){ return m_pCamera;};
};


ChRenderContext::ChRenderContext() : 
				#if defined(CH_USE_3DR)
				m_hGC(0), 
				m_numLightsOn(0),
				#else
				m_pStack(0),
				m_sceneFrame(0),
				m_cameraFrame(0),
				m_headlightFrame(0),
				m_viewport(0), 
				m_boolContinueConstruction( true ),
				m_pCollisionSensor(0),
				m_maxTransparency(false),
				m_pBackgroundTexture(0),
				m_pBackGroundNode(0),
				m_backgroundFrame(0),
				#endif
				#if defined(CH_USE_D3D)
				m_DD(0),
				m_D3D(0),
				m_D3DRM(0),
				m_DDClipper(0),
				#endif
				m_hRC(0), 
				m_hDC(0), 
				m_pWnd(0),
				m_userShading( defaultShading ), 
				m_pRootInstance(0),
				m_cameraCount(0),
				m_pCamera(0),
				m_pDefaultCamera(0),
				m_boolDirty(false),
				m_boolSettingsDirty(false),
				m_boolAnimating(false),
				m_ppDefaults(0),
				m_iShapeCount( 0 ),
				m_iFrameCount( 0 ),
				m_iTotalWork( 0 )

{
	for(int j=0; j<CH_MAX_SPHERE_LEVEL+1; j++)
	{
		m_pSpheres[j] = 0;
	}
	
	#if (defined(CH_USE_RLAB))

	#if defined(_DEBUG) && defined(USE_OUR_RL_ALLOC)
	RLSetAllocator(ChRLAlloc, ChRLRealloc, ChRLFree );
	#endif // defined(_DEBUG) && defined(USE_OUR_RL_ALLOC)
	#else
	m_boolThreaded = false;
	#endif

	m_boolThreaded = !!(ChUtil::GetSystemProperties() & CH_PROP_MULTITHREADED);
 
 	if(IsThreaded())
	{
		::InitializeCriticalSection(&m_sceneCriticalSection);
		::InitializeCriticalSection(&m_qvCriticalSection);
		::InitializeCriticalSection(&m_constructionCriticalSection);
		::InitializeCriticalSection(&m_reconstructionCriticalSection);
	
		// Reconstruction thread events	
		m_hReconstructEvents[reconstructInstance] = ::CreateEvent( 0, false, false, 0 );
		ASSERT( m_hReconstructEvents[reconstructInstance]  );

		m_hReconstructEvents[abortReconstruct] = ::CreateEvent( 0, false, false, 0 );
		ASSERT( m_hReconstructEvents[abortReconstruct] );

		m_hReconstructEvents[endThread] 		  = ::CreateEvent( 0, false, false, 0 );
		ASSERT( m_hReconstructEvents[endThread] );

		// Start the reconstruction thread
		CWinThread *pThread = ::AfxBeginThread(ReConstructInstanceThread, 
										(void*)this, THREAD_PRIORITY_BELOW_NORMAL ); 
		ASSERT( pThread );


		// end of construction event
		m_hConstructDoneEvent  = ::CreateEvent( 0, false, false, 0 );
		ASSERT( m_hConstructDoneEvent );
	}

}

#if defined(_DEBUG) && defined(USE_OUR_RL_ALLOC)
static int numRLAllocs = 0;
static int numRLBytes = 0;

void* ChRLAlloc(size_t size)
{

	numRLAllocs++;
	numRLBytes+=size;
	if(!(numRLAllocs % 100))
	{
		TRACE2("Number RL allocs: %d, bytes %d\n", numRLAllocs, numRLBytes);
	}
	char *bytes = new char[size+8];
	int *pSize = (int*)bytes;
	*pSize++ = 0xcacacaca;
	*pSize = size;
	return (bytes+8);
}
           
void* ChRLRealloc(void* ptr, size_t size)
{
	// Not optimal - just for debugging
	char *bytes = new char[size+8];
	int *pSize = (int*)bytes;
	*pSize++ = 0xcacacaca;
	*pSize = size;
	char *oldPtr = ((char*)ptr)-8;

	int *pTag = (int*)oldPtr;
	if(*pTag == 0xcacacaca)
	{
		if(bytes)
		{
			int oldSize = *(((int*)oldPtr)+1);
			memcpy(bytes + 8, oldPtr + 8, min(size_t(oldSize), size));
			numRLBytes+=size;
			numRLBytes-=oldSize;
		}
		delete [] oldPtr;
	}
	else
	{
		TRACE("Attempt to resize block that's not ours!\n");
	}
	return (bytes+8);
}

void ChRLFree(void* ptr)
{
	numRLAllocs--;

	char *oldPtr = ((char*)ptr)-8;
	int *pSize = (int*)oldPtr;
	int oldSize = pSize[1];
	if(*pSize == 0xcacacaca)
	{
		delete [] oldPtr;
		numRLBytes-=oldSize;
	}
}               

#endif // defined(_DEBUG) && defined(USE_OUR_RL_ALLOC)

ChRenderContext::~ChRenderContext()
{

	RemoveCameras();
	#if (defined(CH_USE_D3D) || defined(CH_USE_RLAB))
	// cleanup the synchronization objects
	if(IsThreaded())
	{
		::CloseHandle( m_hReconstructEvents[reconstructInstance] );
		::CloseHandle( m_hReconstructEvents[abortReconstruct] );
		::CloseHandle( m_hReconstructEvents[endThread] );

		::CloseHandle( m_hConstructDoneEvent);

		::DeleteCriticalSection(&m_sceneCriticalSection);
		::DeleteCriticalSection(&m_qvCriticalSection);
		::DeleteCriticalSection(&m_constructionCriticalSection);
		::DeleteCriticalSection(&m_reconstructionCriticalSection);
	}
	delete m_pCollisionSensor;	// delete the collision sensor viewport
	m_pCollisionSensor = 0;
	#endif

	if ( ChMazeWnd::GetNumMazeObjects() == 0 )
	{ // This is the last object, cleanup all static renderdata objects
		ChQvRenderBaseData::Term();
	}

	#if (defined(CH_USE_D3D))
	// Clean up interfaces
	RELEASE_INTERFACE(m_DDClipper);
	RELEASE_INTERFACE(m_D3DRM);
	RELEASE_INTERFACE(m_D3D);
	RELEASE_INTERFACE(m_DD);
	#endif
}

ChRenderContext*  ChRenderContext::SetRoot(ChQvInstance *pRootInstance)
{
	if(m_pRootInstance != pRootInstance && m_pRootInstance) m_pRootInstance->Release();
	m_pRootInstance = pRootInstance; 
	return this;
};

#if ((defined(CH_USE_RLAB)) || defined(CH_USE_D3D))

#if (defined(CH_USE_RLAB))
void CameraCallback(ChNrFrame frame, void * arg)
#else
void CameraCallback(ChNrFrame frame, void * arg, float delta)
#endif
{
#if 1
	//ASSERT(arg);
	if(arg)
	{
		QvNode *pCamera = ((ChRenderContext*)arg)->GetCurrentCamera();
		if(pCamera)
		{
			ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)(pCamera->GetRenderData());

			pRenderData->OnTick();
		}
	}
#endif
}
#endif


#if 0 && defined(_DEBUG)
int GetHeapDetails(HANDLE heap, int &numBlocks, int &numBytes)
{
	numBlocks = 0;
	numBytes = 0;
	PROCESS_HEAP_ENTRY entry;
	entry.lpData = 0;

	HeapLock(heap);
	while(HeapWalk(heap, &entry))
	{
		numBlocks ++;
		numBytes += entry.cbData;
		
	}
	HeapUnlock(heap);
	return numBlocks;
}
void CheckMemory()
{
	#if 0 && defined(_DEBUG)
	HANDLE heaps[200];
	int numHeaps = 	GetProcessHeaps( sizeof(heaps) / sizeof(heaps[0]), heaps);
	TRACE1("Number of heaps = %d\n", numHeaps);
	HANDLE sysHeap = GetProcessHeap();
	int numBytes, numBlocks;

	for(int j=0; j < numHeaps; j++)
	{
		GetHeapDetails(heaps[j], numBlocks, numBytes);
		TRACE2("Heap blocks = %d, bytes = %d", numBlocks, numBytes);
		if(heaps[j] == sysHeap) TRACE(" (process heap)");
		if(!HeapValidate(heaps[j], 0, 0)) TRACE(" INVALID HEAP!");
		TRACE("\n");
	}

	_HEAPINFO heapInfo;
	int heapRet;
	numBlocks = numBytes = 0;
	int numInUseBlocks = 0, numInUseBytes = 0;

	memset(&heapInfo, 0, sizeof(heapInfo));
	while((heapRet = _heapwalk( &heapInfo)) == _HEAPOK)
	{
		numBlocks ++;
		numBytes += heapInfo._size;
		if(heapInfo._useflag)
		{
			numInUseBlocks ++;
			numInUseBytes += heapInfo._size;
		}
	}				
	TRACE2("CRT Heap total blocks = %d, bytes = %d", numBlocks, numBytes);
	TRACE("\n");
	TRACE2("CRT Heap in use blocks = %d, bytes = %d", numInUseBlocks, numInUseBytes);
	TRACE("\n");
	if(heapRet != _HEAPEND) TRACE("CRT Heap invalid!\n");

	char *p = (char*)malloc(2);
	free(p);

	static int passCount = 0;
	static CMemoryState msLast;

	passCount++;
	if (passCount >= 3)
	{
	//AfxDumpMemoryLeaks();
		CMemoryState msNow;
		msNow.Checkpoint();

	if (msNow.m_lCounts[CMemoryState::objectBlock] != 0 ||
		msNow.m_lCounts[CMemoryState::bitBlock] != 0)
	{
		// dump objects since since difference detected.
		TRACE0("Detected memory growth!\n");
		afxDump.SetDepth(1);    // just 1 line each
		//CMemoryState msEmpty;   // construct empty memory state object
		msLast.DumpAllObjectsSince();
	}
	msLast.Checkpoint();


	}
	#endif
}
#else
#define CheckMemory()
#endif

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
void SceneDestroyCallback(ChNrObject obj, void * arg)
{
	//TRACE("Scene Destroyed\n");
}
void ViewportDestroyCallback(ChNrObject obj, void * arg)
{
	//TRACE("Viewport Destroyed\n");
}
void CameraDestroyCallback(ChNrObject obj, void * arg)
{
	//TRACE("Camera frame Destroyed\n");
}
#endif

ChRenderContext*  ChRenderContext::ResetScene()
{

	// Before we reset the scene we need to terminate all threads currently
	// running for this instance
	#if (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
	// Stop all currently active construction threads because we have a new scene
	AbortConstruction();
	
	// at this point there should be only one
	// thread running

	#endif
	
	CheckMemory();

	// remove all textures in our queue for this scene
	if ( !m_textureQueue.IsEmpty() ) 
	{
		ChPosition pos  = m_textureQueue.GetHeadPosition();

		while( pos )
		{
			ChMazeTextureHTTPReq* pReq  = m_textureQueue.GetNext( pos );
			#if defined(CH_USE_3DR)	
				#pragma message("3DR textures leak")
			#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
				//delete ((ChRLImage *)pReq->GetTextureHandle())->Release();
				if ( pReq->GetTextureHandle() )
				{
					((ChRLImage *)pReq->GetTextureHandle())->Release();
				}
			#endif
			delete pReq;
		
		}
		m_textureQueue.Empty();
	}

	
	SetRoot(0); 
	m_iShapeCount = 0; // This will be incremented by the construction thread
					  // when a shape is done
	m_iFrameCount = 0;	// frames displayed so far for this scene 

	RemoveCameras();
	RemoveLights();
	RemoveTimeSensors();
	Reset();

	#if (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
	m_dotsCache.Erase();	// We don't need to clear items, they
							// are freed when RLab deletes texture objects
	delete m_pCollisionSensor;	// delete the collision sensor viewport
	m_pCollisionSensor = 0;

	if(m_sceneFrame)
	{

	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

		RECT r;
	    int bpp;

		ChNrObjectDestroy(m_viewport); // viewport too
		ChNrObjectDestroy(m_sceneFrame); // whole scene and camera
		m_sceneFrame = 0;
		
		ChNrObjectDestroy(m_hRC); // whole device
	    GetWnd()->GetClientRect(&r);
	    m_hRC = CreateDevice(r.right, r.bottom);

		{
		    CDC *pdc = GetWnd()->GetDC();
		    bpp = pdc->GetDeviceCaps(BITSPIXEL);
			GetWnd()->ReleaseDC(pdc);
		}
	    if (bpp == 1)
	    {	
	    	ChNrDeviceSetShades(m_hRC, 4);
			ChNrSetDefaultTextureShades(4);
	    } else if (bpp == 16)
	    {	
	    	ChNrDeviceSetShades(m_hRC, 32);
			ChNrSetDefaultTextureColors(64);
			ChNrSetDefaultTextureShades(32);
			ChNrDeviceSetDither(m_hRC, FALSE);
	    } else if (bpp == 24)
	    {	
	    	ChNrDeviceSetShades(m_hRC, 256);
			ChNrSetDefaultTextureColors(64);
			ChNrSetDefaultTextureShades(256);
			ChNrDeviceSetDither(m_hRC, FALSE);
	    } else
		{
			ChNrSetDefaultTextureColors(16);  //32
			ChNrSetDefaultTextureShades(8);
			ChNrDeviceSetDither(m_hRC, TRUE);
		}
		
		UpdateOptimization();

	    m_sceneFrame	= CreateFrame(0);
		ChNrObjectAddDestroyCallback(m_sceneFrame, SceneDestroyCallback, this);
		//TRACE("Scene Created\n");


	    m_cameraFrame = CreateFrame(m_sceneFrame);
		ChNrFrameAddCallback(m_cameraFrame, CameraCallback, this);
		ChNrObjectAddDestroyCallback(m_cameraFrame, CameraDestroyCallback, this);
		//TRACE("Camera frame Created\n");

		D3DRelease(m_cameraFrame);

	    m_viewport =  CreateViewport( m_hRC, m_cameraFrame, 0, 0,  
								      ChNrDeviceGetWidth(m_hRC),   
								      ChNrDeviceGetHeight(m_hRC)   
								    );                               
		ChNrObjectAddDestroyCallback(m_viewport, ViewportDestroyCallback, this);
		//TRACE("Viewport Created\n");
			
	    ChNrViewportSetBack(m_viewport, ChNrVal(5000.0));
	
		ChNrFrameAddScale(m_sceneFrame, CombineReplace, 1., 1., -1.);

		#if (defined(CH_USE_RLAB))
		RLSceneSetBackground(m_sceneFrame, ((ChMazeWnd*)GetWnd())->GetBackgroundColorL());
		#elif (defined(CH_USE_D3D))

		unsigned long color = 	 ((ChMazeWnd*)GetWnd())->GetBackgroundColorL();
		SetBackgroundColor(color);
		#endif

		ClearTransformStack();

		#if 0  && defined(CH_USE_D3D)						   
			ChNrLight light1 = CreateLightRGB(ChNrLightAmbient, ChNrVal(0.5), ChNrVal(0.5), ChNrVal(0.5));
		    ChNrFrameAddLight(m_sceneFrame, light1);
			D3DRelease(light1);

			light1 = CreateLightRGB(ChNrLightDirectional, ChNrVal(0.5), ChNrVal(0.5), ChNrVal(0.5));
		    ChNrFrameAddLight(m_sceneFrame, light1);
			D3DRelease(light1);


		#endif


		ChNrViewportForceUpdate(m_viewport, 0, 0,
			    ChNrDeviceGetWidth(m_hRC),
			    ChNrDeviceGetHeight(m_hRC));
	   #else
			#pragma message(" resetscene not done!!")
	   #endif
	}

	#endif

	Animate();

	return this;
};

QvNode *ChRenderContext::GetCurrentProperty(ChQvState *pState, QvState::StackIndex index)
{
	QvNode *pNode = (QvNode *)(pState->GetTopNode(index));
	ASSERT(m_ppDefaults);
	if(!pNode) pNode = m_ppDefaults[index];
	return pNode;
}

ChQvSphereCacheData *ChRenderContext::GetSphere(int level)
{
	level = min(level, CH_MAX_SPHERE_LEVEL);
	level = max(level, CH_MIN_SPHERE_LEVEL);
	if(!m_pSpheres[level]) m_pSpheres[level] = new ChQvSphereCacheData(level);
	return m_pSpheres[level];
}

float ChRenderContext::GetQuality()
{
	float quality;
	if(((ChMazeWnd*)m_pWnd)->IsMoving())
	{
		quality =m_moveQuality;
	}
	else
	{      
		quality =m_standingQuality;  
	}
	return quality;
}

ChRenderContext *ChRenderContext::Reset()	
{							  // predraw reset rc

#if defined(CH_USE_3DR)
	m_numLightsOn = 0;
									// Turn off all light
	for (int j = 0; j < G3D_MAX_LIGHTS; j++)
	{
		G3dResetLight( GetGC(), j );
	}
	G3dSetActiveStack(GetGC(), G3DT_MODEL);
	G3dClearStack ( GetGC() );
	G3dSetActiveStack(GetGC(), G3DT_CAM_CLIP);
	G3dClearStack ( GetGC() );
	G3dSetActiveStack(GetGC(), G3DT_MODEL);
#else
// TODO figure out if this is needed; probably not
//#pragma message("ChRenderContext::Reset() Not done!")
#endif

	return this;
}

//ChRenderContext *ChRenderContext::Draw()
bool ChRenderContext::Draw()
{
	Reset();
	#if defined(CH_USE_3DR)
	if(!IsDirty())
	{
		if ( m_textureQueue.GetCount() )
		{
			ProcessTextureQueue();
		}
		return false;
	}

	// Set up camera
	ChQvState state((ChMazeWnd*)GetWnd());
	m_pCamera->traverse(&state);

	// Turn on lights
	TraverseLights();

	// Traverse the instance tree, drawing the shapes
	ChDrawIterator drawIt(this);

	drawIt.Attach(m_pRootInstance);
	drawIt.Iterate();

	m_iFrameCount++;

	SetDirty(false);
	#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)

	// Do a tick of the simulation; this might dirty us
	TickSensors();

	if(!IsDirty())
	{
		if ( m_textureQueue.GetCount() )
		{
			ProcessTextureQueue();
		}
		return false;
	}

	((ChMazeWnd*)GetWnd())->StartFrameTime();

	// Set the total work done to zero so that we can do reconstruction before the
	// next draw
	m_iTotalWork = 0;

	// Lock the scene and don't be nice
	LockScene();
	
	//TRACE("Drawing the tree - it's dirty.\n");
	{
		#if defined(CH_VRML_PLUGIN )
		AdjustHeadlight(  );
		if ( NumPendingConstructionThreads() && !((ChMazeWnd*)GetWnd())->IsMoving() )
		{  // if the construction is still in progress, update the whole view
			ForceUpdate();
		} 
		#endif

		#if 0
		if(((ChMazeWnd*)GetWnd())->IsMoving())
		{
			//ChNrDeviceSetQuality(m_hRC, RLRenderFlat);
		}
		else
		{
			ChNrDeviceSetQuality(m_hRC, stdQuality);
		}
		//ChNrDeviceSetQuality(m_hRC, RLRenderGouraud);
		#endif

		SetDirty(false);
		UpdateOptimization();

		#if 1 && defined(CH_IMMED_MODE)
		// This is a hack because it seems the dither setting gets messed up
		// in immediate mode - maybe the viewport keeps its own?
		// who knows? This makes it works anyways.
	    int old_dither = ChNrDeviceGetDither(m_hRC);
		ChNrDeviceSetDither(m_hRC, old_dither);
		// end hacked bug work-around

		ChNrViewportForceUpdate
		(   m_viewport,
		    ChNrViewportGetX(m_viewport),
		    ChNrViewportGetY(m_viewport),
		    ChNrViewportGetWidth(m_viewport),
		    ChNrViewportGetHeight(m_viewport)
		);
		#endif

		ChNrFrameMove(m_sceneFrame, 1);
		//DoBackground();
		ChNrViewportClear(m_viewport);
		ChNrViewportRender(m_viewport, m_sceneFrame);

		#if defined(CH_IMMED_MODE)

		// Traverse the instance tree, drawing the shapes
		// in immmediate mode
		ChDrawIterator drawIt(this);

		drawIt.Attach(m_pRootInstance);
		drawIt.Iterate();

		#endif

		ChNrDeviceUpdate(m_hRC);

		m_iFrameCount++;
	}

	UnlockScene();

	#else
	#endif

	if ( m_textureQueue.GetCount() )
	{
		ProcessTextureQueue();
	}

	return true;
}

void ChRenderContext::ProcessTextureQueue()
{	// process only one request at a time

	ChMazeTextureHTTPReq* pReq = m_textureQueue.RemoveHead();

	if( pReq->GetPage() == ((ChMazeWnd*)GetWnd())->GetCurrentPage() )
	{
		TRACE( "ProcessTextureQueue :: Using texture %s\n", LPCSTR(pReq->GetURL()));

		ChQvTextureRenderData* pRenderData = 
			(ChQvTextureRenderData*)(pReq->GetTextureNode()->GetRenderData());


		if( pReq->GetTextureNode()->GetUsage() > 1 
				&& !pRenderData->GetTextureHandle() )
		{

			#if defined(CH_USE_3DR)	
			ChTextureHandle	hTexture = (ChTextureHandle)pReq->GetTextureHandle();
			#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
			ChRLImage *hTexture = (ChRLImage *)pReq->GetTextureHandle();
			#endif

			pRenderData->LoadTexture( this, hTexture );
			SetDirty( true );

		}
		else
		{
			#if defined(CH_USE_3DR)	
				#pragma message("3DR textures leak")
			#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
				//delete ((ChRLImage *)pReq->GetTextureHandle());
				TRACE( "ProcessTextureQueue ::Texture not used\n" );
				((ChRLImage *)pReq->GetTextureHandle())->Release();
			#endif
		}
	}
	else if( pReq->GetTextureHandle() )
	{
		#if defined(CH_USE_3DR)	
			#pragma message("3DR textures leak")
		#elif defined(CH_USE_RLAB)
			//delete ((ChRLImage *)pReq->GetTextureHandle());
			((ChRLImage *)pReq->GetTextureHandle())->Release();
		#endif
	}

	delete pReq;
}

#if (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
bool ChRenderContext::DoBackground()
{
	#if 0	// dead code??
	if(m_sceneFrame)
	{
		if(!m_pBackgroundTexture)
		{
			// make it
			DWORD width  = 1;
			#if defined(CH_USE_D3D)
			while(width <= (m_hRC->GetWidth())) width *= 2;
			#else
			while(width <= ChNrDeviceGetWidth(m_hRC)) width *= 2;
			#endif
			width /= 4;
			DWORD height  = 1;
			while(height <= ChNrDeviceGetHeight(m_hRC)) height *= 2;
			height /= 4;
		    m_pBackgroundTexture = new ChTexture(width, height, ChColor(200,0,0), true);
			RLSceneSetBackgroundImage(m_sceneFrame, m_pBackgroundTexture->GetHandle());
		}
		else
		{
			// say it changed
			ChNrTextureChanged(  m_pBackgroundTexture->GetHandle(), 1, 0);
		}
	}
	#endif
	return true;
}
#endif

#if (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
ChRenderContext *ChRenderContext::ForceUpdate()
{
	if(m_sceneFrame && m_viewport)
	{
		ChNrViewportForceUpdate(m_viewport, 0, 0,
		    ChNrDeviceGetWidth(m_hRC),
		    ChNrDeviceGetHeight(m_hRC));
	}
	return this;
}
#endif


void ChRenderContext::TraverseLights()
{
#if defined(CH_USE_3DR)
	ChQvLightInstance *pInstance;
	ChPosition pos = m_lights.GetHeadPosition();
    while (pos) {
        pInstance = m_lights.GetNext(pos);
		pInstance->traverse(this);
    }
#else
	// unnecessary
#endif
}

ChRenderContext *ChRenderContext::SetTexture(ChTextureHandle hTex)
{
#if defined(CH_USE_3DR)
	Fixed32_t On = 1;
	Fixed32_t Off = 0;
	if(hTex)
	{
		R3dSetState( m_hRC, R3D_STA_ENABLES, R3D_SE_TEXTURING);
		R3dSetState( m_hRC, R3D_STA_TEX_ID, (Dword_t)(hTex));
		// Modulation depends on material; we either multply or don't modulate at all
		// We will turn on/off later face-by-face based on emissiveity
		R3dSetState( m_hRC, R3D_STA_ENABLES, R3D_SE_MODULATION);	
		G3dSetState( m_hGC, G3DL_TEXTURE_MOD, &On);
		// Note: Alternative functions are to  R3D_TF_MULTIPLY, R3D_TF_REDUCE or R3D_TF_SHADE;
		R3dSetState( m_hRC, R3D_STA_TEX_FUNCTION, R3D_TF_MULTIPLY);  
		//R3dSetState( m_hRC, R3D_STA_TEX_FUNCTION, R3D_TF_SHADE);  
	}
	else
	{
		R3dSetState( m_hRC, R3D_STA_DISABLES, R3D_SE_TEXTURING);
		R3dSetState( m_hRC, R3D_STA_TEX_ID, (Dword_t)(0));
		R3dSetState( m_hRC, R3D_STA_DISABLES, R3D_SE_MODULATION);	
		G3dSetState( m_hGC, G3DL_TEXTURE_MOD, &Off);
		R3dSetState( m_hRC, R3D_STA_TEX_FUNCTION, R3D_TF_MULTIPLY);  
		//R3dSetState( m_hRC, R3D_STA_TEX_FUNCTION, R3D_TF_SHADE);  
	}
#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
// not needed
#else
#pragma message("SetTexture not done!")
#endif
	return this;
}

ChTextureHandle ChRenderContext::GetTexture()
{
#if defined(CH_USE_3DR)
	if(m_hRC)
		return R3dGetState( m_hRC, R3D_STA_TEX_ID);
	else
#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
// not needed
#else
#pragma message("SetTexture not done!")
#endif
		return (0);
}

#if defined(CH_USE_3DR)
ChTextureHandle ChRenderContext::LoadDIBTexture( /*ChMazeMainInfo* pInfo,*/  ChDib *pDibIn, 
												chuint32 luChromaClr, chuint uOption )
{
	R3dHandle_t hRC =  GetRC();
	int iWidth = 1;
	int iHeight = 1;

	// power of 2
	while( (iWidth * 2) <= pDibIn->GetWidth() )
	{
		iWidth *= 2;
	}
	while( (iHeight * 2) <= pDibIn->GetHeight() )
	{
		iHeight *= 2;
	}

	if ( ((ChMazeWnd*)GetWnd())->GetSettings()->GetScaleTextures() )
	{ // Limit to 128
		if ( iWidth > 128 )
		{
			iWidth = 128;
		}
		if ( iHeight > 128 )
		{
			iHeight = 128;
		}

	}
	else
	{
		if ( uOption & ChMazeTextureHTTPReq::textureAutoSize )
		{  // auto will always increase the size if it is less than 256
			if ( iWidth != pDibIn->GetWidth() 
								&& (iWidth * 2) <= 256 )
			{
				iWidth *= 2;
			}

			if ( iHeight != pDibIn->GetHeight() 
								&& (iHeight * 2) <= 256  )
			{
				iHeight *= 2;
			}
		}
		else if ( uOption & ChMazeTextureHTTPReq::textureExpand )
		{
			if ( iWidth != pDibIn->GetWidth() )
			{
				iWidth *= 2;
			}

			if ( iHeight != pDibIn->GetHeight() )
			{
				iHeight *= 2;
			}
		}
	}

	// shrink or expand if required
	if ( (iWidth != pDibIn->GetWidth() || iHeight != pDibIn->GetHeight())
		  &&  ( uOption & ChMazeTextureHTTPReq::textureShrink 
		  		||  uOption & ChMazeTextureHTTPReq::textureExpand )
		  		|| ( uOption & ChMazeTextureHTTPReq::textureAutoSize ) )
	{
		// size the DIB
		pDibIn->SetSize( iWidth, iHeight );
	}
	

	// Create new texture 
	Dword_t textureHandle = R3dNewTexture( hRC, R3D_TI_MIPMAP, 32, iWidth, iHeight );

	if ( textureHandle )
	{
		LPBITMAPINFO pBmpInfo = pDibIn->GetBitmapInfoAddress();
		RGBQUAD*	pRgbQuad = pDibIn->GetClrTabAddress();
		BYTE*		pBits = (BYTE*)pDibIn->GetBitsAddress();
		LPByte_t 	pTexBuffer = new Byte_t[ iWidth * 4 ];
		Word_t		texInfo;

		if (  uOption & ChMazeTextureHTTPReq::textureChromaKey )
		{
			//texInfo = R3D_TI_CHROMAKEY;
			texInfo = R3D_TI_DEFAULT;		   // jwd
		}
		else
		{
			texInfo = R3D_TI_DEFAULT;
			luChromaClr = 0;
		}

		
		for( int i = iHeight - 1; i >= 0; i-- )
		{  // the scan lines in a DIB are stored in reverse order
		  	LPByte_t pTmpTex = pTexBuffer;

			// Load the RGB quad in RGBA format
			for ( int j = 0; j < iWidth; j++ )
			{
				if ( pBmpInfo->bmiHeader.biBitCount == 24 )
				{
					int iOffset = j*3;
					*pTmpTex++ = pBits[2 + iOffset ];
					*pTmpTex++ = pBits[1 + iOffset ];
					*pTmpTex++ = pBits[0 + iOffset ];
				}
				else
				{
					*pTmpTex++ = pRgbQuad[ pBits[j] ].rgbRed;
					*pTmpTex++ = pRgbQuad[ pBits[j] ].rgbGreen;
					*pTmpTex++ = pRgbQuad[ pBits[j] ].rgbBlue;
				}
				Byte_t alpha = 0xFF;
				if (  uOption & ChMazeTextureHTTPReq::textureChromaKey )
				{
					Byte_t red = LOBYTE(luChromaClr);
					Byte_t green = HIBYTE(LOWORD(luChromaClr));
					Byte_t blue = LOBYTE(HIWORD(luChromaClr));

					if(*(pTmpTex-3) == red && *(pTmpTex-2) == green && *(pTmpTex-1) == blue)
					{
						alpha = 0;
					}
				}
				*pTmpTex++ = alpha;

			}
			// Go to the next row
			if ( pBmpInfo->bmiHeader.biBitCount == 24 )
			{
	    		pBits += (((pDibIn->GetWidth() * 3 ) + 3) & ~3);
			}
			else
			{
				pBits += (( pDibIn->GetWidth() + 3) & ~3);
			}

			// Load the texture row into 3dr
			R3dLoadTexture( hRC, 
							texInfo,		// texture info
							32,				// bits per pixel
							0,				// mip level
							iWidth,			// width of the texture
							i,				// row being set
							0,				// set this to zero for row at a time
							textureHandle,	// R3dNewTexture return value
							//luChromaClr,	// chromacode or alpha key if any
							0,	// chromacode or alpha key if any
							pTexBuffer );	// the real data
		}

		// we are done, do the cleanup
		delete []pTexBuffer;

	}

	
	return textureHandle;
}
#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
// don't need for RLAB - see ChRLImage instead
#else
#pragma message("ChRenderContext::LoadDIBTexture() Not done!")
#endif


// Stack Manipulators for QV traversals. For 3dr, use 3dr's stack; for others, use ours
ChRenderContext * ChRenderContext::ClearTransformStack()
{
#if defined(CH_USE_3DR)
	G3dSetActiveStack(GetGC(), G3DT_MODEL);
	G3dClearStack( GetGC() );
#else
	while(m_pStack && !m_pStack->IsEmpty())
	{
		m_pStack->RemoveHead();
	}
	PushTransform();

#endif
	return this;
};

ChRenderContext * ChRenderContext::ComposeTransform(GxTransform3Wf& transform)	// apply to object end
{
#if defined(CH_USE_3DR)
	G3dSetActiveStack(GetGC(), G3DT_MODEL);
	G3dPostMultTransform(GetGC(), *(transform.GetMatrix()));  
#else
	ASSERT(m_pStack);

	GxTransform3Wf& top = m_pStack->GetHead();
	//top = transform.Compose(top);		  // this could be faster if we had compose in place for transforms 
	top = transform * top;		  // this is one copy faster, i think

#endif
	return this;
};

ChRenderContext * ChRenderContext::PopTransform()
{
#if defined(CH_USE_3DR)
	G3dSetActiveStack(GetGC(), G3DT_MODEL);
	G3dPopTransform( GetGC() );
#else
	ASSERT(m_pStack);
	m_pStack->RemoveHead();
#endif
	return this;
};

ChRenderContext * ChRenderContext::PopTransform(GxTransform3Wf& transform)
{
#if defined(CH_USE_3DR)
	// need to fetch and convert it first
	GxTransformF_t mat;

  	G3dSetActiveStack(GetGC(), G3DT_MODEL);
	G3dGetTransform(GetGC(), mat);
	transform = GxTransform3Wf(mat);
	G3dPopTransform( GetGC() );
#else
	ASSERT(m_pStack);
	transform = 	m_pStack->RemoveHead();
#endif
	return this;
};

ChRenderContext * ChRenderContext::PushTransform()
{
#if defined(CH_USE_3DR)
	G3dSetActiveStack(GetGC(), G3DT_MODEL);
	G3dPushTransform( GetGC() );
#else

	GxTransform3Wf top;
	ASSERT(m_pStack);
	if(!m_pStack->IsEmpty()) top = m_pStack->GetHead();
	m_pStack->AddHead(top);

#endif
	return this;
};

GxTransform3Wf ChRenderContext::GetModelTransform()	// Renderer's current Model to world 
{
	#if defined(CH_USE_3DR)
	GxTransformF_t mat;

  	G3dSetActiveStack(GetGC(), G3DT_MODEL);
	G3dGetTransform(GetGC(), mat);
	return GxTransform3Wf(mat);
	#else
	ASSERT(m_pStack);
	GxTransform3Wf& top = m_pStack->GetHead();
	return top;
	#endif
}

ChRenderContext *ChRenderContext::SetModelTransform(GxTransform3Wf& transform)  
{
	#if defined(CH_USE_3DR)
  	G3dSetActiveStack(GetGC(), G3DT_MODEL);
	G3dSetTransform(GetGC(), *(transform.GetMatrix()));			 //(float(*)[4])
	#else
	ASSERT(m_pStack);

	GxTransform3Wf& top = m_pStack->GetHead();
	top = transform;
	#endif
	return this;
}

// End transform stack methods

void ChRenderContext::Init(ChViewBaseClass *pWnd, CDC* pDC)
{
	#if defined(CH_USE_3DR)
	{
		if(!m_hRC)
		{
			m_hRC = R3dCreateRC((DWORD)(pDC->GetSafeHdc()), R3D_RI_DOUBLE_BUFFER /*R3D_RI_DEFAULT*/); 	
			m_hGC = G3dCreateGC( m_hRC);
			m_hDC = pDC->GetSafeHdc();
			m_pWnd = pWnd;
		}
	
		// Reset quality while moving to highest / 2 - range is 0 to 1.00
		m_moveQuality = .50;
		m_standingQuality = 1.0;


		// Reset states
	    int dithering = !!(R3dGetState( m_hRC, R3D_STA_ENABLES) & R3D_SE_DITHERING);
		int numColors = pDC->GetDeviceCaps(NUMCOLORS);
		if(numColors > 256 || numColors < 0)
		{
	    	R3dSetState( m_hRC, R3D_STA_DISABLES, R3D_SE_DITHERING);
		}
	    R3dSetState( m_hRC, R3D_STA_ENABLES, R3D_SE_SHADING);
	    R3dSetState( m_hRC, R3D_STA_ENABLES, R3D_SE_Z_BUFFERING);
	    R3dSetState( m_hRC, R3D_STA_DISABLES, R3D_SE_CLIPPING);
	}
	#elif (defined(CH_USE_RLAB))
	{
	    RECT r;
	    int bpp;

		if(!m_hRC)
		{
			m_hDC = pDC->GetSafeHdc();
			m_pWnd = pWnd;
		    GetWnd()->GetClientRect(&r);

		    m_hRC = RLWinCreateDevice(GetWnd()->GetSafeHwnd(), NULL, r.right, r.bottom);

			{
			    CDC *pdc = GetWnd()->GetDC();
			    bpp = pdc->GetDeviceCaps(BITSPIXEL);
				GetWnd()->ReleaseDC(pdc);
			}
		    if (bpp == 1)
		    {	
		    	ChNrDeviceSetShades(m_hRC, 4);
				ChNrSetDefaultTextureShades(4);
		    } else if (bpp == 16)
		    {	
		    	ChNrDeviceSetShades(m_hRC, 32);
				ChNrSetDefaultTextureColors(64);
				ChNrSetDefaultTextureShades(32);
				ChNrDeviceSetDither(m_hRC, FALSE);
		    } else if (bpp == 24)
		    {	
		    	ChNrDeviceSetShades(m_hRC, 256);
				ChNrSetDefaultTextureColors(64);
				ChNrSetDefaultTextureShades(256);
				ChNrDeviceSetDither(m_hRC, FALSE);
		    } else
				//ChNrDeviceSetDither(m_hRC, FALSE);
				ChNrDeviceSetDither(m_hRC, TRUE);

		    #if (defined(CH_USE_RLAB))
			// This is implicit in the driver in d3d
		    ChNrDeviceSetColorModel(m_hRC, stdColorModel);  // ??????????
			#endif

			ChNrDeviceSetQuality(m_hRC, stdQuality);

		    m_sceneFrame	= CreateFrame(NULL);
			ChNrObjectAddDestroyCallback(m_sceneFrame, SceneDestroyCallback, this);
			//TRACE("Scene Created\n");


		    m_cameraFrame = CreateFrame(m_sceneFrame);
			 ChNrFrameAddCallback(m_cameraFrame, CameraCallback, this);
			ChNrObjectAddDestroyCallback(m_cameraFrame, CameraDestroyCallback, this);
			//TRACE("Camera frame Created\n");

			D3DRelease(m_cameraFrame);

		    m_viewport = CreateViewport(	m_hRC, m_cameraFrame, 0, 0,
										    ChNrDeviceGetWidth(m_hRC),
										    ChNrDeviceGetHeight(m_hRC)
										);
			ChNrObjectAddDestroyCallback(m_viewport, ViewportDestroyCallback, this);
			//TRACE("Viewport Created\n");

		    ChNrViewportSetBack(m_viewport, 5000.0);

			// Change both scene and camera frames to RHS - camera is a child of scene
			ChNrFrameAddScale(m_sceneFrame, CombineBefore, 1., 1., -1.);

			#if (defined(CH_USE_RLAB))
			RLSceneSetBackground(m_sceneFrame, ((ChMazeWnd*)GetWnd())->GetBackgroundColorL());
			#else
			SetBackgroundColor((ChMazeWnd*)GetWnd())->GetBackgroundColorL());
			#endif

			m_pStack = new	ChTransformStack;
			ClearTransformStack();
		}
	}
	#else	 //d3d
	{
		#if 1
	    RECT r;
	    int bpp;

		if(!m_hRC)
		{
			m_hDC = pDC->GetSafeHdc();
			m_pWnd = pWnd;
		    GetWnd()->GetClientRect(&r);

        	/*
		     * Create the DD object
		     */
		    HRESULT rval = DirectDrawCreate( NULL, &m_DD, NULL );

		    if (rval != D3DRM_OK) {
		        //Msg("Failed to create Direct3DRM.\n%s", D3DRMErrorToString(rval));
				// NEED TO THROW AN EXCEPTION HERE!
		        return;
		    }

			m_DD->SetCooperativeLevel(pWnd->GetSafeHwnd(), DDSCL_NORMAL);

			// We might need a DD2 object too, but query for it if we do

        	/*
		     * Create the D3D object
		     */
		    rval = m_DD->QueryInterface(IID_IDirect3D, (void **)&m_D3D);
		    if (rval != D3DRM_OK) {
		        //Msg("Failed to create Direct3DRM.\n%s", D3DRMErrorToString(rval));
				// NEED TO THROW AN EXCEPTION HERE!
		        return;
		    }

        	/*
		     * Create the D3DRM object; wonderfully consistent, eh?
		     */
		    rval = Direct3DRMCreate(&m_D3DRM);
		    if (rval != D3DRM_OK) {
		        //Msg("Failed to create Direct3DRM.\n%s", D3DRMErrorToString(rval));
				// NEED TO THROW AN EXCEPTION HERE!
		        return;
		    }
			/*
		     * Create a clipper and associate the window with it
		     */
		    rval = DirectDrawCreateClipper(0, &m_DDClipper, NULL);
		    if (rval != DD_OK) {
		        //Msg("Failed to create DirectDrawClipper");
				// NEED TO THROW AN EXCEPTION HERE!
		        return;
		    }
		    rval = m_DDClipper->SetHWnd(0, GetWnd()->GetSafeHwnd());
		    if (rval != DD_OK) {
		        //Msg("Failed to set hwnd on the clipper");
				// NEED TO THROW AN EXCEPTION HERE!
		        return;
		    }


		    m_hRC = CreateDevice(r.right, r.bottom);

			{
			    CDC *pdc = GetWnd()->GetDC();
			    bpp = pdc->GetDeviceCaps(BITSPIXEL);
				GetWnd()->ReleaseDC(pdc);
			}
		    if (bpp == 1)
		    {	
		    	ChNrDeviceSetShades(m_hRC, 4);
				m_D3DRM->SetDefaultTextureShades(4);
		    } else if (bpp == 16)
		    {	
		    	ChNrDeviceSetShades(m_hRC, 32);
				m_D3DRM->SetDefaultTextureColors(64);
				m_D3DRM->SetDefaultTextureShades(32);
				ChNrDeviceSetDither(m_hRC, FALSE);
		    } else if (bpp == 24)
		    {	
		    	ChNrDeviceSetShades(m_hRC, 256);
				m_D3DRM->SetDefaultTextureColors(64);
				m_D3DRM->SetDefaultTextureShades(256);
				ChNrDeviceSetDither(m_hRC, FALSE);
		    } else
				ChNrDeviceSetDither(m_hRC, TRUE);

			ChNrDeviceSetQuality(m_hRC, stdQuality);

		    m_sceneFrame	= CreateFrame(NULL);
			ChNrObjectAddDestroyCallback(m_sceneFrame, SceneDestroyCallback, this);
			//TRACE("Scene Created\n");

		    m_cameraFrame = CreateFrame(m_sceneFrame);
			ChNrFrameAddCallback(m_cameraFrame, CameraCallback, this);
			ChNrObjectAddDestroyCallback(m_cameraFrame, CameraDestroyCallback, this);
			//TRACE("Camera frame Created\n");

			D3DRelease(m_cameraFrame);

		    m_viewport = CreateViewport(	m_hRC, m_cameraFrame, 0, 0,
										    ChNrDeviceGetWidth(m_hRC),
										    ChNrDeviceGetHeight(m_hRC)
										);
			ChNrObjectAddDestroyCallback(m_viewport, ViewportDestroyCallback, this);
			//TRACE("Viewport Created\n");
	
		    ChNrViewportSetBack(m_viewport, 5000.0);

			// Change both scene and camera frames to RHS - camera is a child of scene
			ChNrFrameAddScale(m_sceneFrame, CombineBefore, 1., 1., -1.);

			#if (defined(CH_USE_RLAB))
			RLSceneSetBackground(m_sceneFrame, ((ChMazeWnd*)GetWnd())->GetBackgroundColorL());
			#else
			SetBackgroundColor(((ChMazeWnd*)GetWnd())->GetBackgroundColorL());
			#endif

			m_pStack = new	ChTransformStack;
			ClearTransformStack();
			#if 0
			{
			    ChNrMesh      egg_mesh;
			    ChNrFrame     egg;

			    egg_mesh = CreateMesh();
			    
				if(egg_mesh)
				{
				    rval = egg_mesh->Load("egg.x", NULL, D3DRMLOAD_FROMFILE, NULL, NULL);

					/*
					 * create an egg frame within the scene
					 */
				    egg = CreateFrame(m_sceneFrame);

					/*
					 * add the loaded mesh into the frame
					 */
				    if(egg)
				    {	
				    	rval = egg->AddVisual(egg_mesh);
						egg->Release();
					}
					egg_mesh->Release();
				}
			}
			#endif

		}
		#endif
	}
	#endif


	SetTexture(0);

	m_ppDefaults = new QvNode* [QvState::NumStacks];
	for(int j=0; j<	QvState::NumStacks; j++) m_ppDefaults[j] = 0;

	// We don't set defaults for cameras, and lights
	m_ppDefaults[QvState::BaseColorIndex	       		] =   new QvBaseColor; 
	m_ppDefaults[QvState::Coordinate3Index       		] =   new QvCoordinate3; 
	m_ppDefaults[QvState::FontStyleIndex         		] =   new QvFontStyle;
	m_ppDefaults[QvState::InfoIndex         	 		] =   new QvInfo;
	m_ppDefaults[QvState::MaterialBindingIndex   		] =   new QvMaterialBinding; 
	m_ppDefaults[QvState::MaterialIndex          		] =   new QvMaterial;  
	m_ppDefaults[QvState::NormalBindingIndex     		] =   new QvNormalBinding;   
	m_ppDefaults[QvState::NormalIndex            		] =   new QvNormal;
	m_ppDefaults[QvState::ShapeHintsIndex        		] =   new QvShapeHints;
	m_ppDefaults[QvState::Texture2Index          		] =   new QvTexture2;  
	m_ppDefaults[QvState::Texture2TransformationIndex 	] =   new QvTexture2Transform;
	m_ppDefaults[QvState::TextureCoordinate2Index		] =   new QvTextureCoordinate2;
	//		 transforms are different, but we need one identity instance handy
	m_ppDefaults[QvState::TransformationIndex			] =   new QvScale;

	ChQvBuildState state((ChMazeWnd*)GetWnd());

	// traverse once to init; this guarantees renderdata is newed
	m_ppDefaults[QvState::BaseColorIndex	       		]->traverse(&state);
	m_ppDefaults[QvState::Coordinate3Index       		]->traverse(&state);
	m_ppDefaults[QvState::FontStyleIndex         		]->traverse(&state);
	m_ppDefaults[QvState::InfoIndex         	 		]->traverse(&state);
	m_ppDefaults[QvState::MaterialBindingIndex   		]->traverse(&state);
	m_ppDefaults[QvState::MaterialIndex          		]->traverse(&state);
	m_ppDefaults[QvState::NormalBindingIndex     		]->traverse(&state);
	m_ppDefaults[QvState::NormalIndex            		]->traverse(&state);
	m_ppDefaults[QvState::ShapeHintsIndex        		]->traverse(&state);
	m_ppDefaults[QvState::Texture2Index          		]->traverse(&state);
	m_ppDefaults[QvState::Texture2TransformationIndex 	]->traverse(&state);
	m_ppDefaults[QvState::TextureCoordinate2Index		]->traverse(&state);
	m_ppDefaults[QvState::TransformationIndex			]->traverse(&state);

}

void ChRenderContext::AbortConstruction()
{
	// Stop all construction threads currently
	// running for this instance
	#if (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
	if ( IsThreaded() )
	{
		// cancel all threads, currently running
		m_boolContinueConstruction = false;
		// Tell the reconstruction thread to abort all requests and clean up the queue

		// Abort all reconstruction requests
		::ResetEvent( GetEndConstructEvent() );
		::SetEvent( m_hReconstructEvents[abortReconstruct] );

		DWORD dwStatus;
	   	// Wait till reconstruction thread says we are OK to proceed
		dwStatus = ::WaitForSingleObject( GetEndConstructEvent(), INFINITE );
		ASSERT( dwStatus == WAIT_OBJECT_0 );
	
		TRACE1( "AbortConstruction : Threads running before abort : %d\n", NumPendingConstructionThreads() );

		while( NumPendingConstructionThreads() )
		{  // There is a thread curently running, block on the end thread event

			dwStatus = ::WaitForSingleObject( GetEndConstructEvent(), INFINITE );

			ASSERT( dwStatus == WAIT_OBJECT_0 );
		}

		// We can start construction of scenes again
		m_boolContinueConstruction = true;
		TRACE1( "AbortConstruction : Threads running after abort : %d\n", NumPendingConstructionThreads() ); 
		ASSERT( NumPendingConstructionThreads() == 0 );
	}
	#endif
}


void ChRenderContext::Term()
{

	#if defined(CH_USE_3DR)
	if(m_hGC) G3dDeleteGC(m_hGC);
	if(m_hRC) R3dDeleteRC(m_hRC);
	m_hGC = 0;
	m_hRC = 0;
	#else

	// Terminate the reconstruction thread
	if ( IsThreaded() )
	{
		// Abort all reconstruction requests
		::SetEvent( m_hReconstructEvents[endThread] );

		DWORD dwStatus;
	   	// Wait till reconstruction thread says we are OK to proceed
		dwStatus = ::WaitForSingleObject( GetEndConstructEvent(), INFINITE );
		ASSERT( dwStatus == WAIT_OBJECT_0 );
		
	}

	delete m_pDefaultCamera;

	ChNrObjectDestroy(m_hRC);
	ChNrObjectDestroy(m_sceneFrame);
	m_hRC 			= 0;
	m_sceneFrame 	= 0;
	m_cameraFrame 	= 0;
	m_viewport 		= 0;
	#endif

	// Moved from destructor to Term by VSP : This was required to
	// Plug leaks in QV.
	if(m_ppDefaults)
	{
		for(int j=0; j<	QvState::NumStacks; j++)
		{
			delete m_ppDefaults[j];
			m_ppDefaults[j] = 0;
		}
	}
	delete m_ppDefaults;
	m_ppDefaults = 0;
	if(m_pRootInstance) m_pRootInstance->Release();
	//delete m_pRootInstance;
	m_pRootInstance = 0;
	for(int j=0; j<CH_MAX_SPHERE_LEVEL+1; j++)
	{
		delete m_pSpheres[j];
		m_pSpheres[j] = 0;
	}
	#if defined(CH_USE_3DR)
	#else
	delete m_pStack;
	m_pStack = 0;
	#endif

}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
void ChRenderContext::Resize( int width, int height, bool boolForceNew )
{
	if(m_hRC)
	{
		LockScene();
		if(width == 0 || width == 0)
		{
		    RECT r;
		    GetWnd()->GetClientRect(&r);
			if(!width) width = r.right;
			if(!height) height = r.bottom;
		}

	    int dev_width = ChNrDeviceGetWidth(m_hRC);
	    int dev_height = ChNrDeviceGetHeight(m_hRC);
	    ChNrValue front = ChNrViewportGetFront(m_viewport);
	    ChNrValue back = ChNrViewportGetBack(m_viewport);
	    ChNrValue field = ChNrViewportGetField(m_viewport);

	    ChNrObjectDestroy(m_viewport);

	    /*
	     * if requesting a device of zero dimensions, actually make the device
	     * slightly larger, as a device of width or height zero is no device at
	     * all, and it causes many problems
	     */

	    if (!width) {
			width = 10;
	    }
	    if (!height) {
			height = 10;
	    }

	    if (boolForceNew || (width > dev_width || height > dev_height))
	    {	
		    int old_dither = ChNrDeviceGetDither(m_hRC);
			ChNrRenderQuality old_quality = ChNrDeviceGetQuality(m_hRC);
			ChNrColorModel old_model = ChNrDeviceGetColorModel(m_hRC);
			int old_shades = ChNrDeviceGetShades(m_hRC);

			#if 0
			// We don't use any right now
			RLDestroyCallback* fns;
			void** args;
			int c, count;

			RLObjectGetDestroyCallbacks(m_hRC, &count, &fns, &args);

			for (c = 0; c < count; c++) {
			    RLObjectRemoveDestroyCallback(m_hRC, fns[c], args[c]);
			}
			#endif

			ChNrObjectDestroy(m_hRC);
			m_hRC = CreateDevice(width, height);

			#if 0
			for (c = 0; c < count; c++) {
			    ChNrObjectAddDestroyCallback(m_hRC, fns[c], args[c]);
			}

			RLFree(fns);
			RLFree(args);
			#endif

			ChNrDeviceSetDither(m_hRC, old_dither);
			ChNrDeviceSetQuality(m_hRC, old_quality);
			#if (defined(CH_USE_RLAB))
			// Just for RL, implicit in device in d3d
			ChNrDeviceSetColorModel(m_hRC, old_model);
			#endif
			ChNrDeviceSetShades(m_hRC, old_shades);
	    }
	    m_viewport = CreateViewport(m_hRC, m_cameraFrame, 0, 0, width, height);
		ChNrObjectAddDestroyCallback(m_viewport, ViewportDestroyCallback, this);
		//TRACE("Viewport Created\n");

	    ChNrViewportSetBack(m_viewport, back);
	    ChNrViewportSetFront(m_viewport, front);
	    ChNrViewportSetField(m_viewport, field);

		if(m_pBackGroundNode)
		{
			ChQvBackgroundInfoData *pData = (ChQvBackgroundInfoData *)(m_pBackGroundNode->GetRenderData());
			pData->OnResize(this);
		}

		if(GetCurrentCamera())((ChQvPCameraRenderData*)(GetCurrentCamera()->GetRenderData()))->SynchCamera();

		SetDirty();

		UnlockScene();
	}
}
#endif

void ChRenderContext::SetModulation(bool boolUseTexture /*= true*/, bool boolPureEmissive)
{
	#if defined(CH_USE_3DR)
	Fixed32_t On = 1;
	Fixed32_t Off = 0;
	if(boolUseTexture && boolPureEmissive)
	{	
		// turn off texture modulation - it paints black
		R3dSetState( m_hRC, R3D_STA_DISABLES, R3D_SE_MODULATION);	
		G3dSetState( m_hGC, G3DL_TEXTURE_MOD, &Off);
	}
	else if(boolUseTexture && (R3dGetState( m_hRC, R3D_STA_ENABLES) & R3D_SE_SHADING))
	{
		// Normal case for diffuse or specular faces - must be smooth shaded to work
		// in 3dr. 
		R3dSetState( m_hRC, R3D_STA_ENABLES, R3D_SE_MODULATION);	
		G3dSetState( m_hGC, G3DL_TEXTURE_MOD, &On);
	}
	else if(boolUseTexture)
 	{	
		// turn off texture modulation -  no smoothing 
		R3dSetState( m_hRC, R3D_STA_DISABLES, R3D_SE_MODULATION);	
		G3dSetState( m_hGC, G3DL_TEXTURE_MOD, &Off);
	}
	// else texturing is off, so don't care
	#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
	// not needed
	#else
	#pragma message("ChRenderContext::SetModulation() Not done!")
	#endif
}


// Set shading according to user preferences and traversal state

ChRenderContext* ChRenderContext::SetShading( ChQvShapeInstance *pInstance )
{
	#if defined(CH_USE_3DR)
	ChShadingLevel	stateShading = defaultShading;
	ChShadingLevel	resultShading;
	int permute[5];

	permute[int(smoothShading)] = 0;
	permute[int(flatShading)] = 1;
	permute[int(noShading)] = 2;
	permute[int(defaultShading)] = 3;
	permute[int(wireFrame)] = 4;
											// Indexing is [user][state]
	static ChShadingLevel aShadingTbl[5][5] =
	{
		// user == smoothShading
		{ smoothShading, flatShading, noShading, smoothShading, noShading },
		// user == flatShading
		{ flatShading, flatShading, noShading, flatShading, noShading },
		// user == none
		{ noShading, noShading, noShading, noShading, noShading },
		// user == defaultShading
		{ smoothShading, flatShading, noShading, defaultShading, noShading },
		// user == wireframe
		{ noShading, noShading, noShading, noShading, noShading }
	};

	// Get Stack top and get the shading value, if any
	// Right now the node only pushes shading nodes, so we don't have to walk down
	QvInfo *pInfoNode = 0;
	if(pInstance) pInfoNode = pInstance->GetInfo();
	if(pInfoNode && pInfoNode->GetRenderData())
	{
		stateShading = ((ChQvInfoRenderData	*)(pInfoNode->GetRenderData()))->GetShading();
	}

	// Make sure values are in range - Help stamp out wild pointers
	int i = int(m_userShading);	if(i>sizeof(permute)/sizeof(permute[0]) || i<0) i = defaultShading;
	int j = int(stateShading);	if(j>sizeof(permute)/sizeof(permute[0]) || j<0) j = defaultShading;
	
	// Lookup in table
	resultShading = aShadingTbl[permute[i]][permute[j]];

	// Set it into the renderer's context
	Fixed32_t On = 1;
	Fixed32_t Off = 0;

    if (resultShading == flatShading)
    {
        R3dSetState( GetRC(), R3D_STA_DISABLES, R3D_SE_SHADING);
        //G3dSetState( GetGC(), G3DL_FLAT_SHADING, &On);
	}
	else if (resultShading == noShading)
	{
        R3dSetState( GetRC(), R3D_STA_DISABLES, R3D_SE_SHADING);
        //G3dSetState( GetGC(), G3DL_FLAT_SHADING, &On);
	}
	else if (resultShading == smoothShading)
	{
    	R3dSetState( GetRC(), R3D_STA_ENABLES, R3D_SE_SHADING); 
        //G3dSetState( GetGC(), G3DL_FLAT_SHADING, &Off);
	}
	else   // default to smoothShading
	{
    	R3dSetState( GetRC(), R3D_STA_ENABLES, R3D_SE_SHADING );
        //G3dSetState( GetGC(), G3DL_FLAT_SHADING, &Off);
	}
	#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
	// not needed
	#else
	#pragma message("ChRenderContext::SetShading() Not done!")
	#endif
	return this;
}


#if defined(CH_USE_3DR)
// Private helper function for RebuildTransformStack
int ChRenderContext::ApplyQvTail( QvElement *elt)
{
	int tailDepth = 0;
	TransformF_t eltMat;
	G3dSetActiveStack(m_hGC, G3DT_MODEL);

	if(elt->next)
	{
		tailDepth = ApplyQvTail( elt->next );
	}
	if( tailDepth < elt->depth || elt->type == QvElement::NoOpTransform)
	{
		G3dPushTransform(m_hGC);
	}
	if(GetTransform( elt, eltMat))
	{
		G3dPostMultTransform(m_hGC, eltMat);
	}
	return elt->depth;
}

void ChRenderContext::RebuildTransformStack(ChQvState *pState)
{
	// recurse down the qv stack, applying each matrix, and pushing the geometry engine stack
	// each time the element depth changes, or a nooptransform is encountered. (Noop transforms are
	// used by TransformSeparator::traverse as markers)
	QvElement *	top = pState->getTopElement(QvState::TransformationIndex);
	
	G3dSetActiveStack(GetGC(), G3DT_MODEL);
	if(top) ApplyQvTail( top );
 
}
#else
	// not used by other renderer's implementations
#endif

Ch3DViewerMode ChRenderContext::GetViewerMode()
{
	Ch3DViewerMode	mode = ((ChMazeWnd*)GetWnd())->GetSceneViewerMode();
	Ch3DViewerMode	prefMode = ((ChMazeWnd*)GetWnd())->GetSettings()->GetViewerMode();

	#if 0
	if(mode == none || ((ChMazeWnd*)GetWnd())->GetSettings()->GetOverrideSceneMode())
	{
		mode = prefMode;
	}
	#endif
	return prefMode;
}

ChQvTransformationInstance *ChRenderContext::GetDefaultTransform()
{
	ChQvRenderBaseData *pData = (ChQvRenderBaseData *)(m_ppDefaults[QvState::TransformationIndex]->GetRenderData());
	return (ChQvTransformationInstance *)(pData->m_instances.GetHead());
}

ChRenderContext* ChRenderContext::AddCamera(QvNode *pCamera, string &strName)
{
	if(!strName.IsEmpty())
	{
		ChCameraEntry *pEntry = new ChCameraEntry(strName, pCamera, 
			((ChMazeWnd*)GetWnd())-> GetCurrentPage());
		m_cameras.AddTail(pEntry);
		m_cameraCount++;
	}
	return this;
}

ChRenderContext* ChRenderContext::RemoveCamera(string &strName)
{
	if(!strName.IsEmpty() && !m_cameras.IsEmpty())
	{
		ChPosition pos = m_cameras.GetHeadPosition();
		while(pos)
		{
			ChPosition thisPos = pos;
			ChCameraEntry *pEntry = m_cameras.GetNext(pos);
			if(pEntry && strName == pEntry->GetName())
			{
				m_cameras.Remove(thisPos);
				delete pEntry;
				break;
			}
		}
		//m_cameras.Delete(strName);
		m_cameraCount--;
	}
	return this;
}

ChRenderContext* ChRenderContext::RemoveCameras()
{
	while(!m_cameras.IsEmpty())
	{
		ChCameraEntry *pEntry = m_cameras.RemoveHead();
		delete pEntry;
	}
	m_cameraCount = 0;
	return this;
}

//////////////// ChCameraIterator - only non-trivial method ////////////
// We put it here because of similarity to RC camera stuff

bool ChCameraIterator::Iterate()
{
	if(!m_pRC) return false;

	bool boolContinue = true;
	if(!m_pRC->m_cameras.IsEmpty())
	{
		ChPosition pos = m_pRC->m_cameras.GetHeadPosition();
		while(pos && boolContinue)
		{
			ChCameraEntry *pEntry = m_pRC->m_cameras.GetNext(pos);
			boolContinue = DoCamera(pEntry->GetName(), pEntry->GetCamera());
		}
	}
	return boolContinue;
}

ChCameraIterator* ChCameraIterator::Attach(ChMazeWnd *pWnd)
{
	m_pRC = pWnd->GetRenderContext();
	return this;
};


//////// back to RC methods

bool ChRenderContext::GetCamera(int i, string &strName, QvNode **ppCamera)
{
	bool	boolFound = false;
	if(!m_cameras.IsEmpty())
	{
		ChPosition pos = m_cameras.FindIndex(i);
		if(pos)
		{
			ChCameraEntry *pEntry = m_cameras.Get(pos);
			strName = pEntry->GetName();
			if(ppCamera) *ppCamera = pEntry->GetCamera();
			boolFound = true;
		}
	}
	return boolFound;
}

ChRenderContext *ChRenderContext::NewDefaultCamera()
{
	bool boolCurrentIsDefault = (m_pDefaultCamera == m_pCamera);
	delete m_pDefaultCamera;
	m_pDefaultCamera = new QvPerspectiveCamera;
	// traverse the camera so we get a renderdata set up
	 ChQvBuildState bldIt(((ChMazeWnd*)GetWnd()));
	 m_pDefaultCamera->traverse(&bldIt);

	if(boolCurrentIsDefault) SetCurrentCamera();
	return this;
}

ChRenderContext *ChRenderContext::SetCurrentCamera(QvNode *pCamera)
{
	if(!pCamera) pCamera = m_pDefaultCamera;
	m_pCamera = pCamera;
	#if (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
	((ChQvPCameraRenderData*)(m_pCamera->GetRenderData()))->Select();
	#endif
	((ChMazeWnd*)GetWnd())->OnCameraChange(ChMazeWnd::cameraSelected);

	return this;
}

ChRenderContext *ChRenderContext::SelectCamera(int iCamIndex)
{
	string strName;
	QvNode *pCamera	= 0;

	if(!GetCamera(iCamIndex, strName, &pCamera))
	{
		pCamera = 0;	
	}
	SetCurrentCamera(pCamera);

	return this;
}

#if	0 && ((defined(CH_USE_RLAB)) || defined(CH_USE_D3D))
ChRenderContext *ChRenderContext::SetCameraLoc(GxVec3f &cameraLoc)
{
	m_cameraLoc = cameraLoc;
	return this;
};
#endif
#if	(defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
GxVec3f ChRenderContext::GetCameraLoc()
{	
	GxVec3f	  cameraLoc;
	QvNode *pCamera = GetCurrentCamera();
	ChQvPCameraRenderData *pData;
	if(pCamera)
	{
		pData = (ChQvPCameraRenderData*)(pCamera->GetRenderData());
		cameraLoc = pData->GetLoc();	
	}

	return cameraLoc;
}
GxVec3f ChRenderContext::GetCameraUp()
{	
	GxVec3f	  cameraUp;
	QvNode *pCamera = GetCurrentCamera();
	ChQvPCameraRenderData *pData;
	if(pCamera)
	{
		pData = (ChQvPCameraRenderData*)(pCamera->GetRenderData());
		cameraUp = pData->GetUp();	
	}

	return cameraUp;
}
GxVec3f ChRenderContext::GetCameraDir()
{	
	GxVec3f	  cameraDir;
	QvNode *pCamera = GetCurrentCamera();
	ChQvPCameraRenderData *pData;
	if(pCamera)
	{
		pData = (ChQvPCameraRenderData*)(pCamera->GetRenderData());
		cameraDir = pData->GetDir();	
	}

	return cameraDir;
}
#endif

int ChRenderContext::GetCameraIndex()
{	
	// Get index of current camera in camera list; -1 if no list
	int 	  index = -1;
	QvNode *pCamera = GetCurrentCamera();
	if(pCamera && !m_cameras.IsEmpty())
	{
		ChPosition pos = m_cameras.GetHeadPosition();
		int i = 0;
		while(pos)
		{
			ChPosition thisPos = pos;
			ChCameraEntry *pEntry = m_cameras.GetNext(pos);
			if(pEntry && pCamera == pEntry->GetCamera())
			{
				index = i;
				break;
			}
			i++;
		}
	}

	return index;
}

GxTransform3Wf ChRenderContext::GetWorldToCameraTransform()
{
	ChQvPCameraRenderData *pData = (ChQvPCameraRenderData*)(GetCurrentCamera()->GetRenderData());
	return pData->GetTransform();	//   use camera matrix
}

GxTransform3Wf ChRenderContext::GetClipToScreenTransform()
{
	// Use the camera port settings - 
	GxTransform3Wf mat;
	float  left, right, top, bottom;
 	ChQvPCameraRenderData *pData = (ChQvPCameraRenderData*)(GetCurrentCamera()->GetRenderData());

	pData->GetPort(left, right, top, bottom);
	// translation
	(*(mat.GetMatrix()))[0][3] = (right - left)	/ 2.;
	//(*(mat.GetMatrix()))[1][3] = (top - bottom) / 2.;
	(*(mat.GetMatrix()))[1][3] = (top - bottom) / 2.;
	(*(mat.GetMatrix()))[2][3] = 0;

	// scaling
	(*(mat.GetMatrix()))[0][0] = (right - left)	/ 2.;		 
	//(*(mat.GetMatrix()))[1][1] = (top - bottom) / 2.;
	(*(mat.GetMatrix()))[1][1] = -(top - bottom) / 2.;
	(*(mat.GetMatrix()))[2][2] = 1.;
	(*(mat.GetMatrix()))[3][3] = 1;

	return (mat);
}

GxTransform3Wf ChRenderContext::GetCameraToClipTransform()
{

 	ChQvPCameraRenderData *pData = (ChQvPCameraRenderData*)(GetCurrentCamera()->GetRenderData());
	GxTransform3Wf camClipTransform = pData->GetClipTransform();
	return (camClipTransform);
}

#if defined(CH_USE_3DR)
ChRenderContext* ChRenderContext::Add(ChQvLightInstance *pLightInst)
{
	m_lights.AddTail(pLightInst);
	return this;
}

ChRenderContext* ChRenderContext::Remove(ChQvLightInstance *pLightInst)
{
	if(m_lights.IsEmpty()) return this;
	ChPosition pos = m_lights.Find(pLightInst);
	if(pos)
	{
		m_lights.Remove(pos);
	}
	delete pLightInst;
	return (this);
}

#else
// These functions aren't used for RealityLab
#endif

ChRenderContext* ChRenderContext::RemoveLights()
{
#if defined(CH_USE_3DR)
	if(m_lights.IsEmpty()) return this;
	ChQvLightInstance *pLightInst;
	while(!m_lights.IsEmpty())
	{
		pLightInst = m_lights.RemoveHead();
		delete pLightInst;
	}
#else
// This function is unnecessary for RealityLab
#endif

	return (this);
}

// 
float ChRenderContext::GetAdjustedLODRange(float range)
{
	#if !((defined(CH_USE_RLAB))  || defined(CH_USE_D3D))
	if(((ChMazeWnd*)m_pWnd)->IsMoving())
	{
		range *= 10;
	}
	#endif
	return range;
}

// Return the angle subtended by one pixel vertically at the center of the screen
float ChRenderContext::GetPixelAngle()
{
	ChQvPCameraRenderData * pCamData = (ChQvPCameraRenderData *)(m_pCamera->GetRenderData());
	float angle;
	if(pCamData->IsPerspective())
	{
		QvPerspectiveCamera * pCamera = (QvPerspectiveCamera *)m_pCamera;
		float left, right, top, bottom;
		pCamData->GetPort( left, right, top, bottom);
		float heightAngle = pCamera->heightAngle.value;

		// abs(bottom - top) == heightAngle
		angle = fabs(heightAngle / (top - bottom));	  // small angle approximation
	}
	else
	{
		angle = 1.;
	} 
	return angle;
}
#if (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
bool ChRenderContext::IsAnchor( int iX, int iY, pChQvAnchorSensor &pAnchor )
{
	bool boolIsAnchor = false;
	#if 1 || (defined(CH_USE_RLAB))
	pAnchor = 0;
	GxVec3f clickPoint;	   
	ChQvInstance *pAnchorInst = 0;
	bool boolIsRetained = false;

	if(m_viewport)
	{

		// Lock the scene and don't be nice
		LockScene();
		
		#if (defined(CH_USE_RLAB))

		ChNrFrame frame;

		ChNrFrame retainedFrame = 0;	 // closest retained hit, anchor or not
		GxVec3f	retainedPoint;
		ChNrFaceInfo *pFaceInfo;
		int count;
		if(ChNrViewportFindFaces( m_viewport, &count, &pFaceInfo, iX, iY) != RLNotFound && count > 0)
		{
			const float zEpsilon = .01;

			float zLimit = pFaceInfo[0].position.z * (1. + zEpsilon);
			// Hit -something-. Is it an anchor? First remember so we can compare to 
			// immed mode hit if any
			retainedPoint= *(GxVec3f*)&(pFaceInfo[0].position);
			retainedFrame =  pFaceInfo[0].frame;

			// Now check for anchorness
			for(int j = 0; j < count && pFaceInfo[0].position.z <= zLimit && !boolIsAnchor; j++)
			{
				frame = pFaceInfo[j].frame;
				ChQvInstance *pInst = (ChQvInstance *)RLObjectGetAppData(frame);
				while(pInst)
				{
					string strType;
					if(pInst->GetNode()->GetType(strType) == typeQvWWWAnchor)
					{
						boolIsAnchor = true;
						pAnchorInst = pInst;
						clickPoint = *(GxVec3f*)&(pFaceInfo[j].position);

						boolIsRetained = true;
						pInst = 0;
					}
					else
					{
						pInst = pInst->GetParent();
					}
				}
			}
		}
		// Check for immed mode
		{
			ChHittestIterator	iterator(this, iX, iY);
			iterator.Attach(GetRoot());
			iterator.Iterate();

			ChQvInstance *pInst;
			GxVec3f pt;

			if(iterator.GetHit(pInst, pt))
			{
				ChNrFrame	hitFrame = pInst->GetFrame();
				bool boolIsClosest = true;
				if(retainedFrame)
				{
					// Note this bit of code is only executed if 
					// we have both a retained mode object and an immediate
					// mode object under the cursor
					RLIMViewVertex ptInScreen;
		
					#if 0
					RLIMTransformVertices
				    (   GetViewport(), 
				    	retainedFrame,
				        (RLIMPositionVector*)&(retainedPoint),
				        &ptInScreen,
				        sizeof(RLIMPositionVector), 
				        sizeof(RLIMViewVertex),
				        1,
				        1
				    );
					#endif
					float retainedZ = retainedPoint.z();

					RLIMTransformVertices
				    (   GetViewport(), 
				    	hitFrame,
				        (RLIMPositionVector*)&(pt),
				        &ptInScreen,
				        sizeof(RLIMPositionVector), 
				        sizeof(RLIMViewVertex),
				        1,
				        1
				    );
					float immedZ = ptInScreen.sz;

					boolIsClosest = immedZ < retainedZ;
				}
				if(boolIsClosest)
				{

					while(pInst)
					{
						string strType;
						if(pInst->GetNode()->GetType(strType) == typeQvWWWAnchor)
						{
							boolIsAnchor = true;
							pAnchorInst = pInst;
							clickPoint = pt;
							frame = hitFrame;
							pInst = 0;
							boolIsRetained = false;
						}
						else
						{
							pInst = pInst->GetParent();
						}
					}
				}
			}

		}
		// Finish up
		if(pAnchorInst)
		{
			pAnchor = ((ChQvWWWAnchorInstance*)pAnchorInst)->GetSensor();
			
			if(((ChQvWWWAnchorInstance*)pAnchorInst)->IsPointMap())
			{
				if(boolIsRetained)
				{
					RLVector4d screenCoord;
					screenCoord.x = clickPoint.x();
					screenCoord.y = clickPoint.y();
					screenCoord.z = clickPoint.z();
					screenCoord.w = 1;
					RLVector tmp;
					ChNrViewportInverseTransform(m_viewport, &tmp, &screenCoord);
					ChNrFrameInverseTransform(frame, (RLVector*)&clickPoint, &tmp);
				}


				pAnchor->SetHitPoint(clickPoint);
			}
		}
		#else
		//#pragma message("D3D anchor testing not done")
		ChNrFrame frame;

		ChNrFrame retainedFrame = 0;	 // closest retained hit, anchor or not
		GxVec3f	retainedPoint;
		//ChNrFaceInfo *pFaceInfo;

	    LPDIRECT3DRMVISUAL visual;
	    LPDIRECT3DRMFRAME pickFrame;
	    LPDIRECT3DRMPICKEDARRAY picked = 0;
	    LPDIRECT3DRMFRAMEARRAY frames;
	    LPDIRECT3DRMMESHBUILDER mesh;
	    LPDIRECT3DRMTEXTURE decal;
		D3DRMPICKDESC 	pickInfo;

		HRESULT rval = m_viewport->Pick(iX, iY, &picked);
		int count = picked ? picked->GetSize() : 0;
		float z = 0;
		if(count > 0)
		{
            picked->GetPick(0, &visual, &frames, &pickInfo);
            frames->GetElement(frames->GetSize() - 1, &pickFrame);

            if (SUCCEEDED(visual->QueryInterface(IID_IDirect3DRMMeshBuilder, (void **) &mesh)))
            {   
                mesh->Release();
				z = pickInfo.vPosition.z;
            }
            else if (SUCCEEDED(visual->QueryInterface(IID_IDirect3DRMTexture, (void **) &decal)))
            {   
                decal->Release();
				z = pickInfo.vPosition.z;
            }

            pickFrame->Release();
            frames->Release();
            visual->Release();

			const float zEpsilon = .01;

			float zLimit = z * (1. + zEpsilon);
			// Hit -something-. Is it an anchor? First remember so we can compare to 
			// immed mode hit if any
			retainedPoint= *(GxVec3f*)&(pickInfo.vPosition);
			retainedFrame =  pickFrame;

			// Now check for anchorness
			
			for(int j = 0; j < count && !boolIsAnchor; j++)
			{
				bool boolCheckit = false;
			    picked->GetPick(j, &visual, &frames, &pickInfo);
	            frames->GetElement(frames->GetSize() - 1, &pickFrame);

	            if (SUCCEEDED(visual->QueryInterface(IID_IDirect3DRMMeshBuilder, (void **) &mesh)))
	            {   
	                mesh->Release();
					z = pickInfo.vPosition.z;
					boolCheckit = true;
	            }
	            else if (SUCCEEDED(visual->QueryInterface(IID_IDirect3DRMTexture, (void **) &decal)))
	            {   
	                decal->Release();
					z = pickInfo.vPosition.z;
					boolCheckit = true;
	            }

	            pickFrame->Release();
	            frames->Release();
	            visual->Release();

				if(z > zLimit) break;

				if(boolCheckit)
				{
					frame = pickFrame;
					ChQvInstance *pInst = (ChQvInstance *)(frame->GetAppData());
					while(pInst)
					{
						string strType;
						if(pInst->GetNode()->GetType(strType) == typeQvWWWAnchor)
						{
							boolIsAnchor = true;
							pAnchorInst = pInst;
							clickPoint = *(GxVec3f*)&(pickInfo.vPosition);

							boolIsRetained = true;
							pInst = 0;
						}
						else
						{
							pInst = pInst->GetParent();
						}
					}
				}
			}
		}
        	picked->Release();

		// Finish up
		if(pAnchorInst)
		{
			pAnchor = ((ChQvWWWAnchorInstance*)pAnchorInst)->GetSensor();
			
			if(((ChQvWWWAnchorInstance*)pAnchorInst)->IsPointMap())
			{
				if(boolIsRetained)
				{
					ChNrVector4d screenCoord;
					screenCoord.x = clickPoint.x();
					screenCoord.y = clickPoint.y();
					screenCoord.z = clickPoint.z();
					screenCoord.w = 1;
					ChNrVector tmp;
					ChNrViewportInverseTransform(m_viewport, &tmp, &screenCoord);
					ChNrFrameInverseTransform(frame, (ChNrVector*)&clickPoint, &tmp);
				}


				pAnchor->SetHitPoint(clickPoint);
			}
		}
		#endif

		#if 0
		RLVisual visual;
		if(ChNrViewportFindVisual( m_viewport, &visual, &frame, iX, iY) != RLNotFound)
		{
			// Hit -something-. Is it an anchor?
			ChQvInstance *pInst = (ChQvInstance *)RLObjectGetAppData(frame);
			while(pInst)
			{
				string strType;
				if(pInst->GetNode()->GetType(strType) == typeQvWWWAnchor)
				{
					boolIsAnchor = true;
					pAnchor = ((ChQvWWWAnchorInstance*)pInst)->GetSensor();
					if(((ChQvWWWAnchorInstance*)pInst)->IsPointMap())
					{
						GxVec3f clickPoint;
						ChNrFaceInfo faceInfo;
						if((ChNrViewportFindFace( m_viewport, &faceInfo, iX, iY) != RLNotFound)
									&& faceInfo.frame == frame)
						{
							clickPoint = *(GxVec3f*)&faceInfo.position;
							RLVector4d screenCoord;
							screenCoord.x = clickPoint.x();
							screenCoord.y = clickPoint.y();
							screenCoord.z = clickPoint.z();
							screenCoord.w = 1;
							RLVector tmp;
							ChNrViewportInverseTransform(m_viewport, &tmp, &screenCoord);
							ChNrFrameInverseTransform(frame, (RLVector*)&clickPoint, &tmp);
						}
						else
						{
							// It's not a face visual, must be a decal
							ChNrFrameGetPosition(frame, ChNrFrameGetParent(frame), (RLVector*)&clickPoint);
						}

						pAnchor->SetHitPoint(clickPoint);
					}
					pInst = 0;
				}
				else
				{
					pInst = pInst->GetParent();
				}
			}
		}
		#endif
		UnlockScene();

	}
	#endif // turn off for d3d
	return boolIsAnchor;
}
#endif

#if (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
void ChRenderContext::LockScene( ) 
{
	if(IsThreaded()) 
	{
		::EnterCriticalSection(&m_sceneCriticalSection);
	}
}

void ChRenderContext::UnlockScene()
{
	if(IsThreaded()) 
	{
		::LeaveCriticalSection(&m_sceneCriticalSection);
	}
}

void ChRenderContext::LockConstruction( ) 
{
	if(IsThreaded()) 
	{
		::EnterCriticalSection(&m_constructionCriticalSection);
	}
}

void ChRenderContext::UnlockConstruction()
{
	if(IsThreaded()) 
	{
		::LeaveCriticalSection(&m_constructionCriticalSection);
	}
}

#endif

void ChRenderContext::LockQv( ) 
{
	if(IsThreaded()) 
	{
		::EnterCriticalSection(&m_qvCriticalSection);
	}
}

void ChRenderContext::UnlockQv()
{
	if(IsThreaded()) 
	{
		::LeaveCriticalSection(&m_qvCriticalSection);
	}
}

bool ChRenderContext::ProcessEvent(ChEventMsg *pEventMsg)
{
#if defined(CH_VRML_EVENTS)
	bool boolOK = true;

	ChNode *pNode = pEventMsg->GetNode();
	ChApplet *pApplet = pEventMsg->GetApplet();
	ChIVrmlEvent *pEvent = pEventMsg->GetEvent();

	ChQvRenderBaseData *pData = (ChQvRenderBaseData *)(((QvNode*)pNode)->GetRenderData());
	if(pData)
	{
		while(pEvent)
		{

				pData->DispatchEvent(this, pApplet, pEvent);

			ChIVrmlEvent *pNextEvent = pEvent->GetNextEvent();

			LockQv();	// 4/30/96 to prevent races during construction
			delete pEvent;
			UnlockQv();
			pEvent = pNextEvent;
		}
	}
	else
	{
		boolOK = false;
	}

	delete pEventMsg;
	LockQv();		   // Lock tree so parse and stream threads don't barf
	((QvNode*)pNode)->Release();	// undo of use before posting by Interpreter
	UnlockQv();
	SetDirty();
	return boolOK;
#else
	return false;
#endif
}

#if (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
#if (defined(CH_USE_RLAB))
void BackgroundCallback(ChNrFrame frame, void * arg)
#else
void BackgroundCallback(ChNrFrame frame, void * arg, float delta)
#endif
{
	ASSERT(arg);
	((ChRenderContext*)arg)->MoveBackgroundImage();
}

void BackgroundDestroyCallback(ChNrObject obj, void * arg)
{
	((ChRenderContext*)arg)->OnDestroyBackground();
}

void ChRenderContext::OnDestroyBackground()
{
	m_pBackGroundNode = 0;
	m_backgroundFrame = 0;
}


bool ChRenderContext::MoveBackgroundImage()
{
	//  set backdrop depth - 1% of total depth off the far camera plane
	float depth =  ChNrViewportGetBack(m_viewport) - 
		((ChNrViewportGetBack(m_viewport) - ChNrViewportGetFront(m_viewport)) * .01);
	ChNrFrameSetPosition(m_backgroundFrame,  m_cameraFrame, 0, 0, depth);
	ChQvBackgroundInfoData *pData = (ChQvBackgroundInfoData *)(m_pBackGroundNode->GetRenderData());
	pData->Move(this);

	return true;
}

ChNrFrame ChRenderContext::SetBackgroundImage(ChQvBackgroundInfoData *pData)
{
	// The background plane is attached to the camera; this
	// means the camera is always looking right at (0,0,z) of the frame
	// The image decal is aligned to keep the look point at the correct point of
	// the image. The image alignment is done by the renderdata.
	m_pBackGroundNode = pData->GetNode();
	m_backgroundFrame = CreateFrame(m_cameraFrame);

	ChTextureHandle tex = pData->GetTextureHandle();
	ChNrFrameAddVisual(m_backgroundFrame, tex);

	ChNrFrameSetPosition(m_backgroundFrame,  m_cameraFrame, 0, 0, 100);
	ChNrFrameAddCallback(m_backgroundFrame, BackgroundCallback, this);
	ChNrObjectAddDestroyCallback(m_backgroundFrame, BackgroundDestroyCallback, this);

	return m_backgroundFrame;
}

void ChRenderContext::AdjustTransparency(ChQvMaterialMap &map)
{
	float transparency = map.GetMaxTransparency();
	m_maxTransparency = max(m_maxTransparency, transparency);
}

#endif

void ChRenderContext::OptimizationChanged(bool boolDirty)
{
	m_boolSettingsDirty = boolDirty;
	#if defined(CH_USE_D3D)
	if(m_hRC) Resize( 0, 0, true );			// Force a new device to be created with current settings
	// 		#pragma message("D3D optimization setting not done")
	#endif
}

void ChRenderContext::UpdateOptimization()
{
	#if (defined(CH_USE_RLAB)) 
	if(((ChMazeWnd*)GetWnd())->GetSettings()->GetRenderOptimization() == renderBetter)
	{
	    ChNrDeviceSetColorModel(m_hRC, RLColourRGB);  
		ChNrDeviceSetQuality(m_hRC, RenderGouraud);
	}
	else
	{
	    ChNrDeviceSetColorModel(m_hRC, RLColourRamp );  
		ChNrDeviceSetQuality(m_hRC, RenderGouraud);
		//ChNrDeviceSetQuality(m_hRC, RLRenderFlat);
	}
	#elif defined(CH_USE_D3D)
	//if(m_boolSettingsDirty && m_hRC) Resize( 0, 0, true );			// Force a new device to be created with current settings
	// 		#pragma message("D3D optimization setting not done")
		ChNrDeviceSetQuality(m_hRC, RenderGouraud);
	#endif
	m_boolSettingsDirty = false;
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
void ChRenderContext::OnWindowActivate(UINT nState, BOOL bMinimized)
{
	if(m_hRC)
	{
		#if (defined(CH_USE_D3D))
	    LPDIRECT3DRMWINDEVICE windev;

	    if (SUCCEEDED(m_hRC->QueryInterface(IID_IDirect3DRMWinDevice, (void **) &windev)))
	    {
	        if (FAILED(windev->HandleActivate(MAKEWORD( nState, bMinimized))))
	        {
	        	TRACE("Failed to handle WM_ACTIVATE.\n");
			}
	        windev->Release();
	    } 
	    else 
	    {
	        TRACE("Failed to create Windows device to handle WM_ACTIVATE.\n");
	    }
		#else

		RLWinHandleActivate(m_hRC, MAKEWORD( nState, bMinimized) );

		#endif
	}
};

void ChRenderContext::OnWindowPaint(HDC hDC)
{
	if(m_hRC)
	{
		#if (defined(CH_USE_D3D))
	    LPDIRECT3DRMWINDEVICE windev;

	    if (SUCCEEDED(m_hRC->QueryInterface(IID_IDirect3DRMWinDevice, (void **) &windev)))
	    {
	        if (FAILED(windev->HandlePaint(hDC)))
	        {
	        	TRACE("Failed to handle WM_PAINT.\n");
			}
	        windev->Release();
	    } 
	    else 
	    {
	        TRACE("Failed to create Windows device to handle WM_PAINT.\n");
	    }
		#else

		RLWinHandlePaint(m_hRC, hDC);

		#endif
	}
}

#if (defined(CH_USE_D3D))
void ChRenderContext::SetBackgroundColor(unsigned long color)
{
	m_sceneFrame->SetSceneBackground(color);

#if 0
	D3DMATERIAL matDesc;
	memset(&matDesc, 0, sizeof(matDesc));
	matDesc.dwSize = sizeof(matDesc);
	ChColor clr(color);
	matDesc.emissive.r = clr.r();
	matDesc.emissive.g = clr.g();
	matDesc.emissive.b = clr.b();
	LPDIRECT3D lpD3D;
	HRESULT rval = m_D3DRM->QueryInterface(IID_IDirect3D, (void**) &lpD3D);
	if (rval == DD_OK)
	{
		// Create the material, and set its color
		LPDIRECT3DMATERIAL mat;
		rval = lpD3D->CreateMaterial(&mat, 0);
		mat->SetMaterial(&matDesc);

		// Get a handle for the material - this depends on the D3D device,
		// NOT the RM device
		LPDIRECT3DDEVICE d3dDev;
		rval = m_hRC->GetDirect3DDevice(&d3dDev);
		D3DMATERIALHANDLE matHandle;
		mat->GetHandle(d3dDev, &matHandle);

		// We need to set the background in the d3d, NOT d3dRM viewport
		LPDIRECT3DVIEWPORT lpD3DView;
		rval = m_viewport->GetDirect3DViewport(&lpD3DView);
		
		// Finally
		lpD3DView->SetBackground(matHandle);

		// Release all the crap we collected
		lpD3DView->Release();
		mat->Release();	//????????
		lpD3D->Release();
		d3dDev->Release();
	}
	#endif
}
#endif

#endif

void ChRenderContext::Add(ChQvTimeSensorRenderData *pSensor)
{
	ChPosition pos = m_timeSensors.Find(pSensor);
	if(!pos)
	{
		m_timeSensors.AddTail(pSensor);
	}
}

void ChRenderContext::RemoveTimeSensors()
{
	while(!m_timeSensors.IsEmpty())
	{
		m_timeSensors.RemoveHead();
	}
}

void ChRenderContext::Remove(ChQvTimeSensorRenderData *pSensor)
{
	if(!m_timeSensors.IsEmpty())
	{
		ChPosition pos = m_timeSensors.Find(pSensor);
		if(pos)
		{
			m_timeSensors.Remove(pos);
		}
	}
}

void ChRenderContext::TickSensors(double t /*= 0.*/)
{
	if(!m_timeSensors.IsEmpty())
	{
		if(t == 0)
		{
			// Compute t based on clock
			#if defined(WIN32)
			struct _timeb timeStruct;
			_ftime( &timeStruct );

			t = timeStruct.time;
			t += timeStruct.millitm / 1000.;

			#else
			#error "Time computation not implemented"
			#endif
		}
		ChPosition pos = m_timeSensors.GetHeadPosition();
		while(pos)
		{
			ChQvTimeSensorRenderData *pSensor = m_timeSensors.GetNext(pos);
			pSensor->OnTick(t);
		}

	}

}

// end of file
