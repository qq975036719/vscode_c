#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int row;        // 行
    int col;        // 列
    double *data;      // 矩阵数组
} Matrix;

// 矩阵初始化 -- 初始化后是一个零矩阵
Matrix * InitMatrix(Matrix *m, int row, int col)
{
    m = (Matrix *)malloc(sizeof(Matrix));               // 为矩阵动态分配内存
    if (m == NULL) {
        fprintf(stderr, "矩阵初始化失败！\n");
        exit(EXIT_FAILURE);
    }
    m->row = row;
    m->col = col;
    m->data = (double *)malloc(sizeof(double) * row * col);   // 为矩阵数组动态分配内存
    if (m->data == NULL) {
        fprintf(stderr, "矩阵初始化失败！\n");
        exit(EXIT_FAILURE);
    }
    memset(m->data, 0, sizeof(double) * row * col);           // 将矩阵数组的值全部设为0 -- 即零矩阵

    return m;
}

// 给一个初始化的矩阵赋值
void AssignMatrix(Matrix *m, double ar[])
{
    if (m)
        memcpy(m->data, ar, sizeof(double) * m->row * m->col);
    else
        fprintf(stderr, "矩阵不存在！");
}

// 打印矩阵
void ShowMatrix(Matrix *m)
{
    for (int i = 0; i < m->row * m->col; i++) {
        printf("%g ", m->data[i]);
        if ((i+1) % m->col == 0)
            putchar('\n');
    }
    putchar('\n');
}

// 初等行变换 -- 交换两行
void SwapLines(Matrix *m, int row1, int row2)
{
    double *row1_ar = (double *)malloc(sizeof(double) * m->col);
    double *row2_ar = (double *)malloc(sizeof(double) * m->col);
    int index = 0;

    // 将row1行的数据存储到row1_ar数组中
    for (int i = m->col * (row1 - 1); i < m->col * row1; i++)
        row1_ar[index++] = m->data[i];
    index = 0;

    // 将row2行的数据存储到row2_ar数组中
    for (int i = m->col * (row2 - 1); i < m->col * row2; i++)
        row2_ar[index++] = m->data[i];
    index = 0;

    // 再将row1_ar数组中的数据赋值到row2行中
    for (int i = m->col * (row2 - 1); i < m->col * row2; i++)
        m->data[i] = row1_ar[index++];
    index = 0;

    // 再将row2_ar数组中的数据赋值到row1行中
    for (int i = m->col * (row1 - 1); i < m->col * row1; i++)
        m->data[i] = row2_ar[index++];
    
    free(row1_ar);
    free(row2_ar);
}

// 初等行变换 -- 某一行乘以k倍
void MultLine(Matrix *m, int row, double k)
{
    for (int i = m->col * (row - 1); i < m->col * row; i++)
        m->data[i] *= k;
}

// 初等行变换 -- 某一行乘以k倍加到另一行上去
/*
    m        --  矩阵
    src_row  --  乘以k倍的那行
    k        --  乘以的倍数
    dest_row --  src_row * k 后要加上去的目标行
*/
void MultAddLine(Matrix *m, int src_row, double k, int dest_row)
{
    double *src_ar = (double *)malloc(sizeof(double) * m->col);
    int index = 0;

    for (int i = m->col * (src_row - 1); i < m->col * src_row; i++)
        src_ar[index++] = m->data[i] * k;
    index = 0;

    for (int i = m->col * (dest_row - 1); i < m->col * dest_row; i++)
        m->data[i] += src_ar[index++];
}

// 测试矩阵的初等行变换
int main(void) {
    Matrix *m = NULL;
    double test_ar[9] = {
        1, 2, 3,
        2, 2, 1,
        4, 3, 1
    };

    // 矩阵初始化和赋值
    m = InitMatrix(m, 3, 3);
    AssignMatrix(m, test_ar);

    // 进行初等行变换后打印结果
    puts("原矩阵：");
    ShowMatrix(m);
    
    // 交换两行
    puts("交换第一行和第二行后：");
    SwapLines(m, 1, 2);
    ShowMatrix(m);
    AssignMatrix(m, test_ar);       // 重置矩阵

    // 某一行乘以k倍
    puts("第二行乘以3倍后：");
    MultLine(m, 2, 3);
    ShowMatrix(m);
    AssignMatrix(m, test_ar);       // 重置矩阵

    // 某一行乘以k倍加到另一行上去
    puts("第一行乘以3倍加到第三行上去后：");
    MultAddLine(m, 1, 3, 3);
    ShowMatrix(m);
    AssignMatrix(m, test_ar);       // 重置矩阵

    return 0;
}