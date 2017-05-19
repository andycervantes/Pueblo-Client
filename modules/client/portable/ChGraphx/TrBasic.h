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

----------------------------------------------------------------------------*/

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <afx.h>

/* #define STANDALONE */
#define DEBUG

typedef struct {
  double x, y;
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

#define QSIZE   1600		/* maximum table sizes */
#define TRSIZE  800		/* max# trapezoids */
#define SEGSIZE 200		/* max# of segments */

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

extern int generate_random_ordering(int n);
extern int construct_trapezoids(int nseg, segment_t *seg);
extern int monotonate_trapezoids(int n);
extern int triangulate_monotone_polygons(int nmonpoly, int op[][3]);
extern int inserted(int segnum, int whichpt);
extern int choose_segment();
extern int init_query_structure(int segnum);
extern int math_logstar_n(int n);
extern int math_N(int n, int h);
extern int _greater_than(point_t *v0, point_t *v1);
extern int traverse_polygon(int mcur, int trnum, int from, int dir);
extern int _equal_to(point_t *v0, point_t *v1);
extern int _greater_than_equal_to(point_t *v0, point_t *v1);
extern int _less_than(point_t *v0, point_t *v1);
extern int triangulate_single_polygon(int posmax, int side, int op[][3]);

/* globals */

extern node_t qs[QSIZE];		/* Query structure */
extern trap_t tr[TRSIZE];		/* Trapezoid structure */
extern segment_t seg[SEGSIZE];		/* Segment table */

extern struct global_s global;
