/* 依赖外部循环的嵌套循环 */
#include <stdio.h>

int main(void)
{
    const int ROWS = 6;
    const int CHAR = 6;
    int rows;
    char ch;

    for (rows = 0; rows < ROWS; rows++)
    {
        for (ch = ('A' + rows); ch < ('A' + CHAR); ch++)
            printf("%c", ch);
        printf("\n");
    }

    getchar();
    return 0;
}