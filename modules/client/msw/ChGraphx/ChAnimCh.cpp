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

	Implementation for the ChGraphic class, which is used to display
	graphics, & accept selection of hot spots and sprites.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChAnimCh.cpp,v 2.4 1995/08/31 18:48:54 jimd Exp $

#include "grheader.h"

#include <ChCore.h>

#include "ChGrMod.h"
#include "ChAnim.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*	
	Class ChAnimCastMember
*/

ChAnimCastMember::ChAnimCastMember(chuint32 luId) : 
		m_id(luId),
		m_strSpriteURL(""),
		m_iCurCell( 0 ),                
		m_numCells( 1 ),                    
		m_boolFrozen( 0 ),                  
		m_boolVisible( 0 ),                 
		m_boolDraggable( 0 ),               
		m_version( 1 ),
		m_iNumSpriteRows(0), m_iNumSpriteCols(0),
		m_pAnchor(0),
		m_pView(0)
{ 
	m_pScript = new ChCell [1];
	m_pSprite = 0;
}

ChAnimCastMember::~ChAnimCastMember() 
{
	delete [] m_pScript;
	m_pScript = 0;
	if (m_pSprite && m_boolVisible)
	{
		m_pView->Remove(m_pSprite);
	}
	delete m_pAnchor;
	delete m_pSprite;
}
								   // Move one step; frame time is in luCurrMsec
bool ChAnimCastMember::Tick(chuint32 luCurrMsec) 
{ 									// for now, assume motion implies visibility
    if (!m_boolFrozen && m_boolVisible)
    {
	// !!!!!!!!! ?????????? need to change for varying framerates

        chint32 lNewCell = m_iCurCell + 1;
        SetCell(lNewCell);
    }
	return true;
} 			
									// return bounding rect
void ChAnimCastMember::SetCell(chint32 lCell) 
{ 									// for now, assume motion implies visibility
    if (!m_boolFrozen && m_boolVisible)
    {
        m_iCurCell = min(lCell, m_numCells - 1);
        m_iCurCell = max(m_iCurCell, 0);
		
        if (m_pScript[m_iCurCell].row < 0) {
            // End of sequence
			if (m_pScript[m_iCurCell].row == CH_ANIM_SCRIPT_GO_TO)
			{
	            m_iCurCell = m_pScript[m_iCurCell].col;
			}
			else
			{
	            m_iCurCell --;
				ASSERT(m_iCurCell >= 0);
				m_boolFrozen = true;
				// return;	// this would freeze in place
				// jump to start and freeze ???
			}
            //return;
        }
        // See if there is a sound to play
        //if (pch->pCurCell->pSnd) {
        //    pch->pCurCell->pSnd->Play();
        //}
        // Move the sprite
        m_pSprite->SetCellRow(m_pScript[m_iCurCell].row);
        m_pSprite->SetCellColumn(m_pScript[m_iCurCell].col);
        m_pSprite->SetZ(m_pScript[m_iCurCell].z);
        m_pSprite->SetPosition(m_pScript[m_iCurCell].x,
                                  m_pScript[m_iCurCell].y);
        // add the sprite rect to the dirty region list
        CRect rcSprite;
        m_pSprite->GetRect(&rcSprite);
        m_pView->AddDirtyRegion(&rcSprite);
    }
	return;
}
 			
void ChAnimCastMember::GetBounds(CRect* pRect)
{ 
}
									// draw yourself to DC
void ChAnimCastMember::Draw(CDC * pDC ) 
{ }
	
void ChAnimCastMember::Animate( bool boolRun)
{
	m_boolFrozen = !boolRun;
} 

									// Test point for containment
bool ChAnimCastMember::HitTest(const CPoint & pt ) 
{
	//NOT_IMPLEMENTED;	 // not needed??
	return false;
}											  // set flag and force redraw
void ChAnimCastMember::Show( bool boolVisible ) 
{
	bool boolChanged = (!!boolVisible != !!m_boolVisible);
	m_boolVisible = boolVisible;
	if (m_pView && boolChanged)
	{
		if (m_pSprite && m_boolVisible)
		{
			m_pView->Insert(m_pSprite);
		}
		else
		{
			m_pView->Remove(m_pSprite);
		}
	}
}
												 
void ChAnimCastMember::SetScript(ChAnimScript *pScript, bool boolCopy)
{
	SetScript( pScript->GetCount(), pScript->GetCurCell(), 
				pScript->GetFrameRate(), pScript->GetCells(), boolCopy);  // copy cells
}
												 // consumes pCells!
void ChAnimCastMember::SetScript(int numCells, int iCurCell, chint32 lFrameRate, ChCell *pCells, bool boolCopy)
{
	if (pCells && numCells > 0 && !boolCopy )
	{
		delete []m_pScript;
		m_pScript = pCells;
		m_numCells = numCells;
	}
	else if (!pCells || numCells == 0) 
	{
		// set default script
		pCells = new ChCell [1];
		if (pCells)
		{
			delete []m_pScript;
			m_pScript = pCells;
			m_numCells = 1;
		}
	}
	else
	{
		ChCell *pNewCells = new ChCell [numCells];
		if (pNewCells)
		{
			delete []m_pScript;
			memcpy(pCells, pNewCells, numCells * sizeof(ChCell));
			m_pScript = pCells;
			m_numCells = numCells;
		}
	}
	m_iCurCell = min(max(iCurCell, 0), m_numCells - 1);
	m_lFrameRate = lFrameRate;
	InitializeScript();
}

									 
void ChAnimCastMember::SetSprite(CPhasedSprite* pSprite)
{
	if (pSprite != m_pSprite) delete m_pSprite;
	m_pSprite = pSprite;
	pSprite->SetNumCellRows( m_iNumSpriteRows);      
	pSprite->SetNumCellColumns( m_iNumSpriteCols);
	pSprite->SetCellRow( m_pScript[m_iCurCell].row);      
	pSprite->SetCellColumn(m_pScript[m_iCurCell].col);
	pSprite->SetZ(m_pScript[m_iCurCell].z);
	pSprite->SetPosition(m_pScript[m_iCurCell].x,
                             m_pScript[m_iCurCell].y);
	pSprite->SetCast(this);

}		  
 
#if 0 // obsolete?
void ChAnimCastMember::InitFromMsg( ChCastMsg *pMsg )
{
	delete m_pSprite;
	m_pSprite = new CPhasedSprite;

	//int iNumSpriteRows, iNumSpriteCols;
	pMsg->GetParams( m_id, m_strSpriteURL, 
			m_iNumSpriteRows, m_iNumSpriteCols, 
			m_numCells, 0, m_iCurCell, m_lFrameRate,
			m_boolVisible, 
			m_boolFrozen, 
			m_boolDraggable );
	
	delete m_pScript;
	m_pScript = new ChCell [m_numCells];

	pMsg->GetParams( m_id, m_strSpriteURL, 
			m_iNumSpriteRows, m_iNumSpriteCols, 
			m_numCells, m_pScript, m_iCurCell,
			m_lFrameRate, 
			m_boolVisible, 
			m_boolFrozen, 
			m_boolDraggable );
	
	InitializeScript();
	//m_pSprite->SetNumCellRows(iNumSpriteRows);
	//m_pSprite->SetNumCellColumns(iNumSpriteCols);

}
#endif

inline void ReadString( istream& strm, string& strStr )
{
	strm.eatwhite();
	strm.get();	   // first quote
	strm.get((strStr.GetBuffer(1000)), 1000, '"');
	strStr.ReleaseBuffer();
	strm.get();	   // last quote
}

inline void SkipIfComment( istream & strm )
{
	int ch = strm.peek();
	while (ch == '#')
	{
		strm.ignore( 1000, '\n');
		ch = strm.peek();
	}
}

void ChAnimCastMember::Read( istream& strm )
{
	delete m_pSprite;
	m_pSprite = new CPhasedSprite;
	chuint32	luType = 0;
	strm.eatwhite();

	SkipIfComment(strm);

	strm >>	(long unsigned)luType;

	if (!luType)
	{
		m_id = 0;
		return;
	}
	SkipIfComment(strm);
	strm >>	m_id;
	SkipIfComment(strm);
	string name;
	ReadString( strm, name );	// discard
	SkipIfComment(strm);
	ReadString( strm, m_strSpriteURL );	
	SkipIfComment(strm);
	strm >>	m_iNumSpriteRows;
	SkipIfComment(strm);
	strm >>	m_iNumSpriteCols;
	SkipIfComment(strm);
	//strm >>	m_numCells;
	SkipIfComment(strm);
	ReadString( strm, m_strScriptURL );	
	SkipIfComment(strm);
	strm >>	m_iCurCell;
	SkipIfComment(strm);
	strm >>	m_lFrameRate;
	SkipIfComment(strm);
	strm >>	m_boolVisible;
	SkipIfComment(strm);
	strm >>	m_boolFrozen;
	SkipIfComment(strm);
	strm >>	m_boolDraggable;

}

void ChAnimCastMember::InitializeScript()
{
	m_lTicksPerFrame = chint32(((1000 * 100) /double(m_lFrameRate)) + .5);
	m_lLastTick = 0; 
}
							  // called when we are added to a view
void ChAnimCastMember::OnAddition(ChAnimView *pView)
{
	m_pView = pView;
	if (m_pSprite && m_boolVisible)
	{
		pView->Insert(m_pSprite);
		pView->NewSprite(m_pSprite);
	}
}  
