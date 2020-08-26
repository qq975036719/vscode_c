#include <stdio.h>

int main()
{
    char ch;
    const char init = 'A';  // 金字塔顶层的字母 -- A
    
    // 用户输入字母
    printf("请输入一个字母(作为金字塔底层): ");
    scanf("%c", &ch);

    // 创建循环所需的变量
    int rows, row, space; /* rows -- 总行数
                             row -- 当前循环的行数
                             space -- 空格数 */

    // 计算总行数
    rows = ch - init + 1;

    // 循环行数
    // row从1开始计数，方便后面变量的计算
    for (row = 1; row <= rows; row++) {
        // 循环空格数 -- rows == row + space
        for (space = 0; space < rows - row; space++)
            printf(" ");
        // 循环正序输出的字母
        for (ch = 'A'; space < rows; space++)
            printf("%c", ch++);
        // 循环逆序输出的字母
        for (ch -= 2, space = 0; space < row - 1; space++, ch--)
            printf("%c", ch);
        // 每行结束后换行
        printf("\n");
    }  

    return 0;
}