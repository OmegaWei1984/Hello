#include <vector>
#include <iostream>

void foo(int n)
{
}

void bar(int n)
{
    int a = n + 1;
    foo(a);
}

class Baz
{
public:
    Baz() { std::cout << "Baz()" << std::endl; }
    ~Baz() { std::cout << "~Baz()" << std::endl; }
};

void qux(int n)
{
    Baz baz;
    if (n == 42)
    {
        throw "42";
    }
}

int main()
{
    auto ptr = new std::vector<int>();
    bar(42);

    try
    {
        qux(0);
        qux(42);
    }
    catch (const char *s)
    {
        std::cout << s << std::endl;
    }

    return 0;
}