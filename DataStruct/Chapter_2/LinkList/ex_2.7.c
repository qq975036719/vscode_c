// 一元多项式加法
#include <stdio.h>
#include <stdlib.h>

// 定义一元多项式的结构
typedef struct node {
    float           coef;       // 系数
    int             expn;       // 指数
    struct node     *next;
} Node;
typedef Node *Polynomial;

// 多项式初始化
void InitPoly(Polynomial *P)
{
    Node *head = (Node *)malloc(sizeof(Node));      // 头结点
    head->next = NULL;                              // 初始化头结点指向NULL
    (*P) = head;                                    // 指向头结点
}

// 添加一个元素到多项式的末尾 -- 尾插法
void CreateList_Tail(Polynomial *P, int n)
{
    Node *p = (*P);

    for (int i = 0; i < n; i++) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL)
            printf("创建新结点失败！\n");
        else {
            new_node->next = NULL;
            printf("第%d项：请输入多项式系数和指数：", i + 1);
            scanf("%f %d", &(new_node->coef), &(new_node->expn));
        }
        p->next = new_node;
        p = new_node;
    }
}

// 输出多项式中的每一项的系数和指数
void TraverseList(Polynomial P)
{
    int i = 0;
    Node *p = P->next;      // 指向第一个结点

    while (p) {
        printf("(%g, %d)      ", p->coef, p->expn);
        p = p->next;
        i++;
        if ((i+1) % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
}

void AddPolyn(Polynomial *a, Polynomial b)
{
    Node *pa, *pb, *pre, *temp;

    pa = (*a)->next;        // 指向a的第一个结点
    pb = b->next;           // 指向b的第一个结点
    pre = (*a);             // 指向a的头结点

    while (pa && pb) {
        if (pa->expn < pb->expn) {
            pre = pa;
            pa = pa->next;
        }
        else if (pa->expn > pb->expn) {
            temp = pb->next;
            pb->next = pa;
            pre->next = pb;
            pre = pb;
            pb = temp;
        }
        else {
            pa->coef += pb->coef;
            if (pa->coef == 0) {
                pre->next = pa->next;
                free(pa);
            }
            else
                pre = pa;
            pa = pre->next;
            temp = pb;
            pb = pb->next;
            free(temp);
        }
    }
    if (pb != NULL)
        pre->next = pb;
    free(b);
}

// 测试一元多项式合并
int main(void)
{
    Polynomial a, b;
    int na, nb;

    // 初始化多项式
    InitPoly(&a);
    InitPoly(&b);

    // 读入多项式的系数和指数
    printf("请输入第一个多项式的项数：");
    scanf("%d", &na);
    CreateList_Tail(&a, na);
    printf("请输入第二个多项式的项数：");
    scanf("%d", &nb);
    CreateList_Tail(&b, nb);

    // 打印创建好的多项式
    printf("\n第一个多项式的系数和指数如下：");
    TraverseList(a);
    printf("\n第二个多项式的系数和指数如下：");
    TraverseList(b);
    
    // 合并多项式
    AddPolyn(&a, b);
    printf("\n              合并后的多项式：");
    TraverseList(a);

    puts("Done!");

    return 0;
}