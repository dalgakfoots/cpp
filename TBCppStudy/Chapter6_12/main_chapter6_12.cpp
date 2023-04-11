#include <iostream>

using namespace std;

int main()
{
    int value = 5;
    const int* ptr = &value;
    //*ptr = 6; // 역참조는 불가

    int value2 = 7;
    ptr = &value2; // 포인터에 다른 변수의 주소값을 넣는 것은 가능.

    int value3 = 8;
    int* const ptr1 = &value3;
    *ptr1 = 10; // 역참조는 가능
    //ptr1 = &value2; // 다른 주소값을 대입 불가

    int value4 = 9;
    const int* const ptr2 = &value4;
    //*ptr2 = 1; // 역참조 불가
    //ptr2 = &value2; // 다른 주소값을 대입 불가



    cout << *ptr << endl;
    return 0;
}