// openloc.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "OpenLoc.h"
#include "ChHtmDsp.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenLoc dialog


COpenLoc::COpenLoc( ChBrowserWnd* pVRML, CWnd* pParent /*=NULL*/)
	: CDialog(COpenLoc::IDD, pParent), m_pHTMLWnd( pVRML )
{
	//{{AFX_DATA_INIT(COpenLoc)
	m_strLocation = _T("");
	//}}AFX_DATA_INIT
}


void COpenLoc::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COpenLoc)
	DDX_CBString(pDX, IDC_EDIT_LOC, m_strLocation);
	DDV_MaxChars(pDX, m_strLocation, 300);
	//}}AFX_DATA_MAP

	if ( pDX->m_bSaveAndValidate )
	{
		if ( !m_strLocation.IsEmpty() )
		{
			GetDlgItem( IDOK )->EnableWindow( true );
		} 
		else
		{
			GetDlgItem( IDOK )->EnableWindow( false );
		}
	}
}


BEGIN_MESSAGE_MAP(COpenLoc, CDialog)
	//{{AFX_MSG_MAP(COpenLoc)
	ON_CBN_SELCHANGE(IDC_EDIT_LOC, OnDataChange)
	ON_CBN_EDITCHANGE(IDC_EDIT_LOC, OnEditchangeEditLoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// COpenLoc message handlers

BOOL COpenLoc::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GetDlgItem( IDOK )->EnableWindow( false );

	// Add all the visited URLs to the open location listbox
	ChBrowserWnd* pHTMLWnd = GetHTMLWnd();
	ASSERT( pHTMLWnd );

	if ( pHTMLWnd->GetHistoryList()->GetCount() )
	{
		string strURL, strFile, strMimeType;
		ChPosition pos = pHTMLWnd->GetHistoryList()->GetHeadPosition();

		while( pos )
		{
			ChHTMLHistory *phtmlHist = (ChHTMLHistory*)pHTMLWnd->
										GetHistoryList()->GetNext( pos );	
		
			phtmlHist->GetHistory( strURL, strFile, strMimeType );

			if ( !strURL.IsEmpty() )
			{ // add it to the listbox
				if( ((CComboBox*)GetDlgItem( IDC_EDIT_LOC ))->
									FindStringExact( 0, strURL ) == CB_ERR ) 
				{
			 		((CComboBox*)GetDlgItem( IDC_EDIT_LOC ))->AddString( strURL );
				}
			}

		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void COpenLoc::OnDataChange() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem( IDOK )->EnableWindow( true );
}

void COpenLoc::OnEditchangeEditLoc() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	
}
