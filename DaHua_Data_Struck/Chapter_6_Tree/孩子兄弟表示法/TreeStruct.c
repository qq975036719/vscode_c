// 孩子兄弟表示法 -- C -- Child, S -- Sibling

// 数据域元素类型
typedef int TElemType;

// 结点结构
typedef struct CSNode {
    TElemType       data;           // 数据域
    struct CSNode   *firstchild;    // 指向长子
    struct CSNode   *rightsib;      // 指向右兄弟
}