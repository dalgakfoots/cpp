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
    
    Something() : m_value(121) // static ��� ������ �����ڿ��� �ʱ�ȭ �� �� ����
    {

    }
    
    static int getValue() // Ư�� �ν��Ͻ��� ��� ���� ���� ����
    {
        return s_value;
    }

    int temp() // �Լ��� �ּҴ� ��� �ν��Ͻ����� ����
    {
        // static �Լ������� �Ʒ��� ���� this �����͸� ������� ���Ѵ�
        return this->s_value;
    }

};

int Something::s_value = 1024;
Something::_init Something::s_initializer;

int main()
{

    cout << Something::getValue() << endl; // ����ƽ ��� �Լ��� ���� static �ϰ� private ���� ������ �����ϴ�

    Something s1 , s2;

    cout << s1.getValue() << endl;
    //cout << s1.s_value << endl;

    int (Something:: * fptr1)() = &(Something::temp);
    cout << (s2.*fptr1)() << endl;

    int (*fptr2)() = &(Something::getValue);
    cout << fptr2() << endl;

    return 0;
}