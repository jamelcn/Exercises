#include <stdio.h>

CMyString& CMyString::operator=(const CMyString &str)
{
    if(this == &str)
	return *this;
    delete []m_pData;
    m_pData = NULL;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}

CMyString& CMyString::operator=(const CMyString &str)
{
    if (this != &str) {
    	CMyString strTemp(str);

	char* pTemp = strTem.m_pData;
	strTemp.m_pData = m_pData;
	m_pData = pTemp;
    }

    return *this;
}
