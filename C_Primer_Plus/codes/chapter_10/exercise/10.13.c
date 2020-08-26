// 一系列处理函数
#include <stdio.h>
#define ROWS 3
#define COLS 5

int main(void)
{
    // 函数原型
    void save_data(double save_ar[][COLS], int rows);             // 把用户输入的数据存储在3*5的数组中
    double get_line_average(const double ar[], int n);            // 计算每组(5个)数据的平均值
    double get_tot_average(const double ar[][COLS], int rows);    // 计算所有数据的平均值
    double get_max(const double ar[][COLS], int rows);            // 找出这15个数据中的最大值
    void show_arr(const double ar[][COLS], int rows,              // 打印结果
                  double *line_average, double tot_average, double max); 
    // 数组声明
    double data[ROWS][COLS];
    double line_average[ROWS];
    // 变量声明
    double tot_average;
    double max;
    // 函数调用
    // 保存数据
    save_data(data, ROWS);
    // 计算每行平均值
    for (int i = 0; i < ROWS; i++)
        line_average[i] = get_line_average(data[i], COLS);
    // 计算所有数据的平均值
    tot_average = get_tot_average(data, ROWS);
    // 找出data数组中的最大值
    max = get_max(data, ROWS);
    // 打印结果
    show_arr(data, ROWS, line_average, tot_average, max);

    return 0;
}

 void save_data(double save_ar[][COLS], int rows)
 {
    printf("请输入3组数, 每组有5个数字: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++)
            scanf("%lf", &save_ar[i][j]);
    }
}

double get_line_average(const double ar[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += ar[i];

    return sum / n;
}

double get_tot_average(const double ar[][COLS], int rows)
{
    double sum = 0;
    for (int i = 0; i < rows; i++)
        sum += get_line_average(ar[i], COLS);

    return sum / rows;
}

double get_max(const double ar[][COLS], int rows)
{
    double max = ar[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (ar[i][j] > max)
                max = ar[i][j];
        }
    }

    return max;
}

void show_arr(const double ar[][COLS], int rows, double *line_average, double tot_average, double max)
{
    // 打印用户输入的数组
    printf("您输入的数组的数据如下: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%g\t", ar[i][j]);
        putchar('\n');
    }
    // 打印每行的平均值
    for (int i = 0; i < rows; i++)
        printf("第%d行的平均值为: %g\n", i+1, *(line_average+i));
    // 打印总的平均值
    printf("总平均值为: %g\n", tot_average);
    // 打印最大值
    printf("数组中的最大值为: %g\n", max);
}