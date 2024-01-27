#include <algorithm>
#include <future>
#include <iostream>
#include <mutex>
#include <numeric>
#include <string>
#include <vector>

template <typename RandomIt>
int parallel_sum(RandomIt beg, RandomIt end)
{
    auto len = end - beg;
    if (len < 1000)
    {
        return std::accumulate(beg, end, 0);
    }
    RandomIt mid = beg + len / 2;
    auto handle = std::async(
        std::launch::async,
        parallel_sum<RandomIt>,
        mid,
        end);
    int sum = parallel_sum(beg, mid);
    return sum + handle.get();
}

std::mutex m;

struct Foo
{
    void foo(int i, const std::string &str)
    {
        std::lock_guard<std::mutex> lk(m);
        std::cout << i << " " << str << std::endl;
    }

    void bar(const std::string &str)
    {
        std::lock_guard<std::mutex> lk(m);
        std::cout << str << std::endl;
    }

    int operator()(int i)
    {
        std::lock_guard<std::mutex> lk(m);
        std::cout << i << std::endl;
        return i + 10;
    }
};

int main()
{
    std::vector<int> v(10000, 1);
    int res = parallel_sum(v.begin(), v.end());
    Foo f;
    auto a1 = std::async(&Foo::foo, &f, 42, "hello");
    auto a2 = std::async(std::launch::deferred, &Foo::bar, f, "world!");
    auto a3 = std::async(std::launch::async, Foo(), 43);
    a2.wait();
    std::cout << a3.get() << std::endl;

    return 0;
}