// 函数: 返回存储在double类型数组中的最大值和最小值的差值
#include <stdio.h>

int main(void)
{
    double get_differ(double ar[], int n);
    double numbers[5] = {55.53, 47.97, 95.56, 102.12, 66.99};
    printf("数组中最大值和最小值的差值为: %.2lf\n", get_differ(numbers, 5));

    return 0;
}

double get_differ(double ar[], int n)
{
    double max = ar[0];
    double min = ar[0];
    for (int i = 0; i < n; i++)
    {
        if (ar[i] > max)
            max = ar[i];
        if (ar[i] < min)
            min = ar[i];
    }
    
    return max - min;
}