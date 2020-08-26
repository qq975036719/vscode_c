// 数据上溢、下溢的情况
#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(void)
{
    int i = 2147483647;
    int j = -2147483648;
    float a = 3.402823e+038;
    float b = -1.175494e-038;

    printf("%d, %d, %d, %d\n", i, i + 1, j - 1, j - 2);
    // 整数上溢：从最小值开始循环递增
    // 整数下溢：从最大值开始循环递减
    //printf("%d, %d\n", INT_MAX, INT_MIN);

    printf("%e\n", a * 100);
    printf("%e\n", b / 100);
    // 浮点数上溢：显示INF
    // 浮点数下溢：丢失精度
    //printf("%e, %e", FLT_MAX, FLT_MIN);


    getchar();

    return 0;
}