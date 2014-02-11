// StringTokenizer.h: interface for the CStringTokenizer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRINGTOKENIZER_H__28BB2E61_1DB7_462D_8AD6_7D8791687F23__INCLUDED_)
#define AFX_STRINGTOKENIZER_H__28BB2E61_1DB7_462D_8AD6_7D8791687F23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*
用以解析以指定分隔符分隔的字符串
*/

class CStringTokenizer  
{
private:

	CStringArray m_Tokens;

public:
	CStringArray * GetTokens();

	CStringTokenizer(CString sSource, CString sDelimiters = " \t\n\r\f");
	virtual ~CStringTokenizer();

};

#endif // !defined(AFX_STRINGTOKENIZER_H__28BB2E61_1DB7_462D_8AD6_7D8791687F23__INCLUDED_)
