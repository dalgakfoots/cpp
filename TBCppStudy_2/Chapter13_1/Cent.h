#pragma once
#include <iostream>

class Cents
{
private:
    int m_cents;

public :
    Cents(int cents) : m_cents(cents)
    {

    }

public :

    friend bool operator > (const Cents& c1, const Cents& c2)
    {
        return (c1.m_cents > c2.m_cents);
    }

    friend std::ostream& operator << (std::ostream& out, const Cents& cent)
    {
        out << cent.m_cents << " cents ";
        return out;
    }

};