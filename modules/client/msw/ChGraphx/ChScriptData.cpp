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

	Implementation for the ChRenderContext class for  Intel 3DR.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChScriptData.cpp,v 2.4 1996/06/27 03:43:46 jimd Exp $

#include "grheader.h"

#include "ChMaze.h"
#include "ChScriptData.h"
#include "CvInstnc.h"
#include "CvType.h"



class ScriptData
{
	public:

	ChQvScriptRenderData 	*	m_pData;
	ChQvInstance 			*	m_pTarget;

	ScriptData() : m_pData(0), m_pTarget(0) {};
	ScriptData(ChQvScriptRenderData *pData, ChQvInstance *pTarget) : 
		m_pData(pData), m_pTarget(pTarget)
			{};
};

// Statics






/* Types of script render data */

ChQvScriptRenderData::ChQvScriptRenderData(QvNode* pNode) : 
	ChQvRenderBaseData(pNode)
{
#if 0 && defined(CH_VRML_EVENTS)
	if(!m_pDispatcher)
	{
		m_pDispatcher = new	ChVrmlDispatcher;
		Init();
	}
#endif
};

void ChQvScriptRenderData::Init()
{
	ChQvRenderBaseData::Init();
#if 0 && defined(CH_VRML_EVENTS)

	AddVrmlDispatcher("set_rotation", SFRotation, OnSetRotation);
	AddVrmlDispatcher("set_translation", SFVec3f, OnSetTranslation);
	AddVrmlDispatcher("set_scaleFactor", SFVec3f, OnSetScaleFactor);
	AddVrmlDispatcher("set_scaleOrientation", SFRotation, OnSetScaleOrientation);
	AddVrmlDispatcher("set_center", SFVec3f, OnSetCenter);

#endif

};



ChQvScriptRenderData::~ChQvScriptRenderData()
{
}


void ChQvScriptRenderData::Term()
{
#if 0 && defined(CH_VRML_EVENTS)
	delete m_pDispatcher;
	m_pDispatcher = 0;
#endif
}

void ChQvScriptRenderData::AddInstance(ChQvInstance *pTarget)
{
}

/////////////////////////////////////////////////////////////////////////////////
ChQvSpinRenderData::ChQvSpinRenderData(QvNode* pNode) : 
	ChQvScriptRenderData(pNode), m_step(0)
{
#if 0 && defined(CH_VRML_EVENTS)
	if(!m_pDispatcher)
	{
		m_pDispatcher = new	ChVrmlDispatcher;
		Init();
	}
#endif
	QvNode *pObject = 0;
	string strType;
	int	iType = pNode->GetType(strType); 
	switch(iType)
	{			  // QvSpin is only script object supported so far
		case  typeQvSpin:
		{
			pObject = ((QvSpin*)pNode)->m_pObject;
			break;
		}
		default:
			break;
	}
	
	if(pObject)
	{						// Add this script to the object of its affection
		((ChQvRenderBaseData*)pObject->GetRenderData())->Add(this);	
	}
};

void ChQvSpinRenderData::Init()
{
	ChQvScriptRenderData::Init();
#if 0 && defined(CH_VRML_EVENTS)

	AddVrmlDispatcher("set_rotation", SFRotation, OnSetRotation);
	AddVrmlDispatcher("set_translation", SFVec3f, OnSetTranslation);
	AddVrmlDispatcher("set_scaleFactor", SFVec3f, OnSetScaleFactor);
	AddVrmlDispatcher("set_scaleOrientation", SFRotation, OnSetScaleOrientation);
	AddVrmlDispatcher("set_center", SFVec3f, OnSetCenter);

#endif

};



ChQvSpinRenderData::~ChQvSpinRenderData()
{
}


void ChQvSpinRenderData::Term()
{
#if 0 && defined(CH_VRML_EVENTS)
	delete m_pDispatcher;
	m_pDispatcher = 0;
#endif
}

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#if (defined(CH_USE_RLAB))
void SpinCallback(ChNrFrame frame, void * arg)
#else
void SpinCallback(ChNrFrame frame, void * arg, float delta)
#endif
{
	ChQvSpinRenderData *pData = (ChQvSpinRenderData *)arg;
	ChQvInstance *pTarget = (ChQvInstance *)(ChNrObjectGetAppData(frame));
	if(pData && pTarget)
	{
		pData->Spin(pTarget);
	}
}
#endif

void ChQvSpinRenderData::AddInstance(ChQvInstance *pTarget)
{
	ChQvScriptRenderData::AddInstance(pTarget);
	if(pTarget->GetFrame())
	{
		ChNrFrameAddCallback(pTarget->GetFrame(), SpinCallback, this);
	}
}

void ChQvSpinRenderData::Spin(ChQvInstance *pTarget)
{

	if(!pTarget->GetContext()->IsAnimating()) return;

	float newStep =  pTarget->GetContext()->GetFrameCount();
	double step = newStep - m_step;	// Based on frame count, interpreting the angle as "per frame increment"
	m_step  = newStep;
	QvSpin *pSpin = (QvSpin*)GetNode();

	// No spin, do nothing
	if(pSpin->xangle.value == 0 && pSpin->yangle.value == 0 && pSpin->zangle.value == 0) return;

	if(step)
	{
		// Time has passed, so we need to
		// integrate the incremental spin by applying this rotation step to the current spinTransform
		double twopi = atan(1.0) * 8.;	// good to about 17 places

		if(pSpin->xangle.value != 0.0)
		{
			float xangle = float(fmod(double(pSpin->xangle.value) * step, twopi));
			m_spinTransform *= GxTransform3Wf(GxVec3f(1., 0., 0.),  xangle);
		}
		if(pSpin->yangle.value != 0.0)
		{
			float yangle = float(fmod(double(pSpin->yangle.value) * step, twopi));
			m_spinTransform *= GxTransform3Wf(GxVec3f(0., 1., 0.), yangle);
		}
		if(pSpin->zangle.value != 0.0)
		{
			float zangle = float(fmod(double(pSpin->zangle.value) * step, twopi));
			m_spinTransform *= GxTransform3Wf(GxVec3f(0., 0., 1.), zangle);
		}
	}

	ChNrFrame frame = pTarget->GetFrame();

	if(frame)
	{
		GxTransform3Wf instTransform = pTarget->GetRendererTransform();
		if(pTarget->GetTransformInstance())
		{
			// It has its own transformation attribute, like a grouping node
			// So modify the tree transform
			GxTransform3Wf instTransform = pTarget->GetTransform();
			if(pSpin->axes.value == QvSpin::GLOBAL)
			{
				pTarget->GetTransformInstance()->SetSelfTransform(instTransform * m_spinTransform * instTransform.Inverse());
			}
			else
			{
				pTarget->GetTransformInstance()->SetSelfTransform(m_spinTransform);
			}
			pTarget->GetTransformInstance()->SetTransformDirty();
		}
		else
		{
			//leaf node	- spin it in RL land
			GxTransform3Wf instTransform = pTarget->GetRendererTransform();
			ChNrFrameAddTransform(frame, CombineReplace, *(instTransform.GetMatrix()));
			if(pSpin->axes.value == QvSpin::GLOBAL)
			{
				ChNrFrameAddTransform(frame, CombineAfter, *(m_spinTransform.GetMatrix()));
			}
			else
			{
				ChNrFrameAddTransform(frame, CombineBefore, *(m_spinTransform.GetMatrix()));
			}
		}
	}
	pTarget->GetContext()->SetDirty();	// force another frame

}


/////////////////////////////////////////////////////////////////////////////////


// end of file

