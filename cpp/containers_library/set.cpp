#include <set>

class Foo
{
private:
    int m_num;

public:
    Foo(int num) : m_num(num){};

    friend bool operator<(const Foo &lhs, const Foo &rhs);
};

bool operator<(const Foo &lhs, const Foo &rhs)
{
    return lhs.m_num < rhs.m_num;
}

class Bar
{
private:
    int m_num;

public:
    Bar(int num) : m_num(num){};
    int get() const
    {
        return m_num;
    }
};

int main()
{
    std::set<int> s{1, 3, 4};
    s.emplace(2);
    s.erase(4);
    s.emplace(2);
    s.insert(5);
    s.insert({6, 7, 8});

    std::set<Foo> fooSet;
    fooSet.emplace(3);
    fooSet.emplace(1);
    fooSet.emplace(2);
    fooSet.emplace(1);

    auto cmp = [](const Bar& lhs, const Bar& rhs){
        return lhs.get() < rhs.get();
    };

    std::set<Bar, decltype(cmp)> barSet(cmp);
    barSet.emplace(2);
    barSet.emplace(1);
    barSet.emplace(3);
    barSet.emplace(1);

    std::multiset<int> ms{1, 2, 3};
    ms.emplace(2);
    ms.erase(2);

    std::multiset<Foo> fooMultiset;
    fooMultiset.emplace(3);
    fooMultiset.emplace(1);
    fooMultiset.emplace(2);
    fooMultiset.emplace(1);
    auto it = fooMultiset.find(Foo(1));
    if (it != fooMultiset.end())
       fooMultiset.erase(it);

    return 0;
}