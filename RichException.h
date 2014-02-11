// RichException.h: interface for the CRichException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RICHEXCEPTION_H__3B379AE3_0D7C_4BB9_A06E_C9FC82A6C70B__INCLUDED_)
#define AFX_RICHEXCEPTION_H__3B379AE3_0D7C_4BB9_A06E_C9FC82A6C70B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRichException : public CException  
{
public:
	int ReportError(UINT nType = MB_OK, UINT nMessageID = 0);
	BOOL GetErrorMessage( LPTSTR sErrorMessage, UINT nCount, PUINT pHelpContext = NULL);
	int ReportError(CWnd *pWnd, LPCTSTR sCaption = NULL, UINT nType = MB_OK | MB_ICONERROR);
	int GetErrorLevel();
	CString GetErrorField();
	
	enum
	{
		reGeneral,
			reSystem,
			reFatal,
	};
	
	void SetError(int nErrorCode, CString sErrorMessage, int nErrorLevel = reGeneral, LPCTSTR sErrorClause = NULL);
	int GetErrorCode();
	CString GetErrorMessage();
	CString GetErrorClause();
	CRichException();
	virtual ~CRichException();
	
protected:
	int m_nErrorCode;
	int m_nErrorLevel;
	CString m_sErrorField;
	CString m_sErrorClause;
	CString m_sErrorMessage;
};

class CTimeoutException : public CException
{
public:
	int ReportError(UINT nType = MB_OK, UINT nMessageID = 0);
};

class COffLineException : public CException
{
public:
	int ReportError(UINT nType = MB_OK, UINT nMessageID = 0);
};

class CUserAbortException : public CException
{
public:
	int ReportError(UINT nType, UINT nMessageID);
};

#endif // !defined(AFX_RICHEXCEPTION_H__3B379AE3_0D7C_4BB9_A06E_C9FC82A6C70B__INCLUDED_)
