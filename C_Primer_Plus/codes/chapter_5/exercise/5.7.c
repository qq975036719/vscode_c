// 打印输入数字的立方值
#include <stdio.h>

int main(void)
{
    double cube(double a);
    double num;
    printf("请输入一个数字: ");
    scanf("%lf", &num);
    cube(num);

    getchar();
    getchar();
    return 0;
}

double cube(double a)
{
    double t = a * a * a;
    printf("%.2lf", t);
    
    return t;
}
