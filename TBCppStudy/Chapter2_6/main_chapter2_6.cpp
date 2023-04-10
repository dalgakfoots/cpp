#include <iostream>


bool isEven(int a);

bool isEqual(int a, int b)
{
    bool result = (a == b);

    return result;
}

int main()
{
    using namespace std;

    bool b1 = true; // copy initialization
    bool b2(false); // direct initialization
    bool b3{ true }; // uniform initialization
    b3 = false;

    cout << std::noboolalpha;
    cout << b3 << endl;
    cout << b1 << endl;
    cout << !true << endl;
    cout << !false << endl << endl;

    cout << (true && true) << endl;
    cout << (true && false) << endl;
    cout << (false && true) << endl;
    cout << (false && false) << endl << endl;

    cout << (true || true) << endl;
    cout << (true || false) << endl;
    cout << (false || true) << endl;
    cout << (false || false) << endl << endl;

    if (3 > 1)
    {
        cout << "This is true" << endl;
        cout << "True second line" << endl;
    }
    else
        cout << "This is false" << endl;

    cout << std::boolalpha;
    cout << isEqual(1, 1) << endl;

    int i;
    cout << "input number : ";
    cin >> i;
    cout << "Your number is even? : " << isEven(i) << endl;


    bool b;
    cin >> b;
    cout << std::boolalpha;
    cout << "Your input : " << b << endl;
    return 0;
}