#include <stdexcept>

int getNum() noexcept
{
    return 42;
}

int getNumException() noexcept
{
    throw std::runtime_error("error");
    return 42;
}

int main()
{
    getNum();
    getNumException();
    return 0;
}