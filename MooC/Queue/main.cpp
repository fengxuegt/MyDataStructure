#include<iostream>
#include"MyQueue.h"
using namespace std;
int main()
{
    MyQueue<int> *my_queue = new MyQueue<int>(4);
    my_queue->EnQueue(10);
    my_queue->EnQueue(12);
    my_queue->EnQueue(16);
    my_queue->EnQueue(18);
    my_queue->EnQueue(20);
    my_queue->traverse();
    cout << "--------" << endl;
    int e = 0;
    my_queue->DeQueue(e);
    cout << e << endl;
    my_queue->DeQueue(e);
    cout << e << endl;

    cout << "--------" << endl;
    my_queue->traverse();

    my_queue->clearQueue();
    my_queue->traverse();
    cout << "----------" << endl;
    my_queue->EnQueue(20);
    my_queue->EnQueue(30);
    my_queue->traverse();

    getchar();
    delete my_queue;
    my_queue = NULL;
    return 0;
}