// 用户输入两个浮点数，计算浮点数之差除浮点数乘积的结果
// 用函数返回计算结果
#include <stdio.h>

float cal(float num1, float num2); // 函数原型
int main(void)
{
    float num1, num2, result;
    printf("请输入两个浮点数(输入非浮点数则会退出程序): ");

    while (scanf("%f %f", &num1, &num2) == 2) {
        // scanf()函数返回的是成功读取格式数据的个数
        result = cal(num1, num2);
        printf("(%.2f - %.2f) / (%.2f * %.2f) = %.2f\n",
               num1, num2, num1, num2, result);
        printf("请输入两个浮点数(输入非浮点数则会退出程序): ");
    }
    printf("程序已退出!");

    return 0;
}

float cal(float num1, float num2)
{
    float res;
    res = (num1 - num2) / (num1 * num2);
    return res;
}