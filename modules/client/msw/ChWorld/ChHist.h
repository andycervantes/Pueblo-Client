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

	Interface for the ChTextInputBar class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChWorld/ChHist.h,v 2.3 1996/03/05 22:09:03 pritham Exp $

#if !defined( _CHHIST_H )
#define _CHHIST_H

//#include <ChSerMod.h>
#include <ChList.h>

#if defined( NO_TEMPLATES )
#include <templcls\ChStrLst.h>
#include <templcls\ChStrLst.inl>
#endif


/*----------------------------------------------------------------------------
	ChHistory class
----------------------------------------------------------------------------*/

class ChHistory : public CObject
{
	public:
		ChHistory( chint16 sMax = 100 );
		virtual ~ChHistory();

		inline int GetCount() { return (int)m_historyList.GetCount(); }
		inline const string& GetString( int iIndex )
						{
							ChPosition	pos;

							ASSERT( iIndex < GetCount() );

							pos = m_historyList.FindIndex( iIndex );
							return m_historyList.Get( pos );
						}

		void Reset();
		void Add( const string& strLine );
		bool GetNext( string& strLine );
		bool GetPrevious( string& strLine );

		bool GetExpansion( string& strText, ChPosition& startPos );

	protected:
		inline void RemoveHead()
				{
					ASSERT( !m_historyList.IsEmpty() );
					m_historyList.RemoveHead();
				}

	protected:
		typedef enum { empty, notBrowsingHistory, atEnd, atTop,
						onlyItem, inMiddle } State;

	protected:
		chint16			m_sMax;
		#if !defined( NO_TEMPLATES )
		ChList<string>	m_historyList;
		#else
		ChStrList		m_historyList;	
		#endif
		ChPosition		m_curr;
		State			m_state;
};

#endif	// !defined( _CHHIST_H )
