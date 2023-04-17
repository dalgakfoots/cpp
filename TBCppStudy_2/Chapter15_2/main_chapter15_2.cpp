#include <iostream>

using namespace std;

void doSomething(int& in)
{
    // 변경이 이뤄졌을 때, 파라미터로 넘어온 레퍼런스에 영향이 발생한다.
    cout << "L-value ref" << endl;
}

void doSomething(int&& in)
{
    // move semantics 를 사용이 가능하다.
    // 어짜피 파라미터로 넘어온 레퍼런스 값은 사라질 값이기 때문에.
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

    // R-value Reference : 곧 사라질 것들만...

    int&& rr3 = 5;
    int&& rrr = getResult();
    const int&& rr6 = 5;

    //

    doSomething(x);

    doSomething(5);

    doSomething(getResult());

    return 0;
}