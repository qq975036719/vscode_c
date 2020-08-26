// 测试typedef
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int(*p)[3][4];

    p = num;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d ", p[i][j]);
        putchar('\n');
    }

        return 0;
}