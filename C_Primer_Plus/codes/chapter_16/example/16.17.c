// 用库函数qsort排序一组数字
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 40

void fillarray(double ar[], int n);
void show_array(const double ar[], int n);
int mycomp(const void *, const void *);         // 从小到大排序数字
int mycomp2(const void *p1, const void *p2);    // 排序姓名

struct names {
    char first[40];
    char last[40];
};
struct names stuff[100] = {
    {"Fuck", "Jack"},
    {"Alan", "Fucker"},
    {"Blan", "Hihi"},
    {"Cici", "Sist"}};

int main(void)
{
    double ar[NUM];

    fillarray(ar, NUM);
    puts("Random list:");
    show_array(ar, NUM);

    qsort(ar, NUM, sizeof(double), mycomp);
    puts("\nSorted list:");
    show_array(ar, NUM);

    qsort(stuff, 4, sizeof(struct names), mycomp2);
    printf("Sorted names:\n");
    for (int i = 0; i < 4; i++)
        printf("%s %s\n", stuff[i].first, stuff[i].last);

    system("pause");
    return 0;
}

void fillarray(double ar[], int n)
{
    for (int i = 0; i < n; i++)
        ar[i] = (double)rand() / ((double)rand() + 0.1);
}

void show_array(const double ar[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%9.4f", ar[i]);
        if (i % 6 == 5)
            putchar('\n');
    }
    if (i % 6 != 0)
        putchar('\n');
}

int mycomp(const void * p1, const void * p2)
{
    const double *a1 = (const double *)p1;
    const double *a2 = (const double *)p2;

    if (*a1 > *a2)
        return -1;
    else if (*a1 == *a2)
        return 0;
    else
        return 1;
}

int mycomp2(const void *p1, const void *p2)
{
    const struct names *a1 = (const struct names *)p1;
    const struct names *a2 = (const struct names *)p2;

    int res = strcmp(a1->first, a2->first);
    if (res != 0)
        return res;
    else
        return strcmp(a1->last, a2->last);
}