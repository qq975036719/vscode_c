// 实现单链表的删除
#include <stdlib.h>
// 单链表结构
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;

// 返回状态
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

Status ListDelete(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q;

    p = *L;         // 令p指向头结点
    j = 1;

    while (p->next && j < i) {      // 寻找第i-1个结点
        p = p->next;
        j++;
    }

    if (!(p->next) || j > i)
        return ERROR;           // 第i个结点不存在

    q = p->next;                // 让q指向第i个待删除的结点(p->next)
    p->next = q->next;          // 让p(第i-1个结点)指向第i+1(q->next -- p->next->next)个结点
    *e = q->data;               // 将被删除的值传递给e
    free(q);

    return OK;
}