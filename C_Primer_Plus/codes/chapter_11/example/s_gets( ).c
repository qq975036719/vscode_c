// 编写一个以后会用得上的函数 -- s_gets()
#include <stdio.h>

char *s_gets(char *st, int n)
{
    char *ret_val;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        // 遍历传入的字符串
        while (*st != '\0' && *st != '\n')
            st++;
        // 将换行符替换为空字符
        if (*st == '\n')
            *st = '\0';
        // 跳过剩余的输入
        else
            while (getchar()!='\n')
                continue;
    }
    return ret_val;
}