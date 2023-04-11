#include <iostream>

using namespace std;

int main()
{
    const int num_rows = 3;
    const int num_columns = 5;
    int array[][num_columns] =
    {
        {1,2,3}, // row 0
        {6,7,8,9,10}, // row 1
        {11,12,13,14,15} // row 2
    };

    for (int row = 0; row < num_rows; row++)
    {
        for (int col = 0; col < num_columns; col++)
        {
            cout << array[row][col] << "\t";
            //cout << (long long) & array[row][col] << "\t"; // 2차원 배열이지만 메모리는 1차원으로 사용된다.
        }
        cout << endl;
    }

    return 0;
}