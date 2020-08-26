// 测试GetElem.c
#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;     // Status表示状态 -- 作为函数的返回类型 -- 表示函数结果的状态
typedef int ElemType;   // 元素的类型

typedef struct {
    ElemType data[MAXSIZE];     // 数组存储数据元素
    int length;                 // 线性表的当前长度
} SqList;

// L -- 线性表   i -- 元素的位置(从1开始)   e -- 用于存储获取到的值
Status GetElem(SqList L, int i, ElemType *e) {
    if (L.length == 0 ||i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i - 1];

    return OK;
}

int main(void)
{
    SqList List = {{1, 2, 3, 4, 5, 6, 7, 8}, 8};
    ElemType res;

    if (GetElem(List, 3, &res))
        printf("%d\n", res);
    else
        printf("Error!\n");

    return 0;
}