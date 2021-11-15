#include"ArrayTree.h"
#include<iostream>
using namespace std;
ArrayTree::ArrayTree(int size)
{
    m_Array = new int[size];
    m_Size = size;
    for (int i = 0; i < m_Size; i++) {
        m_Array[i] = 0;
    }
}
ArrayTree::~ArrayTree()
{
    if (m_Array != nullptr) {
        delete [] m_Array;
    }
    m_Array = nullptr;
}
int *ArrayTree::searchNode(int index)
{
    if (index < 0 || index > m_Size) {
        return nullptr;
    }
    if (m_Array[index] == 0)
        return nullptr;
    return &m_Array[index];
}
bool ArrayTree::addNode(int index, int direction, int *node)
{
    if (index < 0 || index >= m_Size) {
        return false;
    }
    if (m_Array[index] == 0)
        return false;
    if (direction == 0) {
        if (index * 2 + 1 >= m_Size) {
            return false;
        }
        if (m_Array[index * 2 + 1] != 0)
            return false;
        m_Array[index * 2 + 1] = *node;
    }
    if (direction == 1) {
        if (index * 2 + 2 >= m_Size) {
            return false;
        }
        if (m_Array[index * 2 + 2] != 0)
            return false;
        m_Array[index * 2 + 2] = *node;
    }
    return true;
}
bool ArrayTree::deleteNode(int index, int *node)
{
    if (index < 0 || index >= m_Size) {
        return false;
    }
    if (m_Array[index] == 0)
        return false;
    *node = m_Array[index];
    m_Array[index] = 0;
    return true;
}
void ArrayTree::traverse()
{
    for (int i = 0; i < m_Size; i++) {
        cout << m_Array[i] << " ";
    }
}