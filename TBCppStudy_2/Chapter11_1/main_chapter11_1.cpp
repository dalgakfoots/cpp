#include <iostream>

using namespace std;

class Mother
{
private :
    int m_i;

public :

    Mother() : m_i(0)
    {
    }

    Mother(const int& i_in) : m_i(i_in)
    {
        std::cout << "Mother constructor" << std::endl;
    }

    void setValue(const int& in)
    {
        m_i = in;
    }

    int getValue()
    {
        return m_i;
    }

};


class Child : public Mother // derived class
{
private :
    double m_d;

public :

    Child(const int & i_in , const double & d_in) : Mother(i_in) , m_d(d_in)
    {
        
    }

    void setValue(const int& i_in, const double& d_in)
    {
        Mother::setValue(i_in);
        m_d = d_in;
    }

    void setValue(const double& d)
    {
        m_d = d;
    }

    double getValue()
    {
        return m_d;
    }
};

int main()
{
    Mother mother(1024);
    cout << mother.getValue() << endl;


    Child child(1024,128);
    cout << child.Mother::getValue() << endl;
    cout << child.getValue() << endl;

}