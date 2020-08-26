// 例题2.2 -- 在一个递增的顺序表中插入一个元素

// 顺序表基本操作
#include <stdio.h>
#include <stdlib.h>
// 顺序表结构
#define LIST_INIT_SIZE 100      // 线性表存储空间的初始分配量
#define LIST_INCREMENT 10       // 线性表存储空间的分配增补量
typedef int ElemType;
typedef struct {
    ElemType *elem;
    int length;                 // 线性表的当前长度
    int listsize;               // 当前分配的存储容量
} SqList;

// 错误信息提示函数
void Error(char *st)
{
    fprintf(stderr, "%s\n", st);
    exit(EXIT_FAILURE);
}

// 初始化顺序表
void InitList_Sq(SqList *L)
{
    L->elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if (L->elem == NULL)
        Error("Overflow!");
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
}

// 扩充顺序表
void Increment(SqList *L)
{
    // 创建临时数组存储原顺序表的数据
    ElemType *newlist = (ElemType *)malloc(sizeof(ElemType) * (L->listsize + LIST_INCREMENT));
    if (newlist == NULL)
        Error("Overflow!");
    
    // 复制原顺序表数据到临时数组中并释放原顺序表
    for (int i = 0; i < L->length; i++) {
        newlist[i] = L->elem[i];
        free(&L->elem[i]);
    }

    L->elem = newlist;              // 将临时数组的首地址赋值给顺序表
    L->listsize += LIST_INCREMENT;  // 顺序表的分配空间增加
}

// 创建顺序表
void CreatList_Sq(SqList *L, int n)
{
    while (n>=L->listsize)
        Increment(L);
    for (int i = 0; i < n; i++, L->length++) {
        printf("请输入第%d个元素: ", i+1);
        scanf("%d", &L->elem[i]);
    }
}

// 插入第i个元素
void InsertElem_Sq(SqList *L, int i, ElemType e)
{
    // 判断输入的i范围是否正确
    if ((i < 1) || (i > L->length + 1))
        Error("Position Error!");
    if (L->length >= L->listsize)
        Increment(L);
    ElemType *temp = &L->elem[i - 1];       // 指向被插入位置
    ElemType *p;
    // 第i个元素开始往后移动一位
    for (p = &(L->elem[L->length - 1]); p >= temp; p--)
        *(p + 1) = *p;
    *temp = e;                            // 第i个元素变为e
    L->length++;                          // 顺序表当前长度增加1
}

// 删除第i个元素 -- 并用e返回被删除的值
void DeleteElem_Sq(SqList *L, int i, ElemType *e)
{
    // 判断i的范围
    if ((i < 1) || (i > L->length + 1))
        Error("Position Error!");
    *e = L->elem[i - 1];        // 用e返回被删除的值
    // 第i个元素后的元素往前移一位
    for (int j = i - 1; j < L->length - 1; j++)
        L->elem[j] = L->elem[j + 1];
    L->length--;
    /*  还可以这样写
        ElemType *p = &(L->elem[i - 1]);
        ElemType *q = L->elem + L->length - 1;
        for (++p; p <= q; p++)
            *(p - 1) = *p;
    */
}

// 输出顺序表元素(遍历)
void TraverseList_Sq(SqList L)
{
    for (int i = 0; i < L.length; i++) {
        printf("%d\t", L.elem[i]);
        if ((i + 1) % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
}

// 销毁顺序表元素
void DestroyList_Sq(SqList *L)
{
    // 释放所有元素
    free(L->elem);
    L->length = 0;
    L->listsize = 0;
}

// 在递增的顺序表中插入一个元素 -- 且保持顺序表的有序性不变
void Ins_IncreaseList(SqList *L, ElemType e)
{
    // 检查顺序表是否已满 -- 满了退出程序
    if (L->length>=L->listsize)
        Error("Linear List Overflow!");
    // 从后往前遍历L -- 寻找插入位置的同时将元素后移
    for (int i = L->length; i > 0; i--) {
        if (L->elem[i] > e)
            L->elem[i] = L->elem[i-1];
        else {
            L->elem[i+1] = e;
            break;
        }
    }
    L->length++;
}

int main(void)
{
    SqList L;

    // 初始化并创建顺序表
    InitList_Sq(&L);
    CreatList_Sq(&L, 7);
    // 打印创建好的顺序表
    TraverseList_Sq(L);
    // 在顺序表中插入一个元素6 -- 且保持顺序表有序性不变
    Ins_IncreaseList(&L, 6);
    // 打印顺序表观察插入结果
    TraverseList_Sq(L);

    return 0;
}