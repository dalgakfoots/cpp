#include <iostream>

using namespace std;

class Fraction
{
private :
    int m_numerator;
    int m_denominator;

public :

    Fraction()
    {
        m_numerator = 1;
        m_denominator = 1;
    }

    Fraction(const int& num_in , const int & den_in = 1)
    {
        m_numerator = num_in;
        m_denominator = den_in;

        cout << "Fraction constructor()" << endl;
    }

    void print()
    {
        cout << m_numerator << " / " << m_denominator << endl;
    }
};

int main()
{
    Fraction frac; // 생성자가 없을 경우엔 () 생략한다.
    frac.print();

    Fraction oneThird(1, 3);
    oneThird.print();

    Fraction oneSecond{ 1,2 };

    return 0;
}