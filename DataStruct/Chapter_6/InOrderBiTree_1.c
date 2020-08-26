// 中序遍历二叉树 -- 迭代 -- 利用栈实现
#include <stdio.h>
#include <stdlib.h>

/* 二叉树结点定义 */
typedef char ElemType;
typedef struct TNode {
    ElemType data;
    struct TNode *lchild;
    struct TNode *rchild;
} TNode, *BiTree;

/* 栈结构定义 */
#define STACK_MAX_SIZE 100
typedef TNode * StackElem;
typedef struct Stack {
    StackElem *node;
    int top;
    int size;
} Stack;

/* 函数定义 */

// **************************************
// 栈相关函数

// 初始化栈
void InitStack(Stack *S)
{
    S->node = (StackElem *)malloc(sizeof(StackElem) * STACK_MAX_SIZE);
    S->top = -1;
    S->size = STACK_MAX_SIZE;
}

// 入栈
void Push(Stack *S, StackElem e)
{
    if (S->top >= S->size-1) fprintf(stderr, "栈已满！\n");
    else
        S->node[++(S->top)] = e;
}

// 出栈
void Pop(Stack *S, StackElem *e)
{
    if (S->top == -1) fprintf(stderr, "栈已空，无法出栈！\n");
    else
        *e = S->node[S->top--];
}

// **************************************
// 二叉树相关函数

// 前序创建二叉树
void PreCreatBiTree(BiTree *tree)
{
    ElemType ch;
    scanf("%c", &ch);

    if (ch == '#') *tree = NULL;
    else {
        (*tree) = (TNode *)malloc(sizeof(TNode));
        (*tree)->data = ch;
        (*tree)->lchild = NULL;
        (*tree)->rchild = NULL;
        PreCreatBiTree(&(*tree)->lchild);
        PreCreatBiTree(&(*tree)->rchild);
    }
}

// 中序遍历二叉树 -- 迭代
void InOrderTraverse(BiTree tree)
{
    Stack s;
    InitStack(&s);

    BiTree *p = &tree;       // 创建一个指向树tree的指针
    while (*p || s.top!=-1) {
        if (*p) {
            Push(&s, *p);
            *p = (*p)->lchild;
        }
        else {
            Pop(&s, p);
            printf("%c", (*p)->data);
            *p = (*p)->rchild;
        }
    }
}

// 测试中序遍历二叉树 -- 迭代
int main(void)
{
    BiTree tree;
    puts("请输入二叉树内容：");
    PreCreatBiTree(&tree);

    puts("中序遍历二叉树结果如下：");
    InOrderTraverse(tree);
    putchar('\n');

    return 0;
}