// 克鲁斯卡尔算法
#include <stdio.h>
#include <stdlib.h>

// 结构定义
typedef char VertexType;
typedef int EdgeType;
#define MAX_VEX 100
#define MAX_EDGE 100
#define INF 65535
// 邻接矩阵
typedef struct {
    VertexType vexs[MAX_VEX];
    EdgeType edges[MAX_VEX][MAX_VEX];
    int vexnum, edgenum;
} MGraph;
// 边集数组
typedef struct {
    int begin;
    int end;
    int weight;
} Edge;

// 边集数组排序模式函数 -- 用于qsort函数排序的模式函数
int cmp(const void *p1, const void *p2)
{
    return ((Edge *)p1)->weight - ((Edge *)p2)->weight;
}

// 克鲁斯卡尔算法
void MiniSpanTree_Kruskal(MGraph G)
{
    Edge edges[MAX_EDGE];       // 边集数组
    int parent[MAX_VEX];        // 辅助数组
    int k = 0;                  // 操控边集数组的下标

    /* 生成边集数组 ---------------------------------------------------*/
    // 初始化边集数组
    for (int i = 0; i < G.vexnum - 1; i++)
        for (int j = i+1; j < G.vexnum; j++)
            if (G.edges[i][j] != 0 && G.edges[i][j] != INF) {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = G.edges[i][j];
                k++;
            }
    // 排序边集数组
    qsort(edges, G.edgenum, sizeof(Edge), cmp);
    /*----------------------------------------------------------------*/

    // 初始化辅助数组
    for (int i = 0; i < G.vexnum; i++)
        parent[i] = i;
    
    // 遍历每一条边，判断是否添加到最小生成树中(在这里即输出结果)
    int ct = 0;         // 统计当前生成树中添加的边数
    for (int k = 0; k < G.edgenum; k++) {
        if (ct == G.vexnum - 1)         // 生成了n-1条边则退出循环
            break;
        int u1 = edges[k].begin;        // 第k条边的尾顶点
        int u2 = edges[k].end;          // 第k条边的头顶点
        int sn1 = parent[u1];           // 第k条边尾顶点的编号
        int sn2 = parent[u2];           // 第k条边头顶点的编号

        if (sn1 != sn2) {
            printf("(%d, %d) 权值: %d\n",
                   edges[k].begin, edges[k].end, edges[k].weight);
            ct++;                       // 加入生成树的边数+1
            // 将U中集合的编号和V-U中集合的编号统一
            for (int i = 0; i < G.vexnum; i++)
                if (parent[i] == sn2)
                    parent[i] = sn1;
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

    MiniSpanTree_Kruskal(G);

    return 0;
}