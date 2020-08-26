// 函数: 返回存储在double类型数组中最大值的下标
#include <stdio.h>
#define SIZE 7

int main(void)
{
    int get_index(double ar[], int n);
    double numbers[SIZE] = {1.1, 2.2, 3.5, 1.8, 9.4, 1.7, 6.6};
    printf("数组中最大值的下标为: %d\n", get_index(numbers, SIZE));

    return 0;
}

int get_index(double ar[], int n)
{
    int max_index = 0;
    int temp = ar[0];
    for (int i = 0; i < n; i++) {
        if (ar[i] > temp) {
            temp = ar[i];
            max_index = i;
        }
    }
    
    return max_index;
}