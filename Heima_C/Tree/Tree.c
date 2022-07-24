// 左孩子右兄弟表示法可以将一棵多叉树变换为二叉树
// 方法为若是右左孩子，那么就仍然是左孩子，若是有右兄弟的话那么兄弟就变成右孩子
// 兄弟变儿子表示法

/*
二叉树的性质：
    在二叉树的第i层有最多2^i-1个节点
    深度为k的二叉树最多有2^k - 1个节点
    对于任何一棵二叉树，若度为2的节点个数为n，则叶子数为n + 1 个
    对于完全二叉树，若从上到下，从左到右进行编号，则编号为i的节点，其左孩子必为2i，右孩子为2i + 1

满二叉树
    一棵深度为k的满二叉树有2^k - 1个节点，就是说相当于规则的金字塔形状

完全二叉树
    除了最后一层以外，是一棵满二叉树，最后一层的话只缺少右边的若干节点

*/

#include<stdlib.h>
#include<stdio.h>
#include"seqStack.h"

typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void preOrder(TreeNode *root) {
    if (!root) {
        return;
    }
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void midOrder(TreeNode *root) {
    if (!root) {
        return;
    }
    midOrder(root->left);
    printf("%c ", root->data);
    midOrder(root->right);
}

void postOrder(TreeNode *root) {
    if (!root) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);
}

// 求树的叶子数量， 叶子的左右孩子都是NULL
void calLeaves(TreeNode *root, int *num) {
    if (!root) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        (*num)++;
    }
    calLeaves(root->left, num);
    calLeaves(root->right, num);
}



// 求树的深度或者树的高度，树的高度 = max（左子树高度，右子树高度） + 1
int getHeight(TreeNode *root)
{
    if (!root) {
        return 0;
    }
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    int res = l > r ? l : r;
    return res + 1;
}


// 拷贝二叉树
TreeNode *copyTree(TreeNode* root)
{
    if (!root) {
        return NULL;
    }
    TreeNode *l = copyTree(root->left); // 构建左孩子
    TreeNode* r = copyTree(root->right); // 构建右孩子
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = root->data;
    node->left = l;
    node->right = r;
    return node;
}


// 释放二叉树
void destroyTree(TreeNode *root) {
    if(!root) {
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    // printf("%c is freed\n", root->data);
    free(root);
}


// 二叉树非递归遍历， 借助栈
/* 算法流程
    将根节点压入栈中
    进入循环：
        只要栈中元素大于0，进行循环操作
            弹出栈顶元素
            如果这个元素标志为真，直接输出并执行下一次循环
            如果栈顶元素为假，则将次节点的标志设置为真
            将该节点的右子树、左子树、根节点压入到栈中
            执行下一次循环
*/


void preTraverse(TreeNode *root)
{
    if (root == NULL) {
        return;
    }
    SeqStack stack = init_SeqStack();
    push_SeqStack(stack, root);
    while (size_SeqStack(stack) > 0) {
        TreeNode *tmp = top_SeqStack(stack);
        printf("%c ", tmp->data);
        pop_SeqStack(stack);
        if (tmp->right) {
            push_SeqStack(stack, tmp->right);
        }
        if (tmp->left) {
            push_SeqStack(stack, tmp->left);
        }

    }
}

void midTraverse(TreeNode *root)
{
    if (root == NULL) {
        return;
    }
    SeqStack st = init_SeqStack();
    while (root || size_SeqStack(st) > 0) {
        if (root) {
            push_SeqStack(st, root);
            root = root->left;
        } else {
            TreeNode *top = top_SeqStack(st);
            printf("%c ", top->data);
            pop_SeqStack(st);
            root = top->right;
        }
    }
}

void postTraverse(TreeNode *root)
{

}

int main()
{
    TreeNode nodeA = {'A', NULL, NULL};
    TreeNode nodeB = {'B', NULL, NULL};
    TreeNode nodeC = {'C', NULL, NULL};
    TreeNode nodeD = {'D', NULL, NULL};
    TreeNode nodeE = {'E', NULL, NULL};
    TreeNode nodeF = {'F', NULL, NULL};
    TreeNode nodeG = {'G', NULL, NULL};
    TreeNode nodeH = {'H', NULL, NULL};
    // TreeNode nodeA = {'A', NULL, NULL};
    nodeA.left = &nodeB;
    nodeA.right = &nodeF;
    nodeB.right = &nodeC;
    nodeC.left = &nodeD;
    nodeC.right = &nodeE;
    nodeF.right = &nodeG;
    nodeG.left = &nodeH;
    TreeNode *mid = &nodeA;
    TreeNode *post = &nodeA;
    printf("===============preOrder=================\n");
    preOrder(&nodeA);
    printf("\n");
    printf("===============midOrder=================\n");
    midOrder(&nodeA);
    printf("\n");
    printf("===============postOrder=================\n");
    postOrder(post);
    printf("\n");

    // calLeaves
    int num = 0;
    printf("===============callLeaves================\n");
    calLeaves(&nodeA, &num);
    printf("Leaves: %d\n", num);
    printf("===============Height====================\n");
    printf("Height: %d\n", getHeight(&nodeA));

    TreeNode *newTree = copyTree(&nodeA);
    preOrder(newTree);
    printf("\n");
    // destroyTree(newTree);
    // getchar();

    printf("===============NoRecursion=================\n");
    printf("pre\n");
    preTraverse(newTree);
    printf("mid\n");
    midTraverse(newTree);
    destroyTree(newTree);
    return 0;
}


