// 建立二叉树 -- 前序建立
#include <stdio.h>
#include <stdlib.h>

// 二叉树结构 -- 链式结构
typedef char TElemType;         // 数据域元素类型

typedef struct BiTNode {        // 二叉树结点
    TElemType data;             // 数据域
    struct BiTNode *lchild;     // 左子结点
    struct BiTNode *rchild;     // 右子结点
} BiTNode, *BiTree;             // BiTree -- 二叉树

void CreatBiTree(BiTree *T)
{
    TElemType ch;

    scanf("%c", &ch);

    if (ch == '#')
        (*T) = NULL;
    else {
        (*T) = (BiTNode *)malloc(sizeof(BiTNode));
        if (!*T) {
            fprintf(stderr, "Overflow!\n");
            exit(EXIT_FAILURE);
        }
        CreatBiTree(&(*T)->lchild);
        CreatBiTree(&(*T)->rchild);
    }
}