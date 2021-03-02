#pragma once
class CMyString
{
public:
    CMyString();
    ~CMyString();

    CMyString(const char *str);
    CMyString(const CMyString &str);

    CMyString &operator=(const char *str);
    CMyString &operator=(const CMyString &str);

    CMyString &operator+(const char *str);
    CMyString &operator+(const CMyString &str);

    char operator[](unsigned int pos);

    void swap(const CMyString &str);
    unsigned int copy(char* dest, unsigned int count, unsigned int pos = 0);

    const char *c_str() const
    {
        return m_data;
    }

    unsigned int length() const
    {
        return m_length;
    }


private:
    char *m_data;
    unsigned int m_length;
};
