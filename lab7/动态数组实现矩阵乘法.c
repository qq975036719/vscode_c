// 矩阵乘法
#include <stdio.h>
#include <stdlib.h>

// 矩阵结构定义
typedef struct {
    int **matrix;   // 矩阵
    int row;        // 行
    int col;        // 列
} Matrix;

// 创建矩阵
void CreateMatrix(Matrix *m)
{
    m->matrix = (int **)malloc(sizeof(int *) * m->row);    // 分配矩阵行的内存空间

    for (int i = 0; i < m->row; i++)                       // 分配矩阵列的内存空间
        m->matrix[i] = (int *)malloc(sizeof(int) * m->col);

    for (int i = 0; i < m->row; i++) {                     // 读入矩阵的数据
        printf("请输入第%d行\n", i + 1);
        for (int j = 0; j < m->col; j++) {
            printf("请输入第%d个数据: ", j + 1);
            scanf("%d", &(m->matrix[i][j]));
            fflush(stdin);                                 // 刷新缓冲区
        }
    }
}

// 打印矩阵
void ShowMatrix(Matrix m)
{
    for (int i = 0; i < m.row; i++) {
        for (int j = 0; j < m.col; j++)
            printf("%d ", m.matrix[i][j]);
        putchar('\n');
    }
}

// 计算矩阵相乘单个元素的结果
// i -- 结果矩阵中的第i行   j -- 结果矩阵中的第j列
int CalcEach(Matrix m1, Matrix m2, int i, int j)
{
    int result = 0;

    for (int k = 0; k < m1.col; k++)
        result += m1.matrix[i][k] * m2.matrix[k][j];
    
    return result;
}

// 矩阵乘法
void MultiMatrix(Matrix m1, Matrix m2, Matrix *res)
{
    // 判断矩阵是否可以相乘
    if (m1.col != m2.row) {
        fprintf(stderr, "您输入的两个矩阵无法相乘！");
        exit(EXIT_FAILURE);
    }
    
    // 获取结果矩阵的行数和列数
    res->row = m1.row;
    res->col = m2.col;

    // 为结果矩阵分配内存空间
    res->matrix = (int **)malloc(sizeof(int *) * res->row);    // 分配矩阵行的内存空间
    for (int i = 0; i < res->row; i++)                       // 分配矩阵列的内存空间
        res->matrix[i] = (int *)malloc(sizeof(int) * res->col);
    
    // 计算矩阵相乘的结果并存储到res结果矩阵中
    for (int i = 0; i < res->row; i++)
        for (int j = 0; j < res->col; j++)
            res->matrix[i][j] = CalcEach(m1, m2, i, j);
}

int main(void)
{
    Matrix m1, m2, res;                                 // 矩阵1，矩阵2，结果矩阵

    // 创建第一个矩阵
    printf("请输入第一个矩阵的行数和列数: ");
    scanf("%d %d", &m1.row, &m1.col);
    fflush(stdin);                                      // 刷新缓冲区
    CreateMatrix(&m1);

    // 创建第二个矩阵
    printf("请输入第二个矩阵的行数和列数: ");
    scanf("%d %d", &m2.row, &m2.col);
    fflush(stdin);                                      // 刷新缓冲区
    CreateMatrix(&m2);

    // 运行矩阵乘法 -- 并将结果存储到结果矩阵中
    MultiMatrix(m1, m2, &res);

    // 输出结果矩阵
    puts("矩阵相乘后的结果：");
    ShowMatrix(res);

    return 0;
}