#include <string>
#include <cstddef>
#include <iostream>
#include <locale>
using namespace std;


int main()

{

    {
        // c-style
        /*char* strHello = new char[7];
        strcpy_s(strHello, sizeof(char) * 7, "Hello!");
        cout << strHello << endl;*/
    }

    {
        string string;
        wstring wstring;

        wchar_t wc;
    }

    return 0;
}