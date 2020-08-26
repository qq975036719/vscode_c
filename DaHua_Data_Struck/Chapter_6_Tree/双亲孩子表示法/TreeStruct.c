// 双亲孩子表示法 -- P -- Parent, C -- Child
#define MAX_TREE_SIZE 100

// 数据域元素类型
typedef int TElemType;

// 孩子结点结构
typedef struct PCTNode {
    int child;                       // 存放孩子结点的下标
    struct PCTNode *next;            // 指向下一个孩子结点
} * PCPtr;                           // 双亲孩子链表

// 表头结构
typedef struct {
    TElemType data;                 // 数据域
    int parent;                     // 存放该结点的双亲结点的下标
    PCPtr firstchild;               // 双亲孩子链表
} PCTBox;

// 树结构
typedef struct {
    PCTBox nodes[MAX_TREE_SIZE];     // 表头数组
    int root, num;                  // 根的下标和结点数
} PCTree;