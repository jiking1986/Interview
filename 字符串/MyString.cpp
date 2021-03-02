#define _CRT_SECURE_NO_WARNINGS

#include "MyString.h"

#include <memory>

CMyString::CMyString()
{
}


CMyString::~CMyString()
{
}

CMyString::CMyString(const char *str)
{
    if (m_data)
        delete[] m_data;

    if (str)
    {
        m_length = strlen(str);
        m_data = new char[m_length + 1];
        strcpy(m_data, str);
    }
    else
    {
        m_length = 0;
        m_data = new char[1];
    }

    m_data[m_length] = 0x00;
}

CMyString::CMyString(const CMyString &str)
{
    if (m_data)
        delete[] m_data;

    m_length = str.length();
    m_length++;

    if (m_length)
    {
        m_data = new char[m_length + 1];
        strcpy(m_data, str.c_str());
    }
    else
    {
        m_data = new char[1];
    }

    m_data[m_length] = 0x00;
}

//bool String::operator==(const String &str)
//{
//    return strcmp(m_data, str.m_data) == 0;
//}

CMyString &CMyString::operator=(const char *str)
{
    return CMyString("");
}

CMyString &CMyString::operator=(const CMyString &str)
{
    return CMyString("");
}


CMyString &CMyString::operator+(const char *str)
{
    return CMyString("");
}

CMyString &CMyString::operator+(const CMyString &str)
{
    return CMyString("");
}


char CMyString::operator[](unsigned int pos)
{
    return ' ';
}


void CMyString::swap(const CMyString &str)
{
}

unsigned int CMyString::copy(char* dest, unsigned int count, unsigned int pos)
{
    if (!dest || !count)
        return -1;

    int num = count;
    if ((count + pos) > m_length)
        num = m_length - pos;

    memcpy(dest, m_data + pos, num);

    return num;
}
