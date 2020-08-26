// 线索二叉树结构定义
// Link == 0 -- 指向左右孩子，Thread == 1 -- 指向前驱后继
typedef enum {Link, Thread} PointerTag;

typedef char TElemType;         // 数据域元素类型
typedef struct BiThrNode {      // 结点结构
    TElemType data;             // 数据域
    struct BiThrNode *lchild;   // 指向左孩子
    struct BiThrNode *rchild;   // 指向右孩子
    PointerTag ltag;            // 左标签 -- 标记左结点是孩子结点还是前驱
    PointerTag rtag;            // 右标签 -- 标记右结点是孩子结点还是后继
} BiThrNode, *BiThrTree;