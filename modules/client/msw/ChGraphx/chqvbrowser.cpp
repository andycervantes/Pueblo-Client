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

#include "chqvbrowser.h"
#include "ChMaze.h"
#include "CvQuery.h"
#include "ChVrmlEvent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif
#include <QvNodes.h>

class  ChNode : public  QvNode { };

/////////////////////////////////////////////////////////////////////////////
// ChQvBrowser

IMPLEMENT_DYNCREATE(ChQvBrowser, CCmdTarget)

ChQvBrowser::ChQvBrowser()
{
	EnableAutomation();
	
	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	
	AfxOleLockApp();
}

ChQvBrowser::~ChQvBrowser()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	
	AfxOleUnlockApp();
}

void ChQvBrowser::OnFinalRelease()
{
	// When the last reference for an automation object is released
	//	OnFinalRelease is called.  This implementation deletes the 
	//	object.  Add additional cleanup required for your object before
	//	deleting it from memory.

	delete this;
}


BEGIN_MESSAGE_MAP(ChQvBrowser, CCmdTarget)
	//{{AFX_MSG_MAP(ChQvBrowser)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(ChQvBrowser, CCmdTarget)
	//{{AFX_DISPATCH_MAP(ChQvBrowser)
	DISP_FUNCTION(ChQvBrowser, "CompileVRML", CompileVRML, VT_I4, VTS_BSTR)
	DISP_FUNCTION(ChQvBrowser, "FreeNode", FreeNode, VT_EMPTY, VTS_I4)
	DISP_FUNCTION(ChQvBrowser, "Resolve", IResolve, VT_I4, VTS_I4 VTS_BSTR)
	DISP_FUNCTION(ChQvBrowser, "SendEvent", ISendEvent, VT_BOOL, VTS_I4 VTS_I4 VTS_PVARIANT)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

IMPLEMENT_OLECREATE(ChQvBrowser, "Browser", 0x5581ec20, 0x4c64, 0x11cf, 0x99, 0x73, 0x0, 0x40, 0x5, 0x1c, 0x14, 0x30)

/////////////////////////////////////////////////////////////////////////////
// ChQvBrowser message handlers


long ChQvBrowser::CompileVRML(LPCTSTR strVRML) 
{
	// TODO: Add your dispatch handler code here

	return 0;
}


void ChQvBrowser::FreeNode(long node) 
{
	if(node)
	{
		((ChNode*)node)->Release();
	}

}


long ChQvBrowser::IResolve(long relativeNode, LPCTSTR name) 
{
	return long(Resolve((ChNode*)relativeNode, string(name)));
}

BOOL ChQvBrowser::ISendEvent(long pNode, long pApplet, VARIANT FAR* eventList) 
{
	ChVrmlEvent * pEvent = ChVrmlEvent::Create(*(VrmlEvent*)eventList);	 // copy structs, and data

	// Caller deletes eventList and their copy of data

	SendEvent((ChNode*)pNode, (ChApplet*)pApplet, pEvent);


	return TRUE;
}

// Wrappers for munged types
ChNode * ChQvBrowser::Resolve(ChNode * relativeNode, string &name) 
{
	ChNode *pNode = 0;

	QvNode *pRoot = (relativeNode ? relativeNode : ((ChMazeWnd*)(m_pContext->GetWnd()))->GetScene());
	ChQvQuery query( (ChMazeWnd*)(m_pContext->GetWnd()), name );
	query.Apply( relativeNode );

	pNode = (ChNode *)(query.GetNode());
	if(pNode) pNode->Use();
	return pNode;
}

BOOL ChQvBrowser::SendEvent(ChNode * node, ChApplet * applet, ChVrmlEvent * eventList)
{
	ChEventMsg *pEventMsg = new ChEventMsg(node, applet, eventList);
	(m_pContext->GetWnd())->PostMessage(WM_VRML_EVENT, 0, (unsigned long)pEventMsg);
	return true;
}

// Helpers

