#pragma once
template <class T>
class MyQueue {
public:
    MyQueue(){}
    MyQueue(int capacity);

    virtual ~MyQueue();
    void clearQueue();
    bool isEmpty();
    bool isFull();
    int size();
    bool EnQueue(T x);
    bool DeQueue(T &ele);
    void traverse();


private:
    T *m_Queue;
    int m_Capacity;
    int m_Num;
    int m_Head;
    int m_Tail;
};