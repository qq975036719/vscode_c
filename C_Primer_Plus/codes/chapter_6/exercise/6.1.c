// 存储并打印数组
#include <stdio.h>
#define INIT 'a'

int main(void)
{
    char alph[26];
    int i;
    for (i = 0; i < 26; i++) {
        alph[i] = INIT + i;
    }

    for (i = 0; i < 26; i++) {
        printf("%c\t", alph[i]);
    }

    return 0;
}