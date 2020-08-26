// 用库函数qsort排序一组数字
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 40

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
    qsort(stuff, 4, sizeof(struct names), mycomp2);
    printf("Sorted names:\n");
    for (int i = 0; i < 4; i++)
        printf("%s %s\n", stuff[i].first, stuff[i].last);

    system("pause");
    return 0;
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