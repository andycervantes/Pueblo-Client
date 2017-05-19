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

	Interface for the Chaco/Qv material classes.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvMaterl.h,v 2.21 1996/06/27 03:44:08 jimd Exp $

#if !defined( _CVMATERL_H )
#define _CVMATERL_H
#include "CvConvrt.h"

inline bool IsBlack(ChColorA &color)
	{return (color.r() <= 0.0 && color.g()	<= 0.0 && color.b() <= 0.0);};
#if defined(CH_USE_3DR)
inline bool IsBlack(ChColor &color)
	{return (color.r() <= 0.0 && color.g()	<= 0.0 && color.b() <= 0.0);};

inline bool IsBlack(ColorF_t &color)
	{return (color.r <= 0.0 && color.g	<= 0.0 && color.b <= 0.0);};
inline bool IsBlack(ColorFA_t &color)
	{return (color.r <= 0.0 && color.g	<= 0.0 && color.b <= 0.0);};

#endif

class ChQvIFSInstance;
class ChQvShapeInstance;
class ChQvAsciiTextInstance;
class ChQvConeInstance;
class ChQvCubeInstance;
class ChQvCylinderInstance;
class ChQvIFSInstance;
class ChQvILSInstance;
class ChQvPointSetInstance;
class ChQvSphereInstance;
class ChQvMaterialMap;

////////////////////////////////
// A single material first 
////////////////////////////////
class ChMaterial 
{
	friend class ChQvMaterialMap;

	protected:
		ChColor m_ambient;
		ChColor m_diffuse;
		ChColor m_specular;
		ChColor m_emissive;
		float	m_shininess;
		float	m_transparency;

	public:
		ChMaterial() : 
			m_ambient(.2, .2, .2),
			m_diffuse(.8, .8, .8),
			m_specular(0, 0, 0),      
			m_emissive(0, 0, 0),
			m_shininess(.2),
			m_transparency(0)
		{};
		~ChMaterial() {};

		ChColor &GetAmbient() { return m_ambient; };
		ChColor &GetDiffuse() { return m_diffuse; };
		ChColor &GetSpecular() { return m_specular; };
		ChColor &GetEmissive() { return m_emissive; };
		float	&GetShininess() { return m_shininess; };
		float	GetNativeShininess();
		float	&GetTransparency() { return m_transparency; };
		ChColor GetBase();
		bool IsPrelit();
};

 
class ChQvMaterialMap
{
	protected:
		QvMaterial	*m_pMat;		//  current material list 
		long		*m_pIndices;
		long		m_numIndices;
		QvMaterialBinding::Binding m_binding;
									// cache index and emissive flag for performance.
		long 		m_lastI;
		bool		m_boolEmissive;
		ChRenderContext	*m_pRC;

		#if (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
		ChSplay<unsigned long, ChNrMaterial>	m_materialCache;
		#endif

		#if defined(CH_USE_3DR)
		void SetMat( ChNativeContext  hRC, G3dHandle_t hGC, long index,  bool *pboolEmissive = 0);
		#else
		void SetMat(ChNrMesh mesh, ChNrFace face, int vertIndex = -1, long index = 0);
		#endif

	public:
		ChQvMaterialMap( ) : m_pMat(0), m_pIndices(0), m_lastI(-2), m_pRC(0) {};
		#if 0 && defined(CH_USE_3DR)
		ChQvMaterialMap( ChQvIFSInstance *ifsInst);
		#endif
		virtual ~ChQvMaterialMap()
			{
			};

		#if defined(CH_USE_3DR)
		#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
		ChMaterial GetMat( long index );
		#else
		#endif
		float GetMaxTransparency();
};

class ChQvFaceSetMaterials: public ChQvMaterialMap
{
	protected:

	public:
		ChQvFaceSetMaterials( ChQvIFSInstance *ifsInst);
		virtual ~ChQvFaceSetMaterials()
			{
			};
		#if defined(CH_USE_3DR)
		void Set(Dword_t  hRC, G3dHandle_t hGC, int faceNum, int vertex = 0, bool *pboolEmissive = 0);
		#else
		void Set(ChNrMesh mesh, ChNrFace face, int vertIndex, int faceNum, int vertex = 0);
		#endif
};

class ChQvCubeMaterials: public ChQvMaterialMap
{
	protected:

	public:
		ChQvCubeMaterials( ChQvCubeInstance* pInst);
		virtual ~ChQvCubeMaterials()
			{
			};
#if defined(CH_USE_3DR)
		void Set(Dword_t  hRC, G3dHandle_t hGC, int face, bool *pboolEmissive = 0)
		{
			// ignore the binding
			SetMat( hRC, hGC, face, pboolEmissive);
		}
#else
		void Set(ChNrMesh mesh, ChNrFace face)
		{
			// ignore the binding
			SetMat( mesh, face);
		}
#endif


};

class ChQvCylinderMaterials: public ChQvMaterialMap
{
	public:
		enum Parts { Sides = 0, Top = 1, Bottom = 2 };


	public:
		ChQvCylinderMaterials( ChQvCylinderInstance *pInst);
		virtual ~ChQvCylinderMaterials()
			{
			};
		#if defined(CH_USE_3DR)
		void Set(Dword_t  hRC, G3dHandle_t hGC, int part, bool *pboolEmissive = 0);
		#else
		void Set(ChNrMesh mesh, ChNrFace face, Parts part);
		#endif


};

class ChQvConeMaterials: public ChQvMaterialMap
{
	public:
		enum Parts { Sides = 0, Bottom = 1 };

	public:
		ChQvConeMaterials( ChQvConeInstance *pInst);
		virtual ~ChQvConeMaterials()
			{
			};
		#if defined(CH_USE_3DR)
		void Set(Dword_t  hRC, G3dHandle_t hGC, int part, bool *pboolEmissive = 0);
		#else
		void Set(ChNrMesh mesh, ChNrFace face, Parts part);
		#endif



};

class ChQvSphereMaterials: public ChQvMaterialMap
{
	protected:

	public:
		ChQvSphereMaterials( ChQvSphereInstance* pSphereInst);
		virtual ~ChQvSphereMaterials()
			{
			};
		#if defined(CH_USE_3DR)
		void Set(Dword_t  hRC, G3dHandle_t hGC, bool *pboolEmissive = 0);
		#else
		void Set(ChNrMesh mesh, ChNrFace face);
		#endif

};

class ChQvAsciiTextMaterials: public ChQvMaterialMap
{
	protected:

	public:
		ChQvAsciiTextMaterials( ChQvAsciiTextInstance* pInst);
		virtual ~ChQvAsciiTextMaterials()
			{
			};
		#if defined(CH_USE_3DR)
		void Set(Dword_t  hRC, G3dHandle_t hGC, bool *pboolEmissive = 0);
		#elif (defined(CH_USE_RLAB)) || defined(CH_USE_D3D)
		void Set(ChNrMesh mesh, ChNrFace face);
		#endif

};

class ChQvLineSetMaterials: public ChQvMaterialMap
{
	protected:

	public:
		ChQvLineSetMaterials( ChQvILSInstance *ilsInst);
		virtual ~ChQvLineSetMaterials()
			{
			};
		#if defined(CH_USE_3DR)
		void Set(Dword_t  hRC, G3dHandle_t hGC, int faceNum, int vertex = 0, bool *pboolEmissive = 0);
		#else
		void Set(ChNrMesh mesh, ChNrFace face, int vertIndex, int faceNum, int vertex = 0);
		#endif
};

class ChQvPointSetMaterials: public ChQvMaterialMap
{
	protected:
 		int GetIndex( int vertex );

	public:
		ChQvPointSetMaterials( ChQvPointSetInstance *ilsInst);
		virtual ~ChQvPointSetMaterials()
			{
			};
		#if defined(CH_USE_3DR)
		void Set(Dword_t  hRC, G3dHandle_t hGC, int faceNum, int vertex = 0, bool *pboolEmissive = 0);
		#else
		void Set(ChNrMesh mesh, ChNrFace face, int vertIndex, int faceNum, int vertex = 0);
		ChMaterial GetMaterial( int vertex );
		#endif

};

#if defined(CH_USE_3DR)
#endif	 // use 3dr

#endif // _CVMATERL_H
