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
#include <ChGrVw.h>

#include "ChSpritN.h"
#include "ChSprite.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSprite

IMPLEMENT_SERIAL(CSprite, ChDibBmp, 0 /* Schema number */ )

CSprite::CSprite()
{
    m_x = 0;
    m_y = 0;
    m_z = 50;
    m_bTransIndex = 0;
    m_pNotifyObj = NULL;
}

CSprite::~CSprite()
{
}

// Set the initial state of the sprite from its DIB image.
void CSprite::Initialize()
{
    // Get the address of the top-left pixel.
    BYTE* p = (BYTE*)GetPixelAddress(0, 0);
    ASSERT(p);
    // Get the pixel value and save it.
    m_bTransIndex = *p;
}

/////////////////////////////////////////////////////////////////////////////
// CSprite serialization

void CSprite::Serialize(CArchive& ar)
{
    ChDibBmp::Serialize(ar);
    if (ar.IsStoring()) {
        ar << (DWORD) m_x;
        ar << (DWORD) m_y;
        ar << (DWORD) m_z;
    } else {
        DWORD dw;
        ar >> dw; m_x = (int) dw;
        ar >> dw; m_y = (int) dw;
        ar >> dw; m_z = (int) dw;
        // Now generate the other parameters from the DIB.
        Initialize();
    }
}

/////////////////////////////////////////////////////////////////////////////
// CSprite commands

// Render a sprite to a DIB.
void CSprite::Render(ChDibBmp* pDIB, CRect* pClipRect)
{
    ASSERT(pDIB);

    // Get the sprite rectangle.
    CRect rcDraw;
    GetRect(&rcDraw);

    // If a clip rectangle was supplied, see if the sprite
    // is visible inside the rectangle.
    if (pClipRect) {
        if (!rcDraw.IntersectRect(pClipRect, &rcDraw)) {
            return; // not visible
        }
    }
    // Copy the image of the sprite.
    CopyBits(pDIB,                         // Dest DIB
             rcDraw.left,                  // Dest x
             rcDraw.top,                   // Dest y
             rcDraw.right - rcDraw.left,   // Width
             rcDraw.bottom - rcDraw.top,   // Height
             rcDraw.left - m_x,            // Source x
             rcDraw.top - m_y,             // Source y
             PALETTEINDEX(m_bTransIndex)); // Transparent color index
}

// Load a sprite image from a disk file.
BOOL CSprite::Load(char* pszFileName)
{
    if (!ChDibBmp::Load(pszFileName)) {
        return false;
    }
    Initialize();
    return true;
}

// Load a sprite image from a disk file.
BOOL CSprite::Load(CFile* fp)
{
    if (!ChDibBmp::Load(fp)) {
        return false;
    }
    Initialize();
    return true;
}

// Load a sprite image from a resource.
BOOL CSprite::Load(WORD wResid)
{
    if (!ChDibBmp::Load(wResid)) {
        return false;
    }
    Initialize();
    return true;
}

// Map colors to palette.
BOOL CSprite::MapColorsToPalette(CPalette* pPal)
{
    BOOL bResult = ChDibBmp::MapColorsToPalette(pPal);
    // Get the transparency info again.
    // Note: Local call only; don't call any derived class.
    CSprite::Initialize();
    return bResult;
}

// Get the bounding rectangle.
void CSprite::GetRect(CRect* pRect)
{
    ASSERT(pRect);
    pRect->left = m_x;
    pRect->top = m_y;
    pRect->right = m_x + GetWidth();
    pRect->bottom = m_y + GetHeight();
}

// Test for a hit in a non-transparent area
BOOL CSprite::HitTest(CPoint point)
{
    // Test if the point is inside the sprite rectangle
    if ((point.x > m_x) 
    && (point.x < m_x + GetWidth())
    && (point.y > m_y)
    && (point.y < m_y + GetHeight())) {
        // See if this point is transparent by testing whether
        // the pixel value is the same as the top left
        // corner value. Note that top left of the
        // image is bottom left in the DIB.
        BYTE* p = (BYTE*)GetPixelAddress(point.x - m_x, point.y - m_y);
        if (*p != m_bTransIndex) {
            return true; // hit
        }
    }
    return false;
}

// Set a new x,y position.
void CSprite::SetPosition(int x, int y)
{
    // Save the current position.
    CRect rcOld;
    GetRect(&rcOld);
    // Move to new position.
    m_x = x;
    m_y = y;
    CRect rcNew;
    GetRect(&rcNew);
    // Notify that we have moved from our old position to
    // our new position.
    if (m_pNotifyObj) {
        m_pNotifyObj->Change(this, 
                             CSpriteNotifyObj::POSITION,
                             &rcOld,
                             &rcNew);
    }
}

// Set a new Z-order.
void CSprite::SetZ(int z)
{
    if (m_z != z) {
        m_z = z;
        // See if we have to notify anyone.
        if (m_pNotifyObj) {
            CRect rc;
            GetRect(&rc);
            m_pNotifyObj->Change(this,
                                 CSpriteNotifyObj::ZORDER,
                                 &rc);
        }
    }
}
