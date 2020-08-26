// 求模运算 -- 交互式（while循环实现）
#include <stdio.h>

int main(void)
{
    int num1, num2, result;
    printf("本程序用于计算两个数求模的结果!\n");
    
    printf("请输入求模运算的第二个数字: ");
    scanf("%d", &num2);
    printf("请输入求模运算的第一个数字: ");
    scanf("%d", &num1);
    
    while (num1 > 0) {
        result = num1 % num2;
        printf("%d %% %d = %d\n", num1, num2, result);
        printf("请输入第一个数字(<=0 退出程序): ");
        scanf("%d", &num1);
    }
    printf("程序已退出!");

    getchar();
    getchar();
    return 0;
}