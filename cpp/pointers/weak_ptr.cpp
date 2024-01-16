#include <memory>
#include <iostream>

class Foo1
{
private:
    int m_value;

public:
    std::shared_ptr<Foo1> next;

    Foo1(int value) : m_value(value) {}
    ~Foo1()
    {
        std::cout << "~Foo1: " << m_value << std::endl;
    }
};

class Foo2
{
private:
    int m_value;

public:
    std::weak_ptr<Foo2> next;

    Foo2(int value) : m_value(value) {}
    ~Foo2()
    {
        std::cout << "~Foo2: " << m_value << std::endl;
    }
};

int main()
{
    auto f1_a = std::make_shared<Foo1>(1);
    auto f1_b = std::make_shared<Foo1>(2);
    f1_a->next = f1_b;
    f1_b->next = f1_a;

    auto f2_a = std::make_shared<Foo2>(1);
    auto f2_b = std::make_shared<Foo2>(2);
    f2_a->next = f2_b;
    f2_b->next = f2_a;

    return 0;
}
