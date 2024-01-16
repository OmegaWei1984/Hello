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

int main()
{
    Foo f;
    // 匹配 (Foo, double), double 能转换为 int
    foo(f, 1.1);
    return 0;
}
