/* ************************************************************************
> File Name:     array_list.cpp
> Author:        fengxuegt
> blog:          fengxuegt.github.io
> Created Time:  2021年11月05日 星期五 23时23分29秒
> Description:   
 ************************************************************************/
#include "array_list.h"
#include<iostream>
using namespace std;

ArrayList::ArrayList(int size) {
    this->m_Size = size;
    this->m_List = new int[size];
    this->m_Num = 0;
}

void ArrayList::ClearList() {
    this->m_Num = 0;
}

bool ArrayList::IsEmpty() {
    return this->m_Num == 0;
}

ArrayList::~ArrayList() {
    if (this->m_List != NULL) {
        delete []this->m_List;
        this->m_Size = 0;
        this->m_Num = 0;
        this->m_List = NULL;
    }
}

bool ArrayList::GetElement(int i, int *res)
{
    if (i < 0 || i >= this->m_Num) {
        return false;
    }
    *res = this->m_List[i];
    return true;
}

int ArrayList::ListLength()
{
    return this->m_Num;
}
 
int ArrayList::LocateEle(int *ele) {
    for (int i = 0; i < m_Num; i++) {
        if (m_List[i] == *ele) {
            return i;
        }
    }
    return -1;
} 

bool ArrayList::preEle(int *cur, int *pre)
 {
     int res = LocateEle(cur);
     if (res == -1 || res == 0) {
         return false;
     }
     *pre = m_List[res - 1];
     return true;
 }

bool ArrayList::nextEle(int *cur, int *next)
{
     int res = LocateEle(cur);
     if (res == -1 || res == m_Num - 1) {
         return false;
     }
     *next = m_List[res + 1];
     return true;
}

void ArrayList::traverse()
{
    for (int i = 0; i < m_Num; i++) {
        cout << m_List[i] << " ";
    }
    cout << endl;
}

bool ArrayList::insertEle(int i, int *ele)
{
    if (i < 0 || i > m_Num || m_Num == m_Size)
        return false;
    for (int k = m_Num; k > i; k--) {
        m_List[k] = m_List[k - 1];
    }
    m_List[i] = *ele;
    m_Num++;
    return true;
}
bool ArrayList::deleteEle(int i, int *ele)
{
    if (i < 0  || i >= m_Num)
    return false;
    *ele = m_List[i];
    for (int k = i; k < m_Num - 1; k++) {
        m_List[k] = m_List[k + 1];
    }
    m_Num--;
    return true;
}