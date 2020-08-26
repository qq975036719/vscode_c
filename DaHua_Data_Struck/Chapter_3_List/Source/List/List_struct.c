// 线性表的结构
#define MAXSIZE 20

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];     // 数组存储数据元素
    int length;                 // 线性表的当前长度
} SqList;