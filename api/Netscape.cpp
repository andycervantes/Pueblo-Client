// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "headers.h"
#include <afxole.h>         // MFC OLE classes

#include "netscape.h"


/////////////////////////////////////////////////////////////////////////////
// CNetscapeNetwork properties

CString CNetscapeNetwork::GetUsername()
{
	CString result;
	GetProperty(0x1, VT_BSTR, (void*)&result);
	return result;
}

void CNetscapeNetwork::SetUsername(LPCTSTR propVal)
{
	SetProperty(0x1, VT_BSTR, propVal);
}

CString CNetscapeNetwork::GetPassword()
{
	CString result;
	GetProperty(0x2, VT_BSTR, (void*)&result);
	return result;
}

void CNetscapeNetwork::SetPassword(LPCTSTR propVal)
{
	SetProperty(0x2, VT_BSTR, propVal);
}

BOOL CNetscapeNetwork::GetFlagShowAllNews()
{
	BOOL result;
	GetProperty(0x3, VT_BOOL, (void*)&result);
	return result;
}

void CNetscapeNetwork::SetFlagShowAllNews(BOOL propVal)
{
	SetProperty(0x3, VT_BOOL, propVal);
}

BOOL CNetscapeNetwork::GetFlagFancyFTP()
{
	BOOL result;
	GetProperty(0x4, VT_BOOL, (void*)&result);
	return result;
}

void CNetscapeNetwork::SetFlagFancyFTP(BOOL propVal)
{
	SetProperty(0x4, VT_BOOL, propVal);
}

BOOL CNetscapeNetwork::GetFlagFancyNews()
{
	BOOL result;
	GetProperty(0x5, VT_BOOL, (void*)&result);
	return result;
}

void CNetscapeNetwork::SetFlagFancyNews(BOOL propVal)
{
	SetProperty(0x5, VT_BOOL, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// CNetscapeNetwork operations

void CNetscapeNetwork::Close()
{
	InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

short CNetscapeNetwork::Read(BSTR* pBuffer, short iAmount)
{
	short result;
	static BYTE BASED_CODE parms[] =
		VTS_PBSTR VTS_I2;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		pBuffer, iAmount);
	return result;
}

long CNetscapeNetwork::GetStatus()
{
	long result;
	InvokeHelper(0x8, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL CNetscapeNetwork::Open(LPCTSTR pURL, short iMethod, LPCTSTR pPostData, long lPostDataSize, LPCTSTR pPostHeaders)
{
	BOOL result;
	static BYTE BASED_CODE parms[] =
		VTS_BSTR VTS_I2 VTS_BSTR VTS_I4 VTS_BSTR;
	InvokeHelper(0x9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		pURL, iMethod, pPostData, lPostDataSize, pPostHeaders);
	return result;
}

CString CNetscapeNetwork::GetErrorMessage()
{
	CString result;
	InvokeHelper(0xa, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

short CNetscapeNetwork::GetServerStatus()
{
	short result;
	InvokeHelper(0xb, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
	return result;
}

long CNetscapeNetwork::GetContentLength()
{
	long result;
	InvokeHelper(0xc, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

CString CNetscapeNetwork::GetContentType()
{
	CString result;
	InvokeHelper(0xd, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString CNetscapeNetwork::GetContentEncoding()
{
	CString result;
	InvokeHelper(0xe, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString CNetscapeNetwork::GetExpires()
{
	CString result;
	InvokeHelper(0xf, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString CNetscapeNetwork::GetLastModified()
{
	CString result;
	InvokeHelper(0x10, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString CNetscapeNetwork::Resolve(LPCTSTR pBase, LPCTSTR pRelative)
{
	CString result;
	static BYTE BASED_CODE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x11, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		pBase, pRelative);
	return result;
}

BOOL CNetscapeNetwork::IsFinished()
{
	BOOL result;
	InvokeHelper(0x12, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

short CNetscapeNetwork::BytesReady()
{
	short result;
	InvokeHelper(0x13, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
	return result;
}

