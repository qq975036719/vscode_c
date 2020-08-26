// 左旋转指定数量的位
#include <stdio.h>
#include <limits.h>

unsigned int rotate_1(unsigned int n, int r)
{
    int size = CHAR_BIT * sizeof(int);

    for (int i = 0; i < r; i++) {
        if (n & (1 << (size - 1))) {      // 如果最高阶那位是1 -- 就整体左移一位，然后最低阶变为1
            n <<= 1;
            n |= 1;
        }
        else                            // 如果最高阶那位是0 -- 则整体左移一位，最低阶默认是0
            n <<= 1;
    }

    return n;
}

int main(void)
{
    int n, r;

    scanf("%d %d", &n, &r);
    printf("source : %d\n", n);
    printf("new : %d\n", rotate_1(n, r));

    return 0;
}