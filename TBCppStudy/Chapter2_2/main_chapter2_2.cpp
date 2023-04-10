#include <iostream>
#include <cmath>
#include <limits>

int main()
{
    using namespace std;

    short   s = 1; // 2 * 8 = 16 bits

    /*cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl;
    cout << std::numeric_limits<short>::max() << endl;
    cout << std::numeric_limits<short>::min() << endl;
    cout << std::numeric_limits<short>::lowest() << endl;*/

    s = 32767;
    s = s + 1;
    cout << s << endl; // overflow

    s = std::numeric_limits<short>::min();
    s = s - 1;
    cout << s << endl; 

    return 0;
}