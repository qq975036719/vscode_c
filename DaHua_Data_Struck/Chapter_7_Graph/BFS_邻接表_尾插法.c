// 广度优先遍历BFS -- 邻接表
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 邻接表结构定义
typedef char VertixType;                // 顶点数据元素类型
typedef int EdgeType;                   // 边上权值元素类型

// 边表结点
typedef struct EdgeNode {
    int adjvex;                         // 邻接点域 -- 存储该顶点的下标
    struct EdgeNode *next;              // 链域 -- 指向下一个邻接点
    EdgeType weight;                    // 权值
} EdgeNode;

// 顶点表结点
#define MAX_VEX 100                     // 顶点表中的最大顶点数
typedef struct VertexNode{
    VertixType data;                    // 顶点域 -- 存储顶点的信息
    struct EdgeNode *firstedge;         // 与顶点对应边表的头指针
} VertexNode, AdjList[MAX_VEX];

// 邻接表
typedef struct {
    AdjList adjList;                    // 顶点表
    int numVertexes, numEdges;          // 图中当前顶点数和边数
} GraphAdjList;

// 队列结点
typedef struct QNode {
    int             data;
    struct QNode    *next;
} QNode, *QueuePtr;

// 链式队列结构
typedef struct {
    QueuePtr    front;
    QueuePtr    rear;
} LinkQueue;

/* 函数定义 */

// 初始化队列
void InitQueue(LinkQueue *Q)
{
    QNode *head = (QNode *)malloc(sizeof(QNode));

    Q->front = head;
    Q->rear = head;
    head->next = NULL;
}

// 判断队列是否为空
bool isEmptyQueue(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return true;
    return false;
}

// 入队
void EnQueue(LinkQueue *Q, int e)
{
    QNode *new_node = (QNode *)malloc(sizeof(QNode));

    new_node->data = e;
    new_node->next = NULL;
    Q->rear->next = new_node;
    Q->rear = new_node;
}

// 出队
void DeQueue(LinkQueue *Q, int *e)
{
    if (Q->front == Q->rear) {
        fprintf(stderr, "队列为空，无法出队！\n");
        exit(EXIT_FAILURE);
    }
    *e = Q->front->next->data;

    QNode*temp = Q->front->next;        // 指向队首元素
    Q->front->next = temp->next;        // 队首更新
    
    if (Q->rear == temp)                // 如果只有一个元素 -- 则让头尾指针相等
        Q->front = Q->rear;
    free(temp);
}

// 创建邻接表
void CreateALGraph(GraphAdjList *G)
{
    printf("请输入顶点数和边数：");
    scanf("%d %d", &G->numVertexes, &G->numEdges);
    fflush(stdin);

    // 读入顶点表信息
    puts("现在读入顶点表信息...");
    for (int i = 0; i < G->numVertexes; i++) {
        printf("请输入第%d个顶点信息：", i + 1);
        scanf("%c", &G->adjList[i].data);       // 输入顶点信息
        fflush(stdin);
        G->adjList[i].firstedge = NULL;         // 将边表初始化为空表
    }

    // 读入边表信息
    puts("现在读入边表信息...");
    for (int k = 0; k < G->numEdges; k++) {
        int i, j;
        EdgeNode *e;
        
        printf("请输入边(vi, vj)上的顶点序号：");
        scanf("%d %d", &i, &j);

        // 添加边表结点到第i个顶点的边表中 -- 尾插法
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = NULL;
        // 尾插法插入
        if (!(G->adjList[i].firstedge)) {
            G->adjList[i].firstedge = (EdgeNode *)malloc(sizeof(EdgeNode));
            G->adjList[i].firstedge = e;
        }
        else {
            EdgeNode *p = G->adjList[i].firstedge;
            p->next = e;
            p = e;
        }

        // 添加边表结点到第i个顶点的边表中 -- 尾插法
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = NULL;
        // 尾插法插入
        if (!(G->adjList[j].firstedge)) {
            G->adjList[j].firstedge = (EdgeNode *)malloc(sizeof(EdgeNode));
            G->adjList[j].firstedge = e;
        }
        else {
            EdgeNode *q = G->adjList[j].firstedge;
            q->next = e;
            q = e;
        }
    }
}

// 广度优先搜索 -- 邻接表存储方式
void BFSTraverse(GraphAdjList G)
{
    LinkQueue Q;
    EdgeNode *p = NULL;
    bool visited[MAX_VEX];

    InitQueue(&Q);

    // 初始化每个顶点为未访问状态
    for (int i = 0; i < G.numVertexes; i++)
        visited[i] = false;

    for (int i = 0; i < G.numVertexes; i++) {       // 循环每一个顶点
        if (!visited[i]) {                          // 如果当前顶点未被访问则打印并入队
            visited[i] = true;
            printf("%c", G.adjList[i].data);
            EnQueue(&Q, i);

            while (!isEmptyQueue(Q)) {
                DeQueue(&Q, &i);
                p = G.adjList[i].firstedge;         // p指向当前顶点的边表
                while (p) {                         // 对边表进行遍历
                    if (!visited[p->adjvex]) {
                        visited[p->adjvex] = true;
                        printf("%c", G.adjList[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    } // if
                    p = p->next;
                } // while
            } // while
        } // if
    } // for
}

int main(void)
{
    GraphAdjList G;

    CreateALGraph(&G);

    puts("现在以BFS输出图...");
    BFSTraverse(G);

    return 0;
}