/*
 * $Id: RL.H,v 1.3 1995/11/20 22:13:09 jimd Exp $
 *
 * Copyright (c) RenderMorphics Ltd. 1993, 1994
 * Version 1.1
 *
 * All rights reserved.
 *
 * This file contains private, unpublished information and may not be
 * copied in part or in whole without express permission of
 * RenderMorphics Ltd.
 *
 */

#ifndef __RL_H__
#define __RL_H__

#include <stddef.h>

#ifdef __psx__
#ifndef FIXED_POINT_API
#define FIXED_POINT_API
#endif
#ifndef FIXED_POINT_INTERNAL
#define FIXED_POINT_INTERNAL
#endif
#endif

#if defined(__cplusplus)
extern "C" {
#endif

#ifndef TRUE
#define FALSE 0
#define TRUE 1
#endif

typedef struct _RLObject*		RLObject;
typedef struct _RLObject*		RLDevice;
typedef struct _RLObject*		RLViewport;
typedef struct _RLObject*		RLFrame;
typedef struct _RLObject*		RLVisual;
typedef struct _RLObject*		RLMesh;
typedef struct _RLObject*		RLFace;
typedef struct _RLObject*		RLLight;
typedef struct _RLObject*		RLTexture;
typedef struct _RLObject*		RLWrap;
typedef struct _RLObject*		RLMaterial;
typedef struct _RLObject*		RLPath;
typedef struct _RLObject*		RLShadow;
typedef struct _RLObject*		RLAnimation;
typedef struct _RLObject*		RLAnimationSet;
typedef unsigned long			RLColour;
typedef char*				RLAttribute;

#ifdef FIXED_POINT_API
typedef long int	RLValue;
#ifndef __psx__
#define RLVal(x)		((RLValue)((x) * (double)(1<<16)))
#else
#define RLVal(x)		((RLValue)((x) * 65536))
#endif
#define RLInt(x)		((x) >> 16)
#define RLFloat(x)		((x) / 65536.0)
RLValue RLDivide(RLValue, RLValue);
RLValue RLMultiply(RLValue, RLValue);
#define RLMultiply3(a,b,c)	RLMultiply(RLMultiply(a, b), c)
#else
typedef float 		RLValue;
#define RLVal(x)	((RLValue) (x))
#define RLInt(x)	((int)(x))
#define RLFloat(x)	((float) (x))
#define RLDivide(a,b)	((RLValue) ((double) (a) / (double) (b)))
#define RLMultiply(a,b)	((RLValue) ((a) * (b)))
#define RLMultiply3(a,b,c)	((RLValue) ((a) * (b) * (c)))
#endif

/*
 * Error codes
 */

typedef enum _RLError {
    RLNoError = 0,		/* no error */
    RLBadObject,		/* object expected in argument */
    RLBadType,			/* bad argument type passed */
    RLBadAlloc,			/* out of memory */
    RLFaceUsed,			/* face already used in a mesh */
    RLNotFound,			/* object not found in specified place */
    RLNotDoneYet,		/* unimplemented */
    RLFileNotFound,		/* file cannot be opened */
    RLBadFile,			/* data file is corrupt */
    RLBadDevice,		/* device is not compatible with renderer */
    RLBadValue,			/* bad argument value */
    RLBadMajorVersion,		/* bad dll major version */
    RLBadMinorVersion,		/* bad dll minor version */
    RLMaxError
} RLError;

typedef void (*RLErrorHandler)
    (RLError error,		/* error which was generated */
     void* arg			/* argument given to RLAddErrorHandler */
     );

typedef void (*RLDestroyCallback)
    (RLObject obj,		/* object being destroyed */
     void* arg			/* argument given to RLAddDestroyCallback */
     );

typedef void (*RLFrameCallback)
    (RLFrame frame,		/* frame being moved */
     void* arg			/* argument given to RLAddFrameCallback */
     );

typedef RLTexture (*RLTextureNameCallback)
    (char* tex_name,		/* texture name to be loaded.	*/
    void* arg			/* argument given to RLLoadMeshWithTextures. */
    );
    
typedef struct _RLVector {
    RLValue x, y, z;
} RLVector;

typedef struct _RLQuaternion {
    RLValue s;
    RLVector v;
} RLQuaternion;

typedef struct _RLVector4d {
    RLValue x, y, z, w;
} RLVector4d;

typedef RLValue RLMatrix4d[4][4];

typedef struct _RLBox {
    RLVector min, max;
} RLBox;

typedef void (*RLWrapCallback)(RLVector*, int* u, int* v,
			       RLVector* a, RLVector* b, void*);
typedef enum _RLLightType {
    RLLightAmbient,
    RLLightPoint,
    RLLightSpot,
    RLLightDirectional,
    RLLightParallelPoint
} RLLightType;

typedef enum _RLRenderQuality {
    RLRenderWireframe,		/* display just the edges */
    RLRenderUnlitFlat,		/* flat shaded without lighting */
    RLRenderFlat,		/* flat shaded */
    RLRenderGouraud,		/* gouraud shaded */
    RLRenderPhong		/* phong shaded */
} RLRenderQuality;

typedef enum _RLLightingFrequency {
    RLLightNever,
    RLLightOnce,
    RLLightContinually
} RLLightingFrequency;

typedef enum _RLTextureQuality {
    RLTextureNearest,		/* choose nearest pixel in texture */
    RLTextureLinear		/* linearly interpolate 4 nearest pixels */
} RLTextureQuality;

typedef enum _RLCombineType {
    RLCombineReplace,
    RLCombineBefore,
    RLCombineAfter
} RLCombineType;

typedef enum _RLColourModel {
    RLColourRamp, RLColourRGB
} RLColourModel;

typedef enum _RLPaletteFlags {
    RLPaletteFree,		/* renderer may use this entry freely */
    RLPaletteReadOnly,		/* fixed but may be used by renderer */
    RLPaletteReserved		/* may not be used by renderer */
} RLPaletteFlags;

typedef struct _RLPaletteEntry {
    unsigned char red;		/* 0 .. 255 */
    unsigned char green;	/* 0 .. 255 */
    unsigned char blue;		/* 0 .. 255 */
    unsigned char flags;	/* one of RLPaletteFlags */
} RLPaletteEntry;

typedef void (*RLRenderCallback)
    (RLDevice dev,		/* device being rendered */
     void* arg,			/* render_arg passed XXX RLCreateMemoryDevice */
     void* buffer1,		/* buffer being updated */
     void* buffer2,		/* second buffer (if doublebuffering) */
     int x1, int y1,		/* top left of updated rectangle */
     int x2, int y2		/* bottom left of updated rectangle
				 * (non-inclusive) */
     );

typedef void (*RLPaletteCallback)
    (RLDevice dev,		/* device being changed */
     void* arg,			/* palette_arg in XXX RLMemoryDeviceInfo */
     int pixel,			/* pixel number being changed */
     int red,			/* red component (0 .. 255) */
     int green,			/* green component (0 .. 255) */
     int blue			/* blue component (0 .. 255) */
     );
typedef void (*RLObjectEnumerateCallback)
    (RLObject id,		/* the object */
     char* object_type,		/* a string describing the object type */
     void* arg			/* arg passed to RLEnumerateObjects */
     );

typedef struct _RLImage {
    int width, height;		/* width and height in pixels */
    int aspectx, aspecty;	/* aspect ratio for non-square pixels */
    int depth;			/* bits per pixel */
    int rgb;			/* if false, pixels are indices into a
				   palette otherwise, pixels encode
				   RGB values. */
    int bytes_per_line;		/* number of bytes of memory for a
				   scanline. This must be a multiple
				   of 4. */
    void* buffer1;		/* memory to render into (first buffer). */
    void* buffer2;		/* second rendering buffer for double
				   buffering, set to NULL for single
				   buffering. */
    unsigned long red_mask;
    unsigned long green_mask;
    unsigned long blue_mask;
    unsigned long alpha_mask;
    				/* if rgb is true, these are masks for
				   the red, green and blue parts of a
				   pixel.  Otherwise, these are masks
				   for the significant bits of the
				   red, green and blue elements in the
				   palette.  For instance, most SVGA
				   displays use 64 intensities of red,
				   green and blue, so the masks should
				   all be set to 0xfc. */
    int palette_size;           /* number of entries in palette */
    RLPaletteEntry* palette;	/* description of the palette (only if
				   rgb is false).  Must be (1<<depth)
				   elements. */
} RLImage;

typedef enum _RLEventType {
    RLEventButtonPress, RLEventButtonRelease,
    RLEventKeyPress, RLEventKeyRelease,
    RLEventDrag
} RLEventType;

typedef struct _RLEvent {
    RLEventType		type;
    int			x, y;
    union {
	int		button;
	int		key;
    } u;
} RLEvent;

/*
 * Get the code for the last error generated by the system.
 */
RLError			RLGetLastError(void);

/*
 * Generate an error, calling all error handlers and returning the error
 * which was raised.
 */
RLError			RLRaiseError(RLError error);

/*
 * Register a function to be called when a runtime error is detected.
 * It is always safe for an error handler to return; the system will
 * recover from the error appropriately.
 */
RLError			RLAddErrorHandler(RLErrorHandler fn,
					  void* arg);

/*
 * Remove an error handler previously registered with
 * RLAddErrorHandler.
 */
RLError			RLRemoveErrorHandler(RLErrorHandler fn,
					     void* arg);

/*
 * Add elements to the current file search path.
 */
RLError                 RLAddSearchPath(const char* path);

/*
 * Set the current file search path.  To clear the search path,
 * pass NULL.
 */
RLError                 RLSetSearchPath(const char* path);

/*
 * Get the current file search path.  The number of elements in the path
 * is returned in *count_return and an array of strings, one for each
 * element in the path is returned in *path_return.  The application must
 * free each of these strings along with the array itself.
 */
RLError                 RLGetSearchPath(int* count_return,
                                        char*** path_return);

/*
 * Return a descriptive string for an error.
 */
const char*		RLErrorString(RLError error);

/* 
 * Destroy an object.  The object will only be actually destroyed if
 * it is not used by any other object.
 */
RLError			RLObjectDestroy(RLObject object);

/*
 * Duplicate an object.
 */ 
RLObject		RLObjectCopy(RLObject object);

/*
 * Set the object's name.
 */
RLError			RLObjectSetName(RLObject object, const char* name);

/*
 * Get the object's name.
 */
const char*		RLObjectGetName(RLObject object);

/*
 * Find an object given its name.  Returns NULL if no object found.
 */
RLObject		RLObjectFromName(const char* name);

/*
 * Determine whether an object exists (i.e. it has not been destroyed
 * using RLObjectDestroy or via normal system reference countine).
 * Returns RLNoError if the object exists or RLBadObject if not.  No
 * error will be generated and the application's error handlers will
 * not be called.
 */
RLError			RLObjectExists(RLObject object);

/*
 * Return the name of the object's class.  Returns NULL on error.
 */
const char*		RLObjectGetClassName(RLObject object);

/*
 * Inform the system that the application is holding a long-term
 * reference to an object.  This can be used to prevent the system
 * from automatically reclaiming the memory for a texture when the
 * meshes which use it are destroyed or a commonly used mesh when it
 * is removed from its frame.
 */
RLError			RLObjectReference(RLObject object);

/*
 * this function returns the total number of references to the
 * given object that exist due to both the system, and the
 * RLObjectReference call. If the object doesn't exist the
 * returned value will be 0
 */
long 			RLObjectGetReferenceCount(RLObject object);

/*
 * Register a function to be called when an object is destroyed.
 */
RLError			RLObjectAddDestroyCallback(RLObject object,
						   RLDestroyCallback fn,
						   void* arg);
/*
 * Remove a function previously registered with RLObjectAddDestroyCallback.
 */
RLError			RLObjectRemoveDestroyCallback(RLObject object,
						      RLDestroyCallback fn,
						      void* arg);

RLError 		RLObjectGetDestroyCallbacks(RLObject object,
				   		    int* count,
				   		    RLDestroyCallback **fns,
				   		    void* **args);

/*
 * Duplicate an object.  This manufactures a separate copy of the
 * given object, including its attributes.
 */ 
RLObject		RLObjectCopy(RLObject object);

/*
 * Set the application data for an object.
 */
RLError			RLObjectSetAppData(RLObject object,
					   unsigned long data);

/*
 * Get the application data for an object.
 */
unsigned long		RLObjectGetAppData(RLObject object);

/*
 * Create a wrapping function which can be used to assign texture
 * coordinates to faces and meshes.
 */

typedef enum _RLWrapType {
    RLWrapFlat,
    RLWrapCylinder,
    RLWrapSphere,
    RLWrapChrome
} RLWrapType;

RLWrap			RLCreateWrap(RLWrapType type,
				     RLFrame refid,
				     RLValue ox, RLValue oy, RLValue oz,
				     RLValue dx, RLValue dy, RLValue dz,
				     RLValue ux, RLValue uy, RLValue uz,
				     RLValue ou, RLValue ov,
				     RLValue su, RLValue sv);

/*
 * Apply the wrap to the vertices of the object.
 */
RLError			RLWrapApply(RLWrap, RLObject);

/*
 * Apply the wrap to the vertices of the object, first transforming each
 * vertex by the frame's world transform and the wrap's reference frame's
 * inverse world transform.  Generate an RLBadValue error if the wrap
 * does not have a reference frame.
 */
RLError			RLWrapApplyRelative(RLWrap, RLFrame frame, RLObject);

/* 
 * Create a device for rendering the the screen or window.  Note that
 * the device which is created may have different width and height
 * than those passed to RLCreateDevice.  Use RLDeviceGetWidth and
 * RLDeviceGetHeight to find the correct values.
 */
RLDevice		RLCreateDevice(int width, int height);

/*
 * Create a device for rendering to offscreen memory.
 */
RLDevice		RLCreateMemoryDevice(RLImage* image,
					     RLImage* zimage,
					     RLRenderCallback render,
					     void* render_arg,
					     RLPaletteCallback set_colour,
					     void* set_colour_arg);

/*
 * Return a list of devices in *devices_return and *count_return.
 */
RLError			RLGetDevices(int* count_return,
				     RLDevice** devices_return);

RLError			RLDeviceUpdate(RLDevice dev);

/*
 * Use to lock against VSync on a given device
 */
RLError			RLDeviceSync(RLDevice);

/*
 * Return a list of the viewports on a device in *views_return and
 * *count_return.
 */
RLError			RLDeviceGetViewports(RLDevice dev,
					     int* count_return,
					     RLViewport** views_return);

/*
 * Return the width in pixels of a Device.
 */
int			RLDeviceGetWidth(RLDevice);

/*
 * Return the height in pixels of a Device.
 */
int			RLDeviceGetHeight(RLDevice);

/*
 * Return the number of polygons rendered since the device was created.
 */
long			RLDeviceGetPolygonsDrawn(RLDevice);

/*
 * Set the dither flag for the device.  Default is TRUE.
 */
RLError			RLDeviceSetDither(RLDevice, int);

/*
 * Get the dither flag for the device.  Returns -1 on error.
 */
int			RLDeviceGetDither(RLDevice);


/*
 * Get the palette and palette flags for an 8 bit device.
 * Note palette_return must be freed with RLFree.
 */
RLError			RLDeviceGetPalette(RLDevice id,
					   int start, int size,
					   RLPaletteEntry** palette_return);

/*
 * Set the palette and palette flags for an 8 bit device.
 */
RLError			RLDeviceSetPalette(RLDevice id,
					   int start, int size,
					   RLPaletteEntry* palette);

/*
 * Set the rendering quality for the device.  Default is RLRenderFlat.
 */
RLError			RLDeviceSetQuality(RLDevice, RLRenderQuality);

/*
 * Get the rendering quality for the device.  Returns -1 on error.
 */
RLRenderQuality		RLDeviceGetQuality(RLDevice);

/*
 * Get the preferred Image format for the current device, need to call
 * RLFree on the returned RLImage
 */
RLError RLDeviceGetImageFormat(RLDevice, RLImage**);

/*
 * Set options for rendering wireframe objects.  The options argument is
 * a bitmask of the following bits.  The default value is
 * (RLWireframeCull|RLWireframeHiddenLine).
 */

#define RLWireframeCull		1 /* cull backfaces */
#define RLWireframeHiddenLine	2 /* lines are obscured by closer objects */

RLError			RLDeviceSetWireframeOptions(RLDevice, int options);

/*
 * Get the wireframe options.
 */
int			RLDeviceGetWireframeOptions(RLDevice);

/*
 * Set the texture quality for the device.  Default is RLTextureNearest.
 */
RLError			RLDeviceSetTextureQuality(RLDevice, RLTextureQuality);

/*
 * Get the texture quality for the device.  Returns -1 on error.
 */
RLTextureQuality	RLDeviceGetTextureQuality(RLDevice);

/*
 * Set the colour model for the device.
 */
RLError			RLDeviceSetColourModel(RLDevice, RLColourModel);

/*
 * Get the colour model for the device.  Returns -1 on error.
 */
RLColourModel		RLDeviceGetColourModel(RLDevice);

/*
 * Set the gamma correction value for the device.
 */
RLError			RLDeviceSetGamma(RLDevice, RLValue);

/*
 * Return the current gamma value for the device.
 */
RLValue                  RLDeviceGetGamma(RLDevice);

/*
 * Set the number of shades in a ramp of colours used for shading.
 * Must be a power of 2.  Default is 32.
 */
RLError			RLDeviceSetShades(RLDevice, int);

/*
 * Get the number of shades in a ramp of colours used for shading.
 * Returns -1 on error.
 */
int			RLDeviceGetShades(RLDevice);

/*
 * Create a viewport on dev with screen coordinates (x, y) to (x +
 * width, y + height).  The viewport displays objects in the scene of
 * camera with the view direction and upvector taken from camera.
 */
RLViewport		RLCreateViewport(RLDevice dev,
					 RLFrame camera,
					 int x, int y,
					 int width, int height);

/*
 * Get the device the viewport is associated with
 */
RLDevice		RLViewportGetDevice(RLViewport view);

/*
 * Get the dimensions of a viewport.
 */
int			RLViewportGetX(RLViewport view);
int			RLViewportGetY(RLViewport view);
int			RLViewportGetWidth(RLViewport view);
int			RLViewportGetHeight(RLViewport view);

/*
 * Reconfigure the dimensions of a viewport
 */
RLError			RLViewportConfigure(RLViewport view,
						int x, int y,
						int width, int height);


/*
 * Clear the contents of the viewport.
 */
RLError			RLViewportClear(RLViewport view);

/*
 * Force an area of the viewport to be updated.  The specified area will
 * be copied to the screen at the next call to RLDeviceUpdate.
 */
RLError			RLViewportForceUpdate(RLViewport view,
					      int x1, int y1,
					      int x2, int y2);

/*
 * Set the projection type for the viewport.  The default value is
 * RLProjectPerspective.
 */

typedef enum _RLProjectionType {
    RLProjectPerspective,
    RLProjectOrthographic
} RLProjectionType;

RLError			RLViewportSetProjection(RLViewport view,
						RLProjectionType type);

/*
 * Get the current projection type for the viewport.
 */
RLProjectionType	RLViewportGetProjection(RLViewport view);

/*
 * Render a hierarchy in the viewport.
 */
RLError			RLViewportRender(RLViewport view, RLFrame scene);

/*
 * Transform the vector *s in world coordinates to screen coordinates
 * returning the result in *d.
 */
RLError			RLViewportTransform(RLViewport view,
					    RLVector4d* d,
					    RLVector* s);

/*
 * Transform the vector *s in screen coordinates to world coordinates
 * returning the result in *d.
 */
RLError			RLViewportInverseTransform(RLViewport view,
						   RLVector* d,
						   RLVector4d* s);

/*
 * Change the camera for the viewport.
 */
RLError			RLViewportSetCamera(RLViewport view,
					    RLFrame camera);

/*
 * Get the current camera for the viewport.
 */
RLFrame			RLViewportGetCamera(RLViewport view);

/*
 * Change the front clipping plane for the viewport.  Defaults to 1.0
 */
RLError			RLViewportSetFront(RLViewport view, RLValue front);

/*
 * Return the current value for the viewport's front clipping plane.
 */
RLValue                  RLViewportGetFront(RLViewport view);

/*
 * Change the back clipping plane for the viewport.  Defaults to 100.0
 */
RLError			RLViewportSetBack(RLViewport view, RLValue back);

/*
 * Return the current value for the viewport's back clipping plane.
 */
RLValue                  RLViewportGetBack(RLViewport view);

/*
 * Change the field of view for the viewport.  Defaults to 0.5
 */
RLError			RLViewportSetField(RLViewport view, RLValue field);

/*
 * Return the current value for the viewport's field of view.
 */
RLValue                  RLViewportGetField(RLViewport view);

/*
 * Define the front clipping plane of the viewing frustum by giving the
 * coordinates of the four sides, relative to the camera's z axis.
 */
RLError			RLViewportSetPlane(RLViewport view,
					   RLValue left, RLValue right,
					   RLValue bottom, RLValue top);

/*
 * Get the front clipping plane of the viewing frustum.
 */
RLError			RLViewportGetPlane(RLViewport view,
					   RLValue* left, RLValue* right,
					   RLValue* bottom, RLValue* top);

/*
 * If this is set to TRUE, then the same horizontal and vertical scaling
 * factor is used to scale the viewing volume into the larger dimension
 * of the window.  Otherwise, different scaling factors are used to scale
 * the viewing volume exactly into the window.  This would normally be used
 * with RLViewportSetPlane to support banding.  The default setting is TRUE.
 */
RLError			RLViewportSetUniformScaling(RLViewport view, int);

/*
 * Returns TRUE if the viewport scales uniformly, otherwise FALSE.
 */
int			RLViewportGetUniformScaling(RLViewport view);


typedef struct _RLFaceInfo {
    RLVector	position;
    RLFace	face;
    RLMesh	mesh;
    RLFrame	frame;
} RLFaceInfo;

/*
 * Find the closest face with x, y screen coordinates.  The position, face
 * mesh and frame are returned in *info.  Returns RLNotFound if there
 * is no face with the given coordinates.  Note that this will not
 * call the application's error handler when it returns RLNotFound.
 */
RLError			RLViewportFindFace(RLViewport view,
					   RLFaceInfo* info,
					   int x, int y);

/*
 * Find a list of faces with x, y screen coordinates, sorted by depth.
 * The number of faces is returned in *count_return and a list of
 * RLFaceInfo structures is allocated and returned in *info_return.
 * This memory should be freed with RLFree.
 */
RLError			RLViewportFindFaces(RLViewport view,
					    int* count_return,
					    RLFaceInfo** info_return,
					    int x, int y);

/*
 * Find the closest object with x, y screen coordinates.
 */
RLError			RLViewportFindVisual(RLViewport view,
					     RLVisual* visual_return,
					     RLFrame* frames_return,
					     int x, int y);

/*
 * Find a depth sorted list of objects with x, y screen coordinates.
 */
RLError			RLViewportFindVisuals(RLViewport view,
					      int* count_return,
					      RLVisual** visuals_return,
					      RLFrame** frames_return,
					      int x, int y);

typedef struct _RLPickRecord {
    RLVector	position;
    RLFace	face;
    RLVisual	visual;
    int		frame_count;
    RLFrame*	frames;
} RLPickRecord;

/*
 * Find a depth sorted list of objects (and faces if relavent) which includes
 * the path taken in the hierarchy from the root down to the frame which
 * contained the object.
 */
RLError			RLViewportPick(RLViewport id, int x, int y,
				       int* count_return,
				       RLPickRecord** records_return);

/*
 * Free the information returned by RLViewportPick.
 */
void			RLFreePickRecords(int count, RLPickRecord* records);

/*
 * RL System heartbeat.
 */
RLError			RLTick(void);

/*
 * Create a colour from three components in the range 0-1 inclusive.
 */
RLColour		RLCreateColourRGB(RLValue red,
					  RLValue green,
					  RLValue blue);

/*
 * Create a colour from four components in the range 0-1 inclusive.
 */
RLColour		RLCreateColourRGBA(RLValue red,
					   RLValue green,
					   RLValue blue,
					   RLValue alpha);

/*
 * Get the red component of a colour.
 */
RLValue			RLColourGetRed(RLColour);

/*
 * Get the green component of a colour.
 */
RLValue			RLColourGetGreen(RLColour);

/*
 * Get the blue component of a colour.
 */
RLValue			RLColourGetBlue(RLColour);

/*
 * Get the alpha component of a colour.
 */
RLValue			RLColourGetAlpha(RLColour);

/*
 * Create a new RLFace object with no vertices.
 */
RLFace			RLCreateFace(void);

/* 
 * Add a vertex to a face.
 */
RLError			RLFaceAddVertex(RLFace face,
					RLValue x,
					RLValue y,
					RLValue z);

/*
 * Add a vertex to a face by its index in the containing mesh.  The
 * face must already be in a mesh.
 */
RLError			RLFaceAddVertexAndNormalIndexed(RLFace face,
							int vertex,
							int normal);

/*
 * Set the colour of a face
 */
RLError			RLFaceSetColourRGB(RLFace, RLValue, RLValue, RLValue);
RLError			RLFaceSetColour(RLFace, RLColour);

/*
 * Get the colour of a face.  Returns -1 if there was an error.
 */
RLColour		RLFaceGetColour(RLFace);

/*
 * Get vertex information for a face.  Sets *vertex_count to the
 * number of vertices, *coords to point at a list of RLVectors for
 * the vertex coordinates and *normals to point at a list of RLVectors
 * for the vertex normals.
 * The memory returned in *coords and *normals should be freed with
 * RLFree.
 */
RLError			RLFaceGetVertices(RLFace,
					  int* vertex_count,
					  RLVector** coords,
					  RLVector** normals);

/*
 * Get the number of vertices for a face.  Note that this information
 * is also provided by RLFaceGetVertices.  Returns -1 on error.
 */
int			RLFaceGetVertexCount(RLFace);

/*
 * Get an individual vertex and normal for a face.  Note that this
 * information is also provided by RLFaceGetVertices.  Possible values
 * for which range from 0 to RLFaceGetVertexCount(face) - 1.
 */
RLError			RLFaceGetVertex(RLFace,
					int which,
					RLVector* vertex,
					RLVector* normal);

/*
 * Get the vertex index in a mesh for a given face index.
 * Returns -1 on error.
 */
int			RLFaceGetVertexIndex(RLFace, int which);

/*
 * Get the normal index in a mesh for a given face index.
 * Returns -1 on error.
 */
int			RLFaceGetNormalIndex(RLFace, int which);

/*
 * Get the texture coordinate index in a mesh for a given face index.
 * Returns -1 on error.
 */
int			RLFaceGetTextureCoordinateIndex(RLFace id, int which);

/*
 * Set the texture map for a face.  Pass NULL to remove the texture from
 * the face.
 */
RLError			RLFaceSetTexture(RLFace, RLTexture);

/*
 * Get the texture map for a face.  Returns NULL if there is no texture
 * or if an error occurred.
 */
RLTexture		RLFaceGetTexture(RLFace);

/*
 * Set the texture coordinates of a single vertex in a face.
 * Texture coordinates range from (0,0) for the top left to
 * (1,1) for the bottom right. u or v values higher than 1
 * indicate repetition of the texture
 */
RLError			RLFaceSetTextureCoordinates(RLFace id,
						    int which,
						    RLValue u,
						    RLValue v);

/*
 * Get the texture coordinates of a single vertex in a face.
 * The values are returned in u and v.
 * Texture coordinates range from (0,0) for the top left to
 * (1,1) for the bottom right. u or v values higher than 1
 * indicate repetition of the texture
 */
RLError 		RLFaceGetTextureCoordinates(RLFace,
						    int which,
						    RLValue* u,
						    RLValue* v);

/*
 * Set the material for a face.  Pass NULL to remove the material from
 * the face.
 */
RLError			RLFaceSetMaterial(RLFace, RLMaterial);

/*
 * Get the material for a face.  Returns NULL if there is no material
 * or if an error occurred.
 */
RLMaterial		RLFaceGetMaterial(RLFace);

/*
 * Define the topological properties of the texture coordinates
 * across the face.  The texture can be considered to form either
 * a flat surface of infinite extent, an infinite cylinder with
 * either the u or v coordinate wrapping around or a torus with
 * both u and v wrapping around.  The wrap_u and wrap_v parameters
 * define whether the texture wraps around in the u and v direction
 * respectively.  The default values for wrap_u and wrap_v are FALSE.
 */
RLError RLFaceSetTextureTopology(RLFace face, int wrap_u, int wrap_v);

/*
 * Get the topological properties of a texture when mapped onto the face.
 */
RLError RLFaceGetTextureTopology(RLFace face, int* wrap_u, int* wrap_v);

/*
 * Get a normal vector to the face.
 */ 
RLError			RLFaceGetNormal(RLFace id, RLVector* n);

/*
 * Create a new mesh object with no faces.
 */
RLMesh			RLCreateMesh(void);

/*
 * Load a mesh from a file
 */
RLMesh		RLLoadOldMesh(const char*);
RLMesh		RLLoadMesh(const char*);
RLMesh		RLLoadMeshWithTextures(const char* name,
				       RLTextureNameCallback load_tex_fn,
				       void* arg);

typedef enum _RLXOFFormat {
    RLXOFBinary,
    RLXOFCompressed,
    RLXOFText
} RLXOFFormat;

#define RLXOFSaveNormals		1
#define RLXOFSaveTextureCoordinates	2
#define RLXOFSaveMaterials		4
#define RLXOFSaveTextureNames		8
#define RLXOFSaveAll                    15

/*
 * Save a mesh, using either a binary or a text format, specifying
 * which optional sections to save.
 */
RLError			RLSaveMesh(RLMesh mesh, char* fileName,
		      		   RLXOFFormat format, int save);

/*
 * Add a vertex to the mesh, returning the index of the new vertex.
 * The vertex index can then be used later with
 * RLFaceAddVertexAndNormalIndexed.  Returns -1 on error.
 */
int			RLMeshAddVertex(RLMesh mesh,
					RLValue x, RLValue y, RLValue z);

/*
 * Add a normal to the mesh, returning the index of the new normal.
 * The normal index can then be used later with
 * RLFaceAddVertexAndNormalIndexed.  Returns -1 on error.
 */
int			RLMeshAddNormal(RLMesh mesh,
					RLValue x, RLValue y, RLValue z);

/*
 * Add the face to the mesh. The face is consumed by the mesh and
 * cannot be deleted or added to another mesh.
 */
RLError			RLMeshAddFace(RLMesh mesh, RLFace);

/*
 * Create a face and add it to the mesh.  Equivalent to RLCreateFace()
 * followed by RLMeshAddFace().
 */
RLFace			RLMeshCreateFace(RLMesh mesh);

/*
 * Add a number of faces to a mesh.  For each face, face_data should
 * contain a vertex count followed by the indices into the vertices
 * array of the faces.  If normal_count is non-zero, then face_data
 * should contain a vertex count, followed by pairs of indices, the
 * first into the vertices array and the second into the normals
 * array.
 *
 * If face_count_return is non-null, the number of faces added
 * is returned in *face_count_return.
 *
 * If faces_return is non-null, the faces are returned in
 * *faces_return.  The memory should be freed using
 * RLFree(*faces_return).
 */
RLError			RLMeshAddFaces(RLMesh mesh,
				       int vertex_count,
				       RLVector* vertices,
				       int normal_count,
				       RLVector* normals,
				       int* face_data,
				       int* face_count_return,
				       RLFace** faces_return);

/*
 * Reserve space for a given number of vertices, normals, and faces to
 * be added to the mesh.  This can be used when a large number of
 * face-sets are to be added to the mesh to optimise performance.
 */
RLError			RLMeshReserveSpace(RLMesh mesh,
					   int vertex_count,
					   int normal_count,
					   int face_count);

/*
 * Set the values of the each normal in the mesh to the average of the
 * face normals of the faces which share the normal.
 */
RLError			RLMeshGenerateNormals(RLMesh mesh);

/*
 * Set all the faces in a mesh to the given colour.
 */
RLError			RLMeshSetColourRGB(RLMesh, RLValue, RLValue, RLValue);
RLError			RLMeshSetColour(RLMesh, RLColour);

/*
 * Set all the faces in a mesh to the given texture.
 */
RLError			RLMeshSetTexture(RLMesh, RLTexture);

/*
 * Set all the faces in a mesh to the given material.
 */
RLError			RLMeshSetMaterial(RLMesh, RLMaterial);

/*
 * Define the topological properties of the texture coordinates
 * across the mesh.  See also RLFaceSetTextureTopology.
 */
RLError RLMeshSetTextureTopology(RLMesh mesh, int wrap_u, int wrap_v);

/*
 * Set the rendering quality for a mesh.  The quality used for
 * rendering is the minimum of the device quality and the mesh
 * quality.  Default is RLRenderPhong.
 */
RLError			RLMeshSetQuality(RLMesh, RLRenderQuality);

/*
 * Get the rendering quality for a mesh.  Returns -1 on error.
 */
RLRenderQuality		RLMeshGetQuality(RLMesh);


/*
 * Set perspective correction flag for a mesh. Default is FALSE.
 */
RLError			RLMeshSetPerspective(RLMesh mesh, int perspective);

/*
 * Get perspective correction flag for a mesh.  Returns -1 on error.
 */
int			RLMeshGetPerspective(RLMesh mesh);

/*
 * Flags to say whether to relight the mesh every tick, to light just once,
 * or to never light.
 */
RLError			RLMeshSetLightingFrequency(RLMesh, RLLightingFrequency);
RLLightingFrequency	RLMeshGetLightingFrequency(RLMesh);


/*
 * Scale a mesh.
 */
RLError			RLMeshScale(RLMesh,
				    RLValue sx,
				    RLValue sy,
				    RLValue sz);

/*
 * Translate a mesh
 */
RLError                 RLMeshTranslate(RLObject id,
					RLValue tx, 
					RLValue ty, 
					RLValue tz);

/*
 * Find the frame which owns this mesh (if any).
 */
RLFrame			RLMeshGetFrame(RLMesh);

/*
 * Find a bounding box for the mesh.
 */
RLError			RLMeshGetBox(RLMesh, RLBox*);

/*
 * Get a list of the faces in the mesh.  Sets *face_count to the
 * number of faces in the mesh and *faces to point to a list of the
 * faces.  The memory returned in *faces must be freed with RLFree.
 */
RLError			RLMeshGetFaces(RLMesh,
				       int* face_count,
				       RLFace** faces);

/*
 * Return the number of faces in the mesh.
 */
int RLMeshGetFaceCount(RLMesh id);

/*
 * Get a list of the vertices and normals which makes up the faces of the
 * mesh.  The memory returned in *vertices, *normals and *face_data
 * must be freed with RLFree.  The data returned in *face_data is in
 * the same format as that taken by RLMeshAddFaces.
 */
RLError			RLMeshGetVertices(RLMesh,
					  int* vertex_count,
					  RLVector** vertices,
					  int* normal_count,
					  RLVector** normals,
					  int** face_data);

/*
 * Return the number of vertices in the mesh.
 */
int			RLMeshGetVertexCount(RLMesh);

/* 
 * Set the coordinates for a vertex in the mesh.
 */
RLError			RLMeshSetVertex(RLMesh, int which,
					RLValue x, RLValue y, RLValue z);

/* 
 * Set the value of a normal vector in the mesh.
 */
RLError			RLMeshSetNormal(RLMesh, int which,
					RLValue x, RLValue y, RLValue z);

/* 
 * Set the texture coordinates for a vertex in the mesh.
 */
RLError			RLMeshSetTextureCoordinates(RLMesh, int which,
						    RLValue u, RLValue v);

/*
 * Get the texture coordinates for a vertex in the mesh.
 */
RLError			RLMeshGetTextureCoordinates(RLMesh id, int which,
						    RLValue* u, RLValue* v);
typedef enum _RLColourSource {
    RLColourFromFace,
    RLColourFromVertex
} RLColourSource;

/*
 * Set the colour of a vertex to be used if the mesh's colour source
 * is set to RLColourFromVertex.  Default is white.
 */
RLError			RLMeshSetVertexColour(RLMesh id, int which,
					      RLColour colour);
RLError			RLMeshSetVertexColourRGB(RLMesh id, int which,
						 RLValue red,
						 RLValue green,
						 RLValue blue);

/*
 * Get the colour of a vertex.
 */
RLColour		RLMeshGetVertexColour(RLMesh id, int which);


/*
 * Choose whether to take colours from faces or vertices when
 * rendering a mesh.  Default is to use the face colours.
 */
RLError			RLMeshSetColourSource(RLMesh id,
					      RLColourSource source);

/*
 * Return the current colour source for the mesh.
 */
RLColourSource		RLMeshGetColourSource(RLMesh id);

/*
 * Create a new light with the given type and colour.
 */
RLLight			RLCreateLightRGB(RLLightType, RLValue, RLValue, RLValue);
RLLight			RLCreateLight(RLLightType, RLColour);

/*
 * Change the type of a light.
 */
RLError			RLLightSetType(RLLight, RLLightType);

/*
 * Get the type of a light.  Returns -1 on error.
 */
RLLightType		RLLightGetType(RLLight);

/*
 * Change the colour of a light.
 */
RLError			RLLightSetColourRGB(RLLight, RLValue, RLValue, RLValue);
RLError			RLLightSetColour(RLLight, RLColour);

/*
 * Get the colour of a light.  Returns -1 on error.
 */
RLColour		RLLightGetColour(RLLight);

/*
 * Set the range of a spotlight.  Only objects within the range are
 * affected by the light.  The default value is 256.
 */
RLError			RLLightSetRange(RLLight, RLValue);

/*
 * Get the range of a spotlight.  Returns -1 on error.
 */
RLValue			RLLightGetRange(RLLight);

/*
 * The beam of a spotlight has two parts: the umbra and the penumbra.
 * Within the umbra, the spotlight acts as a point source.  Within the
 * penumbra, the spotlight intensity falls off to zero.  This sets the
 * angle of the umbra cone.  Setting the umbra angle to greater than
 * the penumbra increases the penumbra to the new umbra angle.  The
 * default value is 0.4 radians.
 */
RLError			RLLightSetUmbra(RLLight, RLValue);

/*
 * Get the umbra angle of a spotlight.  Returns -1 on error.
 */
RLValue			RLLightGetUmbra(RLLight);

/*
 * Set the angle of the penumbra cone.  Must be greater than or equal
 * to the umbra.  Setting the penumbra angle to less than the umbra
 * contracts the umbra to the new angle for the penumbra. The default
 * value is 0.5 radians.
 */
RLError			RLLightSetPenumbra(RLLight, RLValue);

/*
 * Get the penumbra angle of a spotlight.  Returns -1 on error.
 */
RLValue			RLLightGetPenumbra(RLLight);

/*
 * Set the constant attenuation factor for a light.
 */
RLError			RLLightSetConstantAttenuation(RLLight id,
						      RLValue value);
/*
 * Get the constant attenuation factor for a light.
 */
RLValue			RLLightGetConstantAttenuation(RLLight id);

/*
 * Set the linear attenuation factor for a light.
 */
RLError			RLLightSetLinearAttenuation(RLLight id,
						    RLValue value);

/*
 * Get the linear attenuation factor for a light.
 */
RLValue			RLLightGetLinearAttenuation(RLLight id);

/*
 * Set the quadratic attenuation factor for a light.
 */
RLError			RLLightSetQuadraticAttenuation(RLLight id,
						       RLValue value);
/*
 * Get the quadratic attenuation factor for a light.
 */
RLValue			RLLightGetQuadraticAttenuation(RLLight id);

/*
 * Create a frame of reference relative to a parent reference frame.
 * To create the master reference frame, specify NULL for the parent.
 */
RLFrame			RLCreateFrame(RLFrame parent);

/*
 * Apply the rotations and velocity for all frames in a hierarchy.
 */
RLError			RLFrameMove(RLFrame frame);

/*
 * Add a function to be called to move a frame in an animation.  The
 * function is called before the velocity and rotation of the frame
 * are applied, so changes to the velocity and rotation made by the
 * function will be reflected in the frame's motion.
 */
RLError			RLFrameAddCallback(RLFrame frame,
					   RLFrameCallback fn,
					   void* arg);

/*
 * Remove a function previously registered with RLFrameAddCallback.
 */
RLError			RLFrameRemoveCallback(RLFrame frame,
					      RLFrameCallback fn,
					      void* arg);

/*
 * Add a child frame to a frame.  If the child already has a parent,
 * it is removed from its current parent first.  The location and
 * orientation of the child in the scene are unchanged.
 */ 
RLError			RLFrameAddChild(RLFrame, RLFrame);

/*
 * Remove a child frame from a frame.  If there are no other
 * references to the child, it will be destroyed along with any child
 * frames, meshes and lights that it might have.
 */
RLError			RLFrameRemoveChild(RLFrame, RLFrame);

/*
 * Put an object into a frame.
 * The object added to the frame is then referenced by the frame. 
 * If the frame is destroyed the object will be destroyed as well, 
 * providing it has no other references.
 */
RLError			RLFrameAddVisual(RLFrame, RLVisual);
RLError			RLFrameAddLight(RLFrame, RLLight);

/*
 * Remove an object from a frame.  If there are no other references to
 * the object, it will be destroyed.
 */
RLError			RLFrameRemoveVisual(RLFrame, RLVisual);
RLError			RLFrameRemoveLight(RLFrame, RLLight);

/*
 * Build a mesh which is the union of all meshes in this frame and
 * all meshes in child frames of this frame.  Returns NULL on error.
 */
RLMesh			RLFrameBuildMesh(RLFrame);

/* 
 * Set frame position within the scene in the frame of reference.  If 
 * reference is NULL, position is relative to the root frame.
 */
RLError			RLFrameSetPosition(RLFrame frame,
					   RLFrame reference,
					   RLValue x,
					   RLValue y,
					   RLValue z);

/* 
 * Face the frame along the given vector.
 */
RLError			RLFrameSetOrientation(RLFrame frame,
					      RLFrame reference,
					      RLValue dx, /* direction */
					      RLValue dy,
					      RLValue dz,
					      RLValue ux, /* up */
					      RLValue uy,
					      RLValue uz);

typedef enum _RLFrameConstraint {
    RLConstrainZ,		/* use only X and Y rotations */
    RLConstrainY,		/* use only X and Z rotations */
    RLConstrainX		/* use only Y and Z rotations */
} RLFrameConstraint;

/*
 * Face the frame towards the target frame, relative to the given
 * reference frame, constraining the rotation by the given constraints.
 */
RLError			RLFrameLookAt(RLFrame frame, RLFrame target,
				      RLFrame reference,
				      RLFrameConstraint constraint);
/*
 * Move the frame linearly along the given vector at each call to
 * RLTick().
 */
RLError			RLFrameSetVelocity(RLFrame frame,
					   RLFrame reference,
					   RLValue x,
					   RLValue y,
					   RLValue z);

/*
 * Rotate the frame by theta about the axis given by (x, y, z)
 * relative to reference at each call to RLTick().
 */
RLError			RLFrameSetRotation(RLFrame frame,
					   RLFrame reference,
					   RLValue x,
					   RLValue y,
					   RLValue z,
					   RLValue theta);

/*
 * The following functions modify the frame's local transformation
 * directly.  A transform can be premultiplied by, can replace or can
 * be postmultiplied by the current local transformation.
 */

/*
 * Transform the local coordinates of the frame to the given affine
 * transform according to the value of combine.
 * Note that although a 4x4 matrix is given, the last column must be
 * transpose([0 0 0 1]) for the transform to be affine.
 */
RLError			RLFrameAddTransform(RLFrame frame,
					    RLCombineType combine,
					    RLMatrix4d matrix);

/*
 * Scale a frame by (sx, sy, sz).
 */
RLError			RLFrameAddScale(RLFrame id, RLCombineType combine,
					RLValue sx, RLValue sy, RLValue sz);

/*
 * Rotate a frame about (x, y, z) by theta radians.
 */
RLError			RLFrameAddRotation(RLFrame id, RLCombineType combine,
					   RLValue x, RLValue y, RLValue z,
					   RLValue theta);

/*
 * Translate a frame by (x, y, z).
 */
RLError			RLFrameAddTranslation(RLFrame id,
					      RLCombineType combine,
					      RLValue x, RLValue y, RLValue z);

/*
 * Get the root frame of a hierarchy.
 */
RLFrame			RLFrameGetScene(RLFrame frame);

/*
 * Get the local transform of the frame.
 */
RLError			RLFrameGetTransform(RLFrame frame,
					    RLMatrix4d matrix);

/*
 * Get the position of the frame relative to the given reference frame.
 */
RLError			RLFrameGetPosition(RLFrame frame,
					   RLFrame reference,
					   RLVector* position);

/*
 * Get the velocity of the frame relative to the given reference frame.
 */
RLError			RLFrameGetVelocity(RLFrame frame,
					   RLFrame reference,
					   RLVector* velocity);

/*
 * Get the rotation of the frame relative to the given reference frame.
 */
RLError 		RLFrameGetRotation(RLFrame frame,
					   RLFrame reference,
			   		   RLVector* axis,
					   RLValue* theta);

/*
 * Get the orientation of the frame, relative to the given reference frame.
 */
RLError			RLFrameGetOrientation(RLFrame frame,
					      RLFrame reference,
					      RLVector* dir,
					      RLVector* up);

/*
 * Get the parent frame of this frame.
 */
RLFrame			RLFrameGetParent(RLFrame frame);

/*
 * Get a list of child frames.  The number of frames is returned in
 * *count and *children is set to point to a list of the frames.  The
 * memory returned in *children should be freed with RLFree.
 */
RLError RLFrameGetChildren(RLFrame id,
			   int* count,
			   RLFrame** children);

/*
 * Get a list of visuals in the frame.  The number of visuals is
 * returned in *count and *visuals is set to point to a list of the
 * visuals.  The memory returned in *visuals should be freed with
 * RLFree.
 */
RLError			RLFrameGetVisuals(RLFrame frame,
					  int* count,
					  RLVisual** visuals);

/*
 * Get a list of lights in the frame.  The number of lights is
 * returned in *count and *lights is set to point to a list of the
 * lights.  The memory returned in *lights should be freed with
 * RLFree.
 */
RLError			RLFrameGetLights(RLFrame frame,
					 int* count,
					 RLLight** lights);

/*
 * Set the colour of the frame.  This colour is used for meshes in the
 * frame when the material mode (see RLFrameSetMaterialMode) is
 * RLMaterialFromFrame.
 */
RLError			RLFrameSetColour(RLFrame frame, RLColour colour);
RLError			RLFrameSetColourRGB(RLFrame frame,
					    RLValue red,
					    RLValue green,
					    RLValue blue);

/*
 * Get the colour of the frame.
 */
RLColour		RLFrameGetColour(RLFrame frame);

/*
 * Set the texture of the frame.  This texture is used for meshes in
 * the frame as for RLFrameSetColour.  To disable the frame's texture,
 * use a NULL texture.
 */
RLError			RLFrameSetTexture(RLFrame frame, RLTexture texture);

/*
 * Get the texture for a frame.
 */
RLTexture		RLFrameGetTexture(RLFrame frame);

/*
 * Define the topological properties of the texture coordinates
 * across objects in the frame.  See also RLFaceSetTextureTopology.
 */
RLError			RLFrameSetTextureTopology(RLFrame frame,
						  int wrap_u, int wrap_v);

/*
 * Get the topological properties of a texture when mapped onto
 * objects in the frame.
 */
RLError			RLFrameGetTextureTopology(RLFrame frame,
						  int* wrap_u, int* wrap_v);

/*
 * Set the material mode for a frame.  The material mode determines
 * the source of material information for visuals rendered with the
 * frame.  The default, RLMaterialFromMesh takes material information
 * from the visual itself.  RLMaterialFromFrame overrides the visual's
 * material with the colour or texture from the frame.
 * RLMaterialFromParent inherits the material mode setting (and
 * colour or texture) from the parent frame.
 *
 * If a toplevel frame is rendered with its material mode set to
 * RLMaterialFromParent, it behaves as if it had a parent with a
 * material mode of RLMaterialFromMesh.
 */
typedef enum _RLMaterialMode {
    RLMaterialFromMesh,
    RLMaterialFromParent,
    RLMaterialFromFrame
} RLMaterialMode;
RLError			RLFrameSetMaterialMode(RLFrame frame,
					       RLMaterialMode mode);

/*
 * Get the material mode for a frame.
 */
RLMaterialMode		RLFrameGetMaterialMode(RLFrame frame);

/*
 * Transform the vector *s in frame coordinates to world coordinates
 * returning the result in *d.
 */
RLError			RLFrameTransform(RLFrame frame,
					 RLVector* d,
					 RLVector* s);

/*
 * Transform the vector *s in world coordinates to frame coordinates
 * returning the result in *d.
 */
RLError			RLFrameInverseTransform(RLFrame frame,
						RLVector* d,
						RLVector* s);

/*
 * Set a background colour for a scene (a frame with no parent).
 * The default background colour is black.
 */
RLError			RLSceneSetBackground(RLFrame frame, RLColour bg);
RLError			RLSceneSetBackgroundRGB(RLFrame frame,
						RLValue red,
						RLValue green,
						RLValue blue);

/*
 * Get the current background colour for a scene.
 */
RLColour		RLSceneGetBackground(RLFrame frame);

/*
 * Set a background image for a scene.
 */
RLError			RLSceneSetBackgroundImage(RLFrame frame, RLTexture bg);

/*
 * Set a background depth field for a scene.  The image must have a depth
 * of 16 bits.
 */
RLError			RLSceneSetBackgroundDepth(RLFrame frame, RLImage* im);

/*
 * Get the current background depth field for the scene.
 */
RLImage*		RLSceneGetBackgroundDepth(RLFrame frame);

/*
 * Create a texture from an image in memory.
 */
RLTexture		RLCreateTexture(RLImage*);

/*
 * Load a texture from the file named.
 */
RLTexture		RLLoadTexture(const char*);

/*
 * Load a texture from the named file, called from RLLoadMeshWithTextures.
 */
RLTexture		RLLoadTextureHandler(const char*, void* arg);

/*
 * Inform the renderer that the pixels or palette of a texture's image
 * have been changed by the application.
 */
RLError                 RLTextureChanged(RLTexture,
                                         int pixels,
                                         int palette);
/*
 * Return a pointer to the image that the texture was created with
 */
RLImage*		RLTextureGetImage(RLTexture);

/*
 * Set the default values for a new texture's colours and shades.
 */
void			RLTextureSetDefaultColours(int);
void			RLTextureSetDefaultShades(int);

/*
 * Add an image which specifies opacity values for each pixel of the
 * texture.
 */
RLError			RLTextureSetOpacity(RLTexture, RLImage*);

/*
 * Get the current image specifying opacity values for the texture.
 */
RLImage*		RLTextureGetOpacity(RLTexture);

/*
 * Get the maximum number of colours for a texture to use in the palette
 * colour model.
 */
int			RLTextureGetColours(RLTexture);

/*
 * Set the maximum number of colours for a texture to use in the palette
 * colour model.
 */
RLError			RLTextureSetColours(RLTexture, int);

/*
 * Get the maximum number of shades of each colour for a texture to use in
 * the palette colour model.
 */
int			RLTextureGetShades(RLTexture);

/*
 * Set the maximum number of shades of each colour for a texture to use in
 * the palette colour model.
 */
RLError			RLTextureSetShades(RLTexture, int);

/*
 * Set the size of the decal (in model space) to be used if the decal
 * is being scaled according to its depth in the scene.  The default
 * size is (1, 1).
 */
RLError			RLTextureSetDecalSize(RLTexture,
					      RLValue width, RLValue height);

/*
 * Get the size of the decal previously set with
 * RLTextureSetDecalSize.
 */
RLError			RLTextureGetDecalSize(RLTexture,
					      RLValue* width_return,
					      RLValue* height_return);

/*
 * Set the offset from the top left of the decal origin.  The origin
 * is mapped to the containing frame's position when rendering.  The
 * default origin is (0, 0).
 */
RLError			RLTextureSetDecalOrigin(RLTexture, int x, int y);

/*
 * Get the origin of the decal previously set with
 * RLTextureSetDecalOrigin.
 */
RLError			RLTextureGetDecalOrigin(RLTexture,
						int* x_return,
						int* y_return);

typedef enum _RLDecalDepth {
    RLDecalFront,		/* decal is in front of everything */
    RLDecalBack,		/* decal is behind everything */
    RLDecalMix			/* decal is mixed in according to depth */
} RLDecalDepth;

/*
 * Set the depth properties for a decal.  The decal can be in front of
 * the scene, behind the scene or it can be part of the scene,
 * obscuring or being obscured according to the depth value of its
 * frame.  Default is RLDecalMix.
 */
RLError			RLTextureSetDecalDepth(RLTexture, RLDecalDepth);

/*
 * Return the current depth properties of the decal.  Returns -1 on
 * error.
 */
RLDecalDepth		RLTextureGetDecalDepth(RLTexture);

/*
 * Set to TRUE to scale the decal with depth otherwise FALSE.
 * Default is TRUE.
 */
RLError			RLTextureSetDecalScale(RLTexture, int);

/*
 * Get the scaling property of the decal.  Returns -1 on error.
 */
int			RLTextureGetDecalScale(RLTexture);

/*
 * Set to TRUE if the decal has a transparent colour otherwise FALSE.
 * Default is FALSE.
 */
RLError			RLTextureSetDecalTransparency(RLTexture, int);

/*
 * Get the transparency property of the decal.  Returns -1 on error.
 */
int			RLTextureGetDecalTransparency(RLTexture);

/*
 * Set the transparent colour for a decal.  The default transparent colour
 * is black.
 */
RLError			RLTextureSetDecalTransparentColour(RLTexture, RLColour);

/*
 * Get the transparent colour for a decal.
 */
RLColour		RLTextureGetDecalTransparentColour(RLTexture);

/*
 * Create a shadow from the visual with the light, projecting onto the
 * specified plane.  The shadow is a visual which should be added
 * to the frame which contains the visual.
 */
RLShadow		RLCreateShadow(RLVisual visual, RLLight light,
				       RLValue px, RLValue py, RLValue pz,
				       RLValue nx, RLValue ny, RLValue nz);

/*
 * Create a material with the given properties.
 */
RLMaterial		RLCreateMaterial(RLValue ks, RLValue power);

/*
 * Set the coefficient of specular reflection in a material.
 */
RLError			RLMaterialSetKs(RLMaterial id, RLValue ks);

/*
 * Get the coefficient of specular reflection in a material.
 */
RLValue			RLMaterialGetKs(RLMaterial id);

/*
 * Set the power used for the specular exponent in a material.
 */
RLError			RLMaterialSetPower(RLMaterial id, RLValue power);

/*
 * Get the power used for the specular exponent in a material.
 */
RLValue			RLMaterialGetPower(RLMaterial id);

typedef enum _RLPathType {
    RLPathOpen,
    RLPathClosed
} RLPathType;

/*
 * Create a path, specifying the type of path where RLPathOpen is a path
 * with a start and end point and RLPathClosed is a path where the end
 * loops back to the beginning.
 */
RLPath                  RLCreatePath(RLPathType type);

/*
 * Add a point to the end of a path.
 */
RLError                 RLPathAddPoint(RLPath path,
                                       RLValue x, RLValue y, RLValue z);

/*
 * Insert a point before the existing point with the given index.
 */
RLError                 RLPathInsertPoint(RLPath path, int index,
                                          RLValue x, RLValue y, RLValue z);

/*
 * Delete the point with the given index from the path.
 */
RLError                 RLPathDeletePoint(RLPath path, int index);

/*
 * Return the number of points in the path.
 */
int                     RLPathGetSize(RLPath path);

/*
 * Return the type of the path.
 */
RLPathType 		RLPathGetType(RLPath id);

/*
 * Return the point with the given index from the path in *p.
 */
RLError                 RLPathGetPoint(RLPath path, int index, RLVector* p);

/*
 * Position and orient a frame at a given parametric position on a path
 * relative to the given reference frame.  If the path has insufficient
 * points for the given parametric position, then an RLBadValue error
 * is generated.
 */
RLError                 RLPathPositionFrame(RLPath path,
                                            RLFrame frame, RLFrame ref,
                                            RLValue place);

/*
 * Position a frame at a given parametric position on a path
 * relative to the given reference frame.  Do not orient it.
 * If the path has insufficient
 * points for the given parametric position, then an RLBadValue error
 * is generated.
 */
RLError                 RLPathPlaceFrame(RLPath path,
					 RLFrame frame, RLFrame ref,
					 RLValue place);

/*
 * Create a new, empty animation.
 */
RLAnimation		RLCreateAnimation();

/*
 * Add a rotation keyframe to the animation.
 */
RLError			RLAnimationAddRotateKey(RLAnimation anim,
						RLValue time,
						RLQuaternion* q);

/*
 * Add a position keyframe to the animation.
 */
RLError			RLAnimationAddPositionKey(RLAnimation anim,
						  RLValue time,
						  RLValue x,
						  RLValue y,
						  RLValue z);

/*
 * Add a scaling keyframe to the animation.
 */
RLError			RLAnimationAddScaleKey(RLAnimation anim,
					       RLValue time,
					       RLValue x,
					       RLValue y,
					       RLValue z);

/*
 * Set the frame which is being animated.
 */
RLError			RLAnimationSetFrame(RLAnimation anim,
					    RLFrame frame);

/*
 * Set the current time of the animation, modifying the transform of the
 * animation's frame (if any).
 */
RLError			RLAnimationSetTime(RLAnimation anim, RLValue time);

/*
 * Create a new, empty animation set.
 */
RLAnimationSet		RLCreateAnimationSet();

/*
 * Add an animation to the set.
 */
RLError			RLAnimationSetAddAnimation(RLAnimationSet id,
						   RLAnimation aid);

/*
 * Remove an animation from the set.
 */
RLError			RLAnimationSetRemoveAnimation(RLAnimationSet id,
						      RLAnimation aid);

/*
 * Set the time of all animations in the set.
 */
RLError			RLAnimationSetSetTime(RLAnimationSet id, RLValue time);

/*
 * Add two vectors.  Returns its first argument.
 */
RLVector*		RLVectorAdd(RLVector* d,
				    RLVector* s1,
				    RLVector* s2);

/*
 * Subtract two vectors.  Returns its first argument.
 */
RLVector*		RLVectorSubtract(RLVector* d,
					 RLVector* s1,
					 RLVector* s2);
/*
 * Reflect a ray about a given normal.  Returns its first argument.
 */
RLVector*		RLVectorReflect(RLVector* d,
					RLVector* ray,
					RLVector* norm);

/*
 * Calculate the vector cross product.  Returns its first argument.
 */
RLVector*		RLVectorCrossProduct(RLVector* d,
					     RLVector* s1,
					     RLVector* s2);
/*
 * Return the vector dot product.
 */
RLValue			RLVectorDotProduct(RLVector* s1,
					   RLVector* s2);

/*
 * Scale a vector so that its modulus is 1.  Returns its argument or
 * NULL if there was an error (e.g. a zero vector was passed).
 */
RLVector*		RLVectorNormalise(RLVector*);

/*
 * Return the length of a vector (e.g. sqrt(x*x + y*y + z*z)).
 */
RLValue			RLVectorModulus(RLVector* v);

/*
 * Set the rotation part of a matrix to be a rotation of theta radians
 * around the given axis.
 */

RLVector*	RLVectorRotate(RLVector* r, RLVector* v, RLVector* axis, RLValue theta);

/*
 * Scale a vector uniformly in all three axes
 */
RLVector* RLVectorScale(RLVector* d, RLVector* s, RLValue factor);

/*
 * Return a random unit vector
 */
RLVector* RLVectorRandom(RLVector* d);

/*
 * Returns a unit quaternion that represents a rotation of theta radians
 * around the given axis.
 */

RLQuaternion* RLQuaternionFromRotation(RLQuaternion* quat, 
	RLVector* v,
	RLValue theta);

/*
 * Calculate the product of two quaternions
 */
RLQuaternion* RLQuaternionMultiply(RLQuaternion* q,
				   RLQuaternion* a,
				   RLQuaternion* b);

/*
 * Interpolate between two quaternions
 */
RLQuaternion* RLQuaternionSlerp(RLQuaternion* q, 
                                RLQuaternion* a, 
                                RLQuaternion* b, 
				RLValue alpha);

/*
 * Calculate the matrix for the rotation that a unit quaternion represents
 */
void RLMatrixFromQuaternion(RLMatrix4d mat, RLQuaternion* quat);

/*
 * Register a set of functions to be used in place of malloc, realloc
 * and free for memory allocation.  The functions RLMalloc, RLRealloc
 * and RLFree will use these functions.  The default is to use the
 * ANSI C library routines malloc, realloc and free.
 */
typedef void* (*RLMallocFunction)(size_t);
typedef void* (*RLReallocFunction)(void*, size_t);
typedef void (*RLFreeFunction)(void*);

void			RLSetAllocator(RLMallocFunction malloc_fn,
				       RLReallocFunction realloc_fn,
				       RLFreeFunction free_fn);

/*
 * Get the current functions used for memory allocation.
 */
void			RLGetAllocator(RLMallocFunction* malloc_fn_return,
				       RLReallocFunction* realloc_fn_return,
				       RLFreeFunction* free_fn_return);

/*
 * Print out the object id and class name of all objects currently
 * allocated.
 */
void			RLPrintObjects(void);

/*
 * Run through the list of active RLObjects and allow the callback to be
 * applied to each
 */
void RLEnumerateObjects(RLObjectEnumerateCallback enumerate_cb, void* arg);

/*
 * Allocate size bytes of memory and return a pointer to it in *p_return.
 * Returns RLBadAlloc with *p_return unchanged if the allocation fails.
 */
RLError RLMalloc(void** p_return, size_t size);

/*
 * Change the size of an allocated block of memory.  A pointer to the
 * block is passed in in *p_inout.  If *p_inout is NULL then a new
 * block is allocated.  If the reallocation is successful, *p_inout is
 * changed to point to the new block.  If the allocation fails,
 * *p_inout is unchanged and RLBadAlloc is returned.
 */
RLError RLRealloc(void** p_inout, size_t size);

/*
 * Free a block of memory previously allocated with RLMalloc or
 * RLRealloc.
 */
void RLFree(void* p);

/*
 * Get the total amount of memory currently allocated by the library
 */
size_t	RLGetTotalAllocated(void);

#if defined(__cplusplus)
};
#endif

#endif /* rl.h */
