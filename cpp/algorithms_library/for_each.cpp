#include "lib/common.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

struct Sum
{
    void operator()(int n) { sum += n; }
    int sum{0};
};

int main()
{
    std::vector<int> v{0, 1, 2, 3, 4, 5};
    std::for_each(v.cbegin(), v.cend(), [](const int &num)
                  { std::cout << num << ", "; });
    std::cout << std::endl;
    std::for_each(v.begin(), v.end(), [](int &num)
                  { num++; });
    // 1 + 2 + ... + 6 = 
    Sum s = std::for_each(v.cbegin(), v.cend(), Sum());
    // assert(s.sum == 21);

    return 0;
}