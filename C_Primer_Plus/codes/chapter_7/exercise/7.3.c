// 分别输出偶数和奇数的个数、平均值
#include <stdio.h>

int main(void)
{
    int odd = 0;
    int even = 0;
    float odd_av = 0;
    float even_av = 0;
    int num;

    printf("请输入一个整数(输入0退出程序): ");
    while ((num = getchar()) != 0) {
        if (num % 2 == 0 && num != 0) {  // 判断偶数(不包括0)
            even++;                      // 递增偶数计数器
            even_av += num;              // 偶数和
        }
        if (num % 2 != 0) {   // 判断奇数
            odd++;            // 递增奇数计数器
            odd_av += num;    // 奇数和
        }
    }
    even_av = even_av / even;   // 计算偶数的平均数
    odd_av = odd_av / odd;      // 计算奇数的平均数
    printf("偶数个数    偶数的平均数    奇数个数    奇数的平均数");
    printf("%4d %8f %8d %8f", even, even_av, odd, odd_av);
    return 0;
}