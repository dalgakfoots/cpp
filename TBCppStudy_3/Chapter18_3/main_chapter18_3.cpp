#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    stringstream os;

    //os << "Hello World!"; // << : insertion operator;
    ////os.str("Hi World!");

    //os << endl << "Hello, World 2";

    //string str;
    //str = os.str(); // >> : extraction operator;
    //cout << str << endl;

    int i = 12345;
    double d = 67.89;
    //os << "12345 67.89";

    os << i << " " << d;

    /*string str1;
    string str2;

    os >> str1 >> str2;

    cout << str1 << "|" << str2;*/

    /*int i2;
    double d2;

    os >> i2 >> d2;

    cout << i2 << " | " << d2;*/

    os.str(""); // ºñ¿ì±â

    return 0;
}