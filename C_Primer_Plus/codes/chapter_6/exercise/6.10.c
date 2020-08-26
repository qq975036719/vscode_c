// 计算一个范围内的平方和
#include <stdio.h>

int main(void)
{
    int x, y, i, sum;
    printf("该程序会计算上限和下限整数之间的整数平方和\n");
    printf("请输入下限和上限: ");
    scanf("%d %d", &x, &y);
    while (x < y) {
        sum = 0;
        for (i = x; i <= y; i++)
            sum += i * i;
        printf("%d 到 %d之间的整数平方和为: %d\n", x, y, sum);
        printf("请输入下限和上限: ");
        scanf("%d %d", &x, &y);
    }
    printf("程序已退出！");

    return 0;
}