// 用clock()的返回值计算程序运行时间 -- 从而创造一个循环 -- 循环的时间正是这个计算结果
#include <stdio.h>
#include <time.h>

void run_seconds(double sec)
{
    clock_t run1, run2;

    run1 = clock();
    printf("计时开始!\n");
    run2 = clock();
    while ((double)(run2-run1) / CLOCKS_PER_SEC < sec) {
        run2 = clock();
        printf("Running: %lf\n", (double)(run2-run1) / CLOCKS_PER_SEC);
    }
}

int main(void)
{
    double seconds;

    printf("请输入运行时间(单位: 秒): ");
    scanf("%lf", &seconds);

    run_seconds(seconds);
    puts("Done!");

    return 0;
}