//SerialPort.cpp: implementation of the CSerialPort class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SerialPort.h"
#include "Logger.h"
#include "RichException.h"
#include "Win32Exception.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
//Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSerialPort::CSerialPort()
{
	m_pOwner = NULL;
	m_pThread = NULL;
	m_hHandle = NULL;
	m_bConnected = FALSE;
	m_hShutDownEvent = NULL;
}

CSerialPort::~CSerialPort()
{
	Close();
}

BOOL CSerialPort::Open(CString sPort)
{
	m_hHandle = ::CreateFile(sPort, GENERIC_READ | GENERIC_WRITE, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 
		NULL); //重叠方式
	
	if(m_hHandle == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}
	
	memset(&m_osRead, 0, sizeof(OVERLAPPED));
	memset(&m_osWrite, 0, sizeof(OVERLAPPED));
	
	//为重叠读创建事件对象，手工重置，初始化为无信号的
	if(!(m_osRead.hEvent = ::CreateEvent(NULL, TRUE, FALSE, NULL)))
		return FALSE;
	
	//为重叠写创建事件对象，手工重置，初始化为无信号的
	if(!(m_osWrite.hEvent = ::CreateEvent(NULL, TRUE, FALSE, NULL)))
		return FALSE;
	
	//为关闭连接创建事件对象，手工重置，初始化为无信号的
	if(!(m_hShutDownEvent = ::CreateEvent(NULL, TRUE, FALSE, NULL)))
		return FALSE;
	
	m_bConnected = TRUE;
	return TRUE;
}


BOOL CSerialPort::Open(int nPort)
{
	CString sPort;
	sPort.Format("COM%d", nPort);
	
	return Open(sPort);
}

CWinThread * CSerialPort::StartListener(DWORD nEventMask)
{
	::SetCommMask(m_hHandle, nEventMask);

	::Logger.Log("开启监听线程...");
	m_pThread = AfxBeginThread(CommThread, this, THREAD_PRIORITY_NORMAL, 
		0, CREATE_SUSPENDED, NULL); //创建并挂起线程
	
	m_pThread->ResumeThread();
	return m_pThread;
}

CWinThread * CSerialPort::StartListener(CWnd *pOwner, UINT nNotifyMessageID, DWORD nEventMask)
{
	m_pOwner = pOwner;
	m_nNotifyMessageID = nNotifyMessageID;
	
	return StartListener(nEventMask);
}

void CSerialPort::OnEvent(DWORD nEvent)
{
	switch(nEvent)
	{
	case EV_BREAK:
		{
			OnEvBreak();
			break;
		}
	case EV_CTS:
		{
			OnEvCTS();
			break;
		}
	case EV_DSR:
		{
			OnEvDSR();
			break;
		}
	case EV_ERR:
		{
			OnEvErr();
			break;
		}
	case EV_RING:
		{
			OnEvRing();
			break;
		}
	case EV_RLSD:
		{
			OnEvRLSD();
			break;
		}
	case EV_RXCHAR:
		{
			OnEvRxChar();
			break;
		}
	case EV_RXFLAG:
		{
			OnEvRXFlag();
			break;
		}
	case EV_TXEMPTY:
		{
			OnEvTxEmpty();
			break;
		}
		
	case EV_DISCONNECT:
		{
			OnDisconnect();
			break;
		}
	}
}

void CSerialPort::Close()
{
	if(!m_bConnected)
		return;
	
	m_bConnected = FALSE;
	
	::SetEvent(m_hShutDownEvent);
	//结束CommProc线程中WaitCommEvent的等待
	
	::SetCommMask(m_hHandle, 0); 
	
	//等待辅助线程终止
	if(m_pThread)
	{
		//可能已挂起
		m_pThread->ResumeThread();

		TRACE("正在等待线程关闭...\r\n");
		::WaitForSingleObject(m_pThread->m_hThread, INFINITE);
		TRACE("线程已关闭！\r\n");
	}
	
	m_pThread = NULL;
	
	if(m_hHandle)
		::CloseHandle(m_hHandle);
	
	if(m_hShutDownEvent)
		::CloseHandle(m_hShutDownEvent);
	
	if(m_osRead.hEvent)
		CloseHandle(m_osRead.hEvent);
	
	if(m_osWrite.hEvent)
		CloseHandle(m_osWrite.hEvent);
}

UINT CSerialPort::CommThread(LPVOID pParam)
{
	CSerialPort *pSerialPort = (CSerialPort*)pParam;
	return pSerialPort->CommThread();
}

DWORD CSerialPort::Read(char *pBuffer, DWORD nLength, BOOL bWait)
{
	AssertConnected();
	
	memset(pBuffer, 0, nLength);
	COMSTAT cs;
	GetComStat(&cs);
	
	if(cs.cbInQue < nLength)
		nLength = cs.cbInQue; 
	
	if(!nLength)
		return 0;
	
	if(!ReadFile(m_hHandle, pBuffer, nLength, &nLength, &m_osRead))
	{
		DWORD nError = ::GetLastError();
		if(nError == ERROR_IO_PENDING)
		{
			//等待之
			GetOverlappedResult(&m_osRead, &nLength, bWait);
		}
		else
		{
			throw new CWin32Exception(nError);
		}
	}
	
	return nLength;
}

DWORD CSerialPort::Write(char *pBuffer, DWORD nLength, DWORD nWaitLimit)
{
	AssertConnected();
	
	if(!WriteFile(m_hHandle, pBuffer, nLength, &nLength, &m_osWrite))
	{
		DWORD nError = ::GetLastError();
		if(nError == ERROR_IO_PENDING)
		{
			//同步操作
			if(nWaitLimit)
			{
				//等待之
				if(WaitForSingleObject(m_osWrite.hEvent, nWaitLimit) != WAIT_OBJECT_0)
				{
					//超时，取消当前操作
					Purge(PURGE_RXABORT);
				}

				GetOverlappedResult(&m_osWrite, &nLength, FALSE);
			}
		}
		else
		{
			throw new CWin32Exception(nError);
		}
	}
	
	::Logger.Log("%d bytes sent.", nLength);
	return nLength;
}

BOOL CSerialPort::GetDCB(DCB * pDCB)
{
	return ::GetCommState(m_hHandle, pDCB);
}

HANDLE CSerialPort::GetHandle()
{
	AssertConnected();
	return m_hHandle;
}

BOOL CSerialPort::SetDCB(UINT nBaudRate, BYTE cParity, BYTE nByteSize, BYTE nStopBits)
{
	DCB dcb;
	GetDCB(&dcb);
	
	dcb.BaudRate = nBaudRate;
	dcb.Parity = cParity;
	dcb.ByteSize = nByteSize;
	dcb.StopBits = nStopBits;
	
	return SetDCB(&dcb);
}

BOOL CSerialPort::SetDCB(DCB * pDCB)
{
	pDCB->DCBlength = sizeof(DCB);
	pDCB->fParity = (pDCB->Parity != NOPARITY);
	
	return ::SetCommState(m_hHandle, pDCB);
}

DWORD CSerialPort::Write(CString sBuffer, DWORD nWaitLimit)
{
	return Write((LPSTR)(LPCTSTR)sBuffer, sBuffer.GetLength(), nWaitLimit);
}

BOOL CSerialPort::FlushOutputBuffer()
{
	AssertConnected();
	return ::FlushFileBuffers(m_hHandle);
}

BOOL CSerialPort::ClearInputBuffer()
{
	AssertConnected();
	return Purge(PURGE_RXCLEAR);
}

BOOL CSerialPort::ClearOutputBuffer()
{
	AssertConnected();
	return Purge(PURGE_TXCLEAR);
}

void CSerialPort::OnEvBreak()
{
	TRACE("A break was detected on input. \r\n");
}

void CSerialPort::OnEvCTS()
{
	TRACE("The CTS (clear-to-send) signal changed state. \r\n");
}

void CSerialPort::OnEvDSR()
{
	TRACE("The DSR (data-set-ready) signal changed state. \r\n");
}

void CSerialPort::OnEvErr()
{
	TRACE("A line-status error occurred. Line-status errors are CE_FRAME, CE_OVERRUN, and CE_RXPARITY. \r\n");
}

void CSerialPort::OnEvRing()
{
	TRACE("A ring indicator was detected. \r\n");
}

void CSerialPort::OnEvRLSD()
{
	TRACE("The RLSD (receive-line-signal-detect) signal changed state. \r\n");
}

void CSerialPort::OnEvRxChar()
{
	TRACE("A character was received and placed in the input buffer. \r\n");
}

void CSerialPort::OnEvRXFlag()
{
	TRACE("The event character was received and placed in the input buffer. \r\n");
}

void CSerialPort::OnEvTxEmpty()
{
	TRACE("The last character in the output buffer was sent. \r\n");
}

void CSerialPort::OnDisconnect()
{
	TRACE("The connection was interrupted. \r\n");
}

UINT CSerialPort::CommThread()
{
	OVERLAPPED ol;
	memset(&ol, 0, sizeof(OVERLAPPED));
	ol.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	
	HANDLE ah[2];
	ah[0] = m_hShutDownEvent;
	ah[1] = ol.hEvent;
	
	Purge(PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);
	
	while(m_bConnected)
	{
		DWORD nEvent = 0;
		
		//清除错误
		COMSTAT cs;
		GetComStat(&cs);
		
		//开始接收事件
		::WaitCommEvent(m_hHandle, &nEvent, &ol);

		UINT nHappened = ::WaitForMultipleObjects(sizeof(ah) / sizeof(HANDLE), ah, false, INFINITE);
		
		if(!m_bConnected)
			return -1;

		//等待至接收到事件或者连接中断
		switch(nHappened)
		{
		case 0:
			{
				//关闭连接
				return 0;
			}
		case 1:
			{
				if(m_pOwner)
				{
					::PostMessage(m_pOwner->m_hWnd, m_nNotifyMessageID, 
						nEvent, (WPARAM)this);
				}
				else
				{
					OnEvent(nEvent);
				}
			}
		}
	}
	
	CloseHandle(ol.hEvent);
	return 0;
}

BOOL CSerialPort::GetComStat(COMSTAT * pcs)
{
	DWORD nFlags;
	return ::ClearCommError(m_hHandle, &nFlags, pcs);
}

BOOL CSerialPort::Purge(DWORD nFlags)
{
	return ::PurgeComm(m_hHandle, nFlags);
}

BOOL CSerialPort::SetTimeouts(COMMTIMEOUTS *cto)
{
	return ::SetCommTimeouts(m_hHandle, cto);
}

BOOL CSerialPort::GetTimeouts(COMMTIMEOUTS *cto)
{
	return ::GetCommTimeouts(m_hHandle, cto);
}

BOOL CSerialPort::GetOverlappedResult(OVERLAPPED *pol, DWORD *pLength, BOOL bWait)
{
	return ::GetOverlappedResult(m_hHandle, pol, pLength, bWait);
}

CString CSerialPort::Read(BOOL bWait)
{
	char cBuffer[1024];
	Read(cBuffer, 1024, bWait);
	
	return (CString)cBuffer;
}

BOOL CSerialPort::IsConnected()
{
	return m_bConnected;
}

BOOL CSerialPort::SetDCB(DCB *pDCB, int nHandshaking)
{
	switch(nHandshaking)
	{
	case comNone:
		
		pDCB->fInX = 0;
		pDCB->fOutX = 0;
		pDCB->fRtsControl = 1;
		pDCB->fOutxCtsFlow = 0;
		
		break;
		
	case comXOnXOff:
		
		pDCB->fInX = 1;
		pDCB->fOutX = 1;
		pDCB->fRtsControl = 1;
		pDCB->fOutxCtsFlow = 0;
		
		break;
		
	case comRTS:
		
		pDCB->fInX = 0;
		pDCB->fOutX = 0;
		pDCB->fRtsControl = 2;
		pDCB->fOutxCtsFlow = 1;
		
		break;
		
	case comRTSXOnXOff:
		
		pDCB->fInX = 1;
		pDCB->fOutX = 1;
		pDCB->fRtsControl = 2;
		pDCB->fOutxCtsFlow = 1;
		
		break;
	}
	
	return SetDCB(pDCB);
}

CWinThread * CSerialPort::EnableListener(BOOL bEnable)
{
	if(m_pThread)
	{
		if(bEnable)
		{
			::Logger.Log("继续打开监听线程...");
			m_pThread->ResumeThread(); 
		}
		else
		{
			::Logger.Log("暂时关闭监听线程...");
			m_pThread->SuspendThread();
		}
	}
	
	return m_pThread;
}

CString CSerialPort::ReadAll()
{
	CString sInput;
	char cBuffer[1024];

	while(Read(cBuffer, 1024, FALSE))
	{
		sInput += cBuffer;
	}

	return sInput;
}

CWinThread * CSerialPort::GetListener()
{
	return m_pThread;
}

void CSerialPort::AssertConnected()
{
	if(!IsConnected())
	{
		throw new COffLineException();
	}
}
