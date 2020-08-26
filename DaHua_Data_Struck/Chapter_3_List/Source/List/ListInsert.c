// 实现线性表的插入

// 线性表的结构
#define MAXSIZE 20

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];     // 数组存储数据元素
    int length;                 // 线性表的当前长度
} SqList;

// 定义函数的返回类型
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
typedef int Status;

Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;
    if (L->length == MAXSIZE)       // 线性表满了的情况
        return ERROR;

    /* 插入位置超出线性表的范围--条件为length+1
       是因为插入新元素后整个长度变为length+1
       注意这个条件不包含插入位置i为表的末尾的情况 */
    if (i < 1 || i > L->length + 1) 
        return ERROR;
    if (i <= L->length) {   // 插入位置不在表的末尾
        // 将i后面的元素都往后移一位
        for (k = L->length-1; k >= i-1; k--) // length和i都减1是因为下标从0开始
            L->data[k + 1] = L->data[k];
    }
    // 将第i位(下标为i-1)元素换成待插入的元素
    L->data[i - 1] = e;
    L->length++;    // 表长加1

    return OK;
}