// 使用指定初始化器
#include <stdio.h>
#define MONTH 12

int main(void)
{
    // 指定初始化器 -- 初始化数组时可以对指定元素初始化
    int days[MONTH] = {28, 31, [4] = 31, 30, 31, 31, [1] = 30};
    for (int i = 0; i < MONTH; i++)
        printf("%2d %5d\n", i, days[i]);
    return 0;
}