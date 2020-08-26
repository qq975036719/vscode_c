// 处理数组的函数
#include <stdio.h>
#define SIZE 5

int main(void)
{
    void show_array(const double ar[], int n);   // 打印数组的元素
    void mult_array(double ar[], int n, double mult);   // 令数组每个元素乘以一个数
    double numbers[SIZE] = {20.0, 17.66, 8.2, 15.3, 22.22};
    printf("原数组为: \n");
    show_array(numbers, SIZE);
    printf("修改后的数组为: \n");
    mult_array(numbers, SIZE, 2.5);
    show_array(numbers, SIZE);
}

void show_array(const double ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%8.2lf", ar[i]);
        // printf("%.2lf", *(ar + i))   -- 使用指针表示也可以
    putchar('\n');
}

void mult_array(double ar[], int n, double mult)
{
    for (int i = 0; i < n; i++)
        ar[i] *= mult;
        // *(ar + i) *= mult    -- 使用指针表示也可以
}