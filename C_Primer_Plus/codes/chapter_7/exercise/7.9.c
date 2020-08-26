// 寻找小于或等于用户输入的数字的所有素数
#include <stdio.h>

int main(void)
{
    int num;
    int isPrime(int num);      // 判断素数的函数原型
    int prime[10000] = {0};    // 用于存储素数的数组

    printf("请输入一个正整数: ");
    while (scanf("%d", &num) == 1) {
        if (num <= 0) {
            printf("请输入正整数!");
            continue;
        }
        for (int i = 2; i <= num; i++) {
            if (isPrime(i)) {       // 判断是否是素数,并存储到素数数组中
                prime[i] = i;
            }
        }
        // 循环数组打印出结果
        printf("所有小于或等于%d的素数有: \n", num);
        for (int i = 0; i < num; i++) {
            if (prime[i] != 0)
                printf("%d ", prime[i]);
        }
        printf("\n请输入一个正整数: ");
    }

    return 0;
}

int isPrime(int num)
{
    int prime = 1;      // 默认假设num为素数
    for (int j = 2; j < num; j++) {
        if (num % j == 0) {
            prime = 0;  // num能被j整除 -- num不是素数 -- prime设为0（不是素数）
        }
    }
    return prime;
}