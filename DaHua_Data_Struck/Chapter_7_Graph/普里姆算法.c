// 普里姆算法实现最小生成树
#include <stdio.h>

// 邻接矩阵结构定义
typedef char VertexType;            // 顶点数据元素类型
typedef int EdgeType;               // 边上的权值类型
#define MAXVEX 100                  // 最大顶点数
#define INF 65535                   // 权值不存在时的权值的值

// 邻接矩阵
typedef struct {
    VertexType vexs[MAXVEX];        // 顶点表
    EdgeType arc[MAXVEX][MAXVEX];   // 邻接矩阵 -- 可以看成是边表
    int numVertexes, numEdges;      // 当前顶点数和边数
} MGraph;                           // Matrix Graph

/*************************************************************************************/

/* 函数定义 */

// 最小生成树 -- Prim算法
void MiniSpanTree_Prim(MGraph G)
{
    int adjvex[MAXVEX];                     // 存放权值最小的边在U中顶点下标
    int lowcost[MAXVEX];                    // 最小边上的权值 -- 值为0说明已经并入U中
    
    // 初始化两个数组的内容
    adjvex[0] = 0;                          // 初始化第一个顶点v0下标为0
    lowcost[0] = 0;                         // 初始化第一个顶点v0加入生成树
    for (int i = 0; i < G.numVertexes; i++) {
        adjvex[i] = 0;                      // 全部初始化为和顶点v0邻接
        lowcost[i] = G.arc[0][i];           // 与v0有边关系的权值存入lowcost数组
    }

    // 遍历每一个顶点输出生成树
    for (int i = 1; i < G.numVertexes; i++) {
        // 寻找U和V-U之间的权值最小边
        int j = 1, k = 0;                   // j用于遍历顶点 -- k用于存储权值最小的边在V-U中顶点
        int min = INF;                      // 最小权值 -- 初始化为无穷大

        // 找出lowcost数组中j与adjvex[j]邻接的顶点中权值最小的顶点
        while (j < G.numVertexes) {
            if (lowcost[j]!=0 && lowcost[j]<min) {
                // 若当前遍历的顶点未并入U中且该边的权值小于min
                min = lowcost[j];           // 更新min
                k = j;                      // 更新最小边在V-U中顶点存储到k中
            }
            j++;
        }

        printf("(%d, %d)\t", adjvex[k], k); // 输出最小权值的边        
        lowcost[k] = 0;                     // 输出后将当前顶点的lowcost值置为0代表k并入U中
        
        // 更新lowcost和adjvex数组内容
        for (j = 1; j < G.numVertexes; j++) {
            // 比较与k邻接的所有在V-U中的顶点的权值与lowcost[j]的大小
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
                lowcost[j] = G.arc[k][j];   // 与k邻接的顶点的权值更小则替换lowcost相应位置的值
                adjvex[j] = k;              // 并且更新V-U中下标为j的顶点在U中的邻接点
            }
        }
    }
}

// 测试普里姆算法

int main(void)
{
    MGraph G = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8},
        {
            {0, 10, INF, INF, INF, 11, INF, INF ,INF},
            {10, 0, 18, INF, INF, INF, 16, INF, 12},
            {INF, INF, 0, 22, INF, INF, INF, INF, 8},
            {INF, INF, 22, 0, 20, INF, INF, 16, 21},
            {INF, INF, INF, 20, 0, 26, INF, 7, INF},
            {11, INF, INF, INF, 26, 0, 17, INF, INF},
            {INF, 16, INF, INF, INF, 17, 0, 19, INF},
            {INF, INF, INF, 16, 7, INF, 19, 0, INF},
            {INF, 12, 8, 21, INF, INF, INF, INF, 0}
        },
        9, 15
    };

    MiniSpanTree_Prim(G);

    return 0;
}