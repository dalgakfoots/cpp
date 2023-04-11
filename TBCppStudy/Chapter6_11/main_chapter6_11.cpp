#include <iostream>

using namespace std;

int main()
{
    int length;
    cin >> length;

    // 동적 배열 할당
    int* array = new int[length]();
    delete [] array;

    // resizing


    return 0;
}