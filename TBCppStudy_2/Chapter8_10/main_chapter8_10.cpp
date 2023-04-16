#include <iostream>

using namespace std;

class Something
{
public :
    static constexpr int s_csvalue = 2048; // constexpr : 컴파일 시점에 값이 결정되어야 함
    static const int s_svalue = 1024;
    static int s_value;
};

int Something::s_value = 1; // define in cpp file

int generateID()
{
    static int s_id = 0;
    return ++s_id;
}

int main()
{
    cout << &Something::s_value << " " << Something::s_value << endl;

    Something st1;
    Something st2;

    st1.s_value = 2;

    cout << &st1.s_value << " " << st1.s_value << endl;
    cout << &st2.s_value << " " << st2.s_value << endl;

    Something::s_value = 1024;

    cout << &Something::s_value << " " << Something::s_value << endl;

    return 0;
}