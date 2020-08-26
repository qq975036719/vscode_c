// 我赚钱啦哈哈哈
#include <stdio.h>

int main(void)
{
    int days, i, sum;
    printf("请输入天数：");
    scanf("%d", &days);
    i = 0;
    sum = 0;

    while (i++ < days) {
        printf("今天是第 %d 天，我赚了 $%d!\n", i, i * i);
        sum += i * i;
    }
    printf("打工的日子结束啦，我总共赚了$%d\n"
           "打工是不可能打工的，这辈子是不可能再打工的！", sum);

    getchar();
    getchar();
    return 0;
}