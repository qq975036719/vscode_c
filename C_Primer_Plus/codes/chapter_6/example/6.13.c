// 一类邮资
#include <stdio.h>

int main(void)
{
    const int FIRST_OZ = 46;    // 首重邮资
    const int NEXT_OZ = 20;     // 续重邮资
    printf("ounces  cost\n");

    int ounce, cost;
    for (ounce = 1, cost = FIRST_OZ; ounce <= 16; ounce++, cost += NEXT_OZ)
        printf("%3d     $%4.2f\n", ounce, cost / 100.0);

    getchar();
    return 0;
}