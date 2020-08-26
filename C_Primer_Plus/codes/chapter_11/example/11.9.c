// 使用fgets()函数
// 如果想让程序丢弃输入行的超出字符，可以参考该程序的做法
#include <stdio.h>
#define STLEN 10

int main(void)
{
    char words[STLEN];
    int i;

    puts("请输入一个字符串(直接输入回车退出程序): ");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n') {
        i = 0;
        while (words[i] != '\n' && words[i] != '\0')
            i++;
        if (words[i] == '\n')   // 遍历遇到换行符时,把换行符替换成空字符
            words[i] = '\0';
        else                    // 遍历遇到空字符的情况, 把空字符后面的输入都跳过
            while (getchar() != '\n')
                continue;
        puts(words);
    }
    puts("done");

    return 0;
}