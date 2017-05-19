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
#include "ChPhSprt.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPhasedSprite

IMPLEMENT_SERIAL(CPhasedSprite, CSprite, 0 /* Schema number */ )

CPhasedSprite::CPhasedSprite() :
	m_pCast(0)
{	
    m_iNumCellRows = 1;
    m_iNumCellColumns = 1;
    m_iCellRow = 0;
    m_iCellColumn = 0;
    m_iCellHeight = CSprite::GetHeight();
    m_iCellWidth =  CSprite::GetWidth();
}

CPhasedSprite::~CPhasedSprite()
{
}

/////////////////////////////////////////////////////////////////////////////
// CPhasedSprite serialization

void CPhasedSprite::Serialize(CArchive& ar)
{
    CSprite::Serialize(ar);
    if (ar.IsStoring())
    {
        ar << (DWORD) m_iNumCellRows;
        ar << (DWORD) m_iNumCellColumns;
        ar << (DWORD) m_iCellRow;
        ar << (DWORD) m_iCellColumn;
    }
    else
    {
        DWORD dw;
        ar >> dw;
        SetNumCellRows(dw);
        ar >> dw;
        SetNumCellColumns(dw);
        ar >> dw;
        SetCellRow(dw);
        ar >> dw;
        SetCellColumn(dw);
    }
}

/////////////////////////////////////////////////////////////////////////////
// CPhasedSprite commands

// Do any initialization after file load of a new image etc.
void CPhasedSprite::Initialize()
{
    CSprite::Initialize();
    m_iNumCellRows = 1;
    m_iNumCellColumns = 1;
    m_iCellRow = 0;
    m_iCellColumn = 0;
    m_iCellHeight = CSprite::GetHeight();
    m_iCellWidth = CSprite::GetWidth();
}

// Divide the image into a given number of rows.
BOOL CPhasedSprite::SetNumCellRows(int iRows)
{
    if (iRows < 1) {
        TRACE("Invalid number of rows");
        return false;
    }
    // Compute the height of each row.
    int iCellHeight = CSprite::GetHeight() / iRows;
    if (iCellHeight < 1) {
        TRACE("Can't make them that small");
        return false;
    }
    // Set the new height and row count.
    m_iNumCellRows = iRows;
    m_iCellRow = 0;
    m_iCellHeight = iCellHeight;
    return true;
}

// Divide the image into a given number of columns.
BOOL CPhasedSprite::SetNumCellColumns(int iColumns)
{
    if (iColumns < 1) {
        TRACE("Invalid number of columns");
        return false;
    }
    // Compute the width of each column.
    int iCellWidth = CSprite::GetWidth() / iColumns;
    if (iCellWidth < 1) {
        TRACE("Can't make them that small");
        return false;
    }
    // Set the new width and column count.
    m_iNumCellColumns = iColumns;
    m_iCellColumn = 0;
    m_iCellWidth = iCellWidth;
    return true;
}

// Set the current row.
BOOL CPhasedSprite::SetCellRow(int iRow)
{
    if ((iRow >= m_iNumCellRows)
    || (iRow < 0)) {
        TRACE("Invalid row");
        return false;
    }
    if (iRow == m_iCellRow) return false; // Nothing to do
    m_iCellRow = iRow;
    // Send a notification to redraw.
   if (m_pNotifyObj) {
        CRect rcPos;
        GetRect(&rcPos);
        m_pNotifyObj->Change(this, 
                            CSpriteNotifyObj::IMAGE,
                            &rcPos);
   }
   return true;
}

// Set the current column.
BOOL CPhasedSprite::SetCellColumn(int iColumn)
{
    if ((iColumn >= m_iNumCellColumns)
    || (iColumn < 0)) {
        TRACE("Invalid column");
        return false;
    }
    if (iColumn == m_iCellColumn) return false; // Nothing to do
    m_iCellColumn = iColumn;
    // Send a notification to redraw.
   if (m_pNotifyObj) {
        CRect rcPos;
        GetRect(&rcPos);
        m_pNotifyObj->Change(this, 
                            CSpriteNotifyObj::IMAGE,
                            &rcPos);
   }
   return true;
}
                                                  
// Get the bounding rectangle.
void CPhasedSprite::GetRect(CRect* pRect)
{
    ASSERT(pRect);
    pRect->left = m_x;
    pRect->top = m_y;
    pRect->right = m_x + GetWidth();
    pRect->bottom = m_y + GetHeight();
}

// Test for a hit in a non-transparent area.
BOOL CPhasedSprite::HitTest(CPoint point)
{
    // Test if the point is inside the sprite rectangle.
    if ((point.x > m_x) 
    && (point.x < m_x + GetWidth())
    && (point.y > m_y)
    && (point.y < m_y + GetHeight())) {
        // Hit is in sprite rectangle.
        // See if this point is transparent by testing if
        // the pixel value is the same as the top-left corner value.
        // Note that top-left of the image is bottom-left in the DIB.
        // Get the address of the top-left pixel
        // of the cell, not the DIB. Note that the
        // GetPixelAddress function refers to addresses
        // in the DIB, not the cell.
        int x = point.x - m_x + (m_iCellColumn * m_iCellWidth);
        int y = point.y - m_y + (m_iCellRow * m_iCellHeight);
        BYTE* p = (BYTE*)GetPixelAddress(x, y);
        ASSERT(p);
        if (*p != m_bTransIndex) {
            return true;
        }
    }
    return false;
}

// Render a sprite to a DIB.
void CPhasedSprite::Render(ChDibBmp* pDIB, CRect* pClipRect)
{
    ASSERT(pDIB);
    ASSERT(pClipRect);
    // Get the sprite rect and see if it's visible.
    CRect rcDraw;
    GetRect(&rcDraw);
    if (!rcDraw.IntersectRect(pClipRect, &rcDraw)) {
        return; // Not visible
    }
    // Modify the source x and y values for the current phase of the sprite.
    int xs = rcDraw.left - m_x + m_iCellColumn * m_iCellWidth;
    int ys = rcDraw.top - m_y + m_iCellRow * m_iCellHeight;
    ASSERT(xs >= 0 && xs < CSprite::GetWidth());
    ASSERT(ys >= 0 && ys < CSprite::GetHeight());
    CopyBits(pDIB,                          // Destination DIB
             rcDraw.left,                   // Destination x
             rcDraw.top,                    // Destination y
             rcDraw.right - rcDraw.left,    // Width
             rcDraw.bottom - rcDraw.top,    // Height
             xs,                            // Source x
             ys,                            // Source y
             PALETTEINDEX(m_bTransIndex));  // Transparent color index
}
