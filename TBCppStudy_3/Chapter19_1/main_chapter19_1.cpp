#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void goodbye(const string& s)
{
    cout << "Good bye " << s << endl;
}

class Object
{
public :
    void hello(const string &s)
    {
        cout << "Hello " << s << endl;
    }
};

int main()
{
    // lambda-introducer
    // lambda-parameter-declaration
    // lambda-return-type-clause
    // compound-statement
    auto func = [](const int& i) -> void { cout << "Hello world" << endl; };

    func(123);

    [](const int& i) -> void { cout << "Hello world" << endl; }(1234);

    {
        string name = "JackJack";
        [&]() {std::cout << name << endl; }(); // reference
        //[=]() {std::cout << name << endl; }(); // copy

    }

    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    auto func2 = [](int val) {cout << val << endl; };
    for_each(v.begin(), v.end(), func2);
 
    for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

    cout << []() -> int {return 1; }() << endl;

    function<void(int)> func3 = func2;
    func3(123);

    function<void()> func4 = std::bind(func3, 345); // 파라미터를 바인드 시킨다
    func4();

    {
        Object instance;
        auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

        auto f2 = std::bind(&goodbye, std::placeholders::_1);
        f2(string("world"));
    }

    return 0;
}