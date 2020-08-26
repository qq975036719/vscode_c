// 邻接矩阵结构定义 -- Adjacency Matrix
#define INFINITY 65535     // 带权网图中无邻接关系时的最大值
#define VEX_MAX 100        // 顶点数的最大值
typedef char ElemType;     // 顶点数据元素类型
typedef int VRType;        // 邻接矩阵元素类型 -- 若为无向图可用bool表示
/* 图类型枚举
   D: Direction 方向 -- G: Graph 图
   N: Network   网   -- U: Un前缀 -- 否定
*/
typedef enum{DG, DN, UDG, UDN} GraphKind;
typedef struct {
    ElemType vexs[VEX_MAX];             // 顶点数组
    VRType edges[VEX_MAX][VEX_MAX];     // 邻接矩阵
    /* 若为无向图可这样表示
    bool edges[VEX_MAX][VEX_MAX];       True表示存在边
    */
    GraphKind kind;                     // 图的类型
    int vexnum, edgenum;                // 图的顶点数和边数
} MGraph;                               // M -- Matrix: 矩阵