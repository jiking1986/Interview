#include <iostream>
#include <string>
#include <set>

typedef std::set<std::string> brackets_list;

brackets_list worker(unsigned int num)
{
    brackets_list list;
    if (num == 1)
    {
        list.insert("()");
    }
    else
    {
        brackets_list temp_list = worker(num - 1);
        for (auto it : temp_list)
        {
            list.insert("()" + it);
            list.insert(it + "()");
            list.insert("(" + it + ")");
        }
    }
    return list;
}

int main()
{
    brackets_list list = worker(4);

    return 0;
}
