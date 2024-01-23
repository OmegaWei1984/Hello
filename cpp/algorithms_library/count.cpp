#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v{1, 3, 1, 5, 1, 7};
    int c1 = std::count(v.cbegin(), v.cend(), 1);
    int c2 = std::count_if(
        v.cbegin(),
        v.cend(),
        [](const int &i)
        {
            return i > 4;
        });

    return 0;
}