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

	Implementation for the traversal of a VRML QV tree into Intel 3DR.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvWrite.cpp,v 2.13 1996/08/22 22:45:19 jimd Exp $
/*
 Copyright 1995 by Tenet Networks, Inc.
 Carlsbad, California, USA. All rights reserved.

 Redistribution and use of this software, with or without modification, is
 permitted provided that the following conditions are met:

 1. Redistributions of this software must retain the above copyright
    notice, this list of conditions and the following disclaimer.

  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO
  EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include "grheader.h"
//

#if defined( CH_ARCH_16 )
#include <QvElemnt.h>   
#else
#include <QvElement.h>   
#endif
#include <QvNodes.h>
#include <QvState.h>
#if defined( CH_ARCH_16 )
#include <UnknNode.h>   
#else
#include <QvUnknownNode.h>
#endif

#include <iostream.h>

// int i is used in some macros, but not needed for all
#pragma warning(disable:4101)

//////////////////////////////////////////////////////////////////////////////
//
// write code for all nodes. The default method (in QvNode) does
// nothing. Because write() is defined in the header for ALL node
// classes, each one has an implementation here.
//
//////////////////////////////////////////////////////////////////////////////

// For debugging
static int indent = 0;
static void
announce(const char *className, ostream &strm)
{
    for (int i = 0; i < indent; i++)
	strm << "\t";
    strm <<  className << " {\n";
}
#define ANNOUNCE(className) announce(QV__QUOTE(className), strm)

#define DEFAULT_write(className)					      \
void									      \
className::write(ostream &strm)						      \
{									      \
    ANNOUNCE(className);						      \
}

static void end_brack(ostream &strm )
	{
	for (int i = 0; i < indent; i++)
		strm << "\t";
	strm << "}\n";
	}
 
#define END_BRACK  end_brack( strm );

void tab_in(int in, ostream &strm)
{
	for (int i = 0; i < in; i++) strm << "\t";
}

void print_bitmask(QvSFEnum enm, ostream &strm)
{
	int out_vals_written = 0, all_val;
	QvName all("ALL");

	enm.findEnumValue(all, all_val);

	if (enm.value == all_val) 
		strm << "\tALL\n";
	else  {
		strm << "\t(";
		for (int i = 0; i < enm.numEnums-1; i++) {
	
			if (enm.enumValues[i] & enm.value) {
				if (out_vals_written++) strm << " | ";
				strm << (char *)enm.enumNames[i].getString( );
				}
			}
		strm << ")\n";
		}
}

void print_enum(QvSFEnum enm, ostream &strm)
{
	if (enm.isDefault( )) 
		strm << "DEFAULT\n";
	else  {
		for (int i = 0; i < enm.numEnums; i++) 
			if (enm.enumValues[i] == enm.value) {
				strm << (char *)enm.enumNames[i].getString( ) << "\n";
				break;
				}
		}
}
 
#define MFIELD(fieldNm, grouping)						\
	if (!(fieldNm.isDefault( ))) {						\
		tab_in( indent, strm );								\
 		strm << QV__QUOTE(fieldNm) << "\t[";				\
		for (i = 0; i < fieldNm.num * grouping; i++) {	\
			if (i && (grouping != 1) && (i % grouping == 0)) strm << ",";	\
			strm << " " << fieldNm.values[i];			\
 			}									 		\
	 	strm << "]\n";									\
	 	}

	  
#define BITMASK(fieldNm)								\
 	if (!(fieldNm.isDefault( ))) {						\
		if (fieldNm.numEnums) {							\
			tab_in( indent, strm  );							\
			strm << QV__QUOTE(fieldNm);					\
			print_bitmask(fieldNm, strm);						\
			}											\
		}
 	
  
#define FIXEDARRAYFIELD(fieldNm, grouping)				\
	if (!(fieldNm.isDefault( ))) {						\
		tab_in( indent, strm  );								\
		strm << QV__QUOTE(fieldNm) << "\t";				\
		for (i = 0; i < grouping; i++) {				\
			strm << fieldNm.value[i] << " ";			\
			}									 		\
	 	strm << "\n";									\
		}

#define FIELD(fieldNm) 									\
	if (!(fieldNm.isDefault( ))) {						\
		tab_in( indent, strm  );								\
		strm << QV__QUOTE(fieldNm) << "\t" << fieldNm.value << "\n"; \
		}	 

#define STRINGFIELD(fieldNm) 							\
	if (!(fieldNm.isDefault( ))) {						\
		tab_in( indent, strm  );								\
		strm << QV__QUOTE(fieldNm) << "\t" 				\
			<< "\""  << fieldNm.value.getString( ) << "\"\n"; \
		}
		 

#define MSTRINGFIELD(fieldNm, grouping)						\
	if (!(fieldNm.isDefault( ))) {						\
		tab_in( indent, strm );								\
 		strm << QV__QUOTE(fieldNm) << "\t[";				\
		for (i = 0; i < fieldNm.num * grouping; i++) {	\
			if (i && (grouping != 1) && (i % grouping == 0)) strm << ",";	\
			strm << " " << "\""  << fieldNm.values[i].getString( ) << "\"\n";			\
 			}									 		\
	 	strm << "]\n";									\
	 	}

	  

#define ENUMFIELD(fieldNm)								\
	if (!(fieldNm.isDefault( ))) {						\
		if (fieldNm.numEnums) {							\
			tab_in( indent, strm );							\
			strm << QV__QUOTE(fieldNm) << "\t";			\
			print_enum(fieldNm, strm);						\
			}											\
		}
	
 
#define ROTATIONFIELD(fieldNm)							\
	if (!(fieldNm.isDefault( ))) {						\
		tab_in( indent, strm  );								\
		strm << QV__QUOTE(fieldNm) << "\t";				\
		for (i = 0; i < 3 ; i++) 						\
			strm << fieldNm.axis[i] << " ";				\
		strm <<	fieldNm.angle << "\n";					\
		} 

#define MATRIXFIELD(fieldNm)							\
	if (!(fieldNm.isDefault( ))) {						\
		tab_in( indent, strm  );								\
		strm << QV__QUOTE(fieldNm) << "\t";				\
		for (i = 0; i < 4; i++)							\
			for (int j = 0; j < 4; j++)					\
				strm << fieldNm.value[i][j] << " ";		\
		strm << "\n";									\
		}

#define BOOLFIELD(fieldNm) 								\
	if (!(fieldNm.isDefault( ))) {						\
		tab_in( indent, strm  );								\
		strm << QV__QUOTE(fieldNm) << "\t" <<			\
			(fieldNm.value ? "TRUE" : "FALSE") << "\n"; \
		}
		
//////////////////////////////////////////////////////////////////////////////
//
// Groups.
//
//////////////////////////////////////////////////////////////////////////////

void
QvGroup::write(ostream &strm)
{
    ANNOUNCE(Group);
    indent++;
    for (int i = 0; i < getNumChildren(); i++)
	getChild(i)->write(strm);
	END_BRACK;
    indent--;
}

void
QvLOD::write(ostream &strm)
{  	
	int i;
    ANNOUNCE(QvLOD);
    indent++;

	MFIELD(range,1)
	FIXEDARRAYFIELD(center,3);

    for (i = 0; i < getNumChildren(); i++)
	getChild(i)->write(strm);

	END_BRACK;
    indent--;
}

void
QvSeparator::write(ostream &strm)
{
    ANNOUNCE(Separator);
    indent++;
	
	ENUMFIELD(renderCulling)

    for (int i = 0; i < getNumChildren(); i++)
	getChild(i)->write(strm);
	END_BRACK;
    indent--;
}

void
QvSwitch::write(ostream &strm)
{
    ANNOUNCE(Switch);
    indent++;

	FIELD(whichChild)

    int which = whichChild.value;

    if (which == QV_SWITCH_NONE)
	;

    else if (which == QV_SWITCH_ALL)
	for (int i = 0; i < getNumChildren(); i++)
	    getChild(i)->write(strm);

    else
	if (which < getNumChildren())
	    getChild(which)->write(strm);

	END_BRACK;
    indent--;
}

void
QvTransformSeparator::write(ostream &strm)
{
    ANNOUNCE(TransformSeparator);

    // We need to "push" just the transformation stack. We'll
    // accomplish this by just pushing a no-op transformation onto
    // that stack. When we "pop", we'll restore that stack to its
    // previous str.


    indent++;
    for (int i = 0; i < getNumChildren(); i++)
	getChild(i)->write(strm);

    // Now do the "pop"
	END_BRACK;
    indent--;
}

//////////////////////////////////////////////////////////////////////////////
//
// Properties.
//
//////////////////////////////////////////////////////////////////////////////

#define DO_PROPERTY(className, stackIndex, propName)		\
void									      				\
className::write(ostream &strm)					    	\
{															\
	int i;								      				\
    ANNOUNCE(propName);						     			\
    indent++;			

#define DO_TYPED_PROPERTY(className, stackIndex, eltType)	\
void									      				\
className::write(ostream &strm)					      	\
{															\
	int i;								      				\
    ANNOUNCE(eltType);						      			\
    indent++;			

#define END_PROPERTY 										\
    END_BRACK;					      						\
   	indent--;												\
}

DO_PROPERTY(QvBaseColor,			BaseColorIndex, BaseColor)
	MFIELD(rgb, 3);
END_PROPERTY

DO_PROPERTY(QvCoordinate3,		Coordinate3Index, Coordinate3) 
	MFIELD(point, 3);
END_PROPERTY

DO_PROPERTY(QvFontStyle,		FontStyleIndex, FontStyle) 
	FIELD(size);
	ENUMFIELD(family);
	BITMASK(style);
END_PROPERTY


DO_PROPERTY(QvMaterial,			MaterialIndex, Material)
	MFIELD(ambientColor, 3);
	MFIELD(diffuseColor, 3);
	MFIELD(specularColor, 3);
	MFIELD(emissiveColor, 3);
	MFIELD(shininess, 1);
	MFIELD(transparency, 1);
END_PROPERTY

DO_PROPERTY(QvMaterialBinding,		MaterialBindingIndex, MaterialBinding)
	ENUMFIELD(value);
END_PROPERTY

DO_PROPERTY(QvNormal,			NormalIndex, Normal)
	MFIELD(vector, 3);
END_PROPERTY

DO_PROPERTY(QvNormalBinding,		NormalBindingIndex, NormalBinding)
	ENUMFIELD(value);
END_PROPERTY

DO_PROPERTY(QvShapeHints,		ShapeHintsIndex, ShapeHints)
	ENUMFIELD(vertexOrdering);
	ENUMFIELD(shapeType);
	ENUMFIELD(faceType);
	FIELD(creaseAngle);
END_PROPERTY

DO_PROPERTY(QvTextureCoordinate2,	TextureCoordinate2Index, TextureCoordinate2)
	MFIELD(point, 2);
END_PROPERTY

DO_PROPERTY(QvTexture2,			Texture2Index, Texture2)
	STRINGFIELD(filename);
	// This has not been implemented by QvLib yet    TBA
	// IMAGEFIELD(image)
	ENUMFIELD(wrapS);
	ENUMFIELD(wrapT);
END_PROPERTY

DO_PROPERTY(QvTexture2Transform,	Texture2TransformationIndex, Texture2Transformation)
	FIXEDARRAYFIELD(translation, 2);
	FIELD(rotation);
	FIXEDARRAYFIELD(scaleFactor, 2);
	FIXEDARRAYFIELD(center, 2);
END_PROPERTY


DO_TYPED_PROPERTY(QvDirectionalLight,	LightIndex, DirectionalLight)
	BOOLFIELD(on);
	FIELD(intensity);
	FIXEDARRAYFIELD(color, 3);
	FIXEDARRAYFIELD(direction,3);
END_PROPERTY

DO_TYPED_PROPERTY(QvPointLight,		LightIndex, PointLight)
	BOOLFIELD(on);
	FIELD(intensity);
	FIXEDARRAYFIELD(color, 3);
	FIXEDARRAYFIELD(location,3);
END_PROPERTY

DO_TYPED_PROPERTY(QvSpotLight,		LightIndex, SpotLight)
	BOOLFIELD(on);
	FIELD(intensity);
	FIXEDARRAYFIELD(color, 3);
	FIXEDARRAYFIELD(location,3);
	FIXEDARRAYFIELD(direction,3);
	FIELD(dropOffRate);
	FIELD(cutOffAngle);
END_PROPERTY


DO_TYPED_PROPERTY(QvOrthographicCamera,	CameraIndex, OrthographicCamera)
	FIXEDARRAYFIELD(position,3);
	ROTATIONFIELD(orientation);
	FIELD(focalDistance);
	FIELD(height);
END_PROPERTY

DO_TYPED_PROPERTY(QvPerspectiveCamera,	CameraIndex, PerspectiveCamera)
	FIXEDARRAYFIELD(position,3);
	ROTATIONFIELD(orientation);
	FIELD(focalDistance);
	FIELD(heightAngle);
END_PROPERTY


DO_TYPED_PROPERTY(QvTransform,	     TransformationIndex, Transform)
	FIXEDARRAYFIELD(translation,3);
	ROTATIONFIELD(rotation);
	FIXEDARRAYFIELD(scaleFactor,3);
	ROTATIONFIELD(scaleOrientation);
	FIXEDARRAYFIELD(center,3);
END_PROPERTY

DO_TYPED_PROPERTY(QvRotation,	     TransformationIndex, Rotation)
	ROTATIONFIELD(rotation);
END_PROPERTY

DO_TYPED_PROPERTY(QvMatrixTransform, TransformationIndex, MatrixTransform)
	MATRIXFIELD(matrix);
END_PROPERTY

DO_TYPED_PROPERTY(QvTranslation,     TransformationIndex, Translation)
	FIXEDARRAYFIELD(translation,3);
END_PROPERTY

DO_TYPED_PROPERTY(QvScale,	     TransformationIndex, Scale)
	FIXEDARRAYFIELD(scaleFactor,3);
END_PROPERTY


//////////////////////////////////////////////////////////////////////////////
//
// Shapes.
//
//////////////////////////////////////////////////////////////////////////////

#define DO_SHAPE(classNm, name) 			\
void classNm::write(ostream &strm)	\
{											\
	int i;									\
  	ANNOUNCE(name);							\
  	indent++;

#define END_SHAPE							\
	END_BRACK;								\
	indent--;								\
}	
 

DO_SHAPE(QvAsciiText, AsciiText)
 	MSTRINGFIELD(string, 1);
 	MFIELD(width, 1);
	FIELD(spacing);
	FIELD(justification);	
END_SHAPE

DO_SHAPE(QvCube, Cube)
 	FIELD(width);
	FIELD(height);
	FIELD(depth);	
END_SHAPE


DO_SHAPE(QvCone, Cone)
	BITMASK(parts);
	FIELD(bottomRadius);
	FIELD(height);	
 END_SHAPE
	
DO_SHAPE(QvCylinder, Cylinder)
	BITMASK(parts);
	FIELD(radius);	
 	FIELD(height);
 END_SHAPE


DO_SHAPE(QvIndexedFaceSet, IndexedFaceSet)
	MFIELD(coordIndex, 1);
	MFIELD(materialIndex, 1);
	MFIELD(normalIndex, 1);
	MFIELD(textureCoordIndex, 1);
END_SHAPE

DO_SHAPE(QvIndexedLineSet, IndexedLineSet)
	MFIELD(coordIndex, 1);
	MFIELD(materialIndex, 1);
	MFIELD(normalIndex, 1);
	MFIELD(textureCoordIndex, 1);
 END_SHAPE


DO_SHAPE(QvPointSet, PointSet)
	FIELD(startIndex);
	FIELD(numPoints);
 END_SHAPE

DO_SHAPE(QvSphere, Sphere)
	FIELD(radius);
 END_SHAPE

//
// Not really a shape, but this does what it's supposed to.
//
DO_SHAPE(QvInfo, Info)
	STRINGFIELD(string)
END_SHAPE;


//////////////////////////////////////////////////////////////////////////////
//
// WWW-specific nodes.
//
//////////////////////////////////////////////////////////////////////////////

#define DO_WWW(className, propName)		\
void									      				\
className::write(ostream &strm)					    	\
{															\
	int i;								      				\
    ANNOUNCE(propName);						     			\
    indent++;			

#define END_WWW												\
 	if (getNumChildren() > 0)			 					\
		getChild(0)->write(strm); 						\
	END_BRACK												\
	indent--;	 											\
	}

DO_WWW(QvWWWAnchor, WWWAnchor)
  	STRINGFIELD(name)
	ENUMFIELD(map)
END_WWW

DO_WWW(QvWWWInline, WWWInline)
	STRINGFIELD(name)
	FIXEDARRAYFIELD(bboxSize, 3)
	FIXEDARRAYFIELD(bboxCenter, 3)
END_WWW


//////////////////////////////////////////////////////////////////////////////
//
// Default traversal methods. These nodes have no effects during traversal.
//
//////////////////////////////////////////////////////////////////////////////

DEFAULT_write(QvUnknownNode)
DEFAULT_write(QvBackground)
#if defined(_QV_ENVIRONMENT_)
DEFAULT_write(QvEnvironment)
#endif
DEFAULT_write(QvSpin)
DEFAULT_write(QvSpinGroup)
DEFAULT_write(QvOrientationInterpolator)
DEFAULT_write(QvPositionInterpolator)
DEFAULT_write(QvInterpolator)
DEFAULT_write(QvSensor)
DEFAULT_write(QvTimeSensor)
DEFAULT_write(QvRoute)
DEFAULT_write(QvNavigationInfo)

//////////////////////////////////////////////////////////////////////////////

#undef ANNOUNCE
#undef END_BRACK
#undef DEFAULT_write
#undef DO_PROPERTY
#undef DO_SHAPE
#undef DO_TYPED_PROPERTY
#undef DO_WWW
#undef END_SHAPE
#undef END_PROPERTY
#undef END_WWW
#undef FIELD
#undef MFIELD
#undef BITMASK
#undef END_BRACK
#undef MATRIXFIELD

