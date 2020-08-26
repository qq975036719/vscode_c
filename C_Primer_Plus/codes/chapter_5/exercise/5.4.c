// 身高(厘米)转换成厘米、英尺和英寸显示，且有小数部分，重复输入
// FT -- 英尺   IN -- 英寸
#include <stdio.h>

int main(void)
{
    const float FEET_TO_CM = 30.48;
    const float INCH_TO_CM = 2.54;
    float cm, inch;
    int feet;

    printf("请输入您的身高(cm),输入0或负数即退出程序: ");
    scanf("%f", &cm);

    while (cm > 0) {
        feet = cm / FEET_TO_CM;
        inch = (cm - feet * FEET_TO_CM) / INCH_TO_CM;
        printf("%.1f cm = %d feets, %.1f inches\n", cm, feet, inch);
        printf("请问您是否要继续？若继续则直接输入，若退出则输入0或负数: ");
        scanf("%f", &cm);
    }
    printf("程序已退出！\n");

    getchar();
    getchar();
    return 0;
}