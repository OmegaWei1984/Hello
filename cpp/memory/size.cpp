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

    return 0;
}
