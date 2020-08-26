// 交换一颗二叉树中每个结点的左孩子和右孩子
#include <stdio.h>
#include <stdlib.h>

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

// 前序遍历输出二叉树
void PreTraverse(BiTree tree)
{
    if (tree == NULL) {
        printf("#");
        return;
    }
    printf("%c", tree->data);
    PreTraverse(tree->lchild);
    PreTraverse(tree->rchild);
}

// 交换二叉树每个结点的左右孩子
void Exchange(BiTree tree)
{
    if (tree == NULL)
        return;
    if (tree->lchild == NULL && tree->rchild == NULL)
        return;
    BiTree temp = tree->lchild;
    tree->lchild = tree->rchild;
    tree->rchild = temp;

    Exchange(tree->lchild);
    Exchange(tree->rchild);
}

// 测试交换左右孩子函数
int main(void)
{
    BiTree tree;

    puts("请按前序遍历序列输入二叉树内容：");
    PreCreat(&tree);

    puts("交换左右孩子前的二叉树如下：");
    PreTraverse(tree);

    // 交换二叉树左右孩子
    Exchange(tree);
    puts("\n交换左右孩子后的二叉树如下：");
    PreTraverse(tree);

    return 0;
}