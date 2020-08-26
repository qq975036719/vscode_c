// 以两种方式显示float类型的值 -- 展现C99中的某些特性
#include <stdio.h>
int main(void)
{
    float aboat = 32000.0;
    double abet = 2.14e9;
    long double dip = 5.32e-5;
    printf("%f can be written %e\n", aboat, aboat);

    // 以下内容展现了C99的特性

    printf("And it's %a in hexadecimal(十六进制), powers of 2 aboat\n");
    printf("%f can be written %e\n", abet, abet);
    printf("%Lf can be written %Le\n", dip, dip);

    getchar();
    return 0;
}