#include <iostream>
#include <typeinfo>
#include <cstddef>

using namespace std;

int* doSomething(int* ptr_a)
{
    return nullptr;
}

struct Something
{
    int a, b, c, d;
};

int main()
{
    int x = 5;

    cout << x << endl;
    cout << (long long) & x << endl; // & : address-of operator

    
    // de-reference operator (*)
    cout << *&x << endl;

    // 메모리 주소를 담는 변수를 포인터라 한다
    int *ptr_x = &x;
    cout << (long long)ptr_x << endl;
    cout << *ptr_x << endl;


    double d = 1.15;
    double *ptr_d = &d;

    cout << ptr_d << endl;
    cout << *ptr_d << endl << endl;

    cout << sizeof(ptr_x) << endl; // 8 in x64
    cout << sizeof(ptr_d) << endl<< endl; // 8 in x64
    
    Something ss;
    Something* ptr_s;

    cout << sizeof(Something) << endl; // 16 bytes
    cout << sizeof(ptr_s) << endl; // 8 in x64

    // Null 포인터
    double* ptr = 0; // c-style
    double* ptr_1 = NULL;
    double* ptr_2 = nullptr; // modern c++

    if (ptr_2 != nullptr)
    {

    }
    else
    {

    }

    std::nullptr_t nptr;


    return 0;
}