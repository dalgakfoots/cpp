#include <iostream>
#include "MyConstants.h"
using namespace std;

//Forward declaration
extern void doSomething();
extern int a;

/*
    int g_x // external linkage
    static int g_x // interanl linkage

    extern int g_z;
    extern const int g_z;
*/
int main()
{
    doSomething();
       
    cout << a << endl;

    cout << Constants::pi << " in main " << &Constants::pi << endl;
    return 0;
}