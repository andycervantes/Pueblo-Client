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

----------------------------------------------------------------------------*/

template<class type> class ChPolyPolygon	
{
	protected:
		type	*m_pPts;
		int		*m_pCounts;
		int		*m_pAccumCounts;
		int		m_polyCount;
		int 	m_size;
		int 	m_polySize;
		enum constants { growSize = 50};

	public:
		ChPolyPolygon() : m_pPts(0), m_pCounts(0), m_polyCount(0), 
			m_size(0), m_pAccumCounts(0), m_polySize(0)
			{};
		virtual ~ChPolyPolygon()
			{
				delete m_pPts;
				m_pPts = 0;
				delete m_pCounts;
				m_pCounts = 0;		
				delete m_pAccumCounts;
				m_pAccumCounts = 0;

			};
		ChPolyPolygon<type> *NewPoly()
			{ 
				if(m_polyCount >= m_polySize) Grow();
				m_polyCount++;
				if(m_polyCount > 1)
				{
					m_pAccumCounts[m_polyCount-1] = m_pAccumCounts[m_polyCount-2] + m_pCounts[m_polyCount-2];
				}
				return this;
			};
		ChPolyPolygon<type> *EndPoly()
		{
			return this;
		};
		ChPolyPolygon<type> *Init()
			{
				m_pPts = 0;
				m_pCounts = 0; 
				m_pAccumCounts = 0; 
				m_polyCount = 0; 
				m_size = 0; 
				m_polySize = 0;
				return this;
			};
		inline type &GetPoint( int polyIndex, int index)
		{
			return m_pPts[m_pAccumCounts[polyIndex] + index];
		}
		ChPolyPolygon<type> *Append(const type& pt)
		{
			if(m_pAccumCounts[m_polyCount-1] + m_pCounts[m_polyCount-1] + 1 > m_size)
			{
				Grow();
			}  
			m_pPts[m_pAccumCounts[m_polyCount-1] + m_pCounts[m_polyCount-1]] = pt;
			m_pCounts[m_polyCount-1]++;
			return this;
		};
		
		inline int GetPointCount()
		{
			if(!m_polyCount) return 0;
			return m_pAccumCounts[m_polyCount-1] + m_pCounts[m_polyCount-1];
		};
		inline int GetPointCount(int polyIndex)
		{
			if(polyIndex < 0 || polyIndex >= m_polyCount) return 0;
			return m_pCounts[polyIndex];
		};
		inline int GetPolyCount()
		{
			return m_polyCount;
		};
		protected:
			//bool Grow();


			bool Grow()
			{
				if(m_polyCount >= m_polySize)
				{
					int		*pCounts = new int[m_polySize + growSize];
					int		*pAccumCounts = new int[m_polySize + growSize];
					memmove(pCounts, m_pCounts, m_polySize * sizeof(int));
					memmove(pAccumCounts, m_pAccumCounts, m_polySize * sizeof(int));
					for(int j=m_polySize; j<m_polySize+growSize; j++)
					{
						pCounts[j] = 0;
						pAccumCounts[j] = 0; 
					}
					delete [] m_pCounts;
					delete [] m_pAccumCounts;
					m_pCounts = pCounts;
					m_pAccumCounts = pAccumCounts;
					m_polySize += growSize;
				}
				int iDesired;  // desired new index
				if(m_polyCount >= 1)
				{	
					iDesired =	m_pAccumCounts[m_polyCount-1] + m_pCounts[m_polyCount-1] + 1;
				}
				else
				{
					iDesired =	0;
				}
				if(iDesired >= m_size)
				{
					type		*pPts = new type[m_size + growSize];
					memmove(pPts, m_pPts, m_size * sizeof(type));
					for(int j=m_size; j<m_size+growSize; j++)
					{
						pPts[j] = 0;
					}
					delete [] m_pPts;
					m_pPts = pPts;
					m_size += growSize;

				}
				return true;
			};
			
};
