#include <iostream>
#include <string>
using namespace std;

class Something
{

    // const 를 사용할 수 있다면, 최대한 사용하는 것이 안전하다

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

    int getValue() const // 함수 내부에서 변수를 변경하지 않음을 명시
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

//void print(Something st) // 변수가 복사되고 있다
void print(const Something & st) // 레퍼런스를 사용
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
    //som1.getSvalue() = 1024; 레퍼런스를 통해 변수를 변경 불가능

}