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

	Node types returned by QvNode::GetType(string&);

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvType.h,v 2.7 1996/08/22 22:45:18 jimd Exp $

enum nodeType {
	typeQvBackground,
	typeQvBaseColor,
	typeQvCone,
	typeQvCube,
	typeQvCylinder,
	typeQvEnvironment,
	typeQvGroup,
	typeQvIndexedFaceSet,
	typeQvIndexedLineSet,
	typeQvLOD,	
	typeQvSeparator,
	typeQvSwitch,			
	typeQvTransformSeparator,
	typeQvAsciiText,
	typeQvCoordinate3,
	typeQvDirectionalLight,
	typeQvInfo,
	typeQvFontStyle,
	typeQvMaterial,
	typeQvMaterialBinding,
	typeQvMatrixTransform,
	typeQvNormal,
	typeQvNormalBinding,
	typeQvOrthographicCamera,
	typeQvPerspectiveCamera,
	typeQvPointLight,
	typeQvPointSet,	
	typeQvRotation,
	typeQvScale,
	typeQvShapeHints,
	typeQvSphere,	
	typeQvSpin,
	typeQvSpinGroup,
	typeQvSpotLight,
	typeQvTexture2,
	typeQvTexture2Transform,
	typeQvTextureCoordinate2,
	typeQvTransform,
	typeQvTranslation,
	typeQvWWWAnchor,		
	typeQvWWWInline,
	typeQvInterpolator,
	typeQvOrientationInterpolator,
	typeQvPositionInterpolator,
	typeQvTimeSensor,
	typeQvSensor,
	typeQvRoute,
	typeQvNavigationInfo,
	typeQvUnknownNode
};


// end of file
