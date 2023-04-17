#include <iostream>
#include <string>

using namespace std;

class Animal // Abstract Class �� Object �� ���� �� ����.
{
protected:
    string m_name;

public :
    Animal(string name) : m_name(name)
    {

    }

public :
    string getName() { return m_name; }

    virtual void speak() const = 0; // body �� ���� ' = 0 ���� �Ǿ� �ִ� �Լ��� pure virtual function �̶�� �θ���.
};

//void Animal::speak() const // ������ body �� ������ �� ������, ����� ����. ȣ�� �� �� ����.
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
    //Cow cow("moo"); �ڽ�Ŭ�������� pure virtual function �� �������� ������, Object �� ���� �� ����.

    return 0;
}