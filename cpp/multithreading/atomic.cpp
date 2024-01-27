#include <thread>
#include <atomic>
#include <vector>

std::atomic<int> cnt1{0};
int cnt2{0};

void f2()
{
    for (int n = 0; n < 10000; ++n)
    {
        cnt1++;
        cnt2++;
    }
}

int main()
{
    std::atomic<int> i{42};
    std::atomic<double> j{3.1415};
    static std::atomic_flag flag{false};
    static std::atomic<int> num{0};
    auto f = [&]()
    {
        bool res = flag.test_and_set();
        num += res ? 42 : 0;
    };

    std::thread t1(f);
    std::thread t2(f);
    t1.join();
    t2.join();

    {
        std::vector<std::thread> pool;
        for (int c = 0; c < 10; c++)
            pool.emplace_back(f2);
        for (int c = 0; c < 10; c++)
            pool[c].join();
    }

    return 0;
}
