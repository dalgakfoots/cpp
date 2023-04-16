#include <iostream>

using namespace std;

class A
{
public :

    int m_value;

    A(const int& in) : m_value(in)
    {
        cout << "Constructor" << endl;
    }

    A()
    {
        cout << "Constructor" << endl;
    }

    ~A()
    {
        cout << "Destructor" << endl;
    }

    void print()
    {
        cout << "Hello " << m_value << endl;
    }
};

int main()
{
    
    A(2).print();

    return 0;
}