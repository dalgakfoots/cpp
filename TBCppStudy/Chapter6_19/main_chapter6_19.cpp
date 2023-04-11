#include <iostream>

using namespace std;

int main()
{
    int* ptr = nullptr;
    int** ptrptr = nullptr;

    int value = 5;

    ptr = &value;
    ptrptr = &ptr;


    cout << ptr << " " << *ptr << " " << &ptr << endl;
    cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
    cout << **ptrptr << endl;

    const int row = 3;
    const int col = 5;

    const int s2da[row][col] = 
    {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };

    int** matrix = new int* [row];

    for (int r = 0; r < row; r++)
    {
        matrix[r] = new int[col];
    }

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            matrix[r][c] = s2da[r][c];
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }
    
    // delete
    for (int r = 0; r < row; r++)
    {
        delete [] matrix[r];
    }

    delete[] matrix;

    // 1차원 배열을 2차원 배열처럼 사용하기

    int* m = new int[row * col];

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            m[c + col * r] = s2da[r][c];
            cout << m[c + col * r] << " ";
        }
        cout << endl;
    }


    delete[] m;

    return 0;
}