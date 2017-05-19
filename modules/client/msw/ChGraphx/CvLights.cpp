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

	Implementation for the ChQvLightInstance classes for  Intel 3DR.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvLights.cpp,v 2.17 1996/06/30 19:44:19 jimd Exp $

#include "grheader.h"

#include <QvInfo.h>
#include <QvState.h>
#include "ChMaze.h"
#include "ChMazDep.h"
#include "CvTrnsfm.h"
#include "CvNormal.h"
#include "CvConvrt.h"
#include "CvInstnc.h"
#include "CvType.h"
#include "ChRenderData.h"

//#define D3D_FLIP_LIGHTS		1

ChQvLightInstance::ChQvLightInstance()
{ }
ChQvInstance* ChQvLightInstance::Attach(QvNode *pNode, ChQvBuildState *pState)
{
	m_pNode = pNode;
	ChQvRenderBaseData *pRenderData =  (ChQvRenderBaseData *)(pNode->GetRenderData());

	// Hook us together
	pRenderData->Add(this);
	m_pRenderData = pRenderData;

	#if defined(CH_USE_OPENGL)
	// Open GL

	#elif defined(CH_USE_3DR)
	// Intel 3DR
		// We DO NOT add this to the instance tree, 
		// but we DO add it to the list of lights
	pState->GetView()->GetRenderContext()->Add(this);

	#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	// Microsoft Reality Lab
		// We -DO- add this to the instance tree, 
		// but we DON'T add it to the list of lights

	ChQvGroupInstance *pParent =	pState->GetCurrentParent();
	if(pParent) pParent->Add(this);

	#endif

	Init(pState);
	#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
	Build(GetContext());
	#endif

	return this;
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
void ChQvLightInstance::CreateFrame(GxVec3f &loc,  GxVec3f &dir )
{
	ChQvInstance::CreateFrame();		// Create one based on our qv transform
											// Now rotate z to lookdir
											// Translate, to put in right place in object coords
	//ChNrFrameAddTranslation(m_frame, CombineBefore, loc.x(), loc.y(), loc.z());
	ChNrFrameAddTranslation(m_frame, CombineBefore, loc.x(), loc.y(), loc.z());

	GxTransform3Wf transform;
	GxVec3f backDir = -dir;
	//transform.LookAt( backDir );
	#if D3D_FLIP_LIGHTS && (defined(CH_USE_D3D))
	dir = -dir;
	#endif
	GxVec3f normalizedDir(dir);
	normalizedDir.normalize();

	transform.LookAt( normalizedDir );
	ChNrFrameAddTransform(m_frame, CombineBefore, *transform.GetMatrix());
}
#endif


ChQvSpotLightInstance::ChQvSpotLightInstance()
{

}


#if defined(CH_USE_3DR)
bool ChQvSpotLightInstance::traverse(ChRenderContext *pContext)
{
	bool boolSuccess = false;

	int iLightNum = pContext->GetNextLight();	  
	G3dHandle_t hGC = pContext->GetGC();
  	QvSpotLight *pNode = (QvSpotLight *)m_pNode;

	if(iLightNum >= 0)
	{
		boolSuccess = true;
		Float_t		dimmer = 	int(pNode->on.value) ? 1. : 0.;
		float fIntensity = pNode->intensity.value;
		fIntensity = min(fIntensity, 1.);
		fIntensity = max(fIntensity, 0.);
		if(dimmer > 0. && fIntensity > 0.)
		{
			pContext->TurnOnALight();
			ColorF_t	diffuse;	Qv2Native(pNode->color, diffuse);
			ColorF_t	specular;	Qv2Native(pNode->color,specular) ;
			ColorF_t	ambient = {0.,0.,0.};
			// Transform light from model (vrml) to world coords for 3dr
			GxVec3f	dir, loc;

			Qv2Gx(pNode->location,loc);
			loc = Transform(loc);
			PointFW_t	loc3dr; 
			CopyPoint(loc, loc3dr);
			loc3dr.w = 1.;				 // noninfinite light
				
			Qv2Gx(pNode->direction, dir);
			dir = Transform(dir);
	 		PointF_t	dir3dr;
			CopyPoint(dir, dir3dr);

			Float_t		expon	=	Float_t(pNode->dropOffRate.value);
			Float_t		spotAngle	=	Float_t(pNode->cutOffAngle.value);
	
			specular.r *= fIntensity;
			specular.g *= fIntensity;
			specular.b *= fIntensity;

			diffuse.r *= fIntensity;
			diffuse.g *= fIntensity;
			diffuse.b *= fIntensity;

			G3dSetLight( hGC,  iLightNum, G3DL_DIMMER,    	(Float_t *)&dimmer     );			
			G3dSetLight( hGC,  iLightNum, G3DL_AMBIENT, 	(Float_t *)&ambient  );			
			G3dSetLight( hGC,  iLightNum, G3DL_DIFFUSE,  	(Float_t *)&diffuse   );			
			G3dSetLight( hGC,  iLightNum, G3DL_SPECULAR, 	(Float_t *)&specular  );			
			G3dSetLight( hGC,  iLightNum, G3DL_SPOT_EXP,     	(Float_t *)&expon      );			
			G3dSetLight( hGC,  iLightNum, G3DL_SPOT_ANGLE,  (Float_t *)&spotAngle     );

			G3dSetLight( hGC,  iLightNum, G3DL_DIRECTION,  (Float_t *)&dir3dr  );			
			G3dSetLight( hGC,  iLightNum, G3DL_LOCATION,  (Float_t *)&loc3dr  );
			//G3dSetLight( hGC,  iLightNum, G3DL_ATTENA,  (Float_t *)&atten  );
			//G3dSetLight( hGC,  iLightNum, G3DL_ATTENB,  (Float_t *)&atten  );
			//G3dSetLight( hGC,  iLightNum, G3DL_ATTENC,  (Float_t *)&atten  );
		}
	}
	return boolSuccess;
}
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
void ChQvSpotLightInstance::Build(ChRenderContext *pRC)
{
  	QvSpotLight *pNode = (QvSpotLight *)m_pNode;
	float fIntensity = peg(pNode->intensity.value, float(0.), float(1.));
	if(pNode->on.value && fIntensity > 0.)
	{
		GxVec3f	dir(0,0,1), loc(0,0,0);

		Qv2Gx(pNode->location,loc);

		Qv2Gx(pNode->direction, dir);
		ChColor	color;	Qv2Native(pNode->color, color) ;

		color *= fIntensity;

		CreateFrame(loc, dir);
		float		spotAngle	=	float(pNode->cutOffAngle.value);
		m_light = pRC->CreateLight(ChNrLightSpot, *(color.GetNative()));
		ChNrFrameAddLight(m_frame, m_light);
		D3DRelease(m_light);
		float factor = .3;										// TODO fix to use exponent
		ChNrLightSetUmbra(m_light, spotAngle * factor);
		ChNrLightSetPenumbra(m_light, spotAngle);
	}
};
#endif



ChQvPointLightInstance::ChQvPointLightInstance()
{
}

#if defined(CH_USE_3DR)
bool ChQvPointLightInstance::traverse(ChRenderContext *pContext)
{
	bool boolSuccess = false;
	int iLightNum = pContext->GetNextLight();	  
	G3dHandle_t hGC = pContext->GetGC();
  	QvPointLight *pNode = (QvPointLight *)m_pNode;

	if(iLightNum >= 0)
	{
		boolSuccess = true;
		Float_t		dimmer = 	int(pNode->on.value) ? 1. : 0.;
		float fIntensity = pNode->intensity.value;
		fIntensity = min(fIntensity, 1.);
		fIntensity = max(fIntensity, 0.);
		if(dimmer > 0. && fIntensity > 0.)
		{
			pContext->TurnOnALight();
			ColorFA_t	diffuse;	Qv2Native(pNode->color, diffuse);
			ColorF_t	specular;	Qv2Native(pNode->color,specular) ;
	 		ColorF_t	ambient = {0.,0.,0.};

			// Transform light from model (vrml) to world coords for 3dr
			GxVec3f	dir(0, 0, 0);	  // not a spot
			GxVec3f loc;
	 		PointF_t	dir3dr;
			CopyPoint(dir, dir3dr);

			Qv2Gx(pNode->location,loc);
			loc = Transform(loc);
			PointFW_t	loc3dr; 
			CopyPoint(loc, loc3dr);
			loc3dr.w = 1.;				 // noninfinite light
		
			static Float_t attena = 1.0;
			static Float_t attenb = 0.0;
			static Float_t attenc = 0.0;

			specular.r *= fIntensity;
			specular.g *= fIntensity;
			specular.b *= fIntensity;

			diffuse.r *= fIntensity;
			diffuse.g *= fIntensity;
			diffuse.b *= fIntensity;


			G3dSetLight( hGC,  iLightNum, G3DL_DIMMER,    	(Float_t *)&dimmer     );			
			G3dSetLight( hGC,  iLightNum, G3DL_AMBIENT, 	(Float_t *)&ambient  );			
			G3dSetLight( hGC,  iLightNum, G3DL_DIFFUSE,  	(Float_t *)&diffuse   );			
			G3dSetLight( hGC,  iLightNum, G3DL_SPECULAR, 	(Float_t *)&specular  );			
			G3dSetLight( hGC,  iLightNum, G3DL_DIRECTION,  (Float_t *)&dir3dr  );			
			G3dSetLight( hGC,  iLightNum, G3DL_LOCATION,  (Float_t *)&loc3dr  );
			//G3dSetLight( hGC,  iLightNum, G3DL_ATTENA,  (Float_t *)&attena  );
			//G3dSetLight( hGC,  iLightNum, G3DL_ATTENB,  (Float_t *)&attenb  );
			//G3dSetLight( hGC,  iLightNum, G3DL_ATTENC,  (Float_t *)&attenc  );
		}
	}			
 	return boolSuccess;

}
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
void ChQvPointLightInstance::Build(ChRenderContext *pRC)
{
  	QvPointLight *pNode = (QvPointLight *)m_pNode;
	float fIntensity = peg(pNode->intensity.value, float(0.), float(1.));
	if(pNode->on.value && fIntensity > 0.)
	{
		GxVec3f	dir(0,0,1), loc(0,0,0);

		Qv2Gx(pNode->location,loc);

		ChColor	color;	Qv2Native(pNode->color, color) ;

		color *= fIntensity;

		CreateFrame(loc, dir);
		m_light = pRC->CreateLight(ChNrLightPoint, *(color.GetNative()));
		#if defined(_DEBUG)
		ChNrValue cons = ChNrLightGetConstantAttenuation(m_light);
		ChNrValue lin = ChNrLightGetLinearAttenuation(m_light);
		ChNrValue quad = ChNrLightGetQuadraticAttenuation(m_light);
		#endif
		ChNrFrameAddLight(m_frame, m_light);
		D3DRelease(m_light);

	}
};

#endif


ChQvDirectionalLightInstance::ChQvDirectionalLightInstance()
{ }

#if defined(CH_USE_3DR)
bool ChQvDirectionalLightInstance::traverse(ChRenderContext *pContext)
{ 
	bool boolSuccess = false;
	int iLightNum = pContext->GetNextLight();	  
	G3dHandle_t hGC = pContext->GetGC();
  	QvDirectionalLight *pNode = (QvDirectionalLight *)m_pNode;

	// We don't have directional lights in 3dr, so put a spot light very far away,
	// and leave it wide open angle-wise, with no attenuation
	if(iLightNum >= 0)
	{
		boolSuccess = true;
		Float_t		dimmer = 	int(pNode->on.value) ? 1. : 0.;
		float fIntensity = pNode->intensity.value;
		fIntensity = min(fIntensity, 1.);
		fIntensity = max(fIntensity, 0.);
		if(dimmer > 0. && fIntensity > 0.)
		{
			pContext->TurnOnALight();
			ColorFA_t	diffuse;		Qv2Native(pNode->color, diffuse);
			ColorF_t	specular;		Qv2Native(pNode->color,specular) ;

			// Transform light from model (vrml) to world coords for 3dr

			GxVec3f	dir;
			Qv2Gx(pNode->direction, dir);
			dir = Transform(dir);

			Float_t		infinity	=	1.e6;	// close enough (or far enough) for us
			PointFW_t	loc3dr;
			PointF_t	dir3dr;
			CopyPoint(dir, dir3dr);
			loc3dr.x = -dir.x() * infinity;
			loc3dr.y = -dir.y() * infinity;
			loc3dr.z = -dir.z() * infinity;
			loc3dr.w = 0.;				 // infinite light
	 		ColorF_t	ambient = {0.,0.,0.};
												 
			Float_t exponent	= 0.00;	   // no fall off
			Float_t angle		= 1.57;	   // leave the barn doors open
			Float_t attena 		= 1.00;	   // no attenuation
			Float_t attenb 		= 0.00;
			Float_t attenc 		= 0.00;

			specular.r *= fIntensity;
			specular.g *= fIntensity;
			specular.b *= fIntensity;

			diffuse.r *= fIntensity;
			diffuse.g *= fIntensity;
			diffuse.b *= fIntensity;


			G3dSetLight( hGC, iLightNum, G3DL_DIMMER,   	(Float_t *)&dimmer );			
			G3dSetLight( hGC, iLightNum, G3DL_AMBIENT, 		(Float_t *)&ambient );			
			G3dSetLight( hGC, iLightNum, G3DL_DIFFUSE,  	(Float_t *)&diffuse );			
			G3dSetLight( hGC, iLightNum, G3DL_SPECULAR, 	(Float_t *)&specular );			
			G3dSetLight( hGC, iLightNum, G3DL_DIRECTION,	(Float_t *)&dir3dr );			
			G3dSetLight( hGC, iLightNum, G3DL_LOCATION,		(Float_t *)&loc3dr );
			G3dSetLight( hGC, iLightNum, G3DL_ATTENA,  		(Float_t *)&attena );
			G3dSetLight( hGC, iLightNum, G3DL_ATTENB,  		(Float_t *)&attenb );
			G3dSetLight( hGC, iLightNum, G3DL_ATTENC,  		(Float_t *)&attenc );
			G3dSetLight( hGC, iLightNum, G3DL_SPOT_EXP, 	(Float_t *)&exponent );
			G3dSetLight( hGC, iLightNum, G3DL_SPOT_ANGLE,	(Float_t *)&angle );
		}
	}			
	return boolSuccess;
}
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
void ChQvDirectionalLightInstance::Build(ChRenderContext *pRC)
{
  	QvDirectionalLight *pNode = (QvDirectionalLight *)m_pNode;
	float fIntensity = peg(pNode->intensity.value, float(0.), float(1.));
	if(pNode->on.value && fIntensity > 0.)
	{
		GxVec3f	dir(0,0,1), loc(0,0,0);

		Qv2Gx(pNode->direction, dir);
		ChColor	color;	Qv2Native(pNode->color, color) ;

		color *= fIntensity;

		CreateFrame(loc, dir);
		m_light = pRC->CreateLight(ChNrLightDirectional, *(color.GetNative()));
		ChNrFrameAddLight(m_frame, m_light);
		D3DRelease(m_light);
	}
};

#endif

#if defined(CH_USE_3DR)
void ChRenderContext::CreateHeadlight( GxVec3f& gloc, GxVec3f& gdir, QvState* state )
{
			  // TODO Fix this
	if(((ChMazeWnd*)GetWnd())->IsHeadlightOn())
	{
		//long wLightNum = ((ChQvState*)state)->NextLight();	  
		int wLightNum = GetNextLight();	  
		TurnOnALight();

		if( ((ChQvState*)state)->GetType() ==  ChQvState::draw)
		{
			G3dHandle_t hGC = ((ChQvState*)state)->GetView()->GetGC();
	  

			if(wLightNum < G3D_MAX_LIGHTS)
			{
				PointF_t dir = {gdir.x(), gdir.y(), gdir.z()};
				PointFW_t loc = {gloc.x(), gloc.y(), gloc.z()};
				Float_t		dimmer = 1.;
				float fIntensity = ((ChQvState*)state)->GetView()->GetHeadlightBrightness();
				ColorFA_t	diffuse 	= {1, 1, 1};		
				ColorF_t	specular 	= {1, 1, 1};
		 		ColorF_t	ambient 	= {0.,0.,0.};
				loc.w = 0.;				 // infinite light

				const float infinity_hack=10000.;
				loc.x -= dir.x * infinity_hack;
				loc.y -= dir.y * infinity_hack;
				loc.z -= dir.z * infinity_hack;
													 
				Float_t exponent	= 0.00;	   // no fall off
				Float_t angle		= 3.14 / 2;// leave the barn doors open; 180 deg beam
				Float_t attena 		= 1.00;	   // no attenuation
				Float_t attenb 		= 0.00;
				Float_t attenc 		= 0.00;

				specular.r *= fIntensity;
				specular.g *= fIntensity;
				specular.b *= fIntensity;

				diffuse.r *= fIntensity;
				diffuse.g *= fIntensity;
				diffuse.b *= fIntensity;


				G3dSetLight( hGC, wLightNum, G3DL_DIMMER,   	(Float_t *)&dimmer );			
				G3dSetLight( hGC, wLightNum, G3DL_AMBIENT, 		(Float_t *)&ambient );			
				G3dSetLight( hGC, wLightNum, G3DL_DIFFUSE,  	(Float_t *)&diffuse );			
				G3dSetLight( hGC, wLightNum, G3DL_SPECULAR, 	(Float_t *)&specular );			
				G3dSetLight( hGC, wLightNum, G3DL_DIRECTION,	(Float_t *)&dir );			
				G3dSetLight( hGC, wLightNum, G3DL_LOCATION,		(Float_t *)&loc );
				G3dSetLight( hGC, wLightNum, G3DL_ATTENA,  		(Float_t *)&attena );
				G3dSetLight( hGC, wLightNum, G3DL_ATTENB,  		(Float_t *)&attenb );
				G3dSetLight( hGC, wLightNum, G3DL_ATTENC,  		(Float_t *)&attenc );
				G3dSetLight( hGC, wLightNum, G3DL_SPOT_EXP, 	(Float_t *)&exponent );
				G3dSetLight( hGC, wLightNum, G3DL_SPOT_ANGLE,	(Float_t *)&angle );
			}			
		}
	}
}
#elif (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
void HeadlightDestroyCallback(ChNrObject obj, void * arg)
{
	ChRenderContext *pRC = (ChRenderContext *)arg;
	pRC->DestroyHeadlight();
	//TRACE("Headlight Destroyed\n");

}

#define MAKE_IT_BRIGHT	1
//#define MAKE_IT_SUPER_BRIGHT	1

void ChRenderContext::CreateHeadlight(  )
{
	LockScene();
	#if 0
	if(m_cameraFrame && m_headlightFrame)
	{
		ChNrFrameRemoveChild(m_cameraFrame, m_headlightFrame);
		m_headlightFrame = 0;
	}
	#endif
	if(m_cameraFrame )
	{
		if(!m_headlightFrame)
		{
			m_headlightFrame = CreateFrame(m_cameraFrame);
			if(m_headlightFrame)
			{
				ChNrObjectAddDestroyCallback(m_headlightFrame, HeadlightDestroyCallback, this);
				D3DRelease(m_headlightFrame);

				TRACE("Headlight Created\n");

				#if defined(D3D_FLIP_LIGHTS) && defined(CH_USE_D3D)
				m_headlightFrame->AddRotation(CombineBefore, 0, 1, 0, 3.141593);
				#endif

				ChNrLightType type = ChNrLightDirectional; //  	 ChNrLightParallelPoint	ChNrLightPoint
				ChNrLight light1 = CreateLightRGB(type, ChNrVal(0.5), ChNrVal(0.5), ChNrVal(0.5));
			    ChNrFrameAddLight(m_headlightFrame, light1);
				D3DRelease(light1);
				#if 0 && defined(CH_USE_D3D)
				ChNrFrame frm = 0;
				HRESULT rval = light1->GetEnableFrame(&frm);
				rval = light1->SetEnableFrame(m_sceneFrame);
				D3DCOLOR color = light1->GetColor();
				#endif

				#if defined(MAKE_IT_BRIGHT)
				// Brighter light by ganging up beams
				ChNrLight light2 =	CreateLightRGB(type, ChNrVal(0.5), ChNrVal(0.5), ChNrVal(0.5));
				ChNrLight light3 =	CreateLightRGB(type, ChNrVal(0.5), ChNrVal(0.5), ChNrVal(0.5));
			    ChNrFrameAddLight(m_headlightFrame, light2);
			    ChNrFrameAddLight(m_headlightFrame, light3);
				D3DRelease(light2);
				D3DRelease(light3);
				#endif

				#if defined(MAKE_IT_SUPER_BRIGHT)
			    ChNrFrameAddLight(m_headlightFrame, CreateLightRGB(ChNrLightDirectional, ChNrVal(0.5), ChNrVal(0.5), ChNrVal(0.5)));
			    ChNrFrameAddLight(m_headlightFrame, CreateLightRGB(ChNrLightDirectional, ChNrVal(0.5), ChNrVal(0.5), ChNrVal(0.5)));
			    ChNrFrameAddLight(m_headlightFrame, CreateLightRGB(ChNrLightDirectional, ChNrVal(0.5), ChNrVal(0.5), ChNrVal(0.5)));
				#endif

				// Ambient light
			    ChNrLight light4 =	CreateLightRGB(ChNrLightAmbient, ChNrVal(0.5), ChNrVal(0.5), ChNrVal(0.5));
			    ChNrFrameAddLight(m_headlightFrame, light4);
				D3DRelease(light4);
			}
		}
		AdjustHeadlight();
	}
	UnlockScene();
}

void ChRenderContext::DestroyHeadlight( )
{
	m_headlightFrame = 0;
}

void ChRenderContext::AdjustHeadlight(  )
{
	ChNrLightArray	lights;
	int count;
	LockScene();
	if(GetWnd() && m_sceneFrame && m_headlightFrame)
	{
		ChNrFrameGetLights(m_headlightFrame, &count, &lights);

		#if defined(CH_USE_D3D)
		count = lights->GetSize();
		#endif

		if(count)
		{
			ChMazeWnd *pWnd = (ChMazeWnd *)GetWnd();
			float intensity = 	pWnd->GetHeadlightBrightness();
			int numLocal = 1;
			if(count > 1)
			{
				numLocal = count - 1;
			}
			//intensity  /= float(numLocal);	 // if more than 1, last is ammbient
			if(!pWnd->IsHeadlightOn()) intensity = 0;
			ChColor color(intensity,intensity,intensity);
    		ChNrLight elt;
			for(int j = 0; j < numLocal; j++)
			{
				ChNrLight light = GetElement(lights, (unsigned int)j, elt);
	    		ChNrLightSetColor( light, *(color.GetNative()) );
				D3DRelease(light);
			}
			if(count > 1)
			{
				float fillFactor = .21 * numLocal;

				#if defined(MAKE_IT_BRIGHT)
				//fillFactor *= 2;
				#endif
				ChNrLight light = GetElement(lights, (unsigned int)(count-1), elt);
				ChColor color(intensity * fillFactor,intensity * fillFactor,intensity * fillFactor);
	    		ChNrLightSetColor( light, *(color.GetNative()) );
				D3DRelease(light);
			}
		}
		ChNrFree(lights);
	}
	UnlockScene();
}

#endif

// end of file
