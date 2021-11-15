
#include"DynamicArray.h"
int main()
{

    struct DynamicArray *array = init_DynamicArray(3);
    int a = 12;
    int b = 13;
    int c = 14;
    int d = 15;

    struct Person p1= {"liwang", 18};
    struct Person p2= {"jiyingxin", 18};
    struct Person p3= {"zhagnsan", 18};
    struct Person p4= {"lisi", 18};
    struct Person p5= {"likui", 18};


    // 15 13 14 12
    // lisi jiyingxin zhangsan liwang
    insert(array, 0, (void*)&p1);
    insert(array, 0, (void*)&p2);
    insert(array, 1, (void*)&p3);
    insert(array, 0, (void*)&p4);

    removeByPos(array,2);
    removeByVal(array,&p4, cmp);
    //traverse(array);
    for_each(array, MyPr);
    printf("capacity: %d, size: %d \n", array->m_capacity, array->m_size);
    destroy(array);
    array = NULL;
    getchar();
    return 0;
}