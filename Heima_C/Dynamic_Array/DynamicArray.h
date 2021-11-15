#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct DynamicArray
{
    void ** m_pAddr;
    int m_size;
    int m_capacity;
};

struct Person
{
    char name[10];
    int age;
};
// init
struct DynamicArray* init_DynamicArray(int capacity);

// insert ele
void insert(struct DynamicArray* array, int pos, void *data);

void traverse(struct DynamicArray* array);

void for_each(struct DynamicArray* array, void(*myFun)(void*));

void MyPr(void *data);

void removeByPos(struct DynamicArray *array, int pos);

int cmp(void *a, void *b);

void removeByVal(struct DynamicArray *array, void *data, int(*cmp)(void *, void *));

void destroy(struct DynamicArray* array);