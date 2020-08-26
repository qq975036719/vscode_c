// 比较两个字符串 -- strcmp()的运用
// 改进版 -- 无论用户输入的是大写还是小写，只要符合answer就是正确的

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ANSWER "Grant"
#define SIZE 40

char *s_gets(char *st, int n);
void fomal_input(char *st);
int main(void)
{
    char try[SIZE];
    puts("请猜一个英文单词(不区分大小写):");
    s_gets(try, SIZE);
    // 转换格式
    fomal_input(try);
    // 判断答案是否正确
    while (strcmp(try, ANSWER))
    {
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

void fomal_input(char *st)
{
    // 将第一个字母改成大写
    if (islower(*st))
        *st = toupper(*st);
    st++;
    // 将后面的字母全部改成小写
    while (*st != '\0') {
        *st = tolower(*st);
        st++;
    }
}