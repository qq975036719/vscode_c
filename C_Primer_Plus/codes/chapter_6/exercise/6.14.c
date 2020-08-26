// 数组的应用
#include <stdio.h>

int main(void)
{
    double d1[8], d2[8];
    printf("请输入8个数字,本程序会打印出求和结果: ");
    for (int i = 0; i < 8; i++)
        scanf("%lf", &d1[i]);

    // 用循环嵌套实现
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j <= i; j++)
            d2[i] += d1[j];
    }

    // 不用循环嵌套实现
    // d2[0] = d1[0];
    // for (int i = 1; i < 8; i++) {
    //     d2[i] = d2[i - 1] + d1[i];
    // }
    
    // 循环打印结果
    printf("你输入的八位数和对应的和分别是: \n");
    for (int i = 0; i < 8; i++)
        printf("%.2f\t", d1[i]);

    printf("\n");

    for (int i = 0; i < 8; i++)
        printf("%.2f\t", d2[i]);

    return 0;
}