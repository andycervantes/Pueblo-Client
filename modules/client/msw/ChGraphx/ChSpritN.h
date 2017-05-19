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

	This is a class of pure virtual functions with no data. It is used
	by sprite objects to make notification callbacks. A user of the CSprite
	class can derive an object from CSpriteNotifyObj and pass a pointer to this
	derived class object to the sprite object for notification calls.
	Just like OLE's IClientSite interface really.

----------------------------------------------------------------------------*/

#ifndef __SPRITENO__
#define __SPRITENO__

class CSprite;

class CSpriteNotifyObj : public CObject
{
public:
    enum CHANGETYPE {
        ZORDER      = 0x0001,
        POSITION    = 0x0002,
        IMAGE       = 0x0004
    };

public:
    virtual void Change(CSprite* pSprite,
                        CHANGETYPE change,
                        CRect* pRect1 = NULL,
                        CRect* pRect2 = NULL) = 0;
};
#endif // __SPRITENO__
