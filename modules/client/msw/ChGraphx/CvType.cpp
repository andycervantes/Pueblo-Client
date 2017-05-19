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

	Implementation for dynamic type identification of nodes of a VRML QV tree

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvType.cpp,v 2.13 1996/08/22 22:45:17 jimd Exp $

#include "grheader.h"
//
#if defined( CH_ARCH_16 )
#include <QvElemnt.h>   
#else
#include <QvElement.h>   
#endif
#include <QvNodes.h>
#include <QvState.h>
#include "CvType.h"
#if defined( CH_ARCH_16 )
#include <UnknNode.h>   
#else
#include <QvUnknownNode.h>
#endif
#ifdef CH_MSW
#include <windows.h>
#endif
#ifdef HUGE
#undef HUGE
#endif
#define DEFAULT_GETTYPE(cls)	\
	 int cls::GetType(::string & strType)	\
	  {strType = #cls; return int(type##cls);}; 



DEFAULT_GETTYPE(QvCone)
DEFAULT_GETTYPE(QvCube)
DEFAULT_GETTYPE(QvCylinder)
#if defined(_QV_ENVIRONMENT_)
DEFAULT_GETTYPE(QvEnvironment)
#endif
DEFAULT_GETTYPE(QvGroup)
DEFAULT_GETTYPE(QvIndexedFaceSet)
DEFAULT_GETTYPE(QvIndexedLineSet)
DEFAULT_GETTYPE(QvLOD)	
DEFAULT_GETTYPE(QvSeparator)
DEFAULT_GETTYPE(QvSwitch)			
DEFAULT_GETTYPE(QvTransformSeparator)
									  
DEFAULT_GETTYPE(QvAsciiText)
DEFAULT_GETTYPE(QvBackground)
DEFAULT_GETTYPE(QvBaseColor)
DEFAULT_GETTYPE(QvCoordinate3)
DEFAULT_GETTYPE(QvDirectionalLight)
DEFAULT_GETTYPE(QvInfo)
DEFAULT_GETTYPE(QvFontStyle)
DEFAULT_GETTYPE(QvMaterial)
DEFAULT_GETTYPE(QvMaterialBinding)
DEFAULT_GETTYPE(QvMatrixTransform)
DEFAULT_GETTYPE(QvNormal)
DEFAULT_GETTYPE(QvNormalBinding)
DEFAULT_GETTYPE(QvOrthographicCamera)
DEFAULT_GETTYPE(QvPerspectiveCamera)
DEFAULT_GETTYPE(QvPointLight)
DEFAULT_GETTYPE(QvPointSet)
DEFAULT_GETTYPE(QvRotation)
DEFAULT_GETTYPE(QvScale)
DEFAULT_GETTYPE(QvShapeHints)
DEFAULT_GETTYPE(QvSphere)		 
DEFAULT_GETTYPE(QvSpin)		   
DEFAULT_GETTYPE(QvSpinGroup)		   
DEFAULT_GETTYPE(QvSpotLight)
DEFAULT_GETTYPE(QvTexture2)
DEFAULT_GETTYPE(QvTexture2Transform)
DEFAULT_GETTYPE(QvTextureCoordinate2)
DEFAULT_GETTYPE(QvTransform)
DEFAULT_GETTYPE(QvTranslation)
DEFAULT_GETTYPE(QvWWWAnchor)			 // ??
DEFAULT_GETTYPE(QvWWWInline)			 // ??
DEFAULT_GETTYPE(QvUnknownNode)		 // ??

DEFAULT_GETTYPE(QvOrientationInterpolator)
DEFAULT_GETTYPE(QvPositionInterpolator)
DEFAULT_GETTYPE(QvInterpolator)
DEFAULT_GETTYPE(QvSensor)
DEFAULT_GETTYPE(QvTimeSensor)
DEFAULT_GETTYPE(QvRoute)
DEFAULT_GETTYPE(QvNavigationInfo)

// end of file
