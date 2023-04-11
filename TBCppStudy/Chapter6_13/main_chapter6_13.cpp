#include <iostream>

using namespace std;

void doSomething(int &n) 
{
    n = 10;
    cout << "in doSomething() " << n << endl;
}

void printElenments(int(&arr)[5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}

// 파라미터가 reference 인 경우 리터럴을 바로 넘길 수 있다.
void refDoSomething(const int& n)
{
    cout << n << endl;
}

struct Something
{
    int v1;
    float v2;
};

struct Other
{
    Something st;
};

int main()
{
    int value = 5;
    int* ptr = nullptr;
    ptr = &value;

    int& ref = value; // 같은 메모리를 사용하는 것처럼 작동한다.
    // 별명 처럼 사용

    ref = 10;

    cout << value << " " << ref << endl;

    //int& ref1; // ref 는 초기화 되어야 한다.
    //int& ref1 = 123; // 리터럴로 초기화할 수 없다.
    
    const int v = 8;
    //int& ref = v; // 문법 상 ref 는 const 변수로 초기화 할 수 없다.

    int value1 = 5;
    int value2 = 10;
   
    int& ref1 = value1;
    cout << ref1 << endl;
    ref1 = value2;
    cout << ref1 << endl;

    cout << endl;

    int n = 5;
    cout << "n : " << n << endl;
    doSomething(n);
    cout << "n in main(): " << n << endl;

    const int length = 5;
    int arr[length] = { 1,2,3,4,5 };
    printElenments(arr);

    Other ot;
    int& v1 = ot.st.v1;
    v1 = 1;

    // 아래 코드는 같은 코드
    // 레퍼런스도 내부적으론 포인터로 구현되어 있다.
    int value0 = 0;
    int* const ptr0 = &value;
    int& ref0 = value;

    *ptr = 10;
    ref = 10;

    //
    int x = 5;
    int &ref_x = x;

    int y = 6;
    const int& ref_y = y;

    const int z = 7;
    const int& ref_z = z;

    const int& o = 3 + 4;
    
    refDoSomething(1);

    return 0;
}