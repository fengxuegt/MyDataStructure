#pragma once
#include"Node.h"
class List {
    public:
        List();
        ~List();
        int size();
        bool empty();
        void clear();
        void travse();
        bool insertHead(int data);
        bool insertTail(int data);
        bool insert(int i, int data);
        bool deleteNode(int i, int data);
    private:
        Node *m_Head;
        int m_Num;
};