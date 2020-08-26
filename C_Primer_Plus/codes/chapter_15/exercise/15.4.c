// 返回指定位的值
#include <stdio.h>

void index_num(int n, int index)
{
    if (1 & (n>>=index))
        printf("1");
    else
        printf("0");
}

int main(void)
{
    int n, index;

    scanf("%d %d", &n, &index);
    index_num(n, index);

    return 0;
}