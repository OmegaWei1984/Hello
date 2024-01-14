#include "lib/common.hpp"
#include <string>
#include <iostream>

class Foo
{
private:
    int value;
    using t_int = int;
    t_int value2 = 42;

public:
    Foo() : value(0){};
    Foo(const Foo &foo) = default;
    Foo &operator=(const Foo &foo) = default;
    Foo(Foo &&foo) = default;
    Foo& operator=(Foo &&foo) = default;

    Foo(int num) : value(num){};
    Foo(const std::string &num) : value(stoi(num)){};

    constexpr int get()
    {
        return value;
    }
};

int main()
{
    Foo foo;
    Foo foo42(42);
    Foo foo42str("42");
    Foo foo_cp(foo42);
    Foo foo_cp2;
    foo_cp2 = foo42str;
    assert(foo_cp.get() == 42);
    assert(foo_cp2.get() == 42);
    Foo foo42_a(std::move(foo42));
    assert(foo42_a.get() == 42);
    Foo foo42_b;
    assert(foo42_b.get() == 42);

    return 0;
}