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

	Chaco/Qv node querying  classes and routines.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvQuery.h,v 2.8 1996/02/27 21:53:44 jimd Exp $

#if !defined( _CVQUERY_H )
#define _CVQUERY_H

#include <strstrea.h>

QvNode * ReadVrml( string strAGraph);
class ChQvQueryState;
class ChQvQuery;

class ChQvQueryState : public ChQvState
{

	protected:
		ChQvQuery	*m_pQuery;
		bool m_boolFound;

	public:
		ChQvQueryState(ChMazeWnd *pWnd, ChQvQuery* pQuery) : 
			ChQvState(pWnd, queryNode), m_boolFound(false), m_pQuery(pQuery) 
			{	
			};
		ChQvQuery *GetQuery() {return m_pQuery;};
};



class ChQvQuery
{
	public:
		enum type {byName, byClassName};

	public:
		ChQvQuery(ChMazeWnd *pWnd, string strKey, type theType = byName)
			: m_pNode(0), m_pNodeToFind(0), m_strKey(strKey), m_type(theType), m_pWnd(pWnd)
			  {};
		ChQvQuery(ChMazeWnd *pWnd, QvNode *pNodeToFind);
		virtual ~ChQvQuery();

		QvNode * GetNode()	{  return m_pNode;}
		QvNode * GetKeyNode()	{  return m_pNodeToFind;}
		inline string &GetKey()	{  return m_strKey;};

		bool Apply(QvNode *pNode);
		string &GetNodeDefinition()
		{ 
			// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			// AS A SAFETY FEATURE UNTIL WE FIX THE STREAM PROBLEM,
			// ALL DEFINITION QUERIES SHOULD BE TURNED OFF FOR GROUP NODES
			// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			// Need to check to make sure this isn't a group node...
			// TODO!!
			bool boolIsGroup = false;
			if(m_pNode && !boolIsGroup && !m_strNode.IsEmpty())
			{
				#if defined( CH_ARCH_16 )
				char * buf = m_strNode.GetBuffer(0x7FFF); // PRITHAM AND JIM:
														// THIS NEEDS TO BE CHANGED
														// TO SUPPORT HUGE NODES!!!
				ostrstream strm(buf, 0x7FFF);	   // stream on m_strNode for outputting vrml
				#else
				char * buf = m_strNode.GetBuffer(64000); // PRITHAM AND JIM:
														// THIS NEEDS TO BE CHANGED
														// TO SUPPORT HUGE NODES!!!
				ostrstream strm(buf, 64000);	   // stream on m_strNode for outputting vrml
				#endif
				m_pNode->write(strm);
				strm << '\0';
				m_strNode.ReleaseBuffer();
			}
			return m_strNode; 
		};

		inline type GetType() { return m_type;};

	protected:
									// search keys
		QvNode * m_pNodeToFind;
		string	m_strKey;
		type	m_type;
									// search results
		QvNode * m_pNode;
		string	m_strNode;
		ChMazeWnd *m_pWnd;

		void SetResult(QvNode *pNode)
		{    
			m_pNode = pNode;
		}
	friend bool QueryNode( QvNode * pNode, QvState *qvstate);

};


#endif // _CVQUERY_H

