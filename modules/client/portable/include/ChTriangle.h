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

	Triangulator for Chaco VRML.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/portable/include/ChTriangle.h,v 1.4 1996/09/14 22:28:47 pritham Exp $
#ifndef _CHTRIANGLE_H_
#define _CHTRIANGLE_H_
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <afx.h>

#if ( _MSC_VER > 900	 )
#pragma warning( disable: 4237 )
#endif

#include <ChTypes.h>
#include <GxTypes.h>

/* #define STANDALONE */
//#define DEBUG

// Triangulation exception
typedef struct {
	int val;
} ChExTriangulation;

extern ChExTriangulation CH_EX_TRIANGULATION;
 
typedef struct {
  double x, y;
  //unsigned long data;		// user data to track points
} point_t, vector_t;

typedef struct {
  point_t v0, v1;
  int is_inserted;
  int root0, root1;
} segment_t;

typedef struct {
  int lseg, rseg;
  point_t hi, lo;
  int u0, u1;
  int d0, d1;
  int sink;
  int usave, uside;
  int state;
} trap_t;

typedef struct {
  int nodetype;
  int segnum;
  point_t yval;
  int trnum;
  int parent;
  int left, right;
} node_t;

typedef struct {
  int vnum;
  int next;
  int prev;
} monchain_t;

typedef struct {
  point_t pt;
  int vnext[4];			/* next vertices for the 4 chains */
  int vpos[4];			/* position of v in the 4 chains */
  int nextfree;
} vertexchain_t;

struct global_s {
  int nseg;
};

#define T_X     1
#define T_Y     2
#define T_SINK  3

//#define QSIZE   1600		/* maximum table sizes */
//#define TRSIZE  800		/* max# trapezoids */
//#define SEGSIZE 200		/* max# of segments */

#define TRUE  1
#define FALSE 0

#define FIRSTPT 1		/* checking whether pt. is inserted */ 
#define LASTPT  2

#define EPS 0.000005

#define INFINITY 1<<30

#define C_EPS 1.0e-7

#define S_LEFT 1		/* for merge-direction */
#define S_RIGHT 2

#define ST_VALID 1		/* for trapezium table */
#define ST_INVALID 2

#define SP_SIMPLE_LRUP 1	/* for splitting trapezoids */
#define SP_SIMPLE_LRDN 2
#define SP_2UP_2DN     3
#define SP_2UP_LEFT    4
#define SP_2UP_RIGHT   5
#define SP_2DN_LEFT    6
#define SP_2DN_RIGHT   7
#define SP_NOSPLIT    -1	

#define TR_FROM_UP 1		/* for traverse-direction */
#define TR_FROM_DN 2

#define TRI_LHS 1
#define TRI_RHS 2


#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#define CROSS(v0, v1, v2) (((v1).x - (v0).x)*((v2).y - (v0).y) - \
			   ((v1).y - (v0).y)*((v2).x - (v0).x))

#define DOT(v0, v1) ((v0).x * (v1).x + (v0).y * (v1).y)

#define MODULO_NEXT(v0, n) (((v0) - 1) % (n) + 1)

#define FP_EQUAL(s, t) (fabs(s - t) <= C_EPS)

int lines_intersect( float x1, float y1,   /* First line segment */
		     float x2, float y2,

		     float x3, float y3,   /* Second line segment */
		     float x4, float y4,

		     float &x,
		     float &y         /* Output value:
		                * point of intersection */
               );

class ChTriangulator
{
// Implementation
	public:
		ChTriangulator();
		virtual ~ChTriangulator();

		bool Attach(long *coordIndex, GxVec3f *points, int count);

		int GetCount();
		bool GetTriangle(int triIndex, int *vertIndex);

		bool Iterate();

		virtual bool DoTriangle( int triIndex, int *vertIndex ) {return true;};

	protected:
		int generate_random_ordering(int n);
		int construct_trapezoids(int nseg, segment_t *seg);
		int monotonate_trapezoids(int n);
		int triangulate_monotone_polygons(int nmonpoly, int op[][3]);
		int inserted(int segnum, int whichpt);
		int choose_segment();
		int init_query_structure(int segnum);
		int math_logstar_n(int n);
		int math_N(int n, int h);
		int _greater_than(point_t *v0, point_t *v1);
		int traverse_polygon(int mcur, int trnum, int from, int dir);
		int _equal_to(point_t *v0, point_t *v1);
		int _greater_than_equal_to(point_t *v0, point_t *v1);
		int _less_than(point_t *v0, point_t *v1);
		int triangulate_single_polygon(int posmax, int side, int op[][3]);

		int newnode();
		int  newtrap();
		int is_left_of(int segnum, point_t *v);
		int is_collinear(int segnum, point_t *v, int is_swapped);
		int locate_endpoint(point_t *v, point_t *vo, int r);
		int merge_trapezoids(int segnum, int tfirst, int tlast, int side);
		int add_segment(int segnum);
		int find_new_roots(int segnum);

		int inside_polygon(trap_t *t);
		int newmon();
		int new_chain_element();
		double get_angle(point_t *vp0, point_t *vpnext, point_t *vp1);  //static?
		int get_vertex_positions(int v0, int v1, int *ip, int *iq);
		int make_new_monotone_poly(int mcur, int v0, int v1);

		int init(int count);
		int triangulate();
		int project(long *coordIndex, GxVec3f *points, int count);
		void kill();
		bool IsSelfIntersecting();
		bool ZapCollinears();


	protected:

		int				m_segSize;
		int				m_qSize;
		int				m_trSize;
						
		typedef int		triangle_it[3];
						
		node_t 			*qs;			/* Query structure */
		trap_t 			*tr;			/* Trapezoid structure */
		segment_t 		*seg;			/* Segment table */
						
		int 			q_idx;
		int 			tr_idx;
						
		monchain_t		*mchain;		/* Table to hold all the monotone */
										/* polygons . Each monotone polygon */
										/* is a circularly linked list */

		vertexchain_t	*vert;			/* chain init. information. This */
							    		/* is used to decide which */
							    		/* monotone polygon to split if */
							    		/* there are several other */
							    		/* polygons touching at the same */
							    		/* vertex  */

		int 			*mon;			/* contains position of any vertex in */
										/* the monotone chain for the polygon */
		int 			*visited;	
		int 			chain_idx, op_idx, mon_idx;
						
		struct global_s global;

		int 			choose_idx;
		int 			*permute;
						
		triangle_it		*m_triangles;
						
		int 			m_count;
		bool			m_boolReflected;

};

#endif // _CHTRIANGLE_H_
