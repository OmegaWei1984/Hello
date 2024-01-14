#include "lib/common.hpp"

int arr[] = {
#include "foo.inc"
};

#define ngx_tolower(c) ((c >= 'A' && c <= 'Z') ? (c | 0x20) : c)
#define ngx_toupper(c) ((c >= 'a' && c <= 'z') ? (c & ~0x20) : c)

#define ngx_memzero(buf, n) (void)memset(buf, 0, n)

int main()
{
    for (const auto &num : arr)
    {
    }

#define CUBE(a) (a) * (a) * (a)
    int c3 = CUBE(3);
    int c5 = CUBE(5);
#undef CUBE
    // // error: ‘CUBE’ was not declared in this scope
    // int c7 = CUBE(7);

#define FOO 1
#ifdef FOO
#   undef FOO
#endif
#define FOO 42
    int num = FOO;
    assert(num == 42);
    int version = 0;
#if __cplusplus >= 202302L
    version = 23;
#elif __cplusplus >= 202002L
    version = 20;
#elif __cplusplus >= 201703L
    version = 17;
#elif __cplusplus >= 201402L
    version = 14;
#elif __cplusplus >= 201103L
    version = 11;
#endif
    return 0;
}