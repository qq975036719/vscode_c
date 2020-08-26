// 二叉树存储
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 结点数据元素类型
typedef char ElemType;

// 顺序存储二叉树结构
#define BiTree_Size 100
typedef ElemType SqBiTree[BiTree_Size + 1];

// 链式存储二叉树结构
typedef struct TNode{
    ElemType data;          // 数据域
    struct TNode *lchild;   // 指向左孩子
    struct TNode *rchild;   // 指向右孩子
} TNode, *BiTree;

/* 函数定义 */

// 顺序存储二叉树 -- 层序存储
void CreatBiTree_Sq(SqBiTree T, char *s)
{
    int len = strlen(s);
    T[0] = len;

    for (int i = 1; i <= len; i++)
        T[i] = s[i - 1];
}

// 遍历输出顺序存储的二叉树
void ShowBiTree_Sq(SqBiTree T)
{
    int j;
    for (int i = 1; i <= T[0]; i++) {
        if (i == 1)
            j = 1;
        else if (j * 2 <= T[0])                 // 左孩子
            j *= 2;
        else if (j % 2 == 0 && (j < T[0]))      // 右兄弟 -- j为偶数则当前为双亲的左孩子
            j += 1;                             // 双亲的左孩子+1即右孩子，也就是左孩子的右兄弟
        else if (j>1) {                         // 没有左孩子也没有右孩子
            while ((j / 2) % 2 != 0)            // 当双亲没有有兄弟时就继续往祖先遍历
                j /= 2;
            j = j / 2 + 1;                      // 双亲有右兄弟了则遍历右兄弟所在二叉树
        }
        if (T[j] != '#')
            printf("%c", T[j]);
    }
}

// 链式二叉树创建 -- 先序创建
void CreatBiTree_L(BiTree *T)
{
    ElemType ch;
    scanf("%c", &ch);

    if (ch == '#') *T = NULL;
    else {
        *T = (TNode *)malloc(sizeof(TNode));
        (*T)->data = ch;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        CreatBiTree_L(&(*T)->lchild);
        CreatBiTree_L(&(*T)->rchild);
    }
}

// 顺序存储二叉树的非递归中序遍历 -- 利用栈实现

// 栈结构定义
typedef struct {
    ElemType *data;
    int top;
} Stack;

// 初始化栈
void InitStack(Stack *s)
{
    s->data = (ElemType *)malloc(sizeof(ElemType) * BiTree_Size);
    s->top = -1;
}

// 入栈
void Push(Stack *s, ElemType e)
{
    s->data[++s->top] = e;
}

// 出栈
void Pop(Stack *s, ElemType *e)
{
    *e = s->data[s->top--];
}

// 非递归中序遍历 -- 顺序存储
void InOrderTraverse_Sq(SqBiTree tree)
{
    Stack stack;
    InitStack(&stack);

    int i = 1;
    ElemType p;

    while (tree[i] != '#' || stack.top != -1) {
        if (tree[i] != '#') {       // 当前结点不为空
            Push(&stack, tree[i]);
            if (2*i <= tree[0])      // 有左孩子则访问左孩子
                i *= 2;
        }
        else {
            Pop(&stack, &p);
            printf("%c", p);
            i /= 2;

            if (2*i+1 <= tree[0]) {     // 有右孩子则访问右孩子
                i = i * 2 + 1;
            }
        }
    }
}

int main(void)
{
    SqBiTree tree_sq;
    char treenodes_sq[] = "FBGAD#I##CE##H";
    CreatBiTree_Sq(tree_sq, treenodes_sq);

    puts("非递归中序遍历顺序存储二叉树结果");
    InOrderTraverse_Sq(tree_sq);

    return 0;
}