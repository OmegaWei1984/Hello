/**
 * volatile 可以用来修饰任何变量，
 * 而 mutable 却只能修饰类里面的成员变量，
 * 表示变量即使是在 const 对象里，也是可以修改的。
 */

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

    const Foo kFoo;
    kFoo.set(10);

    return 0;
}