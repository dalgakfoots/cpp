#include <iostream>

using namespace std;

void doSomething(int& in)
{
    // ������ �̷����� ��, �Ķ���ͷ� �Ѿ�� ���۷����� ������ �߻��Ѵ�.
    cout << "L-value ref" << endl;
}

void doSomething(int&& in)
{
    // move semantics �� ����� �����ϴ�.
    // ��¥�� �Ķ���ͷ� �Ѿ�� ���۷��� ���� ����� ���̱� ������.
    cout << "R-value ref" << endl;
}

int getResult()
{
    return 100 * 100;
}

int main()
{
    int x = 5;
    int y = getResult();
    
    const int cx = 6;
    const int cy = getResult();

    int& lr1 = x;
    // int & lr2 = cx;  // Non-modifiable l-values
    // int & lr3 = 5; // R-values
    const int& lr4 = x;
    const int& lr5 = cx;
    const int& lr6 = 5;

    // R-value Reference : �� ����� �͵鸸...

    int&& rr3 = 5;
    int&& rrr = getResult();
    const int&& rr6 = 5;

    //

    doSomething(x);

    doSomething(5);

    doSomething(getResult());

    return 0;
}