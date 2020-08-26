#include <stdio.h>
#include <stdlib.h>

// 多项式结构定义
typedef struct pnode{
    int coef;       // 系数
    int exp;        // 指数
    struct pnode *next;
} poly;
typedef poly MultiPoly;

// 初始化多项式
void InitList(MultiPoly *P)
{
    P->coef = 0;
    P->exp = 0;
    P->next = NULL;
}

// 清空多项式
void DestroyList(MultiPoly *P)
{
    poly *pl, *temp;

    pl = P->next;
    while (pl) {
        temp = pl;
        pl = pl->next;
        free(temp);
    }
}

// 打印多项式
void ShowList(MultiPoly P)
{
    poly *scan = P.next;

    if (scan)
        printf("%dx^%d", scan->coef, scan->exp);
    scan = scan->next;

    while (scan) {
        if (scan->coef > 0)
            printf("+");
        printf("%dx^%d", scan->coef, scan->exp);
        scan = scan->next;
    }
}

// 给空多项式赋值
void CreatePoly(MultiPoly *P, int n, int coef[], int exp[])
{
    poly *pl = P;

    for (int i = 0; i < n; i++) {
        poly *new_poly = (poly *)malloc(sizeof(poly));
        
        new_poly->coef = coef[i];
        new_poly->exp = exp[i];
        new_poly->next = NULL;
        
        pl->next = new_poly;
        pl = new_poly;
    }
}

// 合并多项式
void MergePoly(MultiPoly *Polya, MultiPoly Polyb)
{
    poly *pa, *pb, *pre, *temp;

    pa = Polya->next;
    pb = Polyb.next;
    pre = pa;

    while (pa && pb) {
        // a项的指数比b项小
        if (pa->exp < pb->exp) {
            pre = pa;
            pa = pa->next;
        }
        // a项的指数比b项大
        else if (pa->exp > pb->exp) {
            pre->next = pb;     // a的前一项的下一项指向b
            pre = pb;           // 此时的b成为了a的前一项
            temp = pb->next;    // 用于b的下一项指向a后, b可以指向下一项
            pb->next = pa;      // b的下一项指向a
            pb = temp;          // b指向下一项
        }
        // a项的指数和b项相等
        else {
            pa->coef += pb->coef;
            if (pa->coef == 0) {     // 合并后系数为0
                pre->next = pa->next;
                temp = pa;
                pa = pa->next;
                pb = pb->next;
                free(temp);
            }
            else {                  // 合并后系数不为0
                pre = pa;
                pa = pa->next;
                pb = pb->next;
            }
        }
    }
    if (pb)
        pre->next = pb;
}

int main(void)
{
    int coef_a[4] = {5, -10, -5, 8};
    int exp_a[4] = {0, 3, 6, 9};
    int coef_b[5] = {2, 10, 3, 7, 1};
    int exp_b[5] = {2, 3, 6, 8, 10};

    poly a, b;
    InitList(&a);
    InitList(&b);

    CreatePoly(&a, 4, coef_a, exp_a);
    CreatePoly(&b, 5, coef_b, exp_b);

    puts("合并前：");
    printf("poly a: ");
    ShowList(a);
    printf("\npoly b: ");
    ShowList(b);

    MergePoly(&a, b);
    puts("\n合并后：");
    printf("The sum: ");
    ShowList(a);

    DestroyList(&a);
    DestroyList(&b);
    
    return 0;
}