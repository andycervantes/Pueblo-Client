// COPYRIGHT:
//
//   (C) Copyright Microsoft Corp. 1993.  All rights reserved.
//
//   You have a royalty-free right to use, modify, reproduce and
//   distribute the Sample Files (and/or any modified version) in
//   any way you find useful, provided that you agree that
//   Microsoft has no warranty obligations or liability for any
//   Sample Application Files which are modified.
//


#include "grheader.h"
#undef HUGE
#include <math.h>
#include "ChGrFont.h"
#include "GxTypes.h"
#include "TrBasic.h"

FIXED FixedFromDouble(double);

template <class aType>
void swap(aType& a, aType& b)
{
	aType tmp;
	tmp = a;
	a = b;
	b = tmp;
}     

int ChPolyPolygonGx3::Convexify(ChPolyPolygonGx3* pPoly, int polyIndex)
{
#if defined(CH_USE_GGEMS_TRI_VERSION)
	int n;
	double vertices[100][2];
	int triangles[200][3];
	int i;
	int nmonopoly;

	TRACE("In Convexify.\n");

	vertices[0][0] = 0.0;
	vertices[0][1] = 0.0;
	vertices[1][0] = 10.0;
	vertices[1][1] = 0.0;
	vertices[2][0] = 20.0;
	vertices[2][1] = 0.0;
	vertices[3][0] = 20.0;
	vertices[3][1] = 5.0;
	vertices[4][0] = 20.0;
	vertices[4][1] = 20.0;
	vertices[5][0] = 0.0;
	vertices[5][1] = 20.0;
	vertices[6][0] = 5.0;
	vertices[6][1] = 10.0;

//#define FAKEPOLY 1

#ifdef FAKEPOLY
	n = 7; // GetPointCount(polyIndex);
#else
	n = GetPointCount(polyIndex);
#endif
	// triangles = new int[n][3];

	memset((void *)seg, 0, sizeof(seg));
	for (i = 1; i <= n; i++) {
		GxVec3f ip = GetPoint(polyIndex, i-1);
		seg[i].is_inserted = FALSE;
	
#ifndef FAKEPOLY
		seg[i].v0.x = ip.x();
		seg[i].v0.y = ip.y();
#else
		seg[i].v0.x = vertices[i-1][0];
		seg[i].v0.y = vertices[i-1][1];
#endif
		if (i == 1) {
			seg[n].v1.x = seg[i].v0.x;
			seg[n].v1.y = seg[i].v0.y;
		} else {
			seg[i - 1].v1.x = seg[i].v0.x;
			seg[i - 1].v1.y = seg[i].v0.y;
		}
	}
	global.nseg = n;
	generate_random_ordering(n);
	construct_trapezoids(n, seg);
	nmonopoly = monotonate_trapezoids(n);
	triangulate_monotone_polygons(nmonopoly, triangles);

	// Add the triangles to the end of pPoly
	for (i = 0; i < n - 2; i++) {
		pPoly->NewPoly();
		pPoly->Append(GetPoint(polyIndex, triangles[i][0]));
		pPoly->Append(GetPoint(polyIndex, triangles[i][1]));
		pPoly->Append(GetPoint(polyIndex, triangles[i][2]));
		pPoly->EndPoly();
	}
#endif	// disabled for now
	return 0;
}


ChPolyPolygonI *ChPolyPolygonI::EndPoly()
{
	// Check the order, and force to match flag

	if(m_direction == dontCare) return this;

	GxVec3f pt0, pt1, fn(0,0,0);
	int polyIndex = GetPolyCount()-1;
	int num = GetPointCount(polyIndex);
	if(num < 3) return this;

	for ( int j = 0; j < num - 1; j++ )
	{
		CPoint q0 = GetPoint(polyIndex, j);
		CPoint q1 = GetPoint(polyIndex, j + 1);

		pt0.set(q0.x, q0.y, 0);
		pt1.set(q1.x, q1.y, 0);
		fn += pt0.cross( pt1 ) ;
	}
	CPoint q0 = GetPoint(polyIndex, j);
	CPoint q1 = GetPoint(polyIndex, 0);

	pt0.set(q0.x, q0.y, 0);
	pt1.set(q1.x, q1.y, 0);
	fn += pt0.cross( pt1 ) ;

	bool boolClockWise = fn.z() < 0.0;

	if(boolClockWise ^ (m_direction == clockwise))
	{
		// Flip the poly
		int start = m_pAccumCounts[polyIndex];
		for( j = 0; j < num / 2; j++ )
		{
			swap(m_pPts[start + j], m_pPts[start + num - 1 - j]);
		}
	}
	 
	return this;
}

ChPolyPolygonGx3 *ChPolyPolygonGx3::EndPoly()
{
	// Check the order, and force to match flag

	if(m_direction == dontCare) return this;

	GxVec3f pt0, pt1, fn(0,0,0);
	int polyIndex = GetPolyCount()-1;
	int num = GetPointCount(polyIndex);
	if(num < 3) return this;

	for ( int j = 0; j < num - 1; j++ )
	{
		GxVec3f q0 = GetPoint(polyIndex, j);
		GxVec3f q1 = GetPoint(polyIndex, j + 1);

		pt0.set(q0.x(), q0.y(), 0);
		pt1.set(q1.x(), q1.y(), 0);
		fn += pt0.cross( pt1 ) ;
	}
	GxVec3f q0 = GetPoint(polyIndex, j);
	GxVec3f q1 = GetPoint(polyIndex, 0);

	pt0.set(q0.x(), q0.y(), 0);
	pt1.set(q1.x(), q1.y(), 0);
	fn += pt0.cross( pt1 ) ;

	bool boolClockWise = fn.z() < 0.0;

	if(boolClockWise ^ (m_direction == clockwise))
	{
		// Flip the poly
		int start = m_pAccumCounts[polyIndex];
		for( j = 0; j < num / 2; j++ )
		{
			swap(m_pPts[start + j], m_pPts[start + num - 1 - j]);
		}
	}
	 
	return this;
}

// Convert degrees to radians for math functions.
#define RAD(x) ((x) * 3.1415927 / 180)

/****************************************************************************
 *  FUNCTION   : FixedFromDouble
 *  RETURNS    : FIXED value representing the given double.
 ****************************************************************************/
FIXED 
FixedFromDouble (double d)
{
  long l;

  l = (long) (d * 65536L);
  return *(FIXED *) & l;
}

/****************************************************************************
 *  FUNCTION   : FixedFromDouble
 *  RETURNS    : FIXED value representing the given double.
 ****************************************************************************/
double  
DoubleFromFixed (FIXED f)
{
  double d = f.value;

  d +=  (f.fract / 65536.);
  return d;
}

/****************************************************************************
 *  FUNCTION   : IntFromFixed
 *  RETURNS    : int value approximating the FIXED value.
 ****************************************************************************/
int 
IntFromFixed (FIXED f)
{
  if (f.fract >= 0x8000)
    return (f.value + 1);
  else
    return (f.value);
}

/****************************************************************************
 *  FUNCTION   : fxDiv2
 *  RETURNS    : (val1 + val2)/2 for FIXED values
 ****************************************************************************/
FIXED 
fxDiv2 (FIXED fxVal1, FIXED fxVal2)
{
  long l;

  l = (*((long *) &(fxVal1)) + *((long *) &(fxVal2))) / 2;
  return (*(FIXED *) & l);
}

/****************************************************************************
 *  FUNCTION   : MakeRotationMat
 *  PURPOSE    : Fill in a rotation matrix based on the given angle.
 *  RETURNS    : none.
 ****************************************************************************/
void
MakeRotationMat (LPMAT2 lpMat, double dAngle)
{
  lpMat->eM11 = FixedFromDouble (cos (RAD (dAngle)));
  lpMat->eM12 = FixedFromDouble (sin (RAD (dAngle)));
  lpMat->eM21 = FixedFromDouble (-sin (RAD (dAngle)));
  lpMat->eM22 = FixedFromDouble (cos (RAD (dAngle)));
}

/****************************************************************************
 *  FUNCTION   : ShearMat
 *  PURPOSE    : Fill in a 0.25 horizontal shear matrix.
 *  RETURNS    : none.
 ****************************************************************************/
void
ShearMat (LPMAT2 lpMat)
{
  lpMat->eM11 = FixedFromDouble (1);
  lpMat->eM12 = FixedFromDouble (0);
  lpMat->eM21 = FixedFromDouble (0.25);
  lpMat->eM22 = FixedFromDouble (1);
}
/****************************************************************************
 *  FUNCTION   : IdentityMat
 *  PURPOSE    : Fill in matrix to be the identity matrix.
 *  RETURNS    : none.
 ****************************************************************************/
void
IdentityMat (LPMAT2 lpMat)
{
  lpMat->eM11 = FixedFromDouble (1);
  lpMat->eM12 = FixedFromDouble (0);
  lpMat->eM21 = FixedFromDouble (0);
  lpMat->eM22 = FixedFromDouble (1);
}


/****************************************************************************
 *  FUNCTION   : DrawT2Outline
 *
 *  PURPOSE    : Decode the GGO_NATIVE outline, create a polypolygon from it,
 *               and draw it using PolyPolygon.  
 *
 *               Polygon is not actually returned as would be more common
 *               in real usage.  Also, an arbitrary size for the polygon
 *               is specified instead of actually expanding on a need-to-
 *               grow basis.
 *
 *               Error conditions are not handled.
 *
 *  RETURNS    : none.
 ****************************************************************************/
void
CreateT2Outline (LPTTPOLYGONHEADER lpHeader, DWORD size, int nAscent, ChPolyPolygonGx3& poly)
{
	// Append each polygon and segment to 'poly'

	LPTTPOLYGONHEADER lpStart;
	LPTTPOLYCURVE lpCurve;
	GxVec3f pt[500];			 // big enough for one spline
	//WORD cTotal = 0;		// Total number of points in polypolygon.
    WORD cInCurve; 	// Number of points in current curve.
    WORD cCurves = 0;	// Number of curves in polypolygon.
    unsigned int cInSpline;	// Number of points in digitized spline curve.
    //WORD iFirstCurve;	// Index to start point of first curve.
    WORD i;
    QS spline;
	GxVec3f cpt, firstPoint;

    lpStart = lpHeader;
	poly.Init();
    while ((DWORD)lpHeader < (DWORD)(((LPSTR)lpStart) + size))
    {
	if (lpHeader->dwType == TT_POLYGON_TYPE)
	{
	    poly.NewPoly();
		bool boolFirst = true;

	    cInCurve = 0;	  // obs 
						   
	    // Get to first curve.
	    lpCurve = (LPTTPOLYCURVE) (lpHeader + 1);
	    //iFirstCurve = cTotal;

	    while ((DWORD)lpCurve < (DWORD)(((LPSTR)lpHeader) + lpHeader->cb))
	    {
		if (lpCurve->wType == TT_PRIM_LINE)
		{
			if(boolFirst) 
			{
			    firstPoint.x() = DoubleFromFixed(lpCurve->apfx[0].x);
				firstPoint.y() = DoubleFromFixed(lpCurve->apfx[0].y);
				firstPoint.z() = 0;
				boolFirst = false;
			}
			for (i = 0; i < lpCurve->cpfx; i++)
		    {
				cpt.x() = DoubleFromFixed(lpCurve->apfx[i].x);
				cpt.y() = DoubleFromFixed(lpCurve->apfx[i].y);
				cpt.z() = 0;
				poly.Append(cpt);
				//cTotal++;	  // obs 
				cInCurve++;	  // obs 
		    }
		}
		else if (lpCurve->wType == TT_PRIM_QSPLINE)
		{
		    //**********************************************
		    // Format assumption:
		    //   The bytes immediately preceding a POLYCURVE
		    //   structure contain a valid POINTFX.
		    //
		    //   If this is first curve, this points to the
		    //      pfxStart of the POLYGONHEADER.
		    //   Otherwise, this points to the last point of
		    //      the previous POLYCURVE.
		    //
		    //	 In either case, this is representative of the
		    //      previous curve's last point.
		    //**********************************************
		    spline.ptfxStartPt = *(LPPOINTFX)((LPSTR)lpCurve - sizeof(POINTFX));
	
		    for (i = 0; i < lpCurve->cpfx;)
		    {
			        // The B point.
				spline.ptfxCntlPt = lpCurve->apfx[i++];

				// Calculate the C point.
				if (i == (lpCurve->cpfx - 1))
				{
				    spline.ptfxEndPt = lpCurve->apfx[i++];
				}
				else
				{
				    // C is midpoint between B and next point.
				    spline.ptfxEndPt.x = fxDiv2(lpCurve->apfx[i-1].x,
				    				lpCurve->apfx[i].x);
				    spline.ptfxEndPt.y = fxDiv2(lpCurve->apfx[i-1].y,
				    				lpCurve->apfx[i].y);
				}

				cInSpline = 0; 
				QSpline2Polyline(pt, &spline, -1, &cInSpline, nAscent);
				if(boolFirst)
				{
					firstPoint = pt[0];
					boolFirst = false;
				}
				// Copy the spline pts to our array; brute force
				for( unsigned int k = 0; k < cInSpline; k++)
				{
					poly.Append(pt[k]);
				}
			
				//cTotal += cInSpline;	// obs
				//cInCurve += cInSpline;	// obs

				// New A point for next slice of spline.
				spline.ptfxStartPt = spline.ptfxEndPt;
		    }
		}
		else
		; // error, error, error

		// Move on to next curve.
		lpCurve = (LPTTPOLYCURVE)&(lpCurve->apfx[i]);
	    }

	    // Add points to close curve.
	    // Depending on the specific font and glyph being used, these
	    // may not always be needed, but it never hurts.
		#if 0
	    pt[cTotal].x = lpHeader->pfxStart.x.value;
	    pt[cTotal].y = lpHeader->pfxStart.y.value;
	    cInCurve++;
	    cTotal++;
	    pt[cTotal].x = pt[iFirstCurve].x;
	    pt[cTotal].y = pt[iFirstCurve].y;
	    cInCurve++;
	    cTotal++;
	    count[cCurves++] = cInCurve;
		#endif
		#if 0
		cpt.x()  = lpHeader->pfxStart.x.value;
		cpt.y()  = lpHeader->pfxStart.y.value;
		#endif
		cpt.x()  = DoubleFromFixed(lpHeader->pfxStart.x);
		cpt.y()  = DoubleFromFixed(lpHeader->pfxStart.y);
		cpt.z() = 0;
		poly.Append(cpt);
		//cpt.x()  =   firstPoint.x();
		//cpt.y()  =   firstPoint.y();
		//cpt.z() = 0;
		poly.Append(firstPoint);
	    poly.EndPoly();

	    // Move on to next polygon.
	    lpHeader = (LPTTPOLYGONHEADER)(((LPSTR)lpHeader) + lpHeader->cb);
	}
	else
	; // error, error, error
    }

}

/****************************************************************************
 *  FUNCTION   : CreateGlyphPolyPoly
 *
 *  PURPOSE    : Create a polypoly for a glyph.
 *
 *               Caller must delete returned pointer.
 *
 *  RETURNS    : polypoly, or 0 if error.
 ****************************************************************************/
  ChPolyPolygonGx3* CreateGlyphPolyPoly (HFONT hFont, unsigned int letter, int ascent, int& xAdvance, int &yAdvance)
  {
    GLYPHMETRICS gm;
    MAT2 mat;
    DWORD size;
    LPSTR lpBits;
    WORD flag;
	//ChPolyPolygonGx3 *pPoly = new ChPolyPolygonGx3(ChPolyPolygonGx3::counterClockwise);
	ChPolyPolygonGx3 *pPoly = new ChPolyPolygonGx3(ChPolyPolygonGx3::dontCare);

    HDC hdc = ::GetDC(NULL);
	HFONT oldFont = HFONT(::SelectObject(hdc, hFont));

    /* make the 2x2 matrix */
	IdentityMat(&mat);
    // these are simply hardcoded examples
    #if 0
    if (wEffect == IDM_IDENTITY)
	IdentityMat(&mat);
    else if (wEffect == IDM_ROTATE60)
	MakeRotationMat(&mat, 60);
    else if (wEffect == IDM_SHEAR)
	ShearMat(&mat);
	#endif

    flag = GGO_NATIVE;

    // allocate space for the outline
    size = GetGlyphOutline(hdc, letter, flag, &gm, 0, NULL, &mat);
	if(GDI_ERROR == size)
	{
		delete pPoly;
		return 0;
	}

	if(!size)
	{
		if(letter == ' ')
		{
			SIZE size;
			GetTextExtentPoint32(hdc, " ", 1, &size); 
		 	xAdvance = size.cx;
			yAdvance = 0;
		}
		else
		{
		 	xAdvance = 0;
			yAdvance = 0;
		}
		return pPoly;	// empty
	}
    lpBits = new char[size];

    if ((GetGlyphOutline(hdc, letter, flag, &gm, size, lpBits, &mat)) != size)
    {
		//MessageBox(hMyWnd, "Won't get it", "foo", MB_OK);
		delete pPoly;
		return 0;
    }
	xAdvance = gm.gmCellIncX;
	yAdvance = gm.gmCellIncY;

	::SelectObject(hdc, oldFont);
    ReleaseDC(NULL, hdc);

    // Glyph is in outline format.  Set up viewport origin to align the
    // glyph and draw it.  Actual decoding is done in
    // CreateT2Outline.
    {

								// Align based on cell origin.	??
								//OffsetViewportOrg(hDC, x, y + ascent);
		//ChPolyPolygonI poly;
		CreateT2Outline((LPTTPOLYGONHEADER)lpBits, size, ascent, *pPoly);

    }

    delete(lpBits);
	return pPoly;
}

	
