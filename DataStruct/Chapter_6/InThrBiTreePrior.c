// 求线索链表中某个结点的前驱
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

// 寻找某一个结点的前驱结点
TNode * InThrBiTreePrior(BiTree T, TNode *p)
{
    TNode *prior = p;

    if (p->lchild == T)                         // 待寻找结点的前驱是头结点 -- 即没有前驱
        fprintf(stderr, "没有前驱结点！\n");
    if (p->ltag == Thread)                      // 待寻找结点的左标签是线索 -- 直接返回左孩子
        return p->lchild;
    else {                                      // 寻找待寻找结点左孩子的最右孩子结点
        prior = p->lchild;
        while (prior->rtag == Link)
            prior = prior->rchild;
        return prior;
    }
}