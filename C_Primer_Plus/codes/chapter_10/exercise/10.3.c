// 函数: 返回存储在int类型数组中的最大值
#include <stdio.h>
#define SIZE 5
int main(void)
{
    int max_ar(int ar[], int n);    // 函数原型
    int array[SIZE] = {52, 33, 60, 45, 88};
    printf("array数组中的最大值为: %d", max_ar(array, SIZE));

    return 0;
}

int max_ar(int ar[], int n)
{
    int max = ar[0];
    for (int i = 1; i < n; i++) {
        if (ar[i] > max)
            max = ar[i];
    }
    
    return max;
}