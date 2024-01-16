#include "lib/common.hpp"
#include <string>
#include <tuple>

int sum(int a, int b)
{
    return a + b;
}

constexpr float exp(float x, int n)
{
    return n == 0 ? 1 : n % 2 == 0 ? exp(x * x, n / 2)
                                   : exp(x * x, (n - 1) / 2) * x;
}

inline int cube(int x)
{
    return x * x * x;
}

/**
 * auto 将推断为 lhs 和 rhs 之和的非常量值副本。
 */
template <typename Lhs, typename Rhs>
auto add(const Lhs &lhs, const Rhs &rhs)
{
    return lhs + rhs;
}

/**
 * 当与尾随返回类型结合使用时 auto ，
 * 它只是用作 decltype 表达式生成的任何值的占位符，
 * 并且本身不执行类型推导。
 */
template <typename Lhs, typename Rhs>
auto add2(const Lhs &lhs, const Rhs &rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}

void doSomething(const std::string &input) {}

void doSomething(const std::string &&input) {}

void doSomethingElse(const std::string &input = std::string{"do something"}) {}

struct Foo
{
    std::string name;
    int num;
};

Foo gFoo()
{
    std::string m{"hello"};
    int n{42};
    return {m, n};
}

std::tuple<int, std::string, double> bar()
{
    int i{42};
    std::string s{"hello"};
    double d{3.14};
    return {i, s, d};
}

int (*pf)(int, int);

typedef int (*pf2)(int, int);

pf2 sum2()
{
    return sum;
}

int main()
{
    int i = sum(10, 32);
    assert(i == 42);
    float j = exp(2.71828, 4);
    int k = cube(10);
    auto res1 = add(3.1415, 2.7182);
    auto res2 = add(std::string{"hello"}, std::string{" c++"});
    std::string thing = "do something";
    doSomething(thing);
    doSomething("do something");
    doSomethingElse();
    Foo foo = gFoo();
    auto b = bar();
    assert(std::get<0>(b) == 42);
    auto[b0, b1, b2] = bar();
    assert(b0 == 42);
    pf = &sum;
    i = (*pf)(32, 10);

    return 0;
}