// 使用嵌套if语句显示一个数的约数
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    unsigned long num;   // 待测试的数
    unsigned long div;   // 可能的约数
    bool isPrime;        // 布尔变量用于判读素数 -- 作为标记(flag)

    // 用户读入数据
    printf("请输入一个数字,此程序会给出该数的所有约数: ");
    while (scanf("%lu", &num) == 1) {
        for (div = 2, isPrime = true; (div * div) <= num; div++) {
            if (num % div == 0) {
                if (div * div != num) {
                    printf("%lu的约数有%lu和%lu\n",
                           num, div, num / div);
                }
                else
                    printf("%lu的约数有%lu\n", num, div);

                isPrime = false;        // 能进入该if说明该数字不是素数
            }
        }
        if (isPrime)
            printf("%lu是素数!\n", num);

        printf("请输入一个数字,此程序会给出该数的所有约数: ");
    }

    return 0;
}