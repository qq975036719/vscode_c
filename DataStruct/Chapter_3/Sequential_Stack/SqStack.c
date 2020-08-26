// 顺序栈的基本操作
#include <stdio.h>
#include <stdlib.h>

/* 顺序栈的结构 */
#define STACK_INIT_SIZE 100     // 栈存储空间的初始分配量
#define STACK_INCREMENT 10      // 站存储空间的分配增补量
typedef int ElemType;           // 数据域的元素类型

typedef struct stack {
    ElemType *data;             // 数据域
    int top;                    // top指针 -- 指向栈顶
    int stacksize;              // 栈的当前最大空间
} SqStack;

/* 功能函数 */

// 初始化顺序栈
void InitStack_Sq(SqStack *S)
{
    // 初始化栈空间为100
    S->data = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
    if (!S->data) {
        fprintf(stderr, "Overflow!\n");
        exit(EXIT_FAILURE);
    }
    // 初始化top指向栈底
    S->top = -1;
    // 初始化栈的当前大小为0
    S->stacksize = STACK_INIT_SIZE;
}

// 销毁顺序栈
void DestroyStack_Sq(SqStack *S)
{
    free(S->data);
    S->top = -1;
    S->stacksize = 0;
}

// 获取栈的长度
int StackLength_Sq(SqStack *S)
{
    return (S->top+1);
}

// 取栈顶元素值
void GetTop_Sq(SqStack S, ElemType *e)
{
    if (S.top == -1) {
        fprintf(stderr, "栈为空，没元素可取！\n");
        exit(EXIT_FAILURE);
    }
    else
        *e = S.data[S.top];
}

// 栈空间增加
void Increment(SqStack *S)
{
    ElemType* newSq;

    // 分配新大小的数据域空间
    newSq = (ElemType *)malloc(sizeof(ElemType) * S->stacksize + STACK_INCREMENT);
    if (!newSq) {
        fprintf(stderr, "overflow!\n");
        exit(EXIT_FAILURE);
    }
    // 将旧数据域空间的元素复制到新数据域空间中
    for (int i = 0; i < S->top; i++)
        newSq[i] = S->data[i];
    // 释放旧数据域空间的元素
    free(S->data);
    // 更新S的信息
    S->data = newSq;
    S->stacksize += STACK_INCREMENT;
}

// 入栈操作
void Push_Sq(SqStack *S, ElemType e)
{
    if (S->top == (S->stacksize-1))
        Increment(S);
    else
        S->data[++S->top] = e;
}

// 出栈操作
void Pop_Sq(SqStack *S, ElemType *e)
{
    if (S->top == -1) {
        fprintf(stderr, "栈为空，无法出栈！\n");
        exit(EXIT_FAILURE);
    }
    else
        *e = S->data[S->top--];
}

// 测试栈的基本操作
int main(void)
{
    SqStack Stack_Sq;
    int n;
    ElemType e;

    InitStack_Sq(&Stack_Sq);
    printf("请输入要插入栈中的数据个数：");
    scanf("%d", &n);

    // 入栈
    for (int i = 0; i < n; i++) {
        printf("请输入第%d个元素: ", i + 1);
        scanf("%d", &e);
        Push_Sq(&Stack_Sq, e);
    }

    // 打印顺序栈中的元素
    puts("栈中数据如下：");
    for (int i = 0; i <= Stack_Sq.top; i++) {
        printf("%-5d", Stack_Sq.data[i]);
        if ((i + 1) % 10 == 0)
            putchar('\n');
    }
    putchar('\n');

    // 出栈
    Pop_Sq(&Stack_Sq, &e);
    printf("出栈的元素为：%d\n", e);

    return 0;
}