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

#ifndef __SPRITELST__
#define __SPRITELST__

class CSpriteList : private CObList
{
    DECLARE_SERIAL(CSpriteList)
public:
    CSpriteList();
    ~CSpriteList();
    void RemoveAll();
    BOOL Insert(CSprite* pSprite);
    void Reorder(CSprite* pSprite);
    CSprite *Remove(CSprite* pSprite);
    CSprite *GetNext(POSITION &pos)
        {return (CSprite*) CObList::GetNext(pos);}
    CSprite *GetPrev(POSITION &pos)
        {return (CSprite*) CObList::GetPrev(pos);}
    POSITION GetTailPosition() const
        {return CObList::GetTailPosition();}
    POSITION GetHeadPosition() const
        {return CObList::GetHeadPosition();}
    CSprite* HitTest(CPoint point);
    virtual void Serialize(CArchive& ar);
    BOOL IsEmpty()
        {return CObList::IsEmpty();}

public:
    CSpriteListNotifyObj m_NotifyObj;
};
#endif // __SPRITELST__
