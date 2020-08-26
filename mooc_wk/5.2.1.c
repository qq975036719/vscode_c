// 判断素数
#include <stdio.h>

int main(void)
{
    int num, i;
    int isPrime = 1;    // 是素数
    printf("请输入一个数字: ");
    scanf("%d", &num);

    for (i = 2; i < num; i++) {
        if (num % i == 0)
            isPrime = 0;
    }

    if (isPrime == 1) {
        printf("%d是素数", num);
    } else
        printf("%d不是素数", num);

    getchar();
    getchar();
    return 0;
}