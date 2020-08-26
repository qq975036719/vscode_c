// 判断一棵二叉树是否为完全二叉树
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 二叉树结构定义
typedef char ElemType;
typedef struct TNode {
    ElemType data;
    struct TNode *lchild;
    struct TNode *rchild;
} TNode, *BiTree;

/* 函数定义 */

// 前序创建二叉树
void PreCreat(BiTree *tree)
{
    ElemType ch;
    scanf("%c", &ch);

    if (ch == '#')
        *tree = NULL;
    else {
        *tree = (TNode *)malloc(sizeof(TNode));
        (*tree)->data = ch;
        (*tree)->lchild = NULL;
        (*tree)->rchild = NULL;
        PreCreat(&(*tree)->lchild);
        PreCreat(&(*tree)->rchild);
    }
}

// 判断是否为完全二叉树
bool flag = true;
#define QUEUE_SIZE 105
bool isPerfect(BiTree tree)
{
    TNode *nodeQueue[QUEUE_SIZE];
    memset(nodeQueue, 0, sizeof(nodeQueue));

    if (tree == NULL)
        return false;
    int front = 0;                                  // 指向队首
    int rear = 0;                                   // 指向队尾

    nodeQueue[rear++] = tree;                       // 根结点入队
    TNode *pre = tree;
    TNode *cur;

    while (front != rear) {                         // 当队列不为空时循环
        cur = nodeQueue[front++];
        if (cur->lchild == NULL && cur->rchild){     // 不符合完全二叉树定义时返回false
            return false;
            flag = false;
        }
        else {                                      // 当前结点左右孩子入队
            nodeQueue[rear++] = cur->lchild;
            nodeQueue[rear++] = cur->rchild;
        }
        pre = cur;                                  // 更新pre的位置
    }
    
    return true;
}

// 测试判断是否是完全二叉树函数
int main(void)
{
    BiTree tree;

    puts("请按前序遍历序列输入二叉树内容：");
    PreCreat(&tree);

    isPerfect(tree);
    if (flag)
        puts("是完全二叉树");
    else
        puts("不是完全二叉树");

    return 0;
}