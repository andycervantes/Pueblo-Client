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

----------------------------------------------------------------------------*/

#include "grheader.h"
#include "ChAnim.h"

#include "ChSpritN.h"
#include "ChSprite.h"
#include "ChSpLstN.h"
#include "ChSprLst.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpriteListNotifyObj

CSpriteListNotifyObj::CSpriteListNotifyObj()
{
    m_pSpriteList = NULL;
    m_pBufferView = NULL;
}

CSpriteListNotifyObj::~CSpriteListNotifyObj()
{
}

// Notification callback from a CSprite object.
void CSpriteListNotifyObj::Change(CSprite* pSprite,
                                  CHANGETYPE change,
                                  CRect* pRect1,
                                  CRect* pRect2)
{
    if (change & CSpriteNotifyObj::ZORDER) {
        // Reposition the sprite in the z-order list.
        ASSERT(m_pSpriteList);
        m_pSpriteList->Reorder(pSprite);
        // Add the sprite position to the dirty list.
        ASSERT(m_pBufferView);
        m_pBufferView->AddDirtyRegion(pRect1);
    }
    if (change & CSpriteNotifyObj::POSITION) {
        // pRect1 and pRect2 point to old and new rectangle positions;
        // add these rectangles to the dirty list.
        ASSERT(m_pBufferView);
        m_pBufferView->AddDirtyRegion(pRect1);
        m_pBufferView->AddDirtyRegion(pRect2);
    }
    if (change & CSpriteNotifyObj::IMAGE) {
        // redraw the sprite
        // Add the sprite position to the dirty list.
        ASSERT(m_pBufferView);
        m_pBufferView->AddDirtyRegion(pRect1);
    }
}
