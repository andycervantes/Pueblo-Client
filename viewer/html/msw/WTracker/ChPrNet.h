// chprnet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCachePage dialog

class ChCachePrefsPage : public CPropertyPage
{
	DECLARE_DYNCREATE( ChCachePrefsPage )

	public:
		ChCachePrefsPage();
		~ChCachePrefsPage();

											// Dialog Data
		//{{AFX_DATA(ChCachePrefsPage)
		enum { IDD = IDD_CACHE };
		CString		m_cacheDir;
		UINT 		m_uCacheSize;
		//}}AFX_DATA

											// Overrides
		virtual bool OnSetActive();
		virtual void OnCommit();
											/* ClassWizard generate virtual
												function overrides */
		//{{AFX_VIRTUAL(ChCachePrefsPage)
		protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		//}}AFX_VIRTUAL

	protected:
											// Generated message map functions
		//{{AFX_MSG(ChCachePrefsPage)
		afx_msg void OnClrCache();
		//}}AFX_MSG

	protected:
		bool		m_boolInitialized;
		ChRegistry	m_reg;

	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
// ChNetworkPage dialog

class ChNetworkPage : public CPropertyPage
{
	DECLARE_DYNCREATE(ChNetworkPage)

// Construction
public:
	ChNetworkPage();
	~ChNetworkPage();

// Dialog Data
	//{{AFX_DATA(ChNetworkPage)
	enum { IDD = IDD_NETWORK };
	UINT	m_uMaxConn;
	//}}AFX_DATA

		// Overrides
		virtual bool OnSetActive();
		virtual BOOL  OnKillActive();

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(ChNetworkPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(ChNetworkPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	protected:
		bool		m_boolInitialized;
		ChRegistry	m_reg;
	DECLARE_MESSAGE_MAP()

};
