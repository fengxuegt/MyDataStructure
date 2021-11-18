// 单向链表的企业版本
// 规定前几个字节由链表来使用
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct LinkNode {
    struct LinkNode *next;
}LinkNode;

typedef struct List {
    LinkNode pHead;
    int m_size;
}List;

typedef void* LinkList;

LinkList init_Link_List() {
    List * res = (List*)malloc(sizeof(List));
    if (res == NULL) {
        return NULL;
    }
    res->pHead.next = NULL;
    res->m_size = 0;
    return res;
}

void insert_List(LinkList list, int pos, void *data) {
    if (list == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }
    List * res = (List*)list;
    if (pos < 0 || pos > res->m_size) {
        pos = res->m_size;
    }

    LinkNode *node = (LinkNode *)data; // 取前四个字节
    LinkNode *head = &res->pHead;
    for (int i = 0; i < pos; i++) {
        head = head->next;
    }

    node->next = head->next;
    head->next = node;
    res->m_size++;
}

void removeByPos(LinkList list, int pos) {
    if (list == NULL) {
        return;
    }
    
    List *res = (List *)list;
    if (pos < 0 || pos >= res->m_size) {
        return;
    }
    LinkNode *node = &res->pHead;
    for (int i = 0; i < pos; i++) {
        node = node->next;
    }
    LinkNode *temp = node->next;
    node->next = node->next->next;
    // free(temp); // 没有权限去free，因为数据是用户管理的
    res->m_size--;
}



void removeByVal(LinkList list, void *data, int (*myCompare)(void*a, void*b)) {
    if (list == NULL) {
        return;
    }

    if (data == NULL) {
        return;
    }

    List* res = (List*) list;
    LinkNode * head = &res->pHead;
    while (head && head->next) {
        if (myCompare(head->next, data) == 0) {
            head->next = head->next->next;
        }
        head = head->next;
    }
    res->m_size--;
}

void clear(LinkList list) {
    if (list == NULL) {
        return;
    }
    List* res = (List*) list;
    LinkNode *head = &res->pHead;
    res->m_size = 0;
    res->pHead.next = NULL;
}

void destroy(LinkList list) {
    if (list == NULL) {
        return;
    }

    free(list);
    list = NULL;
}


void for_each(LinkList list, void (*myForeach)(void*)) {
    if (list == NULL) {
        return;
    }
    List * res = (List*)list;
    LinkNode *node = res->pHead.next;
    for (int i = 0; i < res->m_size; i++) {
        myForeach(node);
        node = node->next;
    }
}

// 
struct Person
{
    LinkNode *node; // 四个字节
    char name[64];
    int age;
};

void foreach(void* data) {
    struct Person *p = (struct Person *)data;
    printf("name: %s; age: %d\n", p->name, p->age);

}

int myCompare(void *a, void *b) {
    struct Person *pa = (struct Person*)a;
    struct Person *pb = (struct Person*)b;
    if (strcmp(pa->name, pb->name) == 0 && pa->age == pb->age) {
        return 0;
    }
    return -1;
}

void test01() {
    LinkList list = init_Link_List();
    struct Person p1 = {NULL, "aaa", 10};
    struct Person p2 = {NULL, "bbb", 20};
    struct Person p3 = {NULL, "ccc", 30};
    struct Person p4 = {NULL, "ddd", 40};
    struct Person p5 = {NULL, "eee", 50};

    insert_List(list, 0, &p1);
    insert_List(list, 0, &p2);
    insert_List(list, 1, &p3);
    insert_List(list, -1, &p4);
    insert_List(list, 0, &p5);
    for_each(list, foreach);

    printf("-----------------\n");
    removeByPos(list, 4);
    for_each(list, foreach);

    printf("-----------------\n");
    removeByVal(list, &p1, myCompare);
    removeByVal(list, &p2, myCompare);
    for_each(list, foreach);
    getchar();
}

int main()
{
    test01();
    return 0;
}