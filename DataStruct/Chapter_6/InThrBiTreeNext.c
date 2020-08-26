// 求线索链表中某个结点的后继
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

// 寻找某一个结点的后继结点
TNode * InThrBiTreeNext(BiTree T, TNode *p)
{
    TNode *next = p;

    if (p->rchild == T)                         // 待寻找结点的前驱是头结点 -- 即没有后继
        fprintf(stderr, "没有后继结点！\n");
    if (p->rtag == Thread)                      // 待寻找结点的左标签是线索 -- 直接返回右孩子
        return p->rchild;
    else {                                      // 寻找待寻找结点右孩子的最左孩子结点
        next = p->rchild;
        while (next->ltag == Link)
            next = next->lchild;
        return next;
    }
}