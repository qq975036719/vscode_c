// 函数is_within() -- 判断某个字符在字符串中是否存在 -- 存在返回1 -- 不存在返回0
#include <stdio.h>
#define SIZE 80

int is_within(char target, char *source);
int main(int argc, char *argv[])
{
    char source[SIZE];
    char target = ' ';

    // 输入源字符串
    printf("请输入一个字符串: ");
    fgets(source, SIZE, stdin);
    // 输入待判断的字符
    while (target != EOF) {
        printf("请输入待判断的字符: ");
        // 读取多余的换行符并丢弃
        while ((target = getchar()) == '\n')
            continue;
        if (is_within(target, source))
            printf("你输入的字符串中有%c\n", target);
        else
            printf("你输入的字符串中没有%c\n", target);
    }
}

int is_within(char target, char *source)
{
    int page = 0;
    while (*source) {
        if (*source == target)
            page = 1;
        source++;
    }

    return page;
}