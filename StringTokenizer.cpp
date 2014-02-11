// StringTokenizer.cpp: implementation of the CStringTokenizer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StringTokenizer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStringTokenizer::CStringTokenizer(CString sSource, CString sDelimiters)
{
	//开始解析

	int nStart = 0;
	int nLength = sSource.GetLength();
	int nDelimiters = sDelimiters.GetLength();

	for(int m = 0; m < nLength; m++)
	{
		char ch = sSource.GetAt(m);

		for(int i = 0; i < nDelimiters; i++)
		{
			//查找到匹配
			if(ch == sDelimiters.GetAt(i))
			{
				m_Tokens.Add(sSource.Mid(nStart, m));
				nStart = m + 1;
				break;
			}
		}
	}

	//剩下的字符串
	if(nStart <= nLength)
		m_Tokens.Add(sSource.Mid(nStart));
}

CStringTokenizer::~CStringTokenizer()
{

}

CStringArray * CStringTokenizer::GetTokens()
{
	return &m_Tokens;
}
