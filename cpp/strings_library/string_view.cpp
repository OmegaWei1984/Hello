#include "lib/common.hpp"
#include <iostream>
#include <string>
#include <string_view>

// using string_view = std::basic_string_view<char>;

std::string_view foo()
{
    std::string s{"test"};
    // 内存中的 “test” 会被释放
    return std::string_view {s};
}

int main()
{
    std::string_view sv1("hello");
    std::string s1(sv1);
    // error: no match for ‘operator+’
    // sv1 = sv1 + "cpp";
    std::string_view sv2 = sv1.substr(0, 3);
    std::string_view sv3 = "hello\0 c++";
    assert(sv3.size() == 5);
    std::cout << sv3.data() << std::endl;
    // std::cout << foo() << std::endl;

    return 0;
}