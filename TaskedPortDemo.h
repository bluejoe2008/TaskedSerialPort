// TaskedPortDemo.h : main header file for the TASKEDPORTDEMO application
//

#if !defined(AFX_TASKEDPORTDEMO_H__FF05A2A5_7C82_4369_A132_6EE8395F71C8__INCLUDED_)
#define AFX_TASKEDPORTDEMO_H__FF05A2A5_7C82_4369_A132_6EE8395F71C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTaskedPortDemoApp:
// See TaskedPortDemo.cpp for the implementation of this class
//

class CTaskedPortDemoApp : public CWinApp
{
public:
	CTaskedPortDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskedPortDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTaskedPortDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKEDPORTDEMO_H__FF05A2A5_7C82_4369_A132_6EE8395F71C8__INCLUDED_)
