// 函数: 用于改变参数的位置, 其中参数按从小到大排序
#include <stdio.h>

int main(void)
{
    void change_para(double *, double *, double *);
    double x, y, z;
    printf("请输入三个数字: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("%g %g %g从小到大排序为: ", x, y, z);
    change_para(&x, &y, &z);
    printf("%g %g %g", x, y, z);

    return 0;
}

void change_para(double * x, double * y, double * z)
{
    double temp;
    if (*x > *y) {
        temp = *x;
        *x = *y;
        *y = temp;
    }
    if (*x > *z) {
        temp = *x;
        *x = *z;
        *z = temp;
    }
    if (*y > *z) {
        temp = *y;
        *y = *z;
        *z = temp;
    }
}