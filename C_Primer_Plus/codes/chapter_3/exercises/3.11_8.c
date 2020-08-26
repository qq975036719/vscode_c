// 杯数、品脱、盎司、大汤勺、茶勺单位转换
#include <stdio.h>
int main(void)
{
    float cups, pints, ounce, big_spoon, teaspoon;
    printf("请输入杯数： ");
    scanf("%f", &cups);

    pints = cups / 2;
    ounce = cups * 8;
    big_spoon = cups * 16;
    teaspoon = cups * 48;

    printf("%.2f杯数对应的其他单位如下：\n", cups);
    printf("品脱：%.2f\n", pints);
    printf("盎司：%.2f\n", ounce);
    printf("大汤勺：%.2f\n", big_spoon);
    printf("茶勺：%.2f\n", teaspoon);

    getchar();
    getchar();
    return 0;
}