// 递归和非递归方法后序遍历二叉树
#include <stdio.h>
#include <stdlib.h>

// 二叉树结构定义
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

// 取栈顶元素
void GetTop(Stack S, StackElem *e)
{
    if (S.top != -1)
        *e = S.node[S.top];
    else
        *e = NULL;
}

// 二叉树相关函数

// 遍历二叉树时对二叉树的操作函数
void DoSomething(TNode *n)
{
    printf("%c", n->data);
}

// 前序创建二叉树
void PreCreat(BiTree *tree)
{
    ElemType ch;
    scanf("%c", &ch);

    if (ch == '#')
        *tree = NULL;
    else {
        *tree = (TNode *)malloc(sizeof(TNode));
        (*tree)->data = ch;
        (*tree)->lchild = NULL;
        (*tree)->rchild = NULL;
        PreCreat(&(*tree)->lchild);
        PreCreat(&(*tree)->rchild);
    }
}

// 递归法后序遍历二叉树
void PostTraverse_1(BiTree tree)
{
    if (tree) {
        PostTraverse_1(tree->lchild);
        PostTraverse_1(tree->rchild);
        printf("%c", tree->data);
    }
    else
        return;
}

// 非递归法后序遍历二叉树
void PostTraverse_2(BiTree tree)
{
    Stack s;
    TNode *p = tree;                                // 指向树的根结点
    TNode *pre = p;                                 // 指向上一个访问过的结点
    InitStack(&s);

    while (p || s.top != -1) {
        if (p) {                                    // 根结点入栈
            Push(&s, p);
            pre = p;                                // 更新上一个访问结点的位置
            p = p->lchild;                          // 遍历左子树
        }
        else {                                      // 当前访问的结点为空
            GetTop(s, &p);                          // 访问栈顶元素 -- 但不弹出栈
            
            if (p->rchild && p->rchild != pre) {    // 如果有右子树 -- 则继续遍历右子树
                p = p->rchild;
                Push(&s, p);
                p = p->lchild;                      // 遍历右子树的左子树
            }
            else {                                  // 没有右子树 -- 说明当前层已经遍历完
                Pop(&s, &p);
                DoSomething(p);
                pre = p;                            // 当前结点成为下一次访问的上一个结点
                p = NULL;                           // 把p置空才能让其下次循环访问栈顶元素
            }
        }
    }
}

// 测试递归后序遍历二叉树和非递归后序遍历二叉树
int main(void)
{
    BiTree tree;

    // 创建二叉树
    puts("请按前序输入二叉树内容：");
    PreCreat(&tree);

    // 递归遍历
    puts("\n递归后序遍历二叉树结果如下：");
    PostTraverse_1(tree);

    // 非递归遍历
    puts("\n非递归后序遍历二叉树结果如下：");
    PostTraverse_2(tree);

    return 0;
}