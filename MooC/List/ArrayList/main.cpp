/* ************************************************************************
> File Name:     main.cpp
> Author:        fengxuegt
> blog:          fengxuegt.github.io
> Created Time:  2021年11月05日 星期五 23时28分46秒
> Description:   
 ************************************************************************/
#include<iostream>
#include"array_list.h"
using namespace std;
int main()
{
    ArrayList arrar_list(10);
    int *a = new int(1);
    int *b = new int(2);
    int *c = new int(3);
    int *d = new int(4);
    int *ele = new int();
    cout << "before insert length: " << arrar_list.ListLength()<< endl;
    arrar_list.insertEle(0, a);
    arrar_list.insertEle(0, b);
    arrar_list.insertEle(0, c);
    arrar_list.insertEle(2, d);

    cout << "after insert length: " << arrar_list.ListLength() << endl;
    arrar_list.traverse();
    arrar_list.deleteEle(2, ele);
    cout << "the deleted ele: " << *ele << endl;
    arrar_list.traverse();

    int *temp = new int();
    arrar_list.GetElement(1, temp);
    int location = arrar_list.LocateEle(temp);
    cout << "location is: " << location << endl;

    arrar_list.ClearList();
    cout << "Is empty? " << arrar_list.IsEmpty() << endl;
    arrar_list.traverse();
    cout << "hello" << endl;
    return 0;
}
