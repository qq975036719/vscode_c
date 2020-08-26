// 计算调和平均数的函数 -- harmonic(int a, int b)
#include <stdio.h>

int main(void)
{
    double a, b;
    double harmonic(double a, double b);
    printf("请输入两个数字(不能为0): ");
    scanf("%lf %lf", &a, &b);
    while (a == 0 || b == 0) {
        printf("您输入的数字中有0, 请输入两个不为0的数字: ");
        scanf("%lf %lf", &a, &b);
    }
    printf("%g和%g的调和平均数为: %g", a, b, harmonic(a, b));

    return 0;
}

double harmonic(double a, double b)
{
    double res;
    res = 1 / ((1 / a + 1 / b) / 2);
    
    return res;
}