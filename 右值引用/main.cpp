#include <iostream>
#include <memory>

using namespace std;

#define OUTPUT_LINE cout << "-------- " << __LINE__ << " --------" << endl

class A
{
public:
    A()
    {
        cout << "A(), " << this << endl;
    }
    ~A()
    {
        cout << "~A(), " << this << endl;
    }
    A(const A &a)
    {
        cout << "A(const A &a), " << &a << ", " << this << endl;
    }
    A &operator=(const A &a)
    {
        cout << "A &operator=(const A & a), " << &a << ", " << this << endl;
        return *this;
    }
};

void func1(A a)
{
    return;
}
void func2(const A &a)
{
    return;
}

A func6(A a)
{
    return a;
}

A func3()
{
    A a;
    return a;
}

A func4()
{
    A a;
    return a;
}


unique_ptr<int> test()
{
    unique_ptr<int> temp(new int(123));
    cout << "unique_ptr<int> test() " << temp.get() << ", " << *temp << endl;
    return temp;
}

// ----------------------------------------------------------------

int i = 101, j = 101;

int foo() { return i; }
int&& bar() { return std::move(i); }
void set(int&& k) { k = 102; }
int test2()
{
    foo();
    std::cout << i << std::endl;
    set(bar());
    std::cout << i << std::endl;
    return 0;
}

// ----------------------------------------------------------------

int main()
{
    //test2();

    A a1; OUTPUT_LINE;
    A a2 = a1; OUTPUT_LINE;

    func1(a1); OUTPUT_LINE;
    func2(a1); OUTPUT_LINE;

    A a3 = func3(); OUTPUT_LINE;

    A&& a4 = func3(); OUTPUT_LINE;

    A a5;
    a5 = a1; OUTPUT_LINE;

    A && a6 = std::move(a1); OUTPUT_LINE;

    unique_ptr<int> num_ptr = test();
    cout << "unique_ptr<int> num_ptr " << num_ptr.get() << ", " << *num_ptr << endl;

    return 0;
}