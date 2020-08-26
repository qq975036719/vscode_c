// strcpy()的使用
#include <stdio.h>
#include <string.h>

#define LIM 5
#define SIZE 40

char *s_gets(char *st, int n);
int main(void)
{
    char qwords[LIM][SIZE];
    char temp[SIZE];
    int i = 0;

    printf("请输入以\"q\"开头的单词: \n");
    while (s_gets(temp, SIZE) && i < LIM) {
        if (strncmp(temp, "q", 1))
            printf("\"%s\"不是以q开头的单词, 请输入以\"q\"开头的单词!\n",
                   temp);
        // if (temp[0] != 'q') 也可以
        else {
            strcpy(qwords[i], temp);
            i++;
        }
    }
    puts("你输入的五个以q开头的单词如下: ");
    for (int j = 0; j < LIM; j++)
        printf("%s\n", qwords[j]);

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