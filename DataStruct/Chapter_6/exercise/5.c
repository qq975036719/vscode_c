// 输出指定结点的所有祖先
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// 寻找所有祖先
bool FindAncestors(BiTree tree, TNode *e)
{
    if (tree == NULL)               // 终止条件
        return false;
    if (tree->data == e->data)      // 终止条件
        return true;
    if (FindAncestors(tree->lchild, e) || FindAncestors(tree->rchild, e)) {
        printf("%c", tree->data);
        return true;
    }
    return false;
}

int main(void)
{
    BiTree tree;
    ElemType ch;

    puts("请按前序遍历序列输入二叉树内容：");
    PreCreat(&tree);
    fflush(stdin);
    // 也可以用这个刷新缓冲区
    // while (getchar() != '\n')
    //     continue;

    printf("请输入待查找结点：");
    scanf("%c", &ch);

    TNode *tar = (TNode *)malloc(sizeof(TNode));
    tar->data = ch;
    tar->lchild = NULL;
    tar->rchild = NULL;

    if (FindAncestors(tree, tar))
        puts("\n输出完毕！");
    else
        puts("该结点不在树中！");
    
    return 0;
}