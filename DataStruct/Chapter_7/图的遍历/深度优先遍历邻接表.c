// 深度优先遍历邻接表(DFS)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 邻接表结构定义 -- Adjacency List
typedef char ElemType;          // 头结点数据元素类型
// 表结点结构
typedef struct EdgeNode{        
    int adjvex;                 // 邻接点在头结点数组中的下标
    struct EdgeNode *nextedge;  // 指向下一条边
    int weight;                 // 权域
} EdgeNode, *adjList;
// 头结点结构
typedef struct {
    ElemType vex;               // 顶点信息
    adjList  firstedge;         // 第一条依附于顶点的边(弧)
} VexNode;
// 邻接表存储的图
#define MAX_VEX 100
typedef enum{DG, DN, UDG, UDN} GraphKind;
typedef struct {
    VexNode vexs[MAX_VEX];      // 顶点数组
    int vexnum, edgenum;        // 图中顶点数和边数
    GraphKind kind;             // 图的种类
} ALGraph;

// 定位某个值在图中的位置 -- 找到返回下标，找不到则返回-1
int LocateVex_ALG(ALGraph G, ElemType e)
{
    int i;
    for (i = 0; (i < G.vexnum) && (G.vexs[i].vex != e); i++)
        continue;
    if (i<G.vexnum)
        return i;
    return -1;
}

// 创建邻接表存储的有向图
void CreateDG_ALG(ALGraph *G)
{
    printf("请输入顶点数和边数：");
    scanf("%d %d", &G->vexnum, &G->edgenum);
    fflush(stdin);

    // 构造顶点数组
    for (int i = 0; i < G->vexnum; i++) {
        printf("请输入第%d个顶点信息：", i + 1);
        scanf("%c", &G->vexs[i].vex);
        fflush(stdin);

        G->vexs[i].firstedge = NULL;
    }

    // 构造邻接表
    for (int k = 0; k < G->edgenum; k++) {
        printf("请输入第%d条弧依附的两个顶点：", k + 1);
        ElemType vi, vj;
        scanf("%c %c", &vi, &vj);
        fflush(stdin);

        int i = LocateVex_ALG(*G, vi);
        int j = LocateVex_ALG(*G, vj);
        while ((i<0)||(i>G->vexnum)||
               (j<0)||(j>G->vexnum))
        {
            printf("你输入的顶点不在图中，请重新输入：");
            scanf("%c %c", &vi, &vj);
            fflush(stdin);
        }
        EdgeNode *p = (EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex = j;
        p->nextedge = G->vexs[i].firstedge;
        G->vexs[i].firstedge = p;
    }
}

// 深度优先遍历图G
bool visited[MAX_VEX];          // 标志当前顶点是否被访问过
void DFS_ALG(ALGraph, int);
void DFSTraverse_ALG(ALGraph G)
{
    // 初始化所有顶点为未访问状态
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;
    // 对所有顶点进行DFS遍历
    for (int i = 0; i < G.vexnum; i++)
        if (!visited[i])
            DFS_ALG(G, i);
}

// 从顶点i开始深度优先遍历图中所有顶点
void DFS_ALG(ALGraph G, int i)
{
    EdgeNode *p;
    printf("%c", G.vexs[i].vex);
    visited[i] = true;

    for (p = G.vexs[i].firstedge; p != NULL; p = p->nextedge) {
        if (!visited[p->adjvex])
            DFS_ALG(G, p->adjvex);
    }
}

// 测试
int main(void)
{
    ALGraph G;

    CreateDG_ALG(&G);

    puts("DFS遍历图结果如下：");
    DFSTraverse_ALG(G);

    return 0;
}