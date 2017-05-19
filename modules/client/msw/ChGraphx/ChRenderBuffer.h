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

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChRenderBuffer.h,v 2.1 1996/06/27 03:43:35 jimd Exp $
//
#if !defined( _CHRENDERBUFFER_H )
#define _CHRENDERBUFFER_H

#include "QvNode.h"
#ifdef HUGE
#undef HUGE
#endif

#include "GxSphere.h"

#include "ChRender.h"
#include "ChRenderData.h"

#if defined(CH_IMMED_MODE)
#include "imode.h"
#endif




/*----------------------------------------------------------------------------
	ChRenderBuffer class - a chunk of renderer specific data associated with
	a particular instance or renderdata. Contains cached vertices and triangles,
	usually.
----------------------------------------------------------------------------*/

class ChRenderBuffer
{

	protected:
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) && defined(CH_IMMED_MODE)
	int m_numVerts;
	int m_numTriangles;
	RLIMLightingPoint	*m_pVerts;
	RLIMViewVertex		*m_pViewVerts;
	RLIMTriangle		*m_pTris;
	RLIMSurfaceInfo		*m_pMaterial;
	#endif

	public:
		ChRenderBuffer()
			#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) && defined(CH_IMMED_MODE)
				 :
				m_pVerts(0), m_pViewVerts(0), m_pTris(0), m_pMaterial(0), 
				m_numVerts(0), m_numTriangles(0) 
			#endif
			{
			};
		virtual ~ChRenderBuffer()
		{
			#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) && defined(CH_IMMED_MODE)
			delete [] m_pVerts;
			delete [] m_pViewVerts;
			delete [] m_pTris;
			delete m_pMaterial;
			m_pVerts = 0;
			m_pViewVerts = 0;
			m_pTris = 0;
			m_pMaterial = 0;
			m_numVerts = 0;
			m_numTriangles = 0;
			#endif
		};

		bool Create(int numVerts, int numTris);

		bool Render(ChQvInstance *pInst, ChRenderContext *pRC);
		virtual bool Transform(ChQvInstance *pInst, ChRenderContext *pRC);
		virtual bool Light(ChQvInstance *pInst, ChRenderContext *pRC);
		virtual bool Rasterize(ChQvInstance *pInst, ChRenderContext *pRC, ChShadingLevel quality, chuint32 uFlags);

		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) && defined(CH_IMMED_MODE)
		RLIMLightingPoint	*GetVerts() {return m_pVerts; };
		RLIMViewVertex		*GetTransformedVerts() {return m_pViewVerts;};
		RLIMTriangle		*GetTriangles() {return m_pTris;};
		RLIMSurfaceInfo		*GetMaterial() {return m_pMaterial;};
		inline int GetVertexCount() { return m_numVerts; };
		inline int GetTriangleCount() { return m_numTriangles; };
		#endif

};



#endif // _CHSPHERE_H
