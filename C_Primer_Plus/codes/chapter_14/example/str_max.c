// 函数str_max() -- 用于寻找字符串中的最大字符串
#include <stdio.h>
#include <string.h>

char *str_max(char st[][100]);

int main(void)
{
    char a[5][100];
    char *max_str = NULL;
    int i;

    // 读取用户输入
    printf("请输入五个字符串,计算最大字符串。输入: \n");
    for (i = 0; i < 5; i++)
        gets(a[i]);
    
    // 调用str_max()函数寻找最大的字符串 -- 并将最大的字符串存储在max_str字符数组中
    max_str = str_max(a);

    // 打印结果
    fprintf(stdout, "最大的字符串为: %s\n", max_str);

    return 0;
}

char *str_max(char st[][100])
{
    int max = 0;
    int flag;

    for (int i = 1; i < 5; i++) {
        flag = strcmp(st[max], st[i]);
        if (flag < 0)
            max = i;
    }

    return st[max];
}