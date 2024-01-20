#include <cassert>
#include <iostream>
#include <string>
// #include <cstring>

using namespace std;
using str = std::basic_string<char>;
// wstring = std::basic_string<wchar_t>
// u16string = std::basic_string<char16_t>
// u32string = std::basic_string<char32_t>

char *strncpy(char *destination, const char *source, size_t num)
{
    char *tmp = destination;
    while (num > 0)
    {
        if ((*tmp = *source) == '\0')
        {
            break;
        }
        source++;
        tmp++;
        num--;
    }
    return destination;
}

int main()
{
    string s;
    assert(s.capacity() == 15);
    string s2 = "";
    assert(s2.capacity() == 15);
    string s3(6, '0');
    assert(s3.capacity() == 15);
    char *h = "hello";
    char h2[6];
    strncpy(h2, h, 6);
    str s4 = "hello";
    string s5 = "abc";
    assert(s5.length() == 3);
    assert(s5 < "bcd");
    assert(s5.substr(0, 1) == "a");
    assert(s5[1] == 'b');
    assert(s5.find('d') == string::npos);
    assert(s5 + "d" == "abcd");
    using namespace std::literals::string_literals;
    auto s6 = "hello"s;
    assert(s6.size() == 5);
    string s7 = R"(\n\r\t)";
    std::cout << s7 << std::endl;
    string s8 = R"=(R"(something)")=";
    std::cout << s8 << std::endl;
    assert(stoi("42") == 42);
    assert(stol("42") == 42L);
    assert(stod("42.0") == 42.0);
    assert(to_string(42) == "42");
    

    return 0;
}
