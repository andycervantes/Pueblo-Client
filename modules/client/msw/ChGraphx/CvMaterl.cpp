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

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvMaterl.cpp,v 2.26 1996/09/18 07:06:39 coyote Exp $

#include "grheader.h"

#include "CvInstnc.h"
#include <QvInfo.h>
#include <QvState.h>
#include "ChMaze.h"
#include "ChMazDep.h"
#include "CvTrnsfm.h"
#include "CvNormal.h"
#include "CvBound.h"
#include "CvMaterl.h"
#include "CvTextur.h"
#if (defined(CH_USE_D3D))
#include "ChRenderData.h"
#endif

#if (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
static const float maxShininess = 20.0;
#else
static const float maxShininess = 40.0;
#endif

float	ChMaterial::GetNativeShininess()
{
	return m_shininess * maxShininess;
};

bool ChMaterial::IsPrelit()
{
	return (m_diffuse.IsBlack() && m_ambient.IsBlack() && m_specular.IsBlack()); 
};

ChColor ChMaterial::GetBase()
{
	ChColor base = m_diffuse;

	float diffInt = m_diffuse.r() + m_diffuse.g() + m_diffuse.b();
	float ambInt = m_ambient.r() + m_ambient.g() + m_ambient.b();
	float emitInt = m_emissive.r() + m_emissive.g() + m_emissive.b();
	float specInt = m_specular.r() + m_specular.g() + m_specular.b();

	float multiplier = max(diffInt, ambInt);
	multiplier = max(multiplier,emitInt);
	//multiplier = max(multiplier,specInt);

	if(diffInt > 0)
	{
		// Scale the base color to be as bright as the brightest of  amb, emissive and diffuse
		// but with the same proportions as diffuse
		multiplier /= diffInt;

		float 	r =	base.r();
		float 	g =	base.g();
		float 	b =	base.b();

		if(multiplier > 1.0)
		{
			r =	base.r() * multiplier;
			g =	base.g() * multiplier;
			b =	base.b() * multiplier;
		}

		if(specInt > 0.)
		{
			// Blend in the specular color, depending upon shininess.
			// The shinier it is, the less we blend in.
			// Zero shininess means just add it - the  maxShininess / 2 factor is a hack

		#if (_MSC_VER > 900)

			float specularFactor = (float)pow( (double)2.7,
												(double)(-(GetShininess() *
															maxShininess / 2)) );

		#else
		
			float specularFactor = pow( 2.7,
										-(GetShininess() *
											maxShininess / 2) );

		#endif

			r += specularFactor * m_specular.r();
			g += specularFactor * m_specular.g();
			b += specularFactor * m_specular.b();
		}
		// No component > 1 svp ! - Try to keep the hue constant
		float big = max(r, max(g, b));
		big = max(big, 1);

		base.SetR( r / big );
		base.SetG( g / big );
		base.SetB( b / big );
	}
	else
	{
		base.SetR(max(max(m_diffuse.r(), m_emissive.r()), m_ambient.r()));
		base.SetG(max(max(m_diffuse.g(), m_emissive.g()), m_ambient.g()));
		base.SetB(max(max(m_diffuse.b(), m_emissive.b()), m_ambient.b()));
	}

	return base;

}

float ChQvMaterialMap::GetMaxTransparency()
{
	float transparency = 0;		  
	for(int i = 0; i < m_pMat->transparency.num; i++)
	{
		transparency=	max(transparency, m_pMat->transparency.values[i]);
	}
	return transparency;
}

#if defined(CH_USE_3DR)
void ChQvMaterialMap::SetMat( Dword_t  hRC, G3dHandle_t hGC, long index,  bool *pboolEmissive /*= 0*/)
{
	Fixed32_t wMattNum = 0;	  // for now always use material 0
	long i = index;

	if(i != m_lastI)
	{
		m_lastI = i;
		// Wrap indexing at array length 
		ColorF_t	ambient;	
		ColorFA_t	diffuse;	
		ColorF_t	specular;	
		ColorF_t	emit;		
		Qv2Native(m_pMat->ambientColor, i % m_pMat->ambientColor.num, ambient);
		Qv2Native(m_pMat->diffuseColor, i % m_pMat->diffuseColor.num, diffuse);
		Qv2Native(m_pMat->specularColor, i % m_pMat->specularColor.num, specular) ;
		Qv2Native(m_pMat->emissiveColor, i % m_pMat->emissiveColor.num, emit);

		Float_t		shine	=	maxShininess * 
								Float_t(m_pMat->shininess.values[i % m_pMat->shininess.num]);
								//  0 is opaque in vrml
								// alpha = 0.0, but color.a = 1.0 should be opaque in 3dr 
								// with typical blend functions
		Float_t		alpha	=	Float_t(m_pMat->transparency.values[i % m_pMat->transparency.num]);
		Float_t		cull	=	0.;
		diffuse.a = 1.- alpha;

		G3dSetMatt( hGC,  wMattNum, G3DM_AMBIENT,  (Float_t *)&ambient   );			
		G3dSetMatt( hGC,  wMattNum, G3DM_DIFFUSE,  (Float_t *)&diffuse   );			
		G3dSetMatt( hGC,  wMattNum, G3DM_SPECULAR, (Float_t *)&specular  );			
		G3dSetMatt( hGC,  wMattNum, G3DM_EMIT,     (Float_t *)&emit      );			
		G3dSetMatt( hGC,  wMattNum, G3DM_SHINE,    (Float_t *)&shine     );			
		G3dSetMatt( hGC,  wMattNum, G3DM_CULL,	   (Float_t *)&cull     );
		G3dSetMatt( hGC,  wMattNum, G3DM_ALPHA,    (Float_t *)&alpha     );

		G3dSetMatt( hGC,  wMattNum, G3DM_BACK_AMBIENT,  (Float_t *)&ambient   );			
		G3dSetMatt( hGC,  wMattNum, G3DM_BACK_DIFFUSE,  (Float_t *)&diffuse   );			
		G3dSetMatt( hGC,  wMattNum, G3DM_BACK_SPECULAR, (Float_t *)&specular  );			
		G3dSetMatt( hGC,  wMattNum, G3DM_BACK_EMIT,     (Float_t *)&emit      );			
		G3dSetMatt( hGC,  wMattNum, G3DM_BACK_SHINE,    (Float_t *)&shine     );			
		//G3dSetMatt( hGC,  wMattNum, G3DM_BACK_CULL,   	(Float_t *)&cull     );

		G3dSetCurrentMatt(hGC, wMattNum );	
		
		m_boolEmissive = IsBlack(ambient) && IsBlack(diffuse) && 
								IsBlack(specular);	// don't care whether emissive
									// is non zero - treat pure black as emissive
									// so i omitted this : !IsBlack(emit);		
		if(pboolEmissive)
		{
			*pboolEmissive 	= m_boolEmissive;	
		}
	}
	else if(pboolEmissive)
	{
		*pboolEmissive 	= 	m_boolEmissive;
	}
};
#else
void ChQvMaterialMap::SetMat(ChNrMesh mesh, ChNrFace face, int vertIndex, long index)
{
	long i = index;

	{
		m_lastI = i;
		ChColor	ambient;	
		ChColorA	diffuse;	
		ChColor	specular;	
		ChColor	emit;
		
		int iSpecular = m_pMat->specularColor.num ? i % m_pMat->specularColor.num : 0;		
		int iShininess = m_pMat->shininess.num ? i % m_pMat->shininess.num : 0;
				
		Qv2Native(m_pMat->ambientColor, i, ambient);
		Qv2Native(m_pMat->diffuseColor, i, diffuse);
		Qv2Native(m_pMat->specularColor, i, specular) ;
		Qv2Native(m_pMat->emissiveColor, i, emit);

		float	shine = 0;
		if(m_pMat->shininess.num)
		{
			shine = maxShininess * float(m_pMat->shininess.values[i % m_pMat->shininess.num]);
		}

								//  0 is opaque in vrml
								// alpha = 1.0, and color.a = 1.0 should be opaque in RL 
								// with typical blend functions
		float		alpha	=	1.;
		if(m_pMat->transparency.num)
		{
			alpha	=	1. - float(m_pMat->transparency.values[i % m_pMat->transparency.num]);
		}
		diffuse.SetAlpha(alpha);
		specular.SetAlpha(alpha);
		emit.SetAlpha(alpha);

		ChMaterial mat = GetMat(index);

		ChColor base = mat.GetBase();
		

		#if 0
		// This is quasi-official rule of how to handle; altho doc is ambiguous
		m_boolEmissive = IsBlack(ambient) && IsBlack(diffuse) && 
							IsBlack(specular) && !IsBlack(emit);
		#endif
 		//m_boolEmissive = (emit.r() + emit.g() + emit.b()) >= (diffuse.r() + diffuse.g() + diffuse.b());
		#if USE_FIRST_MOVING_WORLDS_PROPOSAL_DEFN
 		m_boolEmissive = m_pMat->emissiveColor.num > 0 && (emit.r() + emit.g() + emit.b()) > 0.0;
		#endif

		// This following is the VRML 1.0c defn, with the addition of completely ignoring ambient color and
		// as of 4/15/96, allowing black to act as empty

		bool boolEmissivePresent = (m_pMat->emissiveColor.num > 0 && (emit.r() + emit.g() + emit.b()) > 0.0);
		bool boolDiffusePresent = (m_pMat->diffuseColor.num > 0 && (diffuse.r() + diffuse.g() + diffuse.b()) > 0.0);
		bool boolSpecularPresent = (m_pMat->specularColor.num > 0 && (specular.r() + specular.g() + specular.b()) > 0.0);

 		m_boolEmissive = boolEmissivePresent && !boolDiffusePresent	&& !boolSpecularPresent;


		// Reality lab has no support for ambient, emissive, or specular colors
		// However, we can use the shine value for the power (like we do in 3dr), and make
		// an estiamte for the specular intensity ks by looking at the ratio
		// of specular to diffuse color intensities. First, if the surface is pure emissive,
		// revert to unlit for this mesh, and use emissive  for this color
		// Optimally, we'd look at all the materials for this mesh, but this is close
		// enough for now... Note that RL -doesn't- give us the option of just
		// making this face unlit; it's only as finegrained as a mesh.

		// Note that we also set the face color. THis means that if this mesh gets switched to
		// ColorByFace because of transparency or such, we are guaranteed each face is colored
		// to something reasonable
		#if 0 && defined(CH_USE_D3D)
		#else  
		if(m_boolEmissive)
		{
			ChNrMeshSetQuality(mesh, RenderUnlitFlat);
			ChNativeColor	emitColor = *emit.GetNative();
			if(vertIndex >= 0)
			{
				if(alpha >= 1.0)
				{
					ChNrMeshSetVertexColor(mesh, vertIndex, *emit.GetNative());
					ChNrFaceSetColor(face, *emit.GetNative());
				}
				else
				{
					ChNrMeshSetColorSource(mesh, ColorFromFace );
					ChNrFaceSetColor(face, *emit.GetNative());
				}
			}
			else
			{
				ChNrMeshSetColorSource(mesh, ColorFromFace );
				ChNrFaceSetColor(face, emitColor);
			}
		}
		else
		{
			if(vertIndex >= 0)
			{
				if(alpha >= 1.0)
				{
					ChNrFaceSetColor(face, *base.GetNative());
					ChNrMeshSetVertexColor(mesh, vertIndex, *base.GetNative());
				}
				else
				{
					ChNrMeshSetColorSource(mesh, ColorFromFace );
					ChNrFaceSetColor(face, *base.GetNative());
				}
			}
			else
			{
				ChNrFaceSetColor(face, *base.GetNative());
			}
		}

		if(!m_boolEmissive)
		{
								//Only look at first
								// vertex for the material - only one per face allowed
			float ks = 0;
			#if (defined(CH_USE_RLAB))

			ks =  (specular.r() + specular.g() + specular.b()) / 3.;

			if(ks > 0)				 // RL emissive doesn't matter
			#elif (defined(CH_USE_D3D))
			if(!specular.IsBlack() || !emit.IsBlack())	  // In d3d we can mix in emissive on a face
			#endif
			{
				ChNrMaterial material = 0;

				// Find the cached material if any
				#if (defined(CH_USE_RLAB))
				unsigned long lKey = (unsigned long)iSpecular | ((unsigned long)iShininess << 16);
				ChNrMaterial *pMaterial = m_materialCache.Find(lKey);
				if(pMaterial) material = *pMaterial;
				#elif (defined(CH_USE_D3D))
				// On D3D we cache on the material node's render data
				ChQvMaterialRenderData *pData = (ChQvMaterialRenderData *)(m_pMat->GetRenderData());
				material = pData->Find(index);
				#endif

				ChNrMaterial tmpMat = 0;
				if(face) ChNrFaceGetMaterial(face, &tmpMat);
				if((face && !tmpMat) || !face)
				{
					if(m_pRC && !material)
					{
						material = m_pRC->CreateMaterial(ks, shine);
						#if (defined(CH_USE_RLAB))
						m_materialCache.Insert(lKey, material);
						#elif (defined(CH_USE_D3D))
						// ks is ignored in d3d, but we can set colors
						material->SetEmissive(emit.r(), emit.g(), emit.b());
						material->SetSpecular(specular.r(), specular.g(), specular.b());
						pData->Add(index, material);
						#endif
					}
					if(face)
					{
		
						ChNrFaceSetMaterial(face, material);
					}
					else
					{
		
						ChNrMeshSetMaterial(mesh, material);
					}
				}
				D3DRelease(tmpMat);
			}
		}			
		#endif
	}
};
#endif

#if (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
ChMaterial ChQvMaterialMap::GetMat( long index )
{
	long i = index;
	ChMaterial mat;
	// Wrap indexing at array length 
	Qv2Native(m_pMat->ambientColor, i, mat.m_ambient);
	Qv2Native(m_pMat->diffuseColor, i, mat.m_diffuse);
	Qv2Native(m_pMat->specularColor, i, mat.m_specular) ;
	Qv2Native(m_pMat->emissiveColor, i, mat.m_emissive);

	if(m_pMat->shininess.num)
	{
		mat.m_shininess = float(m_pMat->shininess.values[i % m_pMat->shininess.num]);
	}
	else
	{
		mat.m_shininess = 0;
	}

							//  0 is opaque in vrml
							// alpha = 0.0, but color.a = 1.0 should be opaque in RL 
							// with typical blend functions
	if(m_pMat->transparency.num)
	{
		mat.m_transparency	=	float(m_pMat->transparency.values[i % m_pMat->transparency.num]);
	}
	else
	{
		mat.m_transparency	=	0;
	}
	mat.m_diffuse.SetAlpha(1. - mat.m_transparency);

	return mat;
};
#endif

////////////////////////////////////////////////////////
ChQvFaceSetMaterials::ChQvFaceSetMaterials( ChQvIFSInstance *pInst) : ChQvMaterialMap()
{
	m_pMat = pInst->GetMaterial();
	// Get the binding
	QvMaterialBinding *pBinding =  pInst->GetMaterialBinding();
	m_binding = (QvMaterialBinding::Binding)(pBinding->value.value);
	// Save the indices
	m_pIndices =  ((QvIndexedFaceSet*)(pInst->GetNode()))->materialIndex.values;
	m_numIndices = ((QvIndexedFaceSet*)(pInst->GetNode()))->materialIndex.num;

	m_pRC = pInst->GetRC();
}

#if defined(CH_USE_3DR)
void ChQvFaceSetMaterials::Set(Dword_t  hRC, G3dHandle_t hGC, int faceNum, int vertex /*= 0*/, bool *pboolEmissive /*= 0*/)
#else
void ChQvFaceSetMaterials::Set(ChNrMesh mesh, ChNrFace face, int vertIndex, int faceNum, int vertex)
#endif
{
	int i = 0;
	switch(m_binding)
	{
		
		case QvMaterialBinding::PER_FACE:
		{
			i = faceNum;
			break;
		}
		case QvMaterialBinding::PER_FACE_INDEXED:
		{
			if(faceNum < m_numIndices)	i = m_pIndices[faceNum];
			break;
		}
		case QvMaterialBinding::PER_VERTEX:
		{
			i = vertex;
			break;
		}
		case QvMaterialBinding::PER_VERTEX_INDEXED:
		{
			if(vertex < m_numIndices)i = m_pIndices[vertex];
			break;
		}

		case QvMaterialBinding::PER_PART_INDEXED:
		{
			i = m_pIndices[0];
			break;
		}

		case QvMaterialBinding::PER_PART:
		case QvMaterialBinding::DEFAULT:
		case QvMaterialBinding::NONE:
		case QvMaterialBinding::OVERALL:
		{
			i = 0;
			break;
		}
	}

	if (i<0) i = 0;
#if defined(CH_USE_3DR)
	SetMat( hRC, hGC, i, pboolEmissive);
#else
	SetMat( mesh, face, vertIndex, i);
#endif

	return;
};
																  
ChQvLineSetMaterials::ChQvLineSetMaterials( ChQvILSInstance *pInst) : ChQvMaterialMap()
{
	m_pMat = pInst->GetMaterial();
	// Get the binding
	QvMaterialBinding *pBinding =  pInst->GetMaterialBinding();
	m_binding = (QvMaterialBinding::Binding)(pBinding->value.value);
	if(m_binding == QvMaterialBinding::DEFAULT) m_binding = QvMaterialBinding::PER_VERTEX_INDEXED;
	
	QvIndexedLineSet *lines = (QvIndexedLineSet*)(pInst->GetNode());
	m_pIndices =  lines->materialIndex.values;
	m_numIndices = lines->materialIndex.num;

	m_pRC = pInst->GetRC();
};

#if defined(CH_USE_3DR)
void ChQvLineSetMaterials::Set(Dword_t  hRC, G3dHandle_t hGC, int faceNum, int vertex /*= 0*/, bool *pboolEmissive /*= 0*/)
#else
void ChQvLineSetMaterials::Set(ChNrMesh mesh, ChNrFace face, int vertIndex, int faceNum, int vertex)
#endif
{
	int i = 0;
	switch(m_binding)
	{
		
		case QvMaterialBinding::PER_FACE:
		{
			i = faceNum;
			break;
		}
		case QvMaterialBinding::PER_FACE_INDEXED:
		{
			if(faceNum < m_numIndices)	i = m_pIndices[faceNum];
			break;
		}
		case QvMaterialBinding::PER_VERTEX:
		{
			i = vertex;
			break;
		}
		case QvMaterialBinding::PER_VERTEX_INDEXED:
		{
			if(vertex < m_numIndices)i = m_pIndices[vertex];
			break;
		}

		case QvMaterialBinding::PER_PART_INDEXED:
		{
			i = m_pIndices[0];
			break;
		}

		case QvMaterialBinding::PER_PART:
		case QvMaterialBinding::DEFAULT:
		case QvMaterialBinding::NONE:
		case QvMaterialBinding::OVERALL:
		{
			i = 0;
			break;
		}
	}

	if (i<0) i = 0;
#if defined(CH_USE_3DR)
	SetMat( hRC, hGC, i, pboolEmissive);
#else
	SetMat( mesh, face, vertIndex, i);
#endif

	return;
};
																  
//////////////////////////////////
// Not ported yet

ChQvPointSetMaterials::ChQvPointSetMaterials( ChQvPointSetInstance *pInst) : ChQvMaterialMap()
{
	m_pMat = pInst->GetMaterial();
	// Get the binding
	QvMaterialBinding *pBinding =  pInst->GetMaterialBinding();
	m_binding = (QvMaterialBinding::Binding)(pBinding->value.value);
	if(m_binding == QvMaterialBinding::DEFAULT) m_binding = QvMaterialBinding::OVERALL;
	
	QvIndexedLineSet *lines = (QvIndexedLineSet*)(pInst->GetNode());
	m_pIndices =  lines->materialIndex.values;
	m_numIndices = lines->materialIndex.num;

	m_pRC = pInst->GetRC();
};

#if defined(CH_USE_3DR)
void ChQvPointSetMaterials::Set(Dword_t  hRC, G3dHandle_t hGC, int faceNum, int vertex /*= 0*/, bool *pboolEmissive /*= 0*/)
{
	SetMat( hRC, hGC, GetIndex(vertex), pboolEmissive);

	return;
};
#else
void ChQvPointSetMaterials::Set(ChNrMesh mesh, ChNrFace face, int vertIndex, int faceNum, int vertex)
{
	SetMat( mesh, face, vertIndex, GetIndex(vertex));

	return;
};
																  
ChMaterial ChQvPointSetMaterials::GetMaterial( int vertex)
{

	return GetMat(  GetIndex( vertex ) );
};
#endif
																  
int ChQvPointSetMaterials::GetIndex( int vertex)
{
	int i = 0;
	switch(m_binding)
	{
		
		case QvMaterialBinding::PER_VERTEX:
		{
			i = vertex;
			break;
		}
		case QvMaterialBinding::PER_VERTEX_INDEXED:
		{
			if(vertex < m_numIndices)i = m_pIndices[vertex];
			break;
		}

		case QvMaterialBinding::PER_FACE_INDEXED:
		case QvMaterialBinding::PER_PART_INDEXED:
		{
			i = m_pIndices[0];
			break;
		}

		case QvMaterialBinding::PER_FACE:
		case QvMaterialBinding::PER_PART:
		case QvMaterialBinding::DEFAULT:
		case QvMaterialBinding::NONE:
		case QvMaterialBinding::OVERALL:
		{
			i = 0;
			break;
		}
	}

	if (i<0) i = 0;

	return  i;
};
																  

#if defined(CH_USE_3DR)
#endif
//////////////////////////////////////

ChQvConeMaterials::ChQvConeMaterials( ChQvConeInstance* pInst) : ChQvMaterialMap()
{
	m_pMat = pInst->GetMaterial();
	// Get the binding
	QvMaterialBinding *pBinding =  pInst->GetMaterialBinding();
	m_binding = (QvMaterialBinding::Binding)(pBinding->value.value);

	m_pRC = pInst->GetRC();
};

#if defined(CH_USE_3DR)
void ChQvConeMaterials::Set(Dword_t  hRC, G3dHandle_t hGC, int part, bool *pboolEmissive)
#else
void ChQvConeMaterials::Set(ChNrMesh mesh, ChNrFace face, Parts part)
#endif
{	// part 0 == sides, 1 == bottom
	int i = 0;
	switch(m_binding)
	{
		case QvMaterialBinding::PER_PART:
		case QvMaterialBinding::PER_PART_INDEXED:
		{
			i = int(part);
			if (i > 1) i = 1;
			break;
		}

		case QvMaterialBinding::PER_VERTEX_INDEXED:
		case QvMaterialBinding::PER_FACE_INDEXED:
		case QvMaterialBinding::PER_VERTEX:
		case QvMaterialBinding::PER_FACE:
		case QvMaterialBinding::DEFAULT:
		case QvMaterialBinding::NONE:
		case QvMaterialBinding::OVERALL:
		{
			i = 0;
			break;
		}
	}
	#if defined(CH_USE_3DR)
	SetMat( hRC, hGC, i, pboolEmissive);
	#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
	SetMat( mesh, face, -1, i);
	#endif
};

ChQvCubeMaterials::ChQvCubeMaterials( ChQvCubeInstance* pInst) : ChQvMaterialMap()
{
	m_pMat = pInst->GetMaterial();
	// Get the binding
	QvMaterialBinding *pBinding =  pInst->GetMaterialBinding();
	m_binding = (QvMaterialBinding::Binding)(pBinding->value.value);

	m_pRC = pInst->GetRC();
};

ChQvCylinderMaterials::ChQvCylinderMaterials( ChQvCylinderInstance* pInst) : ChQvMaterialMap()
{
	m_pMat = pInst->GetMaterial();
	// Get the binding
	QvMaterialBinding *pBinding =  pInst->GetMaterialBinding();
	m_binding = (QvMaterialBinding::Binding)(pBinding->value.value);

	m_pRC = pInst->GetRC();
};

#if defined(CH_USE_3DR)
void ChQvCylinderMaterials::Set(Dword_t  hRC, G3dHandle_t hGC, int part, bool *pboolEmissive)  // TODO change to Parts
#else
void ChQvCylinderMaterials::Set(ChNrMesh mesh, ChNrFace face, Parts part)
#endif
{	// part 0 == sides, 1 == top, 2== bottom
	int i = 0;
	switch(m_binding)
	{
		case QvMaterialBinding::PER_PART:
		case QvMaterialBinding::PER_PART_INDEXED:
		{
			i = int(part);
			break;
		}

		case QvMaterialBinding::PER_VERTEX_INDEXED:
		case QvMaterialBinding::PER_FACE_INDEXED:
		case QvMaterialBinding::PER_VERTEX:
		case QvMaterialBinding::PER_FACE:
		case QvMaterialBinding::DEFAULT:
		case QvMaterialBinding::NONE:
		case QvMaterialBinding::OVERALL:
		{
			i = 0;
			break;
		}
	}
	#if defined(CH_USE_3DR)
	SetMat( hRC, hGC, i, pboolEmissive);
	#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
	SetMat( mesh, face, -1, i);
	#endif
};


ChQvSphereMaterials::ChQvSphereMaterials( ChQvSphereInstance* pInst) : ChQvMaterialMap()
{
	m_pMat = pInst->GetMaterial();
	// Get the binding
	QvMaterialBinding *pBinding =  pInst->GetMaterialBinding();
	m_binding = (QvMaterialBinding::Binding)(pBinding->value.value);
	if(m_binding == QvMaterialBinding::DEFAULT) m_binding = QvMaterialBinding::OVERALL;

	m_pRC = pInst->GetRC();
};

#if defined(CH_USE_3DR)
void ChQvSphereMaterials::Set(Dword_t  hRC, G3dHandle_t hGC, bool *pboolEmissive)
#else
void ChQvSphereMaterials::Set(ChNrMesh mesh, ChNrFace face)
#endif
{	// part 0 == only possible part
	int i = 0;
	switch(m_binding)
	{
		case QvMaterialBinding::PER_PART:
		case QvMaterialBinding::PER_PART_INDEXED:
		case QvMaterialBinding::PER_VERTEX_INDEXED:
		case QvMaterialBinding::PER_FACE_INDEXED:
		case QvMaterialBinding::PER_VERTEX:
		case QvMaterialBinding::PER_FACE:
		case QvMaterialBinding::DEFAULT:
		case QvMaterialBinding::NONE:
		case QvMaterialBinding::OVERALL:
		{
			i = 0;
			break;
		}
	}
	#if defined(CH_USE_3DR)
	SetMat( hRC, hGC, i, pboolEmissive);
	#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
	SetMat( mesh, face, -1, i);
	#endif
}


ChQvAsciiTextMaterials::ChQvAsciiTextMaterials( ChQvAsciiTextInstance *pInst) : ChQvMaterialMap()
{
	m_pMat = pInst->GetMaterial();
	// Get the binding
	QvMaterialBinding *pBinding =  pInst->GetMaterialBinding();
	m_binding = (QvMaterialBinding::Binding)(pBinding->value.value);
	if(m_binding == QvMaterialBinding::DEFAULT) m_binding = QvMaterialBinding::OVERALL;

	m_pRC = pInst->GetRC();
};

#if defined(CH_USE_3DR)
void ChQvAsciiTextMaterials::Set(Dword_t  hRC, G3dHandle_t hGC, bool *pboolEmissive)
#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
void ChQvAsciiTextMaterials::Set(ChNrMesh mesh, ChNrFace face)
#endif
{	// part 0 == only possible part
	int i = 0;
	switch(m_binding)
	{
		case QvMaterialBinding::PER_PART:
		case QvMaterialBinding::PER_PART_INDEXED:
		case QvMaterialBinding::PER_VERTEX_INDEXED:
		case QvMaterialBinding::PER_FACE_INDEXED:
		case QvMaterialBinding::PER_VERTEX:
		case QvMaterialBinding::PER_FACE:
		case QvMaterialBinding::DEFAULT:
		case QvMaterialBinding::NONE:
		case QvMaterialBinding::OVERALL:
		{
			i = 0;
			break;
		}
	}
	#if defined(CH_USE_3DR)
	SetMat( hRC, hGC, i, pboolEmissive);
	#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
	SetMat( mesh, face, -1, i);
	#endif
};


#if defined(CH_USE_3DR)
#endif

// end of file
