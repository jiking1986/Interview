#include <iostream>
using namespace std;

int main()
{
    int i = 0x12345678;

    if (*((char*)&i) == 0x12)
        cout << "���" << endl;
    else
        cout << "С��" << endl;

    return 0;
}