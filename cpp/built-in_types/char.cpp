#include <iostream>
#include <string>
#include <cassert>

int str_diff(const char *str1, const char *str2)
{
    int n = 0;
    while (*str1 != '\0' && *str2 != '\0') {
        // std::cout << ((*str1) | 0x20)  << std::endl;
        // std::cout << (int)(*str2) << std::endl;
        // if (*str1 != *str2)
        if (((*str1) | 0x20) != ((*str2) | 0x20))
            return n;
        n++;
        str1++;
        str2++;
    }
    if (*str1 != *str2) return n;
    return 0;
}

int main()
{
    char s1[] = "HELLO";
    char s2[] = "hello";
    int res = str_diff(s1, s2);
    assert(res == 0);
    char s3[] = "helle";
    res = str_diff(s1, s3);
    assert(res == 4);
    char s4[] = "hell";
    // "HELLO\0" "hell\0"
    res = str_diff(s1, s4);
    assert(res == 4);
    return 0;
}