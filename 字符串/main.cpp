#include "MyString.h"

#include <string>

int test(const std::string & str)
{
    int i = str.length();

    i++;

    return i;
}

int main()
{
    return 0;
}
