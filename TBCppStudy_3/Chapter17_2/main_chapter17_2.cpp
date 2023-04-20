#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template<typename T>
string ToString(T x)
{
    ostringstream osstream;
    osstream << x;
    return osstream.str();
}

template <typename T>
bool FromString(string& str, T& x)
{
    istringstream isstream(str);
    return (isstream >> x) ? true : false;
}

int main()
{
    //string my_string("my string");

    //const char* my_string = "my string";

    /*vector<char> vec;
    for (auto& e : "Today is a good day.")
        vec.push_back(e);

    string second_string(vec.begin(), find(vec.begin(), vec.end(), 'y'));

    cout << second_string << endl;*/


    string my_str(to_string(1004));
    my_str += to_string(128);
    cout << my_str << endl;

    float f = stof(my_str);
    cout << f << endl;

    string temp(ToString(3.141592));
    cout << temp << endl;

    double d;
    if (FromString(my_str, d))
        cout << d << endl;
    else
        cout << "Cannot convert" << endl;

    return 0;
}