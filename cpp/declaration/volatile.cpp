#include "lib/common.hpp"

const volatile int MAX = 1024;

int main()
{
    int *p = (int *)(&MAX);
    *p = 2048;
    assert(MAX == 2048);
    return 0;
}