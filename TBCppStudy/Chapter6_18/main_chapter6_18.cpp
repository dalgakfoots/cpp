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

    //cout << ptr + 1 << endl; // void �����ʹ� ������ �ȵȴ�.
 
    cout << &f << " " << ptr << endl;
    
    //cout << *ptr << endl; // de-reference �� �Ұ����ϴ�.

    // ĳ������ ���� ��� ����
    cout << *static_cast<float*>(ptr) << endl;


    return 0;
}