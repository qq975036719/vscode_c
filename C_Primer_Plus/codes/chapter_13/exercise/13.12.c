// 数字转图片程序
#include <stdio.h>
#include <stdlib.h>
#define ROW 20
#define COL 30

int main(void)
{
    FILE *f_in, *f_out;
    char in_name[] = "data.txt";
    char out_name[] = "output.txt";
    char symbol[] = {' ', '.', '\'', '\"', '^', '*', '%', '$', '@', '#'};
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

    // 读取输入文件到数组data中
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            fscanf(f_in, "%d", &data[i][j]);
    }

    // 把数组data中的数据转换成字符
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c", symbol[data[i][j]]);
            fprintf(f_out, "%c", symbol[data[i][j]]);
        }
        putchar('\n');
        fprintf(f_out, "\n");
    }

    fclose(f_in);
    fclose(f_out);

    return 0;
}