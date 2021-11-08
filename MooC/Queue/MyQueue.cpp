#include"MyQueue.h"
#include<iostream>
using namespace std;
template<class T>
MyQueue<T>::MyQueue(int capacity) {
    this->m_Queue = new T[capacity];
    this->m_Capacity = capacity;
    clearQueue();
}
template<class T>
MyQueue<T>::~MyQueue(){
    if (this->m_Queue != nullptr) {
        delete [] m_Queue;
    }
    this->m_Queue = nullptr;
}
template<class T>
void MyQueue<T>::clearQueue(){
    this->m_Num = 0;
    this->m_Head = 0;
    this->m_Tail = 0;
}
template<class T>
bool MyQueue<T>::isEmpty(){
    return this->m_Num == 0;
}
template<class T>
bool MyQueue<T>::isFull()
{
    return this->m_Num == this->m_Capacity;
}
template<class T>
int MyQueue<T>::size(){
    return this->m_Num;
}
// 0 1 2 3
template<class T>
bool MyQueue<T>::EnQueue(T x){
    if (isFull()) {
        return false;
    }
    this->m_Queue[this->m_Tail] = x;
    this->m_Num++;
    this->m_Tail = (this->m_Tail + 1) % this->m_Capacity;
    return true;
}
template<class T>
bool MyQueue<T>::DeQueue(T &ele){
    if (isEmpty()) {
        return false;
    }
    ele = this->m_Queue[this->m_Head];
    this->m_Num--;
    this->m_Head = (this->m_Head + 1) % this->m_Capacity;
    return true;
}
template<class T>
void MyQueue<T>::traverse(){
    // for(int i = 0,j = this->m_Head; i < this->m_Num; i++, j++) {
    //     cout << this->m_Queue[j % this->m_Capacity] << endl;
    // }
    for (int i = this->m_Head; i < this->m_Head + this->m_Num; i++) {
        cout << this->m_Queue[i % this->m_Capacity] << endl;
    }
}