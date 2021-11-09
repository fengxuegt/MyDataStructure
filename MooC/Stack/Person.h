#pragma once
#include<iostream>
using namespace std;
class Person {
    friend ostream & operator<< (ostream & os, const Person & person);
    public:
        Person(string name, int age):m_name(name), m_age(age) {}
        Person(){}
        ~Person(){}
    private:
        string m_name;
        int m_age;
};


