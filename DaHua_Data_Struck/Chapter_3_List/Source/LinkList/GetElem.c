// 获取单链表的第i个元素
#include <stdio.h>

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

Status GetElem(LinkList L, int i, ElemType *e)
{
    Node *pn = L->next;
    int j;

    for (j = 1; j < i; j++) {
        if (pn->next == NULL)     // 遍历过程中就到了链表末尾 -- 说明第i个不存在
            return ERROR;
        pn = pn->next;
    }
    *e = pn->data;

    return OK;
}