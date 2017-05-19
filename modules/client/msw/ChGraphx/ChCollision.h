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

	Implementation for collision detection in VRML/RenderLab

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChCollision.h,v 2.5 1996/07/08 21:30:22 jimd Exp $

#if !defined(_CHCOLLISION_H_)
#define _CHCOLLISION_H_
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D)) || defined(CH_USE_D3D)


class ChCollisionView
{
	public:
		ChCollisionView(ChRenderContext *pRC, ChNrViewport sceneView, ChNrFrame scene, ChNrFrame sceneCamera);
		virtual ~ChCollisionView();

		float ChCollisionView::GetCollisionRange(bool boolUseFaces);
		void SetDir(GxVec3f dir);
		void SetRelativeDir(GxVec3f dir);
		void Render();

	protected:
		unsigned char *m_buffer;
		unsigned char *m_zBuffer;
    	ChNativeContext	  m_dev;
    	ChNrViewport	  m_view;
		ChNrFrame 	m_scene;
		ChNrFrame		m_camera;
		ChNrFrame		m_sceneCamera;
		ChNrImage 	m_image;
		ChNrImage 	m_zBufferImage;
		#if (defined(CH_USE_RLAB))
		#elif (defined(CH_USE_D3D))
		ChDevice3D *m_pDevice;
		#endif


	protected:
		void SetBack();
		float GetZ();
};


#endif
#endif

// end of file
