#include <iostream>

using namespace std;

class B; // forward declaration

class A
{
private:
    int m_value = 1;
    // friend �Լ� ����
    friend void doSomething(A& a);

    friend void doSomething1(A& a, B& b);

    friend class B;
};

class B
{
private:
    int m_value = 2;

    friend void doSomething1(A& a, B& b);

public :
    void doSomething(A& a)
    {
        cout << a.m_value << endl;
    }
};

void doSomething(A& a)
{
    // friend �Լ� �� ���, private ����� ������ ����
    cout << a.m_value << endl;
}

void doSomething1(A& a, B& b)
{
    cout << a.m_value << " " << b.m_value << endl;
}

int main()
{
    A a;
    B b;
    b.doSomething(a);
    return 0;
}