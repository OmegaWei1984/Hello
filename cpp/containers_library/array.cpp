#include <array>

int main()
{
    std::array<int, 3> arr1{1, 2, 3};
    std::array arr2{3.0, 1.0, 4.0}; // std::array<double, 3>
    std::array<int, 2> arr3;
    std::array<int, 2> arr4{}; // {0, 0}
    std::array<int, 2> arr5{1}; // {1, 0}

    return 0;
}