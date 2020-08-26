// 使用fgets()和fputs()
// 如果不想丢弃超出的输入行，可以参考该程序的做法
#include <stdio.h>
#define STLEN 10

int main(void)
{
    char words[STLEN];
    puts("请输入一个字符串(输入回车换行退出程序): ");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
        fputs(words, stdout);
    puts("Done!");

    return 0;
}