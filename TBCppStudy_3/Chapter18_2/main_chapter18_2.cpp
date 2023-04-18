#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout.setf(std::ios::showpos); // + - 보여줌
    cout << 108 << endl;

    cout.unsetf(std::ios::showpos); // 지우기
    cout << 108 << endl;

    cout.setf(std::ios::uppercase);
    cout.unsetf(std::ios::dec); // 10진수 모드 끔
    cout.setf(std::ios::hex); // 16진수 모드 켬
    cout << 108 << endl;
    cout.unsetf(std::ios::hex);
    cout.setf(std::ios::dec);

    cout << std::hex;
    cout << 108 << endl;

    cout << std::dec;
    cout << 109 << endl;

    cout << std::boolalpha;
    cout << true << " " << false << endl;
    cout << std::noboolalpha;
    cout << true << " " << false << endl;
    return 0;
}