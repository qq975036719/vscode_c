// 打印浮点数的各种形式
#include <stdio.h>
int main(void)
{
    float float_num;

    printf("Enter a floating-point value: ");
    scanf("%f", &float_num);

    // 打印成小数点形式
    printf("fixed-point notation: %f\n", float_num);
    // 打印成指数形式
    printf("exponential notation: %e\n", float_num);
    // 打印成p计数法
    printf("p notation: %a\n", float_num);

    getchar();
    getchar();
    return 0;
}