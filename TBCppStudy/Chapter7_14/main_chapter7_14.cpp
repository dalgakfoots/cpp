#include <cassert>
#include <array>
#include <iostream>


void printValue(const std::array<int, 5>& arr, const int& idx)
{
    assert(idx >= 0);
    assert(idx <= arr.size() - 1);

    std::cout << arr[idx] << std::endl;
}

int main()
{

    const int number = 5;
    assert(number == 5);

    std::array<int, 5> my_array{ 1,2,3,4,5 };

    static_assert(number == 5 , "number should be 5");

    return 0;
}