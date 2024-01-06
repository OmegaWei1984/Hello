#include <cstddef>

struct test
{
    int i;
    int i2;
    long l;
};

struct test2
{
    int i;
    long l;
    int i2;
};

struct alignas(16) test3
{
    int i;
    long l;
    int i2;
};

class Test4
{
    int i;
    int i2;
    long l;
};

class Test5
{
    int i;
    long l;
    int i2;
};

int main()
{
    // 16 = 4 + 4 + 8
    int size = sizeof(int) + sizeof(int) + sizeof(long);
    // 16 = 4 + 4 + 8
    int size1 = sizeof(test);
    // 24 = 8 + 8 + 8
    int size2 = sizeof(test2);
    // 32 = 16 + 16
    int size3 = sizeof(test3);
    // 16 = 4 + 4 + 8
    size1 = sizeof(Test4);
    // 24 = 8 + 8 + 8
    size2 = sizeof(Test5);
    return 0;
}
