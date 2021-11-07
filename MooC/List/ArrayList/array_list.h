/* ************************************************************************
> File Name:     array_list.h
> Author:        fengxuegt
> blog:          fengxuegt.github.io
> Created Time:  2021年11月05日 星期五 23时19分01秒
> Description:   
 ************************************************************************/
#pragma once
class ArrayList {
public:
    ArrayList(int size);
    void ClearList();
    bool IsEmpty();
    int ListLength();
    bool GetElement(int i , int *res);
    ~ArrayList();
    int LocateEle(int *ele);
    bool preEle(int *cur, int *pre);
    bool nextEle(int *cur, int *next);
    bool insertEle(int i, int *ele);
    bool deleteEle(int i, int *ele);
    void traverse();
private:
    int *m_List;
    int m_Size;
    int m_Num;
};
