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

	Triangulator for Chaco VRML - based on Graphics Gems V.

----------------------------------------------------------------------------*/

#include <ChTriangle.h>
// #include "ChTriangle.h"

ChExTriangulation CH_EX_TRIANGULATION = { 666 };

ChTriangulator::ChTriangulator() : 
	m_count(0),
	qs(0),
	tr(0),
	seg(0),
	mchain(0),
	vert(0),
	mon(0),
	visited(0),
	permute(0),
	m_triangles(0)
{
};

ChTriangulator::~ChTriangulator()
{
	kill();
};

bool ChTriangulator::Attach(long *coordIndex, GxVec3f *points, int count)
{
#define TRI_EXCEPTIONS 1
#define TRI_EXCEPTIONS_ALL 1
	#if defined(TRI_EXCEPTIONS)
	try
	#endif
	{
		kill();
		init(count);
		project(coordIndex, points, m_count);
		ZapCollinears();
		if(IsSelfIntersecting())
		{
			return false;
		}
		triangulate();
	}
	#if defined(TRI_EXCEPTIONS)
	catch(ChExTriangulation)
	{
		#if 1
		TRACE("Bad polygon for triangulation:\n");
		for(int i = 0; i< count; i++)
		{
			char buf[200];
			int j = coordIndex[i];
			sprintf(buf, "points[%d] = (%.3g, %.3g, %.3g )\n", j, double(points[j].x()), double(points[j].y()), double(points[j].z()));
			TRACE(buf);
		}
		#endif
		return false;
	}
	#if defined(TRI_EXCEPTIONS_ALL)
	catch(...)
	{
		#if 1
		TRACE("Bad polygon for triangulation:\n");
		for(int i = 0; i< count; i++)
		{
			char buf[200];
			int j = coordIndex[i];
			sprintf(buf, "points[%d] = (%.3g, %.3g, %.3g )\n", j, double(points[j].x()), double(points[j].y()), double(points[j].z()));
			TRACE(buf);
		}
		#endif
		return false;
	}
	#endif
	#endif

	return true;
};

int ChTriangulator::init(int count)
{
	m_count = count;
	// Dynamically allocate

	m_segSize = count + 2;	  // ????
	m_qSize = 8 * m_segSize;
	m_trSize = 4 * m_segSize;

	m_trSize *= 5;	// ff  TODO - figure out better number
	m_qSize *= 5;	// ff

	qs = new node_t[m_qSize];				//[QSIZE];		/* Query structure */
	tr = new trap_t[m_trSize];				//[TRSIZE];		/* Trapezoid structure */
	seg = new segment_t[m_segSize];			//[SEGSIZE];		/* Segment table */
	mchain = new monchain_t[m_trSize];		//[TRSIZE]; 
	vert = new vertexchain_t[m_segSize];	//[SEGSIZE]; /* chain init. information.   */
	mon = new int[m_segSize];				//[SEGSIZE];	/* contains position of any vertex in */
	visited = new int[m_trSize];			//[TRSIZE];
	permute = new int[m_segSize];			//[SEGSIZE];
	m_triangles = new triangle_it[m_segSize];	//[200][3];	  

	// Zap what needs zapping
	memset((void *)seg, 0, (m_segSize) * sizeof(*seg));

	return 0;
};

int ChTriangulator::triangulate()
{
	int nmonopoly;

	global.nseg = m_count;
	generate_random_ordering(m_count);
	construct_trapezoids(m_count, seg);
	nmonopoly = monotonate_trapezoids(m_count);
	triangulate_monotone_polygons(nmonopoly, m_triangles);

	return 0;
};

void ChTriangulator::kill()
{
	//  delete what we dynamically allocated
	delete [] qs;
	delete [] tr;
	delete [] seg;
	delete [] mchain;
	delete [] vert;
	delete [] mon;
	delete [] visited;
	delete [] permute;
	delete [] m_triangles;

};

int ChTriangulator::project(long *coordIndex, GxVec3f *points, int count)
{
	int i;			// TODO handle duplicate points

	// Compute the face normal
	GxVec3f	normal(0,0,0);
	for ( i = 0; i < count; i++ )
	{
		normal += points[coordIndex[i]].cross( points[coordIndex[(i+1) % count]] ) ;
	}

	normal.normalize() ;


	// Find maximal projection of normal on basis vector
	// and use other two dimensions
	int 	ix, iy;

	GxVec3f	normalSave(normal);
	m_boolReflected = false;

	normal.set(fabs(normal.x()), fabs(normal.y()), fabs(normal.z()));
	float mx = max(max(normal.x(), normal.y()), normal.z());
	if(normal.x() >= mx)
	{
		ix = 1;
		iy = 2;
		if(normalSave.x() < 0.) m_boolReflected = true;
	}
	else if(normal.y() >= mx)
	{
		ix = 0;
		iy = 2;
		if(normalSave.y() < 0.) m_boolReflected = true;
	}
	else
	{
		ix = 0;
		iy = 1;
		if(normalSave.z() < 0.) m_boolReflected = true;
	}

	#if 1
	GxVec3f *p = new GxVec3f[count];

	for ( i = 0; i < count; i++ )
	{
		p[i].x() = points[coordIndex[i]][ix];
		p[i].y() = points[coordIndex[i]][iy];
		p[i].z() = 0;
	}

	normal.set(0,0,0);
	for ( i = 0; i < count; i++ )
	{
		normal += p[i].cross( p[(i+1) % count] ) ;
	}

	delete [] p;

	m_boolReflected = normal.z() < 0.0;
	#endif

	const float eps = 1.e-4;

	// Project away
	// Note that seg and the returned triangle indices are one-based.
	//
	// If this is CW, we reflect to force CCW; this is cheaper/easier
	// than reversing order
	//
	// We also bump any values which are dupes, to prevent errors
	// in the convexifier.
	for (i = 1; i <= count; i++) {
		seg[i].is_inserted = FALSE;
	
		seg[i].v0.x = points[coordIndex[i-1]][ix];
		seg[i].v0.y = points[coordIndex[i-1]][iy];
		if(m_boolReflected) seg[i].v0.x = -seg[i].v0.x;	// negate to reflect

		if (i == 1) {
			// fill in v1
			seg[count].v1.x = seg[i].v0.x;
			seg[count].v1.y = seg[i].v0.y;
		} else {
			// perturb dupes 
			if(seg[i].v0.x == seg[i-1].v0.x &&	seg[i].v0.y == seg[i-1].v0.y)
			{
				seg[i].v0.x *= (1+eps);	 
			}

			// fill in v1
			seg[i - 1].v1.x = seg[i].v0.x;
			seg[i - 1].v1.y = seg[i].v0.y;
		}
	}
	// perturb final dupes 
	if(seg[1].v0.x == seg[count].v0.x &&	seg[1].v0.y == seg[count].v0.y)
	{
		seg[1].v0.x *= (1+eps);	 
		seg[count].v1.x = seg[1].v0.x;
	}

	return 0;
}

bool ChTriangulator::IsSelfIntersecting()
{
	int i, j;
	float x, y;
	bool	boolHit = false;
	for (i = 1; i < m_count - 1; i++)
	{
		for (j = i+2; j <= m_count; j++)
		{
			if(j != m_count || i != 1)
			{
				boolHit = lines_intersect( seg[i].v0.x,  seg[i].v0.y,   /* First line segment */
			     				 seg[i].v1.x,  seg[i].v1.y,
								 seg[j].v0.x,  seg[j].v0.y,	  /* Second line segment */
								 seg[j].v1.x,  seg[j].v1.y, 
			    			     x,
						         y );
				if(boolHit)
				{
					return true;
				}
			}
		}
	}
	return false;
}

#define COLLINEAR_EPS (1.e-3)

bool ChTriangulator::ZapCollinears()
{
	#if 0
	int i, j;
	bool	boolHit = false;
	for (i = 1; i <= m_count; i++)
	{
		j = i + 1;
		if(j > m_count) j = 1;

		
		float delta = (seg[j].v1.x - seg[j].v0.x) * (seg[i].v1.y - seg[i].v0.y);
		delta -= (seg[i].v1.x - seg[i].v0.x) * (seg[j].v1.y - seg[j].v0.y);
		if(fabs(delta) < COLLINEAR_EPS)
		{
			seg[i].v1.x += COLLINEAR_EPS * (seg[i].v1.y - seg[i].v0.y);
			seg[j].v0.x = seg[i].v1.x;
			seg[i].v1.y += COLLINEAR_EPS * (seg[i].v1.x - seg[i].v0.x);
			seg[j].v0.y = seg[i].v1.y;
		}
	}
	#endif
	return true;
}


int ChTriangulator::GetCount()
{
	return m_count ? m_count - 2 : 0;
};

bool ChTriangulator::GetTriangle(int triIndex, int *vertIndex)
{
	ASSERT(triIndex < GetCount() && triIndex >= 0);
	if(0 && m_boolReflected)			   // ???? why did i do this??
	{
		vertIndex[0] = m_triangles[triIndex][0] - 1;
		vertIndex[1] = m_triangles[triIndex][2] - 1;
		vertIndex[2] = m_triangles[triIndex][1] - 1;
	}
	else
	{
		vertIndex[0] = m_triangles[triIndex][0] - 1;
		vertIndex[1] = m_triangles[triIndex][1] - 1;
		vertIndex[2] = m_triangles[triIndex][2] - 1;
	}
	return true;
};

bool ChTriangulator::Iterate()
{
	int iv[3];
	for(int j=0; j<m_count-2; j++)
	{
		GetTriangle(j, iv); 		   // not optimal, but I need to handle 
										// order flipping for reflected
		if(!DoTriangle(j, iv)) return false;
	}
	return true;
}
