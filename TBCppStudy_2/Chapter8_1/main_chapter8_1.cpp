#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Friend : name , address , age , height , weight , ...

class Friend
{

public : // access specifier (public , private , protected)
    string  name;
    string  address;
    int     age;
    double  height;
    double  weight;

    void print()
    {
        cout << name << " " << address << " " << age << " "
            << height << " " << weight << endl;
    }
};

int main()
{
    
    Friend jj{ "Jack Jack" , "Uptown" , 2, 30, 10 }; // instanciation , Instance
    jj.print();


    vector<Friend> my_friends;
    my_friends.resize(2);

    for (auto& elem : my_friends)
    {
        elem.print();
    }

    return 0;
}