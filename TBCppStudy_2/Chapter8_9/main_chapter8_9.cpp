#include <iostream>
#include <string>
using namespace std;

class Something
{

    // const �� ����� �� �ִٸ�, �ִ��� ����ϴ� ���� �����ϴ�

public:
    int m_value = 0;
    string s_value = "default";

    const string& getSvalue() const 
    {
        cout << "const version" << endl;
        return s_value;
    }

    string& getSvalue()
    {
        cout << "non-const version" << endl;
        return s_value;
   }


    void setValue(int value) 
    { 
        m_value = value; 
    }

    int getValue() const // �Լ� ���ο��� ������ �������� ������ ���
    {
        return m_value; 
    }

    Something(const Something& st_in) // copy constructor
    {
        m_value = st_in.m_value;

        cout << "Copy Constructor" << endl;
    }

    Something()
    {
        //cout << "Constructor" << endl;
    }

    
};

//void print(Something st) // ������ ����ǰ� �ִ�
void print(const Something & st) // ���۷����� ���
{
    cout << &st << endl;
    cout << st.m_value << endl;
}

int main()
{
    //const Something something;
    
    //something.setValue(3);
    // cout << something.getValue() << endl;


    //
    /*Something som;

    cout << &som<< endl;

    print(som);

    return 0;*/

    Something som;
    som.getSvalue() = 10;

    const Something som1;
    //som1.getSvalue() = 1024; ���۷����� ���� ������ ���� �Ұ���

}