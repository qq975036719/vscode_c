// 生成100个1~10的随机数并按降序排序
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int num[100];
    int temp;

    // 设置随机种子
    srand((unsigned int)time(0));
    // 获取随机数并存储到数组中
    for (int i = 0; i < 100; i++)
        num[i] = rand() % 10 + 1;

    for (int i = 0; i < 99; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (num[i] < num[j]) {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    for (int i = 1; i <= 100; i++) {
        printf("%d\t", num[i-1]);
        if (i % 10 == 0)
            putchar('\n');
    }

        return 0;
}