//
// Created by dgfoot on 2023-04-05.
//

#include <iostream>
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter Your name: ";
    cin.getline(name, ArSize);
    cout << "Enter your favorite dessert: ";
    cin.getline(dessert, ArSize);
    cout << "I have some delicious " <<  dessert;
    cout << " for you, " << name << "." << endl;
    return 0;
}