#include <iostream>
#include <string>

using namespace std;

class A
{
public :
    // �������̵� �� �Լ��� ���� ���, �ش� �Լ��� �����Ѵ�
    virtual void print() { cout << "A" << endl; } 
};

class B : public A
{
public :
    // ���������δ� �������̵� �� �Լ����� virtual Ű���带 �ۼ��Ѵ�.
    // �������̵� �ߴٴ� ǥ�� ó�� ���� �� �ִ�.
    // �۵������ Ư¡���� ���� �����ϰ� ������� ������ ������ ������ �� �ִ�.
    virtual void print() { cout << "B" << endl; }
};

class C : public B
{
public:
    virtual void print() { cout << "C" << endl; }
};

class D : public C
{
public:
    virtual void print() { cout << "D" << endl;}
};

int main()
{
    A a;
    B b;
    C c;
    D d;

    B& ref = c;
    ref.print();


    return 0;
}