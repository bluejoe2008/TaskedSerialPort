// Waiting.h: interface for the CWaiting class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WAITING_H__10231794_967B_4F48_8EAB_1DF38EBBB2EB__INCLUDED_)
#define AFX_WAITING_H__10231794_967B_4F48_8EAB_1DF38EBBB2EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//指定等待操作
//用户可派生该类以指定特定的等待操作

class CWaiting
{
protected:

	bool m_bAbortFlag; //指定该等待是否被取消
	bool m_bEnded; //指定该等待是否已结束

public:
	
	CWaiting();
	virtual ~CWaiting();
	
	virtual void BeginWait(CString sPrompt, int nRange = 100);
	virtual void EndWait(CString sPrompt, int nPos = -1);
	virtual void EndWait();

	virtual void AssertWaiting();
	void AbortWait();

	virtual void SetPrompt(CString sPrompt) = 0; //设置提示信息
	virtual void SetRange(int nRange) = 0; //设置等待总耗时
	virtual void SetPos(int nPos = -1) = 0; //设置等待总耗时
	
	virtual void OnWaitChip(bool bDirty); //指定等待循环中的操作
};

//不显示任何提示
class CBlockingWaiting : public CWaiting
{
public:

	void SetPos(int nPos = -1) {}
	void SetRange(int nRange) {}
	void OnWaitChip(bool bDirty) {}
	void SetPrompt(CString sPrompt) {}
};

class CDumbWaiting : public CWaiting
{
public:
	CDumbWaiting(HWND hOwner = NULL);
	HWND m_hOwner;

	void SetPos(int nPos = -1) {}
	void OnWaitChip(bool bDirty);
	void SetRange(int nRange) {}
	void SetPrompt(CString sPrompt) {}
};

//显示状态和进度条
class CProgressWaiting : public CWaiting
{
private:

	CStatic * m_pPrompt;
	CProgressCtrl * m_pProgress;
	CWnd * m_pOwner;

public:

	virtual void SetPos(int nPos = -1);
	void StepIt(int nStep = 1);
	void Initialize(CStatic *pPrompt, CProgressCtrl *pProgress, CWnd * pOwner);

	CProgressWaiting(); //缺省构造函数

	CProgressWaiting(CStatic * pPrompt, CProgressCtrl * pProgress, CWnd * pOwner = NULL);
	void OnWaitChip(bool bDirty);
	void SetRange(int nRange);
	void SetPrompt(CString sPrompt);
	void AssertWaiting();
};

#endif // !defined(AFX_WAITING_H__10231794_967B_4F48_8EAB_1DF38EBBB2EB__INCLUDED_)
