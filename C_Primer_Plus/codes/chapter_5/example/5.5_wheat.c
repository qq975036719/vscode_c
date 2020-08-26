// 指数增长
#include <stdio.h>
#define SQUARES 64      // 棋盘中的方格数

int main(void)
{
    const double CROP = 2E16;
    double current, total;
    int count = 1;

    printf("square          grains              total           ");
    printf("fraction of \n");
    printf("                added               grains          ");
    printf("world total\n");

    total = current = 1.0;      // 谷粒数从1开始
    while (count <= SQUARES)
    {
        printf("%4d %20.2e %19.2e %15.2e\n",
                count, current, total, total / CROP);
        count++;
        current *= 2;
        total += current;
    }

    getchar();
    return 0;
}