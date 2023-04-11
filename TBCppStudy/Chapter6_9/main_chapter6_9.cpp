#include <iostream>

using namespace std;

int main()
{
    /* int value = 7;
    int* ptr = &value;

    // 데이터 사이즈 * n 만큼 이동한다
    cout << uintptr_t(ptr - 1) << endl;
    cout << uintptr_t(ptr) << endl;
    cout << uintptr_t(ptr + 1) << endl;
    cout << uintptr_t(ptr + 2) << endl;*/

    //int array[] = { 1,3,5,7,9 };
    //int* ptr = array;

    //for (int i = 0; i < 5; i++)
    //{
    //    //cout << array[i] << " " << (uintptr_t) & array[i] << endl;
    //    cout << *(ptr + i) << " " << (uintptr_t)(ptr + i) << endl;
    //}

    char name[] = "Jack jack";
    char* ptr = name;
    const int n_name = sizeof(name) / sizeof(name[0]);

    for (int i = 0; i < n_name; ++i)
    {
        cout << *(ptr + i);
    }

    cout << endl;

    while (true)
    {
        if (*ptr == '\0') break;
        cout << *ptr++;
    }

    return 0;
}