// 将整数n分解成素数之积
#include <stdio.h>
#include <stdbool.h>
#define FAC_SIZE 100            // 因子表的大小

// 判断是否是素数
bool isPrime(int n)
{
    for (int i = 2; i < n - 1; i++)
        if (n % i == 0)
            return false;
    return true;
}

void myfactor(int n)
{
    if (n == 0 || n == 1) {
        printf("%d = %d", n, n);
        return;
    }

    int factors[FAC_SIZE];      // 因子表 -- 用于存储可以整除n的因子
    int fi = 0;                 // 用于操控因子表的下标
    int count;

    // 生成因子表
    int temp = n;               // 不改变n的值 -- 方便最后输出
    int i = 2;

    // 生成因子表
    while (temp != 1) {
        if (isPrime(i) && (temp % i == 0)) {
            factors[fi++] = i;
            temp /= i;
            i = 2;
        }
        else
            i++;
    }
    count = fi;                 // 记录因子表中的因子个数

    // 输出结果
    if (count == 1)
        printf("%d = %d\n", n, factors[0]);
    else {
        printf("%d = %d ", n, factors[0]);
        for (int i = 1; i < count; i++)
            printf("* %d ", factors[i]);
    }
}

int main(void)
{
    int n;

    printf("请输入待分解的整数: ");
    scanf("%d", &n);

    myfactor(n);

    return 0;
}