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

#if ( _MSC_VER > 900	 )
#pragma warning( disable: 4237 )
#endif
#include <ChTypes.h>
#include "GxTypes.h"
#include "GxTrnsfm.h"
#include <stdio.h>

/****
 *
 * affine_matrix4_inverse
 *
 * Computes the inverse of a 3D affine matrix; i.e. a matrix with a dimen-
 * sionality of 4 where the right column has the entries (0, 0, 0, 1).
 *
 * This procedure treats the 4 by 4 matrix as a block matrix and
 * calculates the inverse of one submatrix for a significant perform-
 * ance improvement over a general procedure that can invert any non-
 * singular matrix:
 *          --        --          --          --
 *          |          | -1       |    -1      |
 *          | A      0 |          |   A      0 |
 *    -1    |          |          |            |
 *   M   =  |          |     =    |     -1     |
 *          | C      1 |          | -C A     1 |
 *          |          |          |            |
 *          --        --          --          --
 *
 *  where     M is a 4 by 4 matrix,
 *            A is the 3 by 3 upper left submatrix of M,
 *            C is the 1 by 3 lower left submatrix of M.
 *
 * Input:
 *   in   - 3D affine matrix
 *
 * Output:
 *   out  - inverse of 3D affine matrix
 *
 * Returned value:
 *   TRUE   if input matrix is nonsingular
 *   FALSE  otherwise
 *
 ***/

bool
affine_matrix4_inverse (GxTransformF_t &in, GxTransformF_t &out)
{
    register  double    det_1;
    double    pos, neg, temp;

#define ACCUMULATE    \
    if (temp >= 0.0)  \
        pos += temp;  \
    else              \
        neg += temp;

//#define PRECISION_LIMIT (1.0e-15)
#define PRECISION_LIMIT (1.0e-7)

    /*
     * Calculate the determinant of submatrix A and determine if the
     * the matrix is singular as limited by the single (or double) precision
     * floating-point data representation.
     */
    pos = neg = 0.0;
    temp =  in[0][0] * in[1][1] * in[2][2];
    ACCUMULATE
    temp =  in[0][1] * in[1][2] * in[2][0];
    ACCUMULATE
    temp =  in[0][2] * in[1][0] * in[2][1];
    ACCUMULATE
    temp = -in[0][2] * in[1][1] * in[2][0];
    ACCUMULATE
    temp = -in[0][1] * in[1][0] * in[2][2];
    ACCUMULATE
    temp = -in[0][0] * in[1][2] * in[2][1];
    ACCUMULATE
    det_1 = pos + neg;

    /* Is the submatrix A singular? */
    if ((det_1 == 0.0) || (fabs(det_1 / (pos - neg)) < PRECISION_LIMIT)) {

        /* Matrix M has no inverse */
        fprintf (stderr, "affine_matrix4_inverse: singular matrix\n");
        return FALSE;
    }

    else {

        /* Calculate inverse(A) = adj(A) / det(A) */
        det_1 = 1.0 / det_1;
        out[0][0] =   ( in[1][1] * in[2][2] -
                                 in[1][2] * in[2][1] )
                               * det_1;
        out[1][0] = - ( in[1][0] * in[2][2] -
                                 in[1][2] * in[2][0] )
                               * det_1;
        out[2][0] =   ( in[1][0] * in[2][1] -
                                 in[1][1] * in[2][0] )
                               * det_1;
        out[0][1] = - ( in[0][1] * in[2][2] -
                                 in[0][2] * in[2][1] )
                               * det_1;
        out[1][1] =   ( in[0][0] * in[2][2] -
                                 in[0][2] * in[2][0] )
                               * det_1;
        out[2][1] = - ( in[0][0] * in[2][1] -
                                 in[0][1] * in[2][0] )
                               * det_1;
        out[0][2] =   ( in[0][1] * in[1][2] -
                                 in[0][2] * in[1][1] )
                               * det_1;
        out[1][2] = - ( in[0][0] * in[1][2] -
                                 in[0][2] * in[1][0] )
                               * det_1;
        out[2][2] =   ( in[0][0] * in[1][1] -
                                 in[0][1] * in[1][0] )
                               * det_1;

        /* Calculate -C * inverse(A) */
        out[3][0] = - ( in[3][0] * out[0][0] +
                                 in[3][1] * out[1][0] +
                                 in[3][2] * out[2][0] );
        out[3][1] = - ( in[3][0] * out[0][1] +
                                 in[3][1] * out[1][1] +
                                 in[3][2] * out[2][1] );
        out[3][2] = - ( in[3][0] * out[0][2] +
                                 in[3][1] * out[1][2] +
                                 in[3][2] * out[2][2] );

        /* Fill in last column */
        out[0][3] = out[1][3] = out[2][3] = 0.0;
        out[3][3] = 1.0;

        return TRUE;
    }
}








