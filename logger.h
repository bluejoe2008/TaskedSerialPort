// logger.h: interface for the CLogger class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGGER_H__C37701FA_4547_4F07_8B9A_C8779DD9ACE1__INCLUDED_)
#define AFX_LOGGER_H__C37701FA_4547_4F07_8B9A_C8779DD9ACE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLogger  
{
public:
	CString m_sTimeFormat;

	bool m_bDumb;

	CLogger();
	~CLogger();

	void SetDumb(bool bDumb = true);
	void Log(char * format, ...);

	void AttachFile(CString sLogPath, bool bDumb = false);

private:

	CString m_sLogPath;
};

extern CLogger Logger;
#endif // !defined(AFX_LOGGER_H__C37701FA_4547_4F07_8B9A_C8779DD9ACE1__INCLUDED_)
