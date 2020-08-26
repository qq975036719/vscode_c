// 天数转换成周数和天数
#include <stdio.h>
#define DAY_PER_WEEK 7
int main(void)
{
    int days, weeks, left;
    // const创建
    // const int DAY_PER_WEEK = 7;
    printf("请输入天数: ");
    scanf("%d", &days);

    weeks = days / DAY_PER_WEEK;
    left = days % DAY_PER_WEEK;
    printf("%d days are %d weeks, %d days", days, weeks, left);

    getchar();
    getchar();
    return 0;
}