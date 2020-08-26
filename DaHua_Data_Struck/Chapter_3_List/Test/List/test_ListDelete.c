// 测试ListDelete.c
#include <stdio.h>

// 实现线性表中某个元素的删除

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

// e -- 用于存储被删除的元素
Status ListDelete(SqList *L, int i, ElemType *e)
{
    if (L->length == 0)     // 线性表为空的情况 -- 没有元素可以删除
        return ERROR;
    if (i < 1 || i > L->length)
        return ERROR;
    // 被删除的元素传递给e
    *e = L->data[i - 1];
    if (i < L->length)  // 如果被删除的元素不是最后一个元素
        for (int k = i; k <= L->length; k++)
            L->data[k - 1] = L->data[k];    // 被删除位置的元素后面的元素往前移一位
    L->length--;    // 表长减1

    return OK;
}

int main(void)
{
    SqList List = {{1, 2, 3, 4, 5, 6, 7, 8}, 8};
    ElemType e;

    if (ListDelete(&List, 3, &e))
        for (int i = 0; i < List.length; i++)
            printf("%d\t", List.data[i]);
    else
        printf("Error!\n");
        
    printf("\n被删除的数字为: %d\n", e);

    return 0;
}