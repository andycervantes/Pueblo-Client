 /* Copyright (c) 1994, 1995 Intel Corporation. All Rights Reserved */


#ifndef  _3DG_H_
#define _3DG_H_

typedef LPVoid_t G3dHandle_t;

#define G3d_ONE				65536.0f
#define G3d_ZONE        	268435455.0f    
#define G3d_COLONE 			65535.0f
#define G3d_MAX_C			255
#define G3d_SMALL_NUMBER   	1.e-12f

#define G3D_OFF 		0
#define G3D_ON 			1

#ifdef	__cplusplus
extern "C" {
#endif

/*
// Dictionary of Acronyms, Keywords, etc.
//
// G3d 	- 3DG reordered for compilation reasons.
//
// 23F		- indicates a 2 by 3 floating point matrix
// A		- indicates alpha blending variable present as in
//			  ColorFA
// BMP		- bitmap image file format
// Coords	- coordinate system
// Eqns		- equations
// F		- indicates floating point 32 bit version
// FA		- indicates floating point 32 bit with alpha (for colors)
// FW		- indicates floating point 32 bit homogeneous coordinates
// GC		- Geometry Context
// Isect	- intersection such as the intersection of a line and
//			  a plane.
// L		- indicates Fixed point 32bit version
// LW		- indicates Fixed point 32bit homogeneous coordinates 
// luBackSub- lower, upper back substitution
// luDecomp	- lower triangular, upper triangular decomposition
//			  of a matrix.
// Matt		- material properties of a surface
// Mult		- multiply
// Norm,nrm	- normal vector perpendicular to a surface.
// Pow		- power or exponentiation
// prim		- drawing primitive such as a line or polygon
// prop		- property or attribute such as of a light source
// pt		- Point in some coordinate system
// Q		- quadratic.  2nd degree (3rd order) polynomial
// qd		- quasi definitive, or quadrature, or quick and dirty.
//			  Indicates that a function is a quick approximation.
// Sqrt		- square root
// S		- indicates short (16bit) components such as for colors
// SA		- indicates short (16bit) components with alpha
// trans	- transform, a 4x4 matrix for transforming points
// vec		- vector, usually x,y,z
// vtx		- vertex such as a polygon vertex
// Win		- window
// W		- indicates the homogeneous coordinate, w value is present
//			  as in PointFW_t
*/


/* ----------------------CONTEXT--------------------------- */
	typedef enum {
		G3D_NO_DRAW_ORDER
	}   G3dContextProps_t;

	typedef enum {
		G3DL_FACETED_NORMALS,
		G3DL_FLAT_SHADING,
		G3DL_TEXTURE_MOD,
		G3DL_FRONT_CCW,
		G3DL_NO_CLIPPING
	}   G3dState_t;

	Void_t WINAPI G3dSetState(G3dHandle_t hGC, G3dState_t st, Fixed32_t *data);
	Void_t WINAPI G3dGetState(G3dHandle_t hGC, G3dState_t st, Fixed32_t *data);

	typedef enum {
		G3DC_OBJECT_COORDS,
		G3DC_WINDOW_COORDS
	}   G3dCoords_t;

	typedef struct {
		Fixed32_t zbufferPlanes;
	}   G3dCapabilities_t;

	G3dHandle_t WINAPI G3dCreateGC(R3dHandle_t);
	Void_t WINAPI G3dDeleteGC(G3dHandle_t hGC);
	Void_t WINAPI G3dSetCoords(G3dHandle_t hGC, G3dCoords_t coordinates);

	Void_t WINAPI G3dQuerySystemCapabilities(G3dHandle_t hGC, G3dCapabilities_t cap);

/* ----------------------COLORS------------------------ */
	typedef struct {
		Float_t r, g, b;
	}   ColorF_t;
	typedef struct {
		Float_t r, g, b, a;
	}   ColorFA_t;
	typedef struct {
		Fixed16_t r, g, b, a;
	} ColorSA_t;

/* ----------------------POINTS------------------------ */
	typedef struct {
		Fixed32_t x, y, z;
	} PointL_t;
	typedef struct {
		Fixed32_t x, y, z, w;
	}   PointLW_t;
	typedef struct {
		Float_t x, y, z;
	}   PointF_t;
	typedef struct {
		Float_t x, y, z, w;
	}   PointFW_t;

	typedef struct {
		PointF_t point, vector;
	}   LineF_t;
	typedef struct {
		Float_t a, b, c, d;
	}   PlaneF_t;
	typedef struct {
		PointF_t center;
		Float_t r;
	}   SphereF_t;

	typedef struct {
		PointL_t point, vector;
	}   LineL_t;
	typedef struct {
		Fixed32_t a, b, c, d;
	}   PlaneL_t;
	typedef struct {
		PointL_t center;
		Fixed32_t r;
	}   SphereL_t;

/* ----------------------PRIMITIVES------------------------ */
#define	G3D_MAX_VERTICES	256
#define	G3D_MAX_LIST		4096
#define G3D_MAX_PLANES		(Fixed32_t)8

	typedef enum {
		G3DCP_DATA,
		G3DCP_SIGN
	}   G3dCPlaneProp_t;

	Void_t WINAPI G3dGetClipPlane(G3dHandle_t hGC, Fixed32_t wCPPNum, G3dCPlaneProp_t prop, Float_t *data);
	Void_t WINAPI G3dSetClipPlane(G3dHandle_t hGC, Fixed32_t wCPNum, G3dCPlaneProp_t prop, Float_t *data);

	typedef enum {
		G3D_PRM_POINTS = R3D_PRM_POINTS,
		G3D_PRM_LINES = R3D_PRM_LINES,
		G3D_PRM_POLYLINE = R3D_PRM_POLYLINE,
		G3D_PRM_TRIANGLES = R3D_PRM_TRIANGLES,
		G3D_PRM_QUADS = R3D_PKT_QUADS,
		G3D_PRM_TRISTRIP = R3D_PRM_TRISTRIP,
		G3D_PRM_QUADSTRIP = R3D_PKT_QUADSTRIP,
		G3D_PRM_POLYGON = R3D_PRM_POLYGON,
	}   G3dPrimitive_t;

	Void_t WINAPI G3dQPatchF(G3dHandle_t hGC, Fixed32_t un,  Fixed32_t vn, 
		    PointFW_t * p, Fixed32_t pstep, PointF_t * t, Fixed32_t tstep,
		    ColorFA_t * c, Fixed32_t cstep, int NormFlag);



	void WINAPI G3dQPatchListF(G3dHandle_t  hGC, Fixed32_t un, Fixed32_t vn,
       PointFW_t * qp, Fixed32_t qpstep,  PointF_t * qt, Fixed32_t qtstep,
       ColorFA_t * qc, Fixed32_t qcstep, int normFlag,
       PointF_t * p, Fixed32_t pstep,  PointF_t * n, Fixed32_t nstep, PointF_t * t, Fixed32_t tstep,
       ColorFA_t * c, Fixed32_t cstep,  Fixed16_t * idx);

	Void_t WINAPI G3dQPatchL(G3dHandle_t hGC, Fixed32_t un,  Fixed32_t vn, 
		    PointLW_t * p, Fixed32_t pstep, PointL_t * t, Fixed32_t tstep,
		    ColorSA_t * c, Fixed32_t cstep, int NormFlag);

	

	void WINAPI G3dQPatchListL(G3dHandle_t  hGC, Fixed32_t un, Fixed32_t vn,
       PointLW_t * qp, Fixed32_t qpstep,  PointL_t * qt, Fixed32_t qtstep,
       ColorSA_t * qc, Fixed32_t qcstep, int normFlag,
       PointL_t * p, Fixed32_t pstep,  PointL_t * n, Fixed32_t nstep, PointL_t * t, Fixed32_t tstep,
       ColorSA_t * c, Fixed32_t cstep,  Fixed16_t * idx);


	Void_t WINAPI G3dPrimitiveF(G3dHandle_t hGC, G3dPrimitive_t prim, Fixed32_t nvtx,
		    PointF_t * p, Fixed32_t pstep, PointF_t * n, Fixed32_t nstep,
		    PointF_t * t, Fixed32_t tstep, ColorFA_t * c, Fixed32_t cstep);
	Void_t WINAPI G3dPrimitiveL(G3dHandle_t hGC, G3dPrimitive_t prim, Fixed32_t nvtx,
		    PointL_t *p, Fixed32_t pstep, PointL_t *n, Fixed32_t nstep,
		    PointL_t *t, Fixed32_t tstep, ColorSA_t *c, Fixed32_t cstep);
	Void_t WINAPI G3dBeginPrim(G3dHandle_t hGC, G3dPrimitive_t prim, Fixed32_t nvtx);
	Void_t WINAPI G3dAddPrimVtxF(G3dHandle_t hGC, PointF_t * p, PointF_t * n, PointF_t * t, ColorFA_t * c);
	Void_t WINAPI G3dAddPrimVtxL(G3dHandle_t hGC, PointL_t *p, PointL_t *n, PointL_t *t, ColorSA_t *c);
	Void_t WINAPI G3dEndPrim(G3dHandle_t hGC);
	Void_t WINAPI G3dPolygonListF(G3dHandle_t hGC, Fixed32_t npoly, Fixed32_t tvtx, PointF_t * p, Fixed32_t pstep,
		    PointF_t * n, Fixed32_t nstep, PointF_t * t, Fixed32_t tstep, ColorFA_t * c, Fixed32_t cstep,
			Fixed16_t *polylist);
	Void_t WINAPI G3dPolygonListL(G3dHandle_t hGC, Fixed32_t npoly, Fixed32_t tvtx, PointL_t *p, Fixed32_t pstep,
		    PointL_t *n, Fixed32_t nstep, PointL_t *t, Fixed32_t tstep, ColorSA_t *c, Fixed32_t cstep,
		    Fixed16_t *polylist);
	Void_t WINAPI G3dPolygonListFF(G3dHandle_t hGC, Fixed32_t npoly, Fixed32_t tvtx, PointF_t * p, Fixed32_t pstep,
		    PointF_t * n, Fixed32_t nstep, PlaneF_t *fn, Fixed32_t fnstep, 
		    PointF_t * t, Fixed32_t tstep, ColorFA_t * c, Fixed32_t cstep,
			Fixed16_t *polylist);
	Void_t WINAPI G3dPolygonListFL(G3dHandle_t hGC, Fixed32_t npoly, Fixed32_t tvtx, PointL_t *p, Fixed32_t pstep,
		    PointL_t *n, Fixed32_t nstep,  PlaneL_t *fn, Fixed32_t fnstep, 
		    PointL_t *t, Fixed32_t tstep, ColorSA_t *c, Fixed32_t cstep,
		    Fixed16_t *polylist);

/* ----------------------LIGHTS------------------------ */
#define G3D_MAX_LIGHTS		(Fixed32_t)16


	typedef enum {
		G3DL_DIMMER,	/* Float_t	  0.0	(off) */
		G3DL_AMBIENT,	/* ColorF_t	  0.0, 0.0, 0.0	 */
		G3DL_DIFFUSE,	/* ColorF_t	  1.0, 1.0, 1.0	 */
		G3DL_SPECULAR,	/* ColorF_t	  1.0, 1.0, 1.0	 */
		G3DL_LOCATION,	/* PointFW_t  0.0, 0.0, 1.0, 0.0	 */
		G3DL_DIRECTION,	/* PointF_t 	  0.0, 0.0, -1.0	 */
		G3DL_SPOT_EXP,	/* Float_t	  0.0		 */
		G3DL_SPOT_ANGLE,	/* Float_t	  PI radians	 */
		G3DL_ATTENA,	/* Float_t	  1.0		 */
		G3DL_ATTENB,	/* Float_t	  0.0		 */
		G3DL_ATTENC,	/* Float_t	  0.0		 */
	}   G3dLightProp_t;

	typedef enum {
		G3DL_OFF,
		G3DL_LINEAR,
		G3DL_EXP,
		G3DL_EXP2
	}   G3dHazeMode_t;

	Void_t WINAPI G3dResetLight(G3dHandle_t hGC, Fixed32_t wLightNum);
	Void_t WINAPI G3dGetLight(G3dHandle_t hGC, Fixed32_t wLightNum, G3dLightProp_t prop, Float_t *data);
	Void_t WINAPI G3dSetLight(G3dHandle_t hGC, Fixed32_t wLightNum, G3dLightProp_t prop, Float_t *data);
	Void_t WINAPI G3dSetHazeColor(G3dHandle_t hGC, ColorF_t * color);
	Void_t WINAPI G3dSetHazeFunction(G3dHandle_t hGC, G3dHazeMode_t mode,
		    Float_t density, Float_t hnear, Float_t hfar);

/* ----------------------MATERIAL------------------------ */
#define G3D_MAX_MATTS		16
	typedef enum {
		G3DM_AMBIENT,	/* ColorF_t		0.0, 0.0, 0.0 */
		G3DM_DIFFUSE,	/* ColorFA_t	0.0, 0.0, 0.0, 1.0 */
		G3DM_SPECULAR,	/* ColorF_t		0.0, 0.0, 0.0 */
		G3DM_EMIT,	/* ColorF_t			0.0, 0.0, 0.0 */
		G3DM_SHINE,	/* Float_t      	0.0  */
		G3DM_CULL,	/* Float_t     		0.0  */
		G3DM_BACK_AMBIENT,	/* ColorF_t		0.0, 0.0, 0.0 */
		G3DM_BACK_DIFFUSE,	/* ColorFA_t	0.0, 0.0, 0.0,
					 * 1.0 */
		G3DM_BACK_SPECULAR,	/* ColorF_t		0.0, 0.0, 0.0 */
		G3DM_BACK_EMIT,	/* ColorF_t			0.0, 0.0, 0.0 */
		G3DM_BACK_SHINE,	/* Float_t		0.0  */
		G3DM_BACK_CULL,	/* Float_t  	    	0.0  */
		G3DM_ALPHA,	/* Float_t  */
		G3DM_TEXTURE_HDL	/* TEX_HDL  */
	}   G3dMattProp_t;

	Void_t WINAPI G3dGetMatt(G3dHandle_t hGC, Fixed32_t wMattNum, G3dMattProp_t prop, Float_t *data);
	Void_t WINAPI G3dSetMatt(G3dHandle_t hGC, Fixed32_t wMattNum, G3dMattProp_t prop, Float_t *data);
	Void_t WINAPI G3dSetCurrentMatt(G3dHandle_t hGC, Fixed32_t wMattNum);

/* ----------------------TRANSFORMS------------------------ */

#define G3D_TRANS_STACK_SIZE		32

	typedef enum {
		G3DT_MODEL,
		G3DT_CAM_CLIP,
		G3DT_TEXTURE
	}   G3dTransformStack_t;

	typedef Float_t TransformF_t[4][4];
	typedef Float_t Transform23F_t[2][3];

	Void_t WINAPI G3dSetActiveStack(G3dHandle_t hGC, G3dTransformStack_t stack);
	Void_t WINAPI G3dClearStack(G3dHandle_t hGC);
	Void_t WINAPI G3dPushTransform(G3dHandle_t hGC);
	Void_t WINAPI G3dPopTransform(G3dHandle_t hGC);
	Void_t WINAPI G3dIdentityTransform(G3dHandle_t hGC);
	Void_t WINAPI G3dRotateTransform(G3dHandle_t hGC, Float_t theta, Float_t x, Float_t y, Float_t z);
	Void_t WINAPI G3dTranslateTransform(G3dHandle_t hGC, Float_t tx, Float_t ty, Float_t tz);
	Void_t WINAPI G3dScaleTransform(G3dHandle_t hGC, Float_t sx, Float_t sy, Float_t sz);
	Void_t WINAPI G3dPreMultTransform(G3dHandle_t hGC, TransformF_t mat);
	Void_t WINAPI G3dPostMultTransform(G3dHandle_t hGC, TransformF_t mat);
	Void_t WINAPI G3dSetTransform(G3dHandle_t hGC, TransformF_t mat);
	Void_t WINAPI G3dGetTransform(G3dHandle_t hGC, TransformF_t mat);
	Void_t WINAPI G3dTransposeMatrix(TransformF_t mat);
	Void_t WINAPI G3dInvertMatrix(TransformF_t src, TransformF_t dst);
	Void_t WINAPI G3dMultMatrix(TransformF_t m0, TransformF_t m1, TransformF_t m2);
	Void_t WINAPI G3dCopyMatrix(TransformF_t m0, TransformF_t m1);
	Void_t WINAPI G3dRotateMatrix(Float_t theta, Float_t a, Float_t b, Float_t c, TransformF_t mat);
	Void_t WINAPI G3dIdentityMatrix(TransformF_t mat);
	Float_t WINAPI G3dUnitVector(PointF_t * vec);
	Void_t WINAPI G3dUnitVector2(PointF_t * in, PointF_t * out);
	Fixed32_t WINAPI G3dluDecomp(Float_t ** amat, Fixed32_t N, Fixed32_t *index, Float_t *ric);
	Void_t WINAPI G3dluBackSub(Float_t ** amat, Fixed32_t N, Fixed32_t *index, Float_t *b);
	Void_t WINAPI G3dSolveLinearEqns(Float_t ** amat, Float_t *b, Fixed32_t N);
	Void_t WINAPI G3dTransformPointF(PointF_t * ptin, PointFW_t * ptout, TransformF_t mat);
	Void_t WINAPI G3dTransformNormalF(PointF_t * pin, PointF_t * pout, TransformF_t mat);
	TransformF_t* WINAPI G3dGetModelCamMatrix(G3dHandle_t  hGC);
	TransformF_t* WINAPI G3dGetInverseModelCamMatrix(G3dHandle_t  hGC);
	Void_t WINAPI G3dTranslateMatrix(Float_t x, Float_t y, Float_t z, TransformF_t mat);
	Void_t WINAPI G3dScaleMatrix(Float_t x, Float_t y, Float_t z, TransformF_t mat);

/* ----------------------CAMERAS-------------------------- */

	typedef enum {
		G3DP_OFF,
		G3DP_PARALLEL,
		G3DP_PERSPECTIVE
	}   G3dProjection_t;

	Void_t WINAPI G3dGetCameraProjection(G3dHandle_t hGC, G3dProjection_t * proj);
	Void_t WINAPI G3dGetCameraPosition(G3dHandle_t hGC, PointFW_t * loc, PointF_t * dir, PointF_t * up);
	Void_t WINAPI G3dGetCameraView(G3dHandle_t hGC, Float_t *right, Float_t *left,
		    Float_t *top, Float_t *bottom,
		    Float_t *pnear, Float_t *pfar);
	Void_t WINAPI G3dGetCameraPort(G3dHandle_t hGC, Float_t *right, Float_t *left,
		    Float_t *top, Float_t *bottom);
	Void_t WINAPI G3dSetCameraProjection(G3dHandle_t hGC, G3dProjection_t proj);
	Void_t WINAPI G3dSetCameraPosition(G3dHandle_t hGC, PointFW_t * loc, PointF_t * dir, PointF_t * up);
	Void_t WINAPI G3dSetCameraView(G3dHandle_t hGC, Float_t right, Float_t left,
		    Float_t top, Float_t bottom,
		    Float_t pnear, Float_t pfar);
	Void_t WINAPI G3dSetCameraPort(G3dHandle_t hGC, Float_t right, Float_t left,
		    Float_t top, Float_t bottom);
	Void_t WINAPI G3dSetWindowSize(G3dHandle_t hGC, Float_t ww, Float_t wh);


/* ----------SELECTION & MANIPULATION----------------------- */

	typedef enum {
		TB_START,
		TB_MOVE,
		TB_END
	}   G3dTrackballEvent_t;

	Void_t WINAPI G3dTrackball(G3dTrackballEvent_t event, PointF_t * center, Float_t radius,
		    Float_t x, Float_t y, PointF_t *axis, Float_t *theta);
	Void_t WINAPI G3dPointWindowToObject(G3dHandle_t hGC, Float_t x, Float_t y, LineF_t * line);
	Void_t WINAPI G3dLineWindowToObject(G3dHandle_t hGC, Float_t x0, Float_t y0, Float_t x1, Float_t y1,
		    PlaneF_t * plane);
	Void_t WINAPI G3dVectorWindowToObject(G3dHandle_t hGC, Float_t x0, Float_t y0, Float_t x1, Float_t y1,
		    LineF_t * vec);
	Void_t WINAPI G3d3PointPlane(PointF_t * a, PointF_t * b, PointF_t * c, PlaneF_t * plane);
	Void_t WINAPI G3dPointNormalPlane(PointF_t * p, PointF_t * n, PlaneF_t * plane);
	Fixed32_t WINAPI G3dLinePlaneIntersect(LineF_t * line, PlaneF_t * plane, PointF_t * vtx);
	Fixed32_t WINAPI G3dLineSphereIntersect(LineF_t * line, SphereF_t * sphere, PointF_t * vtx);
	Void_t WINAPI G3dBoundingSphere(Fixed32_t npts, PointF_t * pts, SphereF_t * sphere);

/* ---------------------- UTILITIES ------------------------------- */

	Float_t WINAPI G3dqdsqrt(Float_t val);	/* quick and dirty square root */
	Float_t WINAPI G3dqdpow(Float_t x, Fixed32_t exp);	/* quick and dirty power */
	Float_t WINAPI G3dqdsin(Float_t val);	/* quick and dirty sin */
	Float_t WINAPI G3dqdcos(Float_t val);	/* quick and dirty cos */

#define G3dVectorLength(x,y,z) ((Float_t)sqrt((x)*(x)+(y)*(y)+(z)*(z)))

#define G3dVectorLengthPt(p) ((Float_t)sqrt(((p)->x)*((p)->x)+((p)->y)*((p)->y)+((p)->z)*((p)->z)))

#define G3dCross( A, B, C ) { \
  (C)->x =  (A)->y * (B)->z - (A)->z * (B)->y; \
  (C)->y = -(A)->x * (B)->z + (A)->z * (B)->x; \
  (C)->z =  (A)->x * (B)->y - (A)->y * (B)->x; \
   }

#define G3dDot(a,b) ((a)->x*(b)->x+(a)->y*(b)->y+(a)->z*(b)->z)

/* ---------------------- IMAGES ------------------------------- */

	HANDLE WINAPI G3dReadBMPFile(LPCSTR ptrToFilename, HANDLE dibHandle);
	R3dHandle_t WINAPI G3dLoadTexture(G3dHandle_t hGC, LPCSTR ptrToFilename);
	R3dHandle_t WINAPI G3dCreateTexture(G3dHandle_t hGC, HANDLE dibHandle);
	Void_t WINAPI G3dTransformBMP(HANDLE bmp1, HANDLE *bmp2, Transform23F_t xform, int x0, int y0,
		int w, int h, int bpp, int rgb);

/* ---------------------- TERRAIN (FUTURE, DO NOT USE) ------------------------------- */
void WINAPI G3dCreateTerrain(LPByte_t archr, int ism, int isn, Float_t Hx, Float_t Hy, Float_t Hz, int error,
    int *npolygons, int *nvertices, PointF_t ** pnt, PointF_t ** nrm, Fixed16_t ** vlist);

void WINAPI G3dOptimizeTerrain(G3dHandle_t hGC, int npolygons, int nvertices,
    PointF_t * pnt, PointF_t * nrm, Fixed16_t * vlist,
    int *npolygonsCl, int *nverticesCl,
    PointF_t * pntCl, PointF_t * nrmCl, Fixed16_t * vlistCl);

#ifdef	__cplusplus
}
#endif	/* __cplusplus */

#endif
