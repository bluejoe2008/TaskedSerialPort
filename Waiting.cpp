// Waiting.cpp: implementation of the CWaiting class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Waiting.h"
#include "Util.h"
#include "RichException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWaiting::CWaiting()
{
	m_bEnded = false;
	m_bAbortFlag = false;
}

CWaiting::~CWaiting()
{
	EndWait();
}

void CWaiting::BeginWait(CString sPrompt, int nRange)
{
	m_bEnded = false;
	m_bAbortFlag = false;
	
	SetPrompt(sPrompt);
	SetRange(nRange);
}

void CWaiting::EndWait()
{
	m_bEnded = true;
}

void CWaiting::AbortWait()
{
	m_bAbortFlag = true;
}

void CWaiting::EndWait(CString sPrompt, int nPos)
{
	if(!m_bAbortFlag)
	{
		SetPrompt(sPrompt);
		SetPos(nPos);
	}
	
	EndWait();
}

void CWaiting::OnWaitChip(bool bDirty)
{
	AssertWaiting();
}

void CWaiting::AssertWaiting()
{
	if(m_bAbortFlag)
	{
		EndWait();
		throw new CUserAbortException();
	}
}

void CProgressWaiting::SetPrompt(CString sPrompt)
{
	ASSERT(m_pPrompt);
	AssertWaiting();
	
	m_pPrompt->SetWindowText(sPrompt);
}

void CProgressWaiting::SetRange(int nRange)
{
	ASSERT(m_pProgress);
	AssertWaiting();
	
	m_pProgress->SetRange(0, nRange);
	m_pProgress->SetPos(0);
}

void CProgressWaiting::OnWaitChip(bool bDirty)
{
	AssertWaiting();
	
	if(bDirty)	
	{
		StepIt();
	}
}

CProgressWaiting::CProgressWaiting(CStatic *pPrompt, CProgressCtrl *pProgress, CWnd * pOwner)
{
	Initialize(pPrompt, pProgress, pOwner);
}

CProgressWaiting::CProgressWaiting()
{
	m_pPrompt = NULL;
	m_pProgress = NULL;
	m_pOwner = NULL;
}

//设置参数
void CProgressWaiting::Initialize(CStatic *pPrompt, CProgressCtrl *pProgress, CWnd *pOwner)
{
	m_pPrompt = pPrompt;
	m_pProgress = pProgress;
	m_pOwner = pOwner;
	
	SetRange(100);
	m_pProgress->SetStep(1);
}

//确定仍在等待状态
void CProgressWaiting::AssertWaiting()
{
	CUtil Util;
	Util.PumpMessages(m_pOwner ? m_pOwner->GetSafeHwnd() : NULL, WM_TIMER);
	
	CWaiting::AssertWaiting();
}

void CProgressWaiting::StepIt(int nStep)
{
	ASSERT(m_pProgress);
	AssertWaiting();
	
	int nLower, nUpper;
	m_pProgress->GetRange(nLower, nUpper);
	
	int nPos = m_pProgress->GetPos();
	nPos += nStep;

	if(nUpper)
		nPos %= nUpper;
	
	m_pProgress->SetPos(nPos);
}

void CProgressWaiting::SetPos(int nPos)
{
	if(nPos = -1)
	{
		int nLower, nUpper;
		
		m_pProgress->GetRange(nLower, nUpper);
		nPos = nUpper - nLower;
	}
	m_pProgress->SetPos(nPos);
}

void CDumbWaiting::OnWaitChip(bool bDirty)
{
	CUtil Util;
	Util.PumpMessages(m_hOwner, WM_TIMER);
}

CDumbWaiting::CDumbWaiting(HWND hOwner)
{
	m_hOwner = hOwner;
}
