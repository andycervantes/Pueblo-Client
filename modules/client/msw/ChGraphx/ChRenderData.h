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

	Declaration for the ChQvRenderData class and derivations, 
	which are used to store renderer specific object data for 3d graphics renderers 
	associated with QvNodes. 

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChRenderData.h,v 2.18 1996/10/03 21:46:11 jimd Exp $
//
#if !defined( _CHRENDERDATA_H )
#define _CHRENDERDATA_H

#include "ChRender.h"

#include "ChVrmlEvent.h"

#ifdef HUGE
#undef HUGE
#endif
													   
// Add an event handler to a dispatcher table
#define AddVrmlDispatcher( name, ty, fn)	\
(GetDispatcher()->Insert(string(name), ChEventDispatch(ChVRMLEvent::ty, ChVrmlEventHandler(fn))))


// Render Data Classes. 
// ChQvRenderData is an abc for use by Qv. 
// ChQvRenderBaseData is lowest level instantiable class.
// Note that shapes are multiply inherited.


class ChApplet;
class ChIVrmlEvent;
class ChQvScriptRenderData;

// Chaco class to hold renderer-specific data in a Qv node
// Derive for each class and each renderer as needed 
class ChQvRenderBaseData : public ChQvRenderData
{
	friend class ChQvRenderBaseDataIterator;
	friend class ChRenderContext;	  // todo: clean up this access
	public:
		typedef bool (ChQvRenderBaseData::*ChVrmlEventHandler)(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEvent);
		class ChEventDispatch
		{
			public:
				ChVRMLEvent::type		m_eventType;
				ChVrmlEventHandler		m_handler;
			public:
				ChEventDispatch() : 
					m_eventType(ChVRMLEvent::invalid),		m_handler(0) { };
				ChEventDispatch(ChVRMLEvent::type t, ChVrmlEventHandler handler) :
					m_eventType(t),		m_handler(handler) { };
		};
		typedef ChSplay<string, ChEventDispatch>	ChVrmlDispatcher;

	protected:


		ChPtrList<ChQvInstance>	m_instances;
		ChPtrList<ChQvInstance>	m_dependents;
		
 		QvNode *m_pNode;
		ChPtrList<ChQvScriptRenderData> m_scripts;

	public:
		ChQvRenderBaseData() : ChQvRenderData() {};
		ChQvRenderBaseData(QvNode *pNode) : ChQvRenderData()
			{ Attach(pNode);};
		virtual ~ChQvRenderBaseData();

		ChQvRenderBaseData *Attach(QvNode *pNode);
		ChQvRenderBaseData *Add(ChQvInstance *pInstance);
		ChQvRenderBaseData *Remove(ChQvInstance *pInstance);
		ChQvRenderBaseData *AddDependent(ChQvInstance *pInstance);
		bool RemoveDependent(ChQvInstance *pInstance);
		int GetInstanceCount();
		inline QvNode * GetNode() {return m_pNode;};

		ChQvRenderBaseData *Add(ChQvScriptRenderData *pScript);
		ChQvRenderBaseData *Remove(ChQvScriptRenderData *pScript);

		virtual bool DispatchEvent(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEventList);

		static void Term();

		void PurgeQv();
		void Init() {};	// for dispatcher
		
		virtual void SetDirty(bool boolDirty = true); 


	protected:
		 virtual ChVrmlDispatcher	*GetDispatcher() {return 0;};
};

// Iterator for instances and scripts attached
class ChQvRenderBaseDataIterator
{
	public:
		ChQvRenderBaseDataIterator();
		ChQvRenderBaseDataIterator( const ChQvRenderBaseData& rbd );

		virtual ~ChQvRenderBaseDataIterator();

		virtual void Attach( ChQvRenderBaseData& rbd );
		virtual int Iterate();
		virtual int IterateDependents();
		virtual int IterateScripts();

		virtual int DoInstance(ChQvInstance& inst) {return 1;};
		virtual int DoScript(ChQvScriptRenderData& script) {return 1;};

   protected:
		ChQvRenderBaseData* m_pData;

   private:
											/* Disable copy constructor and
												assignment operator */

      inline ChQvRenderBaseDataIterator( const ChQvRenderBaseDataIterator& ) {}
      inline ChQvRenderBaseDataIterator& operator=( const ChQvRenderBaseDataIterator& )
      			{
      				return *this;
      			}
};


/*----------------------------------------------------------------------------
	ChQvInfoRenderData class
----------------------------------------------------------------------------*/

class ChQvInfoRenderData : public ChQvRenderBaseData
{
	
	protected:
		ChShadingLevel		m_shading;;

	public:
		ChQvInfoRenderData(QvInfo *pNode) : ChQvRenderBaseData(pNode), m_shading( defaultShading ) {}
		virtual ~ChQvInfoRenderData() {}

		inline ChQvInfoRenderData * SetShading( ChShadingLevel shading )
			{ m_shading = shading; return this; }
		inline ChShadingLevel GetShading() { return m_shading; };

};


/*----------------------------------------------------------------------------
	ChQvIFSRenderData class
----------------------------------------------------------------------------*/

class ChQvIndexedFaceSetNormals;

class ChQvIFSRenderData : public ChQvRenderBaseData
{	   
								// Indexed face set
	friend class QvIndexedFaceSet;

	protected:
		ChQvIndexedFaceSetNormals *m_pNormals;
		bool m_boolValid;		// whether the coord index is valid
		bool CheckValid(QvIndexedFaceSet* ifs, QvState* state);

	public:
		ChQvIFSRenderData(QvIndexedFaceSet* ifs, QvState* state);
		virtual ~ChQvIFSRenderData(); 

		ChQvIndexedFaceSetNormals *GetNormals() { return m_pNormals; };
		void Init(QvIndexedFaceSet* ifs, QvState* state);
		bool IsValid() {return m_boolValid;};

};



/*----------------------------------------------------------------------------
	ChQvMaterialRenderData class
----------------------------------------------------------------------------*/
class ChMaterialCache;
class ChMaterialCacheElement;
#include <QvMaterial.h>

class ChQvMaterialRenderData : public ChQvRenderBaseData
{
	
	protected:
		
		#if (defined(CH_USE_D3D))
		ChMaterialCache	*m_pCache;
		#endif

	public:
		ChQvMaterialRenderData(QvMaterial *pNode);
		virtual ~ChQvMaterialRenderData();

		#if (defined(CH_USE_D3D))
		ChNrMaterial Find(int index);
		void Add(int index, ChNrMaterial mat);
		#endif

	protected:
		#if (defined(CH_USE_D3D))
		double Key(int index);
		ChNrMaterial Find(const double &key);
		#endif

};

/*----------------------------------------------------------------------------
	ChQvTransformationRenderData class
----------------------------------------------------------------------------*/

class ChQvTransformationRenderData : public ChQvRenderBaseData
{	   
							

	private:
		static ChVrmlDispatcher		*m_pDispatcher;

	public:
		ChQvTransformationRenderData(QvNode* pNode);
		virtual ~ChQvTransformationRenderData();
		
		// VRML 2.0 Style Event Handlers
		bool OnSetRotation(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEvent);
		bool OnSetTranslation(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEvent);
		bool OnSetScaleFactor(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEvent);
		bool OnSetScaleOrientation(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEvent);
		bool OnSetCenter(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEvent);
		

		// Dispatch Table for this class
 		virtual ChVrmlDispatcher *GetDispatcher() {return m_pDispatcher;};

		void ChQvTransformationRenderData::Init();

		static void Term();
		virtual void SetDirty(bool boolDirty = true); 

};

/*----------------------------------------------------------------------------
	ChQvGroupRenderData class - all group node types
----------------------------------------------------------------------------*/

class ChQvGroupRenderData : public ChQvRenderBaseData
{	   
							

	private:
		static ChVrmlDispatcher		*m_pDispatcher;

	public:
		ChQvGroupRenderData(QvNode* pNode);
		virtual ~ChQvGroupRenderData();
		
		// VRML 2.0 Event Handlers
		bool OnAddChildren(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEvent);
		bool OnRemoveChildren(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEvent);

 		virtual ChVrmlDispatcher *GetDispatcher() {return m_pDispatcher;};

		void ChQvGroupRenderData::Init();

		static void Term();
		ChQvGroupRenderData* Instantiate(ChMazeWnd * pWnd, QvNode *pNewChild);
		bool IsNodeAddable(QvNode *pChild);
		bool IsNodeRemovable(QvNode *pChild);


};

/*----------------------------------------------------------------------------
	ChQvInlineRenderData class
----------------------------------------------------------------------------*/
class ChMazeWnd;
class ChParseInfo;
class ChMazeInlineHTTPReq;

class ChQvWWWInlineRenderData : public ChQvGroupRenderData
{	   
	friend class QvWWWInline;

	protected:
		string m_strURL;
		ChParseInfo * m_pParseInfo;
		ChMazeInlineHTTPReq*  m_pHttpReq;

	public:
		ChQvWWWInlineRenderData(QvWWWInline* pNode) : ChQvGroupRenderData(pNode), 
			m_pParseInfo(0), m_pHttpReq(0)
			{};
		virtual ~ChQvWWWInlineRenderData(); 

		ChQvWWWInlineRenderData* Instantiate(ChMazeWnd * pWnd, QvNode *pNewChild);
		string& GetCurrentURL() {return m_strURL;};
		void SetURL(string &strURL) {m_strURL = strURL;};
		inline void SetParseInfo(ChParseInfo * pParseInfo) { m_pParseInfo = pParseInfo; };
		inline ChParseInfo * GetParseInfo() { return m_pParseInfo; };
		inline ChMazeInlineHTTPReq* GetReq() {return m_pHttpReq; };
		inline void SetReq(ChMazeInlineHTTPReq*  pReq) {m_pHttpReq = pReq;};

};

/*----------------------------------------------------------------------------
	ChQvTexture2TransformRenderData class
----------------------------------------------------------------------------*/

class ChQvTexture2TransformRenderData : public ChQvRenderBaseData
{	   
							

	protected:
		bool 	m_boolDefault;
		float	m_cosa;
		float	m_sina;

		ChQvTexture2TransformRenderData *CheckForDefault();
	public:
		ChQvTexture2TransformRenderData(QvNode* pNode);
		virtual ~ChQvTexture2TransformRenderData() {};
		
		ChQvTexture2TransformRenderData *Transform(float &s, float& t);
		virtual void SetDirty(bool boolDirty = true); 

};


/*----------------------------------------------------------------------------
	ChQvPCameraRenderData class
----------------------------------------------------------------------------*/
class ChQvBuildState;
class ChQvPCameraRenderData : public ChQvRenderBaseData
{	   // Perspective Camera
	friend class QvPerspectiveCamera;
	friend class QvOrthographicCamera;
										 
	private:
		bool		m_boolSynchEnabled;
		inline const bool IsSynchEnabled() {return m_boolSynchEnabled ;};
		inline void EnableSynch(bool boolEnabled = true) {m_boolSynchEnabled = boolEnabled;};

	protected:
		bool boolInfinite;
		GxVec3f 	m_loc;
		GxVec3f		m_dir;	
		GxVec3f		m_up;
		GxVec3f 	m_startLoc;
		GxVec3f		m_startDir;	
		GxVec3f		m_startUp;
		QvPerspectiveCamera *m_pCamera;
		#if defined(CH_USE_3DR)
		GxTransformF_t	m_invCameraTransform;
		GxTransformF_t	m_cameraTransform;
		#else
		GxTransform3Wf	m_cameraTransform;
		GxTransform3Wf	m_transform; // to world
		#endif
		string 			m_strName;
		ChRenderContext *m_pRC;

		bool m_boolRendererDirty;

		float	m_left;
		float	m_top;
		float	m_right;
		float	m_bottom;

		bool	m_boolPerspective;
		bool	m_boolNew;

		GxTransform3Wf m_camClipTransform;

		static ChVrmlDispatcher		*m_pDispatcher;

	public:
		ChQvPCameraRenderData(QvPerspectiveCamera *pCamera, ChQvBuildState* state );
		ChQvPCameraRenderData(QvOrthographicCamera *pCamera, ChQvBuildState* state );
		virtual ~ChQvPCameraRenderData();

		virtual void SetDirty(bool boolDirty = true); 

		inline bool IsPerspective() { return m_boolPerspective; };
		ChQvPCameraRenderData *SetLoc(GxVec3f &loc)	;
		ChQvPCameraRenderData *SetDir(GxVec3f &dir)	;
		ChQvPCameraRenderData *SetUp(GxVec3f &up);

		ChQvPCameraRenderData *SetStartLoc(GxVec3f &loc)	{m_startLoc = loc; return this;};
		ChQvPCameraRenderData *SetStartDir(GxVec3f &dir)	{m_startDir = dir; return this;};
		ChQvPCameraRenderData *SetStartUp(GxVec3f &up)	{m_startUp = up; return this;};
		ChQvPCameraRenderData *Reset();
		string MakeName(ChQvBuildState* state);


		const GxVec3f &GetLoc()	{return m_loc;};
		const GxVec3f	&GetDir()	{return m_dir;};
		const GxVec3f	&GetUp()	{return m_up;};

		const GxVec3f &GetStartLoc()	{return m_startLoc;};
		const GxVec3f	&GetStartDir()	{return m_startDir;};
		const GxVec3f	&GetStartUp()	{return m_startUp;};

		void TransformPoint( const GxVec3f &src, GxVec3f &dst );
		void InverseTransformPoint( const GxVec3f &src, GxVec3f &dst );
		void TransformNormal( const GxVec3f &src, GxVec3f &dst );
		void InverseTransformNormal( const GxVec3f &src, GxVec3f &dst );

		GxTransform3Wf GetTransform();
		GxTransform3Wf GetClipTransform();
		GxTransform3Wf GetInverseTransform();
		ChQvPCameraRenderData * GetPort(float &left, float &right, float &top, float &bottom)
		{
			left	=	m_left;   
			top		=	m_top;    
			right	=	m_right;  
			bottom	=	m_bottom; 
			return this;
		};

		void SynchCamera();		  // Set camera node fields to agree with this
		void Synch();  			// Set this' fields to agree with  camera node
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) || defined(CH_USE_D3D)
		ChQvPCameraRenderData * ChQvPCameraRenderData::SetRenderer(bool boolNow = false);
		ChQvPCameraRenderData * Select();
		void GetOrientationTransform(GxTransform3Wf &theTransform);
		float GetHither();
		float GetYon();

		bool OnTick();	  // 'move' tick
		#endif

 		virtual ChVrmlDispatcher *GetDispatcher() {return m_pDispatcher;};
		bool OnSetOrientation(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEvent);
		bool OnSetPosition(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEvent);

		void Init();

		static void Term();
};


/*----------------------------------------------------------------------------
	ChQvTextureRenderData class
----------------------------------------------------------------------------*/

class QvTexture2;
class ChRLImage;

class ChQvTextureRenderData : public ChQvRenderBaseData
{	   // Texture data
	friend class QvTexture2;

	protected:
		string m_strURL;
			// Chaco's 3dr fields
		ChTextureHandle m_texture;		// texture handle; set to null if delayed load
		#if defined(CH_USE_3DR)
		long int m_hRC;			// needed to free texture
		#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) || defined(CH_USE_D3D)
		ChRLImage *m_pImage;
		#endif	
		//QvTexture2 *m_pTexture2;

	protected:
		int GetURL(QvState *qvstate);	 // called from QvTexture2

	public:
		ChQvTextureRenderData(QvNode* txt);
		virtual ~ChQvTextureRenderData(); 

		string &GetCurrentURL() { return m_strURL; };
		ChTextureHandle GetTextureHandle() { return m_texture; };
		virtual bool IsEmpty();		// whether it will -never- have a texture
		#if defined(CH_USE_3DR)
		ChQvTextureRenderData* SetRC(long int hRC) 
			{ m_hRC = hRC; return this;};
		#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) || defined(CH_USE_D3D)
		#endif

		virtual ChQvTextureRenderData* LoadTexture(ChRenderContext *pContext, ChDib *pDibIn, chuint32 luChromaClr, chuint uOption);

		#if defined(CH_USE_3DR)
		virtual ChQvTextureRenderData* LoadTexture( ChRenderContext *pContext, ChTextureHandle texHandle );
		#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) || defined(CH_USE_D3D)
		virtual ChQvTextureRenderData* LoadTexture( ChRenderContext *pContext, ChRLImage* pRLImg );

		bool IsChromaKey();
		ChColor GetChromaKey();

		#endif


	#if defined(CH_USE_3DR)
	public:
	#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) || defined(CH_USE_D3D)
	protected:
	#endif	
		ChQvTextureRenderData* SetTextureHandle(ChTextureHandle hText) 
			{ m_texture = hText; return this;};
};

class ChQvBackgroundData : public ChQvRenderBaseData
{	   // Texture data
	friend class QvTexture2;

	protected:
		string m_strURL;
		
		ChTextureHandle m_panTextures[6];		// texture handles for panorama; set to null initially
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) || defined(CH_USE_D3D)
		ChRLImage *m_pImage;
		#endif	

	protected:
		int GetURL(QvState *qvstate);	 // called when spawned

	public:
		ChQvBackgroundData();
		virtual ~ChQvBackgroundData(); 

		string &GetCurrentURL() { return m_strURL; };
		ChTextureHandle GetTextureHandle(int i) { return m_panTextures[i]; };
		bool IsEmpty();		// whether it will -never- have a texture

		ChQvBackgroundData* LoadTexture(ChRenderContext *pContext, ChDib *pDibIn, chuint32 luChromaClr, chuint uOption);

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) || defined(CH_USE_D3D)
		ChQvBackgroundData* LoadTexture( ChRenderContext *pContext, ChRLImage* pRLImg );
		#endif

	#if defined(CH_USE_3DR)
	public:
	#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) || defined(CH_USE_D3D)
	protected:
	#endif
	#if 0	
		ChQvBackgroundData* SetTextureHandle(ChTextureHandle hText) 
			{ m_texture = hText; return this;};
	#endif
};

class ChQvBackgroundInfoData : public ChQvTextureRenderData
{	   // Texture data for Background Info node
	friend class QvInfo;

	protected:
		ChRLImage	*m_pTiledImage;
		int 		m_height;
		int 		m_width;
		GxVec3f		m_backCenter;
		bool		m_boolDirty;
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) || defined(CH_USE_D3D)
		ChNrFrame		m_backgroundFrame;
		#endif

	protected:
		int GetURL(QvState *qvstate);	 // called when spawned

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) || defined(CH_USE_D3D)
		int ComputeTiledWidth(ChRenderContext *pContext);
		int ComputeTiledHeight(ChRenderContext *pContext);
		void InitDecal(ChRenderContext *pContext);
		void Resize( ChRenderContext *pContext);
		#endif

	public:
		ChQvBackgroundInfoData(QvNode *pNode);
		virtual ~ChQvBackgroundInfoData(); 

		virtual bool IsEmpty();		// whether it will -never- have a texture

		virtual ChQvTextureRenderData* LoadTexture(ChRenderContext *pContext, ChDib *pDibIn, chuint32 luChromaClr, chuint uOption);

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) || defined(CH_USE_D3D)
		virtual ChQvTextureRenderData* LoadTexture( ChRenderContext *pContext, ChRLImage* pRLImg );
		bool CreateTexture(ChRenderContext *pContext);
		void Justify(GxVec3f &pt, ChRenderContext *pContext);
		void Move( ChRenderContext *pContext);
		void OnResize( ChRenderContext *pContext);
		void OnDestroyTexture();

		#endif

};

class ChQvSwitchRenderData : public ChQvGroupRenderData
{	   
							

	private:
		static ChVrmlDispatcher		*m_pDispatcher;

	public:
		ChQvSwitchRenderData(QvNode* pNode);
		virtual ~ChQvSwitchRenderData();
		
		// VRML 2.0 Event Handlers
		bool OnSetWhichChild(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEvent);

 		virtual ChVrmlDispatcher *GetDispatcher() {return m_pDispatcher;};

		void Init();

		static void Term();

};

class ChQvSpinGroupInstance;

class ChQvSpinGroupRenderData : public ChQvGroupRenderData
{	   
							

	private:
		static ChVrmlDispatcher		*m_pDispatcher;
		float m_step;
		GxTransform3Wf	m_spinTransform;

	public:
		ChQvSpinGroupRenderData(QvNode* pNode);
		virtual ~ChQvSpinGroupRenderData();
		
		// VRML 2.0 Event Handlers
		bool OnSetRotation(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEvent);

		// Dispatch Table for this class
 		virtual ChVrmlDispatcher *GetDispatcher() {return m_pDispatcher;};

		void Init();

		static void Term();
		void Spin(ChQvSpinGroupInstance *pTarget);

};

		// VRML 2.0 Things
class ChQvTimeSensorRenderData : public ChQvRenderBaseData
{	   
							

	private:
		ChRenderContext *m_pRC;	// where installed

	public:
		ChQvTimeSensorRenderData(QvNode* pNode) : ChQvRenderBaseData(pNode), m_pRC(0) {};
		virtual ~ChQvTimeSensorRenderData();
		
		bool OnTick(double t);
		Install(ChRenderContext *pRC);
};


#endif // _CHRENDER_H
