#pragma once
#include <iostream>

template <class T>
class Storage
{
private:
    T m_value;

public :
    Storage(T value) : m_value(value)
    {

    }

    ~Storage()
    {

    }

public :
    void print()
    {
        std::cout << m_value << "\n";
    }
};

// Specialized instantiation
template<>
void Storage<double>::print()
{
    std::cout << " Double Type ";
    std::cout << std::scientific << m_value << "\n";
}