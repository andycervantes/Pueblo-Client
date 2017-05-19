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

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChRenderData.cpp,v 2.30 1996/08/22 22:45:14 jimd Exp $

#include "grheader.h"

#include <QvInfo.h>
#include <QvState.h>
#include "ChMaze.h"
#include "ChRenderData.h"
#include "ChScriptData.h"
#include "ChMazDep.h"
#include "CvConvrt.h"
#include "CvTrnsfm.h"
#include "CvNormal.h"
#include "CvInstnc.h"
#include "CvType.h"
#include "CvHitTst.h"
#include "ChSphere.h"
#include "ChRLImg.h"
#include <ChSFImage.h>
#include "ChQvPars.h"


#include <ChCore.h>
#include <ChUtil.h>

#include <QvChildList.h>
// Statics
// Be sure to Term all these classes in ChQvRenderBaseData::Term()

ChQvRenderBaseData::ChVrmlDispatcher *ChQvTransformationRenderData::m_pDispatcher = 0;
ChQvRenderBaseData::ChVrmlDispatcher *ChQvGroupRenderData::m_pDispatcher = 0;
ChQvRenderBaseData::ChVrmlDispatcher *ChQvSwitchRenderData::m_pDispatcher = 0;
ChQvRenderBaseData::ChVrmlDispatcher *ChQvSpinGroupRenderData::m_pDispatcher = 0;
ChQvRenderBaseData::ChVrmlDispatcher *ChQvPCameraRenderData::m_pDispatcher = 0;




// Base Render Data
ChQvRenderBaseData::~ChQvRenderBaseData()
{
	while(!m_instances.IsEmpty())
	{
		ChQvInstance *pInstance = m_instances.RemoveHead();
		pInstance->SetRenderData(0);
	}
	// Also need to get rid of dependents!!!!!!!!
	while(!m_dependents.IsEmpty())
	{
		ChQvInstance *pInstance = m_dependents.RemoveHead();
		pInstance->RemoveProperty(this);
	}
};

ChQvRenderBaseData *ChQvRenderBaseData::Attach(QvNode *pNode)
{
	m_pNode = pNode;
	return this;
}

ChQvRenderBaseData *ChQvRenderBaseData::Add(ChQvInstance *pInstance)
{
	m_instances.AddTail(pInstance);
	return this;
}

ChQvRenderBaseData *ChQvRenderBaseData::Remove(ChQvInstance *pInstance)
{
	if(m_instances.IsEmpty()) return this;
	ChPosition pos = m_instances.Find(pInstance);
	if(pos)
	{
		m_instances.Remove(pos);
	}
	return (this);
}

ChQvRenderBaseData *ChQvRenderBaseData::AddDependent(ChQvInstance *pInstance)
{
	m_dependents.AddTail(pInstance);
	return this;
}

bool ChQvRenderBaseData::RemoveDependent(ChQvInstance *pInstance)
{
	if(m_dependents.IsEmpty()) return false;
	ChPosition pos = m_dependents.Find(pInstance);
	if(pos)
	{
		m_dependents.Remove(pos);
	}
	return (pos != 0);
}

bool ChQvRenderBaseData::DispatchEvent(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEvent)
{
#if defined(CH_VRML_EVENTS)

	ChVrmlDispatcher	*pDisp = GetDispatcher();
	if(pDisp)
	{
		ChEventDispatch *pDispDesc = pDisp->Find(pEvent->GetName());
		if(pDispDesc)
		{
			return ((this->*(pDispDesc->m_handler))(pRC, pApplet, pEvent));
		}
	}
	// Not handled yet, so we'll try routing directly to the field
	QvField *fld = 0;
	LPCTSTR strEvent = pEvent->GetName();
	if(QvRoute::findConnection(GetNode(), strEvent, fld, true))
	{
		// Need some serious type checking here	  TODO !!!!!!!!!!!!
		if(fld->getType() == pEvent->GetFieldType())
		{
			if(pEvent->IsMultiple() && pEvent->GetCount())
			{
				((QvMField*)fld)->setValues(pEvent->GetBytes(), 0, pEvent->GetCount());
			}
			else
			{
				((QvSField*)fld)->setValue(pEvent->GetBytes());
				SetDirty(true);
			}
		}
		else
		{
			// Post an error!! TODO!!!!
			string * pMsg = new string( "Error : Attempt to attach - field type mismatch" );
			// The merssage string is deleted by the message handler
			((ChMazeWnd*)pRC->GetWnd())->PostMessage(  WM_VRML_MAZE_ERROR, 
												CH_MAZE_ROUTE_ERROR_FIELD_MISMATCH, 
												(LPARAM)pMsg );
		}
	}
	else
	{
		string * pMsg = new string( "Error : Invalid event name" );
		// The merssage string is deleted by the message handler
		((ChMazeWnd*)pRC->GetWnd())->PostMessage(  WM_VRML_MAZE_ERROR, 
											CH_MAZE_ROUTE_ERROR_EVENT_NOTFOUND, 
											(LPARAM)pMsg );
	}

#endif
	return false;
};

void ChQvRenderBaseData::PurgeQv()
{
	QvNode* pNode = m_pNode;
	ChQvPurgeState	state(0);
	pNode->traverse(&state);
}

int ChQvRenderBaseData::GetInstanceCount()
{
	return m_instances.GetCount();
}

ChQvRenderBaseData *ChQvRenderBaseData::Add(ChQvScriptRenderData *pScript)
{
	ASSERT(pScript);
	
	if(m_scripts.IsEmpty() || !(m_scripts.Find(pScript)))
	{							 // No Dupes!
		m_scripts.AddTail(pScript);
		// Now add our instances to the script
		if (!m_instances.IsEmpty())
		{
			ChPosition pos = m_instances.GetHeadPosition();
			while(pos)
			{
				ChQvInstance *pInst = m_instances.GetNext(pos);
				if(pInst) pScript->AddInstance(pInst);
			}
		}
	}

	return this;
}

ChQvRenderBaseData *ChQvRenderBaseData::Remove(ChQvScriptRenderData *pScript)
{
	if(m_scripts.IsEmpty()) return this;
	ChPosition pos = m_scripts.Find(pScript);
	if(pos)
	{
		m_scripts.Remove(pos);
	}
	return (this);
}

#if 0
class MyBaseDirtyIterator : public ChQvRenderBaseDataIterator
{
	public:
		MyBaseDirtyIterator( const ChQvRenderBaseData& rbd ) : ChQvRenderBaseDataIterator(rbd) {};


		virtual int DoInstance(ChQvInstance& inst)
		{

			inst.SetDirty(true);
			return true;
		};


   protected:

   private:
											/* Disable copy constructor and
												assignment operator */

      inline MyBaseDirtyIterator( const MyTransformDirtyIterator& ) {}
      inline MyBaseDirtyIterator& operator=( const MyTransformDirtyIterator& )
      			{
      				return *this;
      			}
};
#endif

void ChQvRenderBaseData::SetDirty(bool boolDirty)
{
	ChQvRenderData::SetDirty(boolDirty);
	// nada for now, use the iterator later when we handle things other than transforms
} 

/* Standard ABC Instance Iterator for base data */

ChQvRenderBaseDataIterator::ChQvRenderBaseDataIterator()
{
}

ChQvRenderBaseDataIterator::ChQvRenderBaseDataIterator( const ChQvRenderBaseData& rbd )
{
	Attach((ChQvRenderBaseData&)rbd);
}

ChQvRenderBaseDataIterator::~ChQvRenderBaseDataIterator()
{
	
}

void ChQvRenderBaseDataIterator::Attach( ChQvRenderBaseData& rbd )
{
	m_pData = &rbd;
}

int ChQvRenderBaseDataIterator::Iterate()
{
	bool boolKeepGoing = true;
	if (!m_pData->m_instances.IsEmpty())
	{
		ChPosition pos = m_pData->m_instances.GetHeadPosition();
		while(pos && boolKeepGoing)
		{
			ChQvInstance *pInst = m_pData->m_instances.GetNext(pos);
			boolKeepGoing = DoInstance(*pInst);
		}
	}
	return boolKeepGoing;
}

int ChQvRenderBaseDataIterator::IterateDependents()
{
	bool boolKeepGoing = true;
	if (!m_pData->m_dependents.IsEmpty())
	{
		ChPosition pos = m_pData->m_dependents.GetHeadPosition();
		while(pos && boolKeepGoing)
		{
			ChQvInstance *pInst = m_pData->m_dependents.GetNext(pos);
			boolKeepGoing = DoInstance(*pInst);
		}
	}
	return boolKeepGoing;
}

int ChQvRenderBaseDataIterator::IterateScripts()
{
	bool boolKeepGoing = true;
	if (!m_pData->m_scripts.IsEmpty())
	{
		ChPosition pos = m_pData->m_scripts.GetHeadPosition();
		while(pos && boolKeepGoing)
		{
			ChQvScriptRenderData *pScript = m_pData->m_scripts.GetNext(pos);
			boolKeepGoing = DoScript(*pScript);
		}
	}
	return boolKeepGoing;
}


void ChQvRenderBaseData::Term()
{
	ChQvTransformationRenderData::Term();
	ChQvGroupRenderData::Term();
	ChQvSwitchRenderData::Term();
	ChQvSpinGroupRenderData::Term();
	ChQvPCameraRenderData::Term();
}


/* Types of render data */
ChQvTransformationRenderData::ChQvTransformationRenderData(QvNode* pNode) : 
	ChQvRenderBaseData(pNode)
{
#if defined(CH_VRML_EVENTS)
	if(!m_pDispatcher)
	{
		m_pDispatcher = new	ChVrmlDispatcher;
		Init();
	}
#endif
};

void ChQvTransformationRenderData::Init()
{
	ChQvRenderBaseData::Init();
#if defined(CH_VRML_EVENTS)

	AddVrmlDispatcher("set_rotation", SFRotation, OnSetRotation);
	AddVrmlDispatcher("set_translation", SFVec3f, OnSetTranslation);
	AddVrmlDispatcher("set_scaleFactor", SFVec3f, OnSetScaleFactor);
	AddVrmlDispatcher("set_scaleOrientation", SFRotation, OnSetScaleOrientation);
	AddVrmlDispatcher("set_center", SFVec3f, OnSetCenter);

#endif

};



ChQvTransformationRenderData::~ChQvTransformationRenderData()
{
	//  delete instances - not stored in the instance tree, so we do it here
	while(!m_instances.IsEmpty())
	{
		ChQvInstance *pInstance = m_instances.RemoveHead();
		if(pInstance) pInstance->Release();
	}
}


void ChQvTransformationRenderData::Term()
{
#if defined(CH_VRML_EVENTS)
	delete m_pDispatcher;
	m_pDispatcher = 0;
#endif
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#if 1 || defined(CH_VRML_EVENTS)
class MyTransformDirtyIterator: public ChQvRenderBaseDataIterator
{
	public:
		MyTransformDirtyIterator( const ChQvTransformationRenderData& rbd ) : ChQvRenderBaseDataIterator(rbd) {};


		virtual int DoInstance(ChQvInstance& inst)
		{

			GxTransformF_t mat;
			// Needs to get fixed for other transform types
			string strType;
			switch(inst.GetNode()->GetType(strType))
			{
				case typeQvRotation:
				{
					GetTransform((QvRotation*)(inst.GetNode()), mat);
					break;
				}
				case typeQvTransform:
				{
					GetTransform((QvTransform*)(inst.GetNode()), mat);
					break;
				}
				case typeQvScale:
				{
					GetTransform((QvScale*)(inst.GetNode()), mat);
					break;
				}
				case typeQvTranslation:
				{
					GetTransform((QvTranslation*)(inst.GetNode()), mat);
					break;
				}
				case typeQvMatrixTransform:
				{
					GetTransform((QvMatrixTransform*)(inst.GetNode()), mat);
					break;
				}
			}
			ChQvTransformInstance *pInst = (ChQvTransformInstance *)&inst;
			pInst->SetSelfTransform(mat);


			inst.SetTransformDirty(true);
			return true;
		};


   protected:

   private:
											/* Disable copy constructor and
												assignment operator */

      inline MyTransformDirtyIterator( const MyTransformDirtyIterator& ) {}
      inline MyTransformDirtyIterator& operator=( const MyTransformDirtyIterator& )
      			{
      				return *this;
      			}
};
#endif
#endif

void ChQvTransformationRenderData::SetDirty(bool boolDirty)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#if 1 || defined(CH_VRML_EVENTS)
	m_boolDirty = boolDirty;

	if(boolDirty)
	{
		MyTransformDirtyIterator iterator(*this);

		iterator.Iterate();
	}
	m_boolDirty = false;
#endif
#endif
} 


bool ChQvTransformationRenderData::OnSetRotation(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEventList)
{
	bool boolSuccess = false;
#if defined(CH_VRML_EVENTS)
	// Apply based on transform type - eventually this gets merged into
	// the containing separator in 2.0 - if we were going to keep this node, 
	// we'd split out the classes, but for now just hack it
	string strType;
	float axis[3];
	float angle;
	ChRotationEvent *pEvent = (ChRotationEvent *)pEventList;
	pEvent->GetValue(axis, angle);
	QvSFRotation *pRotation = 0;

	if(m_pNode->GetType(strType) == typeQvRotation)
	{
		QvRotation *pNode = (QvRotation *)m_pNode;
		pRotation = &(pNode->rotation);
		boolSuccess = true;
	}
	else if(m_pNode->GetType(strType) == typeQvTransform)
	{
		QvTransform *pNode = (QvTransform *)m_pNode;
		pRotation = &(pNode->rotation);
		boolSuccess = true;
	}

	if(boolSuccess)
	{
		if((axis[0] != pRotation->axis[0]) ||
			(axis[1] != pRotation->axis[1]) ||
			(axis[2] != pRotation->axis[2]) ||
			(angle != pRotation->angle))
		{
			pRotation->axis[0] = axis[0];
			pRotation->axis[1] = axis[1];
			pRotation->axis[2] = axis[2];
			pRotation->angle = angle;
			//SetDirty();

			MyTransformDirtyIterator iterator(*this);

			iterator.Iterate();
		}

	}
#endif

	return boolSuccess;
}

bool ChQvTransformationRenderData::OnSetScaleFactor(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEventList)
{
	bool boolSuccess = false;
#if defined(CH_VRML_EVENTS)
	// Apply based on transform type - eventually this gets merged into
	// the containing separator in 2.0 - if we were going to keep this node, 
	// we'd split out the classes, but for now just hack it
	string strType;
	float scale[3];
	ChVec3fEvent *pEvent = (ChVec3fEvent *)pEventList;
	pEvent->GetValue(scale);
	QvSFVec3f *pScale = 0;

	if(m_pNode->GetType(strType) == typeQvScale)
	{
		QvScale *pNode = (QvScale *)m_pNode;
		pScale = &(pNode->scaleFactor);
		boolSuccess = true;
	}
	else if(m_pNode->GetType(strType) == typeQvTransform)
	{
		QvTransform *pNode = (QvTransform *)m_pNode;
		pScale = &(pNode->scaleFactor);
		boolSuccess = true;
	}

	if(boolSuccess)
	{
		if((scale[0] != pScale->value[0]) ||
			(scale[1] != pScale->value[1]) ||
			(scale[2] != pScale->value[2]))
		{
			pScale->value[0] = scale[0];
			pScale->value[1] = scale[1];
			pScale->value[2] = scale[2];

			MyTransformDirtyIterator iterator(*this);

			iterator.Iterate();
		}

	}
#endif

	return boolSuccess;
}
										  
bool ChQvTransformationRenderData::OnSetTranslation(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEventList)
{
	bool boolSuccess = false;
#if defined(CH_VRML_EVENTS)
	// Apply based on transform type - eventually this gets merged into
	// the containing separator in 2.0 - if we were going to keep this node, 
	// we'd split out the classes, but for now just hack it
	string strType;
	float translation[3];
	ChVec3fEvent *pEvent = (ChVec3fEvent *)pEventList;
	pEvent->GetValue(translation);
	QvSFVec3f *pTranslation = 0;

	if(m_pNode->GetType(strType) == typeQvTranslation)
	{
		QvTranslation *pNode = (QvTranslation *)m_pNode;
		pTranslation = &(pNode->translation);
		boolSuccess = true;
	}
	else if(m_pNode->GetType(strType) == typeQvTransform)
	{
		QvTransform *pNode = (QvTransform *)m_pNode;
		pTranslation = &(pNode->translation);
		boolSuccess = true;
	}

	if(boolSuccess)
	{
		if((translation[0] != pTranslation->value[0]) ||
			(translation[1] != pTranslation->value[1]) ||
			(translation[2] != pTranslation->value[2]))
		{
			pTranslation->value[0] = translation[0];
			pTranslation->value[1] = translation[1];
			pTranslation->value[2] = translation[2];

			MyTransformDirtyIterator iterator(*this);

			iterator.Iterate();
		}

	}
#endif

	return boolSuccess;
}
bool ChQvTransformationRenderData::OnSetScaleOrientation(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEventList)
{
	bool boolSuccess = false;
#if defined(CH_VRML_EVENTS)
	// Apply based on transform type - eventually this gets merged into
	// the containing separator in 2.0 - if we were going to keep this node, 
	// we'd split out the classes, but for now just hack it
	string strType;
	float axis[3];
	float angle;
	ChRotationEvent *pEvent = (ChRotationEvent *)pEventList;
	pEvent->GetValue(axis, angle);
	QvSFRotation *pRotation = 0;

	if(m_pNode->GetType(strType) == typeQvTransform)
	{
		QvTransform *pNode = (QvTransform *)m_pNode;
		pRotation = &(pNode->scaleOrientation);
		boolSuccess = true;
	}

	if(boolSuccess)
	{
		if((axis[0] != pRotation->axis[0]) ||
			(axis[1] != pRotation->axis[1]) ||
			(axis[2] != pRotation->axis[2]) ||
			(angle != pRotation->angle))
		{
			pRotation->axis[0] = axis[0];
			pRotation->axis[1] = axis[1];
			pRotation->axis[2] = axis[2];
			pRotation->angle = angle;
			//SetDirty();

			MyTransformDirtyIterator iterator(*this);

			iterator.Iterate();
		}

	}
#endif

	return boolSuccess;
}
bool ChQvTransformationRenderData::OnSetCenter(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEventList)
{
	bool boolSuccess = false;
#if defined(CH_VRML_EVENTS)
	// Apply based on transform type - eventually this gets merged into
	// the containing separator in 2.0 - if we were going to keep this node, 
	// we'd split out the classes, but for now just hack it
	string strType;
	float center[3];
	ChVec3fEvent *pEvent = (ChVec3fEvent *)pEventList;
	pEvent->GetValue(center);
	QvSFVec3f *pCenter = 0;

	if(m_pNode->GetType(strType) == typeQvTransform)
	{
		QvTransform *pNode = (QvTransform *)m_pNode;
		pCenter = &(pNode->scaleFactor);
		boolSuccess = true;
	}

	if(boolSuccess)
	{
		if((center[0] != pCenter->value[0]) ||
			(center[1] != pCenter->value[1]) ||
			(center[2] != pCenter->value[2]))
		{
			pCenter->value[0] = center[0];
			pCenter->value[1] = center[1];
			pCenter->value[2] = center[2];

			MyTransformDirtyIterator iterator(*this);

			iterator.Iterate();
		}

	}
#endif

	return boolSuccess;
}

/////////////////////////////////////////////////////////////////////////////////
ChQvGroupRenderData::ChQvGroupRenderData(QvNode* pNode) : 
	ChQvRenderBaseData(pNode)
{
#if defined(CH_VRML_EVENTS)
	if(!m_pDispatcher)
	{
		m_pDispatcher = new	ChVrmlDispatcher;
		Init();
	}
#endif
};


void ChQvGroupRenderData::Init()
{
	ChQvRenderBaseData::Init();
#if defined(CH_VRML_EVENTS)

	AddVrmlDispatcher("add_children", SFNode, OnAddChildren);
	AddVrmlDispatcher("add_children", MFNode, OnAddChildren);
	AddVrmlDispatcher("remove_children", SFNode, OnRemoveChildren);

#endif

};

ChQvGroupRenderData::~ChQvGroupRenderData()
{
}

void ChQvGroupRenderData::Term()
{
#if defined(CH_VRML_EVENTS)
	delete m_pDispatcher;
	m_pDispatcher = 0;
#endif
}

bool ChQvGroupRenderData::IsNodeRemovable(QvNode *pChild)
{
	return IsNodeAddable( pChild);
}

bool ChQvGroupRenderData::IsNodeAddable(QvNode *pChild)
{
	bool boolAddable = true;
	string strType;
	int theType = pChild->GetType(strType);
	switch(theType)
	{
		case typeQvBackground:
		case typeQvBaseColor:
		case typeQvEnvironment:
		case typeQvGroup:
		case typeQvCoordinate3:
		case typeQvInfo:
		case typeQvFontStyle:
		case typeQvMaterial:
		case typeQvMaterialBinding:
		case typeQvMatrixTransform:
		case typeQvNormal:
		case typeQvNormalBinding:
		case typeQvRotation:
		case typeQvScale:
		case typeQvShapeHints:
 		case typeQvTexture2:
		case typeQvTexture2Transform:
		case typeQvTextureCoordinate2:
		case typeQvTransform:
		case typeQvTranslation:
		case typeQvUnknownNode:
			boolAddable = false;
			break;


		case typeQvCone:
		case typeQvCube:
		case typeQvCylinder:
		case typeQvIndexedFaceSet:
		case typeQvIndexedLineSet:
		case typeQvLOD:	
		case typeQvSeparator:
		case typeQvTransformSeparator:
		case typeQvSwitch:			
		case typeQvAsciiText:
		case typeQvDirectionalLight:
		case typeQvOrthographicCamera:
		case typeQvPerspectiveCamera:
		case typeQvPointLight:
		case typeQvPointSet:	
		case typeQvSphere:	
		case typeQvSpin:
		case typeQvSpinGroup:
		case typeQvSpotLight:
		case typeQvWWWAnchor:		
		case typeQvWWWInline:
			break;
	
	}
	return boolAddable;
}

// VRML 2.0 Event Handlers

bool ChQvGroupRenderData::OnAddChildren(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEventList)
{
	bool boolSuccess = false;
#if defined(CH_VRML_EVENTS)
	// Append a child to the group node.
	ChNode*	pChild = 0;
	ChNodeEvent *pEvent = (ChNodeEvent *)pEventList;
	pEvent->GetValue(pChild);

	QvGroup *pNode = (QvGroup *)m_pNode;
	if(pChild)
	{
		if(IsNodeAddable((QvNode*)pChild))
		{
			boolSuccess = true;
		}
		else
		{
			// Not allowable - allow it to be thrown it away by not using it
			string strType;
			((QvNode*)pChild)->GetType(strType);
			TRACE1("Attempt to add_children node of type %s rejected.\n", LPCTSTR(strType) );
			// Now tell the user
			string strMsg;
			strMsg.Format("VRML: Event add_children for child node of type %s is not permitted.\n", LPCTSTR(strType) );
			((ChMazeWnd*)pRC->GetWnd())->OnError( CH_MAZE_ROUTE_ERROR_INVALID_ADD, strMsg, ChMazeWnd::traceError);
		}
	}

	if(boolSuccess)
	{
		((QvNode*)pChild)->Use();
		pNode->getChildren()->append((QvNode*)pChild);
		// Now launch a constructtion thread, just like this was
		// an inline
		Instantiate( (ChMazeWnd *)(pRC->GetWnd()), (QvNode*)pChild);

		// Spawn for new requests
		ChQvSpawnState state((ChMazeWnd *)(pRC->GetWnd()), ((ChMazeWnd *)(pRC->GetWnd()))->GetCurrentURL());
    	((QvNode*)pChild)->traverse(&state);

		// Set it dirty, for redraw, etc.
		pRC->SetDirty();

	}
#endif

	return boolSuccess;
}

class MyChildRemovalIterator: public 	  ChQvRenderBaseDataIterator
{
	public:
		MyChildRemovalIterator( const ChQvGroupRenderData& rbd, QvNode *pNode) : 
			ChQvRenderBaseDataIterator(rbd),
			m_pNode(pNode)
			 {};


		virtual int DoInstance(ChQvInstance& inst)
		{
			ChQvGroupInstance*pInst = (ChQvGroupInstance*)&inst;
			pInst->MarkChildForRemoval(m_pNode);

			return true;
		};


   protected:
		QvNode *m_pNode;
};

bool ChQvGroupRenderData::OnRemoveChildren(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEventList)
{
	bool boolSuccess = false;
#if defined(CH_VRML_EVENTS)
	// Delete a child or children from the group node.
	ChNode*	pChild = 0;
	ChNodeEvent *pEvent = (ChNodeEvent *)pEventList;
	QvGroup *pNode = (QvGroup *)m_pNode;

	int iNumToRemove = pEvent->GetCount();

	//pRC->LockScene();	   // Lock scene so we don't conflict with construction
	for(int j = 0; j < iNumToRemove; j++)
	{
		pEvent->GetValue(j, pChild);

		if(pChild)			
		{	
			if(IsNodeRemovable((QvNode*)pChild))
			{
				boolSuccess = true;
				bool boolRemoved = false;
				for ( int i = pNode->getNumChildren() - 1; i >= 0; i--)
				{
					if(	pNode->getChild(i) == (QvNode*)pChild)
					{
						pRC->LockQv();		   // Lock tree so parse and stream threads don't barf
						MyChildRemovalIterator iterator(*this, (QvNode*)pChild);
						iterator.Iterate();
						pNode->getChildren()->remove(i);

						((QvNode*)pChild)->Release(); // This is where the subtree is deleted
						pRC->UnlockQv();
						boolRemoved = true;
					}
				}
				if(!boolRemoved)
				{
					string strMsg;
					string strParent(pNode->getName().getString());
					string strChild(((QvNode*)pChild)->getName().getString());
					if(strParent.IsEmpty()) strParent = "<Unnamed>";
					if(strChild.IsEmpty()) strChild = "<Unnamed>";
					strMsg.Format("VRML: Event remove_children - node %s not a child of %s.\n", 
						LPCTSTR(strChild), LPCTSTR(strParent));
					((ChMazeWnd*)pRC->GetWnd())->OnError( CH_MAZE_ROUTE_ERROR_NODE_NOTFOUND, strMsg, ChMazeWnd::traceError);
				}
			}
			else
			{
				string strType;
				((QvNode*)pChild)->GetType(strType);
				TRACE1("Attempt to remove_children node of type %s rejected.\n", LPCTSTR(strType) );
				// Now tell the user
				string strMsg;
				strMsg.Format("VRML: Event remove_children for child node of type %s is not permitted.\n", LPCTSTR(strType) );
				((ChMazeWnd*)pRC->GetWnd())->OnError( CH_MAZE_ROUTE_ERROR_INVALID_REMOVE, strMsg, ChMazeWnd::traceError);
			}

		}
	}
	//pRC->UnlockScene();

#endif

	return boolSuccess;
}


// End handlers

ChQvGroupRenderData* ChQvGroupRenderData::Instantiate(ChMazeWnd * pWnd, QvNode *pNewChild)
{
	// Walk the list of the group's instances, instantiating the new subtree that came in
	if (!m_instances.IsEmpty())
	{
		ChPosition pos = m_instances.GetHeadPosition();
		while(pos)
		{
			ChQvGroupInstance *pInst = (ChQvGroupInstance *)(m_instances.GetNext(pos));
			ChQvBuildState bldIt(pWnd);
			bldIt.SetCurrentParent(pInst);
			pInst->SetupTraversalState(bldIt);
			pNewChild->traverse(&bldIt);

			// Now construct them for RLab 
			#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
			pWnd->GetRenderContext()->StartConstruction(pInst);
			#endif
		}
	}
	return this;
}

// //////////////////////////////////////////
ChQvIFSRenderData::ChQvIFSRenderData(QvIndexedFaceSet* ifs, QvState* state)
	 : ChQvRenderBaseData(ifs), m_pNormals(0)
{
	CheckValid(ifs, state);
	if(m_boolValid) m_pNormals = new ChQvIndexedFaceSetNormals(ifs, state);
	SetDirty(false);
}

ChQvIFSRenderData::~ChQvIFSRenderData()
{ 
	delete m_pNormals; 
}

void ChQvIFSRenderData::Init(QvIndexedFaceSet* ifs, QvState* state)
{
	CheckValid(ifs, state);
	delete m_pNormals;
	m_pNormals = 0;
	if(m_boolValid) m_pNormals = new ChQvIndexedFaceSetNormals(ifs, state);
	SetDirty(false);
}

inline int VertCount(long *values, int num)
{
	int i = 0;
	while(values[i] != QV_END_FACE_INDEX) i++;
	return i;
}

bool ChQvIFSRenderData::CheckValid(QvIndexedFaceSet* ifs, QvState* state)
{
							/* Validate the coordinate indices of an ifs. Check for
							all faces have 3 or more vertices, and all vertices are legal in
							the context of the current coordinate node. Someday we should put
							out insulting messages when this fails, but that's for later. */
	if(!state->getTopElement(QvState::Coordinate3Index))
	{							 // no coordinates!
		m_boolValid = false;
		return false;
	}
	QvCoordinate3 *pC3 = (QvCoordinate3*)(state->getTopElement(QvState::Coordinate3Index)->data);
	

	m_boolValid = true;
	if(ifs->coordIndex.num < 4) 
	{
		m_boolValid = false;
		return false;
	}
	int vertCount = 0;
	int faceCount = 0;
	
	for(int j = 0; j< ifs->coordIndex.num; j++)	   //coordIndex.values[j] != QV_END_FACE_INDEX
	{
		if( ifs->coordIndex.values[j] <	QV_END_FACE_INDEX)
		{
			m_boolValid = false;		// fail for illegal coord, gotta be -1 or non-neg
			break;
		}
		if( ifs->coordIndex.values[j] >= pC3->point.num)
		{
			m_boolValid = false;		// fail for illegal coord; out of range
			break;
		}
		if( ifs->coordIndex.values[j] !=	QV_END_FACE_INDEX) vertCount ++;
		else
		{
			if(vertCount < 3)
			{
				m_boolValid = false;		// fail for face with too few points
				break;
			}
			else
			{
				vertCount = 0;	// new face
				faceCount++;
			}
		}
	}
	if(vertCount > 2)
	{
		faceCount ++; // accept a trailing unterminated face if it has enough points
		vertCount = 0;
	}

									// fail for trailing trash or no faces
	if(vertCount != 0 || faceCount == 0) m_boolValid = false;
	return m_boolValid;
}


// Texture render data

ChQvTextureRenderData::ChQvTextureRenderData(QvNode* pTxt) :
	ChQvRenderBaseData(pTxt),	
	m_texture(0), 
	#if defined(CH_USE_3DR)
	m_hRC(0), 
	#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	m_pImage(0)
	#endif	
{ }

ChQvTextureRenderData::~ChQvTextureRenderData()
{
	#if defined(CH_USE_3DR)
    if (m_texture && m_hRC ) R3dFreeTexture( m_hRC, (Dword_t)m_texture);
	#else
//	delete m_pImage;
	if ( m_pImage )
	{
		m_pImage->Release();
	}
	m_pImage = 0;
	// Textures themselves are usage counted, and we don't have to free them
	#endif
	m_texture = 0;
}

int ChQvTextureRenderData::GetURL(QvState *qvstate)
{
	// return true if this is a spawn request, else false
	if( ((ChQvState*)qvstate)->GetType() != ChQvState::spawnRequests)
	{
		return false;
	}

	QvTexture2 *pNode = (QvTexture2 *)GetNode();
	// Spawn a new http request and add it to the info's list of requests
	if(m_strURL.IsEmpty())
	{
		ChQvSpawnState *state = (ChQvSpawnState *)qvstate;
		m_strURL = pNode->filename.value.getString();

		// check if we need to fetch a texture from a WWW site
		if(!m_strURL.IsEmpty())	
		{

			ChMazeTextureHTTPReq *pHTTPReq = new ChMazeTextureHTTPReq ( 
									state->GetView(), m_strURL, GetNode() );
			pHTTPReq->SetPage(state->GetView()->GetCurrentPage());

		   	string defURL = state->GetDefaultURL();
			state->GetView()->GetURL( m_strURL, (chparam)pHTTPReq, LPCTSTR(defURL) );
		}
		else if ( pNode->image.size[0] && 
				  pNode->image.size[1] &&
				  pNode->image.numComponents  )
		{ // We have a field that contains an uncompressed 2-dimensional color or greyscale image
		  // convert the image to a ChSFImage and load the texture 
		  	ChRenderContext *pRenderContext = state->GetView()->GetRenderContext();

			if ( pRenderContext )
			{ // We have a valid render context, load the texture
		   		ChSFImage *pSFImage = new ChSFImage();
				ASSERT( pSFImage );

				if ( pSFImage->Create( pNode->image.size[0], 
				  				  pNode->image.size[1],
				  				  pNode->image.numComponents,
				  				  pNode->image.bytes ) )
				{  // Transparent pixel information is ignored in the current
				   // implementation
					LoadTexture( pRenderContext, pSFImage->GetDibImage(), 
								  0, ChMazeTextureHTTPReq::textureAutoSize );
					#if 0
					SetTextureHandle( pRenderContext->LoadDIBTexture( pSFImage, 
										 				  0, 
										 				  ChMazeTextureHTTPReq::textureShrink ));
					#endif
				}
				delete pSFImage;
			}

		}

	}
	return true;
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
// Iterator to propagate texture load info
class MyTextureDataIterator: public ChQvRenderBaseDataIterator
{
	public:
		MyTextureDataIterator( const ChQvTextureRenderData& rbd ) : ChQvRenderBaseDataIterator(rbd) {};


		virtual int DoInstance(ChQvInstance& inst)
		{
			inst.SetTexture((ChQvTextureRenderData*)m_pData);
			return true;
		};


   protected:

   private:
											/* Disable copy constructor and
												assignment operator */

      inline MyTextureDataIterator( const MyTextureDataIterator& ) {}
      inline MyTextureDataIterator& operator=( const MyTextureDataIterator& )
      			{
      				return *this;
      			}
};

#endif

ChQvTextureRenderData* ChQvTextureRenderData::LoadTexture(ChRenderContext *pContext, ChDib *pDibIn, chuint32 luChromaClr, chuint uOption)
{
#if defined(CH_USE_3DR)
	SetTextureHandle( pContext->LoadDIBTexture( pDibIn, luChromaClr, uOption ));
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	if(m_texture) return this;		// Something already there, do nothing for now
	bool boolLimit = false;			// Should we allow reduction for RLAB??

	m_pImage = new ChRLImage(pDibIn, boolLimit, uOption, luChromaClr);

	pContext->LockScene();

	m_texture = pContext->CreateTexture(pRLImage(*m_pImage));

	// Now propagate to all dependents 
	MyTextureDataIterator iterator(*this);
	iterator.IterateDependents();

	pContext->UnlockScene();

		  
#endif
	return this;
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
void NrTextureDestroyCallback(ChNrObject obj, void * arg)
{
}
#endif

#if defined(CH_USE_3DR)
ChQvTextureRenderData* ChQvTextureRenderData::LoadTexture( ChRenderContext *pContext, ChTextureHandle texHandle )
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
ChQvTextureRenderData* ChQvTextureRenderData::LoadTexture( ChRenderContext *pContext, ChRLImage* pRLImg )
#endif
{

#if defined(CH_USE_3DR)

	SetTextureHandle( texHandle );

#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

	if(m_texture) 
	{
		// Delete the old texture we have
		//delete pRLImg;
		pRLImg->Release();
		return this;	  // Something already there, do nothing for now
	}		
	// Need to ask Jim why we are saving RLImage.
	m_pImage = pRLImg;

	pContext->LockScene();
	m_texture = pContext->CreateTexture(pRLImage(*m_pImage));
	// Add callback - Just for debugging for now
	ChNrObjectAddDestroyCallback(m_texture, NrTextureDestroyCallback, this);

	// Now propagate to all dependents 
	MyTextureDataIterator iterator(*this);
	iterator.IterateDependents();
	pContext->UnlockScene();
		  
#endif
	return this;
}

// Return whether it will -never- have a texture
bool ChQvTextureRenderData::IsEmpty()
{
	bool boolEmpty = true;
	QvTexture2 *pNode = (QvTexture2 *)GetNode();
	string strURL = string(pNode->filename.value.getString());
	if(!strURL.IsEmpty()) boolEmpty = false;
	if ( pNode->image.size[0] && 
				  pNode->image.size[0] &&
				  pNode->image.numComponents  ) boolEmpty = false;
	return boolEmpty;
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) || defined(CH_USE_D3D)
bool ChQvTextureRenderData::IsChromaKey() 
{ 
	return m_pImage ? m_pImage->IsChromaKey() : false; 
};

ChColor ChQvTextureRenderData::GetChromaKey() 
{ 
	return m_pImage ? m_pImage->GetChromaKey() : ChColor(0); 
};

#endif		
/////////////////////////////////////////////////////////////////////////
ChQvTexture2TransformRenderData::ChQvTexture2TransformRenderData(QvNode* pNode) : ChQvRenderBaseData(pNode)
{
	SetDirty();
};

ChQvTexture2TransformRenderData *ChQvTexture2TransformRenderData::Transform(float &s, float& t)
{
	if(m_boolDefault) return this;

	QvTexture2Transform * pNode = (QvTexture2Transform*)m_pNode;
	// Far from optimal - need to cache 3x3 homo matrix for better results
	float tmp;
	s -= pNode->center.value[0];
	t -= pNode->center.value[1];

	s *= pNode->scaleFactor.value[0];
	t *= pNode->scaleFactor.value[1];


	tmp = m_cosa * s - m_sina * t;
	t = m_sina * s + m_cosa * t;
	s = tmp;

	s += pNode->center.value[0];
	t += pNode->center.value[1];

	s += pNode->translation.value[0];
	t += pNode->translation.value[1];
	
	return this;
}

ChQvTexture2TransformRenderData *ChQvTexture2TransformRenderData::CheckForDefault()
{
	QvTexture2Transform * pNode = (QvTexture2Transform*)m_pNode;
	m_boolDefault = true;

	if(pNode->scaleFactor.value[0] != 0.0 || pNode->scaleFactor.value[1] != 0.0)
		m_boolDefault = false;
	if(pNode->rotation.value != 0.0)
		m_boolDefault = false;
	if(pNode->translation.value[0] != 0.0 || pNode->translation.value[1] != 0.0)
		m_boolDefault = false;

	return this;
}

void ChQvTexture2TransformRenderData::SetDirty(bool boolDirty )
{
	if(boolDirty)
	{
		QvTexture2Transform * pNode = (QvTexture2Transform*)m_pNode;
		m_cosa = cos(pNode->rotation.value);
		m_sina = sin(pNode->rotation.value);
		CheckForDefault();
	}
	return;
}; 

// WWWInline
ChQvWWWInlineRenderData::~ChQvWWWInlineRenderData()
{
	if(m_pParseInfo)
	{
		m_pParseInfo->Abort();
		m_pParseInfo->SetUserData(0);
		m_pParseInfo = 0;
	}
	if(GetReq())
	{
		GetReq()->Cancel();
		GetReq()->SetInlineNode(0);
		SetReq(0);
	}
}
ChQvWWWInlineRenderData* ChQvWWWInlineRenderData::Instantiate(ChMazeWnd * pWnd, QvNode *pNewChild)
{
	// Walk the list of WWWInline instances, instantiating the new subtree that came in
	if (!m_instances.IsEmpty())
	{
		ChPosition pos = m_instances.GetHeadPosition();
		while(pos)
		{
			ChQvWWWInlineInstance *pInst = (ChQvWWWInlineInstance *)(m_instances.GetNext(pos));
			ChQvBuildState bldIt(pWnd);
			bldIt.SetCurrentParent(pInst);
			pInst->SetupTraversalState(bldIt);
			pNewChild->traverse(&bldIt);

			// Now construct them for RLab 
			#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
			pWnd->GetRenderContext()->StartConstruction(pInst);
			#endif
		}
	}
	return this;
}

/////////////////////////////////////////////////////////////////////////////////
ChQvSwitchRenderData::ChQvSwitchRenderData(QvNode* pNode) : 
	ChQvGroupRenderData(pNode)
{
#if defined(CH_VRML_EVENTS)
	if(!m_pDispatcher)
	{
		m_pDispatcher = new	ChVrmlDispatcher;
		Init();
	}
#endif
};


void ChQvSwitchRenderData::Init()
{
	//ChQvGroupRenderData::Init();
	#if defined(CH_VRML_EVENTS)
	AddVrmlDispatcher("set_whichChild", SFLong, OnSetWhichChild);
	#endif
};

ChQvSwitchRenderData::~ChQvSwitchRenderData()
{
}

void ChQvSwitchRenderData::Term()
{
#if defined(CH_VRML_EVENTS)
	delete m_pDispatcher;
	m_pDispatcher = 0;
#endif
}

bool ChQvSwitchRenderData::OnSetWhichChild(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEventList)
{
	bool boolSuccess = true;
#if defined(CH_VRML_EVENTS)
	long lChild;
	ChLongEvent *pEvent = (ChLongEvent *)pEventList;
	pEvent->GetValue(lChild);

	QvSwitch *pNode = (QvSwitch *)m_pNode;
	pNode->whichChild.value = lChild;

	// Now the hard part; 
	// If this is the cameras node, the camera is on our list, so select it there
	// Otherwise, if this child contains a camera somewhere, select it. Do not add it
	// to the list.

	if(lChild >= 0 && lChild < pNode->getNumChildren())
	{
		if(pNode->getName() == "Cameras")
		{
			pRC->SelectCamera(int (lChild));
		}
		else
		{
			// Search for a camera. If found, set it.
			QvNode *pChild = pNode->getChild(int(lChild));
		}
	}
#endif

	return boolSuccess;
}

// Background ala 2.0 render data

ChQvBackgroundData::ChQvBackgroundData() :	
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	m_pImage(0)
	#endif	
{
	for(int j=0; j<6; j++)
	{
		m_panTextures[j] = 0;
	} 
}

ChQvBackgroundData::~ChQvBackgroundData()
{
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	//delete m_pImage;
	if ( m_pImage )
	{
		m_pImage->Release();
	}
	m_pImage = 0;
	// Textures themselves are usage counted, and we don't have to free them ????
	#endif
	for(int j=0; j<6; j++)
	{
		m_panTextures[j] = 0;
	} 
}

int ChQvBackgroundData::GetURL(QvState *qvstate)
{
	// return true if this is a spawn request, else false
	if( ((ChQvState*)qvstate)->GetType() != ChQvState::spawnRequests)
	{
		return false;
	}

	// Spawn a new http request and add it to the info's list of requests
	if(m_strURL.IsEmpty())
	{
		ChQvSpawnState *state = (ChQvSpawnState *)qvstate;
		QvBackground *pNode = (QvBackground *)GetNode();
		m_strURL = string(pNode->panorama.values[0].getString());

		// check if we need to fetch a texture from a WWW site
		if(!m_strURL.IsEmpty())	
		{

			#if NOT_YET
			ChMazeTextureHTTPReq *pHTTPReq = new ChMazeTextureHTTPReq ( 
									state->GetView(), m_strURL, m_pTexture2 );
			pHTTPReq->SetPage(state->GetView()->GetCurrentPage());

		   	string defURL = state->GetDefaultURL();
			state->GetView()->GetURL( m_strURL, (chparam)pHTTPReq, LPCTSTR(defURL) );
			#endif
		}

	}
	return true;
}


ChQvBackgroundData* ChQvBackgroundData::LoadTexture(ChRenderContext *pContext, ChDib *pDibIn, chuint32 luChromaClr, chuint uOption)
{
#if defined(CH_USE_3DR)
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	#if NOT_YET

	if(m_texture) return this;		// Something already there, do nothing for now
	bool boolLimit = false;			// Should we allow reduction for RLAB??

	m_pImage = new ChRLImage(pDibIn, boolLimit, uOption, luChromaClr);

	pContext->LockScene();

	m_texture = RLCreateTexture(pRLImage(*m_pImage));

	// Now propagate to all dependents 
	MyTextureDataIterator iterator(*this);
	iterator.IterateDependents();

	pContext->UnlockScene();
			#endif

		  
#endif
	return this;
}

#if defined(CH_USE_3DR)
ChQvBackgroundData* ChQvBackgroundData::LoadTexture( ChRenderContext *pContext, ChTextureHandle texHandle )
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
ChQvBackgroundData* ChQvBackgroundData::LoadTexture( ChRenderContext *pContext, ChRLImage* pRLImg )
#endif
{

	#if NOT_YET
#if defined(CH_USE_3DR)

	SetTextureHandle( texHandle );

#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

	if(m_texture) 
	{
		// Delete the old texture we have
		delete pRLImg;
		return this;	  // Something already there, do nothing for now
	}		
	// We are saving RLImage because RL makes us keep it around.
	m_pImage = pRLImg;

	pContext->LockScene();
	m_texture = RLCreateTexture(pRLImage(*m_pImage));

	// Now propagate to all dependents 
	MyTextureDataIterator iterator(*this);
	iterator.IterateDependents();
	pContext->UnlockScene();
#endif
		  
#endif
	return this;
}

// Return whether it will -never- have a texture
bool ChQvBackgroundData::IsEmpty()
{
	bool boolEmpty = true;
	QvBackground *pNode = (QvBackground *)GetNode();
	string strURL = string(pNode->panorama.values[0].getString());
	if(!strURL.IsEmpty()) boolEmpty = false;
	return boolEmpty;
}

// ChQvBackgroundInfoData
		
ChQvBackgroundInfoData::ChQvBackgroundInfoData(QvNode *pNode) :	 ChQvTextureRenderData(pNode),
	m_height(0),
	m_width(0), 
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	m_pTiledImage(0),
	m_backgroundFrame(0),
	#endif
	m_boolDirty(false)
{ }

void BackgroundTextureDestroyCallback(ChNrObject obj, void * arg)
{
	((ChQvBackgroundInfoData*)arg)->OnDestroyTexture();
}

ChQvBackgroundInfoData::~ChQvBackgroundInfoData()
{
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	if(GetTextureHandle())
	{
		ChNrObjectRemoveDestroyCallback(GetTextureHandle(), BackgroundTextureDestroyCallback, this);
	}
	//delete m_pTiledImage;
	if ( m_pTiledImage )
	{
		m_pTiledImage->Release();
	}
	m_pTiledImage = 0;
	m_backgroundFrame = 0;
	#endif
}

int ChQvBackgroundInfoData::GetURL(QvState *qvstate)
{
	// return true if this is a spawn request, else false
	if( ((ChQvState*)qvstate)->GetType() != ChQvState::spawnRequests)
	{
		return false;
	}

	// Spawn a new http request and add it to the info's list of requests
	if(m_strURL.IsEmpty())
	{
		ChQvSpawnState *state = (ChQvSpawnState *)qvstate;
		QvInfo *pNode = (QvInfo *)GetNode();
		string strURL = string(pNode->string.value.getString());
		m_strURL = pNode->string.value.getString();

		// check if we need to fetch a texture from a WWW site
		if(!m_strURL.IsEmpty())	
		{
			// TODO: Ask that the texture not be changed in size TODO!!!!!!!!!
			ChMazeTextureHTTPReq *pHTTPReq = new ChMazeTextureHTTPReq ( 
									state->GetView(), m_strURL, pNode , ChMazeTextureHTTPReq::textureKeepSize );
			pHTTPReq->SetPage(state->GetView()->GetCurrentPage());

		   	string defURL = state->GetDefaultURL();
			state->GetView()->GetURL( m_strURL, (chparam)pHTTPReq, LPCTSTR(defURL) );
		}

	}
	return true;
}


ChQvTextureRenderData* ChQvBackgroundInfoData::LoadTexture(ChRenderContext *pContext, ChDib *pDibIn, chuint32 luChromaClr, chuint uOption)
{
#if defined(CH_USE_3DR)
	SetTextureHandle( pContext->LoadDIBTexture( pDibIn, luChromaClr, uOption ));
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	if(m_texture) return this;		// Something already there, do nothing for now
	bool boolLimit = false;			// Don't allow reduction for RLAB

	m_pImage = new ChRLImage(pDibIn, boolLimit, uOption | ChMazeTextureHTTPReq::textureKeepSize, luChromaClr);

	pContext->LockScene();

	//m_texture = RLCreateTexture(pRLImage(*m_pImage));


	pContext->UnlockScene();

		  
#endif
	return this;
}

#if defined(CH_USE_3DR)
ChQvTextureRenderData* ChQvBackgroundInfoData::LoadTexture( ChRenderContext *pContext, ChTextureHandle texHandle )
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
ChQvTextureRenderData* ChQvBackgroundInfoData::LoadTexture( ChRenderContext *pContext, ChRLImage* pRLImg )
#endif
{

#if defined(CH_USE_3DR)

	SetTextureHandle( texHandle );

#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

	if(m_texture) 
	{
		// Delete the old texture we have
		//delete pRLImg;
		pRLImg->Release();
		return this;	  // Something already there, do nothing for now
	}		
	// Save RLImage - we'll need it to rebuild the texture if size changes.
	m_pImage = pRLImg;

	pContext->LockScene();

	// Tile the image onto a sufficiently large texture
	CreateTexture(pContext);
	if(GetTextureHandle())
	{
		// Now propagate to the scene background frame
		m_backgroundFrame = pContext->SetBackgroundImage(this);


		// Now set up the background frame visual
		InitDecal(pContext);
	}
	pContext->UnlockScene();
		  
#endif
	return this;
}

// Return whether it will -never- have a texture
bool ChQvBackgroundInfoData::IsEmpty()
{
	bool boolEmpty = true;
	QvBackground *pNode = (QvBackground *)GetNode();
	string strURL = string(pNode->panorama.values[0].getString());
	if(!strURL.IsEmpty()) boolEmpty = false;
	return boolEmpty;
}		

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

int ChQvBackgroundInfoData::ComputeTiledWidth(ChRenderContext *pContext)
{
	int devWidth = ChNrDeviceGetWidth(pContext->GetRC());
	int imWidth = pRLImage(*m_pImage)->width;
	int width = 1;
	//while(width < devWidth + imWidth) width *= 2;
	width = max(4, devWidth + imWidth);
	width = ((width - 1) / 4 + 1) * 4;	
	return width;
}

int ChQvBackgroundInfoData::ComputeTiledHeight(ChRenderContext *pContext)
{
	int devHeight = ChNrDeviceGetHeight(pContext->GetRC());
	int imHeight = pRLImage(*m_pImage)->height;
	int height = 1;
	//while(height < devHeight + imHeight) height *= 2;
	height = max(4, devHeight + imHeight);
	height = ((height - 1) / 4 + 1) * 4; // make sure it's 4n pixels wide, guaranteeing 32bit alignment	
	return height;
}

bool ChQvBackgroundInfoData::CreateTexture(ChRenderContext *pContext)
{
	m_width = ComputeTiledWidth(pContext);
	m_height = ComputeTiledHeight(pContext);
	m_width += 8;	// slop factor to prevent too many resizings
	m_height += 8;	// slop factor to prevent too many resizings
	#if (defined(CH_USE_D3D))
	m_width = pRLImage(*m_pImage)->width;
	m_height = pRLImage(*m_pImage)->height;
	m_pTiledImage = 0;
	#else
	m_pTiledImage = new ChRLImage(*m_pImage, m_width, m_height);
	m_texture = pContext->CreateTexture(pRLImage(*m_pTiledImage));
	ChNrObjectAddDestroyCallback(m_texture, BackgroundTextureDestroyCallback, this);
	ChNrTextureSetColors(m_texture, 128);
	ChNrTextureSetShades(m_texture, 1);
	#endif
	return true;
}

void ChQvBackgroundInfoData::OnDestroyTexture()
{
	//delete m_pTiledImage;
	if ( m_pTiledImage )
	{
		m_pTiledImage->Release();
	}
	m_pTiledImage = 0;
	m_texture = 0;
}

void ChQvBackgroundInfoData::Move( ChRenderContext *pContext)
{
	if(m_boolDirty) Resize(pContext);
	QvNode *pCamera = pContext->GetCurrentCamera();
	ChQvPCameraRenderData *pData = 0;
	if(GetTextureHandle() && pCamera)
	{
		pData = (ChQvPCameraRenderData*)(pCamera->GetRenderData());
		GxTransform3Wf	camLook;
		pData->GetOrientationTransform(camLook);
		GxVec3f newCenter = camLook * m_backCenter;
		float extent = max(ChNrDeviceGetWidth(pContext->GetRC()), ChNrDeviceGetHeight(pContext->GetRC()));
		newCenter.x() *= extent / 2;
		newCenter.x() += extent / 2;
		newCenter.y() *= -extent / 2;
		newCenter.y() += extent / 2;

		ChTextureHandle tex = GetTextureHandle();
		Justify(newCenter, pContext);
		ChNrTextureSetDecalOrigin(tex, newCenter.x(),	 newCenter.y());
	}
}
void ChQvBackgroundInfoData::OnResize( ChRenderContext *pContext )
{
	m_boolDirty = true;	
}

void ChQvBackgroundInfoData::Resize( ChRenderContext *pContext)
{
	int height = ComputeTiledHeight(pContext);
	int width = ComputeTiledWidth(pContext);
	ChTextureHandle tex = GetTextureHandle();
	if(m_texture || m_pTiledImage)
	{
		// 16 is a slop factor to prevent excessive resizing computations
		if(m_height < height || m_width < width || m_height - 16 > height || m_width - 16 > width )
		{
			if(tex) ChNrFrameRemoveVisual(m_backgroundFrame, tex);
			//delete m_pTiledImage;
			if ( m_pTiledImage )
			{
				m_pTiledImage->Release();
			}
			m_pTiledImage = 0;
			m_texture = 0;
		}
		else
		{
			m_boolDirty = false;	
			return;		// texture is ok as is
		}
	}

	CreateTexture(pContext);
	if(GetTextureHandle())
	{
		ChNrFrameAddVisual(m_backgroundFrame, GetTextureHandle());
		InitDecal(pContext);
	}
	m_boolDirty = false;	
}

void ChQvBackgroundInfoData::InitDecal( ChRenderContext *pContext)
{
	ChTextureHandle tex = GetTextureHandle();
	ChNrTextureSetDecalScale(tex, false);

	//RLTextureSetDecalDepth(tex, RLDecalFront);
	ChNrTextureSetDecalOrigin(tex, ChNrDeviceGetWidth(pContext->GetRC()) / 2, ChNrDeviceGetHeight(pContext->GetRC()) / 2);

	QvNode *pCamera = pContext->GetCurrentCamera();
	ChQvPCameraRenderData *pCamData = 0;
	if(pCamera)
	{
		pCamData = (ChQvPCameraRenderData*)(pCamera->GetRenderData());
		GxTransform3Wf	camLook;
		pCamData->GetOrientationTransform(camLook);
		camLook.Invert();
		m_backCenter = camLook * GxVec3f(0, 0, 1.);
		//m_backCenter = camLook * GxVec3f(ChNrDeviceGetWidth(GetRC()) / 2,	 ChNrDeviceGetHeight(GetRC())	/ 2, 1.);
		//float w;
		//m_backCenter = camLook.TransformW(GxVec3f(ChNrDeviceGetWidth(GetRC()) / 2, ChNrDeviceGetHeight(GetRC())	/ 2, 1.), w);
	}

}

void ChQvBackgroundInfoData::Justify(GxVec3f &pt, ChRenderContext *pContext)
{
	int devWidth = ChNrDeviceGetWidth(pContext->GetRC());
	int devHeight = ChNrDeviceGetHeight(pContext->GetRC());
	int imWidth = pRLImage(*m_pImage)->width;
	int imHeight = pRLImage(*m_pImage)->height;
	int imBackWidth = pRLImage(*m_pTiledImage)->width;
	int imBackHeight = pRLImage(*m_pTiledImage)->height;

	while(pt.x() < devWidth / 2) pt.x() += imWidth;
	while(pt.y() < devHeight / 2) pt.y() += imHeight;
	while(pt.x() >= imBackWidth - devWidth / 2) pt.x() -= imWidth;
	while(pt.y() >= imBackHeight - devHeight / 2) pt.y() -= imHeight;
}

#endif

/////////////////////////////////////////////////////////////////////////////////
ChQvSpinGroupRenderData::ChQvSpinGroupRenderData(QvNode* pNode) : 
	ChQvGroupRenderData(pNode), m_step(0)
{
#if defined(CH_VRML_EVENTS)
	if(!m_pDispatcher)
	{
		m_pDispatcher = new	ChVrmlDispatcher;
		Init();
	}
#endif
};


void ChQvSpinGroupRenderData::Init()
{
	ChQvGroupRenderData::Init();
	#if defined(CH_VRML_EVENTS)
	AddVrmlDispatcher("set_rotation", SFRotation, OnSetRotation);
	#endif
};

ChQvSpinGroupRenderData::~ChQvSpinGroupRenderData()
{
}

void ChQvSpinGroupRenderData::Term()
{
#if defined(CH_VRML_EVENTS)
	delete m_pDispatcher;
	m_pDispatcher = 0;
#endif
}

bool ChQvSpinGroupRenderData::OnSetRotation(ChRenderContext *pRC, ChApplet * pApplet, ChIVrmlEvent *pEventList)
{
	bool boolSuccess = true;
#if defined(CH_VRML_EVENTS)
	// Change the rotation value, and dirty the context so it takes effect
	float axis[3];
	float angle;
	ChRotationEvent *pEvent = (ChRotationEvent *)pEventList;
	pEvent->GetValue(axis, angle);
	QvSFRotation *pRotation = 0;
 	QvSpinGroup *pNode = (QvSpinGroup *)m_pNode;
	pRotation = &(pNode->rotation);

	pRotation->axis[0] = axis[0];
	pRotation->axis[1] = axis[1];
	pRotation->axis[2] = axis[2];
	pRotation->angle = angle;

	pRC->SetDirty();
#endif

	return boolSuccess;
}

void ChQvSpinGroupRenderData::Spin(ChQvSpinGroupInstance *pTarget)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	if(!pTarget->GetContext()->IsAnimating()) return;

	QvSpinGroup *pSpin = (QvSpinGroup*)GetNode();
	const float almostZero = 1.e-14;
	if(pSpin->rotation.angle > -almostZero && pSpin->rotation.angle < almostZero) return;


	GxTransform3Wf instTransform = pTarget->GetTransform();

	float newStep =  pTarget->GetContext()->GetFrameCount();
	double step = newStep - m_step;	// Based on frame count, interpreting the angle as "per frame increment"
	m_step  = newStep;

	// Integrate the incremental spin by applying this rotation to the current spinTransform

	if(step)
	{
		// Integrate the incremental spin by applying this rotation to the current spinTransform
		double twopi = atan(1.0) * 8.;	// good to about 17 places

		float angle = float(fmod(double(pSpin->rotation.angle) * step, twopi));
		GxVec3f axis(pSpin->rotation.axis[0], pSpin->rotation.axis[1], pSpin->rotation.axis[2]);
		m_spinTransform *= GxTransform3Wf(axis,  angle);
	}


	ChNrFrame frame = pTarget->GetFrame();

	if(frame)
	{
		if(pSpin->local.value == FALSE)
		{
			pTarget->GetTransformInstance()->SetSelfTransform(instTransform * m_spinTransform * instTransform.Inverse());
		}
		else
		{
			pTarget->GetTransformInstance()->SetSelfTransform(m_spinTransform);
		}
		pTarget->GetTransformInstance()->SetTransformDirty();
	}
	pTarget->GetContext()->SetDirty();	// force another frame
#endif

}

ChQvTimeSensorRenderData::~ChQvTimeSensorRenderData()
{
	if(m_pRC)
	{
		m_pRC->Remove(this);
	}
}

bool ChQvTimeSensorRenderData::OnTick(double t)
{
	((QvTimeSensor*)(GetNode()))->Tick(t);
	return true;
}

bool ChQvTimeSensorRenderData::Install(ChRenderContext *pRC)
{
	if(m_pRC == pRC) return true;	// already there
	if(m_pRC)
	{
		m_pRC->Remove(this);
	}
	m_pRC = pRC;
	if(pRC)
	{
		pRC->Add(this);
	}
	return true;
}

// end of file

