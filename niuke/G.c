#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 1000

char *s_gets(char *st, int n);
int main(void)
{
    int i;              // 测试组数
    int len;            // 字符串长度
    char *input;        // 输入的字符串
    char *temp;

    for (i = 0; i < 1000; i++) {
        int j;
        input = (char *)malloc(sizeof(char) * SIZE);
        temp = (char *)malloc(sizeof(char) * SIZE);

        if (s_gets(input, SIZE)!=NULL) {
            len = strlen(input);
            for (j = 0; j < len; j++) {
                temp[j] = input[len - j -1];
            }
            temp[j] = '\0';

            puts(temp);
            free(input);
            free(temp);
        }
        else
            break;
    }

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val = NULL;
    char *find = NULL;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}