#include <vector>
#include "lib/common.hpp"

int main()
{
    std::vector<int> v{0, 1, 2, 3, 4, 5};

    auto it1 = v.begin();
    auto it2 = v.end();
    auto it3 = begin(v);
    auto it4 = end(v);
    auto it5 = v.cbegin();
    auto it6 = v.cend();

    int dis = distance(it1, it2);
    assert(dis == 6);
    dis = distance(it2, it1);
    assert(dis == -6);
    advance(it1, 2);
    assert(*it1 == 2);
    auto it7 = next(it1);
    assert(*it7 == 3);
    auto it8 = next(it2); // undefined behavior
    assert(*(prev(it1)) == 1);

    return 0;
}