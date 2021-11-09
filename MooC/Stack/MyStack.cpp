#include<iostream>
#include"MyStack.h"
using namespace std;
template<class T>
MyStack<T>::MyStack(int capacity)
{
    m_capacity = capacity;
    m_Stack = new T [m_capacity];
    m_top = 0;
}
template<class T>
MyStack<T>::~MyStack()
{
    if (m_Stack != NULL) {
        delete []m_Stack;
    }
    m_Stack = NULL;
}
template<class T>
bool MyStack<T>::isEmpty(){
    return m_top == 0;
}
template<class T>
bool MyStack<T>::isFull()
{
    return m_top == m_capacity;
}
template<class T>
void MyStack<T>::clearStack()
{
    m_top = 0;
}
template<class T>
int MyStack<T>::size()
{
    return m_top;
}
template<class T>
bool MyStack<T>::push(T x)
{
    if (isFull()) {
        return false;
    }
    m_Stack[m_top] = x;
    m_top++;
    return true;
}
template<class T>
bool MyStack<T>::pop(T &x)
{
    if (isEmpty()) {
        return false;
    }
    x = m_Stack[m_top - 1];
    m_top--;
    return true;
}
template<class T>
void MyStack<T>::traverse()
{
    while (!isEmpty()) {
        T tmp;
        pop(tmp);
        cout << tmp << endl;
    }
}