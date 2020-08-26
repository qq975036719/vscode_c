// 提示用户输入身高（厘米）和姓名
#include <stdio.h>

int main(void)
{
    float height;
    char name[40];
    
    printf("请输入您的身高（单位:cm）： ");
    scanf("%f", &height);

    printf("请输入您的姓名： ");
    scanf("%s", name);

    printf("%s，您的身高是：%.3f 米", name, height / 100);

    getchar();
    getchar();
    return 0;
}