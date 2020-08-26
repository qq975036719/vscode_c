// 对比float和double
#include <stdio.h>
#include <float.h>

int main(void)
{
    float i = 1.0 / 3.0;
    double j = 1.0 / 3.0;

    // 打印float后6位
    printf("float of one third = %.6f\n", i);
    // 打印float后12位
    printf("float of one third = %.12f\n", i);
    // 打印float后16位
    printf("float of one third = %.16f\n", i);

    // 打印double后6位
    printf("double of one third = %.6f\n", j);
    // 打印double后12位
    printf("double of one third = %.12f\n", j);
    // 打印double后16位
    printf("double of one third = %.16f\n", j);

    printf("FLT_DIG in float.h is %d\n", FLT_DIG);
    printf("DBL_DIG in float.h is %d\n", DBL_DIG);

    getchar();
    return 0;
}