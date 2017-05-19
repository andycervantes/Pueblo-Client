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

	Implementation for the traversal of a VRML QV tree into Intel 3DR.

----------------------------------------------------------------------------*/

#include "grheader.h"


#include <ChCore.h>

#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
#include "ChGrMod.h"
#endif

#if defined( CH_ARCH_16 )
#include <QvElemnt.h> 
#else
#include <QvElement.h> 
#endif
#include <QvNodes.h>
#include <QvState.h>
#ifdef CH_MSW
#if defined( CH_ARCH_16 )
#include <UnknNode.h>
#else
#include <QvUnknownNode.h>
#endif
#include <windows.h>
#endif
#ifdef HUGE
#undef HUGE
#endif
#include <math.h>
#include <strstrea.h>
#include "ChMaze.h"
#include "ChMazDep.h"
#include "ChRender.h"
#include "ChSphere.h"
#include "CvType.h"

#include "CvBound.h"
#include "CvConvrt.h"
#include "CvMaterl.h"
#include "CvInstnc.h"
#include "CvTextur.h"
#include "CvQuery.h"
#include "CvTrnsfm.h"
#include "CvNormal.h"
#include "ChScriptData.h"

#include <QvChildList.h>

#define CH_WANT_TEXTURED_BACKGROUNDS	1

//////////////////////////////////////////////////////////////////////////////
//
// Traversal code for all nodes for Intel 3dr and Reality Lab. 
// The default method (in QvNode) does
// nothing. Because traverse() is defined in the header for ALL node
// classes, each one has an implementation here.
//
//////////////////////////////////////////////////////////////////////////////



// Standard invalidate for nodes - virtual 
void QvNode::Invalidate(ChRenderContext *pRC)
{
	pRC->SetDirty()->GetWnd()->InvalidateRect(0, 0);
}
    
#if defined( NO_TEMPLATES )    

#else
// Node editing functions

template <class aType>
void swap(aType& a, aType& b)
{
	aType tmp;
	tmp = a;
	a = b;
	b = tmp;
}     
#endif

#define DEFAULT_EDIT_NODE(className)	\
void									\
EditNode(className *a, className *b)      \
{									      \
}

void EditNode(QvPerspectiveCamera *pNode, QvPerspectiveCamera *src)
{
	pNode->position			= src->position;
	pNode->orientation		= src->orientation;
	pNode->focalDistance	= src->focalDistance;
	pNode->heightAngle		= src->heightAngle;

	if(pNode->GetRenderData()) pNode->GetRenderData()->SetDirty();
}

void EditNode(QvOrthographicCamera *pNode, QvOrthographicCamera *src)
{
	pNode->position			= src->position;
	pNode->orientation		= src->orientation;
	pNode->focalDistance	= src->focalDistance;
	pNode->height			= src->height;

	if(pNode->GetRenderData()) pNode->GetRenderData()->SetDirty();
}

class ChQvTransformEditIterator : public ChQvRenderBaseDataIterator
{
	public:
		ChQvTransformEditIterator(ChQvRenderBaseData &data, const GxTransform3Wf& transform); 
		virtual bool DoInstance(ChQvInstance &instance);
	protected:
		GxTransform3Wf m_mat;
};

ChQvTransformEditIterator::ChQvTransformEditIterator(ChQvRenderBaseData &data, const GxTransform3Wf& transform) :
	   ChQvRenderBaseDataIterator(data), m_mat(transform)
{
};

bool ChQvTransformEditIterator::DoInstance(ChQvInstance &instance)
{
	ChQvTransformationInstance *pInstance = (ChQvTransformationInstance *)&instance;
	pInstance->SetSelfTransform(m_mat);
	instance.SetTransformDirty();
	return true;
};

void EditNode(QvTransform *pNode, QvTransform *src)
{
	pNode->center= src->center;
	pNode->scaleOrientation= src->scaleOrientation;
	pNode->scaleFactor= src->scaleFactor;
	pNode->rotation= src->rotation;
	pNode->translation= src->translation;

	GxTransformF_t mat;
	GetTransform(pNode, mat);
	ChQvRenderBaseData * pData =  (ChQvRenderBaseData *)(pNode->GetRenderData());
	ChQvTransformEditIterator iterator(*pData, mat);
	iterator.Iterate();
}
void EditNode(QvRotation *pNode, QvRotation *src)
{
	pNode->rotation = src->rotation;

	GxTransformF_t mat;
	GetTransform(pNode, mat);
	ChQvRenderBaseData * pData =  (ChQvRenderBaseData *)(pNode->GetRenderData());
	ChQvTransformEditIterator iterator(*pData, mat);
	iterator.Iterate();
}
void EditNode(QvMatrixTransform *pNode, QvMatrixTransform *src)
{
	pNode->matrix = src->matrix;

	GxTransformF_t mat;
	GetTransform(pNode, mat);
	ChQvRenderBaseData * pData =  (ChQvRenderBaseData *)(pNode->GetRenderData());
	ChQvTransformEditIterator iterator(*pData, mat);
	iterator.Iterate();
}
void EditNode(QvTranslation *pNode, QvTranslation *src)
{
	pNode->translation = src->translation;

	GxTransformF_t mat;
	GetTransform(pNode, mat);
	ChQvRenderBaseData * pData =  (ChQvRenderBaseData *)(pNode->GetRenderData());
	ChQvTransformEditIterator iterator(*pData, mat);
	iterator.Iterate();
}
void EditNode(QvScale *pNode, QvScale *src)
{
	pNode->scaleFactor =  src->scaleFactor;

	GxTransformF_t mat;
	GetTransform(pNode, mat);
	ChQvRenderBaseData * pData =  (ChQvRenderBaseData *)(pNode->GetRenderData());
	ChQvTransformEditIterator iterator(*pData, mat);
	iterator.Iterate();
}    
void EditNode(QvSwitch *pNode, QvSwitch *src)
{
	pNode->whichChild =  src->whichChild;
}    

#if defined( NO_TEMPLATES )
bool DoNodeEditCommand(QvPerspectiveCamera *pNode, QvState *qstate)
{
	bool boolSubed = false;
	ChQvState * state = (ChQvState *)qstate;

	if(state->GetType() == ChQvState::editNode)
	{
		{
			if(	pNode->getName() == state->GetNode()->getName())
			{

				EditNode(pNode,(QvPerspectiveCamera*)(state->GetNode())); 
				// persp camera only
				state->SetCmdDone( true);
				boolSubed = true;
			}
		}
	}
	return boolSubed;		// we did not do substitiution
}   


bool DoNodeEditCommand(QvTransform *pNode, QvState *qstate)
{
	bool boolSubed = false;
	ChQvState * state = (ChQvState *)qstate;

	if(state->GetType() == ChQvState::editNode)
	{
		{
			if(	pNode->getName() == state->GetNode()->getName())
			{

				EditNode(pNode,(QvTransform*)(state->GetNode())); 
				// persp camera only
				state->SetCmdDone( true);
				boolSubed = true;
			}
		}
	}
	return boolSubed;		// we did not do substitiution
}    
bool DoNodeEditCommand(QvRotation *pNode, QvState *qstate)
{
	bool boolSubed = false;
	ChQvState * state = (ChQvState *)qstate;

	if(state->GetType() == ChQvState::editNode)
	{
		{
			if(	pNode->getName() == state->GetNode()->getName())
			{

				EditNode(pNode,(QvRotation*)(state->GetNode())); 
				// persp camera only
				state->SetCmdDone( true);
				boolSubed = true;
			}
		}
	}
	return boolSubed;		// we did not do substitiution
}    
bool DoNodeEditCommand(QvMatrixTransform *pNode, QvState *qstate)
{
	bool boolSubed = false;
	ChQvState * state = (ChQvState *)qstate;

	if(state->GetType() == ChQvState::editNode)
	{
		{
			if(	pNode->getName() == state->GetNode()->getName())
			{

				EditNode(pNode,(QvMatrixTransform*)(state->GetNode())); 
				// persp camera only
				state->SetCmdDone( true);
				boolSubed = true;
			}
		}
	}
	return boolSubed;		// we did not do substitiution
}    
bool DoNodeEditCommand(QvTranslation *pNode, QvState *qstate)
{
	bool boolSubed = false;
	ChQvState * state = (ChQvState *)qstate;

	if(state->GetType() == ChQvState::editNode)
	{
		{
			if(	pNode->getName() == state->GetNode()->getName())
			{

				EditNode(pNode,(QvTranslation*)(state->GetNode())); 
				// persp camera only
				state->SetCmdDone( true);
				boolSubed = true;
			}
		}
	}
	return boolSubed;		// we did not do substitiution
}    

bool DoNodeEditCommand(QvScale *pNode, QvState *qstate)
{
	bool boolSubed = false;
	ChQvState * state = (ChQvState *)qstate;

	if(state->GetType() == ChQvState::editNode)
	{
		{
			if(	pNode->getName() == state->GetNode()->getName())
			{

				EditNode(pNode,(QvScale*)(state->GetNode())); 
				// persp camera only
				state->SetCmdDone( true);
				boolSubed = true;
			}
		}
	}
	return boolSubed;		// we did not do substitiution
}    
 
#else
//
// Change a node to the one in the state command
template <class aType>
bool DoNodeEditCommand(aType *pNode, QvState *qstate)
{
	bool boolSubed = false;
	ChQvState * state = (ChQvState *)qstate;

	if(state->GetType() == ChQvState::editNode)
	{
		{
			if(	pNode->getName() == state->GetNode()->getName())
			{

				EditNode(pNode,(aType*)(state->GetNode())); 
				// persp camera only
				state->SetCmdDone( true);
				boolSubed = true;
			}
		}
	}
	return boolSubed;		// we did not do substitiution
}    
#endif

// Doesn't stop on the first find; Return LAST hit just like DEF works
bool QueryNode( QvNode * pNode, QvState *qvstate)
{
	bool boolIsQuery = false;
	
	ChQvState * qstate = (ChQvState *)qvstate;

	if(qstate->GetType() == ChQvState::queryNode)
	{
		ChQvQueryState * state = (ChQvQueryState *)qvstate;
		boolIsQuery = true;
		if(state->GetQuery()->GetType() == ChQvQuery::byClassName)
		{
			string strClass;
			pNode->GetType(strClass);
			if( strClass ==	state->GetQuery()->GetKey())
			{
				state->GetQuery()->SetResult(pNode);
				state->SetCmdDone( true);
			}
		}
		else
		{
			if(	pNode->getName() == state->GetQuery()->GetKeyNode()->getName())
			{
				state->GetQuery()->SetResult(pNode);
				state->SetCmdDone( true);
			}
		}
	}
	return boolIsQuery;		// we did not do substitiution
}

#define DEFAULT_QUERYNODE(pNode, state)	\
	if(QueryNode( pNode, state )) return;

// For debugging
static int indent = 0;
static void
announce(const char *className)
{
	char buf[500];
    for (int i = 0; i < indent; i++)  sprintf(buf+i,"\t"); 
    sprintf(buf+indent, "Traversing a %s\r\n", className);
	//OutputDebugString(buf);
}
//#define ANNOUNCE(className) announce(QV__QUOTE(className))
#define ANNOUNCE(className) 

#define DEFAULT_TRAVERSE(className)					      \
void									      \
className::traverse(QvState *state)						      \
{									      \
    ANNOUNCE(className);						      \
	QueryNode(this, state);					\
	if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this); \
}

//////////////////////////////////////////////////////////////////////////////
//
// Groups.
//
//////////////////////////////////////////////////////////////////////////////

void
QvGroup::traverse(QvState *state)
{
    ANNOUNCE(QvGroup);
	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);
		ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)m_pRenderData;
		ChQvGroupInstance *pInstance = new ChQvGroupInstance;
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();
		
		bldState->SetCurrentParent(pInstance);
		 
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		//#define DONT_PUSH	1
		#if defined(DONT_PUSH)
		pRC->PushTransform();

	    state->push();
		#endif

	    indent++;
	    for (int i = 0; i < getNumChildren(); i++)
			getChild(i)->traverse(state);
	    indent--;

		#if defined(DONT_PUSH)
	    state->pop();

		pRC->PopTransform();
		#endif

		if(pParent) bldState->SetCurrentParent(pParent);

	}	
	else
	{
		QueryNode(this, state);
	    indent++;
	    for (int i = 0; i < getNumChildren(); i++)
		getChild(i)->traverse(state);
	    indent--;
	}
}


void
QvLOD::traverse(QvState *state)
{
    ANNOUNCE(QvLOD);
	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	

		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		pRC->PushTransform();

	    state->push();

		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);
		ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)m_pRenderData;
		ChQvLODInstance *pInstance = new ChQvLODInstance;
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();
		bldState->SetCurrentParent(pInstance);
		 
	    indent++;
		// Removed 1/24/96 jwd to postpone instatntiation and spawning until
		// first rendering of lod
		#if 0
	    for (int i = 0; i < getNumChildren(); i++)
			getChild(i)->traverse(state);
	    #endif
	    indent--;
	    state->pop();

		pRC->PopTransform();
		
		//pInstance->SetUpKids();

		if(pParent) bldState->SetCurrentParent(pParent);

	}	
	else if( ((ChQvState*)state)->GetType() == ChQvState::spawnRequests)
	{
		// Spawn for all kids, regardless of range
	    indent++;
		// Removed 1/24/96 jwd to postpone instatntiation and spawning until
		// first rendering of lod
		#if 0
	    for (int i = 0; i < getNumChildren(); i++)
		{
			getChild(i)->traverse(state);
		}
	    #endif
	    indent--;
	}
	else
	{
	    indent++;

	    // ??? 
	    if (getNumChildren() > 0)
		{
			int iChild = -1;

			QueryNode(this, state);
	
			// Lookup in range array
			iChild = 0;

			// Traverse the chosen one
			if (getNumChildren() > 0) getChild(iChild)->traverse(state);
		}
		//getChild(0)->traverse(state);

	    indent--;
	}
}

void
QvSeparator::traverse(QvState *state)
{
    ANNOUNCE(QvSeparator);

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		pRC->PushTransform();

	    state->push();

		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvGroupRenderData(this);
		ChQvGroupRenderData *pRenderData =  (ChQvGroupRenderData *)m_pRenderData;
		ChQvSeparatorInstance *pInstance = new ChQvSeparatorInstance;
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();
		bldState->SetCurrentParent(pInstance);
		 
	    indent++;
	    for (int i = 0; i < getNumChildren(); i++)
			getChild(i)->traverse(state);
	    indent--;
	    state->pop();

		pRC->PopTransform();

		if(pParent) bldState->SetCurrentParent(pParent);

	}	
	else
	{
	    state->push();

		if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
		{
			ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
			pRC->PushTransform();
		}	

		QueryNode(this, state);
    
	    indent++;
	    for (int i = 0; i < getNumChildren(); i++)
		getChild(i)->traverse(state);
	    indent--;
	    state->pop();
	
		if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
		{
			ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
			pRC->PopTransform();
		}
	}	
}

void
QvSpinGroup::traverse(QvState *state)
{
    ANNOUNCE(QvSpinGroup);

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		pRC->PushTransform();

	    state->push();

		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvSpinGroupRenderData(this);
		ChQvSpinGroupRenderData *pRenderData =  (ChQvSpinGroupRenderData *)m_pRenderData;
		ChQvSpinGroupInstance *pInstance = new ChQvSpinGroupInstance;
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();
		bldState->SetCurrentParent(pInstance);
		 
		#if 0
		// Add the group's transform instance onto the stack
		ChQvElement *elt = new ChQvElement;					      
		elt->data = this;							      
		elt->type = QvElement::Transform;					      
		state->addElement(QvState::TransformationIndex, elt);
		ChQvTransformationInstance *pTransformInstance = pInstance->GetTransformInstance();
		pTransformInstance->Attach(this, bldState);
		
		GxTransform3Wf mat;
		pTransformInstance->SetSelfTransform(mat);

		elt->SetInstance(pTransformInstance);
		#endif

	    indent++;
	    for (int i = 0; i < getNumChildren(); i++)
			getChild(i)->traverse(state);
	    indent--;
	    state->pop();

		pRC->PopTransform();

		if(pParent) bldState->SetCurrentParent(pParent);

	}	
	else
	{
	    state->push();

		if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
		{
			ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
			pRC->PushTransform();
		}	

		QueryNode(this, state);
    
	    indent++;
	    for (int i = 0; i < getNumChildren(); i++)
		getChild(i)->traverse(state);
	    indent--;
	    state->pop();
	
		if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
		{
			ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
			pRC->PopTransform();
		}
	}	
}

void
QvSwitch::traverse(QvState *state)
{
    ANNOUNCE(QvSwitch);
  	//DEFAULT_QUERYNODE(this, state);	
 	DoNodeEditCommand(this, state);

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		pRC->PushTransform();
	    state->push();

		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvSwitchRenderData(this);
		ChQvSwitchRenderData *pRenderData =  (ChQvSwitchRenderData *)m_pRenderData;
		ChQvSwitchInstance *pInstance = new ChQvSwitchInstance;
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();
		bldState->SetCurrentParent(pInstance);
		 
	    indent++;
		#if defined(CH_USE_3DR)
	    for (int i = 0; i < getNumChildren(); i++)
			getChild(i)->traverse(state);
		#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		// Traverse just the one - ignore all others forever - needs to be changed for Pueblo
	    int which = whichChild.value;
		if(getName() == "Cameras")
		{
		
			for (int i = 0; i < getNumChildren(); i++)
			{
				string strType;
				QvNode *pChild = getChild(i);
				if( pChild->GetType(strType) == typeQvPerspectiveCamera || 
					pChild->GetType(strType) == typeQvOrthographicCamera ||
					i == which)
				{
		    		pChild->traverse(state);
				}
			}
		}
		else
		{
		    if (which == QV_SWITCH_NONE)
			{
				;
			}
		    else if (which == QV_SWITCH_ALL)
			{
				for (int i = 0; i < getNumChildren(); i++)
				{
			    	getChild(i)->traverse(state);
				}
			}
		    else
			{
				#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
									// Instantiate them all for Pueblo - can be reselected
				for (int i = 0; i < getNumChildren(); i++)
				{
			    	getChild(i)->traverse(state);
				}
				#else
												// VRML 1.0 is not modifiable outside of
												// Pueblo, so just instantiate the whichChild one
											   // Other negatives are bad; ignore them
				if (which >= 0 && which < getNumChildren())
				{
				    getChild(which)->traverse(state);
				}
				#endif
			}
		}
		#else
		#pragma message("Switch traversal not done")
		#endif
	    indent--;
	    state->pop();

		pRC->PopTransform();

		if(pParent) bldState->SetCurrentParent(pParent);

	}	
	else
	{
		QueryNode(this, state);
	    indent++;
	    int which = whichChild.value;

	    if (which == QV_SWITCH_NONE)
		{
			;
		}
	    else if (which == QV_SWITCH_ALL)
		{
			for (int i = 0; i < getNumChildren(); i++)
			{
		    	getChild(i)->traverse(state);
			}
		}
	    else
		{							   // other negatives are bad; ignore
			if (which >= 0 && which < getNumChildren())
			{
			    getChild(which)->traverse(state);
			}
		}

	    indent--;
	}
}

void
QvTransformSeparator::traverse(QvState *state)
{
    ANNOUNCE(QvTransformSeparator);

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		pRC->PushTransform();

	    state->push();

		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);
		ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)m_pRenderData;
		ChQvTransformSeparatorInstance *pInstance = new ChQvTransformSeparatorInstance;
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();
		bldState->SetCurrentParent(pInstance);
		 
	    indent++;
	    for (int i = 0; i < getNumChildren(); i++)
			getChild(i)->traverse(state);
	    indent--;
	    state->pop();

		pRC->PopTransform();

		if(pParent) bldState->SetCurrentParent(pParent);

	}	
	else
	{
	    // We need to "push" just the transformation stack. We'll
	    // accomplish this by just pushing a no-op transformation onto
	    // that stack. When we "pop", we'll restore that stack to its
	    // previous state.

	    QvElement *markerElt = new QvElement;
	    markerElt->data = this;
	    markerElt->type = QvElement::NoOpTransform;
	    state->addElement(QvState::TransformationIndex, markerElt);

		if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
		{
			ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
			pRC->PushTransform();
		}	
    
 		QueryNode(this, state);

	    indent++;
	    for (int i = 0; i < getNumChildren(); i++)
		{
			getChild(i)->traverse(state);
		}
	    indent--;

	    // Now do the "pop"
	    while (state->getTopElement(QvState::TransformationIndex) != markerElt)
		state->popElement(QvState::TransformationIndex);
	
		if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
		{
			ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
			pRC->PopTransform();
		}
	}	
}

//////////////////////////////////////////////////////////////////////////////
//
// Properties.
//
//////////////////////////////////////////////////////////////////////////////

#define DO_PROPERTY(className, stackIndex)				      \
void									      \
className::traverse(QvState *state)					      \
{									      \
    ANNOUNCE(className);						      \
	DEFAULT_QUERYNODE(this, state);	\
    QvElement *elt = new QvElement;					      \
    elt->data = this;							      \
    state->addElement(QvState::stackIndex, elt);			      \
	if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);	\
}

#define DO_TYPED_PROPERTY(className, stackIndex, eltType)		      \
void									      \
className::traverse(QvState *state)					      \
{									      \
    ANNOUNCE(className);						      \
	DEFAULT_QUERYNODE(this, state);	\
	/*DoNodeEditCommand(this, state);*/						\
    QvElement *elt = new QvElement;					      \
    elt->data = this;							      \
    elt->type = QvElement::eltType;					      \
    state->addElement(QvState::stackIndex, elt);			      \
	if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);	\
}

DO_PROPERTY(QvCoordinate3,			Coordinate3Index)
DO_PROPERTY(QvMaterialBinding,		MaterialBindingIndex)
DO_PROPERTY(QvNormal,				NormalIndex)
DO_PROPERTY(QvNormalBinding,		NormalBindingIndex)
DO_PROPERTY(QvTextureCoordinate2,	TextureCoordinate2Index)
DO_PROPERTY(QvFontStyle,			FontStyleIndex)

void									      
QvTexture2::traverse(QvState *state)					      
{	
	DEFAULT_QUERYNODE(this, state);
	ChQvTextureRenderData *pRenderData;
	if(!m_pRenderData)
	{
		m_pRenderData = pRenderData = new ChQvTextureRenderData(this);
	}
	else {
		pRenderData =  (ChQvTextureRenderData *)m_pRenderData;
	}
	if (pRenderData->GetURL(state)) return;								      

    QvElement *elt = new QvElement;					      
    elt->data = this;							      
    state->addElement(QvState::Texture2Index, elt);

	if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
}

//DO_PROPERTY(QvTexture2Transform,	Texture2TransformationIndex)
void									      
QvTexture2Transform::traverse(QvState *state)					      
{	
	DEFAULT_QUERYNODE(this, state);
	ChQvTexture2TransformRenderData *pRenderData;
	if(!m_pRenderData)
	{
		m_pRenderData = pRenderData = new ChQvTexture2TransformRenderData(this);
	}
	else {
		pRenderData =  (ChQvTexture2TransformRenderData *)m_pRenderData;
	}

    QvElement *elt = new QvElement;					      
    elt->data = this;							      
    state->addElement(QvState::Texture2TransformationIndex, elt);

	if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
}

void									      
QvDirectionalLight::traverse(QvState *state)					      
{									      
    ANNOUNCE(className);						      
	DEFAULT_QUERYNODE(this, state);	
    QvElement *elt = new QvElement;					      
    elt->data = this;							      
    elt->type = QvElement::DirectionalLight;					      
    state->addElement(QvState::LightIndex, elt);

	int wLightNum = ((ChQvState*)state)->NextLight();	  

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);
		ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)m_pRenderData;
		ChQvDirectionalLightInstance *pInstance = new ChQvDirectionalLightInstance;
		pInstance->Attach(this, bldState);
	}	
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
		#if defined(CH_USE_3DR)
		// TODO figure out if this is dead code for 3dr too
		G3dHandle_t hGC = ((ChQvState*)state)->GetView()->GetGC();
	  

		// We don't have directional lights in 3dr, so put a spot light very far away,
		// and leave it wide open angle-wise, with no attenuation
		if(wLightNum < G3D_MAX_LIGHTS)
		{
			Float_t		dimmer = 	int(on.value) ? 1. : 0.;
			float fIntensity = intensity.value;
			fIntensity = min(fIntensity, 1.);
			fIntensity = max(fIntensity, 0.);
			ColorFA_t	diffuse;		Qv2Native(color, diffuse);
			ColorF_t	specular;		Qv2Native(color,specular) ;


			// Transform light from model (vrml) to world coords for 3dr
			PointF_t	dir;		Qv2Native(direction,dir);
			PointFW_t	tmp;		
			GxTransformF_t mat;
			G3dSetActiveStack(hGC, G3DT_MODEL);
			G3dGetTransform(hGC,  mat);
			G3dTransformPointF( &dir, &tmp, mat );
			CopyPoint(tmp, dir);

			Float_t		infinity	=	1.e6;	// close enough (or far enough) for us
			PointFW_t	loc;
			loc.x = -dir.x * infinity;
			loc.y = -dir.y * infinity;
			loc.z = -dir.z * infinity;
			loc.w = 0.;				 // infinite light
	 		ColorF_t	ambient = {0.,0.,0.};
													 
			Float_t exponent	= 0.00;	   // no fall off
			Float_t angle		= 1.57;	   // leave the barn doors open
			Float_t attena 		= 1.00;	   // no attenuation
			Float_t attenb 		= 0.00;
			Float_t attenc 		= 0.00;

			specular.r *= fIntensity;
			specular.g *= fIntensity;
			specular.b *= fIntensity;

			diffuse.r *= fIntensity;
			diffuse.g *= fIntensity;
			diffuse.b *= fIntensity;


			G3dSetLight( hGC, wLightNum, G3DL_DIMMER,   	(Float_t *)&dimmer );			
			G3dSetLight( hGC, wLightNum, G3DL_AMBIENT, 		(Float_t *)&ambient );			
			G3dSetLight( hGC, wLightNum, G3DL_DIFFUSE,  	(Float_t *)&diffuse );			
			G3dSetLight( hGC, wLightNum, G3DL_SPECULAR, 	(Float_t *)&specular );			
			G3dSetLight( hGC, wLightNum, G3DL_DIRECTION,	(Float_t *)&dir );			
			G3dSetLight( hGC, wLightNum, G3DL_LOCATION,		(Float_t *)&loc );
			G3dSetLight( hGC, wLightNum, G3DL_ATTENA,  		(Float_t *)&attena );
			G3dSetLight( hGC, wLightNum, G3DL_ATTENB,  		(Float_t *)&attenb );
			G3dSetLight( hGC, wLightNum, G3DL_ATTENC,  		(Float_t *)&attenc );
			G3dSetLight( hGC, wLightNum, G3DL_SPOT_EXP, 	(Float_t *)&exponent );
			G3dSetLight( hGC, wLightNum, G3DL_SPOT_ANGLE,	(Float_t *)&angle );
		}
		#endif			
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
		if(!((ChQvState*)state)->GetCmd().CompareNoCase("light"))	 // hard coded yucko!!
		{
			if(((ChQvState*)state)->GetIData() == wLightNum-1)		 // oughta use keys
			{
				intensity.value = ((ChQvState*)state)->GetFData();
				intensity.value = max(intensity.value, 0.);
				intensity.value = min(intensity.value, 1.);
			}
		}
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::findGlobals)
	{
		ChQvGlobalSearchState *srchState = (ChQvGlobalSearchState*)state; 

		if( on.value > 0.) srchState->SetLightOn( );
	}
			

}


void									      
QvPointLight::traverse(QvState *state)					      
{									      
    ANNOUNCE(className);						      
	DEFAULT_QUERYNODE(this, state);	
    QvElement *elt = new QvElement;					      
    elt->data = this;							      
    elt->type = QvElement::PointLight;					      
    state->addElement(QvState::LightIndex, elt);

	int wLightNum = ((ChQvState*)state)->NextLight();	  

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);
		ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)m_pRenderData;
		ChQvPointLightInstance *pInstance = new ChQvPointLightInstance;
		pInstance->Attach(this, bldState);
	}	
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
		#if defined(CH_USE_3DR)
		G3dHandle_t hGC = ((ChQvState*)state)->GetView()->GetGC();
	  
		if(wLightNum < G3D_MAX_LIGHTS)
		{
			Float_t		dimmer = 	int(on.value) ? 1. : 0.;
			float fIntensity = intensity.value;
			fIntensity = min(fIntensity, 1.);
			fIntensity = max(fIntensity, 0.);

			ColorFA_t	diffuse;	Qv2Native(color, diffuse);
			ColorF_t	specular;	Qv2Native(color,specular) ;
			PointF_t	dir = {0., 0., 0.};	  // not a spot
	 		ColorF_t	ambient = {0.,0.,0.};

			// Transform light from model (vrml) to world coords for 3dr
			PointF_t	locV;		Qv2Native(location,locV);
			PointFW_t	loc;		
			GxTransformF_t mat;
			G3dSetActiveStack(hGC, G3DT_MODEL);
			G3dGetTransform(hGC,  mat);
			G3dTransformPointF( &locV, &loc, mat );
			loc.w = 1.;				 // noninfinite light
			
			 
			static int j = 0;
			static Float_t attena = 1.0;
			static Float_t attenb = 0.0;
			static Float_t attenc = 0.0;
			//static Float_t attenb = .0075;
			//static Float_t attenc = .0075;

			//test effect of dimming
			//if (wLightNum == 5) fIntensity /= 5;
			//if (wLightNum == 7) fIntensity = 1;

			specular.r *= fIntensity;
			specular.g *= fIntensity;
			specular.b *= fIntensity;

			diffuse.r *= fIntensity;
			diffuse.g *= fIntensity;
			diffuse.b *= fIntensity;


			G3dSetLight( hGC,  wLightNum, G3DL_DIMMER,    	(Float_t *)&dimmer     );			
			G3dSetLight( hGC,  wLightNum, G3DL_AMBIENT, 	(Float_t *)&ambient  );			
			G3dSetLight( hGC,  wLightNum, G3DL_DIFFUSE,  	(Float_t *)&diffuse   );			
			G3dSetLight( hGC,  wLightNum, G3DL_SPECULAR, 	(Float_t *)&specular  );			
			G3dSetLight( hGC,  wLightNum, G3DL_DIRECTION,  (Float_t *)&dir  );			
			G3dSetLight( hGC,  wLightNum, G3DL_LOCATION,  (Float_t *)&loc  );
			//G3dSetLight( hGC,  wLightNum, G3DL_ATTENA,  (Float_t *)&attena  );
			G3dSetLight( hGC,  wLightNum, G3DL_ATTENB,  (Float_t *)&attenb  );
			G3dSetLight( hGC,  wLightNum, G3DL_ATTENC,  (Float_t *)&attenc  );
		}			
		#endif
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
		if(!((ChQvState*)state)->GetCmd().CompareNoCase("light"))	 // hard coded yucko!!
		{
			if(((ChQvState*)state)->GetIData() == wLightNum-1)		 // oughta use keys
			{
				intensity.value = ((ChQvState*)state)->GetFData();
				intensity.value = max(intensity.value, 0.);
				intensity.value = min(intensity.value, 1.);
			}
		}
	}			
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::findGlobals)
	{
		ChQvGlobalSearchState *srchState = (ChQvGlobalSearchState*)state; 

		if( on.value > 0.) srchState->SetLightOn( );
	}

}




void									      
QvSpotLight::traverse(QvState *state)					      
{									      
    ANNOUNCE(className);						      
 	DEFAULT_QUERYNODE(this, state);	
	//DoNodeEditCommand(this, state);
 		
 	QvElement *elt = new QvElement;					      
    elt->data = this;							      
    elt->type = QvElement::SpotLight;					    
    state->addElement(QvState::LightIndex, elt);

	int wLightNum = ((ChQvState*)state)->NextLight();	  

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);
		ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)m_pRenderData;
		ChQvSpotLightInstance *pInstance = new ChQvSpotLightInstance;
		pInstance->Attach(this, bldState);
	}	
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
		#if defined(CH_USE_3DR)
		G3dHandle_t hGC = ((ChQvState*)state)->GetView()->GetGC();
	  
		if(wLightNum < G3D_MAX_LIGHTS)
		{
			Float_t		dimmer = 	int(on.value) ? 1. : 0.;
			float fIntensity = intensity.value;
			fIntensity = min(fIntensity, 1.);
			fIntensity = max(fIntensity, 0.);
			ColorF_t	diffuse;	Qv2Native(color, diffuse);
			ColorF_t	specular;	Qv2Native(color,specular) ;
			ColorF_t	ambient = {0.,0.,0.};
			// Transform light from model (vrml) to world coords for 3dr
			PointF_t	locV;		Qv2Native(location,locV);
			PointFW_t	loc;		
			GxTransformF_t mat;
			G3dSetActiveStack(hGC, G3DT_MODEL);
			G3dGetTransform(hGC,  mat);
			G3dTransformPointF( &locV, &loc, mat );
			loc.w = 1.;				 // noninfinite light
			
			PointF_t	dir;		Qv2Native(direction,dir);
			PointFW_t	tmp;		
			G3dTransformPointF( &dir, &tmp, mat );
			CopyPoint(tmp, dir);

			Float_t		expon	=	Float_t(dropOffRate.value);
			Float_t		spotAngle	=	Float_t(cutOffAngle.value);
		
			specular.r *= fIntensity;
			specular.g *= fIntensity;
			specular.b *= fIntensity;

			diffuse.r *= fIntensity;
			diffuse.g *= fIntensity;
			diffuse.b *= fIntensity;

			G3dSetLight( hGC,  wLightNum, G3DL_DIMMER,    	(Float_t *)&dimmer     );			
			G3dSetLight( hGC,  wLightNum, G3DL_AMBIENT, 	(Float_t *)&ambient  );			
			G3dSetLight( hGC,  wLightNum, G3DL_DIFFUSE,  	(Float_t *)&diffuse   );			
			G3dSetLight( hGC,  wLightNum, G3DL_SPECULAR, 	(Float_t *)&specular  );			
			G3dSetLight( hGC,  wLightNum, G3DL_SPOT_EXP,     	(Float_t *)&expon      );			
			G3dSetLight( hGC,  wLightNum, G3DL_SPOT_ANGLE,  (Float_t *)&spotAngle     );
 
			G3dSetLight( hGC,  wLightNum, G3DL_DIRECTION,  (Float_t *)&dir  );			
			G3dSetLight( hGC,  wLightNum, G3DL_LOCATION,  (Float_t *)&loc  );
			//G3dSetLight( hGC,  wLightNum, G3DL_ATTENA,  (Float_t *)&atten  );
			//G3dSetLight( hGC,  wLightNum, G3DL_ATTENB,  (Float_t *)&atten  );
			//G3dSetLight( hGC,  wLightNum, G3DL_ATTENC,  (Float_t *)&atten  );
		}
		#endif
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
		if(!((ChQvState*)state)->GetCmd().CompareNoCase("light"))	 // hard coded yucko!!
		{
			if(((ChQvState*)state)->GetIData() == wLightNum-1)		 // oughta use keys
			{
				intensity.value = ((ChQvState*)state)->GetFData();
				intensity.value = max(intensity.value, 0.);
				intensity.value = min(intensity.value, 1.);
			}
		}
	}			
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::findGlobals)
	{
		ChQvGlobalSearchState *srchState = (ChQvGlobalSearchState*)state; 

		if( on.value > 0.) srchState->SetLightOn( );
	}

}

#if 0
// example for traverses
void									      
classname::traverse(QvState *state)					      
{									      
    QvElement *elt = new QvElement;					      
    elt->data = this;							      
    state->addElement(QvState::classIndex, elt);

	G3dHandle_t hGC = ((ChQvState*)state)->GetView()->GetGC();
	  
	if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
}
#endif


DO_PROPERTY(QvShapeHints,		ShapeHintsIndex)

void									      
QvMaterial::traverse(QvState *state)					      
{									      
    ANNOUNCE(className);						      
	DEFAULT_QUERYNODE(this, state);	
    QvElement *elt = new QvElement;					      
    elt->data = this;							      
    state->addElement(QvState::MaterialIndex, elt);
	if(!m_pRenderData) m_pRenderData = new ChQvMaterialRenderData(this);

}


// i oughta RTFM; i didn't need to write this i think. Use G3dTransformPointF instead.

#if defined(CH_USE_3DR)
void Mult(GxTransformF_t& mat, PointF_t& a, PointF_t& b)
{	// b must not be the same as a
	b.x = a.x * mat[0][0] + a.y * mat[0][1] + a.z * mat[0][2];
	b.y = a.x * mat[1][0] + a.y * mat[1][1] + a.z * mat[1][2];
	b.z = a.x * mat[2][0] + a.y * mat[2][1] + a.z * mat[2][2];
}

//void CreateHeadlight(  PointFW_t loc, PointF_t dir, QvState *state );

void									      
QvPerspectiveCamera::traverse(QvState *state)					      
{									      
    ANNOUNCE(className);
   						      
 	DoNodeEditCommand(this, state);

    QvElement *elt = new QvElement;					      
    elt->data = this;							      
    elt->type = QvElement::PerspectiveCamera;					      
    state->addElement(QvState::CameraIndex, elt);

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{
		G3dHandle_t hGC = ((ChQvState*)state)->GetView()->GetGC();
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();

		G3dSetCameraProjection(hGC, G3DP_PERSPECTIVE);
		PointF_t	up, upa = {0.0f, 1.0f, 0.0f};		// starting loc for look dirs
		PointF_t	dir, dira = {0.0f, 0.0f, -1.0f};		// will rotate later
		PointFW_t 	loc;

		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)GetRenderData();

		if(!pRenderData)
		{
			m_pRenderData = pRenderData = new ChQvPCameraRenderData(this, (ChQvBuildState*)state);
		}

		// Use the node to set the render data
		Qv2Native(position, loc);
		loc.w = 0.;				 // infinite camera - faster

		float angle = orientation.angle;

		GxTransformF_t	rotMat;
		RotateMatrix(-angle, 
						orientation.axis[0],
						orientation.axis[1],
						orientation.axis[2],
						rotMat);

 		// Inventor puts the camera in transformed world (model) coordinates,
		// But 3dr defines the bottom model transform by the camera. 
		// Therefore, we have to walk the qv stack of transforms, accumulating them
		// Then we transform by the resultant matrix

		GxTransformF_t	stackMat, cameraMat;
		AccumQVTransform( state, stackMat);

		G3dMultMatrix( rotMat, stackMat, cameraMat );

		Mult(cameraMat, dira, dir);

		
		if(pRC->GetViewerMode() != walk )
		{
			Mult(cameraMat, upa, up);
		}
		else						// We're walking; keep camera level
		{							// This computation is not pure VRML,
									// but it keeps camera manipulations much cleaner for
									// walking situations. The camera acts more camera-like 
									// and less airplane-like.

			PointF_t n;				// normal to plane defined by (dir, yaxis)
			PointF_t axis = {	orientation.axis[0],
								orientation.axis[1],
								orientation.axis[2] };
			PointF_t yAxis = {	0, 1, 0 };

 			G3dCross(&yAxis, &dir, &n);
			if (G3dDot(&n, &n) > SMIDGEON)
			{
 				G3dCross(&dir, &n, &up);
 			}
			else
			{
				// special case; looking straight up or down
				Mult(cameraMat, upa, up);
			} 

			if (G3dDot(&up, &up) < SMIDGEON)
			{
				up.x = 0; up.y = 1; up.z = 0;
			}
			G3dUnitVector(&up);
		}


		pRenderData->SetLoc(*(GxVec3f*)&loc)->SetUp(*(GxVec3f*)&up)->SetDir(*(GxVec3f*)&dir);
		pRenderData->SetStartLoc(*(GxVec3f*)&loc)->SetStartUp(*(GxVec3f*)&up)->SetStartDir(*(GxVec3f*)&dir);
		pRenderData->SetDirty(false);

		loc.w = 0;		// infinite camera for all but highest quality
						// rendering
		
		G3dSetCameraPosition(hGC,  &loc, &dir, &up);
		// use window size for projection; note that coord system is y-up
		RECT rt;
		((ChQvState*)state)->GetView()->GetClientRect(&rt);

		// set the view box based on the angle they requested, and the
		// window's aspect ratio, and the bounds of the scene graph

		// TODO: try out the RL fix here; use a big maxZ (like 32k) but work in
		// just the front of the buffer, by multiplying fFar by 10 or 40 or something

		Float_t fNear = nearDistance.value; 
		Float_t fFar = 50000.;
		const float maxZResolution = 2000.;	// Assuming ?? bits signed
		ChMazeWnd * pView = ((ChQvState*)state)->GetView();
		if(pView->GetBounds())
		{				   
							// Compute based on scene bounds, and
							// multiply in a little fudge factor for luck
			fFar = 1.5 * pView->GetBounds()->GetFarDistance(loc.x, loc.y, loc.z);
		}
		float minNear = fFar / maxZResolution;	   // prevent zbuffer overrun
		fNear = 1.0;							  // hack
		fNear = max(fNear, minNear);
		Float_t top = tan(heightAngle.value / 2.) * fNear ;
		Float_t bottom = -top;
		Float_t right = top * rt.right / rt.bottom;
		Float_t left = -right;

		G3dSetCameraView(hGC, right, left, top, bottom, fNear, fFar);

		G3dSetCameraPort(	hGC, 
							Float_t(rt.right),		/* right */
							0.0f,					/* left*/
			    			Float_t(rt.bottom),		/* top */
			    			0.0f);					/* bottom */

		// Now let's save the matrices into the render data for later use
				
		memcpy(pRenderData->m_cameraTransform, G3dGetModelCamMatrix(hGC), sizeof(pRenderData->m_cameraTransform));
		memcpy(pRenderData->m_invCameraTransform, G3dGetInverseModelCamMatrix(hGC), sizeof(pRenderData->m_invCameraTransform));
		G3dSetActiveStack(hGC, G3DT_CAM_CLIP);
		GxTransformF_t mat;
		G3dGetTransform(hGC, mat);	   
		pRenderData->m_camClipTransform	= GxTransform3Wf(mat);
		G3dSetActiveStack(hGC, G3DT_MODEL);

		pRenderData->m_right 	=  Float_t(rt.right);		/* right */        
		pRenderData->m_left  	=  0.0f;					/* left*/          
		pRenderData->m_top   	=  Float_t(rt.bottom);		/* top */          
		pRenderData->m_bottom	=  0.0f;					/* bottom */ 
		      
		// Now rebuild the renderer's transform stack, based on the qv stack
		// To get back to model coords
		pRC->RebuildTransformStack((ChQvState*)state);
		pRC->SetCameraLoc(*(GxVec3f*)&loc);			// in world coords!
	}
	else if(((ChQvState*)state)->GetType() ==  ChQvState::draw ||  ((ChQvState*)state)->GetType() ==  ChQvState::queryNode)
	{
		G3dHandle_t hGC = ((ChQvState*)state)->GetView()->GetGC();
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();

		G3dSetCameraProjection(hGC, G3DP_PERSPECTIVE);
		PointF_t	up, upa = {0.0f, 1.0f, 0.0f};		// starting loc for look dirs
		PointF_t	dir, dira = {0.0f, 0.0f, -1.0f};		// will rotate later
		PointFW_t 	loc;

		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)GetRenderData();
		ASSERT(pRenderData);

		if(pRenderData->IsDirty())
		{
			// Use the node to set the render data
			Qv2Native(position, loc);
			loc.w = 0.;				 // infinite camera - faster
	
			float angle = orientation.angle;

			GxTransformF_t	rotMat;
			RotateMatrix(-angle, 
							orientation.axis[0],
							orientation.axis[1],
							orientation.axis[2],
							rotMat);

	 		// Inventor puts the camera in transformed world (model) coordinates,
			// But 3dr defines the bottom model transform by the camera. 
			// Therefore, we have to walk the qv stack of transforms, accumulating them
			// Then we transform by the resultant matrix

			GxTransformF_t	stackMat, cameraMat;
			AccumQVTransform( state, stackMat);

			G3dMultMatrix( rotMat, stackMat, cameraMat );

			Mult(cameraMat, dira, dir);

			
			if(pRC->GetViewerMode() != walk )
			{
				Mult(cameraMat, upa, up);
			}
			else						// We're walking; keep camera level
			{							// This computation is not pure VRML,
										// but it keeps camera manipulations much cleaner for
										// walking situations. The camera acts more camera-like 
										// and less airplane-like.

				PointF_t n;				// normal to plane defined by (dir, yaxis)
				PointF_t axis = {	orientation.axis[0],
									orientation.axis[1],
									orientation.axis[2] };
				PointF_t yAxis = {	0, 1, 0 };

	 			G3dCross(&yAxis, &dir, &n);
				if (G3dDot(&n, &n) > SMIDGEON)
				{
	 				G3dCross(&dir, &n, &up);
	 			}
				else
				{
					// special case; looking straight up or down
					Mult(cameraMat, upa, up);
				} 

				if (G3dDot(&up, &up) < SMIDGEON)
				{
					up.x = 0; up.y = 1; up.z = 0;
				}
				G3dUnitVector(&up);
			}


			pRenderData->SetLoc(*(GxVec3f*)&loc)->SetUp(*(GxVec3f*)&up)->SetDir(*(GxVec3f*)&dir);
			pRenderData->SetDirty(false);
		}
		else
		{
			GxVec3f gloc = pRenderData->GetLoc();
			GxVec3f gup =  pRenderData->GetUp();
			GxVec3f gdir = pRenderData->GetDir();
			loc.x = gloc.x();
			loc.y = gloc.y();
			loc.z = gloc.z();
			up.x = gup.x();
			up.y = gup.y();
			up.z = gup.z();
			dir.x = gdir.x();
			dir.y = gdir.y();
			dir.z = gdir.z();

		}
		loc.w = 0;		// infinite camera for all but highest quality
						// rendering
		
		G3dSetCameraPosition(hGC,  &loc, &dir, &up);
		// use window size for projection; note that coord system is y-up
		RECT rt;
		((ChQvState*)state)->GetView()->GetClientRect(&rt);

		// set the view box based on the angle they requested, and the
		// window's aspect ratio, and the bounds of the scene graph
		Float_t fNear = nearDistance.value; 
		Float_t fFar = 50000.;
		const float maxZResolution = 2000.;	// Assuming ?? bits signed
		ChMazeWnd * pView = ((ChQvState*)state)->GetView();
		if(pView->GetBounds())
		{				   
							// Compute based on scene bounds, and
							// multiply in a little fudge factor for luck
			fFar = 1.5 * pView->GetBounds()->GetFarDistance(loc.x, loc.y, loc.z);
		}
		float minNear = fFar / maxZResolution;	   // prevent zbuffer overrun
		fNear = 1.0;							  // hack
		fNear = max(fNear, minNear);
		Float_t top = tan(heightAngle.value / 2.) * fNear ;
		Float_t bottom = -top;
		Float_t right = top * rt.right / rt.bottom;
		Float_t left = -right;

		G3dSetCameraView(hGC, right, left, top, bottom, fNear, fFar);

		G3dSetCameraPort(	hGC, 
							Float_t(rt.right),		/* right */
							0.0f,					/* left*/
			    			Float_t(rt.bottom),		/* top */
			    			0.0f);					/* bottom */

		// We've now established world, camera and screen spaces.
		// Now let's save the world-to-camera and camclip matrices into the render data for later use
				
		memcpy(pRenderData->m_cameraTransform, G3dGetModelCamMatrix(hGC), sizeof(pRenderData->m_cameraTransform));
		memcpy(pRenderData->m_invCameraTransform, G3dGetInverseModelCamMatrix(hGC), sizeof(pRenderData->m_invCameraTransform));

		G3dSetActiveStack(hGC, G3DT_CAM_CLIP);
		GxTransformF_t mat;
		G3dGetTransform(hGC, mat);	   
		pRenderData->m_camClipTransform	= GxTransform3Wf(mat);
		G3dSetActiveStack(hGC, G3DT_MODEL);

		pRenderData->m_right 	=  Float_t(rt.right);		/* right */        
		pRenderData->m_left  	=  0.0f;					/* left*/          
		pRenderData->m_top   	=  0.0f;					/* top */          
		pRenderData->m_bottom	=  Float_t(rt.bottom);		/* bottom */ 
		      									  
		// Turn on headlight if required, now we know where the camera is
		// This is done in world coords, just like 3dr wanted the camera
		pRC->CreateHeadlight( GxVec3f(loc.x, loc.y, loc.z),  GxVec3f(dir.x, dir.y, dir.z), state );

		// Now rebuild the renderer's transform stack, based on the qv stack
		// To get back to model coords
		pRC->RebuildTransformStack((ChQvState*)state);
		pRC->SetCameraLoc(*(GxVec3f*)&loc);			// in world coords!
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
 	DEFAULT_QUERYNODE(this, state);	
}

void									      
QvOrthographicCamera::traverse(QvState *state)					      
{									      
    ANNOUNCE(className);
   						      
 	DoNodeEditCommand(this, state);

    QvElement *elt = new QvElement;					      
    elt->data = this;							      
    elt->type = QvElement::OrthographicCamera;					      
    state->addElement(QvState::CameraIndex, elt);

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{
		G3dHandle_t hGC = ((ChQvState*)state)->GetView()->GetGC();
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();

		G3dSetCameraProjection(hGC, G3DP_PARALLEL);		 // This is major difference for ortho
		PointF_t	up, upa = {0.0f, 1.0f, 0.0f};		// starting loc for look dirs
		PointF_t	dir, dira = {0.0f, 0.0f, -1.0f};		// will rotate later
		PointFW_t 	loc;

		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)GetRenderData();

		if(!pRenderData)
		{
			m_pRenderData = pRenderData = new ChQvPCameraRenderData(this, (ChQvBuildState*)state);
			pRenderData->m_boolPerspective = false;
		}

		// Use the node to set the render data
		Qv2Native(position, loc);
		loc.w = 0.;				 // infinite camera - faster

		float angle = orientation.angle;

		GxTransformF_t	rotMat;
		RotateMatrix(-angle, 
						orientation.axis[0],
						orientation.axis[1],
						orientation.axis[2],
						rotMat);

 		// Inventor puts the camera in transformed world (model) coordinates,
		// But 3dr defines the bottom model transform by the camera. 
		// Therefore, we have to walk the qv stack of transforms, accumulating them
		// Then we transform by the resultant matrix

		GxTransformF_t	stackMat, cameraMat;
		AccumQVTransform( state, stackMat);

		G3dMultMatrix( rotMat, stackMat, cameraMat );

		Mult(cameraMat, dira, dir);

		
		if(pRC->GetViewerMode() != walk )
		{
			Mult(cameraMat, upa, up);
		}
		else						// We're walking; keep camera level
		{							// This computation is not pure VRML,
									// but it keeps camera manipulations much cleaner for
									// walking situations. The camera acts more camera-like 
									// and less airplane-like.

			PointF_t n;				// normal to plane defined by (dir, yaxis)
			PointF_t axis = {	orientation.axis[0],
								orientation.axis[1],
								orientation.axis[2] };
			PointF_t yAxis = {	0, 1, 0 };

 			G3dCross(&yAxis, &dir, &n);
			if (G3dDot(&n, &n) > SMIDGEON)
			{
 				G3dCross(&dir, &n, &up);
 			}
			else
			{
				// special case; looking straight up or down
				Mult(cameraMat, upa, up);
			} 

			if (G3dDot(&up, &up) < SMIDGEON)
			{
				up.x = 0; up.y = 1; up.z = 0;
			}
			G3dUnitVector(&up);
		}


		pRenderData->SetLoc(*(GxVec3f*)&loc)->SetUp(*(GxVec3f*)&up)->SetDir(*(GxVec3f*)&dir);
		pRenderData->SetStartLoc(*(GxVec3f*)&loc)->SetStartUp(*(GxVec3f*)&up)->SetStartDir(*(GxVec3f*)&dir);
		pRenderData->SetDirty(false);

		loc.w = 0;		// infinite camera for all but highest quality
						// rendering
		
		G3dSetCameraPosition(hGC,  &loc, &dir, &up);
		// use window size for projection; note that coord system is y-up
		RECT rt;
		((ChQvState*)state)->GetView()->GetClientRect(&rt);

		// set the view box based on the angle they requested, and the
		// window's aspect ratio, and the bounds of the scene graph
		Float_t fNear = nearDistance.value; 
		Float_t fFar = 50000.;
		const float maxZResolution = 2000.;	// Assuming ?? bits signed
		ChMazeWnd * pView = ((ChQvState*)state)->GetView();
		if(pView->GetBounds())
		{				   
							// Compute based on scene bounds, and
							// multiply in a little fudge factor for luck
			fFar = 1.5 * pView->GetBounds()->GetFarDistance(loc.x, loc.y, loc.z);
		}
		float minNear = fFar / maxZResolution;	   // prevent zbuffer overrun
		fNear = 1.0;							  // hack
		fNear = max(fNear, minNear);
		Float_t top = height.value / 2.;		  // This is difference for ortho
		Float_t bottom = -top;
		Float_t right = top * rt.right / rt.bottom;
		Float_t left = -right;

		G3dSetCameraView(hGC, right, left, top, bottom, fNear, fFar);

		G3dSetCameraPort(	hGC, 
							Float_t(rt.right),		/* right */
							0.0f,					/* left*/
			    			Float_t(rt.bottom),		/* top */
			    			0.0f);					/* bottom */

		// Now let's save the matrices into the render data for later use
				
		memcpy(pRenderData->m_cameraTransform, G3dGetModelCamMatrix(hGC), sizeof(pRenderData->m_cameraTransform));
		memcpy(pRenderData->m_invCameraTransform, G3dGetInverseModelCamMatrix(hGC), sizeof(pRenderData->m_invCameraTransform));
		G3dSetActiveStack(hGC, G3DT_CAM_CLIP);
		GxTransformF_t mat;
		G3dGetTransform(hGC, mat);	   
		pRenderData->m_camClipTransform	= GxTransform3Wf(mat);
		G3dSetActiveStack(hGC, G3DT_MODEL);

		pRenderData->m_right 	=  Float_t(rt.right);		/* right */        
		pRenderData->m_left  	=  0.0f;					/* left*/          
		pRenderData->m_top   	=  Float_t(rt.bottom);		/* top */          
		pRenderData->m_bottom	=  0.0f;					/* bottom */ 
		      
		// Now rebuild the renderer's transform stack, based on the qv stack
		// To get back to model coords
		pRC->RebuildTransformStack((ChQvState*)state);
		pRC->SetCameraLoc(*(GxVec3f*)&loc);			// in world coords!
	}
	else if(((ChQvState*)state)->GetType() ==  ChQvState::draw ||  ((ChQvState*)state)->GetType() ==  ChQvState::queryNode)
	{
		G3dHandle_t hGC = ((ChQvState*)state)->GetView()->GetGC();
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();

		G3dSetCameraProjection(hGC, G3DP_PARALLEL);		 // This is major difference for ortho
		PointF_t	up, upa = {0.0f, 1.0f, 0.0f};		// starting loc for look dirs
		PointF_t	dir, dira = {0.0f, 0.0f, -1.0f};		// will rotate later
		PointFW_t 	loc;

		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)GetRenderData();
		ASSERT(pRenderData);

		if(pRenderData->IsDirty())
		{
			// Use the node to set the render data
			Qv2Native(position, loc);
			loc.w = 0.;				 // infinite camera - faster
	
			float angle = orientation.angle;

			GxTransformF_t	rotMat;
			RotateMatrix(-angle, 
							orientation.axis[0],
							orientation.axis[1],
							orientation.axis[2],
							rotMat);

	 		// Inventor puts the camera in transformed world (model) coordinates,
			// But 3dr defines the bottom model transform by the camera. 
			// Therefore, we have to walk the qv stack of transforms, accumulating them
			// Then we transform by the resultant matrix

			GxTransformF_t	stackMat, cameraMat;
			AccumQVTransform( state, stackMat);

			G3dMultMatrix( rotMat, stackMat, cameraMat );

			Mult(cameraMat, dira, dir);

			
			if(pRC->GetViewerMode() != walk )
			{
				Mult(cameraMat, upa, up);
			}
			else						// We're walking; keep camera level
			{							// This computation is not pure VRML,
										// but it keeps camera manipulations much cleaner for
										// walking situations. The camera acts more camera-like 
										// and less airplane-like.

				PointF_t n;				// normal to plane defined by (dir, yaxis)
				PointF_t axis = {	orientation.axis[0],
									orientation.axis[1],
									orientation.axis[2] };
				PointF_t yAxis = {	0, 1, 0 };

	 			G3dCross(&yAxis, &dir, &n);
				if (G3dDot(&n, &n) > SMIDGEON)
				{
	 				G3dCross(&dir, &n, &up);
	 			}
				else
				{
					// special case; looking straight up or down
					Mult(cameraMat, upa, up);
				} 

				if (G3dDot(&up, &up) < SMIDGEON)
				{
					up.x = 0; up.y = 1; up.z = 0;
				}
				G3dUnitVector(&up);
			}


			pRenderData->SetLoc(*(GxVec3f*)&loc)->SetUp(*(GxVec3f*)&up)->SetDir(*(GxVec3f*)&dir);
			pRenderData->SetDirty(false);
		}
		else
		{
			GxVec3f gloc = pRenderData->GetLoc();
			GxVec3f gup =  pRenderData->GetUp();
			GxVec3f gdir = pRenderData->GetDir();
			loc.x = gloc.x();
			loc.y = gloc.y();
			loc.z = gloc.z();
			up.x = gup.x();
			up.y = gup.y();
			up.z = gup.z();
			dir.x = gdir.x();
			dir.y = gdir.y();
			dir.z = gdir.z();

		}
		loc.w = 0;		// infinite camera for all but highest quality
						// rendering
		
		G3dSetCameraPosition(hGC,  &loc, &dir, &up);
		// use window size for projection; note that coord system is y-up
		RECT rt;
		((ChQvState*)state)->GetView()->GetClientRect(&rt);

		// set the view box based on the angle they requested, and the
		// window's aspect ratio, and the bounds of the scene graph
		Float_t fNear = nearDistance.value; 
		Float_t fFar = 50000.;
		const float maxZResolution = 2000.;	// Assuming ?? bits signed
		ChMazeWnd * pView = ((ChQvState*)state)->GetView();
		if(pView->GetBounds())
		{				   
							// Compute based on scene bounds, and
							// multiply in a little fudge factor for luck
			fFar = 1.5 * pView->GetBounds()->GetFarDistance(loc.x, loc.y, loc.z);
		}
		float minNear = fFar / maxZResolution;	   // prevent zbuffer overrun
		fNear = 1.0;							  // hack
		fNear = max(fNear, minNear);
		Float_t top = height.value / 2.;		  // This is difference for ortho
		Float_t bottom = -top;
		Float_t right = top * rt.right / rt.bottom;
		Float_t left = -right;

		G3dSetCameraView(hGC, right, left, top, bottom, fNear, fFar);

		G3dSetCameraPort(	hGC, 
							Float_t(rt.right),		/* right */
							0.0f,					/* left*/
			    			Float_t(rt.bottom),		/* top */
			    			0.0f);					/* bottom */

		// We've now established world, camera and screen spaces.
		// Now let's save the world-to-camera and camclip matrices into the render data for later use
				
		memcpy(pRenderData->m_cameraTransform, G3dGetModelCamMatrix(hGC), sizeof(pRenderData->m_cameraTransform));
		memcpy(pRenderData->m_invCameraTransform, G3dGetInverseModelCamMatrix(hGC), sizeof(pRenderData->m_invCameraTransform));

		G3dSetActiveStack(hGC, G3DT_CAM_CLIP);
		GxTransformF_t mat;
		G3dGetTransform(hGC, mat);	   
		pRenderData->m_camClipTransform	= GxTransform3Wf(mat);
		G3dSetActiveStack(hGC, G3DT_MODEL);

		pRenderData->m_right 	=  Float_t(rt.right);		/* right */        
		pRenderData->m_left  	=  0.0f;					/* left*/          
		pRenderData->m_top   	=  0.0f;					/* top */          
		pRenderData->m_bottom	=  Float_t(rt.bottom);		/* bottom */ 
		      									  
		// Turn on headlight if required, now we know where the camera is
		// This is done in world coords, just like 3dr wanted the camera
		pRC->CreateHeadlight( GxVec3f(loc.x, loc.y, loc.z),  GxVec3f(dir.x, dir.y, dir.z), state );

		// Now rebuild the renderer's transform stack, based on the qv stack
		// To get back to model coords
		pRC->RebuildTransformStack((ChQvState*)state);
		pRC->SetCameraLoc(*(GxVec3f*)&loc);			// in world coords!
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
 	DEFAULT_QUERYNODE(this, state);	
}
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
//DO_TYPED_PROPERTY(QvOrthographicCamera, CameraIndex,OrthographicCamera)

void									      
QvOrthographicCamera::traverse(QvState *state)					      
{									      
    ANNOUNCE(className);
   						      
 	DoNodeEditCommand(this, state);

    QvElement *elt = new QvElement;					      
    elt->data = this;							      
    elt->type = QvElement::OrthographicCamera;					      
    state->addElement(QvState::CameraIndex, elt);

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{
		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)GetRenderData();

		if(!pRenderData)
		{
			m_pRenderData = pRenderData = new ChQvPCameraRenderData(this, (ChQvBuildState*)state);
		}
	}
	else if(((ChQvState*)state)->GetType() ==  ChQvState::draw ||  ((ChQvState*)state)->GetType() ==  ChQvState::queryNode)
	{
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
 	DEFAULT_QUERYNODE(this, state);	
}

void									      
QvPerspectiveCamera::traverse(QvState *state)					      
{									      
    ANNOUNCE(className);
   						      
 	DoNodeEditCommand(this, state);

    QvElement *elt = new QvElement;					      
    elt->data = this;							      
    elt->type = QvElement::PerspectiveCamera;					      
    state->addElement(QvState::CameraIndex, elt);

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{
		ChQvPCameraRenderData *pRenderData = (ChQvPCameraRenderData *)GetRenderData();

		if(!pRenderData)
		{
			m_pRenderData = pRenderData = new ChQvPCameraRenderData(this, (ChQvBuildState*)state);
		}
	}
	else if(((ChQvState*)state)->GetType() ==  ChQvState::draw ||  ((ChQvState*)state)->GetType() ==  ChQvState::queryNode)
	{
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
 	DEFAULT_QUERYNODE(this, state);	
}

#endif


void									      
QvTransform::traverse(QvState *state)					      
{									      
 	DoNodeEditCommand(this, state);
 	DEFAULT_QUERYNODE(this, state);	

	ChQvElement *elt = new ChQvElement;					      
	elt->data = this;							      
	elt->type = QvElement::Transform;					      
	state->addElement(QvState::TransformationIndex, elt);

	  
	if( ((ChQvState*)state)->GetType() ==  ChQvState::draw || 
		((ChQvState*)state)->GetType() ==  ChQvState::getBounds ||
		((ChQvState*)state)->GetType() ==  ChQvState::buildInstance ||
		((ChQvState*)state)->GetType() ==  ChQvState::hitTest)
	{
		GxTransformF_t mat;		
		GetTransform(this, mat);
		GxTransform3Wf transform(mat);
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		pRC->ComposeTransform(transform);

		if(((ChQvState*)state)->GetType() ==  ChQvState::buildInstance ) 
		{	
			ChQvBuildState *bldState = (ChQvBuildState*)state;
			if(!m_pRenderData) m_pRenderData = new ChQvTransformationRenderData(this);
			ChQvTransformationRenderData *pRenderData =  (ChQvTransformationRenderData *)m_pRenderData;
			ChQvTransformInstance *pInstance = new ChQvTransformInstance;
			pInstance->Attach(this, bldState);
			pInstance->SetSelfTransform(mat);

			elt->SetInstance(pInstance);
		}
 
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
}

void									      
QvRotation::traverse(QvState *state)					      
{									      
 	DoNodeEditCommand(this, state);
 	DEFAULT_QUERYNODE(this, state);	

	ChQvElement *elt = new ChQvElement;					      
	elt->data = this;							      
	elt->type = QvElement::Rotation;					      
	state->addElement(QvState::TransformationIndex, elt);

	  
	if( ((ChQvState*)state)->GetType() ==  ChQvState::draw || 
		((ChQvState*)state)->GetType() ==  ChQvState::getBounds ||
		((ChQvState*)state)->GetType() ==  ChQvState::buildInstance ||
		((ChQvState*)state)->GetType() ==  ChQvState::hitTest)
	{
		GxTransformF_t mat;		
		GetTransform(this, mat);
		GxTransform3Wf transform(mat);
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		pRC->ComposeTransform(transform);

		if(((ChQvState*)state)->GetType() ==  ChQvState::buildInstance ) 
		{	
			ChQvBuildState *bldState = (ChQvBuildState*)state;
			if(!m_pRenderData) m_pRenderData = new ChQvTransformationRenderData(this);
			ChQvTransformationRenderData *pRenderData =  (ChQvTransformationRenderData *)m_pRenderData;
			ChQvRotationInstance *pInstance = new ChQvRotationInstance;
			pInstance->Attach(this, bldState);
			pInstance->SetSelfTransform(mat);

			elt->SetInstance(pInstance);
		}
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
}

void									      
QvMatrixTransform::traverse(QvState *state)					      
{									      
 	DoNodeEditCommand(this, state);
 	DEFAULT_QUERYNODE(this, state);	

	ChQvElement *elt = new ChQvElement;					      
	elt->data = this;							      
	elt->type = QvElement::MatrixTransform;					      
	state->addElement(QvState::TransformationIndex, elt);

	if( ((ChQvState*)state)->GetType() ==  ChQvState::draw || 
		((ChQvState*)state)->GetType() ==  ChQvState::getBounds ||
		((ChQvState*)state)->GetType() ==  ChQvState::buildInstance ||
		((ChQvState*)state)->GetType() ==  ChQvState::hitTest)
	{
		GxTransformF_t mat;		
		GetTransform(this, mat);
		GxTransform3Wf transform(mat);
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		pRC->ComposeTransform(transform);

		if(((ChQvState*)state)->GetType() ==  ChQvState::buildInstance ) 
		{	
			ChQvBuildState *bldState = (ChQvBuildState*)state;
			if(!m_pRenderData) m_pRenderData = new ChQvTransformationRenderData(this);
			ChQvTransformationRenderData *pRenderData =  (ChQvTransformationRenderData *)m_pRenderData;
			ChQvMatrixTransformInstance *pInstance = new ChQvMatrixTransformInstance;
			pInstance->Attach(this, bldState);
			pInstance->SetSelfTransform(mat);

			elt->SetInstance(pInstance);
		}

		
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
}

void									      
QvTranslation::traverse(QvState *state)					      
{									      
 	DoNodeEditCommand(this, state);
 	DEFAULT_QUERYNODE(this, state);	

	ChQvElement *elt = new ChQvElement;					      
	elt->data = this;							      
	elt->type = QvElement::Translation;					      
	state->addElement(QvState::TransformationIndex, elt);

	if( ((ChQvState*)state)->GetType() ==  ChQvState::draw || 
		((ChQvState*)state)->GetType() ==  ChQvState::getBounds ||
		((ChQvState*)state)->GetType() ==  ChQvState::buildInstance ||
		((ChQvState*)state)->GetType() ==  ChQvState::hitTest)
	{
		GxTransformF_t mat;		
		GetTransform(this, mat);
		GxTransform3Wf transform(mat);
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		pRC->ComposeTransform(transform);

		if(((ChQvState*)state)->GetType() ==  ChQvState::buildInstance ) 
		{	
			ChQvBuildState *bldState = (ChQvBuildState*)state;
			if(!m_pRenderData) m_pRenderData = new ChQvTransformationRenderData(this);
			ChQvTransformationRenderData *pRenderData =  (ChQvTransformationRenderData *)m_pRenderData;
			ChQvTranslationInstance *pInstance = new ChQvTranslationInstance;
			pInstance->Attach(this, bldState);
			pInstance->SetSelfTransform(mat);

			elt->SetInstance(pInstance);
		}



	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
}

void									      
QvScale::traverse(QvState *state)					      
{									      
 	DoNodeEditCommand(this, state);
 	DEFAULT_QUERYNODE(this, state);	

	ChQvElement *elt = new ChQvElement;					      
	elt->data = this;							      
	elt->type = QvElement::Scale;					      
	state->addElement(QvState::TransformationIndex, elt);

	if( ((ChQvState*)state)->GetType() ==  ChQvState::draw || 
		((ChQvState*)state)->GetType() ==  ChQvState::getBounds ||
		((ChQvState*)state)->GetType() ==  ChQvState::buildInstance ||
		((ChQvState*)state)->GetType() ==  ChQvState::hitTest)
	{
		GxTransformF_t mat;		
		GetTransform(this, mat);
		GxTransform3Wf transform(mat);
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		pRC->ComposeTransform(transform);

		if(((ChQvState*)state)->GetType() ==  ChQvState::buildInstance ) 
		{	
			ChQvBuildState *bldState = (ChQvBuildState*)state;
			if(!m_pRenderData) m_pRenderData = new ChQvTransformationRenderData(this);
			ChQvTransformationRenderData *pRenderData =  (ChQvTransformationRenderData *)m_pRenderData;
			ChQvScaleInstance *pInstance = new ChQvScaleInstance;
			pInstance->Attach(this, bldState);
			pInstance->SetSelfTransform(mat);

			elt->SetInstance(pInstance);
		}
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
}

//////////////////////////////////////////////////////////////////////////////
//
// Shapes.
//
//////////////////////////////////////////////////////////////////////////////

static void
printProperties(QvState *state)
{
    #if 0
    OutputDebugString("--------------------------------------------------------------\r\n");
    state->print();
    OutputDebugString("--------------------------------------------------------------\r\n");
	#endif
}

#define DO_SHAPE(className)						      \
void									      \
className::traverse(QvState *state)					      \
{									      \
    ANNOUNCE(className);						      \
 	DEFAULT_QUERYNODE(this, state);				 \
    printProperties(state);						      \
}

//DO_SHAPE(QvPointSet)
//DO_SHAPE(QvAsciiText)
void
QvAsciiText::traverse(QvState *state)	
{									 
    
 	DEFAULT_QUERYNODE(this, state);	

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);
		ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)m_pRenderData;
		ChQvAsciiTextInstance *pInstance = new ChQvAsciiTextInstance;
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();
	}	
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
}
                                    
				  
inline int VertCount(long *values)
{
	int i = 0;
	while(values[i] != QV_END_FACE_INDEX) i++;
	return i;
}


void
QvIndexedFaceSet::traverse(QvState *state)	
{									 
    
 	DEFAULT_QUERYNODE(this, state);	

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvIFSRenderData(this, state);
		ChQvIFSRenderData *pRenderData =  (ChQvIFSRenderData *)m_pRenderData;
		ChQvIFSInstance *pInstance = new ChQvIFSInstance;
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();

	}	
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
}
                                    
void
QvIndexedLineSet::traverse(QvState *state)	
{									 
    
 	DEFAULT_QUERYNODE(this, state);	

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);
		ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)m_pRenderData;
		ChQvILSInstance *pInstance = new ChQvILSInstance;
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();

	}	
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
}
                                    
void
QvPointSet::traverse(QvState *state)	
{									 
    
 	DEFAULT_QUERYNODE(this, state);	

	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);
		ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)m_pRenderData;
		ChQvPointSetInstance *pInstance = new ChQvPointSetInstance;
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();
	}	
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::command)
	{
	}			
}
                                    
void
QvCube::traverse(QvState *state)	
{									 
    
 	DEFAULT_QUERYNODE(this, state);	
	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);
		ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)m_pRenderData;
		ChQvCubeInstance *pInstance = new ChQvCubeInstance;
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();

	}	
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
	}
 }


void
QvCylinder::traverse(QvState *state)	
{									 
 	DEFAULT_QUERYNODE(this, state);	
    
	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);
		ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)m_pRenderData;
		ChQvCylinderInstance *pInstance = new ChQvCylinderInstance;
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();

	}	
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
	}
 }

void
QvCone::traverse(QvState *state)	
{									 
 	DEFAULT_QUERYNODE(this, state);	
    
	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);
		ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)m_pRenderData;
		ChQvConeInstance *pInstance = new ChQvConeInstance;
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();

	}	
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
	}
 }

void
QvSphere::traverse(QvState *state)	
{									 
 	DEFAULT_QUERYNODE(this, state);	
    
	if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{

	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChQvBuildState *bldState = (ChQvBuildState*)state;
		int level = 8;	// 8 = default	-- should compute based on bbox
		if(!m_pRenderData) m_pRenderData = new ChQvSphereRenderData(this);
		ChQvSphereRenderData *pRenderData =  (ChQvSphereRenderData *)m_pRenderData;
		ChQvSphereInstance *pInstance = new ChQvSphereInstance;
		pInstance->Attach(this, bldState);

	}	

}
//////////////////////////////////////////////////////////////////////////////
//
// Script-like nodes.
//
//////////////////////////////////////////////////////////////////////////////

void
QvSpin::traverse(QvState *state)	
{									 
 	DEFAULT_QUERYNODE(this, state);	
    
	if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{

	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChQvBuildState *bldState = (ChQvBuildState*)state;
		int level = 8;	// 8 = default	-- should compute based on bbox
		if(!m_pRenderData) m_pRenderData = new ChQvSpinRenderData(this);

	}	

}

//////////////////////////////////////////////////////////////////////////////
//
// WWW-specific nodes.
//
//////////////////////////////////////////////////////////////////////////////


void 
QvWWWAnchor::traverse(QvState *state)
{
    ANNOUNCE(QvWWWAnchor);
	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	

		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		pRC->PushTransform();

	    state->push();

		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);
		ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)m_pRenderData;
		ChQvWWWAnchorInstance *pInstance = new ChQvWWWAnchorInstance;
		pRenderData->Attach(this);
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();
		bldState->SetCurrentParent(pInstance);
		 
	    indent++;
	    for (int i = 0; i < getNumChildren(); i++)
			getChild(i)->traverse(state);
	    indent--;
	    state->pop();

		pRC->PopTransform();

		if(pParent) bldState->SetCurrentParent(pParent);

	}	
	else
	if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		pRC->PushTransform();

		state->push();
    
	    indent++;
	    for (int i = 0; i < getNumChildren(); i++)
			getChild(i)->traverse(state);
	    indent--;
		state->pop();

		pRC->PopTransform();

		UpdateSensor(state);
	}
	else
	{
		QueryNode(this, state);
		state->push();
	    indent++;
	    for (int i = 0; i < getNumChildren(); i++)
		getChild(i)->traverse(state);
	    indent--;
		state->pop();
	}
}

void 
QvWWWInline::traverse(QvState *state)
{
    ANNOUNCE(QvWWWInline);
	if( ((ChQvState*)state)->GetType() ==  ChQvState::purgeTree)
	{
		ChQvWWWInlineRenderData *pRenderData =  (ChQvWWWInlineRenderData *)m_pRenderData;
		if(pRenderData->GetInstanceCount() == 0)
		{
		    for ( int i = 0; i < getNumChildren(); i++)
				getChild(i)->Release();
		}
		while(getNumChildren() > 0)
		{
			getChildren()->remove(getNumChildren() - 1);
		}
		pRenderData->SetURL(string(""));



	#if 0
	    if(GetUsage() <= 1)
	    {
		    state->push();
		    indent++;

		    for (int i = 0; i < getNumChildren(); i++)
				getChild(i)->traverse(state);
		    indent--;
		    state->pop();
		    for ( i = 0; i < getNumChildren(); i++)
				getChild(i)->Release();

		}
	#endif	
	}
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	
		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();
		pRC->PushTransform();

	    state->push();

		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvWWWInlineRenderData(this);
		ChQvWWWInlineRenderData *pRenderData =  (ChQvWWWInlineRenderData *)m_pRenderData;
		ChQvWWWInlineInstance *pInstance = new ChQvWWWInlineInstance;
		pInstance->Attach(this, bldState);
		ChQvGroupInstance *pParent =	bldState->GetCurrentParent();
		bldState->SetCurrentParent(pInstance);
		 
	    indent++;
	    for (int i = 0; i < getNumChildren(); i++)
		{
			getChild(i)->traverse(state);
		}
	    indent--;
	    state->pop();

		pRC->PopTransform();

		if(pParent) bldState->SetCurrentParent(pParent);

	}	
	else if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
	    indent++;
	    for (int i = 0; i < getNumChildren(); i++)
			getChild(i)->traverse(state);
	    indent--;
	}
	else if( ((ChQvState*)state)->GetType() == ChQvState::spawnRequests)
	{

		// Spawn a new http request
		ChQvSpawnState *spawnState = (ChQvSpawnState *)state;
		string strURL = name.value.getString();
		ChQvWWWInlineRenderData *pRenderData =  (ChQvWWWInlineRenderData *)m_pRenderData;

		// Check to see if we have the file, or have a request or parse outstanding
		if(pRenderData->GetCurrentURL().IsEmpty() && pRenderData->GetReq() == 0 && pRenderData->GetParseInfo() == 0)
		{
			// Only request if there is no file already here
			ChMazeInlineHTTPReq *pHTTPReq = new ChMazeInlineHTTPReq ( spawnState->GetView(), strURL, this );
			pHTTPReq->SetPage(spawnState->GetView()->GetCurrentPage());
			pRenderData->SetReq(pHTTPReq);

		   	string defURL = spawnState->GetDefaultURL();
			spawnState->GetView()->GetURL( strURL, (chparam)pHTTPReq, LPCTSTR(defURL) );
		}
	}

	else
	{
		QueryNode(this, state);
	    indent++;
	    for (int i = 0; i < getNumChildren(); i++)
		{
			getChild(i)->traverse(state);
		}
	    indent--;
	}
}

void									      
QvInfo::traverse(QvState *qvstate)					      
{									      
 	DEFAULT_QUERYNODE(this, qvstate);
 		

	if(getName() == "Shading")
	{	   // only push this on the stack if it's a shading node
		if(!m_pRenderData)
		{
			// first pass, alloc an info render object
			ChQvInfoRenderData	*pRenderData = new  ChQvInfoRenderData(this);   
			m_pRenderData	 = 	pRenderData;

		}
	}
	else if (getName() == "BackgroundImage")
	{
		if(!m_pRenderData)
		{
			// first pass, alloc a render bginfo object
			ChQvBackgroundInfoData	*pRenderData = new  ChQvBackgroundInfoData(this);   
			m_pRenderData	 = 	pRenderData;

		}										   
	}
	else
	{
		if(!m_pRenderData)
		{
			// first pass, alloc a render base object
			ChQvRenderBaseData	*pRenderData = new  ChQvRenderBaseData(this);   
			m_pRenderData	 = 	pRenderData;

		}										   
	}										   
	if(getName() == "Shading")
	{	   // only push this on the stack if it's a shading node
	    QvElement *elt = new QvElement;					      
	    elt->data = this;							      
	    qvstate->addElement(QvState::InfoIndex, elt);
		::string val = string.value.getString();

		ChQvInfoRenderData	*pRenderData = (ChQvInfoRenderData	*)m_pRenderData;
		if(getName() == "Shading")
		{
			if(!val.CompareNoCase("flat"))
			{
				pRenderData->SetShading( flatShading );
			}
			else if(!val.CompareNoCase("none"))
			{
				pRenderData->SetShading( noShading );
			}
			else if(!val.CompareNoCase("smooth"))
			{
				pRenderData->SetShading( smoothShading );
			}
			else pRenderData->SetShading( defaultShading );
		}
	}
	  
	if( ((ChQvState*)qvstate)->GetType() ==  ChQvState::findGlobals)
	{
		ChQvGlobalSearchState *state = (ChQvGlobalSearchState*)qvstate; 
		::string val = string.value.getString();
		if(getName() == "BackgroundColor")
		{
			ChColor color(0,0,0); 
			#if defined( CH_ARCH_16 )   
			LPCSTR pstrVal = (LPCTSTR)val;
			char * pstrEnd;    
			color.SetR( strtod( pstrVal, &pstrEnd ));
			if ( pstrVal != pstrEnd )
			{   
				pstrVal = pstrEnd;
				color.SetG(strtod( pstrVal, &pstrEnd ));
			
				if ( pstrVal != pstrEnd )
				{   
					pstrVal = pstrEnd;
					color.SetB(strtod( pstrVal, &pstrEnd ));  
					if ( pstrVal != pstrEnd )
					{  
						state->SetBackground(color);
					} 
				}
				
			}
			#else
			float r, g, b;
			if(sscanf(LPCTSTR(val), "%f %f %f", &r, &g, &b) == 3)
			{
				color.set(r, g, b);
				state->SetBackground(color);
			}
			#endif
		}
		else if(getName() == "AspectRatio")
		{
			float fVal;    
			#if defined( CH_ARCH_16 )   

			LPCSTR pstrVal = (LPCTSTR)val;
			char * pstrEnd;    
			fVal = strtod( pstrVal, &pstrEnd );

			if ( pstrVal != pstrEnd )
			{
				state->SetAspect(fVal);
			}
			else
			{
				state->SetAspect(-1.);
			}  
			
			#else
			if(sscanf(LPCTSTR(val), "%f", &fVal) == 1)
			{
				state->SetAspect(fVal);
			}
			else
			{
				state->SetAspect(-1.);
			}  
			
			#endif
		}
		else if (getName() == "Shading")
		{									// Discard this??????
			ChShadingLevel	shading;

			if (!val.CompareNoCase( "flat" ))
			{
				shading = flatShading;
			}
			else if (!val.CompareNoCase( "none" ))
			{
				shading = noShading;
			}
			else
			{
				shading = smoothShading;
			}

			state->SetShading( shading );
		}
		else if (getName() == "Viewer")
		{
			/*	    DEF Viewer Info { string  "walk" }	*/
			#define VIEWER_WALK	"walk"
			#define VIEWER_FLY	"fly"
			#define VIEWER_EXAMINE	"examine"

			Ch3DViewerMode	mode = none;

			if (!val.CompareNoCase( VIEWER_WALK ))
			{
				mode = walk;
			}
			if (!val.CompareNoCase( VIEWER_EXAMINE ))
			{
				mode = examine;
			}
			else if (!val.CompareNoCase( VIEWER_FLY ))
			{
				mode = fly;
			}

			if(mode != none) state->SetViewerMode( mode );

		}
		else if (getName() == "CollisionDetection")
		{
			/*
			  DEF CollisionDetection Info 
              {
                  string  "TRUE"  # Turn on collision detection for the scene
              }
			*/

			Ch3DCollisionMode	mode = collisionOff;

			if (!val.CompareNoCase( "true" ))
			{
				mode = collisionOn;
			}

			if(mode != none) state->SetCollisionMode( mode );

		}

	}
	if (getName() == "BackgroundImage" && ((ChQvState*)qvstate)->GetType() ==  ChQvState::spawnRequests)
	{
		ChQvBackgroundInfoData	*pRenderData =  (ChQvBackgroundInfoData* )m_pRenderData;
		#if defined(CH_WANT_TEXTURED_BACKGROUNDS)
		pRenderData->GetURL(qvstate);
		#endif
	}
}

//////////////////////////////////////////////////////////////////////////////
//
// Wierd Stuff.
//
//////////////////////////////////////////////////////////////////////////////


void 
QvRoute::traverse(QvState *state)
{
    ANNOUNCE(QvRoute);
	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	

		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();

		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvRenderBaseData(this);
		ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)m_pRenderData;

		// DO THE CONNECTIONS HERE!!!!!!!
		#if 0 && defined(CH_VRML_EVENTS)
			ChVrmlBrowser * pBrowser = GetView()->GetBrowser();

			// Find the subject node
			
			string strNode(nodeName);

			QvNode * pSrcNode = (QvNode*)(pBrowser->Resolve(0, strNode));
			QvNode * pSrcNode = (QvNode*)(pBrowser->Resolve(0, strNode));
		#endif
	}	
	else
	if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
		// do nada
	}
	else
	{
		QueryNode(this, state);
	}
}

void 
QvTimeSensor::traverse(QvState *state)
{
    ANNOUNCE(QvRoute);
	if( ((ChQvState*)state)->GetType() ==  ChQvState::buildInstance)
	{	

		ChRenderContext *pRC = ((ChQvState*)state)->GetView()->GetRenderContext();

		ChQvBuildState *bldState = (ChQvBuildState*)state;
		if(!m_pRenderData) m_pRenderData = new ChQvTimeSensorRenderData(this);
		ChQvTimeSensorRenderData *pRenderData =  (ChQvTimeSensorRenderData *)m_pRenderData;
		pRenderData->Install(pRC);

	}	
	else
	if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
	{
		// do nada
	}
	else
	{
		QueryNode(this, state);
	}
}

//////////////////////////////////////////////////////////////////////////////
//
// Default traversal methods. These nodes have no effects during traversal.
//
//////////////////////////////////////////////////////////////////////////////

DEFAULT_TRAVERSE(QvUnknownNode)
DEFAULT_TRAVERSE(QvBaseColor)
DEFAULT_TRAVERSE(QvBackground)
DEFAULT_TRAVERSE(QvInterpolator)
DEFAULT_TRAVERSE(QvOrientationInterpolator)
DEFAULT_TRAVERSE(QvPositionInterpolator)
DEFAULT_TRAVERSE(QvSensor)
DEFAULT_TRAVERSE(QvNavigationInfo)
//DEFAULT_TRAVERSE(QvTimeSensor)
//DEFAULT_TRAVERSE(QvRoute)

#if defined(_QV_ENVIRONMENT_)
DEFAULT_TRAVERSE(QvEnvironment)
#endif

//////////////////////////////////////////////////////////////////////////////

// just here for now; put in separate file asap
void
ChQvInput::putBack(char c)
{
    if (c == (char) EOF)
	return;

    if (backBufIndex >= 0)
	--backBufIndex;
    else
		m_is->putback(c);
}


QvBool
ChQvInput::eof() const
{
    return m_is->eof();
}


QvBool
ChQvInput::get(char &c)
{
    QvBool ret;

    if (backBufIndex >= 0) {
	c = backBuf.getString()[backBufIndex++];

	if (c != '\0')
	    return TRUE;

	backBuf.makeEmpty();
	backBufIndex = -1;
    }

    if (! readHeader && ! checkHeader())
	return FALSE;

    if (eof()) {
	c = (char)EOF;
	ret = FALSE;
    }

    else {
	int i = m_is->get();

	if (i == EOF) {
	    c = (char)EOF;
	    ret = FALSE;
	}
	else {
	    c = (char) i;
	    ret = TRUE;
	}
    }

    return ret;
}

//////////////////////////////////////////////////////////////////////
///////////////

ChQvFileMapInput::ChQvFileMapInput() : QvInput(), 
				m_hFile( INVALID_HANDLE_VALUE ),
				m_hFileMap( 0 ),
				m_pMappedView( 0 ), m_lFileSize( 0 ),
				m_lCurrIndex( 0 ), m_boolCancel( false )
{

}
ChQvFileMapInput::~ChQvFileMapInput()
{
	if ( m_hFile != INVALID_HANDLE_VALUE )
	{
		if ( m_pMappedView ) 
		{
			::UnmapViewOfFile( m_pMappedView );
		}
		if ( m_hFileMap )
		{
			::CloseHandle( m_hFileMap );
		}

		::CloseHandle( m_hFile );
	}

}

void ChQvFileMapInput::setFilePointer(HANDLE hFile )
{
	ASSERT( hFile );
	// save the file handle
	m_hFile = hFile;

	DWORD  dwHigh;

	m_lFileSize = ::GetFileSize( m_hFile, &dwHigh );
	// Map if we have a good file
	if ( m_lFileSize || dwHigh )
	{
		
		m_hFileMap =  CreateFileMapping(
				    			m_hFile,	// handle of file to map 
				      			NULL,	// optional security attributes 
				    			PAGE_READONLY | SEC_COMMIT,	// protection for mapping object 
				    			0,	// high-order 32 bits of object size  
				    			0,	// low-order 32 bits of object size  
				    			NULL 	// name of file-mapping object 
		   );	

		ASSERT( m_hFileMap );

		m_pMappedView = (char*) MapViewOfFile(
						    m_hFileMap,		// file-mapping object to map into address space  
						    FILE_MAP_READ,	// access mode 
						    0,	// high-order 32 bits of file offset 
						    0,	// low-order 32 bits of file offset 
						    0 	// number of bytes to map, 0 = Map the whole file
		   );
		ASSERT( m_pMappedView );

	}
}

QvBool ChQvFileMapInput::get(char &c)
{
    QvBool ret;

	if ( m_boolCancel )
	{
		c = (char)EOF;
		return FALSE;
	}
    
    if (backBufIndex >= 0) 
    {
		c = backBuf.getString()[backBufIndex++];

		if (c != '\0')
		    return TRUE;

		backBuf.makeEmpty();
		backBufIndex = -1;
    }

    if (! readHeader && ! checkHeader())
	return FALSE;

	if ( m_lCurrIndex < m_lFileSize )
	{
	  	c = m_pMappedView[ m_lCurrIndex++ ];
	    ret = TRUE;
	}
	else
	{
		c = (char)EOF;
		ret = FALSE;
	}

    return ret;
}


void ChQvFileMapInput::putBack(char c)
{
    if (c == (char) EOF)
	return;

    if (backBufIndex >= 0)
	{
		--backBufIndex;
	}
    else
	{
		ASSERT( m_lCurrIndex );

		--m_lCurrIndex;  // move the pointer index back by one	
	}
}

QvBool ChQvFileMapInput::eof() const
{
	return ( m_boolCancel || m_lCurrIndex >= m_lFileSize );	
}

#if defined(CH_USE_3DR)
#endif // temporary 3dr only

#undef ANNOUNCE
#undef DEFAULT_TRAVERSE
#undef DO_PROPERTY
#undef DO_SHAPE
#undef DO_TYPED_PROPERTY
