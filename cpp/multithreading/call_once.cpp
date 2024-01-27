#include <mutex>
#include <iostream>
#include <thread>

std::once_flag flag1;

int main()
{
    auto f = []()
    {
        std::cout << "tid = "
                  << std::this_thread::get_id() << std::endl;
        std::call_once(flag1, []()
                       { std::cout << "run once" << std::endl; });
    };
    std::thread t1(f);
    std::thread t2(f);
    t1.join();
    t2.join();

    return 0;
}