#include <iostream>

using namespace std;

// ���� ����ο� default ���� �д�
void print(int x = 10, int y = 20, int z = 30);
void print(int x, int y , int z)
{
    cout << x << " " << y << " " << z << endl;
}


int main()
{
    print();
    print(100);
    

    return 0;
}