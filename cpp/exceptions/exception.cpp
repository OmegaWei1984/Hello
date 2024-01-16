#include <stdexcept>
#include <iostream>

int main()
{
    int num = 0;
    try
    {
        if (num == 0) throw std::runtime_error("divide by zero");
        float res = 42 / num;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}