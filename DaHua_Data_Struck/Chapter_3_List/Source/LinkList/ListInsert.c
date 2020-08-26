// 实现单链表元素的插入
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

Status ListInsert(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p, s;

    p = *L;     // 初始化一个指针指向表头结点
    j = 1;

    while (p && j < i) {        // 寻找第i-1个结点
        p = p->next;
        j++;
    }

    if (p == NULL || j > i)
        return ERROR;

    s = (LinkList)malloc(sizeof(Node));     // 让s成为一个Node结点
    s->data = e;            // 插入元素 -- s是第i个元素
    s->next = p->next;      // 让s的next指向第i+1个元素
    p->next = s;            // 再让p(第i-1个元素)的next指向s(第i个元素)

    return OK;
}