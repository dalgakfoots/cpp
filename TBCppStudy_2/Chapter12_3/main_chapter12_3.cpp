#include <iostream>

using namespace std;

class A
{
public :
    void print(int x) 
    {
        cout << "A::getThis()" << endl;
        cout << "A" << endl; 
    }
    //virtual void print(int x) final { cout << "A" << endl; }

    virtual A* getThis() { return this; }

};

class B : public A
{
public:
    void print(int x) { cout << "B" << endl; }
    virtual B* getThis() 
    { 
        cout << "B::getThis()" << endl;
        return this; 
    }
};

class C : public B
{
public:
    void print(int x) { cout << "B" << endl; }
};


int main()
{
    A a;
    B b;

    A& ref = b;
    b.getThis()->print(1); // B
    ref.getThis()->print(1); // A

    cout << typeid(b.getThis()).name() << endl; // class B *
    cout << typeid(ref.getThis()).name() << endl; // class A *

    return 0;
}