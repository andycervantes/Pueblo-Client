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

	Implementation for the ChQV helper classes.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChQvStat.cpp,v 2.8 1995/10/23 17:59:05 jimd Exp $

#include "grheader.h"
//
#include <ChCore.h>

#include <QvDB.h>
#include <QvInput.h>
#include <QvNode.h>
#include <QvState.h>
#include <fstream.h>
#include <strstrea.h>
#include "ChMaze.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

#define NOT_IMPLEMENTED	TRACE2("Function not implemented, file %s: line %s.", __FILE__, __LINE__)

ChQvState::ChQvState(ChMazeWnd* pView) :
		QvState(), m_pView(pView), m_numLights(0), m_type(draw),
		m_iData(0), m_fData(0), m_boolKeyFound(0), m_boolCmdDone(0), m_pNode(0),
		m_pHint(0), m_pMaterialBinding(0), m_pMaterial(0), m_pCamera(0)

{
	
	push();
	m_pHint 			= new QvShapeHints;
	m_pMaterialBinding 	= new QvMaterialBinding;
	m_pMaterial 		= new QvMaterial;
	pView->GetRenderContext()->GetDefaultCamera()->traverse(this);

	m_pHint->traverse(this);
	m_pMaterialBinding->traverse(this);
	m_pMaterial->traverse(this);
}

void ChQvState::popElement(StackIndex stackIndex)
{
	#if defined(CH_USE_3DR)
	if(stackIndex == LightIndex)
	{
	 	G3dHandle_t hGC = GetView()->GetGC();
		int iLight = PopLight();
		if(iLight >= 0)
		{
			G3dResetLight(hGC, iLight);
		}
	}
	#endif	// don't need for others
	QvState::popElement(stackIndex);
}

ChQvState& ChQvState::operator=( const ChQvState& state )
{
	// 	We only dupe the qvstate part, not ours
	if (this != &state)
	{
		Kill();
		Copy( state );
	}

	return *this;
}

void ChQvState::Kill()
{
    while (depth > 0) pop();

    for (int i = 0; i < NumStacks; i++)
		stacks[i] = NULL;

    //delete [] stacks;
	//stacks = 0;
}

void ChQvState::Copy(const ChQvState& state)
{
	depth = state.depth;
    if (!stacks) stacks = new QvElement * [NumStacks];

    for (int i = 0; i < NumStacks; i++)
	{
		stacks[i] = 0;
		QvElement *pElt = state.stacks[i];
		QvElement *pLast = 0;
		while(pElt)
		{
			QvElement *pNew = new QvElement;	
			*pNew = *pElt;
			pNew->next = 0;
			if(pLast)
			{
				pLast->next = pNew;
			}
			else
			{
				stacks[i] = pNew;
			}
			pLast = pNew;
			pElt = pElt->next;
		}
	}
}

ChQvBoundsState& ChQvBoundsState::operator=( const ChQvState& state )
{
	// 	We only dupe the qvstate part, not ours
	if (this != &state)
	{
		Kill();
		Copy( state );
	}

	return *this;
}

