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

#ifndef __SPRITE__
#define __SPRITE__

#include <ChDibBmp.h>

class CSprite : public ChDibBmp
{
    DECLARE_SERIAL(CSprite)
public:
    CSprite();
    ~CSprite();

    virtual int GetX() {return m_x;}   // Get x.
    virtual int GetY() {return m_y;}   // Get y.
    virtual int GetZ() {return m_z;}   // Get z-order.

    virtual void Serialize(CArchive& ar);
    virtual void Render(ChDibBmp* pDIB, CRect* pClipRect = NULL);
    virtual BOOL Load(CFile* fp);               // Load from file
    virtual BOOL Load(char* pszFileName = NULL);// Load DIB from disk file
    virtual BOOL Load(WORD wResid);             // Load DIB from resource
    virtual BOOL MapColorsToPalette(CPalette* pPal);
    virtual void GetRect(CRect* pRect); 
    virtual BOOL HitTest(CPoint point);
    virtual void SetPosition(int x,
                             int y);
    virtual void SetZ(int z);
    virtual void SetNotificationObject(CSpriteNotifyObj* pNO)
        {m_pNotifyObj = pNO;}


protected:
    int m_x;                        // X Coordinate of top-left corner
    int m_y;                        // Y Coordinate of top-left corner
    int m_z;                        // Z-order for sprite
    BYTE m_bTransIndex;             // Transparency index value
    CSpriteNotifyObj* m_pNotifyObj; // Pointer to a notification object

    virtual void Initialize();      // Set initial state.
};
#endif __SPRITE__
