#include "lib/common.hpp"

class Foo
{
private:
    mutable int m_value = 0;
public:
    int get() const
    {
        return m_value;
    }
    void set(int value) const
    {
        m_value = value;
    }
};

int main()
{
    Foo foo;
    foo.set(42);
    assert(foo.get() == 42);
    return 0;
}