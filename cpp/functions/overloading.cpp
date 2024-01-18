/**
 * ┌────────────────┬─────────────┐
 * │ element        │ overloading │
 * ├────────────────┼─────────────┤
 * │ return type    │ yes         │
 * ├────────────────┼─────────────┤
 * │ num of args    │ yes         │
 * ├────────────────┼─────────────┤
 * │ type of args   │ yes         │
 * ├────────────────┼─────────────┤
 * │ ellipsis       │ yes         │
 * ├────────────────┼─────────────┤
 * │ typedef        │ no          │
 * ├────────────────┼─────────────┤
 * │ array bounds   │ no          │
 * ├────────────────┼─────────────┤
 * │ const,volatile │ yes         │
 * ├────────────────┼─────────────┤
 * │ ref & and &&   │ yes         │
 * └────────────────┴─────────────┘
 */

#include "lib/common.hpp"
#include <vector>

typedef int i;

void foo(int num) {}

// error: ambiguating new declaration of ‘int foo(int)’
// int foo(int num) { return 0; }

void foo(int num1, int num2) {}

// error: redefinition of ‘void foo(int, int)’
// void foo(int num2, int num1) {}

void foo(float num) {}

void foo(int num, int...) {}

// error: redefinition of ‘void foo(i)’
// void foo(i num) {}

// error: redefinition of ‘void foo(int)’
// void foo(const int num) {}

class Foo
{
    void foo(int num) {}
    void foo(int num) const {}
};

void foo(int &num) {}

void foo(const int &num) {}

void foo(int &&num) {}

void foo(Foo foo, int num)
{
    assert(num == 1);
}

class Bar
{
public:
    Bar()
    {
    }
    Bar(Bar &bar)
    {
    }
    Bar(const Bar &bar)
    {
    }
    Bar(volatile Bar &bar)
    {
    }
    static void test()
    {
    }
    //  ‘void Bar::test()’ cannot be overloaded with ‘static void Bar::test()’
    // void test()
    // {
    // }
};

class Baz
{
private:
    std::vector<int> m_data;
public:
    std::vector<int> get() &
    {
        return m_data;
    }
    std::vector<int> get() &&
    {
        return std::move(m_data);
    }
};

void func(int i)
{
}

void func(char *sz)
{
}

int main()
{
    /*
     * error: call of overloaded ‘foo(int)’ is ambiguous
     * candidate: ‘void foo(int)’
     * candidate: ‘void foo(float)’
     * ‘void foo(const int&)’
     * ‘void foo(int&&)’
     */
    // foo(42);
    Foo f;
    // 匹配 (Foo, double), double 能转换为 int
    foo(f, 1.1);
    Bar b1;
    Bar b2(b1);
    const Bar b3;
    Bar b4(b3);
    volatile Bar b5;
    Bar b6(b5);
    Baz baz;
    auto v = baz.get();
    auto v2 = Baz().get();
    extern void func(char *sz);
    // error: invalid conversion from ‘int’ to ‘char*’
    // func(42); // func( int ) is h idden
    func("hello");

    return 0;
}
