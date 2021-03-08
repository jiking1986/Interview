#if 0
#include <memory>
#include <iostream>
#include <cassert>

struct Foo {
    Foo() { std::cout << "Foo\n"; }
    ~Foo() { std::cout << "~Foo\n"; }

    void hello() { std::cout << "hello\n"; }
};

int main()
{
    Foo* fp = nullptr;

    {
        std::cout << "Creating new Foo...\n";
        std::unique_ptr<Foo> up(new Foo());

        std::cout << "About to release Foo...\n";
        fp = up.release();

        up->hello();

        Foo *fp_ptr = up.get();

        assert(up.get() == nullptr);

        up->hello();

        std::cout << "Foo is no longer owned by unique_ptr...\n";
    }

    fp->hello();

    delete fp;
}
#endif

#if 0
#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void observe()
{
    std::cout << "use_count == " << gw.use_count() << ": ";
    if (auto spt = gw.lock()) { // 使用之前必须复制到 shared_ptr
        std::cout << *spt << "\n";
    }
    else {
        std::cout << "gw is expired\n";
    }
}

int main()
{
    {
        auto sp = std::make_shared<int>(42);
        gw = sp;

        std::shared_ptr<int> data = gw.lock();
        int a = *data.get;

        observe();
    }

    observe();
}
#endif

#include <memory>
#include <thread>
#include <iostream>

int test_error1()
{
    int *p = new int(1);
    std::cout << *p << std::endl;

    std::shared_ptr<int> ptr = std::shared_ptr<int>(p);
    std::cout << *ptr << std::endl;

    ptr.reset();

    std::cout << *p << std::endl; // error

    return 0;
}

int test_error2()
{
    int *p = new int(1);

    auto test = [](int *p)
    {
        std::shared_ptr<int> ptr = std::shared_ptr<int>(p);
        std::cout << *ptr << std::endl;
    }; // error

    std::thread th1(test, p);
    std::thread th2(test, p);

    th1.join();
    th2.join();

    return 0;
}

int main()
{
    test_error1();

    test_error2();

    return 0;
}
