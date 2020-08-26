// 图的存储结构 -- 邻接表
#include <stdio.h>
#include <stdlib.h>

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

/* 函数定义 */

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

        // 添加边表结点到第i个顶点的边表中 -- 头插法
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        // 添加边表结点到第j个顶点的边表中 -- 头插法
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}

int main(void)
{
    GraphAdjList G;

    CreateALGraph(&G);

    return 0;
}