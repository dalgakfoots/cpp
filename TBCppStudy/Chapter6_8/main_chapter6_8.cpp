#include <iostream>

using namespace std;

//void printArray(int array[])
void printArray(int *array)
{
    cout << sizeof(array) << endl;
    cout << *array << endl;
    *array = 100;
}

struct MyStruct
{
    int array[5] = { 1, 3, 5,  7 ,9 };
};

void doSomething (MyStruct *ms)
{
    cout << sizeof((*ms).array) << endl;
}

int main()
{

    int array[5] = { 1, 3, 5,  7 ,9 };


    cout << sizeof(array) << endl;

    int* ptr = array;

    cout << sizeof(ptr) << endl;
    
    printArray(array);

    cout << array[0] << " " << *array << endl;

    MyStruct ms;
    cout << sizeof(ms.array) << endl;
    doSomething(&ms);

    return 0;
}