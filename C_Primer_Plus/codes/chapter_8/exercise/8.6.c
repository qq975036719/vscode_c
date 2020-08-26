#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char get_first(void);
    char res;
    res = get_first();
    printf("\"%c\"", res);

    return 0;
}

char get_first(void)
{
    int ch;
    ch = getchar();
    while (isspace(ch)) {
        ch = getchar();
    }
    
    return ch;
}