// 重写10.7的程序 -- main()中的任务都用函数完成
// 拷贝二维数组
#include <stdio.h>
#define ROWS 2
#define COLS 3

int main(void)
{
    // 函数原型
    void copy_arr(double ar1[], double source[], int n);        // 一维数组的复制
    void copy_2d_arr(double ar_2d[][COLS], double source[][COLS], int n);     // 二维数组的复制
    void show_arr(int rows, int cols, double ar[rows][cols]);   // 打印二维数组内容
    
    // 数组声明
    double source[ROWS][COLS] = {{1.22, 3.14, 15.92}, {6.16, 0.35, 9.99}};
    double target1[ROWS][COLS];
    // 调用二维数组复制函数
    copy_2d_arr(target1, source, ROWS);
    // 打印target1的元素
    show_arr(ROWS, COLS, target1);

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

void show_arr(int rows, int cols, double ar[rows][cols])
{
    for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                printf("%g  ", ar[i][j]);
            putchar('\n');
        }
}