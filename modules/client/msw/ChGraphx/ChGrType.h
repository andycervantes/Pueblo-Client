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

	Declaration for the ChMazeWnd class, which is used to display
	3d graphics.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChGrType.h,v 2.21 1996/09/25 03:17:55 pritham Exp $

#if !defined( _CHGRTYPE_H )
#define _CHGRTYPE_H

#if defined( CH_MSW )
	#pragma warning( disable:4091 )
#endif	// defined( CH_MSW )





// Registered names for viewers, browsers, etc
// Standalone
#define CH_REG_VRML_BROWSER	"VR Scout"
// DDE Viewer app
#define CH_REG_VRML_VIEWER	"VR Scout"
// OCX Viewer control
#define CH_REG_VRML_OCX_VIEWER	"VR Scout OCX"

#if defined(CH_VRML_VIEWER)
	#if defined CH_USE_OCX
	#define	CH_VRML_PRODUCT_NAME	CH_REG_VRML_OCX_VIEWER
	#elif defined CH_USE_DDE
	#define	CH_VRML_PRODUCT_NAME	CH_REG_VRML_VIEWER
	#else
	#define	CH_VRML_PRODUCT_NAME	CH_REG_VRML_BROWSER
	#endif

#elif  defined( CH_VRML_PLUGIN )

	#define	CH_VRML_PRODUCT_NAME	"VR Scout Plug-In"

#elif  defined( CH_PUEBLO_PLUGIN )

	#define	CH_VRML_PRODUCT_NAME	"Pueblo Plug-In"

#else
	// Pueblo
	#define	CH_VRML_PRODUCT_NAME	CH_PRODUCT_NAME
#endif

#define CH_CONNECTION_GROUP         "Connection"
#define CH_VRML_HOME_PAGE			"Home Page"
#define CH_DEF_VRML_HOME_PAGE		""
/*----------------------------------------------------------------------------
	Typedefs and helper classes
----------------------------------------------------------------------------*/

typedef chuint32	ChGraphicPageID;	   // for tracking current page

											/* The following enum values must
												be the same as the indices of
												the corresponding elements in
												the preferences dialog */
#if defined(CH_USE_3DR)
#endif
typedef enum { defaultShading = 0, smoothShading, flatShading, noShading, wireFrame,
			   invalidShadingLevel	// this should always be the last value in the enum
			   					    // list, add any new values before this 	
			 } ChShadingLevel;

typedef enum { renderBetter = 0, renderFaster,  
				renderOptimizationCount	// this should always be the last value in the enum
			   					    // list, add any new values before this 	
			 } ChRenderOptimization;

typedef enum { walk = 0, fly, examine, viewerModeCount,
				none = -1 } Ch3DViewerMode;

typedef enum { collisionOff = 0, collisionOn, collisionModeCount, invalidCollisionMode = -1
	 } Ch3DCollisionMode;

// Renderer-dependent types
#if defined(CH_USE_3DR)
#define ChTextureHandle	Dword_t
#elif (defined(CH_USE_RLAB))
#define ChTextureHandle	RLTexture	   
#elif (defined(CH_USE_D3D))
#define ChTextureHandle	LPDIRECT3DRMTEXTURE	   
#elif defined(CH_USE_OPENGL)
#else
#define ChTextureHandle	chuint32
#endif

// Handy little template
template<class TYPE>
TYPE peg(const TYPE inval, const TYPE minVal, const TYPE maxVal)
{				    
	TYPE val = min(inval, maxVal);  
	val = max(val, minVal);
	return val;  
}

/*----------------------------------------------------------------------------
	Graphics Preferences registry group
----------------------------------------------------------------------------*/

#define GR_PREFS_GROUP						"Graphics module"
#define GR_PREFS_RENDER_OPTIMIZATION		"3D Rendering Optimization"
#define GR_PREFS_RENDER_OPTIMIZATION_DEF	renderFaster
#define GR_PREFS_RENDER_QUALITY				"3D Rendering Quality (normal)"
#define GR_PREFS_RENDER_QUALITY_MOVING		"3D Rendering Quality (moving)"
#define GR_PREFS_DRAW_MOVE_VECTOR			"Mouse movement line drawing"
#define GR_PREFS_DRAW_MOVE_VECTOR_DEF			true
#define GR_PREFS_DRAW_SCALE_PAT				"Scale large patterns"
#define GR_PREFS_DRAW_SCALE_PAT_DEF				true
#define GR_PREFS_HEADLIGHT_ON				"Headlight On"
#define GR_PREFS_HEADLIGHT_ON_DEF				false
#define GR_PREFS_HEADLIGHT_BRIGHTNESS		"Headlight Brightness"
#define GR_PREFS_HEADLIGHT_BRIGHTNESS_DEF		100
#define GR_PREFS_OVERRIDE_SCENE_MODE		"Override Scene Viewer Mode"
#define GR_PREFS_OVERRIDE_SCENE_MODE_DEF		false
#define GR_PREFS_VIEWER_MODE				"Viewer Mode"
#define GR_PREFS_VIEWER_MODE_DEF				0
#define GR_PREFS_ASCII_TEXT_QUALITY				"AsciiText Quality"
#define GR_PREFS_ASCII_TEXT_QUALITY_DEF			1
#define GR_PREFS_COLLISION_MODE					"Collision Mode"              
#define GR_PREFS_COLLISION_MODE_DEF				collisionOn              
#define GR_PREFS_COLLISION_ALARM	         	"Collision Alarm"
#define GR_PREFS_COLLISION_ALARM_DEF         	false
#if 0
#define GR_PREFS_OVERRIDE_COLLISION_MODE		"Override Collision Mode"
#define GR_PREFS_OVERRIDE_COLLISION_MODE_DEF  	false
#endif


                         
#endif	// !defined( _CHGRTYPE_H )
