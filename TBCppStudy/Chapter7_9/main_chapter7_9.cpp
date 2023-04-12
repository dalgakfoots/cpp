#include <iostream>
#include <array>
#include <functional>

using namespace std;

int func()
{
    return 5;
}

int foo()
{
    return 10;
}

//

bool isEven(const int& number)
{
    if (number % 2 == 0) return true;
    else return false;
}

bool isOdd(const int& number)
{
    if (number % 2 != 0) return true;
    else return false;
}


void printNumbers(const std::array<int, 10> &arr , bool (*check_fcn)(const int&) = isEven)
{
    for (auto i : arr)
    {
        if (check_fcn(i) == true) cout << i;
    }
    cout << endl;
}

void printNumbers_std(const std::array<int, 10>& arr, std::function<bool(const int&)> check_fcn)
{
    for (auto i : arr)
    {
        if (check_fcn(i) == true) cout << i;
    }
    cout << endl;
}

int main()
{
    func();
    cout << func << endl; // 함수도 주소를 가지고 있다.

    // 함수 포인터 초기화
    int (*fcnptr)() = func;
    cout << fcnptr() << endl;

    fcnptr = foo;
    cout << fcnptr() << endl;

    //

    std::array<int, 10> my_array { 0,1,2,3,4,5,6,7,8,9 };

    printNumbers(my_array);
    printNumbers(my_array, isOdd);

    cout << endl;

    //

    std::function<bool(const int&)> fcnpt = isEven;
    printNumbers_std(my_array, fcnpt);


    return 0;
}