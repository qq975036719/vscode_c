// 克鲁斯卡尔算法实现最小生成树
#include <stdio.h>
#include <stdlib.h>                 // 包含qsort函数

// 邻接矩阵结构定义
typedef char VertexType;            // 顶点数据元素类型
typedef int EdgeType;               // 边上的权值类型
#define MAXVEX 100                  // 最大顶点数
#define MAXEDGE 100                 // 最大边数
#define INF 65535                   // 权值不存在时的权值的值

// 邻接矩阵
typedef struct {
    VertexType vexs[MAXVEX];        // 顶点表
    EdgeType arc[MAXVEX][MAXVEX];   // 邻接矩阵 -- 可以看成是边表
    int numVertexes, numEdges;      // 当前顶点数和边数
} MGraph;                           // Matrix Graph

// 边集数组结构定义
typedef struct {
    int begin;
    int end;
    int weight;
} Edge;

/*************************************************************************************/

/* 函数定义 */

// 交换边集数组中两个元素
void swapn(Edge *edges, int i, int j)
{
    int tmp;

    tmp = edges[i].begin;
    edges[i].begin = edges[j].begin;
    edges[j].begin = tmp;

    tmp = edges[i].end;
    edges[i].end = edges[j].end;
    edges[j].end = tmp;

    tmp = edges[i].weight;
    edges[i].weight = edges[j].weight;
    edges[j].weight = tmp;
}

// 对边集数组按权值从小到大进行排序
void sort(Edge *edges, MGraph *G)
{
    for (int i = 0; i < G->numEdges; i++) {
        for (int j = i + 1; j < G->numEdges; j++) {
            if (edges[i].weight > edges[j].weight)
                swapn(edges, i, j);
        }
    }
    puts("排序后的边集数组如下：");
    for (int i = 0; i < G->numEdges; i++)
        printf("(%d, %d) 权值%d\n",
               edges[i].begin, edges[i].end, edges[i].weight);
    putchar('\n');
}

// 查找连线顶点的尾部下标
int Find(int *parent, int f)
{
    while (parent[f] > 0)
        f = parent[f];
    return f;
}

// 最小生成树 -- 克鲁斯卡尔算法
void MiniSpanTree_Kruskal(MGraph G)
{
    Edge edges[MAXEDGE];                // 边集数组
    int parent[MAXVEX];                 // 用于标记边与边之间是否会形成回路
    int k = 0;                          // 边集数组的下标

    // 创建边集数组并排序 ----------------------------------------
    for (int i = 0; i < G.numVertexes - 1; i++)
        for (int j = i + 1; j < G.numVertexes; j++)
            if (G.arc[i][j] != INF) {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = G.arc[i][j];
                k++;
            }
    sort(edges, &G);
    // ----------------------------------------------------------

    // 初始化parent数组为0
    for (int i = 0; i < G.numVertexes; i++)
        parent[i] = 0;
    
    // 循环每一条边
    puts("最小生成树：");
    for (int i = 0; i < G.numEdges; i++) {
        int n = Find(parent, edges[i].begin);
        int m = Find(parent, edges[i].end);
        if (n != m) {
            parent[n] = m;
            printf("(%d, %d) 权值%d\n",
            edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}

int main(void)
{
    MGraph G = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8},
        {
            {0, 10, INF, INF, INF, 11, INF, INF ,INF},
            {10, 0, 18, INF, INF, INF, 16, INF, 12},
            {INF, INF, 0, 22, INF, INF, INF, INF, 8},
            {INF, INF, 22, 0, 20, INF, 24, 16, 21},
            {INF, INF, INF, 20, 0, 26, INF, 7, INF},
            {11, INF, INF, INF, 26, 0, 17, INF, INF},
            {INF, 16, INF, 24, INF, 17, 0, 19, INF},
            {INF, INF, INF, 16, 7, INF, 19, 0, INF},
            {INF, 12, 8, 21, INF, INF, INF, INF, 0}
        },
        9, 15
    };

    puts("克鲁斯卡尔算法的最小生成树：");
    MiniSpanTree_Kruskal(G);

    return 0;
}