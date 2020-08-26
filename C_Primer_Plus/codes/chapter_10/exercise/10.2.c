// 数组拷贝函数
#include <stdio.h>

int main(void)
{
    // 函数原型
    void copy_arr(double ar1[], double source[], int n);
    void copy_ptr(double *ar2, double *sourece, int n);
    void copy_ptrs(double *ar3, double *s_first, double *s_last);

    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    // 打印target1的元素
    for (int i = 0; i < 5; i++)
        printf("%.1f\t", target1[i]);
    putchar('\n');
    // 打印target2的元素
    for (int i = 0; i < 5; i++)
        printf("%.1f\t", target2[i]);
    putchar('\n');
    // 打印target3的元素
    for (int i = 0; i < 5; i++)
        printf("%.1f\t", target3[i]);
    putchar('\n');
}

void copy_arr(double ar1[], double source[], int n)
{
    for (int i = 0; i < n; i++)
        ar1[i] = source[i];
}

void copy_ptr(double *ar2, double *source, int n)
{
    for (int i = 0; i < n; i++)
        *(ar2 + i) = *(source + i);
}

void copy_ptrs(double *ar3, double *s_first, double *s_last)
{
    for (int i = 0; i < (s_first - s_last); i++)
        *(ar3 + i) = *(s_first + i);
}