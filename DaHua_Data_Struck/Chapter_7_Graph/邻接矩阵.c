// 图的存储结构 -- 邻接矩阵 -- Vertex -- 顶点
#include <stdio.h>

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

/*************************************************************************************/

/* 函数定义 */

// 创建无向网图的邻接矩阵
void CreateMGraph(MGraph *G)
{
    printf("请输入顶点数和边数：");
    scanf("%d %d", &G->numVertexes, &G->numEdges);
    fflush(stdin);

    // 创建顶点表
    puts("请输入顶点元素...");
    for (int i = 0; i < G->numVertexes; i++) {
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

int main(void)
{
    MGraph graph;

    CreateMGraph(&graph);

    return 0;
}