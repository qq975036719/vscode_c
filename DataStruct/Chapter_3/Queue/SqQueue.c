// 循环队列基本操作
#include <stdio.h>
#include <stdlib.h>

/* 定义循环队列结构 */
#define QUEUE_MAX_SIZE 100      // 循环队列空间大小
typedef int ElemType;           // 元素类型

typedef struct {                // 循环队列结构体
    ElemType     *data;
    int          front;
    int          rear;
} SqQueue;

/* 功能函数 */

// 初始化一个空循环队列
void InitQueue_Sq(SqQueue *Q)
{
    // 分配空间
    Q->data = (ElemType *)malloc(sizeof(ElemType) * QUEUE_MAX_SIZE);
    if (Q->data == NULL) {
        fprintf(stderr, "Overflow!\n");
        exit(EXIT_FAILURE);
    }
    Q->front = 0;
    Q->rear  = 0;
}

// 销毁循环列表
void DestroyQueue_Sq(SqQueue *Q)
{
    free(Q->data);
    Q->front = 0;
    Q->rear  = 0;
}

// 求队列长度
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
}

// 获取队头元素
void GetHead_Sq(SqQueue Q, ElemType *e)
{
    if (Q.rear == Q.front) {
        fprintf(stderr, "Queue Empty!\n");
        exit(EXIT_FAILURE);
    }
    *e = Q.data[Q.front];
}

// 入队操作
void EnQueue_Sq(SqQueue *Q, ElemType e)
{
    if ((Q->rear + 1) % QUEUE_MAX_SIZE  == Q->front) {
        fprintf(stderr, "Queue Full!\n");
        exit(EXIT_FAILURE);
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % QUEUE_MAX_SIZE;
}

// 出队操作
void DeQueue_Sq(SqQueue *Q, ElemType *e)
{
    if (Q->front == Q->rear) {
        fprintf(stderr, "Queue Empty!\n");
        exit(EXIT_FAILURE);
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % QUEUE_MAX_SIZE;
}

// 测试循环队列的基本操作
int main(void)
{
    SqQueue Queue;
    ElemType e;
    int length;

    // 初始化
    InitQueue_Sq(&Queue);
    printf("请输入队列长度：");
    scanf("%d", &length);

    // 入队操作
    for (int i = 0; i < length; i++) {
        printf("输入第%d个元素：", i + 1);
        scanf("%d", &e);
        EnQueue_Sq(&Queue, e);
    }

    // 打印队列信息
    printf("队列长度：%d\n", QueueLength(Queue));
    printf("队列元素如下：\n");
    for (int i = 0; i < length; i++) {
        printf("%-5d", Queue.data[i]);
        if (!(i + 1))
            putchar('\n');
    }
    putchar('\n');

    // 出队操作
    GetHead_Sq(Queue, &e);
    printf("当前队头元素：%d\n", e);
    printf("现在进行出队操作！\n");
    DeQueue_Sq(&Queue, &e);
    printf("出队元素：%d\n", e);

    // 销毁队列
    puts("现在销毁队列！");
    DestroyQueue_Sq(&Queue);

    puts("Done!");

    return 0;
}