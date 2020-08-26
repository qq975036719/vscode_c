// 用循环嵌套打印图形
#include <stdio.h>

int main(void) 
{
    int row, col;
    for (row = 0; row < 5; row++) {
        for (col = 0; col <= row; col++) {
            printf("%c", '$');
        }
        printf("\n");
    }

    getchar();
    return 0;
}