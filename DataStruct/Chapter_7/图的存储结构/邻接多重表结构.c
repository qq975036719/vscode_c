// 邻接多重表结构定义
#include <stdbool.h>
typedef char ElemType;                      // 顶点元素数据类型
// 表结点结构
typedef struct EdgeBox {
    bool                mark;               // 标记当前结点是否被访问过
    int                 ivex, jvex;         // 记录该边所依附的两个顶点的位置
    struct EdgeBox      *ilink;             // 指向依附于ivex的下一条边
    struct EdgeBox      *jlink;             // 指向依附于jvex的下一条边
    int weight;
} EdgeBox;
// 顶点结构
typedef struct {
    ElemType            vex;                // 顶点信息
    EdgeBox             *firstedge;         // 顶点数和边数
} VexBox;
// 邻接多重表存储的图
#define MAX_VEX 100
typedef struct {
    VexBox              vexs[MAX_VEX];      // 顶点数组
    int                 numvex, numedge;    // 顶点数和边数
} AMLGraph;


