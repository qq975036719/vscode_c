// 数组元素之和
#include <stdio.h>
#define SIZE 10

int main(void)
{
    int sum(int ar[], int n);   // 函数原型 -- 用数组ar[]表示指针
    int numbers[SIZE] = {10, 20, 22, 29, 16, 30, 15, 45, 30, 33};
    long answer = sum(numbers, SIZE);
    printf("数组的所有元素之和为: %ld\n", answer);
    printf("数组的大小为: %lu\n", sizeof(numbers));

    return 0;
}

int sum(int ar[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += ar[i];
    printf("函数sum(int ar[], int n)的第一个形参的大小为: %lu\n",
           sizeof(ar));
    return total;
}