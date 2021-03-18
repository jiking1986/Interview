#include <iostream>
using namespace std;

union UData {
    int a;
    unsigned char b[2];
};

int test()
{
    UData data = { 0 };

    data.b[0] = 1;
    data.b[1] = 10;

    std::cout << sizeof(data) << std::endl;
    std::cout << data.a << std::endl;

    return 0;
}

int test2()
{
    int x2 = 0b10;
    //double x16 = 0b101.01011;

    int x8 = 010;

    int x10 = 10;

    int x16 = 0x10;

    std::cout << x2 << std::endl;
    std::cout << x8 << std::endl;
    std::cout << x10 << std::endl;
    std::cout << x16 << std::endl;

    return 0;
}

int main()
{
    test();

    test2();

    int i = 0x12345678;

    if (*((char*)&i) == 0x12)
        cout << "´ó¶Ë" << endl;
    else
        cout << "Ğ¡¶Ë" << endl;

    return 0;
}
