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

	Implementation for the ChQvInstance class for  Intel 3DR.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvInstnc.cpp,v 2.35 1996/06/30 19:44:15 jimd Exp $

#include "grheader.h"

#include "CvInstnc.h"
#include <QvInfo.h>
#include <QvState.h>
#include "ChMaze.h"
#include "ChRenderData.h"
#include "ChScriptData.h"
#include "ChMazDep.h"
#include "CvTrnsfm.h"
#include "CvNormal.h"
#include "CvBound.h"
#include "CvConvrt.h"
#include "CvHitTst.h"
#include "imode.h"

//#define VERIFY_NO_THREAD_CONFLICT	1
#if defined(VERIFY_NO_THREAD_CONFLICT)
static HANDLE ghCurrentAddThread = 0;
#define CheckAddThread()	\
	{if(0 == ghCurrentAddThread) ghCurrentAddThread =  GetCurrentThread();\
	ASSERT(ghCurrentAddThread == GetCurrentThread());}
#else
#define CheckAddThread()

#endif


#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
class ChCanCollapseIterator : public ChQvInstanceIterator
{

	public:
		ChCanCollapseIterator(ChRenderContext * pContext) : 
			ChQvInstanceIterator(pContext), m_boolCanCollapse(true)
			{};

		virtual ~ChCanCollapseIterator() {};

		virtual int DoNode(ChQvInstance& inst)
		{
			if(!inst.CanCollapse())
			{
				m_boolCanCollapse = true;
				return false;
			}
			return true;
		};

		bool CanCollapse() {return m_boolCanCollapse;};

   protected:

		bool		m_boolCanCollapse;	 

   private:
											/* Disable copy constructor and
												assignment operator */

      inline ChCanCollapseIterator( const ChDrawIterator& ) : ChQvInstanceIterator(0) {}
      inline ChCanCollapseIterator& operator=( const ChDrawIterator& )
      			{
      				return *this;
      			}
};
#endif
//#define COUNT_INSTANCES	1
#if defined(COUNT_INSTANCES)
static int iInstCount = 0;
#endif

/////////////////////////////////////////////////////////////////////////////////////////////
ChQvInstance::ChQvInstance() :
		m_pNode(0),
		m_pParent(0),
		m_pRenderData(0),
		m_pBounds(0),
		m_pTransform(0),
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		m_frame(0),
		m_boolConstructed(0),
		#endif
		m_pContext(0),
		m_boolBoundsDirty(true),
		m_boolRenderDirty(true),
		m_boolDeleteMe(false),
		m_iUsage(1)

{
#if defined(COUNT_INSTANCES)
	iInstCount ++;
	TRACE1("Instance count = %d\n", iInstCount);
#endif
}

ChQvInstance::~ChQvInstance()
{
#if defined(COUNT_INSTANCES)
	iInstCount --;
#endif
	if(m_pRenderData)
	{		   // TODO more graceful destruction
		if(m_pRenderData) m_pRenderData->Remove(this);
		m_pRenderData = 0;
	}
	if(m_pParent)
	{
		m_pParent->Remove(this);
		m_pParent = 0;
	}
	m_pNode=0;
	delete m_pBounds;
	m_pBounds = 0;

	if(m_pTransform)
	{
		m_pTransform->RemoveDependent(this);
	}

}

#if 1
void ChQvInstance::Use(bool boolChildren /*= true */ , chuint32 uBump /*= 1*/)
{
	m_iUsage += uBump;
	//TRACE2("Use %lx -> %d\n", UINT(this), m_iUsage);
}

void ChQvInstance::Release(bool boolChildren /*= true*/ , chuint32 uBump /*= 1*/)
{
	m_iUsage -= uBump;
	//TRACE2("Release %lx -> %d\n", UINT(this), m_iUsage);
	if(m_iUsage <= 0)
	{
		//TRACE1("Delete %lx\n", UINT(this));
		delete this;
	}
}

#endif
bool ChQvInstance::GetBounds(ChQvBounds& bounds)
{
	if(m_boolBoundsDirty)
	{
		ComputeBounds();
	}
	if(m_pBounds)
	{
		m_pBounds->SetTransform(GetTransform());	// cached transform might be out of date?
		bounds = *m_pBounds;
	}
	else
	{
		bounds.SetTransform(GetTransform());	// cached transform might be out of date?
	}

	return (m_pBounds != 0);
}

ChQvInstance* ChQvInstance::Attach(QvNode *pNode, ChQvBuildState *pState)
{
	m_pNode = pNode;
	ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)(pNode->GetRenderData());
	// Hook us together
	m_pRenderData = pRenderData;
	pRenderData->Add(this);
	ChQvGroupInstance *pParent =	pState->GetCurrentParent();
	if(pParent) pParent->Add(this);

	Init(pState);
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	Build(GetContext());
	#endif

	return this;
}

bool ChQvInstance::Iterate(ChQvInstanceIterator *pIterator)
{
	ChQvInstanceIterator::whenVisiting visit = pIterator->GetVisitType();
	pIterator->SetVisitType(ChQvInstanceIterator::isLeaf);
	bool boolKeepGoing = pIterator->DoNode(*this);
	pIterator->SetVisitType(visit);
	return boolKeepGoing;
}

void ChQvInstance::Init(ChQvBuildState *pState)
{                                                                         
	ChRenderContext *pRC = pState->GetView()->GetRenderContext();
	//SetTransform(pRC->GetModelTransform());							 
	m_pContext = pRC;

	ChQvElement *pElt = (ChQvElement *)(pState->getTopElement(QvState::TransformationIndex));
	if(pElt)
	{
		ASSERT(pElt->GetInstance());
		m_pTransform = (ChQvTransformationInstance*)(pElt->GetInstance());
		m_pTransform->AddDependent(this);
	}
	else
	{
		m_pTransform = pRC->GetDefaultTransform();
		m_pTransform->AddDependent(this);
	}
}

GxVec3f ChQvInstance::Transform(const GxVec3f& v)
{
	return GetTransform() * v;
};

GxVec3f ChQvInstance::TransformWorldToModel(const GxVec3f& v)
{
	return GetTransform().Inverse() * v;
};

GxTransform3Wf&  ChQvInstance::GetTransform() 
{ 
	return m_pTransform->GetTransform();
};

ChQvInstance* ChQvInstance::SetTransform(ChQvTransformationInstance	*pTransform)
{
	m_pTransform = pTransform;
	return this;
}


ChQvInstance * ChQvInstance::GetPipeline(ChRenderContext *pRC, ChPipeline &pipeline)
{
	GxTransform3Wf modelCamera = pRC->GetWorldToCameraTransform();	// world to camera
	GxTransform3Wf cameraToClip = pRC->GetCameraToClipTransform();
	GxTransform3Wf clipToScreen = pRC->GetClipToScreenTransform();

	pipeline.Set(GetTransform(), modelCamera, cameraToClip, clipToScreen);
	return this;
}

void ChQvInstance::Term()
{
	// placeholder 
}

bool ChQvInstance::ComputeBounds()
{
	// Every class needs to do their own. Maybe this should be pure virtual
	return false;
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
void ChQvInstance::CreateFrame()
{
	if(GetParent())
	{
		m_frame = GetContext()->CreateFrame(GetParent()->GetFrame());
	}
	else
	{
		m_frame = GetContext()->CreateFrame(m_pContext->GetFrame());
	}
	ChNrFrameAddTransform(m_frame, CombineBefore, *(GetTransform().GetMatrix()));
	ChNrObjectSetAppData(m_frame, (unsigned long)this);
	D3DRelease(m_frame);
	InstallScripts();
};

ChNrFrame ChQvInstance::GetParentFrame()
{
	ChNrFrame	frame = 0;
	if(GetParent())
	{
		frame = GetParent()->GetFrame();
	}
	if(!frame)
	{
		frame = m_pContext->GetFrame();
	}
	
	return frame;
};

bool ChQvInstance::CanCollapse()
{
	if(GetParent() == 0) return false;	 // never collapse the root
	return true;
};

bool ChQvInstance::Collapse()
{
	#if 0	 // not needed for now
	if(m_frame)
	{
		ChNrFrame *pFrames;
		int count;

		ChNrFrameGetChildren(m_frame, &count, &pFrames);
		if(count)
		{
			ChNrMesh mesh;
			mesh = ChNrFrameBuildMesh(m_frame);

			for(int j=0; j < count; j++)
			{
				ChNrFrame child = pFrames[j];
				ChNrFrameRemoveChild(m_frame, child);
			}
			ChNrFrameAddVisual(m_frame, mesh);
			ChNrObjectSetAppData(mesh, (unsigned long)this);
		}
		RLFree(pFrames);
	}
	#endif
	return true;
}

#endif


void ChQvInstance::InstallScripts()
{
	ChQvRenderBaseData *pData =  (ChQvRenderBaseData *)(GetNode()->GetRenderData());
	if(pData)
	{
		MyInstallScriptIterator	iterator(*pData, this);
		iterator.IterateScripts();
	}
}

bool ChQvInstance::SetTexture(ChQvTextureRenderData *pTextureData, ChNrMesh mesh)
{
	return false;	// false says nothing happened
}


void ChQvInstance::MarkForRemoval(bool boolDelete /*= true*/)
{
	m_boolDeleteMe = boolDelete;
	m_pNode = 0;		// break the link with the Node, it's probably going away
}


string& ChQvInstance::GetRelativeURL()
{
	if(GetParent()) return GetParent()->GetRelativeURL();

	return (((ChMazeWnd *)(GetContext()->GetWnd()))->GetCurrentURL());
}

// Transformation Instance Classes
ChQvTransformationInstance::ChQvTransformationInstance() : ChQvInstance(), m_pPredecessor(0)
{}

ChQvTransformationInstance::~ChQvTransformationInstance()
{
	while(!m_dependents.IsEmpty())
	{
		ChQvInstance *pDependent = m_dependents.RemoveHead();
		if(pDependent) pDependent->SetTransform( 0 );
	}

}

void ChQvTransformationInstance::Init(ChQvBuildState *pState)
{
	// Don't do the usual stuff...	 
	ChQvElement *pElt = (ChQvElement *)(pState->getTopElement(QvState::TransformationIndex));
	// Top is us, we go one deeper for who we depend on
	if(pElt->next)
	{
				// Make this a dependent of instance that -was- top
		ChQvElement *pPrevTop = (ChQvElement *)(pElt->next);
		m_pPredecessor = ((ChQvTransformationInstance*)(pPrevTop->GetInstance()));
		m_pPredecessor->AddDependent(this);
	}
	m_pTransform = m_pPredecessor;
	ChRenderContext *pRC = pState->GetView()->GetRenderContext();
	m_pContext = pRC;
	SetTransform(pRC->GetModelTransform());
}

ChQvInstance* ChQvTransformationInstance::Attach(QvNode *pNode, ChQvBuildState *pState)
{	  // TODO zap this, unnecessary	????
	//ChQvInstance::Attach(pNode, pState); 
	m_pNode = pNode;
	ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)(pNode->GetRenderData());
	// Hook us together
	m_pRenderData = pRenderData;
	pRenderData->Add(this);
	ChQvGroupInstance *pParent =	pState->GetCurrentParent();
	//if(pParent) pParent->Add(this);

	Init(pState);


	return this;
}

ChQvInstance* ChQvTransformationInstance::SetTransformDirty(bool boolDirty)
{	 
	// recurse to force recompute of all dependents
	if(boolDirty)
	{
		if(m_pPredecessor)
		{
			m_ModelTransform = m_pPredecessor->m_ModelTransform.Compose(m_SelfTransform);	// ?????????
			//m_ModelTransform = m_SelfTransform.Compose(m_pPredecessor->m_ModelTransform);	// ?????????
			//m_ModelTransform = m_pPredecessor->m_ModelTransform * m_SelfTransform;	// ?????????
		}
		else
		{
			m_ModelTransform =  m_SelfTransform;
		}
	}
	if(!m_dependents.IsEmpty())
	{
		ChPosition pos = m_dependents.GetHeadPosition();
		while(pos)
		{
			ChQvInstance *pInst = m_dependents.GetNext(pos);
			pInst->SetTransformDirty(boolDirty);
		}
	}
	return this;
}

ChQvTransformationInstance* ChQvTransformationInstance::SetTransform(const GxTransform3Wf& modelTransform)
{
	m_ModelTransform = modelTransform;
	return this;
}

ChQvTransformationInstance* ChQvTransformationInstance::SetSelfTransform(const GxTransform3Wf& transform)
{
	m_SelfTransform = transform;
	return this;
}

ChQvTransformationInstance* ChQvTransformationInstance::AddDependent(ChQvInstance *pDependent)
{
	CheckAddThread();
	m_dependents.AddTail(pDependent);
	return this;
}

ChQvTransformationInstance* ChQvTransformationInstance::RemoveDependent(ChQvInstance *pDependent)
{
	CheckAddThread();	
	if(!m_dependents.IsEmpty())
	{

		ChPosition pos = m_dependents.Find(pDependent);
		if(pos){
			m_dependents.Remove(pos);
		}
		pDependent->SetTransform( 0 );
	}
	return this;
}

//	ChQvGroupInstance
ChQvGroupInstance::ChQvGroupInstance() : ChQvInstance(), m_boolChildPendingRemoval(false)
{
}

ChQvGroupInstance::~ChQvGroupInstance()
{
	// Delete children
	CheckAddThread();
	while(!m_children.IsEmpty())
	{
		ChQvInstance* pChild = m_children.RemoveHead();
		//delete pChild;
		//pChild->SetParent(0);
		//if(pChild) pChild->Release();		YIKES!!!!!!!!!!		DOUBLE DELETE!!
		if(pChild) pChild->m_pParent = 0;		
	}
	ChQvInstanceHasProps::Term(this);
}

ChQvInstance* ChQvGroupInstance::Attach(QvNode *pNode, ChQvBuildState *pState)
{
	ChQvInstance::Attach(pNode, pState); 

	// Add the group's transform instance onto the stack
	ChQvElement *elt = new ChQvElement;					      
	elt->data = pNode;							      
	elt->type = QvElement::Transform;					      
	pState->addElement(QvState::TransformationIndex, elt);
	ChQvTransformationInstance *pTransformInstance = GetTransformInstance();
	pTransformInstance->Attach(pNode, pState, this);
	
	GxTransform3Wf mat;
	pTransformInstance->SetSelfTransform(mat);

	elt->SetInstance(pTransformInstance);


	return this;
}

ChQvTransformationInstance* ChQvTransformationInstance::Attach(QvNode *pNode, ChQvBuildState *pState, ChQvGroupInstance *pOwner)
{
	m_pNode = pNode;
	ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)(pNode->GetRenderData());
	// Hook us together
	//m_pRenderData = pRenderData;
	m_pRenderData = 0;
	// We don't add to renderdata or parent, because we are not an instance of Group

	Init(pState);
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	Build(GetContext());
	#endif

	return this;
}


#if 1

void ChQvGroupInstance::Use(bool boolChildren /*= true */, chuint32 uBump /*= 1*/)
{
	m_iUsage += uBump;
	//TRACE2("Use %lx -> %d (grp)\n", UINT(this), m_iUsage);

	if(boolChildren && !m_children.IsEmpty())
	{
		ChPosition pos = m_children.GetHeadPosition();
		while(pos)
		{
			ChQvInstance *pChild = m_children.GetNext(pos);
			pChild->Use(boolChildren);
		}

	}
}

void ChQvGroupInstance::Release(bool boolChildren /*= true*/, chuint32 uBump /*= 1*/)
{
	m_iUsage -= uBump;
	//TRACE2("Release %lx -> %d (grp)\n", UINT(this), m_iUsage);
	if(boolChildren && !m_children.IsEmpty())
	{
		ChPosition pos = m_children.GetHeadPosition();
		while(pos)
		{
			ChQvInstance *pChild = m_children.GetNext(pos);
			pChild->Release(boolChildren, uBump);
		}

	}
	if(m_iUsage <= 0)
	{
		delete this;
	}
}

#endif
void ChQvGroupInstance::Init(ChQvBuildState *pState)
{
	ChQvInstance::Init(pState);
	ChQvInstanceHasProps::Init(pState, this);
}

void ChQvGroupInstance::RestoreProp(ChQvState &state, QvNode *pProp, QvState::StackIndex stackIndex)
{
    QvElement *elt = new QvElement;					
    elt->data = pProp;							
    state.addElement(stackIndex, elt);
}

ChQvGroupInstance *ChQvGroupInstance::SetupTraversalState(ChQvState &state)
{	

	ChRenderContext *pRC = state.GetView()->GetRenderContext();
	pRC->SetModelTransform(GetTransform());

								///  set up stack to have proper transform instance at top to
								// inherit into subtree 
	ChQvElement *elt = new ChQvElement;					
    elt->data = m_pTransform->GetNode();
    elt->SetInstance(m_pTransform);							
    state.addElement(QvState::TransformationIndex, elt);
							   // Now all the other simpler props
	RestoreProp(state, GetMaterial(), QvState::MaterialIndex );
	RestoreProp(state, GetMaterialBinding(), QvState::MaterialBindingIndex );
	RestoreProp(state, GetNormal(), QvState::NormalIndex );
	RestoreProp(state, GetNormalBinding(), QvState::NormalBindingIndex );
	RestoreProp(state, GetCoordinate3(), QvState::Coordinate3Index );
	RestoreProp(state, GetTextureCoordinate2(), QvState::TextureCoordinate2Index );
	RestoreProp(state, GetTexture2Transform(), QvState::Texture2TransformationIndex);
	RestoreProp(state, GetShapeHints(), QvState::ShapeHintsIndex );
	RestoreProp(state, GetInfo(), QvState::InfoIndex );
	RestoreProp(state, GetFontStyle(), QvState::FontStyleIndex );

	return this;
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#if (defined(CH_USE_RLAB))
void GroupCallback(ChNrFrame frame, void * arg)
#else
void GroupCallback(ChNrFrame frame, void * arg, float delta)
#endif
{
	#if defined(CH_VRML_EVENTS)
	ChQvGroupInstance *pInst = (ChQvGroupInstance *)arg;
	if(pInst->HasChildrenMarkedForRemoval())pInst->RemoveMarkedChildren();
	#endif
}


void ChQvGroupInstance::CreateFrame()
{
	if(GetParent())
	{
		m_frame = GetContext()->CreateFrame(GetParent()->GetFrame());
	}
	else
	{
		m_frame = GetContext()->CreateFrame(m_pContext->GetFrame());
	}
	// Difference is that we don't do this: ChNrFrameAddTransform(m_frame, CombineBefore, *(GetTransform().GetMatrix()));
	ChNrObjectSetAppData(m_frame, (unsigned long)this);

	// Now add the callback for removing unwanted children
	ChNrFrameAddCallback(m_frame, GroupCallback, this);
	D3DRelease(m_frame);
	InstallScripts();
};

// Callback to collapse mesh while rendering
void CollapseFrameCallback(ChNrFrame frame, void * arg)
{
	#if 0
	ChQvLODInstance *pInst = (ChQvLODInstance *)arg;
	pInst->Collapse();
	ChNrFrameRemoveCallback(frame, CollapseFrameCallback, pInst);
	#endif
}

bool ChQvGroupInstance::Draw(ChRenderContext *pRC, ChDrawIterator *pIterator)
{
	ASSERT(m_frame);
	return true;
}

bool ChQvGroupInstance::Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator)
{
	ASSERT(m_frame);
	#if 0
	// Collapsing causes crashes in RL wehn we add the new mesh - ???
	if(CanCollapse())
	{
		pRC->LockScene();
		ChCanCollapseIterator iterator(pRC);
		iterator.Attach(this);
		iterator.IterateAll();
		if(iterator.CanCollapse())
		{
			ChNrFrameAddCallback(m_frame, CollapseFrameCallback, this);
		}
		pRC->UnlockScene();
	}
	#endif
	return true;
}


void ChQvGroupInstance::Build(ChRenderContext *pRC)
{
	ASSERT(m_frame == 0);
	CreateFrame();
}
void ChQvShapeInstance::Build(ChRenderContext *pRC)
{
	ASSERT(m_frame == 0);
	CreateFrame();
}

#endif

ChQvGroupInstance * ChQvGroupInstance::Add(ChQvInstance *pChild)
{
	CheckAddThread();
	if(pChild->m_pParent)
	{
		m_pParent->Remove(pChild);
	}
	m_children.AddTail(pChild);
	pChild->m_pParent = this;

	// Adjust the child's usage count to match the parent
	// This means any construction threads will decrement 
	// correctly.
	int iUsage = GetUsage() - pChild->GetUsage();
	if(iUsage > 0) pChild->Use(true, chuint32(iUsage));

	return this;
}

bool ChQvGroupInstance::Remove(ChQvInstance *pChild)
{
	CheckAddThread();
	if(m_children.IsEmpty()) return false;
	ChPosition pos = m_children.Find(pChild);
	if(pos)
	{
		m_children.Remove(pos);
		pChild->m_pParent = 0;
	}
	//ASSERT(! m_children.Find(pChild)); // Should only be one copy! 
	return (pos != 0);
}

ChQvInstance* ChQvGroupInstance::GetChild( int iChild)
{
	// result is only valid if all children were instatniated,
	// and none have been deleted yet
	ChQvInstance *pChild = 0;
	if(!m_children.IsEmpty())
	{
		ChPosition pos = m_children.FindIndex(iChild);
		if(pos)
		{
			pChild = m_children.Get(pos);
		}
	}
	return pChild;
}

bool ChQvGroupInstance::Iterate(ChQvInstanceIterator *pIterator)
{
								// Visit self pre
	pIterator->SetVisitType(ChQvInstanceIterator::beforeChildren);
	pIterator->SetDoKids(true); 
	bool boolKeepGoing = pIterator->DoNode(*this);

								// Visit kids if any
	if(pIterator->ShouldDoKids() && !m_children.IsEmpty())
	{
		ChPosition pos = m_children.GetHeadPosition();
		while(pos && boolKeepGoing)
		{
			pIterator->SetVisitType(ChQvInstanceIterator::isLeaf);
			ChQvInstance *pChild = m_children.GetNext(pos);
			boolKeepGoing = pChild->Iterate(pIterator);
		}
	}
								// Visit self post
	pIterator->SetDoKids(true); 
	if(boolKeepGoing)
	{
		pIterator->SetVisitType(ChQvInstanceIterator::afterChildren);
		boolKeepGoing = pIterator->DoNode(*this);
	}
	return boolKeepGoing;
}

void  ChQvGroupInstance::MarkChildForRemoval(QvNode *pNode)
{
	m_boolChildPendingRemoval = true;

	if(!m_children.IsEmpty())
	{
		ChPosition pos = m_children.GetHeadPosition();
		while(pos)
		{
			ChQvInstance *pChild = m_children.GetNext(pos);
			if( pChild->GetNode() == pNode ) pChild->MarkForRemoval();
		}
	}
}

void ChQvGroupInstance::RemoveMarkedChildren()
{
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	if(!m_children.IsEmpty())
	{
		//	m_pContext->LockConstruction();
		ChPosition pos = m_children.GetHeadPosition();
		TRACE("Removing marked children\n");
		while(pos)
		{
			ChQvInstance *pChild = m_children.GetNext(pos);
			if( pChild->IsMarkedForRemoval() )
			{
				ChNrFrameRemoveChild(m_frame, pChild->GetFrame());
				//delete pChild;
				pChild->Release();
			}
		}
		//	m_pContext->UnlockConstruction();
	}
	#endif
	m_boolChildPendingRemoval = false;
};

ChQvInstance * ChQvGroupInstance::InstantiateChild(QvNode *pNewChild)
{
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	ChQvBuildState bldIt((ChMazeWnd*)(GetContext()->GetWnd()));

	// Alternative idea, setCurrentParent(0), then extract it from
	// state and add to parent??
	bldIt.SetCurrentParent(this);
	SetupTraversalState(bldIt);
	pNewChild->traverse(&bldIt);

	// Now construct them for RLab 
	ChQvInstance *pChildInst = 	(m_children.IsEmpty() ? 0 : m_children.GetTail());
	if(pChildInst)
	{
		GetContext()->StartConstruction(pChildInst);
	}

	return pChildInst;
	#else
	return 0;
	#endif
}

//////////////////////////////////////////////////////////////////////


// Iterators

ChQvInstanceIterator::ChQvInstanceIterator(ChRenderContext * pContext) :
	m_pRoot(0), m_pContext(pContext), m_boolDoKids(true)
{
}

ChQvInstanceIterator::ChQvInstanceIterator(ChRenderContext * pContext, ChQvInstance* pRoot ) :
	m_pRoot(0), m_pContext(pContext), m_boolDoKids(true)
{
	Attach(pRoot);
}

ChQvInstanceIterator::~ChQvInstanceIterator()
{
}

void ChQvInstanceIterator::Attach( ChQvInstance *pInst )
{
	m_pRoot = pInst;
}

bool ChQvInstanceIterator::Iterate()	   // Just those in draw scope; respects lods,etc.
{
	m_type = inDrawScope;
	if(!m_pRoot) return false;
	return m_pRoot->Iterate(this);
}

int ChQvInstanceIterator::IterateAll()  // Exhaustive iteration
{
	m_type = all;
	if(!m_pRoot) return false;
	return m_pRoot->Iterate(this); 
}

int ChDrawIterator::DoNode(ChQvInstance& inst)
{
	bool boolKeepGoing = true;
	if(GetVisitType() == isLeaf || GetVisitType() == afterChildren)
	{
		boolKeepGoing = inst.Draw(m_pContext, this);
	}

	return boolKeepGoing;
}
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))


bool ChDrawIterator::Iterate()	  // Just those in draw scope; respects lods,etc.
{
	m_startTime = ::GetTickCount();
	bool retVal =  ChQvInstanceIterator::Iterate();
	return retVal;
}
	  
bool ChDrawIterator::IterateAll()  // Exhaustive iteration
{
	m_startTime = ::GetTickCount();
	bool retVal = ChQvInstanceIterator::IterateAll();
	return retVal;
}  
#endif

int ChConstructionIterator::DoNode(ChQvInstance& inst)
{
	bool boolKeepGoing = true;
	if(GetVisitType() == isLeaf || GetVisitType() == afterChildren)
	{
		boolKeepGoing = inst.Construct(m_pContext, this);
	}

	if(!boolKeepGoing) m_boolWorkRemains = true;	// halted with work to do
	
	return boolKeepGoing;
}
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

bool ChConstructionIterator::IsOKToProceed(ChQvInstance *pInst)
{
	if ( GetRenderContext()->ContinueConstruction() && (!pInst || (pInst->GetNode() && pInst->GetRenderData())))
	{ 
		// Must call UnlockScene if this succeeds!
		if(GetRenderContext()->IsThreaded())
		{
			GetRenderContext()->LockScene();
			//GetRenderContext()->LockQv();		   // Lock tree so other threads don't kill our data
		}
		else
		{
			// Check work done and elapsed time, and return false if exceeded
			//#pragma message("nonthreaded not done")
			int iMaxMsgs = 0;
			CWinThread* pThread = AfxGetThread();
			while ( GetRenderContext()->ContinueConstruction() && iMaxMsgs < 100 )
			{
				MSG msg;

				if (::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE) )
				{

					if ( msg.message == WM_VRML_PARSE_DONE )
					{  // if there is a new scene to load, we should abort
					   // construction for the current scene. The message WM_VRML_PARSE_DONE
					   // should be retrieved from the main message loop, this guarantees that
					   // there is no construction going on.
						return false;
					}

					if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
					{
						iMaxMsgs++; // Num messages processed
						::DispatchMessage(&msg);
					}
					// allow user-interface updates
					pThread->OnIdle(-1);
				}
				else
				{
					break;
				}
			}
			if ( !GetRenderContext()->ContinueConstruction() )
			{
				return false;
			}
		}
		return true;
	}
	else
	{  // Construction has been canceled
		return false;
	}
}

void ChConstructionIterator::DidAShape()
{
	m_workDone ++;

	GetRenderContext()->IncrementShapeCount();

	if(GetRenderContext()->IsThreaded())
	{
		if(::GetTickCount() - m_startTime > TimeToDirty || ::GetTickCount() < m_startTime)
		{
			GetRenderContext()->SetDirty();
			m_startTime = ::GetTickCount();
			SayProgress();
		}
	}
	else
	{
		GetRenderContext()->SetDirty();		  // Set dirty for every piece of work
	}
}

void ChConstructionIterator::SayProgress(bool boolDone)
{
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	ChMazeWnd *pWnd = (ChMazeWnd *)(m_pContext->GetWnd());
	if(boolDone)
	{	 // PRITHAM: Please figure out how to do this
		pWnd->WriteStatus( PROGRESS_MSG_1 );
	}
	else
	{
		pWnd->WriteStatus( PROGRESS_MSG_2 );
	}
	#endif
}

bool ChConstructionIterator::Iterate()	  // Just those in draw scope; respects lods,etc.
{
	m_startTime = ::GetTickCount();
	m_workDone = 0;
	SayProgress();
	bool retVal =  ChQvInstanceIterator::Iterate();
	SayProgress(true);
	return retVal;
}
	  
bool ChConstructionIterator::IterateAll()  // Exhaustive iteration
{
	m_startTime = ::GetTickCount();
	m_workDone = 0;
	SayProgress();
	bool retVal = ChQvInstanceIterator::IterateAll();
	SayProgress(true);		
	return retVal;
}  
#endif

// Pipeline

ChPipeline * ChPipeline::Set(GxTransform3Wf &model, GxTransform3Wf &world2Cam, GxTransform3Wf &cam2Clip, GxTransform3Wf &clip2Screen)
{
	m_model = model;
	m_world2Cam = world2Cam;
	m_cam2Clip = cam2Clip;
	m_clip2Screen = clip2Screen;

	m_model2Clip = cam2Clip;
	m_model2Clip *= world2Cam;
	m_model2Clip *= model;

	return this;
}

GxVec3f ChPipeline::TransformToScreen(GxVec3f& pt)
{
	GxVec3f newPt;
	float w;

	newPt = m_model2Clip.TransformW(pt, w);
	newPt *= 1. / w;
	newPt = m_clip2Screen * newPt;
	//newPt.y() = -newPt.y(); 
	return newPt;
}


GxVec3f ChPipeline::TransformToPort(GxVec3f& pt, bool & boolClipped)
{
	GxVec3f p;
	float w;

	p = m_model2Clip.TransformW(pt, w);
	boolClipped = (p.x() <= -w || p.x() >= w || p.y() <= -w || p.y() >= w || p.z() <= 0. || p.z() >= w);
	p *= 1. / w;
	GxTransform3Wf clip2Port = m_clip2Screen;
	(*(clip2Port.GetMatrix()))[1][1] = -(*(clip2Port.GetMatrix()))[1][1];
	(*(clip2Port.GetMatrix()))[1][3] = -(*(clip2Port.GetMatrix()))[1][3];
	
	p = clip2Port * p;
	return p;
}




// end of file
