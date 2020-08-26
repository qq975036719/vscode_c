// 十字链表结构定义
typedef char ElemType;              // 顶点数据元素类型
// 表结点结构
typedef struct ArcBox {
    int             tailvex         // 该弧的弧尾位置
    int             headvex;        // 该弧的弧头位置
    struct ArcBox   *hlink;         // 指向和当前弧头相同的下一条弧
    struct ArcBox   *tlink;         // 指向和当前弧尾相同的下一条弧
    int weight;                     // 权域
} ArcBox;
// 头结点结构
typedef struct {
    ElemType      vex;              // 顶点信息
    ArcBox        *firstin;         // 指向该顶点第一条入弧
    ArcBox        *firstout;        // 指向该顶点第一条出弧
} VexNode;
// 十字链表存储的图
#define MAX_VEX 100
typedef struct {
    head VexNode[MAX_VEX];          // 顶点数组
    int vexnum, edgenum;            // 顶点数和边(弧)数
} OLGraph;


