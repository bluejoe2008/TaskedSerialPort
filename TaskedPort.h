// TaskedPort.h: interface for the CTaskedPort class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASKEDPORT_H__55962DCB_4955_4ACA_A605_74F41A464656__INCLUDED_)
#define AFX_TASKEDPORT_H__55962DCB_4955_4ACA_A605_74F41A464656__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define IDU_TASK_COMPLETE	(WM_USER + 101)

#include "SerialPort.h"
#include "RichException.h"
#include "Waiting.h"

/*
CTaskedPort任务类
用户可以指定任务的目标，即待查找的一组匹配字符串以及相应的匹配码
任务完成时可以通过以下途径通知用户：

  1. 给窗口发送消息；
  2. 设置事件为有信号；
  3. 调用OnTaskCompleted()方法；
  4. 简单地设置成员变量m_bCompleted；
  
*/
class CTaskedPort;

class CPortTask
{
protected:
	
	CStringArray m_sMatches;
	CByteArray m_nMatchCodes;
	int m_nLimit;
	HANDLE m_hCompleteEvent;
	BOOL m_bCompleted;
	CWnd * m_pOwner;
	UINT m_nNotifyMessageID;

	CMutex m_Mutex;
	
	int m_nMatchIndex;
	int m_nDirty; //数据脏计数，每次接收到数据，该计数自动加1
	
	CTaskedPort * m_pOwnerPort;
	CString m_sFullInput; //该任务消化的字符
	
	void EndTask(); //结束当前任务
	void CompleteTask(); //完成当前任务
	
public:
	CStringArray * GetMatches();
	
	CString m_sTaskName;
	CString GetInputBuffer();
	
	int GetDirty();
	
	void SetBufferSize(int nLimit); //设置缓冲区长度
	void AbortTask(); //取消当前任务
	void ResetTask(); //重置当前任务
	
	void SetOwner(CTaskedPort * pOwnerPort); //设置隶属CTaskedPort
	int GetMatchCode(); //获取匹配码
	
	CPortTask(CString sTaskName);
	~CPortTask();
	
	void AttachEvent(CWnd * pOwner, UINT nMessageID = IDU_TASK_COMPLETE); //设置消息通知方式
	void AttachEvent(HANDLE hEvent); //设置事件通知方式
	
	int Catch(CString sInput); //消化字符串
	
	BOOL IsCompleted(); //指定该任务是否已完成
	
	virtual void OnTaskCompleted();
	
	int AddMatches(CString sMatches); //添加多个匹配项，匹配项之间以|分隔
	int AddMatch(CString sMatch); //添加匹配项
	int AddMatch(CString sMatch, int nValue); //添加匹配项，并指定匹配码
	
};

/*
支持任务的串口操作类
任务包括后台任务和前台任务
同时只允许一个任务被激活
如果存在前台任务，后台任务自动隐藏
载入新的任务，会自动覆盖旧的任务
后台任务一直存在
*/

class CTaskedPort : public CSerialPort  
{
private:
	
	CPortTask * m_pBGTask; //后台任务
	CPortTask * m_pFGTask; //前台任务

	
public:

	void WaitForTask(CPortTask *pTask, int nEndCondition, CWaiting * pWaiting, DWORD nIdleTimeLimit);
	void Close();
	
	//等待时间
	enum
	{
			tmShort = 20,
			tmNormal = 1000,
			tmInitialize = 3000,
			tmLong = 6000,
			tmLonger = 20000,
	};
	
	//指定GetInput函数的行为
	enum
	{
		//指定GetInput调用的终止条件
		
		//0-3: 匹配条件
		
		ecDirty = 0x0001, //有值即返回
			ecWaiting = 0x0002, //不等待
			ecOkOrError = 0x0004, //有OK或者ERROR即返回
			ecCrlf = 0x0008, //有回车即返回
			
			//4-7: 指定发生等待超时时GetInput的动作选项
			
			ecRetryAlways = 0x0100, //一直等待
			ecRetryPrompt = 0x0200, //提示用户是否继续
	};
	
	CMutex m_Mutex;
	
	BOOL Open(CString sPort);
	int Request(CString sRequest, CString & sResponse, int nEndCondition, CWaiting * pWaiting, char * sFind = NULL, CString sTaskName = "", DWORD nIdleTimeLimit = tmNormal);
	DWORD SendCommand(CString sCommand, DWORD nIdleTimeLimit = tmNormal);
	CString Request(CString sRequest, int nEndCondition, CWaiting * pWaiting, char * sFind = NULL, CString sTaskName = "", DWORD nIdleTimeLimit = tmNormal);
	
	void UnloadTask(CPortTask * pTask);
	
	void LoadFGTask(CPortTask * pTask);
	void LoadBGTask(CPortTask * pTask);
	
	CString m_sInputBuffer;
	
	void OnEvRxChar();
	CTaskedPort();
	virtual ~CTaskedPort();
};

#endif // !defined(AFX_TASKEDPORT_H__55962DCB_4955_4ACA_A605_74F41A464656__INCLUDED_)
