// 英寸转换为厘米
#include <stdio.h>
int main(void)
{
    float height;
    printf("请输入您的身高（单位/英寸）: ");
    scanf("%f", &height);

    height *= 2.54;
    printf("您的身高是：%.2f厘米", height);

    getchar();
    getchar();
    return 0;
}