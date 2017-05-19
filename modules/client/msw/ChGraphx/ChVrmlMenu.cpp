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

	Implementation for the ChGraphicMaze class, which is used to display VRML.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChVrmlMenu.cpp,v 2.3 1996/09/12 19:09:48 pritham Exp $

#include "grheader.h"

#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN ) && !defined( CH_PUEBLO_PLUGIN )
#include "resource.h"
#else
#include "vwrres.h"
#endif

#include <ChReg.h>

#if !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
#include <ChCore.h>
#include "ChGrMod.h"
#endif
#include <ChHTTP.h>
#include <ChUtil.h>




#include "ChMaze.h"
#include "ChMazCam.h"

#include "ChVrmlTransition.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

#define NOT_IMPLEMENTED	TRACE2("Function not implemented, file %s: line %s.", __FILE__, __LINE__)


void 	ChMazeWnd::OnSettingsChanged()
{
	// Override this to get notified
}

void ChMazeWnd::DisplayMenu( int x, int y, chuint32 uFlags )
{
	if (0 == m_pScoutMenu)
	{
		m_pScoutMenu = new CMenu;
		ASSERT( m_pScoutMenu );
		m_pScoutMenu->LoadMenu( IDR_EMBED );
	}
	POINT	ptPos;
	::GetCursorPos( &ptPos );
	m_pScoutMenu->GetSubMenu( 0 )->TrackPopupMenu( TPM_LEFTALIGN | TPM_RIGHTBUTTON,
						ptPos.x, ptPos.y , this  );
}


void ChMazeWnd::OnHeadlightSwitch()
{
	ChRegistry	reg( CH_COMPANY_NAME, CH_VRML_PRODUCT_NAME,
						GR_PREFS_GROUP );
	bool		boolHeadlight = !IsHeadlightOn();

	SetHeadlight( boolHeadlight )
					->InvalidateRect( NULL, false );

	reg.WriteBool( GR_PREFS_HEADLIGHT_ON, boolHeadlight );
	OnSettingsChanged();
}


void ChMazeWnd::OnResetCamera()
{
	ResetCamera()->InvalidateRect( NULL, false );
}


void ChMazeWnd::OnBrighten()
{
	ChVrmlSettings*	pSettings =  GetSettings();
	ChRegistry		reg( CH_COMPANY_NAME, CH_VRML_PRODUCT_NAME,
							GR_PREFS_GROUP );
	float			brightness = pSettings->GetHeadlightBrightness();;

	brightness += .05;

	if ( brightness > 1.0 )
	{
		brightness = 1.0;
	}

	pSettings->SetHeadlightBrightness( reg, brightness );

	InvalidateRect( NULL, false );
											// Update the toolbar to match
	OnSettingsChanged();
}

void ChMazeWnd::OnDimmer()
{
	ChVrmlSettings*	pSettings =  GetSettings();
	ChRegistry		reg( CH_COMPANY_NAME, CH_VRML_PRODUCT_NAME,
							GR_PREFS_GROUP );
	float			brightness = pSettings->GetHeadlightBrightness();;

	brightness -= .05;

	if ( brightness < 0.0 )
	{
		brightness = 0.0;
	}

	pSettings->SetHeadlightBrightness(reg, brightness);

	InvalidateRect( NULL, false );
											// Update the toolbar to match
	OnSettingsChanged();
}


void ChMazeWnd::OnExamine()
{
	ChVrmlSettings* pSettings =  GetSettings();
	ChRegistry	reg( CH_COMPANY_NAME, CH_VRML_PRODUCT_NAME,
						GR_PREFS_GROUP );

	pSettings->SetViewerMode(reg, examine);
											// Update the toolbar to match
	OnSettingsChanged();
}


void ChMazeWnd::OnFly()
{
	ChVrmlSettings* pSettings =  GetSettings();
	ChRegistry	reg( CH_COMPANY_NAME, CH_VRML_PRODUCT_NAME,
						GR_PREFS_GROUP );

	pSettings->SetViewerMode( reg, fly );
											// Update the toolbar to match
	OnSettingsChanged();
}


void ChMazeWnd::OnWalk()
{
	ChVrmlSettings* pSettings =  GetSettings();
	ChRegistry	reg( CH_COMPANY_NAME, CH_VRML_PRODUCT_NAME,
						GR_PREFS_GROUP );

	pSettings->SetViewerMode(reg, walk);
											// Update the toolbar to match
	OnSettingsChanged();
}


void ChMazeWnd::OnInitMenuPopup( CMenu* pPopupMenu, UINT nIndex,
										BOOL bSysMenu )
{
	bool			boolUpdateToolbar = false;
	ChVrmlSettings*	pSettings = GetSettings();

	CWnd::OnInitMenuPopup( pPopupMenu, nIndex, bSysMenu );

	if (0 == nIndex)
	{										// Main menu

		Ch3DViewerMode	viewerMode;
		bool			boolHeadlight = IsHeadlightOn();
		float			brightness = pSettings->GetHeadlightBrightness();
		float			fPercent = brightness * 100;
		CString			strMenuText;
		CString			strFormat;
											// Handle walk/fly/examine
		viewerMode = pSettings->GetViewerMode();

		pPopupMenu->CheckMenuItem( IDM_WALK, MF_BYCOMMAND |
								  	((walk == viewerMode) ?
								  		MF_CHECKED : MF_UNCHECKED ) );
		pPopupMenu->CheckMenuItem( IDM_FLY, MF_BYCOMMAND |
								  	((fly == viewerMode) ?
									  	MF_CHECKED : MF_UNCHECKED ) );
		pPopupMenu->CheckMenuItem( IDM_EXAMINE, MF_BYCOMMAND |
								  	((examine == viewerMode) ?
									  	MF_CHECKED : MF_UNCHECKED ) );

											// Handle the headlight items

		pPopupMenu->EnableMenuItem( IDM_BRIGHTEN, MF_BYCOMMAND |
											((brightness < 1.0)
											? MF_ENABLED : MF_GRAYED ) );
		pPopupMenu->EnableMenuItem( IDM_DIMMER, MF_BYCOMMAND |
											((brightness > 0.0)
											? MF_ENABLED : MF_GRAYED ) );

											// Set the headlight item text
		if (boolHeadlight)
		{
			#if 0 && !defined(CH_VRML_VIEWER) && !defined(CH_VRML_PLUGIN )
			char * sFormat = strFormat.GetBuffer(100);
			::LoadString(IDS_HEADLIGHT_ON, 
			#else
			strFormat.LoadString( IDS_HEADLIGHT_ON );
			#endif
			strMenuText.Format( strFormat, (int)fPercent );
		 	pPopupMenu->ModifyMenu( ID_OPT_HEADLIGHT_SWITCH, MF_BYCOMMAND,
									ID_OPT_HEADLIGHT_SWITCH,  strMenuText );
		}
		else
		{
			strMenuText.LoadString( IDS_HEADLIGHT_OFF );
		 	pPopupMenu->ModifyMenu( ID_OPT_HEADLIGHT_SWITCH, MF_BYCOMMAND,
									ID_OPT_HEADLIGHT_SWITCH,  strMenuText );
		}
											/* Check the headlight menu if the
												headlight is on */

		pPopupMenu->CheckMenuItem( ID_OPT_HEADLIGHT_SWITCH,
									MF_BYCOMMAND |
								  	(boolHeadlight ?
								  		MF_CHECKED : MF_UNCHECKED ) );

											// Render Optimization items
		ChRenderOptimization opt = pSettings->GetRenderOptimization();

		pPopupMenu->CheckMenuItem( IDM_OPTIMIZE_BETTER, MF_BYCOMMAND |
								  	((renderBetter == opt) ?
								  		MF_CHECKED : MF_UNCHECKED ) );

		pPopupMenu->CheckMenuItem( IDM_OPTIMIZE_FASTER, MF_BYCOMMAND |
								  	((renderFaster == opt) ?
								  		MF_CHECKED : MF_UNCHECKED ) );

											// Collision items
		pPopupMenu->CheckMenuItem( IDM_COLLISION_CHECKING,
									MF_BYCOMMAND |
								  	((pSettings->GetCollisionMode() == collisionOn) ?
								  		MF_CHECKED : MF_UNCHECKED ) );



		SetupCameraMenu();

		boolUpdateToolbar = true;
	}

	if (boolUpdateToolbar)
	{
		OnSettingsChanged();
	}
}


void ChMazeWnd::OnCameraNext() 
{

	int count =	GetRenderContext()->GetCameraCount();
	if(count > 0)
	{
		int index = GetRenderContext()->GetCameraIndex();
		index++;
		if(index >= count) index = 0;
		GetRenderContext()->SelectCamera(index);
		Invalidate(false);
	}
	
}

void ChMazeWnd::OnCameraPrev() 
{
	int count =	GetRenderContext()->GetCameraCount();
	if(count > 0)
	{
		int index = GetRenderContext()->GetCameraIndex();
		index--;
		if(index < 0) index = count - 1;
		GetRenderContext()->SelectCamera(index);
		Invalidate(false);
	}
}

void ChMazeWnd::OnOptResetSpeed() 
{
	if(GetScene() != 0) ResetUserSpeedFactor();	
}

void ChMazeWnd::FindCameraMenu()
{
	CMenu * pMenu = m_pScoutMenu;   //  plugin menu
	string strCameras = "Ca&meras";		// move to resource TODO
	m_hCameraMenu = FindMenu(pMenu, strCameras); 
}

HMENU ChMazeWnd::FindMenu(CMenu * pMenu, string &strName)
{
	HMENU hMenu = 0;

	int count = pMenu->GetMenuItemCount( );

	for(int i = 0; i < count && !hMenu; i++)
	{
		char cBuf[200];

		pMenu->GetMenuString(i, cBuf, sizeof(cBuf), MF_BYPOSITION);
		CMenu *pSubMenu = pMenu->GetSubMenu(i);
		if(pSubMenu && strName == cBuf)
		{
			hMenu = pSubMenu->GetSafeHmenu();
		}
		else if(pSubMenu)
		{
			// Search recursively
			hMenu = FindMenu(pSubMenu, strName);
		}
	}

	return 	hMenu;
}

HMENU ChMazeWnd::FindParentMenu(CMenu * pTopMenu, const HMENU hChildMenu, int &index)
{
	HMENU hMenu = 0;

	int count = pTopMenu->GetMenuItemCount( );

	for(int i = 0; i < count && !hMenu; i++)
	{
		CMenu *pSubMenu = pTopMenu->GetSubMenu(i);
		if(pSubMenu && hChildMenu == pSubMenu->GetSafeHmenu())
		{
			hMenu = pTopMenu->GetSafeHmenu();
			index = i;
		}
		else if(pSubMenu)
		{
			// Search recursively
			hMenu = FindParentMenu(pSubMenu, hChildMenu, index);
		}
	}

	return 	hMenu;
}

class ChMyMenuCameraIterator : public ChCameraIterator
{
	protected:
		HMENU m_hMenu;
		UINT	uId;

	public:

		ChMyMenuCameraIterator(ChMazeWnd *pWnd, HMENU hCameraMenu) : ChCameraIterator(pWnd) 
		{
			m_hMenu = hCameraMenu;
			uId = IDM_CAMERA_FIRST;
		};

		virtual ~ChMyMenuCameraIterator() {};


		virtual bool DoCamera(string &strName, QvNode *pCamera)
		{
			CMenu *pMenu = CMenu::FromHandle(m_hMenu);

			pMenu->AppendMenu(MF_STRING, uId++, LPCTSTR (strName));
			return true;
		}


};


bool ChMazeWnd::SetupCameraMenu()
{
	if(!m_hCameraMenu) FindCameraMenu();
	if(m_hCameraMenu)
	{
		CMenu *pMenu = CMenu::FromHandle(m_hCameraMenu);
		int count = pMenu->GetMenuItemCount( );

		// Zap eveything else
		for(int i = 0; i < count; i++)
		{
			pMenu->DeleteMenu(0, MF_BYPOSITION);
		}

		int cameraID = GetRenderContext()->GetCameraIndex() + UINT(IDM_CAMERA_FIRST);
		ChMyMenuCameraIterator camIterator(this, m_hCameraMenu);
		camIterator.Iterate();
		count = pMenu->GetMenuItemCount( );
		if(count > 0) pMenu->CheckMenuItem( cameraID, MF_BYCOMMAND | MF_CHECKED );

		int index;
		HMENU hMenu = FindParentMenu(m_pScoutMenu, m_hCameraMenu, index);
		pMenu = CMenu::FromHandle(hMenu);
		pMenu->EnableMenuItem( index, MF_BYPOSITION | ( (count > 0) ? MF_ENABLED : MF_GRAYED) );
		pMenu->EnableMenuItem( IDM_CAMERA_NEXT, MF_BYCOMMAND | ( (count > 0) ? MF_ENABLED : MF_GRAYED) );
		pMenu->EnableMenuItem( IDM_CAMERA_PREV, MF_BYCOMMAND | ( (count > 0) ? MF_ENABLED : MF_GRAYED) );
	}
	return true;
}

void ChMazeWnd::OnCameraMenuCommand( UINT uId )
{
	GetRenderContext()->SelectCamera(uId - IDM_CAMERA_FIRST);
	Invalidate(false);
}

void ChMazeWnd::OnCameraMenuUpdateCommand( CCmdUI* pCmdUI )
{
	if (!pCmdUI->m_pSubMenu)				// We don't handle submenu items...
	{
		bool	boolEnabled = true;

		int index = GetRenderContext()->GetCameraIndex();
		pCmdUI->SetCheck( UINT(index) == (pCmdUI->m_nID - UINT(IDM_CAMERA_FIRST)) );
		pCmdUI->Enable( boolEnabled );
	}
}

void ChMazeWnd::OnOptimizeBetter() 
{
	ChVrmlSettings*	pSettings =  GetSettings();
	ChRegistry		reg( CH_COMPANY_NAME, CH_VRML_PRODUCT_NAME,
							GR_PREFS_GROUP );

	pSettings->SetRenderOptimization(reg, renderBetter);

	InvalidateRect( NULL, false );
											// Update the toolbar to match
	OnSettingsChanged();
	
}

void ChMazeWnd::OnOptimizeFaster() 
{
	ChVrmlSettings*	pSettings =  GetSettings();
	ChRegistry		reg( CH_COMPANY_NAME, CH_VRML_PRODUCT_NAME,
							GR_PREFS_GROUP );

	pSettings->SetRenderOptimization(reg, renderFaster);

	InvalidateRect( NULL, false );
											// Update the toolbar to match
	OnSettingsChanged();
	
}

void ChMazeWnd::OnCollisionChecking() 
{
	
	ChVrmlSettings*	pSettings =  GetSettings();
	ChRegistry		reg( CH_COMPANY_NAME, CH_VRML_PRODUCT_NAME,
							GR_PREFS_GROUP );
	Ch3DCollisionMode	mode = pSettings->GetCollisionMode();

	mode = (mode == collisionOn) ? collisionOff : collisionOn;
	pSettings->SetCollisionMode(reg, mode);

	InvalidateRect( NULL, false );
											// Update the toolbar to match
	OnSettingsChanged();
}
