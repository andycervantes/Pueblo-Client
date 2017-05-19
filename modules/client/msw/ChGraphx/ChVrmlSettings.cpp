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

	Implementation for the ChGraphicMaze class, which is used to display VRML.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChVrmlSettings.cpp,v 2.5 1996/09/12 19:09:48 pritham Exp $

#include "grheader.h"

#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN ) && !defined( CH_PUEBLO_PLUGIN )
#include "resource.h"
#else
#include "vwrres.h"
#endif

#include <ChReg.h>

#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
#include <ChCore.h>
#include "ChGrMod.h"
#endif
#include <ChHTTP.h>
#include <ChUtil.h>


#include "ChMaze.h"
#include "ChMazCam.h"


#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

#define NOT_IMPLEMENTED	TRACE2("Function not implemented, file %s: line %s.", __FILE__, __LINE__)

/*----------------------------------------------------------------------------
	ChVrmlSettings class
----------------------------------------------------------------------------*/
ChVrmlSettings* ChVrmlSettings::SetRegistry(const string& strCompanyName, const string& strProduct,
			const string& strGroup)
{
	m_strCompanyName = strCompanyName;
	m_strProduct= strProduct;
	m_strGroup = strGroup;
	if(strCompanyName.IsEmpty())
	{
		m_strCompanyName = CH_COMPANY_NAME;
	}
	if(strProduct.IsEmpty())
	{
		m_strProduct = CH_PRODUCT_NAME;
	}
	return this;
};

void ChVrmlSettings::ReadPreferences(const string& strCompanyName, const string& strProduct,
						const string& strGroup)
{
	chint16			sSetting;
	SetRegistry(strCompanyName, strProduct, strGroup);	 	// Current registry

	
	ChRegistry	reg(m_strCompanyName, m_strProduct, m_strGroup);
	ChRegistry	*pReg = &reg; 


											/* This code assumes that the
												ChShadingLevel enum values are
												be the same as the indices of
												the corresponding elements in
												the preferences dialog */

	pReg->Read( GR_PREFS_RENDER_QUALITY, sSetting, (chint16)defaultShading );
	m_renderQuality = (ChShadingLevel)sSetting;

	// sanity check
	if ( m_renderQuality < defaultShading || m_renderQuality >= invalidShadingLevel )
	{
	 	m_renderQuality = defaultShading;
	}

	pReg->Read( GR_PREFS_RENDER_QUALITY_MOVING, sSetting,
				(chint16)flatShading );
	m_moveRenderQuality = (ChShadingLevel)sSetting;	  

	// sanity check
	if ( m_moveRenderQuality < defaultShading || m_moveRenderQuality >= invalidShadingLevel )
	{
	 	m_moveRenderQuality = flatShading;
	}




	pReg->ReadBool( GR_PREFS_DRAW_MOVE_VECTOR, m_boolMoveVector,
					GR_PREFS_DRAW_MOVE_VECTOR_DEF );

	pReg->ReadBool( GR_PREFS_DRAW_SCALE_PAT, m_boolScaleTextures,
					GR_PREFS_DRAW_SCALE_PAT_DEF );

	chint16	sBright;		// scaled by 100, as int
	pReg->Read( GR_PREFS_HEADLIGHT_BRIGHTNESS, sBright,
					GR_PREFS_HEADLIGHT_BRIGHTNESS_DEF );
	m_fHeadlightBrightness = peg(float(sBright)/100., 0., 1.0);

	pReg->Read( GR_PREFS_VIEWER_MODE, sSetting,	(chint16)walk );
	m_viewerMode = (Ch3DViewerMode)sSetting;

	pReg->Read( GR_PREFS_ASCII_TEXT_QUALITY, sSetting,	(chint16)GR_PREFS_ASCII_TEXT_QUALITY_DEF );
	m_iAsciiTextQuality = (Ch3DViewerMode)sSetting;

	pReg->ReadBool( GR_PREFS_HEADLIGHT_ON, m_boolHeadlightOn, true );

	pReg->Read( GR_PREFS_COLLISION_MODE, sSetting,	(chint16)GR_PREFS_COLLISION_MODE_DEF );
	m_collisionMode = (Ch3DCollisionMode)sSetting;
	
	// sanity check
	if(m_collisionMode < 0 || m_collisionMode >= collisionModeCount)
	{
		m_collisionMode = GR_PREFS_COLLISION_MODE_DEF;
	}

	pReg->ReadBool( GR_PREFS_COLLISION_ALARM, m_boolCollisionAlarm, GR_PREFS_COLLISION_ALARM_DEF );

	pReg->Read( GR_PREFS_RENDER_OPTIMIZATION, sSetting, (chint16)GR_PREFS_RENDER_OPTIMIZATION_DEF );
	m_optimization = (ChRenderOptimization)sSetting;

	// sanity check
	if ( m_optimization < 0 || m_optimization >= renderOptimizationCount )
	{
	 	m_optimization = GR_PREFS_RENDER_OPTIMIZATION_DEF;
	}

}

bool ChVrmlSettings::UpdatePreferences( bool boolMoveVector,
										bool boolScaleTextures,
										ChShadingLevel renderQuality,
										ChShadingLevel moveRenderQuality,
										float fHeadlight,
										int iAsciiTextQuality )
{
									/* return true if anything changed */
	chuint32 whatChanged =
						((m_boolMoveVector != boolMoveVector) ? moveVector : 0) |
						((m_boolScaleTextures != boolScaleTextures) ? scaleTextures : 0) |
						((m_renderQuality != renderQuality) ? renderQuality : 0) |
						((m_moveRenderQuality != moveRenderQuality) ? moveRenderQuality : 0) |
						((m_fHeadlightBrightness != fHeadlight) ? headlightBrightness : 0) |
						((m_iAsciiTextQuality != iAsciiTextQuality) ? asciiTextQuality : 0);
	bool boolChanged = !!whatChanged;

	m_boolMoveVector = boolMoveVector;
	m_boolScaleTextures = boolScaleTextures;
	m_renderQuality = renderQuality;
	m_moveRenderQuality = moveRenderQuality;
	m_fHeadlightBrightness = fHeadlight;
	m_iAsciiTextQuality = iAsciiTextQuality;

	if(boolChanged) Notify(whatChanged);

	return boolChanged;

}

bool ChVrmlSettings::UpdatePreferences( bool boolMoveVector,
										bool boolScaleTextures,
										ChShadingLevel renderQuality,
										ChShadingLevel moveRenderQuality,
										float fHeadlight,
										int iAsciiTextQuality,
										bool boolCollisionAlarm )
{
	chuint32 whatChanged =
						((m_boolMoveVector != boolMoveVector) ? moveVector : 0) |
						((m_boolScaleTextures != boolScaleTextures) ? scaleTextures : 0) |
						((m_renderQuality != renderQuality) ? renderQuality : 0) |
						((m_moveRenderQuality != moveRenderQuality) ? moveRenderQuality : 0) |
						((m_fHeadlightBrightness != fHeadlight) ? headlightBrightness : 0) |
						((m_iAsciiTextQuality != iAsciiTextQuality) ? asciiTextQuality : 0) |
						((m_boolCollisionAlarm != boolCollisionAlarm) ? collisionAlarm  : 0);
									/* return true if anything changed */
	bool boolChanged = !!whatChanged;

	m_boolMoveVector = boolMoveVector;
	m_boolScaleTextures = boolScaleTextures;
	m_renderQuality = renderQuality;
	m_moveRenderQuality = moveRenderQuality;
	m_fHeadlightBrightness = fHeadlight;
	m_iAsciiTextQuality = iAsciiTextQuality;
	m_boolCollisionAlarm = boolCollisionAlarm;

	if(boolChanged) Notify(whatChanged);

	return boolChanged;

}

ChVrmlSettings*  ChVrmlSettings::SetHeadlightBrightness(ChRegistry &reg, float fHeadlightBrightness)
{	 
														   // Test might fail more often than we 
	if(m_fHeadlightBrightness != fHeadlightBrightness)	   // need, but do we really care?  														
	{
		m_fHeadlightBrightness = fHeadlightBrightness;
			// scaled by 100, as int
		int iBright = m_fHeadlightBrightness * 100;
		iBright = peg(iBright, 0, 100);
		reg.Write( GR_PREFS_HEADLIGHT_BRIGHTNESS, iBright );
		Notify(headlightBrightness);
	}
	return this;
}

ChVrmlSettings*  ChVrmlSettings::SetHeadlightSwitch(ChRegistry &reg, bool headlightOn)
{	 
											
	if(m_boolHeadlightOn != headlightOn)	    														
	{
		m_boolHeadlightOn = headlightOn;
		reg.WriteBool( GR_PREFS_HEADLIGHT_ON, m_boolHeadlightOn );
		Notify(headlightSwitch);
	}
	return this;
}

ChVrmlSettings*  ChVrmlSettings::SetRenderQuality(ChRegistry &reg, ChShadingLevel newRenderQuality)
{
	if (newRenderQuality != m_renderQuality)
	{
		chint16			sSetting;
		m_renderQuality = newRenderQuality;
		sSetting = (chint16)m_renderQuality;
		reg.Write( GR_PREFS_RENDER_QUALITY, sSetting );
		Notify(renderQuality);
	}
	return this;
}

ChVrmlSettings*  ChVrmlSettings::SetMoveRenderQuality(ChRegistry &reg, ChShadingLevel newMoveRenderQuality)
{	
	if (newMoveRenderQuality != m_moveRenderQuality)
	{
		chint16			sSetting;
		m_moveRenderQuality = newMoveRenderQuality;
		sSetting = (chint16)m_moveRenderQuality;
		reg.Write( GR_PREFS_RENDER_QUALITY_MOVING, sSetting );
		Notify(moveRenderQuality);
	}
	return this;
}

ChVrmlSettings*  ChVrmlSettings::SetRenderOptimization(ChRegistry &reg, ChRenderOptimization	optimization)
{	
	if (optimization != m_optimization)
	{
		chint16			sSetting;
		m_optimization = optimization;
		sSetting = (chint16)m_optimization;
		reg.Write( GR_PREFS_RENDER_OPTIMIZATION, sSetting );
		Notify(renderOptimization);
	}
	return this;
}

ChVrmlSettings*  ChVrmlSettings::SetMoveVector(ChRegistry &reg, bool boolMoveVector)
{		
	m_boolMoveVector = boolMoveVector;
	reg.WriteBool( GR_PREFS_DRAW_MOVE_VECTOR, m_boolMoveVector );

	Notify(moveVector);
	return this;
}

ChVrmlSettings*  ChVrmlSettings::SetScaleTextures(ChRegistry &reg, bool boolScaleTextures)
{	
	m_boolScaleTextures = boolScaleTextures;
	reg.WriteBool( GR_PREFS_DRAW_SCALE_PAT, m_boolScaleTextures );
	Notify(scaleTextures);
	return this;
}

ChVrmlSettings*  ChVrmlSettings::SetViewerMode(ChRegistry &reg, Ch3DViewerMode newViewerMode)
{	
	if (m_viewerMode != newViewerMode)
	{
		chint16			sSetting;
		m_viewerMode = newViewerMode;
		sSetting = (chint16)m_viewerMode;
		reg.Write( GR_PREFS_VIEWER_MODE, sSetting );
	}
	Notify(ChVrmlSettings::viewerMode);
	return this;
}

ChVrmlSettings*  ChVrmlSettings::SetAsciiTextQuality(ChRegistry &reg, int iAsciiTextQuality)
{	
	if (m_iAsciiTextQuality != iAsciiTextQuality)
	{
		chint16			sSetting;
		m_iAsciiTextQuality = iAsciiTextQuality;
		sSetting = (chint16)iAsciiTextQuality;
		reg.Write( GR_PREFS_ASCII_TEXT_QUALITY, sSetting );
	}
	Notify(asciiTextQuality);
	return this;
}

ChVrmlSettings* ChVrmlSettings::SetCollisionMode(ChRegistry &reg, Ch3DCollisionMode newCollisionMode)
{	
	if (m_collisionMode != newCollisionMode)
	{
		chint16			sSetting;
		m_collisionMode = newCollisionMode;
		sSetting = (chint16)newCollisionMode;
		reg.Write( GR_PREFS_COLLISION_MODE, sSetting );
	}
	Notify(collisionMode);
	return this;
}

ChVrmlSettings* ChVrmlSettings::SetCollisionAlarm(ChRegistry &reg, bool boolCollisionAlarm)
{	
	if (m_boolCollisionAlarm != boolCollisionAlarm)
	{
		m_boolCollisionAlarm = boolCollisionAlarm;
		reg.WriteBool( GR_PREFS_COLLISION_ALARM, m_boolCollisionAlarm); 
	}
	Notify(collisionAlarm);
	return this;
}


ChVrmlSettings* ChVrmlSettings::SetHeadlightBrightness( float fHeadlightBrightness)
{
	ASSERT(!m_strGroup.IsEmpty());
	ChRegistry	reg(m_strCompanyName, m_strProduct, m_strGroup); 

	return 	SetHeadlightBrightness( reg, fHeadlightBrightness);
}
ChVrmlSettings* ChVrmlSettings::SetRenderQuality( ChShadingLevel renderQuality)
{
	ASSERT(!m_strGroup.IsEmpty());
	ChRegistry	reg(m_strCompanyName, m_strProduct, m_strGroup); 

	return 	SetRenderQuality( reg, renderQuality);
}
ChVrmlSettings* ChVrmlSettings::SetMoveRenderQuality( ChShadingLevel moveRenderQuality)
{
	ASSERT(!m_strGroup.IsEmpty());
	ChRegistry	reg(m_strCompanyName, m_strProduct, m_strGroup); 

	return 	SetMoveRenderQuality( reg, moveRenderQuality);
}
ChVrmlSettings*  ChVrmlSettings::SetRenderOptimization( ChRenderOptimization optimization)
{
	ASSERT(!m_strGroup.IsEmpty());
	ChRegistry	reg(m_strCompanyName, m_strProduct, m_strGroup); 

	return 	SetRenderOptimization( reg, optimization );
}

ChVrmlSettings* ChVrmlSettings::SetMoveVector( bool boolMoveVector)
{
	ASSERT(!m_strGroup.IsEmpty());
	ChRegistry	reg(m_strCompanyName, m_strProduct, m_strGroup); 

	return 	SetMoveVector( reg, boolMoveVector);
}
ChVrmlSettings* ChVrmlSettings::SetScaleTextures( bool boolScaleTextures)
{
	ASSERT(!m_strGroup.IsEmpty());
	ChRegistry	reg(m_strCompanyName, m_strProduct, m_strGroup); 

	return 	SetScaleTextures( reg, boolScaleTextures);
}
ChVrmlSettings* ChVrmlSettings::SetViewerMode( Ch3DViewerMode viewerMode)
{
	ASSERT(!m_strGroup.IsEmpty());
	ChRegistry	reg(m_strCompanyName, m_strProduct, m_strGroup); 

	return 	SetViewerMode( reg, viewerMode);
}
ChVrmlSettings* ChVrmlSettings::SetAsciiTextQuality( int iAsciiTextQuality)
{
	ASSERT(!m_strGroup.IsEmpty());
	ChRegistry	reg(m_strCompanyName, m_strProduct, m_strGroup); 

	return 	SetAsciiTextQuality( reg, iAsciiTextQuality);
}
ChVrmlSettings* ChVrmlSettings::SetHeadlightSwitch( bool headlightOn)
{
	ASSERT(!m_strGroup.IsEmpty());
	ChRegistry	reg(m_strCompanyName, m_strProduct, m_strGroup); 

	return 	SetHeadlightSwitch( reg, headlightOn);
}

ChVrmlSettings* ChVrmlSettings::SetCollisionMode(Ch3DCollisionMode collisionMode)
{
	ASSERT(!m_strGroup.IsEmpty());
	ChRegistry	reg(m_strCompanyName, m_strProduct, m_strGroup); 

	return 	SetCollisionMode( reg, collisionMode);
}

ChVrmlSettings* ChVrmlSettings::SetCollisionAlarm(bool boolCollisionAlarm)
{
	ASSERT(!m_strGroup.IsEmpty());
	ChRegistry	reg(m_strCompanyName, m_strProduct, m_strGroup); 

	return 	SetCollisionAlarm( reg, boolCollisionAlarm);
}


// If VRML window is attached to a Non-MFC application then  ChVrmlSettings
// should be derived and the virtual method Notify should notify the VRML 
// window of the changes.
void ChVrmlSettings::Notify(chuint32 which)
{
	#if !defined(CH_VRML_PLUGIN )
	AfxGetMainWnd()->SendMessageToDescendants( WM_VRML_PREF_CHANGE, which);
	#else
	// Note plugin derives a new class from  ChVrmlSettings and overides this method
	// to handle changes.
	#endif
};

