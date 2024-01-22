#include <unordered_set>

class Foo
{
private:
    int m_num;

public:
    Foo(int num) : m_num(num){};

    friend bool operator==(const Foo &lhs, const Foo &rhs);

    int get() const
    {
        return m_num;
    }
};

bool operator==(const Foo &lhs, const Foo &rhs)
{
    return lhs.m_num == rhs.m_num;
}

int main()
{
    std::unordered_set<int> us;
    us.insert(3);
    us.insert(1);
    us.insert(2);
    us.insert({3, 4, 5, 6});
    auto it = us.find(6);
    if (it != us.end())
        us.erase(it);
    us.erase(3);

    std::unordered_multiset<int> ums;
    ums.insert(3);
    ums.insert(1);
    ums.insert(2);
    ums.insert({3, 4, 5, 6});
    auto it2 = ums.find(6);
    if (it2 != ums.end())
        ums.erase(it2);
    ums.erase(3);

    auto hasher = [](const Foo &foo)
    {
        return std::hash<int>()(foo.get());
    };
    std::unordered_set<Foo, decltype(hasher)> fooSet(10, hasher);
    fooSet.insert(Foo(3));
    fooSet.insert(Foo(2));

    return 0;
}