// 打印字符对应的ASCii码
#include <stdio.h>

int main(void)
{
    char ch;
    int count = 0;

    while ((ch = getchar()) != EOF) {
        if (count++ == 10) {
            printf("\n");
            count = 1;
            // 每打印十个结果就换一次行,换行后把计数器设置为1
        }
        if (ch >= '\040')
            printf(" \'%c\'--%3d", ch, ch);
            // '\040' -- 空格符,空格符后的字符都是可显示的
        else if (ch == '\n') {
            printf(" \'\\n\'--\\n\n");
            count = 0;
        }   // 遇到换行符时需换行, 并打印出换行符, 且计数器重置
        else if (ch == '\t') {
            printf(" \'\\t\'--\\t");
            // 制表符的处理
        }
        else
            printf(" \'%c\'--^%c", ch, (ch + 64));
            // \040以前的不可显示字符的处理
    }
    printf("程序已退出！");

    return 0;
}