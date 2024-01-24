#include <algorithm>
#include <vector>
#include <random>
#include <numeric>

int main()
{
    std::vector<int> v(10);
    std::iota(v.begin(), v.end(), 0);
    std::mt19937 rng(std::random_device{}());
    std::shuffle(begin(v), end(v), rng);

    std::vector<int> v2(v);
    std::partial_sort(begin(v2), next(begin(v2), 3), end(v2));
    std::vector<int> v3(v);
    std::nth_element(begin(v3), next(begin(v3), 3), end(v3));
    std::vector<int> v4(v);
    auto mid = next(begin(v4), v4.size() / 2);
    std::nth_element(begin(v4), mid, end(v4));
    std::vector<int> v5(v);
    auto pos = std::partition(begin(v5), end(v5), [](const int &num) {
        return num > 5;
    });
    auto value = std::minmax_element(cbegin(v), cend(v));

    return 0;
}