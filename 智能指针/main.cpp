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
