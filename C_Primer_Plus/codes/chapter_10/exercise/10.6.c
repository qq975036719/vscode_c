// 将double类型数组中的数据倒序排列(从大到小排列)
#include <stdio.h>

int main(void)
{
    double numbers[6] = {51, 23, 66, 92, 15, 36};
    void r_sort(double numbers[], int n);
    
    // 排序前
    printf("排序前的数组如下:\n");
    for (int i = 0; i < 6; i++)
        printf("%g  ", numbers[i]);
    putchar('\n');
    // 排序
    r_sort(numbers, 6);
    // 排序后
    printf("排序后的数组如下:\n");
    for (int i = 0; i < 6; i++)
        printf("%g  ", numbers[i]);

    return 0;
}

void r_sort(double ar[], int n)
{
    double temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (ar[j] < ar[j + 1]) {
                temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
}