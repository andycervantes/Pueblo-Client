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

	Chaco/Qv bounding box classes and routines.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvBound.h,v 2.14 1996/06/27 03:43:55 jimd Exp $

#if !defined( _CVBOUND_H )
#define _CVBOUND_H

#include <math.h>

class ChQvBounds
{
	public:
		ChQvBounds() {};
		virtual ~ChQvBounds() {};

		void GetBounds(GxVec3f &lower, GxVec3f &upper, GxTransform3Wf &mat);
		inline void GetBounds(GxVec3f &lower, GxVec3f &upper)
		{
			lower 	 = 	 m_lower; 
			upper 	 = 	 m_upper; 
		};
		void GetCenter(GxVec3f &center);


		void GetWorldBounds(GxVec3f &lower, GxVec3f &upper)
		{
			GetTransformedBounds( lower, upper, m_mat );
		}

		float GetFarDistance(float x, float y, float z)
		{
			GxVec3f lower, upper;
			GxVec3f pt(x, y, z);
			GetWorldBounds(lower, upper);

			float sum2 = 0;
			float diffa, diffb;

			diffa = pt.x() - lower.x();	diffa *= diffa; 
			diffb = pt.x() - upper.x();	diffb *= diffb; 
			sum2 += max(diffa, diffb);
			diffa = pt.y() - lower.y();	diffa *= diffa; 
			diffb = pt.y() - upper.y();	diffb *= diffb; 
			sum2 += max(diffa, diffb);
			diffa = pt.z() - lower.z();	diffa *= diffa; 
			diffb = pt.z() - upper.z();	diffb *= diffb; 
			sum2 += max(diffa, diffb);
			return sqrt(sum2);
		}
		// For simplicity the 'set' members are not protected but should only be called
		// by node bounds traversers      


		inline ChQvBounds *SetTransform(GxTransform3Wf &mat) { m_mat = mat; return this; };

		inline ChQvBounds *SetBounds(GxVec3f &lower, GxVec3f &upper)
			{
				m_lower = lower; 
				m_upper = upper; 
				return this; 
			};
		ChQvBounds *SetCenter(GxVec3f &center)
			{
				m_center = center; 
				return this; 
			};
		void GetTransformedBounds(GxVec3f &lower, GxVec3f &upper, GxTransform3Wf &mat);
 		void Apply(ChQvInstance *pInst, ChRenderContext *pRC);	// compute in context of this context


		bool IsEmpty()
		{
			return (m_lower.x() >= m_upper.x() && m_lower.y() >= m_upper.y() && m_lower.z() >= m_upper.z() );
		};
		bool IntersectLine(const GxVec3f &p0, const GxVec3f &vec, GxVec3f &result, bool boolRay = true);
		void PointWindowToObject(ChRenderContext *pRC, float wx, float wy, GxVec3f &p, GxVec3f &vec);
		bool HitTest(ChRenderContext *pRC, chint32 lX, chint32 lY, GxVec3f &hPt);


		static void GetBounds(GxVec3f *pts, int numPts, GxVec3f &lower, GxVec3f &upper ); 
		static void GetBounds(GxVec3f *pts, int numPts, GxVec3f &lower, GxVec3f &upper, GxVec3f &center );

	protected:
		GxTransform3Wf m_mat;
		GxVec3f m_lower, m_upper; // In object space
		GxVec3f m_center; // In object space

		ChQvBounds * SetEmpty() 
		{
			m_lower.set(0, 0, 0);
			m_upper = m_center = m_lower;
			return this;
		};

};

bool GetBoundingCube(QvMFLong *pCoordIndex, QvCoordinate3 *pC3, GxVec3f &lower, GxVec3f &upper, GxVec3f &center ); 



#endif // _CVBOUND_H

