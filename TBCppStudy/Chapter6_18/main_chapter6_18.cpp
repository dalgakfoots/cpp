#include <iostream>

using namespace std;

int main()
{
    int     i = 5;
    float   f = 3.0f;
    char    c = 'a';

    void* ptr = nullptr;

    ptr = &i;
    ptr = &f;

    //cout << ptr + 1 << endl; // void 포인터는 연산이 안된다.
 
    cout << &f << " " << ptr << endl;
    
    //cout << *ptr << endl; // de-reference 가 불가능하다.

    // 캐스팅을 통해 사용 가능
    cout << *static_cast<float*>(ptr) << endl;


    return 0;
}