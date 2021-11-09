#pragma once
template<class T>
class MyStack {
    public:
        MyStack(int capacity);
        ~MyStack();
        bool isEmpty();
        bool isFull();
        void clearStack();
        int size();
        bool push(T x);
        bool pop(T &x);
        void traverse();

    private:
        T *m_Stack;
        int m_top;
        int m_capacity;
};