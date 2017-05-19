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

class ChNode;
class ChVrmlEvent;
class ChApplet;
class ChRenderContext;
struct VrmlEvent;

/////////////////////////////////////////////////////////////////////////////
// ChQvBrowser command target

class ChQvBrowser : public CCmdTarget
{
	DECLARE_DYNCREATE(ChQvBrowser)
protected:
	ChQvBrowser();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ChQvBrowser)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~ChQvBrowser();

	// Generated message map functions
	//{{AFX_MSG(ChQvBrowser)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(ChQvBrowser)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(ChQvBrowser)
	afx_msg long CompileVRML(LPCTSTR strVRML);
	afx_msg void FreeNode(long node);
	afx_msg long IResolve(long relativeNode, LPCTSTR name);
	afx_msg BOOL ISendEvent(long pNode, long pApplet, VARIANT FAR* eventList);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	protected:
		//ChNode * CompileVRML(string strVRML);
		//void FreeNode( ChNode * node);

		BOOL SendEvent(ChNode * node, ChApplet * applet, ChVrmlEvent * eventList);
		ChNode * Resolve(ChNode * relativeNode, string & name);


	protected:

		ChRenderContext *m_pContext;

};

/////////////////////////////////////////////////////////////////////////////
