#include <iostream>
#include <cstdio>

int main()
{
    using namespace std;

    int x = 1024;
    double pi = 3.141592;
    cout << "I love this lecture!\n"; // << std::endl;
    
    cout << "x is " << x << " pi is " << pi << endl;

    cout << "abc" << "\t" << "def" << endl;
    cout << "ab" << "\t" << "cdef" << endl;

    cout << "\a"; // audio Ãâ·Â

    int y;
    cin >> y;
    cout << "your input is " << y << endl;

    return 0;
}