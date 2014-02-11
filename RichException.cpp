// RichException.cpp: implementation of the CRichException class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RichException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRichException::CRichException()
{
	m_nErrorCode = 0;
	m_nErrorLevel = reGeneral;
	m_sErrorMessage = "没有任何错误！";
}

CRichException::~CRichException()
{
	
}

CString CRichException::GetErrorMessage()
{
	return m_sErrorMessage;
}

int CRichException::GetErrorCode()
{
	return m_nErrorCode;
}

void CRichException::SetError(int nErrorCode, CString sErrorMessage, int nErrorLevel, LPCTSTR sErrorClause)
{
	m_nErrorCode = nErrorCode;
	m_sErrorMessage = sErrorMessage;
	m_nErrorLevel = nErrorLevel;
	if(sErrorClause)
	{
		m_sErrorClause = sErrorClause;
	}
}

CString CRichException::GetErrorClause()
{
	return m_sErrorClause;
}

CString CRichException::GetErrorField()
{
	return m_sErrorField;
}

int CRichException::GetErrorLevel()
{
	return m_nErrorLevel;
}

int CRichException::ReportError(CWnd *pWnd, LPCTSTR sCaption, UINT nType)
{
	if(!sCaption)
		sCaption = "发生异常";
	
	CString sErrorLevel;
	sErrorLevel.Format("%d", m_nErrorLevel);
	switch(m_nErrorLevel)
	{
	case reGeneral : 
		sErrorLevel += " (一般性异常)";
		break;
	case reSystem : 
		sErrorLevel += " (系统级异常)";
		break;
	case reFatal : 
		sErrorLevel += " (致命级异常)";
		break;
	}
	
	CString sBody;
	sBody.Format(
		"系统在执行操作时发生异常，详细信息如下:\r\n\r\n"
		"错误内码: 0x%x\r\n"
		"错误信息: %s\r\n\r\n"
		"错误级别: %s\r\n"
		"错误类别: %s",
		m_nErrorCode,
		m_sErrorMessage,
		sErrorLevel,
		m_sErrorField);
	
	if(!m_sErrorClause.IsEmpty())
	{
		sBody += "\r\n\r\n造成该异常可能存在以下原因:\r\n\r\n";
		sBody += m_sErrorClause;
	}
	
	if(pWnd)
		return pWnd->MessageBox(sBody, sCaption, nType);
	else
		return MessageBox(NULL, sBody, sCaption, nType);
}

BOOL CRichException::GetErrorMessage(LPTSTR sErrorMessage, UINT nCount, PUINT pHelpContext)
{
	strcpy(sErrorMessage, m_sErrorMessage);
	return TRUE;
}

int CRichException::ReportError(UINT nType, UINT nMessageID)
{
	return IDOK;
}

int COffLineException::ReportError(UINT nType, UINT nMessageID)
{
	ASSERT(0);
	//屏蔽MessageBox操作
	return IDOK;
}

int CTimeoutException::ReportError(UINT nType, UINT nMessageID)
{
	ASSERT(0);
	//屏蔽MessageBox操作
	return IDOK;
}

int CUserAbortException::ReportError(UINT nType, UINT nMessageID)
{
	ASSERT(0);
	//屏蔽MessageBox操作
	return IDOK;
}
