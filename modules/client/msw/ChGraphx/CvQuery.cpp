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

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/CvQuery.cpp,v 2.12 1996/02/27 21:53:42 jimd Exp $
#include "grheader.h"
//
#if defined( CH_ARCH_16 )
#include <QvElemnt.h>   
#else
#include <QvElement.h>   
#endif
#include <QvNodes.h>
#include <QvState.h>
#if defined( CH_ARCH_16 )
#include <UnknNode.h>   
#else
#include <QvUnknownNode.h>
#endif
#ifdef CH_MSW
#include <windows.h>
#endif
#ifdef HUGE
#undef HUGE
#endif
#include <math.h>
#include <strstrea.h>
#include "ChMaze.h"
#include "CvQuery.h"


QvNode * ReadVrml( string strAGraph)
{
	string strVRML = ChMazeWnd::EncapsulateVRML(strAGraph);
	char *buf = strVRML.GetBuffer(1);
	istrstream is(buf);
	QvDB::init();

	ChQvInput	in;
	in.setFilePointer(&is);
	QvNode	*root;

    if (QvDB::read(&in, root) && root != NULL)
    {
		// read ok
	}
	else
	{
		// bad read; dispose if any nodes created
		if(root)
		{
			root->Release();

			#if 0
			ChQvDeleteState delState(0);
			root->traverse(&delState);
			delete root;
			#endif

			root = 0;	// say we failed
		}
	}
	return root;
}

ChQvQuery::ChQvQuery(ChMazeWnd *pWnd, QvNode *pNodeToFind) : m_pNode(0), m_pNodeToFind(pNodeToFind), m_pWnd(pWnd)
{
	if(pNodeToFind) pNodeToFind->Use();
}

ChQvQuery::~ChQvQuery()
{
	if(m_pNodeToFind) m_pNodeToFind->Release();
}

bool ChQvQuery::Apply(QvNode *pNode)
{
	m_pNode = 0;
	m_strNode = "";
	if(!pNode) return false;

	if(m_type == byName)
	{	
	
		if(!m_pNodeToFind)
		{
			// read in node from string
			m_pNodeToFind = ReadVrml(m_strKey);
		}
		if (! m_pNodeToFind) return false;
	
	}
	else
	{
		// m_strKey is the className to search, just proceed with it
	}
	ChQvQueryState state(m_pWnd, this);
	pNode->traverse(&state );
	return true;
}


