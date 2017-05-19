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
#include "ChGrVw.h"
//#include "dib.h"

#include "ChSpritN.h"
#include "ChSprite.h"
#include "ChSpLstN.h"
#include "ChSprLst.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpriteList

IMPLEMENT_SERIAL(CSpriteList, CObList, 0 /* Schema number */ )

CSpriteList::CSpriteList()
{
    // Give the sprite notification object
    // a pointer to the list object.
    m_NotifyObj.SetList(this);
}

CSpriteList::~CSpriteList()
{
}

/////////////////////////////////////////////////////////////////////////////
// CSpriteList serialization

void CSpriteList::Serialize(CArchive& ar)
{
    // Let the base class create the set of objects.
    CObList::Serialize(ar);

    // If we've just loaded, initialize each sprite.
    if (ar.IsLoading()) {
        for (POSITION pos = GetHeadPosition(); pos != NULL;) {
            CSprite* pSprite = GetNext(pos); // Increment position.
            pSprite->SetNotificationObject(&m_NotifyObj);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// CSpriteList commands

// Remove everything from the list deleting all the sprites we remove
void CSpriteList::RemoveAll()
{
    // Walk down the list deleting objects as we go.
    // We need to do this here because the base class
    // simply deletes the pointers.
    POSITION pos;
    CSprite* pSprite;
    for (pos = GetHeadPosition(); pos != NULL;) {
        pSprite = GetNext(pos); // Increment position.
        if (pSprite) {
            ASSERT(pSprite->IsKindOf(RUNTIME_CLASS(CSprite)));
            delete pSprite;
        }
    }
    // Now call the base class to remove the pointers.
    CObList::RemoveAll();
}

// Add a sprite to the list, placing it according to its z-order value.
BOOL CSpriteList::Insert(CSprite* pNewSprite)
{
    // Set the notification object pointer in the sprite
    // to the sprite list's notification object.
    pNewSprite->SetNotificationObject(&m_NotifyObj);

    // Walk down the list until we either get to the end
    // or we find a sprite with the same or higher z-order
    // in which case we insert just before that one.

    POSITION pos, posThis;
    CSprite* pSprite;
    for (pos = GetHeadPosition(); pos != NULL;) {
        posThis = pos;
        pSprite = GetNext(pos); // Increment position.
        if (pSprite->GetZ() >= pNewSprite->GetZ()) {
            InsertBefore(posThis, pNewSprite);
            return true;
        }
    }
    // Nothing with the same or a higher z-order, so add the sprite to
    // the end.
    AddTail(pNewSprite); 
    return true;
}

// Remove a sprite from the list, but do not delete it
CSprite* CSpriteList::Remove(CSprite* pSprite)
{
    POSITION pos = Find(pSprite);
    if (pos == NULL) {
        return NULL;
    }
    RemoveAt(pos);
    return pSprite;
}

// Move a sprite to its correct z-order position.
void CSpriteList::Reorder(CSprite* pSprite)
{
    // Remove the sprite from the list.
    if (!Remove(pSprite)) {
        TRACE("Unable to find sprite");
        return; // Not there.
    }
    // Now insert it again in the right place.
    Insert(pSprite);
}

// Test for a mouse hit on any sprite in the list.
CSprite* CSpriteList::HitTest(CPoint point)
{
    // Walk the list top down.
    POSITION pos;
    CSprite* pSprite;
    for (pos = GetHeadPosition(); pos != NULL;) {
        pSprite = GetNext(pos); // Increment position.
        if (pSprite->HitTest(point)) {
            return pSprite;
        }
    }
    return NULL;
}

