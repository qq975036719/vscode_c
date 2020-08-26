// 患者在医院排队就诊模拟程序

// 链队列基本操作
#include <stdio.h>
#include <stdlib.h>

/* 定义链队列结构 */
typedef int ElemType;           // 元素类型

// 链队列结点结构
typedef struct QNode {
    ElemType        data;       // 数据域
    struct QNode    *next;      // 指针域
} QNode, *QueuePtr;             // QueuePtr -- 指向队列的指针

// 链队列结构
typedef struct {
    QueuePtr front;             // 链队列头指针 -- 指向链队列头结点
    QueuePtr rear;              // 链队列尾指针 -- 指向链队列尾结点
} LinkQueue;

/* 功能函数 */

// 初始化一个空链队列
void InitQueue_L(LinkQueue *Q)
{
    // 创建一个头结点
    QNode *head = (QNode *)malloc(sizeof(QNode));
    // 头尾指针指向该头结点
    Q->front = head;
    Q->rear  = head;
    Q->front->next = NULL;      // 头结点的下一个结点(队列第一个结点)为NULL
}

// 销毁队列 -- 执行完后整个队列不能再使用
void DestroyQueue_L(LinkQueue *Q)
{
    // 遍历每一个结点进行释放(包括头结点)
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}

// 清空队列 -- 执行完后整个队列还可以使用，只是数据被清空
void ClearQueue_L(LinkQueue *Q)
{
    QNode *p = Q->front->next;
    QNode *q;

    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    Q->front->next = NULL;
    Q->rear = Q->front;
}

// 求队列长度
int QueueLength_L(LinkQueue Q)
{
    int length = 0;

    while (Q.front->next) {
        length++;
        Q.front = Q.front->next;
    }

    return length;
}

// 入队操作
void EnQueue_L(LinkQueue *Q, ElemType e)
{
    QNode *new_qnode = (QNode *)malloc(sizeof(QNode));
    
    // 检查是否分配到新结点
    if (!new_qnode) {
        fprintf(stderr, "分配新结点失败！\n");
        exit(EXIT_FAILURE);
    }
    new_qnode->data = e;
    new_qnode->next = NULL;
    
    /* 修改队列尾指针的信息 -- 注意理解rear.next和rear赋值的区别 */

    // new_qnode成为队列的最后一个结点 -- 插入new_qnode后此时rear指向倒数第二个结点
    Q->rear->next = new_qnode;
    // rear指向new_qnode -- 即队列的最后一个结点
    Q->rear = new_qnode;
}

// 出队操作 -- 注意Q->front是头结点，Q->front->next才是队列的第一个结点
void DeQueue_L(LinkQueue *Q, ElemType *e)
{
    if (Q->front == Q->rear) {
        fprintf(stderr, "空队列无法出队！\n");
        exit(EXIT_FAILURE);
    }

    QNode *temp;
    *e = Q->front->next->data;      // 出队元素存储到e中返回调用函数
    temp = Q->front->next;          // 用于front指向下一个元素后释放出队元素
    Q->front->next = temp->next;    // front指向下一元素
    if (Q->rear == temp)
        Q->rear = Q->front;         // 队列只有一个元素时，出队后队列为空
    free(temp);                     // 释放出队元素
}

// 医院排队就诊模拟
void SeeDoctor(void)
{
    LinkQueue Queue;
    int flag = 1;       // 1 -- 接收患者; 0 -- 停止就诊
    char ch;            // 命令

    InitQueue_L(&Queue);
    
    while (flag) {
        ElemType e;

        printf("请输入命令：");
        scanf("%c", &ch);
        while (getchar() != '\n')
                    continue;
        switch(ch) {
            case 'a':
            case 'A':
                printf("请输入你的病历号：");
                scanf("%d", &e);
                while (getchar() != '\n')
                    continue;
                EnQueue_L(&Queue, e);       // 入队等候
                break;
            case 'n':
            case 'N':
                if (Queue.front != Queue.rear) {
                    DeQueue_L(&Queue, &e);
                    printf("病历号为：%d的患者就诊\n", e);
                }
                else
                    puts("队列中没患者！");
                break;
            case 's':
            case 'S':
                puts("不再接收患者！");
                puts("请下列排队的患者依次就诊：");
                while (Queue.front->next) {
                    DeQueue_L(&Queue, &e);
                    printf("%-4d", e);
                }
                putchar('\n');
                puts("不再接收患者！");
                flag = 0;
                break;
            default:
                puts("指令非法！");
                break;
        }
    }
}

int main(void)
{
    SeeDoctor();

    return 0;
}