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
							   
	Declaration for the  ChQvSphereRenderData classes and derivations, 
	which are used to store renderer specific data for 3d graphics renderers for contexts
	and in QvNodes. 

----------------------------------------------------------------------------*/

#include "grheader.h"

#include "ChSphere.h"


// Helper classes
int ChQvSphereCacheData::mySphereTriangleIterator::DoTriangle( int iTri, int iv0, int iv1, int iv2 )
{
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) && defined(CH_IMMED_MODE)
	ASSERT(m_numTris > iTri);
	m_pTris[iTri].v[0] = (RLIMViewVertex*)(m_pVerts + iv0);
	m_pTris[iTri].v[1] = (RLIMViewVertex*)(m_pVerts + iv1);
	m_pTris[iTri].v[2] = (RLIMViewVertex*)(m_pVerts + iv2);

	if(iTri < m_numTris - 1) m_pTris[iTri].next = m_pTris + 1;
	else m_pTris[iTri].next = 0;
	#endif

	return 1;
}

/*----------------------------------------------------------------------------
	ChQvSphereRenderData class
----------------------------------------------------------------------------*/

ChQvSphereCacheData::ChQvSphereCacheData(int level /*= 8*/) : 
	m_Sphere(level), m_pTex(0)
{
	// Allocate and fill in the texture array
	myTexIter	txIter;
	txIter.Attach(m_Sphere);
	
	int numTextures = txIter.NumTextures();
	m_pTex = new GxVec2f[numTextures];
	txIter.m_pTex = m_pTex;
	txIter.Iterate();

	myVertIter	vertIter;
	vertIter.Attach(m_Sphere);
	
	m_numVerts = vertIter.NumVertices();
	m_pVerts = new GxVec3f[vertIter.NumVertices()];
	vertIter.m_pVerts = m_pVerts;
	vertIter.Iterate();
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) && defined(CH_IMMED_MODE)
	// Make space in the renderer buffer
	int iTris = (((level - 1) * level) * 2 + level) * 8;
	m_buffer.Create(m_Sphere.NumVerts() * 8, iTris );

	// Now initialize the triangles
	mySphereTriangleIterator triIter;
	triIter.Attach(m_Sphere);
	triIter.m_pTris = m_buffer.GetTriangles();
	triIter.m_numTris = iTris;
	triIter.m_pVerts = m_buffer.GetTransformedVerts(); //m_pVerts;
	triIter.Iterate(GxSphere::Indexed);

	// Now copy int the texture coords. If nobody uses funny transforms on this,
	// that's sufficient forever.
	RLIMViewVertex		*pVerts = m_buffer.GetTransformedVerts();
	for(int j= 0; j < numTextures; j++)
	{
		pVerts[j].tu = m_pTex[j].u();
		pVerts[j].tv = 1. - m_pTex[j].v();
	}

	 // Normals are same for every instance, so do once, and forget!!!!!
	RLIMLightingPoint *pLightVerts =  m_buffer.GetVerts();
	for(j= 0; j < m_numVerts; j++)
	{
		pLightVerts[j].normal = *((RLIMDirectionVector*)(m_pVerts + j)); 
	}
	#endif
};



