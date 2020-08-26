// 使用strtol()函数 -- 将字符串转换成long int
#include <stdio.h>
#include <stdlib.h>
#define LIM 30

char *s_gets(char *st, int n);
int main(void)
{
    char number[LIM];
    char *end;
    long value;
    
    puts("请输入一个数字(输入空行退出): ");
    while (s_gets(number, LIM) && number[0] != '\0') {
        value = strtol(number, &end, 10);   // 十进制
        printf("以10进制输入,以10进制输出: %ld, 到%s(%d)结束\n",
               value, end, *end);
        value = strtol(number, &end, 16);   // 十六进制
        printf("以16进制输入,以16进制输出: %ld, 到%s(%d)结束\n",
               value, end, *end);
        puts("请输入下一个数字: ");
    }
    puts("程序已退出!");

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