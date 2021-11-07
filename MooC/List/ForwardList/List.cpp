#include<iostream>
using namespace std;
#include"List.h"

List::List()
{
    m_Head = new Node;
    m_Num = 0;
    m_Head->data = 0;
    m_Head->next = NULL;
}
List::~List()
{
    clear();
    delete m_Head; 
}
int List::size(){
    return this->m_Num;
}
bool List::empty()
{
    return this->m_Head->next == NULL;
}
void List::clear()
{
    if (m_Head->next == NULL)
        return;
    else {
        Node *p = m_Head->next;
        while (p != NULL)
        {
            Node *tmp = p;
            p = p->next;
            delete tmp;
        }
    }
    m_Head->next = NULL;
}

bool List::insertHead(int data)
{
    Node * p = new Node(data);
    p->next = NULL;
    p->next = m_Head->next;
    m_Head->next = p;
    m_Num++;
    return true;
}
bool List::insertTail(int data)
{
    Node *p = m_Head;
    while (p->next != NULL) {
        p = p->next;
    }
    Node *newNode = new Node(data);
    if (newNode == NULL) {
        return false;
    }
    newNode->next = NULL;
    p->next = newNode;

    m_Num++;
    return true;
}
bool List::insert(int i, int data)
{
    if (i < 0 || i > m_Num) {
        return false;
    }
    Node* newNode = new Node(data);
    if (newNode == NULL) {
        return false;
    }
    newNode->next = NULL;
    // -1 1 2 3
    //    0 1 2

    Node* cur = m_Head;
    int k = 0;
    while (k < i && cur != NULL) {
        cur = cur->next;
        k++;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    m_Num++;
    return true;
}
bool List::deleteNode(int j, int data)
{

}

void List::travse()
{
    Node * cur = m_Head->next;
    while (cur != NULL) {
        cur->printNode();
        cur = cur->next;
    }
}

