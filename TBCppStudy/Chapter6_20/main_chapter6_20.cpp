#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void printLength(const std::array<int, 5>& arr)
{
    cout << arr.size() << endl;
}
int main()
{
    int arr[5] = { 1,2,3,4,5 };
    std::array<int, 5> my_arr = { 1,2,3,4,5 };

    my_arr = {0,1,2,3,4};
    my_arr = { 0,1,3 };

    cout << my_arr[0] << endl;
    cout << my_arr.at(0) << endl;
    cout << my_arr.size() << endl;

    printLength(my_arr);

    std::array<int, 5> my_arr1 = { 1,21, 3, 56, 123 };

    for (auto& element : my_arr1)
        cout << element << " ";
    cout << endl;

    std::sort(my_arr1.begin(), my_arr1.end());
    for (auto& element : my_arr1)
        cout << element << " ";
    cout << endl;

    std::sort(my_arr1.rbegin(), my_arr1.rend());
    for (auto& element : my_arr1)
        cout << element << " ";
    cout << endl;

    return 0;
}