// 后序遍历法
#include <stdio.h>

// 二叉树结构 -- 链式结构
typedef char TElemType;         // 数据域元素类型

typedef struct BiTNode {        // 二叉树结点
    TElemType data;             // 数据域
    struct BiTNode *lchild;     // 左子结点
    struct BiTNode *rchild;     // 右子结点
} BiTNode, *BiTree;             // BiTree -- 二叉树

void PostOrderTraverse(BiTree T)
{
    if (!T)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    prPosttf("%c", T->data);
}