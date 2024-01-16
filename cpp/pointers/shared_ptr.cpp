#include "lib/common.hpp"
#include <memory>
#include <string>

int main()
{
    std::shared_ptr<int> p (new int(42));
    auto p2 = std::make_shared<std::string>("hello");
    assert(*p2 == "hello");
    auto p3 = std::move(p2);
    assert(p2 == nullptr);
    auto p4 = p3;
    assert(p3.use_count() == 2);
    return 0;
}