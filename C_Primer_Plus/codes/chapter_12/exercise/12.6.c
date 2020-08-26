// 统计生成的随机数的次数
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int main(void)
{
    int num;
    int count[11] = {0};    // 统计随机数出现的次数 -- 初始化为0
    int total = 0;

    // 设置随机种子
    srand((unsigned int)time(0));
    // srand(1);

    // 统计随机数出现的次数
    for (int i = 0; i < SIZE; i++) {
        num = rand() % 10 + 1;
        count[num]++;
    }
    
    // 打印统计结果
    for (int i = 1; i < 11; i++) {
        printf("%d : %d\n", i, count[i]);
        total += count[i];
    }
    printf("total count = %d\n", total);

    return 0;
}