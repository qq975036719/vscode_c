// 中序遍历线索二叉树进行线索化
#include <stdio.h>
#include <stdlib.h>

// 线索二叉树结构定义
// Link == 0 -- 指向左右孩子，Thread == 1 -- 指向前驱后继
typedef enum {Link, Thread} PointerTag;

typedef char TElemType;         // 数据域元素类型
typedef struct BiThrNode {      // 结点结构
    TElemType data;             // 数据域
    struct BiThrNode *lchild;   // 指向左孩子
    struct BiThrNode *rchild;   // 指向右孩子
    PointerTag ltag;            // 左标签 -- 标记左结点是孩子结点还是前驱
    PointerTag rtag;            // 右标签 -- 标记右结点是孩子结点还是后继
} BiThrNode, *BiThrTree;

/* 全局变量：pre -- 用于指向当前遍历结点的前一个结点 */
BiThrNode *pre = NULL;

// 前序创建一颗二叉树
void PreCreatBiTree(BiThrTree *T)
{
    TElemType ch;
    scanf("%c", &ch);

    if (ch == '#')
        *T = NULL;
    else {
        *T = (BiThrNode *)malloc(sizeof(BiThrNode));
        (*T)->data = ch;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        (*T)->ltag = Link;
        (*T)->rtag = Link;
        PreCreatBiTree(&(*T)->lchild);
        PreCreatBiTree(&(*T)->rchild);
    }
    
}

// 将一颗二叉树线索化 -- tree是根结点
void InThreading(BiThrTree tree)
{
    if (tree) {
        InThreading(tree->lchild);      // 递归左子树

        /* 中序遍历过程 */
        if (!tree->lchild) {            // 当前结点的左孩子不存在 -- 则lchild指向前驱
            tree->ltag = Thread;        // 打开前驱标签
            tree->lchild = pre;         // 指向前驱
        }
        if (!pre->rchild) {             // 前驱的右孩子不出在 -- 则前驱的rchild指向当前结点
            pre->rtag = Thread;         // 打开后继标签
            pre->rchild = tree;         // 前驱的右孩子指向当前结点
        }
        pre = tree;                     // 当前结点成为下一轮递归的前一个结点

        InThreading(tree->rchild);      // 递归右子树
    }
}

// 创建头结点指向树的根结点
void CreatHead(BiThrNode **head, BiThrTree tree)
{
    *head = (BiThrNode *)malloc(sizeof(BiThrNode));
    (*head)->ltag = Link;
    (*head)->rtag = Thread;
    (*head)->rchild = *head;

    if (!tree)
        (*head)->lchild = *head;
    else {
        (*head)->lchild = tree;
        pre = *head;
    }
}

// 中序遍历线索二叉树并打印二叉树内容 -- head是头结点，其lchild指向一颗二叉树的根结点
void InOrderTraverse_Thr(BiThrTree head)
{
    BiThrTree tree = head->lchild;

    while (tree != head) {                      // tree是空树或遍历结束时退出循环
        while (tree->ltag == Link)              // 找到中序遍历的第一个结点
            tree = tree->lchild;
        printf("%c", tree->data);               // 打印结点数据

        while (tree->rtag == Thread &&          // 如果线索标签打开 -- 寻找后继结点
               tree->rchild != head)
        {
            tree = tree->rchild;
            printf("%c", tree->data);
        }
        tree = tree->rchild;                    // 否则遍历到右孩子
    }
}

int main(void)
{
    BiThrTree tree = NULL;
    BiThrNode *head = NULL;

    // 前序创建二叉树
    puts("请按前序输入二叉树内容：");
    PreCreatBiTree(&tree);

    // 创建指向二叉树的头结点
    CreatHead(&head, tree);

    // 将二叉树线索化 -- 中序线索化
    InThreading(tree);
    // 经历了InThreading后 -- pre此时指向了二叉树的最后一个结点
    pre->rtag = Thread;     // 让最后一个结点的右标签变为线索标签
    pre->rchild = head;     // 让最后一个结点的右孩子指向头结点
    head->rchild = pre;     // 头结点的右孩子指向二叉树的最后一个结点
    
    // 遍历输出二叉树 -- 中序遍历
    InOrderTraverse_Thr(head);

    return 0;
}