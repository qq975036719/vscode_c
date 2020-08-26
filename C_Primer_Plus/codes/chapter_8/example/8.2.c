// 重复输入, 直到文件结尾
// 输入Ctrl+Z即可结束输出
#include <stdio.h>

int main(void)
{
    int ch;
    while ((ch = getchar()) != EOF)
        putchar(ch);

    return 0;
}