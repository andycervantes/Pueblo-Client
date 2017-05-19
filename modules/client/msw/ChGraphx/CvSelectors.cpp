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

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvSelectors.cpp,v 2.6 1996/06/27 03:44:08 jimd Exp $

#include "grheader.h"

#include "CvInstnc.h"
#include <QvInfo.h>
#include <QvState.h>
#include "ChMaze.h"
#include "ChRenderData.h"
#include "ChMazDep.h"
#include "CvTrnsfm.h"
#include "CvNormal.h"
#include "CvBound.h"
#include "CvConvrt.h"
#include "CvHitTst.h"


//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////


ChQvLODInstance::ChQvLODInstance() : ChQvGroupInstance()
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
				, m_pFrames(0)
				, m_iCurrentChild(-1)
#endif
{
}

ChQvLODInstance::~ChQvLODInstance()
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	delete [] m_pFrames;
	m_pFrames = 0;
	if(!m_children.IsEmpty())
	{
		ChPosition pos = m_children.GetHeadPosition();
		while(pos)
		{
			ChQvInstance *pChild = m_children.GetNext(pos);
			ChNrFrame frame = pChild->GetFrame();
			if (frame) ChNrObjectDestroy(frame);
		}
	}
#endif
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
// Callback to choose child while rendering
#if (defined(CH_USE_RLAB))
void LODFrameCallback(ChNrFrame frame, void * arg)
#else
void LODFrameCallback(ChNrFrame frame, void * arg, float delta)
#endif
{
	ChQvLODInstance *pInst = (ChQvLODInstance *)arg;
	pInst->PickAChild();
}

void  ChQvLODInstance::PickAChild()
{
	int iChild = LookupChild(m_pContext);
	
#if 1
	if(iChild != m_iCurrentChild)
	{ 
		if(m_pFrames[iChild])
		{
			if(m_iCurrentChild >= 0)
			{
				ChNrFrameRemoveChild(m_frame, m_pFrames[m_iCurrentChild]);

			}
			ChNrFrameAddChild(m_frame, m_pFrames[iChild]);
			m_iCurrentChild = iChild;
			// Now get rid of unwanted stuff - very aggressive here!
			//Purge(iChild, 100);	// purge all but current and iChild
		}
		else
		{
			// Request the new one
			// Instantiate the child, then spawn and start construction
			QvNode *pChild = ((QvGroup*)GetNode())->getChild(iChild);
			ChQvInstance * pChildInst = InstantiateChild(pChild);

			// Add the child's new frame to our array, and remove it from us
			m_pFrames[iChild] = pChildInst->GetFrame();
			ChNrObjectReference(m_pFrames[iChild]);
			ChNrFrameRemoveChild(m_frame, m_pFrames[iChild]);

					// Spawn for new requests
			ChQvSpawnState state((ChMazeWnd *)(GetContext()->GetWnd()),	GetRelativeURL()); 
								//((ChMazeWnd *)(GetContext()->GetWnd()))->GetCurrentURL());
	    	pChild->traverse(&state);

			// Now get rid of unwanted stuff
			//Purge(iChild, 100);	// purge all but current and iChild

		}
	}
#else
	if(!m_children.IsEmpty())
	{
		if(iChild != m_iCurrentChild)
		{ 
			ChNrFrameRemoveChild(m_frame, m_pFrames[m_iCurrentChild]);
			ChNrFrameAddChild(m_frame, m_pFrames[iChild]);
			m_iCurrentChild = iChild;
		}
	}
#endif
};		
#endif

int  ChQvLODInstance::LookupChild(ChRenderContext * pContext)
{	
	QvLOD *lod = (QvLOD*)GetNode();
	int iChild = -1;

								// Transform camera from world coords
	GxVec3f	center, diff;
	Qv2Gx(lod->center, center);
	//center = Transform(center);
	GxVec3f	camera = pContext->GetCameraLoc();
	camera = TransformWorldToModel(camera);
	  
								// compute distance from camera 
	diff = center;
	diff -= camera;
	float range = diff.magnitude();

	range = pContext->GetAdjustedLODRange(range);
	
								// Lookup in range array
	int numKids = lod->getNumChildren();

	if(numKids)
	{
		int numRanges = lod->range.num;
		int i;
		for( i = 0; i < numRanges; i++)
		{
			if(range < (lod->range.values[i]))
			{
				break;
			}
		}
		iChild = min(i, (numKids - 1));
	}
	return iChild;
}

bool  ChQvLODInstance::Purge(int iChildToKeep /* = -1 */, int iHowMuch /* = 100 */)
{
	bool boolZapped = false;
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	// Throw away all the child instances except for the currently used
	// and currently desired iChild; if iChild is -1, look it up
	// It is intended that iHowMuch says how aggressive to be, but not used yet
	if(iChildToKeep == -1)
	{
		iChildToKeep = LookupChild(m_pContext);
	}

	QvLOD *lod = (QvLOD*)GetNode();
	int numKids = lod->getNumChildren();
	for(int i = 0; i < numKids; i++)
	{
		if(i != iChildToKeep && i != m_iCurrentChild)
		{
			if(m_pFrames[i])
			{
				if(!m_children.IsEmpty())
				{
					ChPosition pos = m_children.GetHeadPosition();
					while(pos)
					{
						ChPosition oldPos = pos;
						ChQvInstance *pChild = m_children.GetNext(pos);
						ChNrFrame frame = pChild->GetFrame();
						if(frame == m_pFrames[i])
						{
							ChQvRenderBaseData * pData = (ChQvRenderBaseData *)pChild->GetNode()->GetRenderData();
							m_pFrames[i] = 0;
							ChNrObjectDestroy(frame);
							#if 1
							pChild->Release();
							#endif
							pData->PurgeQv();
							//m_children.Remove(oldPos); this is done by deleting child
							boolZapped = true;
							break;
						}
					}
				}
				
			}
		}
	}
	#endif
	return boolZapped;
}

bool ChQvLODInstance::Iterate(ChQvInstanceIterator *pIterator)
{
	if(pIterator->GetIterationType() == ChQvInstanceIterator::inDrawScope)
	{
		int iChild = LookupChild(pIterator->GetRenderContext());


		pIterator->SetVisitType(ChQvInstanceIterator::beforeChildren);
		pIterator->SetDoKids(true); 
		bool boolKeepGoing = pIterator->DoNode(*this);
		if(pIterator->ShouldDoKids() && !m_children.IsEmpty() && boolKeepGoing)
		{
			ChPosition pos = m_children.FindIndex(iChild);
			if(!pos)
			{
				pos = m_children.GetTailPosition();
			}
			if(pos)
			{
				pIterator->SetVisitType(ChQvInstanceIterator::isLeaf);
				ChQvInstance *pChild = m_children.Get(pos);
				boolKeepGoing = pChild->Iterate(pIterator);
			}
		}
		pIterator->SetDoKids(true); 
		if(boolKeepGoing)
		{
			pIterator->SetVisitType(ChQvInstanceIterator::afterChildren);
			boolKeepGoing = pIterator->DoNode(*this);
		}
		return boolKeepGoing;
	}
	else
	{
		return ChQvGroupInstance::Iterate(pIterator);
	}
}


void ChQvLODInstance::SetUpKids(ChRenderContext* pContext)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	QvLOD *pNode = (QvLOD *)GetNode();
	int numKids = pNode->getNumChildren();

	m_pFrames = new ChNrFrame[numKids];
	for(int j = 0; j < numKids; j++) m_pFrames[j] = 0;

	pContext->LockScene();
	if(!m_children.IsEmpty())
	{
		int i = 0;
		ChPosition pos = m_children.GetHeadPosition();
		while(pos)
		{
			ChQvInstance *pChild = m_children.GetNext(pos);
			m_pFrames[i] = pChild->GetFrame();
			ChNrObjectReference(m_pFrames[i]);
			if(pos) ChNrFrameRemoveChild(m_frame, m_pFrames[i]);
			i++;
		}
		m_iCurrentChild = i - 1;
	}

	ChNrFrameAddCallback(m_frame, LODFrameCallback, this);
	pContext->UnlockScene();
#endif
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
bool ChQvLODInstance::Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator)
{
	if(	pIterator->GetVisitType() == ChQvInstanceIterator::afterChildren)
	{
		bool boolKeepGoing = true;
		if(!m_children.IsEmpty())
		{
			ChPosition pos = m_children.GetHeadPosition();
			while(pos && boolKeepGoing)
			{
				pIterator->SetVisitType(ChQvInstanceIterator::isLeaf);
				ChQvInstance *pChild = m_children.GetNext(pos);
				boolKeepGoing = pChild->Iterate(pIterator);
			}
		}

		if(boolKeepGoing)
		{
			SetUpKids(pRC);		
		}
		return boolKeepGoing;
	}

	return true;
}
bool ChQvLODInstance::Draw(ChRenderContext *pRC, ChDrawIterator *pIterator)
{
	ChQvGroupInstance::Draw(pRC, pIterator);

	return true;
}
#endif

//////////////////////////////////////////////////////////

ChQvSwitchInstance::ChQvSwitchInstance() : ChQvGroupInstance(),
	m_pFrames(0), m_iCurrentChild(-1)
{
}

ChQvSwitchInstance::~ChQvSwitchInstance()
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	delete [] m_pFrames;
	m_pFrames = 0;
	if(!m_children.IsEmpty())
	{
		ChPosition pos = m_children.GetHeadPosition();
		while(pos)
		{
			ChQvInstance *pChild = m_children.GetNext(pos);
			ChNrFrame frame = pChild->GetFrame();
			if (frame) ChNrObjectDestroy(frame);
		}
	}
#endif
}

bool ChQvSwitchInstance::Iterate(ChQvInstanceIterator *pIterator)
{
	if( pIterator->GetIterationType() == ChQvInstanceIterator::inDrawScope)
	{
		int iChild;
		if(m_pNode)
		{
			iChild = int(((QvSwitch*)GetNode())->whichChild.value);
		}
		else
		{
			iChild = QV_SWITCH_ALL;
		}
		bool boolKeepGoing = true;

		if (iChild == QV_SWITCH_ALL)
		{
			return ChQvGroupInstance::Iterate(pIterator);	 // VRML 1.0 only; 1.1 does away with it
		}
		else
		{
			pIterator->SetVisitType(ChQvInstanceIterator::beforeChildren);
			pIterator->SetDoKids(true); 
			bool boolKeepGoing = pIterator->DoNode(*this);
			if(pIterator->ShouldDoKids() && !m_children.IsEmpty() && boolKeepGoing)
			{
				if(iChild >= 0)	// i.e., not QV_SWITCH_NONE or QV_SWITCH_ALL
				{
					ChPosition pos = m_children.FindIndex(iChild);
					if(pos)
					{
						pIterator->SetVisitType(ChQvInstanceIterator::isLeaf);
						ChQvInstance *pChild = m_children.Get(pos);
						boolKeepGoing = pChild->Iterate(pIterator);
					}
				}
			}
			pIterator->SetDoKids(true); 
			if(boolKeepGoing)
			{
				pIterator->SetVisitType(ChQvInstanceIterator::afterChildren);
				boolKeepGoing = pIterator->DoNode(*this);
			}
			return boolKeepGoing;
		}
	}
	else
	{
		return ChQvGroupInstance::Iterate(pIterator);
	}
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
// Callback to choose child while rendering
#if (defined(CH_USE_RLAB))
void SwitchFrameCallback(ChNrFrame frame, void * arg)
#else
void SwitchFrameCallback(ChNrFrame frame, void * arg, float delta)
#endif
{
	ChQvSwitchInstance *pInst = (ChQvSwitchInstance *)arg;
	if(pInst) pInst->PickAChild();
}

void ChQvSwitchInstance::RemoveChildFrames()
{
	ChNrFrameArray frames;
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	int count;

	ChNrFrameGetChildren(m_frame, &count, &frames);
	#if defined(CH_USE_D3D)
	count = frames->GetSize();
	#endif

	ChNrFrame elt;
	for( int i = 0; i < count; i++)
	{
		ChNrFrameRemoveChild(m_frame, GetElement(frames, (unsigned int)i, elt));
		D3DRelease(elt);
	}
#else
	#pragma message("D3D Switch implementation Not done!")
#endif

	ChNrFree(frames);
}

int  ChQvSwitchInstance::LookupChild()
{
	// Get a -valid- whichChild value
	int iChild = ((QvSwitch*)GetNode())->whichChild.value;
	int iChildCount = ((QvGroup*)GetNode())->getNumChildren();
	iChild = min(iChild, iChildCount - 1);	// Out of range, use last
	if(iChild < 0 && iChild != QV_SWITCH_ALL && iChild != QV_SWITCH_NONE) iChild = QV_SWITCH_NONE;
	if(iChildCount <= 0) iChild = QV_SWITCH_NONE;
	return iChild;
}

void  ChQvSwitchInstance::PickAChild()
{

	int iChild = LookupChild();
	int iChildCount = ((QvGroup*)GetNode())->getNumChildren();

	if(iChild != m_iCurrentChild)
	{ 
		switch(iChild)
		{
			case QV_SWITCH_ALL:
			{
				// No need to remove any, just add all not currently added, and
				// request construction on the unconstructed
				RemoveChildFrames();
				ChQvInstance *pChild = 0;
				for(int i = 0; i < iChildCount; i++)
				{
					ChNrFrameAddChild(m_frame, m_pFrames[i]);
					pChild = GetChild(i);
					if(!pChild->IsConstructed())
					{
						GetContext()->StartConstruction(pChild);
								// Spawn for new requests
						ChQvSpawnState state((ChMazeWnd *)(GetContext()->GetWnd()),	GetRelativeURL()); 
				    	pChild->GetNode()->traverse(&state);
					}
				}
				m_iCurrentChild = iChild;
				break;
			}
			case QV_SWITCH_NONE:
			{
				// Just remove all and be done with it
				RemoveChildFrames();
				m_iCurrentChild = iChild;
				break;
			}
			default:
			{
				ChQvInstance *pChild = 0;
				if(iChild >= 0)
				{
					pChild = GetChild(iChild);
					if(pChild)
					{
						if(pChild->IsConstructed())
						{
							if(m_iCurrentChild >= 0)
							{
								ChNrFrameRemoveChild(m_frame, m_pFrames[m_iCurrentChild]);

							}
							else if(m_iCurrentChild == QV_SWITCH_ALL)
							{
								// Remove all children
								RemoveChildFrames();
							}
							ChNrFrameAddChild(m_frame, m_pFrames[iChild]);
							m_iCurrentChild = iChild;
						}
						else
						{
							// Request the new one
							// Start construction
							// Explicitly do -not- set m_iCurrentChild
							// Wait until it's complete to copy in as current
							// Note that this may fire off unneeded construction threads
							GetContext()->StartConstruction(pChild);
									// Spawn for new requests
							ChQvSpawnState state((ChMazeWnd *)(GetContext()->GetWnd()),	GetRelativeURL()); 
					    	pChild->GetNode()->traverse(&state);

							// try this instead...
							RemoveChildFrames();
							ChNrFrameAddChild(m_frame, m_pFrames[iChild]);
							m_iCurrentChild = iChild;
						}
					}
				}

			}
		}

		#if 0
		//debris
			// Add the child's new frame to our array, and remove it from us
			m_pFrames[iChild] = pChildInst->GetFrame();
			ChNrObjectReference(m_pFrames[iChild]);
			ChNrFrameRemoveChild(m_frame, m_pFrames[iChild]);

					// Spawn for new requests
			ChQvSpawnState state((ChMazeWnd *)(GetContext()->GetWnd()),	GetRelativeURL()); 
	    	pChild->traverse(&state);

			// Now get rid of unwanted stuff
			//Purge(iChild, 100);	// purge all but current and iChild

		#endif
	}
};		
#endif
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
bool ChQvSwitchInstance::Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator)
{
	if(	m_pNode && pIterator->GetVisitType() == ChQvInstanceIterator::afterChildren)
	{
		SetUpKids(pRC);		
	}

	return true;
}
bool ChQvSwitchInstance::Draw(ChRenderContext *pRC, ChDrawIterator *pIterator)
{
	ChQvGroupInstance::Draw(pRC, pIterator);

	return true;
}
#endif
void ChQvSwitchInstance::SetUpKids(ChRenderContext* pContext)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	QvSwitch *pNode = (QvSwitch *)GetNode();
	int numKids = pNode->getNumChildren();

		//TRACE("Reallocating child frames! That's a leak!!\n");
	if(!m_pFrames) 
	{
		m_pFrames = new ChNrFrame[numKids ? numKids : 1];
		for(int j = 0; j < numKids; j++) m_pFrames[j] = 0;

		pContext->LockScene();
		m_iCurrentChild = LookupChild();
		if(!m_children.IsEmpty())
		{
			int i = 0;
			ChPosition pos = m_children.GetHeadPosition();
			while(pos)
			{
				ChQvInstance *pChild = m_children.GetNext(pos);
				m_pFrames[i] = pChild->GetFrame();
				ChNrObjectReference(m_pFrames[i]);
				if(i != m_iCurrentChild && m_iCurrentChild != QV_SWITCH_ALL)
				{
					ChNrFrameRemoveChild(m_frame, m_pFrames[i]);
				}
				i++;
			}
		}

		ChNrFrameAddCallback(m_frame, SwitchFrameCallback, this);
		pContext->UnlockScene();
	}
#endif
}


///////////////////////////////////////////////////////////////////////////////


// end of file
