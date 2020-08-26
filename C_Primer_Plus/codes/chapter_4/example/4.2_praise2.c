// 字符串 -- sizeof
#include <stdio.h>
#include <string.h>
#define PRAISE "You are an extraordinary being."

int main(void)
{
    char name[40];
    printf("What's your name?\n");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    printf("你的名字的字符长度为 %zd，且占用内存 %zd 字节\n",
           strlen(name), sizeof name);
    printf("phrase 的字符长度为 %zd",
           strlen(PRAISE));
    printf("并且占用内存%zd字节.\n", sizeof PRAISE);

    getchar();
    getchar();
    return 0;
}