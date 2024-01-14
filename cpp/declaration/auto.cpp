#include <map>
#include <set>
#include <vector>

auto get_a_set()
{
    std::set<int> s = {1, 3, 5, 7};
    return s;
}

int main()
{
    std::map<int, char> m = {{0, 'a'}, {1, 'b'}};
    auto it = m.begin();
    auto x = 0L;
    auto px = &x;
    auto px2{&x};
    auto &x1 = x;
    auto *x2 = &x;

    std::vector<int> a = {1, 1, 2, 3, 5, 8};
    for (const auto &num : a)
    {
    }

    for (auto &num : a)
    {
        num++;
    }
}