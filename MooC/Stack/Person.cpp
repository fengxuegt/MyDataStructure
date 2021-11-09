#include"Person.h"
ostream & operator<< (ostream & os, const Person & person)
{
    os << person.m_name  << ", " << person.m_age << endl;
    return os;
} 