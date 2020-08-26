// 使用已定义的常量
#include <stdio.h>
#define PI 3.1415926

int main(void)
{
    float area, circum, radius;
    printf("What is the radius of your pizza?(cm)");
    scanf("%f", &radius);
    area = PI * radius * radius;
    circum = 2 * PI * radius;

    printf("Your basic pizza parameters are as follows:\n");
    printf("circumference = %1.2f, area = %1.2f",
           circum, area);

    getchar();
    getchar();
    return 0;
}