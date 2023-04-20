#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string my_str("abcdefg");

    cout << my_str[0] << endl;
    cout << my_str[3] << endl;

    my_str[3] = 'Z'; // ����ó�� �Ұ�. �����ڰ� Ȯ���� ��ġ�� ���� �ؾ��Ѵ�. ������
    cout << my_str << endl;
    my_str.at(3) = 'X'; // ����ó�� ����. ��������� ����
    cout << my_str << endl;

    const char* arr = my_str.c_str(); // string ���� null character �� �������� ������

    cout << (int)arr[6] << endl; // c_str() ���� �����Ѵ�. �迭ó�� �ٲ�
    cout << (int)arr[7] << endl;

    char buf[20];

    my_str.copy(buf, 5, 0);
    buf[5] = '\0';

    cout << buf << endl;

    return 0;
}