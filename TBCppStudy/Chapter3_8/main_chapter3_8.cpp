#include <iostream>
#include <bitset>

using namespace std;

int main()
{

    unsigned int a = 3;

    cout << std::bitset<8>(a) << endl;

    cout << std::bitset<8>(a << 1) << " " << (a << 1) << endl;
    cout << std::bitset<8>(a << 2) << " " << (a << 2) << endl;
    cout << std::bitset<8>(a << 3) << " " << (a << 3) << endl;
    cout << std::bitset<8>(a << 4) << " " << (a << 4) << endl << endl;

    unsigned int b = 1024;
    cout << std::bitset<16>(b) << endl;

    cout << std::bitset<16>(b >> 1) << " " << (b >> 1) << endl;
    cout << std::bitset<16>(b >> 2) << " " << (b >> 2) << endl;
    cout << std::bitset<16>(b >> 3) << " " << (b >> 3) << endl;
    cout << std::bitset<16>(b >> 4) << " " << (b >> 4) << endl << endl;

    unsigned int c = 1024;
    cout << std::bitset<16>(c) << endl;  
    cout << std::bitset<16>(~c) << " " << (~c) << endl << endl;

    unsigned int d = 0b1100;
    unsigned int e = 0b0110;

    cout << std::bitset<4>(d & e) << endl;
    cout << std::bitset<4>(d | e) << endl;
    cout << std::bitset<4>(d ^ e) << endl;

    return 0;
}