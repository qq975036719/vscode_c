// 打印指定个数的素数 -- 利用循环嵌套
#include <stdio.h>

int main(void)
{
    int cnt = 0;
    int x;
    int terms;
    printf("你想输出多少个素数呢？(从2开始的素数): ");
    scanf("%d", &terms);

    for (x = 2; cnt < terms; x++) {
        int i;
        int isPrime = 1;    // 是素数

        for (i = 2; i < x; i++) {
            if (x % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1) {
            cnt++;
            printf("%d\t", x);
            if (cnt % 5 == 0)
                printf("\n");
        }
    }

    getchar();
    getchar();
    return 0;
}