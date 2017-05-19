// chlocbar.cpp : implementation file
//

#include "stdafx.h"

#include <ChReg.h>
#include "resource.h"
#include "ChLocBar.h"


#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// ChFrmCombo

ChLocBarCombo::ChLocBarCombo()
{
}

ChLocBarCombo::~ChLocBarCombo()
{
}


BEGIN_MESSAGE_MAP(ChLocBarCombo, CComboBox)
	//{{AFX_MSG_MAP(ChLocBarCombo)
	//}}AFX_MSG_MAP
	ON_MESSAGE( CB_SHOWDROPDOWN , OnShowDropDown )
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// ChFrmCombo message handlers
/////////////////////////////////////////////////////////////////////////////
// When user types Ctl+C we get this message do the copy 
LONG ChLocBarCombo::OnShowDropDown( UINT wParam, LONG lParam )
{
 	if ( !wParam )
	{
		if ( GetKeyState( VK_CONTROL ) & 0x8000 )
		{
			Copy();
		}
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// ChLocationBar dialog


ChLocationBar::ChLocationBar( )
	: CDialogBar( )
{
	//{{AFX_DATA_INIT(ChLocationBar)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ChLocationBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	bool boolInit = m_animCntl.m_hWnd == 0;

	//{{AFX_DATA_MAP(ChLocationBar)
	DDX_Control(pDX, IDC_NET_ACTIVE, m_animCntl);
	DDX_Control(pDX, IDC_CURR_URL, m_urlCombo);
	//}}AFX_DATA_MAP

   if ( boolInit )
   {
	   	m_animCntl.Open(IDR_AVI_BOOKS) ; 
		EnableAnimationCtrl( false );
   }

}

void ChLocationBar::EnableAnimationCtrl(bool bEnable)
{

   if (!bEnable)
   {
      m_animCntl.Stop() ;
      m_animCntl.Seek(0) ;
   }
   else
   {
      m_animCntl.Play(0, (UINT)-1, (UINT)-1) ;
   }
}

void ChLocationBar::GetLocBarText( string& strURL)
{
	m_urlCombo.GetWindowText( strURL );	
}

void ChLocationBar::InitLocationBar( )
{
	ChRegistry reg( CH_COMPANY_NAME, CH_HTML_PRODUCT_NAME, VISIT_HISTORY );
	string   strKey, strURL, strDefault;
	int iCount = 0;	

	while ( iCount < 10 )
	{
		strKey.Format( VISIT_KEY, iCount );
		if ( reg.Read( strKey, strURL, strDefault ) )
		{
			if ( !strURL.IsEmpty() )
			{
				m_urlCombo.AddString( strURL );
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
		iCount++;
	}
}
void ChLocationBar::CommitLocationBar( )
{
}

void ChLocationBar::UpdateLocationBar( const string& strURL )
{
	int iIndex;
	if ( ( iIndex = m_urlCombo.SelectString( 0, strURL ) ) == CB_ERR )
	{	// Add the recently visited item to the top of the list
		m_urlCombo.InsertString( 0, strURL );
		m_urlCombo.SetCurSel( 0 );		
	}
}



BEGIN_MESSAGE_MAP(ChLocationBar, CDialogBar)
	//{{AFX_MSG_MAP(ChLocationBar)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// ChLocationBar message handlers



void ChLocationBar::OnSize(UINT nType, int cx, int cy) 
{
	CDialogBar::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if ( m_animCntl.m_hWnd && m_urlCombo.m_hWnd )
	{ // size the controls

		CRect rtCombo, rtAnim;

		m_animCntl.GetWindowRect( &rtAnim );
		m_urlCombo.GetWindowRect( &rtCombo );
		ScreenToClient( &rtCombo );
		ScreenToClient( &rtAnim );

		int x = cx - rtAnim.Width() - (rtAnim.Width() >> 2 );

		int iWidth = x - rtCombo.left - (rtAnim.Width() >> 2 );
		m_urlCombo.SetWindowPos(  0, 0, 0, iWidth, rtCombo.Height() + (m_urlCombo.GetItemHeight(0) * 8), 
							SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOMOVE | SWP_DRAWFRAME | SWP_NOACTIVATE );


		m_animCntl.SetWindowPos(  0, x, rtAnim.top, 0, 0, 
							SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE );
	}
	
}




