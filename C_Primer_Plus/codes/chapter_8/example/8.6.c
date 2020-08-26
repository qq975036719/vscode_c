// 按指定的行列打印字符
#include <stdio.h>

int main(void)
{
    int rows, cols;     // 行数和列数
    char ch;
    void showchar(char ch, int rows, int cols);      // 声明原型
    printf("请输入一个字符和两个数字: ");
    while ((ch = getchar()) != '\n') {
        if (scanf("%d %d", &rows, &cols) != 2)
            break;
        else {
            showchar(ch, rows, cols);
            while (getchar() != '\n')       // 跳过剩余的输入
                continue;
        }
        printf("请输入一个字符和两个数字: ");
    }
    return 0;
}

void showchar(char ch, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%c ", ch);
        putchar('\n');      // 每行结束后换行
    }
}