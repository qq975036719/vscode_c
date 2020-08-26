// 括号匹配问题

// 顺序栈的基本操作
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 顺序栈的结构 */
#define STACK_INIT_SIZE 100     // 栈存储空间的初始分配量
#define STACK_INCREMENT 10      // 站存储空间的分配增补量
typedef char ElemType;          // 数据域的元素类型

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

// 括号匹配函数
int matching()
{
    SqStack S;
    ElemType ch;
    ElemType e;
    int flag = 1;               // 标志括号是否合法 -- 默认合法

    InitStack_Sq(&S);           // 初始化顺序栈
    Push_Sq(&S, '#');           // "#"放在栈底表示括号串开始

    printf("请输入一个字符串：");
    ch = getchar();

    while (ch != '\n' && flag) {
        if (ch == '(')
            Push_Sq(&S, ch);
        if (ch == ')') {
            GetTop_Sq(S, &e);
            if (e != '#')           // 栈中还有'('可以和')'匹配
                Pop_Sq(&S, &e);     // 有的话就让')'出栈
            else
                flag = 0;           // 没有的话说明')'多余 -- 非法
        }
        ch = getchar();
    }
    GetTop_Sq(S, &e);               // while出来的条件只用考虑ch == '\n'
                                    // 因为flag==0说明已经是非法，不用再考虑了
    if (e != '#')                   // 说明栈中还有'('未匹配 -- 非法
        flag = 0;

    return flag;
}

int main(void)
{
    if (matching())
        printf("合法！\n");
    else
        printf("不合法！\n");

    return 0;
}