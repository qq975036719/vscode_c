#include <stdio.h>

int main(void)
{
    int num[2] = {0, 1};
    int flag = 0;

    for (int i = 1; i; i++) {
        printf("%-4d", num[flag]);
        if (flag == 0)
            flag = 1;
        else
            flag = 0;
        if ((i+1)%100 == 0)
            putchar('\n');
    }

    getchar();
    return 0;
}