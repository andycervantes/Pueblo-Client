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

	Implementation for the ChPuebloVrmlWnd class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChVrmlWnd.cpp,v 2.6 1996/09/26 02:07:02 pritham Exp $

#include "grheader.h"

#include "ChVrmlWnd.h"
#include "ChGrMod.h"

#if defined( CH_PUEBLO_PLUGIN )
#include "vwrres.h"
#endif


/*----------------------------------------------------------------------------
	ChPuebloVrmlWnd class
----------------------------------------------------------------------------*/
BEGIN_MESSAGE_MAP(ChPuebloVrmlWnd, ChMazeWnd)
	//{{AFX_MSG_MAP(ChPuebloVrmlWnd)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
#if defined( CH_PUEBLO_PLUGIN )
	ON_WM_ERASEBKGND()
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_WM_KEYDOWN()
#endif
END_MESSAGE_MAP()


ChPuebloVrmlWnd::ChPuebloVrmlWnd(ChMazeMainInfo *pInfo, ChVrmlSettings *pSettings ) :
	ChMazeWnd(pInfo, pSettings)
{
};

ChPuebloVrmlWnd::~ChPuebloVrmlWnd()
{
}

bool ChPuebloVrmlWnd::OnCameraChange(ChCameraChange efChanged)
{
	GetMainInfo()->OnCameraChange(efChanged);
	#if 0
	TRACE("Camera changed : %s \n", 
		((efChanged & ChMazeWnd::cameraMoved) ? "moved" : 
			((efChanged & ChMazeWnd::cameraTurned) ? "turned" : 
				((efChanged & ChMazeWnd::cameraSelected) ? "selected" : "unknown") 
		)));
	#endif
	return true;
}




void ChPuebloVrmlWnd::OnTimer(UINT nIDEvent) 
{
	ChMazeWnd::OnTimer(nIDEvent);
	GetMainInfo()->OnTick();
	 
}

/*----------------------------------------------------------------------------
	We override this virtual member function to display trace messages generated
	by VRML parser, HTTP load errors, plugin errors etc.
----------------------------------------------------------------------------*/
void ChPuebloVrmlWnd::OnError( chuint32 luErrorCode, const string& strMsg, int iType )
{

	GetMainInfo()->GetCore()->Trace( strMsg, iType == traceError 	
	 									? ChCore::traceErrors  
 										: ChCore::traceWarnings,
 										true );
}

#if defined( CH_PUEBLO_PLUGIN )

void ChPuebloVrmlWnd::OnKillFocus( CWnd* pNewWnd )
{

	ChMazeWnd::OnKillFocus( pNewWnd );

	#if (defined( CH_USE_RLAB ) || defined(CH_USE_D3D))
	// fake the deactivate message
	OnVRMLActivate( WA_INACTIVE, pNewWnd, IsIconic());
	#endif
}


void ChPuebloVrmlWnd::OnSetFocus( CWnd* pOldWnd )
{

	ChMazeWnd::OnSetFocus( pOldWnd );

	// TODO: Add your message handler code here
	// fake the activate message
	#if (defined( CH_USE_RLAB ) || defined(CH_USE_D3D))
	OnVRMLActivate( WA_CLICKACTIVE, pOldWnd, IsIconic());
	#endif

}

void ChPuebloVrmlWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	// Do our own accelarator mapping 
	bool boolProcessed = false;
	
	if ( GetKeyState( VK_CONTROL ) &  0x8000 
				&& GetKeyState( VK_SHIFT ) &  0x8000 )
	{
		boolProcessed = true;

		switch( nChar )
		{
			case 'K' :
			case 'k' :
			{
				SendMessage( WM_COMMAND, IDM_WALK ); 
				break;
			}
			case 'F' :
			case 'f' :
			{
				SendMessage( WM_COMMAND, IDM_FLY ); 
				break;
			}
			case 'E' :
			case 'e' :
			{
				SendMessage( WM_COMMAND, IDM_EXAMINE ); 
				break;
			}
			case 'B' :
			case 'b' :
			{
				SendMessage( WM_COMMAND, IDM_BRIGHTEN ); 
				break;
			}
			case 'D' :
			case 'd' :
			{
				SendMessage( WM_COMMAND, IDM_DIMMER ); 
				break;
			}
			default :
			{
				boolProcessed = false;
				break;
			}

		}
	}
	
	if ( !boolProcessed )
	{

		ChMazeWnd ::OnKeyDown(nChar, nRepCnt, nFlags);
	}
}

BOOL ChPuebloVrmlWnd::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return true;
}
#endif //#if defined( CH_PUEBLO_PLUGIN )

