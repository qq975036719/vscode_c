// 测试单链表的插入
#include <stdio.h>

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

Status ListInsert(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p = *L;        // p指向第一个结点
    LinkList s;

    j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }

    if (p==NULL || j > i)
        return ERROR;

    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}

int main(void)
{
    LinkList L, *p;
    int num, index;
    ElemType res = 0;
    ElemType value;

    printf("请输入创建的个数: ");
    scanf("%d", &num);

    CreatListTail(&L, num);

    GetElem(L, 3, &res);
    printf("第3个元素为: %d\n", res);

    printf("请输入待插入位置和待插入元素: ");
    scanf("%d %d", &index, &value);

    ListInsert(&L, index, value);
    printf("插入元素后的单链表为:\n");

    p = &L;
    for (int i = 0; i < num + 1; i++) {
        *p = (*p)->next;
        printf("%d ", (*p)->data);
        if ((i + 1) % 10 == 0)
            putchar('\n');
    }
    
    return 0;
}