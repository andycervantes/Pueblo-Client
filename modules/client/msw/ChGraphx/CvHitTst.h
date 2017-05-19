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

	Chaco/Qv node HitTesting  classes and routines.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvHitTst.h,v 2.9 1996/06/27 03:44:01 jimd Exp $

#if !defined( _CVHITTST_H )
#define _CVHITTST_H

#include <strstrea.h>
#include "CvBound.h"
#include "CvInstnc.h"

class ChQvBounds;
class ChQvWWWAnchorInstance;
class ChQvAnchorSensor;

class ChQvAnchorSensor
{
	public:
		ChQvAnchorSensor(ChQvWWWAnchorInstance	*pAnchorInst) : m_pAnchor(pAnchorInst), m_boolDirty(true) {};
		virtual ~ChQvAnchorSensor() {};

#if defined(CH_USE_3DR)
		BOOL operator==(ChQvAnchorSensor anchor) const
		{
			return (m_pAnchor == anchor.m_pAnchor && m_sID == anchor.m_sID);
		};

		inline ChQvBounds	*GetBounds () {return &m_bounds; };
		inline ChQvWWWAnchorInstance	*GetAnchorInstance () {return m_pAnchor; };
		inline TransformF_t	*GetCamClipTransform () {return &m_CamClipTransform; };
		bool HitTest(G3dHandle_t hRC, chint32 lX, chint32 lY, float &fZ);
		inline ChQvAnchorSensor* SetDirty( bool boolDirty = true )
			{
				m_boolDirty = 	boolDirty; 
				return this;
			};

		inline ChQvAnchorSensor* SetPort( float left, float top, float right, float bottom )
			{
				m_left		=	left;  
				m_top		=	top;   
				m_right		=	right; 
				m_bottom	=	bottom;

				m_boolDirty = true; 
				return this;
			};
		void PointWindowToObject(Float_t wx, Float_t wy, LineF_t & line);
		//void Init(G3dHandle_t hGC);
		void Init(ChRenderContext *pRC);

		inline ChQvAnchorSensor* SetID(chint16 id) { m_sID = id; return this; }; 
		inline chint16 GetID() { return m_sID; };
#else
		BOOL operator==(ChQvAnchorSensor anchor) const
		{
			return (m_pAnchor == anchor.m_pAnchor);
		};

#endif
		inline QvWWWAnchor	*GetAnchorNode () {return (QvWWWAnchor	*)(m_pAnchor->GetNode()); };
		string GetCommand();
		bool GetHint(string &hint);
		inline GxVec3f& GetHitPoint() { return m_hitPoint; };
		inline ChQvAnchorSensor* SetHitPoint(GxVec3f& pt) { m_hitPoint = pt; return this; }; 


	protected:
		ChQvWWWAnchorInstance *m_pAnchor;
		bool	m_boolDirty;
		GxVec3f	m_hitPoint;

#if defined(CH_USE_3DR)
		ChQvBounds	m_bounds;
		float	m_left;
		float	m_top;
		float	m_right;
		float	m_bottom;
		PointFW_t m_cameraLoc;

		TransformF_t m_CamClipTransform;
		TransformF_t m_ModelTransform;
		TransformF_t m_invCamClipTransform;
		TransformF_t m_invModelTransform;


		chint16	m_sID;		// Unique(?) Identifier
#endif

};
#if 0
class ChQvHitTestState;
class ChQvHitTest;

class ChQvHitTestState : public ChQvState
{

	protected:
		QvNode * m_pNode;

	public:
		ChQvHitTestState(ChMazeWnd* pView) : 
			ChQvState(pView, hitTest), m_pNode(0) 
			{	
			};
		ChQvHitTest *GetHitTest() {return m_pNode;};
};



class ChQvHitTest
{

	public:
		ChQvHitTest( ChMazeWnd* pView, chint32 lX, chint32 lY )
			: m_pNode(0), m_boolFound(false), m_x(lX), m_y(lY), m_pView(pView)
			  {};
		virtual ~ChQvHitTest() {};

		QvNode * GetNode()	{  return m_pNode;}
		void GetKeys(chint32 &lX, chint32 &lY)	{  lX = m_x; lY = m_y; return;}
		bool Apply(QvNode *pNode)
		{
			ChQvHitTestState state(m_pView, this);
			pNode->traverse(&state );
			
			return true;
		}

		void SetResult(QvNode *pNode, float zHit)
		{   
			if(!boolFound || zHit < m_zHit)
			{ 
				m_pNode = pNode;
				m_zHit = zHit;
			}
 		}
		
	protected:
									// search keys
		chint32	m_x, m_y;

		float m_zHit;		// min z value of hit node
									// search results
		QvNode * m_pNode;
		bool m_boolFound;
		ChMazeWnd* m_pView;


	//friend bool HitTestNode( QvNode * pNode, QvState *qvstate);

};

float PointDistToLine(const GxVec3f &p0, const GxVec3f &v, const GxVec3f &q, float *pT = 0);

#endif

#endif // _CVHITTST_H

