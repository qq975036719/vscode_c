// 寻找一个字符串中的空格，如果有则返回第一个空格的地址，没有则返回NULL
#include <stdio.h>

char *find_space(const char *st);
int main(void)
{
    char words[10] = "fuck you";
    char *space;
    space = find_space(words);
    printf("空格的地址是: %p", space);
    printf("\n该地址对应的值为: \"%c\"\n", *space);
    *space = 'F';
    puts(words);
    puts(space);

    return 0;
}

char *find_space(const char *st)
{
    while (*st != ' ' && *st !='\0') {
        st++;
    }
    if (*st == '\0')
        return NULL;
    else
        return (char *) st;
}