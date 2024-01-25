#include "lib/common.hpp"
#include <algorithm>
#include <vector>
#include <set>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6};
    bool found = std::binary_search(v.cbegin(), v.cend(), 4);
    std::vector<int>::const_iterator pos =
        std::lower_bound(v.cbegin(), v.cend(), 4);
    if (pos != v.cend())
    {
        assert(*pos == 4);
        assert(found);
    }
    pos = std::upper_bound(v.cbegin(), v.cend(), 4);
    if (pos != v.cend())
    {
        assert(*pos == 5);
    }
    std::vector<int>::iterator found2 =
        std::find(v.begin(), v.end(), 4);
    std::multiset<int> s{4, 3, 1, 2, 5, 3, 6, 1};
    std::multiset<int>::iterator found3 = s.find(5);

    return 0;
}