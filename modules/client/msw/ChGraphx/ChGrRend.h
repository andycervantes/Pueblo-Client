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

	Includes for standard renderer header files. 

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChGrRend.h,v 2.3 1996/07/08 21:30:23 jimd Exp $
//

// The Renderer to use is selected at compile-time only
#if !defined(ChGrRend_h)
#define	ChGrRend_h	1

#if defined(CH_USE_OPENGL)
// Open GL
#include "glos.h"
#include <gl\gl.h>
#include <gl\glu.h>

#elif defined(CH_USE_3DR)
// Intel 3DR
#include <3dr.h>
#include <3dg.h>

#elif (defined(CH_USE_RLAB))
// Microsoft Reality Lab
#include "rl.h"
#include "rlwin.h"
#elif defined(CH_USE_D3D)
#include <direct.h>
#include <d3drmwin.h>
#else
#error "Undefined Renderer"
#endif // 3DR

// Standard aliases for common native types
#if defined(CH_USE_OPENGL)
// Open GL

#elif defined(CH_USE_3DR)
// Intel 3DR
typedef Dword_t ChNativeContext;

#elif (defined(CH_USE_RLAB))
// Microsoft Reality Lab
typedef RLDevice  		ChNativeContext;	
typedef RLFrame 		ChNrFrame;	
typedef RLViewport 		ChNrViewport;	
typedef RLMesh 			ChNrMesh;
typedef RLFace 			ChNrFace;
typedef RLLight 		ChNrLight;
typedef RLMaterial 		ChNrMaterial;
typedef RLObject		ChNrObject;
typedef RLImage  		ChNrImage;
typedef RLLightType 	ChNrLightType;
typedef	RLValue 		ChNrValue;
typedef RLVector4d		ChNrVector4d;
typedef RLVector		ChNrVector;
typedef RLPaletteEntry	ChNrPaletteEntry;

typedef RLFace*			ChNrFaceArray;
typedef RLLight*		ChNrLightArray;
typedef RLFrame*		ChNrFrameArray;

typedef int ChNrFaceData;

typedef RLRenderQuality	ChNrRenderQuality;
typedef RLColourModel	ChNrColorModel;
typedef RLFaceInfo	ChNrFaceInfo;

#define ChNrPaletteFree			RLPaletteFree      
#define ChNrPaletteReadOnly 	RLPaletteReadOnly   
#define ChNrPaletteReserved 	RLPaletteReadOnly   
                      
			// Native Renderer (Nr) macros to make RL & D3D look
			// pretty much alike
#define ChNrDeviceGetColorModel							RLDeviceGetColourModel
#define ChNrDeviceGetDither(dev)						RLDeviceGetDither((dev))
#define ChNrDeviceGetHeight(dev)						(DWORD(RLDeviceGetHeight(dev)))
#define ChNrDeviceGetQuality							RLDeviceGetQuality
#define ChNrDeviceGetShades(dev)						(DWORD(RLDeviceGetShades(dev)))	
#define ChNrDeviceGetWidth(dev)							(DWORD(RLDeviceGetWidth(dev)))
#define ChNrDeviceSetColorModel							RLDeviceSetColourModel
#define ChNrDeviceSetDither(dev, dit)					RLDeviceSetDither((dev), (dit))
#define ChNrDeviceSetHeight(dev, w)						RLDeviceSetHeight(dev, w))
#define ChNrDeviceSetQuality(dev, q)					RLDeviceSetQuality((dev),(q))
#define ChNrDeviceSetShades(dev, ns)					RLDeviceSetShades((dev), (ns))	
#define ChNrDeviceSetWidth(dev, w)						RLDeviceSetWidth(dev, w))
#define ChNrDeviceUpdate(dev) 							RLDeviceUpdate(dev)
#define ChNrFaceAddVertexAndNormalIndexed				RLFaceAddVertexAndNormalIndexed  
#define ChNrFaceGetColor								RLFaceGetColour                 
#define ChNrFaceGetMaterial(fce, pmat)					(*(pmat)=RLFaceGetMaterial(fce))
#define ChNrFaceGetVertexCount							RLFaceGetVertexCount             
#define ChNrFaceGetVertexIndex							RLFaceGetVertexIndex            
#define ChNrFaceSetColor								RLFaceSetColour		
#define ChNrFaceSetMaterial								RLFaceSetMaterial
#define ChNrFrameAddCallback							RLFrameAddCallback
#define ChNrFrameAddChild(frm, chld)		  			RLFrameAddChild((frm), (chld))
#define ChNrFrameAddLight        						RLFrameAddLight
#define ChNrFrameAddScale(frm, cmbn, sx, sy, sz)		RLFrameAddScale((frm), (cmbn), (sx), (sy), (sz))
#define ChNrFrameAddTransform							RLFrameAddTransform
#define ChNrFrameAddTranslation  						RLFrameAddTranslation
#define ChNrFrameAddVisual(frm, vis)		 			RLFrameAddVisual((frm), (vis))
#define ChNrFrameGetChildren     						RLFrameGetChildren
#define ChNrFrameGetLights								RLFrameGetLights
#define ChNrFrameGetOrientation							RLFrameGetOrientation
#define ChNrFrameGetParent(frm, prnt) 					((prnt)=RLFrameGetParent(frm))       
#define ChNrFrameGetPosition							RLFrameGetPosition
#define ChNrFrameInverseTransform						RLFrameInverseTransform
#define ChNrFrameMove(frm, dlta)						RLFrameMove(frm)
#define ChNrFrameRemoveChild(frm, chld)		  			RLFrameRemoveChild((frm), (chld))
#define ChNrFrameRemoveVisual    						RLFrameRemoveVisual
#define ChNrFrameSetOrientation  						RLFrameSetOrientation 
#define ChNrFrameSetPosition(frm, relFrm, px, py, pz)	RLFrameSetPosition((frm), (relFrm), (px), (py), (pz))
#define ChNrFrameTransform								RLFrameTransform
#define ChNrFree(o)										RLFree(o)
#define ChNrLightGetConstantAttenuation					RLLightGetConstantAttenuation
#define ChNrLightGetLinearAttenuation					RLLightGetLinearAttenuation
#define ChNrLightGetQuadraticAttenuation				RLLightGetQuadraticAttenuation
#define ChNrLightSetColor								RLLightSetColour
#define ChNrLightSetPenumbra	 						RLLightSetPenumbra
#define ChNrLightSetUmbra		  						RLLightSetUmbra	
#define ChNrMeshAddFaces(msh, vcnt, v, ncnt, n, fcdata, pnfc, pfcary)		RLMeshAddFaces((msh), (vcnt), (v), (ncnt), (n), (fcdata), (pnfc), (pfcary))
#define ChNrMeshAddNormal								RLMeshAddNormal
#define ChNrMeshAddVertex								RLMeshAddVertex	  
#define ChNrMeshCreateFace(msh, fce)			 		((fce)=RLMeshCreateFace((msh)))
#define ChNrMeshGetColorSource							RLMeshGetColourSource
#define ChNrMeshReserveSpace							RLMeshReserveSpace
#define ChNrMeshSetColorSource							RLMeshSetColourSource	
#define ChNrMeshSetMaterial								RLMeshSetMaterial
#define ChNrMeshSetPerspective							RLMeshSetPerspective
#define ChNrMeshSetQuality								RLMeshSetQuality
#define ChNrMeshSetTexture								RLMeshSetTexture           
#define ChNrMeshSetTextureCoordinates					RLMeshSetTextureCoordinates
#define ChNrMeshSetTextureTopology						RLMeshSetTextureTopology   
#define ChNrMeshSetVertexColor							RLMeshSetVertexColour	
#define ChNrObjectAddDestroyCallback(o, fn, dat)		RLObjectAddDestroyCallback((o), (fn), (dat))
#define ChNrObjectDestroy								RLObjectDestroy
#define ChNrObjectGetAppData							RLObjectGetAppData
#define ChNrObjectReference(o)							RLObjectReference(o)
#define ChNrObjectRemoveDestroyCallback					RLObjectRemoveDestroyCallback
#define ChNrObjectSetAppData							RLObjectSetAppData
#define ChNrTextureChanged(txt)							RLTextureChanged(txt)
#define ChNrTextureSetColors  							RLTextureSetColours
#define ChNrTextureSetDecalScale						RLTextureSetDecalScale 
#define ChNrTextureSetDecalOrigin						RLTextureSetDecalOrigin
#define ChNrTextureSetShades							RLTextureSetShades
#define ChNrViewportClear								RLViewportClear
#define ChNrViewportFindFace	   						RLViewportFindFace
#define ChNrViewportFindFaces	   						RLViewportFindFaces
#define ChNrViewportFindVisual	   						RLViewportFindVisual
#define ChNrViewportForceUpdate	  						RLViewportForceUpdate
#define ChNrViewportGetCamera(vu, cam)					((cam)=RLViewportGetCamera(vu))
#define ChNrViewportGetHeight							RLViewportGetHeight    
#define ChNrViewportGetProjection						RLViewportGetProjection
#define ChNrViewportGetWidth							RLViewportGetWidth     
#define ChNrViewportGetX								RLViewportGetX
#define ChNrViewportGetY								RLViewportGetY
#define ChNrViewportInverseTransform					RLViewportInverseTransform
#define ChNrViewportRender								RLViewportRender
#define ChNrViewportSetProjection						RLViewportSetProjection
#define ChNrViewportTransform	  						RLViewportTransform
#define ChNrViewportSetBack								RLViewportSetBack 
#define ChNrViewportGetBack								RLViewportGetBack 
#define ChNrViewportSetFront							RLViewportSetFront
#define ChNrViewportGetFront							RLViewportGetFront
#define ChNrViewportGetField							RLViewportGetField
#define ChNrViewportSetField							RLViewportSetField
// //
#define RenderWireframe	 	RLRenderWireframe	 
#define RenderUnlitFlat		RLRenderUnlitFlat	 
#define RenderFlat			RLRenderFlat		 
#define RenderGouraud		RLRenderGouraud	 
#define RenderPhong			RLRenderPhong		 

#define CombineReplace		RLCombineReplace
#define CombineBefore		RLCombineBefore
#define CombineAfter		RLCombineAfter
typedef RLCombineType		ChNativeCombineType;

#define ColorFromFace		RLColourFromFace
#define ColorFromVertex	    RLColourFromVertex

#define ProjectPerspective 		RLProjectPerspective 
#define ProjectOrthographic		RLProjectOrthographic

#define ChNrLightAmbient		RLLightAmbient	
#define ChNrLightDirectional	RLLightDirectional
#define ChNrLightPoint	  		RLLightPoint	  	
#define ChNrLightSpot			RLLightSpot		

#define D3DRelease(obj)	

// These two macros only work in the scope of ChRenderContext for d3d
#define ChNrSetDefaultTextureColors(n)				RLTextureSetDefaultColours(n)
#define ChNrSetDefaultTextureShades(n)				RLTextureSetDefaultShades(n)

#elif defined(CH_USE_D3D)
// Microsoft d3d
typedef LPDIRECT3DRMDEVICE  ChNativeContext;
typedef LPDIRECT3DRMFRAME ChNrFrame;	
typedef LPDIRECT3DRMVIEWPORT ChNrViewport;	
typedef LPDIRECT3DRMMESHBUILDER ChNrMesh;
typedef LPDIRECT3DRMFACE ChNrFace;
typedef LPDIRECT3DRMLIGHT ChNrLight;
typedef LPDIRECT3DRMMATERIAL ChNrMaterial;
typedef LPDIRECT3DRMOBJECT ChNrObject;
typedef D3DRMIMAGE ChNrImage;
typedef D3DRMLIGHTTYPE ChNrLightType;
typedef D3DRMVECTOR4D	ChNrVector4d;
typedef D3DVECTOR	ChNrVector;

typedef D3DRMPALETTEENTRY	ChNrPaletteEntry;

typedef LPDIRECT3DRMFACEARRAY	ChNrFaceArray;
typedef LPDIRECT3DRMLIGHTARRAY	ChNrLightArray;
typedef LPDIRECT3DRMFRAMEARRAY	ChNrFrameArray;

typedef D3DRMRENDERQUALITY	ChNrRenderQuality;
typedef D3DCOLORMODEL	ChNrColorModel;
typedef unsigned long ChNrFaceData;

#define ChNrPaletteFree			D3DRMPALETTE_FREE
#define ChNrPaletteReadOnly 	D3DRMPALETTE_READONLY   
#define ChNrPaletteReserved 	D3DRMPALETTE_RESERVED   

			// Native Renderer (Nr) macros to make RL & D3D look
			// pretty much alike
#define ChNrDeviceGetDither(dev)		((dev)->GetDither())
#define ChNrDeviceGetHeight(dev)		((dev)->GetHeight())
#define ChNrDeviceGetShades(dev)		((dev)->GetShades())
#define ChNrDeviceGetWidth(dev)			((dev)->GetWidth())
#define ChNrDeviceGetQuality(dev)		((dev)->GetQuality())
#define ChNrDeviceGetColorModel(dev)	((dev)->GetColorModel())

	
#define ChNrDeviceSetDither(dev, dit)	((dev)->SetDither(dit))
#define ChNrDeviceSetHeight(dev, h)		((dev)->SetHeight(h))
#define ChNrDeviceSetShades(dev, ns)	((dev)->SetShades(ns))	
#define ChNrDeviceSetWidth(dev, w)		SetWidth(w))
#define ChNrDeviceSetQuality(dev, q)	((dev)->SetQuality(q))

#define ChNrDeviceUpdate(dev)		(dev)->Update()

#define ChNrViewportForceUpdate(vu, dwX1, dwY1, dwX2,dwY2)	\
	  		((vu)->ForceUpdate((dwX1), (dwY1), (dwX2),(dwY2)))
#define ChNrViewportRender(vu, fr)			((vu)->Render(fr))
#define ChNrViewportClear(vu)				((vu)->Clear())
#define ChNrViewportFindFaces	   		RLViewportFindFaces
#define ChNrViewportFindVisual	   		RLViewportFindVisual
#define ChNrViewportTransform(vu, v4dst, v3src)	  		((vu)->Transform((v4dst), (v3src)))
#define ChNrViewportInverseTransform(vu, v3dst, v4src)	((vu)->InverseTransform((v3dst), (v4src)))
#define ChNrViewportSetBack(vu, d)	 	((vu)->SetBack(d))
#define ChNrViewportGetBack(vu)	 		((vu)->GetBack())
#define ChNrViewportSetFront(vu, d)	 	((vu)->SetFront(d))
#define ChNrViewportGetFront(vu)	 	((vu)->GetFront())
#define ChNrViewportGetField(vu)		((vu)->GetField())
#define ChNrViewportSetField(vu, d)	 	((vu)->SetField(d))

#define ChNrTextureChanged(txt)			((txt)->Changed())

#define ChNrFrameAddCallback(frm, fn, dat)	((frm)->AddMoveCallback((fn), (dat)))
#define ChNrFrameAddScale(frm, cmbn, sx, sy, sz)	((frm)->AddScale((cmbn), (sx), (sy), (sz)))
#define ChNrFrameAddTransform(frm, cmbn, mat)		((frm)->AddTransform((cmbn), (mat)))
#define ChNrFrameMove(frm, dlta)			 ((frm)->Move(dlta))
#define ChNrFrameSetPosition(frm, relFrm, px, py, pz)	((frm)->SetPosition((relFrm), (px), (py), (pz)))
#define ChNrFrameAddVisual(frm, vis)		 ((frm)->AddVisual(vis))
#define ChNrFrameRemoveChild(frm, chld)		((frm)->DeleteChild(chld))
#define ChNrFrameAddChild(frm, chld)		((frm)->AddChild(chld))
#define ChNrFrameTransform(frm, dst, src)	((frm)->Transform((dst), (src)))

#define ChNrMeshSetQuality(msh, q)		((msh)->SetQuality(q))

#define ChNrMeshSetColorSource(msh,  src)			((msh)->SetColorSource(src))
#define ChNrMeshSetVertexColor(msh, vIndex, clr)	((msh)->SetVertexColor((vIndex), (clr)))
#define ChNrFaceSetColor(fce, clr)					((fce)->SetColor(clr))

//#define ChNrFaceInfo                      
//#define ChNrFrameGetLights 						((frm)->GetLights       
//#define ChNrViewportFindFace
#define ChNrFaceAddVertexAndNormalIndexed(fce, v, n)	((fce)->AddVertexAndNormalIndexed((v), (n)))  
#define ChNrFaceGetColor(fce)							((fce)->GetColor())                  
#define ChNrFaceGetVertexCount(fce)						((fce)->GetVertexCount())             
#define ChNrFaceGetVertexIndex(fce, inx)				((fce)->GetVertexIndex(inx))             
#define ChNrFaceSetColor(fce, clr)						((fce)->SetColor(clr))                  
#define ChNrFrameAddLight(frm, lt)						((frm)->AddLight(lt))        
#define ChNrFrameAddTranslation(frm, cmbn, tx, ty, tz)		((frm)->AddTranslation((cmbn), (tx), (ty), (tz)))  
#define ChNrFrameGetChildren(frm, pcnt, pary)			((frm)->GetChildren(pary))     
#define ChNrFrameGetOrientation(frm, frmRef, lk, up)	((frm)->GetOrientation((frmRef), (lk), (up)))
#define ChNrFrameGetParent(frm, prnt) 					((frm)->GetParent(&(prnt)))       
#define ChNrFrameGetPosition(frm, frmRef, pos)			((frm)->GetPosition((frmRef), (pos)))
#define ChNrFrameInverseTransform(frm, v1, v2)			((frm)->InverseTransform((v1), (v2)))
#define ChNrFrameRemoveVisual(frm, vis)					((frm)->DeleteVisual(vis))    
#define ChNrFrameSetOrientation(frm, frmRef, lkx, lky, lkz, upx, upy, upz)	((frm)->SetOrientation((frmRef), (lkx), (lky), (lkz), (upx), (upy), (upz)))  
#define ChNrFrameGetLights(frm, pcnt, pary)				((frm)->GetLights((pary)))
#define ChNrLightGetConstantAttenuation(lt)				((lt)->GetConstantAttenuation())
#define ChNrLightGetLinearAttenuation(lt)				((lt)->GetLinearAttenuation())   
#define ChNrLightGetQuadraticAttenuation(lt)			((lt)->GetQuadraticAttenuation())
#define ChNrLightSetColor(lt, clr)						((lt)->SetColor(clr))              
#define ChNrLightSetPenumbra(lt, val)					((lt)->SetPenumbra(val))            
#define ChNrLightSetUmbra(lt, val)						((lt)->SetUmbra(val))                
#define ChNrMeshAddFaces(msh, vcnt, v, ncnt, n, fcdata, pnfc, pfcary)		((msh)->AddFaces((vcnt), (v), (ncnt), (n), (fcdata), (pfcary)))
#define ChNrMeshAddNormal(msh, nx, ny, nz)			 	((msh)->AddNormal((nx), (ny), (nz)))
#define ChNrMeshAddVertex(msh, nx, ny, nz)			 	((msh)->AddVertex((nx), (ny), (nz)))
#define ChNrMeshCreateFace(msh, fce)			 		((msh)->CreateFace(&(fce)))
#define ChNrMeshGetColorSource(msh)						((msh)->GetColorSource())
#define ChNrMeshReserveSpace(msh, vcnt, ncnt, fcnt)		((msh)->ReserveSpace((vcnt), (ncnt), (fcnt)))	
#define ChNrMeshSetPerspective(msh, val)				((msh)->SetPerspective((val)))
#define ChNrMeshSetTexture(msh, val)					((msh)->SetTexture((val)))
#define ChNrMeshSetTextureCoordinates(msh, i, u, v)		((msh)->SetTextureCoordinates((i), (u), (v)))
#define ChNrMeshSetTextureTopology(msh, valu, valv)		((msh)->SetTextureTopology((valu),(valv)))
#define ChNrObjectRemoveDestroyCallback(o, fn, dat)		((o)->DeleteDestroyCallback((fn), (dat)))
#define ChNrViewportGetCamera(vu, cam)					((vu)->GetCamera(&(cam)))
#define ChNrViewportGetHeight(vu)						((vu)->GetHeight())
#define ChNrViewportGetProjection(vu)					((vu)->GetProjection())
#define ChNrViewportGetWidth(vu)						((vu)->GetWidth())
#define ChNrViewportSetProjection(vu, prval)			((vu)->SetProjection(prval))

#define ChNrTextureSetShades(tx, n)						((tx)->SetShades(n))
#define ChNrTextureSetColors(tx, n)						((tx)->SetColors(n))
#define ChNrTextureSetDecalScale(tx, val)				((tx)->SetDecalScale(val))
#define ChNrTextureSetDecalOrigin(tx, px, py) 			((tx)->SetDecalOrigin((px), (py))) 

#define ChNrFaceGetMaterial(fce, pmat)					((fce)->GetMaterial(pmat))
#define ChNrFaceSetMaterial(fce, mat)					((fce)->SetMaterial(mat))
#define ChNrMeshSetMaterial(msh, mat)					((msh)->SetMaterial(mat))

#define ChNrObjectDestroy(o)							((o)->Release())
#define ChNrObjectAddDestroyCallback(o, fn, dat)		((o)->AddDestroyCallback((fn), (dat)))
#define ChNrObjectSetAppData(o, dat)					((o)->SetAppData(dat))
#define ChNrObjectGetAppData(o)							((o)->GetAppData())
														
#define ChNrObjectReference(o)							((o)->AddRef())
#define ChNrFree(o)				((o)->Release())

#define RenderWireframe	D3DRMRENDER_WIREFRAME 
#define RenderUnlitFlat	D3DRMRENDER_UNLITFLAT 
#define RenderFlat		D3DRMRENDER_FLAT      
#define RenderGouraud	D3DRMRENDER_GOURAUD   
#define RenderPhong		D3DRMRENDER_PHONG

#define CombineReplace     D3DRMCOMBINE_REPLACE
#define CombineBefore      D3DRMCOMBINE_BEFORE
#define CombineAfter        D3DRMCOMBINE_AFTER
#define	ChNativeCombineType D3DRMCOMBINETYPE
#define	ChNrValue D3DVALUE

#define ColorFromFace		D3DRMCOLOR_FROMFACE
#define ColorFromVertex	    D3DRMCOLOR_FROMVERTEX

#define ProjectPerspective 		D3DRMPROJECT_PERSPECTIVE 
#define ProjectOrthographic		D3DRMPROJECT_ORTHOGRAPHIC

#define ChNrLightAmbient		D3DRMLIGHT_AMBIENT
#define ChNrLightDirectional	D3DRMLIGHT_DIRECTIONAL
#define ChNrLightPoint	  		D3DRMLIGHT_POINT
#define ChNrLightSpot			D3DRMLIGHT_SPOT

#define D3DRelease(obj)		((obj)?(obj)->Release():0)	

// These two macros only work in the scope of ChRenderContext
#define ChNrSetDefaultTextureColors(n)				m_D3DRM->SetDefaultTextureColors(n)
#define ChNrSetDefaultTextureShades(n)				m_D3DRM->SetDefaultTextureShades(n)


#endif // 3DR, etc.

#define ChNrVal	ChNrValue

#if (defined(CH_USE_RLAB)|| defined(CH_USE_D3D))
template <class aType, class anArrayType>
inline aType &GetElement(anArrayType &ary, unsigned int index, aType &elt)
{
	#if (defined(CH_USE_RLAB))
	return (elt = ary[index]);
	#elif defined(CH_USE_D3D)
	ary->GetElement(DWORD(index), &elt);
	return elt;
	#endif
}
#endif

#endif	// ChGrRend_h
