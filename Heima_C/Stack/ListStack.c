#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

typedef struct StackNode {
    StackNode *next;
}StackNode;

typedef struct Stack {
    StackNode phead;
}Stack;

typedef void* ListStack;

ListStack initListStack()
{
    ListStack myStack = malloc(sizeof(Stack));
    if (myStack == NULL) {
        return NULL;
    }
    Stack* stack = (Stack*)myStack;
    stack->phead.next = NULL;
    return myStack;
}

void push(ListStack listStack, void* data)
{
    if (listStack == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }
    Stack *stack = (Stack*)listStack;
    StackNode* nodeHead = (StackNode*)data;
    nodeHead->next = stack->phead.next;
    stack->phead.next = nodeHead;
}

int empty(ListStack listStack)
{
    if (listStack == NULL) {
        return -1;
    }
    Stack *stack = (Stack*)listStack;
    if (stack->phead.next == NULL) {
        return 1;
    }
    return 0;
}

void pop(ListStack listStack)
{
    if (listStack == NULL) {
        return;
    }
    if (empty(listStack)) {
        return;
    }
    Stack *stack = (Stack*)listStack;
    stack->phead.next = stack->phead.next->next;
}

void* top(ListStack listStack)
{
    if (empty(listStack)) {
        return NULL;
    }
    Stack *stack = (Stack*)listStack;
    return stack->phead.next;
}

void destroy(ListStack listStack) {
    free(listStack);
    listStack = NULL;
}

typedef struct Person
{
    void *next;
    char name[64];
    int age;
}Person;



int main()
{
    ListStack stack = initListStack();
    Person p1 = {NULL, "lw", 18};
    Person p2 = {NULL, "zhangsan", 23};
    Person p3 = {NULL, "lisi", 16};
    Person p4 = {NULL, "wangsu", 88};

    push(stack, &p1);
    push(stack, &p2);
    push(stack, &p3);
    push(stack, &p4);

    while (!empty(stack)) {
        Person* p = (Person*)top(stack);
        printf("name: %s; age: %d\n", p->name, p->age);
        pop(stack);
    }

    destroy(stack);
    getchar();
    return 0;
}