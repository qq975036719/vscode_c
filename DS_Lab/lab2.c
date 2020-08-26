#include <stdio.h>
#include <stdlib.h>

// 顺序表结构
typedef struct {
    int *data;
    int length;     // 顺序表当前长度
    int space;      // 顺序表的空间
} SqList;

// 初始化顺序表
int InitSqList(SqList *L, int length, int space)
{
    L->data = (int *)malloc(sizeof(int) * space);
    if (!L->data) {
        fprintf(stderr, "Memory error!\n");
        return 0;
    }

    L->length = length;
    L->space = space;
    return 1;
}

// 顺序表插入元素
void InsertElem(SqList *L, int e)
{
    L->data[L->length++] = e;
}

// 顺序表删除元素
void DeleteElem(SqList *L, int index, int *e)
{
    int j;

    *e = L->data[index - 1];

    for (j = index - 1; j < L->length - 1; j++)
        L->data[j] = L->data[j + 1];
    L->length--;
}

// 打印顺序表
void ShowSqList(SqList L)
{
    for (int i = 0; i < L.length; i++)
        printf("%-4d", L.data[i]);
    putchar('\n');
}

// 释放顺序表
void ClearSqList(SqList *L)
{
    free(L->data);

    L->length = 0;
    L->data = NULL;
    L->space = 0;
}

int main(void)
{
    SqList a, b;
    int e;

    int data[10] = {1, 3, 2, 4, 5, 7, 10, 13, 14, 23};
    InitSqList(&a, 0, 10);
    InitSqList(&b, 0, 10);

    for (int i = 0; i < 10; i++)
        InsertElem(&a, data[i]);

    puts("开始前：");
    printf("List A is ");
    ShowSqList(a);
    printf("List B is ");
    ShowSqList(b);

    int i = 1;
    while (i<=a.length) {
        if (a.data[i-1] & 1) {
            DeleteElem(&a, i, &e);
            InsertElem(&b, e);
        }
        else
            i++;
    }
    puts("结束后：");
    printf("List A is ");
    ShowSqList(a);
    printf("List B is ");
    ShowSqList(b);

    ClearSqList(&a);
    ClearSqList(&b);

    return 0;
}