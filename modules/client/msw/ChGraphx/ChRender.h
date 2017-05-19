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

	Declaration for the ChRenderContext and ChQvRenderData classes and derivations, 
	which are used to store renderer specific data for 3d graphics renderers for contexts
	and in QvNodes. 

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChRender.h,v 2.59 1996/07/16 20:13:32 jimd Exp $
//
#if !defined( _CHRENDER_H )
#define _CHRENDER_H

#include "ChGrRend.h"
#include <ChSplay.h>

#include <ChGraphx.h>
#include "ChGrType.h"
#include "GxTrnsfm.h"
#include "ChColor.h"

#include <QvState.h>
#include "QvNode.h"
#include "QvInfo.h"
#include "QvWWWInline.h"
#ifdef HUGE
#undef HUGE
#endif

//#include "ChGrVw.h"

class ChRenderContext;
class ChQvState;
class ChQvInstance;
class ChQvLightInstance;
class ChQvShapeInstance;
class ChQvTransformationInstance;
class ChQvSphereCacheData;
class ChCameraEntry;
class ChEventMsg;
class ChQvBackgroundInfoData;
class ChMazeTextureHTTPReq;
class ChScrollWnd;
class ChQvTimeSensorRenderData;

#if !defined( ChViewBaseClass )
	#if defined( CH_VRML_PLUGIN )
	#define ChViewBaseClass		CWnd
	#elif defined( CH_VRML_VIEWER )
	#define ChViewBaseClass		CView
	#else
	#define ChViewBaseClass		ChScrollWnd
	#endif
#endif

// Constant that's close enough to zero for our purposes, to prevent underflow and
// divide by zero problems
#define SMIDGEON	(1e-12) 

// Sphere tesselation limits
#define CH_MAX_SPHERE_LEVEL		10
#define CH_MIN_SPHERE_LEVEL		1


#if defined(CH_USE_3DR)
#define CH_MAX_LIGHTS	 G3D_MAX_LIGHTS
#else
#define CH_MAX_LIGHTS	 100000L	// No set limit
#endif


#if defined( CH_USE_RLAB ) || defined(CH_USE_D3D)
UINT ConstructionThread( LPVOID pData );
UINT ReConstructInstanceThread( LPVOID pData );

// This class is used to pass data to the construction thread.
class ChUnderConstruction
{
	public:
		ChUnderConstruction(ChRenderContext *pContext, ChQvInstance *pRoot)
			: m_pContext(pContext), m_pRoot(pRoot) {};
		
		ChRenderContext	 	*GetContext() {return m_pContext;};
		ChQvInstance 		*GetRoot() {return m_pRoot;};

	protected:
		ChRenderContext	 	*m_pContext;
		ChQvInstance 		*m_pRoot;
		ChPtrList<ChQvInstance>	m_usedInstances;
};

#endif

#define RELEASE_INTERFACE(intfc)	\
		if(intfc) { (intfc)->Release(); (intfc)= 0; }



class ChTransformStack: public ChList<GxTransform3Wf>
{
	public:
		ChTransformStack() : ChList<GxTransform3Wf>() {} ;
		virtual ~ChTransformStack() {};
};

class ChTexture;
class ChDotsCache: public ChPtrSplay<ChTexture>
{
	public:
		ChDotsCache() : ChPtrSplay<ChTexture>() {} ;
		virtual ~ChDotsCache() {};
};

class ChDib;
class QvNode;
class QvInfo;
class ChQvAnchorSensor;
typedef ChQvAnchorSensor * pChQvAnchorSensor;
class ChCameraIterator;
class ChCollisionView;
class ChQvMaterialMap;
class ChDevice3D;

/*----------------------------------------------------------------------------
	ChRenderContext class
----------------------------------------------------------------------------*/

class ChRenderContext
{
	friend class ChCameraIterator;

	protected:
		#if defined( CH_USE_3DR )

		G3dHandle_t		m_hGC;				// only sometimes valid
		ChNativeContext	m_hRC;
		HDC				m_hDC;

		#elif defined(CH_USE_RLAB) || defined(CH_USE_D3D)
		// Microsoft Reality Lab or D3D
		enum tagEvents { reconstructInstance = 0, abortReconstruct, endThread, maxEvents };
		enum tagConsts { MaxWorkPerRender = 50 };

		ChNativeContext	m_hRC;
		HDC				m_hDC;
		ChNrFrame			m_sceneFrame;
		ChNrFrame			m_cameraFrame;
		ChNrFrame			m_headlightFrame;
		ChNrViewport		m_viewport;

		CRITICAL_SECTION 	m_sceneCriticalSection;
		CRITICAL_SECTION 	m_constructionCriticalSection;
		CRITICAL_SECTION 	m_reconstructionCriticalSection;
		HANDLE				m_hReconstructEvents[maxEvents];
		HANDLE				m_hConstructDoneEvent;
		bool				m_boolContinueConstruction;

		#if defined(CH_USE_D3D)
		LPDIRECTDRAW	m_DD;           /* DirectDraw object */
		LPDIRECT3D		m_D3D;           /* Direct3D (Immediate Mode) object */
		LPDIRECT3DRM	m_D3DRM;           /* Direct3DRM object */

		LPDIRECTDRAWCLIPPER m_DDClipper;/* DirectDrawClipper object for window */

		#endif
		#endif // 3DR

		CRITICAL_SECTION 	m_qvCriticalSection;
 	
 		bool				m_boolThreaded;
			   
		ChViewBaseClass* 				m_pWnd;
		ChShadingLevel					m_userShading;
		QvNode							**m_ppDefaults;
		bool							m_boolDirty;
		bool							m_boolSettingsDirty;
		// Scene State
		int								m_iShapeCount;
		#if defined( CH_USE_3DR )
		GxVec3f 						m_cameraLoc;  // do we need w too?
		#endif // 3DR
		ChQvInstance					*m_pRootInstance;
		QvNode*							m_pCamera;
		QvNode*							m_pDefaultCamera;
		ChPtrList<ChCameraEntry>		m_cameras;
		int 							m_cameraCount;
		#if defined( CH_USE_3DR )
		ChPtrList<ChQvLightInstance>	m_lights;
		int								m_numLightsOn;
		#else
			// lights are in scene for RL
		#endif
		float							m_moveQuality;
		float							m_standingQuality;
		ChQvSphereCacheData				*m_pSpheres[CH_MAX_SPHERE_LEVEL+1];
		#if defined(CH_USE_RLAB) || defined(CH_USE_D3D)
		ChDotsCache						m_dotsCache;
		ChPtrList<ChQvInstance>			m_constructionThreadList;
		ChPtrList<ChQvInstance>			m_reconstructionThreadList;
		ChCollisionView	 				*m_pCollisionSensor;
		float							m_maxTransparency;
		#endif
		ChPtrList<ChMazeTextureHTTPReq>	m_textureQueue;

		int								m_iTotalWork;
		int								m_iFrameCount;
		bool							m_boolAnimating;
		ChPtrList<ChQvTimeSensorRenderData>	m_timeSensors;

	public:
		ChRenderContext();
		virtual ~ChRenderContext();

		void Init( ChViewBaseClass* pWnd, CDC* pDC );
		void Term();

		void AbortConstruction();


		#if defined(CH_USE_3DR)
		inline ChRenderContext* SetGC( G3dHandle_t hGC ) { m_hGC = hGC; return this; }
		inline G3dHandle_t GetGC() { return m_hGC; }
		#endif

		inline ChRenderContext* SetRC( ChNativeContext hRC ) { m_hRC = hRC; return this; }
		inline ChRenderContext* SetDC( HDC hDC ) { m_hDC = hDC; return this; }
		inline ChNativeContext GetRC() { return m_hRC; }
		inline HDC GetDC() { return m_hDC; }
		inline ChViewBaseClass* GetWnd() { return m_pWnd; }

		ChRenderContext* SetTexture( ChTextureHandle hTex = 0 ); 
		ChTextureHandle GetTexture(); 
		void SetModulation( bool boolUseTexture = true, bool boolPureEmissive = false );
		
		ChRenderContext* SetShading( ChQvShapeInstance *pInstance );

		#if defined(CH_USE_3DR)
		inline void SetShadingPref( ChShadingLevel	userShading )
			{ m_userShading = userShading; };

		inline ChRenderContext *SetCameraLoc(GxVec3f &cameraLoc) { m_cameraLoc = cameraLoc; return this;};
		inline GxVec3f GetCameraLoc() {return m_cameraLoc;};
		#else
		ChRenderContext *SetCameraLoc(GxVec3f &cameraLoc);
		GxVec3f GetCameraLoc();
		GxVec3f GetCameraUp();
		GxVec3f GetCameraDir();
		#endif
 		Ch3DViewerMode GetViewerMode();
		int GetFrameCount() { return m_iFrameCount;};

		// These 4 transforms yield the standard pipeline
		GxTransform3Wf GetModelTransform();	// Renderer's current Model to world
		GxTransform3Wf GetWorldToCameraTransform();
		GxTransform3Wf GetCameraToClipTransform();
		GxTransform3Wf GetClipToScreenTransform();

		ChRenderContext *SetModelTransform(GxTransform3Wf& transform);  
		ChQvTransformationInstance *GetDefaultTransform();
		QvNode *GetCurrentCamera() {return m_pCamera;};
		ChRenderContext *SetCurrentCamera(QvNode *pCamera = 0);
		ChRenderContext *SelectCamera(int iCamIndex);
		int GetCameraIndex();
		QvNode *GetDefaultCamera() {return m_pDefaultCamera;};
		ChRenderContext *NewDefaultCamera();
		bool IsCameraDefault() {return (m_pDefaultCamera == m_pCamera);};
		QvNode *GetCurrentProperty(ChQvState *pState, QvState::StackIndex index);
		ChRenderContext* AddCamera(QvNode *pCamera, string &strName);
		ChRenderContext* RemoveCamera(string &strName);
		int GetCameraCount(){return m_cameraCount;};
		bool GetCamera(int i, string &strName, QvNode **pCamera);
		#if defined(CH_USE_3DR)
		ChRenderContext* Add(ChQvLightInstance *pLightInst);
		ChRenderContext* Remove(ChQvLightInstance *pLightInst);
	 	inline int GetNextLight()
	 		{ 						
	 			if(m_numLightsOn < CH_MAX_LIGHTS) return m_numLightsOn;
	 			else return -1;
	 		};
	 	inline ChRenderContext*  TurnOnALight(bool boolOn = true)
	 		{
	 			if(boolOn)++m_numLightsOn;
	 			else --m_numLightsOn;
	 			return this;
	 		};
		#else
		#endif

		#if defined(CH_USE_3DR)
		void CreateHeadlight( GxVec3f& loc, GxVec3f& dir, QvState* state );
		#elif defined(CH_USE_RLAB) || defined(CH_USE_D3D)
		void CreateHeadlight( ); // attached to camera
		void DestroyHeadlight( );
		void AdjustHeadlight();
		#endif


		bool Draw();
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		void OnWindowActivate(UINT nState, BOOL bMinimized);
		void OnWindowPaint(HDC hDC);
		#endif

		ChRenderContext*  SetRoot(ChQvInstance *pRootInstance);
		inline ChQvInstance*  GetRoot() {return m_pRootInstance;};
		ChRenderContext*  ResetScene();

		float GetAdjustedLODRange(float range);
		ChQvSphereCacheData *GetSphere(int level);
		float GetQuality();
		#if defined(CH_USE_3DR)
 		ChTextureHandle LoadDIBTexture( ChDib *pDibIn, chuint32 luChromaClr, chuint uOption );
		#endif
		float GetPixelAngle();

		ChRenderContext * ClearTransformStack();
		ChRenderContext * ComposeTransform(GxTransform3Wf& transform);	// apply to object end
		ChRenderContext * PopTransform();
		ChRenderContext * PopTransform(GxTransform3Wf& transform);
		ChRenderContext * PushTransform();

		#if defined(CH_USE_3DR)
		void RebuildTransformStack( ChQvState* pState );
		#else
		inline ChNrFrame GetFrame() { return m_sceneFrame;};
		inline ChNrViewport GetViewport() {return m_viewport;};
		void Resize( int width = 0, int height = 0, bool boolForceNew = false );
		#endif

		void LockQv();
		void UnlockQv();

		#if defined(CH_USE_RLAB) || defined(CH_USE_D3D)
		ChDotsCache* GetDotsCache() {return &m_dotsCache;};
		bool IsAnchor( int iX, int iY, pChQvAnchorSensor &pAnchor );

		void LockScene();
		void UnlockScene();

		void LockConstruction();
		void UnlockConstruction();

		bool ConstructScene(ChQvInstance *pRoot);
		ChRenderContext *StartConstruction(ChQvInstance *pRoot = 0);
		void IncrementShapeCount()			{ m_iShapeCount++; }


		HANDLE GetEndConstructEvent()		{ return m_hConstructDoneEvent; }
		int    GetTotalReConstructEvents()	{ return maxEvents; }
		HANDLE* GetReConstructEvents()		{ return m_hReconstructEvents; }

		bool ReconstructInstance( DWORD lEvent ) 	{ return (lEvent == reconstructInstance); }
		bool AbortReconstruct( DWORD lEvent ) 	  	{ return (lEvent == abortReconstruct); }
		bool TerminateReconstruct( DWORD lEvent ) 	{ return (lEvent == endThread); }


		long NumPendingConstructionThreads(); 
		bool AddConstruction(ChQvInstance *pRoot );
		bool RemoveConstruction(ChQvInstance *pRoot );

		bool ContinueConstruction()		{ return m_boolContinueConstruction; };

		bool AddSynchReconstruction(int iWork);
		bool AddReconstruction(ChQvInstance *pInst);
		void ClearReconstruction( );
		bool RemoveReconstruction(ChQvInstance *pInst);
		ChQvInstance * GetNextReconstruction(bool boolRemove = false);
		void LockReconstruction();
		void UnlockReconstruction();
		void LowerConstructionThreads(bool);

		ChRenderContext *ForceUpdate();

		void Animate( bool boolRun = true ) { m_boolAnimating = boolRun;};
		bool IsAnimating( ) {return m_boolAnimating; };

		float GetCollisionRange();
		float GetCollisionRange(GxVec3f &look, bool boolRelative = false);
		bool GetHitPoint(int iX, int iY, GxVec3f &pt);
		float GetAvatarRadius();

		void AdjustTransparency(ChQvMaterialMap &map);
		#endif
  	
  		bool IsThreaded()					{ return m_boolThreaded; }
		int	 GetShapeCount()				{ return m_iShapeCount; }
		bool IsDirty() { return m_boolDirty;};
		ChRenderContext *  SetDirty(bool dirty = true) { m_boolDirty = dirty; return this;};
		void OptimizationChanged(bool boolDirty = true);

		bool ProcessEvent(ChEventMsg *pEventMsg);

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		ChNrFrame SetBackgroundImage(ChQvBackgroundInfoData *pData);
		bool MoveBackgroundImage();
		void OnDestroyBackground();
		QvNode *m_pBackGroundNode;
		ChNrFrame	m_backgroundFrame;
		#endif
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		ChNativeContext CreateDevice(int width, int height);
		ChNrFrame CreateFrame(ChNrFrame parent);
		ChNrMesh CreateMesh();
		ChNrFace CreateFace();
		ChNrLight CreateLight(ChNrLightType type, const ChColor & color);
		ChNrLight CreateLightRGB(ChNrLightType type, ChNrValue r, ChNrValue g, ChNrValue b);
		ChNrViewport CreateViewport(ChNativeContext dev, ChNrFrame camera, DWORD dwXPos, DWORD dwYPos, DWORD dwWidth, DWORD dwHeight);
		ChNrMaterial CreateMaterial(ChNrValue ks, ChNrValue pow);
		ChTextureHandle CreateTexture(ChNrImage *pImage );

		#if (defined(CH_USE_D3D))
		bool ChRenderContext::InitOffscreenDevice(ChDevice3D &device, int width, int height);
		bool ChRenderContext::InitWindowDevice(ChDevice3D &device, int width, int height);
		#endif

		#endif
							 // call this only from main thread
		inline void AddToTextureQueue( ChMazeTextureHTTPReq* pReq )	
						{
							m_textureQueue.AddHead( pReq );
						}
		void Add(ChQvTimeSensorRenderData *pSensor);
		void Remove(ChQvTimeSensorRenderData *pSensor);
		void RemoveTimeSensors();
		void TickSensors(double t = 0.);

	protected:
		#if defined(CH_USE_3DR)
		ApplyQvTail( QvElement* elt );
		#endif
		void TraverseLights();
		ChRenderContext* Reset();
		ChRenderContext* RemoveLights();

		#if defined(CH_USE_3DR)
		#else
		ChTransformStack *m_pStack;
		#endif

		protected:
		ChRenderContext* RemoveCameras();
		#if defined(CH_USE_RLAB) || defined(CH_USE_D3D)
		bool DoBackground();
		ChTexture *m_pBackgroundTexture;

		#endif

		void UpdateOptimization();
		void ProcessTextureQueue();  // call this only from the main thread

	#if (defined(CH_USE_D3D))

	public:
		HRESULT EnumDriver(LPGUID lpGuid, LPSTR lpDeviceDescription, LPSTR lpDeviceName,
        	LPD3DDEVICEDESC lpHWDesc, LPD3DDEVICEDESC lpHELDesc);

	protected:
		class ChD3dDriver
		{
			protected:
				string m_name;
				GUID 	m_guid;
				bool	m_boolHardware;
				bool	m_boolMono;

			public:
				ChD3dDriver() :
				   m_boolHardware(false), m_boolMono(false)
				   { };

				void Set(const string &name, const GUID &guid, bool boolHardware, bool boolMono)
				{
					m_name = name;
					m_guid = guid;
					m_boolHardware = boolHardware;
					m_boolMono = boolMono;
				};

				string &GetName() { return m_name;};
				GUID &GetGUID() {return m_guid;};
				bool IsHardware() {return m_boolHardware; };
				bool IsMono() {return m_boolMono;};
		};

		ChD3dDriver	m_drivers[renderOptimizationCount];

		int GetBPP();

		BOOL ChRenderContext::EnumDrivers();
		void SetBackgroundColor(unsigned long color);

	#endif

};

// Iterator for all the available cameras.
// Guaranteed to list in same order as World file Switch{ }
class ChMazeWnd;

class ChCameraIterator
{
	friend class ChRenderContext;

	public:
		ChCameraIterator() : m_pRC(0) {};
		ChCameraIterator(ChRenderContext *pRC) : m_pRC(0) 
		{
			Attach(m_pRC);
		};

		ChCameraIterator(ChMazeWnd *pWnd) : m_pRC(0) 
		{
			Attach(pWnd);
		};

		virtual ~ChCameraIterator() {};

		ChCameraIterator* Attach(ChRenderContext *pRC)
		{
			m_pRC = pRC;
			return this;
		};

		ChCameraIterator* Attach(ChMazeWnd *pWnd);

		bool Iterate();

		virtual bool DoCamera(string &strName, QvNode *pCamera) = 0;

	protected:

		 ChRenderContext *m_pRC;

};




#endif // _CHRENDER_H
