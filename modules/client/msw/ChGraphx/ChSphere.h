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

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChSphere.h,v 2.4 1996/06/27 03:43:51 jimd Exp $
//
#if !defined( _CHSPHERE_H )
#define _CHSPHERE_H

#include "QvNode.h"
#ifdef HUGE
#undef HUGE
#endif


#include "GxSphere.h"

#include "ChRender.h"
#include "ChRenderData.h"
#include "ChRenderBuffer.h"

#include <QvSphere.h>

class QvSphere;


/*----------------------------------------------------------------------------
	ChQvSphereRenderData class
----------------------------------------------------------------------------*/

class ChQvSphereRenderData : public ChQvRenderBaseData
{

	protected:

	public:
		ChQvSphereRenderData(QvSphere *pNode) : 
			ChQvRenderBaseData(pNode)
			{
			};
		virtual ~ChQvSphereRenderData() {};


};

class ChSphereRenderBuffer : public ChRenderBuffer
{
	public:
		ChSphereRenderBuffer() { };
		virtual ~ChSphereRenderBuffer() { };

};

class ChQvSphereCacheData
{	   

	protected:
		GxSphere	m_Sphere;
		GxVec2f		*m_pTex;
		GxVec3f		*m_pVerts;
		int			m_numVerts;
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) && defined(CH_IMMED_MODE)
		ChSphereRenderBuffer	m_buffer;
		#endif

		class myTexIter : public GxSphereTextureIterator
		{
			public:

				int DoTexture( int vnum, const GxVec2f& tex )
				{
					m_pTex[vnum] = tex;
					return 1 ;
				}
				GxVec2f		*m_pTex;
		} ;

		class myVertIter : public GxSphereVertexIterator
		{
			public:

				int DoVertex( int vnum, const GxVec3f& vert )
				{
					m_pVerts[vnum] = vert;
					return 1 ;
				}
				GxVec3f		*m_pVerts;
		} ;

		class mySphereTriangleIterator : public GxSphereTriangleIterator
		{
			public:
				mySphereTriangleIterator() : GxSphereTriangleIterator()
					#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) && defined(CH_IMMED_MODE)
						,m_pTris(0), m_numTris(0), m_pVerts(0)
					#endif
					 {};
				mySphereTriangleIterator( const GxSphere& sph ) : GxSphereTriangleIterator(sph) {};

				virtual mySphereTriangleIterator::~mySphereTriangleIterator() {};

				virtual int DoTriangle( int tri, int iv1, int iv2, int iv3 );

				#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) && defined(CH_IMMED_MODE)
					RLIMTriangle		*m_pTris;
					int					m_numTris;
					RLIMViewVertex		*m_pVerts;
				#endif

			private:
											/* Disable copy constructor and
												assignment operator */

				inline mySphereTriangleIterator( const mySphereTriangleIterator& ) {}
				inline mySphereTriangleIterator& operator=( const mySphereTriangleIterator& )
					{
						return *this;
					}
		};


	public:
		ChQvSphereCacheData(int level = 8);
		virtual ~ChQvSphereCacheData() { delete [] m_pTex; delete [] m_pVerts;};

		inline GxVec2f *GetTextureCoord() { return m_pTex; };
		inline GxSphere *GetSphere() { return &m_Sphere; };
 		inline GxVec3f* GetVertices() {return m_pVerts; };
		inline int GetVertexCount() { return m_numVerts; };

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) && defined(CH_IMMED_MODE)
		ChRenderBuffer * GetBuffer() { return &m_buffer;};
		#endif

};


#endif // _CHSPHERE_H
