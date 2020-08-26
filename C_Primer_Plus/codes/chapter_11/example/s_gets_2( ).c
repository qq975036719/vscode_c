// s_gets()函数 -- 用strchr()替代其中的while循环
#include <stdio.h>
#include <string.h>

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        // 将换行符替换为空字符
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        // 跳过剩余的输入
        else
            while (getchar()!='\n')
                continue;
    }
    return ret_val;
}