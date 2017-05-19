/********************************************************************/
/* IMODE.H                                                          */
/* Immediate mode interface for Reality Lab                         */
/********************************************************************/

#ifndef __IMODE_H__
#define __IMODE_H__

#include "rl.h"

#ifdef __psx__
#include "libgte.h"
#include "libgpu.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

/********************************************************************/
/* RLIMValue is the fundamental Immediate Mode fractional data type */
/********************************************************************/

/* The IMVAL(val, prec) initialises an RLIM<prec>Value,
 * where prec may be 12, 16, or 24
 *
 * RLTOIMVAL(val, prec) converts an RLValue to an RLIM<prec>Value
 */
#ifdef FIXED_POINT_INTERNAL

typedef long RLIMValue, RLIM12Value, RLIM16Value, RLIM24Value;
#define IMVAL(val, prec) ((RLIMValue)((double)(val) * ((double)(1L << prec))))

#ifdef FIXED_POINT_API
#define RLTOIMVAL(val, prec) ((val) >> 16 - prec)
#else
#define RLTOIMVAL(val, prec) IMVAL(val, prec)
#endif

#else

typedef float RLIMValue, RLIM12Value, RLIM16Value, RLIM24Value;
#define IMVAL(val, prec) ((RLIMValue) (val))

#ifdef FIXED_POINT_API
#define RLTOIMVAL(val, prec) ((RLIMValue) ((double)(val) / ((double)(1L << 16))))
#else
#define RLTOIMVAL(val, prec) ((RLIMValue) (val))
#endif

#endif

/********************************************************************/
/* Opaque types for internal system use                             */
/********************************************************************/

typedef RLIMValue RLInternal_v;
typedef int RLInternal_i;
typedef long RLInternal_l;
typedef unsigned long RLInternal_ul;
typedef unsigned char RLInternal_uc;

/********************************************************************/
/* Immediate Mode data types                                        */
/********************************************************************/

typedef int RLIMFlag; /* boolean value */

#define IMRGBA(red, green, blue, alpha) /* RGB mode only; values in range 0..255 */\
    (((alpha) << 24) | ((red) << 16) | ((green) << 8) | (blue))
typedef RLInternal_ul RLIMColour;

typedef struct _RLIMVector
{   RLIM12Value x, y, z;
} RLIMVector, RLIMPositionVector, RLIMDirectionVector;

/* lightable point in model space */
typedef struct _RLIMLightingPoint
{   RLIMDirectionVector normal; /* normalised unit vector */
    RLIMPositionVector position;
} RLIMLightingPoint;

/* Transformed vertex */
typedef struct _RLIMViewVertex
{   RLIMColour colour;     /* vertex colour (for smooth shading) */
    RLInternal_ul specular;
    RLIM16Value sx;        /* screen coordinates */
    RLIM16Value sy;
    RLIM24Value sz;
    RLIM16Value hw;
    RLIM16Value tu;        /* texture u coordinate */
    RLIM16Value tv;        /* texture v coordinate */
    RLInternal_i clip;
    RLInternal_v hx;
    RLInternal_v hy;
    RLInternal_v hz;
} RLIMViewVertex;

/* Material properties */
typedef struct _RLIMSurfaceInfo
{   RLInternal_ul diffuse;
    RLInternal_ul ambient;
    RLInternal_ul specular;
    RLInternal_ul emissive;
    RLInternal_v power;
    RLInternal_i ramp_size;
    RLInternal_ul texture;
    RLInternal_uc specular_table[260];
} RLIMSurfaceInfo;

/* Triangle to be renderered */
typedef struct _RLIMTriangle
{   RLIMViewVertex* v[3];	    /* triangle vertices in clockwise order */
    RLIMColour colour; 		    /* triangle colour (for flat shading) */
    RLInternal_ul specular;
    RLInternal_ul flags;
    struct _RLIMTriangle* next;	    /* next triangle in a sorted list */
    RLIMSurfaceInfo* mat;	    /* phong shading only */
#ifdef __psx__
    POLY_GT3 prim[2];		    /* PSX only: double buffered primitives */
    SVECTOR p[3];      		    /* PSX only: model coords */
    long initialised;		    /* PSX only: initialisation flags */
#endif
} RLIMTriangle;

/********************************************************************/
/* Memory Allocation                                                */
/********************************************************************/

/* To ensure compatability with future hardware, use the following
 * functions to allocate memory for polygon information
 */

/* RLIMAllocateVertices()
 * Allocate a number of vertices.
 * Specify the size of each vertex (sizeof(RLIMViewVertex) + user data),
 * and number of vertices
 */
RLIMViewVertex* RLIMAllocateVertices
    (RLDevice dev, size_t vertexSize, size_t count);

/* RLIMAllocateTriangles()
 * Allocate a number of triangles.
 * Specify the size of each triangle (sizeof(RLIMTriangle) + user data),
 * and number of triangles
 */
RLIMTriangle* RLIMAllocateTriangles
    (RLDevice dev, size_t triangleSize, size_t count);

/* RLIMFreeVertices()
 * RLIMFreeTriangles()
 */
void RLIMFreeVertices(RLDevice dev, RLIMViewVertex* vertices);
void RLIMFreeTriangles(RLDevice dev, RLIMTriangle* triangles);

/********************************************************************/
/* Transform                                                        */
/********************************************************************/

typedef enum
{   RLIM_ALL_VISIBLE = 0, /* all vertices are within the viewport */
    RLIM_SOME_VISIBLE,
    RLIM_NONE_VISIBLE
} RLIMClippingFlag;

/* RLIMTransformVertices()
 * Transforms model coordinates to viewport coordinates
 */
RLIMClippingFlag RLIMTransformVertices
(   RLViewport view,            /* viewport */
    RLFrame transform,          /* transform to use */
    RLIMPositionVector* source, /* array of position vectors */
    RLIMViewVertex* destination,/* destination for transformed coordinates */
    size_t sourceSize,          /* size of source elements */
    size_t destinationSize,     /* size of destination elements */
    size_t vertexCount,         /* number of elements to transform */
    RLIMFlag checkClipping      /* return clipping flag if true */
);

/********************************************************************/
/* Lighting                                                         */
/********************************************************************/

/* RLIMInitialiseSurfaceInfo()
 * Sets up a SurfaceInfo structure for use in lighting calculations
 */
RLError RLIMInitialiseSurfaceInfo
(   RLDevice device,
    RLMaterial material,
    RLColour colour,
    RLTexture texture,
    RLIMSurfaceInfo* surface /* structure to initialise */
);

/* RLIMLightMeshPoints()
 * Calculates illuminated colours of world model points, using surface info;
 * results may be placed in triangles (for flat shading)
 * or viewport vertices (for smooth shaded triangles)
 * When the triangle is drawn, required palette entries will be allocated,
 * possibly reusing the entries assigned for unused materials
 */
RLError RLIMLightMeshPoints
(   RLViewport view,
    RLFrame frame,
    RLIMSurfaceInfo* surface,
    RLIMLightingPoint* vertices,
    RLIMColour* destination,    /* colour field in RLIMViewVertex or RLIMTriangle */
    size_t vertexSize,
    size_t destinationSize,
    size_t count
);

/* RLIMColourMeshPoints()
 * Assigns the unlit colour in a RLIMSurfaceInfo to RLIMColour fields,
 * ie. in viewport vertices or triangles.
 * In subsequent frames, the objects do not need to be recoloured
 * provided RLIMcolourStillValid() returns true or RGB mode is used
 */
RLError RLIMColourMeshPoints
(   RLViewport view,
    RLIMSurfaceInfo* colour,
    RLIMColour* dest,
    size_t destSize,
    size_t count
);

/* RLIMColourStillValid()
 * Checks whether palette entries used to light or colour meshes are
 * still valid, and if so, informs the palette manager that the palette
 * entries are still in use.
 * If it returns false, the meshes should be lit or coloured again.
 * This call is not needed in RGB mode.
 */
RLIMFlag RLIMColourStillValid
(   RLViewport view,
    RLIMSurfaceInfo* colour
);

/********************************************************************/
/* Device settings                                                  */
/********************************************************************/

/* RLIMSetDithering()
 * RLIMSetPerspectiveCorrection()
 * RLIMSetGamma()
 *
 * Set device properties
 *    dithering on/off
 *    perspective correction on/off
 *    gamma correction value
 */
RLError RLIMSetDithering(RLDevice, RLIMFlag);
RLError RLIMSetPerspectiveCorrection(RLDevice, RLIMFlag);
RLError RLIMSetGamma(RLDevice, RLIM16Value);

/********************************************************************/
/* Triangle drawing                                                 */
/********************************************************************/

typedef enum
{   RLIM_WIRE_QUALITY,
    RLIM_UNLIT_QUALITY,
    RLIM_FLAT_QUALITY,
    RLIM_SMOOTH_QUALITY
} RLIMRenderQuality;

/* RLIMSetCurrentFill()
 * Sets the parameters for the current triangle fill.
 *
 * When drawing a textured triangle, the renderer interpolates between
 * the texture coordinates of the triangle's vertices. wrapTextureU and
 * wrapTextureV determine the topology of the texture, ie whether the
 * interpolation path may wrap around the texture image edges in the U
 * and V directions
 */
RLError RLIMSetCurrentFill
(   RLViewport viewport,
    RLTexture texture,
    RLIMFlag wrapTextureU,
    RLIMFlag wrapTextureV,
    RLIMFlag transparent  /* enable transparency */
);

/* RLIMDrawTriangles()
 * Renders triangles to the specified viewport
 * useClipping must be true unless all triangles are known to be unclipped
 */
RLError RLIMDrawTriangles
(   RLViewport viewport,
    RLIMTriangle* triangles,
    size_t size,
    size_t count,
    RLIMRenderQuality quality,
    RLIMFlag useClipping
);

#if defined(__cplusplus)
};
#endif

#endif
