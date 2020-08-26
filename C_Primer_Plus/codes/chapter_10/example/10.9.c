// 数组用指针表示
#include <stdio.h>
#define MONTH 12

int main(void)
{
    int days[MONTH] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < MONTH; i++)
        printf("%d月有%d天\n", i + 1, *(days + i));

    return 0;
}