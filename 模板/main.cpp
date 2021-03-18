#define _CRT_SECURE_NO_WARNINGS

#include <string>

template <typename T>
class CTemplate
{
public:
    explicit CTemplate() {}
    ~CTemplate() {}

    CTemplate(CTemplate &other) {
        //this->m_data = new T(other.data());
    }

public:
    void setData(T t) {
        m_data = t;
    }
    T getData() {
        return m_data;
    }

private:
    T m_data;
};

int main()
{
    CTemplate<char *> templ;
    char *temp = new char[5];
    strcpy(temp, "123");
    templ.setData(temp);

    CTemplate<char *> templ2 = templ;

    return 0;
}
