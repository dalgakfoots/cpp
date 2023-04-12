#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
private: // access specifier
    int m_month;
    int m_day;
    int m_year;

public:
    void setDate(const int& month_input, const int& day_input, const int& year_input)
    {
        m_month = month_input;
        m_day = day_input;
        m_year = year_input;
    }

    void setMonth(const int& month_input)
    {
        m_month = month_input;
    }

    const int& getDay()
    {
        return m_day;
    }

    // ���� Ŭ������� �ٸ� �ν��Ͻ��� private ��� ������ ���� �����ϴ�
    void copyFrom(const Date& origin) 
    {
        m_month = origin.m_month;
        m_day = origin.m_day;
        m_year = origin.m_year;
    }
};

int main()
{
    Date today;
    today.setDate(4, 4, 2023);
    today.setMonth(10);
    cout << today.getDay() << endl;
    
    //
    Date copy;
    copy.copyFrom(today);

    return 0;
}