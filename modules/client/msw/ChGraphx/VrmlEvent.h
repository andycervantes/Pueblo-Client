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

	Implementation for collision detection in VRML/RenderLab

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/VrmlEvent.h,v 2.3 1996/07/18 04:50:25 pritham Exp $
#if !defined( _VRMLEVENT_H_ )
#define _VRMLEVENT_H_

struct ChVRMLEvent 
{
	ChVRMLEvent	*nextEvent;
	enum type {invalid = 0, 
		SFBitMask = 1, SFBool, SFColor, SFEnum, SFFloat, SFImage, SFLong, SFMatrix, SFNode,
		SFRotation, SFString, SFVec2f, SFVec3f, SFTime, SFPick, SFProximity, SFCollision,
		MFBitMask = 0x8001, MFBool, MFColor, MFEnum, MFFloat, MFImage, MFLong, MFMatrix, MFNode,
		MFRotation, MFString, MFVec2f, MFVec3f, MFTime, MFPick, MFProximity, MFCollision
		} eventType;
	double 		eventTime;
	char 		*eventName;
	int 		dataSize;
	char		*bytes;
};
 
#endif // _VRMLEVENT_H_
