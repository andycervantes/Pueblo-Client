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

	Implementation for the ChQvInstance class for  Intel 3DR.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvShapes.cpp,v 2.50 1996/10/08 02:04:06 jimd Exp $

#include "grheader.h"

#include "CvInstnc.h"
#include <QvInfo.h>
#include <QvState.h>
#include "ChMaze.h"
#include "ChRenderData.h"
#include "ChMazDep.h"
#include "CvTrnsfm.h"
#include "CvNormal.h"
#include "CvBound.h"
#include "CvMaterl.h"
#include "CvTextur.h"
#include "GxSphere.h"
#include "ChSphere.h"
#include <ChTriangle.h>
#include "ChRenderBuffer.h"

#if defined(CH_IMMED_MODE)
#include "imode.h"
#endif

//#define FLIP_D3D_NORMALS	1

#define CH_SPHERE_LOD	1

// Binary transparency only for now
static bool IsTransparent(float transparency)
{	// 0 is opaque, 1 is totally transparent
	//return alpha <= 0.5;	
	return transparency >= 0.5;	
}

#if 0
inline int VertCount(long *values)
{
	int i = 0;
	while(values[i] != QV_END_FACE_INDEX) i++;
	return i;
}
#endif

inline int VertCount(long *values, int numPoints)
{
	int i = 0;
	while(i < numPoints && values[i] != QV_END_FACE_INDEX) i++;
	return i;
};

inline int VertCount(QvMFLong &coords, int start)
{
	return VertCount(coords.values + start, coords.num - start);
}

inline int GetFaceCount(long *values, int numPoints)
{
	int count = 0;
	for(int i = 0; i < numPoints ;i++)
	{
		if(values[i] == QV_END_FACE_INDEX || i == numPoints - 1) count++;
	}
	return count;
}


#if 0
bool ChQvInstance::ComputeBounds()
{
	// Every class needs to do their own. Maybe this should be pure virtual
	return false;
}

#endif

void ChQvInstanceHasProps::Init(ChQvBuildState *pState, ChQvInstance *pInstance)
{
	ChRenderContext *pRC = pState->GetView()->GetRenderContext();

	m_pMaterial =             (QvMaterial 			 *)(pRC->GetCurrentProperty(pState, QvState::MaterialIndex));   
	m_pMaterialBinding =      (QvMaterialBinding 	 *)(pRC->GetCurrentProperty(pState, QvState::MaterialBindingIndex));   
	m_pNormal =               (QvNormal 			 *)(pRC->GetCurrentProperty(pState, QvState::NormalIndex));   
	m_pNormalBinding =        (QvNormalBinding 	 *)(pRC->GetCurrentProperty(pState, QvState::NormalBindingIndex));   
	m_pCoordinate3 =          (QvCoordinate3 		 *)(pRC->GetCurrentProperty(pState, QvState::Coordinate3Index));   
	m_pTexture2 =             (QvTexture2 			 *)(pRC->GetCurrentProperty(pState, QvState::Texture2Index));   
	m_pTexture2Transform =    (QvTexture2Transform  *)(pRC->GetCurrentProperty(pState, QvState::Texture2TransformationIndex));   
	m_pTextureCoordinate2 =   (QvTextureCoordinate2 *)(pRC->GetCurrentProperty(pState, QvState::TextureCoordinate2Index));   
	m_pShapeHints =           (QvShapeHints 		 *)(pRC->GetCurrentProperty(pState, QvState::ShapeHintsIndex));   
	m_pInfo =           	  (QvInfo 				 *)(pRC->GetCurrentProperty(pState, QvState::InfoIndex));   
	m_pFontStyle =            (QvFontStyle 			 *)(pRC->GetCurrentProperty(pState, QvState::FontStyleIndex));   

	((ChQvRenderBaseData *)(m_pMaterial->GetRenderData()))->AddDependent(pInstance);             
	((ChQvRenderBaseData *)(m_pMaterialBinding->GetRenderData()))->AddDependent(pInstance);      
	((ChQvRenderBaseData *)(m_pNormal->GetRenderData()))->AddDependent(pInstance);               
	((ChQvRenderBaseData *)(m_pNormalBinding->GetRenderData()))->AddDependent(pInstance);        
	((ChQvRenderBaseData *)(m_pCoordinate3->GetRenderData()))->AddDependent(pInstance);          
	((ChQvRenderBaseData *)(m_pTexture2->GetRenderData()))->AddDependent(pInstance);             
	((ChQvRenderBaseData *)(m_pTexture2Transform->GetRenderData()))->AddDependent(pInstance);    
	((ChQvRenderBaseData *)(m_pTextureCoordinate2->GetRenderData()))->AddDependent(pInstance);   
	((ChQvRenderBaseData *)(m_pShapeHints->GetRenderData()))->AddDependent(pInstance);           
	((ChQvRenderBaseData *)(m_pInfo->GetRenderData()))->AddDependent(pInstance);           
	((ChQvRenderBaseData *)(m_pFontStyle->GetRenderData()))->AddDependent(pInstance);           

}

void ChQvInstanceHasProps::Term( ChQvInstance *pInstance)
{
	if(m_pMaterial) ((ChQvRenderBaseData *)(m_pMaterial->GetRenderData()))->RemoveDependent(pInstance);             
	if(m_pMaterialBinding) ((ChQvRenderBaseData *)(m_pMaterialBinding->GetRenderData()))->RemoveDependent(pInstance);      
	if(m_pNormal) ((ChQvRenderBaseData *)(m_pNormal->GetRenderData()))->RemoveDependent(pInstance);               
	if(m_pNormalBinding) ((ChQvRenderBaseData *)(m_pNormalBinding->GetRenderData()))->RemoveDependent(pInstance);        
	if(m_pCoordinate3) ((ChQvRenderBaseData *)(m_pCoordinate3->GetRenderData()))->RemoveDependent(pInstance);          
	if(m_pTexture2) ((ChQvRenderBaseData *)(m_pTexture2->GetRenderData()))->RemoveDependent(pInstance);             
	if(m_pTexture2Transform) ((ChQvRenderBaseData *)(m_pTexture2Transform->GetRenderData()))->RemoveDependent(pInstance);    
	if(m_pTextureCoordinate2) ((ChQvRenderBaseData *)(m_pTextureCoordinate2->GetRenderData()))->RemoveDependent(pInstance);   
	if(m_pShapeHints) ((ChQvRenderBaseData *)(m_pShapeHints->GetRenderData()))->RemoveDependent(pInstance);           
	if(m_pInfo) ((ChQvRenderBaseData *)(m_pInfo->GetRenderData()))->RemoveDependent(pInstance);           
	if(m_pFontStyle) ((ChQvRenderBaseData *)(m_pFontStyle->GetRenderData()))->RemoveDependent(pInstance);           
	m_pMaterial =             0;
	m_pMaterialBinding =      0;
	m_pNormal =               0;
	m_pNormalBinding =        0;
	m_pCoordinate3 =          0;
	m_pTexture2 =             0;
	m_pTexture2Transform =    0;
	m_pTextureCoordinate2 =   0;
	m_pShapeHints =           0;
	m_pInfo =           	  0;
	m_pFontStyle =            0;
}

void ChQvInstanceHasProps::RemoveProperty(ChQvRenderBaseData *pData)
{
	RemoveProperty(pData, (QvNode**)&m_pMaterial);
	RemoveProperty(pData, (QvNode**)&m_pMaterialBinding);
	RemoveProperty(pData, (QvNode**)&m_pNormal);
	RemoveProperty(pData, (QvNode**)&m_pNormalBinding);
	RemoveProperty(pData, (QvNode**)&m_pCoordinate3);
	RemoveProperty(pData, (QvNode**)&m_pTexture2);
	RemoveProperty(pData, (QvNode**)&m_pTexture2Transform);
	RemoveProperty(pData, (QvNode**)&m_pTextureCoordinate2);
	RemoveProperty(pData, (QvNode**)&m_pShapeHints);
	RemoveProperty(pData, (QvNode**)&m_pInfo);
	RemoveProperty(pData, (QvNode**)&m_pFontStyle);
}

void ChQvInstanceHasProps::RemoveProperty(ChQvRenderBaseData *pData, QvNode **ppNode)
{
	if(ppNode && *ppNode)
	{
		if(((ChQvRenderBaseData *)((*ppNode)->GetRenderData())) == pData) *ppNode = 0;          
	}
}

/////////// Shapes - first the shapeInstance abc

void ChQvShapeInstance::Init(ChQvBuildState *pState)
{
	ChQvInstance::Init(pState);
	ChQvInstanceHasProps::Init(pState, this);
	pState->AddShape();
}

ChQvShapeInstance::ChQvShapeInstance() : ChQvInstance()
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	, m_mesh(0)
	, m_boolTransformDirty(false)
#if defined(CH_IMMED_MODE)
	, m_hTexture(0)
#endif
#endif
{
}

ChQvShapeInstance::~ChQvShapeInstance()
{
	ChQvInstanceHasProps::Term(this);
#if defined(CH_IMMED_MODE)
	if(m_hTexture)
	{
		ChNrObjectDestroy(m_hTexture);
	}
	m_hTexture = 0;
#endif
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

#if (defined(CH_USE_RLAB))
void ShapeTransformCallback(ChNrFrame frame, void * arg)
#else
void ShapeTransformCallback(ChNrFrame frame, void * arg, float delta)
#endif
{
	#if 1 || defined(CH_VRML_EVENTS)
	ChQvShapeInstance *pInst = (ChQvShapeInstance *)arg;
	if(pInst->IsTransformDirty())
	{
		ChNrFrameAddTransform(frame, CombineReplace, *(pInst->GetTransform().GetMatrix()));
		ChQvBounds bounds;
		pInst->GetBounds(bounds);	// ??????????? force the bounds transform to update

		pInst->SetTransformDirty( false );
	}
	#endif
}

void ChQvShapeInstance::CreateFrame()
{
	ChQvInstance::CreateFrame();
	// Install callback for event processing on transforms
	#if 1 || defined(CH_VRML_EVENTS)
	ChNrFrameAddCallback(m_frame, ShapeTransformCallback, this);
	#endif
};

#endif
ChQvInstance* ChQvShapeInstance::SetTransformDirty(bool boolDirty)
{
	m_boolTransformDirty = boolDirty;
	if(boolDirty && GetRC()) GetRC()->SetDirty();
	return this;
};

bool ChQvShapeInstance::SetupTexture(ChRenderContext *pRC)
{	
				// This is for procedural renderers like 3dr, OGL and D3d
	bool boolUseTexture = false;
	ChQvTextureRenderData *pTextureData = 0;
	pTextureData = (ChQvTextureRenderData*)(GetTexture2()->GetRenderData());
	if (pTextureData->GetTextureHandle()) boolUseTexture = true;
	 
	if(boolUseTexture)
	{
		pRC->SetTexture(pTextureData->GetTextureHandle());
	}
	else
	{
		pRC->SetTexture(0);
	}
	return boolUseTexture;
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
bool ChQvShapeInstance::SetTexture(ChQvTextureRenderData *pTextureData, ChNrMesh mesh /* = 0 */)
{
	if(!pTextureData) pTextureData = (ChQvTextureRenderData*)(GetTexture2()->GetRenderData());
	if(!mesh) mesh = m_mesh;

				// This is for retained mode renderers like RealityLab
	bool boolDidIt = false;


	if (mesh)
	{
		if(pTextureData)
		{
			ChTextureHandle texture = pTextureData->GetTextureHandle();
			if(texture)
			{
				ChNrMeshSetTexture(mesh, texture);
				boolDidIt = true;

				#if (defined(CH_USE_D3D))
				// D3D RM doesn't support alpha transparency for textures, 
				// so use chromaKey instead.
				if(pTextureData->IsChromaKey())
				{
					texture->SetDecalTransparency(true);
					texture->SetDecalTransparentColor(*(pTextureData->GetChromaKey().GetNative()));
				}
				
				// Bleach color out - sometimes D3D insists on modulating
				SetColor(ChColorA(1., 1., 1.), mesh);	 
				#endif
			}
		}
		else
		{
			// remove existing texture
			ChNrMeshSetTexture(mesh, 0);
		}
	}
	return boolDidIt;	// false says nothing happened
}

void ChQvShapeInstance::SetColor(const ChColorA &color, ChNrMesh mesh /* = 0 */)
{
#if (defined(CH_USE_D3D))
	if(!mesh) mesh = m_mesh;
	if(mesh)
	{
		mesh->SetColor(*(color.GetNative()));	 // set faces as asked
		mesh->SetColorSource(ColorFromFace);
	}
#endif
}

#endif

// Shapes


// arbitrary for now; later make it depend on image size
#define CalcCylinderFacetCount(cyl, pRC)	(50)
#define CalcConeFacetCount(cyl, pRC)	(50)


ChQvConeInstance::ChQvConeInstance() : ChQvShapeInstance()
{
}


bool ChQvConeInstance::Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	{
		QvCone *pNode = (QvCone *)GetNode();

		ASSERT(m_frame );
		pRC->LockQv();		   // Lock tree so other threads don't kill our data
		if(!pIterator->IsOKToProceed(this))	 // This locks scene if available
		{
			pRC->UnlockQv();		   // Unlock tree 
			return 0;
		}
		if(IsConstructed())
		{
			pRC->UnlockScene();
			pRC->UnlockQv();		   // Unlock tree 
			return 1;
		}
		m_boolConstructed = true;
		
		ChNrMesh mesh = m_mesh = pRC->CreateMesh();
		ChNrFrameAddVisual(GetFrame(), mesh);				   
		D3DRelease(mesh);

		ChNrObjectSetAppData(mesh, (unsigned long)this);
		ChNrMeshSetColorSource(mesh,ColorFromFace); // alternative: ChNativeColorFromVertex 
		ChNrMeshSetPerspective(mesh,true);  

		ChNrMeshSetTextureTopology(mesh,true, false); // uwrap, vwrap 

		bool boolCull = (pNode->parts.value == QvCone::ALL);	// if all sides are present, then cull
		   //boolCull = true;
		int numFacets = CalcConeFacetCount(this, state);

		// Make a material mapping; we will use later for each facet, top and bottom
		ChQvConeMaterials materialMap( this );
		pRC->AdjustTransparency(materialMap);

		/* Do the texture stuff -  make the map, assign to all the verts, */
		ChQvConeTextures	*pTxMap =  new ChQvConeTextures( this, numFacets );
		ChQvTextureRenderData *pTextureData = (ChQvTextureRenderData*)(GetTexture2()->GetRenderData());
		bool boolUseTexture = !(pTextureData->IsEmpty());  // one -might- arrive

		float h2 = pNode->height.value / 2.;
		float r = pNode->bottomRadius.value;

		float pi = atan(1.) * 4.;
		float twoPi = pi * 2;

		// Build the display list: verts, normals, and faces
		// We replicate the apex vertex for each facet, since it has a different 
		// texture u for each facet.
		int numFaces = numFacets + 1, numVerts = numFacets * 2, numNorms = numFacets * 2 + 1;
		if (!boolCull) numNorms *= 2;
		int vertStep = 0;		// step to find verts for sides
		if (boolUseTexture)
		{
			vertStep = numVerts;
			numVerts += numFacets;
		}

		// alloc face_data conservatively; might be a touch too big in some cases
		int face_data_size = numFacets * 3 * 2 		// for side faces - triangles with normals
							+ numFacets 			// side counts
							+ 2 * numFacets 		// bottom
							+ 1 					// bottom counts		
							+ 1;					// terminator
		if (!boolCull) face_data_size *= 2;
		ChNrFaceData * face_data = new ChNrFaceData[face_data_size];

		int 	ifd = 0; // index into face data
		GxVec3f *n = new GxVec3f[numNorms];
		GxVec3f *v = new GxVec3f[numVerts];

		int normStep = numNorms / 2;
		float ynorm = (h2 > 1e-3) ? (r  / (h2 * 2)) : 0;
		for( int facet = 0; facet < numFacets; facet ++)
		{
			float theta = facet * twoPi / numFacets;
			float sintheta = sin(theta);
			float costheta = cos(theta);

			n[facet*2].x() = -sintheta;
			n[facet*2].y() = ynorm;	//  width / height, then mormalize
			n[facet*2].z() = -costheta;
	 
			v[facet].x() = -sintheta * r;
			v[facet].y() = -h2;
			v[facet].z() = -costheta * r;

			v[facet + numFacets].set(0,h2,0);  // top vertex

			n[facet*2].normalize();
			//n[facet*2].z() = -n[facet*2].z();
			if(!boolCull)
			{
				n[facet*2+normStep] = -n[facet*2];	// inside normal
			}

			theta = (facet +.5) * twoPi / numFacets;	// halfway to next point for top vert
			n[facet*2+1].x() = -sin(theta);
			n[facet*2+1].y() = ynorm;	// width / height, then mormalize
			n[facet*2+1].z() = -cos(theta);
			n[facet*2+1].normalize();
			if(!boolCull)
			{
				n[facet*2+1+normStep] = -n[facet*2+1];	// point's inside normal
			}
		}
		n[numFacets*2].set(0,-1,0);  // bottom's normal
		if(!boolCull)
		{
			n[numFacets*2+normStep] = -n[numFacets*2];	// bottom's inside normal
		}
		// Dupe the bottom verts, to use for sides, if we have texture
		if(boolUseTexture)
		{
			for( int i = 0; i < numFacets; i ++)
			{
				v[i+vertStep] = v[i];
			}
		}
		

		// Do the bottom
		if(pNode->parts.value & QvCone::BOTTOM)
		{
		 	 // TODO : Make sure this order is right when we do textures
			face_data[ifd++] = numFacets;	// count
			for( int j = 0; j < numFacets; j ++)
			{
					// Use the vertices, in mangled order

				int index = ( j % (numFacets));
				face_data[ifd++] = index;			// vertex
				face_data[ifd++] = numFacets * 2;		// normal
			}
			if(!boolCull)
			{
				face_data[ifd++] = numFacets;	// count
				for( int j = 0; j < numFacets; j ++)
				{
					// Use the vertices, in even more mangled order

					int index = (numFacets - j) % (numFacets);
					face_data[ifd++] = index;			// vertex
					face_data[ifd++] = numFacets * 2 + normStep;		// normal
				}
			}
		}

		// Do the sides
		if(pNode->parts.value & QvCone::SIDES)
		{
			for( int facet = 0; facet < numFacets; facet ++)
			{
				face_data[ifd++] = 3;	// face vertex count

				face_data[ifd++] = facet + vertStep;							  // v        
				face_data[ifd++] = facet * 2;						  // n, etc.  
				face_data[ifd++] = facet + numFacets;				  // top vertex
				face_data[ifd++] = facet * 2 + 1;
				face_data[ifd++] = ((facet + 1) % numFacets)  + vertStep;
				face_data[ifd++] = (facet * 2 + 2) % (2 * numFacets);
			}
			if(!boolCull)
			{
				for( int facet = 0; facet < numFacets; facet ++)
				{
					face_data[ifd++] = 3;	// face vertex count
											// change the order of pt[1] and [2]

	 				face_data[ifd++] = facet + vertStep;							// v
					face_data[ifd++] = facet * 2 + normStep;			// n, etc.
					face_data[ifd++] = ((facet + 1) % numFacets) + vertStep;
					face_data[ifd++] = (facet * 2 + 2) % (2 * numFacets) + normStep;
					face_data[ifd++] = facet + numFacets;				// top vertex
					face_data[ifd++] = facet * 2 + 1 + normStep;
				}
			}
		}

		face_data[ifd] = 0;	// terminate array

		// Load the verts and faces
		ChNrFaceArray facesAdded;
		int numFacesAdded;
		ChNrMeshAddFaces(mesh,
				       numVerts,
				       (ChNrVector*) v,
				       numNorms,
				       (ChNrVector*) n,
				       face_data,
				       &numFacesAdded,
				       &facesAdded);
		
		// Assign colors to faces
		int iface = 0;

		#if defined(CH_USE_D3D)
		numFacesAdded = facesAdded->GetSize();
		#endif

		ChNrFace elt;	// scratch space
		// Do the bottom
		if(pNode->parts.value & QvCone::BOTTOM)
		{
			int count = 1;	// count
			if(!boolCull) count *= 2;
			for( int j = 0; j < count; j ++)
			{
				GetElement(facesAdded, unsigned(iface), elt);
				if(boolUseTexture)
				{ 
					SetTextureCoordinates(pTxMap, mesh, elt, Bottom); 
				}
				materialMap.Set(mesh, elt, ChQvConeMaterials::Bottom);
				iface++;
				D3DRelease(elt);
			}
		}

		// Do the sides
		if(pNode->parts.value & QvCone::SIDES)
		{
			int count = numFacets;	// count
			if(!boolCull) count *= 2;
			for( int j = 0; j < count; j ++)
			{
				GetElement(facesAdded, unsigned(iface), elt);
				if(boolUseTexture && j < numFacets)
				{ 
					SetTextureCoordinates(pTxMap, mesh, elt, Sides, j); 
				}
				materialMap.Set(mesh, elt, ChQvConeMaterials::Sides);
				iface++;
				D3DRelease(elt);
			}
		}

		if(boolUseTexture)
		{
			ChTextureHandle hdl = pTextureData->GetTextureHandle();
			if(hdl)
			{
				// Texture guy got here first, apply it
				//ChNrMeshSetTexture(mesh, hdl);
				SetTexture(pTextureData);

			}
		}  
	
													  // Cleanup time
 		ChNrFree(facesAdded);							  
		delete [] v;
		delete [] n;
		delete [] face_data;
		delete [] pTxMap;

		pIterator->DidAShape();
		pRC->UnlockScene();		
		pRC->UnlockQv();		   // Unlock tree 
	}
#endif
	return true;
}


bool ChQvConeInstance::Draw(ChRenderContext *pRC, ChDrawIterator *pIterator)
{
#if defined( CH_USE_3DR )
	long On = 1;
	long Off = 0;

	G3dHandle_t hGC = pRC->GetGC();
	Dword_t  hRC = pRC->GetRC();
	QvCone *pNode = (QvCone *)GetNode();
	pRC->SetModelTransform(GetTransform());

	pRC->SetShading(this);


	Float_t		cull = 0;
	Fixed32_t wMattNum = 0;	  // always use material 0

	if(pNode->parts.value == QvCone::ALL) cull = 1;	// if all sides are present, then cull
	G3dSetMatt( hGC,  wMattNum, G3DM_BACK_CULL,	(Float_t *)&cull );
	
	int numFacets = CalcConeFacetCount(this, pRC);

	// Make a material mapping; we will use later for each facet and bottom
	ChQvConeMaterials materialMap( this);

	/* Do the texture stuff - find it, make the map, set up 3dr for it, */
	int boolUseTexture = false;
	
	ChQvTextureRenderData *pTextureData = 0;
	pTextureData = (ChQvTextureRenderData*)(GetTexture2()->GetRenderData());
	if (pTextureData->GetTextureHandle()) boolUseTexture = true;
	
	ChQvConeTextures	*pTxMap = 0;
	 
	if(boolUseTexture)
	{
		pRC->SetTexture(pTextureData->GetTextureHandle());
		pTxMap = new ChQvConeTextures( this, numFacets );
	}

	float h2 = pNode->height.value / 2.;
	float r = pNode->bottomRadius.value;

	Fixed32_t lCCW;
	G3dGetState( hGC, G3DL_FRONT_CCW, &lCCW); // save CCW state
	G3dSetState( hGC, G3DL_FRONT_CCW, &On);

	
	bool boolPureEmissive;
	float pi = atan(1.) * 4.;
	float twoPi = pi * 2;

	// Do the sides
	if(pNode->parts.value & QvCone::SIDES)
	{
		materialMap.Set(hRC, hGC, 0, &boolPureEmissive);
		pRC->SetModulation( boolUseTexture, boolPureEmissive);

		G3dBeginPrim(hGC, G3D_PRM_QUADSTRIP, numFacets * 2 + 2);
		for( int facet = 0; facet <= numFacets; facet ++)
		{
			PointF_t n, v1, v2;
			float theta = facet * twoPi / numFacets;

			// get better norm from RLab Code TODO!!!
			n.x = -sin(theta);
			n.y = 0;
			n.z = -cos(theta);
		 
			v1.x = 0;
			v1.y = h2;
			v1.z = 0;

			v2.x = n.x * r;
			v2.y = -h2;
			v2.z = n.z * r;

			if(boolUseTexture)
			{
				PointF_t textCoord = pTxMap->GetCoord3(0, facet, 0);
				G3dAddPrimVtxF(hGC, &v1, &n, &textCoord, 0);

				textCoord = pTxMap->GetCoord3(0, facet, 1);
				G3dAddPrimVtxF(hGC, &v2, &n, &textCoord, 0);
			}
			else
			{
				G3dAddPrimVtxF(hGC, &v1, &n, 0, 0);
				G3dAddPrimVtxF(hGC, &v2, &n, 0, 0);
			}
		}
		try
		{
			G3dEndPrim(hGC);
		}
		catch(...)
		{
			//TRACE("Exception in drawing cylinder caught\r\n");
		}
	}


	// Do the bottom
	G3dSetState( hGC, G3DL_FRONT_CCW, &Off);
	if(pNode->parts.value & QvCone::BOTTOM)
	{
		materialMap.Set(hRC, hGC, 1 /*bottom*/, &boolPureEmissive);
		pRC->SetModulation( boolUseTexture, boolPureEmissive);

		G3dBeginPrim(hGC, G3D_PRM_POLYGON, numFacets);
		PointF_t n, v1;
		n.x = 0;
		n.y = -1;
		n.z = 0;
		for( int j = 0; j <= numFacets; j ++)
		{
			float theta = j * twoPi / numFacets;
			v1.x = sin(theta + pi) * r;
			v1.y = -h2;
			v1.z = cos(theta + pi) * r;
		 
			if(boolUseTexture)
			{
				PointF_t textCoord = pTxMap->GetCoord3(1, 0, j);
				G3dAddPrimVtxF(hGC, &v1, &n, &textCoord, 0);
			}
			else
			{
				G3dAddPrimVtxF(hGC, &v1, &n, 0, 0);
			}
		}
		G3dEndPrim(hGC);
	}

	G3dSetState( hGC, G3DL_FRONT_CCW, &lCCW);
	if(boolUseTexture)
	{
		pRC->SetTexture(0);							// turn off texture
		delete pTxMap;
	}
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#endif //defined( CH_USE_3DR )
	return true;
}


#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
void ChQvConeInstance::SetTextureCoordinates(ChQvConeTextures *pTxMap, ChNrMesh mesh, ChNrFace face, Parts part, int facet)
{

	int count = ChNrFaceGetVertexCount(face);
	for(int j = 0; j < count; j++)
	{
		GxVec3f textCoord = pTxMap->GetCoord3(part, facet, j);
		int index = ChNrFaceGetVertexIndex(face, j);
		ChNrMeshSetTextureCoordinates(mesh, index, textCoord.x(), textCoord.y());
	}
}
#endif


ChQvCubeInstance::ChQvCubeInstance() : ChQvShapeInstance()
{
}

bool ChQvCubeInstance::Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	{
		ASSERT(m_frame );
		pRC->LockQv();		   // Lock tree so other threads don't kill our data
		if(!pIterator->IsOKToProceed(this))	 // This locks scene if available
		{
			pRC->UnlockQv();		   // Unlock tree 
			return 0;
		}
		if(IsConstructed())
		{
			pRC->UnlockScene();
			pRC->UnlockQv();		   // Unlock tree 
			return 1;
		}
		m_boolConstructed = true;
		
		static long indices[6][4] =
		{
			{0, 1, 5, 4},	// front
			{2, 3, 7, 6},	// back
			{3, 0, 4, 7},	// left
			{1, 2, 6, 5},	// right
			{3, 2, 1, 0},	// top
			{4, 5, 6, 7}	// bottom
		};
		static  GxVec3f fSigns[8] =
		{
			GxVec3f(-1, 1, 1),	// top front left
			GxVec3f( 1, 1, 1),	// top right
			GxVec3f( 1, 1, -1),	// top right back
			GxVec3f(-1, 1, -1),	// top left back
			GxVec3f(-1, -1, 1),	// bottom left
			GxVec3f( 1, -1, 1),	// bottom right
			GxVec3f( 1, -1, -1),	// bottom right back
			GxVec3f(-1, -1, -1)	// bottom left back
		};
		#if 0
		static  GxVec3f fNorms[6] =		
		{									// indexed by face
			GxVec3f( 0, 0, 1),// 
			GxVec3f( 0, 0, -1),	// 
			GxVec3f(-1, 0, 0),	// 
			GxVec3f( 1, 0, 0),	// 
			GxVec3f( 0, 1, 0),	// 
			GxVec3f( 0, -1, 0)	// bottom 
		};
		#else
		static  GxVec3f fNorms[6] =		
		{									// indexed by face
			GxVec3f( 0, 0, -1),// 
			GxVec3f( 0, 0, 1),	// 
			GxVec3f(1, 0, 0),	// 
			GxVec3f( -1, 0, 0),	// 
			GxVec3f( 0, -1, 0),	// 
			GxVec3f( 0, 1, 0)	// bottom 
		};
		#endif
		QvCube *pNode = (QvCube *)GetNode();

		// Make a material mapping; we will use later for each face
		ChQvCubeMaterials materialMap( this );
		pRC->AdjustTransparency(materialMap);

		/* Do the texture stuff - find it, make the map, set up 3dr for it, */
		ChQvCubeTextures	*pTxMap =  new ChQvCubeTextures( this );
		ChQvTextureRenderData *pTextureData = (ChQvTextureRenderData*)(GetTexture2()->GetRenderData());
		bool boolUseTexture = !(pTextureData->IsEmpty());  // one -might- arrive


		float h2 = pNode->height.value / 2.;
		float w2 = pNode->width.value / 2.;
		float d2 = pNode->depth.value / 2.;

		ChNrMesh mesh = m_mesh = pRC->CreateMesh();
		ChNrFrameAddVisual(GetFrame(), mesh);				   
		D3DRelease(mesh);

		ChNrObjectSetAppData(mesh, (unsigned long)this);
		ChNrMeshSetColorSource(mesh,ColorFromFace); // alternative: ChNativeColorFromVertex 
		ChNrMeshSetPerspective(mesh,true);  

		// Need to reserve space for vertices, normals, and faces - 
		int numFaces = 6, numVerts = 8, numNorms = 6;
		int vertStep = 0;		// step to find verts for sides
		if (boolUseTexture)
		{
			vertStep = numVerts;
			numVerts *= 3;
		}

		ChNrMeshReserveSpace(mesh, numVerts, numNorms, numFaces);  
		ChNrFaceData * face_data = new ChNrFaceData[48 + 6 + 1];
		int 	ifd = 0; // index into face data
		GxVec3f *n = new GxVec3f[numNorms], *v = new GxVec3f[numVerts];

		for (int index = 0; index < numVerts; index++)
		{
			int i = index % 8;
			v[index].x() = fSigns[i].x() * w2;
			v[index].y() = fSigns[i].y() * h2;
			v[index].z() = fSigns[i].z() * d2;
		}

		for( int iface = 0; iface < 6; iface ++)
		{
			n[iface] = -fNorms[iface];
			#if defined(FLIP_D3D_NORMALS) && defined(CH_USE_D3D)
			n[iface] = -n[iface];
			#endif

			face_data[ifd++] = 4;

			int istep = (iface / 2) * vertStep;	// which group of vertices, if texturing

			for( int j = 0; j < 4; j++ )
			{
				int index = indices[iface][j];
				face_data[ifd++] = index + istep;
				face_data[ifd++] = iface;
			}

		}
		face_data[ifd] = 0;	// terminate array
		
		#if 0  // || TRY_TO_FIX_POINT_LIGHTS
		GxTransform3Wf transform = GetTransform();
		(*(transform.GetMatrix()))[3][0] = 0;
		(*(transform.GetMatrix()))[3][1] = 0;
		(*(transform.GetMatrix()))[3][2] = 0;
		for(int ifn = 0; ifn < 6; ifn++)
		{
			float w;
			GxVec3f normT;
			normT =	transform.TransformW(n[ifn], w);
			float mag = normT.magnitude();
			if (w != 0.0) mag /= w;
			if (mag != 0.0) n[ifn] *= 1. / (mag);
		}
		#endif

		// Load the verts and faces
		ChNrFaceArray facesAdded;
		int numFacesAdded;
		ChNrMeshAddFaces(mesh,
				       numVerts,
				       (ChNrVector*) v,
				       6,
				       (ChNrVector*) n,
				       face_data,
				       &numFacesAdded,
				       &facesAdded);

		#if defined(CH_USE_D3D)
		numFacesAdded = facesAdded->GetSize();
		#endif
		#if 0 && defined(CH_USE_D3D)

		DWORD dwVerts, dwNormals, dwFaceSize;
		D3DVECTOR tmpV[24], tmpN[24];
		mesh->GetVertices(&dwVerts, tmpV, &dwNormals, tmpN, &dwFaceSize, 0);
		#endif

		ChNrFace elt;
		// Set the material for the whole mesh
		for( iface = 0; iface < 6; iface ++)
		{
			GetElement(facesAdded, unsigned(iface), elt);
			if(boolUseTexture) 
				SetTextureCoordinates(pTxMap, mesh, elt, iface); 
			materialMap.Set(mesh, elt);
			#if 0 && defined(CH_USE_D3D)
			D3DVECTOR Normal;
			elt->GetNormal(&Normal);
			//elt->SetNormal((ChNrVector*)(n+iface));
			#endif
			D3DRelease(elt);

		}

		if(boolUseTexture)
		{
			ChTextureHandle hdl = pTextureData->GetTextureHandle();
			if(hdl)
			{
				// Texture guy got here first, apply it
				//ChNrMeshSetTexture(mesh, hdl);
				SetTexture(pTextureData);

			}
		}  

		ChNrFree(facesAdded);
		delete [] v;
		delete [] n;
		delete [] face_data;
		delete pTxMap;

		pIterator->DidAShape();
		pRC->UnlockScene();		
		pRC->UnlockQv();		   // Unlock tree 

	}
#endif
	return	true;
}

bool ChQvCubeInstance::Draw(ChRenderContext *pRC, ChDrawIterator *pIterator)
{
#if defined( CH_USE_3DR )
	{
		Fixed32_t On = 1;
		Fixed32_t Off = 0;
		static long indices[6][4] =
		{
			{0, 1, 5, 4},	// front
			{2, 3, 7, 6},	// back
			{3, 0, 4, 7},	// left
			{1, 2, 6, 5},	// right
			{3, 2, 1, 0},	// top
			{4, 5, 6, 7}	// bottom
		};
		static  PointF_t fSigns[8] =
		{
			{-1, 1, 1},	// top front left
			{ 1, 1, 1},	// top right
			{ 1, 1, -1},	// top right back
			{-1, 1, -1},	// top left back
			{-1, -1, 1},	// bottom left
			{ 1, -1, 1},	// bottom right
			{ 1, -1, -1},	// bottom right back
			{-1, -1, -1}	// bottom left back
		};
		static  PointF_t fNorms[6] =		
		{									// indexed by face
			{ 0, 0, 1},// 
			{ 0, 0, -1},	// 
			{-1, 0, 0},	// 
			{ 1, 0, 0},	// 
			{ 0, 1, 0},	// 
			{ 0, -1, 0}	// bottom 
		};
		G3dHandle_t hGC = pRC->GetGC();
		Dword_t  hRC = pRC->GetRC();
		QvCube *pNode = (QvCube *)GetNode();
		pRC->SetModelTransform(GetTransform());

		pRC->SetShading(this);

		Float_t		cull = 1;	   // always backcull cubes
		Fixed32_t wMattNum = 0;	  // always use material 0
		G3dSetMatt( hGC,  wMattNum, G3DM_BACK_CULL,	(Float_t *)&cull );
	
		// Make a material mapping; we will use later for each face
		ChQvCubeMaterials materialMap( this );

		/* Do the texture stuff - find it, make the map, set up 3dr for it, */
		int boolUseTexture = SetupTexture(pRC);
		ChQvCubeTextures	*pTxMap = 0;
		if(boolUseTexture)
		{
			pTxMap = new ChQvCubeTextures( this );
		}

		float h2 = pNode->height.value / 2.;
		float w2 = pNode->width.value / 2.;
		float d2 = pNode->depth.value / 2.;

		Fixed32_t lCCW = true;
		G3dGetState( hGC, G3DL_FRONT_CCW, &lCCW);
		G3dSetState( hGC, G3DL_FRONT_CCW, &Off);

		for( int face = 0; face < 6; face ++)
		{
			bool boolPureEmissive;
			materialMap.Set(hRC, hGC, face, &boolPureEmissive);
			pRC->SetModulation( boolUseTexture, boolPureEmissive);

			G3dBeginPrim(hGC, G3D_PRM_POLYGON, 4);
			PointF_t n, v;
			n = fNorms[face];

			for( int j = 0; j < 4; j++ )
			{
				int index = indices[face][j];
				v.x = fSigns[index].x * w2;
				v.y = fSigns[index].y * h2;
				v.z = fSigns[index].z * d2;
				if(boolUseTexture)
				{
					PointF_t textCoord = pTxMap->GetCoord3(face, j);

					G3dAddPrimVtxF(hGC, &v, &n, &textCoord, 0);
				}
				else
				{
					G3dAddPrimVtxF(hGC, &v, &n, 0, 0);
				}
			}
			G3dEndPrim(hGC);

		}
		G3dSetState( hGC, G3DL_FRONT_CCW, &lCCW);
		if(boolUseTexture)
		{
			pRC->SetTexture(0);							// turn off texture
			delete pTxMap;
		}
	}
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#else
#endif //defined( CH_USE_3DR ) or others
	return true;
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
void ChQvCubeInstance::SetTextureCoordinates(ChQvCubeTextures *pTxMap, ChNrMesh mesh, ChNrFace face, int faceNum)
{
	int count = ChNrFaceGetVertexCount(face);
	for(int j = 0; j < count; j++)
	{
		GxVec3f textCoord = pTxMap->GetCoord3(faceNum, j);
		int index = ChNrFaceGetVertexIndex(face, j);
		ChNrMeshSetTextureCoordinates(mesh, index, textCoord.x(), textCoord.y());
	}
}
#endif

//////////////////////////////////////////////////////////////////////

ChQvCylinderInstance::ChQvCylinderInstance() : ChQvShapeInstance()
{
}
bool ChQvCylinderInstance::Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	{
		QvCylinder *pNode = (QvCylinder *)GetNode();

		ASSERT(m_frame );
		pRC->LockQv();		   // Lock tree so other threads don't kill our data
		if(!pIterator->IsOKToProceed(this))	 // This locks scene if available
		{
			pRC->UnlockQv();		   // Unlock tree 
			return 0;
		}
		if(IsConstructed())
		{
			pRC->UnlockScene();
			pRC->UnlockQv();		   // Unlock tree 
			return 1;
		}
		m_boolConstructed = true;
		
		ChNrMesh mesh = m_mesh = pRC->CreateMesh();
		ChNrFrameAddVisual(GetFrame(), mesh);				   
		D3DRelease(mesh);

		ChNrObjectSetAppData(mesh, (unsigned long)this);
		ChNrMeshSetColorSource(mesh,ColorFromFace); // alternative: ChNativeColorFromVertex
		ChNrMeshSetPerspective(mesh,true);  
		 
		ChNrMeshSetTextureTopology(mesh,true, false); // uwrap, vwrap 

		bool boolCull = (pNode->parts.value == QvCylinder::ALL);	// if all sides are present, then cull
		   //boolCull = true;
		int numFacets = CalcCylinderFacetCount(this, state);

		// Make a material mapping; we will use later for each facet, top and bottom
		ChQvCylinderMaterials materialMap( this );
		pRC->AdjustTransparency(materialMap);

		/* Do the texture stuff -  make the map, assign to all the verts, */
		ChQvCylinderTextures	*pTxMap =  new ChQvCylinderTextures( this, numFacets );
		ChQvTextureRenderData *pTextureData = (ChQvTextureRenderData*)(GetTexture2()->GetRenderData());
		bool boolUseTexture = !(pTextureData->IsEmpty());  // one -might- arrive
	
		float h2 = pNode->height.value / 2.;
		float r = pNode->radius.value;

		float pi = atan(1.) * 4.;
		float twoPi = pi * 2;

		// Build the display list: verts, normals, and faces
		int numFaces = numFacets + 2, numVerts = numFacets * 2, numNorms = numFacets + 2;
		if (!boolCull) numNorms *= 2;
		int vertStep = 0;		// step to find verts for sides
		if (boolUseTexture)
		{
			vertStep = numVerts;
			numVerts *= 2;
		}

		// alloc face_data conservatively; might be a touch too big in some cases
		int face_data_size = numFacets * 4 * 2 		// for side faces
							+ numFacets 			// side counts
							+ 2 * numFacets * 2 	// ends
							+ 2 					// end counts		
							+ 1;					// terminator
		if (!boolCull) face_data_size *= 2;
		ChNrFaceData * face_data = new ChNrFaceData[face_data_size];

		int 	ifd = 0; // index into face data
		GxVec3f *n = new GxVec3f[numNorms];
		GxVec3f *v = new GxVec3f[numVerts];

		int normStep = numNorms / 2;
		  // We store both inside and outside normals if not backculled,
		  // but only store outsides if this is solid (not backCulled).
		  // We store all outside norms, first side norms, then ends,
		  // then same for insides if needed.
		for( int facet = 0; facet < numFacets; facet ++)
		{
			float theta = facet * twoPi / numFacets;
			float sintheta = sin(theta);
			float costheta = cos(theta);
			n[facet].x() = -sintheta;
			n[facet].y() = 0;
			n[facet].z() = -costheta;
			if(!boolCull)
			{
				n[facet+normStep] = -n[facet];	// inside normal
			}
	 
			v[facet*2].x() = -sintheta * r;
			v[facet*2].y() = h2;
			v[facet*2].z() = -costheta * r;
			v[facet*2+1] = v[facet*2];
			v[facet*2+1].y() = -h2;
		}
		n[facet].set(0,1,0);	 
		if(!boolCull) n[facet+normStep] = -n[facet];	// inside normal
		facet++;
		n[facet].set(0,-1,0);
		if(!boolCull) n[facet+normStep] = -n[facet];	// inside normal
		facet++;

		// Dupe the verts, to use for sides, if we have texture
		if(boolUseTexture)
		{
			for( int i = 0; i < numVerts / 2; i ++)
			{
				v[i+vertStep] = v[i];
			}
		}

		// Do the top
		if(pNode->parts.value & QvCylinder::TOP)
		{
			face_data[ifd++] = numFacets;	// count
			for( int j = 0; j < numFacets; j ++)
			{
				// Use the even numbered vertices, in reversed order
				int index = ((numFacets - j) * 2) % (numFacets * 2);
				face_data[ifd++] = index;			// vertex
				face_data[ifd++] = numFacets;		// normal
			}
			if(!boolCull)
			{
				// Back face - uses inside normal
				face_data[ifd++] = numFacets;	// count for this face
				for( int j = 0; j < numFacets; j ++)
				{
					// Use the even numbered vertices, in reversed order from front face
					int index = (j * 2) % (numFacets * 2);
					face_data[ifd++] = index;			// vertex
					face_data[ifd++] = numFacets + normStep;		// normal
				}
			}
		}

		// Do the bottom
		if(pNode->parts.value & QvCylinder::BOTTOM)
		{
		 	 // TODO : Make sure this order is right when we do textures
			face_data[ifd++] = numFacets;	// count for this face
			for( int j = 0; j < numFacets; j ++)
			{
					// Use the odd numbered vertices, in mangled order

				int index = ((j * 2) % (numFacets * 2)) + 1;
				face_data[ifd++] = index;			// vertex
				face_data[ifd++] = (numFacets + 1);		// normal
			}
			if(!boolCull)
			{
				// Back face - uses inside normal
				face_data[ifd++] = numFacets;	// count for this face
				for( int j = 0; j < numFacets; j ++)
				{
					// Use the odd numbered vertices, in even more mangled order

					int index = (numFacets * 2 - j * 2) % (numFacets * 2) + 1;
					face_data[ifd++] = index;			// vertex
					face_data[ifd++] = (numFacets + 1)  + normStep;		// normal
				}
			}
		}

		// Do the sides
		if(pNode->parts.value & QvCylinder::SIDES)
		{
			static int backPermute[4] = { 0, 1, 3, 2 };
			static int permute[4] = { 0, 2, 3, 1 };
			for( int facet = 0; facet < numFacets; facet ++)
			{
				face_data[ifd++] = 4;	// count
				for( int j = 0; j < 4; j++ )
				{
					int index = (facet * 2 + permute[j]) % (numFacets * 2);
					face_data[ifd++] = index + vertStep;
					face_data[ifd++] = (facet + (permute[j] / 2)) % numFacets;
				}
			}
			if(!boolCull)
			{
				// Back face - uses inside normal
				for( int facet = 0; facet < numFacets; facet ++)
				{
					face_data[ifd++] = 4;	// count

					for( int j = 0; j < 4; j++ )
					{
						int index = (facet * 2 + backPermute[j]) % (numFacets * 2);
						face_data[ifd++] = index + vertStep;
						face_data[ifd++] = ((facet + (permute[j] / 2)) % numFacets) + normStep;
					}
				}
			}
		}

		face_data[ifd] = 0;	// terminate array

		// Load the verts and faces
		ChNrFaceArray	facesAdded;
		int numFacesAdded;
		ChNrMeshAddFaces(mesh,
				       numVerts,
				       (ChNrVector*) v,
				       numNorms,
				       (ChNrVector*) n,
				       face_data,
				       &numFacesAdded,
				       &facesAdded);
		
		#if defined(CH_USE_D3D)
		numFacesAdded = facesAdded->GetSize();
		#endif

		// Assign colors to faces
		int iface = 0;
		ChNrFace elt;
		if(pNode->parts.value & QvCylinder::TOP)
		{
			int count = 1;	// count
			if(!boolCull) count *= 2;
			for( int j = 0; j < count; j ++)
			{	
				GetElement(facesAdded, unsigned(iface), elt);
				if(boolUseTexture) 
					SetTextureCoordinates(pTxMap, mesh, elt, Top); 
				materialMap.Set(mesh, elt, ChQvCylinderMaterials::Top);
				D3DRelease(elt);
				iface++;
			}
		}

		// Do the bottom
		if(pNode->parts.value & QvCylinder::BOTTOM)
		{
			int count = 1;	// count
			if(!boolCull) count *= 2;
			for( int j = 0; j < count; j ++)
			{
				GetElement(facesAdded, unsigned(iface), elt);
				if(boolUseTexture) 
					SetTextureCoordinates(pTxMap, mesh, elt, Bottom); 
				materialMap.Set(mesh, elt, ChQvCylinderMaterials::Bottom);
				D3DRelease(elt);
				iface++;
			}
		}

		// Do the sides
		if(pNode->parts.value & QvCylinder::SIDES)
		{
			int count = numFacets;	// count
			if(!boolCull) count *= 2;
			for( int j = 0; j < count; j ++)
			{
				GetElement(facesAdded, unsigned(iface), elt);
				if(boolUseTexture && j < numFacets) 
					SetTextureCoordinates(pTxMap, mesh, elt, Sides, j % numFacets); 
				materialMap.Set(mesh, elt, ChQvCylinderMaterials::Sides);
				D3DRelease(elt);
				iface++;
			}
		}


		if(boolUseTexture)
		{
			ChTextureHandle hdl = pTextureData->GetTextureHandle();
			if(hdl)
			{
				// Texture guy got here first, apply it
				//ChNrMeshSetTexture(mesh, hdl);
				SetTexture(pTextureData);

			}
		}  
													  
													  
													  // Cleanup time
 		ChNrFree(facesAdded);							  
		delete [] v;
		delete [] n;
		delete [] face_data;
		delete pTxMap;

		pIterator->DidAShape();
		pRC->UnlockScene();		
		pRC->UnlockQv();		   // Unlock tree 

	}
#endif
	return true;
}

bool ChQvCylinderInstance::Draw(ChRenderContext *pRC, ChDrawIterator *pIterator)
{
#if defined( CH_USE_3DR )
	{
		Fixed32_t On = 1;
		Fixed32_t Off = 0;

		G3dHandle_t hGC = pRC->GetGC();
		Dword_t  hRC = pRC->GetRC();
		QvCylinder *pNode = (QvCylinder *)GetNode();
		pRC->SetModelTransform(GetTransform());

		pRC->SetShading(this);

		Float_t		cull = 0;
		Fixed32_t wMattNum = 0;	  // always use material 0

		if(pNode->parts.value == QvCylinder::ALL) cull = 1;	// if all sides are present, then cull
		G3dSetMatt( hGC,  wMattNum, G3DM_BACK_CULL,	(Float_t *)&cull );
	
		int numFacets = CalcCylinderFacetCount(this, state);

		// Make a material mapping; we will use later for each facet, top and bottom
		ChQvCylinderMaterials materialMap( this );

		/* Do the texture stuff - find it, make the map, set up 3dr for it, */
		int boolUseTexture = SetupTexture(pRC);
		ChQvCylinderTextures	*pTxMap = 0;
		if(boolUseTexture)
		{
			pTxMap = new ChQvCylinderTextures( this, numFacets );
		}
	
		float h2 = pNode->height.value / 2.;
		float r = pNode->radius.value;

		Fixed32_t lCCW;
		G3dGetState( hGC, G3DL_FRONT_CCW, &lCCW); // save CCW state
		G3dSetState( hGC, G3DL_FRONT_CCW, &On);

	
		bool boolPureEmissive;
		float pi = atan(1.) * 4.;
		float twoPi = pi * 2;

		// Do the sides
		if(pNode->parts.value & QvCylinder::SIDES)
		{
			materialMap.Set(hRC, hGC, 0, &boolPureEmissive);
			pRC->SetModulation( boolUseTexture, boolPureEmissive);

			G3dBeginPrim(hGC, G3D_PRM_QUADSTRIP, numFacets * 2 + 2);
			for( int facet = 0; facet <= numFacets; facet ++)
			{
				PointF_t n, v1, v2;
				float theta = facet * twoPi / numFacets;
				n.x = -sin(theta);
				n.y = 0;
				n.z = -cos(theta);
		 
				v1.x = n.x * r;
				v1.y = h2;
				v1.z = n.z * r;

				v2 = v1;
				v2.y = -h2;
		

				if(boolUseTexture)
				{
					PointF_t textCoord = pTxMap->GetCoord3(0, facet, 0);
					G3dAddPrimVtxF(hGC, &v1, &n, &textCoord, 0);

					textCoord = pTxMap->GetCoord3(0, facet, 1);
					G3dAddPrimVtxF(hGC, &v2, &n, &textCoord, 0);
				}
				else
				{
					G3dAddPrimVtxF(hGC, &v1, &n, 0, 0);
					G3dAddPrimVtxF(hGC, &v2, &n, 0, 0);
				}
			}
			G3dEndPrim(hGC);
		}
		G3dSetState( hGC, G3DL_FRONT_CCW, &On);

		// Do the top
		if(pNode->parts.value & QvCylinder::TOP)
		{
			materialMap.Set(hRC, hGC, 1 /*top*/, &boolPureEmissive);
			pRC->SetModulation( boolUseTexture, boolPureEmissive);

			G3dBeginPrim(hGC, G3D_PRM_POLYGON, numFacets);
			PointF_t n, v1;
			n.x = 0;
			n.y = 1;
			n.z = 0;
			for( int j = 0; j <= numFacets; j ++)
			{
				float theta = j * twoPi / numFacets;
				v1.x = -sin(theta) * r;
				v1.y = h2;
				v1.z = -cos(theta) * r;
		 
				if(boolUseTexture)
				{
					PointF_t textCoord = pTxMap->GetCoord3(1, 0, j);
					G3dAddPrimVtxF(hGC, &v1, &n, &textCoord, 0);
				}
				else
				{
					G3dAddPrimVtxF(hGC, &v1, &n, 0, 0);
				}
			}
			G3dEndPrim(hGC);
		}

		// Do the bottom
		G3dSetState( hGC, G3DL_FRONT_CCW, &Off);
		if(pNode->parts.value & QvCylinder::BOTTOM)
		{
			materialMap.Set(hRC, hGC, 2 /*bottom*/, &boolPureEmissive);
			pRC->SetModulation( boolUseTexture, boolPureEmissive);

			G3dBeginPrim(hGC, G3D_PRM_POLYGON, numFacets);
			PointF_t n, v1;
			n.x = 0;
			n.y = -1;
			n.z = 0;
			for( int j = 0; j <= numFacets; j ++)
			{
				float theta = j * twoPi / numFacets;
				v1.x = sin(theta + pi) * r;
				v1.y = -h2;
				v1.z = cos(theta + pi) * r;
		 
				if(boolUseTexture)
				{
					PointF_t textCoord = pTxMap->GetCoord3(2, 0, j);
					G3dAddPrimVtxF(hGC, &v1, &n, &textCoord, 0);
				}
				else
				{
					G3dAddPrimVtxF(hGC, &v1, &n, 0, 0);
				}
			}
			G3dEndPrim(hGC);
		}

		G3dSetState( hGC, G3DL_FRONT_CCW, &lCCW);
		if(boolUseTexture)
		{
			pRC->SetTexture(0);							// turn off texture
			delete pTxMap;
		}
	}
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#endif //defined( CH_USE_3DR )
	return true;
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
void ChQvCylinderInstance::SetTextureCoordinates(ChQvCylinderTextures *pTxMap, ChNrMesh mesh, ChNrFace face, Parts part, int facet)
{
	int count = ChNrFaceGetVertexCount(face);
	for(int j = 0; j < count; j++)
	{
		GxVec3f textCoord = pTxMap->GetCoord3(part, facet, j);
		int index = ChNrFaceGetVertexIndex(face, j);
		ChNrMeshSetTextureCoordinates(mesh, index, textCoord.x(), textCoord.y());
	}
}
#endif

ChQvIFSInstance::ChQvIFSInstance() : ChQvShapeInstance()
{
}

#define ALMOST_ZERO	(1.e-12)

bool ChQvIFSInstance::IsConvex(int iFirstVertex, int iNumVerts)
{
	QvIndexedFaceSet *pNode = (QvIndexedFaceSet *)GetNode();

	// If they claim convex, believe 'em
	if(GetShapeHints()->faceType.value == QvShapeHints::CONVEX) return true;

	QvCoordinate3 *pC3 = GetCoordinate3();
	int j;
	GxVec3f n;
	 
	long *pCoords = pNode->coordIndex.values + iFirstVertex;

	// First pass - find a non-degenerate normal
	for(j = 0; j < iNumVerts; j++)
	{
		int iC3 = pCoords[j] * 3;
		GxVec3f	p(pC3->point.values[iC3], pC3->point.values[iC3+1], pC3->point.values[iC3+2]);
		int iCv = pCoords[(j+1) % iNumVerts] * 3;
		GxVec3f	v1(pC3->point.values[iCv], pC3->point.values[iCv+1], pC3->point.values[iCv+2]);
		iCv = pCoords[(j+2) % iNumVerts] * 3;
		GxVec3f	v2(pC3->point.values[iCv], pC3->point.values[iCv+1], pC3->point.values[iCv+2]);

		v1 -= p;
		v2 -= p;

		n = v1.cross(v2);
		if(n.magnitude() > ALMOST_ZERO) break;
	}

	GxVec3f nRef = n;

	// Second pass - test against non-degenerate reference normal 
	for(j = 0; j < iNumVerts; j++)
	{
		int iC3 = pCoords[j] * 3;
		GxVec3f	p(pC3->point.values[iC3], pC3->point.values[iC3+1], pC3->point.values[iC3+2]);
		int iCv = pCoords[(j+1) % iNumVerts] * 3;
		GxVec3f	v1(pC3->point.values[iCv], pC3->point.values[iCv+1], pC3->point.values[iCv+2]);
		iCv = pCoords[(j+2) % iNumVerts] * 3;
		GxVec3f	v2(pC3->point.values[iCv], pC3->point.values[iCv+1], pC3->point.values[iCv+2]);

		v1 -= p;
		v2 -= p;

		n = v1.cross(v2);
		if(n.dot(nRef) < 0.0) return false;
	}
	return true;	// TODO
};

bool ChQvIFSInstance::Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	{
		ASSERT(m_frame );
		pRC->LockQv();		   // Lock tree so other threads don't kill our data
		if(!pIterator->IsOKToProceed(this))	 // This locks scene if available
		{
			pRC->UnlockQv();		   // Unlock tree 
			return 0;
		}
		if(IsConstructed())
		{
			pRC->UnlockQv();		   // Lock tree so other threads don't kill our data
			pRC->UnlockScene();
			return 1;
		}
		//TRACE("Constructing an IFS\n");
		m_boolConstructed = true;

		QvIndexedFaceSet *pNode = (QvIndexedFaceSet *)GetNode();

		// Interpret shapehints; we assume there is at least one there; (we inited to make sure)
		// Remember that RL CW is opposite from VRML (LHS ~ RHS)
		bool boolCCW = (GetShapeHints()->vertexOrdering.value == QvShapeHints::COUNTERCLOCKWISE);
		bool boolDirectionKnown = !(GetShapeHints()->vertexOrdering.value == QvShapeHints::UNKNOWN_ORDERING);
		
		bool boolFlipNormals = false;	// ????????

		// Figure out if we can backcull. solid + known order means we can
		bool boolBackCull = ((GetShapeHints()->vertexOrdering.value != QvShapeHints::UNKNOWN_ORDERING) &&
					(GetShapeHints()->shapeType.value == QvShapeHints::SOLID));
	

									/* If they can't write good nodes, don't draw them! */				 
		if(((ChQvIFSRenderData *)m_pRenderData)->IsValid())
		{
		
			ChQvIndexedFaceSetNormals *pNormals = ((ChQvIFSRenderData *)m_pRenderData)->GetNormals();

 			// Make a material mapping; we will use later for each face
			ChQvFaceSetMaterials materialMap( this );
			pRC->AdjustTransparency(materialMap);

			int j;			// multiuse counter

			/* Get the texture map, */
			ChQvIFSTextures	*pTxMap  = new ChQvIFSTextures( this );	
			ChQvTextureRenderData *pTextureData = (ChQvTextureRenderData*)(GetTexture2()->GetRenderData());
			bool boolUseTexture = !(pTextureData->IsEmpty());  // one -might- arrive

			// Get the vertices
			QvCoordinate3 *pC3 = GetCoordinate3();

			ChNrMesh mesh = m_mesh = pRC->CreateMesh();
			ChNrFrameAddVisual(GetFrame(), mesh);
			D3DRelease(mesh);

			ChNrObjectSetAppData(mesh, (unsigned long)this);
			ChNrMeshSetPerspective(mesh,true);

			QvMaterialBinding::Binding	binding = (QvMaterialBinding::Binding)(GetMaterialBinding()->value.value);
			bool boolColorByFace = !(binding == QvMaterialBinding::PER_VERTEX || 
									binding == QvMaterialBinding::PER_VERTEX_INDEXED);

			ChNrMeshSetColorSource(mesh, boolColorByFace ? ColorFromFace : ColorFromVertex);
			 
			// Need to reserve space for vertices, normals, and faces -  ????
			int numFaces = GetFaceCount(pNode->coordIndex.values, pNode->coordIndex.num);

			// Allocate vertex and normal arrays, at least as big as we need
			int normSize = pNode->coordIndex.num;
			if(!boolBackCull) normSize *= 2;
			GxVec3f *pN = new GxVec3f[normSize];	  
			GxVec3f *pV = new GxVec3f[pNode->coordIndex.num];

			// Allocate the index arrays, to reuse as much as possible
			int * faceNorms = new int[numFaces];
			int * uniqueNorms = new int[pNode->coordIndex.num];	 // indexed by coord #
			int * sharedNorms = new int[pC3->point.num];	 //  indexed by coordIndex[j]
			int * verts = new int[pC3->point.num];	    
			int * texIndices = new int[pC3->point.num];	    	// parallel to verts
			int * texVerts = new int[pNode->coordIndex.num];	 // indexed by coord #

			for( j = 0; j< pNode->coordIndex.num; j++)
			{  
				uniqueNorms[j] = -1;	  // -1 unused
			}
			for( j = 0; j< pC3->point.num; j++)
			{  
				sharedNorms[j] = verts[j] = -1;	  // -1 unused
			}
			for( j = 0; j< numFaces; j++)
			{  
				faceNorms[j] =  -1;	  // -1 unused
			}

			// Get the coordinates; add all the vertices and normals to the mesh, and index them

			// Counters into faces, pN and pV	  
			int numN = 0;		// pN
			int	numV = 0;		// pV
			int	iface = 0;		 // current face
			int ifd = 0;		 // Index to Face Data

			int face_data_size = pNode->coordIndex.num * 2		// for faces' vertices 
								+ numFaces 				// face counts
								+ 1;					// terminator
			if(!boolBackCull) face_data_size *= 2;

			// As a worst case, we could get a triangle for almost
			// every point. To be conservative, we assume this and get 
			// lots of space for face_data
			face_data_size *= 4;		// actually need 7 ints for each triangle, instead of 2

			ChNrFaceData * face_data = new ChNrFaceData[face_data_size];

			// Set up an array to remember where each point of each face came from
			int *pSource = new int[face_data_size];		   // very conservative
			int iSource = 0;	// running index

			// Set up a table that goes coord num => face num
			int *pCoordToFace = new int[pNode->coordIndex.num];

			// j is first index into coordIndex for each face
			for(j = 0; j< pNode->coordIndex.num; j++, iface++)
			{
				// do a face
				int nVerts = VertCount(pNode->coordIndex, j);	 // # verts in -this face-

				GxVec3f n;
	
				// note that the sense of normals depend upon ccw or cw
				// if the norms point in to the front surface no shading will be done
				// on -either side-
				// Notice the back norm, if kept, is right after the front norm
				if(pNormals->IsPerFace())
				{
					pNormals->GetFaceNormal( iface,  n );
					if(faceNorms[iface] == -1)
					{
						n = -n;
						faceNorms[iface] = numN;
						if(boolBackCull && boolCCW) n = -n;
						#if (defined(FLIP_D3D_NORMALS) && defined(CH_USE_D3D))
						n = -n;
						#endif
						pN[numN++] = n;
						if(!boolBackCull) pN[numN++] = -n;
					}
				}

				for(int k = 0; k < nVerts; k++)
				{
					pCoordToFace[j+k] = iface;	   // Build table for later
				}

				bool boolConvex = IsConvex( j, nVerts );
				int	iNumFacets = 1;				// How many individual convex facets in this face

				ChTriangulator tri;

				//boolConvex = true;  // VSP : temporary fix for this release

				if(!boolConvex)
				{
					#if 1
					if(tri.Attach(pNode->coordIndex.values + j, (GxVec3f*)(pC3->point.values), nVerts))
					{
						iNumFacets = tri.GetCount();
					}
					else
					{
						boolConvex = true;	// triangulation failed. Proceed as if convex
					}
					#endif
				}

				for( int iFacet	= 0; iFacet < iNumFacets; iFacet++)
				{
					int nVertsFacet = boolConvex ? nVerts : 3;
					face_data[ifd] = nVertsFacet;
					if(!boolBackCull) face_data[ifd+2*nVertsFacet+1] = nVertsFacet;
					ifd++;

					int	triIndex[3];

					if(!boolConvex)
					{
						tri.GetTriangle(iFacet, triIndex);
					}
					for(int k = 0; k < nVertsFacet; k++)
					{
						int normIndex;
						int vertIndex;
						int iVertNumber;
						if(boolConvex)
						{
							iVertNumber = j + k;
						}
						else
						{
							iVertNumber = j + triIndex[k];
						}
						int index = pNode->coordIndex.values[iVertNumber];
					
						// First, add a vert to the vert array, and remember where in pV it is
						// To save even more space, we could build a tree where the key is index + texIndex
						// But that would be slower, probably.
						if(boolUseTexture) 
						{
							int texIndex = pTxMap->GetIndex(iVertNumber);
							vertIndex = -1;
							if(verts[index] == -1)
							{
								// Store the first occurrence of a unique vertex into pV, and save where
								// pV will store all the -used- vertices from the C3 node
								// Also save the tex index, so we can see on later verts if their
								// tex coords match. If so, we'll be able to reuse this vertex.
								// This enforces the rule: Different tex coords ==> different verts
								int iC3 = index * 3;
								GxVec3f p;
								p.x() = pC3->point.values[iC3];
								p.y() = pC3->point.values[iC3+1];
								p.z() = pC3->point.values[iC3+2];
								verts[index] = numV;
								vertIndex = numV;
								pV[numV++] = p;
								texIndices[index] = texIndex;
							}
							else if(texIndices[index] == texIndex)
							{
								vertIndex = verts[index];	// tex coords match, use the shared array
							}
							else
							{
								int iC3 = index * 3;	  // Use the unshared array
								GxVec3f p;
								p.x() = pC3->point.values[iC3];
								p.y() = pC3->point.values[iC3+1];
								p.z() = pC3->point.values[iC3+2];
								texVerts[iVertNumber] = numV;
								vertIndex = numV;
								pV[numV++] = p;
							}

						}
						else
						{
							if(verts[index] == -1)
							{
								// Store the first occurrence of a unique vertex into pV, and save where
								// pV will store all the -used- vertices from the C3 node
								int iC3 = index * 3;
								GxVec3f p;
								p.x() = pC3->point.values[iC3];
								p.y() = pC3->point.values[iC3+1];
								p.z() = pC3->point.values[iC3+2];
								verts[index] = numV;
								vertIndex = numV;
								pV[numV++] = p;
							}
							else
							{
								vertIndex = verts[index];
							}
						
						}
						// Get the normal, if it's by vertex or default ....
						// We store it in one of three arrays, and remember its index
						// in the pN array
						if(pNormals->IsPerFace())
						{
							normIndex = faceNorms[iface];
						}
						else if(pNormals->IsPerVertex())
						{	
							// This could be better if we saved 
							// by normal index instead of vertNumber					
							pNormals->GetVertexNormal( iVertNumber,  n );
							n = -n;
							if(uniqueNorms[iVertNumber] == -1)
							{
								uniqueNorms[iVertNumber] = numN;
								//	n.z() = -n.z();

								if(boolBackCull && boolCCW) n = -n;
								#if (defined(FLIP_D3D_NORMALS) && defined(CH_USE_D3D))
								n = -n;
								#endif
								pN[numN++] = n;
								if(!boolBackCull) pN[numN++] = -n;
							}
							normIndex = uniqueNorms[iVertNumber];
						}
						else
						{
							chuint32 normFlag;
							pNormals->GetDefaultNormal( iVertNumber, iface,  n, normFlag );
							n = -n;
							#if (defined(FLIP_D3D_NORMALS) && defined(CH_USE_D3D))
							n = -n;
							#endif
							if(normFlag & GX_NORMAL_FACE)
							{
								if(faceNorms[iface] == -1)
								{
									faceNorms[iface] = numN;
									if(boolBackCull && boolCCW) n = -n;
									pN[numN++] = n;
									if(!boolBackCull) pN[numN++] = -n;
								}
								normIndex = faceNorms[iface];
							}
							else if(normFlag & GX_NORMAL_ALL_FACES)
							{
								if(sharedNorms[index] == -1)
								{
									sharedNorms[index] = numN;
									if(boolBackCull && boolCCW) n = -n;
									#if (defined(FLIP_D3D_NORMALS) && defined(CH_USE_D3D))
									n = -n;
									#endif
									pN[numN++] = n;
									if(!boolBackCull) pN[numN++] = -n;
								}
								normIndex = sharedNorms[index];
							}
							else
							{
								if(uniqueNorms[iVertNumber] == -1)
								{
									uniqueNorms[iVertNumber] = numN;
									if(boolBackCull && boolCCW) n = -n;
									#if (defined(FLIP_D3D_NORMALS) && defined(CH_USE_D3D))
									n = -n;
									#endif
									pN[numN++] = n;
									if(!boolBackCull) pN[numN++] = -n;
								}
								normIndex = uniqueNorms[iVertNumber];
							}
						}

						// Whew, now we have indices for both vert and norm, so add them to 
						// the face_data

						int bump = 0;
						if(!boolBackCull || !boolCCW)
						{
							face_data[ifd+k*2] = vertIndex;
							face_data[ifd+k*2+1] = normIndex++;
							bump = 2 * nVertsFacet + 1;
							pSource[iSource+k] = iVertNumber;
						}

						// Add backface index
						if(!boolBackCull || boolCCW)
						{
							int reverseIndex = ifd + 2 * nVertsFacet - 2 * k - 2 + bump;
							face_data[reverseIndex] = vertIndex;
							face_data[reverseIndex + 1] = normIndex;
							pSource[iSource + nVertsFacet - k - 1 + (bump?nVertsFacet:0)] = iVertNumber;
						}

					
					}
					ifd += nVertsFacet * 2;
					iSource += nVertsFacet;
					if (!boolBackCull)
					{
						ifd += nVertsFacet * 2 + 1;
						iSource += nVertsFacet;
					}
				}
				j += nVerts;   	 // next face  -- the j++ in loop bumps over -1
			}


			face_data[ifd] = 0;

			// Load the verts and faces
			ChNrFaceArray facesAdded;
			int numFacesAdded;
			ChNrMeshAddFaces(mesh,
					       numV,
					       (ChNrVector*) pV,
					       numN,
					       (ChNrVector*) pN,
					       face_data,
					       &numFacesAdded,
					       &facesAdded);
		
			// Assign colors and textures to faces
			int inc = 1;
			if(!boolBackCull) inc *= 2;	 // only every other face if we did back faces
 			unsigned int ifacet;

			#if defined(CH_USE_D3D)
			numFacesAdded = facesAdded->GetSize();
			#endif

			for( ifacet = 0, j = 0; int(ifacet) < numFacesAdded; ifacet += inc)
			{
				ChNrFace elt;
				int count = ChNrFaceGetVertexCount(GetElement(facesAdded, ifacet, elt));
				D3DRelease(elt);

				for(int k = 0; k < count; k++)
				{				
 					iSource = j * inc + k;
					if(boolCCW && boolBackCull)
					{
						// reverse the texture && material coords; we already reversed the vertex order
						//iSource = j + count - k - 1; 
					}
					int	iVertNumber = pSource[iSource];
					int iface = pCoordToFace[iVertNumber];

					int index = ChNrFaceGetVertexIndex(GetElement(facesAdded,ifacet, elt), k);
					D3DRelease(elt);

					if(boolUseTexture) 
					{
						int iC3 = pNode->coordIndex.values[iVertNumber] * 3;
						GxVec3f textCoord = pTxMap->GetCoord3(iVertNumber, pC3->point.values+iC3);
						ChNrMeshSetTextureCoordinates(mesh, index, textCoord.x(), textCoord.y());
					}
					if(k == 0 || !boolColorByFace)
					{
						// Color the verts if necessary, but just faces if possible
						int iVert = boolColorByFace ? -1 : index;  // -1 means set face color
						materialMap.Set(mesh, GetElement(facesAdded, unsigned(ifacet), elt), iVert, iface, iVertNumber);
						D3DRelease(elt);
					}
				}

				// If we applied a color to the face for some reason (like transparency)
				// we need to copy that color to the backface, if there is one
				// BUG HERE! We are not handling meshes with a mixture of transparency 
				// and opaque
				if( inc > 1  /*!boolBackCull && (ChNrMeshGetColorSource(mesh) == ColorFromFace )*/)
				{
					ChNrFace elt;
					ChNativeColor color = ChNrFaceGetColor(GetElement(facesAdded, ifacet, elt));
					D3DRelease(elt);
					ChNrFaceSetColor(GetElement(facesAdded, ifacet+1, elt), color);
					D3DRelease(elt);
				}

				j += count;
			}

			m_boolCanCollapse = (ChNrMeshGetColorSource(mesh) == ColorFromFace );
			//ChNrFrameSetColor(m_frame, RLCreateColorRGBA(RLVal(0.6), RLVal(0.6), RLVal(0.6),
			//	RLVal(0.4)));

			if(boolUseTexture)
			{
				// This is in case the texture is already arrived
				ChTextureHandle hdl = pTextureData->GetTextureHandle();
				if(hdl)
				{
					// Texture guy got here first, apply it
					//ChNrMeshSetTexture(mesh, hdl);
					SetTexture(pTextureData);

				}
			}  


		 	// Cleanup
			delete [] pN;
			delete [] pV;
			delete [] faceNorms;
			delete [] uniqueNorms;
			delete [] sharedNorms;
			delete [] verts;
			delete [] face_data;
			delete [] texIndices;
			delete [] texVerts;
			delete [] pSource;
			delete [] pCoordToFace;

			ChNrFree(facesAdded);							  
			delete pTxMap;

		}
		else
		{
			// Notify them of the bad node TODO
		}

		pIterator->DidAShape();
		pRC->UnlockQv();
		pRC->UnlockScene();		
	}
#endif
	return true;
}

bool ChQvIFSInstance::Draw(ChRenderContext *pRC, ChDrawIterator *pIterator)
{
#if defined( CH_USE_3DR )
	{
		G3dHandle_t hGC = pRC->GetGC();
		Dword_t  hRC = pRC->GetRC();
		QvIndexedFaceSet *pNode = (QvIndexedFaceSet *)GetNode();
		pRC->SetModelTransform(GetTransform());

		pRC->SetShading(this);

		Fixed32_t wMattNum = 0;	  // for now always use material 0
		G3dSetCurrentMatt(hGC, wMattNum );

		// Interpret shapehints; we assume there is at least one there; (we inited to make sure)
		Fixed32_t lIsCCW = (GetShapeHints()->vertexOrdering.value == QvShapeHints::COUNTERCLOCKWISE);
	    G3dSetState( hGC, G3DL_FRONT_CCW, &lIsCCW);

		// Figure out if we can backcull. solid + known order means we can
		bool boolBackCull = ((GetShapeHints()->vertexOrdering.value != QvShapeHints::UNKNOWN_ORDERING) &&
					(GetShapeHints()->shapeType.value == QvShapeHints::SOLID));
		Float_t		cull = boolBackCull;
		G3dSetMatt( hGC,  wMattNum, G3DM_BACK_CULL,	(Float_t *)&cull );
	
		// Make a material mapping; we will use later for each face
		ChQvFaceSetMaterials materialMap( this );	// making this is cheap; don't cache

		// Normals
		int	face = 0;

									/* If they can't write good nodes, don't draw them! */				 
		if(((ChQvIFSRenderData *)m_pRenderData)->IsValid())
		{
		
			ChQvIndexedFaceSetNormals *pNormals = ((ChQvIFSRenderData *)m_pRenderData)->GetNormals();


			/* Do the texture stuff - find it, make the map, set up 3dr for it, */
			int boolUseTexture = false;
	
			ChQvTextureRenderData *pTextureData = 0;
			pTextureData = (ChQvTextureRenderData*)(GetTexture2()->GetRenderData());
			if (pTextureData->GetTextureHandle()) boolUseTexture = true;
	
			ChQvIFSTextures	*pTxMap = 0;
	 
			if(boolUseTexture)
			{
				pRC->SetTexture(pTextureData->GetTextureHandle());
				pTxMap = new ChQvIFSTextures( this );	// efficient except for many-faced
															// textured ifs' with default map,
															// which are unlikely because they
															// would be b ugly, so don't
															// bother to cache. People who make
															// ugly ifs' deserve it.
			}

			// Get the coordinates
			QvCoordinate3 *pC3 = GetCoordinate3();
			for(int j = 0; j< pNode->coordIndex.num; j++)	   //coordIndex.values[j] != QV_END_FACE_INDEX
			{
				// do a face
				int nVerts = VertCount(pNode->coordIndex, j);

				// Set the material
				bool boolPureEmissive;
				materialMap.Set(hRC, hGC, face, j, &boolPureEmissive);
				pRC->SetModulation( boolUseTexture, boolPureEmissive);

				G3dBeginPrim(hGC, G3D_PRM_POLYGON, nVerts);
				PointF_t n, v1, v2, v0;
				Qv2Native(pC3->point,pNode->coordIndex.values[j+0],v0); 
				Qv2Native(pC3->point,pNode->coordIndex.values[j+1],v1); 
				Qv2Native(pC3->point,pNode->coordIndex.values[j+2],v2);
	
				v1.x -= v0.x; v1.y -= v0.y; v1.z -= v0.z; 
				v2.x -= v0.x; v2.y -= v0.y; v2.z -= v0.z;
				Fixed32_t lCCW = true;
				G3dGetState( hGC, G3DL_FRONT_CCW, &lCCW);
				// note that the sense of normals depend upon ccw or cw
				// if the norms point in to the front surface no shading will be done
				// on -either side-
				if(pNormals->IsPerFace())
				{
					pNormals->GetFaceNormal( face,  (GxVec3f&)n );
					if (!lCCW)
					{
						n.x = -n.x; n.y = -n.y; n.z = -n.z; 
					}
				}


				int k = 0;
			
				Float_t alpha;
				G3dGetMatt( hGC,  wMattNum, G3DM_ALPHA,    (Float_t *)&alpha     );
				if (IsTransparent(alpha))
				{
					while(pNode->coordIndex.values[j] != QV_END_FACE_INDEX)
					{
						j++;	k++; 
					}
				}
				else
			
				{
					while(j < pNode->coordIndex.num && pNode->coordIndex.values[j] != QV_END_FACE_INDEX)
					{
						PointF_t p;

						int index = pNode->coordIndex.values[j] * 3;
						p.x = pC3->point.values[index];
						p.y = pC3->point.values[index+1];
						p.z = pC3->point.values[index+2];
						// Get the normal, if it's by vertex or default ....
						if(!pNormals->IsPerFace())
						{							
							if(pNormals->IsPerVertex())
							{						
								pNormals->GetVertexNormal( j,  (GxVec3f&)n );
							}
							else
							{
								pNormals->GetDefaultNormal( j, face,  (GxVec3f&)n );
							}
							if (!lCCW)
							{
								n.x = -n.x; n.y = -n.y; n.z = -n.z; 
							}
						}

						if(boolUseTexture)
						{
							PointF_t textCoord = pTxMap->GetCoord3(j, pC3->point.values+index);

							G3dAddPrimVtxF(hGC, &p, &n, &textCoord, 0);
						}
						else
						{
							G3dAddPrimVtxF(hGC, &p, &n, 0, 0);
						}
						j++;	k++; 
					}
					G3dEndPrim(hGC);
				}
				//delete pTextCoord;
				face++;
			}
			if(boolUseTexture)
			{
				pRC->SetTexture(0);							// turn off texture
				delete pTxMap;
			}
		}
	}
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#else
#endif
	return true;
}


ChQvILSInstance::ChQvILSInstance() : ChQvShapeInstance()
{
}

bool ChQvILSInstance::Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	{
		ASSERT(m_frame );
		pRC->LockQv();		   // Lock tree so other threads don't kill our data
		if(!pIterator->IsOKToProceed(this))	 // This locks scene if available
		{
			pRC->UnlockQv();		   // Unlock tree 
			return 0;
		}
		if(IsConstructed())
		{
			pRC->UnlockScene();
			pRC->UnlockQv();		   // Unlock tree 
			return 1;
		}
		m_boolConstructed = true;
		
		

		QvIndexedLineSet *pNode = (QvIndexedLineSet *)GetNode();

		// Interpret shapehints; we assume there is at least one there; (we inited to make sure)
		// Remember that RL CW is opposite from VRML (LHS ~ RHS)
		bool boolCCW = (GetShapeHints()->vertexOrdering.value == QvShapeHints::COUNTERCLOCKWISE);
		bool boolDirectionKnown = !(GetShapeHints()->vertexOrdering.value == QvShapeHints::UNKNOWN_ORDERING);

		// Figure out if we can backcull. solid + known order means we can
		bool boolBackCull = ((GetShapeHints()->vertexOrdering.value != QvShapeHints::UNKNOWN_ORDERING) &&
					(GetShapeHints()->shapeType.value == QvShapeHints::SOLID));


									/* If they can't write good nodes, don't draw them! */				 
		if(pNode->coordIndex.num >= 2 && 
			pNode->coordIndex.values[0] >= 0 &&
			pNode->coordIndex.values[1] >= 0)	 /* need to validate someday*/
		{
		

 			// Make a material mapping; we will use later for each face
			ChQvLineSetMaterials materialMap( this );
			pRC->AdjustTransparency(materialMap);

			int	iface = 0;

			/* Get the texture map, */
			//ChQvILSTextures	*pTxMap  = new ChQvILSTextures( this );	

			// Get the vertices
			int vertIndex = 0;
			QvCoordinate3 *pC3 = GetCoordinate3();

			ChNrMesh mesh = m_mesh = pRC->CreateMesh();
			ChNrFrameAddVisual(GetFrame(), mesh);
			D3DRelease(mesh);

			ChNrObjectSetAppData(mesh, (unsigned long)this);
			ChNrMeshSetColorSource(mesh,ColorFromFace); // alternative: ColorFromFace 
			ChNrMeshSetPerspective(mesh,true);  
			ChNrMeshSetQuality(mesh,RenderWireframe);  

			// Decide how many normals to store; we need both front and back if not backculled
			int numNorms = 0;

			// Need to reserve space for vertices, normals, and faces - 
			int numFaceEstimate = 5;
			numFaceEstimate = GetFaceCount(pNode->coordIndex.values, pNode->coordIndex.num);
			ChNrMeshReserveSpace(mesh, pNode->coordIndex.num, 
							numNorms, numFaceEstimate);  

			// just to test speed diff:
			//ChNrMeshSetLightingFrequency(mesh,ChNrLightOnce); // alternative: ChNrLightContinually 

			// Get the coordinates; add all the vertices and normals to the mesh, and index them
			int *pVertIndices = new int[pNode->coordIndex.num];

			int normIndex		=	ChNrMeshAddNormal(mesh, 0, 0, -1);
			for(int j = 0; j< pNode->coordIndex.num; j++, iface++)
			{
				// do a face
				int nVerts = VertCount(pNode->coordIndex, j);

				for(int k = 0; k < nVerts; k++)
				{
					GxVec3f p;

					int index = pNode->coordIndex.values[j+k] * 3;
					p.x() = pC3->point.values[index];
					p.y() = pC3->point.values[index+1];
					p.z() = pC3->point.values[index+2];

					pVertIndices[j + k]		=	ChNrMeshAddVertex(mesh, p.x(), p.y(), p.z());
					#if 0
					if(pTxMap)
					{
						GxVec3f textCoord = pTxMap->GetCoord3(j, pC3->point.values+index);
						ChNrMeshSetTextureCoordinates(mesh, pVertIndices[j + k], 
												textCoord.x(), textCoord.y());
					}
					#endif
					
					vertIndex++; 
				}
				j += nVerts;   	 // next face
			}

			// Now add the faces, and associate with verts and normals
			for(j = 0, iface = 0; j< pNode->coordIndex.num; j++, iface++)
			{
				// do a face
				int nVerts = VertCount(pNode->coordIndex, j);

				// We draw both faces if not back culling; if back culling,
				// render it CCW, like RL wants for a front, in our rhs system.

				// Create a face - CCW (according to VRML's RHS)
				if(!boolBackCull || !boolCCW)
				{		  
					#if 0
					ChNrFace face = ChNrMeshCreateFace(mesh);
					ChNrObjectSetAppData(face, (unsigned long)this);
					ChNrFaceSetColorRGB( face, 1, 1, 1);	// black for now 
					#endif
			
					for(int k = 0; k < nVerts - 1; k++)
					{
						ChNrFace face;
						ChNrMeshCreateFace(mesh, face);
						D3DRelease(face);

						ChNrObjectSetAppData(face, (unsigned long)this);
						ChNrFaceAddVertexAndNormalIndexed(face, pVertIndices[j+k], 0);
						ChNrFaceAddVertexAndNormalIndexed(face, pVertIndices[j+k+1], 0);
						ChNrFaceAddVertexAndNormalIndexed(face, pVertIndices[j+k], 0); // retrace our steps
						materialMap.Set(mesh, face, -1 /*pVertIndices[j + k]*/, iface ,j + k);
					}

					#if 0
					// Old way -used a solid face - this is wrong!
					for(int k = 0; k < nVerts; k++)
					{
						ChNrFaceAddVertexAndNormalIndexed(face, pVertIndices[j+k], 0);
						materialMap.Set(mesh, face, -1 /*pVertIndices[j + k]*/, iface ,j + k);
					}
					for(k = nVerts - 2; k >= 0; k--)	 // retrace our steps
					{
						ChNrFaceAddVertexAndNormalIndexed(face, pVertIndices[j+k], 0);
						materialMap.Set(mesh, face, -1 /*pVertIndices[j + k]*/, iface ,j + k);
					}
					#endif

				}
				// Add the other face - CW
				#if 0
				// Turns out this is not needed if we do the new forward and back trick above
				if(!boolBackCull || boolCCW)
				{
					#if 0		  
					ChNrFace face = ChNrMeshCreateFace(mesh);
					ChNrObjectSetAppData(face, (unsigned long)this);
					ChNrFaceSetColorRGB( face, 0, 0, 0);	// black for now 
					#endif
			
					float transparency = 0;	// TODO
			
					if (IsTransparent(transparency))
					{
						// skip it for now
					}
					else
					{
						for(int k = 0; k < nVerts; k++)
						{
							int index = j + nVerts - k - 1;
							ChNrFaceAddVertexAndNormalIndexed(face, pVertIndices[index], 0);
							// maybe this should depend on boolBackCull whether to do this, but
							// It -does- set the material for the face, in addition to the color 
							// of the vertex
							materialMap.Set(mesh, face, -1 /*pVertIndices[index]*/, iface , index);
						}
						for(k = nVerts - 2; k >= 0; k--)
						{
							int index = j + nVerts - k - 1;
							ChNrFaceAddVertexAndNormalIndexed(face, pVertIndices[index], 0);
							// maybe this should depend on boolBackCull whether to do this, but
							// It -does- set the material for the face, in addition to the color 
							// of the vertex
							materialMap.Set(mesh, face, -1 /*pVertIndices[index]*/, iface , index);
						}
					}
				}
				#endif
				j += nVerts;	 // next face

			}
			delete [] pVertIndices;

			ChNrMeshSetQuality(mesh,RenderWireframe);  

		}
		else
		{
			ChNrFrame parent;
			ChNrFrameGetParent(m_frame, parent);
			ChNrFrameRemoveChild(parent, m_frame);
			m_frame = 0;
			m_mesh = 0;
			// Notify them of the bad node TODO

		}
			
		pIterator->DidAShape();
		pRC->UnlockScene();		
		pRC->UnlockQv();		   // Unlock tree 
	}
#endif
	return true;
}

bool ChQvILSInstance::Draw(ChRenderContext *pRC, ChDrawIterator *pIterator)
{
#if defined( CH_USE_3DR )
	Fixed32_t On = 1;
	G3dHandle_t hGC = pRC->GetGC();
	Dword_t  hRC = pRC->GetRC();
	QvIndexedLineSet *pNode = (QvIndexedLineSet *)GetNode();
	pRC->SetModelTransform(GetTransform());

	pRC->SetShading(this);
	#if 0
        R3dSetState( GetRC(), R3D_STA_DISABLES, R3D_SE_SHADING);
        G3dSetState( GetGC(), G3DL_FLAT_SHADING, &On);
	#endif

	Dword_t disabled = ( hRC, R3D_STA_DISABLES );
	Dword_t enabled = ( hRC, R3D_STA_ENABLES );
	Fixed32_t oldShading;
    G3dGetState( hGC, G3DL_FLAT_SHADING, &oldShading);
    G3dSetState( hGC, G3DL_FLAT_SHADING, &On);
    R3dSetState( hRC, R3D_STA_DISABLES, R3D_SE_SHADING);

	R3dSetState( hRC, R3D_STA_ENABLES, R3D_SE_CLIPPING);	// avoid 3dr clipping crash

	Fixed32_t wMattNum = 0;	  // for now always use material 0
	G3dSetCurrentMatt(hGC, wMattNum );

	Float_t		cull = false;
	G3dSetMatt( hGC,  wMattNum, G3DM_BACK_CULL,	(Float_t *)&cull );

	// Make a material mapping; we will use later for each face
	ChQvLineSetMaterials materialMap( this );	// making this is cheap; don't cache

	// Normals
	int	face = 0;
	int boolUseNorms;
	boolUseNorms = false;	// make my own for now; only face defined; NEED to improve
							// to work like Inventor


	/* Do the texture stuff - find it, make the map, set up 3dr for it, */
	int boolUseTexture = false;
	
	ChQvTextureRenderData *pTextureData = 0;
	pTextureData = (ChQvTextureRenderData*)(GetTexture2()->GetRenderData());
	if (pTextureData->GetTextureHandle()) boolUseTexture = true;
	 
	ChQvILSTextures	*pTxMap = 0;
	if(boolUseTexture)
	{
		pRC->SetTexture(pTextureData->GetTextureHandle());
		pTxMap = new ChQvILSTextures( this );	
	}
	R3dSetState( hRC, R3D_STA_DISABLES, R3D_SE_PATTERNING );  // solid line

	// Get the coordinates
	QvCoordinate3 *pC3 = GetCoordinate3();
	for(int j = 0; j< pNode->coordIndex.num; j++)	   //coordIndex.values[j] != QV_END_FACE_INDEX
	{
		// do a face
		int nVerts = VertCount(pNode->coordIndex, j);

		if(nVerts > 1)
		{
			// Set the material
			bool boolPureEmissive;
			materialMap.Set(hRC, hGC, face, j, &boolPureEmissive);

			#if 1
			{
				ColorFA_t color, diff, emissive;
				G3dGetMatt(hGC, 0, G3DM_DIFFUSE, (float*)&diff);
				G3dGetMatt(hGC, 0, G3DM_EMIT, (float*)&emissive);
				ColorFA_t black = {0.,0., 0., 0.};

				// We're using prelit colors
				// Bogus em up by assuming a light value of  white .75
				// ignoring specular and Lambertian effects
				// Conversely, you could assume light = 1 and cos(theta) = .75 for diffuse
				//color.r = diff.r * .75 + emissive.r;
				//color.g = diff.g * .75 + emissive.g;
				//color.b = diff.b * .75 + emissive.b;
				color.r = max(diff.r, emissive.r);
				color.g = max(diff.g, emissive.g);
				color.b = max(diff.b, emissive.b);
				color.a = 1.0;
				G3dSetMatt(hGC, 0, G3DM_EMIT, (float*)&color);
				G3dSetMatt(hGC, 0, G3DM_DIFFUSE, (float*)&black);
				G3dSetMatt(hGC, 0, G3DM_BACK_EMIT, (float*)&color);
				G3dSetMatt(hGC, 0, G3DM_BACK_DIFFUSE, (float*)&black);
				boolPureEmissive = true;
			}
			#endif
			pRC->SetModulation( boolUseTexture, boolPureEmissive);

			//G3dBeginPrim(hGC, G3D_PRM_POLYLINE, nVerts);
			PointF_t n = {0., 1., 0.};
			// Do our own allocation
			PointF_t *points = new PointF_t[nVerts];
			PointF_t *normals = 0;
			normals = new PointF_t[nVerts];
			ColorFA_t *colors = new ColorFA_t[nVerts];
			PointF_t *textures = 0;
			if (boolUseTexture) textures = new PointF_t[nVerts];

			GxVec3f fn( 0, 0, 0 ) ;

			int i = j;
			int first = i ;
			long* coords = pNode->coordIndex.values;
			GxVec3f* verts = (GxVec3f*) (pC3->point.values);  // sneaky - depends on QV pts being same layout
															  // assumes 4 byte alignment or less
			while ( i + 1 < pNode->coordIndex.num && coords[i+1] != -1 )
			{
				fn += verts[coords[i]].cross( verts[coords[i+1]] ) ;
				i++ ;
			}
			fn += verts[coords[i]].cross( verts[coords[first]] ) ;

			fn.normalize() ;

			CopyPoint(fn, n);

			int k = 0;
			while( j < pNode->coordIndex.num && pNode->coordIndex.values[j] != QV_END_FACE_INDEX)
			{
				PointF_t p;

				int index = pNode->coordIndex.values[j] * 3;
				p.x = pC3->point.values[index];
				p.y = pC3->point.values[index+1];
				p.z = pC3->point.values[index+2];
				// Get the normal
				if(boolUseNorms)
				{	
				#if 0
					int nrmJ = boolByFace ? face : j;
					int normIndex = normalIndex.values[nrmJ]*3;
					n.x = pNC3->point.values[normIndex];   
					n.y = pNC3->point.values[normIndex+1]; 
					n.z = pNC3->point.values[normIndex+2]; 
				#endif
				}
				else
				{
				}
				if(boolUseTexture)
				{
					PointF_t textCoord = pTxMap->GetCoord3(j, pC3->point.values+index);
					textures[k] = textCoord;
					//G3dAddPrimVtxF(hGC, &p, &n, &textCoord, 0);
				}
				else
				{

					//G3dAddPrimVtxF(hGC, &p, &n, 0, 0);
					//G3dAddPrimVtxF(hGC, &p, 0, 0, &black);
				}
				ColorFA_t black = {0.,0., 0., 1.};
				if(normals) normals[k] = n;
				points[k] = p;
				colors[k] = black;

				j++;	k++; 
			}
			try
			{
				#if 0
					for(int m = 0; m < nVerts - 1; m++)
					{
						G3dPrimitiveF(hGC, G3D_PRM_POLYLINE, 2,
									points + m, sizeof(PointF_t), 
									normals + m, sizeof(PointF_t), 
									0, sizeof(PointF_t), 
									0, sizeof(ColorFA_t) );

					}
				#else
				G3dPrimitiveF(hGC, G3D_PRM_POLYLINE, nVerts,
							points, sizeof(PointF_t), 
							normals, sizeof(PointF_t), 
							textures, sizeof(PointF_t), 
							colors, sizeof(ColorFA_t) );
				#endif
			}
			catch (...)
			{
				//TRACE("Exception in drawing lines caught\r\n");
			}

			delete	[] points;
			delete	[] normals;
			delete	[] textures;
			delete	[] colors;
			//G3dEndPrim(hGC);
		}
		else
		{
			j += nVerts;				// bad line; only zero or one point, skipped
		}
		//delete pTextCoord;
		face++;
	}
	if(boolUseTexture)
	{
		pRC->SetTexture(0);							// turn off texture
		delete pTxMap;
	}

	R3dSetState( hRC, R3D_STA_DISABLES, disabled ); 
	R3dSetState( hRC, R3D_STA_ENABLES, enabled);
    G3dSetState( hGC, G3DL_FLAT_SHADING, &oldShading);
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

#endif //defined( CH_USE_3DR )
	return true;
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
bool ChQvILSInstance::SetTexture(ChQvTextureRenderData *pTextureData, ChNrMesh mesh)
{
	return false;	// false says nothing happened
}
#endif


// Spheres

ChQvSphereInstance::ChQvSphereInstance() : ChQvShapeInstance()
#if (defined(CH_IMMED_MODE) && defined(CH_USE_RLAB))
, m_rlMaterial(0)
#endif
{
}

ChQvSphereInstance::~ChQvSphereInstance()
{
#if (defined(CH_IMMED_MODE) && defined(CH_USE_RLAB))
	if(m_rlMaterial) ChNrObjectDestroy(m_rlMaterial);
	m_rlMaterial = 0;
#endif
}

// sphere helper for drawing

class myStripIter : public GxSphereTriStripIterator
{
		chint32 *m_plVert;
		chint32 m_lNumVerts;
		ChRenderContext *m_pRC ;
		ChQvSphereCacheData *m_pData;
		chint32 m_lSize;
		bool m_boolTexture;
		float m_radius;		
		ChQvSphereMaterials *m_pMaterialMap;
		ChQvTexture2TransformRenderData* m_pTex2Xform;
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		ChNrMesh m_mesh;
		#endif

	public:
		myStripIter( ChQvSphereCacheData *pData, ChRenderContext *pRC, bool boolTexture, 
			float radius, ChQvSphereMaterials *pMaterialMap, ChQvTexture2TransformRenderData* pTex2Xform ) : 
			GxSphereTriStripIterator(), m_plVert(0), m_lNumVerts(0),
			m_pRC(pRC),	m_pData(pData), m_boolTexture(boolTexture), 
			m_radius(radius), m_pMaterialMap(pMaterialMap), m_pTex2Xform(pTex2Xform)
				{
					m_lSize = m_pData->GetSphere()->Level() * 2 + 2;
					m_plVert = new chint32[m_lSize];
				};
		virtual ~myStripIter()
		{
			delete [] m_plVert;
		};

	public:
		int StartStrip( int strip )
		{
			m_lNumVerts = 0;
			return 1 ;
		}

		int StopStrip( int )
		{
			GxVec2f *pTex = m_boolTexture ? m_pData->GetTextureCoord() : 0;
			GxVec3f*pVerts = m_pData->GetVertices();
			#if defined(CH_USE_3DR)
			PointF_t tex;
			G3dBeginPrim(m_pRC->GetGC(), G3D_PRM_TRISTRIP, m_lNumVerts);
			for (int j=0; j<m_lNumVerts; j++)
			{
				PointF_t pt = *((PointF_t*)&pVerts[m_plVert[j]]);

				pt.x *= m_radius;
				pt.y *= m_radius;
				pt.z *= m_radius;
				
				if(pTex)
				{
					tex.x =  pTex[m_plVert[j]].x();
					tex.y =  pTex[m_plVert[j]].y();
					tex.z = 1.;
					//tex.x += .25;
					tex.x += .5;
					while(tex.x < 0.) tex.x += 1.;
					while(tex.x > 1.) tex.x -= 1.;
					if(m_pTex2Xform)m_pTex2Xform->Transform(tex.x, tex.y);	// ??
					G3dAddPrimVtxF(m_pRC->GetGC(), &pt, (PointF_t*)&pVerts[m_plVert[j]], &tex, 0);
				}
				else
				{
					G3dAddPrimVtxF(m_pRC->GetGC(), &pt, (PointF_t*)&pVerts[m_plVert[j]], 0, 0);
				}
			}
			G3dEndPrim(m_pRC->GetGC());
			#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))

			// Build the display list: verts, normals, and faces
			int numFaces = m_lNumVerts - 2, numVerts = m_lNumVerts, numNorms = m_lNumVerts;


			if(m_boolTexture)
			{
				// Get the coordinates; add all the vertices and normals to the mesh, and index them
				int *pVertIndices = new int[numVerts];
				int *pNormalIndices = new int[numNorms];

				GxVec3f n;
				GxVec3f v;
				for (int j=0; j<numVerts; j++)
				{
					v = *((GxVec3f*)&pVerts[m_plVert[j]]);
					//n = -v;
					n = v;
					v *= m_radius;
					pVertIndices[j] = ChNrMeshAddVertex(m_mesh, v.x(), v.y(), v.z());
					pNormalIndices[j] = ChNrMeshAddNormal(m_mesh, n.x(), n.y(), n.z());
					
					float u =  pTex[m_plVert[j]].x();
					float v =  pTex[m_plVert[j]].y();
					if(m_pTex2Xform)m_pTex2Xform->Transform(u, v);
									// VRML v is bottom==0.0 so we need to
					v = 1 - v;		// convert to RLab top-down convention for v
					ChNrMeshSetTextureCoordinates(m_mesh, pVertIndices[j], u, v);
					#if 0
					{
						float u =  pTex[m_plVert[j]].x();
						float v =  pTex[m_plVert[j]].y();
						u += .5;
						while(u < 0.) u += 1.;
						while(u > 1.) u -= 1.;
						v = 1 - v;
						if(m_pTex2Xform)m_pTex2Xform->Transform(u, v);
						v = 1 - v;
						ChNrMeshSetTextureCoordinates(m_mesh, pVertIndices[j], u, v);
					}
					#endif
				}
																	   
				for (j=0; j<numVerts - 2; j++)						   
				{
					ChNrFace face; 
					ChNrMeshCreateFace(m_mesh, face);

					ChNrFaceAddVertexAndNormalIndexed(face, 
											pVertIndices[(j & 1) ? j : (j + 1)], 
											pNormalIndices[(j & 1) ? j : (j + 1)]);
					ChNrFaceAddVertexAndNormalIndexed(face, 
											pVertIndices[(j & 1) ? (j + 1) : j], 
											pNormalIndices[(j & 1) ? (j + 1) : j]);
					ChNrFaceAddVertexAndNormalIndexed(face, 
											pVertIndices[j + 2], 
											pNormalIndices[j + 2]);
	  				m_pMaterialMap->Set(m_mesh, face);
					D3DRelease(face);
				}
				delete [] pVertIndices;
				delete [] pNormalIndices;

			}
			else
			{
				// Alloc, assign vert and norm data
				GxVec3f *n = new GxVec3f[numVerts];
				GxVec3f *v = new GxVec3f[numVerts];

				for (int j=0; j<numVerts; j++)
				{
					v[j] = *((GxVec3f*)&pVerts[m_plVert[j]]);
					//n[j] = -v[j];
					n[j] = v[j];
					v[j] *= m_radius;
				}

				// alloc face_data
				int face_data_size = numFaces * 3 * 2 		// for faces - triangles with normals
									+ numFaces 				// face counts
									+ 1;					// terminator
				ChNrFaceData * face_data = new ChNrFaceData[face_data_size];

				int 	ifd = 0; // index into face data
				for (j=0; j<numVerts - 2; j++)						   
				{
					face_data[ifd++] = 3;
					face_data[ifd++] = (j & 1) ? j : (j + 1);	  // vert               
					face_data[ifd++] = (j & 1) ? j : (j + 1);	  // norm for same, etc 
					face_data[ifd++] = (j & 1) ? (j + 1) : j;	
					face_data[ifd++] = (j & 1) ? (j + 1) : j;	
					face_data[ifd++] = j + 2;
					face_data[ifd++] = j + 2;
				}
				face_data[ifd] = 0;

				// Load the verts and faces
				ChNrFaceArray facesAdded;
				int numFacesAdded;
				ChNrMeshAddFaces(m_mesh,
						       numVerts,
						       (ChNrVector*) v,
						       numNorms,
						       (ChNrVector*) n,
						       face_data,
						       &numFacesAdded,
						       &facesAdded);
		
				#if defined(CH_USE_D3D)
				numFacesAdded = facesAdded->GetSize();
				#endif

				// Assign colors to faces
				int iface = 0;
				GxVec3f tex;
				ChNrFace elt;
				for(j = 0; j < numFacesAdded; j ++)
				{
					m_pMaterialMap->Set(m_mesh, GetElement(facesAdded, unsigned(j), elt));
					D3DRelease(elt);
				}

															  // Cleanup time
		 		ChNrFree(facesAdded);							  
				delete [] v;
				delete [] n;
				delete [] face_data;
			}

			#endif
			return 1 ;
		}

		int DoVertex( int vnum )
		{
			ASSERT(m_lSize > m_lNumVerts);
			m_plVert[m_lNumVerts++] = vnum;
			return 1 ;
		}

		int DoVertex( const GxVec3f& v )
		{
			return 1 ;
		}
		#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		ChNrMesh GetMesh() {return m_mesh;};
		void SetMesh(ChNrMesh mesh) { m_mesh = mesh; return;};
		#endif

} ;



#if (defined(CH_USE_RLAB))
void SphereFrameCallback(ChNrFrame frame, void * arg);
#else
void SphereFrameCallback(ChNrFrame frame, void * arg, float delta);
#endif

bool ChQvSphereInstance::Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	#if !defined(CH_IMMED_MODE)
	{

		pRC->LockQv();		   // Lock tree so other threads don't kill our data
		if(!pIterator->IsOKToProceed(this))	 // This locks scene if available
		{
			pRC->UnlockQv();		   // Unlock tree 
			return 0;
		}
		if(IsConstructed())
		{
			pRC->UnlockScene();
			pRC->UnlockQv();		   // Unlock tree 
			return 1;
		}
		
		ASSERT(m_frame );

		// Compute the tesselation level desired, then fetch it
		// We start with the current tesselation, then auto lod it as needed

		// Don't need to lock access to these; nobody else can read them yet
		// until we launch a reconstruction thread, or install the callback
		m_iBackLevel =  0;

		m_iCurrentLevel = GetLevel(pRC);
		m_backMesh = 0;
		//m_iCurrentLevel = 1;

		m_mesh = BuildMesh(pRC, m_iCurrentLevel);
		ChNrFrameAddVisual(GetFrame(), m_mesh);

		#if defined(CH_SPHERE_LOD)
		// Install the callback, which will do loding
		ChNrFrameAddCallback(m_frame, SphereFrameCallback, this);

		#endif
						   

		pIterator->DidAShape();
		m_boolConstructed = true;
		pRC->UnlockScene();		
		pRC->UnlockQv();		   // Unlock tree 
	}
	#endif // IMMED_MODE
#endif
	return true;
}

bool ChQvSphereInstance::Draw(ChRenderContext *pRC, ChDrawIterator *pIterator)
{
#if defined( CH_USE_3DR )
	{
		Fixed32_t On = 1;
		Fixed32_t Off = 0;
		G3dHandle_t hGC = pRC->GetGC();
		Dword_t  hRC = pRC->GetRC();
		QvSphere *pNode = (QvSphere *)GetNode();
		pRC->SetModelTransform(GetTransform());

		pRC->SetShading(this);

		Float_t		cull = 1;
		Fixed32_t wMattNum = 0;	  // always use material 0

		G3dSetMatt( hGC,  wMattNum, G3DM_BACK_CULL,	(Float_t *)&cull );
	
		// Make a material mapping; we will use later 
		ChQvSphereMaterials materialMap( this );

		/* Do the texture stuff - find it, make the map, set up 3dr for it, */
		int boolUseTexture = SetupTexture(pRC);

		Fixed32_t lCCW;
		G3dGetState( hGC, G3DL_FRONT_CCW, &lCCW); // save CCW state
		G3dSetState( hGC, G3DL_FRONT_CCW, &On);	  // ????

		bool boolPureEmissive;

		// Compute the tesselation level desired, then fetch it
		ChQvSphereCacheData * pCache = pRC->GetSphere(GetLevel(pRC));
		ChQvTexture2TransformRenderData* m_pTex2Xform =
				((ChQvTexture2TransformRenderData*)(GetTexture2Transform()->GetRenderData()));
	
		// Do the facets
		{
			materialMap.Set(hRC, hGC, &boolPureEmissive);
			pRC->SetModulation( boolUseTexture, boolPureEmissive);
			// so draw the thing
			myStripIter stripIter(pCache, pRC, boolUseTexture, pNode->radius.value, &materialMap, m_pTex2Xform);
			stripIter.Attach(*(pCache->GetSphere()));
			stripIter.Iterate(GxSphere::Indexed);
		}


		G3dSetState( hGC, G3DL_FRONT_CCW, &lCCW);
		if(boolUseTexture)
		{
			pRC->SetTexture(0);							// turn off texture
		}
	}
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	#if defined(CH_IMMED_MODE)

		bool boolClipped;
		ChRect rtExtent = GetBoundsExtent(pRC, 0, &boolClipped, false);

		// Render if not completely clipped
		// Cull utterly if invisible
		if(!boolClipped)
		{
			m_iCurrentLevel = GetLevel(pRC, rtExtent, boolClipped);
			//if(m_iCurrentLevel <= 1) ::AfxTrace("extent = %d %d %d %d\n", rtExtent.left, rtExtent.top, rtExtent.right, rtExtent.bottom);

			// Look at texture node every time. That way, we don't have to worry 
			// about updating when it arrives

			bool boolUseTexture = false;
			ChQvTextureRenderData *pTextureData = 0;
			pTextureData = (ChQvTextureRenderData*)(GetTexture2()->GetRenderData());
			ChTextureHandle hdl = pTextureData->GetTextureHandle();


			bool boolRedoMaterial = false;

			if(!m_rlMaterial || m_colorModel != ChNrDeviceGetColorModel(pRC->GetRC()))
			{
				boolRedoMaterial = true;
			}
			else if(hdl && (hdl != m_hTexture || !m_sInfo.texture))
			{
				boolRedoMaterial = true;
			}
			else if(m_colorModel == RLColourRamp && !RLIMColourStillValid(pRC->GetViewport(), &m_sInfo))
			{
				boolRedoMaterial = true;
			}


			if(boolRedoMaterial)
			{
				RLColourModel oldModel = m_colorModel;
				m_colorModel = ChNrDeviceGetColorModel(pRC->GetRC());

				ChQvSphereMaterials materialMap( this );
				ChMaterial material = materialMap.GetMat( 0 );

				m_boolIsPrelit = material.IsPrelit();
				// This needs to be tweaked for cache dirtying
				// Also get rid of m_rlMaterial - it's redundant
				float ks = 0., shine = material.GetNativeShininess();
				ChColorA specular = material.GetSpecular();
				if(m_colorModel == RLColourRGB)
				{
				
					if(specular.r() > 0. || specular.g() > 0. || specular.b() > 0)
					{	
						ks = 1.;   // the color will take care of brightness, so ks is always 1 or 0
					}
				}
				else
				{
					ks = (specular.r() + specular.g() + specular.b())/ 3.;
				}

				if(m_rlMaterial) ChNrObjectDestroy(m_rlMaterial);
				m_rlMaterial = RLCreateMaterial(ks, shine);

				if(!hdl)
				{
					// Use the material colors
					ChNativeColor color1;
					if(m_colorModel == RLColourRGB)
					{
						color1 = *(material.GetDiffuse().GetNative());
					}
					else
					{
						color1 = *(material.GetBase().GetNative());
					}
					if(m_boolIsPrelit) color1 = *(material.GetEmissive().GetNative());

					RLIMInitialiseSurfaceInfo(pRC->GetRC(), m_rlMaterial, color1, 0, &m_sInfo);
					// We need to save the color model because RLIMColourStillValid crashes if
					// we call it after a model change to ramp


					// Hack in emissive and ambient colors
					if(m_colorModel == RLColourRGB)
					{
							// Hack in the specular color - can't do this with retained mode api
							// sInfo.specular is supposed to be opaque to us, but we know
							// how it works (heh heh).
							// THis only works in rgb mode, unless we can figure out how
							// to validate the emissive and specular colors too
						m_sInfo.specular = RLInternal_ul(*(material.GetSpecular().GetNative()));
						m_sInfo.emissive = RLInternal_ul(*(material.GetEmissive().GetNative()));
						m_sInfo.ambient = RLInternal_ul(*(material.GetAmbient().GetNative()));
					}
					m_iCurrentLevel = max(m_iCurrentLevel, 3);	// prevent first draw yukkies
				}
				else
				{
					// We have a texture
					if(hdl != m_hTexture || !m_sInfo.texture)
					{
						// It's new
						ASSERT(RLObjectExists(hdl) == RLNoError);
						if(m_hTexture && hdl != m_hTexture)
						{
							// Texture Changed! Dispose of old one.
							ChNrObjectDestroy(m_hTexture);
						}

						// Use this texture and remember it
						ChNrObjectReference(hdl);
						m_hTexture = hdl;

						// Make the surface info
						RLIMInitialiseSurfaceInfo(pRC->GetRC(), m_rlMaterial, 0, hdl, &m_sInfo);
						m_colorModel = ChNrDeviceGetColorModel(pRC->GetRC());
					}
					else if( ( m_colorModel != oldModel /* ChNrDeviceGetColorModel(pRC->GetRC()) */|| 
						!RLIMColourStillValid(pRC->GetViewport(), &m_sInfo))/**/)
					{
						// Colors changed; Palette mode needs this, or kaboom
						RLIMInitialiseSurfaceInfo(pRC->GetRC(), m_rlMaterial, 0, hdl, &m_sInfo);
						m_colorModel = ChNrDeviceGetColorModel(pRC->GetRC());
					}
				}
			}

			ChQvSphereCacheData * pCache = pRC->GetSphere(m_iCurrentLevel);
			QvSphere *pNode = (QvSphere *)GetNode();

			int numVerts = pCache->GetVertexCount();
			int numTris = pCache->GetBuffer()->GetTriangleCount();

			RLIMLightingPoint *pVerts = pCache->GetBuffer()->GetVerts();	// use these as scratch - will be used to light, in model coords
			GxVec3f* pSrcVerts = pCache->GetVertices();			// These are unscaled; sphere of radius 1

			float radius = pNode->radius.value;
			for( int i = 0; i < numVerts; i++)
			{
				pVerts[i].position.x = pSrcVerts[i].x() * radius;
				pVerts[i].position.y = pSrcVerts[i].y() * radius;
				pVerts[i].position.z = pSrcVerts[i].z() * radius;
			}

			RLIMClippingFlag clip = RLIMTransformVertices
	        (   pRC->GetViewport(), 
	        	m_frame,
	            &(pVerts[0].position),
	            pCache->GetBuffer()->GetTransformedVerts(),
	            sizeof(RLIMLightingPoint), 
	            sizeof(RLIMViewVertex),
	            numVerts,
	            1
	        );

			//bool boolIsPrelit = !(m_sInfo.specular & 0xffffff || m_sInfo.diffuse & 0xffffff || m_sInfo.ambient & 0xffffff);
			ChShadingLevel quality  = smoothShading;
			
			if(m_boolIsPrelit && !hdl)
			{
				// Take advantage of prelit material to go faster
				// But if it's textured we have to light anyway
				// Color the triangles so we can render flat
				RLInternal_ul oldDiffuse = m_sInfo.diffuse;
				//m_sInfo.diffuse = m_sInfo.emissive;
			    RLIMColourMeshPoints
			    (   pRC->GetViewport(),
			        &m_sInfo,
			        &(pCache->GetBuffer()->GetTriangles()->colour),
			        sizeof(RLIMTriangle),
					numTris
			        //&(pCache->GetBuffer()->GetTransformedVerts()->colour),
			        //sizeof(RLIMViewVertex),
			        //numVerts
			    );
				//m_sInfo.diffuse = oldDiffuse;
				quality = flatShading;	 //
			}
			else
			{
				RLIMLightMeshPoints
			    (   pRC->GetViewport(), 
			        	m_frame,
			        &m_sInfo,
			        pVerts,
			        &(pCache->GetBuffer()->GetTransformedVerts()->colour),
			        sizeof(RLIMLightingPoint),
			        sizeof(RLIMViewVertex),
			        numVerts
			    );
				quality = smoothShading;
			}
    		if(hdl)
    		{
    			RLIMSetCurrentFill(pRC->GetViewport(), hdl, 1, 1, 0);
			}
			else
			{
    			RLIMSetCurrentFill(pRC->GetViewport(), 0, 0, 0, 0);
			}
			pCache->GetBuffer()->Rasterize(this, pRC, quality, chuint32(clip));
		}
		else
		{
			//TRACE(".");
		}

	#endif
#endif //defined( CH_USE_3DR )

	return true;
}


int ChQvSphereInstance::GetLevel(ChRenderContext *pRC)
{
#if defined( CH_USE_3DR )
	// Find out how big it is, so we can decide how many facets to render
	ChRect rtExtent = GetBoundsExtent(pRC);
	float aMatterOfTaste = 1.;		// fudge factor for computation
	int maxExtent = max(rtExtent.bottom - rtExtent.top, rtExtent.right - rtExtent.left);
	float fRoot = sqrt(float(maxExtent));	   // reduce it slower than linear
	int level = fRoot / aMatterOfTaste;	  // each octant is divided into levels
	float quality = pRC->GetQuality();
	level = int(level * quality);		// linear degradation for now
	return max(1,level);			   // we don't limit; let cacher do that 
#else
	#if defined(CH_SPHERE_LOD)
	
	// Find out how big it is, so we can decide how many facets to render
	bool boolClipped;
	ChRect rtExtent = GetBoundsExtent(pRC, 0, &boolClipped);
	return GetLevel(pRC, rtExtent, boolClipped);
	#else
	return 6;
	#endif

#endif //defined( CH_USE_3DR )
}

int ChQvSphereInstance::GetLevel(ChRenderContext *pRC, ChRect &rtExtent, bool boolClipped)
{
	if(boolClipped)
	{
		#if defined(CH_IMMED_MODE)
		return 1;
		#else
		return 2;
		#endif
	}
	const int MAX_LEVELS = 6;	// was 8
	if(rtExtent.left == 0 && rtExtent.right == 0 && rtExtent.top == 0 && rtExtent.bottom == 0)
	{
		int level = m_iCurrentLevel;			// bogus transform bug
		return min(MAX_LEVELS, max(1,level));
	}
	float aMatterOfTaste = .6;	//.7;		// fudge factor for computation
	int maxExtent = max(rtExtent.bottom - rtExtent.top, rtExtent.right - rtExtent.left);
	//float fRoot = sqrt(float(maxExtent));	   // reduce it slower than linear

											// reduce it slower than linear
	#if (_MSC_VER > 900)

		float fRoot = (float)pow( (double)maxExtent, .42 );

	#else
	
		float fRoot = pow( (float)maxExtent, .42 );

	#endif

	int level = fRoot * aMatterOfTaste;	  // each octant is divided into "level" strips
	return min(MAX_LEVELS, max(1,level));		//was max(1,level));
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
bool ChQvSphereInstance::Reconstruct(ChRenderContext *pRC)
{
	int level = GetLevel(pRC);

	m_pContext->LockReconstruction();
	ChNrMesh backMesh = m_backMesh;
	int iBackLevel = m_iBackLevel;
	m_pContext->UnlockReconstruction();

	if(!backMesh || level != iBackLevel)
	{	
		ChNrMesh oldBackMesh = backMesh;
	//pRC->LockScene();

		backMesh = BuildMesh(pRC, level);
	//pRC->UnlockScene();
		m_pContext->LockReconstruction();
		if(m_backMesh) ChNrObjectDestroy(m_backMesh);	// don't leak "not good enoughs"
		m_iBackLevel	=	level;		   
		m_backMesh 		= 	backMesh;
		m_pContext->UnlockReconstruction();


		//m_pContext->LockScene();
		m_pContext->SetDirty();
		//m_pContext->UnlockScene();
	}
	return true;
}

ChNrMesh ChQvSphereInstance::BuildMesh(ChRenderContext *pRC, int iLevel)
{

	QvSphere *pNode = (QvSphere *)GetNode();

	ChNrMesh mesh = pRC->CreateMesh();
	ChNrObjectSetAppData(mesh, (unsigned long)this);
	ChNrMeshSetColorSource(mesh,ColorFromFace);
	ChNrMeshSetPerspective(mesh,true);  

	ChQvSphereCacheData * pCache = pRC->GetSphere(iLevel);
	
	// Make a material mapping; we will use later 
	ChQvSphereMaterials materialMap( this );
	pRC->AdjustTransparency(materialMap);
	
	/* Do the texture stuff - find it, make the map, */
	int boolDidIt = SetupTexture(pRC);
	ChQvTextureRenderData *pTextureData = (ChQvTextureRenderData*)(GetTexture2()->GetRenderData());
	bool boolUseTexture = !(pTextureData->IsEmpty());  // one -might- arrive
	ChQvTexture2TransformRenderData* m_pTex2Xform =
			((ChQvTexture2TransformRenderData*)(GetTexture2Transform()->GetRenderData()));

	
	// Reserve space to load faster
	int numFaces = (m_iCurrentLevel + 1) * (m_iCurrentLevel + 2) * 8 / 2;
	int numVerts = pCache->GetSphere()->NumVerts();
	ChNrMeshReserveSpace(mesh, numVerts, numVerts, numFaces);  
	// Do the facets
	{
		// so draw the thing already
		myStripIter stripIter(pCache, pRC, boolUseTexture, pNode->radius.value, &materialMap, m_pTex2Xform);
		stripIter.SetMesh(mesh);
		stripIter.Attach(*(pCache->GetSphere()));
		stripIter.Iterate(GxSphere::Indexed);
	}

	if(boolUseTexture)
	{
		// This is in case the texture is already arrived
		ChTextureHandle hdl = pTextureData->GetTextureHandle();
		if(hdl)
		{
			// Texture guy got here first, apply it
			//ChNrMeshSetTexture(mesh, hdl);
			SetTexture(pTextureData, mesh);

		}
	}  

	return mesh;
}

// Callback to choose child while rendering
#if (defined(CH_USE_RLAB))
void SphereFrameCallback(ChNrFrame frame, void * arg)
#else
void SphereFrameCallback(ChNrFrame frame, void * arg, float delta)
#endif
{
	ChQvSphereInstance *pInst = (ChQvSphereInstance *)arg;
	pInst->PickASphere();
}

bool ChQvSphereInstance::PickASphere()
{
	int iLevel = GetLevel(m_pContext);
	const int Tolerance = 1;	// max error permitted without requesting a new one

	if ( m_pContext->IsThreaded() )	  
	{
		m_pContext->LockReconstruction();
		bool boolBack = m_iBackLevel > 0 && abs(iLevel - m_iCurrentLevel) > abs(iLevel - m_iBackLevel);
		m_pContext->UnlockReconstruction();
	
		if(boolBack)
		{
			// Swap in back, discard front
			//TRACE3("Sphere frame %lx: swapping out %d, in %d levels.\n",(unsigned long)m_frame, m_iCurrentLevel, m_iBackLevel );
			m_pContext->LockReconstruction();
			m_iCurrentLevel	= m_iBackLevel;
			m_iBackLevel = 0;
			ChNrMesh oldMesh = m_mesh;
			m_mesh = m_backMesh;
			m_backMesh = 0;
			m_pContext->UnlockReconstruction();

			ChNrFrameAddVisual(m_frame, m_mesh);
			ChNrFrameRemoveVisual(m_frame, oldMesh);
			//m_pContext->SetDirty();
		}
		//m_pContext->UnlockReconstruction();

		// Request a new one if the current requirement is differnet than
		// the current by more than some tolerance. We special case from 1 to
		// 2 because that's such a big visual difference
		if(abs(iLevel - m_iCurrentLevel) > Tolerance ||
			(iLevel > m_iCurrentLevel && m_iCurrentLevel == 1))
		{  
			m_pContext->AddReconstruction(this);
			//TRACE1("Adding reconstruction; backmesh = %lx \n", (unsigned long)m_backMesh);
		}
	}
	else
	{

	
		// Reconstruct if necessary, and if we haven't 
		// exceeded the render-time budget
		// Note that iLevel will range from 1 to 8 or 9 or so
		if(abs(iLevel - m_iCurrentLevel) > Tolerance ||
			iLevel > m_iCurrentLevel && m_iCurrentLevel == 1)
		{
			if(m_pContext->AddSynchReconstruction(iLevel * iLevel))	
			{  
				ChNrMesh oldMesh = m_mesh;
				
				Reconstruct(m_pContext);
				m_mesh = m_backMesh;
				m_backMesh = 0;
				m_iCurrentLevel = iLevel;
				ChNrFrameRemoveVisual(m_frame, oldMesh);
				ChNrFrameAddVisual(m_frame, m_mesh);
			}
		}
	}

	return true;
}

#endif

///////////////////////////////////////////////////////////////////////////////
////////////////////// Point Set //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

ChQvPointSetInstance::ChQvPointSetInstance() : ChQvShapeInstance()
{
}


bool ChQvPointSetInstance::Construct(ChRenderContext *pRC, ChConstructionIterator *pIterator)
{
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	{

		pRC->LockQv();		   // Lock tree so other threads don't kill our data
		if(!pIterator->IsOKToProceed(this))	 // This locks scene if available
		{
			pRC->UnlockQv();		   // Unlock tree 
			return 0;
		}
		if(IsConstructed())
		{
			pRC->UnlockScene();
			pRC->UnlockQv();		   // Unlock tree 
			return 1;
		}
		ASSERT(m_frame );
		m_boolConstructed = true;
		
		QvPointSet *pNode = (QvPointSet *)GetNode();
		m_mesh = 0;

		// Make a material mapping; we will use later for each face
		ChQvPointSetMaterials materialMap( this );	// making this is cheap; don't cache
		pRC->AdjustTransparency(materialMap);

		bool boolOverall = (GetNormalBinding()->value.value == QvNormalBinding::OVERALL);	// else by vertex

		/* Do no texture stuff  */

		// Get the coordinates
		QvCoordinate3 *pC3 = GetCoordinate3();
		int numPoints = pNode->numPoints.value;
		if(numPoints < 0)
		{
			numPoints = pC3->point.num - pNode->startIndex.value;
		}
		// do the points
		if(numPoints >= 1)
		{

			// Doing one point at a time lets us do pervertex colors
			for(int j = pNode->startIndex.value; j < numPoints + pNode->startIndex.value; j++)	  

			{
				ChMaterial material = materialMap.GetMaterial( j );
				ChColor color(1, 0, 0);
				
				ChColor diffuse = material.GetDiffuse();
				ChColor emissive = material.GetEmissive();

				// We're using prelit colors ??

				color.SetR( max(diffuse.r(), emissive.r()) );
				color.SetG( max(diffuse.g(), emissive.g()) );
				color.SetB( max(diffuse.b(), emissive.b()) );
				ChTexture *pTexture;

				chparam key = chparam(*color.GetNative());

				ChTexture **ppTex;
				if(ppTex = pRC->GetDotsCache()->Find(key))
				{
					pTexture = *ppTex;
				}
				else
				{
					pTexture= new ChTexture(pRC, 2, 2, color);
					pRC->GetDotsCache()->Insert(key, pTexture);
				}


				GxVec3f p;
				int index = j * 3;
				p.set(pC3->point.values[index], pC3->point.values[index+1], pC3->point.values[index+2]);
				ChNrFrame frame = pRC->CreateFrame(m_frame);
				ChNrObjectSetAppData(frame, (unsigned long)this);
				ChNrFrameAddTranslation(frame, CombineBefore, p.x(), p.y(), p.z());
				ChNrFrameAddVisual(frame, pTexture->GetHandle());
				ChNrTextureSetDecalScale(pTexture->GetHandle(), false);
				ChNrTextureSetDecalOrigin(pTexture->GetHandle(), 1, 1);
			}

		}

		pIterator->DidAShape();
		pRC->UnlockScene();		
		pRC->UnlockQv();		   // Unlock tree 
	}
#endif
	return true;
}

bool ChQvPointSetInstance::Draw(ChRenderContext *pRC, ChDrawIterator *pIterator)
{
#if defined( CH_USE_3DR )
	{
		#if 1
		G3dHandle_t hGC = pRC->GetGC();
		Dword_t  hRC = pRC->GetRC();
		QvPointSet *pNode = (QvPointSet *)GetNode();
		pRC->SetModelTransform(GetTransform());

		//pRC->SetShading(this);
	    R3dSetState( hRC, R3D_STA_DISABLES, R3D_SE_SHADING);

		Fixed32_t wMattNum = 0;	  // for now always use material 0
		G3dSetCurrentMatt(hGC, wMattNum );

		Float_t		cull = false;
		G3dSetMatt( hGC,  wMattNum, G3DM_BACK_CULL,	(Float_t *)&cull );

		// Make a material mapping; we will use later for each face
		ChQvPointSetMaterials materialMap( this );	// making this is cheap; don't cache

		// Normals
		int	face = 0;
		int boolUseNorms = true;
		bool boolOverall = (GetNormalBinding()->value.value == QvNormalBinding::OVERALL);	// else by vertex

		/* Do no texture stuff  */
		int boolUseTexture = false;
	
		Dword_t disabled = ( hRC, R3D_STA_DISABLES );
		Dword_t enabled = ( hRC, R3D_STA_ENABLES );
		R3dSetState( hRC, R3D_STA_ENABLES, R3D_SE_CLIPPING);  // I need them to clip for me too
															  // because I'm not pixel accurate
		R3dSetState( hRC, R3D_STA_DISABLES, R3D_SE_PATTERNING );  // solid line

		// Get the coordinates
		QvCoordinate3 *pC3 = GetCoordinate3();
		int numPoints = pNode->numPoints.value;
		if(numPoints < 0)
		{
			numPoints = pC3->point.num - pNode->startIndex.value;
		}
		// do the points
		if(numPoints >= 1)
		{

			ColorFA_t color, diff, emissive;
			int k = 0;
			ChPipeline pipeline;
			GetPipeline(pRC, pipeline);

			// Doing one point at a time lets us do pervertex colors
			for(int j = pNode->startIndex.value; j < numPoints + pNode->startIndex.value; j++)	  

			{
				bool boolPureEmissive;
				materialMap.Set(hRC, hGC, face, j, &boolPureEmissive);
				G3dGetMatt(hGC, 0, G3DM_DIFFUSE, (float*)&diff);
				G3dGetMatt(hGC, 0, G3DM_EMIT, (float*)&emissive);

				// We're using prelit colors
				// Bogus em up by assuming a light value of  white .5
				// ignoring specular and Lambertian effects
				// Conversely, you could assume light = 1 and cos(theta) = .5 for diffuse
				// These are so dinky nobody's gonna notice
				//color.r = diff.r * .75 + emissive.r;
				//color.g = diff.g * .75 + emissive.g;
				//color.b = diff.b * .75 + emissive.b;
				color.r = max(diff.r, emissive.r);
				color.g = max(diff.g, emissive.g);
				color.b = max(diff.b, emissive.b);
				color.a = 1.0;
				//pRC->SetModulation( false, false);
				ColorFA_t black = {0.,0., 0., 1.};

				GxVec3f p;

				int index = j * 3;
				p.set(pC3->point.values[index], pC3->point.values[index+1], pC3->point.values[index+2]);

				// Transform p to screen
				bool boolClipped;
				p = pipeline.TransformToPort(p, boolClipped);

				// Load poly
				if(!boolClipped)
				{
		 			R3dFloatVtxClr_t vtx[4];
					for(k=0; k<4; k++)
					{
						vtx[k].x = 	p.x() + ((k == 1 || k == 2) ? 2 : 0);
						vtx[k].y = 	p.y() + ((k == 2 || k == 3) ? 2 : 0);
						vtx[k].z = 	p.z();
						vtx[k].r =  color.r;
						vtx[k].g =  color.g;
						vtx[k].b =  color.b;
						vtx[k].a = 1.0;
					}
					// Draw it
					try
					{
		    			R3dPrimitive(   hRC, 
		                    R3D_PKT_POLYGON, 
		                    R3D_VI_COLOR | R3D_VI_FLOAT, 
		                    4, 
		                    sizeof(R3dFloatVtxClr_t),
		                    (LPByte_t) vtx);
					}
					catch(...)
					{
						//TRACE("Exception in drawing points caught\r\n");
					}
				}
				#if 0
				DOESN'T WORK
				try
				{
					G3dPrimitiveF(hGC, G3D_PRM_POINTS, 1,
								points, sizeof(PointF_t), 
								0, sizeof(PointF_t), 
								textures, sizeof(PointF_t), 
								colors, sizeof(ColorFA_t) );
				}
				catch (...)
				{
					//TRACE("Exception in drawing points caught\r\n");
				}
				#endif
			}

		}
		R3dSetState( hRC, R3D_STA_DISABLES, disabled ); 
		R3dSetState( hRC, R3D_STA_ENABLES, enabled);
		#endif
	}
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	
#endif //defined( CH_USE_3DR )
	return true;
}

// end of file
