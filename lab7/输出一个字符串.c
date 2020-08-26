// myputs函数 -- 输出一个字符串
#include <stdio.h>
#define SIZE 100

void myputs(char *str)
{
    char *pst = str;

    while (pst[0]) {
        putchar(pst[0]);
        pst++;
    }
    putchar('\n');
}

int main(void)
{
    char str[SIZE] = "heihei";

    myputs(str);

    return 0;
}