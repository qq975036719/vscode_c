// 广度优先遍历BFS -- 邻接矩阵存储方式
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 邻接矩阵结构定义
typedef char VertexType;            // 顶点数据元素类型
typedef int EdgeType;               // 边上的权值类型
#define MAXVEX 100                  // 最大顶点数
#define INFINITY 65535              // 权值不存在时的权值的值

// 邻接矩阵
typedef struct {
    VertexType vexs[MAXVEX];        // 顶点表
    EdgeType arc[MAXVEX][MAXVEX];   // 邻接矩阵 -- 可以看成是边表
    int numVertexes, numEdges;      // 当前顶点数和边数
} MGraph;                           // Matrix Graph

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

// 创建无向网图的邻接矩阵
void CreateMGraph(MGraph *G)
{
    printf("请输入顶点数和边数：");
    scanf("%d %d", &G->numVertexes, &G->numEdges);
    fflush(stdin);

    // 创建顶点表
    puts("请输入顶点元素...");
    for (int i = 0; i < G->numVertexes; i++) {
        printf("请输入第%d个顶点：", i + 1);
        scanf("%c", &G->vexs[i]);
        fflush(stdin);
    }
    
    // 初始化邻接矩阵
    for (int i = 0; i < G->numVertexes; i++)
        for (int j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINITY;
    
    // 创建邻接矩阵 -- 即创建边表
    for (int k = 0; k < G->numEdges; k++) {
        int i, j, w;
        printf("输入边(vi, vj)上的下标i, 下标j和权w：");
        scanf("%d %d %d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];            // 无向图创建后是对称矩阵
    }
}

// 广度优先搜索 -- 邻接矩阵存储方式
void BFSTraverse(MGraph G)
{
    LinkQueue Q;
    bool visited[MAXVEX];

    InitQueue(&Q);

    // 初始化所有顶点为未访问状态
    for (int i = 0; i < G.numVertexes; i++)
        visited[i] = false;

    for (int i = 0; i < G.numVertexes; i++) {   // 对每一个顶点循环
        if (!visited[i]) {                      // 没访问过的顶点则输出并入队
            visited[i] = true;
            printf("%c", G.vexs[i]);
            // 入队是为了更新i的下标从而判断其他顶点与该顶点是否有边
            EnQueue(&Q, i);
            
            while (!isEmptyQueue(Q)) {          // 队列非空则循环
                DeQueue(&Q, &i);
                // 判断其他顶点若与当前顶点存在边且未访问过 -- 打印该顶点并入队
                for (int j = 0; j < G.numVertexes; j++) {
                    if (G.arc[i][j] == 1 && !visited[j]) {
                        visited[j] = true;
                        printf("%c", G.vexs[j]);
                        EnQueue(&Q, j);
                    } // if
                } // for
            } // while

        } // if
    } // for
}

int main(void)
{
    MGraph G;

    CreateMGraph(&G);

    puts("现在以BFS输出图...");
    BFSTraverse(G);

    return 0;
}