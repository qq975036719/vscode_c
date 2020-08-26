// 计算一棵二叉树中的野子结点数
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

// 计算二叉树的叶子结点数
int CalcLeaf(BiTree tree)
{
    static int leaf = 0;      // 声明为静态存储期 -- 保证出函数后不会被再次修改
    if (tree == NULL)
        return 0;
    if (tree->lchild == NULL && tree->rchild == NULL)
        leaf++;
    CalcLeaf(tree->lchild);
    CalcLeaf(tree->rchild);

    return leaf;
}

// 测试统计叶子结点数的函数
int main(void)
{
    BiTree tree;

    puts("请按前序遍历序列输入二叉树内容：");
    PreCreat(&tree);

    printf("\n二叉树中的叶子节点数：%d", CalcLeaf(tree));

    return 0;
}

