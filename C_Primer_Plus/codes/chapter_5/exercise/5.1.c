// 将分钟转换成以小时，分钟表示的时间
#include <stdio.h>
#define M_TO_H 60   // 每小时60分钟

int main(void)
{
    int min, hour, left;        // left -- 剩余的分钟数
    printf("请输入分钟数(<=0时会退出程序): ");
    scanf("%d", &min);

    while (min > 0)
    {
        hour = min / M_TO_H;
        left = min % M_TO_H;
        printf("%d分钟 = %d时,%d分\n", min, hour, left);
        printf("如果还想继续请输入下一个分钟数，输入0或负数退出程序: ");
        scanf("%d", &min);
    }
    printf("程序已退出!\n");

    getchar();
    getchar();
    return 0;
}