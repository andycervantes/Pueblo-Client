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

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvGroup.cpp,v 1.4 1996/06/27 03:44:00 jimd Exp $

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

ChQvSeparatorInstance::ChQvSeparatorInstance() : ChQvGroupInstance()
{
}
//////////////////////////////////////////////////////////////////////
ChQvSpinGroupInstance::ChQvSpinGroupInstance() : ChQvGroupInstance()
{
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#if (defined(CH_USE_RLAB))
void SpinGroupCallback(ChNrFrame frame, void * arg)
#else
void SpinGroupCallback(ChNrFrame frame, void * arg, float delta)
#endif
{
	ChQvSpinGroupRenderData *pData = (ChQvSpinGroupRenderData *)arg;
	ChQvSpinGroupInstance *pTarget = (ChQvSpinGroupInstance *)(ChNrObjectGetAppData(frame));
	if(pData && pTarget)
	{
		pData->Spin(pTarget);
	}
}
#endif


void ChQvSpinGroupInstance::CreateFrame()
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	ChQvGroupInstance::CreateFrame();
	// Now add the callback for spinning this
	ChNrFrameAddCallback(m_frame, SpinGroupCallback, this->GetRenderData());
#endif
};

ChQvGroupInstance *ChQvSpinGroupInstance::SetupTraversalState(ChQvState &state)
{	
	ChQvGroupInstance::SetupTraversalState(state);


								///  set up stack to have proper transform instance at top to
								// inherit into subtree
								// Since this is a spingroup, it's own transform is important 
	ChQvElement *elt = new ChQvElement;					
    elt->data = GetNode();
    elt->SetInstance(GetTransformInstance());							
    state.addElement(QvState::TransformationIndex, elt);

	return this;
}



//////////////////////////////////////////////////////////////////////
ChQvTransformSeparatorInstance::ChQvTransformSeparatorInstance() : ChQvGroupInstance()
{
}

///////////////////////////////////////////////////////////////////////////////
ChQvWWWAnchorInstance::ChQvWWWAnchorInstance() : ChQvGroupInstance()
{

	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	m_pSensor = new ChQvAnchorSensor(this);
	#endif
}

ChQvWWWAnchorInstance::~ChQvWWWAnchorInstance()
{
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	delete m_pSensor;
	#endif
}

bool ChQvWWWAnchorInstance::Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	ChQvGroupInstance::Construct(pRC, pIterator);
#endif
	return true;
}

bool ChQvWWWAnchorInstance::Draw(ChRenderContext *pRC, ChDrawIterator *pIterator)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	ChQvGroupInstance::Draw(pRC, pIterator);
#endif
	UpdateSensor(pRC);
	return true;
}

void ChQvWWWAnchorInstance::UpdateSensor(ChRenderContext *pRC)
{
	#if defined(CH_USE_3DR)
	ChQvAnchorSensor *pAnchor = new ChQvAnchorSensor(this);
	pAnchor->Init(pRC);
	// Compute current bounds
	pAnchor->GetBounds()->Apply(this, pRC);

	// Add self and bounds to list
	((ChMazeWnd*)(pRC->GetWnd()))->AddAnchor(pAnchor);
	#endif
}

bool  ChQvWWWAnchorInstance::IsPointMap()
{
	QvWWWAnchor *pNode = (QvWWWAnchor*)GetNode();

	return 	(pNode->map.value == QvWWWAnchor::POINT); 
}


///////////////////////////////////////////////////////////////////////////////
ChQvWWWInlineInstance::ChQvWWWInlineInstance() : ChQvGroupInstance() 
{
}

void ChQvWWWInlineInstance::Init(ChQvBuildState *pState)
{
	ChQvGroupInstance::Init(pState);
}

string& ChQvWWWInlineInstance::GetRelativeURL()
{
	return ((ChQvWWWInlineRenderData*)m_pRenderData)->GetCurrentURL();
}


#if 0
void ChQvWWWInlineInstance::Init(ChQvBuildState *pState)
{
	ChQvGroupInstance::Init(pState);
	ChQvInstanceHasProps::Init(pState, this);
}

void ChQvWWWInlineInstance::RestoreProp(ChQvState &state, QvNode *pProp, QvState::StackIndex stackIndex)
{
    QvElement *elt = new QvElement;					
    elt->data = pProp;							
    state.addElement(stackIndex, elt);
}

ChQvWWWInlineInstance *ChQvWWWInlineInstance::SetupTraversalState(ChQvState &state)
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
#endif
//////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////


// end of file
