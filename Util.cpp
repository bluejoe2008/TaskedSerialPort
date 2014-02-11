// Util.cpp: implementation of the CUtil class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Util.h"
#include <afxinet.h>
#include <Winsock2.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void CUtil::ReportException(
							CException * e,
							CString sHeading,
							CString sCaption)
{
	TCHAR sCause[256];
	e->GetErrorMessage(sCause, 256);
	
	CString Prompt;
	Prompt.Format("%s:\r\n\r\n%s", sHeading, sCause);
	:: MessageBox(NULL, Prompt, sCaption, MB_OK | MB_ICONEXCLAMATION);
	e->Delete();
}

CString CUtil::GetFilePathFromFileName(CString FileName)
{
	int Where;
	Where = FileName.ReverseFind('\\');
	if (Where == -1)
		Where = FileName.ReverseFind('/');
	CString FilePath = FileName.Left(Where);
	return FilePath + '\\';
}

bool CUtil::IsReachableURL(CString sURL)
{
	CInternetSession Session;
	CHttpFile * pFile;
	try
	{
		pFile = (CHttpFile *) Session.OpenURL(sURL);
	}
	catch (CException * e)
	{
		e->Delete();
		pFile = NULL;
	}
	return (pFile != NULL);
}

CString CUtil::GetFileTitleFromFileName(CString FileName, BOOL Ext)
{
	int Where;
	Where = FileName.ReverseFind('\\');
	if (Where == -1)
		Where = FileName.ReverseFind('/');
	CString FileTitle = FileName.Right(FileName.GetLength() - 1 - Where);
	if (!Ext)
	{
		int Which = FileTitle.ReverseFind('.');
		if (Which != -1)
			FileTitle = FileTitle.Left(Which);
	}
	return FileTitle;
}

int CUtil::MultiLineTextOut(
							CDC * pDC,
							int x,
							int y,
							CString Text,
							int LineSpace)
{
	TEXTMETRIC Metric;
	if (pDC->GetOutputTextMetrics(& Metric))
	{
		LineSpace += Metric.tmHeight;
	}
	
	int Lines = 0;
	int Length = Text.GetLength();
	int Start = 0;
	for (int i = 0; i < Length; i++)
	{
		if (Text.GetAt(i) == '\n')
		{
			Lines++;
			pDC->TextOut(x, y, Text.Mid(Start, i - Start));
			y += LineSpace;
			Start = i + 1;
		}
	}
	pDC->TextOut(x, y, Text.Mid(Start, i - Start));
	return Lines;
}

//推荐使用CIpTable

CString CUtil::GetLocalIp()
{
	struct hostent * phost;
	char ip[20];
	char hostname[50];
	
	gethostname(hostname, 50);
	phost = gethostbyname(hostname);
	char * * names;
	names = phost->h_aliases;
	char * * iplist;
	iplist = phost->h_addr_list;
	while (* iplist)
	{
		strcpy(ip, inet_ntoa(* (struct in_addr *) * iplist));
		iplist++;
	}
	
	CString LocalIp = ip;
	return LocalIp;
}

void CUtil::Wait(int nDelay, UINT nMsgFilter)
{
	DWORD nStartTime = GetTickCount();
	while (true)
	{
		DWORD nEndTime = GetTickCount();
		if (nEndTime - nStartTime > (DWORD) nDelay)
			break;
		continue;
		
		PumpMessages(NULL, nMsgFilter);
	}
}

int CUtil::GetModemList(CString *pNameList, CString *pPortList)
{
	CRegKey RegKey;
	int nCount = 0;
	int nModemCount = 0;
	
	if(RegKey.Open(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Ras\\Tapi Devices") == ERROR_SUCCESS)
	{
		while(true)
		{
			char KeyName[_MAX_PATH];
			DWORD nSize;
			
			if(::RegEnumKey(HKEY(RegKey), nCount, KeyName, _MAX_PATH) == ERROR_NO_MORE_ITEMS)
			{
				break;
			}
			
			//读取该设备
			CRegKey Device;
			if(Device.Open(HKEY_LOCAL_MACHINE, (CString)"SOFTWARE\\Microsoft\\Ras\\Tapi Devices\\" + KeyName) == ERROR_SUCCESS)
			{
				//是否为Modem设备
				nSize = _MAX_PATH;
				
				char cValue[_MAX_PATH];
				Device.QueryValue(cValue, "Media Type", &nSize);
				CString sMediaType = cValue;
				if(sMediaType == "Modem")
				{
					if(pNameList)
					{
						nSize = _MAX_PATH;
						Device.QueryValue(cValue, "Friendly Name", &nSize);
						pNameList[nModemCount] = cValue;
					}
					
					if(pPortList)
					{
						nSize = _MAX_PATH;
						Device.QueryValue(cValue, "Address", &nSize);
						pPortList[nModemCount] = cValue;
					}
					nModemCount++;
				}
			}
			nCount++;
		}
	}
	
	return nModemCount;
}

int CUtil::GetSystemPorts(CString *pNameList, CString *pPortList)
{
	CRegKey RegKey;
	int nCount = 0;
	
	if(RegKey.Open(HKEY_LOCAL_MACHINE, "Hardware\\DeviceMap\\SerialComm") == ERROR_SUCCESS)
	{
		while(true)
		{
			char ValueName[_MAX_PATH];
			unsigned char ValueData[_MAX_PATH];
			DWORD nValueSize = _MAX_PATH;
			DWORD nDataSize = _MAX_PATH;
			DWORD nType;
			
			if(::RegEnumValue(HKEY(RegKey), nCount, ValueName, &nValueSize, NULL, &nType, ValueData, &nDataSize) == ERROR_NO_MORE_ITEMS)
			{
				break;
			}
			
			if(pNameList)
				pNameList[nCount] = ValueName;
			
			if(pPortList)
				pPortList[nCount] = ValueData;
			
			nCount++;
		}
	}
	
	return nCount;
}


void CUtil::PumpMessages(HWND hWnd, UINT nMsgFilter)
{
	MSG msg;
	// Handle dialog messages
	while(::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		//需要过滤的消息
		if(nMsgFilter && nMsgFilter == msg.message)
		{
			continue;
		}

		if(!::IsDialogMessage(hWnd, &msg))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg); 
		}
	}

}
