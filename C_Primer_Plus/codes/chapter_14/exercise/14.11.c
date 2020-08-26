// transform函数 -- 调用一个函数多次
#include <stdio.h>
#include <math.h>

void transform(double src[], double tar[], int n, double (*fun)(double));

int main(void)
{
    double source[10];
    double target[10];

    for (int i = 0; i < 10; i++)
        source[i] = i;

    printf("source: ");
    for (int i = 0; i < 10; i++)
        printf("%g ", source[i]);
    putchar('\n');

    transform(source, target, 10, sin);
    printf("sin -- 10\n");
    for (int i = 0; i < 10; i++)
        printf("%g ", target[i]);
    putchar('\n');

    transform(source, target, 10, cos);
    printf("cos -- 10\n");
    for (int i = 0; i < 10; i++)
        printf("%g ", target[i]);
    putchar('\n');

    return 0;
}

void transform(double src[], double tar[], int n, double (*fun)(double))
{
    for (int i = 0; i < n; i++)
        tar[i] = fun(src[i]);
}