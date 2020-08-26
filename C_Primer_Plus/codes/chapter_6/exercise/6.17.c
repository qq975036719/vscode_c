// 循环处理复利问题
#include <stdio.h>

int main(void)
{
    const float ANNUAL = 0.08;
    const float MONEY = 100.0;
    int year;
    float total = MONEY;

    for (year = 1; total > 9; year++) {
        total = total * (1 + ANNUAL);
        total -= 10;
        printf("今年是第%d年,余额为: %.2lf\n", year, total);
    }
    printf("%d年后, Chuckie的余额为: %.2lf\n", year - 1, total);
    printf("所有%d年后, Chuckie取完了所有的钱", year);

    return 0;
}