// 演示strncpy()的特性
#include <stdio.h>
#include <string.h>

#define SIZE 40
#define TARGETSIZE 7
#define LIM 5

char *s_gets(char *st, int n);
int main(void)
{
    char qwords[LIM][TARGETSIZE];
    char temp[SIZE];
    int i = 0;

    printf("请输入以\"q\"开头的单词: \n");
    while (s_gets(temp, SIZE) && i < LIM) {
        if (strncmp(temp, "q", 1))
            printf("\"%s\"不是以q开头的单词, 请输入以\"q\"开头的单词!\n",
                   temp);
        // if (temp[0] != 'q') 也可以
        else {
            strncpy(qwords[i], temp, TARGETSIZE-1);    // TARGETSIZE-1是为了确保有一个空间用来存放'\0'
            qwords[i][TARGETSIZE - 1] = '\0';          // 将最后一个元素替换成'\0'确保字符串完整 
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