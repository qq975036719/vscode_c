// 课本例题2.1 -- 合并两个顺序表
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

// 合并两个顺序表
void Merge_Sq(SqList L1, SqList L2, SqList *L)
{
    // 将两个有序顺序表L1和L2合并成有序顺序表L
    // 调节L的长度
    L->length = L1.length + L2.length;
    L->listsize = L->length;

    // 遍历L开始赋值
    // i -- L1的下标, j -- L2的下标, k -- L的下标
    int i = 0, j = 0, k = 0;
    while ((i < L1.length) && (j < L2.length)) {
        if (L1.elem[i] <= L2.elem[j]) {
            L->elem[k] = L1.elem[i];
            i++;
            k++;
        }
        else {
            L->elem[k] = L2.elem[j];
            j++;
            k++;
        }

    }
    // 检查L1和L2是否还有剩余元素 -- 有则添加到L中
    while (i < L1.length) {
        L->elem[k] = L1.elem[i];
        k++;
        i++;
    }
    while (j < L2.length) {
        L->elem[k] = L2.elem[j];
        k++;
        j++;
    }
}

int main(void)
{
    SqList L1, L2, L;
    // 初始化三个顺序表
    InitList_Sq(&L1);
    InitList_Sq(&L2);
    InitList_Sq(&L);
    // 创建L1和L2顺序表 -- 往L1和L2中添加数据
    CreatList_Sq(&L1, 5);
    CreatList_Sq(&L2, 6);
    printf("合并前:\n");
    printf("L1:\n");
    TraverseList_Sq(L1);
    printf("L2:\n");
    TraverseList_Sq(L2);
    // 合并L1和L2到L中
    Merge_Sq(L1, L2, &L);
    // 打印合并后的顺序表
    printf("\n合并后:\n");
    printf("L:\n");
    TraverseList_Sq(L);

    return 0;
}