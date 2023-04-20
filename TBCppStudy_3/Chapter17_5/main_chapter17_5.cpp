#include <string>
#include <iostream>
using namespace std;

int main()
{
    string str1("one");

    string str2;
    str2 = str1;
    str2 = "two";
    str2.assign("two").append(" ").append("three");

    cout << str2 << endl;

    swap(str1, str2);

    cout << str1 << " " << str2 << endl;

    str1.swap(str2);
    
    cout << str1 << " " << str2 << endl;

    str2.push_back('A');

    cout << str2 << endl;

    str2.insert(2, "BBB");
    cout << str2 << endl;


    return 0;
}