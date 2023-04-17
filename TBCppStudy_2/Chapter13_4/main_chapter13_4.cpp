#include <iostream>
#include "Storage.h"
using namespace std;

template<typename T>
T getMax(T x, T y)
{
    return (x > y) ? x : y;
}

// Specialized
template<>
char getMax(char x, char y)
{
    cout << "warning : comparing chars" << endl;
    return (x > y) ? x : y;
}

int main()
{
    Storage<int> nValue(5);
    Storage<double> dValue(1.65);

    nValue.print();
    dValue.print();
}