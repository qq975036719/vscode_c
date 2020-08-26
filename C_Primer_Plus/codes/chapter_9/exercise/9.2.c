// 函数 -- chline(ch, i, j) -- 打印指定的字符j行i列
#include <stdio.h>

int main(void)
{
    void chline(char ch, int i, int j);
    char ch;
    int i, j;
    
    // 读入打印数据
    printf("请输入字符: ");
    scanf("%c", &ch);
    printf("请输入要打印的行数: ");
    scanf("%d", &i);
    printf("请输入要打印的列数: ");
    scanf("%d", &j);

    // 打印字符
    chline(ch, i, j);

    return 0;
}

void chline(char ch, int i, int j)
{
    int row, col;
    for (row = 0; row < i;row++) {
        for (col = 0; col < j; col++)
            printf("%c ", ch);
        putchar('\n');
    }
}