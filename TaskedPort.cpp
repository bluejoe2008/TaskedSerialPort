// TaskedPort.cpp: implementation of the CTaskedPort class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TaskedPort.h"
#include "Logger.h"
#include "Stringtokenizer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTaskedPort::CTaskedPort()
{
}

CTaskedPort::~CTaskedPort()
{
	if(m_pFGTask)
	{
		m_pFGTask->AbortTask();
		m_pFGTask = NULL;
	}
	
	if(m_pBGTask)
	{
		m_pBGTask->AbortTask();
		m_pBGTask = NULL;
	}
	
}

void CTaskedPort::OnEvRxChar()
{
	CSingleLock sl(&m_Mutex);
	sl.Lock();
	//接收字符
	
	CString sInput;
	sInput = ReadAll();
	TRACE("\r\nreceived<<%s\r\n", sInput);
	TRACE("\r\n当前TASK %s...\r\n", m_pFGTask ? m_pFGTask->m_sTaskName : "<无>");
	TRACE("m_pFGTask == %p\r\n", m_pFGTask);
	
	//优先处理前台任务
	if(m_pFGTask)
	{
		TRACE("\r\n处理TASK %s...\r\n", m_pFGTask->m_sTaskName);
		if(m_pFGTask->Catch(sInput) != -1)
		{
			//控制权转交后台任务
			m_pFGTask = NULL;
			
			if(m_pBGTask)
				m_pBGTask->ResetTask();
		}
		return;
	}
	
	//处理后台任务
	if(m_pBGTask)
	{
		if(m_pBGTask->Catch(sInput) != -1)
		{
			//继续新任务
			m_pBGTask->ResetTask();
		}
	}
}

CPortTask::CPortTask(CString sTaskName)
{
	m_hCompleteEvent = NULL;
	m_pOwner = NULL;
	m_pOwnerPort = NULL;
	m_nLimit = 0xFFFF;
	m_sTaskName = sTaskName;

	ResetTask();
}

CPortTask::~CPortTask()
{
	EndTask();
}

BOOL CTaskedPort::Open(CString sPort)
{
	if(!CSerialPort::Open(sPort))
		return FALSE;
	
	StartListener();
	return TRUE;
}

void CTaskedPort::UnloadTask(CPortTask *pTask)
{
	CSingleLock sl(&m_Mutex);
	sl.Lock();
	
	if(pTask == m_pFGTask)
		m_pFGTask = NULL;
	
	if(pTask == m_pBGTask)
		m_pBGTask = NULL;
}

int CPortTask::AddMatch(CString sMatch, int nValue)
{
	m_sMatches.Add(sMatch);
	int nWhich = m_nMatchCodes.Add(nValue);
	
	return nWhich;
}

int CPortTask::AddMatch(CString sMatch)
{
	return AddMatch(sMatch, m_nMatchCodes.GetSize());
}

int CPortTask::AddMatches(CString sMatches)
{
	CStringTokenizer st(sMatches, "|");
	CStringArray * psa = st.GetTokens();
	int nCount = 0;
	
	for(int i = 0; i < psa->GetSize(); i++)
	{
		if(AddMatch(psa->GetAt(i)))
			nCount++;
	}
	
	return nCount;
}

DWORD CTaskedPort::SendCommand(CString sCommand, DWORD nIdleTimeLimit)
{
	//ASSERT(sCommand.Right(1) == "\r" || sCommand.Right(1) == 26);
	TRACE("\r\nsend>>" + sCommand + "\r\n");

	::Logger.Log("发送命令>>%s", sCommand);

	return Write(sCommand, nIdleTimeLimit);
}

int CTaskedPort::Request(CString sRequest, CString & sResponse, int nEndCondition, CWaiting * pWaiting, char * sFind, CString sTaskName, DWORD nIdleTimeLimit)
{
	AssertConnected();
	Purge(PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);

	///////////////////////////////
	////构造TASK
	//////////////////////////////

	if(sTaskName.IsEmpty())
		sTaskName = sRequest;

	CPortTask Task(sTaskName);
	
	if(nEndCondition & ecOkOrError)
		Task.AddMatches("ERROR|OK");
	
	if(nEndCondition & ecCrlf)
		Task.AddMatch("\r");
	
	if(sFind)
		Task.AddMatches(sFind);
	
	//设置停止标志
	if(Task.GetMatches()->GetSize())
		nEndCondition |= ecWaiting;
	else
		nEndCondition &= ~ecWaiting;
	
	if(nEndCondition & ecDirty)
		nEndCondition |= ecWaiting;
	
	///////////////////////////////
	////载入TASK
	//////////////////////////////

	LoadFGTask(&Task);

	//发送命令
	if(SendCommand(sRequest, nIdleTimeLimit) <= 0)
	{
		return -1;
	}

	WaitForTask(&Task, nEndCondition, pWaiting, nIdleTimeLimit);

	sResponse = Task.GetInputBuffer();
	::Logger.Log("接收数据<<%s", sResponse);

	return Task.GetMatchCode();
}

CString CTaskedPort::Request(CString sRequest, int nEndCondition, CWaiting * pWaiting, char * sFind, CString sTaskName, DWORD nIdleTimeLimit)
{
	CString sResponse;
	Request(sRequest, sResponse, nEndCondition, pWaiting, sFind, sTaskName, nIdleTimeLimit);
	
	return sResponse;
}

void CTaskedPort::LoadBGTask(CPortTask *pTask)
{
	CSingleLock sl(&m_Mutex);
	sl.Lock();
	
	if(m_pBGTask)
	{
		TRACE("旧任务:%s\r\n", m_pBGTask->m_sTaskName);
		TRACE("新任务:%s\r\n", pTask->m_sTaskName);
		
		m_pBGTask->AbortTask();
	}
	
	m_pBGTask = pTask;
	
	if(pTask)
	{
		pTask->SetOwner(this);
		pTask->ResetTask();
	}
}

void CTaskedPort::LoadFGTask(CPortTask *pTask)
{
	CSingleLock sl(&m_Mutex);
	sl.Lock();
	
	if(m_pFGTask)
	{
		TRACE("旧任务:%s\r\n", m_pFGTask->m_sTaskName);
		TRACE("新任务:%s\r\n", pTask->m_sTaskName);

		::Logger.Log("警告：旧任务[%s]与新任务[%s] 发生冲突！", 
			m_pFGTask->m_sTaskName, 
			pTask->m_sTaskName);
		
		m_pFGTask->AbortTask();
	}
	
	m_pFGTask = pTask;
	TRACE("设置前台TASK: %s\r\n", pTask->m_sTaskName);
	TRACE("m_pFGTask == %p\r\n", m_pFGTask);
	
	if(pTask)
	{
		pTask->SetOwner(this);
		pTask->ResetTask();
	}
}

void CPortTask::OnTaskCompleted()
{
	//do nothing...
}

BOOL CPortTask::IsCompleted()
{
	CSingleLock sl(&m_Mutex);
	sl.Lock();

	return m_bCompleted;
}

void CPortTask::ResetTask()
{
	m_bCompleted = FALSE;
	m_sFullInput.Empty();
	
	if(m_hCompleteEvent)
		::ResetEvent(m_hCompleteEvent);
	
	m_nMatchIndex = -1;
	m_nDirty = 0;
	
}

int CPortTask::Catch(CString sInput)
{
	TRACE("Catch %s\r\n", sInput);

	CSingleLock sl(&m_Mutex);
	sl.Lock();

	m_nDirty++;

	if(m_nDirty >= 0x8000)
	{
		m_nDirty = 0;
	}
	
	CString sLastInput = m_sFullInput;
	m_sFullInput += sInput;
	
	//扔掉旧信息
	if(m_nLimit > 0 && m_sFullInput.GetLength() > m_nLimit)
	{
		m_sFullInput.Delete(0, m_sFullInput.GetLength() - m_nLimit);
	}
	
	for(int i = 0; i < m_sMatches.GetSize(); i++)
	{
		//查找指定的字符串
		CString sMatch = m_sMatches.GetAt(i);
		CString sCatch = sLastInput.Right(sMatch.GetLength()) + sInput;
		
		//找到匹配
		if(sCatch.Find(sMatch) != -1)
		{
			{
				m_nMatchIndex = i;
				break;;
			}
		}
	}
	
	//返回匹配码
	int nCode = GetMatchCode();
	if(nCode != -1)
	{
		CompleteTask();
	}
	
	return nCode;
}

void CPortTask::AttachEvent(HANDLE hEvent)
{
	m_hCompleteEvent = hEvent;
}

void CPortTask::AttachEvent(CWnd *pOwner, UINT nMessageID)
{
	m_pOwner = pOwner;
	m_nNotifyMessageID = nMessageID;
}

int CPortTask::GetMatchCode()
{
	if(!m_sMatches.GetSize())
		return 0;
	
	if(m_nMatchIndex == -1)
		return -1;
	
	return m_nMatchCodes.GetAt(m_nMatchIndex);
}

void CPortTask::CompleteTask()
{
	TRACE("TASK completed!\r\n");
	m_bCompleted = TRUE;
	OnTaskCompleted();
	
	//以下语句必须放在最后，以防止CPortTask析构提前产生
	if(m_pOwner)
	{
		m_pOwner->PostMessage(m_nNotifyMessageID, (WPARAM)this, (LPARAM)GetMatchCode());
	}
	
	if(m_hCompleteEvent)
	{
		::SetEvent(m_hCompleteEvent);
	}	
}

void CPortTask::SetOwner(CTaskedPort *pOwnerPort)
{
	m_pOwnerPort = pOwnerPort;
}

void CPortTask::EndTask()
{
	if(m_pOwnerPort)
	{
		m_pOwnerPort->UnloadTask(this);
	}
}

void CPortTask::AbortTask()
{
	EndTask();
}

void CPortTask::SetBufferSize(int nLimit)
{
	m_nLimit = nLimit;
}

int CPortTask::GetDirty()
{
	return m_nDirty;
}

CString CPortTask::GetInputBuffer()
{
	return m_sFullInput;
}

CStringArray * CPortTask::GetMatches()
{
	return &m_sMatches;
}

void CTaskedPort::Close()
{
	UnloadTask(m_pBGTask);
	UnloadTask(m_pFGTask);

	CSerialPort::Close();
}

void CTaskedPort::WaitForTask(CPortTask *pTask, int nEndCondition, CWaiting * pWaiting, DWORD nIdleTimeLimit)
{
	int nDirty = 0;
	DWORD nStartTime = GetTickCount();
	
	while(!pTask->IsCompleted())
	{
		AssertConnected();

		//不需要等待
		if(!(nEndCondition & ecWaiting))
			break;
		
		//有数据
		int nNewDirty = pTask->GetDirty();
		if(nDirty != nNewDirty)
		{
			nDirty = nNewDirty;
			nStartTime = GetTickCount();
			
			//显示进度
			pWaiting->OnWaitChip(true);
			
			//有脏数据即返回
			if(nEndCondition & ecDirty)
				break;
		}

		//没有数据
		else
		{
			pWaiting->OnWaitChip(false);
			
			//是否有时限？
			if(nIdleTimeLimit != -1)
			{
				DWORD nEndTime = GetTickCount();
				
				//超时
				if(nEndTime - nStartTime > nIdleTimeLimit)
				{
					//提示是否继续等待
					if(nEndCondition & ecRetryPrompt)
					{
						if(::MessageBox(NULL, "数据等待时间过长，是否继续等待？", 
							"等待超时", 
							MB_YESNO | MB_ICONQUESTION) == IDNO)
						{
							throw new CTimeoutException();
						}
						//继续等待
						else
						{
							continue;
						}
					}
					
					//不允许超时
					if(!(nEndCondition & ecRetryAlways))
					{
						::Logger.Log("等待超时错误！");
						throw new CTimeoutException();
					}
				} // if(nEndTime - nStartTime > nIdleTimeLimit)
			} //if(nIdleTimeLimit != -1)
		} //if(nDirty == nNewDirty)
	} //while
	
	pWaiting->OnWaitChip(true);
}
