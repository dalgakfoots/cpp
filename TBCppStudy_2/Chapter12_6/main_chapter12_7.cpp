#include <iostream>
#include <string>

using namespace std;

class Animal // Abstract Class 는 Object 를 만들 수 없다.
{
protected:
    string m_name;

public :
    Animal(string name) : m_name(name)
    {

    }

public :
    string getName() { return m_name; }

    virtual void speak() const = 0; // body 가 없고 ' = 0 으로 되어 있는 함수를 pure virtual function 이라고 부른다.
};

//void Animal::speak() const // 별도로 body 를 지정할 수 있지만, 쓸모는 없다. 호출 할 수 없다.
//{
//    cout << m_name << " ??? " << endl;
//}

class Cat : public Animal
{
public:
    Cat(string name) : Animal(name)
    {

    }

    void speak() const
    {
        cout << m_name << " Meow " << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string name) : Animal(name)
    {

    }

    void speak() const
    {
        cout << m_name << " Woof " << endl;
    }
};

class Cow : public Animal
{
public:
    Cow(string name) : Animal(name)
    {

    }
};

int main()
{
    //Cow cow("moo"); 자식클래스에서 pure virtual function 을 구현하지 않으면, Object 를 만들 수 없다.

    return 0;
}