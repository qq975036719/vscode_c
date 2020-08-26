// 函数: 用于进制转换, 第一个参数是十进制数, 第二个参数是要转换的进制
#include <stdio.h>

int main(void)
{
    void to_binary(int num, int into);
    int num, into;
    printf("此程序用于输出十进制整数的其他进制形式\n");
    printf("请输入一个十进制整数和要转换的进制: ");
    while (scanf("%d %d", &num, &into) == 2) {
        if (into < 2 || into > 10) {
            printf("进制只能是2~10, 您的输入超出范围, 请重新输入: ");
            continue;
        }
        printf("%d的%d进制形式为: ", num, into);
        to_binary(num, into);
        putchar('\n');
        printf("请输入一个十进制整数和要转换的进制: ");
    }
    return 0;
}

void to_binary(int num, int into)
{
    int r;
    r = num % into;
    if (num >= 2)
        to_binary(num / into, into);
    printf("%d", r);

    return;
}