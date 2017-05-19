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

	This file contains the interface for ChQvNormalMap class and its derived
	classes, these are used to compute the normals for various Qv shape nodes.

	ChQvNormalMap				- Abstract base class of various normal maps
	ChQvCubeNormals				- Computes the normals of a cube
	ChQvConeNormals				- Computes the normals of a cone
	ChQvCylinderNormals			- Computes the normals of a cylinder
	ChQvSphereNormals			- Computes the normals of a sphere
	ChQvIndexedFaceSetNormals	- Computes the normals of an indexed face set

----------------------------------------------------------------------------*/

#if !defined( _CHQVNORMALMAP_H )
#define _CHQVNORMALMAP_H

#include "GxTypes.h"
//
// For the time being use 3dr data types, we can normalize later
//
//typedef int chint32 ;
#if defined(CH_USE_3DR)
#if !defined(_3DG_H_)
typedef float Float_t ;

typedef struct {
	Float_t x, y, z ;
} PointF_t ;
#endif
#endif


class ChQvNormalMap
{
	public:
		virtual ~ChQvNormalMap() {}

		virtual chint32   GetNumParts() = 0 ;

		virtual chint32   GetNumFaces( chint32 lPart = 0 ) = 0 ;

		virtual chint32   GetNumVertices( chint32 lFace = 0,
										  chint32 lPart = 0 ) = 0 ;


		virtual GxVec3f  GetPartNormal( chint32 lPart ) = 0 ;

		virtual GxVec3f  GetFaceNormal( chint32 lFace,
										 chint32 lPart = 0 ) = 0 ;

		virtual GxVec3f  GetVertexNormal( chint32 lVertex, chint32 lFace = 0,
										   chint32 lPart = 0 )  = 0 ;
} ;

class QvState ;
class QvCube ;
class QvCone ;
class QvCylinder ;
class QvSphere ;
class QvIndexedFaceSet ;

//
// A QvCube has 1 part, 6 faces and 8 vertices. Note that GetPartNormal
// and GetVertexNormal do not make much sense for a cube. GetPartNormal
// simply returns the normal of the first face. GetVertexNormal will
// always return a face normal of the face specified. It does not check
// to make sure that the vertex indeed belongs to the face.
//
class ChQvCubeNormals : public ChQvNormalMap
{
	public:
		ChQvCubeNormals( QvCube* cube, QvState* state ) ;
		virtual ~ChQvCubeNormals() ;

		virtual chint32   GetNumParts() ;

		virtual chint32   GetNumFaces( chint32 lPart = 0 ) ;

		virtual chint32   GetNumVertices( chint32 lFace = 0,
										  chint32 lPart = 0 ) ;


		virtual GxVec3f  GetPartNormal( chint32 lPart ) ;

		virtual GxVec3f  GetFaceNormal( chint32 lFace, chint32 lPart = 0 ) ;

		virtual GxVec3f  GetVertexNormal( chint32 lVertex, chint32 lFace = 0,
										   chint32 lPart = 0 )  ;

	protected:
		//
		// Six normals for six faces, we need only keep one static table
		//
		static GxVec3f m_pNormals[6] ;
} ;

//
// A QvCone has two parts the - the cone itself and the base. The cone is
// subdivided into subdiv faces. The cone part has subdiv faces and
// subdiv+1 vertices. The base is also subdivided accordingly and has
// equal number of faces and vertices. The minimum value for subdiv is 3.
// However the normals along the subdivided faces of the base point along
// the same direction so we maintain only one base normal.
//
class ChQvConeNormals : public ChQvNormalMap
{
	public:
		ChQvConeNormals( QvCone* cone, QvState* state, chint32 subdiv ) ;
		virtual ~ChQvConeNormals() ;

		virtual chint32   GetNumParts() ;

		virtual chint32   GetNumFaces( chint32 lPart = 0 ) ;

		virtual chint32   GetNumVertices( chint32 lFace = 0,
										  chint32 lPart = 0 ) ;


		virtual GxVec3f  GetPartNormal( chint32 lPart ) ;

		virtual GxVec3f  GetFaceNormal( chint32 lFace, chint32 lPart = 0 ) ;

		virtual GxVec3f  GetVertexNormal( chint32 lVertex, chint32 lFace = 0,
										   chint32 lPart = 0 )  ;

	protected:
		static GxVec3f m_pBaseNormal ;
		chint32			m_pSubDivision ;
		GxVec3f*		m_pFaceNormals ;
		GxVec3f*		m_pVertexNormals ;
} ;

//
// A QvCylinder has two parts the - the cylinder itself and two bases.
// Each part is subdivided into subdiv faces. The cylinder part has
// 2*subdiv vertices whereas each base has subdiv+1 vertices. The
// subdivision is performed radially.The minimum value for subdiv is 4.
// Similar to the cone above all the faces of a base have only one normal.
//
class ChQvCylinderNormals : public ChQvNormalMap
{
	public:
		ChQvCylinderNormals( QvCylinder* cylinder, QvState* state, chint32 subdiv ) ;
		virtual ~ChQvCylinderNormals() ;

		virtual chint32   GetNumParts() ;

		virtual chint32   GetNumFaces( chint32 lPart = 0 ) ;

		virtual chint32   GetNumVertices( chint32 lFace = 0,
										  chint32 lPart = 0 ) ;


		virtual GxVec3f  GetPartNormal( chint32 lPart ) ;

		virtual GxVec3f  GetFaceNormal( chint32 lFace, chint32 lPart = 0 ) ;

		virtual GxVec3f  GetVertexNormal( chint32 lVertex, chint32 lFace = 0,
										   chint32 lPart = 0 )  ;

	protected:
		static GxVec3f	m_pBaseNormals[2] ;
		chint32			m_pSubDivision ;
		GxVec3f*		m_pFaceNormals ;
		GxVec3f*		m_pVertexNormals ;
} ;


#ifdef MY_NOTYET

//
// I have not yet decided upon the tessellation scheme for the sphere.
// However it will have one part and f(subdiv) faces and g(subdiv) vertices.
//
class ChQvSphereNormals : public ChQvNormalMap
{
	public:
		ChQvSphereNormals( QvSphere* sphere, QvState* state ) ;
		virtual ~ChQvSphereNormals() ;

		virtual chint32   GetNumParts() ;

		virtual chint32   GetNumFaces( chint32 lPart = 0 ) ;

		virtual chint32   GetNumVertices( chint32 lFace = 0,
										  chint32 lPart = 0 ) ;


		virtual GxVec3f  GetPartNormal( chint32 lPart ) ;

		virtual GxVec3f  GetFaceNormal( chint32 lFace, chint32 lPart = 0 ) ;

		virtual GxVec3f  GetVertexNormal( chint32 lVertex, chint32 lFace = 0,
										   chint32 lPart = 0 )  ;

	protected:
		chint32   m_NumSphereNormals ;
		GxVec3f* m_SphereNormals ;
} ;

#endif

//
// The normal helper classes do not gain anything by having a common
// base. At least IFS normals is an altogether different beast. This
// is constructed with an IFS and a state and is expected to be cached.
// The IFS and state can be set independantly. This allows the same
// instance to handle varying traversal states from one to traversal
// to another, and default normals are computed only once. However if the
// IFS itself changes, then it may be set once again, destroying the
// computed normals.
//
// The usage is also a little complicated, it provides three queries,
// isPerFace?, isPerVertex? and isDefault, there are corresponding methods
// which must be used for getting the normal. For example if isPerFace
// returns true, then GetFaceNormal should be used once per face with the
// current face number as the input argument. This seperation of the various
// Get*Normal methods is necessary to maintain a balance between flexibility
// and runtime efficiency.
//
class ChQvIndexedFaceSetNormals
{
   public:
	  inline ChQvIndexedFaceSetNormals( QvIndexedFaceSet* ifs, QvState* state )
	  {
		 Init() ;
		 Set( ifs ) ;
		 Set( state ) ;
	  }

	  // Non-virtual destructor, change if deriving subclasses
	  inline ~ChQvIndexedFaceSetNormals() { Destroy() ; }

	  bool Set( QvIndexedFaceSet* ifs ) ;
	  bool Set( QvState* state ) ;

	  inline bool IsPerFace() const { return m_perFace ; }
	  inline bool IsPerVertex() const { return m_perVertex ; }
	  inline bool IsDefault() const { return m_default ; }

	  inline bool GetFaceNormal( chint32 lFace,  GxVec3f& normal ) const
	  {
		 if ( !m_perFace ) return false ;
		 else
		 {
			long inx = ( m_indexed ? m_pIndices[lFace] : lFace ) ;
			normal = m_pNormals[inx] ;
			return true ;
		 }
	  }

	  inline bool GetVertexNormal( chint32 lVertex, GxVec3f& normal ) const
	  {
		 if ( !m_perVertex ) return false ;
		 {
			long inx = ( m_indexed ? m_pIndices[lVertex] : lVertex ) ;
			normal = m_pNormals[inx] ;
			return true ;
		 }
	  };

	  inline bool GetDefaultNormal( chint32 lIndex, chint32 lFace,
									GxVec3f& normal ) const
		{
			chuint32 flag;
			return GetDefaultNormal(lIndex, lFace, normal, flag);
		};

	  inline bool GetDefaultNormal( chint32 lIndex, chint32 lFace,
									GxVec3f& normal, chuint32& flag ) const
	  {
		 if ( !m_default ) return false ;
		 else
		 {
			normal = m_pNormals[lIndex-lFace] ;
			flag = m_pFlags[lIndex-lFace];
			return true ;
		 }
	  };

   private:
	  QvIndexedFaceSet* m_pIFS ;
	  QvState*          m_pState ;

	  bool              m_indexed ;
	  long*             m_pIndices ;
	  GxVec3f*         m_pNormals ;

	  bool              m_perVertex ;
	  bool              m_perFace ;
	  bool              m_default ;

	  chint32           m_numFaces ;
	  chint32           m_numDefaultNormals ;
	  GxVec3f*         m_pDefaultNormals ;
	  chuint32*			m_pFlags;

	  inline void Init()
	  {
		 m_pIFS = 0 ; m_pState = 0 ;
		 m_indexed = false ; m_pIndices = 0 ; m_pNormals = 0 ;
		 m_perFace = m_perVertex = m_default = false ;
		 m_numFaces = 0 ;
		 m_numDefaultNormals = 0 ; m_pDefaultNormals = 0 ;
		 m_pFlags = 0;
	  }

	  inline void Destroy()
	  {
		 m_pIFS = 0 ; m_pState = 0 ;
		 m_indexed = false ; m_pIndices = 0 ; m_pNormals = 0 ;
		 m_perFace = m_perVertex = m_default = false ;
		 m_numFaces = 0 ;
		 m_numDefaultNormals = 0 ;
		 delete[] m_pDefaultNormals ; m_pDefaultNormals = 0 ;
		 delete[] m_pFlags ; m_pFlags = 0 ;
	  }		 
} ;

#endif	// !defined( _CHQVNORMALMAP_H )

// Local Variables: ***
// tab-width:4 ***
// End: ***
