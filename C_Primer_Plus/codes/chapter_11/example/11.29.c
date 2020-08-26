// 字符串排序
#include <stdio.h>
#include <string.h>
#define SIZE 81			// 限制字符串长度，包括'\0'
#define LIM 20			// 可读入的最多行数
#define HALT ""			// 遇到空字符串停止输入

char* s_gets(char* st, int n);
void stsrt(char* strings[], int num);   // 字符串排序函数

int main(void)
{
    char input[LIM][SIZE];      // 存储输入的数组
    char* ptstr[LIM];           // 内含指针变量的数组
    int ct = 0;                 // 输入计数
    int k;                      // 输出计数

    printf("请输入一段话,此程序会对其进行排序,最多可输入%d行\n", LIM);
    printf("如果要退出程序,请以单独的回车为一行!\n");
    // 开始读入
    while (ct < LIM && s_gets(input[ct], SIZE) && input[ct][0] != '\0') {
        ptstr[ct] = input[ct];
        ct++;
    }
    stsrt(ptstr, ct);
    puts("\n排序后的结果: \n");
    for (int i = 0; i < ct; i++)
        puts(ptstr[i]);

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

void stsrt(char* strings[], int num)
{
    char *temp;
    int top, seek;
    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top], strings[seek])>0) {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}