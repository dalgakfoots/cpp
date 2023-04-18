#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;

void printCharacterClassfication(const int& i)
{
    cout << boolalpha;
    cout << "isalnum=" << bool(std::isalnum(i)) << endl;
    cout << "isblank=" << bool(std::isblank(i)) << endl;
    cout << "isdigit=" << bool(std::isdigit(i)) << endl;
    cout << "islower=" << bool(std::islower(i)) << endl;
    cout << "isupper=" << bool(std::isupper(i)) << endl;
}

void printStates(const std::ios& stream)
{
    cout << boolalpha;
    cout << "good()=" << stream.good() << endl;
    cout << "eof()=" << stream.eof() << endl;
    cout << "fail()=" << stream.fail() << endl;
    cout << "bad()=" << stream.bad() << endl;
}

void classifyCharacters(const string& str) {
   
    for (auto e : str)
    {
        std::cout << e << endl;
        std::cout << "isdigit" << std::isdigit(e) << endl;
        std::cout << "isblank" << std::isblank(e) << endl;
        std::cout << "isalpha" << std::isalpha(e) << endl;
    }
}

int main()
{
    //while (true)
    //{
    //    char i;
    //    cin >> i;

    //    printStates(cin);

    //    /*
    //    cout << boolalpha;

    //    cout << std::bitset<8>(cin.rdstate()) << endl;
    //    cout << std::bitset<8>(std::istream::goodbit) << endl;
    //    cout << std::bitset<8>(std::istream::failbit) << endl;
    //    cout << !bool((cin.rdstate() & std::istream::failbit) != 0) << endl;*/
    //    

    //    printCharacterClassfication(i);

    //    /*cin.clear();
    //    cin.ignore(1024, '\n');
    //    cout << endl;*/

    //    
    //}

    cout << boolalpha;
    classifyCharacters("1234");
    classifyCharacters("a 1234");

    return 0;
} 