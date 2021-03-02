#include <iostream>
using namespace std;

int main()
{
    int i = 0x12345678;

    if (*((char*)&i) == 0x12)
        cout << "´ó¶Ë" << endl;
    else
        cout << "Ð¡¶Ë" << endl;

    return 0;
}