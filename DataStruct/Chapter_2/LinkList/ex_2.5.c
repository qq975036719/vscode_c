// 逆序创建单链表

// 单链表基本操作
#include <stdio.h>
#include <stdlib.h>

/* 单链表类型定义 */
typedef int ElemType;
typedef struct node {       // 结点
    ElemType data;          // 数据域
    struct node *next;      // 指针域
} Node;
typedef Node *LinkList;     // 单链表

// 单链表初始化
void InitList(LinkList *L)
{
    Node *head = (Node *)malloc(sizeof(Node));      // 头结点
    head->next = NULL;                              // 初始化头结点指向NULL
    (*L) = head;                                    // 指向头结点
}

// 添加一个元素到单链表的末尾 -- 尾插法
void CreateList_Tail(LinkList *L, int n)
{
    Node *p = (*L);

    for (int i = 0; i < n; i++) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL)
            printf("创建新结点失败！\n");
        else {
            printf("请输入第%d个数据：", i + 1);
            scanf("%d", &(new_node->data));
        }
        new_node->next = p->next;
        p->next = new_node;
    }
}

// 清空单链表
void DestroyList(LinkList *L)
{
    Node *p = (*L)->next;        // 存储第一个结点 -- (*L)是头结点
    Node *q = NULL;
    // 释放链表
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    (*L)->next = NULL;          // 头结点的下一个结点为NULL
}

// 求表长
int ListLength(LinkList L)
{
    int ct = 0;
    Node *p = L;                // 指向头结点

    while (p->next) {           // 当头结点后面的结点存在时
        ct++;
        p = p->next;
    }
    /* 没有头结点的版本
       Node *p = L;             // 指向第一个结点
       while (p) {
           ct++;
           p = p->next;
       }
    */
    return ct;
}

// 获取指定下标的数据域
void GetItem(LinkList L, int i, ElemType *e)
{
    Node *p = L->next;               // 指向第一个结点
    int j = 0;

    while ((j < i-1) && p != NULL) {
        p = p->next;
        j++;
    }
    if (p == NULL || (j > i-1)) {
        printf("Position Error!\n");
        exit(EXIT_FAILURE);
    }
    else 
        *e = p->data;
}

// 获取指定数据域的地址
Node *LocateElem(LinkList L, ElemType e)
{
    Node *p = L->next;          // 指向第一个结点

    while (p && (p->data != e))
        p = p->next;

    return p;
}

// 插入元素
void ListInsert(LinkList *L, int i, ElemType e)
{
    Node *p = (*L);             // 指向头结点
    int j = 0;

    while (p && (j < i - 1)) {    // 寻找第i-1个结点
        p = p->next;
        j++;
    }
    if (p == NULL || (j > i - 1)) {
        printf("Position Error!\n");
        exit(EXIT_FAILURE);
    }
    else {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = e;
        new_node->next = p->next;
        p->next = new_node;
    }
}

// 删除元素
void ListDelete(LinkList *L, int i, ElemType *e)
{
    Node *p = (*L);             // 指向头结点
    Node *q = NULL;
    int j = 0;

    while (p && (j < i - 1)) {    // 寻找第i-1个结点
        p = p->next;
        j++;
    }

    if (p == NULL || (j > i - 1)) {
        printf("Position Error!\n");
        exit(EXIT_FAILURE);
    }
    else {
        q = p->next;
        *e = q->data;
        p->next = q->next;
        free(q);
    }
}

// 输出单链表中的元素
void TraverseList(LinkList L)
{
    int i = 0;
    Node *p = L->next;      // 指向第一个结点

    while (p) {
        printf("%-10d", p->data);
        p = p->next;
        i++;
        if ((i+1) % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
}

// 逆序创建单链表 -- 头插法
void CreatList_Head(LinkList *L, int n)
{
    for (int i = 0; i < n; i--) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) {
            printf("创建新结点失败！\n");
            exit(EXIT_FAILURE);
        }
        else {
            printf("请输入第%d个数据：", i);
            scanf("%d", &(new_node->data));
            new_node->next = (*L)->next;
            (*L)->next = new_node;
        }
    }
}

// 测试头插法
int main(void)
{
    LinkList L;
    int n;
    InitList(&L);
    printf("请输入数据个数：");
    scanf("%d", &n);
    CreateList_Tail(&L, n);
    printf("单链表的数据如下：\n");
    TraverseList(L);

    return 0;
}