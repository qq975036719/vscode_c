// 用只有尾指针的循环链表实现队列
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 定义结点结构 */
typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node *next;
} Node;
typedef struct {
    Node *rear;     // 指向队尾元素
} Queue;

// 初始化队列
void InitQueue(Queue *Q)
{
    Node *head = (Node *)malloc(sizeof(Node));

    Q->rear = head;         // 尾指针指向头结点
    Q->rear->next = head;   // 尾结点的next指向头结点
}

// 置空队列
void ClearQueue(Queue *Q)
{
    Node *head = (*Q).rear->next;           // 指向头结点
    Node *pfirst = head->next;              // 指向队首元素

    while (pfirst != head) {
        Node *temp;
        temp = pfirst;
        pfirst = pfirst->next;
        free(temp);
    }
}

// 判断队列是否为空
bool isEmpty(Queue Q)
{
    if (Q.rear == Q.rear->next)     // 队列为空的条件
        return true;
    else
        return false;
}

// 入队操作
void EnQueue(Queue *Q, ElemType e)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    Node *head = (*Q).rear->next;

    new_node->data = e;
    new_node->next = head;             // 新结点的next指向头结点形成循环
    (*Q).rear->next = new_node;        // 新结点排到队尾元素后面
    (*Q).rear = new_node;              // 尾指针指向新结点
}

// 出队操作
void DeQueue(Queue *Q, ElemType *e)
{
    if (isEmpty(*Q)) {
        fprintf(stderr, "队列为空，无法出队！\n");
        exit(EXIT_FAILURE);
    }
    Node *head = (*Q).rear->next;       // 指向头结点
    Node *pfirst = head->next;          // 指向队首元素

    *e = pfirst->data;                  // 出队元素的值传给e
    head->next = pfirst->next;          // 头结点的下一个结点指向出队元素的下一个结点
    free(pfirst);
}

// 打印队列元素
void Traverse(Queue Q)
{
    puts("队列元素如下：");
    Node *scan = Q.rear->next->next;        // 从队首开始扫描
    while (scan != Q.rear->next) {          // 扫描到头结点才结束
        printf("%-4d", scan->data);
        scan = scan->next;
    }
    putchar('\n');
}

int main(void)
{
    Queue queue;
    ElemType e;

    InitQueue(&queue);

    // 判断队是否为空
    if (isEmpty(queue))
        puts("队列为空！");
    else
        puts("队列非空！");

    // 入队
    for (int i = 0; i < 5; i++) {
        printf("请输入第%d个元素：", i + 1);
        scanf("%d", &e);
        EnQueue(&queue, e);
    }

    // 打印队列元素
    Traverse(queue);

    // 出队
    puts("现在出队！");
    DeQueue(&queue, &e);
    printf("出队元素：%d\n", e);
    puts("出队后的队列如下：");
    Traverse(queue);

    // 置空队列
    puts("现在置空队列！");
    ClearQueue(&queue);

    puts("Done!");

    return 0;
}