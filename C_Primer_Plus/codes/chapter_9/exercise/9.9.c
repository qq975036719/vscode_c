// 函数: 计算一个数的整数次幂(包括整数和负数) -- 递归实现
#include <stdio.h>

int main(void)
{
    double power(double base, int index);   // 函数原型
    double base, xpower;
    int index;
    printf("请输入底数和指数: ");
    while (scanf("%lf %d", &base, &index) == 2) {
        xpower = power(base, index);
        printf("%g的%d次幂 = %g\n", base, index, xpower);
        printf("请输入底数和指数: ");
    }
    return 0;
}

double power(double base, int index)
{
    double answer = 1;
    // 指数 > 0
    if (base != 0 && index > 0) {
        answer = base * power(base, index - 1);
    }
    // 指数 < 0
    else if (base != 0 && index < 0) {
        answer *= power(base, (index + 1) / 2);
    }
    // 底数 == 0
    else if (base == 0 && index != 0)
        answer = 0;
    // 指数 == 0
    else if (index == 0 && base != 0)
        answer = 1;
    // 底数、指数都为0
    else if (index == 0 && base == 0) {
        printf("0的0次幂的情况未定义, 这里将这种情况处理为1!\n");
    }
    return answer;
}