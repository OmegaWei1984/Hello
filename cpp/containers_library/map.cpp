#include <map>
#include <string>

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
    std::map<std::string, int> m{{"a", 1}, {"b", 2}};
    m["c"] = 3;
    m.erase("b");
    auto it = m.find("c");
    m.insert({"d", 4});
    m.insert({{"e", 5}, {"f", 6}});
    m.insert({"d", 7});
    m["d"] = 7;

    std::multimap<std::string, int> mm{{"a", 1}, {"b", 2}};
    mm.erase("b");
    auto it2 = mm.find("c");
    mm.insert({"d", 4});
    mm.insert({{"e", 5}, {"f", 6}});
    mm.insert({"d", 7});

    std::map<Foo, std::string> fooMap{{Foo(2), "f2"}};
    fooMap.insert({{Foo(3), "f3"}, {Foo(2), "f2"}});
    fooMap.insert({Foo(1), "f1"});

    auto cmp = [](const Bar& lhs, const Bar& rhs){
        return lhs.get() < rhs.get();
    };

    std::map<Bar, std::string, decltype(cmp)> barMap(cmp);
    barMap.emplace(2, "b2");
    barMap.emplace(1, "b1");
    barMap.emplace(3, "b3");
    barMap.emplace(1, "b1");

    return 0;
}