// 打印超出系统允许的最大值会发生什么？
#include <stdio.h>
int main(void)
{
    int i = 2147483647;
    unsigned int j = 4294967295;

    printf("%d, %d, %d\n", i, i + 1, i + 2);
    printf("%u, %u, %u\n", j, j + 1, j + 2);

    getchar();
    return 0;
}