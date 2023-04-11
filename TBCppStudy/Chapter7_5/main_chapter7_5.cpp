#include <iostream>
#include <array>
#include <tuple>
using namespace std;

// return by value
int getValue(int x)
{
    int value = x * 2;
    return value;
}

// return by address
// �����. ������.
int* getAddress(int x)
{
    int value = x * 2;
    return &value;
}

int* allocateMemory(int size)
{
    return new int[size]; // delete �� ��� �� ���ΰ�..?
}

// return by reference
int& getReference(int x)
{
    int value = x * 2;
    return value;
}

int& get(std::array<int, 30> arr, int index)
{
    return arr[index];
}

// return by struct
// C-style
// directX ���̺귯���� �̷� ������ �Ǿ�����...
struct S
{
    int a, b, c, d;
};


S getStuct()
{
    S my_s{ 1,2,3,4 };
    return my_s;
}


// return by tuple
std::tuple<int, double> getTuple()
{
    int a = 10;
    double d = 3.14;
    return std::make_tuple(a, d);
}

int main()
{
    int value = getValue(3);
    
    int value_a = * getAddress(3);
    
    int value_r = getReference(3);

    // int &value_r = getReference(3); <- ������
    S value_s = getStuct();
    
    std::tuple<int, double> value_tp = getTuple();
    cout << std::get<0>(value_tp) << endl;
    cout << std::get<1>(value_tp) << endl;

    return 0;
}