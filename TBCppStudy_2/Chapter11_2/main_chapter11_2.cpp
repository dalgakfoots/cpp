#include <iostream>
#include "Student.h"
#include "Teacher.h"

using namespace std;



int main()
{
    Student std("Jack jack");
    
    Teacher teacher1("Dr. k");

    std::cout << std << " " << teacher1 << std::endl;

    std.doNothing();
    teacher1.doNothing();

    std.study();
    teacher1.teach();

    Person person;
    person.setName("Mr. cha");
    cout << person.getName() << endl;

    return 0;
}