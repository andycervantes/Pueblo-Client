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

#ifndef __PHSPRITE__
#define __PHSPRITE__

class ChAnimCastMember;

class CPhasedSprite : public CSprite
{
    DECLARE_SERIAL(CPhasedSprite)
public:
    CPhasedSprite();
    ~CPhasedSprite();

    // New in this class
    virtual int GetNumCellRows() {return m_iNumCellRows;}
    virtual int GetNumCellColumns() {return m_iNumCellColumns;}
    virtual int GetCellRow() {return m_iCellRow;}
    virtual int GetCellColumn() {return m_iCellColumn;}

    virtual BOOL SetNumCellRows(int iNumRows);
    virtual BOOL SetNumCellColumns(int iNumColumns);
    virtual BOOL SetCellRow(int iRow);
    virtual BOOL SetCellColumn(int iColumn);

    // from base classes
    virtual long GetHeight() {return m_iCellHeight;}
    virtual long GetWidth() {return m_iCellWidth;}
    virtual void GetRect(CRect* pRect); 
    virtual BOOL HitTest(CPoint point);
    virtual void Render(ChDibBmp* pDIB, CRect* pClipRect = NULL);
    virtual void Serialize(CArchive& ar);
    virtual void Initialize();
	inline ChAnimCastMember *GetCast() { return m_pCast; };
	inline void SetCast(ChAnimCastMember *pCast) { m_pCast = pCast;};

protected:
    int m_iNumCellRows;     // Number of rows in the image grid
    int m_iNumCellColumns;  // Number of columns in the image grid
    int m_iCellRow;         // Current cell row
    int m_iCellColumn;      // Current cell column
    int m_iCellHeight;      // Height of a row
    int m_iCellWidth;       // Width of a column

	ChAnimCastMember *m_pCast;			// containing cast member
};
#endif // __PHSPRITE__
