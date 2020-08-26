// 打印数组的值并翻倍
#include <stdio.h>

int main(void)
{
    // 声明数组
    int numbers[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };
    // 函数原型
    void show_arr(int ar[][5], int n);
    void db_arr(int ar[][5], int n);

    // 函数调用
    printf("原数组为: \n");
    show_arr(numbers, 3);
    // 数组翻倍
    db_arr(numbers, 3);
    printf("\n翻倍后的数组为: \n");
    show_arr(numbers, 3);

    return 0;
}

void show_arr(int ar[][5], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++)
            printf("%d\t", ar[i][j]);
        putchar('\n');
    }
}

void db_arr(int ar[][5], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++)
            ar[i][j] *= 2;
    }
}