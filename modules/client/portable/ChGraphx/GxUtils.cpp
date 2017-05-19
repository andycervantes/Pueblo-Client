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

#ifndef _GX_UTILS_C_
#define _GX_UTILS_C_

#include "GxTypes.h"
#include "GxUtils.h"


//
// This is a function rather than a class because the generation of
// default IFS normals does not really fit well into the iterator model.
// Note that the usage with Qv is straight forward. numVerts and vertices
// can be pulled directly from the "point" member of QvCoordinate3 node,
// numCoords and coords come from "coordIndex" member of QvIndexedFaceSet
// and the creaseAngle is from QvShapeHints. If successful an array of
// numNormals is returned in normals, it is the users responsibility to
// delete this array. The size of the array is 3*numNormals*sizeof(float).
//
// If ppFlags, is not null, it receives a pointer to an array of flags
// describing how many face normals went into each vertex normal,
// which may be useful in reusing normal values. The possible bit-mask
// values are:
// GX_NORMAL_FACE		- this is a face normal, no other faces contributed
// GX_NORMAL_ALL_FACES 	- all the adjoining faces contributed to the normal.
//						hence, all such normals for the same coordinate
//						will be identical.
int GxGenIFSNormals( int numVerts, const float* vertices,
		     int numCoords, const long* coords,
		     float creaseAngle,
		     int& numNormals, float*& normals, unsigned long ** ppFlags)
{
   if ( numVerts <= 0 || !vertices || numCoords <= 0 || !coords ) return 0 ;

   int i ;

   // cast the float array to a GxVec3f array
   // WARNING: beware of double word alignment,
   // should not be an issue on X86 platforms
   GxVec3f* verts = (GxVec3f*) vertices ;

   // First find how many faces we have
   int numFaces = 0 ;
   for( i = 0 ; i < numCoords ; i++ )
   {
      if ( coords[i] == -1 )
	 continue ;								  
	 					 // jwd added test for last coord here in case of unterminated
      if ( (i == numCoords - 1) || i < numCoords-1 && coords[i+1] == -1 ) numFaces++ ;
   }
   if(numFaces == 0 && numVerts > 2) numFaces = 1;

   // Allocate an array for face normals
   GxVec3f* faceNormals = new GxVec3f[numFaces] ;
   if ( !faceNormals ) return 0 ;

   // Allocate an array for face counts and clear it
   int* faceCounts = new int[numVerts] ;
   if ( !faceCounts )
   {
      delete[] faceNormals ;
      return 0 ;
   }

   for ( i = 0 ; i < numVerts ; i++ )
      faceCounts[i] = 0 ;

   // Compute the face normals and face counts
	int faceNum = 0 ;
	i = 0 ;
	while ( i < numCoords )
	{
		if ( coords[i] == -1 )
		{
			i++ ;
			continue ;
		}

		GxVec3f fn( 0, 0, 0 ) ;

		int first = i ;
		while ( i + 1 < numCoords && coords[i+1] != -1 )   // be careful of unterminated ones!
		{
			fn += verts[coords[i]].cross( verts[coords[i+1]] ) ;
			faceCounts[coords[i+1]]++ ;
			i++ ;
		}
		fn += verts[coords[i]].cross( verts[coords[first]] ) ;
		faceCounts[coords[first]]++ ;
		i++ ;

		fn.normalize() ;
		faceNormals[faceNum++] = fn ;
	}

   // Allocate an array for cumulative indices
   int* cumIndex = new int[numVerts+1] ;
   if ( !cumIndex )
   {
      delete[] faceNormals ; delete[] faceCounts ;
      return 0 ;
   }

   // set up the cumulative index and compute the size for the
   // expanded face normals array. This array maintains all the
   // face normals at a given vertex contiguously, facilitating
   // the normal generation phase which follows. The cumulative
   // index is used for providing random access into this array.
   cumIndex[0] = 0 ;
   int numExpFaceNormals = faceCounts[0] ;
   for ( i = 1 ; i < numVerts ; i++ )
   {
      numExpFaceNormals += faceCounts[i] ;
      cumIndex[i] = cumIndex[i-1] + faceCounts[i-1] ;
   }
   cumIndex[i] = cumIndex[i-1] + faceCounts[i-1] ;

   // we will be reusing the faceCount array so clear it here.
   for ( i = 0 ; i < numVerts ; i++ )
      faceCounts[i] = 0 ;

   // Allocate the expanded face normals array
   int* expFaceNormals = new int[numExpFaceNormals] ;
   if ( !expFaceNormals )
   {
      delete[] faceNormals ; delete[] faceCounts ; delete[] cumIndex ;
      return 0 ;
   }

   // Fill up the expanded face normals array
   for ( i = 0, faceNum = 0 ; i < numCoords ; i++ )
   {
      if ( coords[i] == -1 )
	 continue ;

      expFaceNormals[ cumIndex[coords[i]]+faceCounts[coords[i]]++ ] = faceNum ;
      if ( i < numCoords-1 && coords[i+1] == -1 ) faceNum++ ;
   }

   // The final pass, we generate the normals now

   float cosCrease = cos( creaseAngle ) ;

	// Allocate space for the normals
	GxVec3f* theNormals = new GxVec3f[numExpFaceNormals] ;
	unsigned long* pFlags = new unsigned long[numExpFaceNormals] ;
	if ( !theNormals )
	{
		// my kingdom for exceptions
		delete[] faceNormals ; delete[] faceCounts ; delete[] cumIndex ;
		delete[] expFaceNormals ;
		return 0 ;
	}

	int theNormal = 0 ;
	for ( i = 0, faceNum = 0 ; i < numCoords ; i++ )
	{
		if ( coords[i] == -1 ) continue ;

		GxVec3f vn( 0, 0, 0 ) ;
		GxVec3f& faceNormal = faceNormals[faceNum] ;

		// Disable crease angle check for degenerate face normals
		int isDegenerate = faceNormal.magnitude() < 1e-2 ;
		int count = 0;		// contributor count
		for ( int j = cumIndex[coords[i]] ; j < cumIndex[coords[i]+1] ; j++ )
		{
			#if defined(_DEBUG)
			// To make it easy to look at in debugging
			GxVec3f tmp = faceNormals[expFaceNormals[j]] ;
			float cosA = faceNormal.dot( faceNormals[expFaceNormals[j]] );
			#endif
			//if ( isDegenerate || j == faceNum ||
			if ( isDegenerate || expFaceNormals[j] == faceNum ||	// jwd 12/28/95
			  faceNormal.dot( faceNormals[expFaceNormals[j]] ) > cosCrease )
			{
				vn += faceNormals[expFaceNormals[j]] ;
				count++;
			}
		}

		if(count == 1)
		{
			pFlags[theNormal] = GX_NORMAL_FACE;
		}
		else if(count == cumIndex[coords[i]+1] - cumIndex[coords[i]])
		{
			pFlags[theNormal] = GX_NORMAL_ALL_FACES;
		}
		else
		{
			pFlags[theNormal] = 0;
		}
		vn.normalize() ;
		theNormals[theNormal++] = vn ;
		if ( i < numCoords-1 && coords[i+1] == -1 ) faceNum++ ;
	}

   numNormals = numExpFaceNormals ;
   
   // WARNING: will not work for double word alignment
   normals = (float*) theNormals ;

   if(ppFlags) *ppFlags = pFlags;
   else delete [] pFlags;

   // Clean up the mess
   delete[] faceNormals ;
   delete[] faceCounts ;
   delete[] cumIndex ;
   delete[] expFaceNormals ;

   return 1 ;
}




#endif // _GX_UTILS_C_
