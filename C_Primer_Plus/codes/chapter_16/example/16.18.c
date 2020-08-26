// 使用assert()调试程序
#include <stdio.h>
// #define NDEBUG       // 用于使所有的assert语句失效
#include <assert.h>
#include <math.h>

int main(void)
{
    double x, y, z;

    printf("Enter a pair of numbers (0 0 to quit): ");
    while ((scanf("%lf %lf", &x, &y)) == 2 && (x != 0 || y != 0)) {
        z = x * x - y * y;
        assert(z >= 0);
        printf("answer is %f\n", sqrt(z));
        printf("Next pair of numbers: ");
    }
    puts("Done!");

    return 0;
}

