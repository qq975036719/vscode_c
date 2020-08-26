// 使用fgets()和fputs()
#include <stdio.h>
#define STLEN 14

int main(void)
{
    char words[STLEN];

    puts("请输入一个字符串: ");
    fgets(words, STLEN, stdin);
    printf("输出你输入的字符串两次(puts(), fputs()): \n");
    puts(words);
    fputs(words, stdout);
    puts("请输入一个字符串: ");
    fgets(words, STLEN, stdin);
    printf("输出你输入的字符串两次(puts(), fputs()): \n");
    puts(words);
    fputs(words, stdout);
    puts("Done!");

    return 0;
}