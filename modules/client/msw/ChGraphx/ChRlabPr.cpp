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
#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#if defined( CH_VRML_PLUGIN ) || defined( CH_PUEBLO_PLUGIN )
#include "vwrres.h"
#elif defined( CH_VRML_VIEWER )
#include "pueblo.h"
#endif
#include "chrlabpr.h"

#if defined( CH_PUEBLO_PLUGIN )
#include "ChGrMod.h"
#include "ChVrmlWnd.h"
#endif

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ChMazeRlabPrefPage property page

#undef new

IMPLEMENT_DYNCREATE(ChMazeRlabPrefPage, ChMazePrefPage)

ChMazeRlabPrefPage::ChMazeRlabPrefPage() : ChMazePrefPage(ChMazeRlabPrefPage::IDD)
{
	//{{AFX_DATA_INIT(ChMazeRlabPrefPage)
	m_iAsciiTextQuality = -1;
	m_boolCollisionAlarm = FALSE;
	//}}AFX_DATA_INIT
}

ChMazeRlabPrefPage::~ChMazeRlabPrefPage()
{
}

#if defined( CH_PUEBLO_PLUGIN )
void ChMazeRlabPrefPage::SetMainInfo( ChMainInfo* pMainInfo )
{
	ChVrmlSettings* 	pSettings =  ((ChMazeMainInfo*)pMainInfo)->GetSettings();

	SetInitialPreferences( pSettings->GetAsciiTextQuality(),
											pSettings->GetCollisionAlarm(),
											pSettings->GetMoveVector(),
											pSettings->GetHeadlightBrightness() );
}
#endif


void ChMazeRlabPrefPage::DoDataExchange(CDataExchange* pDX)
{
	ChMazePrefPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ChMazeRlabPrefPage)
	DDX_CBIndex(pDX, IDC_COMBO_ASCII_QUALITY, m_iAsciiTextQuality);
	DDX_Check(pDX, IDC_COLLISION_SOUND, m_boolCollisionAlarm);
	//}}AFX_DATA_MAP
	//DDX_CBIndex(pDX, IDC_COMBO_COLLISION_MODE, m_iCollisionMode);
}


BEGIN_MESSAGE_MAP(ChMazeRlabPrefPage, ChMazePrefPage)
	//{{AFX_MSG_MAP(ChMazeRlabPrefPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void ChMazeRlabPrefPage::SetInitialPreferences( int iAsciiTextQuality,
												bool boolCollisionAlarm,
												bool boolMoveVector,
												float fHeadlight )
{
	m_iAsciiTextQuality = iAsciiTextQuality;

	m_boolCollisionAlarm = boolCollisionAlarm;       

	ChMazePrefPage::SetInitialPreferences(  boolMoveVector,
											 fHeadlight );
}

void ChMazeRlabPrefPage::WritePreferences()
{
	if (m_boolInitialized)
	{
		chint16			sSetting;

		sSetting = (chint16)m_iAsciiTextQuality;
		m_reg.Write( GR_PREFS_ASCII_TEXT_QUALITY, sSetting );

	   	m_reg.WriteBool( GR_PREFS_COLLISION_ALARM, m_boolCollisionAlarm); 


	}
	ChMazePrefPage::WritePreferences();
}



/////////////////////////////////////////////////////////////////////////////
// ChMazeRlabPrefPage message handlers

#endif // defined(CH_USE_RLAB)
