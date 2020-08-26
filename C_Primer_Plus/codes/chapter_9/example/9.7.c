// 阶乘计算 -- 循环和递归分别实现
#include <stdio.h>

// 函数原型
long fact(int num);        // 循环计算阶乘
long rfact(int num);       // 递归计算阶乘

int main(void)
{
    int num;
    printf("此程序用两种方式计算阶乘!\n");
    printf("请输入一个0~12的数字: ");
    while (scanf("%d", &num) == 1) {
        if (num < 0)
            printf("阶乘运算对象必须是非负数!\n");
        else if (num > 12)
            printf("请输入0~12之间的数字!\n");
        else {
            printf("用循环计算%d的阶乘的结果为: %ld\n", num, fact(num));
            printf("用递归计算%d的阶乘的结果为: %ld\n", num, rfact(num));
        }
        printf("\n请输入一个0~12的数字: ");
    }
}

long fact(int num)
{
    long res;
    for (res = 1; num > 1; num--)
        res *= num;

    return res;
}

long rfact(int num)
{
    long res;
    if (num > 0)
        res = num * rfact(num - 1);
    else
        res = 1;

    return res;
}