// 循环嵌套打印图形
#include <stdio.h>
#define INIT 'A'

int main(void)
{
    int row, col;

    for (row = 0; row < 6; row++) {
        for (col = 0; col <= row; col++) {
            printf("%c", INIT + col);
        }
        printf("\n");
    }

    getchar();
    return 0;
}