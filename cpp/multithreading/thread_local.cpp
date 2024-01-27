#include <thread>
#include <iostream>

int main()
{
    thread_local int num1 = 0;
    static int num2 = 0;
    num1 += 10;
    auto f = [&](int x) {
        // num1 = 0;
        std::cout << num1 << std::endl;
        num1 += x;
        num2 += x;
        std::cout << num1 << " " << num2 << std::endl;
    };

    std::thread t1(f, 10);
    std::thread t2(f, 42);
    t1.join();
    t2.join();

    return 0;
}