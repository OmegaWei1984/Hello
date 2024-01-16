#include "lib/common.hpp"
#include <memory>
#include <string>

template<class T, class... Args>
std::unique_ptr<T> make_unique_c11(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

int main()
{
    std::unique_ptr<int> p(new int(42));
    assert(*p == 42);
    assert(p != nullptr);

    auto p2 = std::make_unique<int>(42);
    assert(*p2 == 42);

    auto p3 = make_unique_c11<std::string>("hello");
    assert(*p3 == "hello");

    auto p4 = std::move(p2);
    assert(*p4 == 42);
    assert(p2 == nullptr);

    return 0;
}