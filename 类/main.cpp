#include <string>

class A
{
public:
    int num;
    std::string str;
    char szArray[100];
    char *pstr;
};

int main()
{
    char szStr[] = "pstr";

    A a;

    a.num = 123;
    a.str = "str";
    memcpy(a.szArray, "arr", 3);
    a.szArray[3] = 0x00;
    a.pstr = szStr;

    A a2 = a;

    A a3;
    a3 = a;

    return 0;
}
