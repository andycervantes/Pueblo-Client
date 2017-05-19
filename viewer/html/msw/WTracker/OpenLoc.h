#if !defined( OPENLOC_H )
#define  OPENLOC_H
// openloc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COpenLoc dialog

// openloc.h : header file
//

class ChBrowserWnd;
/////////////////////////////////////////////////////////////////////////////
// COpenLoc dialog

class COpenLoc : public CDialog
{
// Construction
public:
	COpenLoc( ChBrowserWnd* pHTML, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COpenLoc)
	enum { IDD = IDD_OPEN_LOCATION };
	CString	m_strLocation;
	//}}AFX_DATA

	string&		GetLocation()		{ return m_strLocation; }		 
	ChBrowserWnd* GetHTMLWnd()		{ return m_pHTMLWnd; }
private :
	ChBrowserWnd* m_pHTMLWnd;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenLoc)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COpenLoc)
	virtual BOOL OnInitDialog();
	afx_msg void OnDataChange();
	afx_msg void OnEditchangeEditLoc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#endif // !defined( OPENLOC_H )
