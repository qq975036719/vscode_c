// 单位转换
#include <stdio.h>
#define GALLON_TO_LITER 3.785
#define MILE_TO_KM 1.609

int main(void)
{
    float range, oil;
    printf("请输入旅行里程和消耗的汽油量：");
    scanf("%f %f", &range, &oil);
    
    // 打印 英里/加仑 单位
    printf("在美国，每加仑汽油可以行驶的路程为: %.1f 英里\n", range / oil);

    // 打印 升/100 千米 单位
    printf("在欧洲，每100千米路程需要消耗的燃料为: %.1f 升\n",
    (oil * GALLON_TO_LITER) / (range * MILE_TO_KM));

    getchar();
    getchar();
    return 0;
}