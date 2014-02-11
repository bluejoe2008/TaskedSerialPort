// Util.h: interface for the CUtil class.
//
//////////////////////////////////////////////////////////////////////
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "shlwapi.lib")

#if !defined(AFX_UTIL_H__E955E09F_8ACB_41C5_B1D3_15CCFCFDE941__INCLUDED_)
#define AFX_UTIL_H__E955E09F_8ACB_41C5_B1D3_15CCFCFDE941__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <shlobj.h>

class CUtil  
{
public:

	void PumpMessages(HWND hWnd, UINT nMsgFilter = NULL);
	int GetSystemPorts(CString *pNameList, CString *pPortList);
	int GetModemList(CString * pNameList, CString * pPortList);
	void Wait(int nDelay, UINT nMsgFilter = NULL);
	CString GetLocalIp();
	int MultiLineTextOut(CDC *pDC, int x, int y, CString Text,int LineSpace = 0);
	CString GetFileTitleFromFileName(CString FileName,BOOL Ext);
	bool IsReachableURL(CString sURL);
	CString GetFilePathFromFileName(CString FileName);
	void ReportException(CException * e, CString sHeading, CString sCaption);
};

#endif // !defined(AFX_UTIL_H__E955E09F_8ACB_41C5_B1D3_15CCFCFDE941__INCLUDED_)
