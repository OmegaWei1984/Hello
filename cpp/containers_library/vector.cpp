#include "lib/common.hpp"
#include <vector>
#include <iostream>

class Foo
{
private:
    int m_num = 0;

public:
    Foo(int num)
    {
        std::cout << num << std::endl;
        m_num = num;
    }
    int get()
    {
        return m_num;
    }
};

int main()
{
    std::vector<int> v(2);
    assert(v.size() == 2);
    assert(v.capacity() == 2);
    v.push_back(42);
    std::vector<Foo> vf;
    Foo f1(1);
    vf.push_back(f1);
    vf.push_back(f1);
    vf.push_back(std::move(f1));
    vf.emplace_back(2);
    vf.emplace_back(f1);
    Foo *f3 = new Foo(3);
    vf.push_back(*f3);
    delete f3;
    auto f3_ = vf.back();
    assert(f3_.get() == 3);

    return 0;
}