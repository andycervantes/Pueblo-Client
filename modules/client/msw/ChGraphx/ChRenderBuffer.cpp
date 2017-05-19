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

	Implementation for the ChRenderBuffer class for immediate mode renderers.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChRenderBuffer.cpp,v 2.1 1996/06/27 03:43:33 jimd Exp $

#include "grheader.h"

#include "CvInstnc.h"
#include "ChRenderData.h"
//#include "CvTrnsfm.h"
//#include "CvNormal.h"
//#include "CvMaterl.h"
//#include "CvTextur.h"
//#include "GxSphere.h"
//#include "ChSphere.h"
//#include <ChTriangle.h>
#include "ChRenderBuffer.h"


bool ChRenderBuffer::Create(int numVerts, int numTris)
{
	
	#if defined(CH_USE_RLAB) && defined(CH_IMMED_MODE)
	m_pVerts		= new RLIMLightingPoint[numVerts];
	m_pViewVerts	= new RLIMViewVertex[numVerts];
	m_pTris			= new RLIMTriangle[numTris];
	m_pMaterial 	= new RLIMSurfaceInfo;

	m_numTriangles = numTris;
	m_numVerts = numVerts;
	#endif

	return true;
}

bool ChRenderBuffer::Render(ChQvInstance *pInst, ChRenderContext *pRC)
{
	return true;
}

bool ChRenderBuffer::Transform(ChQvInstance *pInst, ChRenderContext *pRC)
{
	return true;
}

bool ChRenderBuffer::Light(ChQvInstance *pInst, ChRenderContext *pRC)
{
	return true;
}

bool ChRenderBuffer::Rasterize(ChQvInstance *pInst, ChRenderContext *pRC, ChShadingLevel quality, chuint32 uFlags)
{
#if (defined(CH_IMMED_MODE))
    if(!m_numTriangles) return false;
    RLIMRenderQuality rlQual;

	switch(quality)
	{
		case defaultShading:
		case smoothShading:
		case invalidShadingLevel:
		{
			rlQual = RLIM_SMOOTH_QUALITY;
			break;
		}
		case flatShading:
		{
			rlQual = RLIM_FLAT_QUALITY;
			break;
		}
		case noShading:
		{
			rlQual = RLIM_UNLIT_QUALITY;
			break;
		}
		case wireFrame:
		{
			rlQual = RLIM_WIRE_QUALITY;
			break;
		}
	}

    RLIMDrawTriangles
    (   pRC->GetViewport(),
        GetTriangles(),
        sizeof(RLIMTriangle),
        m_numTriangles,
        rlQual,	 // oughta check the RC for this, really
        uFlags
    );
#endif
	return true;
}



