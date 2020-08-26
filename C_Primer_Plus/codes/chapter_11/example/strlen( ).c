// 实现strlen()函数
#include <stdio.h>

int strlen(char *st);
int main(void)
{
    char str1[] = "Fuck you baby!";
    printf("%d", strlen(str1));

    return 0;
}

int strlen(char * st)
{
    int length = 0;
    while (*st++)
        length++;
    
    return length;
}