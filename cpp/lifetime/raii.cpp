#include <iostream>
#include <mutex>

enum class type
{
    B,
    C
};

class A
{
public:
    virtual ~A() {};
};

class B : public A
{
public:
    B()
    {
        std::cout << "B()" << std::endl;
    }
    ~B()
    {
        std::cout << "~B()" << std::endl;
    }
};

class C : public A
{
public:
    C()
    {
        std::cout << "C()" << std::endl;
    }
    ~C()
    {
        std::cout << "~C()" << std::endl;
    }
};

A *create(type t)
{
    switch (t)
    {
    case type::B:
        return new B();
    case type::C:
        return new C();
    }
}

class Wrapper
{
private:
    A *m_ptr;

public:
    explicit Wrapper(A *ptr = nullptr) : m_ptr(ptr)
    {
    }

    ~Wrapper()
    {
        delete m_ptr;
    }

    A *get()
    {
        return m_ptr;
    }
};

std::mutex mtx;

void fred()
{
    std::lock_guard<std::mutex> guard(mtx);
    // do smoething
}

int main()
{
    Wrapper ptrA(create(type::B));
    Wrapper ptrB(create(type::C));

    B *b = new B();
    delete b;

    return 0;
}