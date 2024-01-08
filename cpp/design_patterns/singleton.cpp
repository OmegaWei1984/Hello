#include <iostream>
#include <mutex>
#include <string>
#include <thread>

class Singleton
{
private:
    static Singleton *instance;
    static std::mutex mtx;

protected:
    Singleton(const std::string value) : value_(value)
    {
    }
    ~Singleton(){};
    std::string value_;

public:
    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;
    static Singleton *getInstance(const std::string &value)
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (instance == nullptr)
        {
            instance = new Singleton(value);
        }
        return instance;
    }
    std::string value() const
    {
        return value_;
    }
};

void foo()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *inst = Singleton::getInstance("foo");
    std::cout << inst->value() << std::endl;
}

void bar()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *inst = Singleton::getInstance("bar");
    std::cout << inst->value() << std::endl;
}

Singleton *Singleton::instance{nullptr};
std::mutex Singleton::mtx;

int main()
{
    std::thread t1(foo);
    std::thread t2(bar);

    t1.join();
    t2.join();

    return 0;
}