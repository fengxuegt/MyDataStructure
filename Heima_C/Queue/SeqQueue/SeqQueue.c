#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include"DynamicArray.h"
#define MAX_SIZE 1024
typedef void* SeqQueue;

SeqQueue init_SeqQueue()
{
    struct DynamicArray *array = init_DynamicArray(MAX_SIZE);
    return array;
}

void push(SeqQueue queue, void *data)
{
    struct DynamicArray *array = (struct DynamicArray *)queue;
    insert(array, 0, data);
}

void* pop(SeqQueue queue)
{
    struct DynamicArray *array = (struct DynamicArray *)queue;
    void *tmp = array->m_pAddr[array->m_size - 1];
    removeByPos(array, array->m_size - 1);
    return tmp;
}

int size(SeqQueue queue) {
    struct DynamicArray *array = (struct DynamicArray *)queue;
    return array->m_size;
}

int empty(SeqQueue queue) {
    struct DynamicArray *array = (struct DynamicArray *)queue;
    return array->m_size == 0;
}

void destroy_queue(SeqQueue queue) {
    struct DynamicArray *array = (struct DynamicArray *)queue;
    destroy(array);
}



void test01()
{
    Person p1 = {"lw", 19};
    Person p2 = {"zhangan", 22};
    Person p3 = {"wangsu", 33};
    SeqQueue seqq = init_SeqQueue();
    push(seqq, &p1);
    push(seqq, &p2);
    push(seqq, &p3);

    while (!empty(seqq)) {
        Person *tmp = (Person*) pop(seqq);
        printf("name: %s; age: %d\n", tmp->name, tmp->age);
    }
    return;
}

int main()
{
    test01();

    getchar();
    return 0;
}