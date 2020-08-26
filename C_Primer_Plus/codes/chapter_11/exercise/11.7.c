// mystrncpy()函数 -- 实现与strncpy()函数一样的功能
#include <stdio.h>
#define SIZE 100

char *mystrncpy(char *st1, char *st2, int n);
int main(void)
{
    char st1[SIZE];
    char st2[SIZE];
    int n;

    printf("请输入源字符串: ");
    fgets(st2, SIZE, stdin);
    printf("请输入你想拷贝的字符串的字符数: ");
    scanf("%d", &n);

    while (*st2 != '\n') {
        mystrncpy(st1, st2, n);
        printf("拷贝后的字符串为: ");
        puts(st1);

        while (getchar()!='\n')
            break;

        printf("请输入源字符串: ");
        fgets(st2, SIZE, stdin);
        printf("请输入你想拷贝的字符串的字符数: ");
        scanf("%d", &n);
    }

    return 0;
}

char *mystrncpy(char *st1, char *st2, int n)
{
    int count = 0;

    while (*st2 && count < n) {
        *(st1 + count++) = *st2++;
    }
    while (count < n) {
        *(st1 + count++) = '\0';
    }
    
    return st1;
}