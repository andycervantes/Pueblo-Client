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

	Implementation for the ChColor class for  Intel 3DR and RealityLab.

----------------------------------------------------------------------------*/

#include "grheader.h"

#include "ChTransition.h"

ChStateTransition::ChStateTransition(int numStates, int numEvents /* = 1*/) :
	m_numStates(numStates), m_numEvents(numEvents), m_uData(0), m_iState(0), m_pMatrix(0)
{
	Init();
};

ChStateTransition::ChStateTransition() :
	m_numStates(1), m_numEvents(1), m_uData(0), m_iState(-1), m_pMatrix(0)
{
	Init();
};

ChStateTransition::~ChStateTransition()
{
	delete [] m_pMatrix;
};

		
bool ChStateTransition::ProcessKeyEvent(int keyMsg, int key, chuint32 modifiers)
{
	int iEvent;
	chuint32 *pData;
	bool	m_boolDidIt = false;

	if(TranslateKeyEvent(keyMsg, key, modifiers, iEvent, pData))
	{
		transition cell = GetMatrix()[iEvent * m_numStates + m_iState];
		//if(pData) m_uData = *pData;
		if((this->*(cell.m_action))())
		{
			m_iState = cell.m_iNewState;
		}
		m_boolDidIt = true;
	}
	return m_boolDidIt;
}

bool ChStateTransition::ProcessMouseEvent(int mouseMsg, int x, int y, chuint32 uFlags)
{
	int iEvent;
	chuint32 *pData;
	bool	m_boolDidIt = false;

	if(TranslateMouseEvent(mouseMsg, x, y, uFlags, iEvent, pData))
	{
		transition cell = GetMatrix()[iEvent * m_numStates + m_iState];
		//if(pData) m_uData = *pData;
		if((this->*(cell.m_action))())
		{
			m_iState = cell.m_iNewState;
		}
		m_boolDidIt = true;
	}
	return m_boolDidIt;
}

bool ChStateTransition::ProcessEvent(int iMsg, void *pMsgData)
{
	int iEvent;
	chuint32 *pData;
	bool	m_boolDidIt = false;

	if(TranslateEvent(iMsg, pMsgData, iEvent, pData))
	{
		transition cell = GetMatrix()[iEvent * m_numStates + m_iState];
		//if(pData) m_uData = *pData;
		if((this->*(cell.m_action))())
		{
			m_iState = cell.m_iNewState;
			m_boolDidIt = true;
		}
		m_boolDidIt = true;
	}
	return m_boolDidIt;
}

		// Overrides
void ChStateTransition::Init()
{
	m_pMatrix = new transition[m_numStates * m_numEvents];
	for(int iEvent = 0; iEvent < m_numEvents; iEvent++)
	{
		for(int iState = 0; iState < m_numStates; iState++)
		{
			InitCell(m_pMatrix[iEvent * m_numStates + iState], iState);
		}
	}

}

bool ChStateTransition::SetCell( int iState, int iEvent, const transition &trans)
{
	GrowMatrix(iState + 1, iEvent + 1);
	m_pMatrix[iEvent * m_numStates + iState] = trans;
	return true;
}

bool ChStateTransition::GrowMatrix(int numStates, int numEvents)
{
	// NOT IMPLEMENTED YET
	if(numStates <= m_numStates && numEvents <= m_numEvents) return true;
	ASSERT(false);
	return false;

}


 
