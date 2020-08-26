// 将一个8个元素的数组的元素分别设置为2的前8次幂
#include <stdio.h>

int main(void)
{
    int num[8];
    // 循环将元素赋值为2的前8次幂
    for (int i = 0; i < 8; i++) {
        num[i] = 1;
        for (int j = 0; j <= i; j++) {
            num[i] *= 2;
        }
    }
    // 循环打印
    int i = 0;
    do {
        printf("%d\t", num[i++]);
    } while (i < 8);

    return 0;
}