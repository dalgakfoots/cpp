#include <iostream>

using namespace std;

int main()
{
    int scores[] = { 123 , 2133, 534345, 123123, 222 };
    const int num_students = sizeof(scores) / sizeof(int);

    int total_score = 0;

    for (int i = 0; i < num_students; i++)
    {
        total_score += scores[i];
    }

    double avg = static_cast<double>(total_score) / num_students;

    int max_score = 0;
    for (int i = 0; i < num_students; i++)
    {
        max_score = max_score < scores[i] ? scores[i] : max_score;
    }


}