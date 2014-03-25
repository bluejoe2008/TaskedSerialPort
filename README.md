做过串口通讯的VCer肯定都熟悉MsComm控件和CodeProject上的CSerial。也许更多的程序员更愿意使用不需要控件的CSerial。但是不幸的是，CSerial类仅仅完成对底层串口通讯的封装，有时候并不如MsComm控件好用。

CSerialPort为bluejoe在CSerial基础上开发的类，支持开启事件监视线程。CTaskedPort为CSerialPort的派生类，它支持基于任务的事件处理。

用户发送一条命令（如：AT<cr>），可能就需要等待串口的回应（如：OK）才决定做下一步，这个AT命令其实就是一项任务（CPortTask），任务的结束一般需要用户指定关键词（如：OK或者ERROR）。CTaskedPort自动将命令和关键词列表封装成一个任务。

本包主要包括以下几个类：

CSerialPort：类似于CSerial的类，类声明如下：

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

CPortTask：完成对串口任务的封装，类声明如下：

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

CTaskedPort：支持任务的串口操作类，类声明如下：

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

CTaskedPort支持的任务包括后台任务和前台任务，它同时只允许一个任务被激活：如果存在前台任务，后台任务自动隐藏；新前台任务的载入，会自动覆盖旧的任务。

后台任务一直存在，用以监视用户指定的串口事件，并构造字符缓冲区。当用户调用Request函数时，CTaskedPort自动创建一个前台任务，并disable后台监视任务。前台任务一直等待，直到关键字的出现（或者超时）。这个等待过程表现出来的是一个同步接口，用户只需要等待Request函数结束即可。至于用户可能需要在等待过程中做一些其它的操作，如：显示进度条，这就需要用到CWaiting类。

CWaiting：CWaiting类用以指定等待过程中的动作，系统中已提供了3种CWaiting类：CDumbWaiting（啥都不干）、CProgressWaiting（显示进度条）和CNewProgressWaiting（创建一个新的进度窗口并显示进度）。CNewProgressWaiting继承于CProgressWaiting，它们之间的区别在于CProgressWaiting可以依附于任何一个窗口（如：当前的主窗口），而CNewProgressWaiting创建一个新的窗口。

创建一个CWaiting对象，将它作为参数，传入Request函数，就这么简单，你的程序就完成了同步等待和异步显示。

此外，Request允许用户指定等待时限。在等待超时时，是否直接结束等待，还是继续重试，还是弹出提示框询问用户，这些动作都可以通过Request的参数指定。

CTaskedPort还提供了丰富的接口，用户可以通过继承，来实现更多的功能。 

本包已经成功应用到bluejoe的手机串口通讯软件，目前还没有发现什么问题。希望各位使用探讨，并希望各位提出修改意见。

所附源码还包括其它的工具类，包括CUtil、CRichException、CWin32Exception等，希望能与大家一块共享。
