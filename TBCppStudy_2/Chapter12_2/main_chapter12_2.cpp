#include <iostream>
#include <string>

using namespace std;

class A
{
public :
    // 오버라이딩 된 함수가 있을 경우, 해당 함수를 실행한다
    virtual void print() { cout << "A" << endl; } 
};

class B : public A
{
public :
    // 관습적으로는 오버라이딩 한 함수에도 virtual 키워드를 작성한다.
    // 오버라이딩 했다는 표기 처럼 사용될 수 있다.
    // 작동방식의 특징으로 인해 적절하게 사용하지 않으면 성능이 떨어질 수 있다.
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