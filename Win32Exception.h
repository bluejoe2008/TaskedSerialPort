// Win32Exception.h: interface for the CWin32Exception class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WIN32EXCEPTION_H__617B2602_DBDA_4AC5_922A_411E8AD37AB8__INCLUDED_)
#define AFX_WIN32EXCEPTION_H__617B2602_DBDA_4AC5_922A_411E8AD37AB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWin32Exception : public CException  
{
public:
	int ReportError(UINT nType = MB_OK, UINT nMessageID = 0);
	BOOL GetErrorMessage( LPTSTR lpszError, UINT nMaxError, PUINT pnHelpContext = NULL);
	void ParseError();

	DWORD m_nErrorCode;
	CString m_sErrorName;
	CString m_sErrorDescription;
	CString m_sErrorLabel;

	CWin32Exception(DWORD nErrorCode);
	virtual ~CWin32Exception();

private:
};

#endif // !defined(AFX_WIN32EXCEPTION_H__617B2602_DBDA_4AC5_922A_411E8AD37AB8__INCLUDED_)
