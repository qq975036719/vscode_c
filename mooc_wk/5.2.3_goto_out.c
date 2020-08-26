// 枚举硬币，跳出循环 -- goto语句
#include <stdio.h>

int main(void)
{
    int one, two, five;
    int x;

    printf("请输入要得出组合的金额: ");
    scanf("%d", &x);

    for (one = 1; one < x * 10; one++) {
        for (two = 1; two < x * 10 / 2; two++) {
            for (five = 1; five < x * 10 / 5; five++) {
                if (one + two * 2 + five * 5 == x*10) {
                    printf("你可以用%d张1角和%d张2角和%d张5角组合成%d元\n\n",
                           one, two, five, x);
                    goto out;
                }
            }
        }
    }
    out:    // goto out 语句可以让循环到一种可行的情况时就跳转
            // 到指定的位置，达到退出循环的目的
    getchar();
    getchar();
    return 0;
}