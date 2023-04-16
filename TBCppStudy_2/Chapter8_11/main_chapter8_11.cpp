#include <iostream>

using namespace std;

class Something
{

public:

    class _init // inner class
    {
    public:
        _init()
        {
            s_value = 9999;
        }
    };

    static int s_value;
    int m_value;

    static _init s_initializer;

public :
    
    Something() : m_value(121) // static 멤버 변수는 생성자에서 초기화 할 수 없다
    {

    }
    
    static int getValue() // 특정 인스턴스와 상관 없이 실행 가능
    {
        return s_value;
    }

    int temp() // 함수의 주소는 모든 인스턴스에서 같다
    {
        // static 함수에서는 아래와 같이 this 포인터를 사용하지 못한다
        return this->s_value;
    }

};

int Something::s_value = 1024;
Something::_init Something::s_initializer;

int main()
{

    cout << Something::getValue() << endl; // 스태틱 멤버 함수를 통해 static 하게 private 값에 접근이 가능하다

    Something s1 , s2;

    cout << s1.getValue() << endl;
    //cout << s1.s_value << endl;

    int (Something:: * fptr1)() = &(Something::temp);
    cout << (s2.*fptr1)() << endl;

    int (*fptr2)() = &(Something::getValue);
    cout << fptr2() << endl;

    return 0;
}