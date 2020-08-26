// 返回参数中打开位的数量 -- 即二进制表示中的1的数量
#include <stdio.h>
#include <limits.h>

int bits_nums(int n);

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%d\n", bits_nums(n));

    return 0;
}

int bits_nums(int n)
{
    int sum = 0;

    for (int i = 0; i < 32; i++) {
        if (n & 1)
            sum++;
        n >>= 1;
    }

    return sum;
}