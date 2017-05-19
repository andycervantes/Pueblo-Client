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

	Interface for the Chaco/Qv texture classes.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvTextur.h,v 2.18 1996/06/27 03:44:17 jimd Exp $

#if !defined( _CVTEXTUR_H )
#define _CVTEXTUR_H

class ChQvShapeInstance;
class ChQvAsciiTextInstance;
class ChQvConeInstance;
class ChQvCubeInstance;
class ChQvCylinderInstance;
class ChQvIFSInstance;
class ChQvILSInstance;
class ChQvPointSetInstance;
class ChQvSphereInstance;

#if defined (CH_USE_RLAB) || defined(CH_USE_D3D)
// A wrapper for all the stuff associated with a texture
class ChTexture
{
	protected:
		ChNrImage * m_pImage;
		ChTextureHandle m_texture;
		char * m_pBytes;
		bool	m_boolChroma;
		ChColor m_chromaKey;

	public:
		ChTexture();
		ChTexture( ChRenderContext *pRC, int width, int height, const ChColor& color, bool boolPalette = false );
		ChTexture( ChRenderContext *pRC, const ChColor& color, const CBitmap &alphaBmp, const ChColor *pChroma = 0);
		~ChTexture();
		ChTextureHandle GetHandle() { return m_texture;};
	protected:
		bool Create( int width, int height, const ChColor& color, bool boolPalette = false );
		bool SetAlpha(const CBitmap &alphaBmp);
};
#endif

class ChQvTextureMap
{				  // TODO add bullet proofing in here - it allows bad coordinate indices
					// to go unchallenged
	protected:
		float	 	*m_pTx2;		//  coordinates 
		long		*m_pIndices;
		long		m_numIndices;
		bool		m_boolIsDefault;
		int			m_iMajor;			// Major axis for default 0,1,or 2 (x, y or z)
		int			m_iMinor;			// Minor axis for default 0,1,or 2
		float		m_fMinorOff, m_fMajorOff;
		float		m_fMajorLen;
		ChQvShapeInstance *m_pInst;

	public:
		ChQvTextureMap()  : m_pTx2(0), m_pIndices(0), m_numIndices(0) {};
		ChQvTextureMap( ChQvShapeInstance *pInst );
		virtual ~ChQvTextureMap()
			{
				//if(m_pTx2 && m_boolOurTx2) delete []m_pTx2;
				//if(m_pIndices && m_boolOurIndices) delete []m_pIndices;
			};

		bool IsDefault() {return m_boolIsDefault;};

		// Get the texture s,t values expressed as a 3d pointf
};


class ChQvIndexedTextures : public ChQvTextureMap
{
	protected:

	public:
		ChQvIndexedTextures( ChQvShapeInstance *pInst) : ChQvTextureMap(pInst){};
		ChQvIndexedTextures( ) : ChQvTextureMap(){};
		virtual ~ChQvIndexedTextures()
			{
			};

		int GetIndex(int index)
		{				// convert vertex index to textureindex
			if(m_boolIsDefault)
			{
				return -1;
			}

			return (m_pIndices) ? (m_pIndices[index] * 2) : (index * 2);
		};
		#if defined(CH_USE_3DR)
		PointF_t GetCoord3(int index, float *pVert);
		#else
		GxVec3f GetCoord3(int index, float *pVert);

		#endif
};
class ChQvIFSTextures : public ChQvIndexedTextures
{
	protected:

	public:
		ChQvIFSTextures(  ChQvIFSInstance *ifsInst);
		virtual ~ChQvIFSTextures()
			{
			};

};

class ChQvCubeTextures: public ChQvTextureMap
{
	protected:

	public:
		ChQvCubeTextures( ChQvCubeInstance *pInst ) ;
	   	virtual ~ChQvCubeTextures()
			{
			};

#if defined(CH_USE_3DR)
		PointF_t GetCoord3(int face, int vert);
#else
		GxVec3f GetCoord3(int face, int vert);
#endif

};
#define PI (3.1415927)
 
class ChQvCylinderTextures: public ChQvTextureMap
{
	public:
	protected:
		int m_iNumFacets;
		float m_fStep;

	public:
		ChQvCylinderTextures( ChQvCylinderInstance *pInst, int iNumFacets );

	   	virtual ~ChQvCylinderTextures()
			{
			};

#if defined(CH_USE_3DR)
		PointF_t GetCoord3(int part, int facet, int vert);
#else
		GxVec3f GetCoord3(ChQvCylinderInstance::Parts part, int facet, int vert);
#endif

};

class ChQvConeTextures: public ChQvTextureMap
{
	public:
	//enum Parts { Sides = 0, Bottom = 1 };
	protected:
		int m_iNumFacets;
		float m_fStep;

	public:
		ChQvConeTextures( ChQvConeInstance *pInst, int iNumFacets );
	   	virtual ~ChQvConeTextures()
			{
			};

		#if defined(CH_USE_3DR)
		PointF_t GetCoord3(int part, int facet, int vert);
		#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
		GxVec3f GetCoord3(ChQvConeInstance::Parts part, int facet, int vert);
		#endif

};
 
class ChQvILSTextures: public ChQvIndexedTextures
{
	protected:														 

	public:
		ChQvILSTextures( ChQvILSInstance *pInst);
	   	virtual ~ChQvILSTextures()
			{
			};

};


#endif // _CVTEXTUR_H
