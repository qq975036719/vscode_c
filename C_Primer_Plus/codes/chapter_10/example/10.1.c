// 初始化一维数组 -- 打印每个月的天数
#include <stdio.h>
#define MONTH 12    // 每年的月数

int main(void)
{
    int days[MONTH] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index;

    for (index = 0; index < MONTH; index++) {
        printf("%d月有%d天\n", index + 1, days[index]);
    }
    return 0;
}