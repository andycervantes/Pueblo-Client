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

	This file contains the implementation for ChQvNormalMap class and its
	derived	classes, these are used to compute the normals for various Qv
	shape nodes.

	ChQvNormalMap				- Abstract base class of various normal maps
	ChQvCubeNormals				- Computes the normals of a cube
	ChQvConeNormals				- Computes the normals of a cone
	ChQvCylinderNormals			- Computes the normals of a cylinder
	ChQvSphereNormals			- Computes the normals of a sphere
	ChQvIndexedFaceSetNormals	- Computes the normals of an indexed face set

----------------------------------------------------------------------------*/

#if !defined( _CHQVNORMALMAP_CPP )
#define _CHQVNORMALMAP_CPP

#if ( _MSC_VER > 900	 )
#pragma warning( disable: 4237 )
#endif

#include <math.h>
#include <QvState.h>
#include <QvCoordinate3.h>
#include <QvNormal.h>
#include <QvShapeHints.h>
#include <QvNormalBinding.h>
#include <QvCone.h>
#include <QvIndexedFaceSet.h>
#include "GxUtils.h"
#include "CvNormal.h"

//
// A QvCube has 1 part, 6 faces and 8 vertices. Note that GetPartNormal
// and GetVertexNormal do not make much sense for a cube. GetPartNormal
// simply returns the normal of the first face. GetVertexNormal will
// always return a face normal of the face specified. 
//
// The basic cube is always represented by the following sequence of
// vertices numbered from 0 - 7,
//		(-1,-1,-1), ( 1,-1,-1), ( 1, 1,-1), (-1, 1,-1)
//		(-1,-1, 1), ( 1,-1,-1), ( 1, 1,-1), (-1, 1,-1)
// the faces are numbered 0 - 5,
//		(1,2,6,5), (0,4,7,3), (2,3,7,6), (1,5,4,0), (4,5,6,7), (0,3,2,1)
// the normals for the above faces are
//      (1,0,0), (-1,0,0), (0,1,0), (0,-1,0), (0,0,1), (0,0,-1)
//
GxVec3f ChQvCubeNormals::m_pNormals[6] = 
{ GxVec3f(1,0,0), GxVec3f(-1,0,0), GxVec3f(0,1,0), GxVec3f(0,-1,0), GxVec3f(0,0,1), GxVec3f(0,0,-1) } ;

ChQvCubeNormals::ChQvCubeNormals( QvCube* cube, QvState* state )
{
}

ChQvCubeNormals::~ChQvCubeNormals()
{
}

chint32 ChQvCubeNormals::GetNumParts()
{
	return 1 ;
}

chint32 ChQvCubeNormals::GetNumFaces( chint32 )
{
	return 6 ;
}

chint32 ChQvCubeNormals::GetNumVertices( chint32, chint32 )
{
	return 8 ;
}

GxVec3f ChQvCubeNormals::GetPartNormal( chint32 )
{
	//
	// We don't have any parts, simply return the 0th face normal
	//
	return m_pNormals[0] ;
}

GxVec3f ChQvCubeNormals::GetFaceNormal( chint32 lFace, chint32 )
{
	//
	// We ignore the part (assume 0th part) also we don't check
	// if 0 <= lFace < 6
	//
	return m_pNormals[lFace] ;
}

GxVec3f ChQvCubeNormals::GetVertexNormal( chint32, chint32 lFace, chint32 )
{
	//
	// Simply return the normal of the face to which the vertex belongs
	//
	return m_pNormals[lFace] ;
}


//
// A QvCone has two parts the - the cone itself and the base. The cone is
// subdivided into subdiv faces. The cone part has subdiv faces and
// subdiv+1 vertices. The base is also subdivided accordingly and has
// equal number of faces and vertices. The minimum value for subdiv is 3.
// However the normals along the subdivided faces of the base point along
// the same direction so we maintain only one base normal. The cone is
// always situated with its base lying in xz plane through the origin.
// The apex is on +ve y-axis.
//
// The first part is the cone and the second part is the base. The ordering
// of faces within each part is as follows, 0th face starts at +ve x-axis,
// and proceeds turning around the y-axis towards +ve z-axis. The ordering
// of vertices in a face always starts at either the apex or the base of the
// cone and proceeds counter clockwise.
//
GxVec3f ChQvConeNormals::m_pBaseNormal = GxVec3f( 0, -1, 0 ) ;

ChQvConeNormals::ChQvConeNormals( QvCone* cone, QvState*, chint32 subdiv )
{
    m_pSubDivision = 0 ;
	m_pFaceNormals = m_pVertexNormals = 0 ;
	if ( !cone ) return ;

	m_pSubDivision = ( subdiv < 3 ? 3 : subdiv ) ;
	m_pFaceNormals = new GxVec3f[m_pSubDivision] ;
	m_pVertexNormals = new GxVec3f[m_pSubDivision] ;

	if ( !m_pFaceNormals || !m_pVertexNormals )
	{
		subdiv = 0 ;
		delete[] m_pFaceNormals ; m_pFaceNormals = 0 ;
		delete[] m_pVertexNormals ; m_pVertexNormals = 0 ;
	}

	float h = cone->height.value ;
	float r = cone->bottomRadius.value ;

	//
	// The y component of all the normals is sqrt( r*r/(h*h+r*r) )
	//
	float ny = sqrt( r*r/(h*h + r*r) ) ;
	float xyscale = sqrt( h*h/(h*h + r*r) ) ;

	for ( int i = 0 ; i < m_pSubDivision ; i++ )
	{
		float theta = -i*M_PI/m_pSubDivision ;
		m_pVertexNormals[i].x() = xyscale*cos( theta ) ;
		m_pVertexNormals[i].y() = ny ;
		m_pVertexNormals[i].z() = xyscale*sin( theta ) ;

		theta *= 1.5 ;

		m_pFaceNormals[i].x() = xyscale*cos( theta ) ;
		m_pFaceNormals[i].y() = ny ;
		m_pFaceNormals[i].z() = xyscale*sin( theta ) ;
	}
}

ChQvConeNormals::~ChQvConeNormals()
{
	delete[] m_pFaceNormals ;
	delete[] m_pVertexNormals ;
}

chint32 ChQvConeNormals::GetNumParts()
{
	return 2 ;
}

chint32 ChQvConeNormals::GetNumFaces( chint32 )
{
	//
	// Both parts have the same number of faces
	//
	return m_pSubDivision ;
}

chint32 ChQvConeNormals::GetNumVertices( chint32, chint32 )
{
	//
	// All the faces are triangles
	//
	return 3 ;
}

GxVec3f ChQvConeNormals::GetPartNormal( chint32 lPart )
{
	//
	// Simply return the first face normal for the cone part
	//
	if ( lPart == 0 )
		return m_pFaceNormals[0] ;
	else 
		return m_pBaseNormal ;
}

GxVec3f ChQvConeNormals::GetFaceNormal( chint32 lFace, chint32 lPart )
{
	if ( lPart == 0 )
		return m_pFaceNormals[lFace] ;
	else
		return m_pBaseNormal ;
}

GxVec3f ChQvConeNormals::GetVertexNormal( chint32 lVertex,
										   chint32 lFace, chint32 lPart )
{
	if ( lPart == 0 )
	{
		//
		// The 0th vertex is the apex, use the face normal for this
		// Since no. of faces is equal to no. of vertices and since
		// vertices are counter-clockwise within a face, the 1st and
		// 2nd vertices correspond to lFace and lFace+1 entries in
		// the vertex array.
		//
		if ( lVertex == 0 )
			return m_pFaceNormals[lFace] ;
		else if ( lVertex == 0 )
			return m_pVertexNormals[lFace] ;
		else
			return m_pVertexNormals[(lFace+1)%m_pSubDivision] ;
	}
	else
		return m_pBaseNormal ;
}


//
// A QvCylinder has three parts the - the cylinder itself and two bases.
// Each part is subdivided into subdiv faces. The cylinder part has
// 2*subdiv vertices whereas each base has subdiv+1 vertices. The
// subdivision is performed radially.The minimum value for subdiv is 4.
// Similar to the cone above all the faces of a base have only one normal.
// 
GxVec3f ChQvCylinderNormals::m_pBaseNormals[2] = { GxVec3f(0,1,0), GxVec3f(0,-1,0) } ;

ChQvCylinderNormals::ChQvCylinderNormals( QvCylinder*, QvState*, chint32 subdiv )
{
	m_pSubDivision = ( subdiv < 3 ? 3 : subdiv ) ;
	m_pFaceNormals = new GxVec3f[m_pSubDivision] ;
	m_pVertexNormals = new GxVec3f[m_pSubDivision] ;

	if ( !m_pFaceNormals || !m_pVertexNormals )
	{
		subdiv = 0 ;
		delete[] m_pFaceNormals ; m_pFaceNormals = 0 ;
		delete[] m_pVertexNormals ; m_pVertexNormals = 0 ;
	}

	for ( int i = 0 ; i < m_pSubDivision ; i++ )
	{
		float theta = -i*M_PI/m_pSubDivision ;
		m_pVertexNormals[i].x() = cos( theta ) ;
		m_pVertexNormals[i].y() = 0 ;
		m_pVertexNormals[i].z() = sin( theta ) ;

		theta *= 1.5 ;

		m_pFaceNormals[i].x() = cos( theta ) ;
		m_pFaceNormals[i].y() = 0 ;
		m_pFaceNormals[i].z() = sin( theta ) ;
	}
}

ChQvCylinderNormals::~ChQvCylinderNormals()
{
	delete[] m_pFaceNormals ;
	delete[] m_pVertexNormals ;
}

chint32 ChQvCylinderNormals::GetNumParts()
{
	//
	// The cylinder lies along y-axis and is centered on the origin
	//		Part 0 - the vertical walls of the cylinder
	//		Part 1 - the base of the cylinder on +ve y-axis
	//		Part 2 - the base of the cylinder on -ve y-axis
	//
	return 3 ;
}

chint32 ChQvCylinderNormals::GetNumFaces( chint32 lPart )
{
	//
	// All parts subdiv faces
	//
	return m_pSubDivision ;
}

chint32 ChQvCylinderNormals::GetNumVertices( chint32, chint32 lPart )
{
	//
	// The vertical walls of the cylinder are tessellated into rectangles
	// whereas the circular bases are tessellated into triangles similar
	// to the cone.
	//
	if ( lPart == 0 )
		return 4 ;
	else
		return 3 ;
}

GxVec3f ChQvCylinderNormals::GetPartNormal( chint32 lPart )
{
	//
	// Simply return the first face normal for vertical part
	//
	if ( lPart == 0 )
		return m_pFaceNormals[0] ;
	else if ( lPart == 1 )
		return m_pBaseNormals[0] ;
	else
		return m_pBaseNormals[1] ;
}

GxVec3f ChQvCylinderNormals::GetFaceNormal( chint32 lFace, chint32 lPart )
{
	//
	// All the faces in a base have the same normal
	//
	if ( lPart == 0 )
		return m_pFaceNormals[lFace] ;
	else if ( lPart == 1 )
		return m_pBaseNormals[0] ;
	else
		return m_pBaseNormals[1] ;
}

GxVec3f ChQvCylinderNormals::GetVertexNormal( chint32 lVertex,
											   chint32 lFace, chint32 lPart )
{
	if ( lPart == 0 )
	{
		lVertex = lVertex >> 2 ;
		if ( lVertex == 0 )
			return m_pVertexNormals[lFace] ;
		else
			return m_pVertexNormals[(lFace+1)%m_pSubDivision] ;
	}
	else if ( lPart == 1 )
		return m_pBaseNormals[0] ;
	else
		return m_pBaseNormals[1] ;
}

#ifdef MY_NOTYET

//
// I have not yet decided upon the tessellation scheme for the sphere.
// However it will have one part and f(subdiv) faces and g(subdiv) vertices.
//
ChQvSphereNormals::ChQvSphereNormals( QvSphere* sphere, QvState* state )
{
}

ChQvSphereNormals::~ChQvSphereNormals()
{
}

chint32 ChQvSphereNormals::GetNumParts()
{
}

chint32 ChQvSphereNormals::GetNumFaces( chint32 lPart )
{
}

chint32 ChQvSphereNormals::GetNumVertices( chint32 lFace, chint32 lPart )
{
}

GxVec3f ChQvSphereNormals::GetPartNormal( chint32 lPart )
{
}

GxVec3f ChQvSphereNormals::GetFaceNormal( chint32 lFace, chint32 lPart )
{
}

GxVec3f ChQvSphereNormals::GetVertexNormal( chint32 lVertex,
											 chint32 lFace, chint32 lPart )
{
}

#endif

bool ChQvIndexedFaceSetNormals::Set( QvIndexedFaceSet* ifs )
{
   if ( !ifs ) return false ;

   Destroy() ;
   m_pIFS = ifs ;

   // find how many faces we have, currently we do not need this
   // however if we change the logic for default normal generation
   // we will need the number of faces to make sure we have enough
   // normals for PER_FACE and PER_FACE_INDEXED bindings
   int numCoordIndices = ifs->coordIndex.num ;
   long* coordIndices = ifs->coordIndex.values ;
   for( int i = 0 ; i < numCoordIndices ; i++ )
   {
      if ( coordIndices[i] == -1 )
	 continue ;
      if ( i < numCoordIndices-1 && coordIndices[i+1] == -1 ) m_numFaces++ ;
   }

   return true ;
}

bool ChQvIndexedFaceSetNormals::Set( QvState* state )
{
	if ( !m_pIFS || !state ) return false ;

	m_pState = state ;

	// Get the necessary elements
	QvNormalBinding* nbelt =	0;
	if(state->getTopElement(QvState::NormalBindingIndex))
	{
		nbelt = ( (QvNormalBinding*)
			(state->getTopElement(QvState::NormalBindingIndex)->data) );
	}

	QvCoordinate3* c3elt = 0;
	if(state->getTopElement(QvState::Coordinate3Index))
	{
		c3elt =   ( (QvCoordinate3*)
			(state->getTopElement(QvState::Coordinate3Index)->data) ) ;
	}

	QvNormal* n3elt = 0;
	if(state->getTopElement(QvState::NormalIndex))
	{
		n3elt =  ( (QvNormal*)
			(state->getTopElement(QvState::NormalIndex)->data) ) ;
	}

	// Pull the information from the elements
	QvNormalBinding::Binding nbinding = QvNormalBinding::DEFAULT ;
	if ( nbelt ) nbinding = (QvNormalBinding::Binding) (nbelt->value.value) ;
	float* normalList = ( n3elt ? n3elt->vector.values : 0 ) ;
	float* coordList = ( c3elt ? c3elt->point.values : 0 ) ;

	// We really can't do without coordinates
	if ( !c3elt || !coordList ) return false ;

	//
	// Decide if we need to generate/use default normals (see Mentor p132)
	//
	//if ( !normalList || n3elt->vector.num != c3elt->point.num )
	if ( !normalList || m_pIFS->coordIndex.num > m_pIFS->normalIndex.num )
		nbinding = QvNormalBinding::DEFAULT ;

	long* normalIndex = m_pIFS->normalIndex.values ;

	switch( nbinding )
	{

		case QvNormalBinding::NONE:
			break ;

		case QvNormalBinding::DEFAULT:
		case QvNormalBinding::OVERALL:
		case QvNormalBinding::PER_PART:
		case QvNormalBinding::PER_PART_INDEXED:
			m_default = true ;
			break ;

		case QvNormalBinding::PER_FACE_INDEXED:
			if ( normalIndex )
				m_indexed = true ;	 
		case QvNormalBinding::PER_FACE:
			m_perFace = true ;
			break ;
		
		case QvNormalBinding::PER_VERTEX_INDEXED:
			if ( normalIndex && normalIndex[0] != -1 )
				m_indexed = true ;
		case QvNormalBinding::PER_VERTEX:
			m_perVertex = true ;
			break ;
	}

   if ( m_indexed ) m_pIndices = normalIndex ;
   if ( m_perFace || m_perVertex ) m_pNormals = (GxVec3f*)normalList ;

   // Generate default normals if necessary
   if ( m_default && !m_pDefaultNormals )
   {
   	  QvElement *pElt =  state->getTopElement(QvState::ShapeHintsIndex);

      QvShapeHints	defaultHints;	  
      QvShapeHints* shelt = &defaultHints;
	  if(pElt)
	  {
	  	shelt =  ( (QvShapeHints*)(pElt->data) ) ;
	  }
	  
	
      float creaseAngle = ( shelt ? shelt->creaseAngle.value : 0 ) ;

      int numNormals ;
      float* normals ;
      chuint32* pFlags ;
      if ( GxGenIFSNormals( c3elt->point.num, coordList,
			    m_pIFS->coordIndex.num, m_pIFS->coordIndex.values,
			    creaseAngle, numNormals, normals, &pFlags ) )
      {
	 m_numDefaultNormals = numNormals ;
	 m_pDefaultNormals = (GxVec3f*) normals ;
	 m_pFlags = pFlags;
      }
      else
      {
	 m_default = false ;
	 return false ;
      }
   }

   if ( m_default ) m_pNormals = m_pDefaultNormals ;

   return true ;
}

#endif	// !defined( _CHQVNORMALMAP_CPP )

// Local Variables: ***
// tab-width:4 ***
// End: ***
