#include <iostream>
#include <limits>
int main()
{
    using namespace std;

    char c = 65;


    cout << char(65) << endl;
    cout << int('A') << endl;

    cout << static_cast<char>(65) << endl;
    cout << static_cast<int>('A') << endl;

    char c1;
    cin >> c1;
    cout << c1 << " " << static_cast<int>(c1) << endl;

    cout << sizeof(char) << endl;
    cout << (int)std::numeric_limits<char>::max() << endl;
    cout << (int)std::numeric_limits<char>::lowest() << endl;

    return 0;

}