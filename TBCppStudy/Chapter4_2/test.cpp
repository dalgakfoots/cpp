#include <iostream>
#include "MyConstants.h";
extern int a = 123;

void doSomething()
{
    using namespace std;
    cout << Constants::pi << " in test.cpp " << &Constants::pi << endl;
    cout << "Hello" << endl;
}