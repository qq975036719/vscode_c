// 使用变长数组完成10.13
// 一系列处理函数
#include <stdio.h>
#define ROWS 3
#define COLS 5

int main(void)
{
    // 函数原型
    void save_data(int rows, int cols, double save_ar[rows][cols]);             // 把用户输入的数据存储在3*5的数组中
    double get_line_average(int n, const double ar[n]);                         // 计算每组(5个)数据的平均值
    double get_tot_average(int rows, int cols, const double ar[rows][cols]);    // 计算所有数据的平均值
    double get_max(int rows, int cols, const double ar[rows][cols]);            // 找出这15个数据中的最大值
    void show_arr(int rows, int cols, const double ar[rows][cols]);             // 打印结果
    // 数组声明
    double data[ROWS][COLS];
    // 函数调用
    // 保存数据
    save_data(ROWS, COLS, data);
    // 打印结果
    show_arr(ROWS, COLS, data);

    return 0;
}

 void save_data(int rows, int cols, double save_ar[rows][cols])
 {
    printf("请输入3组数, 每组有5个数字: \n");
    for (int i = 0; i < rows; i++) {
        printf("请输入第%d组数: \n", i+1);
        for (int j = 0; j < cols; j++)
            scanf("%lf", &save_ar[i][j]);
    }
}

double get_line_average(int n, const double ar[n])
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += ar[i];

    return sum / n;
}

double get_tot_average(int rows, int cols, const double ar[rows][cols])
{
    double sum = 0;
    for (int i = 0; i < rows; i++)
        sum += get_line_average(cols, ar[i]);

    return sum / rows;
}

double get_max(int rows, int cols, const double ar[rows][cols])
{
    double max = ar[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (ar[i][j] > max)
                max = ar[i][j];
        }
    }

    return max;
}

void show_arr(int rows, int cols, const double ar[rows][cols])
{
    // 打印用户输入的数组
    printf("您输入的数组的数据如下: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%g\t", ar[i][j]);
        putchar('\n');
    }
    // 打印每行的平均值
    for (int i = 0; i < rows; i++)
        printf("第%d行的平均值为: %g\n", i+1, get_line_average(cols, ar[i]));
    // 打印总的平均值
    printf("总平均值为: %g\n", get_tot_average(rows, cols, ar));
    // 打印最大值
    printf("数组中的最大值为: %g\n", get_max(rows, cols, ar));
}