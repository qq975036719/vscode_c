// 双亲表示法 -- 双亲域 -- 另有用长子域和右兄弟域
#define MAX_TREE_SIZE 100

typedef int TElemType;              // 定义结点数据元素类型

typedef struct PTNode {             // 定义结点的结构
    TElemType data;
    int parent;                     // 指向双亲结点的下标    --  双亲域
 /* 
    int firstchild;                 // 指向结点的最左孩子结点 -- 长子域
    int rightsib;                   // 指向结点的右边兄弟结点 -- 右兄弟域
 */ 
} PTNode;

typedef struct {                    // 定义树结构类型
    PTNode nodes[MAX_TREE_SIZE];
    int r, n;                       // r -- 根的位置, n -- 结点数
} PTree;