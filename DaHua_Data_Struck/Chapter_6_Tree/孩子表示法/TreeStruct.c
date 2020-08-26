// 孩子表示法
#define MAX_TREE_SIZE 100

// 数据域元素类型
typedef int TElemType;

// 孩子结点
typedef struct CTNode {
    int child;                  // 当前孩子结点的下标
    CTNode *next;               // 指向下一个孩子结点
} *ChildPtr;                    // 孩子链表

// 表头结构
typedef struct {
    TElemType data;             // 数据域
    ChildPtr firstchild;        // 孩子链表
} CTBox;                        // 根结点

// 树结构
typedef struct {
    CTBox nodes[MAX_TREE_SIZE]; // 表头数组
    int root, num;              // 存储根结点下标和结点数
} CTree;