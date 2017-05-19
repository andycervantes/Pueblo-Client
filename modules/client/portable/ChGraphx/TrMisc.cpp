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

#include <TrBasic.h>
#include <time.h>
#include <math.h>

#ifdef __STDC__
extern double log2(double);
#else
extern double log2();
#endif

/* globals */
node_t qs[QSIZE];		/* Query structure */
trap_t tr[TRSIZE];		/* Trapezoid structure */
segment_t seg[SEGSIZE];		/* Segment table */

struct global_s global;

/* This is horribly lame, but should work. */
double log2(double x)
{
	return (log(x) / 0.69314718);
}

static int choose_idx;
static int permute[SEGSIZE];

/* Generate a random permutation of the segments 1..n */
int generate_random_ordering(int n)
{
#if 0
  struct timeval tval;
  struct timezone tzone;
#endif
  register int i;
  int m, st[SEGSIZE], *p;
  
  choose_idx = 1;
#if 0
  gettimeofday(&tval, &tzone);
  srand48(tval.tv_sec);
#else
  srand(time(0));
#endif
  for (i = 0; i <= n; i++)
    st[i] = i;

  p = st;
  for (i = 1; i <= n; i++, p++)
    {
#if 0
      m = lrand48() % (n + 1 - i) + 1;
#else
      m = rand() % (n + 1 - i) + 1;
#endif
      permute[i] = p[m];
      if (m != 1)
	p[m] = p[1];
    }
  return 0;
}

  
/* Return the next segment in the generated random ordering of all the */
/* segments in S */
int choose_segment()
{
/*  
#ifdef DEBUG
  fprintf(stderr, "choose_segment: %d\n", permute[choose_idx]);
#endif 
  return permute[choose_idx++];
*/

#ifdef CHOOSE_MANUAL
  int i;

  printf("Enter seg: ");
  scanf("%d", &i);
  return i;
#else
  
#ifdef DEBUG
  TRACE("choose_segment: %d\n", permute[choose_idx]);
#endif 
  return permute[choose_idx++];
#endif
}


int inserted(int segnum, int whichpt)
{
  int n1, n2;

  n1 = segnum % global.nseg + 1; /* next seg. */
  n2 = (segnum - 1 + global.nseg - 1) % global.nseg + 1; /* prev. */ 

  if (whichpt == FIRSTPT)
    return seg[n2].is_inserted;
  else
    return seg[n1].is_inserted;
}


#ifdef STANDALONE

/* Read in the list of vertices from infile */
int read_segments(FILE *infile)
{
  int nseg;
  register int i;

  memset((void *)seg, 0, sizeof(seg));
  i = 1; 
  nseg = 0;
  while (fscanf(infile, "%lf%lf", &seg[i].v0.x, &seg[i].v0.y) == 2)
    {
      seg[i - 1].v1.x = seg[i].v0.x;
      seg[i - 1].v1.y = seg[i].v0.y;
      seg[i].is_inserted = FALSE;
      i++;
      nseg++;
    }
  seg[nseg].v1.x = seg[1].v0.x;
  seg[nseg].v1.y = seg[1].v0.y;
  
  global.nseg = nseg;
  return nseg;
}

#endif


/* Get log*n for given n */
int math_logstar_n(int n)
{
  register int i;
  double v;
  
  for (i = 0, v = (double) n; v >= 1; i++)
    v = log2(v);
  
  return (i - 1);
}
  

int math_N(int n, int h)
{
  register int i;
  double v;

  for (i = 0, v = (int) n; i < h; i++)
    v = log2(v);
  
  return (int) ceil((double) 1.0*n/v);
}
