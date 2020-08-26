// 无向图的邻接矩阵
#include <stdio.h>
#include <stdbool.h>

// 邻接矩阵结构定义
#define INFINITY 65535     // 带权网图中无邻接关系时的最大值
#define VEX_MAX 100        // 顶点数的最大值
typedef char ElemType;     // 顶点数据元素类型
typedef bool VRType;       // 邻接矩阵元素类型 -- 若为无向图可用bool表示
/* 图类型枚举
   D: Direction 方向 -- G: Graph 图
   N: Network   网   -- U: Un前缀 -- 否定
*/
typedef enum{DG, DN, UDG, UDN} GraphKind;
typedef struct {
    ElemType vexs[VEX_MAX];             // 顶点数组
    VRType edges[VEX_MAX][VEX_MAX];     // 邻接矩阵
    GraphKind kind;                     // 图的类型
    int vexnum, edgenum;                // 图的顶点数和边数
} MGraph;                               // M -- Matrix: 矩阵

// 定位某个值在图中的位置 -- 找到返回下标，找不到则返回-1
int LocateVex_MG(MGraph G, ElemType e)
{
    int i;
    for (i = 0; (i < G.vexnum) && (G.vexs[i]!=e); i++)
        continue;
    if (i < G.vexnum)
        return i;
    else
        return -1;
}

// 创建无向图的邻接矩阵
void CreateUDG_MG(MGraph *G)
{
    // 读入图的顶点数和边数
    printf("请输入图的顶点数和边数：");
    scanf("%d %d", &G->vexnum, &G->edgenum);
    fflush(stdin);
    // 读入图的顶点信息
    for (int i = 0; i < G->vexnum; i++) {
        printf("请输入第%d个顶点信息：", i + 1);
        scanf("%c", &G->vexs[i]);
        fflush(stdin);
    }
    // 初始化边为false
    for (int i = 0; i < G->vexnum; i++)
        for (int j = 0; j < G->vexnum; j++)
            G->edges[i][j] = false;
    // 创建边
    puts("现在请输入边信息, 输入边依附的两个顶点即可：");
    for (int k = 0; k < G->edgenum; k++) {
        ElemType vi, vj;
        
        printf("请输入第%d条边：", k + 1);
        scanf("%c %c", &vi, &vj);
        fflush(stdin);

        // 获取输入的顶点在图中的位置
        int i = LocateVex_MG(*G, vi);
        int j = LocateVex_MG(*G, vj);

        // 判断输入的顶点是否在图中
        while ((i<0)||(i>G->vexnum-1)||
               (j<0)||(j>G->vexnum-1))
        {
            printf("你输入的顶点不在图中，请重新输入：");
            scanf("%c %c", &vi, &vj);
            i = LocateVex_MG(*G, vi);
            j = LocateVex_MG(*G, vj);
            fflush(stdin);
        }
        // 无向图的邻接矩阵是对称矩阵
        G->edges[i][j] = G->edges[j][i] = true;
    }
}

// 测试
int main(void)
{
    MGraph G;

    CreateUDG_MG(&G);

    return 0;
}