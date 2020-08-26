// 检查是否需要停止读取输入
#include <stdio.h>
#include <string.h>

#define SIZE 80
#define LIM 10
#define STOP "quit"

char *s_gets(char *st, int n);
int main(void)
{
    char input[LIM][SIZE];
    int count = 0;

    printf("请输入不超过%d行的字符串(输入quit退出程序): \n", LIM);
    // 遍历每一行字符串看是否符合条件
    // 条件: 不超过LIM行; 输入的内容不是quit;没有读取到文件结尾
    // 一旦不符合其中一个条件则停止检查
    while (count < LIM && s_gets(input[count], SIZE) &&
            strcmp(input[count], STOP))
        count++;
    printf("已输入%d行字符串", count);

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