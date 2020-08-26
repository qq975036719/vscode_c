// 用户输入5，打印5~15的所有整数
#include <stdio.h>

int main(void)
{
    int num;
    int count = 0;
    printf("请输入一个整数: ");
    scanf("%d", &num);
    
    while (count++ < 11)
    {
        printf("%d\t", num++);
    }

    getchar();
    getchar();
    return 0;
}