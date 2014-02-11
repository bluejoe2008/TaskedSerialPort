// SerialPort.h: interface for the CSerialPort class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SerialPort_H__AD808C48_F413_484A_9B54_A481FA3D2B7E__INCLUDED_)
#define AFX_SerialPort_H__AD808C48_F413_484A_9B54_A481FA3D2B7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxmt.h>

#define IDU_COMM_EVENT	(WM_USER + 100)
#define EV_DISCONNECT	192

class CSerialPort  
{
public:
	void AssertConnected();
	CWinThread * GetListener();
	CString ReadAll();

	CWinThread * EnableListener(BOOL bEnable = TRUE);
	BOOL SetDCB(DCB * pDCB, int nHandshaking);

	enum
	{
		comNone,
			comXOnXOff,
			comRTS,
			comRTSXOnXOff
	};

	BOOL IsConnected();

	BOOL GetOverlappedResult(OVERLAPPED * pol, DWORD * pLength, BOOL bWait);
	BOOL GetTimeouts(COMMTIMEOUTS * cto);
	BOOL SetTimeouts(COMMTIMEOUTS * cto);
	BOOL Purge(DWORD nFlags);
	BOOL GetComStat(COMSTAT * pcs);
	UINT CommThread();

	BOOL ClearOutputBuffer();
	BOOL ClearInputBuffer();
	BOOL FlushOutputBuffer();

	BOOL SetDCB(DCB * pDCB);
	HANDLE GetHandle();
	BOOL Open(int nPort);

	BOOL GetDCB(DCB * pDCB);
	BOOL SetDCB(UINT nBaudRate, BYTE cParity = NOPARITY, BYTE nByteSize = 8, BYTE nStopBits = ONESTOPBIT);

	BOOL Open(CString sPort);
	void Close();

	CString Read(BOOL bWait = FALSE);
	DWORD Read(char *pBuffer, DWORD nLength, BOOL bWait = FALSE);
	DWORD Write(char *pBuffer, DWORD nLength, DWORD nWaitLimit = INFINITE);
	DWORD Write(CString sBuffer, DWORD nWaitLimit = INFINITE);

	static UINT CommThread(LPVOID pParam);

	//开启监视线程，以事件方式通知
	CWinThread * StartListener(DWORD nEventMask = EV_BREAK | EV_ERR | EV_RXCHAR);
	//开启监视线程，以消息方式通知
	CWinThread * StartListener(CWnd * pOwner, UINT nNotifyMessageID = IDU_COMM_EVENT, DWORD nEventMask = EV_BREAK | EV_ERR | EV_RXCHAR);
	
	CSerialPort();
	virtual ~CSerialPort();

private:

	CWnd * m_pOwner;
	CWinThread * m_pThread;
	UINT m_nNotifyMessageID;
	OVERLAPPED m_osRead; // 用于重叠读
	OVERLAPPED m_osWrite; // 用于重叠写

	BOOL m_bConnected;
	volatile HANDLE m_hHandle;
	volatile HANDLE m_hShutDownEvent;

protected:

	virtual void OnDisconnect();
	virtual void OnEvent(DWORD nEvent);
	virtual void OnEvRLSD();
	virtual void OnEvErr();
	virtual void OnEvDSR();
	virtual void OnEvBreak();
	virtual void OnEvTxEmpty();
	virtual void OnEvRXFlag();
	virtual void OnEvRxChar();
	virtual void OnEvRing();
	virtual void OnEvCTS();
};

#endif // !defined(AFX_SerialPort_H__AD808C48_F413_484A_9B54_A481FA3D2B7E__INCLUDED_)
