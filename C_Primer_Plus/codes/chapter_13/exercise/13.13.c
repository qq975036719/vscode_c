// 用变长数组完成13.12
// 数字转图片程序
#include <stdio.h>
#include <stdlib.h>
#define ROW 20
#define COL 30

void get_data(FILE *fp, int row, int col, int ar[row][col]);
void write_data(FILE *fp, int row, int col, int ar[row][col]);
char symbol[] = {' ', '.', '\'', '\"', '^', '*', '%', '$', '@', '#'};

int main(void)
{
    FILE *f_in, *f_out;
    char in_name[] = "data.txt";
    char out_name[] = "output.txt";
    int data[ROW][COL];

    // 打开文件
    if ((f_in = fopen(in_name, "r")) == NULL) {
        fprintf(stderr, "打开文件%s失败", in_name);
        exit(EXIT_FAILURE);
    }
    if ((f_out = fopen(out_name, "w")) == NULL) {
        fprintf(stderr, "打开文件%s失败", out_name);
        exit(EXIT_FAILURE);
    }

    // 读取数据
    get_data(f_in, ROW, COL, data);

    // 写入数据
    write_data(f_out, ROW, COL, data);

    fclose(f_in);
    fclose(f_out);

    return 0;
}

void get_data(FILE *fp, int row, int col, int ar[row][col])
{
    // 读取输入文件到数组data中
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++)
                fscanf(fp, "%d", &ar[i][j]);
        }
}

void write_data(FILE *fp, int row, int col, int ar[row][col])
{
    // 把数组data中的数据转换成字符
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c", symbol[ar[i][j]]);
            fprintf(fp, "%c", symbol[ar[i][j]]);
        }
        putchar('\n');
        fprintf(fp, "\n");
    }
}