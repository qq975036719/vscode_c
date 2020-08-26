// min(x, y)函数 -- 返回两个double类型值的较小值。
#include <stdio.h>

int main(void)
{
    double x, y;
    double min(double x, double y);

    printf("请输入两个待比较的数: ");
    scanf("%lf %lf", &x, &y);
    printf("%g", min(x, y));

    return 0;
}

double min(double x, double y)
{
    double min_num = 0.0;
    if (x<y)
        min_num = x;
    else if (x>y)
        min_num = y;

    return min_num;
}