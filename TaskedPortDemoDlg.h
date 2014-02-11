// TaskedPortDemoDlg.h : header file
//

#if !defined(AFX_TASKEDPORTDEMODLG_H__C44CDDFE_55B2_4B78_B846_4A12564B46B5__INCLUDED_)
#define AFX_TASKEDPORTDEMODLG_H__C44CDDFE_55B2_4B78_B846_4A12564B46B5__INCLUDED_

#include "TaskedPort.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTaskedPortDemoDlg dialog

class CTaskedPortDemoDlg : public CDialog
{
// Construction
public:
	CTaskedPort m_Port;
	CTaskedPortDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTaskedPortDemoDlg)
	enum { IDD = IDD_TASKEDPORTDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskedPortDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTaskedPortDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKEDPORTDEMODLG_H__C44CDDFE_55B2_4B78_B846_4A12564B46B5__INCLUDED_)
