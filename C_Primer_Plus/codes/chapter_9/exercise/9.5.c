// 函数 larger_of(x, y) -- 把较大的值赋值
#include <stdio.h>

int main(void)
{
    double x, y;
    double larger_of(double *, double *);
    printf("请输入两个数字: ");
    scanf("%lf %lf", &x, &y);

    printf("两个数字中较大的是%g\n", larger_of(&x, &y));
    printf("且现在x=%g, y=%g", x, y);
    
    return 0;
}

double larger_of(double * x, double * y)
{
    double bigger;
    if (*x > *y) {
        *y = *x;
        bigger = *x;
    }
    else {
        *x = *y;
        bigger = *y;
    }

    return bigger;
}