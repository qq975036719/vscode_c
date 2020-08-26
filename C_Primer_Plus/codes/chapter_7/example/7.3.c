// 替换输入的字母, 非字母字符保持不变
#include <stdio.h>
#include <ctype.h>  // 包含isalpha()函数原型

int main(void)
{
    char ch;
    printf("请输入一行话: ");
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch))
            putchar(ch + 1);    // 打印字母的下一位
        else
            putchar(ch);        // 原样输出非字母
    }
    putchar(ch);                // 换行输出
    return 0;
}