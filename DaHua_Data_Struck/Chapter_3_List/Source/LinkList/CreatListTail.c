// 尾插法创建单链表
#include <stdlib.h>

// 单链表结构
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;
typedef Node *LinkList;

// 返回状态
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

void CreatListTail(LinkList *L, int n)
{
    LinkList p, r;

    *L = (LinkList)malloc(sizeof(Node));        // 创建一个空链表
    r = *L;                                     // 指向尾部的结点

    for (int i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));     // 创建新结点
        scanf("%d", &(p->data));
        r->next = p;                            // 原本的尾部结点r指向p
        r = p;                                  // 再让p成为新的尾部结点
    }
    r->next = NULL;
}