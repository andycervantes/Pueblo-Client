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

#include <afxwin.h>
#include <ChTypes.h>
#include <iostream.h>
#include <process.h>
#include <afxext.h>						// MFC extensions

#include "GxQuaternion.h"

main(int argc, char *argv[ ])
{
	float x, y, z;
	GxVec3f	dir(0, 0, -1);
	GxVec3f	up(0, 1, 0);

	if(argc >= 4)
	{
		sscanf(argv[1], "%g", &x);
		sscanf(argv[2], "%g", &y);
		sscanf(argv[3], "%g", &z);
		dir.set(x, y, z);
	}
	if(argc >= 7)
	{
		sscanf(argv[4], "%g", &x);
		sscanf(argv[5], "%g", &y);
		sscanf(argv[6], "%g", &z);
		up.set(x, y, z);
	}

	GxQuaternion	q(dir, up);
	GxVec3f	axis;
	float angle;
	q.AxisAngle(axis, angle);
	printf("(%f %f %f), %f", axis.x(), axis.y(), axis.z(), angle);

	//getchar();

	return 0;
}
		   					
