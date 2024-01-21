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

    std::set<Foo> fooSet;
    fooSet.emplace(3);
    fooSet.emplace(1);
    fooSet.emplace(2);

    auto cmp = [](const Bar& lhs, const Bar& rhs){
        return lhs.get() < rhs.get();
    };

    std::set<Bar, decltype(cmp)> barSet(cmp);
    barSet.emplace(2);
    barSet.emplace(1);
    barSet.emplace(3);

    return 0;
}