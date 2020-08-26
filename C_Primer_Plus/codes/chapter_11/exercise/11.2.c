// 11.1.c的改进 -- 读取到n个字符停止，遇到空白、制表符、换行符停止
#include <stdio.h>
#define SIZE 100

char *get_str(char *st, int n);
int main(int argc, char *argv[])
{
    char words[SIZE];
    puts("请输入一段话: ");
    get_str(words, SIZE);
    puts("你输入的话如下: ");
    puts(words);

    return 0;
}

char *get_str(char *st, int n)
{
    int i = 0;
    do {
        st[i] = getchar();
        if (st[i] == '\n' || st[i] == '\t' || st[i] == ' ')
            break;
    } while (st[i] != EOF && ++i < n);

    return st;
}