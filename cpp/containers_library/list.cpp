#include <algorithm>
#include <list>

int main()
{
    std::list<int> l{1, 2, 3};
    l.push_back(4);
    l.push_front(0);
    auto it = std::find(l.begin(), l.end(), 2);
    l.insert(it, 42);

    return 0;
}