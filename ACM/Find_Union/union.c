// 合并
#include <stdio.h>
#define MAXN 100

// 数组
int fa[MAXN];

// 原型
void makeSet(int size);
void unionSet(int x, int y);
int find(int x);

// 主函数
int main(void)
{
    makeSet(MAXN);
    int x = 3;
    int y = 4;
    unionSet(x, y);
    printf("x=%d, y=%d", x, y);

    return 0;
}

// 函数定义
void makeSet(int size)
{
    for (int i = 0; i < size; i++)
        fa[i] = i;
}

int find(int x)
{
    if (fa[x] == x)
        return x;
    else
        return (find(fa[x]));
}

void unionSet(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y)
        return;
    fa[x] = y;
}