#include <iostream>
#include <cstdarg> // for ellipsis

using namespace std;

double findAverage(int count, ...)
{
    double sum = 0;

    va_list list;

    va_start(list, count);

    for (int arg = 0; arg < count; ++arg)
    {
        sum += va_arg(list, int);
    }

    va_end(list);

    return sum / count;
}

int main()
{
    
    return 0;
}