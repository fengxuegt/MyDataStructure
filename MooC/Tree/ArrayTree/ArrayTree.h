#pragma once
class ArrayTree {
    public:
        ArrayTree(int size); // 创建树
        ~ArrayTree();        // 销毁树
        int *searchNode(int index); 
        bool addNode(int index, int direction, int *node);
        bool deleteNode(int index, int *node);
        void traverse();

    private:
        int *m_Array;
        int m_Size;
};