// 使用for循环创建一个立方表
#include <stdio.h>

int main(void)
{
    printf("    n   n cubed\n");
    for (int num = 1; num <= 6; num++)
        printf("%5d %9d\n", num, num * num * num);

    getchar();
    return 0;
}