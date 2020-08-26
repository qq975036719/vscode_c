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


