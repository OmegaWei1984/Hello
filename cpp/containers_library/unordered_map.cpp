#include <unordered_map>
#include <string>

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
    std::unordered_map<std::string, int> um{{"a", 1}, {"b", 2}};
    um["c"] = 3;
    um.erase("b");
    auto it = um.find("c");
    um.insert({"d", 4});
    um.insert({{"e", 5}, {"f", 6}});
    um.insert({"d", 7});
    um["d"] = 7;

    std::unordered_multimap<std::string, int> umm{{"a", 1}, {"b", 2}};
    umm.erase("b");
    auto it2 = umm.find("c");
    umm.insert({"d", 4});
    umm.insert({{"e", 5}, {"f", 6}});
    umm.insert({"d", 7});

    auto hasher = [](const Foo &foo)
    {
        return std::hash<int>()(foo.get());
    };
    std::unordered_map<Foo, std::string, decltype(hasher)> fooUnorderedMap(10, hasher);
    fooUnorderedMap.insert({Foo(1), "f1"});
    fooUnorderedMap.insert({{Foo(3), "f3"}, {Foo(2), "f2"}});

    return 0;
}