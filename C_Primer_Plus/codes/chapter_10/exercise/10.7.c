// 拷贝二维数组
#include <stdio.h>
#define ROWS 2
#define COLS 3
int main(void)
{
    void copy_arr(double ar1[], double source[], int n);        // 一维数组的复制
    void copy_2d_arr(double ar_2d[][COLS], double source[][COLS], int n);     // 二维数组的复制
    double source[ROWS][COLS] = {{1.22, 3.14, 15.92}, {6.16, 0.35, 9.99}};
    double target1[ROWS][COLS];
    // 调用二维数组复制函数
    copy_2d_arr(target1, source, ROWS);
    // 打印target1的元素
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%g  ", target1[i][j]);
        putchar('\n');
    }

    return 0;
}

void copy_arr(double ar1[], double source[], int n)
{
    for (int i = 0; i < n; i++)
        ar1[i] = source[i];
}

void copy_2d_arr(double ar_2d[][COLS], double source[][COLS], int n)
{
    for (int i = 0; i < n; i++)
        copy_arr(ar_2d[i], source[i], COLS);
}