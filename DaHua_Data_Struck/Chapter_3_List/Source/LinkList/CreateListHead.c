// 头插法创建单链表
#include <time.h>
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

void CreateListHead(LinkList *L, int n)
{
    int i;
    LinkList p;
    srand(time(0));     // 设置随机种子

    *L = (LinkList)malloc(sizeof(Node));        // 初始化一个空链表
    (*L)->next = NULL;      // 建立一个带头结点的单链表

    for (i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));     // 生成一个新结点
        p->data = rand() % 100 + 1;             // 让新结点的数据域为100以内的随机数
        p->next = (*L)->next;                   // 让p的下一个结点为*L的下一个结点
        (*L)->next = p;                         // 头插法 -- 每次生成的新结点永远是第一个结点
    }
}