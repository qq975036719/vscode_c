// 浮点数格式化输出
#include <stdio.h>

int main(void)
{
    float flt;
    printf("请输入一个浮点数：");
    scanf("%f", &flt);

    printf("%0.1e\n", flt);
    printf("%+0.3E\n", flt);

    getchar();
    getchar();
    return 0;
}