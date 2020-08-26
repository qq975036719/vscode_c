// 处理二维数组的函数
#include <stdio.h>
#define ROWS 3
#define COLS 4

int main(void)
{
    void sum_rows(int ar[][COLS], int rows);     // 函数原型
    void sum_cols(int ar[][COLS], int rows);     // 函数原型
    int sum2d(int ar[][COLS], int rows);         // 函数原型

    int junk[ROWS][COLS] = {
        {2, 4, 6, 8},
        {3, 5, 7, 9},
        {12, 10, 8, 6}
    };

    sum_rows(junk, ROWS);
    sum_cols(junk, ROWS);
    printf("所有元素的总和 = %d\n", sum2d(junk, ROWS));

    return 0;
}

void sum_rows(int ar[][COLS], int rows)
{
    int tot_r = 0;
    for (int i = 0; i < rows; i++) {
        tot_r = 0;
        for (int j = 0; j < COLS; j++)
            tot_r += ar[i][j];
        printf("第 %d 行的所有元素总和 = %d\n", i, tot_r);
    }
}

void sum_cols(int ar[][COLS], int rows)
{
    int tot_c = 0;
    for (int j = 0; j < COLS; j++) {
        tot_c = 0;
        for (int i = 0; i < rows; i++)
            tot_c += ar[i][j];
        printf("第 %d 列的所有元素总和 = %d\n", j, tot_c);
    }
}

int sum2d(int ar[][COLS], int rows)
{
    int total = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++)
            total += ar[i][j];
    }

    return total;
}