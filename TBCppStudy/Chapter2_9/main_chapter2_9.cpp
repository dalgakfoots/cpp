#include <iostream>
#include "MY_CONSTANTS.h"
using namespace std;

void printNumber(const int my_number)
{
    int n = my_number;
    cout << n << endl;
}

int main()
{
    constexpr double gravity{ 9.8 }; // constexpr : ������ �� �����Ǵ� ���
    printNumber(123);

    int number;
    cin >> number;
    const int special_number(number);

    double t = 2.0 * constants::pi;
    return 0;
}