#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

void doSomething()
{
    //Resource* res = new Resource; // dull pointer
    // delete res;
    AutoPtr<Resource> res(new Resource); // smart pointer



    return;
}

int main()
{
    doSomething();
    return 0;
}