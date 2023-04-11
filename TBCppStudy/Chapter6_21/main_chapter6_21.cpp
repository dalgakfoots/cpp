#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> array;
    
    std::vector<int> array2 = { 1,2,3,4,5 };
    cout << array2.size() << endl;

    array2.resize(2);

    for (auto& itr : array2)
    {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}