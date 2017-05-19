// Machine generated IDispatch driver class(es) created with MFCDSPWZ tool.
/////////////////////////////////////////////////////////////////////////////
// CNetscapeNetwork wrapper class

class CNetscapeNetwork : public COleDispatchDriver
{
// Attributes
public:
	CString GetUsername();
	void SetUsername(LPCTSTR);
	CString GetPassword();
	void SetPassword(LPCTSTR);
	BOOL GetFlagShowAllNews();
	void SetFlagShowAllNews(BOOL);
	BOOL GetFlagFancyFTP();
	void SetFlagFancyFTP(BOOL);
	BOOL GetFlagFancyNews();
	void SetFlagFancyNews(BOOL);

// Operations
public:
	void Close();
	short Read(BSTR* pBuffer, short iAmount);
	long GetStatus();
	BOOL Open(LPCTSTR pURL, short iMethod, LPCTSTR pPostData, long lPostDataSize, LPCTSTR pPostHeaders);
	CString GetErrorMessage();
	short GetServerStatus();
	long GetContentLength();
	CString GetContentType();
	CString GetContentEncoding();
	CString GetExpires();
	CString GetLastModified();
	CString Resolve(LPCTSTR pBase, LPCTSTR pRelative);
	BOOL IsFinished();
	short BytesReady();
};
