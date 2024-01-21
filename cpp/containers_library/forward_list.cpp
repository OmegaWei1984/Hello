#include <algorithm>
#include <forward_list>

int main()
{
    std::forward_list<int> fl{3,4,5};
    fl.push_front(1);
    auto it = find(fl.begin(), fl.end(), 1);
    if (it != fl.end())
        fl.insert_after(it, 2);

    return 0;
}