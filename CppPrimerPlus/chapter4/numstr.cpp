//
// Created by dgfoot on 2023-04-05.
//

#include <iostream>
int main()
{
    using namespace std;
    cout << "what year was your house built? \n";
    int year;
    cin >> year;
    cin.get();
    cout << "what is its street address?\n";
    char address[80];
    cin.getline(address, 80);

    cout << "Year built : " << year << endl;
    cout << "Address : " << address << endl;
    cout << "Done! \n";
    return 0;
}