// 中序遍历线索二叉树 -- 迭代
#include <stdio.h>

// 线索链表结构定义
typedef char ElemType;                         // 数据域元素类型
typedef enum {Link, Thread} PointerTag;        // 标签
typedef struct TNode {
    ElemType data;
    struct TNode *lchild;
    struct TNode *rchild;
    PointerTag ltag;
    PointerTag rtag;
} TNode, *BiTree;

// 中序遍历线索二叉树
void InOrderTraverse(BiTree T)
{
    TNode *p = T->lchild;
    while (p != T) {
        while (p->ltag == Link)
            p = p->lchild;
        printf("%c", p->data);
        while ((p->rtag == Thread) && (p->rchild != T)) {
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
}