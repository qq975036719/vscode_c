// 显示年龄对应的秒数
#include <stdio.h>
int main(void)
{
    int age;
    printf("请输入您的年龄： ");
    scanf("%d", &age);
    printf("\n您的年龄对应的秒数是：%le秒", 3.156e7 * age);

    getchar();
    getchar();

    return 0;
}