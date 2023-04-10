#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

int main()
{
    using namespace std;

    float f(3.141592f);
    double d(3.141592);
    long double ld(3.141592);

    cout << sizeof(f) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(ld) << endl <<endl;

    cout << numeric_limits<float>::max() << endl;
    cout << numeric_limits<double>::max() << endl;
    cout << numeric_limits<long double>::max() << endl << endl;

    cout << numeric_limits<float>::lowest() << endl;
    cout << numeric_limits<double>::lowest() << endl;
    cout << numeric_limits<long double>::lowest() << endl << endl;

    cout << 3.14 << endl;
    cout << 31.4e-1 << endl;
    cout << 31.4e-2 << endl;
    cout << 31.4e1 << endl;
    cout << 31.4e2 << endl << endl;

    cout << std::setprecision(16) << endl;
    cout << 1.0 / 3.0 << endl << endl;

    float a(123456789.0f);
    cout << std::setprecision(9);
    cout << a << endl << endl;

    double b(0.1);
    cout << b << endl;
    cout << std::setprecision(17);
    cout << b << endl << endl;

    double d1(1.0);
    double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);

    cout << setprecision(17);
    cout << d1 << endl;
    cout << d2 << endl << endl;

    double zero = 0.0;
    double posinf = 5.0 / zero;
    double neginf = -5.0 / zero;
    double nan = zero / zero;
    
    cout << posinf << " " << std::isinf(posinf) << endl;
    cout << neginf << " " << std::isinf(neginf) << endl;
    cout << nan << " " << std::isnan(nan) << endl;

    return 0;
}