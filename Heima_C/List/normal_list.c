#include<stdio.h>
#include<stdlib.h>
typedef struct LinkNode {
    void * data;
    struct LinkNode *next;
} LinkNode;

struct List
{
    LinkNode *head;
    int m_size;
};

struct Person
{
    char name[10];
    int age;
};

typedef void * LinkList; // 隐藏list的内部变量实现

// 初始化链表
LinkList init_List() {
    struct List* res = (struct List*)malloc(sizeof(struct List));
    res->head = (LinkNode*)malloc(sizeof(LinkNode));
    res->m_size = 0;
    res->head->data = NULL;
    res->head->next = NULL;
    return res;
}

// 插入链表
void insert(LinkList linklist, int pos, void *data) {
    if (linklist == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }
    // -1 1 2 3
    //    0 1 2
    struct List* list = (struct List*)linklist;
    if (pos < 0 || pos > list->m_size) {
        pos = list->m_size;
    }

    LinkNode *node = list->head;
    for (int i = 0; i < pos; i++) {
        node = node->next;
    }

    LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->next = node->next;
    node->next = newNode;
    list->m_size++;

}

// 遍历链表
void traverse(LinkList linklist, void(*myForeach)(void *)) {

}

void trave(LinkList linklist) {
    struct List *list = (struct List *)linklist;
    LinkNode *node = list->head->next;
    while (node) 
    {
        printf("%d ", *(int*)node->data);
        node = node->next;
    }
    printf("\n");
    
}

// 删除链表  按照位置
void removeByPos_LinkList(LinkList linklist, int pos) {
    if (linklist == NULL) {
        return;
    }
    struct List *list = (struct List*) linklist;
    if (pos < 0 || pos > list->m_size) {
        return;
    }
    LinkNode *node = list->head;
    for (int i = 0; i < pos; i++) {
        node = node->next;
    }
    LinkNode *temp = node->next;
    node->next = node->next->next;
    free(temp);
    list->m_size--;
}


// 删除链表  按照值
void removeByValue_LinkList(LinkList linklist , void * data) {
    if (linklist == NULL) {
        return;
    }
    struct List *list = (struct List*) linklist;
    LinkNode *node = list->head;
    while (node->next)
    {
        printf("size: %d\n", list->m_size);
        printf("data: %d\n", *(int*)data);
        printf("node->next->data: %d\n", *(int*)node->next->data);
        if (*(int*)(node->next->data) == *(int*)data) {
            LinkNode *tmp = node->next;
            node->next = node->next->next;
            free(tmp);
            continue;
        }
        node = node->next;
    }
    
}

// 清空链表
void clear_LinkList(LinkList linklist) {
    if (linklist == NULL) {
        return;
    }
    struct List *list = (struct List*) linklist;
    LinkNode *node = list->head->next;
    while (node) {
        LinkNode *temp = node;
        node = node->next;
        free(node);
    }
}

// 返回链表长度
int  size_LinkList(LinkList linklist) {
    struct List *list = (struct List*) linklist;
    return list->m_size;
}


// 销毁链表
void destroy_Linklist(LinkList linklist) {
    if (linklist == NULL) {
        return;
    }
    struct List *list = (struct List*) linklist;
    LinkNode *node = list->head;
    while (node) {
        LinkNode *temp = node;
        node = node->next;
        free(node);
    }
}

int main()
{
    int a = 1;
    int b = 1;
    int c = 3;
    int d = 1;
    LinkList list = init_List();
    // 1 4 2 3
    insert(list, -1, &a);
    insert(list, -1, &b);
    insert(list, -1, &c);
    insert(list, 1, &d);
    trave(list);
    //removeByPos_LinkList(list, 1);
    //removeByPos_LinkList(list, 0);
    removeByValue_LinkList(list, (void*)&a);
    trave(list);
    getchar();
    return 0;
}