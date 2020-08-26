// 递归打印二进制整数
#include <stdio.h>

int main(void)
{
    void to_binary(int num);
    int num;
    printf("此程序用于输出十进制整数的二进制形式\n");
    printf("请输入一个十进制整数: ");
    while (scanf("%d", &num)==1) {
        printf("%d的二进制形式为: ", num);
        to_binary(num);
        putchar('\n');
        printf("请输入一个十进制整数: ");
    }
    return 0;
}

void to_binary(int num)
{
    int r;
    r = num % 2;
    if (num > 2)
        to_binary(num / 2);
    putchar(r == 0 ? '0' : '1');
    return;
}