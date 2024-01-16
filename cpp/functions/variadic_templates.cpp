#include <iostream>
#include <string>

template<typename T>
void show(T t)
{
    std::cout << t << std::endl;
}

template<typename T, typename... Args>
void show(T t, Args... args)
{
    std::cout << t << std::endl;
    show(args...);
}

int main()
{
    std::string s1{"hello"};
    std::string s2{"C++"};
    show(s1, s2, 3.14, 42);
    return 0;
}