#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string my_str("abcdefg");

    cout << my_str[0] << endl;
    cout << my_str[3] << endl;

    my_str[3] = 'Z'; // 예외처리 불가. 개발자가 확실한 위치를 보장 해야한다. 빠르다
    cout << my_str << endl;
    my_str.at(3) = 'X'; // 예외처리 가능. 상대적으로 느림
    cout << my_str << endl;

    const char* arr = my_str.c_str(); // string 에는 null character 를 저장하지 않지만

    cout << (int)arr[6] << endl; // c_str() 에는 저장한다. 배열처럼 바뀜
    cout << (int)arr[7] << endl;

    char buf[20];

    my_str.copy(buf, 5, 0);
    buf[5] = '\0';

    cout << buf << endl;

    return 0;
}