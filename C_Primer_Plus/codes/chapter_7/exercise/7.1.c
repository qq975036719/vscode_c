// 读取输入, 报告读取的空格数、换行符数和其他字符数
#include <stdio.h>
#include <ctype.h>  // 包含isspace()函数原型

int main(void)
{
    char ch;
    int space = 0;
    int enter = 0;
    int other = 0;
    printf("请输入一句话(以#结束): ");
    while ((ch = getchar()) != '#') {
        if (ch == ' ')
            space++;
        else if (ch == '\n')
            enter++;
        else
            other++;
    }
    printf("空格数    换行符数    其他字符数\n");
    printf("%4d %10d %12d\n", space, enter, other);

    return 0;
}