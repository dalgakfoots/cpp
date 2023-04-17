#include <iostream>
#include "Cent.h"
using namespace std;

template<typename T_NAME>
T_NAME getMax(T_NAME x, T_NAME y)
{
    return (x > y) ? x : y;
}

int main()
{
    cout << getMax(Cents(5), Cents(7)) << endl;
    return 0;
}