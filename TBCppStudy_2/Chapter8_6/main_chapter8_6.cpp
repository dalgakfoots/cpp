#include <iostream>

using namespace std;

class Simple
{
private :
    int m_id;

public :
    Simple(const int& id_in)
    {
        m_id = id_in;
        cout << "Constructor " << m_id << endl;
    }

    ~Simple() // 소멸자는 파라미터가 없음
    {
        cout << "Destructor " << m_id << endl;
    }
};

class IntArray
{
private :
    int* m_arr = nullptr;
    int m_length = 0;

public :
    IntArray(const int length_in)
    {
        m_length = length_in;
        m_arr = new int[length_in];
        // cout << "Constructor" << endl;
    }

    ~IntArray()
    {
        if(m_arr != nullptr)
            delete [] m_arr;

    }

    int size() {
        return m_length;
    }
};

int main()
{
    /*Simple *s1 = new Simple(0);
    Simple s2(1);
    delete s1;*/

    return 0;
}