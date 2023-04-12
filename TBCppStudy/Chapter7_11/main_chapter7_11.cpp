#include <iostream>
#include <vector>
using namespace std;

void printStack(const std::vector<int>& stack)
{
    for (auto& e : stack)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    //// int *v_ptr = new int[3] {1,2,3} 과 유사함
    //std::vector<int> v{ 1,2,3 };
    //
    //// 내부의 new 와 delete 를 적게 사용하는 것이
    //// 벡터를 최적화 하는 방법 중 하나이다.
    //
    //v.resize(2);

    //for (auto& e : v)
    //{
    //    cout << e << " ";
    //}
    //cout << endl;

    //cout << v.size() << " " << v.capacity() << endl; // 2 3

    ////cout << v.at(2) << endl;

    //// 억지로 가져오기
    //int* ptr = v.data();
    //cout << ptr[2] << endl;

    //// reserve
    //v.reserve(1024);
    //for (auto& e : v)
    //{
    //    cout << e << " ";
    //}
    //cout << endl;
    //cout << v.size() << " " << v.capacity() << endl; // 2 1024

    // stack 처럼 사용하기

    std::vector<int> stack;

    // stack.reserve(1024);

    stack.push_back(3);
    printStack(stack);

    stack.push_back(5);
    printStack(stack);

    stack.push_back(7);
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    return 0;
}