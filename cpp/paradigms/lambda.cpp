#include "lib/common.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Foo {
private:
    int x = 42;
public:
    auto test()
    {
        return [this]() {
            return x;
        };
    }
};

int main()
{
    auto sqr = [](int num) -> int
    {
        return num * num;
    };
    int num2 = 42;
    auto foo = [=](int num)
    {
        return num * num2;
    };
    assert(foo(10) == 420);
    std::vector<int> v = {1, 2, 3, 4};
    std::cout << *find_if(v.begin(), v.end(), [](int x)
                          { return x >= 3; })
              << std::endl;
    int value = 42;
    auto f1 = [=]()
    {
        //  error: assignment of read-only variable ‘value’
        // value += 1;
    };
    auto f2 = [&]()
    {
        value += 10;
    };
    auto f3 = [=, &value]()
    {
        value += 10;
    };
    auto f4 = (Foo()).test();
    assert(f4() == 42);
    auto f5 = [](const auto& value){
        return value + value;
    };
    assert(f5(10) == 20);
    std::string s = "hello";
    assert(f5(s) == "hellohello");

    return 0;
}