#include <iostream>

using namespace std;

// 보통 선언부에 default 값을 둔다
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