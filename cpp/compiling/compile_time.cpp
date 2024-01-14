#include <iostream>

template <int N>
struct fib
{
    static_assert(N >= 2, "N >= 2");

    static const int value =
        fib<N - 1>::value + fib<N - 2>::value;
};

template <>
struct fib<0>
{
    static const int value = 1;
};

template <>
struct fib<1>
{
    static const int value = 1;
};

[[noreturn]] void func_noreturn()
{
    while (true)
    {
    }
}

[[deprecated]] void func_deprecated()
{
    std::cout << "func deprecated" << std::endl;
}

[[unused]] void func_unused()
{
}

[[constructor]] void func_constructor()
{
    std::cout << "before" << std::endl;
}

[[destructor]] void func_destructor()
{
    std::cout << "after" << std::endl;
}

[[always_inline]] void func_always_inline()
{
    std::cout << "always inline" << std::endl;
}

[[hot]] void func_hot()
{
}

template<typename T>
void check_type(T v)
{
    static_assert(std::is_integral<T>::value, "int");
    std::cout << "static_assert : " << typeid(v).name() << std::endl;
}

int main()
{
    func_always_inline();
    // 1, 1, 2, 3, 5, 8
    static_assert(fib<5>::value == 8);
    static_assert(
        sizeof(long) >= 8, "must run on x64");
    static_assert(
        sizeof(int) == 4, "int must be 32bit");
    func_deprecated();
    check_type(42);
    // check_type((void*)0);
    return 0;
}