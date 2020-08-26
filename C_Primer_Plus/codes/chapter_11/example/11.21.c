// 比较两个字符串 -- strcmp()的运用
#include <stdio.h>
#include <string.h>

#define ANSWER "Grant"
#define SIZE 40

char *s_gets(char *st, int n);
int main(void)
{
    char try[SIZE];
    puts("请猜一个英文单词:");
    s_gets(try, SIZE);
    while (strcmp(try, ANSWER)) {
        puts("你猜错啦！再猜一次试试吧: ");
        s_gets(try, SIZE);
    }
    puts("你猜对啦!");

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        // 遍历传入的字符串
        while (st[i] != '\0' && st[i] != '\n')
            i++;
        // 将换行符替换为空字符
        if (st[i] == '\n')
            st[i] = '\0';
        // 跳过剩余的输入
        else
            while (getchar()!='\n')
                continue;
    }
    return ret_val;
}