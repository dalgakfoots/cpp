#include <iostream>

using namespace std;

class Simple
{
private :
    int m_id;

public :
    Simple(int id)
    {
        this->setID(id); // this 는 항상 숨겨져 있음

        cout << this << endl; // 자신의 주소값 (포인터)
    }

    void setID(int id) { m_id = id; }
    int  getID() { return m_id; }
};

class Calc
{
private:
    int m_value;

public:
    Calc(int init_value)
        : m_value(init_value)
    {

    }
    Calc& add(int value) 
    { 
        m_value += value; 
        return *this;
    }
    Calc& sub(int value) 
    {
        m_value -= value; 
        return *this;
    }
    Calc& mult(int value) 
    {
        m_value *= value;
        return *this;
    }

    void print()
    {
        cout << m_value
            << endl;
    }
};

int main()
{
    Simple s1(1), s2(2);

    s1.setID(2);
    s2.setID(4);

    cout << &s1 << " " << &s2 << endl;

    Calc cal(10);
    cal.add(1).sub(10).mult(2).print();


    return 0;
}