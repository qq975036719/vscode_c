#define Harmonic(X, Y) (1 / ((1 / (X)) + (1 / (Y)) / 2))
#include <stdio.h>

int main(void)
{
    double x, y;
    printf("请输入两个数字: ");
    scanf("%lf %lf", &x, &y);

    printf("%lf", Harmonic(x, y));

    return 0;
}