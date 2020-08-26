// 拼接两个字符串
#include <stdio.h>
#include <string.h>
#define SIZE 80

char *s_gets(char *st, int n);
int main(void)
{
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";
    
    puts("你最喜欢的花是什么?");
    
    if (s_gets(flower, SIZE)) {
        strcat(flower, addon);
        puts(flower);
        puts(addon);
    }

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