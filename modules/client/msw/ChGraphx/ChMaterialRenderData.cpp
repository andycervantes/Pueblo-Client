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

	Implementation for the ChQvMaterialRenderData - primarily for D3D.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChMaterialRenderData.cpp,v 1.1 1996/07/01 23:08:52 jimd Exp $

#include "grheader.h"

#include "ChRenderData.h"



// Helper classes
class ChMaterialCacheElement
{
	friend class ChQvMaterialRenderData;
	ChNrMaterial	m_mat;

	public:
		ChMaterialCacheElement() : m_mat(0) {};
		ChMaterialCacheElement(const ChNrMaterial mat) :  m_mat(mat)
		{
			#if (defined(CH_USE_D3D))
			if(m_mat) m_mat->AddRef();
			#endif
		};

		inline ChMaterialCacheElement( const ChMaterialCacheElement& m)
			{
				m_mat = m.m_mat;
				#if (defined(CH_USE_D3D))
				if(m_mat) m_mat->AddRef();
				#endif
			};

		virtual ~ChMaterialCacheElement() 
			{ 
				#if (defined(CH_USE_D3D))
				if(m_mat) m_mat->Release();
				#endif
			};

		inline ChMaterialCacheElement& operator=( const ChMaterialCacheElement& m)
			{
				Set(m.m_mat);
				return *this;
			};

		inline void Set(ChNrMaterial mat)
		{
			#if (defined(CH_USE_D3D))
			if(mat && m_mat != mat) mat->AddRef();
			if(m_mat && m_mat != mat) m_mat->Release();
			#endif
			m_mat = mat;
		};
		inline ChNrMaterial GetMaterial() const {return m_mat;};
};

typedef ChMaterialCacheElement *pChMaterialCacheElement;

class ChMaterialCache : public ChSplay<double, ChMaterialCacheElement>
{
	friend class ChQvMaterialRenderData;

	ChMaterialCache() {};
	virtual ~ChMaterialCache() {};

	private:
      inline ChMaterialCache( const ChMaterialCache& ) {}
      inline ChMaterialCache& operator=( const ChMaterialCache& )
      			{
      				return *this;
      			}

};

#if (00 && defined(CH_USE_D3D))
class MaterialReleaser : public 	ChVisitor2<double, ChMaterialCacheElement>  
{
	public:
		 bool Visit( const double& key,  const ChMaterialCacheElement &elt )
				{
					if(elt.GetMaterial())
					{
						elt.GetMaterial()->Release();
						//elt.Set(0);
					}
					return true;
				}
};
#endif


// Material render data

ChQvMaterialRenderData::ChQvMaterialRenderData(QvMaterial *pNode) : ChQvRenderBaseData(pNode)
#if (defined(CH_USE_D3D))
,	m_pCache(0)
#endif
{
	#if (defined(CH_USE_D3D))
 	m_pCache = new ChMaterialCache;
	#endif
}
ChQvMaterialRenderData::~ChQvMaterialRenderData()
{
#if (defined(CH_USE_D3D))
	// Walk cache and clean out

	#if 0
	if (m_pCache)
	{
		MaterialReleaser		zapMaterials;
		m_pCache->Infix( zapMaterials );
	}
	#endif
	delete m_pCache;
	m_pCache = 0;
#endif
}

#if (defined(CH_USE_D3D))
ChNrMaterial ChQvMaterialRenderData::Find(int index)
{
	double key = Key(index);
	return Find(key);
}

ChNrMaterial ChQvMaterialRenderData::Find(const double &key)
{
	ChMaterialCacheElement *pElt;
	ChNrMaterial mat = 0;

	if(m_pCache)
	{
		pElt = m_pCache->Find(key);
		if(pElt)
		{
			mat = pElt->GetMaterial();
		}
	}
	return mat;
}

void ChQvMaterialRenderData::Add(int index, ChNrMaterial mat)
{
	double key = Key(index);
	
	if(!Find(key))
	{
		//mat->AddRef();	// save until we get zapped
		m_pCache->Insert(key, mat);
	}
}

double ChQvMaterialRenderData::Key(int index)
{
	// for RM key is index of 3d matrix [power, specular, emissive]
	// for immediate mode: ???
	QvMaterial *pNode = (QvMaterial *)GetNode();
	int shininessCount = pNode->shininess.num ? pNode->shininess.num : 1;
	int specularCount = pNode->specularColor.num ? pNode->specularColor.num : 1;
	int emissiveCount = pNode->emissiveColor.num ? pNode->emissiveColor.num : 1;
	double i = index % shininessCount;
	double j = index % specularCount;
	double k = index % emissiveCount;

	double dKey = i * specularCount * emissiveCount;
	dKey += j * emissiveCount;
	dKey += k;

	return dKey;
}
#endif
// end of file

