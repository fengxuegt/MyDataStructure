#include"DynamicArray.h"

// init
struct DynamicArray* init_DynamicArray(int capacity) {
    if (capacity <= 0) {
        return NULL;
    }
    struct DynamicArray *array = (struct DynamicArray*) malloc(sizeof(struct DynamicArray));
    if (array == NULL) {
        return NULL;
    }
    
    array->m_pAddr = (void**)malloc(sizeof(void*) * capacity);
    array->m_size = 0;
    array->m_capacity = capacity;

    return array;
}

// insert ele
void insert(struct DynamicArray* array, int pos, void *data) {
    if (array == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }

    if (pos < 0 || pos > array->m_size) {
        pos = array->m_size;
    }

    if (pos == array->m_size) {
        // tail insert
            if (array->m_size < array->m_capacity) {
                array->m_pAddr[pos] = data;
                array->m_size++;
            } else {
                // malloc new memory
                void ** tmp = (void **)malloc(sizeof(void*) * array->m_capacity * 2);
                for (int i = 0; i < array->m_size; i++) {
                    tmp[i] = array->m_pAddr[i];
                }
                // copy
                // memcpy(tmp, array->m_pAddr, sizeof(void*)*array->m_capacity);

                free(array->m_pAddr);
                array->m_pAddr = tmp;
                array->m_pAddr[pos] = data;
                array->m_size++;
                array->m_capacity *= 2;
            }
    } else {
        if (array->m_size < array->m_capacity) {
            for (int i = array->m_size; i > pos; i--) {
                array->m_pAddr[i] = array->m_pAddr[i-1];
            }
            array->m_pAddr[pos] = data;
            array->m_size++;
        } else {
            void ** tmp = (void **)malloc(sizeof(void*) * array->m_capacity * 2);
            for (int i = 0; i < pos; i++) {
                tmp[i] = array->m_pAddr[i];
            }
            tmp[pos] = data;
            for (int i = pos; i < array->m_size; i++) {
                tmp[i + 1] = array->m_pAddr[i];
            }

            free(array->m_pAddr);
            array->m_pAddr = tmp;
            array->m_size++;
            array->m_capacity *= 2;
        }
    }


}

void traverse(struct DynamicArray* array) {
    for (int i = 0; i < array->m_size; i++) {
        printf("%d ", *(int*)array->m_pAddr[i]);
    }
    printf("\n");
}

void for_each(struct DynamicArray* array, void(*myFun)(void*))
{
    for (int i = 0; i < array->m_size; i++) {
        myFun(array->m_pAddr[i]);
    }
}

void MyPr(void *data) {
    struct Person *p = (struct Person*)data;
    printf("name: %s, age: %d\n", p->name, p->age);
}


void removeByPos(struct DynamicArray *array, int pos) {
    if (pos < 0 || pos >= array->m_size) {
        return;
    }
    for (int i = pos; i < array->m_size - 1; i++) {
        array->m_pAddr[i] = array->m_pAddr[i+1];
    }
    array->m_size--;
}

int cmp(void *a, void *b) {
    struct Person *pa = (struct Person*)a;
    struct Person *pb = (struct Person*)b;
    if (pa->age == pb->age && strcmp(pa->name, pb->name) == 0) {
        return 0;
    }
    return -1;
}

void removeByVal(struct DynamicArray *array, void *data, int(*cmp)(void *, void *)) {
    if (array == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }
    for (int i = 0; i < array->m_size; i++) {
        if (cmp(data, array->m_pAddr[i]) == 0) {
            removeByPos(array, i);
            break;
        }
    }
}

void destroy(struct DynamicArray* array) {
    if (array == NULL) {
        return;
    }
    if (array->m_pAddr != NULL) {
        free(array->m_pAddr);
    }

    free(array);
}