// logger.cpp: implementation of the CLogger class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "logger.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CLogger Logger;

CLogger::CLogger()
{
	m_bDumb = true;
}

CLogger::~CLogger()
{
	Log("Logger shutdown!");
}

void CLogger::AttachFile(CString sLogPath, bool bDumb)
{
	SetDumb(bDumb);
	m_sLogPath = sLogPath;
	
	unlink(sLogPath);
	Log("Logger started!");
}

void CLogger::Log(char *format, ...)
{
	try
	{
		if(m_bDumb)
			return;
		
		FILE * pLogFile = fopen(m_sLogPath, "a");
		
		if(!pLogFile)
		{
			return;
		}
		
		SYSTEMTIME st;
		::GetSystemTime(&st);
		
		fprintf(pLogFile, "[%4d-%02d-%02d %02d:%02d:%02d.%03d]\t", 
			st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
		
		va_list args;
		va_start(args, format);

		char * pBuffer = new char[0xFFFF];
		vsprintf(pBuffer, format, args);
		fprintf(pLogFile, pBuffer);
		delete [] pBuffer;

		va_end(args);
		
		fprintf(pLogFile, "\r\n");
		
		fclose(pLogFile);
	}
	catch(CException * e)
	{
		e->Delete();
	}
}

void CLogger::SetDumb(bool bDumb)
{
	m_bDumb = bDumb;
}
