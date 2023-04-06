#include <iostream>

using namespace std;

void print()
{
    cout << "Hello World" << endl;
}

int addTwoNumbers(int x, int y)
{
    return x + y;
}

int main()
{
    int sum = addTwoNumbers(1, 2);
    return 0;
}