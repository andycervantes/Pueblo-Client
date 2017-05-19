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

#include "grheader.h"

#include "ChStubBrowser.h"
#include "ChMaze.h"
#include "CvQuery.h"
#include "CvType.h"
#include "ChVrmlEvent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif
#include <QvNodes.h>

class  ChNode : public  QvNode { };

ChStubBrowser::~ChStubBrowser()
{
};



#if 0
long ChQvBrowser::CompileVRML(LPCTSTR strVRML) 
{
	// TODO: Add your dispatch handler code here

	return 0;
}

#endif

void ChStubBrowser::FreeNode(ChNode * node) 
{
	if(node)
	{
		((ChNode*)node)->Release();
	}

}


ChNode * ChStubBrowser::Resolve(ChNode * relativeNode, string &nameArg) 
{
	ChNode *pNode = 0;
	string name = nameArg;

	QvNode *pRoot = (relativeNode ? relativeNode : ((ChMazeWnd*)(m_pContext->GetWnd()))->GetScene());
	string strKey;

	int index = 0;
	
	while(pRoot && index >= 0)
	{
		// Handle node.node.node syntax

		index = name.Find(".");

		string nodeName;
		if(index >= 0)
		{
			nodeName = name.Left(index);
			int count = name.GetLength() - index - 1;
			if(count > 0) name = name.Right(count);	 // remainder
			else index = -1;  // trailing dot
		}
		else
		{
			nodeName = name;
		}
		
		// Now look up the node				   
		strKey = "DEF " + nodeName + " Info{ }";	  // Don't care what class, just the name
		ChQvQuery query( (ChMazeWnd*)(m_pContext->GetWnd()), strKey );
		query.Apply( pRoot );

		pNode = (ChNode *)(query.GetNode());
		pRoot = pNode;		   // loop down to next level if any
	}
	if(pNode) pNode->Use();
	return pNode;
}

BOOL ChStubBrowser::SendEvent(ChNode * node, ChApplet * applet, ChIVrmlEvent * eventList)
{
	node->Use();
	ChEventMsg *pEventMsg = new ChEventMsg(node, applet, eventList);
	(m_pContext->GetWnd())->PostMessage(WM_VRML_EVENT, 0, (unsigned long)pEventMsg);
	return true;
}

ChNode* ChStubBrowser::CompileVRML(string strVRML)
{
	ChNode *pNode = 0;
    char *buf = strVRML.GetBuffer(1);
	istrstream is(buf);
	bool boolSuccess = false;
	QvDB::init();

    ChQvInput	in;
	in.setFilePointer(&is);
	QvNode	*root = 0;

    if (QvDB::read(&in, root) && root != 0)
	{
		pNode = (ChNode*)root;
		//pNode->Use();
	}
	else if(root)
	{
		delete root;
	}
	return pNode;
} 


// Helpers

ChVRMLEvent::type	ChStubBrowser::GetType(string &eventTypeName)
{
	// Needs to be a faster lookup - hash or splay
	if(eventTypeName == "SFBitMask") 	return ChVRMLEvent::SFBitMask;
	if(eventTypeName == "SFBool") 		return ChVRMLEvent::SFBool;
	if(eventTypeName == "SFColor") 		return ChVRMLEvent::SFColor;
	if(eventTypeName == "SFEnum") 		return ChVRMLEvent::SFEnum;
	if(eventTypeName == "SFFloat") 		return ChVRMLEvent::SFFloat;
	if(eventTypeName == "SFImage") 		return ChVRMLEvent::SFImage;
	if(eventTypeName == "SFLong") 		return ChVRMLEvent::SFLong;
	if(eventTypeName == "SFMatrix") 	return ChVRMLEvent::SFMatrix;
	if(eventTypeName == "SFNode") 		return ChVRMLEvent::SFNode;
	if(eventTypeName == "SFRotation") 	return ChVRMLEvent::SFRotation;
	if(eventTypeName == "SFString") 	return ChVRMLEvent::SFString;
	if(eventTypeName == "SFVec2f") 		return ChVRMLEvent::SFVec2f;
	if(eventTypeName == "SFVec3f") 		return ChVRMLEvent::SFVec3f;
	if(eventTypeName == "SFTime") 		return ChVRMLEvent::SFTime;
	if(eventTypeName == "SFPick") 		return ChVRMLEvent::SFPick;
	if(eventTypeName == "SFProximity") 	return ChVRMLEvent::SFProximity;
	if(eventTypeName == "SFCollision") 	return ChVRMLEvent::SFCollision;

	if(eventTypeName == "MFBitMask") 	return ChVRMLEvent::MFBitMask;
	if(eventTypeName == "MFBool") 		return ChVRMLEvent::MFBool;
	if(eventTypeName == "MFColor") 		return ChVRMLEvent::MFColor;
	if(eventTypeName == "MFEnum") 		return ChVRMLEvent::MFEnum;
	if(eventTypeName == "MFFloat") 		return ChVRMLEvent::MFFloat;
	if(eventTypeName == "MFImage") 		return ChVRMLEvent::MFImage;
	if(eventTypeName == "MFLong") 		return ChVRMLEvent::MFLong;
	if(eventTypeName == "MFMatrix") 	return ChVRMLEvent::MFMatrix;
	if(eventTypeName == "MFNode") 		return ChVRMLEvent::MFNode;
	if(eventTypeName == "MFRotation") 	return ChVRMLEvent::MFRotation;
	if(eventTypeName == "MFString") 	return ChVRMLEvent::MFString;
	if(eventTypeName == "MFVec2f") 		return ChVRMLEvent::MFVec2f;
	if(eventTypeName == "MFVec3f") 		return ChVRMLEvent::MFVec3f;
	if(eventTypeName == "MFTime") 		return ChVRMLEvent::MFTime;
	if(eventTypeName == "MFPick") 		return ChVRMLEvent::MFPick;
	if(eventTypeName == "MFProximity") 	return ChVRMLEvent::MFProximity;
	if(eventTypeName == "MFCollision") 	return ChVRMLEvent::MFCollision;

	return ChVRMLEvent::invalid;
}

string ChStubBrowser::getWorldURL()
{
	return ((ChMazeWnd*)(m_pContext->GetWnd()))->GetCurrentURL();
}

void ChStubBrowser::loadWorld(string& url)
{
	return;
}

ChNode * ChStubBrowser::GetViewpoint()
{
	ChNode *pViewPoint = (ChNode*)(m_pContext->GetCurrentCamera());
	if(pViewPoint) pViewPoint->Use();
	return (pViewPoint);
}

void ChStubBrowser::GetViewpointPosition(float loc[3])
{
	loc[0] = loc[1] = loc[2] = 0;
	QvNode *pViewPoint = (m_pContext->GetCurrentCamera());
	if(pViewPoint)
	{
		string strType;
		nodeType typ = nodeType(pViewPoint->GetType(strType));
		QvSFVec3f *pPos = 0;

		if(typ == typeQvOrthographicCamera)
		{
			pPos = &(((QvOrthographicCamera *)pViewPoint)->position);
		}
		else if(typ == typeQvPerspectiveCamera)
		{
			pPos = &(((QvPerspectiveCamera *)pViewPoint)->position);
		}
		if(pPos)
		{
			loc[0] = pPos->value[0];
			loc[1] = pPos->value[1];
			loc[2] = pPos->value[2];
		}
	}
}

void ChStubBrowser::GetViewpointOrientation(float axis[3], float &angle)
{
	axis[0] = axis[2] = angle = 0;	   axis[1] = 1;

	QvNode *pViewPoint = (m_pContext->GetCurrentCamera());
	if(pViewPoint)
	{
		string strType;
		nodeType typ = nodeType(pViewPoint->GetType(strType));
		QvSFRotation *pRot = 0;

		if(typ == typeQvOrthographicCamera)
		{
			pRot = &(((QvOrthographicCamera *)pViewPoint)->orientation);
		}
		else if(typ == typeQvPerspectiveCamera)
		{
			pRot = &(((QvPerspectiveCamera *)pViewPoint)->orientation);
		}
		if(pRot)
		{
			axis[0] = pRot->axis[0];
			axis[1] = pRot->axis[1];
			axis[2] = pRot->axis[2];
			angle = pRot->angle;
		}
	}
}
