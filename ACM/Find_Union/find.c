// 了解并查集
#include <stdio.h>
#define MAXN 100

// 数组
int fa[MAXN];

// 原型
void makeSet(int size);
int find(int x);

// 主函数
int main(void)
{
    makeSet(MAXN);
    printf("%d", find(4));

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