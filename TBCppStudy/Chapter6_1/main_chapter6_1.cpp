#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int width;
};

enum StudentName
{
    JACKJACK,
    DASH,
    VIOLET,
    NUM_STUDENTS,
};

void doSomething(int students_scores[]) // �迭�� �ּҰ��� �����´�
{
    cout << (long long)&students_scores[0] << endl;
    cout << students_scores[0] << endl;
    cout << students_scores[1] << endl;
    cout << students_scores[2] << endl;

}

int main()
{
    const int num_students = 20;
    
    int students_scores[num_students] = {1,2,3,4,5};

    cout << (long long)&students_scores << endl;
    cout << students_scores[0] << endl;
    cout << students_scores[1] << endl;
    cout << students_scores[2] << endl;

    doSomething(students_scores);

    return 0;
}