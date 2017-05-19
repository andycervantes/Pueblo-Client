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

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvInstnc.h,v 2.30 1996/06/30 19:44:17 jimd Exp $
//
#if !defined( _CHINSTNC_H )
#define _CHINSTNC_H

#include "ChGrRend.h"

#include <ChGraphx.h>
#include "ChGrType.h"
#include "QvNodes.h"
#include "QvState.h"
#include "GxTrnsfm.h"

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) && defined(CH_IMMED_MODE)
#include <imode.h>
#endif

/*
	Classes defined elsewhere 
*/
class ChRenderContext;
class ChQvState;
class ChQvRenderData;
class ChQvRenderBaseData;
class ChQvTextureRenderData;
class ChQvBounds;
class ChQvBuildState;
class ChColorA;

/*
	Forward declarations of classes 
*/
class ChQvInstanceIterator;
class ChQvGroupInstance;
class ChBoundsIterator;
class ChQvInstance;
class ChQvTransformationInstance;
class ChDrawIterator;
class ChConstructionIterator;
class ChHittestIterator;
class ChCollisionIterator;

class ChPipeline	 
{
	public:
	ChPipeline() {};
	virtual ChPipeline::~ChPipeline() {};
	ChPipeline(GxTransform3Wf &model, GxTransform3Wf &world2Cam, GxTransform3Wf &cam2Clip, GxTransform3Wf &clip2Screen)
	{
		Set(model, world2Cam, cam2Clip, clip2Screen);
	}
	ChPipeline * Set(GxTransform3Wf &model, GxTransform3Wf &world2Cam, GxTransform3Wf &cam2Clip, GxTransform3Wf &clip2Screen);
	GxVec3f TransformToScreen(GxVec3f& pt);
 	GxVec3f TransformToPort(GxVec3f& pt, bool & boolClipped);

	protected:
		GxTransform3Wf	m_model;
		GxTransform3Wf	m_world2Cam;
		GxTransform3Wf	m_cam2Clip;
		GxTransform3Wf	m_model2Clip;
		GxTransform3Wf	m_clip2Screen;


};

/*----------------------------------------------------------------------------
	ChQvInstance class
----------------------------------------------------------------------------*/
class ChQvInstance
{
 	friend class ChQvInstanceIterator;
	// These should be unnecessary, but MSVC prevents accessing protected virtual
	// functions without them
	friend class ChQvGroupInstance;
	friend class ChQvLODInstance;
	friend class ChQvSeparatorInstance;
	friend class ChQvSwitchInstance;
	friend class ChQvWWWInlineInstance;
	friend class ChQvWWWAnchorInstance;

	public:
		enum nodeFamily	{ group, shape, property, camera, misc };	// ???
		//enum nodeType
	protected:

	public:
		ChQvInstance();
		virtual ~ChQvInstance();

		virtual bool Draw(ChRenderContext *pRC, ChDrawIterator *pIterator) {return true;};
		virtual bool Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator) {return true;};
		virtual bool Hittest(ChRenderContext *pRC, ChHittestIterator *pIterator) {return true;};
		virtual bool CollisionTest(ChRenderContext *pRC, ChCollisionIterator *pIterator) {return true;};

		virtual bool GetBounds(ChQvBounds& bounds);
		ChRect GetBoundsExtent(ChRenderContext *pRC, ChQvBounds *pBounds = 0, bool *pboolClipped = 0, bool boolBeGenerous = true);
		bool IsBoundsDirty() { return m_boolBoundsDirty; };
										  

		virtual ChQvInstance* Attach(QvNode *pNode, ChQvBuildState *pState);
		virtual ChQvInstance* SetDirty(bool boolDirty = true)
			{ 
				m_boolBoundsDirty = m_boolRenderDirty = true;
				return this;
			};
		virtual ChQvInstance* SetTransformDirty(bool boolDirty = true) {return this;};

		ChQvGroupInstance *GetParent() { return m_pParent; };
		QvNode *GetNode() {return m_pNode;};
		ChQvInstance* SetTransform(ChQvTransformationInstance	*pTransform);
		virtual GxTransform3Wf&  GetTransform();
		virtual GxTransform3Wf  GetRendererTransform()
			{
				return GxTransform3Wf();
			}
		virtual ChQvTransformationInstance *GetTransformInstance() {return 0;};

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual void Build(ChRenderContext *pRC) {};
		virtual  ChNrFrame GetFrame() {return (m_frame ? m_frame : GetParentFrame());};
		ChNrFrame GetParentFrame();
		virtual void CreateFrame();
		bool IsConstructed() {return m_boolConstructed;};
		virtual bool CanCollapse();
		virtual bool Collapse();
		virtual bool Reconstruct(ChRenderContext *pRC) { return false;};
		#endif
		inline ChRenderContext	*GetContext() {return m_pContext;};
		virtual bool SetTexture(ChQvTextureRenderData *pTextureData, ChNrMesh mesh = 0);

		void MarkForRemoval(bool boolDelete = true);
		inline bool IsMarkedForRemoval() {return m_boolDeleteMe;};
		ChQvInstance*  SetRenderData(ChQvRenderBaseData	*pRenderData)
			{
				m_pRenderData = pRenderData; 
				if(!pRenderData) m_pNode = 0;
				return this;
			};
		inline ChQvRenderBaseData* GetRenderData() {return m_pRenderData;};
		virtual string& GetRelativeURL();

		#if 1
		virtual void Use(bool boolChildren = true, chuint32 iBump = 1);
		virtual void Release(bool boolChildren = true, chuint32 iBump = 1);
		inline int GetUsage() { return m_iUsage; };
		#endif

		void InstallScripts();
		virtual void RemoveProperty(ChQvRenderBaseData *pData) {};
		ChRenderContext * GetRC() {return m_pContext;};

	protected:
		ChQvRenderBaseData	*m_pRenderData;
		QvNode 			*m_pNode;
		bool			m_boolBoundsDirty;
		bool			m_boolRenderDirty;
		ChQvBounds		*m_pBounds;
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		ChNrFrame 		m_frame;
		bool			m_boolConstructed;
		#endif
		ChRenderContext	*m_pContext;

		bool			m_boolDeleteMe;

		int				m_iUsage;

		// Traversal state

		// matrix
		ChQvTransformationInstance	*m_pTransform;		  // Model to world

		ChQvGroupInstance *m_pParent;

		virtual void Init(ChQvBuildState *pState);
		virtual void Term();
		virtual bool ComputeBounds();
		virtual int Iterate(ChQvInstanceIterator *pIterator);
		GxVec3f Transform(const GxVec3f& v);
		GxVec3f TransformWorldToModel(const GxVec3f& v);
		ChQvInstance * GetPipeline(ChRenderContext *pRC, ChPipeline &pipeline);
		ChQvInstance * SetParent(ChQvGroupInstance *pParent) {m_pParent = pParent; return this;};
};

class ChQvInstanceHasProps
{

	public:
		ChQvInstanceHasProps() {};
		virtual ~ChQvInstanceHasProps() {}


		inline QvMaterial 			*GetMaterial() { return m_pMaterial;};
		inline QvMaterialBinding 	*GetMaterialBinding() { return m_pMaterialBinding;};
		inline QvNormal 			*GetNormal() { return m_pNormal;};
		inline QvNormalBinding 		*GetNormalBinding() { return m_pNormalBinding;};
		inline QvCoordinate3 		*GetCoordinate3() { return m_pCoordinate3;};
		inline QvTexture2 			*GetTexture2() { return m_pTexture2;};
		inline QvTexture2Transform 	*GetTexture2Transform() { return m_pTexture2Transform;};
		inline QvTextureCoordinate2 *GetTextureCoordinate2() { return m_pTextureCoordinate2;};
		inline QvShapeHints 		*GetShapeHints() { return m_pShapeHints;};
		inline QvInfo 				*GetInfo() { return m_pInfo;};
		inline QvFontStyle 			*GetFontStyle() { return m_pFontStyle;};

		void RemoveProperty(ChQvRenderBaseData *pData);
		void RemoveProperty(ChQvRenderBaseData *pData, QvNode **pNode);

	protected:
		virtual void Init(ChQvBuildState *pState, ChQvInstance *pInstance);
		virtual void Term(ChQvInstance *pInstance);

		QvMaterial 				*m_pMaterial;
		QvMaterialBinding 		*m_pMaterialBinding;
		QvNormal 				*m_pNormal;
		QvNormalBinding 		*m_pNormalBinding;
		QvCoordinate3 			*m_pCoordinate3;
		QvTexture2 				*m_pTexture2;
		QvTexture2Transform 	*m_pTexture2Transform;
		QvTextureCoordinate2 	*m_pTextureCoordinate2;
		QvShapeHints 			*m_pShapeHints;
		QvInfo					*m_pInfo;
		QvFontStyle 			*m_pFontStyle;
};


class ChQvTransformationInstance:public ChQvInstance
{
	public:
		ChQvTransformationInstance();
		virtual ~ChQvTransformationInstance();
		virtual ChQvInstance* Attach(QvNode *pNode, ChQvBuildState *pState);
		virtual ChQvInstance* SetTransformDirty(bool boolDirty = true);
		ChQvTransformationInstance* SetTransform(const GxTransform3Wf& modelTransform);
		ChQvTransformationInstance* SetSelfTransform(const GxTransform3Wf& transform);
		virtual GxTransform3Wf&  GetTransform() { return m_ModelTransform;};
		ChQvTransformationInstance * AddDependent(ChQvInstance *pDependent);
		ChQvTransformationInstance * RemoveDependent(ChQvInstance *pDependent);

		ChQvTransformationInstance* Attach(QvNode *pNode, ChQvBuildState *pState, ChQvGroupInstance *pOwner);


	protected:

		ChPtrList<ChQvInstance>	m_dependents;
		GxTransform3Wf	m_ModelTransform;		  // Model to world
		GxTransform3Wf	m_SelfTransform;		  // Own matrix transform
		virtual void Init(ChQvBuildState *pState);
		ChQvTransformationInstance * m_pPredecessor;	// Who we depend on
};

typedef ChQvTransformationInstance ChQvTransformInstance;
typedef ChQvTransformationInstance ChQvRotationInstance;
typedef ChQvTransformationInstance ChQvScaleInstance;
typedef ChQvTransformationInstance ChQvTranslationInstance;
typedef ChQvTransformationInstance ChQvMatrixTransformInstance;


class ChQvGroupInstance:public ChQvInstance, public ChQvInstanceHasProps
{
	friend class ChQvInstanceIterator;

	public:
		ChQvGroupInstance();
		virtual ~ChQvGroupInstance();

		ChQvGroupInstance * Add(ChQvInstance *pChild);
		bool  Remove(ChQvInstance *pChild);
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual void CreateFrame();
		virtual void Build(ChRenderContext *pRC);
		virtual bool Draw(ChRenderContext *pRC, ChDrawIterator *pIterator);
		virtual bool Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator);
		#endif
		virtual ChQvGroupInstance *SetupTraversalState(ChQvState &state);
		void MarkChildForRemoval(QvNode *pNode);
		inline bool HasChildrenMarkedForRemoval() {return m_boolChildPendingRemoval;};
		void RemoveMarkedChildren();
		#if 1
		virtual void Use(bool boolChildren = true, chuint32 iBump = 1);
		virtual void Release(bool boolChildren = true, chuint32 iBump = 1);
		#endif
		ChQvInstance* GetChild( int iChild);
		virtual ChQvTransformationInstance *GetTransformInstance() {return &m_transformInstance;};
		virtual ChQvInstance* Attach(QvNode *pNode, ChQvBuildState *pState);
		virtual void RemoveProperty(ChQvRenderBaseData *pData)
			{
				ChQvInstanceHasProps::RemoveProperty(pData);
			};

	protected:
		virtual void Init(ChQvBuildState *pState);
		void RestoreProp(ChQvState &state, QvNode *pProp, QvState::StackIndex stackIndex);
		ChQvInstance * InstantiateChild(QvNode *pNewChild);


	protected:
		ChPtrList<ChQvInstance>	m_children;
		virtual bool Iterate(ChQvInstanceIterator *pIterator);

		bool m_boolChildPendingRemoval;
		ChQvTransformationInstance	m_transformInstance;
};

// Iterate over children
class ChQvInstanceIterator
{
	public:
		enum iterationType {inDrawScope, all};
		enum whenVisiting {beforeChildren, afterChildren, isLeaf};
	public:
		ChQvInstanceIterator(ChRenderContext * pContext);
		ChQvInstanceIterator(ChRenderContext * pContext, ChQvInstance *pRoot );

		virtual ~ChQvInstanceIterator();

		virtual void Attach( ChQvInstance *pInst );
		virtual bool Iterate();	   // Just those in draw scope; respects lods,etc.
		virtual bool IterateAll();  // Exhaustive iteration

		virtual int DoNode(ChQvInstance& inst) {return true;};
		iterationType GetIterationType() { return m_type;};
		whenVisiting GetVisitType() { return m_visitType; };
		ChQvInstanceIterator* SetVisitType(whenVisiting visitType) {m_visitType = visitType;return this; };
		ChRenderContext * GetRenderContext() {return m_pContext;};
		bool ShouldDoKids() { return m_boolDoKids; };
		void SetDoKids(bool boolDoEm = true) { m_boolDoKids = boolDoEm; };

   protected:
		iterationType m_type;
		ChQvInstance* m_pRoot;
		whenVisiting m_visitType;
   		ChRenderContext * m_pContext;
		bool		m_boolDoKids;

   private:
											/* Disable copy constructor and
												assignment operator */

      inline ChQvInstanceIterator( const ChQvInstanceIterator& ) {}
      inline ChQvInstanceIterator& operator=( const ChQvInstanceIterator& )
      			{
      				return *this;
      			}
};


class ChConstructionIterator : public ChQvInstanceIterator
{
	enum Constants { TimeToDirty = 1000 };

	public:
		ChConstructionIterator(ChRenderContext * pContext) : 
			ChQvInstanceIterator(pContext), m_boolWorkRemains(true)
			{};

		virtual ~ChConstructionIterator() {};

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual bool Iterate();	   // Just those in draw scope; respects lods,etc.
		virtual bool IterateAll();  // Exhaustive iteration
		bool IsOKToProceed(ChQvInstance *pInst);
		void DidAShape();
		chint32 GetWorkDone() { return m_workDone; };
		bool IsCompleted() { return m_boolWorkRemains;};
		#endif

		virtual int DoNode(ChQvInstance& inst);


   protected:

		bool		m_boolWorkRemains;	 // only used for rlab
		chuint32	m_startTime;		 // only used for rlab
		chint32		m_workDone;			 // only used for rlab
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		void SayProgress(bool boolDone = false);
		#endif

   private:
											/* Disable copy constructor and
												assignment operator */

      inline ChConstructionIterator( const ChConstructionIterator& ) : ChQvInstanceIterator(0) {}
      inline ChConstructionIterator& operator=( const ChConstructionIterator& )
      			{
      				return *this;
      			}
};


class ChDrawIterator : public ChQvInstanceIterator
{
	//enum Constants { TimeToDirty = 1000 };

	public:
		ChDrawIterator(ChRenderContext * pContext) : 
			ChQvInstanceIterator(pContext)
			{};

		virtual ~ChDrawIterator() {};

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual bool Iterate();	   // Just those in draw scope; respects lods,etc.
		virtual bool IterateAll();  // Exhaustive iteration
		//bool IsOKToProceed(ChQvInstance *pInst);
		void DidAShape();
		//chint32 GetWorkDone() { return m_workDone; };
		//bool IsCompleted() { return m_boolWorkRemains;};
		#endif

		virtual int DoNode(ChQvInstance& inst);


   protected:

		//bool		m_boolWorkRemains;	 // only used for rlab
		chuint32	m_startTime;		 // only used for rlab
		//chint32		m_workDone;			 // only used for rlab
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		//void SayProgress(bool boolDone = false);
		#endif

   private:
											/* Disable copy constructor and
												assignment operator */

      inline ChDrawIterator( const ChDrawIterator& ) : ChQvInstanceIterator(0) {}
      inline ChDrawIterator& operator=( const ChDrawIterator& )
      			{
      				return *this;
      			}
};

// Iterates thru a tree, returning the instances covering the 2d screen point
// The list is -not- sorted by depth.
// If options are set to "findFirst" only one instance is returned. This is the first found,
// not necessarily the closest.
class ChHittestIterator : public ChQvInstanceIterator
{
	public:
		class ChInstanceHit
		{
			public:
				ChQvInstance	*m_pInstance;
				GxVec3f			m_pt;

			public:
				ChInstanceHit() : m_pInstance(0) {};
				ChInstanceHit(ChQvInstance	*pInstance, const GxVec3f &pt) : 
					m_pInstance(pInstance), m_pt(pt) {};
		};

	typedef ChList<ChInstanceHit> ChInstanceHitList;

	public:
		ChHittestIterator(ChRenderContext * pContext, int iX, int iY) : 
			ChQvInstanceIterator(pContext),
			m_iX(iX), m_iY(iY)
			{};

		virtual ~ChHittestIterator() {};

		virtual int DoNode(ChQvInstance& inst);

		void Add(ChQvInstance *pInstance, const GxVec3f &pt);

		ChInstanceHitList	&GetHits() { return m_instances;};
		bool GetHit( ChQvInstance *& closest, GxVec3f &pt);

		inline void GetScreenPoint(int &iX, int &iY) {iX = m_iX; iY = m_iY;};

		#if !defined(CH_IMMED_MODE)
									// Do nothing
		virtual bool Iterate() {return false;};	   
		virtual bool IterateAll() {return false;}; 
		#endif



   protected:
		int				m_iX;
		int				m_iY;
		ChInstanceHitList	m_instances;

   private:
											/* Disable copy constructor and
												assignment operator */

      inline ChHittestIterator( const ChHittestIterator& ) : ChQvInstanceIterator(0) {}
      inline ChHittestIterator& operator=( const ChHittestIterator& )
      			{
      				return *this;
      			}
};

// Iterates thru a tree, returning the instances covering the 2d screen point
// The list is -not- sorted by depth.
// If options are set to "findFirst" only one instance is returned. This is the first found,
// not necessarily the closest.
class ChCollisionIterator : public ChQvInstanceIterator
{
	public:
		class ChInstanceHit
		{
			public:
				ChQvInstance	*m_pInstance;
				//GxVec3f			m_pt;	// actually, probably want an impact vector for bouncing
				float 			m_t;		// parameter for ray (loc, dir)

			public:
				ChInstanceHit() : m_pInstance(0) {};
				ChInstanceHit(ChQvInstance	*pInstance, float t) : 
					m_pInstance(pInstance), m_t(t) {};
		};

	typedef ChList<ChInstanceHit> ChInstanceHitList;

	public:
		ChCollisionIterator(ChRenderContext * pContext, const GxVec3f & loc,  const GxVec3f &dir, float radius) : 
			ChQvInstanceIterator(pContext),
			m_loc(loc), m_dir(dir), m_radius(radius)
			{};

		virtual ~ChCollisionIterator() {};

		virtual int DoNode(ChQvInstance& inst);

		void Add(ChQvInstance *pInstance, float t);

		ChInstanceHitList	&GetHits() { return m_instances;};
		bool GetHit( ChQvInstance *& closest, float &t);

		inline GxVec3f & GetLoc() {return m_loc;};
		inline GxVec3f & GetDir() {return m_dir;};
		inline float GetRadius() {return m_radius;};

		#if !defined(CH_IMMED_MODE)
									// Do nothing
		virtual bool Iterate() {return false;};	   
		virtual bool IterateAll() {return false;}; 
		#endif

   protected:
		GxVec3f 	m_loc;
		GxVec3f 	m_dir;
		float 		m_radius;

		ChInstanceHitList	m_instances;

   private:
											/* Disable copy constructor and
												assignment operator */

      inline ChCollisionIterator( const ChCollisionIterator& ) : ChQvInstanceIterator(0) {}
      inline ChCollisionIterator& operator=( const ChCollisionIterator& )
      			{
      				return *this;
      			}
};

class ChBoundsIterator : public ChQvInstanceIterator
{
	class ChBoundsStack
	{
		public:
			ChBoundsStack(GxVec3f& upper, GxVec3f &lower, GxVec3f &center, int childCount, GxTransform3Wf &inverseTransform) :
				  m_upper(upper), m_lower(lower), m_center(center), 
				  m_childBoundsCount(childCount), m_inverseTransform(inverseTransform)
					{};
					         
	 		GxVec3f 	m_upper, m_lower, m_center;
			int 		m_childBoundsCount;
			GxTransform3Wf	m_inverseTransform;
		
	};
	public:
		ChBoundsIterator(ChRenderContext * pContext, ChQvBounds *pBounds) : 
			ChQvInstanceIterator(pContext), m_pBounds(pBounds)
			{
				LocalReset();
			};

		virtual ~ChBoundsIterator() {};

		virtual int DoNode(ChQvInstance& inst);

		ChQvBounds *GetBounds() {return m_pBounds;};

   protected:
 		GxVec3f 	m_upper, m_lower, m_center;
		int 		m_childBoundsCount;
		ChQvBounds* m_pBounds;
		ChPtrList<ChBoundsStack>	m_stack;
  		GxTransform3Wf	m_inverseTransform;

		ChBoundsIterator* LocalReset();
		void Push();
		bool Pop();
		void Accumulate();


   private:
											/* Disable copy constructor and
												assignment operator */

      inline ChBoundsIterator( const ChDrawIterator& ) : ChQvInstanceIterator(0) {}
      inline ChBoundsIterator& operator=( const ChDrawIterator& )
      			{
      				return *this;
      			}
};



class ChQvShapeInstance:public ChQvInstance, public ChQvInstanceHasProps
{
	protected:
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		ChNrMesh	m_mesh;
		bool	m_boolTransformDirty;
		#if defined(CH_IMMED_MODE)
		ChTextureHandle m_hTexture;
		#endif
		#endif

	public:
		ChQvShapeInstance();
		virtual ~ChQvShapeInstance();

		bool SetupTexture(ChRenderContext *pRC);
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual void Build(ChRenderContext *pRC);
		virtual bool SetTexture(ChQvTextureRenderData *pTextureData, ChNrMesh mesh = 0 );
		virtual void CreateFrame();
		virtual ChQvInstance* SetTransformDirty(bool boolDirty = true);
		virtual IsTransformDirty() { return m_boolTransformDirty; };
		void SetColor(const ChColorA &color, ChNrMesh mesh = 0 );

		#endif
		virtual GxTransform3Wf  GetRendererTransform()
			{
				return GetTransform();
			}
		virtual void RemoveProperty(ChQvRenderBaseData *pData)
			{
				ChQvInstanceHasProps::RemoveProperty(pData);
			};



	protected:
		virtual void Init(ChQvBuildState *pState);

};


// Lights are properties, but they still have instances that can differ
class QvPointLight;
class QvDirectionalLight;
class QvSpotLight;

class ChQvLightInstance:public ChQvInstance
{
	friend class QvSpotLight;
	friend class QvPointLight;
	friend class QvDirectionalLight;

	protected:

	public:
		ChQvLightInstance();
		virtual ~ChQvLightInstance() {}

		#if defined(CH_USE_3DR)
		virtual bool traverse(ChRenderContext *pContext) = 0;
		#endif
 		virtual ChQvInstance* Attach(QvNode *pNode, ChQvBuildState *pState);
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual void CreateFrame(GxVec3f &loc,  GxVec3f &dir);
		#endif

	protected:
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		ChNrLight	m_light;
		#endif
};

class ChQvSpotLightInstance:public ChQvLightInstance
{
	friend class QvSpotLight;

	protected:

	public:
		ChQvSpotLightInstance();
		virtual ~ChQvSpotLightInstance() {}

		#if defined(CH_USE_3DR)
		virtual bool traverse(ChRenderContext *pContext);
		#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual void Build(ChRenderContext *pContext);
		#endif
	protected:
};

class ChQvPointLightInstance:public ChQvLightInstance
{

	protected:

	public:
		ChQvPointLightInstance();
		virtual ~ChQvPointLightInstance() {}

		#if defined(CH_USE_3DR)
		virtual bool traverse(ChRenderContext *pContext);
 		#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual void Build(ChRenderContext *pContext);
		#endif

	protected:
};

class ChQvDirectionalLightInstance:public ChQvLightInstance
{

	protected:

	public:
		ChQvDirectionalLightInstance();
		virtual ~ChQvDirectionalLightInstance() {}

		#if defined(CH_USE_3DR)
		virtual bool traverse(ChRenderContext *pContext);
		#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual void Build(ChRenderContext *pContext);
		#endif

	protected:
};


class ChQvCameraInstance:public ChQvInstance
{
	protected:

	public:
		ChQvCameraInstance();
		virtual ~ChQvCameraInstance() {}


	protected:

};


// Group Node types


class ChQvSeparatorInstance:public ChQvGroupInstance
{
	protected:

	public:
		ChQvSeparatorInstance();
		virtual ~ChQvSeparatorInstance() {}


	protected:
};

class ChQvSpinGroupInstance:public ChQvGroupInstance
{
	protected:

	public:
		ChQvSpinGroupInstance();
		virtual ~ChQvSpinGroupInstance() {};

		virtual ChQvGroupInstance *SetupTraversalState(ChQvState &state);

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual void CreateFrame();

		#endif


	protected:
};

class ChQvTransformSeparatorInstance:public ChQvGroupInstance
{
	protected:

	public:
		ChQvTransformSeparatorInstance();
		virtual ~ChQvTransformSeparatorInstance() {}


	protected:
};

class ChQvLODInstance:public ChQvGroupInstance
{
	protected:

	public:
		ChQvLODInstance();
		virtual ~ChQvLODInstance();
		virtual bool Iterate(ChQvInstanceIterator *pIterator);

		void SetUpKids(ChRenderContext* pContext);
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual bool Draw(ChRenderContext *pRC, ChDrawIterator *pIterator);
		virtual bool Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator);
		void  PickAChild();
		virtual bool CanCollapse() {return false;};

		#endif
		bool  ChQvLODInstance::Purge(int iChildToKeep /* = -1 */, int iHowMuch /* = 100 */);

	protected:
		int  LookupChild(ChRenderContext * pContext);

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		int m_iCurrentChild;
		ChNrFrame *m_pFrames;
		#endif

};

class ChQvSwitchInstance:public ChQvGroupInstance
{
	protected:

	public:
		ChQvSwitchInstance();
		virtual ~ChQvSwitchInstance();
		virtual bool Iterate(ChQvInstanceIterator *pIterator);

		void SetUpKids(ChRenderContext* pContext);
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
 		virtual bool Draw(ChRenderContext *pRC, ChDrawIterator *pIterator);
		virtual bool Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator);
		void PickAChild();
		void RemoveChildFrames();
		#endif
		int LookupChild();


	protected:
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		int m_iCurrentChild;
		ChNrFrame *m_pFrames;
		#endif
};

class ChQvAnchorSensor;

class ChQvWWWAnchorInstance:public ChQvGroupInstance
{
	protected:

	public:
		ChQvWWWAnchorInstance();
		virtual ~ChQvWWWAnchorInstance();

		virtual bool Draw(ChRenderContext *pRC, ChDrawIterator *pIterator);
		virtual bool Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator);
		//virtual bool Hittest(ChRenderContext *pRC, ChHittestIterator *pIterator);
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		ChQvAnchorSensor *GetSensor() { return m_pSensor;};
		virtual bool CanCollapse() {return false;};
		#endif
		bool IsPointMap();

	protected:
		void UpdateSensor(ChRenderContext *pRC);
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		ChQvAnchorSensor *m_pSensor;
		#endif
};

class ChQvWWWInlineInstance:public ChQvGroupInstance
{
	protected:

	public:
		ChQvWWWInlineInstance();
		virtual ~ChQvWWWInlineInstance() {}
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual bool CanCollapse() {return false;};
		#endif
		virtual string& GetRelativeURL();


	protected:
		virtual bool ComputeBounds();
		virtual void Init(ChQvBuildState *pState);
};

class ChQvIFSInstance:public ChQvShapeInstance
{
	public:

		ChQvIFSInstance();
		virtual ~ChQvIFSInstance() {}
		virtual bool Draw(ChRenderContext *pRC, ChDrawIterator *pIterator);
		virtual bool Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator);

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual bool CanCollapse() {return IsConstructed() && m_boolCanCollapse;};
		#endif


	protected:

		bool IsConvex(int iFirstVertex, int iNumVerts);
		bool m_boolCanCollapse;
		virtual bool ComputeBounds();


};

class ChQvILSInstance:public ChQvShapeInstance
{

	public:
		ChQvILSInstance();
		virtual ~ChQvILSInstance() {}
		virtual bool Draw(ChRenderContext *pRC, ChDrawIterator *pIterator);
		virtual bool Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator);


		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual bool SetTexture(ChQvTextureRenderData *pTextureData, ChNrMesh mesh = 0);
		#endif

	protected:
		virtual bool ComputeBounds();

};

class ChQvSphereInstance:public ChQvShapeInstance
{
	public:
		ChQvSphereInstance();
		virtual ~ChQvSphereInstance();
		virtual bool Draw(ChRenderContext *pRC, ChDrawIterator *pIterator);
		virtual bool Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator);
		virtual bool Hittest(ChRenderContext *pRC, ChHittestIterator *pIterator);
		virtual bool CollisionTest(ChRenderContext *pRC, ChCollisionIterator *pIterator);

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		virtual bool CanCollapse() {return false;};	 // for auto lod'ing
		virtual bool Reconstruct(ChRenderContext *pRC);
		ChNrMesh BuildMesh(ChRenderContext *pRC, int iLevel);
		bool PickASphere();
		#endif


	protected:

		int GetLevel(ChRenderContext *pRC);
		int GetLevel(ChRenderContext *pRC, ChRect &rtExtent, bool boolClipped);
		virtual bool ComputeBounds();

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		ChNrMesh	m_backMesh;
		int		m_iCurrentLevel;
		int		m_iBackLevel;
		#if defined(CH_IMMED_MODE)
		RLMaterial 	m_rlMaterial;
		RLIMSurfaceInfo m_sInfo;
		ChNrColorModel m_colorModel;
		bool m_boolIsPrelit;

		#endif
		#endif

};

class ChQvCubeTextures;
class ChQvCubeInstance:public ChQvShapeInstance
{
	protected:

	public:
		ChQvCubeInstance();
		virtual ~ChQvCubeInstance() {}
		virtual bool Draw(ChRenderContext *pRC, ChDrawIterator *pIterator);
		virtual bool Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator);


	protected:
		virtual bool ComputeBounds();
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		void SetTextureCoordinates(ChQvCubeTextures *pTxMap, ChNrMesh mesh, ChNrFace face, int faceNum);
		#endif

};

class ChQvConeTextures;
class ChQvConeInstance:public ChQvShapeInstance
{
	public:
		enum Parts { Sides = 0, Bottom = 1 };

	protected:

	public:
		ChQvConeInstance();
		virtual ~ChQvConeInstance() {}
		virtual bool Draw(ChRenderContext *pRC, ChDrawIterator *pIterator);
		virtual bool Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator);


	protected:
		virtual bool ComputeBounds();
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		void SetTextureCoordinates(ChQvConeTextures *pTxMap, ChNrMesh mesh, ChNrFace face, 
			Parts part, int facet = 0);
		#endif

};

class ChQvCylinderTextures;
class ChQvCylinderInstance:public ChQvShapeInstance
{
	public:
		enum Parts { Sides = 0, Top = 1, Bottom = 2 };
	protected:

	public:
		ChQvCylinderInstance();
		virtual ~ChQvCylinderInstance() {}
		virtual bool Draw(ChRenderContext *pRC, ChDrawIterator *pIterator);
		virtual bool Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator);

	protected:
		virtual bool ComputeBounds();

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		void SetTextureCoordinates(ChQvCylinderTextures *pTxMap, ChNrMesh mesh, ChNrFace face, 
			Parts part, int facet = 0);
		#endif
};


class ChAsciiCharCache;

class ChQvAsciiTextInstance:public ChQvShapeInstance
{

	public:
		ChQvAsciiTextInstance();
		virtual ~ChQvAsciiTextInstance();
		virtual bool Draw(ChRenderContext *pRC, ChDrawIterator *pIterator);
		virtual bool Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator);

	protected:
		virtual bool ComputeBounds();

		float GetTextWidth(HFONT hFont, int index);
		float GetTextWidth(HFONT hFont, char * text);
		float GetTextHeight();
 		float GetBaselineOffset();
		HFONT CreateFont(int iAscent, float aspect = 0.);		// very Windows-y
		float GetFontLODHeight(ChRenderContext *pRC);
		ChPtrList<ChAsciiCharCache> *m_pCache;


	protected:
		ChTextureHandle m_texture;
};

class ChQvPointSetInstance:public ChQvShapeInstance
{
	protected:

	public:
		ChQvPointSetInstance();
		virtual ~ChQvPointSetInstance() {}
		virtual bool Draw(ChRenderContext *pRC, ChDrawIterator *pIterator);
		virtual bool Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator);

	protected:
		virtual bool ComputeBounds();

};


// Derived Qv classes to handle instances

// This class is -only- used for transform classes as of now: TransformationIndex
class ChQvElement : public QvElement
{

  public:
    ChQvElement() : QvElement(), m_pInst(0) {};
    virtual ~ChQvElement() {};
	ChQvInstance *GetInstance() {return m_pInst;};
	ChQvElement *SetInstance(ChQvInstance *pInst) {m_pInst = pInst; return this;};

	protected:

		ChQvInstance * m_pInst;
};



#endif // _CHINSTNC_H
