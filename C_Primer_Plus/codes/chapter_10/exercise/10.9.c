// 用处理变长数组的函数来拷贝数组和打印数组
#include <stdio.h>

int main(void)
{
    // 声明数组
    double source[3][5] = {
        {1.1, 2.2, 3.3, 4.4, 5.5},
        {6.6, 7.7, 8.8, 9.9, 10.10},
        {11.11, 12.12, 13.13, 14.14, 15.15}
    };
    double target[3][5];
    // 函数原型
    // 复制函数
    void copy_arr(int rows, int cols,
                  double source[rows][cols], double target[rows][cols]);
    // 打印函数
    void show_arr(int rows, int cols, double ar[rows][cols]);
    // 调用函数
    copy_arr(3, 5, source, target);
    show_arr(3, 5, target);

    return 0;
}

void copy_arr(int rows, int cols,
                  double source[rows][cols], double target[rows][cols])
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            target[i][j] = source[i][j];
    }
}

void show_arr(int rows, int cols, double ar[rows][cols])
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%g\t", ar[i][j]);
        putchar('\n');
    }
}