#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define MAX_SIZE 1024
typedef struct Stack
{
    void* m_Arr[MAX_SIZE];
    int m_top;
    int m_size;
}Stack;

typedef void* SeqStack;

SeqStack initStack()
{
    SeqStack seq = malloc(sizeof(Stack));
    if (seq == NULL) {
        return NULL;
    }
    Stack * s = (Stack*) seq;
    memset(s->m_Arr, 0, sizeof(void*) * MAX_SIZE);
    s->m_size = 0;
    s->m_top = 0;
    return seq;
}

void push(SeqStack seq, void *data)
{
    if (seq == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }
    Stack * s = (Stack*) seq;
    if (s->m_top == MAX_SIZE) {
        return;
    }
    s->m_Arr[s->m_top] = data;
    s->m_top++;
}

int empty(SeqStack seq)
{
    Stack * s = (Stack*) seq;
    if (s->m_top == 0) {
        return 1;
    }
    return 0;
}

void pop(SeqStack seq)
{
    if (seq == NULL) {
        return;
    }
    Stack * s = (Stack*) seq;
    if (empty(seq)) {
        return;
    }
    
    s->m_Arr[s->m_top-1] = NULL;
    s->m_top--;
}

void* top(SeqStack seq)
{
    Stack * s = (Stack*) seq;
    if (empty(seq)) {
        return NULL;
    }
    return s->m_Arr[s->m_top-1];
}



int size(SeqStack seq)
{
    if (seq == NULL) {
        return -1;
    }
    Stack * s = (Stack*) seq;
    return s->m_top;
}




void destroy(SeqStack seq)
{
    if (seq == NULL) {
        return;
    }
    Stack * s = (Stack*) seq;
    free(s);
    s = NULL;
}

typedef struct Person{
    char name[64];
    int age;
}Person;


int main()
{
    Person p1 = {"lw", 18};
    Person p2 = {"zhansan", 22};

    SeqStack seq = initStack();
    push(seq, &p1);
    push(seq, &p2);
    
    printf("stack size: %d\n", size(seq));

    while (!empty(seq)) {
        Person* p = (Person*)top(seq);
        printf("name: %s; age: %d\n",p->name, p->age);
        pop(seq);
    }

    printf("stack size: %d\n", size(seq));

    destroy(seq);
    getchar();
    return 0;
}