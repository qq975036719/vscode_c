// 测试头插法创建单链表
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 单链表的结构
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
    // (*L)->next = NULL;                          // 建立一个带头结点的单链表

    for (i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));     // 生成一个新结点
        // p->data = rand() % 100 + 1;             // 让新结点的数据域为100以内的随机数
        scanf("%d", &(p->data));             // 以键盘读入的方式作为链表数据域
        p->next = (*L)->next;                   // 让p的下一个结点为*L的下一个结点
        (*L)->next = p;                         // 头插法 -- 每次生成的新结点永远是第一个结点
    }
}

int main(void)
{
    int num;
    LinkList link_list;
    LinkList *p = &link_list;

    printf("请输入要创建单链表的个数: ");
    scanf("%d", &num);

    // 头插法创建随机单链表
    CreateListHead(&link_list, num);

    // 打印创建好的单链表
    for (int i = 0; i < num; i++) {
        *p = (*p)->next;
        printf("%d ", (*p)->data);
        if ((i+1) % 10 == 0)
            putchar('\n');
    }

    return 0;
}