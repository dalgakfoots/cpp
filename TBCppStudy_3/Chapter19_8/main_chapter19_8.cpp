#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Examples
{
public:
    void ex1()
    {
        std::vector<int> vect;

        for(vector<int>::iterator itr = vect.begin(); itr != vect.end(); itr++)
        {
            cout << *itr;
        }

        for (auto itr = vect.begin(); itr != vect.end(); itr++)
        {
            cout << *itr;
        }

        for (auto itr : vect)
        {
            cout << itr;
        }
    }

    void ex2()
    {
        int x = int();

        auto auto_x = x;

        const int& crx = x; 

        auto auto_crx1 = crx;

        const auto& auto_crx2 = crx;

        volatile int vx = 1024;

        auto avx = vx;

        volatile auto vavx = vx;
    }

    template<class T>
    void func_ex3(T arg)
    {

    }

    void ex3()
    {
        const int& crx = 123;
        func_ex3(crx);
    }

    template<typename T, typename S>
    void func_ex7(T lhs, S rhs)
    {
        auto prod1 = lhs * rhs;

        typedef decltype (lhs* rhs) product_type;

        product_type prod2 = lhs * rhs;

        decltype(lhs * rhs) prod3 = lhs * rhs;
    }

    template<typename T, typename S>
    auto func_ex8(T lhs, S rhs) -> decltype(lhs * rhs)
    {
        return lhs * rhs;
    }
};