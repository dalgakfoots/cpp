#include <iostream>

using namespace std;

int main()
{
    int value = 5;
    const int* ptr = &value;
    //*ptr = 6; // �������� �Ұ�

    int value2 = 7;
    ptr = &value2; // �����Ϳ� �ٸ� ������ �ּҰ��� �ִ� ���� ����.

    int value3 = 8;
    int* const ptr1 = &value3;
    *ptr1 = 10; // �������� ����
    //ptr1 = &value2; // �ٸ� �ּҰ��� ���� �Ұ�

    int value4 = 9;
    const int* const ptr2 = &value4;
    //*ptr2 = 1; // ������ �Ұ�
    //ptr2 = &value2; // �ٸ� �ּҰ��� ���� �Ұ�



    cout << *ptr << endl;
    return 0;
}