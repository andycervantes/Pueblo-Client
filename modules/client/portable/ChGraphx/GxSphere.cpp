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

	This file contains the implementation for VRML Sphere classes.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/portable/ChGraphx/GxSphere.cpp,v 1.8 1996/06/27 03:44:30 jimd Exp $

#ifndef _GX_SPHERE_C_
#define _GX_SPHERE_C_

#include "GxSphere.h"

#define TESS_LAT_LONG	1

/*----------------------------------------------------------------------------
	GxSphere class static members
----------------------------------------------------------------------------*/

int		GxSphere::iOctantOrdering[8][3] = { { 1, 1, 1 },
											{-1, 1, 1 },
											{-1,-1, 1 },
											{ 1,-1, 1 },
											{ 1,-1,-1 },
											{ 1, 1,-1 },
											{-1, 1,-1 },
											{-1,-1,-1 } };

int		GxSphere::iOctantDirection[8] = { 1, -1, 1, -1, 1, -1, 1, -1 };


/*----------------------------------------------------------------------------
	GxSphere class
----------------------------------------------------------------------------*/

GxSphere::GxSphere( int level )
{
	if ( level < 1 ) level = 1;

	m_pLevel = level;

	m_pNumVerts  = VertsInLevel( level );
	m_pVertices  = new GxVec3f[m_pNumVerts];
	m_pTexCoords = new GxVec2f[m_pNumVerts];

	if ( !m_pVertices || !m_pTexCoords )
	{
		Kill();
		return;
	}

	Tessellate();
}

GxSphere::GxSphere( const GxSphere& sphere )
{
	Copy( sphere );
}

GxSphere::~GxSphere()
{
	Kill();
}

int GxSphere::VertsInLevel( int lvl )
{
	#if defined(TESS_LAT_LONG)
	return ((lvl+1)*lvl) + 1;
	#else
	return ((lvl+1)*(lvl+2))/2;
	#endif
}

int GxSphere::TrisInLevel( int lvl )
{
	#if defined(TESS_LAT_LONG)
	return lvl*lvl;
	#else
	return (lvl * (lvl - 1) * 2 + lvl);
	#endif
}


GxSphere& GxSphere::operator=( const GxSphere& sphere )
{
	if (this != &sphere)
	{
		Kill();
		Copy( sphere );
	}

	return *this;
}

void GxSphere::Tessellate()
{
	#if defined(TESS_LAT_LONG)
						// Tesselate one octant
						// as (level - 1) rows of lat/log rectangles
						// plus one row of triangles at North Pole
	double x, y, z, s, t;
	for (int i = 0, v = 0; i < m_pLevel; i++)
	{
						// For this latitude band, with north being up..
						// starting at the equator
		double lat = M_PI / 2. * float(i) / m_pLevel;
		y = sin(lat);
		double cosLat = cos(lat);	  // compiler bug - making this float breaks things
		t = .5 - float(i) / m_pLevel / 2;

		for ( int j = 0; j <= m_pLevel; j++ )
		{
								  	// Do a point of longitude
			double longitude = M_PI / 2. * float(j) / m_pLevel;
			x = sin(longitude) * cosLat;
									// Cheapest way I know to get z,
			z = sqrt(1 - (x * x + y * y));
			m_pVertices[v].set( x, y, z );
									// Compute s and set s,t (or u,v)
									// s goes from 0 to .25
									// t goes from .5 at equator to 0 at NP 
			s = float(j) / m_pLevel / 4;
			 
			m_pTexCoords[v].set( s, t );
			v++;
		}
	}
	m_pVertices[v].set( 0, 1, 0 );	// North pole xyz
	m_pTexCoords[v].set( 0, 0 );   // North pole uv

	#else  // old triangle tesselator
	double x, y, z, s, t;

	for (int i = 0, v = 0; i <= m_pLevel; i++)
	{
		y = i;
		y /= m_pLevel;
		y = 1 - y;
		t = atan2( 1-y, y )/M_PI;

		for ( int j = 0; j <= i; j++ )
		{
			x = j; x /= m_pLevel;
			z = 1 - x - y;
			m_pVertices[v].set( x, y, z );
			m_pVertices[v].normalize();

			// t = asin(1. - m_pVertices[v].y()) / M_PI;	// jwd squashed at equator
			t = .5 - asin(m_pVertices[v].y()) / M_PI;	// jwd
			if ( i )
			{
				s = j; s /= i;
				s = 0.5*atan2( s, 1-s )/M_PI;
				//s = 0.5 * atan2( m_pVertices[v].x(), m_pVertices[v].z() ) / M_PI;	// jwd
			}
			else
			{
				s = 0;
			}

			m_pTexCoords[v].set( s, t );
			v++;
		}
	}
	#endif
}


void GxSphere::Kill()
{
	delete[] m_pVertices; m_pVertices = 0;
	delete[] m_pTexCoords; m_pTexCoords = 0;
	m_pLevel = 0;
	m_pNumVerts = 0;
}


void GxSphere::Copy( const GxSphere& sphere )
{
	m_pLevel = 0;
	m_pNumVerts = 0;

	if (sphere.m_pVertices)
	{
		m_pVertices  = new GxVec3f[sphere.m_pNumVerts];
		m_pTexCoords = new GxVec2f[sphere.m_pNumVerts];

		if ( !m_pVertices || !m_pTexCoords )
		{
			Kill();
			return;
		}

		m_pLevel = sphere.m_pLevel;
		m_pNumVerts = sphere.m_pNumVerts;

		for ( int i = 0; i < m_pNumVerts; i++ )
		{
			m_pVertices[i]  = sphere.m_pVertices[i];
			m_pTexCoords[i] = sphere.m_pTexCoords[i];
		}
	}
}


/*----------------------------------------------------------------------------
	GxSphereVertexIterator class
----------------------------------------------------------------------------*/

GxSphereVertexIterator::GxSphereVertexIterator()
{
	m_pSphere = 0;
}


GxSphereVertexIterator::GxSphereVertexIterator( const GxSphere& sph )
{
	Attach( sph );
}


GxSphereVertexIterator::~GxSphereVertexIterator()
{
}


void GxSphereVertexIterator::Attach( const GxSphere& sph )
{
	m_pSphere = &sph;
}


int GxSphereVertexIterator::NumVertices() const
{
	if (m_pSphere)
	{
		return 8 * m_pSphere->NumVerts();
	}
	else
	{
		return 0;
	}
}

int GxSphereVertexIterator::Iterate()
{
	if ( !m_pSphere )
		return 0;

	GxVec3f*	vs = m_pSphere->Vertices();
	int			nvs = m_pSphere->NumVerts();
	GxVec3f		v;

	for (int i = 0, nv = 0; i < 8; i++)
	{
		int		sx = (GxSphere::iOctantOrdering[i][0] > 0 ? 1 : -1 );
		int		sy = (GxSphere::iOctantOrdering[i][1] > 0 ? 1 : -1 );
		int		sz = (GxSphere::iOctantOrdering[i][2] > 0 ? 1 : -1 );

		for (int j = 0; j < nvs; j++)
		{
			v[0] = vs[j][0]*sx;
			v[1] = vs[j][1]*sy;
			v[2] = vs[j][2]*sz;

			DoVertex( nv++, v );
		}
	}

	return 1;
}


int GxSphereVertexIterator::DoVertex( int, const GxVec3f& )
{
	return 1;
}


/*----------------------------------------------------------------------------
	GxSphereTriangleIterator class
----------------------------------------------------------------------------*/

GxSphereTriangleIterator::GxSphereTriangleIterator()
{
	m_pSphere = 0;
}

GxSphereTriangleIterator::GxSphereTriangleIterator( const GxSphere& sph )
{
	Attach( sph );
}

GxSphereTriangleIterator::~GxSphereTriangleIterator()
{
}


void GxSphereTriangleIterator::Attach( const GxSphere& sph )
{
	m_pSphere = &sph;
}


int GxSphereTriangleIterator::NumTriangles() const
{
	if (m_pSphere)
	{
		return 8 * GxSphere::TrisInLevel( m_pSphere->Level() );
	}
	else
	{
		return 0;
	}
}


int GxSphereTriangleIterator::Iterate( GxSphere::IType itp )
{
	if (!m_pSphere)
	{
		return 0;
	}

	// This needs to be fixed for lat/long tesselation!!
	#if defined(TESS_LAT_LONG)
	if ( !m_pSphere ) return 0;

	int level = m_pSphere->Level();

	GxVec3f* vs = m_pSphere->Vertices();
	int nvs = m_pSphere->NumVerts();
	int nts = GxSphere::TrisInLevel( level );

	int tri = 0;
	for ( int i = 0; i < 8; i++ )
	{
		int vbase = i*nvs;

		int isclk = ( GxSphere::iOctantDirection[i] == -1 );

		int sx = (GxSphere::iOctantOrdering[i][0] > 0 ? 1 : -1 );
		int sy = (GxSphere::iOctantOrdering[i][1] > 0 ? 1 : -1 );
		int sz = (GxSphere::iOctantOrdering[i][2] > 0 ? 1 : -1 );


		if ( itp == GxSphere::Indexed )
		{
			// Do the latitudinal belts of rectangles
			// level - 1 belts
			// level rects in each belt
			// This means 2 * level tris in a belt
			// in each belt.
			for ( int j = 0, top = 0, bot = level + 1; j < level - 1; j++ )
			{

				for ( int k = 0; k < level; k++ )
				{
					int a = vbase + top++, b = vbase + bot++;
					int c = vbase + top, d = vbase + bot;
					if ( isclk )
					{
						GxSwap( a, b );
						GxSwap( c, d );
					}
					if ( !DoTriangle( tri++, a, b, c ) ) return 0;
					if ( !DoTriangle( tri++, c, b, d ) ) return 0;
				}
				top ++;
				bot ++;

			}

			// Do the polar triangles 
			for (  j = 0; j < level; j++ )
			{

				int pole = vbase + nvs - 1;
				int a = vbase + (level + 1) * (level - 1) + j;
				int b = a + 1;
				if ( isclk ) GxSwap( a, b );
				if ( !DoTriangle( tri++, a, pole, b ) ) return 0;

			}
		}
		else
		{
			#if 0
			for ( int j = 0, top = 0, bot = 1; j < level; j++ )
			{
				if ( !StartStrip( strip ) ) return 0;

				for ( int k = 0; k <= j; k++ )
				{
					int a = top++, b = bot++;
					if ( isclk ) GxSwap( a, b );

					GxVec3f va, vb;
					va[0] = vs[a][0]*sx, va[1] = vs[a][1]*sy, va[2] = vs[a][2]*sz;
					vb[0] = vs[b][0]*sx, vb[1] = vs[b][1]*sy, vb[2] = vs[b][2]*sz;

					if ( !DoVertex( va ) ) return 0;
					if ( !DoVertex( vb ) ) return 0;
				}

				int c = bot++;
				GxVec3f vc;
				vc[0] = vs[c][0]*sx, vc[1] = vs[c][1]*sy, vc[2] = vs[c][2]*sz;

				if ( !DoVertex( vc ) ) return 0;

				if ( !StopStrip( strip++ ) ) return 0;
			}
			#else
			//ASSERT(0);
			#endif
		}
	}

	return 1;
	#else
	int			level = m_pSphere->Level();
	GxVec3f*	vs = m_pSphere->Vertices();
	int			nvs = m_pSphere->NumVerts();
	int			nts = GxSphere::TrisInLevel( level );

	for (int i = 0, tri = 0; i < 8; i++)
	{
		int		vbase = i * nvs;
		int		isclk = ( GxSphere::iOctantDirection[i] == -1 );
		int		sx = (GxSphere::iOctantOrdering[i][0] > 0 ? 1 : -1 );
		int		sy = (GxSphere::iOctantOrdering[i][1] > 0 ? 1 : -1 );
		int		sz = (GxSphere::iOctantOrdering[i][2] > 0 ? 1 : -1 );

		for (int j = 0, top = 0, bot = 1; j < level; j++)
		{
			for ( int k = 0; k < j; k++ )
			{
				if (!TriOut( tri, vbase, top, bot, bot+1, top+1, isclk, itp,
								vs, sx, sy, sz ))
				{
					return 0;
				}

				top++;
				bot++;
				tri += 2;
			}

			if (!TriOut( tri, vbase, top, bot, bot+1, isclk, itp,
							vs, sx, sy, sz ))
			{
				return 0;
			}

			top++;
			bot += 2;
			tri++;
		}
	}

	return 1;
#endif
}


int GxSphereTriangleIterator::DoTriangle( int, int, int, int )
{
	return 1;
}


int GxSphereTriangleIterator::DoTriangle( int, const GxVec3f&, const GxVec3f&,
											const GxVec3f& )
{
	return 1;
}


/*----------------------------------------------------------------------------
	GxSphereTriangleIterator protected methods
----------------------------------------------------------------------------*/

int GxSphereTriangleIterator::TriOut( int tri, int vbase, int a, int b,
										int c, int d, int isclk,
										GxSphere::IType itp, GxVec3f* vs,
										int sx, int sy, int sz )
{
	int		retval = 0;

	if (isclk)
	{
		GxSwap( a, b );
		GxSwap( c, d );
	}

	if (itp == GxSphere::Indexed)
	{
		a += vbase;
		b += vbase;
		c += vbase;
		d += vbase;

		if (DoTriangle( tri, a, b, c ))
		{
			if ( DoTriangle( tri+1, a, c, d ) )
			{
				retval = 1;
			}
		}
	}
	else
	{
		GxVec3f		va, vb, vc, vd;

		va[0] = vs[a][0]*sx;
		va[1] = vs[a][1]*sy;
		va[2] = vs[a][2]*sz;
		vb[0] = vs[b][0]*sx;
		vb[1] = vs[b][1]*sy;
		vb[2] = vs[b][2]*sz;
		vc[0] = vs[c][0]*sx;
		vc[1] = vs[c][1]*sy;
		vc[2] = vs[c][2]*sz;
		vd[0] = vs[d][0]*sx;
		vd[1] = vs[d][1]*sy;
		vd[2] = vs[d][2]*sz;

		if (DoTriangle( tri, va, vb, vc ))
		{
			if (DoTriangle( tri+1, va, vc, vd ))
			{
				retval = 1;
			}
		}
	}

	return retval;
}

int GxSphereTriangleIterator::TriOut( int tri, int vbase, int a, int b, int c,
				  int isclk, GxSphere::IType itp,
				  GxVec3f* vs, int sx, int sy, int sz )
      {
	 int retval = 0;

	 if ( isclk ) GxSwap( a, b );

	 if ( itp == GxSphere::Indexed )
	 {
	    a += vbase, b += vbase, c += vbase;
	    if ( DoTriangle( tri, a, b, c ) ) retval = 1;
	 }
	 else
	 {
	    GxVec3f va, vb, vc;
	    va[0] = vs[a][0]*sx, va[1] = vs[a][1]*sy, va[2] = vs[a][2]*sz;
	    vb[0] = vs[b][0]*sx, vb[1] = vs[b][1]*sy, vb[2] = vs[b][2]*sz;
	    vc[0] = vs[c][0]*sx, vc[1] = vs[c][1]*sy, vc[2] = vs[c][2]*sz;

	    if ( DoTriangle( tri, va, vb, vc ) ) retval = 1;
	 }

	 return retval;
      }



/*----------------------------------------------------------------------------
	GxSphereTriStripIterator class
----------------------------------------------------------------------------*/

GxSphereTriStripIterator::GxSphereTriStripIterator()
{
	m_pSphere = 0;
}


GxSphereTriStripIterator::GxSphereTriStripIterator( const GxSphere& sph )
{
	Attach( sph );
}


GxSphereTriStripIterator::~GxSphereTriStripIterator()
{
}


void GxSphereTriStripIterator::Attach( const GxSphere& sph )
{
	m_pSphere = &sph;
}


int GxSphereTriStripIterator::NumStrips()
{
	if ( m_pSphere )
	{
		return 8 * m_pSphere->Level();
	}
	else
	{
		return 0;
	}
}


int GxSphereTriStripIterator::Iterate( GxSphere::IType itp )
{
	#if defined(TESS_LAT_LONG)
	if ( !m_pSphere ) return 0;

	int level = m_pSphere->Level();

	GxVec3f* vs = m_pSphere->Vertices();
	int nvs = m_pSphere->NumVerts();
	int nts = GxSphere::TrisInLevel( level );

	for ( int i = 0, strip = 0; i < 8; i++ )
	{
		int vbase = i*nvs;

		int isclk = ( GxSphere::iOctantDirection[i] == -1 );

		int sx = (GxSphere::iOctantOrdering[i][0] > 0 ? 1 : -1 );
		int sy = (GxSphere::iOctantOrdering[i][1] > 0 ? 1 : -1 );
		int sz = (GxSphere::iOctantOrdering[i][2] > 0 ? 1 : -1 );


		if ( itp == GxSphere::Indexed )
		{
			// Do the latitudinal belts of rectangles
			// level - 1 belts
			// level rects in each belt
			// This means 2 * (level + 1) verts as a tristrip
			// in each belt.
			for ( int j = 0, top = 0, bot = level + 1; j < level - 1; j++ )
			{
				if ( !StartStrip( strip ) ) return 0;

				for ( int k = 0; k <= level; k++ )
				{
					int a = vbase + top++, b = vbase + bot++;
					if ( isclk ) GxSwap( a, b );
					if ( !DoVertex( b ) ) return 0;
					if ( !DoVertex( a ) ) return 0;
				}


				if ( !StopStrip( strip++ ) ) return 0;
			}

			// Do the polar triangles - each is a tristrip
			for (  j = 0; j <= level; j++ )
			{
				if ( !StartStrip( strip ) ) return 0;

				int pole = vbase + nvs - 1;
				int a = vbase + (level + 1) * (level - 1) + j;
				int b = a + 1;
				if ( isclk ) GxSwap( a, b );
				if ( !DoVertex( b ) ) return 0;
				if ( !DoVertex( pole ) ) return 0;
 				if ( !DoVertex( a ) ) return 0;

				if ( !StopStrip( strip++ ) ) return 0;
			}
		}
		else
		{
			for ( int j = 0, top = 0, bot = 1; j < level; j++ )
			{
				if ( !StartStrip( strip ) ) return 0;

				for ( int k = 0; k <= j; k++ )
				{
					int a = top++, b = bot++;
					if ( isclk ) GxSwap( a, b );

					GxVec3f va, vb;
					va[0] = vs[a][0]*sx, va[1] = vs[a][1]*sy, va[2] = vs[a][2]*sz;
					vb[0] = vs[b][0]*sx, vb[1] = vs[b][1]*sy, vb[2] = vs[b][2]*sz;

					if ( !DoVertex( va ) ) return 0;
					if ( !DoVertex( vb ) ) return 0;
				}

				int c = bot++;
				GxVec3f vc;
				vc[0] = vs[c][0]*sx, vc[1] = vs[c][1]*sy, vc[2] = vs[c][2]*sz;

				if ( !DoVertex( vc ) ) return 0;

				if ( !StopStrip( strip++ ) ) return 0;
			}
		}
	}

	return 1;
	#else
   if ( !m_pSphere )
      return 0;

   int level = m_pSphere->Level();

   GxVec3f* vs = m_pSphere->Vertices();
   int nvs = m_pSphere->NumVerts();
   int nts = GxSphere::TrisInLevel( level );

   for ( int i = 0, strip = 0; i < 8; i++ )
   {
      int vbase = i*nvs;

      int isclk = ( GxSphere::iOctantDirection[i] == -1 );

      int sx = (GxSphere::iOctantOrdering[i][0] > 0 ? 1 : -1 );
      int sy = (GxSphere::iOctantOrdering[i][1] > 0 ? 1 : -1 );
      int sz = (GxSphere::iOctantOrdering[i][2] > 0 ? 1 : -1 );


      if ( itp == GxSphere::Indexed )
      {
	 for ( int j = 0, top = 0, bot = 1; j < level; j++ )
	 {
	    if ( !StartStrip( strip ) ) return 0;

	    for ( int k = 0; k <= j; k++ )
	    {
	       int a = vbase + top++, b = vbase + bot++;
	       if ( isclk ) GxSwap( a, b );
	       if ( !DoVertex( a ) ) return 0;
	       if ( !DoVertex( b ) ) return 0;
	    }

	    if ( !DoVertex( vbase + bot++ ) ) return 0;

	    if ( !StopStrip( strip++ ) ) return 0;
	 }
      }
      else
      {
	 for ( int j = 0, top = 0, bot = 1; j < level; j++ )
	 {
	    if ( !StartStrip( strip ) ) return 0;

	    for ( int k = 0; k <= j; k++ )
	    {
	       int a = top++, b = bot++;
	       if ( isclk ) GxSwap( a, b );

	       GxVec3f va, vb;
	       va[0] = vs[a][0]*sx, va[1] = vs[a][1]*sy, va[2] = vs[a][2]*sz;
	       vb[0] = vs[b][0]*sx, vb[1] = vs[b][1]*sy, vb[2] = vs[b][2]*sz;

	       if ( !DoVertex( va ) ) return 0;
	       if ( !DoVertex( vb ) ) return 0;
	    }

	    int c = bot++;
	    GxVec3f vc;
	    vc[0] = vs[c][0]*sx, vc[1] = vs[c][1]*sy, vc[2] = vs[c][2]*sz;

	    if ( !DoVertex( vc ) ) return 0;

	    if ( !StopStrip( strip++ ) ) return 0;
	 }
      }
   }

   return 1;
	#endif	// TESS_LAT_LONG
}


int GxSphereTriStripIterator::StartStrip( int )
{
	return 1;
}


int GxSphereTriStripIterator::StopStrip( int )
{
	return 1;
}


int GxSphereTriStripIterator::DoVertex( int )
{
	return 1;
}


int GxSphereTriStripIterator::DoVertex( const GxVec3f& )
{
	return 1;
}


/*----------------------------------------------------------------------------
	GxSphereTextureIterator class
----------------------------------------------------------------------------*/

GxSphereTextureIterator::GxSphereTextureIterator()
{
	m_pSphere = 0;
}


GxSphereTextureIterator::GxSphereTextureIterator( const GxSphere& sph )
{
	Attach( sph );
}


GxSphereTextureIterator::~GxSphereTextureIterator()
{
}


void GxSphereTextureIterator::Attach( const GxSphere& sph )
{
	m_pSphere = &sph;
}


int GxSphereTextureIterator::NumTextures() const
{
	if (m_pSphere)
	{
		return 8*m_pSphere->NumVerts();
	}
	else
	{
		return 0;
	}
}


int GxSphereTextureIterator::Iterate()
{
   if ( !m_pSphere )
      return 0;

   GxVec2f* ts = m_pSphere->TexCoords();
   int nvs = m_pSphere->NumVerts();

   GxVec2f t;

   for ( int i = 0, nv = 0; i < 8; i++ )
   {
      int sx = (GxSphere::iOctantOrdering[i][0] > 0 ? 1 : -1 );
      int sy = (GxSphere::iOctantOrdering[i][1] > 0 ? 1 : -1 );
      int sz = (GxSphere::iOctantOrdering[i][2] > 0 ? 1 : -1 );

      float u1 = 0;

									  // Corrected to correspond exactly to VRML uv coords
									  // by jwd 3/28/96

									  // u = 0 is at back seam, then advances CCW as
									  // seen from NP. ( i.e., looking from y > 0) 

      if ( sx < 0 && sz < 0 ) u1 = 0.0;				   // 0.0 <= u <= .25
      else if ( sx < 0 && sz > 0 ) u1 = 0.5;		   // .25 <= u <= .50
      else if ( sx > 0 && sz > 0 ) u1 = 0.5;		   // .50 <= u <= .75
      else if ( sx > 0 && sz < 0 ) u1 = 1.0;		   // .75 <= u <= 1.0

      float v1 = ( sy > 0 ? 1 : 0 );

      for ( int j = 0; j < nvs; j++ )
      {
		 t[0] = u1 + sx*sz*ts[j][0];
		 t[1] = v1 - sy*ts[j][1];		 // VRML goes from bottom up; south pole is v = 0
		 if ( !DoTexture( nv++, t ) ) return 0;
      }

	  #if 0
      if ( sx > 0 && sz < 0 ) u1 = 0.5;
      else if ( sx < 0 && sz < 0 ) u1 = 0.5;
      else if ( sx < 0 && sz > 0 ) u1 = 1.0;

      float v1 = ( sy < 0 ? 1 : 0 );

      for ( int j = 0; j < nvs; j++ )
      {
		 t[0] = u1 + sx*sz*ts[j][0];
		 t[1] = v1 + sy*ts[j][1];
		 if ( !DoTexture( nv++, t ) ) return 0;
      }
	  #endif

   }

   return 1;
}


int GxSphereTextureIterator::DoTexture( int, const GxVec2f& )
{
	return 1;
}


#endif //_GX_SPHERE_C_
